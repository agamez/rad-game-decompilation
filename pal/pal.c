/* pal.c — RAD Linux port: lifecycle + x86 I/O port dispatch.
 *
 * The recovered RAD code keeps its literal port numbers and calls
 * pal_outport()/pal_inport().  This file owns SDL_Init/Shutdown, routes
 * each port to the sub-system that emulates it, and exposes the
 * pal_get_sdl_version() diagnostic used by the headless test.
 *
 * Port map (see the individual emulation sites for rationale):
 *   0x3BA / 0x3DA        VGA input status 1  -> video.c (retrace + pacing)
 *   0x3C7/0x3C8/0x3C9    VGA DAC palette      -> video.c
 *   0x40..0x43,0x61      PIT ch2 + speaker    -> audio.c
 *   0x388/0x389/0x188/0x189 AdLib (OPL2) bus  -> audio.c
 *   anything else        out = ignored, in = 0 (documented default)
 */
#include <SDL2/SDL.h>

#include "pal.h"
#include "pal_internal.h"

void pal_init(void)
{
    /* SDL is used for video, keyboard and audio only. */
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    pal_video_init();   /* window + renderer + streaming texture + 128 KiB shadow */
    pal_input_init();
    pal_audio_init();
    pal_dos_init();
}

void pal_shutdown(void)
{
    pal_audio_shutdown();
    pal_input_shutdown();
    pal_video_shutdown();
    SDL_Quit();
}

/* SDL_QUIT is observed by the input pump; the flag lives in input.c. */
bool pal_quit_requested(void)
{
    pal_input_pump();
    return pal_input_quit_flag();
}

/* ---- x86 I/O ports ---------------------------------------------------- */

void pal_outport(u16 port, u8 val)
{
    switch (port) {
    case 0x3C7: case 0x3C8: case 0x3C9:
        pal_video_outport(port, val);
        return;
    case 0x40: case 0x41: case 0x42: case 0x43:   /* 8253 PIT + speaker */
    case 0x61:                                    /* PPI speaker gate    */
    case 0x388: case 0x389: case 0x188: case 0x189: /* AdLib/OPL2 bus     */
        pal_audio_outport(port, val);
        return;
    default:
        /* Unknown/unimplemented port: ignored.  This deliberately includes
         * the Sound Blaster DSP/mixer ports (0x2xx) so that the original
         * "Sound Blaster detect" probe fails and the game falls back to the
         * AdLib path, which is what this port emulates. */
        return;
    }
}

u8 pal_inport(u16 port)
{
    switch (port) {
    case 0x3BA: case 0x3DA:                 /* VGA input status 1 */
    case 0x3C7: case 0x3C8: case 0x3C9:     /* DAC palette        */
        return pal_video_inport(port);
    case 0x40: case 0x41: case 0x42:        /* PIT counters (read 0) */
    case 0x61:                              /* PPI (read 0)          */
    case 0x388: case 0x389:                 /* AdLib status/data     */
    case 0x188: case 0x189:                 /* see audio.c guess     */
        return pal_audio_inport(port);
    default:
        return 0;
    }
}

/* Diagnostic helper (see pal.h contract extensions). */
void pal_get_sdl_version(int *major, int *minor, int *patch)
{
    SDL_version v;
    SDL_GetVersion(&v);
    if (major) *major = v.major;
    if (minor) *minor = v.minor;
    if (patch) *patch = v.patch;
}
