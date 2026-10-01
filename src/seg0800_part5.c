/* seg0800_part5.c -- RAD V3.1 preservation port, segment 0800, part 5.
 *
 * Functions 0800:184C .. 0800:19E1 (2 functions, ascending offset):
 *   184C 19E1
 *
 * Literal recovery from analysis/slices/0800/0800_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg0800.h
 * (analysis/summary/iface.tsv).  See CONVENTIONS.md and
 * docs/notes-0800.md ("## part 5").
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   None.  No int 10h / int 16h / int 21h, no `in`/`out` port instruction,
 *   no __cli/__sti and no int 23h occur in 184C..19E1.  The mouse cursor is
 *   hidden/shown through segment 1206 (fn1206_0066 / fn1206_0038, themselves
 *   INT 33h wrappers replaced in seg1206.c), so no PAL call is issued here.
 *
 * Flat-model far pointers:
 *   cs:1830h..cs:1848h (the button-label strings drawn by bgi_get_char_size_info) become
 *   &g_seg0800[0x1830] .. &g_seg0800[0x1848]; the DGROUP far pointer staged
 *   for fn1EDA_0A39 (ds:541Eh + 1Ah*slot) becomes &g_dgroup[...].
 *
 * DGROUP offsets written/read: 53D4h (loop counter), 53DBh/53DCh/53DEh
 * (counters), 53E2h/53FEh/53F0h/540Ch (left/right/top/bottom edge tables),
 * 541Ah/5428h (x/y tables) and 541Eh (0x1A-byte slot records).
 */

#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0800.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1206.h"
#include "seg13E2.h"

// 0800:184C: u16 fn0800_184C(void * dsOut)
// Draw the "Fichier" button panel: hide the cursor, paint the frame, loop the
// eight slot cells (fn0800_09C2 per slot, repainting the cursor each time),
// then blit the two text rows (cs:1830h..1848h) and the second-frame strings,
// and finally hand control to the 1206:01AC / 1206:0038 mouse wrappers.
u16 fn0800_184C(void *dsOut)
{
	void *bp_535;        /* 1206:0066 bpOut (Reko frame ptr)    */
	u16   ds_103;        /* 1206:0066 dsOut (dropped selector)  */
	u16   bp_536;        /* 0800:09C2 bpOut                     */
	u16   ds_118;        /* 0800:09C2 dsOut                     */
	void *bp_537;        /* 1206:0066 bpOut (loop)              */
	u16   ds_161;        /* 1AB8:1536 dsOut                     */
	u8    ch_538;        /* 1AB8:1D82 chOut                     */
	u8    ch_539;
	u8    ch_540;
	u8    ch_541;
	u8    ch_542;
	u8    ch_543;
	u8    ch_544;
	u8    ch_545;
	u8    ch_546;
	u8    ch_547;
	u8    ch_548;
	u8    ch_549;
	u8    ch_550;
	u8    ch_551;
	u16   si_552;        /* 1206:01AC siOut                     */
	void *es_553;        /* 1206:01AC esOut                     */
	u16   ds_502;        /* 1206:01AC dsOut                     */
	u8    ch_554;        /* 1206:0038 chOut                     */
	u16   dx_518;        /* 1206:0038 dxOut (returned in DX)    */
	void *bp_555;        /* 1206:0038 bpOut                     */
	u16   ds_517;        /* 1206:0038 dsOut (dropped selector)  */

	/* call far 1206h:0066h -- hide the mouse cursor. */
	fn1206_0066(&bp_535, &ds_103);
	bgi_set_text_window();
	fn13E2_003B();
	/* push 8h ; call far 1AB8h:1C32h */
	bgi_get_text_cursor_attributes(0x08);
	/* push 0h ; push 0h ; push 1h ; call far 1AB8h:10F4h */
	bgi_set_text_background_color(0x01, 0x00, 0x00);
	/* push 0h ; push 0h ; push 27Fh ; push 177h ; call far 1AB8h:112Eh */
	bgi_clip_text_rectangle(0x0177, 0x027F, 0x00, 0x00);
	/* push 3h ; push 17Bh ; push 27Ch ; push 1DAh ; call 1315h */
	fn0800_1315(0x01DA, 0x027C, 0x017B, 0x0003);
	/* mov byte ptr [53DEh],0h ; [53DCh],0h ; [53DBh],0h */
	LG8(0x53DE) = 0x00;
	LG8(0x53DC) = 0x00;
	LG8(0x53DB) = 0x00;
	/* xor ax,ax ; mov [53D4h],ax */
	LG16(0x53D4) = 0x0000;

	for (;;)
	{
		/* mov al,[53D4h] ; push ax ; call 09C2h */
		fn0800_09C2(LG8(0x53D4), &bp_536, &ds_118);
		/* call far 1206h:0066h */
		fn1206_0066(&bp_537, &ds_103);
		if (LG16(0x53D4) == 0x0008)
			break;
		/* inc word ptr [53D4h] */
		LG16(0x53D4) = (u16)(LG16(0x53D4) + 0x0001);
	}

	/* push 0h ; push 0h ; push 1h ; call far 1AB8h:1536h */
	bgi_load_video_driver_file(0x01, 0x00, 0x00, &ds_161);
	/* push 1h ; push 1h ; call far 1AB8h:14F4h */
	bgi_set_text_rectangle(0x01, 0x01);
	/* push 8h ; call far 1AB8h:1C32h */
	bgi_get_text_cursor_attributes(0x08);

	/* first text row: cs:1830h,1838h,1830h,183Fh,1842h,1845h,1848h at 1CEh */
	bgi_get_char_size_info(&g_seg0800[0x1830], 0x01CE, 0x0043, &ch_538);
	bgi_get_char_size_info(&g_seg0800[0x1838], 0x01CE, 0x0093, &ch_539);
	bgi_get_char_size_info(&g_seg0800[0x1830], 0x01CE, 0x00E3, &ch_540);
	bgi_get_char_size_info(&g_seg0800[0x183F], 0x01CE, 0x012F, &ch_541);
	bgi_get_char_size_info(&g_seg0800[0x1842], 0x01CE, 0x0163, &ch_542);
	bgi_get_char_size_info(&g_seg0800[0x1845], 0x01CE, 0x0197, &ch_543);
	bgi_get_char_size_info(&g_seg0800[0x1848], 0x01CE, 0x01CB, &ch_544);
	/* push 0Bh ; call far 1AB8h:1C32h */
	bgi_get_text_cursor_attributes(0x0B);
	/* second text row at 1CFh */
	bgi_get_char_size_info(&g_seg0800[0x1830], 0x01CF, 0x0044, &ch_545);
	bgi_get_char_size_info(&g_seg0800[0x1838], 0x01CF, 0x0094, &ch_546);
	bgi_get_char_size_info(&g_seg0800[0x1830], 0x01CF, 0x00E4, &ch_547);
	bgi_get_char_size_info(&g_seg0800[0x183F], 0x01CF, 0x0130, &ch_548);
	bgi_get_char_size_info(&g_seg0800[0x1842], 0x01CF, 0x0164, &ch_549);
	bgi_get_char_size_info(&g_seg0800[0x1845], 0x01CF, 0x0198, &ch_550);
	bgi_get_char_size_info(&g_seg0800[0x1848], 0x01CF, 0x01CC, &ch_551);
	/* push 0h ; call far 1AB8h:1C32h */
	bgi_get_text_cursor_attributes(0x00);

	/* push 1h ; push 198h ; push 16h ; call 04CCh ; push ax ;
	 * push 1D1h ; push 9Ch ; push 1B4h ; call far 1206h:01ACh.
	 * The frozen 01AC prototype (siOut/esOut/dsOut only) carries no slots
	 * for the six staged words; the fn0800_04CC(16h) call is kept because
	 * its evaluation sits between the pushes (it is pure). */
	(void)fn0800_04CC(0x0016);
	fn1206_01AC(&si_552, &es_553, &ds_502);

	/* call far 1206h:0038h ; leave ; ret */
	fn1206_0038(&ch_554, &dx_518, &bp_555, &ds_517);
	/* Reko: dsOut = ds_517 ; return dx_518.  DS is dropped in the flat
	 * model, so the selector word at dsOut is 0; DX is the return. */
	*(u16 *)dsOut = ds_517;
	return dx_518;
}

// 0800:19E1: u8 fn0800_19E1(u8 flag, u8 * label, u16 y, u16 x, u16 slot, u16 * dxOut, void * bpOut, void * dsOut)
// Draw one button/slot around (x,y): copy the caller's 0FFh-prefixed label
// into [bp-0100h], compute the left/right/top/bottom edges from the label's
// measured half-width/height, blit the 19h-byte slot record and draw the four
// beveled sides with bgi_set_pixel, then the label and the 1206:0038 mouse
// wrapper.
//
// REPAIRED (see docs/notes-0800.md "## part 5"): the original reads six word
// arguments (ret 0Ch) -- [bp+04h] flag, [bp+06h]/[bp+08h] far label pointer,
// [bp+0Ah] y, [bp+0Ch] x, [bp+0Eh] slot index.  The prototype now carries them
// explicitly; Reko had reached the four non-pointer ones through the BP saved
// by 1206:0066.
u8 fn0800_19E1(u8 flag, u8 *label, u16 y, u16 x, u16 slot, u16 *dxOut, void *bpOut, void *dsOut)
{
	u8 *buf100 = g_dgroup + 0xFB00;   /* [bp-0100h] copied label; [bp-0100h] is SS-resident, and SS==DS in the tiny model, so stage at DGROUP 0xFB00 for the ES:BX materialization */
	u16 tFEFE;           /* [bp-0102h] left   edge (DGROUP 53E2h)        */
	u16 tFEFA;           /* [bp-0106h] right  edge (DGROUP 53FEh)        */
	u16 tFEFC;           /* [bp-0104h] top    edge (DGROUP 53F0h)        */
	u16 tFEF8;           /* [bp-0108h] bottom edge (DGROUP 540Ch)        */
	void *bp_39;         /* 1206:0066 bpOut (Reko frame ptr)             */
	u16   ds_43;         /* 1206:0066 dsOut                              */
	u16   ds_66;         /* 1AB8:1536 dsOut                              */
	u16   dx_819;        /* 1EDA:0A39 dxOut (label copy)                 */
	u16   dx_820;        /* 1EDA:0A39 dxOut (19h-byte slot record)       */
	u16   dx_821;        /* 1AB8:1AF6 dxOut                              */
	u16   dx_822;
	u16   dx_823;
	u16   dx_824;
	u16   dx_825;
	u16   dx_826;
	u16   dx_827;
	u16   dx_828;
	u16   dx_829;
	u16   dx_830;
	u16   dx_831;
	u16   dx_832;
	u8    ch_833;        /* 1AB8:1D82 chOut                              */
	u8    ch_834;        /* 1206:0038 chOut                              */
	u16   dx_768;        /* 1206:0038 dxOut                              */
	void *bp_763;        /* 1206:0038 bpOut                              */
	u16   ds_767;        /* 1206:0038 dsOut                              */
	u8    ret;

	/* les di,[bp+6h] ; push es:di (src) ; push ss:buf (dst) ; push 0FFh */
	fn1EDA_0A39(0xFF, buf100, label, &dx_819);
	/* call far 1206h:0066h */
	fn1206_0066(&bp_39, &ds_43);
	/* push 1h ; push 0h ; push 3h ; call far 1AB8h:1536h */
	bgi_load_video_driver_file(0x03, 0x00, 0x01, &ds_66);
	/* push 1h ; push 3h ; call far 1AB8h:1175h */
	bgi_set_text_font_size(0x03, 0x01);
	/* push 0h ; push 0h ; push 1h ; call far 1AB8h:10F4h */
	bgi_set_text_background_color(0x01, 0x00, 0x00);
	/* push 1h ; push 1h ; call far 1AB8h:14F4h */
	bgi_set_text_rectangle(0x01, 0x01);

	/* left = x - width/2 - 5 (53E2h + 2*index) */
	LG16((u16)(0x53E2 + ((u16)slot << 1))) =
		(u16)(x - (bgi_advance_text_pointer(buf100) >> 0x0001) - 0x0005);
	/* right = x + width/2 + 5 (53FEh + 2*index) */
	LG16((u16)(0x53FE + ((u16)slot << 1))) =
		(u16)(x + (bgi_advance_text_pointer(buf100) >> 0x0001) + 0x0005);
	/* top = y - height/2 (53F0h + 2*index) */
	LG16((u16)(0x53F0 + ((u16)slot << 1))) =
		(u16)(y - (bgi_display_error_string(buf100) >> 0x0001));
	/* bottom = y + height/2 + 5 (540Ch + 2*index) */
	LG16((u16)(0x540C + ((u16)slot << 1))) =
		(u16)(y + (bgi_display_error_string(buf100) >> 0x0001) + 0x0005);
	/* mov [di+541Ah],ax (x) ; mov [di+5428h],ax (y) */
	LG16((u16)(0x541A + ((u16)slot << 1))) = x;
	LG16((u16)(0x5428 + ((u16)slot << 1))) = y;
	/* imul di,[bp+0Eh],1Ah ; add di,541Eh ; push ds:di (dst) ;
	 * push ss:buf (src) ; push 19h ; call far 1EDAh:0A39h */
	fn1EDA_0A39(0x19, &g_dgroup[(u16)(0x541E + 0x001A * slot)],
	            buf100, &dx_820);

	/* reload the four edges from the DGROUP tables */
	tFEFE = LG16((u16)(0x53E2 + ((u16)slot << 1)));
	tFEFA = LG16((u16)(0x53FE + ((u16)slot << 1)));
	tFEFC = LG16((u16)(0x53F0 + ((u16)slot << 1)));
	tFEF8 = LG16((u16)(0x540C + ((u16)slot << 1)));

	/* push FEFEh ; FEFCh ; FEFA h ; FEF8h ; call far 1AB8h:1B3Eh */
	bgi_draw_rectangle(tFEF8, tFEFA, tFEFC, tFEFE);
	bgi_get_text_cursor_attributes(0x0B);
	if (flag != 0x00)
		bgi_get_text_cursor_attributes(0x00);

	/* first pair of 1AF6h bevels */
	bgi_set_pixel(tFEFC, (u16)(tFEFA + 0x0003), tFEFC,
	            (u16)(tFEFE - 0x0003), &dx_821);
	bgi_set_pixel((u16)(tFEFC + 0x0001), (u16)(tFEFA + 0x0001),
	            (u16)(tFEFC + 0x0001), (u16)(tFEFE - 0x0002), &dx_822);
	bgi_get_text_cursor_attributes(0x0B);
	bgi_set_pixel((u16)(tFEFC + 0x0002), tFEFA,
	            (u16)(tFEFC + 0x0002), (u16)(tFEFE - 0x0001), &dx_823);
	if (flag != 0x00)
		bgi_get_text_cursor_attributes(0x00);

	/* second pair (left/bottom bevels) */
	bgi_set_pixel((u16)(tFEF8 + 0x0002), (u16)(tFEFE - 0x0003), tFEFC,
	            (u16)(tFEFE - 0x0003), &dx_824);
	bgi_set_pixel((u16)(tFEF8 + 0x0001), (u16)(tFEFE - 0x0002),
	            (u16)(tFEFC + 0x0001), (u16)(tFEFE - 0x0002), &dx_825);
	bgi_get_text_cursor_attributes(0x0B);
	bgi_set_pixel(tFEF8, (u16)(tFEFE - 0x0001),
	            (u16)(tFEFC + 0x0002), (u16)(tFEFE - 0x0001), &dx_826);
	bgi_get_text_cursor_attributes(0x08);
	if (flag != 0x00)
		bgi_get_text_cursor_attributes(0x00);

	/* third pair (right/bottom bevels) */
	bgi_set_pixel((u16)(tFEF8 + 0x0001), (u16)(tFEFA + 0x0003), tFEFC,
	            (u16)(tFEFA + 0x0003), &dx_827);
	bgi_set_pixel(tFEF8, (u16)(tFEFA + 0x0002),
	            (u16)(tFEFC + 0x0001), (u16)(tFEFA + 0x0002), &dx_828);
	bgi_get_text_cursor_attributes(0x08);
	bgi_set_pixel((u16)(tFEF8 - 0x0001), (u16)(tFEFA + 0x0001),
	            (u16)(tFEFC + 0x0002), (u16)(tFEFA + 0x0001), &dx_829);
	if (flag != 0x00)
		bgi_get_text_cursor_attributes(0x00);

	/* bottom bevels */
	bgi_set_pixel((u16)(tFEF8 + 0x0002), (u16)(tFEFA + 0x0002),
	            (u16)(tFEF8 + 0x0002), (u16)(tFEFE - 0x0002), &dx_830);
	bgi_set_pixel((u16)(tFEF8 + 0x0001), (u16)(tFEFA + 0x0001),
	            (u16)(tFEF8 + 0x0001), (u16)(tFEFE - 0x0001), &dx_831);
	bgi_get_text_cursor_attributes(0x08);
	bgi_set_pixel(tFEF8, tFEFA, tFEF8, tFEFE, &dx_832);
	bgi_get_text_cursor_attributes(0x00);
	/* push FEFEh-4 ; FEFCh-1 ; FEFA h+4 ; FEF8h+3 ; call far 1AB8h:112Eh */
	bgi_clip_text_rectangle((u16)(tFEF8 + 0x0003), (u16)(tFEFA + 0x0004),
	            (u16)(tFEFC - 0x0001), (u16)(tFEFE - 0x0004));
	bgi_get_text_cursor_attributes(0x01);
	if (flag != 0x00)
		bgi_get_text_cursor_attributes(0x0E);

	/* push [bp+0Ch] (x) ; push [bp+0Ah] (y) ; push ss:buf ;
	 * call far 1AB8h:1D82h */
	bgi_get_char_size_info(buf100, y, x, &ch_833);

	/* call far 1206h:0038h ; leave ; ret 0Ch */
	ret = fn1206_0038(&ch_834, &dx_768, &bp_763, &ds_767);
	*dxOut = dx_768;
	/* Reko dereferences 0038's returned BP (bp_777 = *(bp_763)); it is the
	 * register-preservation chain artifact, so 0 is stored. */
	*(u16 *)bpOut = 0x0000;
	*(u16 *)dsOut = ds_767;
	return ret;
}
