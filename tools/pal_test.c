/* pal_test.c — headless smoke test for the RAD platform abstraction layer.
 *
 * Exercises: pal_init, BIOS mode set (13h), the 128 KiB VGA shadow, the DAC
 * palette ports (0x3C8/0x3C9), pal_video_present and pal_shutdown.  Run with
 * SDL_VIDEODRIVER=dummy SDL_AUDIODRIVER=dummy; expected output ends in
 * "PAL OK" and the process exits 0.
 *
 * No SDL headers are used here: SDL is confined to pal/, so the SDL version is
 * queried through the pal_get_sdl_version() diagnostic.
 */
#include <stdio.h>
#include <time.h>

#include "pal.h"

int main(void)
{
    u8 *fb;
    int x, y, i;
    int vmajor = 0, vminor = 0, vpatch = 0;
    clock_t start;

    pal_init();

    bios_video_set_mode(0x13);
    fb = pal_vga_memory();

    /* 320x200 gradient into the shadow framebuffer (row stride 320). */
    for (y = 0; y < 200; y++) {
        for (x = 0; x < 320; x++) {
            fb[y * 320 + x] = (u8)((x + y) & 0xFF);
        }
    }

    /* Grayscale palette through the DAC ports: 6-bit v = i/4. */
    pal_outport(0x3C8, 0x00);
    for (i = 0; i < 256; i++) {
        u8 v = (u8)(i >> 2);
        pal_outport(0x3C9, v);
        pal_outport(0x3C9, v);
        pal_outport(0x3C9, v);
    }

    pal_video_present();

    /* Wait ~500 ms without depending on SDL. */
    start = clock();
    while ((clock() - start) * 1000 / CLOCKS_PER_SEC < 500)
        ;

    pal_get_sdl_version(&vmajor, &vminor, &vpatch);
    printf("SDL version: %d.%d.%d\n", vmajor, vminor, vpatch);
    printf("PAL OK\n");

    pal_shutdown();
    return 0;
}
