/* seg0C74_part5.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 5a of N: function 0C74:1B3B (the rocket/explosion trajectory animation).
 *
 * Literal recovery from analysis/slices/0C74/0C74_1B3B.asm (ground truth) and
 * the Reko slice 0C74_1B3B.c; frozen prototype from src/seg0C74.h
 * (analysis/summary/iface.tsv) adopted exactly:
 *
 *   u16 engine_rocket_trajectory(void * dsOut)
 *
 * See CONVENTIONS.md, analysis/SEGMAP.md and docs/notes-0C74.md ("## part 5a").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   NONE directly.  No `int 10h/16h/21h`, no raw `in`/`out` port instruction,
 *   no __cli/__sti and no int 23h occur in 1B3B.  Every hardware-touching
 *   operation is reached indirectly through already-ported callees
 *   (fn1AB8_*, engine_clock_tick/070D, fn1EDA_096F/098A/023F/0254).
 *
 * Flat-model / ABI adaptations (recorded in docs/notes-0C74.md "## part 5a"):
 *   - Reko's `bp_139`/`bp_240` frame-pointer locals (re-bound after each call
 *     to engine_scale_and_tick_clock / 02D8 / 0FA1, whose AX return is the caller's saved BP)
 *     are this function's own frame.  They are folded back onto the literal
 *     stack locals below ([bp-01h] counter, [bp-06h]/[bp-04h] far block), per
 *     the notes-0C74.md part 1 convention.
 *   - The 16:16 far block allocated by fn1EDA_023F is carried as a `u32`
 *     (offset | segment<<16, low word at the lower address, matching
 *     `[bp-06h]/[bp-04h]`) and materialised with `far_ptr(dw)` at the
 *     call sites, the same convention as seg0800_part3.c / seg1229_part1.c.
 *   - renamed_1eda_098a's frozen `void * dsOut` receives a `void *` local (`dsv`)
 *     because the callee stores a full pointer; engine_scale_and_tick_clock's `void * dsOut`
 *     receives the `u16` scratch (`dsTmp`), matching seg0C74_part2.c.
 *   - fn1EDA_023F / 0254 / 098A require stack words the original never pushes
 *     (leftover-stack / far-return-address words read only on the fatal
 *     dispatcher path); they are seeded 0 (part 1 / part 4 convention).
 *   - Saved-BP / DGROUP-selector register outputs have no flat-C equivalent:
 *     the out pointers receive 0 and the artifact return is 0.
 */

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C74.h"
#include "seg1AB8.h"
#include "seg1EDA.h"

// 0C74:1B3B: u16 engine_rocket_trajectory(void * dsOut)
//
// Animate the window at DGROUP 0x58B4/0x58B6/0x58B8/0x58BA one row at a time,
// bouncing the frame block between the two row bounds, then run the
// direction-dependent column sweeps and hand off to engine_per_frame_muck.
u16 engine_rocket_trajectory /* was fn0C74_1B3B */(void *dsOut)
{
	u8  bCount = 0x00;         /* [bp-01h] loop counter (Reko [bp_139-1]) */
	u32 dwBlock = 0x00000000;  /* [bp-06h]/[bp-04h] far block, off|seg<<16 */
	u8  dlTmp = 0x00;          /* bgi_draw_line dlOut scratch */
	void *dsv = NULL;          /* engine_scale_and_tick_clock / renamed_1eda_098a dsOut scratch */
	u16 dsTmp = 0x0000;        /* engine_clock_tick / fn1EDA_023F/0254 dsOut (u16) */
	u16 dxTmp = 0x0000;        /* renamed_1eda_0254 dxOut */
	u16 bpTmp = 0x0000;        /* engine_redraw_bars_down/0D43 bpOut, engine_per_frame_muck bpOut */
	s16 cxT = 0;               /* renamed_1eda_098a cxOut */
	s16 dxT = 0;               /* renamed_1eda_098a dxOut */
	s16 bxT = 0;               /* renamed_1eda_098a bxOut */

	/* --- 0C74:1B3B prologue: three pixels (colors 3,1,1) ---------------- */
	(void)bgi_get_line_attributes(0x03, (u16)(LG16(0x58B8) + 0x001C),
	                  (u16)(LG16(0x58B4) + 0x0017));
	(void)bgi_get_line_attributes(0x01, (u16)(LG16(0x58B8) + 0x001C),
	                  (u16)(LG16(0x58B4) + 0x0018));
	(void)bgi_get_line_attributes(0x01, (u16)(LG16(0x58B8) + 0x001C),
	                  (u16)(LG16(0x58B4) + 0x0019));

	/* --- 0C74:1B99: size and allocate the backing block, paint it ------- */
	LG16(0x595E) = bgi_clamp_rectangle_coords((u16)(LG16(0x58B8) + 0x001C),
	                           (u16)(LG16(0x58B4) + 0x002B),
	                           LG16(0x58B8), LG16(0x58B4));
	dwBlock = fn1EDA_023F(LG16(0x595E), 0x0000, 0x0000, &dsTmp);
	bgi_draw_clip_rectangle(far_ptr(dwBlock),
	            (u16)(LG16(0x58B8) + 0x001C),
	            (u16)(LG16(0x58B4) + 0x002B),
	            LG16(0x58B8), LG16(0x58B4));

	/* --- 0C74:1BCF: loop A: descend while the probes are clear ---------- */
	bCount = 0x00;
	while (bCount < 0x58)
	{
		if (bgi_draw_line((u16)(LG16(0x58B8) - 0x0001), LG16(0x58B4),
		                &dlTmp) != 0x00)
			break;
		if (bgi_draw_line((u16)(LG16(0x58B8) - 0x0001), LG16(0x58B6),
		                &dlTmp) != 0x00)
			break;
		(void)engine_scale_and_tick_clock(0x000A, 0x00C8, &dsTmp);
		LG16(0x58B8) = (u16)(LG16(0x58B8) - 0x0001);
		bgi_signed_rectangle_intersect(0x00, far_ptr(dwBlock), LG16(0x58B8),
		            LG16(0x58B4));
		++bCount;
	}
	{
		static int tr = -1;
		if (tr < 0) tr = (getenv("RAD_ROBOT_TRACE") != NULL);
		if (tr) fprintf(stderr, "ROBOT 1B3B after rise: bCount=%u B4=%u B8=%u 5968=%d\n",
		                bCount, LG16(0x58B4), LG16(0x58B8), (int)LG16(0x5968));
	}

	/* --- 0C74:1C1E: tick (098A(4, 096F(...)) -> 02D8) ------------------- */
	cxT = 0; dxT = 0; bxT = 0; dsv = NULL;
	(void)engine_clock_tick((u16)renamed_1eda_098a(0x0004,
	        fn1EDA_096F(LG16(0x4D0C), LG16(0x58E6), 0x0000,
	                    (u16)(s16)LG16(0x58E6)),
	        0x0000, 0x0000, &cxT, &dxT, &bxT, &dsv), &dsTmp);

	/* --- 0C74:1C3E: loop B: rise back while the counter is positive ----- */
	while (bCount > 0x00)
	{
		if (bgi_draw_line((u16)(LG16(0x58B8) + 0x002C),
		                (u16)(LG16(0x58B4) - 0x0001), &dlTmp) != 0x00)
			break;
		if (bgi_draw_line((u16)(LG16(0x58B8) + 0x002C),
		                (u16)(LG16(0x58B6) + 0x0001), &dlTmp) != 0x00)
			break;
		(void)engine_scale_and_tick_clock(0x000A, 0x00C8, &dsTmp);
		LG16(0x58B8) = (u16)(LG16(0x58B8) + 0x0001);
		bgi_signed_rectangle_intersect(0x00, far_ptr(dwBlock), LG16(0x58B8),
		            LG16(0x58B4));
		--bCount;
	}

	/* --- 0C74:1C93: counter exhausted? free; else run the sweeps -------- */
	if (bCount == 0x00)
	{
		/* 1C99: nothing left to animate; release the block. */
		(void)renamed_1eda_0254(LG16(0x595E), (u16)((dwBlock) & 0xFFFFu), (u16)((dwBlock) >> 16), 0, &dxTmp, &dsTmp);
	}
	else
	{
		/* 1CAB: direction-dependent column sweep. */
		if (LG16(0x5968) == 0x0001)
		{
			/* 1CB2 */
			(void)engine_clock_tick(0x00C8, &dsTmp);
			(void)engine_redraw_bars_up(0x15, &bpTmp, &dsTmp);
			(void)engine_clock_tick(0x00C8, &dsTmp);
			(void)engine_redraw_bars_down(0x15, &bpTmp, &dsTmp);
			(void)engine_clock_tick(0x00C8, &dsTmp);
			(void)engine_redraw_bars_up(0x0B, &bpTmp, &dsTmp);
		}
		else
		{
			/* 1CD5 */
			(void)engine_clock_tick(0x00C8, &dsTmp);
			(void)engine_redraw_bars_down(0x15, &bpTmp, &dsTmp);
			(void)engine_clock_tick(0x00C8, &dsTmp);
			(void)engine_redraw_bars_up(0x15, &bpTmp, &dsTmp);
			(void)engine_clock_tick(0x00C8, &dsTmp);
			(void)engine_redraw_bars_down_15(0x0B, &dsTmp);
		}

		/* 1CF6: repaint the window, then hand back to the frame engine. */
		bgi_draw_clip_rectangle(far_ptr(dwBlock),
		            (u16)(LG16(0x58B8) + 0x001C),
		            (u16)(LG16(0x58B4) + 0x002B),
		            LG16(0x58B8), LG16(0x58B4));
		if (engine_per_frame_muck(&bpTmp, &dsTmp) == 0x00)
		{
			/* 1D1D: rise once more while the counter is positive. */
			while (bCount > 0x00)
			{
				(void)engine_scale_and_tick_clock(0x000A, 0x00C8, &dsTmp);
				LG16(0x58B8) = (u16)(LG16(0x58B8) + 0x0001);
				bgi_signed_rectangle_intersect(0x00, far_ptr(dwBlock),
				            LG16(0x58B8), LG16(0x58B4));
				--bCount;
			}
		}

	/* 1D48: release the block. */
		(void)renamed_1eda_0254(LG16(0x595E), (u16)((dwBlock) & 0xFFFFu), (u16)((dwBlock) >> 16), 0, &dxTmp, &dsTmp);

		if (LG8(0x58B3) == 0x00)
		{
			static int tr2 = -1;
			if (tr2 < 0) tr2 = (getenv("RAD_ROBOT_TRACE") != NULL);
			if (tr2) fprintf(stderr, "ROBOT 1B3B after 0FA1: B4=%u B8=%u 5968=%d 58B3=%d\n",
			                 LG16(0x58B4), LG16(0x58B8), (int)LG16(0x5968), (int)LG8(0x58B3));
			/* 1D60: final tick and direction-dependent sweep. */
			cxT = 0; dxT = 0; bxT = 0; dsv = NULL;
			(void)engine_clock_tick((u16)renamed_1eda_098a(0x0004,
			        fn1EDA_096F(LG16(0x4D0C), LG16(0x58E6), 0x0000,
			                    (u16)(s16)LG16(0x58E6)),
			        0x0000, 0x0000, &cxT, &dxT, &bxT, &dsv), &dsTmp);
			if (LG16(0x5968) == 0x0001)
				(void)engine_redraw_bars_up_15(0x0B, &dsTmp);
			else
				(void)engine_redraw_bars_down(0x0B, &bpTmp, &dsTmp);
		}
	}

	/* 0C74:1D93: epilogue.  The original leaves AX = the saved-BP frame word
	 * (Reko `(ss->*bp_240.u3).t0000.u2`); the flat model writes 0. */
	*(u16 *)dsOut = 0x0000;
	return 0x0000;
}
