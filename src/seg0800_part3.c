/* seg0800_part3.c -- RAD V3.1 preservation port, segment 0800, part 3.
 *
 * Functions 0800:0B42 .. 0800:0D20 (4 functions, ascending offset):
 *   0B42 0BEC 0C71 0D20
 *
 * Literal recovery from analysis/slices/0800/0800_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg0800.h
 * (analysis/summary/iface.tsv) adopted exactly.
 * See CONVENTIONS.md and docs/notes-0800.md ("## part 3").
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   None in this range.  No int 10h / int 16h / int 21h, no `in`/`out` port
 *   instruction, no __cli/__sti and no int 23h occur in 0B42..0D20.  The
 *   mouse traffic (INT 33h) goes through renamed_1206_0066 / renamed_1206_0038, which
 *   reach the register-frame trampoline dos_interrupt_trampoline and are replaced in
 *   seg1206.c; keyboard polling goes through renamed_1e78_02fb / renamed_1e78_030d
 *   (replaced in seg1E78.c).  Every other callee is a file/video/string
 *   helper already ported in segments 0C74 / 1AB8 / 1EDA.
 */

#include <stddef.h>
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0800.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1206.h"
#include "seg0C74.h"
#include "seg1E78.h"

// 0800:0B42: u16 renamed_0800_0b42(void * dsOut)
// Redraw the "TIME:" clock: format the seconds counter (DGROUP:58CCh) into a
// two-digit text record, pad single digits with a leading '0', hide the mouse
// cursor, repaint the two clock halves, then show the cursor again.
//
// Stack-frame notes (see docs/notes-0800.md "## part 3"):
//   [bp-0104h]  abLoc0104   converted-number scratch (Reko ptrLoc010A_234)
//   [bp-0004h]  bLoc06      length-prefixed 2-digit record (Reko bLoc06)
// The original relies on Turbo C's "stack-reuse" calling convention: the far
// pointer the caller pushed for engine_format_u32 (SS:bp-0104h) is left on the stack
// by 004B's `retf 4h` and is reused as the source pointer of the following
// renamed_1eda_0a39 call.  Reko recovered that as ptrLoc010A_234 and the flat calls
// pass it explicitly.
u16 renamed_0800_0b42(void *dsOut)
{
	u8  abLoc0104[0x104];   /* [bp-0104h] number scratch (Reko ptrLoc010A_234) */
	u8 *bLoc06 = g_dgroup + 0xF6F0;
	                        /* [bp-0004h] length-prefixed 2-digit record (Reko
	                         * bLoc06).  SS-resident, and SS==DS in the tiny
	                         * model, so stage at DGROUP 0xF6F0 for the ES:BX
	                         * materialization that bgi_get_char_size_info does for the
	                         * driver's 0x26 text op (a C stack buffer resolves
	                         * to segment 0 and the seconds digits drew
	                         * nothing). */
	u16 bp_122 = 0x0000;    /* register-preservation artifact out of 1206:0066 */
	u16 ds_126 = 0x0000;    /* DGROUP selector out of 1206:0066 (dropped) */
	u16 dx_256;
	u16 dx_261;
	u8  ch_257;
	u8  ch_258;
	u8  ch_259;
	u16 dx_260;
	u16 bp_212 = 0x0000;    /* BP register out of 1206:0038 (artifact) */
	u16 ds_216 = 0x0000;    /* DGROUP selector out of 1206:0038 (dropped) */

	/* 0800:0B47: format [58CCh] into the scratch record. */
	engine_format_u32(LG32(0x58CC), abLoc0104);
	/* 0800:0B5B: copy its first <=2 bytes into bLoc06. */
	renamed_1eda_0a39(0x02, bLoc06, abLoc0104, &dx_256);

	/* 0800:0B6B: cmp byte [bp-4h],2h ; jnc 0B91h */
	if (bLoc06[0] < 0x02)
	{
		/* 0800:0B6B: prefix the single digit with the "0" record at cs:0B40. */
		renamed_1eda_0a1f(&g_seg0800[0x0B40], abLoc0104);
		renamed_1eda_0aac(bLoc06, abLoc0104);
		renamed_1eda_0a39(0x02, bLoc06, abLoc0104, &dx_261);
	}

	/* 0800:0B91: hide cursor, repaint the two halves, show cursor. */
	(void)renamed_1206_0066(&bp_122, &ds_126);
	/* push 233h ; push 192h ; push 244h ; push 19Bh ; call 005Ah */
	renamed_0800_005a(0x019B, 0x0244, 0x0192, 0x0233);
	(void)bgi_get_text_cursor_attributes(0x08);
	/* push 23Bh ; push 196h ; push ss:bp-4 ; call 1AB8:1D82h */
	(void)bgi_get_char_size_info(bLoc06, 0x0196, 0x023B, &ch_257);
	(void)bgi_get_text_cursor_attributes(0x0A);
	/* push 23Ch ; push 197h ; push ss:bp-4 ; call 1AB8:1D82h */
	(void)bgi_get_char_size_info(bLoc06, 0x0197, 0x023C, &ch_258);
	(void)bgi_get_text_cursor_attributes(0x00);
	(void)renamed_1206_0038(&ch_259, &dx_260, &bp_212, &ds_216);

	/* The frozen prototype has no BP output slot: Reko models the return as
	 * the word at the 1206:0038 BP output (its caller's saved BP), which has
	 * no flat-C equivalent; both surviving callers ignore it.  Return 0 and
	 * record the loss (see notes). */
	*(u16 *)dsOut = 0x0000;     /* DGROUP selector dropped in the flat model */
	return 0x0000;
}

// 0800:0BEC: u16 renamed_0800_0bec(void)
// Reset the clock/time display state and force one redraw via renamed_0800_0b42 and
// renamed_0800_0aa1.
u16 renamed_0800_0bec(void)
{
	u16 ds_97 = 0x0000;     /* DGROUP selector out of 0B42 (dropped) */
	u16 ds_112 = 0x0000;    /* DGROUP selector out of 0AA1 (dropped) */
	u8  ch_140;
	u8  ch_141;
	u16 prod16;

	/* mov al,[53DDh] ; xor ah,ah ; xor dx,dx ; mov [58CCh],ax ; [58CEh],dx */
	LG16(0x58CC) = (u16)LG8(0x53DD);
	LG16(0x58CE) = 0x0000;
	/* xor ax,ax ; mov [58DCh],ax ; mov [58DEh],ax */
	LG16(0x58DC) = 0x0000;
	LG16(0x58DE) = 0x0000;
	/* copy the two counters into the "previous" snapshot at 58C4h/58C8h. */
	LG16(0x58C4) = LG16(0x58CC);
	LG16(0x58C6) = LG16(0x58CE);
	LG16(0x58C8) = LG16(0x58DC);
	LG16(0x58CA) = LG16(0x58DE);
	/* mov byte ptr [53E0h],0 ; mov byte ptr [53E1h],0 */
	LG8(0x53E0) = 0x00;
	LG8(0x53E1) = 0x00;
	/* mov al,[53DDh] ; xor ah,ah ; imul ax,ax,5Fh ; cwd ; mov [58D4h],ax ;
	 * mov [58D6h],dx */
	prod16 = (u16)((u16)LG8(0x53DD) * 0x5F);
	LG16(0x58D4) = prod16;
	LG16(0x58D6) = (u16)(((s16)prod16 < 0) ? 0xFFFF : 0x0000);

	(void)bgi_get_text_cursor_attributes(0x08);
	/* push 233h ; push 196h ; push cs:0BE1h ; call 1AB8:1D82h */
	(void)bgi_get_char_size_info(&g_seg0800[0x0BE1], 0x0196, 0x0233, &ch_140);
	(void)bgi_get_text_cursor_attributes(0x0A);
	/* push 234h ; push 197h ; push cs:0BE1h ; call 1AB8:1D82h */
	(void)bgi_get_char_size_info(&g_seg0800[0x0BE1], 0x0197, 0x0234, &ch_141);
	(void)renamed_0800_0b42(&ds_97);
	(void)renamed_0800_0aa1(&ds_112);

	/* original returns the DGROUP selector (dropped in the flat model). */
	return 0x0000;
}

// 0800:0C71: s16 renamed_0800_0c71(void * bpOut, u16 * dsOut)
// Clock tick handler: divide the milliseconds counter at DGROUP:58D8h by 60
// (098A gives both quotient at 58CCh and remainder at 58DCh), then repaint the
// seconds (0AA1) and minutes (0B42) whenever they changed, and run the tile
// animation (08E9) while the counter is zero or negative.
//
// The 58D8h countdown is driven on real hardware by the int-1Ch handler
// installed at cs:007Bh (see renamed_0800_00c1): each 55ms BIOS tick adds 37h to the
// millisecond accumulator at 53E2h and, on reaching 3E8h, resets it and
// decrements the 32-bit clock at 58D8h.  The port services that handler's
// state lazily from the host clock (fn0800_timer_service below); 0C71h is one
// of the two call sites (the other is the 1E78 pacing primitive, where time
// passes inside long waits).
s16 renamed_0800_0c71(void *bpOut, u16 *dsOut)
{
	s16  cx_212 = 0;
	s16  dx_24 = 0;
	s16  bx_213 = 0;
	void *ds_23 = NULL;     /* 098A DS output (void * per that prototype) */
	s16  cx_47 = 0;
	s16  dx_214 = 0;
	s16  bx_46 = 0;
	void *ds_110 = NULL;    /* 098A DS output, forwarded to 0AA1/0B42 */
	u16  ax_63;
	s16  ax_94;
	s16  dx_122;
	u16  dx_89;

	fn0800_timer_service();

	/* 0800:0C75: quotient of ([58DAh]:[58D8h]) / 3Ch -> 58CCh:58CEh. */
	LG16(0x58CC) = (u16)renamed_1eda_098a(0x003C, LG32(0x58D8),
	                                0x0000, 0x0000,
	                                &cx_212, &dx_24, &bx_213, &ds_23);
	LG16(0x58CE) = (u16)dx_24;

	/* 0800:0C8D: remainder -> 58DCh:58DEh. */
	(void)renamed_1eda_098a(0x003C, LG32(0x58D8), 0x0000, 0x0000,
	                  &cx_47, &dx_214, &bx_46, &ds_110);
	LG16(0x58DC) = (u16)cx_47;
	LG16(0x58DE) = (u16)bx_46;

	/* 0800:0CC2: seconds changed -> repaint the ":" seconds field. */
	ax_63 = LG16(0x58DC);
	if (LG16(0x58DE) != LG16(0x58CA) || ax_63 != LG16(0x58C8))
	{
		(void)renamed_0800_0aa1((u16 *)&ds_110);
		dx_89 = LG16(0x58DE);
		LG16(0x58C8) = LG16(0x58DC);
		LG16(0x58CA) = dx_89;
	}

	/* 0800:0CCC: minutes changed -> repaint the ":" minutes field. */
	ax_94 = (s16)LG16(0x58CC);
	dx_122 = (s16)LG16(0x58CE);
	if (dx_122 != (s16)LG16(0x58C6) || ax_94 != (s16)LG16(0x58C4))
	{
		(void)renamed_0800_0b42(&ds_110);
		dx_122 = (s16)LG16(0x58DE);
		LG16(0x58C4) = LG16(0x58CC);
		LG16(0x58C6) = (u16)dx_122;
	}

	/* 0800:0CF0: cmp word [58DAh],0 ; jl 0D00h ; jg 0D05h ;
	 *            cmp word [58D8h],0 ; ja 0D05h ; call 08E9h */
	if ((s16)LG16(0x58DA) < 0 ||
	    ((s16)LG16(0x58DA) == 0 && LG16(0x58D8) == 0x0000))
		dx_122 = renamed_0800_08e9(dx_122);

	/* Reko models bpOut as ss->*bp_106 (the caller's saved BP); there is no
	 * flat-C equivalent, so seed 0 (both surviving callers reload their own
	 * locals from DGROUP right after the call). */
	*(u16 *)bpOut = 0x0000;
	*dsOut = 0x0000;        /* DGROUP selector dropped in the flat model */
	return dx_122;
}

// 0800:0D20: u16 renamed_0800_0d20(u8 * ptrArg02, u16 wArg06, u16 wArg08,
//                          u16 wArg0A, u16 wArg0C, u8 * ptrArg0E)
// "Code Mission" prompt dialog.  Copy the caller's prompt string, open the
// RAD.MEM stream block, read the high-score line, allocate a screen buffer,
// initialise the code/mission display, then run the keypad entry loop: the
// player types the code, arrows/space move the cursor, and the two 5000/10000
// tick branches flash the cursor.  On exit the buffer is freed and the final
// memory line is written back to ptrArg0E.
u16 renamed_0800_0d20(u8 *ptrArg02, u16 wArg06, u16 wArg08, u16 wArg0A, u16 wArg0C,
                u8 *ptrArg0E)
{
	/* enter 518h: 0x518 bytes of locals.  Offsets are bp-relative, matching
	 * the .asm comments; buffer sizes are the 0x100-byte 0A39 record clamp. */
	/* All six work buffers are staged in DGROUP free space (0xF840..0xFD47;
	 * see the fn0800_0AA1/0B42/0C74_011E notes): the dialog feeds the prompt,
	 * answer and composition records straight into the BGI driver's 0x26 text
	 * op, which materializes them as 16:16 far pointers via far_seg_of().  A
	 * C stack buffer resolves to segment 0 there and the driver then reads
	 * pixel garbage as a glyph count/pointer (SEGV in pal_bgi_dispatch when
	 * opening the F2 "Code Mission" dialog).  The original's tiny model had
	 * SS==DS so the stack buffers were valid far pointers; the flat port is
	 * not. */
	u8 *abLoc0100 = g_dgroup + 0xF840;   /* [bp-0100h] first 0A39 destination */
	u16 ax_181;             /* [bp-0106h] heap size (return of 13A3) */
	u32 dx_ax_1868;         /* heap block, (segment << 16) | offset */
	u16 ds_200 = 0x0000;    /* DGROUP selector out of 023F (dropped) */
	u16 ds_296 = 0x0000;    /* DGROUP selector out of 1536 (dropped) */
	u8 *bLoc0206 = g_dgroup + 0xF940;    /* [bp-0206h] record buffer */
	u8  bLoc0209 = 0x00;    /* [bp-0207h] key/selection (Reko bLoc0209_1592) */
	u16 ax_422;             /* [bp-020Ah] (Reko ax_422) */
	u16 ax_317;             /* [bp-020Ch] (Reko ax_317) */
	u16 ax_769;             /* [bp-020Eh] (Reko ax_769) */
	u16 wLoc0210 = 0x0000;  /* [bp-0210h] tick counter (Reko wLoc0212_1593) */
	u8 *abStream0310 = g_dgroup + 0xFA40;/* [bp-0310h] stream block */
	u8 *bLoc0318 = g_dgroup + 0xFB40;    /* [bp-0318h] line buffer */
	u8 *abLoc0418 = g_dgroup + 0xFB48;   /* [bp-0418h] temp record */
	u8 *abLoc0518 = g_dgroup + 0xFC48;   /* [bp-0518h] temp record */
	u16 dx_1869;
	u16 dx_1873;
	u16 dx_1874;
	u16 dx_1875;
	u16 dx_684;
	u16 dx_696;
	u16 dx_1876;
	u16 dx_1877;
	u16 dx_1878;
	u16 dx_1879;
	u16 dx_1880;
	u16 ds_1417 = 0x0000;   /* DGROUP selector out of 0254 (dropped) */
	u8  ch_1871;
	u8  ch_1872;
	u16 ax_693;
	u8  al_704;
	u8  al_723;

	/* 0800:0D27: copy ptrArg02 into [bp-0100h]. */
	renamed_1eda_0a39(0xFF, abLoc0100, ptrArg02, &dx_1869);

	/* mov byte ptr [bp-0206h],0 ; mov byte ptr [bp-0318h],0 */
	bLoc0206[0] = 0x00;
	bLoc0318[0] = 0x00;

	/* 0800:0D47: build/open the RAD.MEM stream block, read its first line. */
	renamed_1eda_04f5(&g_seg0800[0x0D07], abStream0310);
	(void)renamed_1eda_0565(abStream0310);
	(void)renamed_1eda_0896(0x06, bLoc0318, abStream0310);
	renamed_1eda_086c(abStream0310);
	(void)renamed_1eda_05bf(abStream0310);
	/* 0800:0D7F: renamed_1eda_04a2 returns the latched DOS error word; if clear,
	 * keep the line just read. */
	if (renamed_1eda_04a2() == 0x00)
		renamed_1eda_0a39(0xFF, bLoc0206, bLoc0318, &dx_1873);

	/* 0800:0D9C: allocate the screen buffer and draw the dialog. */
	(void)bgi_get_text_cursor_attributes(0x0B);
	ax_181 = bgi_clamp_rectangle_coords(wArg06, wArg08, wArg0A, wArg0C);
	dx_ax_1868 = fn1EDA_023F(ax_181, 0x0000, 0x0000, &ds_200);
	bgi_draw_clip_rectangle(far_ptr(dx_ax_1868),
	            wArg06, wArg08, wArg0A, wArg0C);
	renamed_0800_0024(wArg06, wArg08, wArg0A, wArg0C);
	(void)bgi_clip_text_rectangle(wArg06, wArg08, wArg0A, wArg0C);
	(void)bgi_load_video_driver_file(0x01, 0x00, 0x00, &ds_296);
	bgi_set_text_rectangle(0x01, 0x00);

	/* 0800:0E18: ax_317 = (wArg06 - wArg0A) / 2 + wArg0A (16-bit). */
	ax_317 = (u16)(((wArg06 - wArg0A) >> 1) + wArg0A);

	/* 0800:0E28: label the code field. */
	{
		u16 arg = (u16)(bgi_advance_text_pointer(&g_seg0800[0x0D0F]) + wArg0C);
		(void)bgi_get_char_size_info(abLoc0100, ax_317, arg, &ch_1871);
	}
	renamed_1eda_0a1f(&g_seg0800[0x0D12], abLoc0418);
	renamed_1eda_0aac(abLoc0100, abLoc0418);
	{
		u16 arg = (u16)(bgi_advance_text_pointer(abLoc0418) + wArg0C);
		bgi_set_text_color(ax_317, arg);
	}

	/* 0800:0E6D: ax_422 = current cursor column; draw the caret field. */
	ax_422 = bgi_get_text_foreground();
	(void)bgi_get_text_cursor_attributes(0x0A);
	(void)bgi_get_char_size_info(bLoc0206, ax_317, ax_422, &ch_1872);
	renamed_1eda_0a1f(&g_seg0800[0x0D12], abLoc0418);
	renamed_1eda_0aac(abLoc0100, abLoc0418);
	renamed_1eda_0aac(bLoc0206, abLoc0418);
	{
		u16 arg = (u16)(bgi_advance_text_pointer(abLoc0418) + wArg0C);
		bgi_set_text_color(ax_317, arg);
	}

	/* 0800:0EC8: keypad loop. */
	bLoc0209 = 0x25;
	wLoc0210 = 0x0000;
	do
	{
		++wLoc0210;

		/* 0800:0EDF: 5000 ticks -> blink the caret (attribute 0Bh). */
		if (wLoc0210 == 0x1388)
		{
			u16 a3;
			u16 a4;
			(void)bgi_get_text_cursor_attributes(0x0B);
			a3 = bgi_get_text_foreground();
			a4 = bgi_get_text_foreground();
			(void)bgi_set_pixel((u16)(ax_317 - 0x06), a4,
			                  (u16)(ax_317 + 0x06), a3, &dx_1874);
		}

		/* 0800:0F0F: 10000 ticks -> restore and blink the other half. */
		if (wLoc0210 == 0x2710)
		{
			u16 a3;
			u16 a4;
			wLoc0210 = 0x0000;
			(void)bgi_get_text_cursor_attributes(0x00);
			a3 = bgi_get_text_foreground();
			a4 = bgi_get_text_foreground();
			(void)bgi_set_pixel((u16)(ax_317 - 0x06), a4,
			                  (u16)(ax_317 + 0x06), a3, &dx_1875);
		}

		/* 0800:0F3D: poll one keyboard event. */
		if (renamed_1e78_02fb() != 0x00)
		{
			u16 a3;
			u16 a4;
			(void)bgi_get_text_cursor_attributes(0x00);
			a3 = bgi_get_text_foreground();
			a4 = bgi_get_text_foreground();
			(void)bgi_set_pixel((u16)(ax_317 - 0x06), a4,
			                  (u16)(ax_317 + 0x06), a3, &dx_684);
			(void)bgi_get_text_cursor_attributes(0x0A);
			ax_693 = renamed_1e78_030d((s16)dx_684, 0x000A, &dx_696);
			al_704 = renamed_1eda_1384((u8)ax_693);
			bLoc0209 = al_704;
			if (al_704 == 0x00)
			{
				al_723 = (u8)renamed_1e78_030d((s16)dx_696, ax_693, &dx_1876);
				if (al_723 == 0x4B)         /* 'K' left */
					bLoc0209 = 0x08;
				else if (al_723 == 0x53)    /* 'S' down */
					bLoc0209 = 0x14;
				else
					bLoc0209 = 0x00;
			}

			/* 0800:0FB6: printable/control code 15h..0FFh */
			if (bLoc0209 >= 0x15 && bLoc0209 <= 0xFF)
			{
				u16 ax_1188;
				u16 ax_1197;
				ax_1188 = (u16)(wArg08 -
				                bgi_advance_text_pointer(&g_seg0800[0x0D0F]));
				ax_1197 = bgi_get_text_foreground();
				/* cmp dx,bx ; jl ; jg ; cmp ax,cx ; jnc : action when the
				 * cursor column is negative or exactly 0 and < the field
				 * width. */
				/* 0FB6..0FE5: cwd; cmp dx,bx (bx = 0); jl insert;
				 * jg no; cmp ax,cx; jnc no -- i.e. the 32-bit
				 * signed pen (dx:ax) < (0:limit).  A previous
				 * transcription added a spurious `== 0 &&`,
				 * which only inserted at pen == 0 and silently
				 * dropped every typed character. */
				if ((s16)ax_1197 < 0 || ax_1197 < ax_1188)
				{
					renamed_1eda_0b4f(bLoc0209, abLoc0418);
					bgi_draw_text_string(abLoc0418);
					renamed_1eda_0a1f(bLoc0206, abLoc0518);
					renamed_1eda_0b4f(bLoc0209, abLoc0418);
					renamed_1eda_0aac(abLoc0418, abLoc0518);
					renamed_1eda_0a39(0xFF, bLoc0206, abLoc0518, &dx_1880);
				}
			}
			/* 0800:1035: code 14h (down) -> move the answer field. */
			else if (bLoc0209 == 0x14)
			{
				u16 F1;
				u16 BB1;
				u16 AX1;
				u16 E1;
				u16 AX2;
				u16 F2;
				u16 BB2;
				u16 AX3;
				bLoc0206[0] = 0x00;
				F1  = bgi_display_error_string(&g_seg0800[0x0D17]);
				BB1 = bgi_get_text_background();
				AX1 = (u16)(BB1 - (F1 >> 1));
				E1  = bgi_advance_text_pointer(&g_seg0800[0x0D19]);
				AX2 = (u16)(E1 + ax_422);
				F2  = bgi_display_error_string(&g_seg0800[0x0D17]);
				BB2 = bgi_get_text_background();
				AX3 = (u16)(BB2 + (F2 >> 1));
				renamed_0800_0024(AX3, AX2, AX1, ax_422);
				bgi_set_text_color(ax_317, ax_422);
			}
			/* 0800:10A5: code 08h (left) -> move the caret field. */
			else if (bLoc0209 == 0x08)
			{
				u16 W1;
				u16 E1;
				u16 W2;
				u16 F1;
				u16 BB1;
				u16 E2;
				u16 W3;
				u16 F2;
				u16 BB2;
				u16 E3;
				u16 ax_748;
				ax_748 = bgi_get_text_foreground();
				if ((s16)ax_748 >= 0 && ax_422 < ax_748)
				{
					W1  = bgi_get_text_foreground();
					ax_769 = W1;
					E1  = bgi_advance_text_pointer(&g_seg0800[0x0D17]);
					W2  = bgi_get_text_foreground();
					F1  = bgi_display_error_string(&g_seg0800[0x0D17]);
					BB1 = bgi_get_text_background();
					E2  = bgi_advance_text_pointer(&g_seg0800[0x0D17]);
					W3  = bgi_get_text_foreground();
					F2  = bgi_display_error_string(&g_seg0800[0x0D17]);
					BB2 = bgi_get_text_background();
					renamed_0800_0024((u16)(BB2 + (F2 >> 1)),
					            (u16)(W3 + E2),
					            (u16)(BB1 - (F1 >> 1)),
					            (u16)(W2 - E1));
					E3 = bgi_advance_text_pointer(&g_seg0800[0x0D17]);
					bgi_set_text_color(ax_317, (u16)(ax_769 - E3));
					renamed_1eda_0bd0(0x01, (u16)bLoc0206[0], bLoc0206);
				}
			}
		}
	} while (bLoc0209 != 0x0D && bLoc0209 != 0x1B);

	/* 0800:1182: ESC -> restore the original line. */
	if (bLoc0209 == 0x1B)
		renamed_1eda_0a39(0xFF, bLoc0206, bLoc0318, &dx_1879);

	/* 0800:119D: free the screen buffer, then copy the last line out. */
	(void)bgi_signed_rectangle_intersect(0x00, far_ptr(dx_ax_1868), wArg0A, wArg0C);
	(void)renamed_1eda_0254(ax_181, (u16)(dx_ax_1868 & 0xFFFFu), (u16)(dx_ax_1868 >> 16), 0, &dx_1877, &ds_1417);
	renamed_1eda_0a39(0xFF, ptrArg0E, bLoc0206, &dx_1878);

	/* original returns the DGROUP selector (dropped in the flat model). */
	return 0x0000;
}
