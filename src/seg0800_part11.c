/* seg0800_part11.c -- RAD V3.1 preservation port, segment 0800, part 11.
 *
 * Function 0800:31B7 only (the mission/input dialog driver, ~612 C lines).
 *
 * Literal recovery from analysis/slices/0800/0800_31B7.asm (ground truth) and
 * the Reko decompilation; the frozen prototype from src/seg0800.h
 * (analysis/summary/iface.tsv) is adopted exactly.  See CONVENTIONS.md and
 * docs/notes-0800.md ("## part 11").
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   None direct.  No int 10h / int 16h / int 21h, no `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch occur in
 *   31B7.  Every BIOS/DOS/hardware service reached from here is owned by the
 *   callee segments and replaced there: segment 0C74 (the 51xx/52xx/54xx menu
 *   handlers and engine_arm_window_geometry), 1EDA (the DOS stream layer 0FA2/0FD0/1123/
 *   108C/1051/04A9/0A39/0CD4), 1AB8 (video/text), 1206 (mouse cursor; the
 *   int 33h trampoline fn1E5F_000B is reached inside seg1206.c) and 1E78
 *   (keyboard/PIT).
 *
 * Frame (enter 284h,0h):
 *   [bp-0284h] buf284[0x100]  RAD stream block for the final record write
 *   [bp-0204h] buf204[0x100]  input line buffer (dest of the cs:3112h copy,
 *                             filled by the keystroke loop)
 *   [bp-0002h] bLoc02         initial button-slot counter 0..8
 *   [bp-0001h] bLoc01         input line index (starts at 1 at 0800:3447)
 *
 * Dropped-argument adaptation (see docs/notes-0800.md "## part 11"):
 *   fn1EDA_108C's third, dropped data-buffer far pointer is the caller's
 *   [bp-0204h] line buffer.  The port's record-I/O layer writes through the
 *   shared slot g_1EDA_io_buffer (src/seg1EDA_shared.h), which the caller must
 *   point at its own buffer; 31B7 does so around the call (and restores it).
 */

#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0800.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1EDA_shared.h"
#include "seg1206.h"
#include "seg0C74.h"
#include "seg1E78.h"

/* 0800:31B7: u16 fn0800_31B7(s16 dx, u16 * dsOut)
 * The mission input dialog.  Drain the key queue, copy the cs:3112h record
 * into the [bp-0204h] line buffer, paint the button panel and 14+7 text rows,
 * set up the mouse/button range, then run the event loop: a key (through
 * fn0800_031B / fn1E78_030D) or mouse byte is dispatched by the [53D2h]
 * command switch (the 0C74 handler set consumes one of the 53DBh/53DCh/53DEh
 * counters; 'H'/'K'/'M'/'P' move the selection; 20h/44h/1Bh have special
 * meaning), the accepted byte is appended to the line buffer when the
 * cs:316Fh / cs:318Fh bit tables allow it, the clock is ticked (fn0800_0C71)
 * and the loop repeats until fn0800_0877 or DGROUP:58B3h signals completion.
 * On completion the line buffer is written back as one record of the
 * cs:31AFh-named stream, then the "PRESS..." wait (fn0800_0768) runs. */
u16 fn0800_31B7(s16 dx, u16 *dsOut)
{
	u8  buf284[0x100];       /* [bp-0284h] RAD stream block / record buffer */
	u8  buf204[0x100];       /* [bp-0204h] input line buffer (0A39 dest)     */
	u8  bLoc01 = 0x00;       /* [bp-0001h] input line index                  */
	u8  bLoc02;              /* [bp-0002h] initial slot counter              */
	u8  al_1056;             /* [53D2h] command byte, latched once           */

	u16 dx_2182 = 0x0000;    /* 1EDA:0A39 dxOut (copy cs:3112h)              */
	u16 bp_210 = 0x0000;     /* 1206:0066 bpOut (pass-through caller BP)     */
	u16 ds_218 = 0x0000;     /* 1206:0066 dsOut (dropped selector)           */
	u16 dx_2183 = 0x0000;    /* 1EDA:0A39 dxOut (5CB4h -> 5ECEh)             */
	u16 dx_2184 = 0x0000;    /* 1EDA:0A39 dxOut (5CB4h -> 5ED6h)             */
	u16 bp_2185 = 0x0000;    /* 0800:09C2 bpOut (initial slot loop)          */
	u16 ds_225 = 0x0000;     /* 0800:09C2 dsOut (initial slot loop)          */
	u16 ds_268 = 0x0000;     /* 1AB8:1536 dsOut                              */
	u8  ch_2186, ch_2187, ch_2188, ch_2189, ch_2190, ch_2191, ch_2192;
	u8  ch_2193, ch_2194, ch_2195, ch_2196, ch_2197, ch_2198, ch_2199;
	u16 ds_601 = 0x0000;     /* 1206:00FF dsOut                              */
	u16 ds_620 = 0x0000;     /* 1206:012D dsOut                              */
	u16 si_2200 = 0x0000;    /* 1206:00D1 siOut                              */
	u16 es_2201 = 0x0000;    /* 1206:00D1 esOut                              */
	u16 ds_639 = 0x0000;     /* 1206:00D1 dsOut                              */
	u16 ds_662 = 0x0000;     /* 1AB8:1536 dsOut (second)                     */
	u8  ch_2202, ch_2203;    /* 1AB8:1D82 chOut (5CBBh rows)                 */
	u16 ds_754 = 0x0000;     /* 0800:04E3 dsOut                              */
	u16 ax_809 = 0x0000;     /* 04CC(53D9h)                                  */
	u16 w_816 = 0x0000;      /* 04CC input word (high = ax_809, low 53DAh)   */
	u16 w_817 = 0x0000;      /* 04CC(w_816)                                  */
	u16 bp_2204 = 0x0000;    /* 0800:09C2 bpOut                              */
	u16 ds_2243 = 0x0000;    /* 0800:09C2 dsOut                              */
	u8  ch_2205;             /* 1206:015B chOut                              */
	u16 dx_2206 = 0x0000;    /* 1206:015B dxOut                              */
	u16 bp_2207 = 0x0000;    /* 1206:015B bpOut                              */
	u16 bp_1120 = 0x0000;    /* main-loop 09C2 bpOut / tail 0066 bpOut       */
	u16 ds_1001 = 0x0000;    /* main-loop DGROUP selector (dropped)          */
	s16 dx_1012 = 0x0000;    /* threaded DX (00C1 -> 030D -> 0C71)           */
	u8  ch_2208;             /* 1206:015B chOut (loop)                       */
	u16 ax_low;              /* 60 * [53DDh] low word                        */
	u16 dx_high;             /* cwd high word of ax_low                      */
	u16 bp_2209 = 0x0000;    /* case 3Dh/3Ch 09C2 bpOut                      */
	u16 bp_2210 = 0x0000;    /* 0C74:522C bpOut                              */
	u16 ds_1658 = 0x0000;    /* case 3Bh DGROUP selector                     */
	u16 bp_2224 = 0x0000;    /* case 3Ch 09C2 bpOut                          */
	u16 ds_1593 = 0x0000;    /* case 3Ch DGROUP selector                     */
	u16 bp_2225 = 0x0000;    /* case 3Dh 09C2 bpOut                          */
	u16 ds_1530 = 0x0000;    /* case 3Dh DGROUP selector                     */
	u16 bp_2226 = 0x0000;    /* case 20h 09C2 bpOut                          */
	u16 ds_1429 = 0x0000;    /* case 20h DGROUP selector                     */
	u8  ch_2228;             /* case 20h 12B chOut                           */
	u16 dx_2229 = 0x0000;    /* case 20h 12B dxOut                           */
	u16 bp_2230 = 0x0000;    /* case 20h 12B bpOut                           */
	u16 dx_2227 = 0x0000;    /* case 20h 00C1 dxOut                          */
	u16 bp_2231 = 0x0000;    /* case 48h 09C2 bpOut                          */
	u16 ds_1362 = 0x0000;    /* case 48h DGROUP selector                     */
	u16 bp_2232 = 0x0000;    /* case 4Bh 09C2 bpOut                          */
	u16 ds_1252 = 0x0000;    /* case 4Bh DGROUP selector                     */
	u16 dx_2233 = 0x0000;    /* case 4Bh 54F0 dxOut                          */
	u16 bp_2234 = 0x0000;    /* case 4Bh 54F0 bpOut                          */
	u16 ds_1268 = 0x0000;    /* case 4Bh DGROUP selector                     */
	u16 bp_2235 = 0x0000;    /* case 4Bh 09C2 bpOut (inner)                  */
	u16 ds_1290 = 0x0000;    /* case 4Bh DGROUP selector (inner)             */
	u16 bp_2236 = 0x0000;    /* case 4Bh 09C2 bpOut (inner 2)                */
	u16 bp_2237 = 0x0000;    /* case 4Dh 09C2 bpOut                          */
	u16 ds_1142 = 0x0000;    /* case 4Dh DGROUP selector                     */
	u16 dx_2238 = 0x0000;    /* case 4Dh 54B1 dxOut                          */
	u16 bp_2239 = 0x0000;    /* case 4Dh 54B1 bpOut                          */
	u16 ds_1158 = 0x0000;    /* case 4Dh DGROUP selector                     */
	u16 bp_2240 = 0x0000;    /* case 4Dh 09C2 bpOut (inner)                  */
	u16 ds_1180 = 0x0000;    /* case 4Dh DGROUP selector (inner)             */
	u16 bp_2241 = 0x0000;    /* case 4Dh 09C2 bpOut (inner 2)                */
	u16 bp_2242 = 0x0000;    /* case 50h 09C2 bpOut                          */
	u16 ds_1092 = 0x0000;    /* case 50h DGROUP selector                     */
	u8 *es_2222 = 0;         /* 1EDA:0CD4 esOut (316Fh table)                */
	u8 *es_2223 = 0;         /* 1EDA:0CD4 esOut (318Fh table)                */
	u16 bp_2211 = 0x0000;    /* 0800:0768 bpOut                              */
	u16 ds_2025 = 0x0000;    /* 0800:0768 dsOut                              */
	s16 dx_2026 = 0x0000;    /* 0800:0768 return / 030D threading            */

	/* l0800_31BB: drain the pending-key queue.  fn1E78_030D takes no stack
	 * argument in the original (its wArg02 is the stale stack word), so it
	 * is seeded 0 here, matching the other part files. */
	while (fn1E78_02FB() != 0x00)
	{
		(void)fn1E78_030D(dx, 0x0000, (u16 *)&dx);
	}

	/* l0800_31CB: copy the cs:3112h record (0FFh-byte clamp) into
	 * [bp-0204h]. */
	(void)fn1EDA_0A39(0x00FF, buf204, &g_seg0800[0x3112], &dx_2182);

	/* call far 1206h:0066h -- show the mouse cursor. */
	(void)fn1206_0066(&bp_210, &ds_218);

	/* draw the panel frame. */
	(void)fn1AB8_1C32(0x08);
	fn1AB8_10F4(0x0001, 0x0000, 0x0000);
	(void)fn1AB8_112E(0x0177, 0x027F, 0x0000, 0x0000);
	fn0800_0024(0x01DF, 0x027F, 0x0179, 0x0000);
	(void)fn0800_1315(0x01DA, 0x027C, 0x017B, 0x0003);

	/* two 6-byte record copies out of DGROUP:5CB4h. */
	(void)fn1EDA_0A39(0x0006, &g_dgroup[0x5ECE], &g_dgroup[0x5CB4], &dx_2183);
	(void)fn1EDA_0A39(0x0006, &g_dgroup[0x5ED6], &g_dgroup[0x5CB4], &dx_2184);

	/* seed the mission counters from the loaded record. */
	LG8(0x53D9) = LG8(0x5CDE);
	LG8(0x53DA) = LG8(0x5CDF);
	LG8(0x53DB) = LG8(0x5CDA);
	LG8(0x53DC) = LG8(0x5CDB);
	if (LG8(0x5CDC) > 0x0A)
		LG8(0x5CDC) = 0x0A;
	LG8(0x53DD) = LG8(0x5CDC);
	LG8(0x53DE) = LG8(0x5CDD);

	/* l0800_3266: blit the button slots 0..8.  The original sets the slot
	 * counter, then runs the body first (do-while on [bp-2h] != 8). */
	bLoc02 = 0x00;
	for (;;)
	{
		(void)fn0800_09C2(bLoc02, &bp_2185, &ds_225);
		(void)fn1206_0066(&bp_210, &ds_218);
		if (bLoc02 == 0x08)
			break;
		++bLoc02;
	}

	/* l0800_328D: paint the input dialog frame. */
	(void)fn1AB8_1536(0x0001, 0x0000, 0x0000, &ds_268);
	fn1AB8_14F4(0x0001, 0x0001);
	(void)fn1AB8_1C32(0x08);
	/* first text row (cs:3153h,315Bh,3153h,3162h,3165h,3168h,316Bh at
	 * 1CEh). */
	(void)fn1AB8_1D82(&g_seg0800[0x3153], 0x01CE, 0x0043, &ch_2186);
	(void)fn1AB8_1D82(&g_seg0800[0x315B], 0x01CE, 0x0093, &ch_2187);
	(void)fn1AB8_1D82(&g_seg0800[0x3153], 0x01CE, 0x00E3, &ch_2188);
	(void)fn1AB8_1D82(&g_seg0800[0x3162], 0x01CE, 0x012F, &ch_2189);
	(void)fn1AB8_1D82(&g_seg0800[0x3165], 0x01CE, 0x0163, &ch_2190);
	(void)fn1AB8_1D82(&g_seg0800[0x3168], 0x01CE, 0x0197, &ch_2191);
	(void)fn1AB8_1D82(&g_seg0800[0x316B], 0x01CE, 0x01CB, &ch_2192);
	(void)fn1AB8_1C32(0x0B);
	/* second text row at 1CFh. */
	(void)fn1AB8_1D82(&g_seg0800[0x3153], 0x01CF, 0x0044, &ch_2193);
	(void)fn1AB8_1D82(&g_seg0800[0x315B], 0x01CF, 0x0094, &ch_2194);
	(void)fn1AB8_1D82(&g_seg0800[0x3153], 0x01CF, 0x00E4, &ch_2195);
	(void)fn1AB8_1D82(&g_seg0800[0x3162], 0x01CF, 0x0130, &ch_2196);
	(void)fn1AB8_1D82(&g_seg0800[0x3165], 0x01CF, 0x0164, &ch_2197);
	(void)fn1AB8_1D82(&g_seg0800[0x3168], 0x01CF, 0x0198, &ch_2198);
	(void)fn1AB8_1D82(&g_seg0800[0x316B], 0x01CF, 0x01CC, &ch_2199);
	(void)fn1AB8_1C32(0x00);

	/* 0800:3398: field widths / mouse range.  ax_809 = 04CC(53D9h); the
	 * second 04CC input keeps ax_809's high byte (the original pushes AX
	 * after `mov al,[53DAh]`), which 04CC ignores (it reads AL only). */
	(void)fn0800_04CC(0x0016);   /* result is the dropped 00FFh arg */
	(void)fn1206_00FF(&ds_601);
	(void)fn1206_012D(0, &ds_620);
	(void)fn1206_00D1(0, &si_2200, &es_2201, &ds_639);

	/* second frame block. */
	(void)fn1AB8_1536(0x0001, 0x0000, 0x0000, &ds_662);
	fn1AB8_14F4(0x0001, 0x0001);
	fn0800_005A(0x018F, 0x0114, 0x0184, 0x000F);
	(void)fn1AB8_1C32(0x08);
	(void)fn1AB8_1D82(&g_dgroup[0x5CBB], 0x0189, 0x0093, &ch_2202);
	(void)fn1AB8_1C32(0x0A);
	(void)fn1AB8_1D82(&g_dgroup[0x5CBB], 0x018A, 0x0094, &ch_2203);

	/* 0800:340C: repaint the HUD and the clock, then set button 8. */
	(void)fn0800_04E3(&ds_754);
	(void)fn0800_0619();
	(void)fn0800_0BEC();
	(void)fn1AB8_1342(0x0000, 0x0008);
	ax_809 = (u16)fn0800_04CC(LG8(0x53D9));
	w_816 = (u16)((ax_809 & 0xFF00u) | (u16)LG8(0x53DA));
	w_817 = (u16)fn0800_04CC((u8)w_816);
	(void)engine_arm_window_geometry(w_817, ax_809);
	(void)fn0800_09C2(0x0B, &bp_2204, &ds_2243);

	/* l0800_3433: wait for a key or a mouse button, then one 09C2(2h). */
	while (fn1E78_02FB() == 0x00)
	{
		if ((u8)fn1206_015B(&ch_2205, &dx_2206, &bp_2207, &ds_2243) != 0x00)
			break;
	}
	(void)fn0800_09C2(0x02, &bp_1120, &ds_1001);

	/* 0800:3447: arm the millisecond timer (60 * [53DDh] -> 0800:00C1). */
	ax_low = (u16)((u16)LG8(0x53DD) * 0x003C);
	dx_high = (u16)(((s16)ax_low < 0) ? 0xFFFF : 0x0000);
	(void)fn0800_00C1(ax_low, dx_high, (u16 *)&dx_1012);
	bLoc01 = 0x01;

	/* l0800_345E: mission input loop. */
	for (;;)
	{
		/* 0800:345E: if neither a key nor a mouse button is pending, skip
		 * straight to the clock tick at 0800:364Ah. */
		if (fn1E78_02FB() != 0x00)
			goto l0800_3475;
		if ((u8)fn1206_015B(&ch_2208, (u16 *)&dx_1012, &bp_1120,
		                    &ds_1001) != 0x00)
			goto l0800_3475;
		goto l0800_364A;

	l0800_3475:
		/* 0800:3475: read the command byte. */
		if (fn1E78_02FB() != 0x00)
		{
			LG8(0x53D2) = (u8)fn1E78_030D(dx_1012, 0x0000,
			                              (u16 *)&dx_1012);
			if (LG8(0x53D2) == 0x00)
				LG8(0x53D2) = (u8)fn1E78_030D(dx_1012, 0x0000,
				                              (u16 *)&dx_1012);
			while (fn1E78_02FB() != 0x00)
				(void)fn1E78_030D(dx_1012, 0x0000,
				                  (u16 *)&dx_1012);
		}
		else
		{
			word16 ax_996 = fn0800_031B(&bp_1120, &ds_1001);

			LG8(0x53D2) = (u8)ax_996;
		}

		/* l0800_34AD: dispatch the command byte (latched once in AL). */
		al_1056 = LG8(0x53D2);
		switch (al_1056)
		{
		case 0x3B:
			/* ';' -- consume one 53DBh counter if the menu allows it. */
			(void)fn0800_09C2(0x0E, &bp_2209, &ds_1658);
			if (LG8(0x53DB) > 0x00)
			{
				if (engine_frame_dispatch(&bp_2210, &ds_1658) != 0x00)
					LG8(0x53DB) = (u8)(LG8(0x53DB) - 0x01);
			}
			(void)fn0800_09C2(0x05, &bp_1120, &ds_1001);
			break;
		case 0x3C:
			/* '<' -- consume one 53DCh counter. */
			(void)fn0800_09C2(0x0F, &bp_2224, &ds_1593);
			if (LG8(0x53DC) > 0x00)
			{
				if (engine_frame_retract(&ds_1593) != 0x00)
					LG8(0x53DC) = (u8)(LG8(0x53DC) - 0x01);
			}
			(void)fn0800_09C2(0x06, &bp_1120, &ds_1001);
			break;
		case 0x3D:
			/* '=' -- consume one 53DEh counter. */
			(void)fn0800_09C2(0x10, &bp_2225, &ds_1530);
			if (LG8(0x53DE) > 0x00 &&
			    engine_frame_pull_in_extended(&ds_1530) != 0x00)
				LG8(0x53DE) = (u8)(LG8(0x53DE) - 0x01);
			(void)fn0800_09C2(0x07, &bp_1120, &ds_1001);
			break;
		default:
			if (al_1056 == 0x1B)
			{
				/* Esc -- leave the dialog. */
				fn0800_0103();
				goto l0800_36E4;
			}
			else if (al_1056 == 0x20)
			{
				/* space -- save the timer, repaint, restore it. */
				u16 dx_1412 = LG16(0x58DA);

				LG16(0x58D0) = LG16(0x58D8);
				LG16(0x58D2) = dx_1412;
				fn0800_0103();
				(void)fn0800_09C2(0x0B, &bp_2226, &ds_1429);
				while (fn1E78_02FB() == 0x00)
				{
					if ((u8)fn1206_015B(&ch_2228, &dx_2229,
					                    &bp_2230,
					                    &ds_1429) != 0x00)
						break;
				}
				(void)fn0800_09C2(0x02, &bp_1120, &ds_1001);
				(void)fn0800_00C1(LG16(0x58D0), LG16(0x58D2),
				                  &dx_2227);
			}
			else if (al_1056 == 0x44)
			{
				/* 'D' -- toggle the DGROUP:58B0h flag. */
				if (LG8(0x58B0) != 0x00)
					LG8(0x58B0) = 0x00;
				else
					LG8(0x58B0) = 0x01;
			}
			else if (al_1056 == 0x48)
			{
				/* 'H' -- move the selection up/left. */
				(void)fn0800_09C2(0x09, &bp_2231, &ds_1362);
				(void)engine_call_rocket_trajectory();
				(void)fn0800_09C2(0x00, &bp_1120, &ds_1001);
			}
			else if (al_1056 == 0x4B)
			{
				/* 'K' -- move the selection. */
				(void)fn0800_09C2(0x0A, &bp_2232, &ds_1252);
				if (engine_probe_march_left(&dx_2233, &bp_2234,
				                &ds_1268) == 0x00)
				{
					(void)fn0800_09C2(0x0E, &bp_2235,
					                  &ds_1290);
					(void)fn0800_08C0();
					(void)fn0800_09C2(0x05, &bp_2236,
					                  &ds_1268);
				}
				(void)fn0800_09C2(0x01, &bp_1120, &ds_1001);
			}
			else if (al_1056 == 0x4D)
			{
				/* 'M' -- move the selection. */
				(void)fn0800_09C2(0x0C, &bp_2237, &ds_1142);
				if (engine_probe_march_right(&dx_2238, &bp_2239,
				                &ds_1158) == 0x00)
				{
					(void)fn0800_09C2(0x0E, &bp_2240,
					                  &ds_1180);
					(void)fn0800_08C0();
					(void)fn0800_09C2(0x05, &bp_2241,
					                  &ds_1158);
				}
				(void)fn0800_09C2(0x03, &bp_1120, &ds_1001);
			}
			else if (al_1056 == 0x50)
			{
				/* 'P' -- page the selection. */
				(void)fn0800_09C2(0x0D, &bp_2242, &ds_1092);
				(void)engine_edge_collision_probe();
				(void)fn0800_09C2(0x04, &bp_1120, &ds_1001);
			}
			break;
		}

		/* l0800_35FA: append the byte to the line buffer when the
		 * cs:316Fh / cs:318Fh bit tables allow it.  0CD4 returns 0 when
		 * the tested bit is SET (ZF semantics). */
		if (fn1EDA_0CD4(&g_seg0800[0x316F], LG8(0x53D2),
		                &es_2222) == 0x00)
		{
			buf204[bLoc01] = LG8(0x53D2);
			if (bLoc01 < 0xFF)
				++bLoc01;
			if (fn1EDA_0CD4(&g_seg0800[0x318F], LG8(0x53D2),
			                &es_2223) == 0x00)
			{
				buf204[bLoc01] = LG8(0x58BC);
				if (bLoc01 < 0xFF)
					++bLoc01;
			}
		}

	l0800_364A:
		/* 0800:364A: tick the clock, then test the exit flags. */
		dx_1012 = fn0800_0C71(&bp_1120, &ds_1001);
		if (fn0800_0877() != 0x00 || LG8(0x58B3) != 0x00)
			break;
	}

	/* l0800_365E: when fn0800_0877 signals completion, write the line
	 * buffer back into the cs:31AFh-named stream as one 0x100-byte record. */
	if (fn0800_0877() != 0x00)
	{
		u8 *saved_io;
		u32 ax_04a9;
		u16 dx_2212 = 0x0000;    /* 1EDA:0FD0 dxOut                    */
		u8  ch_2214;             /* 1EDA:04A9 chOut                    */
		u16 ds_1914 = 0x0000;    /* 1EDA:04A9 dsOut                    */
		u8  ch_2216;             /* 1EDA:04A9 chOut                    */
		u16 ds_1946 = 0x0000;    /* 1EDA:04A9 dsOut                    */
		u8  ch_2218;             /* 1EDA:04A9 chOut                    */
		u16 ds_1979 = 0x0000;    /* 1EDA:04A9 dsOut                    */
		u8  ch_2221;             /* 1EDA:04A9 chOut                    */

		fn1EDA_0FA2(&g_seg0800[0x31AF], buf284);
		(void)fn1EDA_0FD0(0x0100, buf284, &dx_2212);
		(void)fn1EDA_04A9(0x0000, 0x0000, &ch_2214, &ds_1914);
		(void)fn1EDA_1123(LG16(0x598E), LG16(0x5990), buf284);
		ax_04a9 = fn1EDA_04A9(0x0000, 0x0000, &ch_2216, &ds_1946);
		/* fn1EDA_108C's dropped data-buffer pointer is the caller's
		 * [bp-0204h] line buffer; point the shared I/O slot at it. */
		saved_io = g_1EDA_io_buffer;
		g_1EDA_io_buffer = buf204;
		fn1EDA_108C((u8)ax_04a9, buf284);
		g_1EDA_io_buffer = saved_io;
		ax_04a9 = fn1EDA_04A9(0x0000, 0x0000, &ch_2218, &ds_1979);
		(void)fn1EDA_1051((u8)ax_04a9, buf284);
		(void)fn1EDA_04A9(0x0000, 0x0000, &ch_2221, &ds_1001);
	}

	/* l0800_36C9: "PRESSEZ UNE TOUCHE" wait, then drain the key queue. */
	fn0800_0103();
	dx_2026 = fn0800_0768(&bp_2211, &ds_2025);
	while (fn1E78_02FB() != 0x00)
		(void)fn1E78_030D(dx_2026, 0x0000, (u16 *)&dx_2026);
	(void)fn1206_0066(&bp_1120, &ds_1001);

l0800_36E4:
	/* The surviving caller (fn0800_3D9D:40EA) ignores the return value; the
	 * original leaves a frame word in AX that has no flat-C equivalent. */
	*dsOut = ds_1001;
	return 0x0000;
}
