/* seg0C74_part4.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 4 of N: function 0C74:0FA1 (one of the two largest functions).
 *
 * Literal recovery from analysis/slices/0C74/0C74_0FA1.asm (ground truth) and
 * the Reko slice 0C74_0FA1.c; frozen prototype from src/seg0C74.h
 * (analysis/summary/iface.tsv) adopted exactly:
 *
 *   u8 engine_per_frame_muck(void *bpOut, u16 *dsOut)
 *
 * See CONVENTIONS.md, analysis/SEGMAP.md and docs/notes-0C74.md ("## part 4").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   NONE directly.  No `int 10h/16h/21h`, no raw `in`/`out` port instruction,
 *   no __cli/__sti and no int 23h occur in 0FA1.  The only hardware-touching
 *   call is indirect, into engine_draw_status_sprites (0C74:0E2E), which owns the PC-speaker /
 *   AdLib port I/O (analysis/summary/functions.tsv: port42h/43h/61h/388h/389h)
 *   and keyboard graphics helpers; engine_draw_status_sprites is a separate chunk.  All other
 *   callees are file/video helpers already ported in 1AB8 / 1EDA / 0C74.
 *
 * Flat-model / ABI adaptations (recorded in docs/notes-0C74.md "## part 4"):
 *   - Reko's `bp_XXXX` frame-pointer locals (re-bound after each call to
 *     engine_scale_and_tick_clock / 02D8 / 0E2E, whose AX/far return is the caller's saved BP)
 *     are the current function's own frame.  They are folded back onto the
 *     literal DGROUP stack locals below (documented convention, notes-0C74.md
 *     part 1 §3).
 *   - The 16:16 far blocks allocated by fn1EDA_023F are carried as `u32`
 *     (offset | segment<<16) and materialised with `far_ptr(dw)` at the
 *     call sites, the same convention as seg0800_part3.c / seg1229_part1.c.
 *   - fn1EDA_098A's frozen `void * dsOut` receives a `void *` local.
 *   - fn1EDA_023F / 098A / 0254 require stack words the original never pushes
 *     (they are leftover-stack / far-return-address words used only on the
 *     fatal divide-by-zero path); they are seeded 0.
 *   - `push bp` before engine_draw_status_sprites passes the caller's frame pointer and 0E2E
 *     reads the caller's [bp-4] through it (ss:[bp-4]).  Flat C has no SS:BP
 *     chain, so the call sites pass that word's VALUE (the arm-extension index
 *     wLoc04, seeded 14h/13h at the asm's own `mov word [bp-4],n` sites) and
 *     0E2E consumes it directly (see seg0C74_part3.c).
 */

#include <stddef.h>
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C74.h"
#include "seg1AB8.h"
#include "seg1EDA.h"

// 0C74:0FA1: u8 engine_per_frame_muck(void * bpOut, u16 * dsOut)
//
// Game-core per-frame update: paints the two status fields, animates the
// muck/level bars, runs the "level complete" sequences, then frees the scratch
// blocks.  Returns the [bp-1] byte (0 = abort/keep waiting, 1 = advance).
u8 engine_per_frame_muck /* was fn0C74_0FA1 */(void *bpOut, u16 *dsOut)
{
	u8  bLoc01 = 0x00;      /* [bp-01h] return flag (Reko al_3370) */
	u16 wLoc04 = 0x0000;    /* [bp-04h] primary index (Reko bp_1039-4) */
	u16 wLoc06 = 0x0000;    /* [bp-06h] inner index */
	u16 wLoc08 = 0x0000;    /* [bp-08h] level-bar loop counter */
	u16 wLoc0A = 0x0000;    /* [bp-0Ah] */
	u16 wLoc0C = 0x0000;    /* [bp-0Ch] */
	u32 dwLoc10 = 0x00000000; /* [bp-10h]/[bp-0Eh] far block #1 */
	u32 dwLoc14 = 0x00000000; /* [bp-14h]/[bp-12h] far block #2 */
	u32 dwLoc18 = 0x00000000; /* [bp-18h]/[bp-16h] far block #3 */
	u32 dwLoc1C = 0x00000000; /* [bp-1Ch]/[bp-1Ah] far block #4 */
	u16 wLoc1E = 0x0000;    /* [bp-1Eh] */
	u16 wLoc20 = 0x0000;    /* [bp-20h] */
	u16 wLoc22 = 0x0000;    /* [bp-22h] */
	u16 wLoc24 = 0x0000;    /* [bp-24h] */
	u16 wLoc26 = 0x0000;    /* [bp-26h] */
	u16 wLoc28 = 0x0000;    /* [bp-28h] */
	u16 wLoc2A = 0x0000;    /* [bp-2Ah] */
	u16 dsTmp = 0x0000;     /* reusable u16 dsOut (023F/0254/05B8/02D8/070D?) */
	void *dsv = NULL;       /* reusable void * dsOut (098A/070D/0E2E) */
	u16 dxTmp = 0x0000;     /* fn1AB8_1AF6 / fn1EDA_0254 dxOut */
	u8  dlTmp = 0x00;       /* fn1AB8_1E3C dlOut */
	s16 cxT = 0, dxT = 0, bxT = 0;  /* fn1EDA_098A outs (cx/dx/bx) */

	/* --- prologue: paint the two status rectangles (0FA1..106C) ---------- */
	wLoc20 = fn1AB8_13A3(0x001B, 0x001C, 0x000D, 0x0019);
	dwLoc10 = fn1EDA_023F(wLoc20, 0x0000, 0x0000, &dsTmp);
	dwLoc14 = fn1EDA_023F(wLoc20, 0x0000, 0x0000, &dsTmp);
	/* first 1E6B draws into the [bp-14h] block */
	fn1AB8_1E6B(far_ptr(dwLoc14), (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(LG16(0x58B4) + 0x001C), (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x0019));
	/* second 1E6B draws into the [bp-10h] block */
	fn1AB8_1E6B(far_ptr(dwLoc10), (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(LG16(0x58B4) + 0x0011), (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x000E));
	wLoc24 = (u16)(LG16(0x58B4) + 0x000E - 0x0001);
	wLoc26 = (u16)(LG16(0x58B4) + 0x0019 + 0x0001);

	/* time tick: 098A(4, 096F([4D0Ch], [58E6h], 0, sign([58E6h]))) -> 02D8 */
	cxT = 0; dxT = 0; bxT = 0; dsv = NULL;
	(void)engine_clock_tick((u16)fn1EDA_098A(0x0004,
	        fn1EDA_096F(LG16(0x4D0C), LG16(0x58E6), 0x0000,
	                    (u16)(s16)LG16(0x58E6)),
	        0x0000, 0x0000, &cxT, &dxT, &bxT, &dsv), &dsTmp);

	fn1AB8_13D7(0x00, far_ptr(dwLoc10),
	            (u16)(LG16(0x58B8) + 0x000D), wLoc24);
	fn1AB8_13D7(0x00, far_ptr(dwLoc14),
	            (u16)(LG16(0x58B8) + 0x000D), wLoc26);
	fn1EDA_0254(wLoc20, (u16)((dwLoc10) & 0xFFFFu), (u16)((dwLoc10) >> 16), 0,
	            &dxTmp, &dsTmp);
	fn1EDA_0254(wLoc20, (u16)((dwLoc14) & 0xFFFFu), (u16)((dwLoc14) >> 16), 0,
	            &dxTmp, &dsTmp);
	fn1AB8_10F4(0x0001, 0x0000, 0x0000);
	(void)fn1AB8_1C32(0x00);

	fn1AB8_1AF6((u16)(LG16(0x58B8) + 0x001B), (u16)(LG16(0x58B4) + 0x0019),
	            (u16)(LG16(0x58B8) + 0x000D), (u16)(LG16(0x58B4) + 0x0019),
	            &dxTmp);
	fn1AB8_1AF6((u16)(LG16(0x58B8) + 0x001B), (u16)(LG16(0x58B4) + 0x0011),
	            (u16)(LG16(0x58B8) + 0x000D), (u16)(LG16(0x58B4) + 0x0011),
	            &dxTmp);

	fn1AB8_1E54(0x0B, (u16)(LG16(0x58B8) + 0x0012), (u16)(LG16(0x58B4) + 0x0019));
	fn1AB8_1E54(0x03, (u16)(LG16(0x58B8) + 0x0013), (u16)(LG16(0x58B4) + 0x0019));
	fn1AB8_1E54(0x09, (u16)(LG16(0x58B8) + 0x0014), (u16)(LG16(0x58B4) + 0x0019));
	fn1AB8_1E54(0x0B, (u16)(LG16(0x58B8) + 0x0012), (u16)(LG16(0x58B4) + 0x0011));
	fn1AB8_1E54(0x03, (u16)(LG16(0x58B8) + 0x0013), (u16)(LG16(0x58B4) + 0x0011));
	fn1AB8_1E54(0x09, (u16)(LG16(0x58B8) + 0x0014), (u16)(LG16(0x58B4) + 0x0011));

	wLoc20 = fn1AB8_13A3(0x001B, 0x001D, 0x000D, 0x0019);
	dwLoc10 = fn1EDA_023F(wLoc20, 0x0000, 0x0000, &dsTmp);
	dwLoc14 = fn1EDA_023F(wLoc20, 0x0000, 0x0000, &dsTmp);
	fn1AB8_1E6B(far_ptr(dwLoc14), (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(LG16(0x58B4) + 0x001D), (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x0019));
	fn1AB8_1E6B(far_ptr(dwLoc10), (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(LG16(0x58B4) + 0x0011), (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x000D));

	wLoc04 = 0x0001;

	/* --- 0C74:11EC: scan the left/right field edge up to 14h -------------- */
	while (wLoc04 < 0x0014)
	{
		if (fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x001B),
		                (u16)(LG16(0x58B4) + 0x000C - wLoc04), &dlTmp) != 0)
			break;
		if (fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x001B),
		                (u16)(LG16(0x58B4) + 0x001E + wLoc04), &dlTmp) != 0)
			break;
		if (fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x000D),
		                (u16)(LG16(0x58B4) + 0x000C - wLoc04), &dlTmp) != 0)
			break;
		if (fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x000D),
		                (u16)(LG16(0x58B4) + 0x001E + wLoc04), &dlTmp) != 0)
			break;
		if (fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x0016),
		                (u16)(LG16(0x58B4) + 0x000C - wLoc04), &dlTmp) != 0)
			break;
		if (fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x0016),
		                (u16)(LG16(0x58B4) + 0x001E + wLoc04), &dlTmp) != 0)
			break;

		(void)engine_scale_and_tick_clock(0x0019, 0x00E6, &dsv);
		fn1AB8_13D7(0x00, far_ptr(dwLoc10),
		            (u16)(LG16(0x58B8) + 0x000D),
		            (u16)(LG16(0x58B4) + 0x000D - wLoc04));
		fn1AB8_13D7(0x00, far_ptr(dwLoc14),
		            (u16)(LG16(0x58B8) + 0x000D),
		            (u16)(LG16(0x58B4) + 0x0019 + wLoc04));
		++wLoc04;
	}

	/* --- 0C74:12E2 ------------------------------------------------------- */
	if (wLoc04 != 0x0014)
	{
		(void)engine_draw_status_sprites(wLoc04, &dsv);   /* the caller's [bp-4] word */
		fn1EDA_0254(wLoc20, (u16)((dwLoc10) & 0xFFFFu), (u16)((dwLoc10) >> 16), 0,
		            &dxTmp, &dsTmp);
		fn1EDA_0254(wLoc20, (u16)((dwLoc14) & 0xFFFFu), (u16)((dwLoc14) >> 16), 0,
		            &dxTmp, &dsTmp);
		bLoc01 = 0x00;
		goto l0C74_1B36;
	}

	/* --- 0C74:130F ------------------------------------------------------- */
	wLoc0A = (u16)(LG16(0x58B4) + 0x001A + wLoc04);
	wLoc0C = (u16)(LG16(0x58B4) + 0x000D - wLoc04 + 0x0002);

	if (LG16(0x5968) == 0xFFFF)
	{
		/* --- 0C74:1333: extend the right field (uses the [bp-14h] block) */
		while (wLoc04 < 0x0041)
		{
			if (fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x001B),
			                (u16)(LG16(0x58B4) + 0x001E + wLoc04), &dlTmp) != 0)
				break;
			if (fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x000D),
			                (u16)(LG16(0x58B4) + 0x001E + wLoc04), &dlTmp) != 0)
				break;
			(void)engine_scale_and_tick_clock(0x0019, 0x00E6, &dsv);
			fn1AB8_13D7(0x00, far_ptr(dwLoc14),
			            (u16)(LG16(0x58B8) + 0x000D),
			            (u16)(LG16(0x58B4) + 0x0019 + wLoc04));
			++wLoc04;
		}

		/* --- 0C74:1397 --------------------------------------------------- */
		if (wLoc04 == 0x0041)
		{
			/* --- 0C74:147B ----------------------------------------------- */
			wLoc0A = (u16)(LG16(0x58B4) + 0x001A + wLoc04);
		}
		else
		{
			/* --- 0C74:13A0 ----------------------------------------------- */
			fn1EDA_0254(wLoc20, (u16)((dwLoc14) & 0xFFFFu), (u16)((dwLoc14) >> 16), 0,
			            &dxTmp, &dsTmp);
			wLoc22 = fn1AB8_13A3((u16)(LG16(0x58B8) + 0x001B),
			                     (u16)(LG16(0x58B4) + 0x001D + wLoc04),
			                     (u16)(LG16(0x58B8) + 0x000D),
			                     (u16)(LG16(0x58B4) + 0x0019 + wLoc04));
			dwLoc14 = fn1EDA_023F(wLoc22, 0x0000, 0x0000, &dsTmp);
			fn1AB8_1E6B(far_ptr(dwLoc14),
			            (u16)(LG16(0x58B8) + 0x001B),
			            (u16)(LG16(0x58B4) + 0x001D + wLoc04),
			            (u16)(LG16(0x58B8) + 0x000D),
			            (u16)(LG16(0x58B4) + 0x0019 + wLoc04));

			if (wLoc04 >= 0x0013)
			{
				wLoc06 = wLoc04;
				do
				{
					(void)engine_scale_and_tick_clock(0x0019, 0x00E6, &dsv);
					fn1AB8_13D7(0x00, far_ptr(dwLoc14),
					            (u16)(LG16(0x58B8) + 0x000D), wLoc06);
					if (wLoc06 == 0x0013)
						break;
					--wLoc06;
				} while (1);
			}

			/* --- 0C74:144D ----------------------------------------------- */
			fn1EDA_0254(wLoc22, (u16)((dwLoc14) & 0xFFFFu), (u16)((dwLoc14) >> 16), 0,
			            &dxTmp, &dsTmp);
			wLoc04 = 0x0014;
			(void)engine_draw_status_sprites(wLoc04, &dsv);   /* the caller's [bp-4] word */
			fn1EDA_0254(wLoc20, (u16)((dwLoc10) & 0xFFFFu), (u16)((dwLoc10) >> 16), 0,
			            &dxTmp, &dsTmp);
			bLoc01 = 0x00;
			goto l0C74_1B36;
		}
	}

	/* --- 0C74:1487 ------------------------------------------------------- */
	if (LG16(0x5968) != 0x0001)
		goto l0C74_15E7;

	/* --- 0C74:1491: extend the left field (uses the [bp-10h] block) ------ */
	while (wLoc04 < 0x0041)
	{
		if (fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x001B),
		                (u16)(LG16(0x58B4) + 0x000C - wLoc04), &dlTmp) != 0)
			break;
		if (fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x000D),
		                (u16)(LG16(0x58B4) + 0x000C - wLoc04), &dlTmp) != 0)
			break;
		(void)engine_scale_and_tick_clock(0x0019, 0x00E6, &dsv);
		fn1AB8_13D7(0x00, far_ptr(dwLoc10),
		            (u16)(LG16(0x58B8) + 0x000D),
		            (u16)(LG16(0x58B4) + 0x000D - wLoc04));
		++wLoc04;
	}

	/* --- 0C74:14F5 ------------------------------------------------------- */
	if (wLoc04 == 0x0041)
		goto l0C74_15D9;

	/* --- 0C74:14FE ------------------------------------------------------- */
	fn1EDA_0254(wLoc20, (u16)((dwLoc10) & 0xFFFFu), (u16)((dwLoc10) >> 16), 0,
	            &dxTmp, &dsTmp);
	wLoc22 = fn1AB8_13A3((u16)(LG16(0x58B8) + 0x001B),
	                     (u16)(LG16(0x58B4) + 0x0011 - wLoc04),
	                     (u16)(LG16(0x58B8) + 0x000D),
	                     (u16)(LG16(0x58B4) + 0x000D - wLoc04));
	dwLoc10 = fn1EDA_023F(wLoc22, 0x0000, 0x0000, &dsTmp);
	fn1AB8_1E6B(far_ptr(dwLoc10),
	            (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(LG16(0x58B4) + 0x0011 - wLoc04),
	            (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x000D - wLoc04));

	if (wLoc04 >= 0x0013)
	{
		wLoc06 = wLoc04;
		do
		{
			(void)engine_scale_and_tick_clock(0x0019, 0x00E6, &dsv);
			fn1AB8_13D7(0x00, far_ptr(dwLoc10),
			            (u16)(LG16(0x58B8) + 0x000D), wLoc06);
			if (wLoc06 == 0x0013)
				break;
			--wLoc06;
		} while (1);
	}

	/* --- 0C74:15AB ------------------------------------------------------- */
	wLoc04 = 0x0014;
	(void)engine_draw_status_sprites(wLoc04, &dsv);   /* the caller's [bp-4] word */
	fn1EDA_0254(wLoc22, (u16)((dwLoc10) & 0xFFFFu), (u16)((dwLoc10) >> 16), 0,
	            &dxTmp, &dsTmp);
	fn1EDA_0254(wLoc20, (u16)((dwLoc14) & 0xFFFFu), (u16)((dwLoc14) >> 16), 0,
	            &dxTmp, &dsTmp);
	bLoc01 = 0x00;
	goto l0C74_1B36;

	/* --- 0C74:15D9 ------------------------------------------------------- */
l0C74_15D9:
	wLoc0C = (u16)(LG16(0x58B4) + 0x000D - wLoc04 + 0x0002);

	/* --- 0C74:15E7: level-complete / score animation -------------------- */
l0C74_15E7:
	cxT = 0; dxT = 0; bxT = 0; dsv = NULL;
	(void)engine_clock_tick((u16)fn1EDA_098A(0x0004,
	        fn1EDA_096F(LG16(0x4D0C), LG16(0x58E6), 0x0000,
	                    (u16)(s16)LG16(0x58E6)),
	        0x0000, 0x0000, &cxT, &dxT, &bxT, &dsv), &dsTmp);
	wLoc04 = (u16)(LG16(0x58B8) + 0x001C);
	wLoc06 = (u16)(LG16(0x58B8) + 0x001C);

	/* --- 0C74:1619 ------------------------------------------------------- */
l0C74_1619:
	if (fn1AB8_1E3C(wLoc06, wLoc0C, &dlTmp) == 0)
		goto l0C74_163A;
	if (fn1AB8_1E3C(wLoc04, wLoc0A, &dlTmp) == 0)
		goto l0C74_163A;
	goto l0C74_16C1;

l0C74_163A:
	if (fn1AB8_1E3C(wLoc06, wLoc0C, &dlTmp) != 0)
		goto l0C74_1678;
	(void)fn1AB8_1E54(0x0B, wLoc06, wLoc0C);
	(void)fn1AB8_1E54(0x03, wLoc06, (u16)(wLoc0C + 0x0001));
	(void)fn1AB8_1E54(0x09, wLoc06, (u16)(wLoc0C + 0x0002));
	++wLoc06;

l0C74_1678:
	if (fn1AB8_1E3C(wLoc04, wLoc0A, &dlTmp) != 0)
		goto l0C74_16B6;
	(void)fn1AB8_1E54(0x0B, wLoc04, wLoc0A);
	(void)fn1AB8_1E54(0x03, wLoc04, (u16)(wLoc0A + 0x0001));
	(void)fn1AB8_1E54(0x09, wLoc04, (u16)(wLoc0A + 0x0002));
	++wLoc04;

l0C74_16B6:
	(void)engine_scale_and_tick_clock(0x001E, 0x00FA, &dsv);
	goto l0C74_1619;

	/* --- 0C74:16C1: victory sequence ------------------------------------ */
l0C74_16C1:
	cxT = 0; dxT = 0; bxT = 0; dsv = NULL;
	(void)engine_clock_tick((u16)fn1EDA_098A(0x0004,
	        fn1EDA_096F(LG16(0x4D0C), LG16(0x58E6), 0x0000,
	                    (u16)(s16)LG16(0x58E6)),
	        0x0000, 0x0000, &cxT, &dxT, &bxT, &dsv), &dsTmp);

	wLoc1E = fn1AB8_13A3(LG16(0x58BA), LG16(0x58B6),
	                     (u16)(LG16(0x58BA) - 0x000E), LG16(0x58B4));
	dwLoc18 = fn1EDA_023F(wLoc1E, 0x0000, 0x0000, &dsTmp);
	fn1AB8_1E6B(far_ptr(dwLoc18), LG16(0x58BA), LG16(0x58B6),
	            (u16)(LG16(0x58BA) - 0x000E), LG16(0x58B4));
	LG16(0x58BA) = (u16)(LG16(0x58BA) - 0x0001);
	fn1AB8_13D7(0x00, far_ptr(dwLoc18),
	            (u16)(LG16(0x58BA) - 0x000E), LG16(0x58B4));
	fn1EDA_0254(wLoc1E, (u16)((dwLoc18) & 0xFFFFu), (u16)((dwLoc18) >> 16), 0,
	            &dxTmp, &dsTmp);
	fn1AB8_10F4(0x0001, 0x0000, 0x0000);
	(void)fn1AB8_1C32(0x00);
	fn1AB8_1AF6((u16)(LG16(0x58BA) + 0x0001), LG16(0x58B6),
	            (u16)(LG16(0x58BA) + 0x0001), LG16(0x58B4), &dxTmp);

	wLoc1E = fn1AB8_13A3((u16)(LG16(0x58BA) + 0x0001), LG16(0x58B6),
	                     (u16)(LG16(0x58BA) - 0x000D), LG16(0x58B4));
	dwLoc18 = fn1EDA_023F(wLoc1E, 0x0000, 0x0000, &dsTmp);
	fn1AB8_1E6B(far_ptr(dwLoc18), (u16)(LG16(0x58BA) + 0x0001),
	            LG16(0x58B6), (u16)(LG16(0x58BA) - 0x000D), LG16(0x58B4));

	/* --- 0C74:17C1 ------------------------------------------------------- */
	do
	{
		(void)engine_scale_and_tick_clock(0x003C, 0x0064, &dsv);
		LG16(0x58BA) = (u16)(LG16(0x58BA) - 0x0001);
		fn1AB8_13D7(0x00, far_ptr(dwLoc18),
		            (u16)(LG16(0x58BA) - 0x000D), LG16(0x58B4));
	} while ((u16)(LG16(0x58B8) + 0x002B) != LG16(0x58BA));

	/* --- 0C74:17EF ------------------------------------------------------- */
	fn1EDA_0254(wLoc1E, (u16)((dwLoc18) & 0xFFFFu), (u16)((dwLoc18) >> 16), 0,
	            &dxTmp, &dsTmp);
	wLoc28 = fn1AB8_13A3(LG16(0x58BA), LG16(0x58B6), LG16(0x58B8),
	                     LG16(0x58B4));
	dwLoc1C = fn1EDA_023F(wLoc28, 0x0000, 0x0000, &dsTmp);
	fn1AB8_1E6B(far_ptr(dwLoc1C), LG16(0x58BA), LG16(0x58B6),
	            LG16(0x58B8), LG16(0x58B4));

	cxT = 0; dxT = 0; bxT = 0; dsv = NULL;
	(void)engine_clock_tick((u16)fn1EDA_098A(0x0004,
	        fn1EDA_096F(LG16(0x4D0C), LG16(0x58E6), 0x0000,
	                    (u16)(s16)LG16(0x58E6)),
	        0x0000, 0x0000, &cxT, &dxT, &bxT, &dsv), &dsTmp);
	wLoc08 = 0x0001;

	/* --- 0C74:1867: shrink the bar toward the centre -------------------- */
l0C74_1867:
	(void)engine_scale_and_tick_clock(0x0028, 0x0032, &dsv);
	LG16(0x58B4) = (u16)(LG16(0x58B4) - LG16(0x5968));
	LG16(0x58B6) = (u16)(LG16(0x58B6) - LG16(0x5968));
	fn1AB8_13D7(0x00, far_ptr(dwLoc1C), LG16(0x58B8),
	            LG16(0x58B4));
	if (wLoc08 == 0x002C)
		goto l0C74_18B0;
	++wLoc08;
	goto l0C74_1867;

	/* --- 0C74:18B0 ------------------------------------------------------- */
l0C74_18B0:
	cxT = 0; dxT = 0; bxT = 0; dsv = NULL;
	(void)engine_clock_tick((u16)fn1EDA_098A(0x0004,
	        fn1EDA_096F(LG16(0x4D0C), LG16(0x58E6), 0x0000,
	                    (u16)(s16)LG16(0x58E6)),
	        0x0000, 0x0000, &cxT, &dxT, &bxT, &dsv), &dsTmp);
	fn1EDA_0254(wLoc28, (u16)((dwLoc1C) & 0xFFFFu), (u16)((dwLoc1C) >> 16), 0,
	            &dxTmp, &dsTmp);
	fn1AB8_10F4(0x0001, 0x0000, 0x0000);
	(void)fn1AB8_1C32(0x00);

	/* --- 0C74:18F0: vertical sweep of the two bars ---------------------- */
l0C74_18F0:
	if ((u16)(LG16(0x58B8) + 0x001C) < wLoc06)
		goto l0C74_1906;
	if ((u16)(LG16(0x58B8) + 0x001C) >= wLoc04)
		goto l0C74_1954;

l0C74_1906:
	if ((u16)(LG16(0x58B8) + 0x001C) >= wLoc06)
		goto l0C74_1928;
	--wLoc06;
	fn1AB8_1AF6(wLoc06, (u16)(wLoc0C + 0x0002), wLoc06, wLoc0C, &dxTmp);

l0C74_1928:
	if ((u16)(LG16(0x58B8) + 0x001C) >= wLoc04)
		goto l0C74_194A;
	--wLoc04;
	fn1AB8_1AF6(wLoc04, (u16)(wLoc0A + 0x0002), wLoc04, wLoc0A, &dxTmp);

l0C74_194A:
	(void)engine_scale_and_tick_clock(0x001E, 0x00FA, &dsv);
	goto l0C74_18F0;

	/* --- 0C74:1954 ------------------------------------------------------- */
l0C74_1954:
	fn1EDA_0254(wLoc20, (u16)((dwLoc10) & 0xFFFFu), (u16)((dwLoc10) >> 16), 0,
	            &dxTmp, &dsTmp);
	fn1EDA_0254(wLoc20, (u16)((dwLoc14) & 0xFFFFu), (u16)((dwLoc14) >> 16), 0,
	            &dxTmp, &dsTmp);

	cxT = 0; dxT = 0; bxT = 0; dsv = NULL;
	(void)engine_clock_tick((u16)fn1EDA_098A(0x0004,
	        fn1EDA_096F(LG16(0x4D0C), LG16(0x58E6), 0x0000,
	                    (u16)(s16)LG16(0x58E6)),
	        0x0000, 0x0000, &cxT, &dxT, &bxT, &dsv), &dsTmp);

	wLoc20 = fn1AB8_13A3((u16)(LG16(0x58B8) + 0x001B),
	                     (u16)(wLoc0A + 0x0004),
	                     (u16)(LG16(0x58B8) + 0x000D),
	                     (u16)(wLoc0A - 0x0001));
	dwLoc14 = fn1EDA_023F(wLoc20, 0x0000, 0x0000, &dsTmp);
	fn1AB8_1E6B(far_ptr(dwLoc14), (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(wLoc0A + 0x0004), (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(wLoc0A - 0x0001));
	wLoc2A = (u16)(LG16(0x58B4) + 0x0019 + 0x0013);

	if ((u16)(wLoc0A - 0x0001) >= wLoc2A)
	{
		wLoc06 = (u16)(wLoc0A - 0x0001);
		do
		{
			(void)engine_scale_and_tick_clock(0x0019, 0x00E6, &dsv);
			fn1AB8_13D7(0x00, far_ptr(dwLoc14),
			            (u16)(LG16(0x58B8) + 0x000D), wLoc06);
			if (wLoc06 == wLoc2A)
				break;
			--wLoc06;
		} while (1);
	}

	/* --- 0C74:1A27 ------------------------------------------------------- */
	fn1EDA_0254(wLoc20, (u16)((dwLoc14) & 0xFFFFu), (u16)((dwLoc14) >> 16), 0,
	            &dxTmp, &dsTmp);
	wLoc20 = fn1AB8_13A3((u16)(LG16(0x58B8) + 0x001B),
	                     (u16)(wLoc0C + 0x0003),
	                     (u16)(LG16(0x58B8) + 0x000D),
	                     (u16)(wLoc0C - 0x0002));
	dwLoc10 = fn1EDA_023F(wLoc20, 0x0000, 0x0000, &dsTmp);
	fn1AB8_1E6B(far_ptr(dwLoc10), (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(wLoc0C + 0x0003), (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(wLoc0C - 0x0002));
	wLoc2A = (u16)(LG16(0x58B4) + 0x000D - 0x0013);

	if ((u16)(wLoc0C - 0x0002) <= wLoc2A)
	{
		wLoc06 = (u16)(wLoc0C - 0x0002);
		do
		{
			(void)engine_scale_and_tick_clock(0x0019, 0x00E6, &dsv);
			fn1AB8_13D7(0x00, far_ptr(dwLoc10),
			            (u16)(LG16(0x58B8) + 0x000D), wLoc06);
			if (wLoc06 == wLoc2A)
				break;
			++wLoc06;
		} while (1);
	}

	/* --- 0C74:1ACF ------------------------------------------------------- */
	fn1EDA_0254(wLoc20, (u16)((dwLoc10) & 0xFFFFu), (u16)((dwLoc10) >> 16), 0,
	            &dxTmp, &dsTmp);
	wLoc04 = 0x0013;
	(void)engine_draw_status_sprites(wLoc04, &dsv);   /* the caller's [bp-4] word */

	cxT = 0; dxT = 0; bxT = 0; dsv = NULL;
	(void)engine_clock_tick((u16)fn1EDA_098A(0x0004,
	        fn1EDA_096F(LG16(0x4D0C), LG16(0x58E6), 0x0000,
	                    (u16)(s16)LG16(0x58E6)),
	        0x0000, 0x0000, &cxT, &dxT, &bxT, &dsv), &dsTmp);

	bLoc01 = 0x01;
	if (fn1AB8_1E3C((u16)(LG16(0x58BA) + 0x0001), LG16(0x58B4),
	                &dlTmp) != 0)
		goto l0C74_1B36;
	if (fn1AB8_1E3C((u16)(LG16(0x58BA) + 0x0001), LG16(0x58B6),
	                &dlTmp) != 0)
		goto l0C74_1B36;
	(void)engine_scroll_blit(&dsTmp);
	(void)engine_scatter_muck();

	/* --- 0C74:1B36 ------------------------------------------------------- */
l0C74_1B36:
	/* Reko models bpOut as the caller's saved BP and dsOut as the DGROUP
	 * selector; neither exists in flat C, so both receive 0 (notes-0C74.md). */
	*(u16 *)bpOut = 0x0000;
	*dsOut = 0x0000;
	return bLoc01;
}
