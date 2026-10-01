/* seg0800_part2.c -- RAD V3.1 preservation port, segment 0800, part 2.
 *
 * Functions 0800:0619 .. 0800:0AA1 (7 functions, ascending offset):
 *   0619 0768 0877 08C0 08E9 09C2 0AA1
 *
 * Literal recovery from analysis/slices/0800/0800_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg0800.h
 * (analysis/summary/iface.tsv).  See CONVENTIONS.md and
 * docs/notes-0800.md ("## part 2").
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   None.  No int 10h / int 16h / int 21h, no `in`/`out` port instruction,
 *   no __cli/__sti and no int 23h occur in 0619..0AA1.  Every BIOS/DOS
 *   service reached from here goes through the callee segments already
 *   converted: fn1AB8_* (video), fn1EDA_* (formatted records/data files),
 *   fn0C74_* (menus), fn1206_* (mouse, INT 33h via dos_interrupt_trampoline) and
 *   fn1E78_* (keyboard/PIT).  The strings cs:0605={4,"DEMO"}, cs:060A=
 *   {3,"000"}, cs:060E={1,"0"}, cs:0610={8,"MISSION "}, cs:0755={7,
 *   "PRESSEZ"}, cs:075D={10,"UNE TOUCHE"}, cs:0A9F={1,"0"} are referenced
 *   from the segment image exactly as the original does.
 *
 * Flat-model far pointers:
 *   The DGROUP far-pointer tables at 0x5388 (RAD.BUT, written by 03F8) and
 *   0x598E/0x5990 (RAD.STR stream position) are read as their two literal
 *   words: LG32(off) = (segment << 16) | offset, the same convention used by
 *   seg0800_part1.c.
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0800.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg0C74.h"
#include "seg1206.h"
#include "seg1E78.h"

// 0800:0619: u16 fn0800_0619(void)
// Pause/mission-select overlay: paint the box, compare the current record at
// ds:5ECE against cs:0605 ("DEMO"), build the two "MISSION n" labels from the
// 3-byte selected-record buffer, and draw them.
u16 fn0800_0619(void)
{
	u8 *abBuf = g_dgroup + 0xF800;
	                    /* [bp-0104h] formatted string / record scratch (Reko
	                     * ptrLoc010A).  SS-resident, and SS==DS in the tiny
	                     * model, so stage at DGROUP 0xF800 for the ES:BX
	                     * materialization that bgi_get_char_size_info does for the
	                     * driver's 0x26 text op (a C stack buffer resolves to
	                     * segment 0 and the "MISSION n" line drew nothing). */
	u8  bLoc04[0x04];   /* [bp-0004h] 3-byte selected-record copy */
	u16 ax_569;
	u16 dx_570;
	u16 ds_43 = 0x0000; /* dropped DGROUP selector out of bgi_load_video_driver_file */
	u16 dx_571;
	u16 dx_572;
	u16 dx_573;
	u16 dx_578;
	u8  ch_574;
	u8  ch_575;
	u8  ch_576;
	u8  ch_577;

	fn0800_005A(0x01CF, 0x0264, 0x01A7, 0x0204);
	(void)bgi_load_video_driver_file(0x0000, 0x0000, 0x0000, &ds_43);
	bgi_set_text_rectangle(0x0001, 0x0001);

	/* 0800:0627: fn1EDA_0B24(cs:0605, ds:5ECE) sets ZF when equal. */
	if (fn1EDA_0B24(&g_seg0800[0x0605], &g_dgroup[0x5ECE], &ax_569, &dx_570) == 0x00)
	{
		/* l0800_0651: not "DEMO" -- build the record from the far pointer
		 * stored at [5990h]:[598Eh]. */
		engine_format_u32(LG32(0x598E), abBuf);
		(void)fn1EDA_0A39(0x03, bLoc04, abBuf, &dx_572);
	}
	else
	{
		/* l0800_0672: equal -- the canonical {3,"000"} record. */
		(void)fn1EDA_0A39(0x03, bLoc04, &g_seg0800[0x060A], &dx_571);
	}

	/* The three "MISSION" strings; [bp-4h] (bLoc04[0]) is re-read after each
	 * block because fn1EDA_0A39 rewrites the length byte. */
	if (bLoc04[0] < 0x02)
	{
		fn1EDA_0A1F(&g_seg0800[0x060E], abBuf);       /* {1,"0"} */
		fn1EDA_0AAC(bLoc04, abBuf);
		(void)fn1EDA_0A39(0x03, bLoc04, abBuf, &dx_573);
	}
	if (bLoc04[0] < 0x03)
	{
		fn1EDA_0A1F(&g_seg0800[0x060E], abBuf);       /* {1,"0"} */
		fn1EDA_0AAC(bLoc04, abBuf);
		(void)fn1EDA_0A39(0x03, bLoc04, abBuf, &dx_578);
	}

	bgi_get_text_cursor_attributes(0x08);
	fn1EDA_0A1F(&g_seg0800[0x0610], abBuf);               /* {8,"MISSION "} */
	fn1EDA_0AAC(bLoc04, abBuf);
	(void)bgi_get_char_size_info(abBuf, 0x01AE, 0x0233, &ch_574);
	(void)bgi_get_char_size_info(&g_dgroup[0x5ECE], 0x01C6, 0x0233, &ch_575);
	bgi_get_text_cursor_attributes(0x0B);
	fn1EDA_0A1F(&g_seg0800[0x0610], abBuf);               /* {8,"MISSION "} */
	fn1EDA_0AAC(bLoc04, abBuf);
	(void)bgi_get_char_size_info(abBuf, 0x01AF, 0x0234, &ch_576);
	(void)bgi_get_char_size_info(&g_dgroup[0x5ECE], 0x01C7, 0x0234, &ch_577);

	return ds_43;   /* original returns the dropped DGROUP selector (0) */
}

// 0800:0768: s16 fn0800_0768(u16 * bpOut, u16 * dsOut)
// "PRESSEZ UNE TOUCHE" wait: two timed waits (2500 and 5000 ticks) on the
// mouse/keyboard, each followed by a key-release drain, then return.
s16 fn0800_0768(u16 * bpOut, u16 * dsOut)
{
	u16 wLoc02 = 0x0000;   /* [bp-0002h] wait counter (Reko bp_157.tFFFE) */
	u16 wLoc04 = 0x0000;   /* uninitialised 030D wArg02 stack slot (Reko ss->*sp) */
	u16 ds_111 = 0x0000;   /* dropped DGROUP selector out of bgi_load_video_driver_file */
	u16 bpDummy = 0x0000;  /* 015B BP-register output, discarded */
	s16 dx_170 = 0x0000;   /* 015B DX-register output / return value */
	u8  ch_440;
	u8  ch_441;
	u8  ch_442;
	u8  ch_443;
	u8  ch_444;
	u8  ch_445;
	u8  ch_446;
	u8  ch_447;

	(void)bgi_load_video_driver_file(0x0000, 0x0000, 0x0000, &ds_111);
	bgi_set_text_rectangle(0x0001, 0x0001);
	bgi_get_text_cursor_attributes(0x08);
	fn0800_005A(0x01CF, 0x0264, 0x01A7, 0x0204);
	(void)bgi_get_char_size_info(&g_seg0800[0x0755], 0x01AE, 0x0233, &ch_440);   /* {7,"PRESSEZ"} */
	(void)bgi_get_char_size_info(&g_seg0800[0x075D], 0x01C6, 0x0233, &ch_441);   /* {10,"UNE TOUCHE"} */

l0768_07B6:
	bgi_get_text_cursor_attributes(0x0B);
	(void)bgi_get_char_size_info(&g_seg0800[0x0755], 0x01AF, 0x0234, &ch_446);
	(void)bgi_get_char_size_info(&g_seg0800[0x075D], 0x01C7, 0x0234, &ch_447);
	wLoc02 = 0x0001;
	goto l0768_07E7;

l0768_07E4:
	++wLoc02;

l0768_07E7:
	if ((u8)fn1206_015B(&ch_442, (u16 *)&dx_170, &bpDummy, &ds_111) != 0x00)
		goto l0768_0875;
	if (fn1E78_02FB() != 0x00)
		goto l0768_0875;
	if (wLoc02 != 0x09C4)               /* 2500 */
		goto l0768_07E4;

	/* l0800_0804: second, longer wait. */
	bgi_get_text_cursor_attributes(0x0E);
	(void)bgi_get_char_size_info(&g_seg0800[0x0755], 0x01AF, 0x0234, &ch_443);
	(void)bgi_get_char_size_info(&g_seg0800[0x075D], 0x01C7, 0x0234, &ch_444);
	wLoc02 = 0x0001;
	goto l0768_0835;

l0768_0832:
	++wLoc02;

l0768_0835:
	if ((u8)fn1206_015B(&ch_445, (u16 *)&dx_170, &bpDummy, &ds_111) != 0x00)
		goto l0768_0875;
	if (fn1E78_02FB() != 0x00)
		goto l0768_0875;
	if (wLoc02 != 0x1388)               /* 5000 */
		goto l0768_0832;

	/* l0800_0852: after the second timeout, wait for the key to be released,
	 * draining the keyboard buffer, then restart the whole sequence. */
	if (fn1E78_02FB() == 0x00)
		goto l0768_07B6;

l0768_085E:
	if (fn1E78_02FB() == 0x00)
		goto l0768_086E;
	(void)fn1E78_030D(dx_170, wLoc04, (u16 *)&dx_170);
	goto l0768_085E;

l0768_086E:
	bgi_get_text_cursor_attributes(0x00);

l0768_0875:
	*bpOut = 0x0000;   /* saved-BP output; not meaningful here */
	*dsOut = 0x0000;   /* DGROUP selector dropped in the flat model */
	return dx_170;
}

// 0800:0877: u8 fn0800_0877(void)
// Scan the 0x5EB0 grid for a cell equal to '^' whose bgi_draw_line result is not
// 0x0F; returns 1 when the index reaches 0x1C while still scanning, else 0.

/* Diagnostic (RAD_WIN_TRACE env): log fn0800_0877 outcomes; every ret=1,
 * ret=0 sampled at powers-of-two call counts; inert unless the env is set. */
static void rad0877_trace(u8 ret, u8 idx, u8 tile, u8 pix)
{
	static int on = -1;
	static unsigned long cnt;
	static struct timespec last;
	if (on < 0)
		on = getenv("RAD_WIN_TRACE") != NULL;
	if (!on)
		return;
	++cnt;
	if (ret == 0 && (cnt & (cnt - 1)) != 0)
		return;
	clock_gettime(CLOCK_MONOTONIC, &last);
	fprintf(stderr, "rad0877: n=%lu ret=%u idx=%02X tile=%02X pix=%02X\n",
	        cnt, ret, idx, tile, pix);
}

u8 fn0800_0877(void)
{
	u8 bLoc01 = 0x00;   /* [bp-0001h] result flag (Reko bLoc03_64) */
	u8 bLoc02 = 0x00;   /* [bp-0002h] grid index (Reko bLoc04_65) */
	u8 dl_109;

	while (LG8((u16)(0x5EB0 + (u16)bLoc02)) != 0x5E ||
	       bgi_draw_line(0x0176,
	                   (u16)((u16)bLoc02 * 0x0016 + 0x000B),
	                   &dl_109) == 0x000F)
	{
		if (bLoc02 == 0x1C)
		{
			bLoc01 = 0x01;
			rad0877_trace(bLoc01, 0xFF, 0, 0);
			return bLoc01;
		}
		++bLoc02;
	}
	rad0877_trace(bLoc01, bLoc02, LG8((u16)(0x5EB0 + (u16)bLoc02)), dl_109);
	return bLoc01;
}

// 0800:08C0: u16 fn0800_08C0(void)
// If the 53DBh counter is positive, consume one via engine_frame_dispatch and return 1.
/* NOTE: analysis/summary/iface.tsv documents this return as the dropped DGROUP
 * selector, but the .asm's only return write is `mov al,[bp-1h]` (the flag);
 * the frozen prototype is u16, so the flag is returned.  Every caller
 * (fn0800_2401/2827/2C0C/31B7) discards it. */
u16 fn0800_08C0(void)
{
	u8 bLoc01 = 0x00;   /* [bp-0001h] result flag */
	u16 bp_16 = 0x0000;
	u16 ds_16 = 0x0000;

	if (LG8(0x53DB) > 0x00)
	{
		if (engine_frame_dispatch(&bp_16, &ds_16) != 0x00)
		{
			bLoc01 = 0x01;
			LG8(0x53DB) = (u8)(LG8(0x53DB) - 0x01);
		}
	}
	return (u16)bLoc01;
}

// 0800:08E9: s16 fn0800_08E9(s16 dx)
// Grid hit-test loop: for every cell, call bgi_draw_line; when it reports 0x0F
// select the cell via engine_scatter_starfield.  Esc sets the 58B3h latch.  Called from
// fn0800_0C71 only; the return value is discarded there.
s16 fn0800_08E9(s16 dx)
{
	u8  bLoc02 = 0x00;   /* [bp-0002h] outer row index (Reko bLoc04_166) */
	u8  bLoc01 = 0x00;   /* [bp-0001h] inner col index (Reko bLoc03_167) */
	u16 wLoc04 = 0x0000; /* [bp-0004h] 030D wArg02 stack slot (uninitialised in
	                      * the original; seeded 0 for determinism) */
	s16 dx_134 = 0x0000; /* 030D DX output (Reko return value) */
	u8  dh_156;
	u8  dl_67 = 0x00;

	for (;;)
	{
		bLoc01 = 0x00;
		for (;;)
		{
			dh_156 = (u8)((u16)dx >> 8);
			if (fn1E78_02FB() != 0x00)
			{
				dh_156 = (u8)((u16)dx_134 >> 8);
				if ((u8)fn1E78_030D(dx, wLoc04, (u16 *)&dx_134) == 0x1B)
				{
					LG8(0x58B3) = 0x01;
					return dx_134;
				}
			}
			/* asm 091D: bgi_draw_line(bLoc02*22+1, bLoc01*22+1) */
			wLoc04 = (u16)((u16)bLoc01 * 0x0016 + 0x0001);
			if (bgi_draw_line((u16)((u16)bLoc02 * 0x0016 + 0x0001),
			                wLoc04, &dl_67) == 0x000F)
			{
				/* asm 093B: engine_scatter_starfield(bLoc02*22+22, bLoc01*22+22,
				 *                    bLoc02*22+1, bLoc01*22+1) */
				wLoc04 = (u16)((u16)bLoc01 * 0x0016 + 0x0001);
				dx = (s16)engine_scatter_starfield(
					(u16)((u16)bLoc02 * 0x0016 + 0x0016),
					(u16)((u16)bLoc01 * 0x0016 + 0x0016),
					(u16)((u16)bLoc02 * 0x0016 + 0x0001),
					wLoc04);
			}
			else
			{
				/* Reko threads DX as (dh_156, callee DL output). */
				dx = (s16)(((u16)dh_156 << 8) | (u16)dl_67);
			}
			if (bLoc01 == 0x1D)
				break;
			++bLoc01;
		}
		if (bLoc02 == 0x11)
		{
			dx_134 = (s16)engine_scatter_muck();
			return dx_134;
		}
		++bLoc02;
	}
}

// 0800:09C2: u8 fn0800_09C2(u8 bArg02, u16 * bpOut, u16 * dsOut)
// Select one of the 0x11 button bitmaps: compute its screen line, blit the
// 5388h far-pointer slot, frame it, then conditionally repaint the HUD (04E3)
// and show the mouse cursor (fn1206_0038).
u8 fn0800_09C2(u8 bArg02, u16 * bpOut, u16 * dsOut)
{
	u16 wLoc02 = 0x0000;   /* [bp-0002h] computed screen line */
	u16 bp_236 = 0x0000;   /* 0066/0038 BP-register output */
	u16 ds_198 = 0x0000;   /* dropped DGROUP selector */
	u16 es_297 = 0x0000;
	u16 es_298 = 0x0000;
	u16 ax_235 = 0x0000;   /* Reko's uninitialised al_223 seeded 0 */
	u8  ch_299;
	u16 dx_300;
	u8 *blk;

	LG8(0x58E4) = bArg02;                 /* [58E4h] = bArg02 */
	if (bArg02 <= 0x08)
	{
		wLoc02 = (u16)((u16)bArg02 * 0x0008 +
		               (u16)(fn0800_04CC((u8)(bArg02 << 0x01)) + 0x0016));
	}
	else if (bArg02 >= 0x09 && bArg02 <= 0x10)
	{
		wLoc02 = (u16)((u16)((u16)bArg02 - 0x0009) * 0x0008 +
		               (u16)(fn0800_04CC((u8)(((u16)bArg02 - 0x0009) << 0x01)) + 0x0016));
	}
	bgi_get_text_cursor_attributes(0x0B);
	(void)fn1206_0066(&bp_236, &ds_198);
	/* les di,[di+5388h] with di = bArg02*4 */
	blk = far_ptr(LG32((u16)(0x5388 + (u16)bArg02 * 0x0004)));
	(void)bgi_signed_rectangle_intersect(0x00, blk, 0x0198, wLoc02);
	bgi_set_text_background_color(0x0001, 0x0000, 0x0000);
	bgi_get_text_cursor_attributes(0x00);
	(void)bgi_clip_text_rectangle(0x01C4, (u16)(wLoc02 + 0x002C), 0x0197,
	                  (u16)(wLoc02 - 0x0001));
	/* asm 0A7C: jz 0A86h -- call 04E3 when 0CD4 returns 0 (bit set). */
	if (fn1EDA_0CD4(&g_seg0800[0x0982], bArg02, &es_297) == 0x00)
		(void)fn0800_04E3(&ds_198);
	/* asm 0A93: jnz 0A9Bh -- call 0038 when 0CD4 returns 1 (bit clear).
	 * NOTE: Reko wrote this site as `if (!...)` but the machine code is the
	 * opposite branch from the 0CD4 call above; the .asm is followed here. */
	if (fn1EDA_0CD4(&g_seg0800[0x09A2], bArg02, &es_298) != 0x00)
		ax_235 = (u16)fn1206_0038(&ch_299, &dx_300, &bp_236, &ds_198);
	*bpOut = 0x0000;   /* saved-BP output; not meaningful here */
	*dsOut = 0x0000;   /* DGROUP selector dropped in the flat model */
	return (u8)(ax_235 >> 8);
}

// 0800:0AA1: u16 fn0800_0AA1(u16 * dsOut)
// Increment/consume one item of the record at [58DEh]:[58DCh]; while its length
// byte is < 2, append a '0' digit record; then paint the two updated labels and
// show the mouse cursor.
u16 fn0800_0AA1(u16 * dsOut)
{
	u8  abBuf[0x100];   /* [bp-0104h] record scratch (Reko ptrLoc010A) */
	u8 *bLoc04 = g_dgroup + 0xF6E0;
	                    /* [bp-0004h] 2-byte selected-record copy.  SS-resident
	                     * (SS==DS in the tiny model), and it is the 1D82
	                     * source, so stage at DGROUP 0xF6E0 for the ES:BX
	                     * materialization (a C stack buffer resolves to
	                     * segment 0 and the seconds digits drew nothing). */
	u16 dx_257;
	u16 dx_262;
	u16 bp_122 = 0x0000;
	u16 ds_126 = 0x0000;
	u8  ch_258;
	u8  ch_259;
	u8  ch_260;
	u16 dx_261;
	u16 bp_206 = 0x0000;
	u16 ds_210 = 0x0000;

	engine_format_u32(LG32(0x58DC), abBuf);
	(void)fn1EDA_0A39(0x02, bLoc04, abBuf, &dx_257);
	if (bLoc04[0] < 0x02)
	{
		fn1EDA_0A1F(&g_seg0800[0x0A9F], abBuf);       /* {1,"0"} */
		fn1EDA_0AAC(bLoc04, abBuf);
		(void)fn1EDA_0A39(0x02, bLoc04, abBuf, &dx_262);
	}
	(void)fn1206_0066(&bp_122, &ds_126);
	fn0800_005A(0x019B, 0x025C, 0x0192, 0x024B);
	bgi_get_text_cursor_attributes(0x08);
	(void)bgi_get_char_size_info(bLoc04, 0x0196, 0x0253, &ch_258);
	bgi_get_text_cursor_attributes(0x0A);
	(void)bgi_get_char_size_info(bLoc04, 0x0197, 0x0254, &ch_259);
	(void)fn1206_0038(&ch_260, &dx_261, &bp_206, &ds_210);
	bgi_get_text_cursor_attributes(0x00);

	*dsOut = 0x0000;   /* DGROUP selector dropped in the flat model */
	return bp_206;     /* saved-BP output (Reko returns [bp_206]) */
}
