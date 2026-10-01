/* seg0800_part6.c -- RAD V3.1 preservation port, segment 0800, part 6.
 *
 * Functions 0800:1D55 .. 0800:2004 (3 functions, ascending offset):
 *   1D55 1E3F 2004
 *
 * Literal recovery from analysis/slices/0800/0800_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg0800.h
 * (analysis/summary/iface.tsv) adopted exactly.  See CONVENTIONS.md and
 * docs/notes-0800.md ("## part 6").
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   None.  No int 10h / int 16h / int 21h, no `in`/`out` port instruction,
 *   no __cli/__sti, no int 23h and no raw IVT dispatch occur in 1D55..2004.
 *   The mouse cursor/position is reached through segment 1206
 *   (renamed_1206_0094 / renamed_1206_0066 / renamed_1206_015b, themselves INT 33h wrappers
 *   replaced in seg1206.c), the keyboard/PIT delay through segment 1E78
 *   (renamed_1e78_02fb / renamed_1e78_030d / renamed_1e78_029c, replaced there with
 *   bios_kbd_* / pal_*), and every text/drawing primitive through segment
 *   1AB8 (bgi_get_text_cols / 14F4 / 1536 / 1C32 / 1D82) and segment 1EDA
 *   (renamed_1eda_0cd4, the bit test).  No PAL call is issued in this file.
 *
 * Flat-model far pointers:
 *   renamed_0800_1e3f stages the ds:2306h + (row<<8) table as
 *   &g_dgroup[(u16)((row << 8) + 0x2306)]; renamed_0800_2004 stages
 *   ds:3706h + (row<<8) as &g_dgroup[(u16)((row << 8) + 0x3706)].  The
 *   cs:1DE0h / cs:1E1Fh (1E3F) and cs:1FB5h / cs:1FE4h (2004) bit-test
 *   tables become &g_seg0800[0x1DE0] / [0x1E1F] / [0x1FB5] / [0x1FE4]; the
 *   cs:1E00h (1E3F) and cs:1FD5h (2004) label pointers become
 *   &g_seg0800[0x1E00] / &g_seg0800[0x1FD5].
 *
 * DGROUP offsets read: 53E2h/53FEh/53F0h/540Ch (slot edge tables, 1D55),
 *   53D8h (selected flag) and 0002h (deferred action byte) in 1E3F/2004.
 */

#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0800.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1206.h"
#include "seg1E78.h"

/* 0800:1D55: u8 renamed_0800_1d55(u16 * dxOut, void * bpOut, u16 * dsOut)
 * Hit-test the mouse cursor (polled from INT 33h through renamed_1206_0094) against
 * the eight slot boxes whose edges live in DGROUP 53E2h (left), 53FEh (right),
 * 53F0h (top) and 540Ch (bottom), each indexed by the 1..7 slot number.  The
 * first slot that strictly contains the cursor (left < x < right and
 * top < y < bottom) yields its function-key code 3Ah + slot (F1..F7); if none
 * matches the result is 0.  The poll loop repeats while a button is held. */
u8 renamed_0800_1d55(u16 *dxOut, void *bpOut, u16 *dsOut)
{
	/* The frame's dead words [bp-2h] and [bp-0Ah] hold no live value and
	 * are not modelled. */
	u16 wLoc04 = 0x0000;  /* [bp-4h] 1206:0094 dsOut (BX, button state) */
	u16 wLoc06 = 0x0000;  /* [bp-6h] 1206:0094 bpOut (CX, cursor x)     */
	u16 wLoc08 = 0x0000;  /* [bp-8h] 1206:0094 dxOut (DX, cursor y)     */
	u8  bLoc09;           /* [bp-9h] slot index 1..7                    */
	u8  bLoc01;           /* [bp-1h] result key code                    */

	/* l0800_1D59: poll the cursor/buttons until none is pressed.  The
	 * three out words are seeded 0 above because a missing mouse driver
	 * leaves them unwritten. */
	do
	{
		(void)renamed_1206_0094(&wLoc08, &wLoc06, &wLoc04);
	} while (wLoc04 != 0x0000);

	bLoc01 = 0x00;
	bLoc09 = 0x01;
	for (;;)
	{
		u16 di = (u16)((u16)bLoc09 << 0x01);   /* shl di,1h */

		/* l0800_1D80: cmp [di+53E2h],[bp-6h] ; jge 1DD5h */
		if ((s16)LG16((u16)(0x53E2 + di)) >= (s16)wLoc06)
			goto l0800_1DD5;
		/* l0800_1D92: cmp [di+53FEh],[bp-6h] ; jle 1DD5h */
		if ((s16)LG16((u16)(0x53FE + di)) <= (s16)wLoc06)
			goto l0800_1DD5;
		/* l0800_1DA4: cmp [di+53F0h],[bp-8h] ; jge 1DD5h */
		if ((s16)LG16((u16)(0x53F0 + di)) >= (s16)wLoc08)
			goto l0800_1DD5;
		/* l0800_1DB6: cmp [di+540Ch],[bp-8h] ; jle 1DD5h */
		if ((s16)LG16((u16)(0x540C + di)) <= (s16)wLoc08)
			goto l0800_1DD5;

		/* l0800_1DC8: slot hit -> key code = slot + 3Ah. */
		bLoc01 = (u8)((u16)bLoc09 + 0x003A);
		break;

	l0800_1DD5:
		/* cmp [bp-9h],7h ; jnz 1D7Dh (inc) else fall to 1DDBh. */
		if (bLoc09 == 0x07)
			break;
		++bLoc09;
	}

	/* Register-output threading (the only caller, renamed_0800_3d9d:3ED9, uses AL
	 * only): DX at ret is 1206:0094's cursor-y output = wLoc08; BP is the
	 * saved caller frame (no flat meaning); DS is the dropped DGROUP
	 * selector. */
	*dxOut = wLoc08;
	*(u16 *)bpOut = 0x0000;
	*dsOut = 0x0000;
	return bLoc01;
}

/* 0800:1E3F: u16 renamed_0800_1e3f(s16 dx, u16 * dsOut)
 * The 20-row (rows 1..14h) "SUITE." command screen.  Drains the key buffer,
 * draws the frame with renamed_0800_1315 and, per row, blits the ds:2306h +
 * (row<<8) label twice (normal then highlighted) with bgi_get_char_size_info, choosing
 * attribute 0Ah when the row's bit is set in the cs:1DE0h table (via
 * renamed_1eda_0cd4) and 0Bh otherwise.  Then it draws the cs:1E00h string block,
 * waits for a key or a mouse button, and on a key that is present in the
 * cs:1E1Fh table (while DGROUP 53D8h is set) defers an action by writing
 * 0FFh to DGROUP 0002h.  Finally it repaints the string block with the
 * highlight flag set and draws the closing box via renamed_0800_0024. */
u16 renamed_0800_1e3f(s16 dx, u16 *dsOut)
{
	u16 wLoc02;        /* [bp-2h]  x anchor, 2Ah then +8           */
	u16 wLoc04;        /* [bp-4h]  10CE() - 2Ah                    */
	u16 wLoc06;        /* [bp-6h]  y anchor, 14h then +8           */
	u16 wLoc08;        /* [bp-8h]  16Ah                            */
	u8  bLoc0B;        /* [bp-0Bh] slot index 1..14h               */
	u16 bp_36 = 0x0000;/* 1206:0066 bpOut (pass-through caller BP) */
	u16 ds_40 = 0x0000;/* 1206:0066 dsOut (dropped selector)       */
	u16 ds_103 = 0x0000;/* 1AB8:1536 dsOut (dropped selector)      */
	u8  ch_472;        /* 1AB8:1D82 chOut                          */
	u8  ch_474;        /* 1AB8:1D82 chOut                          */
	u8 *es_473 = 0;    /* 1EDA:0CD4 esOut (flat analog)            */
	u16 dx_251 = 0x0000;/* 19E1/015B dxOut, then 030D dx in        */
	u16 bp_475 = 0x0000;/* 19E1 bpOut                              */
	u16 ds_250 = 0x0000;/* 19E1/015B dsOut (dropped selector)      */
	u8  ch_476;        /* 1206:015B chOut                          */
	u16 bp_477 = 0x0000;/* 1206:015B bpOut                         */
	u16 dx_481 = 0x0000;/* 1E78:030D dxOut                         */
	u8 *es_482 = 0;    /* 1EDA:0CD4 esOut                          */
	u16 dx_478 = 0x0000;/* 19E1 dxOut                              */
	u16 bp_479 = 0x0000;/* 19E1 bpOut                              */
	u16 ds_370 = 0x0000;/* 19E1 dsOut (dropped selector)           */
	u16 bp_382 = 0x0000;/* 1206:0066 bpOut                         */
	u16 ds_386 = 0x0000;/* 1206:0066 dsOut (dropped selector)      */
	u16 dx_480 = 0x0000;/* 1E78:029C dxOut                         */
	u16 ax;            /* 030D AX result                           */

	/* l0800_1E43: drain the key buffer.  The original calls 030D with no
	 * pushed argument; wArg02 is a stale word (seeded 0) and dx is the
	 * incoming parameter, re-threaded through dxOut. */
	while (renamed_1e78_02fb() != 0x00)
	{
		(void)renamed_1e78_030d(dx, 0x0000, (u16 *)&dx);
	}

	/* l0800_1E53: frame setup. */
	wLoc02 = 0x002A;                          /* mov [bp-2h],2Ah */
	wLoc06 = 0x0014;                          /* mov [bp-6h],14h */
	wLoc04 = (u16)(bgi_get_text_cols() - 0x002A);   /* sub ax,2Ah */
	wLoc08 = 0x016A;                          /* mov [bp-8h],16Ah */
	renamed_1206_0066(&bp_36, &ds_40);
	/* push [bp-2h] ; push [bp-6h] ; push [bp-4h] ; push [bp-8h] ;
	 * call 1315h */
	renamed_0800_1315(wLoc08, wLoc04, wLoc06, wLoc02);
	wLoc02 = (u16)(wLoc02 + 0x0008);          /* add ax,8h */
	wLoc06 = (u16)(wLoc06 + 0x0008);          /* add ax,8h */
	/* push 0h ; push 1h ; call far 1AB8h:14F4h */
	bgi_set_text_rectangle(0x01, 0x00);
	/* push 0h ; push 0h ; push 1h ; call far 1AB8h:1536h */
	(void)bgi_load_video_driver_file(0x01, 0x00, 0x00, &ds_103);

	bLoc0B = 0x01;
	for (;;)
	{
		/* push 0h ; call far 1AB8h:1C32h */
		(void)bgi_get_text_cursor_attributes(0x00);

		/* first pass at (x-1, y-1): push (wLoc02-1) ; push
		 * (bLoc0B*0Dh + wLoc06 - 1) ; push ds ; push di. */
		(void)bgi_get_char_size_info(
			&g_dgroup[(u16)(((u16)bLoc0B << 0x08) + 0x2306)],
			(u16)((u16)bLoc0B * 0x0D + wLoc06 - 0x0001),
			(u16)(wLoc02 - 0x0001),
			&ch_472);

		/* push <row> ; mov di,1DE0h ; push cs ; push di ;
		 * call far 1EDAh:0CD4h ; jz 1EF7h.
		 * 0CD4 != 0 -> tested bit CLEAR -> attribute 0Bh. */
		if (!renamed_1eda_0cd4(&g_seg0800[0x1DE0], bLoc0B, &es_473))
			(void)bgi_get_text_cursor_attributes(0x0A);          /* bit set   */
		else
			(void)bgi_get_text_cursor_attributes(0x0B);          /* bit clear */

		/* second pass at (x, y): push wLoc02 ; push
		 * (bLoc0B*0Dh + wLoc06) ; push ds ; push di. */
		(void)bgi_get_char_size_info(
			&g_dgroup[(u16)(((u16)bLoc0B << 0x08) + 0x2306)],
			(u16)((u16)bLoc0B * 0x0D + wLoc06),
			wLoc02,
			&ch_474);

		/* cmp [bp-0Bh],14h ; jnz 1EADh (inc). */
		if (bLoc0B == 0x14)
			break;
		++bLoc0B;
	}

	/* l0800_1F28: push 5h ; push 140h ; push 14Ah ; push cs:1E00h ;
	 * push 0h ; call 19E1h */
	(void)renamed_0800_19e1(0x00, &g_seg0800[0x1E00], 0x014A, 0x0140, 0x0005,
	                  &dx_251, &bp_475, &ds_250);

	/* l0800_1F3A: wait for a key or a mouse button. */
	while (renamed_1e78_02fb() == 0x00)
	{
		if ((u8)renamed_1206_015b(&ch_476, &dx_251, &bp_477, &ds_250) != 0x00)
			break;
	}

	/* l0800_1F4E: a key is pending -- test it against cs:1E1Fh. */
	if (renamed_1e78_02fb() != 0x00)
	{
		ax = renamed_1e78_030d(dx_251, 0x0000, &dx_481);
		/* call 0CD4 ; jz 1F75h: proceed only when the bit is SET
		 * (0CD4 == 0). */
		if (renamed_1eda_0cd4(&g_seg0800[0x1E1F], (u8)ax, &es_482) == 0x00 &&
		    LG8(0x53D8) != 0x00)
			LG8(0x0002) = 0xFF;
	}

	/* l0800_1F75: repaint the block with the flag word = 1, then the
	 * epilogue box. */
	(void)renamed_0800_19e1(0x01, &g_seg0800[0x1E00], 0x014A, 0x0140, 0x0005,
	                  &dx_478, &bp_479, &ds_370);
	renamed_1206_0066(&bp_382, &ds_386);
	(void)renamed_1e78_029c(0x0096, &dx_480);
	/* mov ax,[bp-2h] ; sub ax,0Ch ; push ; ... ; call 0024h */
	renamed_0800_0024((u16)(wLoc08 + 0x0004), (u16)(wLoc04 + 0x0004),
	            (u16)(wLoc06 - 0x000C), (u16)(wLoc02 - 0x000C));

	*dsOut = ds_386;
	return 0x0000;   /* original returns a frame word (dropped here) */
}

/* 0800:2004: u16 renamed_0800_2004(void)
 * The 21-row (rows 1..15h) registration screen.  Clears DGROUP 53D8h, draws
 * the frame with renamed_0800_1315 and, per row, blits the ds:3706h + (row<<8)
 * label twice through bgi_get_char_size_info, choosing attribute 0Ah/0Bh from the
 * cs:1FB5h bit table.  Then it draws the cs:1FD5h string block, waits for a
 * key or mouse button, and on a key present in the cs:1FE4h table sets
 * DGROUP 53D8h.  Finally it repaints the block with flag 1, runs the
 * epilogue and calls renamed_0800_1e3f. */
u16 renamed_0800_2004(void)
{
	u16 wLoc02;         /* [bp-2h]  9Ch then +8                   */
	u16 wLoc04;         /* [bp-4h]  1E0h                          */
	u16 wLoc06;         /* [bp-6h]  14h then +0Ch                 */
	u16 wLoc08;         /* [bp-8h]  16Ah                          */
	u8  bLoc09;         /* [bp-9h]  slot index 1..15h             */
	u16 ds_70 = 0x0000; /* 1AB8:1536 dsOut (dropped selector)     */
	u8  ch_457;         /* 1AB8:1D82 chOut                        */
	u8  ch_459;         /* 1AB8:1D82 chOut                        */
	u8 *es_458 = 0;     /* 1EDA:0CD4 esOut                        */
	u16 dx_221 = 0x0000;/* 19E1/015B dxOut                        */
	u16 bp_460 = 0x0000;/* 19E1 bpOut                             */
	u16 ds_220 = 0x0000;/* 19E1/015B dsOut (dropped selector)     */
	u8  ch_461;         /* 1206:015B chOut                        */
	u16 bp_462 = 0x0000;/* 1206:015B bpOut                        */
	u16 dx_466 = 0x0000;/* 1E78:030D dxOut                        */
	u8 *es_467 = 0;     /* 1EDA:0CD4 esOut                        */
	u16 dx_463 = 0x0000;/* 19E1 dxOut                             */
	u16 bp_464 = 0x0000;/* 19E1 bpOut                             */
	u16 ds_338 = 0x0000;/* 19E1 dsOut (dropped selector)          */
	u16 bp_465 = 0x0000;/* 1206:0066 bpOut                        */
	u16 ds_354 = 0x0000;/* 1206:0066 dsOut (dropped selector)     */
	u16 dx_366 = 0x0000;/* 1E78:029C dxOut -> 0800:1E3F dx        */
	u16 ds_381 = 0x0000;/* 0800:1E3F dsOut                        */
	u16 ax;             /* 030D AX result                          */

	/* mov byte ptr [53D8h],0h */
	LG8(0x53D8) = 0x00;

	/* mov [bp-2h],9Ch ; [bp-6h],14h ; [bp-4h],1E0h ; [bp-8h],16Ah */
	wLoc02 = 0x009C;
	wLoc06 = 0x0014;
	wLoc04 = 0x01E0;
	wLoc08 = 0x016A;
	/* push [bp-2h] ; push [bp-6h] ; push [bp-4h] ; push [bp-8h] ;
	 * call 1315h */
	renamed_0800_1315(wLoc08, wLoc04, wLoc06, wLoc02);
	wLoc02 = (u16)(wLoc02 + 0x0008);          /* add ax,8h  */
	wLoc06 = (u16)(wLoc06 + 0x000C);          /* add ax,0Ch */
	/* push 1h ; push 1h ; call far 1AB8h:14F4h */
	bgi_set_text_rectangle(0x01, 0x01);
	/* push 0h ; push 0h ; push 1h ; call far 1AB8h:1536h */
	(void)bgi_load_video_driver_file(0x01, 0x00, 0x00, &ds_70);

	bLoc09 = 0x01;
	for (;;)
	{
		u16 di = (u16)((u16)bLoc09 << 0x08);   /* shl di,8h */

		/* push 0h ; call far 1AB8h:1C32h */
		(void)bgi_get_text_cursor_attributes(0x00);

		/* first pass at (x-1, y-1): x is the column centre
		 * ((wLoc04-wLoc02)/2 + wLoc02). */
		(void)bgi_get_char_size_info(
			&g_dgroup[(u16)(di + 0x3706)],
			(u16)((u16)bLoc09 * 0x0D + wLoc06 - 0x0001),
			(u16)(((u16)(wLoc04 - wLoc02) >> 0x01) + wLoc02 - 0x0001),
			&ch_457);

		/* push <row> ; mov di,1FB5h ; push cs ; push di ;
		 * call far 1EDAh:0CD4h ; jz 20AEh.
		 * 0CD4 != 0 -> tested bit CLEAR -> attribute 0Bh. */
		if (!renamed_1eda_0cd4(&g_seg0800[0x1FB5], bLoc09, &es_458))
			(void)bgi_get_text_cursor_attributes(0x0A);          /* bit set   */
		else
			(void)bgi_get_text_cursor_attributes(0x0B);          /* bit clear */

		/* second pass at (x, y). */
		(void)bgi_get_char_size_info(
			&g_dgroup[(u16)(di + 0x3706)],
			(u16)((u16)bLoc09 * 0x0D + wLoc06),
			(u16)(((u16)(wLoc04 - wLoc02) >> 0x01) + wLoc02),
			&ch_459);

		/* cmp [bp-9h],15h ; jz 20EBh (exit) else inc. */
		if (bLoc09 == 0x15)
			break;
		++bLoc09;
	}

	/* l0800_20EB: push 5h ; push 140h ; push 14Ah ; push cs:1FD5h ;
	 * push 0h ; call 19E1h. */
	(void)renamed_0800_19e1(0x00, &g_seg0800[0x1FD5], 0x014A, 0x0140, 0x0005,
	                  &dx_221, &bp_460, &ds_220);

	/* l0800_20FD: wait for a key or a mouse button. */
	while (renamed_1e78_02fb() == 0x00)
	{
		if ((u8)renamed_1206_015b(&ch_461, &dx_221, &bp_462, &ds_220) != 0x00)
			break;
	}

	/* l0800_2111: a key is pending -- test it against cs:1FE4h. */
	if (renamed_1e78_02fb() != 0x00)
	{
		ax = renamed_1e78_030d((s16)dx_221, 0x0000, &dx_466);
		/* call 0CD4 ; jz 2131h: set 53D8h only when the bit is SET
		 * (0CD4 == 0). */
		if (renamed_1eda_0cd4(&g_seg0800[0x1FE4], (u8)ax, &es_467) == 0x00)
			LG8(0x53D8) = 0x01;
	}

	/* l0800_2131: repaint the block with the flag word = 1, epilogue,
	 * then renamed_0800_1e3f. */
	(void)renamed_0800_19e1(0x01, &g_seg0800[0x1FD5], 0x014A, 0x0140, 0x0005,
	                  &dx_463, &bp_464, &ds_338);
	renamed_1206_0066(&bp_465, &ds_354);
	(void)renamed_1e78_029c(0x0096, &dx_366);
	(void)renamed_0800_1e3f((s16)dx_366, &ds_381);

	return ds_381;   /* original returns the dropped DGROUP selector (0) */
}
