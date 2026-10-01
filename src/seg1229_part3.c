/* seg1229_part3.c -- RAD V3.1 preservation port, segment 1229, part 3.
 *
 * Functions 1229:0CCE .. 1229:0DCC (2 functions, ascending offset):
 *   0CCE 0DCC
 * Literal recovery from analysis/slices/1229/1229_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg1229.h
 * (analysis/summary/iface.tsv).  See CONVENTIONS.md, analysis/SEGMAP.md and
 * docs/notes-1229.md ("## part 3").
 *
 * Hardware / DOS: neither function contains an int 10h/16h/21h, a raw port
 * I/O instruction, __cli/__sti or int 23h, so no pal.h entry point is
 * referenced.  Every BIOS/hardware service reached from here goes through
 * segment 133F (mode/menu drawing, mouse enable), 1AB8 (video primitives),
 * 1E78 (beep / mouse-scan), 13C8 (mouse INT 33h) or segment 1EDA (DOS file /
 * string helpers), all replaced in their own ports.
 *
 * 0x5992 far-pointer table: the two bgi_signed_rectangle_intersect sites read a 32-bit far
 * pointer from DGROUP:0x5992[idx*4].  The table is populated at startup by
 * the (unported) 0800 loader from fn1EDA_023F and is all zero in the shipped
 * image; the pointer is reconstructed exactly as docs/notes-1AB8.md does for
 * the analogous DGROUP slots: far_ptr(LG32(slot)).  See notes.
 */
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1229.h"
#include "seg133F.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1E78.h"
#include "seg13C8.h"

/* 1229:0DCC shared mouse/keyboard poll (far 133F:0528).  The original stages
 * three far out-pointers ds:62D2 -> ptrArg06, ds:62D0 -> ptrArg0A,
 * ds:62CE -> ptrArg0E and the byte [50C7h] as the last stack word.  That word
 * is the callee's [bp+6h] zero-test flag (`retf 0Eh` accounts for 7 words);
 * the frozen prototype names the slot `dx` and Reko threaded the DX register
 * there instead, so the byte is passed as the first argument -- the only C
 * slot that reaches [bp+6h].  The callee reads only its low byte. */
static u16 seg1229_scan_0528(s16 * dxOut, u16 * bpOut, u16 * dsOut)
{
	return vgaerr_read_input((s16)LG8(0x50C7),
	                   (u8 *)&g_dgroup[0x62D2],
	                   (u8 *)&g_dgroup[0x62D0],
	                   (u8 *)&g_dgroup[0x62CE],
	                   dxOut, bpOut, dsOut);
}

// 1229:0CCE: void fn1229_0CCE(void)
void fn1229_0CCE(void)
{
	u16 dx_341;   /* dxOut of 133F:0137 */
	u16 bp_342;   /* bpOut of 133F:0137 */
	u16 ds_15;    /* dropped DGROUP selector */
	u16 dx_343;   /* dxOut of 1EDA:0A39 */
	u16 ds_294;   /* dropped DGROUP selector */
	u16 ax_10E1;
	u16 ax_10CE;

	/* call far 133F:0137 ; 04A7 ; 1AB8:0F80 */
	vgaerr_show_cursor(&dx_341, &bp_342, &ds_15);
	vgaerr_reset_message_counter();
	bgi_set_text_window();
	bgi_get_text_cursor_attributes(0x0F);
	/* push 0h ; push 0h ; push 27Fh ; push 177h */
	bgi_clip_text_rectangle(0x0177, 0x027F, 0x0000, 0x0000);
	(void)fn1229_0AA8();
	fn1229_0C58();

	/* five menu labels: far 133F:0352(ds far ptr, y0, y1, x0, x1, key).
	 * The pointers are length-prefixed strings in this segment. */
	(void)vgaerr_setup_text_rectangle(&g_seg1229[0x0CB4], 0x0191, 0x0057, 0x0180, 0x0005, 0x53);
	(void)vgaerr_setup_text_rectangle(&g_seg1229[0x0CB9], 0x01A9, 0x002B, 0x0198, 0x0005, 0x2D);
	(void)vgaerr_setup_text_rectangle(&g_seg1229[0x0CBD], 0x01A9, 0x0057, 0x0198, 0x0030, 0x2B);
	(void)vgaerr_setup_text_rectangle(&g_seg1229[0x0CC1], 0x01C1, 0x0057, 0x01B0, 0x0005, 0x54);
	(void)vgaerr_setup_text_rectangle(&g_seg1229[0x0CC6], 0x01D9, 0x0057, 0x01C8, 0x0005, 0x51);
	/* push 64h ; push 192h ; push 0h ; push 0h ; push cs:0CCBh */
	(void)vgaerr_init_text_area(&g_seg1229[0x0CCB]);

	/* push 0h ; push 0h ; call 1AB8:10CE ; push ax ; call 1AB8:10E1 ;
	 * push ax ; call far 133F:0200 */
	ax_10CE = bgi_get_text_cols();
	ax_10E1 = bgi_get_text_rows();
	vgaerr_set_text_window(ax_10E1, ax_10CE, 0x0000, 0x0000);
	/* push 1h ; push 1h ; call 1AB8:10CE ; push ax ; call 1AB8:10E1 ;
	 * push ax ; call far 133F:04B1 */
	ax_10CE = bgi_get_text_cols();
	ax_10E1 = bgi_get_text_rows();
	(void)vgaerr_configure_text_area(ax_10E1, ax_10CE, 0x0001, 0x0001, &ds_294);
	/* push 16h ; push 16h */
	vgaerr_set_cursor_step(0x0016, 0x0016);
	/* push cs:0CCCh (src) ; push ds:62DEh (dst) ; push 0FFh */
	(void)fn1EDA_0A39(0xFF, &g_dgroup[0x62DE], &g_seg1229[0x0CCC], &dx_343);
}

// 1229:0DCC: u16 fn1229_0DCC(u8 * ptrArg04, u16 * bpOut, u16 * dsOut)
u16 fn1229_0DCC(u8 * ptrArg04, u16 * bpOut, u16 * dsOut)
{
	u8  buf_100[0x100];   /* [bp-0100h] string staging (lea di,[bp+0FF00h]) */
	u8  bLocFEFF;         /* [bp-0FEFFh] (= [bp-0101h]) drag/refresh flag */
	s16 dx_1022;          /* DX register threaded through 133F:0141/0528 */
	u16 bp_186;           /* BP register output (frame-chain artifact) */
	u16 ds_1002;          /* dropped DGROUP selector */
	u16 dx_1359;
	u16 dx_1360;
	u16 dx_1361;
	u16 dx_1364;          /* dxOut of 133F:0137 (draw cell)   */
	u16 bp_269;
	u16 ds_273;
	u16 dx_1365;          /* dxOut of 133F:0137 (erase cell)  */
	u16 bp_387;
	u16 ds_391;
	u16 ax_178;           /* 0528 return */
	u16 ax_487;           /* [62CEh] key code */
	u16 ax_570;           /* 0528 return (0x53 drain loop) */
	u16 ax_702;           /* 0528 return (0x51 drain loop) */
	u16 ax_863;           /* 0528 return ('-' drain loop) */
	u16 ax_1024;          /* 0528 return ('+' drain loop) */
	s16 ax_247;           /* selected-slot index of the zoom branch */
	s16 qx;
	s16 qy;
	u16 dx_1366;          /* dxOut of 133F:0137 ('+' branch) */
	u16 bp_891;
	u16 ds_895;
	s16 dx_1368;
	u16 ds_u16;           /* 061B dsOut dummy */
	s16 dx_1369;
	u16 bp_dummy;         /* 0735 bpOut dummy */
	u16 ds_dummy;         /* 0735 dsOut dummy */
	u16 dx_1371;          /* dxOut of 133F:0137 ('-' branch) */
	u16 bp_730;
	u16 ds_734;
	s16 dx_1373;
	s16 dx_1374;
	u16 dx_1379;          /* dxOut of 133F:0137 (0x53 branch) */
	u16 bp_1380;
	u16 ds_509;
	u16 dx_1065;          /* dxOut of 133F:0137 at the epilogue */
	u16 bp_1060;
	u16 ds_1064;
	u16 ax_1362;          /* axOut of 1EDA:0B24 */
	u16 dx_1363;          /* dxOut of the first tail 1EDA:0A39 */

	/* les di,[bp+6h] ; push es:di (src) ; push ss:buf (dst) ; push 0FFh */
	fn1EDA_0A39(0xFF, buf_100, ptrArg04, &dx_1359);
	bgi_set_text_window();
	/* push 0Fh ; push 3Fh ; push 3Fh ; push 3Fh */
	bgi_get_pixel(0x3F, 0x3F, 0x3F, 0x0F);
	/* push ss:buf (src) ; push ds:6BBAh (dst) ; push 0FFh */
	fn1EDA_0A39(0xFF, &g_dgroup[0x6BBA], buf_100, &dx_1360);

	LG8(0x62DB) = 0x00;
	LG8(0x62CB) = 0x01;
	LG8(0x6CBA) = 0x00;
	/* push 1h ; call far 13C8:0111 ; call 039Dh ; call 0CCEh */
	(void)config_mouse_speed_threshold(0x01);
	fn1229_039D();
	fn1229_0CCE();
	vgaerr_hide_cursor(&dx_1022, &bp_186, &ds_1002);
	bLocFEFF = 0x00;

l1229_0E2E:
	ax_178 = seg1229_scan_0528(&dx_1022, &bp_186, &ds_1002);
	if ((u8)ax_178 == 0x00)
		goto l1229_10EF;              /* l1229_0E4A: jmp 10EFh */

	/* l1229_0E4D: cursor is over a filled cell -> highlight it */
	if (LG16(0x62CE) == 0x0001 &&
	    (s16)LG16(0x62D0) > 0x0059 &&
	    (s16)LG16(0x62D2) > 0x0187)
	{
		fn1E78_02C7(0x00F0);
		(void)fn1E78_029C(0x0064, &dx_1361);
		/* (Y-187h)/16h*19h + (X-59h)/16h */
		ax_247 = (s16)(((s16)(LG16(0x62D2) - 0x0187) / 0x16) * 0x19 +
		               ((s16)(LG16(0x62D0) - 0x0059) / 0x16));
		LG8(0x62CB) = (u8)((u16)LG8(0x6CBA) + (u16)ax_247);
		(void)fn1E78_02F4();
		dx_1022 = ax_247;
	}

	/* l1229_0EA2: cursor over cell type 1 -> paint the cell */
	if (LG16(0x62CE) == 0x0001 && (s16)LG16(0x62D2) < 0x0177)
	{
		vgaerr_show_cursor(&dx_1364, &bp_269, &ds_273);
		qx = (s16)(LG16(0x62D0) - 0x0001) / 0x16;   /* (X-1)/16h */
		qy = (s16)(LG16(0x62D2) - 0x0001) / 0x16;   /* (Y-1)/16h */
		LG8((u16)(0x5CE0 + (u16)(qy * 0x1D + qx))) = LG8(0x62CB);
		/* les di,[di+5992h] with di = selected-slot * 4 */
		bgi_signed_rectangle_intersect(0x00,
		            far_ptr(LG32((u16)(0x5992 + ((u16)LG8(0x62CB) << 2)))),
		            (u16)(qy * 0x16 + 0x0001),
		            (u16)(qx * 0x16 + 0x0001));
		bLocFEFF = 0x01;
		vgaerr_hide_cursor(&dx_1022, &bp_186, &ds_1002);
	}

	/* l1229_0F19: cursor over cell type 2 -> clear the cell */
	if (LG16(0x62CE) == 0x0002 && (s16)LG16(0x62D2) < 0x0177)
	{
		vgaerr_show_cursor(&dx_1365, &bp_387, &ds_391);
		qx = (s16)(LG16(0x62D0) - 0x0001) / 0x16;
		qy = (s16)(LG16(0x62D2) - 0x0001) / 0x16;
		LG8((u16)(0x5CE0 + (u16)(qy * 0x1D + qx))) = 0x00;
		/* les di,[5992h] (table entry 0) */
		bgi_signed_rectangle_intersect(0x00,
		            far_ptr(LG32(0x5992)),
		            (u16)(qy * 0x16 + 0x0001),
		            (u16)(qx * 0x16 + 0x0001));
		bLocFEFF = 0x01;
		vgaerr_hide_cursor(&dx_1022, &bp_186, &ds_1002);
	}

	/* l1229_0F82 */
	ax_487 = LG16(0x62CE);
	if (ax_487 == 0x002B)
	{
		/* '+' page-forward, only while [5990h:598Eh] < 0xFA (signed high
		 * word checked first: jl body, jg skip, else unsigned low < 0FAh) */
		if ((s16)LG16(0x5990) < 0 ||
		    ((s16)LG16(0x5990) == 0 && (u16)LG16(0x598E) < 0x00FA))
		{
			vgaerr_show_cursor(&dx_1366, &bp_891, &ds_895);
			if (bLocFEFF != 0x00 &&
			    (u8)fn1229_061B(&dx_1368, &ds_u16) != 0x00)
				(void)fn1229_0735(&dx_1369, &bp_dummy, &ds_dummy);
			LG32(0x598E) = (u32)(LG32(0x598E) + 0x00000001u);
			(void)fn1229_0486();
			bLocFEFF = 0x00;
			(void)fn1229_0AA8();
			vgaerr_hide_cursor(&dx_1022, &bp_186, &ds_1002);
			/* drain the keyboard/mouse queue */
			do
			{
				ax_1024 = seg1229_scan_0528(&dx_1022, &bp_186, &ds_1002);
			} while ((u8)ax_1024 != 0x00);
		}
	}
	else if (ax_487 == 0x002D)
	{
		/* '-' page-back, only while [5990h:598Eh] > 1 */
		if ((s16)LG16(0x5990) > 0 ||
		    ((s16)LG16(0x5990) == 0 && (u16)LG16(0x598E) > 0x0001))
		{
			vgaerr_show_cursor(&dx_1371, &bp_730, &ds_734);
			if (bLocFEFF != 0x00 &&
			    (u8)fn1229_061B(&dx_1373, &ds_u16) != 0x00)
				(void)fn1229_0735(&dx_1374, &bp_dummy, &ds_dummy);
			LG32(0x598E) = (u32)(LG32(0x598E) - 0x00000001u);
			(void)fn1229_0486();
			bLocFEFF = 0x00;
			(void)fn1229_0AA8();
			vgaerr_hide_cursor(&dx_1022, &bp_186, &ds_1002);
			do
			{
				ax_863 = seg1229_scan_0528(&dx_1022, &bp_186, &ds_1002);
			} while ((u8)ax_863 != 0x00);
		}
	}
	else if (ax_487 == 0x0051)
	{
		/* 'Q' quit: flag the exit, then wait for the queue to drain */
		LG8(0x62DB) = 0x01;
		LG8(0x5CB3) = 0x01;
		if (bLocFEFF != 0x00 &&
		    (u8)fn1229_061B(&dx_1022, &ds_u16) != 0x00)
			(void)fn1229_0735(&dx_1022, &bp_dummy, &ds_dummy);
		do
		{
			ax_702 = seg1229_scan_0528(&dx_1022, &bp_186, &ds_1002);
		} while ((u8)ax_702 != 0x00);
	}
	else if (ax_487 == 0x0054)
	{
		/* 'T' test: clear the flag and leave immediately (no drain loop) */
		LG8(0x5CB3) = 0x00;
		LG8(0x62DB) = 0x01;
		if (bLocFEFF != 0x00 &&
		    (u8)fn1229_061B(&dx_1022, &ds_u16) != 0x00)
			(void)fn1229_0735(&dx_1022, &bp_dummy, &ds_dummy);
	}
	else if (ax_487 == 0x0053)
	{
		/* 'S' swap: toggle [6CBAh] between 0 and 64h, redraw, drain */
		if (LG8(0x6CBA) == 0x64)
			LG8(0x6CBA) = 0x00;
		else
			LG8(0x6CBA) = 0x64;
		vgaerr_show_cursor(&dx_1379, &bp_1380, &ds_509);
		fn1229_0C58();
		vgaerr_hide_cursor(&dx_1022, &bp_186, &ds_1002);
		do
		{
			ax_570 = seg1229_scan_0528(&dx_1022, &bp_186, &ds_1002);
		} while ((u8)ax_570 != 0x00);
	}

l1229_10EF:
	if (LG8(0x62DB) == 0x00)
		goto l1229_0E2E;

	/* l1229_10F9: teardown */
	vgaerr_reset_message_counter();
	vgaerr_show_cursor(&dx_1065, &bp_1060, &ds_1064);
	if (LG8(0x5CB3) != 0x00)
	{
		bgi_set_text_window();
		/* compare the working name ds:5CB4 with "NONAME" (cs:0DC5).  The
		 * frozen fn1EDA_0B24 returns 1 when the records are equal, so the
		 * asm `jnz 112Eh` (ZF clear, unequal) is `== 0` here. */
		if (fn1EDA_0B24(&g_seg1229[0x0DC5], &g_dgroup[0x5CB4],
		                &ax_1362, &dx_1065) == 0x00)
		{
			/* l1229_112E: restore the name buffers */
			(void)fn1EDA_0A39(0x06, &g_dgroup[0x5ED6], &g_dgroup[0x5CB4], &dx_1363);
			(void)fn1EDA_0A39(0x06, &g_dgroup[0x5ECE], &g_dgroup[0x5ED6], &dx_1065);
		}
		else
		{
			/* l1229_1120 */
			LG16(0x598E) = 0x0001;
			LG16(0x5990) = 0x0000;
		}
	}

	/* l1229_1150 */
	*bpOut = bp_1060;
	*dsOut = ds_1064;
	return dx_1065;
}
