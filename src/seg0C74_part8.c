/* seg0C74_part8.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 8 of N: function 0C74:2E5A only.
 *
 * Literal recovery from analysis/slices/0C74/0C74_2E5A.asm (ground truth) and
 * the Reko slice 0C74_2E5A.c; frozen prototype from src/seg0C74.h
 * (analysis/summary/iface.tsv) adopted exactly:
 *
 *   u8 fn0C74_2E5A(u16 *bpOut, u16 *dsOut)
 *
 * See CONVENTIONS.md, analysis/SEGMAP.md and docs/notes-0C74.md ("## part 8").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   NONE directly.  No int 10h/16h/21h, no raw in/out port instruction, no
 *   __cli/__sti, no int 23h and no raw IVT dispatch occur in 2E5A.  Every
 *   hardware-touching action is reached indirectly through already-ported
 *   callees: the 1AB8 video driver (13A3/13D7/10F4/1AF6/1C32/1E3C/1E54/1E6B),
 *   the 1EDA far-heap helpers (023F/0254), fn1E78_029C (keyboard/pacing),
 *   fn11C8_033B/0354 (sound) and the 0C74 helpers 070D/2BBD/02D8.
 *
 * Flat-model / ABI adaptations (recorded in docs/notes-0C74.md "## part 8"):
 *   - Reko's bp_XXXX frame-pointer locals (re-bound after each call to
 *     fn0C74_070D / 02D8 whose AX return is the caller's saved BP) are the
 *     current function's own frame; they are folded back onto the literal
 *     locals below (documented convention, notes-0C74.md part 1 section 3).
 *   - The 16:16 far blocks from fn1EDA_023F are carried as u32
 *     (offset | segment<<16, low word at the lower address, matching the
 *     original [bp-0Eh]/[bp-0Ch] and [bp-1Eh]/[bp-1Ch] pairs) and materialised
 *     with far_ptr(dw) at the call sites, the same convention as
 *     seg0C74_part4.c / part6.c.
 *   - fn1EDA_023F / 0254 require two leading stack words the original never
 *     pushes (the far return-address words read only on the fatal
 *     divide-by-zero dispatcher path); they are seeded 0 (part4/part6).
 *   - The far-pointer table at DGROUP:0x58F4 (4 bytes per entry) is read as a
 *     single u32 and cast to a host pointer, matching seg0C74_part2.c.
 *   - bpOut / dsOut register outputs are the caller's saved BP and the dropped
 *     DGROUP selector; both receive 0 (notes-0C74.md part 1 section 3).
 */

#include <stddef.h>
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C74.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1E78.h"
#include "seg11C8.h"

// 0C74:2E5A: u8 fn0C74_2E5A(u16 * bpOut, u16 * dsOut)
//
// Game-core "bar pull" update: gates on five 1E3C edge probes, paints the two
// cached regions with 1E6B and slides them left/right, shrinks the cached rows
// 16h+1 times, wipes the remaining columns, then pulls the live bar down 16h
// rows (drawing one of the five DGROUP:0x58F4 sprite pointers per step) and
// frees both scratch blocks.  Returns the [bp-1] byte (0 = gate failed).
u8 fn0C74_2E5A(u16 *bpOut, u16 *dsOut)
{
	u8  bLoc01 = 0x00;      /* [bp-01h] return flag */
	u8  bLoc02 = 0x00;      /* [bp-02h] row / animation counter */
	u8  bLoc03 = 0x00;      /* [bp-03h] column counter */
	u16 wLoc08 = 0x0000;    /* [bp-08h] scan count (u16 of [bp-02h]) */
	u16 wLoc0A = 0x0000;    /* [bp-0Ah] [58B4h]+0x0D-1 */
	u32 dwLoc0E = 0x00000000; /* [bp-0Eh]/[bp-0Ch] far block #1 (offset at -0Eh) */
	u16 wLoc10 = 0x0000;    /* [bp-10h] 13A3 size #1 */
	u16 wLoc12 = 0x0000;    /* [bp-12h] 13A3 size #2 */
	u16 wLoc14 = 0x0000;    /* [bp-14h] [58B4h]-0x16 */
	u16 wLoc16 = 0x0000;    /* [bp-16h] [58B4h]-1 */
	u16 wLoc18 = 0x0000;    /* [bp-18h] [58B8h]+0x15 */
	u16 wLoc1A = 0x0000;    /* [bp-1Ah] [58BAh] */
	u32 dwLoc1E = 0x00000000; /* [bp-1Eh]/[bp-1Ch] far block #2 (offset at -1Eh) */
	u16 dsTmp = 0x0000;     /* reusable u16 dsOut for 023F/0254/02D8 */
	void *dsv = NULL;       /* reusable void * dsOut for 070D */
	u16 dxTmp = 0x0000;     /* fn1AB8_1AF6 / fn1EDA_0254 / fn1E78_029C dxOut */
	u8  dlTmp = 0x00;       /* fn1AB8_1E3C dlOut */

	/* cmp word [58B4h],1h ; ja 2E6Ch -- only run when the counter exceeds 1 */
	if (LG16(0x58B4) > 0x0001 &&
	    /* 2E6C: fn1AB8_1E3C([58BAh], [58B4h]-1) must be non-zero */
	    fn1AB8_1E3C(LG16(0x58BA), (u16)(LG16(0x58B4) - 0x0001), &dlTmp) != 0 &&
	    /* 2E7E: fn1AB8_1E3C([58B8h]+16h, [58B4h]-9) must be non-zero */
	    fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x0016), (u16)(LG16(0x58B4) - 0x0009), &dlTmp) != 0 &&
	    /* 2E95: fn1AB8_1E3C([58BAh], [58B4h]-17h) must be zero */
	    fn1AB8_1E3C(LG16(0x58BA), (u16)(LG16(0x58B4) - 0x0017), &dlTmp) == 0 &&
	    /* 2EA9: fn1AB8_1E3C([58B8h], [58B4h]-1) must be zero */
	    fn1AB8_1E3C(LG16(0x58B8), (u16)(LG16(0x58B4) - 0x0001), &dlTmp) == 0 &&
	    /* 2EBB: fn1AB8_1E3C([58B8h]+16h, [58B4h]-17h) must be zero */
	    fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x0016), (u16)(LG16(0x58B4) - 0x0017), &dlTmp) == 0)
	{
		/* 2ED5: mov byte [bp-1h],1h */
		bLoc01 = 0x01;

		/* 2ED5..2F00: window size #1, then allocate block #1 into
		 * [bp-0Eh]/[bp-0Ch]. */
		wLoc10 = fn1AB8_13A3(LG16(0x58BA), LG16(0x58B4),
		                     (u16)(LG16(0x58B8) + 0x0015),
		                     (u16)(LG16(0x58B4) - 0x0016));
		dwLoc0E = fn1EDA_023F(wLoc10, 0x0000, 0x0000, &dsTmp);

		/* 2F03..2F47: fill block #1 with the 1Ch x 0Eh rectangle. */
		fn1AB8_1E6B(far_ptr(dwLoc0E), LG16(0x58BA), LG16(0x58B4),
		            (u16)(LG16(0x58B8) + 0x0016),
		            (u16)(LG16(0x58B4) - 0x0016));

		/* 2F4A..2F7F: window size #2, then allocate block #2 into
		 * [bp-1Eh]/[bp-1Ch]. */
		wLoc12 = fn1AB8_13A3((u16)(LG16(0x58B8) + 0x001B),
		                     (u16)(LG16(0x58B4) + 0x0011),
		                     (u16)(LG16(0x58B8) + 0x000D),
		                     (u16)(LG16(0x58B4) + 0x000D));
		dwLoc1E = fn1EDA_023F(wLoc12, 0x0000, 0x0000, &dsTmp);

		/* 2F82..2FB1: fill block #2 (11h x 0Dh). */
		fn1AB8_1E6B(far_ptr(dwLoc1E),
		            (u16)(LG16(0x58B8) + 0x001B),
		            (u16)(LG16(0x58B4) + 0x0011),
		            (u16)(LG16(0x58B8) + 0x000D),
		            (u16)(LG16(0x58B4) + 0x000D));

		/* 2FB4..2FC1: clear the bottom row of block #2, latch the gfx
		 * context, then draw the 0Bh/03h/09h markers. */
		wLoc0A = (u16)(LG16(0x58B4) + 0x000D);
		--wLoc0A;
		fn1AB8_13D7(0x00, far_ptr(dwLoc1E),
		            (u16)(LG16(0x58B8) + 0x000D), wLoc0A);
		fn1AB8_10F4(0x0001, 0x0000, 0x0000);
		(void)fn1AB8_1C32(0x00);
		fn1AB8_1AF6((u16)(LG16(0x58B8) + 0x001B),
		            (u16)(LG16(0x58B4) + 0x0011),
		            (u16)(LG16(0x58B8) + 0x000D),
		            (u16)(LG16(0x58B4) + 0x0011), &dxTmp);
		fn1AB8_1E54(0x0B, (u16)(LG16(0x58B8) + 0x0012),
		            (u16)(LG16(0x58B4) + 0x0011));
		fn1AB8_1E54(0x03, (u16)(LG16(0x58B8) + 0x0013),
		            (u16)(LG16(0x58B4) + 0x0011));
		fn1AB8_1E54(0x09, (u16)(LG16(0x58B8) + 0x0014),
		            (u16)(LG16(0x58B4) + 0x0011));

		/* 2FE6..2FFB: free block #2, then rebuild it one column left
		 * (the last 13A3 argument changes from 0Dh to 0Ch). */
		(void)fn1EDA_0254(wLoc12, (u16)((dwLoc1E) & 0xFFFFu), (u16)((dwLoc1E) >> 16), 0, &dxTmp, &dsTmp);
		wLoc12 = fn1AB8_13A3((u16)(LG16(0x58B8) + 0x001B),
		                     (u16)(LG16(0x58B4) + 0x0011),
		                     (u16)(LG16(0x58B8) + 0x000D),
		                     (u16)(LG16(0x58B4) + 0x000C));
		dwLoc1E = fn1EDA_023F(wLoc12, 0x0000, 0x0000, &dsTmp);
		fn1AB8_1E6B(far_ptr(dwLoc1E),
		            (u16)(LG16(0x58B8) + 0x001B),
		            (u16)(LG16(0x58B4) + 0x0011),
		            (u16)(LG16(0x58B8) + 0x000D),
		            (u16)(LG16(0x58B4) + 0x000C));

		/* 3075..30CF: slide block #2 left until the edge is hit or the
		 * counter reaches 14h. */
		bLoc02 = 0x01;
		while (bLoc02 < 0x14)
		{
			if (fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x001B),
			                (u16)(LG16(0x58B4) + 0x000C - bLoc02),
			                &dlTmp) != 0)
				break;
			(void)fn0C74_070D(0x000A, 0x00E6, &dsv);
			fn1AB8_13D7(0x00, far_ptr(dwLoc1E),
			            (u16)(LG16(0x58B8) + 0x000D),
			            (u16)(LG16(0x58B4) + 0x000D - bLoc02));
			++bLoc02;
		}

		/* 30D1..3100: latch the scan count and the shrinking rectangle. */
		wLoc08 = (u16)bLoc02;
		wLoc14 = (u16)(LG16(0x58B4) - 0x0016);
		wLoc16 = (u16)(LG16(0x58B4) - 0x0001);
		wLoc18 = (u16)(LG16(0x58B8) + 0x0015);
		wLoc1A = LG16(0x58BA);
		bLoc03 = 0x01;

		/* 3101..3140: shrink both cached rows 16h times (22 draws). */
		while (1)
		{
			--wLoc14;
			--wLoc16;
			fn1AB8_13D7(0x00, far_ptr(dwLoc0E),
			            (u16)(wLoc18 + 0x0001), wLoc14);
			fn1AB8_13D7(0x00, far_ptr(dwLoc1E),
			            (u16)(LG16(0x58B8) + 0x000D),
			            (u16)(wLoc16 + 0x0002));
			(void)fn0C74_070D(0x0014, 0x00E6, &dsv);
			if (bLoc03 == 0x16)
				break;
			++bLoc03;
		}

		/* 3142..3161: if the latch row is empty, collapse the bar. */
		if (fn1AB8_1E3C((u16)(wLoc1A + 0x0001), wLoc16, &dlTmp) == 0)
		{
			(void)fn0C74_2BBD(wLoc1A, wLoc16, wLoc18, wLoc14);
		}

		/* 3162..31A4: wipe the remaining columns of block #2 down to 0.
		 * The asm computes AX=[bp-8h]+16h then `or al,al ; jc 31A5h`;
		 * `or al,al` clears carry, so the branch is never taken (Reko
		 * folds it to `if (true)`) and the block always runs. */
		bLoc03 = (u8)(wLoc08 + 0x0016);
		while (1)
		{
			(void)fn0C74_070D(0x0005, 0x00E6, &dsv);
			fn1AB8_13D7(0x00, far_ptr(dwLoc1E),
			            (u16)(LG16(0x58B8) + 0x000D),
			            (u16)(LG16(0x58B4) + 0x000D - (u16)bLoc03));
			if (bLoc03 == 0x00)
				break;
			--bLoc03;
		}

		/* 31A5..31BF: free block #2, then run the 16h-step pull-in. */
		(void)fn1EDA_0254(wLoc12, (u16)((dwLoc1E) & 0xFFFFu), (u16)((dwLoc1E) >> 16), 0, &dxTmp, &dsTmp);
		bLoc02 = 0x05;
		bLoc03 = 0x01;

		/* 31C0..3222: pull the bar down by 16h rows, cycling the
		 * animation counter 5..1 and drawing table[58F4h + bLoc02*4]. */
		while (1)
		{
			(void)fn1E78_029C((u16)((s16)LG16(0x58E6) / 2), &dxTmp);
			(void)fn0C74_02D8(0x000A, &dsTmp);
			--bLoc02;
			if (bLoc02 == 0x00)
			{
				bLoc02 = 0x04;
				if (LG8(0x58B0) != 0x00)
					fn11C8_0354(0x0032);
			}
			else
				(void)fn11C8_033B();
			LG16(0x58B4) = (u16)(LG16(0x58B4) - 0x0001);
			LG16(0x58B6) = (u16)(LG16(0x58B6) - 0x0001);
			fn1AB8_13D7(0x00,
			            far_ptr(LG32((u16)(0x58F4 + (u16)(bLoc02 * 4)))),
			            LG16(0x58B8), LG16(0x58B4));
			if (bLoc03 == 0x16)
				break;
			++bLoc03;
		}

		/* 3223..3230: free block #1. */
		(void)fn1EDA_0254(wLoc10, (u16)((dwLoc0E) & 0xFFFFu), (u16)((dwLoc0E) >> 16), 0, &dxTmp, &dsTmp);
	}

	/* 3231: mov al,[bp-1h] ; leave ; ret */
	*(u16 *)bpOut = 0x0000;
	*dsOut = 0x0000;
	return bLoc01;
}
