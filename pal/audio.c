/* audio.c — RAD Linux port: SDL2 audio mixing AdLib (OPL2) + PC speaker.
 *
 * Two sound sources are mixed additively into one SDL audio device:
 *   1. AdLib / OPL2 via Nuked OPL3 in OPL2 mode.  The recovered code writes
 *      the register index to port 0x388 and the data byte to 0x389; those map
 *      to OPL3_WriteRegBuffered().  A read of 0x388 is the AdLib status port.
 *   2. The PC speaker: the 8253 PIT channel 2 (data 0x42, control 0x43) sets a
 *      divisor; port 0x61 bits 0/1 gate the speaker.  A square wave at
 *      1193182/divisor Hz is generated when gated on.
 *
 * DECISIONS:
 *   - Output format is 44100 Hz stereo float (AUDIO_F32SYS), 1024-sample
 *     buffer -> ~23 ms latency (well under the 80 ms budget).
 *   - The OPL2 is reset at the *output* rate and rendered with
 *     OPL3_GenerateResampled(), which is Nuked OPL3's built-in
 *     native(49716)->output resampler.  newm is left 0, so the chip stays in
 *     OPL2 mode and OPL3-only registers (>=0x100) are ignored.
 *   - OPL2 status (read 0x388) returns 0x00: IRQ, timer1 and timer2 bits all
 *     clear (idle).  This is the value that makes "wait while busy" loops
 *     terminate immediately.  (The brief's "0xE0-ish" is inconsistent with
 *     its own "bits 5/6/7 clear"; the all-clear idle value is used.)
 *   - Port 0x188 (and, as a guess, 0x189) is routed to the same OPL2 bus as
 *     the brief requests; this still needs revisiting against the recovered
 *     code (the recon only ever *reads* 0x188, testing bit 2).
 *   - Reads of 0x40..0x42 (PIT counters) and 0x61 (PPI) return 0, per brief.
 *   - 25% speaker amplitude, ~0.6 OPL gain, 0.7 master volume, hard clip.
 *   - SDL's audio callback runs on SDL's own thread; register/state writes
 *     are serialised with SDL_LockAudioDevice().  No threads are created here.
 */
#include <SDL2/SDL.h>
#include <string.h>

#include "pal.h"
#include "pal_internal.h"
#include "opl3.h"

#define RAD_SAMPLE_RATE 44100
#define RAD_AUDIO_SAMPLES 1024

#define OPL_GAIN   0.60
#define SPK_AMP    0.25
#define MASTER_VOL 0.70

static SDL_AudioDeviceID g_adev = 0;
static SDL_AudioSpec     g_have;

static opl3_chip g_opl;
static u8        g_opl_reg = 0;     /* last index written to 0x388/0x188 */
static bool      g_opl_ready = false;

/* --- 8253 PIT channel 2 / speaker state --- */
static u16  g_pit_div = 0;          /* channel 2 divisor (0 => silent)     */
static u8   g_pit_access = 3;       /* 1=lo, 2=hi, 3=lo/hi                 */
static u8   g_pit_lo = 0;
static bool g_pit_hi_next = false;
static u8   g_ppi61 = 0;            /* last byte written to port 0x61      */

/* --- square wave phase --- */
static double g_sq_phase = 0.0;

/* ------------------------------------------------------------------ */

static double spk_frequency(void)
{
    double f;
    if ((g_ppi61 & 0x03) != 0x03 || g_pit_div == 0)
        return 0.0;
    f = 1193182.0 / (double)g_pit_div;
    if (f > RAD_SAMPLE_RATE / 2.0)      /* clamp above Nyquist to avoid alias */
        f = RAD_SAMPLE_RATE / 2.0;
    if (f < 1.0)
        f = 1.0;
    return f;
}

static void audio_callback(void *userdata, Uint8 *stream, int len)
{
    float *out = (float *)stream;
    int frames = len / (int)(sizeof(float) * 2);
    int i;
    double freq;

    (void)userdata;

    freq = spk_frequency();

    for (i = 0; i < frames; i++) {
        int16_t o[2];
        double l, r, sq = 0.0;

        if (g_opl_ready) {
            OPL3_GenerateResampled(&g_opl, o);
            l = (double)o[0] / 32768.0 * OPL_GAIN;
            r = (double)o[1] / 32768.0 * OPL_GAIN;
        } else {
            l = r = 0.0;
        }

        if (freq > 0.0) {
            g_sq_phase += freq / (double)RAD_SAMPLE_RATE;
            if (g_sq_phase >= 1.0)
                g_sq_phase -= (double)(long)g_sq_phase;
            sq = (g_sq_phase < 0.5) ? SPK_AMP : -SPK_AMP;
        }

        l = (l + sq) * MASTER_VOL;
        r = (r + sq) * MASTER_VOL;
        if (l >  1.0) l =  1.0;
        if (l < -1.0) l = -1.0;
        if (r >  1.0) r =  1.0;
        if (r < -1.0) r = -1.0;

        out[i * 2 + 0] = (float)l;
        out[i * 2 + 1] = (float)r;
    }
}

void pal_audio_init(void)
{
    SDL_AudioSpec want;

    memset(&want, 0, sizeof(want));
    want.freq = RAD_SAMPLE_RATE;
    want.format = AUDIO_F32SYS;
    want.channels = 2;
    want.samples = RAD_AUDIO_SAMPLES;
    want.callback = audio_callback;
    want.userdata = NULL;

    memset(&g_opl, 0, sizeof(g_opl));
    OPL3_Reset(&g_opl, RAD_SAMPLE_RATE);
    g_opl_ready = true;

    g_adev = SDL_OpenAudioDevice(NULL, 0, &want, &g_have, 0);
    if (g_adev != 0)
        SDL_PauseAudioDevice(g_adev, 0);
}

void pal_audio_shutdown(void)
{
    if (g_adev != 0) {
        SDL_CloseAudioDevice(g_adev);
        g_adev = 0;
    }
}

/* ------------------------------------------------------------------ */
/* ports                                                               */
/* ------------------------------------------------------------------ */

void pal_audio_outport(u16 port, u8 val)
{
    if (g_adev != 0)
        SDL_LockAudioDevice(g_adev);

    switch (port) {
    case 0x388:
    case 0x188:                 /* guessed alias of the AdLib index port */
        g_opl_reg = val;
        break;

    case 0x389:
    case 0x189:                 /* guessed alias of the AdLib data port */
        if (g_opl_ready)
            OPL3_WriteRegBuffered(&g_opl, (uint16_t)g_opl_reg, val);
        break;

    case 0x43:                  /* 8253 control word */
        if (((val >> 6) & 0x03) == 0x02) {          /* channel 2 */
            g_pit_access = (u8)((val >> 4) & 0x03);
            if (g_pit_access == 0)
                g_pit_access = 3;
            g_pit_hi_next = false;
        }
        break;

    case 0x42:                  /* channel 2 counter data */
        if (g_pit_access == 3) {
            if (!g_pit_hi_next) {
                g_pit_lo = val;
                g_pit_hi_next = true;
            } else {
                g_pit_div = (u16)(((u16)val << 8) | g_pit_lo);
                g_pit_hi_next = false;
            }
        } else if (g_pit_access == 1) {
            g_pit_div = (u16)((g_pit_div & 0xFF00u) | val);
        } else { /* access == 2 */
            g_pit_div = (u16)(((u16)val << 8) | (g_pit_div & 0x00FFu));
        }
        break;

    case 0x40:
    case 0x41:
        /* channels 0/1 are unused by the PC speaker; ignored */
        break;

    case 0x61:                  /* PPI: bits 0/1 gate the speaker */
        g_ppi61 = val;
        break;

    default:
        break;
    }

    if (g_adev != 0)
        SDL_UnlockAudioDevice(g_adev);
}

u8 pal_audio_inport(u16 port)
{
    switch (port) {
    case 0x388:
    case 0x188:
        /* AdLib/OPL2 status: idle, IRQ and both timer flags clear. */
        return 0x00;
    case 0x389:
    case 0x189:
        return 0x00;
    case 0x40:
    case 0x41:
    case 0x42:
        return 0x00;            /* PIT counter reads unsupported -> 0 */
    case 0x61:
        return 0x00;            /* PPI read unsupported -> 0 */
    default:
        return 0x00;
    }
}
