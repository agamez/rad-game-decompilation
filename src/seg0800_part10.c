/* seg0800_part10.c -- RAD V3.1 preservation port, segment 0800, part 10.
 *
 * Function 0800:2C0C (1 function):
 *   2C0C
 *
 * Literal recovery from analysis/slices/0800/0800_2C0C.asm (ground truth)
 * and the Reko decompilation; frozen prototype from src/seg0800.h
 * (analysis/summary/iface.tsv) adopted exactly:
 *   u16 renamed_0800_2c0c(s16 dx, u16 *dsOut).
 * See CONVENTIONS.md and docs/notes-0800.md ("## part 10").
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   None directly.  No int 10h / int 16h / int 21h, no raw `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch occur in
 *   2C0C.  Every BIOS/DOS/hardware service reached from here is owned by the
 *   callee segments and replaced there: segment 1E78 (keyboard poll/read
 *   through renamed_1e78_02fb/030D/016B), 1206 (mouse cursor through
 *   renamed_1206_0066/0038/015B), 1EDA (file/stream + string helpers), 1AB8
 *   (video/text primitives), 13E2 (palette install), 0C74 (clock/error
 *   report) and the 0800 CRT helpers renamed_0800_00c1/0103 (the int 1Ch timer
 *   vector, installed inside renamed_0800_00c1).
 *
 * Flat-model pointers (CONVENTIONS.md Memory model):
 *   cs:2B43h / cs:2B4Ah / cs:2B4Fh / cs:2B57h / cs:2B82h / cs:2BAFh /
 *   cs:2BDAh / cs:2BEDh become &g_seg0800[0xHHHH]; ds:5ECE / ds:5ED6 /
 *   ds:5CBB / ds:B8AC / ds:B9BC become &g_dgroup[0xHHHH] or LG16().
 *
 * Register / stack model:
 *   The original `enter 102h,0h` gives one 0x102-byte local at [bp-0102h]
 *   (the RAD.MEM stream block, Reko's ptrLoc/`bp - 0x0102`) and one byte at
 *   [bp-01h] (the 5CBBh scan-code table index, Reko `.bFFFF`).  The many
 *   `ss->*((word16) sp - N)` terms in the Reko listing are simulated pushes;
 *   each call is recovered with its frozen-prototype argument list, and the
 *   values the original reads back from the stack are the same values the
 *   prototype names (e.g. the leftover block pointer consumed by renamed_1eda_0848
 *   after renamed_1eda_08ce).
 *
 * renamed_1eda_0b24 polarity (asm ground truth): the frozen renamed_1eda_0b24 returns 1
 *   when the two records are equal.  The asm branches are therefore recovered
 *   as `jz T` -> `if (renamed_1eda_0b24(...) != 0) goto T;` and
 *   `jnz T` -> `if (renamed_1eda_0b24(...) == 0) goto T;`.
 */

#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0800.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1206.h"
#include "seg1E78.h"
#include "seg13E2.h"
#include "seg0C74.h"

// 0800:2C0C: u16 renamed_0800_2c0c(s16 dx, u16 * dsOut)
// The demo/mission browser: key/mouse driven frame loop.  On entry it drains
// the key buffer; then, per outer iteration, it compares the current record
// ds:5ECE with cs:2B43 ("NONAME") and cs:2B4A ("DEMO").  "NONAME" resets the
// record position to 1 and leaves; "DEMO" skips the RAD.MEM file setup; any
// other name opens RAD.MEM on the [bp-0102h] stream block (renamed_1eda_04f5/056A/
// 08CE/0848/05BF) and, on a DOS error, paints the four "Impossible d'acceder"
// lines and takes the fatal exit.  It then paints the title screen, drives the
// clock (renamed_0800_00c1 arms the int 1Ch handler, renamed_0800_0c71 ticks it) and runs
// the key/mouse switch (F1..F7 via 09C2, SPACE save, D toggle, H/K/M/P menu
// keys, ESC exit) until renamed_0800_0877 or ds:58B3 signals an exit.
u16 renamed_0800_2c0c(s16 dx, u16 *dsOut)
{
	u8  abLoc0102[0x102];   /* [bp-0102h] RAD.MEM stream block / scratch   */
	u8  bLoc01;             /* [bp-0001h] scan-code table index (Reko bFFFF) */
	u16 ds_1065 = 0x0000;   /* persistent DS selector (dropped; flat 0)     */
	u16 bp_1005 = 0x0000;   /* persistent BP register output of 1206:0066   */
	u16 ax_2262, dx_2263;   /* 1EDA:0B24 out @2C37 */
	u16 ax_2264, dx_2265;   /* 1EDA:0B24 out @2C57 */
	u16 cx_162;             /* 1EDA:08CE cx out @2C89 */
	u16 dx_2269;            /* 1E78:016B dx out @2C80 */
	u16 cx_238, cx_287, cx_336, cx_385;     /* 1EDA:08CE cx out (x4) */
	u8  ch_2271, ch_2273, ch_2275, ch_2277; /* 1EDA:04A9 ch out (x4) */
	u16 ds_263, ds_312, ds_361, ds_410;     /* 1EDA:04A9 ds out (x4) */
	u16 dx_2278;            /* 1E78:030D dx out @2D21 */
	u16 ds_457;             /* 1AB8:1536 ds out @2D35 */
	u16 ax_2267, dx_2268;   /* 1EDA:0B24 out @2D5E */
	u8  ch_2279, ch_2280;   /* 1AB8:1D82 ch out */
	u16 ax_2281, dx_2282;   /* 1EDA:0B24 out @2D98 */
	u8  ch_2283, ch_2284;   /* 1AB8:1D82 ch out */
	u16 ds_644;             /* 0800:04E3 ds out @2DC1 */
	u16 dx_2285;            /* 1EDA:0A39 dx out @2DD5 */
	u16 bp_2286, ds_735;    /* 1206:0066 out @2DDC */
	u8  ch_2287;            /* 1206:0038 ch out */
	u16 dx_2288;            /* 1206:0038 dx out */
	u16 ax_2289, dx_2290;   /* 1EDA:0B24 out @2E12 */
	u16 bp_2291, ds_2333;   /* 0800:09C2 out @2E19 */
	u8  ch_2292;            /* 1206:015B ch out */
	u16 dx_2293, bp_2294;   /* 1206:015B dx/bp out */
	u16 dx_1020 = 0x0000;   /* 0800:00C1 dx out / 030D register / 0C71 ret */
	u8  ch_2295;            /* 1206:015B ch out (do-loop top) */
	u16 ax_2296;            /* 1EDA:0B24 ax out @2E5D */
	u16 dx_1028;            /* 1E78:030D dx out */
	u16 ds_1009;            /* 0800:031B ds out */
	u16 ax_2299, dx_2300;   /* 1EDA:0B24 out @2EB3 */
	u16 bp_2302, ds_1839, bp_2303, bp_2304; /* 09C2 / 0C74:522C out */
	u16 bp_2305, ds_1774, bp_2306;          /* 09C2 / 0C74:542B out */
	u16 bp_2307, ds_1711, bp_2308;          /* 09C2 / 0C74:5258 out */
	u8  ch_2309, ch_2310;   /* 1AB8:1D82 ch out */
	u16 dx_1472;            /* ds:58DA snapshot */
	u16 bp_2311, ds_1489, bp_2312;          /* 0800:09C2 out */
	u8  ch_2314;            /* 1206:015B ch out */
	u16 dx_2315, bp_2316;   /* 1206:015B dx/bp out */
	u16 dx_2313;            /* 0800:00C1 dx out */
	u16 bp_2317, ds_1422, bp_2318;          /* 0800:09C2 out */
	u16 bp_2319, ds_1312, dx_2320, bp_2321, ds_1328;  /* 09C2/54F0 out */
	u16 bp_2323, ds_1350, bp_2324, bp_2322;           /* 09C2 out */
	u16 bp_2325, ds_1202, dx_2326, bp_2327, ds_1218;  /* 09C2/54B1 out */
	u16 bp_2329, ds_1240, bp_2330, bp_2328;           /* 09C2 out */
	u16 bp_2331, ds_1152, bp_2332;          /* 09C2 out */
	u16 dx_1999;            /* 0800:0768 result */
	u16 ax_2297, dx_2298;   /* 1EDA:0B24 out @30A8 */
	u16 bp_2301;            /* 1206:0066 bp out @3108 */
	s16 ax_749, ax_753;     /* 0800:04CC results @2DF2/2DFA */
	u16 ax_915;             /* ds:53DD * 3Ch */

	/* l0800_2C10: drain the key buffer. */
	while (renamed_1e78_02fb() != 0x00)
		(void)renamed_1e78_030d(dx, 0x0000, (u16 *)&dx);

	/* l0800_2C20: outer loop. */
	for (;;)
	{
		(void)renamed_1206_0066(&bp_1005, &ds_1065);
		(void)renamed_13e2_003b();
		renamed_0800_01fe();

		/* l0800_2C2D: call 1EDA:0B24h ; jnz 2C4Dh.
		 * equal to cs:2B43h ("NONAME") -> l0800_2C3E. */
		if (renamed_1eda_0b24(&g_seg0800[0x2B43], &g_dgroup[0x5ECE],
		                &ax_2262, &dx_2263) != 0)
			break;

		/* l0800_2C4D: call 1EDA:0B24h ; jnz 2C61h.
		 * equal to cs:2B4Ah ("DEMO") -> l0800_2C5E -> l0800_2D2B. */
		if (renamed_1eda_0b24(&g_seg0800[0x2B4A], &g_dgroup[0x5ECE],
		                &ax_2264, &dx_2265) != 0)
			goto l0800_2D2B;

		/* l0800_2C61: open RAD.MEM on the [bp-0102h] stream block. */
		(void)renamed_1eda_04f5(&g_seg0800[0x2B4F], abLoc0102);
		renamed_1eda_056a(abLoc0102);
		(void)renamed_1eda_08ce(0x0000, &g_dgroup[0x5ECE], abLoc0102, &cx_162);
		ds_1065 = renamed_1eda_0848(0x00, cx_162, abLoc0102);
		(void)renamed_1eda_05bf(abLoc0102);

		/* l0800_2CA0: call 1EDA:04A2h ; or ax,ax ; jnz 2CAAh. */
		if (renamed_1eda_04a2() != 0x00)
		{
			/* l0800_2CAA: the four "Impossible d'acceder" lines. */
			(void)renamed_1e78_016b(LG16(0xB8AC), &dx_2269);

			(void)renamed_1eda_08ce(0x0000, &g_seg0800[0x2B57],
			                  &g_dgroup[0xB9BC], &cx_238);
			ds_1065 = renamed_1eda_0848(0x00, cx_238, &g_dgroup[0xB9BC]);
			(void)fn1EDA_04A9(0x0000, 0x0000, &ch_2271, &ds_263);

			(void)renamed_1eda_08ce(0x0000, &g_seg0800[0x2B82],
			                  &g_dgroup[0xB9BC], &cx_287);
			ds_1065 = renamed_1eda_0848(0x00, cx_287, &g_dgroup[0xB9BC]);
			(void)fn1EDA_04A9(0x0000, 0x0000, &ch_2273, &ds_312);

			(void)renamed_1eda_08ce(0x0000, &g_seg0800[0x2BAF],
			                  &g_dgroup[0xB9BC], &cx_336);
			ds_1065 = renamed_1eda_0848(0x00, cx_336, &g_dgroup[0xB9BC]);
			(void)fn1EDA_04A9(0x0000, 0x0000, &ch_2275, &ds_361);

			(void)renamed_1eda_08ce(0x0000, &g_seg0800[0x2BDA],
			                  &g_dgroup[0xB9BC], &cx_385);
			ds_1065 = renamed_1eda_0848(0x00, cx_385, &g_dgroup[0xB9BC]);
			(void)fn1EDA_04A9(0x0000, 0x0000, &ch_2277, &ds_410);

			/* l0800_2D21: call 1E78:030Dh (the register-preserving
			 * 04A9 leaves DX:AX = 0 on the surviving path). */
			(void)renamed_1e78_030d(0x0000, 0x0000, &dx_2278);
			ds_1065 = (u16)(uintptr_t)fn1EDA_00E9(0x0000);
		}

	l0800_2D2B:
		/* l0800_2D2B: frame setup + the DEMO/NONAME-dependent title. */
		(void)bgi_load_video_driver_file(0x0001, 0x0000, 0x0000, &ds_457);
		bgi_set_text_rectangle(0x0001, 0x0001);
		renamed_0800_005a(0x018F, 0x0114, 0x0184, 0x000F);
		(void)bgi_get_text_cursor_attributes(0x08);

		/* l0800_2D50: call 0B24h ; jz 2D77h. */
		/* asm 2D5E: jz 2D77 -> EQUAL draws cs:2BED (DEMO prompt);
		 * NOT-equal falls through to 2D65 which draws ds:5CBB (mission text). */
		if (renamed_1eda_0b24(&g_seg0800[0x2B4A], &g_dgroup[0x5ECE],
		                &ax_2267, &dx_2268) == 0)
			(void)bgi_get_char_size_info(&g_dgroup[0x5CBB], 0x0189, 0x0093, &ch_2280);
		else
			(void)bgi_get_char_size_info(&g_seg0800[0x2BED], 0x0189, 0x0093, &ch_2279);

		(void)bgi_get_text_cursor_attributes(0x0A);

		/* l0800_2D87: call 0B24h ; jz 2DB1h. */
		/* asm 2D87: jz 2DB1 -> EQUAL draws cs:2BED; NOT-equal draws ds:5CBB. */
		if (renamed_1eda_0b24(&g_seg0800[0x2B4A], &g_dgroup[0x5ECE],
		                &ax_2281, &dx_2282) == 0)
			(void)bgi_get_char_size_info(&g_dgroup[0x5CBB], 0x018A, 0x0094, &ch_2284);
		else
			(void)bgi_get_char_size_info(&g_seg0800[0x2BED], 0x018A, 0x0094, &ch_2283);

		/* l0800_2DC1: HUD counters, then copy ds:5ECEh -> ds:5ED6h. */
		(void)renamed_0800_04e3(&ds_644);
		(void)renamed_1eda_0a39(0x06, &g_dgroup[0x5ED6], &g_dgroup[0x5ECE], &dx_2285);

		/* l0800_2DD5: call 0619h ; call 0BECh ; call 13E2:00FBh. */
		(void)renamed_0800_0619();
		ds_1065 = renamed_0800_0bec();
		renamed_13e2_00fb();

		/* l0800_2DE4: push 8h ; push 0h ; call 1AB8:1342h. */
		(void)bgi_set_text_character_color(0x00, 0x0008);
		(void)renamed_1206_0066(&bp_2286, &ds_735);

		/* l0800_2DF2/2DFA: 04CCh(ds:53D9h), 04CCh(ds:53DAh) -> 0C74:06B7h.
		 * The original's stale AH on the first push is ignored by 04CCh
		 * (it reads AL only). */
		ax_749 = renamed_0800_04cc((u8)LG8(0x53D9));
		ax_753 = renamed_0800_04cc((u8)LG8(0x53DA));
		(void)engine_arm_window_geometry((u16)ax_753, (u16)ax_749);
		(void)renamed_1206_0038(&ch_2287, &dx_2288, &bp_1005, &ds_1065);

		/* l0800_2E12: call 0B24h ; jz 2E37h.  Not "DEMO" -> wait. */
		if (renamed_1eda_0b24(&g_seg0800[0x2B4A], &g_dgroup[0x5ECE],
		                &ax_2289, &dx_2290) == 0x00)
		{
			/* l0800_2E19: paint + wait for a key or a mouse event. */
			(void)renamed_0800_09c2(0x0B, &bp_2291, &ds_2333);
			while (renamed_1e78_02fb() == 0x00)
			{
				if ((u8)renamed_1206_015b(&ch_2292, &dx_2293, &bp_2294,
				                    &ds_2333) != 0x00)
					break;
			}
			(void)renamed_0800_09c2(0x02, &bp_1005, &ds_1065);
		}

		/* l0800_2E37: arm the timer with 3Ch * ds:53DDh. */
		ax_915 = (u16)((u16)LG8(0x53DD) * 0x003C);
		(void)renamed_0800_00c1(ax_915, 0x0000, &dx_1020);
		bLoc01 = 0x01;   /* mov byte ptr [bp-1h],1h */

		/* l0800_2E49: per-frame key handling. */
		do
		{
			/* l0800_2E49: if no key is pending, poll the mouse and
			 * re-test "DEMO"; otherwise go straight to the read. */
			if (renamed_1e78_02fb() == 0x00)
			{
				if ((u8)renamed_1206_015b(&ch_2295, &dx_1020,
				                    &bp_1005, &ds_1065) != 0x00)
					goto l0800_2E71;    /* l0800_2E52: jnz 2E71h */
				if (renamed_1eda_0b24(&g_seg0800[0x2B4A], &g_dgroup[0x5ECE],
				                &ax_2296, &dx_1020) == 0x00)
					goto l0800_3087;    /* l0800_2E6E: jmp 3087h */
			}

	l0800_2E71:
			/* l0800_2E71: read one key/character into ds:53D2h. */
			if (renamed_1e78_02fb() != 0x00)
			{
				LG8(0x53D2) = (u8)renamed_1e78_030d(dx_1020, 0x0000, &dx_1028);
				if (LG8(0x53D2) == 0x00)
					LG8(0x53D2) = (u8)renamed_1e78_030d(dx_1028, 0x0000,
					                              &dx_1028);
				while (renamed_1e78_02fb() != 0x00)
					(void)renamed_1e78_030d(dx_1028, 0x0000, &dx_1028);
			}
			else
			{
				/* l0800_2EA3: call 031Bh */
				LG8(0x53D2) = (u8)renamed_0800_031b(&bp_1005, &ds_1009);
				ds_1065 = ds_1009;
			}

			/* l0800_2EA9: call 0B24h ; jnz 2ED2h.  1EDA:0B24h leaves
			 * ZF=1 when the two records are EQUAL (rep cmpsb /
			 * cmp al,ah at 1EDA:0B4Ah), so `jnz 2ED2h` jumps when
			 * the record DIFFERS from "DEMO": the translation
			 * through the ds:5CBBh script bytes runs only for the
			 * "DEMO" record (demo playback).  Every other record
			 * dispatches the raw scan code at 2ED2h, which is what
			 * routes the arrow scan codes (48h/50h/4Bh/4Dh) to the
			 * robot handlers 0C74:51AA/51B2/54F0/54B1. */
			if (renamed_1eda_0b24(&g_seg0800[0x2B4A], &g_dgroup[0x5ECE],
			                &ax_2299, &dx_2300) != 0x00)
			{
				if (LG8(0x53D2) != 0x1B)
					LG8(0x53D2) = LG8((u16)(0x5CBB + (u16)bLoc01));
				++bLoc01;
			}

			/* l0800_2ED2: dispatch on ds:53D2h. */
			switch (LG8(0x53D2))
			{
			case 0x3B:
				/* l0800_2ED9: F1 -- next table. */
				(void)renamed_0800_09c2(0x0E, &bp_2302, &ds_1839);
				if (LG8(0x53DB) > 0x00)
				{
					if (engine_frame_dispatch(&bp_2304, &ds_1839) != 0x00)
						LG8(0x53DB) = (u8)(LG8(0x53DB) - 0x01);
				}
				(void)renamed_0800_09c2(0x05, &bp_2303, &ds_1065);
				break;

			case 0x3C:
				/* l0800_2EFE: F2. */
				(void)renamed_0800_09c2(0x0F, &bp_2305, &ds_1774);
				if (LG8(0x53DC) > 0x00)
				{
					if (engine_frame_retract(&ds_1774) != 0x00)
						LG8(0x53DC) = (u8)(LG8(0x53DC) - 0x01);
				}
				(void)renamed_0800_09c2(0x06, &bp_2306, &ds_1065);
				break;

			case 0x3D:
				/* l0800_2F23: F3. */
				(void)renamed_0800_09c2(0x10, &bp_2307, &ds_1711);
				if (LG8(0x53DE) > 0x00 &&
				    engine_frame_pull_in_extended(&ds_1711) != 0x00)
					LG8(0x53DE) = (u8)(LG8(0x53DE) - 0x01);
				(void)renamed_0800_09c2(0x07, &bp_2308, &ds_1065);
				break;

			case 0x3F:
			case 0x2C:
				/* l0800_2F4C: reset the frame and repaint it. */
				LG8(0x58B2) = 0x00;
				ds_1065 = renamed_0800_2401();
				LG8(0x58B2) = 0x01;
				(void)bgi_load_video_driver_file(0x0001, 0x0000, 0x0000, &ds_1065);
				bgi_set_text_rectangle(0x0001, 0x0001);
				renamed_0800_005a(0x018F, 0x0114, 0x0184, 0x000F);
				(void)bgi_get_text_cursor_attributes(0x08);
				(void)bgi_get_char_size_info(&g_dgroup[0x5CBB], 0x0189, 0x0093,
				                  &ch_2309);
				(void)bgi_get_text_cursor_attributes(0x0A);
				(void)bgi_get_char_size_info(&g_dgroup[0x5CBB], 0x018A, 0x0094,
				                  &ch_2310);
				break;

			default:
				if (LG8(0x53D2) == 0x1B)
				{
					/* l0800_2FB0: ESC -- restore the vector, leave. */
					renamed_0800_0103();
					goto l0800_3110;
				}
				else if (LG8(0x53D2) == 0x20)
				{
					/* l0800_2FBD: SPACE -- snapshot/commit the clock. */
					dx_1472 = LG16(0x58DA);
					LG16(0x58D0) = LG16(0x58D8);
					LG16(0x58D2) = dx_1472;
					renamed_0800_0103();
					(void)renamed_0800_09c2(0x0B, &bp_2311, &ds_1489);
					while (renamed_1e78_02fb() == 0x00)
					{
						if ((u8)renamed_1206_015b(&ch_2314, &dx_2315,
						                    &bp_2316, &ds_1489) != 0x00)
							break;
					}
					(void)renamed_0800_09c2(0x02, &bp_2312, &ds_1065);
					(void)renamed_0800_00c1(LG16(0x58D0), LG16(0x58D2),
					                  &dx_2313);
				}
				else if (LG8(0x53D2) == 0x44)
				{
					/* l0800_2FFE: 'D' -- toggle ds:58B0h. */
					if (LG8(0x58B0) != 0x00)
						LG8(0x58B0) = 0x00;
					else
						LG8(0x58B0) = 0x01;
				}
				else if (LG8(0x53D2) == 0x48)
				{
					/* l0800_3017: 'H'. */
					(void)renamed_0800_09c2(0x09, &bp_2317, &ds_1422);
					(void)engine_call_rocket_trajectory();
					(void)renamed_0800_09c2(0x00, &bp_2318, &ds_1065);
				}
				else if (LG8(0x53D2) == 0x4B)
				{
					/* l0800_302C: 'K'. */
					(void)renamed_0800_09c2(0x0A, &bp_2319, &ds_1312);
					if (engine_probe_march_left(&dx_2320, &bp_2321,
					                &ds_1328) == 0x00)
					{
						(void)renamed_0800_09c2(0x0E, &bp_2323, &ds_1350);
						(void)renamed_0800_08c0();
						(void)renamed_0800_09c2(0x05, &bp_2324, &ds_1328);
					}
					(void)renamed_0800_09c2(0x01, &bp_2322, &ds_1065);
				}
				else if (LG8(0x53D2) == 0x4D)
				{
					/* l0800_3052: 'M'. */
					(void)renamed_0800_09c2(0x0C, &bp_2325, &ds_1202);
					if (engine_probe_march_right(&dx_2326, &bp_2327,
					                &ds_1218) == 0x00)
					{
						(void)renamed_0800_09c2(0x0E, &bp_2329, &ds_1240);
						(void)renamed_0800_08c0();
						(void)renamed_0800_09c2(0x05, &bp_2330, &ds_1218);
					}
					(void)renamed_0800_09c2(0x03, &bp_2328, &ds_1065);
				}
				else if (LG8(0x53D2) == 0x50)
				{
					/* l0800_3078: 'P'. */
					(void)renamed_0800_09c2(0x0D, &bp_2331, &ds_1152);
					(void)engine_edge_collision_probe();
					(void)renamed_0800_09c2(0x04, &bp_2332, &ds_1065);
				}
				break;
			}

	l0800_3087:
			/* l0800_3087: tick the clock, then test the exit flags. */
			dx_1020 = (u16)renamed_0800_0c71(&bp_1005, &ds_1065);
		} while (renamed_0800_0877() == 0x00 && LG8(0x58B3) == 0x00);

		/* l0800_309B */
		renamed_0800_0103();
		/* l0800_30A8: call 0B24h ; jnz 30B1h.  Equal "DEMO" -> leave. */
		if (renamed_1eda_0b24(&g_seg0800[0x2B4A], &g_dgroup[0x5ECE],
		                &ax_2297, &dx_2298) != 0)
			goto l0800_3110;

		/* l0800_30B1: call 0877h ; jz 3108h. */
		if (renamed_0800_0877() == 0x00)
			goto l0800_3108;

		/* l0800_30B8: wait out a key, advance the record position. */
		dx_1999 = renamed_0800_0768(&bp_1005, &ds_1065);
		while (renamed_1e78_02fb() != 0x00)
			(void)renamed_1e78_030d((s16)dx_1999, 0x0000, (u16 *)&dx_1999);

		LG32(0x598E) = LG32(0x598E) + 0x00000001u;
		if (LG16(0x5990) == 0x0000 && (u16)LG8(0x0002) == LG16(0x598E))
		{
			ds_1065 = renamed_0800_166d();
			goto l0800_3110;
		}
		if (LG16(0x5990) == 0x0000 && LG16(0x598E) == 0x00FA)
		{
			LG16(0x598E) = 0x0001;
			LG16(0x5990) = 0x0000;
		}

	l0800_3108:
		/* l0800_3108: show the cursor and iterate the outer loop. */
		(void)renamed_1206_0066(&bp_2301, &ds_1065);
	}

	/* l0800_2C3E: reached only when the record is "NONAME"; reset the
	 * position and return. */
	LG16(0x598E) = 0x0001;
	LG16(0x5990) = 0x0000;

l0800_3110:
	/* l0800_3110: leave;ret.  The original's AX is the frame word Reko
	 * returned; no caller reads it (renamed_0800_3d9d ignores AX at both call
	 * sites), so 0 is returned.  The dropped DGROUP selector becomes 0. */
	*dsOut = ds_1065;
	return 0x0000;
}
