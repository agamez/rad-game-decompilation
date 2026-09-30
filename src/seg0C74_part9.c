/* seg0C74_part9.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 9 of N: functions 0C74:3236 .. 0C74:3615 (2 functions, ascending).
 *
 *   3236 3615
 *
 * Literal recovery from analysis/slices/0C74/0C74_<off>.asm (ground truth)
 * and the Reko slices 0C74_3236.c / 0C74_3615.c; frozen prototypes from
 * src/seg0C74.h (analysis/summary/iface.tsv) adopted exactly:
 *
 *   u8 fn0C74_3236(u16 *bpOut, u16 *dsOut)
 *   u8 fn0C74_3615(u16 *dxOut, u16 *bpOut, u16 *dsOut)
 *
 * See CONVENTIONS.md, analysis/SEGMAP.md and docs/notes-0C74.md ("## part 9").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   NONE directly.  No int 10h / int 16h / int 21h, no raw `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch occur in
 *   3236..3615.  Every hardware-touching action is reached through
 *   already-ported callees: the 1AB8 video driver (13A3/13D7/10F4/1AF6/1C32/
 *   1E3C/1E54/1E6B), the 1EDA far-heap helpers (023F/0254), fn1E78_029C
 *   (keyboard/pacing), fn1E78_02FB (input poll), fn1206_015B (INT 33h mouse
 *   wrapper, seg1206.c), fn11C8_033B/0354 (sound) and the 0C74 helpers
 *   070D/02D8/2BBD/0CFA.
 *
 * Flat-model / ABI adaptations (recorded in docs/notes-0C74.md "## part 9"):
 *   - Reko's bp_XXXX frame-pointer locals (re-bound after each fn0C74_070D /
 *     02D8 call whose AX return is the caller's saved BP) are the current
 *     function's own frame; they are folded back onto the literal locals,
 *     per the part 1 section 3 convention.
 *   - The 16:16 far blocks returned by fn1EDA_023F are carried as u32
 *     (offset | segment<<16, low word at the lower address, matching the
 *     original [bp-0Ch]/[bp-0Ah] and [bp-1Ch]/[bp-1Ah] pairs) and
 *     materialised with far_ptr(dw) at the call sites, the same
 *     convention as parts 2/4/6/7/8.
 *   - fn1EDA_023F / 0254 require two leading stack words the original never
 *     pushes (far-return-address words read only on the fatal divide-by-zero
 *     dispatcher path); they are seeded 0 (part4/part6).
 *   - The far-pointer tables at DGROUP:0x58E4 (4 bytes per entry) are read as
 *     a single u32 and cast to a host pointer, matching parts 2/3/8.
 *   - bpOut / dsOut register outputs are the caller's saved BP and the dropped
 *     DGROUP selector; both receive 0 (part 1 section 3).
 *   - fn0C74_3615's `dxOut` is the DX register left by the last call; Reko
 *     models it across the 1E3C / 13D7 / 11C8:033B returns but no observed
 *     caller (542B / 54B1) reads it.  The flat port writes 0 and records the
 *     loss (same treatment as fn0C74_0000's dxOut, notes-0C74 part 1 section 6).
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
#include "seg1E78.h"
#include "seg11C8.h"
#include "seg1206.h"

// 0C74:3236: u8 fn0C74_3236(u16 * bpOut, u16 * dsOut)
//
// Second game-core "bar" update (sibling of 2E5A).  Five 1E3C edge probes gate
// the body: two 13A3/023F scratch blocks are allocated and stamped, the block #2
// bottom row is cleared, the 0Bh/03h/09h markers are drawn, block #2 is rebuilt
// one row taller, its rows are wiped while the edge probe is clear, both cached
// rows are shrunk 16h times, the bar is collapsed when the latch row is empty,
// the remaining rows are wiped to 0, then the live bar is pulled down 16h rows
// (drawing a DGROUP:0x58E4 sprite per step) and both scratch blocks are freed.
// Returns the [bp-1] byte (0 = gate failed).
u8 fn0C74_3236(u16 *bpOut, u16 *dsOut)
{
	u8  bLoc01 = 0x00;      /* [bp-01h] return flag */
	u8  bLoc02 = 0x00;      /* [bp-02h] row / animation counter */
	u8  bLoc03 = 0x00;      /* [bp-03h] column counter */
	u16 wLoc06 = 0x0000;    /* [bp-06h] scan count (u16 of [bp-02h]) */
	u16 wLoc08 = 0x0000;    /* [bp-08h] [58B4h]+0x1A (block #2 bottom row) */
	u16 wLoc0E = 0x0000;    /* [bp-0Eh] 13A3 size #1 (block #1) */
	u16 wLoc10 = 0x0000;    /* [bp-10h] 13A3 size #2 (block #2, reused) */
	u16 wLoc12 = 0x0000;    /* [bp-12h] [58B6h]++ (shrink walk) */
	u16 wLoc14 = 0x0000;    /* [bp-14h] [58B6h]+16h++ (write-only in asm) */
	u16 wLoc16 = 0x0000;    /* [bp-16h] [58B8h]+0x15 */
	u16 wLoc18 = 0x0000;    /* [bp-18h] [58BAh] */
	u16 dsTmp = 0x0000;     /* reusable u16 dsOut for 023F/0254/02D8 */
	void *dsv = NULL;       /* reusable void * dsOut for 070D */
	u16 dxTmp = 0x0000;     /* 1AF6 / 0254 / 029C dxOut */
	u8  dlTmp = 0x00;       /* 1E3C dlOut */
	u32 blk1 = 0;           /* [bp-0Ah]:[bp-0Ch] block #1 far pointer */
	u32 blk2 = 0;           /* [bp-1Ah]:[bp-1Ch] block #2 far pointer */
	u16 ax_3541;

	/* 3236..3247: cmp word [58B4h],27Eh ; jc 3249h -- only run below 27Eh.
	 * 3249..32AD: the five edge probes gate the whole body (Reko's && chain). */
	if (LG16(0x58B4) < 0x027E &&
	    fn1AB8_1E3C(LG16(0x58BA), (u16)(LG16(0x58B6) + 0x0001), &dlTmp) != 0x00 &&
	    fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x0016),
	                (u16)(LG16(0x58B6) + 0x0001), &dlTmp) != 0x00 &&
	    fn1AB8_1E3C(LG16(0x58BA), (u16)(LG16(0x58B6) + 0x0017), &dlTmp) == 0x00 &&
	    fn1AB8_1E3C(LG16(0x58B8), (u16)(LG16(0x58B6) + 0x0001), &dlTmp) == 0x00 &&
	    fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x0016),
	                (u16)(LG16(0x58B6) + 0x0017), &dlTmp) == 0x00)
	{
		/* 32B0: mov byte [bp-1h],1h */
		bLoc01 = 0x01;

		/* 32B0..32E0: window size #1, then allocate+stamp block #1. */
		wLoc0E = fn1AB8_13A3(LG16(0x58BA), (u16)(LG16(0x58B6) + 0x0016),
		                     (u16)(LG16(0x58B8) + 0x0015), LG16(0x58B6));
		blk1 = fn1EDA_023F(wLoc0E, 0x0000, 0x0000, &dsTmp);
		fn1AB8_1E6B(far_ptr(blk1), LG16(0x58BA),
		            (u16)(LG16(0x58B6) + 0x0016),
		            (u16)(LG16(0x58B8) + 0x0016), LG16(0x58B6));

		/* 32??: window size #2 ([58B8h]+0Dh x [58B4h]+1Dh), then
		 * allocate+stamp block #2. */
		wLoc10 = fn1AB8_13A3((u16)(LG16(0x58B8) + 0x001B),
		                     (u16)(LG16(0x58B4) + 0x001D),
		                     (u16)(LG16(0x58B8) + 0x000D),
		                     (u16)(LG16(0x58B4) + 0x0019));
		blk2 = fn1EDA_023F(wLoc10, 0x0000, 0x0000, &dsTmp);
		fn1AB8_1E6B(far_ptr(blk2),
		            (u16)(LG16(0x58B8) + 0x001B),
		            (u16)(LG16(0x58B4) + 0x001D),
		            (u16)(LG16(0x58B8) + 0x000D),
		            (u16)(LG16(0x58B4) + 0x0019));

		/* 32E1..32F4: clear the bottom row of block #2 at [58B4h]+1Ah. */
		wLoc08 = (u16)(LG16(0x58B4) + 0x001A);
		(void)fn1AB8_13D7(0x00, far_ptr(blk2),
		                  (u16)(LG16(0x58B8) + 0x000D), wLoc08);

		/* 32F7..330A: latch the gfx context and draw the markers. */
		fn1AB8_10F4(0x0001, 0x0000, 0x0000);
		(void)fn1AB8_1C32(0x00);
		(void)fn1AB8_1AF6((u16)(LG16(0x58B8) + 0x001B),
		                  (u16)(LG16(0x58B4) + 0x0019),
		                  (u16)(LG16(0x58B8) + 0x000D),
		                  (u16)(LG16(0x58B4) + 0x0019), &dxTmp);
		fn1AB8_1E54(0x0B, (u16)(LG16(0x58B8) + 0x0012),
		            (u16)(LG16(0x58B4) + 0x0019));
		fn1AB8_1E54(0x03, (u16)(LG16(0x58B8) + 0x0013),
		            (u16)(LG16(0x58B4) + 0x0019));
		fn1AB8_1E54(0x09, (u16)(LG16(0x58B8) + 0x0014),
		            (u16)(LG16(0x58B4) + 0x0019));

		/* 33??: free block #2, then rebuild it one row taller
		 * ([58B4h]+1Eh instead of +1Dh) and stamp it. */
		(void)fn1EDA_0254(wLoc10, (u16)((blk2) & 0xFFFFu), (u16)((blk2) >> 16), 0, &dxTmp, &dsTmp);
		wLoc10 = fn1AB8_13A3((u16)(LG16(0x58B8) + 0x001B),
		                     (u16)(LG16(0x58B4) + 0x001E),
		                     (u16)(LG16(0x58B8) + 0x000D),
		                     (u16)(LG16(0x58B4) + 0x0019));
		blk2 = fn1EDA_023F(wLoc10, 0x0000, 0x0000, &dsTmp);
		fn1AB8_1E6B(far_ptr(blk2),
		            (u16)(LG16(0x58B8) + 0x001B),
		            (u16)(LG16(0x58B4) + 0x001E),
		            (u16)(LG16(0x58B8) + 0x000D),
		            (u16)(LG16(0x58B4) + 0x0019));

		/* 3456..34AA: wipe block #2 rows while the edge probe is clear. */
		bLoc02 = 0x01;
		while (bLoc02 < 0x14)
		{
			if (fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x001B),
			                (u16)(LG16(0x58B4) + 0x001E + bLoc02),
			                &dlTmp) != 0x00)
				break;
			(void)fn0C74_070D(0x000A, 0x00E6, &dsv);
			(void)fn1AB8_13D7(0x00, far_ptr(blk2),
			                  (u16)(LG16(0x58B8) + 0x000D),
			                  (u16)(LG16(0x58B4) + 0x0019 + bLoc02));
			++bLoc02;
		}

		/* 34AC..34D6: latch the scan count and the shrinking rectangle. */
		wLoc06 = (u16)bLoc02;
		wLoc12 = LG16(0x58B6);
		wLoc14 = (u16)(LG16(0x58B6) + 0x0016);
		wLoc16 = (u16)(LG16(0x58B8) + 0x0015);
		wLoc18 = LG16(0x58BA);
		bLoc03 = 0x01;

		/* 34DB..351B: shrink both cached rows 16h times (wLoc14 is
		 * incremented by the asm but never read -- kept literally). */
		while (1)
		{
			wLoc12 = (u16)(wLoc12 + 0x0001);
			wLoc14 = (u16)(wLoc14 + 0x0001);
			(void)fn1AB8_13D7(0x00, far_ptr(blk1),
			                  (u16)(wLoc16 + 0x0001), wLoc12);
			(void)fn1AB8_13D7(0x00, far_ptr(blk2),
			                  (u16)(LG16(0x58B8) + 0x000D),
			                  (u16)(wLoc12 - 0x0005));
			(void)fn0C74_070D(0x0014, 0x00E6, &dsv);
			if (bLoc03 == 0x16)
				break;
			++bLoc03;
		}
		(void)wLoc14;   /* dead store in the original; silences -Wunused */

		/* 351D..3540: if the latch row is empty, collapse the bar. */
		if (fn1AB8_1E3C((u16)(wLoc18 + 0x0001), (u16)(wLoc12 + 0x0001),
		                &dlTmp) == 0x00)
		{
			(void)fn0C74_2BBD(wLoc18, wLoc14, wLoc16,
			                  (u16)(wLoc12 + 0x0001));
		}

		/* 3541..3583: wipe the remaining rows of block #2 down to 0.
		 * The asm computes AX=[bp-6h]+15h then `or al,al ; jc 3584h`.
		 * `or` preserves CF, so the branch tests the preceding ADD's
		 * carry; wLoc06 is a byte value, so the sum never carries and the
		 * block always runs (Reko's `if (true)`). */
		ax_3541 = (u16)(wLoc06 + 0x0015);
		if (!(ax_3541 < wLoc06))
		{
			bLoc03 = (u8)ax_3541;
			while (1)
			{
				(void)fn0C74_070D(0x0005, 0x00E6, &dsv);
				(void)fn1AB8_13D7(0x00, far_ptr(blk2),
				                  (u16)(LG16(0x58B8) + 0x000D),
				                  (u16)(LG16(0x58B4) + 0x0019 + bLoc03));
				if (bLoc03 == 0x00)
					break;
				--bLoc03;
			}
		}

		/* 3584..359A: free block #2, then start the 16h-step pull-in. */
		(void)fn1EDA_0254(wLoc10, (u16)((blk2) & 0xFFFFu), (u16)((blk2) >> 16), 0, &dxTmp, &dsTmp);
		bLoc02 = 0x01;
		bLoc03 = 0x01;

		/* 359F..3600: pull the bar down 16h rows, cycling bLoc02 5..1 and
		 * drawing table[58E4h + bLoc02*4]. */
		while (1)
		{
			(void)fn1E78_029C((u16)((s16)LG16(0x58E6) / 0x0002), &dxTmp);
			(void)fn0C74_02D8(0x000A, &dsTmp);
			++bLoc02;
			if (bLoc02 == 0x05)
			{
				bLoc02 = 0x01;
				if (LG8(0x58B0) != 0x00)
					fn11C8_0354(0x0032);
			}
			else
				(void)fn11C8_033B();
			LG16(0x58B4) = (u16)(LG16(0x58B4) + 0x0001);
			LG16(0x58B6) = (u16)(LG16(0x58B6) + 0x0001);
			(void)fn1AB8_13D7(0x00,
			    far_ptr(LG32((u16)(0x58E4 +
			                                (u16)((u16)bLoc02 << 2)))),
			    LG16(0x58B8), LG16(0x58B4));
			if (bLoc03 == 0x16)
				break;
			++bLoc03;
		}

		/* 3602..360F: free block #1. */
		(void)fn1EDA_0254(wLoc0E, (u16)((blk1) & 0xFFFFu), (u16)((blk1) >> 16), 0, &dxTmp, &dsTmp);
	}

	/* 3610: mov al,[bp-1h] ; leave ; ret */
	*bpOut = 0x0000;
	*dsOut = 0x0000;
	return bLoc01;
}

// 0C74:3615: u8 fn0C74_3615(u16 * dxOut, u16 * bpOut, u16 * dsOut)
//
// Third game-core "bar" update.  Gates on [58B6h] < 27Eh, clears [58B1h] and
// either runs the 0CFA half-bar redraw when the state word [5968h] is 0FFFFh,
// or (five more 1E3C edge probes) enters the main march: tick 02D8 with
// [58E6h]*2, cycle the animation counter 5..1 (11C8 sound), advance the live
// position while [58B6h] < 27Eh, poll input / mouse (02FB, 1206:015B) or the
// [58BCh]/[58BDh] latch, then repeatedly probe four edges; on success blit the
// DGROUP:0x58E4 sprite for the current counter row; after 16h rows either
// restart (bump [58BCh]) or stop; a failed probe shrinks the position by one
// and stops.
u8 fn0C74_3615(u16 *dxOut, u16 *bpOut, u16 *dsOut)
{
	u8  bLoc01 = 0x00;      /* [bp-01h] result flag */
	u8  bLoc02 = 0x00;      /* [bp-02h] animation counter (5..1) */
	u8  bLoc03 = 0x00;      /* [bp-03h] row counter */
	u16 dsTmp = 0x0000;     /* reusable u16 dsOut for 02D8 / 0CFA / 1206 */
	u16 dxTmp2 = 0x0000;    /* fn1206_015B dxOut */
	u16 bpScratch = 0x0000; /* fn0C74_0CFA bpOut artifact */
	u16 bpScratch2 = 0x0000;/* fn1206_015B bpOut artifact */
	u8  chTmp = 0x00;       /* fn1206_015B chOut */
	u8  dlTmp = 0x00;       /* fn1AB8_1E3C dlOut */

	/* 3615..3627: cmp word [58B6h],27Eh ; jc 3628h */
	if (LG16(0x58B6) < 0x027E)
	{
		/* 3628: mov byte [58B1h],0h */
		LG8(0x58B1) = 0x00;

		/* 362E..363F: cmp word [5968h],0FFh ; jnz 3640h -- the 0FFFFh
		 * state runs the 0CFA half-bar redraw and returns. */
		if (LG16(0x5968) == 0xFFFF)
		{
			(void)fn0C74_0CFA(0x15, &bpScratch, &dsTmp);
			bLoc01 = 0x01;
		}
		/* 3640..368F: four more edge probes run into the main march. */
		else if (fn1AB8_1E3C(LG16(0x58BA),
		                     (u16)(LG16(0x58B6) + 0x0001), &dlTmp) == 0x00 &&
		         fn1AB8_1E3C((u16)(LG16(0x58BA) - 0x0015),
		                     (u16)(LG16(0x58B6) + 0x0001), &dlTmp) == 0x00 &&
		         fn1AB8_1E3C((u16)(LG16(0x58BA) - 0x0029),
		                     (u16)(LG16(0x58B6) + 0x0001), &dlTmp) == 0x00 &&
		         fn1AB8_1E3C((u16)(LG16(0x58BA) + 0x0001),
		                     (u16)(LG16(0x58B6) + 0x0001), &dlTmp) != 0x00)
		{
			/* 3692: mov byte [bp-1h],1h ; mov byte [bp-2h],0h */
			bLoc01 = 0x01;
			bLoc02 = 0x00;

		l0C74_369A:
			/* 369A: mov byte [bp-3h],1h */
			bLoc03 = 0x01;
			for (;;)
			{
				/* 36A3: push ([58E6h] << 1) ; call 02D8h */
				(void)fn0C74_02D8((u16)(LG16(0x58E6) << 1), &dsTmp);

				/* 36AD..36CC: cycle the animation counter 5..1; the
				 * sound branch is guarded by DGROUP:0x58B0. */
				++bLoc02;
				if (bLoc02 == 0x05)
				{
					bLoc02 = 0x01;
					if (LG8(0x58B0) != 0x00)
						fn11C8_0354(0x0032);
				}
				else
					(void)fn11C8_033B();

				/* 36CE..36DC: advance the live position while below
				 * the 27Eh limit. */
				if (LG16(0x58B6) < 0x027E)
				{
					LG16(0x58B4) = (u16)(LG16(0x58B4) + 0x0001);
					LG16(0x58B6) = (u16)(LG16(0x58B6) + 0x0001);
				}

				/* 36DE..3716: input/mouse poll or latch compare. */
				if (LG8(0x58B2) != 0x00)
				{
					if (fn1E78_02FB() != 0x00)
						LG8(0x58B1) = 0x01;
					/* push 0h ; call 1206h:015Bh */
					if ((u8)fn1206_015B(&chTmp, &dxTmp2, &bpScratch2,
					                    &dsTmp) != 0x00)
					{
						LG8(0x58E0) = 0x01;
						LG8(0x58B1) = 0x01;
					}
				}
				else if (LG8(0x58BC) == LG8(0x58BD))
					LG8(0x58B1) = 0x01;

				/* 3718..3723: clamp the limit. */
				if (LG16(0x58B6) >= 0x027E)
					LG8(0x58B1) = 0x01;

				/* 3725..377E: four edge probes.  Any of the first
				 * three non-zero (or the fourth zero) stops with a
				 * one-step shrink. */
			{
				u8 p1 = (u8)fn1AB8_1E3C(LG16(0x58BA), LG16(0x58B6), &dlTmp);
				u8 p2 = (u8)fn1AB8_1E3C((u16)(LG16(0x58BA) - 0x0015),
				                        LG16(0x58B6), &dlTmp);
				u8 p3 = (u8)fn1AB8_1E3C((u16)(LG16(0x58BA) - 0x0029),
				                        LG16(0x58B6), &dlTmp);
				u8 p4 = (u8)fn1AB8_1E3C((u16)(LG16(0x58BA) + 0x0001),
				                        LG16(0x58B6), &dlTmp);
				static int wtr = -1;
				if (wtr < 0)
					wtr = (getenv("RAD_WALK_TRACE") != NULL);
				if (wtr && (p1 || p2 || p3 || !p4))
					fprintf(stderr,
						"WALK block: B4=%u B6=%u BA=%u "
						"p(352)=%u p(331)=%u p(310)=%u p(353)=%u "
						"BC=%u BD=%u\n",
						LG16(0x58B4), LG16(0x58B6),
						LG16(0x58BA), p1, p2, p3, p4,
						LG8(0x58BC), LG8(0x58BD));
				if (p1 != 0x00 || p2 != 0x00 || p3 != 0x00 ||
				    p4 == 0x00)
					break;
			}

				/* 3781..37A8: blit the current sprite row. */
				(void)fn1AB8_13D7(0x00,
				    far_ptr(LG32((u16)(0x58E4 +
				                                (u16)((u16)bLoc02 << 2)))),
				    LG16(0x58B8), LG16(0x58B4));

				/* 37A9..37BC: after 16h rows either bump the latch
				 * and restart, or stop when a stop was requested. */
				if (bLoc03 == 0x16)
				{
					if (LG8(0x58B1) == 0x00)
						LG8(0x58BC) = (u8)(LG8(0x58BC) + 0x01);
					if (LG8(0x58B1) == 0x00)
						goto l0C74_369A;
					goto l0C74_37BE;
				}
				++bLoc03;
			}

			/* 3770..377E: failed probe -- shrink the position one
			 * step and tick the sound helper, then stop. */
			LG16(0x58B4) = (u16)(LG16(0x58B4) - 0x0001);
			LG16(0x58B6) = (u16)(LG16(0x58B6) - 0x0001);
			(void)fn11C8_033B();
		}
	}

l0C74_37BE:
	/* 37BE: mov al,[bp-1h] ; leave ; ret.  DX / BP / DS are register
	 * artifacts; the flat model writes 0 (part 1 section 3 / section 6). */
	*dxOut = 0x0000;
	*bpOut = 0x0000;
	*dsOut = 0x0000;
	return bLoc01;
}
