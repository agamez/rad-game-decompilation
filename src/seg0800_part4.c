/* seg0800_part4.c -- RAD V3.1 preservation port, segment 0800, part 4.
 *
 * Functions 0800:11EF .. 0800:166D (4 functions, ascending offset):
 *   11EF 1315 149F 166D
 *
 * Literal recovery from analysis/slices/0800/0800_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg0800.h
 * (analysis/summary/iface.tsv) adopted exactly.  See CONVENTIONS.md and
 * docs/notes-0800.md ("## part 4").
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   None.  No int 10h / int 16h / int 21h, no raw `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch occur in
 *   11EF..166D.  Every BIOS/DOS/hardware service reached from here is owned
 *   by the callee segments and replaced there: segment 1AB8 (video/text
 *   primitives), 1EDA (DOS stream/file + bitmap helpers), 1E78 (keyboard /
 *   PIT through fn1E78_0143), 1206 (mouse cursor), 0C74 (error report),
 *   13E2 (colour install).
 *
 * The Reko `bp` frame-pointer outputs of fn1206_0066 / fn1206_0038 are
 * pass-through copies of the caller's BP; every `bp - N` use in the
 * decompilation is recovered as the local buffer at that bp offset, exactly
 * as seg1229 parts 2a/3 did for vgaerr_show_cursor.
 *
 * fn1EDA_04A9 is the register-preserving pending-error trap (see
 * seg1EDA_part2b.c).  The 1EDA helpers leave their AX result live across it,
 * so the port captures the value from the helper call itself
 * (fn1EDA_0FD0 / fn1EDA_1185) and still issues the trap.
 */

#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0800.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1206.h"
#include "seg0C74.h"
#include "seg1E78.h"
#include "seg13E2.h"

/* 0800:11EF: u16 fn0800_11EF(void)
 * Load the .RAD.DAT mission/record: draw the "Code Mission" dialog box
 * (fn0800_0D20) from the cs:11D8 label, open cs:11E7 "RAD.DAT" in the
 * [bp-0088h] stream block, then the 32-bit position counter at ds:598Eh /
 * ds:5990h is swept from 0FFFFFFFFh upward; each record read through
 * fn1EDA_1085 into the DGROUP record buffer is compared with the 6-byte head
 * saved at [bp-0008h] (fn1EDA_0B24).  The sweep stops on a match, on an
 * fn1EDA_1185 "past end" result, or when the counter reaches the record
 * count byte at ds:0002h (sign-extended).  The chosen 6-byte head is finally
 * copied back to ds:5ED6h and, if it no longer matches the buffer, the
 * position is reset to record 1...A0h. */
u16 fn0800_11EF(void)
{
	u8  buf18C[0x100];   /* [bp-018Ch] 0D20 ptrArg0E dst (0FFh bytes) */
	u8  buf88[0x80];     /* [bp-0088h] RAD.DAT stream block           */
	u8  buf8[0x06];      /* [bp-0008h] saved 6-byte record head       */
	u16 bp_12;           /* fn1206_0066 bpOut (pass-through caller BP) */
	u16 ds_16;           /* fn1206_0066 dsOut (dropped selector)       */
	u8  ch_456;          /* fn1206_0038 chOut                          */
	u16 dx_457;          /* fn1206_0038 dxOut                          */
	u16 bp_108;          /* fn1206_0038 bpOut (pass-through caller BP) */
	u16 ds_112;          /* fn1206_0038 dsOut (dropped selector)       */
	u16 dx_455;          /* fn1EDA_0A39 dxOut (save record head)       */
	u16 dx_458;          /* engine_probe_file dxOut                          */
	u16 dx_459;          /* fn1EDA_0FD0 dxOut                          */
	u8  ch_461;          /* fn1EDA_04A9 chOut (open trap)              */
	u8  al_235;          /* AL surviving fn1EDA_0FD0 -> fn1EDA_1085    */
	u16 w_10CE_m68;      /* 10CE()/2 - 068h                            */
	u16 w_10CE_p68;      /* 10CE()/2 + 068h                            */
	u16 ax_454;          /* fn1EDA_0B24 axOut (loop)                   */
	u16 dx_472;          /* fn1EDA_0B24 dxOut (loop)                   */
	u16 ax_466;          /* fn1EDA_0B24 axOut (final)                  */
	u16 dx_467;          /* fn1EDA_0B24 dxOut (final)                  */
	u16 dx_465;          /* fn1EDA_0A39 dxOut (copy head -> ds:5ED6h)  */
	u8  ch_dummy;        /* fn1EDA_04A9 chOut (reused)                 */
	u16 ds_dummy;        /* fn1EDA_04A9 dsOut (reused)                 */
	u8  b_1185;          /* fn1EDA_1185 "past end" result              */
	u16 ax_324;          /* loop counter low word (seeded 0)           */
	u16 dx_320;          /* CWD (sign extension) of ax_324             */

	/* call far 1206h:0066h -- show the mouse cursor */
	fn1206_0066(&bp_12, &ds_16);

	/* push ss ; lea di,[bp+0FE74h] ; push di ; call 1AB8h:10CEh
	 * (the ss:bp-018Ch pair 10CE ignores and leaves on the stack; it is
	 * reused as the source of the fn1EDA_0A39 copy below). */
	w_10CE_m68 = (u16)(((s16)bgi_get_text_cols() / 0x0002) - 0x0068);
	w_10CE_p68 = (u16)(((s16)bgi_get_text_cols() / 0x0002) + 0x0068);
	/* push ax ; push 8Eh ; ...
	 * push ax ; push 0A0h ; push cs ; mov di,11D8h ; push di ; call 0D20h */
	(void)fn0800_0D20(&g_seg0800[0x11D8], 0x00A0, w_10CE_p68, 0x008E,
	                  w_10CE_m68, buf18C);

	/* lea di,[bp-8h] ; push ss ; push di ; push 6 ; call 1EDA:0A39h
	 * (copies 6 bytes from the leftover ss:bp-018Ch source into [bp-8h]). */
	(void)fn1EDA_0A39(0x06, buf8, buf18C, &dx_455);

	/* call far 1206h:0038h -- hide the mouse cursor, return caller's BP */
	fn1206_0038(&ch_456, &dx_457, &bp_108, &ds_112);

	/* mov di,11E7h ; push cs ; push di ; call far 0C74h:0000h */
	if (engine_probe_file(&g_seg0800[0x11E7], &dx_458) == 0x00)
		(void)fn0800_0000();      /* l0800_1249: fatal deinit */

	/* l0800_124C: open the RAD.DAT stream block at [bp-0088h]. */
	fn1EDA_0FA2(&g_seg0800[0x11E7], buf88);
	al_235 = (u8)fn1EDA_0FD0(0x0219, buf88, &dx_459);
	(void)fn1EDA_04A9(0x0000, 0x0000, &ch_461, &ds_dummy);

	/* mov word ptr [598Eh],0FFFFh ; mov word ptr [5990h],0FFFFh */
	LG16(0x598E) = 0xFFFF;
	LG16(0x5990) = 0xFFFF;
	ax_324 = 0x0000;      /* seeded: 1051's AL is only a stale register */

	/* l0800_127B: 32-bit add/adc position sweep. */
	do
	{
		LG32(0x598E) = LG32(0x598E) + 0x00000001u;
		(void)fn1EDA_1085(al_235, buf88);
		(void)fn1EDA_04A9(0x0000, 0x0000, &ch_dummy, &ds_dummy);
		/* mov di,5CB4h ; push ds ; push di ; lea di,[bp-8h] ;
		 * push ss ; push di ; call 1EDA:0B24h */
		if (fn1EDA_0B24(buf8, &g_dgroup[0x5CB4], &ax_454, &dx_472) != 0x00)
			break;        /* l0800_12D5: record head matches */
		/* l0800_12AE: lea di,[bp+0FF78h] ; push ss ; push di ;
		 * call 1EDA:1185h */
		b_1185 = (u8)fn1EDA_1185(buf88);
		(void)fn1EDA_04A9(0x0000, 0x0000, &ch_dummy, &ds_dummy);
		if (b_1185 != 0x00)
			break;        /* l0800_12D5: past the end of the stream */

		/* l0800_12C2: mov al,[0002h] ; xor ah,ah ; dec ax ; cwd ;
		 * cmp dx,[5990h] ; jnz 127Bh ; cmp ax,[598Eh] ; jnz 127Bh */
		ax_324 = (u16)((u16)LG8(0x0002) - 0x0001);
		dx_320 = (u16)((ax_324 & 0x8000) ? 0xFFFF : 0x0000);
	} while (dx_320 != LG16(0x5990) || ax_324 != LG16(0x598E));

	/* l0800_12D5: close the stream (the original passes the stale loop AX). */
	(void)fn1EDA_1051((u8)ax_324, buf88);
	(void)fn1EDA_04A9(0x0000, 0x0000, &ch_dummy, &ds_dummy);

	/* lea di,[bp-8h] ; push ss ; push di ; mov di,5ED6h ; push ds ;
	 * push di ; push 6 ; call 1EDA:0A39h -- copy the head to ds:5ED6h. */
	(void)fn1EDA_0A39(0x06, &g_dgroup[0x5ED6], buf8, &dx_465);

	/* mov di,5CB4h ; push ds ; push di ; lea di,[bp-8h] ; push ss ;
	 * push di ; call 1EDA:0B24h ; jz 1313h */
	if (fn1EDA_0B24(buf8, &g_dgroup[0x5CB4], &ax_466, &dx_467) == 0x00)
	{
		/* l0800_1307: mov word ptr [598Eh],1h ; mov [5990h],0h */
		LG16(0x598E) = 0x0001;
		LG16(0x5990) = 0x0000;
	}

	return 0x0000;   /* original returns the dropped DGROUP selector */
}

/* 0800:1315: u8 fn0800_1315(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)
 * Title-screen frame: set the fill/border attributes and draw the rectangular
 * border of the box (x=wArg02..wArg04, y=wArg06..wArg08) with the eight
 * bgi_set_pixel line segments, in two attribute passes (0Bh then 08h).  Each
 * bgi_set_pixel call draws one edge; the argument order is Reko's. */
u8 fn0800_1315(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)
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

	/* push 1h ; push 3h ; call 1AB8h:1175h */
	bgi_set_text_font_size(0x03, 0x01);
	/* push 0h ; push 0h ; push 1h ; call 1AB8h:10F4h */
	bgi_set_text_background_color(0x01, 0x00, 0x00);
	/* push [bp+0Ah] ; push [bp+8h] ; push [bp+6h] ; push [bp+4h] ;
	 * call 1AB8h:1B3Eh */
	bgi_draw_rectangle(wArg02, wArg04, wArg06, wArg08);
	/* push 0Bh ; call 1AB8h:1C32h */
	(void)bgi_get_text_cursor_attributes(0x0B);

	/* 0800:1344: top-left corner (wArg06, wArg04+3, wArg06, wArg08-3) */
	(void)bgi_set_pixel(wArg06, (u16)(wArg04 + 0x0003), wArg06,
	                  (u16)(wArg08 - 0x0003), &dx_419);
	/* 0800:1359: (wArg06+1, wArg04+1, wArg06+1, wArg08-2) */
	(void)bgi_set_pixel((u16)(wArg06 + 0x0001), (u16)(wArg04 + 0x0001),
	                  (u16)(wArg06 + 0x0001), (u16)(wArg08 - 0x0002), &dx_420);
	/* 0800:1370: (wArg06+2, wArg04, wArg06+2, wArg08-1) */
	(void)bgi_set_pixel((u16)(wArg06 + 0x0002), wArg04,
	                  (u16)(wArg06 + 0x0002), (u16)(wArg08 - 0x0001), &dx_421);
	/* 0800:1385: (wArg02+2, wArg08-3, wArg06, wArg08-3) */
	(void)bgi_set_pixel((u16)(wArg02 + 0x0002), (u16)(wArg08 - 0x0003),
	                  wArg06, (u16)(wArg08 - 0x0003), &dx_422);
	/* 0800:139E: (wArg02+1, wArg08-2, wArg06+1, wArg08-2) */
	(void)bgi_set_pixel((u16)(wArg02 + 0x0001), (u16)(wArg08 - 0x0002),
	                  (u16)(wArg06 + 0x0001), (u16)(wArg08 - 0x0002), &dx_423);
	/* 0800:13B3: (wArg02, wArg08-1, wArg06+2, wArg08-1) */
	(void)bgi_set_pixel(wArg02, (u16)(wArg08 - 0x0001),
	                  (u16)(wArg06 + 0x0002), (u16)(wArg08 - 0x0001), &dx_424);

	/* push 8h ; call 1AB8h:1C32h */
	(void)bgi_get_text_cursor_attributes(0x08);

	/* 0800:13C8: (wArg02+1, wArg04+3, wArg06, wArg04+3) */
	(void)bgi_set_pixel((u16)(wArg02 + 0x0001), (u16)(wArg04 + 0x0003),
	                  wArg06, (u16)(wArg04 + 0x0003), &dx_425);
	/* 0800:13DA: (wArg02, wArg04+2, wArg06+1, wArg04+2) */
	(void)bgi_set_pixel(wArg02, (u16)(wArg04 + 0x0002),
	                  (u16)(wArg06 + 0x0001), (u16)(wArg04 + 0x0002), &dx_426);
	/* 0800:13EE: (wArg02-1, wArg04+1, wArg06+2, wArg04+1) */
	(void)bgi_set_pixel((u16)(wArg02 - 0x0001), (u16)(wArg04 + 0x0001),
	                  (u16)(wArg06 + 0x0002), (u16)(wArg04 + 0x0001), &dx_427);
	/* 0800:1404: (wArg02+2, wArg04+2, wArg02+2, wArg08-2) */
	(void)bgi_set_pixel((u16)(wArg02 + 0x0002), (u16)(wArg04 + 0x0002),
	                  (u16)(wArg02 + 0x0002), (u16)(wArg08 - 0x0002), &dx_428);
	/* 0800:141F: (wArg02+1, wArg04+1, wArg02+1, wArg08-1) */
	(void)bgi_set_pixel((u16)(wArg02 + 0x0001), (u16)(wArg04 + 0x0001),
	                  (u16)(wArg02 + 0x0001), (u16)(wArg08 - 0x0001), &dx_429);
	/* 0800:1436: (wArg02, wArg04, wArg02, wArg08) */
	(void)bgi_set_pixel(wArg02, wArg04, wArg02, wArg08, &dx_430);

	return 0x00;
}

/* 0800:149F: u16 fn0800_149F(void)
 * Code-listing screen (the "FLECHES/ESPACE" panel).  Draws the frame with
 * fn0800_1315, then walks the 18 x N command table (effective DGROUP base
 * 0006h, stride 100h, selected by [bp-000Bh]) and renders each entry with
 * fn1EDA_0B4F + bgi_get_char_size_info, twice per entry (normal then shifted, the
 * selected one taking attribute 0Ah via fn1EDA_0CD4 against cs:147Fh).
 * After the last row it waits on the 0x7D00-iteration counter-driven
 * fn1EDA_0D80 / bgi_get_line_attributes scroll, then restores the video state. */
u16 fn0800_149F(void)
{
	u8  buf10E[0x100];  /* [bp-010Eh] 1D82 render string (0B4F writes 2) */
	u16 wLoc02;         /* [bp-0002h] 2Ah, then 32h                  */
	u16 wLoc04;         /* [bp-0004h] 10CE() - 2Ah                   */
	u16 wLoc06;         /* [bp-0006h] 6Ah, then 72h                  */
	u16 wLoc08;         /* [bp-0008h] 10E1() - 6Ah                   */
	u16 wLoc0A_452;     /* [bp-000Ah] epilogue counter (1..7D00h)    */
	u8  bLoc0D_409;     /* [bp-000Bh] outer row index (1..12h)       */
	u8  bLoc0E_412;     /* [bp-000Ch] inner entry index (1..count)   */
	u8  al_107;         /* [bp-000Dh] per-row entry count            */
	u16 ax_20;          /* 10CE()                                    */
	u16 ax_28;          /* 10E1()                                    */
	u16 ds_90;          /* bgi_load_video_driver_file dsOut (dropped selector)      */
	u16 dx_302;         /* fn1E78_029C dxOut (outer 1F4h delay)      */
	u16 dx_504;         /* fn1E78_029C dxOut (inner 1Eh delay)       */
	u16 dx_502;         /* fn1E78_030D dxOut                         */
	u8  ch_dummy;       /* bgi_get_char_size_info chOut (reused)                */
	u16 es_501;         /* fn1EDA_0CD4 esOut (dropped selector)      */
	u16 dx_505;         /* fn1EDA_0D80 dxOut (wLoc04 path)           */
	u16 dx_506;         /* fn1EDA_0D80 dxOut (wLoc08 path)           */
	u16 rem_a;          /* fn1EDA_0D80 return, wLoc04 path           */
	u16 ax_a;           /* rem_a + wLoc02                            */
	u16 rem_b;          /* fn1EDA_0D80 return, wLoc08 path           */
	u16 ax_b;           /* rem_b + wLoc06                            */

	/* call far 1AB8h:0F80h -- clear / open the text screen */
	bgi_set_text_window();
	wLoc02 = 0x002A;
	wLoc06 = 0x006A;
	ax_20 = bgi_get_text_cols();
	wLoc04 = (u16)(ax_20 - 0x002A);      /* mov [bp-4h],ax */
	ax_28 = bgi_get_text_rows();
	wLoc08 = (u16)(ax_28 - 0x006A);      /* mov [bp-8h],ax */

	/* push [bp-2h] ; push [bp-6h] ; push [bp-4h] ; push [bp-8h] ; call 1315h */
	fn0800_1315(wLoc08, wLoc04, 0x006A, 0x002A);

	/* mov ax,[bp-2h] ; add ax,8h ; mov [bp-2h],ax (same for [bp-6h]) */
	wLoc02 = (u16)(wLoc02 + 0x0008);
	wLoc06 = (u16)(wLoc06 + 0x0008);

	/* push 0h ; push 1h ; call 1AB8h:14F4h */
	bgi_set_text_rectangle(0x01, 0x00);
	/* push 0h ; push 0h ; push 1h ; call 1AB8h:1536h */
	(void)bgi_load_video_driver_file(0x01, 0x00, 0x00, &ds_90);

	bLoc0D_409 = 0x01;
	for (;;)
	{
		/* 0800:1506: mov di,ax ; shl di,8h ; mov al,[di+0FF06h] */
		al_107 = (u8)LG8((u16)(((u16)bLoc0D_409 << 8) - 0x00FA));
		if (0x01 <= al_107)
		{
			bLoc0E_412 = 0x01;
			for (;;)
			{
				u8 bCode;

				/* push 0h ; call 1AB8h:1C32h */
				(void)bgi_get_text_cursor_attributes(0x00);

				/* first pass at (x-1, y-1) */
				bCode = (u8)LG8((u16)(((u16)bLoc0D_409 << 8) +
				                      (u16)bLoc0E_412 - 0x00FA));
				fn1EDA_0B4F(bCode, buf10E);
				(void)bgi_get_char_size_info(buf10E,
					(u16)((u16)bLoc0D_409 * 0x0D + wLoc06 - 0x0001),
					(u16)(((u16)bLoc0E_412 << 3) + wLoc02 - 0x0001),
					&ch_dummy);

				/* push <code> ; mov di,147Fh ; push cs ; push di ;
				 * call 1EDA:0CD4h ; jz 159Fh */
				if (!fn1EDA_0CD4(&g_seg0800[0x147F],
				                 (u8)LG8((u16)(((u16)bLoc0D_409 << 8) +
				                               (u16)bLoc0E_412 - 0x00FA)),
				                 &es_501))
					(void)bgi_get_text_cursor_attributes(0x0A);   /* bit set  */
				else
					(void)bgi_get_text_cursor_attributes(0x0B);   /* bit clear */

				/* second pass at (x, y) */
				bCode = (u8)LG8((u16)(((u16)bLoc0D_409 << 8) +
				                      (u16)bLoc0E_412 - 0x00FA));
				fn1EDA_0B4F(bCode, buf10E);
				(void)bgi_get_char_size_info(buf10E,
					(u16)((u16)bLoc0D_409 * 0x0D + wLoc06),
					(u16)(((u16)bLoc0E_412 << 3) + wLoc02),
					&ch_dummy);

				/* push 1Eh ; call 1E78h:029Ch */
				(void)fn1E78_029C(0x001E, &dx_504);
				if (bLoc0E_412 == al_107)
					break;
				++bLoc0E_412;
			}
		}

		/* 0800:15F8: push 1F4h ; call 1E78h:029Ch */
		(void)fn1E78_029C(0x01F4, &dx_302);
		if (bLoc0D_409 == 0x12)
			break;
		++bLoc0D_409;
	}

	/* 0800:1609: call far 1E78h:030Dh */
	(void)fn1E78_030D((s16)dx_302, 0x01F4, &dx_502);

	/* 0800:1609: mov word ptr [bp-0Ah],1h ; ... cmp ... ,7D00h ; jnz */
	wLoc0A_452 = 0x0001;
	for (;;)
	{
		/* mov ax,[bp-4h] ; sub ax,[bp-2h] ; push ax ; call 1EDA:0D80h ;
		 * add ax,[bp-2h] ; push ax
		 * mov ax,[bp-8h] ; sub ax,[bp-6h] ; push ax ; call 1EDA:0D80h ;
		 * add ax,[bp-6h] ; push ax ; push 0h ; call 1AB8h:1E54h */
		rem_a = fn1EDA_0D80((u16)(wLoc04 - wLoc02), &dx_505);
		ax_a  = (u16)(rem_a + wLoc02);
		rem_b = fn1EDA_0D80((u16)(wLoc08 - wLoc06), &dx_506);
		ax_b  = (u16)(rem_b + wLoc06);
		(void)bgi_get_line_attributes(0x00, ax_b, ax_a);
		if (wLoc0A_452 == 0x7D00)
			break;
		++wLoc0A_452;
	}

	/* 0800:1646: call far 1AB8h:0F80h ; leave */
	bgi_set_text_window();
	return 0x0000;   /* original returns the dropped DGROUP selector */
}

/* 0800:166D: u16 fn0800_166D(void)
 * The same command-listing screen as fn0800_149F, driven by the other 18-row
 * table (DGROUP base 1106h, stride 100h) and comparing against cs:164Dh.
 * First it drains any pending key (fn1E78_02FB / fn1E78_030D) and installs
 * the colour table (fn13E2_0080); the epilogue is identical. */
u16 fn0800_166D(void)
{
	u8  buf10E[0x100];  /* [bp-010Eh] 1D82 render string (0B4F writes 2) */
	u16 wLoc02;         /* [bp-0002h] 2Ah, then 32h                  */
	u16 wLoc04;         /* [bp-0004h] 10CE() - 2Ah                   */
	u16 wLoc06;         /* [bp-0006h] 6Ah, then 72h                  */
	u16 wLoc08;         /* [bp-0008h] 10E1() - 6Ah                   */
	u16 wLoc0C_489;     /* [bp-000Ah] epilogue counter (1..7D00h)    */
	u8  bLoc0D_446;     /* [bp-000Bh] outer row index (1..12h)       */
	u8  bLoc0E_449;     /* [bp-000Ch] inner entry index (1..count)   */
	u8  al_132;         /* [bp-000Dh] per-row entry count            */
	s16 dx_22;          /* fn13E2_0080 result / fn1E78_030D dx       */
	u16 ax_44;          /* 10CE()                                    */
	u16 ax_52;          /* 10E1()                                    */
	u16 ds_115;         /* bgi_load_video_driver_file dsOut (dropped selector)      */
	u16 dx_327;         /* fn1E78_029C dxOut (outer 1F4h delay)      */
	u16 dx_546;         /* fn1E78_029C dxOut (inner 1Eh delay)       */
	u16 dx_544;         /* fn1E78_030D dxOut                         */
	u8  ch_dummy;       /* bgi_get_char_size_info chOut (reused)                */
	u16 es_543;         /* fn1EDA_0CD4 esOut (dropped selector)      */
	u16 dx_547;         /* fn1EDA_0D80 dxOut (wLoc04 path)           */
	u16 dx_548;         /* fn1EDA_0D80 dxOut (wLoc08 path)           */
	u16 rem_a;          /* fn1EDA_0D80 return, wLoc04 path           */
	u16 ax_a;           /* rem_a + wLoc02                            */
	u16 rem_b;          /* fn1EDA_0D80 return, wLoc08 path           */
	u16 ax_b;           /* rem_b + wLoc06                            */

	/* call far 1AB8h:0F80h ; call far 13E2h:0080h */
	bgi_set_text_window();
	dx_22 = (s16)fn13E2_0080();

	/* l0800_167B: do { } while (fn1E78_02FB() != 0) drain the key buffer.
	 * fn1E78_030D has no stack arguments in the original (`retf`), so its
	 * wArg02 is a stale word; Reko left it undefined, seeded 0 here. */
	while (fn1E78_02FB() != 0x00)
	{
		(void)fn1E78_030D(dx_22, 0x0000, (u16 *)&dx_22);
	}

	/* l0800_168B: rect setup, identical to fn0800_149F. */
	wLoc02 = 0x002A;
	wLoc06 = 0x006A;
	ax_44 = bgi_get_text_cols();
	wLoc04 = (u16)(ax_44 - 0x002A);
	ax_52 = bgi_get_text_rows();
	wLoc08 = (u16)(ax_52 - 0x006A);
	fn0800_1315(wLoc08, wLoc04, 0x006A, 0x002A);
	wLoc02 = (u16)(wLoc02 + 0x0008);
	wLoc06 = (u16)(wLoc06 + 0x0008);
	bgi_set_text_rectangle(0x01, 0x00);
	(void)bgi_load_video_driver_file(0x01, 0x00, 0x00, &ds_115);

	bLoc0D_446 = 0x01;
	for (;;)
	{
		/* 0800:16E9: mov di,ax ; shl di,8h ; mov al,[di+1106h] */
		al_132 = (u8)LG8((u16)(((u16)bLoc0D_446 << 8) + 0x1106));
		if (0x01 <= al_132)
		{
			bLoc0E_449 = 0x01;
			for (;;)
			{
				u8 bCode;

				/* push 0h ; call 1AB8h:1C32h */
				(void)bgi_get_text_cursor_attributes(0x00);

				/* first pass at (x-1, y-1) */
				bCode = (u8)LG8((u16)(((u16)bLoc0D_446 << 8) +
				                      (u16)bLoc0E_449 + 0x1106));
				fn1EDA_0B4F(bCode, buf10E);
				(void)bgi_get_char_size_info(buf10E,
					(u16)((u16)bLoc0D_446 * 0x0D + wLoc06 - 0x0001),
					(u16)(((u16)bLoc0E_449 << 3) + wLoc02 - 0x0001),
					&ch_dummy);

				/* push <code> ; mov di,164Dh ; push cs ; push di ;
				 * call 1EDA:0CD4h ; jz 1782h */
				if (!fn1EDA_0CD4(&g_seg0800[0x164D],
				                 (u8)LG8((u16)(((u16)bLoc0D_446 << 8) +
				                               (u16)bLoc0E_449 + 0x1106)),
				                 &es_543))
					(void)bgi_get_text_cursor_attributes(0x0A);   /* bit set  */
				else
					(void)bgi_get_text_cursor_attributes(0x0B);   /* bit clear */

				/* second pass at (x, y) */
				bCode = (u8)LG8((u16)(((u16)bLoc0D_446 << 8) +
				                      (u16)bLoc0E_449 + 0x1106));
				fn1EDA_0B4F(bCode, buf10E);
				(void)bgi_get_char_size_info(buf10E,
					(u16)((u16)bLoc0D_446 * 0x0D + wLoc06),
					(u16)(((u16)bLoc0E_449 << 3) + wLoc02),
					&ch_dummy);

				/* push 1Eh ; call 1E78h:029Ch */
				(void)fn1E78_029C(0x001E, &dx_546);
				if (bLoc0E_449 == al_132)
					break;
				++bLoc0E_449;
			}
		}

		/* 0800:17DB: push 1F4h ; call 1E78h:029Ch */
		(void)fn1E78_029C(0x01F4, &dx_327);
		if (bLoc0D_446 == 0x12)
			break;
		++bLoc0D_446;
	}

	/* 0800:17EC: call far 1E78h:030Dh */
	(void)fn1E78_030D((s16)dx_327, 0x01F4, &dx_544);

	/* 0800:17EC: mov word ptr [bp-0Ah],1h ; ... cmp ... ,7D00h ; jnz */
	wLoc0C_489 = 0x0001;
	for (;;)
	{
		rem_a = fn1EDA_0D80((u16)(wLoc04 - wLoc02), &dx_547);
		ax_a  = (u16)(rem_a + wLoc02);
		rem_b = fn1EDA_0D80((u16)(wLoc08 - wLoc06), &dx_548);
		ax_b  = (u16)(rem_b + wLoc06);
		(void)bgi_get_line_attributes(0x00, ax_b, ax_a);
		if (wLoc0C_489 == 0x7D00)
			break;
		++wLoc0C_489;
	}

	/* 0800:1829: call far 1AB8h:0F80h ; leave */
	bgi_set_text_window();
	return 0x0000;   /* original returns the dropped DGROUP selector */
}
