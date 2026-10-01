/* seg0800_part12.c -- RAD V3.1 preservation port, segment 0800, part 12.
 *
 * Functions 0800:36E6 .. 0800:3C72 (5 functions, ascending offset):
 *   36E6 3850 391E 3BF2 3C72
 *
 * Literal recovery from analysis/slices/0800/0800_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg0800.h
 * (analysis/summary/iface.tsv) adopted exactly.  See CONVENTIONS.md and
 * docs/notes-0800.md ("## part 12").
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   None direct.  No int 10h / int 16h / int 21h, no `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch occur in
 *   36E6..3C72.  The mouse cursor poll/hide/show goes through segment 1206
 *   (fn1206_0094 / fn1206_0066 / fn1206_0038 / fn1206_015B, themselves INT 33h
 *   wrappers replaced in seg1206.c), keyboard/PIT through segment 1E78
 *   (fn1E78_02FB / 030D / 029C), text/drawing through segment 1AB8 (fn1AB8_*),
 *   records/streams through segment 1EDA (fn1EDA_04F5 / 0565 / 0896 / 081A /
 *   0918 / 04A9 / 04A2 / 1384 / 05BF / 0CD4 / 096F), and the system-clock
 *   wrapper fn1E5F_00A2 (INT 21h AH=2Ch -> msdos_get_system_time, already
 *   replaced in seg1E5F.c).  No PAL call is issued in this file.
 *
 * Flat-model far pointers:
 *   cs:38E0h = {7,"RAD.DOC"} (stream name), cs:38E8h = {11," S : SUITE "} and
 *   cs:38F4h = {9," F : FIN "} (button labels) resolve to
 *   &g_seg0800[0x38E0] / [0x38E8] / [0x38F4]; the cs:38FEh bit table (drawn
 *   from fn1EDA_0CD4) is &g_seg0800[0x38FE].  The 391E frame's stream block
 *   ([bp-0110h]) becomes abStream[0x100] and its line buffer ([bp-0210h])
 *   abBuf[0x100].
 *
 * DGROUP offsets read/written: 53E2h/53FEh/53F0h/540Ch (slot edge tables,
 *   3850), 53E4h/53F2h/5400h/540Eh (button box, 391E), 53D2h (pending key
 *   code) and 4D06h/4D07h (function-key code / slot table).
 */

#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0800.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1206.h"
#include "seg1E5F.h"
#include "seg1E78.h"

/* 0800:36E6: void fn0800_36E6(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)
 * Draw the four beveled sides of a button box at (wArg06,wArg08) with extent
 * (wArg04,wArg02): set the fill attribute, select the frame, lay the twelve
 * bgi_set_pixel bevels in three colour groups (0Bh between the groups), and the
 * outline box.  Called from fn0800_391E. */
void fn0800_36E6(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)
{
	u16 dx_419;
	u16 dx_420;
	u16 dx_421;
	u16 dx_422;
	u16 dx_423;
	u16 dx_424;
	u16 dx_425;
	u16 dx_426;
	u16 dx_427;
	u16 dx_428;
	u16 dx_429;
	u16 dx_430;

	/* push 1h ; push 3h ; call far 1AB8h:1175h */
	bgi_set_text_font_size(0x03, 0x01);
	/* push 0h ; push 0h ; push 1h ; call far 1AB8h:10F4h */
	bgi_set_text_background_color(0x01, 0x00, 0x00);
	/* push [bp+0Ah] ; [bp+8h] ; [bp+6h] ; [bp+4h] ; call far 1AB8h:1B3Eh */
	bgi_draw_rectangle(wArg02, wArg04, wArg06, wArg08);
	/* push 8h ; call far 1AB8h:1C32h */
	(void)bgi_get_text_cursor_attributes(0x08);

	/* push [bp+0Ah]-3 ; [bp+8h] ; [bp+6h]+3 ; [bp+8h] ; call 1AF6h */
	(void)bgi_set_pixel(wArg06, (u16)(wArg04 + 0x0003), wArg06,
	                  (u16)(wArg08 - 0x0003), &dx_419);
	/* push [bp+0Ah]-2 ; [bp+8h]+1 ; [bp+6h]+1 ; [bp+8h]+1 ; call 1AF6h */
	(void)bgi_set_pixel((u16)(wArg06 + 0x0001), (u16)(wArg04 + 0x0001),
	                  (u16)(wArg06 + 0x0001), (u16)(wArg08 - 0x0002), &dx_420);
	/* push [bp+0Ah]-1 ; [bp+8h]+2 ; [bp+6h] ; [bp+8h]+2 ; call 1AF6h */
	(void)bgi_set_pixel((u16)(wArg06 + 0x0002), wArg04,
	                  (u16)(wArg06 + 0x0002), (u16)(wArg08 - 0x0001), &dx_421);
	/* push [bp+0Ah]-3 ; [bp+8h] ; [bp+0Ah]-3 ; [bp+4h]+2 ; call 1AF6h */
	(void)bgi_set_pixel((u16)(wArg02 + 0x0002), (u16)(wArg08 - 0x0003), wArg06,
	                  (u16)(wArg08 - 0x0003), &dx_422);
	/* push [bp+0Ah]-2 ; [bp+8h]+1 ; [bp+0Ah]-2 ; [bp+4h]+1 ; call 1AF6h */
	(void)bgi_set_pixel((u16)(wArg02 + 0x0001), (u16)(wArg08 - 0x0002),
	                  (u16)(wArg06 + 0x0001), (u16)(wArg08 - 0x0002), &dx_423);
	/* push [bp+0Ah]-1 ; [bp+8h]+2 ; [bp+0Ah]-1 ; [bp+4h] ; call 1AF6h */
	(void)bgi_set_pixel(wArg02, (u16)(wArg08 - 0x0001),
	                  (u16)(wArg06 + 0x0002), (u16)(wArg08 - 0x0001), &dx_424);

	/* push 0Bh ; call far 1AB8h:1C32h */
	(void)bgi_get_text_cursor_attributes(0x0B);

	/* push [bp+6h]+3 ; [bp+8h] ; [bp+6h]+3 ; [bp+4h]+1 ; call 1AF6h */
	(void)bgi_set_pixel((u16)(wArg02 + 0x0001), (u16)(wArg04 + 0x0003), wArg06,
	                  (u16)(wArg04 + 0x0003), &dx_425);
	/* push [bp+6h]+2 ; [bp+8h]+1 ; [bp+6h]+2 ; [bp+4h] ; call 1AF6h */
	(void)bgi_set_pixel(wArg02, (u16)(wArg04 + 0x0002),
	                  (u16)(wArg06 + 0x0001), (u16)(wArg04 + 0x0002), &dx_426);
	/* push [bp+6h]+1 ; [bp+8h]+2 ; [bp+6h]+1 ; [bp+4h]-1 ; call 1AF6h */
	(void)bgi_set_pixel((u16)(wArg02 - 0x0001), (u16)(wArg04 + 0x0001),
	                  (u16)(wArg06 + 0x0002), (u16)(wArg04 + 0x0001), &dx_427);
	/* push [bp+0Ah]-2 ; [bp+6h]+2 ; [bp+4h]+2 ; [bp+0Ah]-2 ; call 1AF6h */
	(void)bgi_set_pixel((u16)(wArg02 + 0x0002), (u16)(wArg04 + 0x0002),
	                  (u16)(wArg02 + 0x0002), (u16)(wArg08 - 0x0002), &dx_428);
	/* push [bp+0Ah]-1 ; [bp+6h]+1 ; [bp+4h]+1 ; [bp+0Ah]-1 ; call 1AF6h */
	(void)bgi_set_pixel((u16)(wArg02 + 0x0001), (u16)(wArg04 + 0x0001),
	                  (u16)(wArg02 + 0x0001), (u16)(wArg08 - 0x0001), &dx_429);
	/* push [bp+0Ah] ; [bp+4h] ; [bp+6h] ; [bp+4h] ; call 1AF6h */
	(void)bgi_set_pixel(wArg02, wArg04, wArg02, wArg08, &dx_430);
}

/* 0800:3850: u8 fn0800_3850(u8 * chOut, u16 * bpOut, u16 * dsOut)
 * Hit-test the mouse cursor (fn1206_0094) against the third button's slot
 * edges; when the cursor falls strictly inside slot 1 or 2 return the key code
 * stored in the cs:4D07h slot table (DGROUP 4D07h + index), else 0.  The poll
 * loop repeats while a button is held.  Called from fn0800_391E. */
u8 fn0800_3850(u8 *chOut, u16 *bpOut, u16 *dsOut)
{
	u16 wLoc04 = 0x0000;  /* [bp-4h] 1206:0094 dsOut (BX, button state) */
	u16 wLoc06 = 0x0000;  /* [bp-6h] 1206:0094 bpOut (CX, cursor x)     */
	u16 wLoc08 = 0x0000;  /* [bp-8h] 1206:0094 dxOut (DX, cursor y)     */
	u8  bLoc09;           /* [bp-9h] slot index 1..2                    */
	u8  bLoc01;           /* [bp-1h] result / slot-table byte           */

	/* l0800_3854: poll the cursor/buttons until none is pressed.  The three
	 * out words are seeded 0 because a missing mouse driver leaves them
	 * unwritten. */
	do
	{
		(void)fn1206_0094(&wLoc08, &wLoc06, &wLoc04);
	} while (wLoc04 != 0x0000);

	/* l0800_386E */
	bLoc01 = 0x00;
	bLoc09 = 0x01;
	for (;;)
	{
		u16 di = (u16)((u16)bLoc09 << 0x01);   /* shl di,1h */

		/* l0800_387B: left = 53E2h + 2*index, right = 53FEh + 2*index
		 * (x), top = 53F0h + 2*index, bottom = 540Ch + 2*index (y); the
		 * signed jge/jle edge tests. */
		if ((s16)LG16((u16)(0x53E2 + di)) >= (s16)wLoc06)
			goto l0800_38D3;
		if ((s16)LG16((u16)(0x53FE + di)) <= (s16)wLoc06)
			goto l0800_38D3;
		if ((s16)LG16((u16)(0x53F0 + di)) >= (s16)wLoc08)
			goto l0800_38D3;
		if ((s16)LG16((u16)(0x540C + di)) <= (s16)wLoc08)
			goto l0800_38D3;

		/* l0800_38C3: slot hit -> bFFFF = [4D07h + index]. */
		bLoc01 = LG8((u16)(0x4D07 + (u16)bLoc09));
		break;

	l0800_38D3:
		/* cmp byte ptr [bp-9h],2h ; jnz 3878h (inc) else fall to 38D9h. */
		if (bLoc09 == 0x02)
			break;
		++bLoc09;
	}

	/* l0800_38D9: register-output threading.  CH at ret is a register
	 * artifact; BP is the caller's pushed BP frame word (no flat meaning);
	 * DS is the dropped DGROUP selector. */
	*chOut = 0x00;
	*bpOut = 0x0000;
	*dsOut = 0x0000;
	return bLoc01;
}

/* 0800:391E: u16 fn0800_391E(void)
 * The "SUITE" (module list) browser: open RAD.DOC, drain the key buffer, paint
 * the frame, list slot rows 1..14h (one stream line each), and run the modal
 * key/mouse loop that selects a module, ends with 53h ('S') or exits with 46h
 * ('F').  Called from fn0800_3D9D. */
u16 fn0800_391E(void)
{
	u8  abStream[0x100];  /* [bp-0110h] RAD.DOC stream block (04F5 et al.) */
	u8 *abBuf = g_dgroup + 0xFA00;   /* [bp-0210h] line buffer (0896 dest, 1D82 src); [bp-0210h] is SS-resident, and SS==DS in the tiny model, so stage at DGROUP 0xFA00 for the ES:BX materialization */
	u16 wLoc02;           /* [bp-2h]  x anchor, 2Ah                        */
	u16 wLoc04;           /* [bp-4h]  bgi_get_text_cols() - 2Ah                  */
	u16 wLoc06;           /* [bp-6h]  y anchor, 14h                        */
	u16 wLoc08;           /* [bp-8h]  16Ah                                 */
	u16 wLoc0A;           /* [bp-0Ah] wLoc02 + 30h                         */
	u16 wLoc0C;           /* [bp-0Ch] wLoc06 + 0Ch                         */
	u8  bLoc0F;           /* [bp-0Fh] row counter 1..14h                   */
	u8  ch_412;           /* 1AB8:1D82 chOut (inner row loop)              */
	u8  ch_987;           /* 1EDA:04A9 chOut                               */
	u8  ch_989;           /* 1EDA:04A9 chOut                               */
	u8  ch_991;           /* 1206:0038 chOut                               */
	u8  ch_993;           /* 1206:015B chOut                               */
	u8  ch_996;           /* 1EDA:04A9 chOut                               */
	u8  ch_997;           /* 0800:3850 chOut                               */
	u8  ch_1000;          /* 1EDA:04A9 chOut                               */
	u8  ch_1005;          /* 1EDA:04A9 chOut                               */
	u16 ds_89;            /* 1206:0066 dsOut (dropped selector)            */
	u16 ds_207;           /* 0800:19E1 dsOut (dropped selector)            */
	u16 ds_236;           /* 0800:19E1 / 1EDA:04A9 dsOut (dropped)         */
	u16 ds_254;           /* 1206:0066 dsOut (dropped selector)            */
	u16 ds_334;           /* 1AB8:1536 / 1EDA:04A9 dsOut (dropped)         */
	u16 ds_448;           /* 1EDA:04A9 dsOut (dropped selector)            */
	u16 ds_479 = 0x0000;  /* 1206:0038 / 0800:19E1 dsOut (dropped)         */
	u16 ds_608;           /* 1206:015B dsOut (dropped selector)            */
	u16 ds_819;           /* 0800:19E1 dsOut (dropped selector)            */
	u16 ds_847;           /* 1EDA:04A9 / 1206:0066 dsOut (dropped)         */
	void *bp_85;          /* 1206:0066 bpOut (frame ptr)                   */
	void *bp_250;         /* 1206:0066 bpOut (outer loop)                  */
	u16 bp_604 = 0x0000;  /* 1206:015B / 0800:3850 bpOut                   */
	u16 bp_815;           /* 0800:19E1 bpOut                               */
	u16 bp_983;           /* 0800:19E1 bpOut                               */
	u16 bp_985;           /* 0800:19E1 bpOut                               */
	u16 bp_990;           /* 0800:19E1 bpOut                               */
	u16 bp_992;           /* 1206:0038 bpOut                               */
	u16 bp_855;           /* 1206:0066 bpOut (epilogue)                    */
	u16 dx_42;            /* 1EDA:0565 return, then 1E78:030D dx           */
	u16 dx_480 = 0x0000;  /* 1206:0038 / 0800:19E1 dxOut                    */
	u16 dx_550 = 0x0000;  /* 1E78:030D dxOut                               */
	u16 dx_982;           /* 0800:19E1 dxOut                               */
	u16 dx_984;           /* 0800:19E1 dxOut                               */
	u16 dx_990;           /* 0800:19E1 dxOut                               */
	u16 dx_994;           /* 1206:015B dxOut                               */
	u16 dx_1001;          /* 0800:19E1 dxOut                               */
	u16 dx_1002;          /* 0800:19E1 dxOut                               */
	u16 dx_1006;          /* 1E78:029C dxOut                               */
	u8 *es_998 = 0;       /* 1EDA:0CD4 esOut (flat analog)                 */

	/* push cs:38E0h ; push ss:bp-0110h ; call far 1EDAh:04F5h */
	fn1EDA_04F5(&g_seg0800[0x38E0], abStream);
	/* push ss:bp-0110h ; call far 1EDAh:0565h (reopen RAD.DOC) */
	dx_42 = fn1EDA_0565(abStream);
	/* call far 1EDAh:04A2h ; or ax,ax ; jz 3949h */
	if (fn1EDA_04A2() != 0x00)
		goto l0800_3BF0;

	/* l0800_3949: drain the key buffer.  The original calls 030D with no
	 * pushed argument, so wArg02 is a stale word seeded 0. */
	while (fn1E78_02FB() != 0x00)
		(void)fn1E78_030D((s16)dx_42, 0x0000, &dx_42);

	/* l0800_3959: frame setup. */
	wLoc02 = 0x002A;                          /* mov [bp-2h],2Ah */
	wLoc06 = 0x0014;                          /* mov [bp-6h],14h */
	wLoc04 = (u16)(bgi_get_text_cols() - 0x002A);   /* sub ax,2Ah      */
	wLoc08 = 0x016A;                          /* mov [bp-8h],16Ah */
	fn1206_0066(&bp_85, &ds_89);
	/* push [bp-2h] ; [bp-6h] ; [bp-4h] ; [bp-8h] ; call 1315h */
	fn0800_1315(wLoc08, wLoc04, wLoc06, wLoc02);
	/* push [bp-2h]+8 ; [bp-6h]+0Ah ; [bp-4h]-8 ; [bp-8h]-32h ; call 36E6h */
	fn0800_36E6((u16)(wLoc08 - 0x0032), (u16)(wLoc04 - 0x0008),
	            (u16)(wLoc06 + 0x000A), (u16)(wLoc02 + 0x0008));
	/* push 1h ; push 7h ; call far 1AB8h:1175h */
	bgi_set_text_font_size(0x07, 0x01);
	/* push [bp-2h]+8 ; [bp-6h]+0Dh ; [bp-4h]-9 ; [bp-8h]-34h ; call 1B3Eh */
	bgi_draw_rectangle((u16)(wLoc08 - 0x0034), (u16)(wLoc04 - 0x0009),
	            (u16)(wLoc06 + 0x000D), (u16)(wLoc02 + 0x0008));
	/* mov ax,[bp-2h] ; add ax,30h ; mov [bp-0Ah],ax ; [bp-6h]+0Ch -> [bp-0Ch] */
	wLoc0A = (u16)(wLoc02 + 0x0030);
	wLoc0C = (u16)(wLoc06 + 0x000C);
	/* push 1h ; 0F0h ; 14Eh ; cs:38E8h ; 0h ; call 19E1h */
	(void)fn0800_19E1(0x00, &g_seg0800[0x38E8], 0x014E, 0x00F0, 0x0001,
	                  &dx_982, &bp_983, &ds_207);
	/* push 2h ; 190h ; 14Eh ; cs:38F4h ; 0h ; call 19E1h */
	(void)fn0800_19E1(0x00, &g_seg0800[0x38F4], 0x014E, 0x0190, 0x0002,
	                  &dx_984, &bp_985, &ds_236);

l0800_3A06:
	/* l0800_3A06: outer loop head -- hide cursor and re-frame. */
	fn1206_0066(&bp_250, &ds_254);
	/* push 1h ; push 7h ; call far 1AB8h:1175h */
	bgi_set_text_font_size(0x07, 0x01);
	/* push [bp-2h]+8 ; [bp-6h]+0Dh ; [bp-4h]-9 ; [bp-8h]-34h ; call 1B3Eh */
	bgi_draw_rectangle((u16)(wLoc08 - 0x0034), (u16)(wLoc04 - 0x0009),
	            (u16)(wLoc06 + 0x000D), (u16)(wLoc02 + 0x0008));
	/* mov al,[4D06h] ; xor ah,ah ; push ax ; call far 1AB8h:1C32h */
	(void)bgi_get_text_cursor_attributes(LG8(0x4D06));
	/* push 0h ; push 1h ; call far 1AB8h:14F4h */
	bgi_set_text_rectangle(0x01, 0x00);
	/* push 2h ; push 0h ; push 4h ; call far 1AB8h:1536h */
	(void)bgi_load_video_driver_file(0x04, 0x00, 0x02, &ds_334);
	/* mov byte ptr [bp-0Fh],1h */
	bLoc0F = 0x01;
	goto l0800_3A5D;

l0800_3A5A:
	/* inc byte ptr [bp-0Fh] */
	++bLoc0F;

l0800_3A5D:
	/* push 0FFh ; ss:bp-0210h ; ss:bp-0110h ; call 0896h ;
	 * call 081Ah (reuses the block far pointer 0896 left on the stack);
	 * call 04A9h. */
	{
		u16 cx_081A = fn1EDA_0896(0xFF, abBuf, abStream);
		(void)fn1EDA_081A(cx_081A, abStream);
	}
	(void)fn1EDA_04A9(0x0000, 0x0000, &ch_987, &ds_334);
	/* push [bp-0Ah] ; (index*0Dh + [bp-0Ch]) ; ss:bp-0210h ; call 1D82h */
	(void)bgi_get_char_size_info(abBuf,
	                  (u16)((u16)bLoc0F * 0x000D + wLoc0C), wLoc0A, &ch_412);
	/* cmp byte ptr [bp-0Fh],14h ; jnz 3A5Ah */
	if (bLoc0F != 0x14)
		goto l0800_3A5A;

	/* l0800_3A9B: one line read -- decide whether a module was picked. */
	{
		u16 v1 = fn1EDA_0918(ch_412, abStream);
		(void)fn1EDA_04A9(0x0000, 0x0000, &ch_989, &ds_448);
		if ((u8)v1 != 0x00)
		{
			/* l0800_3AAF: draw/redraw the selection box. */
			fn0800_005A((u16)(LG16(0x540E) + 0x0003),
			            (u16)(LG16(0x5400) + 0x0004),
			            (u16)(LG16(0x53F2) - 0x0001),
			            (u16)(LG16(0x53E4) - 0x0004));
			(void)fn1206_0038(&ch_991, &dx_480, &bp_992, &ds_479);
		}
		else
		{
			/* l0800_3AD3: no selection -- repaint the right button. */
			(void)fn0800_19E1(0x00, &g_seg0800[0x38E8], 0x014E, 0x00F0,
			                  0x0001, &dx_990, &bp_990, &ds_479);
		}
	}

l0800_3AE5:
	/* l0800_3AE5: pending key/selection handling. */
	LG8(0x53D2) = 0xFF;
	if (fn1E78_02FB() != 0x00)
	{
		LG8(0x53D2) = (u8)fn1E78_030D((s16)dx_480, 0x0000, &dx_550);
		if (LG8(0x53D2) == 0x00)
			LG8(0x53D2) = (u8)fn1E78_030D((s16)dx_550, 0x0000, &dx_550);
		while (fn1E78_02FB() != 0x00)
			(void)fn1E78_030D((s16)dx_550, 0x0000, &dx_550);
		LG8(0x53D2) = fn1EDA_1384(LG8(0x53D2));
	}
	/* push 0h ; call far 1206h:015Bh */
	if ((u8)fn1206_015B(&ch_993, &dx_994, &bp_604, &ds_608) != 0x00)
	{
		/* push bp ; call 3850h */
		LG8(0x53D2) = fn0800_3850(&ch_997, &bp_604, &ds_608);
	}
	/* call 0918h ; call 04A9h ; or al,al ; jz 3B58h */
	{
		u16 v2 = fn1EDA_0918(0x00, abStream);
		(void)fn1EDA_04A9(0x0000, 0x0000, &ch_996, &ds_479);
		/* l0800_3B4C: cmp [53D2h],53h ; jnz 3B58h */
		if ((u8)v2 != 0x00 && LG8(0x53D2) == 0x53)
			LG8(0x53D2) = 0x00;
	}
	/* push [53D2h] ; cs:38FEh ; call 0CD4h ; jnz 3B6Bh (0CD4 != 0 ->
	 * tested bit CLEAR -> fall to 3B68h = jmp 3AE5h). */
	if (fn1EDA_0CD4(&g_seg0800[0x38FE], LG8(0x53D2), &es_998) != 0x00)
		goto l0800_3AE5;

	/* l0800_3B6B: selection changed to 53h -> repaint the left button. */
	if (LG8(0x53D2) == 0x53)
		(void)fn0800_19E1(0x01, &g_seg0800[0x38E8], 0x014E, 0x00F0,
		                  0x0001, &dx_1001, &bp_604, &ds_479);

	/* l0800_3B84: call 0918h ; call 04A9h ; or al,al ; jnz 3BA2h ;
	 * cmp [53D2h],46h ; jz 3BA2h ; jmp 3A06h. */
	{
		u16 v3 = fn1EDA_0918(0x00, abStream);
		(void)fn1EDA_04A9(0x0000, 0x0000, &ch_1000, &ds_236);
		if ((u8)v3 == 0x00 && LG8(0x53D2) != 0x46)
			goto l0800_3A06;
	}

	/* l0800_3BA2: leave the modal loop -- repaint the right button, close
	 * the stream and restore the screen. */
	/* push 2h ; 190h ; 14Eh ; cs:38F4h ; 1h ; call 19E1h */
	(void)fn0800_19E1(0x01, &g_seg0800[0x38F4], 0x014E, 0x0190, 0x0002,
	                  &dx_1002, &bp_815, &ds_819);
	/* push ss:bp-0110h ; call far 1EDAh:05BFh */
	(void)fn1EDA_05BF(abStream);
	/* call far 1EDAh:04A9h */
	(void)fn1EDA_04A9(0x0000, 0x0000, &ch_1005, &ds_847);
	/* call far 1206h:0066h */
	fn1206_0066(&bp_855, &ds_847);
	/* push 96h ; call far 1E78h:029Ch */
	(void)fn1E78_029C(0x0096, &dx_1006);
	/* push [bp-2h]-14h ; [bp-6h]-0Ch ; [bp-4h]+4 ; [bp-8h]+4 ; call 0024h */
	fn0800_0024((u16)(wLoc08 + 0x0004), (u16)(wLoc04 + 0x0004),
	            (u16)(wLoc06 - 0x000C), (u16)(wLoc02 - 0x0014));

l0800_3BF0:
	/* Reko returns the dropped DGROUP selector (0). */
	return 0x0000;
}

/* 0800:3BF2: void fn0800_3BF2(void * ptrArg04)
 * Fill the time interval at ptrArg04+8 (32-bit, DS:SI field) from the clock
 * fields at ptrArg04+0/+2/+4/+6 (hours/minutes/seconds/hundredths, read by
 * fn1E5F_00A2) using fn1EDA_096F with the multiplier 07E40h, minutes * 1770h,
 * seconds * 64h and hundredths.  Called from fn0800_3CFA. */
void fn0800_3BF2(void *ptrArg04)
{
	u8  *base = (u8 *)ptrArg04;
	u16  w0;   /* hours      */
	u16  w2;   /* minutes    */
	u16  w4;   /* seconds    */
	u16  w6;   /* hundredths */
	u16  cx;
	u16  bx;
	u32  acc;

	/* push es:di (base) ; +2 ; +4 ; +6 ; call far 1E5Fh:00A2h: fills the
	 * four clock words, then the fields are read back. */
	fn1E5F_00A2((u16 *)(base + 0x06), (u16 *)(base + 0x04),
	            (u16 *)(base + 0x02), base);
	w0 = *(u16 *)base;
	w2 = *(u16 *)(base + 0x02);
	w4 = *(u16 *)(base + 0x04);
	w6 = *(u16 *)(base + 0x06);

	/* mov ax,[di] ; xor dx,dx ; mov cx,7E40h ; mov bx,5h ; call 096Fh */
	acc = fn1EDA_096F(w0, 0x7E40, 0x0000, 0x0005);
	cx = (u16)acc;
	bx = (u16)(acc >> 16);

	/* imul ax,[di+2h],1770h ; xor dx,dx ; add ax,cx ; adc dx,bx */
	acc = (u32)(u16)(w2 * 0x1770) + (((u32)bx << 16) | (u32)cx);
	cx = (u16)acc;
	bx = (u16)(acc >> 16);

	/* imul ax,[di+4h],64h ; xor dx,dx ; add ax,cx ; adc dx,bx */
	acc = (u32)(u16)(w4 * 0x0064) + (((u32)bx << 16) | (u32)cx);
	cx = (u16)acc;
	bx = (u16)(acc >> 16);

	/* mov ax,[di+6h] ; xor dx,dx ; add ax,cx ; adc dx,bx */
	acc = (u32)w6 + (((u32)bx << 16) | (u32)cx);

	/* mov es:[di+8h],ax ; mov es:[di+0Ah],dx */
	*(u16 *)(base + 0x08) = (u16)acc;
	*(u16 *)(base + 0x0A) = (u16)(acc >> 16);
}

/* 0800:3C72: u16 fn0800_3C72(void * ptrArg04, s16 * dxOut)
 * Read the current time through fn1E5F_00A2 (hours/minutes/seconds/hundredths
 * in [bp-6h..bp-0Ch]), convert it to the same unit as fn0800_3BF2, store it at
 * ptrArg04+0Ch, and return the 32-bit difference against ptrArg04+8 (low word
 * in AX, high word in *dxOut).  Called from fn0800_3CFA. */
u16 fn0800_3C72(void *ptrArg04, s16 *dxOut)
{
	u8  *base = (u8 *)ptrArg04;
	u16  wLoc0C;   /* [bp-0Ch] hundredths (DL) */
	u16  wLoc0A;   /* [bp-0Ah] seconds    (DH) */
	u16  wLoc08;   /* [bp-8h]  minutes    (CL) */
	u16  wLoc06;   /* [bp-6h]  hours      (CH) */
	u16  wLoc04;   /* [bp-4h]  result low      */
	u16  wLoc02;   /* [bp-2h]  result high     */
	u16  cx;
	u16  bx;
	u32  acc;
	u32  total;
	u32  diff;

	/* push ss:bp-6h ; bp-8h ; bp-0Ah ; bp-0Ch ; call far 1E5Fh:00A2h */
	fn1E5F_00A2(&wLoc0C, &wLoc0A, &wLoc08, &wLoc06);

	/* mov ax,[bp-6h] ; xor dx,dx ; mov cx,7E40h ; mov bx,5h ; call 096Fh */
	acc = fn1EDA_096F(wLoc06, 0x7E40, 0x0000, 0x0005);
	cx = (u16)acc;
	bx = (u16)(acc >> 16);

	/* imul ax,[bp-8h],1770h ; xor dx,dx ; add ax,cx ; adc dx,bx */
	acc = (u32)(u16)(wLoc08 * 0x1770) + (((u32)bx << 16) | (u32)cx);
	cx = (u16)acc;
	bx = (u16)(acc >> 16);

	/* imul ax,[bp-0Ah],64h ; xor dx,dx ; add ax,cx ; adc dx,bx */
	acc = (u32)(u16)(wLoc0A * 0x0064) + (((u32)bx << 16) | (u32)cx);
	cx = (u16)acc;
	bx = (u16)(acc >> 16);

	/* mov ax,[bp-0Ch] ; xor dx,dx ; add ax,cx ; adc dx,bx */
	acc = (u32)wLoc0C + (((u32)bx << 16) | (u32)cx);

	/* mov es:[di+0Ch],ax ; mov es:[di+0Eh],dx */
	*(u16 *)(base + 0x0C) = (u16)acc;
	*(u16 *)(base + 0x0E) = (u16)(acc >> 16);

	/* mov ax,es:[di+0Ch] ; mov dx,es:[di+0Eh] ; sub ax,es:[di+8h] ;
	 * sbb dx,es:[di+0Ah] */
	total = ((u32)*(u16 *)(base + 0x0E) << 16) | (u32)*(u16 *)(base + 0x0C);
	diff = total - (((u32)*(u16 *)(base + 0x0A) << 16) |
	                (u32)*(u16 *)(base + 0x08));
	wLoc04 = (u16)diff;
	wLoc02 = (u16)(diff >> 16);

	*dxOut = (s16)wLoc02;
	return wLoc04;
}
