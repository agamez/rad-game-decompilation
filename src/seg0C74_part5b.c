/* seg0C74_part5b.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 5b of N: function 0C74:1D95.
 *
 * Literal recovery from analysis/slices/0C74/0C74_1D95.asm (ground truth) and
 * the Reko slice 0C74_1D95.c; frozen prototype from src/seg0C74.h
 * (analysis/summary/iface.tsv) adopted exactly:
 *
 *   u16 engine_blit_field_edges(u16 wArg02, void * dsOut)
 *
 * See CONVENTIONS.md, analysis/SEGMAP.md and docs/notes-0C74.md ("## part 5b").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   NONE directly.  No `int 10h/16h/21h`, no raw `in`/`out` port instruction,
 *   no __cli/__sti and no int 23h occur in 1D95.  All hardware work is reached
 *   indirectly through already-ported callees: the 1AB8 video driver
 *   (13A3/13D7/1E6B) and the 1EDA far-heap helpers (023F/0254); engine_scale_and_tick_clock
 *   owns the PC-speaker/AdLib pacing (parts 2/3).
 *
 * Flat-model / ABI adaptations (recorded in docs/notes-0C74.md "## part 5b"):
 *   - `ss:[wArg02-4]` is the CALLER's [bp-4] local, read through the `push bp`
 *     argument at every call site (engine_per_frame_level: 2250/23BA/2518/2A7B).  The
 *     .asm uses that word for a well-defined purpose: it is added to / subtracted
 *     from the [58B4h] Y coordinates of the two rectangles, and its low byte is
 *     the blit-loop counter.  The frozen `u16 wArg02` carries only the pushed BP
 *     word and flat C has no SS:BP chain (cross-part callers seed it 0), so the
 *     read is modelled as the documented constant `wCallerL4 = 0` -- the same
 *     treatment as engine_draw_status_sprites (notes-0C74.md part 3 item 5).
 *   - The 16:16 far blocks returned by fn1EDA_023F are carried as `u32`
 *     (`offset | segment<<16`, low word at the lower address, matching the
 *     original [bp-0Ah]/[bp-08h] and [bp-0Eh]/[bp-0Ch]) and materialised with
 *     `far_ptr(dw)` at the call sites -- the seg0C74_part3/4/6 convention.
 *   - fn1EDA_023F / 0254 take `wArg00`/`wArg02` stack words the original never
 *     pushes (far-return-address / leftover slots, read only on the fatal
 *     divide-by-zero dispatcher path); they are seeded 0.
 *   - `dsOut` / the saved-BP artifact return: flat C has no DGROUP selector and
 *     no BP chain, so `dsOut` receives NULL and the function returns 0.
 */

#include <stddef.h>
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C74.h"
#include "seg1AB8.h"
#include "seg1EDA.h"

// 0C74:1D95: u16 engine_blit_field_edges(u16 wArg02, void * dsOut)
//
// Blit the two caller-indexed field-edge rectangles: build both rects with
// bgi_clamp_rectangle_coords, allocate a far block each (fn1EDA_023F), stamp the rects into the
// blocks (bgi_draw_clip_rectangle), then for the caller-frame offset down to 0 tick
// engine_scale_and_tick_clock(0Ah,0E6h) and blit both blocks with bgi_signed_rectangle_intersect, finally free
// both blocks.  Returns the saved-BP artifact (0 in flat C).
u16 engine_blit_field_edges /* was fn0C74_1D95 */(u16 wArg02, void * dsOut)
{
	u16 wLoc04;              /* [bp-04h] first  bgi_clamp_rectangle_coords result (blk B size) */
	u16 wLoc06;              /* [bp-06h] second bgi_clamp_rectangle_coords result (blk A size) */
	u32 dwLoc0A;             /* [bp-0Ah]/[bp-08h] far block A (023F of wLoc06) */
	u32 dwLoc0E;             /* [bp-0Eh]/[bp-0Ch] far block B (023F of wLoc04) */
	u8  bLoc01;              /* [bp-01h] blit-loop counter */
	u16 dsTmp = 0x0000;      /* reusable u16 dsOut (023F/0254/070D) */
	u16 dxTmp = 0x0000;      /* fn1EDA_0254 dxOut */
	/* ss:[wArg02-4]: the original reads the caller's [bp-4] word through the
	 * pushed BP (`push bp` at every call site).  Flat C has no SS:BP chain, so
	 * -- exactly like the byte-identical twin engine_draw_status_sprites (the UP arm
	 * retraction, fixed in session 6) -- the callers pass their [bp-4] VALUE
	 * directly in wArg02 and it is consumed here.  1F08's band-seal rects and
	 * blit-loop count are built from this index; with 0 the seal degenerates
	 * to a no-op and the marched band keeps the wire/body colour strips. */
	u16 wCallerL4 = wArg02;

	/* 1D95..1DB4: first rect = [58B8h+1Bh, 58B4h+1Dh+N]-[58B8h+0Dh, 58B4h+19h+N] */
	wLoc04 = bgi_clamp_rectangle_coords((u16)(LG16(0x58B8) + 0x001B),
	                     (u16)(LG16(0x58B4) + 0x001D + wCallerL4),
	                     (u16)(LG16(0x58B8) + 0x000D),
	                     (u16)(LG16(0x58B4) + 0x0019 + wCallerL4));
	/* 1DB6..1DDD: second rect = [58B8h+1Bh, 58B4h+11h-N]-[58B8h+0Dh, 58B4h+0Dh-N] */
	wLoc06 = bgi_clamp_rectangle_coords((u16)(LG16(0x58B8) + 0x001B),
	                     (u16)(LG16(0x58B4) + 0x0011 - wCallerL4),
	                     (u16)(LG16(0x58B8) + 0x000D),
	                     (u16)(LG16(0x58B4) + 0x000D - wCallerL4));

	/* push [bp-6h] ; call 023Fh -> DX:AX = block A */
	dwLoc0A = fn1EDA_023F(wLoc06, 0x0000, 0x0000, &dsTmp);
	/* push [bp-4h] ; call 023Fh -> DX:AX = block B */
	dwLoc0E = fn1EDA_023F(wLoc04, 0x0000, 0x0000, &dsTmp);

	/* 1DF7: stamp the first rect into block B (les di,[bp-0Eh]) */
	bgi_draw_clip_rectangle(far_ptr(dwLoc0E),
	            (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(LG16(0x58B4) + 0x001D + wCallerL4),
	            (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x0019 + wCallerL4));
	/* 1E2B: stamp the second rect into block A (les di,[bp-0Ah]) */
	bgi_draw_clip_rectangle(far_ptr(dwLoc0A),
	            (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(LG16(0x58B4) + 0x0011 - wCallerL4),
	            (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x000D - wCallerL4));

	/* mov al,ss:[di-4h] ; or al,al ; jc (never taken) ; blit loop */
	bLoc01 = (u8)wCallerL4;
	for (;;)
	{
		(void)engine_scale_and_tick_clock(0x000A, 0x00E6, &dsTmp);
		/* push (58B4h+19h+c) ; (58B8h+0Dh) ; es:di=block B ; 0 ; 13D7 */
		(void)bgi_signed_rectangle_intersect(0x00,
		                  far_ptr(dwLoc0E),
		                  (u16)(LG16(0x58B8) + 0x000D),
		                  (u16)(LG16(0x58B4) + 0x0019 + bLoc01));
		/* push (58B4h+0Dh-c) ; (58B8h+0Dh) ; es:di=block A ; 0 ; 13D7 */
		(void)bgi_signed_rectangle_intersect(0x00,
		                  far_ptr(dwLoc0A),
		                  (u16)(LG16(0x58B8) + 0x000D),
		                  (u16)(LG16(0x58B4) + 0x000D - bLoc01));
		if (bLoc01 == 0x00)
			break;
		--bLoc01;                /* 1E91: dec byte [bp-1h] */
	}

	/* push [bp-8h] ; push [bp-0Ah] ; push [bp-6h] ; call 0254h */
	(void)fn1EDA_0254(wLoc06, (u16)((dwLoc0A) & 0xFFFFu), (u16)((dwLoc0A) >> 16), 0,
	                  &dxTmp, &dsTmp);
	/* push [bp-0Ch] ; push [bp-0Eh] ; push [bp-4h] ; call 0254h */
	(void)fn1EDA_0254(wLoc04, (u16)((dwLoc0E) & 0xFFFFu), (u16)((dwLoc0E) >> 16), 0,
	                  &dxTmp, &dsTmp);

	*(u16 *)dsOut = 0x0000;  /* DGROUP selector dropped in the flat model */
	return 0x0000;           /* saved-BP artifact; no caller consumes it */
}
