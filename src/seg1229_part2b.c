/* seg1229_part2b.c -- RAD V3.1 preservation port, segment 1229, part 2b.
 *
 * Functions 1229:09F9 .. 1229:0C58 (3 functions, ascending offset):
 *   09F9 0AA8 0C58
 * Literal recovery from analysis/slices/1229/1229_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg1229.h
 * (analysis/summary/iface.tsv) adopted exactly.  See CONVENTIONS.md,
 * analysis/SEGMAP.md and docs/notes-1229.md ("## part 2b").
 *
 * Hardware / DOS services: none of these three functions issues an int 10h /
 * int 16h / int 21h, a raw port I/O instruction, __cli/__sti or int 23h, so no
 * pal.h entry point is referenced.  Every BIOS/hardware service reached from
 * here goes through segment 1AB8 (video/text primitives, driver dispatch
 * 0F93/1028/14F4/1536/13D7/1D82) or segment 1EDA (DOS file/string helpers),
 * replaced in their own ports.
 *
 * Stack-frame / calling-convention recovery:
 *   The 1EDA string helpers (0A1F/0AAC/0A39) use the CPU stack as a persistent
 *   scratch area.  A call pushes a destination far pointer *first* and a source
 *   far pointer *last*; the callee pops only its own last-pushed argument
 *   (`retf 4h`/`retf 0Ah`), leaving the earlier-staged far pointer on the stack
 *   for the *next* string call.  09F9's callers (`0AA8`) chain several 0AAC
 *   appends against the pointer 09F9 was handed, and 0AA8 itself builds its
 *   menu line by appending formatted numbers and literals into the buffer
 *   staged at [bp-0202h].  As in parts 1/3, the staged pointer is recovered as
 *   an explicit pointer argument; the bp-relative buffer offsets are kept in
 *   comments.
 *   0x5992 far-pointer table: the bgi_signed_rectangle_intersect sites load a 32-bit far pointer
 *   from DGROUP:0x5992[idx*4]; it is reconstructed exactly as parts 1/3 and
 *   docs/notes-1AB8.md do for the analogous DGROUP slots,
 *   `far_ptr(LG32(...))`.  The table is populated at startup by the
 *   (unported) 0800 loader and is all zero in the shipped image.
 */
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1229.h"
#include "seg1AB8.h"
#include "seg1EDA.h"

// 1229:09F9: void fn1229_09F9(u8 bArg02, u8 * ptrArg04)
void fn1229_09F9(u8 bArg02, u8 * ptrArg04)
{
	u8  buf200[0x100];   /* [bp-0200h] prepend staging (lea di,[bp+0FE00h]) */
	u8  buf100[0x100];   /* [bp-0100h] fn1EDA_0F26 number output */
	u16 dx_262;
	u16 dx_263;
	u16 dx_264;

	/* fn1EDA_0F26(0FFh, ss:bp-0100h, 0, 32-bit bArg02) */
	fn1EDA_0F26(0xFF, buf100, 0x00, (u32)bArg02);
	if (bArg02 < 0x0A)
	{
		/* l1229_0A1C: prepend cs:09F7 ({1,"0"}) to buf100 */
		fn1EDA_0A1F(&g_seg1229[0x09F7], buf200);
		fn1EDA_0AAC(buf100, buf200);
		fn1EDA_0A39(0xFF, buf100, buf200, &dx_262);
	}
	if (bArg02 < 100)
	{
		/* l1229_0A4B: second prepend; zero-pad to 3 digits */
		fn1EDA_0A1F(&g_seg1229[0x09F7], buf200);
		fn1EDA_0AAC(buf100, buf200);
		fn1EDA_0A39(0xFF, buf100, buf200, &dx_263);
	}
	/* l1229_0A74: copy buf100 into the caller's staged far pointer */
	fn1EDA_0A39(0xFF, ptrArg04, buf100, &dx_264);
}

// 1229:0AA8: u16 fn1229_0AA8(void)
u16 fn1229_0AA8(void)
{
	u8  buf_202[0x100];   /* [bp-0202h] accumulated menu line (staged dest) */
	u8  buf_302[0x100];   /* [bp-0302h] 09F9 scratch (lea di,[bp+0FCFEh]) */
	u8  buf_402[0x100];   /* [bp-0402h] 09F9 scratch (lea di,[bp+0FBFEh]) */
	u8  buf_502[0x100];   /* [bp-0502h] 09F9 scratch (lea di,[bp+0FAFEh]) */
	u8  buf_602[0x100];   /* [bp-0602h] 09F9 scratch (lea di,[bp+0F9FEh]) */
	u8  buf_102[0x100];   /* [bp-0102h] final rendered line (lea di,[bp+0FEFEh]) */
	u8  bLoc04_623;       /* [bp-0002h] row (0..10h) */
	u8  bLoc03_624;       /* [bp-0001h] column (0..1Ch) */
	u8  ch_725;           /* bgi_get_char_size_info chOut */
	u16 ds_227;           /* bgi_load_video_driver_file dsOut (dropped DGROUP selector) */
	u16 dx_724;           /* fn1EDA_0A39 dxOut */

	bgi_draw_text_rectangle(0x01, 0x0176, 0x027E, 0x01, 0x01);
	bgi_update_text_window_position();
	bgi_draw_text_rectangle(0x01, 0x01DF, 0x027F, 0x00, 0x00);
	bLoc04_623 = 0x00;
	while (1)
	{
		bLoc03_624 = 0x00;
		while (1)
		{
			u16 wCell;   /* DI = row*1Dh + col (cell index into 5CE0h) */

			wCell = (u16)((u16)bLoc04_623 * 0x1D + bLoc03_624);
			if (LG8((u16)(0x5CE0 + wCell)) != 0x00)
			{
				/* table entry cell*4 at 5992h; Y = col*16h+1, X = row*16h+1 */
				(void)bgi_signed_rectangle_intersect(
					0x00,
					far_ptr(LG32((u16)(0x5992 +
						((u16)LG8((u16)(0x5CE0 + wCell)) << 2)))),
					(u16)((u16)bLoc04_623 * 0x16 + 0x0001),
					(u16)((u16)bLoc03_624 * 0x16 + 0x0001));
			}
			if (bLoc03_624 == 0x1C)
				break;
			++bLoc03_624;
		}
		if (bLoc04_623 == 0x10)
			break;
		++bLoc04_623;
	}

	/* l1229_0B46: repaint the frame, then build the status line. */
	bgi_draw_text_rectangle(0x01, 0x0182, 0x027E, 0x0178, LG16(0x50C4));
	bgi_update_text_window_position();
	bgi_draw_text_rectangle(0x01, 0x01DF, 0x027F, 0x00, 0x00);
	bgi_set_text_rectangle(0x01, 0x00);
	bgi_load_video_driver_file(0x04, 0x00, 0x02, &ds_227);

	/* 09F9(formatted byte) then 0AAC appends into buf_202 (the staged dest).
	 * Literals: cs:0A8Bh={1," "}, cs:0A8Dh={5,"TIME:"}, cs:0A93h={6," PUSH:"},
	 * cs:0A9Ah={6," BLOW:"}, cs:0AA1h={6," PASS:"}; ds:5CB4 / ds:5CBB names. */
	fn1229_09F9(LG8(0x598E), buf_202);
	fn1EDA_0AAC(&g_seg1229[0x0A8B], buf_202);
	fn1EDA_0AAC(&g_dgroup[0x5CB4], buf_202);
	fn1EDA_0AAC(&g_seg1229[0x0A8B], buf_202);
	fn1EDA_0AAC(&g_seg1229[0x0A8D], buf_202);

	fn1229_09F9(LG8(0x5CDC), buf_302);
	fn1EDA_0AAC(buf_302, buf_202);
	fn1EDA_0AAC(&g_seg1229[0x0A93], buf_202);

	fn1229_09F9(LG8(0x5CDA), buf_402);
	fn1EDA_0AAC(buf_402, buf_202);
	fn1EDA_0AAC(&g_seg1229[0x0A9A], buf_202);

	fn1229_09F9(LG8(0x5CDD), buf_502);
	fn1EDA_0AAC(buf_502, buf_202);
	fn1EDA_0AAC(&g_seg1229[0x0AA1], buf_202);

	fn1229_09F9(LG8(0x5CDB), buf_602);
	fn1EDA_0AAC(buf_602, buf_202);
	fn1EDA_0AAC(&g_seg1229[0x0A8B], buf_202);
	fn1EDA_0AAC(&g_dgroup[0x5CBB], buf_202);

	fn1EDA_0A39(0xFF, buf_102, buf_202, &dx_724);
	(void)bgi_get_char_size_info(buf_102, 0x017D, (u16)(LG16(0x50C4) + 0x16), &ch_725);
	return ds_227;   /* Reko return = the dropped DGROUP selector (0) */
}

// 1229:0C58: void fn1229_0C58(void)
void fn1229_0C58(void)
{
	u8 bLoc05_81 = LG8(0x6CBA);   /* [bp-0003h] running tile index (6CBAh) */
	u8 bLoc03_82 = 0x00;          /* [bp-0001h] row (0..3) */
	u8 bLoc04_83;                 /* [bp-0002h] column (0..18h) */

	while (1)
	{
		bLoc04_83 = 0x00;
		while (1)
		{
			/* les di,[di+5992h] with di = bLoc05*4; Y = row*16h+187h,
			 * X = col*16h+59h. */
			(void)bgi_signed_rectangle_intersect(
				0x00,
				far_ptr(LG32((u16)(0x5992 + ((u16)bLoc05_81 << 2)))),
				(u16)((u16)bLoc03_82 * 0x16 + 0x0187),
				(u16)((u16)bLoc04_83 * 0x16 + 0x59));
			++bLoc05_81;
			if (bLoc04_83 == 0x18)
				break;
			++bLoc04_83;
		}
		if (bLoc03_82 == 0x03)
			break;
		++bLoc03_82;
	}
}
