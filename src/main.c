/* main.c — host entry point for the RAD V3.1 Linux port.
 *
 * Replaces the DOS program loader: loads the segment images into the flat
 * memory model (what the DOS loader did), initializes the SDL platform
 * layer, fabricates a minimal PSP (program segment prefix) with the
 * command tail, and calls the recovered CRT entry fn0800_4255.
 *
 * Original entry point (from the MZ header): e_ip=0x4255, e_cs=0 relative
 * to load base 0x0800 -> segment 0800, offset 4255 (see analysis/SEGMAP.md).
 */
#include "globals.h"
#include "seg0800.h"
#include "pal.h"
#include <stdio.h>
#include <string.h>

static u8 g_psp[256];

/* Build a minimal DOS PSP. Only the fields the recovered code reads:
 *   [0x00] int 20h (CD 20)
 *   [0x02] word  segment past end of allocation (memtop paragraph)
 *   [0x80] byte  command tail length
 *   [0x81..]     command tail, terminated by 0x0D
 */
static void build_psp(int argc, char **argv)
{
    memset(g_psp, 0, sizeof g_psp);
    g_psp[0] = 0xCD; g_psp[1] = 0x20;
    g_psp[2] = 0xFF; g_psp[3] = 0x9F;              /* memtop = 0x9FFF paragraphs (640K) */
    {
        int total = 0;
        for (int i = 1; i < argc; i++) {
            size_t l = strlen(argv[i]);
            if (total + l + 1 > 125) break;
            if (i > 1) g_psp[0x81 + total++] = ' ';
            memcpy(&g_psp[0x81 + total], argv[i], l);
            total += (int)l;
        }
        g_psp[0x80] = (u8)total;
        g_psp[0x81 + total] = 0x0D;
    }
}


/* ---- diagnostic (RAD_DUMP_SECS env): dump framebuffer+palette, exit ----
 * Used for headless behavioral verification against DOSBox reference
 * captures.  Compiled in but inert unless RAD_DUMP_SECS is set. */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

static void rad_dump_handler(int sig)
{
    (void)sig;
    {
        const char *fb = "/tmp/opencode/fb.bin";
        static u8 frame[320 * 200];
        pal_composed_frame(frame);
        FILE *f = fopen(fb, "wb");
        if (f) { fwrite(frame, 1, sizeof(frame), f); fclose(f); }
    }
    {
        /* g_pal lives in pal/video.c; re-derive the effective 8-bit palette
         * by reading the DAC state through the documented ports instead. */
        FILE *f = fopen("/tmp/opencode/done.flag", "w");
        if (f) { fputs("dumped", f); fclose(f); }
    }
    {
        /* raw mode-12h index canvas (640x480, 1 byte/px) for gameplay
         * verification (crate box, robot box, floor probes). */
        extern u8 *pal_vga12_canvas(void);
        u8 *cv = pal_vga12_canvas();
        if (cv) {
            FILE *f = fopen("/tmp/opencode/canvas.bin", "wb");
            if (f) { fwrite(cv, 1, 640u * 480u, f); fclose(f); }
        }
    }
    {
        /* DAC snapshot (256 entries x RGB, 6-bit) for cross-checking the
         * DOSBox captures against canvas indices. */
        FILE *f = fopen("/tmp/opencode/dac.bin", "wb");
        if (f) {
            u8 buf[768];
            int i;
            pal_outport(0x3C7, 0);
            for (i = 0; i < 768; i++)
                buf[i] = pal_inport(0x3C9);
            fwrite(buf, 1, sizeof(buf), f);
            fclose(f);
        }
    }
    _exit(42);
}
/* ---- end diagnostic ---- */

int main(int argc, char **argv)
{
    const char *dumpsecs = getenv("RAD_DUMP_SECS");
    if (dumpsecs) { signal(SIGALRM, rad_dump_handler); alarm((unsigned)atoi(dumpsecs)); }
    pal_init();
    rad_load_images();
    build_psp(argc, argv);
    fn0800_4255(g_psp);          /* recovered CRT entry: init + main loop + exit */
    pal_shutdown();
    return 0;
}
