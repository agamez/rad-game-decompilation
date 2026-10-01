/* globals.c — DGROUP and segment images. Generated skeleton; symbol names
 * for individual DGROUP variables live in analysis/summary/globals.tsv and
 * are adopted gradually during recovery (LG macros keep offsets literal). */
#include "globals.h"
#include "pal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double g_game_speed = 1.0;   /* -s/--speed command line; see globals.h */

u8 g_dgroup[0x10000] __attribute__((aligned(65536)));

u8 g_seg0800[] __attribute__((aligned(65536)));
u8 g_seg0C43[] __attribute__((aligned(65536)));
u8 g_seg0C74[] __attribute__((aligned(65536)));
u8 g_seg11C8[] __attribute__((aligned(65536)));
u8 g_seg1206[] __attribute__((aligned(65536)));
u8 g_seg1229[] __attribute__((aligned(65536)));
u8 g_seg133F[] __attribute__((aligned(65536)));
u8 g_seg13C1[] __attribute__((aligned(65536)));
u8 g_seg13C8[] __attribute__((aligned(65536)));
u8 g_seg13E2[] __attribute__((aligned(65536)));
u8 g_seg1AB8[] __attribute__((aligned(65536)));
u8 g_seg1E5F[] __attribute__((aligned(65536)));
u8 g_seg1E78[] __attribute__((aligned(65536)));
u8 g_seg1EDA[] __attribute__((aligned(65536)));

static void load_one(const char *dir, const char *name, void *dst, size_t len)
{
    char path[512];
    snprintf(path, sizeof path, "%s/segments/%s", dir, name);
    FILE *f = fopen(path, "rb");
    if (!f) { fprintf(stderr, "rad: cannot open %s\n", path); exit(1); }
    if (fread(dst, 1, len, f) != len) { fprintf(stderr, "rad: short read %s\n", path); exit(1); }
    fclose(f);
}

void rad_load_images(void)
{
    const char *dir = getenv("RAD_DATA");
    if (!dir || !*dir) dir = "data";
    load_one(dir, "dgroup_data.bin", g_dgroup, 0x5390);
    load_one(dir, "seg0800.bin", g_seg0800, 0x4430);
    load_one(dir, "seg0C43.bin", g_seg0C43, 0x0310);
    load_one(dir, "seg0C74.bin", g_seg0C74, 0x5540);
    load_one(dir, "seg11C8.bin", g_seg11C8, 0x03E0);
    load_one(dir, "seg1206.bin", g_seg1206, 0x0230);
    load_one(dir, "seg1229.bin", g_seg1229, 0x1160);
    load_one(dir, "seg133F.bin", g_seg133F, 0x0820);
    load_one(dir, "seg13C1.bin", g_seg13C1, 0x0070);
    load_one(dir, "seg13C8.bin", g_seg13C8, 0x01A0);
    load_one(dir, "seg13E2.bin", g_seg13E2, 0x6D60);
    load_one(dir, "seg1AB8.bin", g_seg1AB8, 0x3A70);
    load_one(dir, "seg1E5F.bin", g_seg1E5F, 0x0190);
    load_one(dir, "seg1E78.bin", g_seg1E78, 0x0620);
    load_one(dir, "seg1EDA.bin", g_seg1EDA, 0x13A0);
    /* The original loads Borland's EGAVGA.BGI from disk (the Turbo C
     * distribution); the archive embeds the identical driver in segment
     * 13E2 at offset 0x278 (5554 bytes, "pk\x08\x08BGI Device Driver
     * (EGAVGA)...").  Materialize it next to the other data files so the
     * recovered file-based loading path works verbatim, and register the
     * game's mode byte with the PAL for the driver's set-mode function. */
    {
        const char *dir2 = getenv("RAD_DATA");
        char path[512];
        FILE *f;
        if (!dir2 || !*dir2) dir2 = "data";
        snprintf(path, sizeof path, "%s/EGAVGA.BGI", dir2);
        f = fopen(path, "rb");
        if (!f) {
            f = fopen(path, "wb");
            if (f) { fwrite(g_seg13E2 + 0x278, 1, 5554, f); fclose(f); }
        } else fclose(f);
    }
    pal_set_mode_byte(&LG8(0xB8A3));
}

/* ---- 16:16 far-pointer mapping (see globals.h) ---- */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Lazily-created 64 KiB arenas for every segment that is not part of the
 * loaded image (the far heap allocated by fn1EDA_023F lives here). */
static u8 *g_arena_tab[0x10000];

/* Reverse mapping: host pointer -> the 16-bit segment it belongs to.
 * The draw wrappers re-stage ES:BX register images from materialized host
 * pointers; arenas are 64 KiB aligned so the offset half is simply the low
 * 16 bits, but the segment number only exists in g_arena_tab. */
u16 far_seg_of(const void *host)
{
    uintptr_t p = (uintptr_t)host;
    static const struct { u16 seg; const u8 *base; } img[] = {
        { 0x2014, g_dgroup }, { 0x0800, g_seg0800 }, { 0x0C43, g_seg0C43 },
        { 0x0C74, g_seg0C74 }, { 0x11C8, g_seg11C8 }, { 0x1206, g_seg1206 },
        { 0x1229, g_seg1229 }, { 0x133F, g_seg133F }, { 0x13C1, g_seg13C1 },
        { 0x13C8, g_seg13C8 }, { 0x13E2, g_seg13E2 }, { 0x1AB8, g_seg1AB8 },
        { 0x1E5F, g_seg1E5F }, { 0x1E78, g_seg1E78 }, { 0x1EDA, g_seg1EDA },
    };
    for (size_t i = 0; i < sizeof(img) / sizeof(img[0]); i++)
        if (p >= (uintptr_t)img[i].base && p < (uintptr_t)img[i].base + 0x10000)
            return img[i].seg;
    for (u32 seg = 0; seg < 0x10000; seg++)
        if (g_arena_tab[seg] &&
            p >= (uintptr_t)g_arena_tab[seg] &&
            p <  (uintptr_t)g_arena_tab[seg] + 0x10000)
            return (u16)seg;
    return 0x0000;
}

void *far_ptr(u32 fp16)
{
    u16 off = (u16)(fp16 & 0xFFFF);
    u16 seg = (u16)(fp16 >> 16);
    switch (seg) {
    case 0x2014: return g_dgroup + off;
    case 0x0800: return g_seg0800 + off;
    case 0x0C43: return g_seg0C43 + off;
    case 0x0C74: return g_seg0C74 + off;
    case 0x11C8: return g_seg11C8 + off;
    case 0x1206: return g_seg1206 + off;
    case 0x1229: return g_seg1229 + off;
    case 0x133F: return g_seg133F + off;
    case 0x13C1: return g_seg13C1 + off;
    case 0x13C8: return g_seg13C8 + off;
    case 0x13E2: return g_seg13E2 + off;
    case 0x1AB8: return g_seg1AB8 + off;
    case 0x1E5F: return g_seg1E5F + off;
    case 0x1E78: return g_seg1E78 + off;
    case 0x1EDA: return g_seg1EDA + off;
    default: {
        u8 *a = g_arena_tab[seg];
        if (!a) {
            if (posix_memalign((void **)&a, 65536, 0x10000) != 0)
                a = 0;
            if (!a) { fprintf(stderr, "rad: far_ptr OOM seg %04X\n", seg); return g_dgroup + off; }
            memset(a, 0, 0x10000);
            g_arena_tab[seg] = a;
        }
        return a + off;
    }
    }
}
