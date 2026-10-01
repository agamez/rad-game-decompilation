/* globals.h — RAD V3.1 memory model (see CONVENTIONS.md, analysis/SEGMAP.md).
 *
 * DGROUP (original segment 2014) is a flat 64 KiB image. Reko's
 * `Mem[ds:off:type]` references become the LG macros below — offsets stay
 * literal so aliases and pointer arithmetic behave exactly as in the EXE.
 * _DATA (0x0000..0x5390) is loaded from data/segments/dgroup_data.bin by
 * rad_load_images(); _BSS is zero-initialized (static storage).
 */
#ifndef RADGLOBALS_H
#define RADGLOBALS_H

#include "radtypes.h"

/* Global game-time multiplier (command line -s/--speed): 1.0 = original
 * speed, 2.0 = everything (movement animation, game clock countdown,
 * timed sequences) runs twice as fast in wall time.  Applied ONLY at the
 * two game-time -> host-time conversion points (fn1E78_pace_ns and
 * fn0800_timer_service); no game logic, score or replay semantics change. */
extern double g_game_speed;

extern u8 g_dgroup[0x10000] __attribute__((aligned(65536)));

#define LG8(off)   (*(u8  *)&g_dgroup[(off)])
#define LG16(off)  (*(u16 *)&g_dgroup[(off)])
#define LG32(off)  (*(u32 *)&g_dgroup[(off)])
#define LG64(off)  (*(u64 *)&g_dgroup[(off)])

/* Code segments and their embedded data (file image bytes, per SEGMAP). */
extern u8 g_seg0800[] __attribute__((aligned(65536)));
extern u8 g_seg0C43[] __attribute__((aligned(65536)));
extern u8 g_seg0C74[] __attribute__((aligned(65536)));
extern u8 g_seg11C8[] __attribute__((aligned(65536)));
extern u8 g_seg1206[] __attribute__((aligned(65536)));
extern u8 g_seg1229[] __attribute__((aligned(65536)));
extern u8 g_seg133F[] __attribute__((aligned(65536)));
extern u8 g_seg13C1[] __attribute__((aligned(65536)));
extern u8 g_seg13C8[] __attribute__((aligned(65536)));
extern u8 g_seg13E2[] __attribute__((aligned(65536)));
extern u8 g_seg1AB8[] __attribute__((aligned(65536)));
extern u8 g_seg1E5F[] __attribute__((aligned(65536)));
extern u8 g_seg1E78[] __attribute__((aligned(65536)));
extern u8 g_seg1EDA[] __attribute__((aligned(65536)));

/* Load _DATA and segment images from the data directory (what the DOS
 * loader did). Exits with a message if files are missing. */
void rad_load_images(void);

#endif /* RADGLOBALS_H */

/* ---- flat mapping of original 16:16 far pointers (off | seg<<16) ----
 * Known image segments map to their arrays; any other segment (the far
 * heap, allocated by fn1EDA_023F beyond the loaded image) maps to a
 * lazily-created 64 KiB arena so the recovered loader/copy code runs
 * unmodified.  Defined in globals.c. */
void *far_ptr(u32 fp16);
u16   far_seg_of(const void *host);   /* host ptr -> its 16-bit segment */
#define FAR_PTR(seg, off) ((u32)(u16)(off) | ((u32)(u16)(seg) << 16))
