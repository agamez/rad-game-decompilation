/* seg1229_part2a.c -- RAD V3.1 preservation port, segment 1229, part 2a.
 *
 * Function 1229:0735 (1 function).  Literal recovery from
 * analysis/slices/1229/1229_0735.asm (ground truth) and the Reko
 * decompilation; the frozen prototype from src/seg1229.h
 * (analysis/summary/iface.tsv) is adopted exactly.  See CONVENTIONS.md,
 * analysis/SEGMAP.md and docs/notes-1229.md ("## part 2a").
 *
 * 0735 is the "edit the saved-game record" dialog: it draws two name/box
 * rectangles, runs two fn1229_0040 text-entry dialogs (the second one
 * displaying a substring of the record at DGROUP:4FC4h), re-encodes the
 * five edited counters/fields with fn1229_050A, then rewrites the 0x219h
 * byte record through the 1EDA stream helpers (0FA2/0FD0/1123/108C/116A/
 * 1051).
 *
 * Hardware / DOS services: none directly.  There is no int 10h / int 16h /
 * int 21h, no raw `in`/`out`, no __cli/__sti, no int 23h and no raw IVT
 * dispatch in this function.  Every BIOS/hardware service reached from here
 * goes through segment 133F (mouse cursor show/hide 0137/0141 -> 13C8
 * INT 33h), segment 1AB8 (video/text primitives) or segment 1EDA (DOS
 * stream/file helpers plus the pending-error trap 04A9), all of which are
 * replaced in their own ports.
 *
 * Stack-frame / calling convention: as in parts 1/2b/3, the 1EDA record
 * helpers stage a destination far pointer on the CPU stack and pop only
 * their own source pointer (`retf 4h` for 0A1F/0AAC, `retf 8h` for 0A6B),
 * or pop all of their arguments (0A39 `retf 0Ah`, 0953 `retf 0Ah`).  The
 * port passes explicit pointer arguments.  The `enter 79Ch,0` frame is
 * reproduced as named buffers whose bp-relative offsets are kept in
 * comments; note that [bp-029Ah] .. [bp-082h] is one contiguous 0x219h
 * record (the size passed to fn1EDA_0FD0), carved into the fields the
 * original writes individually.
 *
 * All `dsOut` / `chOut` register outputs are dropped DGROUP selectors in
 * the flat model (stored as 0).  The Reko `bp_11` frame pointer returned by
 * fn133F_0137 is a pass-through of the caller's BP; every `bp_11 - N`
 * reference is recovered as the local buffer at that bp-relative offset,
 * exactly as part 3 did for fn1229_0DCC.
 *
 * fn1EDA_04A9 is a register-preserving pending-error trap: the original's
 * `or al,al` (and the `sub ax,2h ; sbb dx,0h`) after it consume the value
 * left in AX by the preceding helper (1123 / 1185 / 116A).  The port's
 * fn1EDA_04A9 returns 0 on the surviving path (it cannot reproduce the
 * register-preserving `retf`), so the value is captured from the helper
 * call itself and the 04A9 trap is still issued.  See notes "## part 2a".
 */
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1229.h"
#include "seg133F.h"
#include "seg1AB8.h"
#include "seg1EDA.h"

/* 1229:0735: u8 fn1229_0735(s16 * dxOut, void * bpOut, void * dsOut) */
u8 fn1229_0735(s16 * dxOut, void * bpOut, void * dsOut)
{
	u8  buf79C[0x100];   /* [bp-079Ch] 2nd fn1229_0040 output (ptrArg10) */
	u8  buf69C[0x100];   /* [bp-069Ch] 1st 0040 output / 0A6B scratch     */
	u8  buf59C[0x100];   /* [bp-059Ch] staged prompt / 0040 input          */
	u8  buf49C[0x100];   /* [bp-049Ch] 2nd edited-name record              */
	u8  buf39C[0x100];   /* [bp-039Ch] 1st edited-name record              */
	u8  buf29A[0x0006];  /* [bp-029Ah] 0A39 destination field              */
	u8  bLoc293;         /* [bp-0293h] record byte                         */
	u8  buf274[0x0006];  /* [bp-0274h..026Fh] record header bytes          */
	u8  buf26E[0x01ED];  /* [bp-026Eh..082h] 0953 destination record       */
	u8  buf80[0x0080];   /* [bp-0080h] DOS stream block                    */

	u16 dx_993;          /* dxOut of 133F:0137                    */
	u16 bp_11;           /* bpOut of 133F:0137 (Reko frame ptr)   */
	u16 ds_15;           /* dsOut of 133F:0137 (dropped selector) */
	u16 rect1_ce_m68;    /* 10CE/2 - 068h  */
	u16 rect1_e1_m10;    /* 10E1/2 - 010h  */
	u16 rect1_ce_p68;    /* 10CE/2 + 068h  */
	u16 rect1_e1_p10;    /* 10E1/2 + 010h  */
	u16 rect2_ce_m128;   /* 10CE/2 - 128h  */
	u16 rect2_e1_m10;    /* 10E1/2 - 010h  */
	u16 rect2_ce_p128;   /* 10CE/2 + 128h  */
	u16 rect2_e1_p10;    /* 10E1/2 + 010h  */
	u16 ds_dummy;        /* dropped DGROUP selector, reused as 0A39 dxOut */
	u8  ch_dummy;        /* 04A9 CH output (dropped)              */
	u8  al_758;          /* 1123 return low byte passed to 108C   */
	u8  al_825;          /* 0A39 return low byte passed to 108C   */
	u8  b_1185;          /* 1185 result tested after the 04A9 trap */
	u16 ax_920;          /* 116A record count                     */
	s16 dx_967;          /* final 133F:0141 dxOut                 */
	u16 bp_962;          /* final 133F:0141 bpOut                 */
	u16 ds_966;          /* final 133F:0141 dsOut                 */

	/* call far 133F:0137 (hide the mouse cursor); the returned BP is the
	 * caller's own frame pointer -- all its uses are the local offsets. */
	(void)fn133F_0137(&dx_993, &bp_11, &ds_15);

	/* --- first dialog box ------------------------------------------- */
	/* rect = (10CE/2-68h, 10E1/2-10h, 10CE/2+68h, 10E1/2+10h) */
	rect1_ce_m68 = (u16)(((s16)bgi_get_text_cols() / 0x0002) - 0x0068);
	rect1_e1_m10 = (u16)(((s16)bgi_get_text_rows() / 0x0002) - 0x0010);
	rect1_ce_p68 = (u16)(((s16)bgi_get_text_cols() / 0x0002) + 0x0068);
	rect1_e1_p10 = (u16)(((s16)bgi_get_text_rows() / 0x0002) + 0x0010);

	/* cs:06C3h literal, ds:5CB4h working name, cs:06C9h literal */
	fn1EDA_0A1F(&g_seg1229[0x06C3], buf59C);
	fn1EDA_0AAC(&g_dgroup[0x5CB4], buf59C);
	fn1EDA_0AAC(&g_seg1229[0x06C9], buf59C);

	fn1229_0040(buf59C, rect1_e1_p10, rect1_ce_p68, rect1_e1_m10,
	            rect1_ce_m68, buf69C, &ds_dummy);

	/* copy the length-prefixed result [bp-069Ch] into [bp-039Ch] */
	(void)fn1EDA_0A39(0xFF, buf39C, buf69C, &ds_dummy);
	if (buf39C[0] != 0x00)
	{
		/* non-empty name: store the first 6 bytes at ds:5CB4h */
		(void)fn1EDA_0A39(0x06, &g_dgroup[0x5CB4], buf39C, &ds_dummy);
	}

	/* --- second dialog box ------------------------------------------ */
	/* rect = (10CE/2-128h, 10E1/2-10h, 10CE/2+128h, 10E1/2+10h) */
	rect2_ce_m128 = (u16)(((s16)bgi_get_text_cols() / 0x0002) - 0x0128);
	rect2_e1_m10 = (u16)(((s16)bgi_get_text_rows() / 0x0002) - 0x0010);
	rect2_ce_p128 = (u16)(((s16)bgi_get_text_cols() / 0x0002) + 0x0128);
	rect2_e1_p10 = (u16)(((s16)bgi_get_text_rows() / 0x0002) + 0x0010);

	/* cs:06CDh literal, ds:5CBBh working name, cs:06D3h literal */
	fn1EDA_0A1F(&g_seg1229[0x06CD], buf59C);
	fn1EDA_0AAC(&g_dgroup[0x5CBB], buf59C);
	fn1EDA_0AAC(&g_seg1229[0x06D3], buf59C);

	/* substring of the record at ds:4FC4h: skip wArg06=1 byte, copy
	 * wArg04 = 1Eh - [5CBBh] bytes into [bp-069Ch]. */
	fn1EDA_0A6B((u16)(0x1E - (u16)LG8(0x5CBB)), 0x0001,
	            &g_dgroup[0x4FC4], buf69C);
	fn1EDA_0AAC(buf69C, buf59C);
	fn1EDA_0AAC(&g_seg1229[0x06D5], buf59C);

	fn1229_0040(buf59C, rect2_e1_p10, rect2_ce_p128, rect2_e1_m10,
	            rect2_ce_m128, buf79C, &ds_dummy);

	/* copy the length-prefixed result [bp-079Ch] into [bp-049Ch] */
	(void)fn1EDA_0A39(0xFF, buf49C, buf79C, &ds_dummy);
	if (buf49C[0] != 0x00)
	{
		/* non-empty name: store the first 0x1Eh bytes at ds:5CBBh */
		(void)fn1EDA_0A39(0x1E, &g_dgroup[0x5CBB], buf49C, &ds_dummy);
	}

	/* --- l1229_088E: re-encode the five counters -------------------- */
	LG8(0x5CDA) = (u8)fn1229_050A(LG8(0x5CDA), &g_seg1229[0x06D8], &ds_dummy);
	LG8(0x5CDB) = (u8)fn1229_050A(LG8(0x5CDB), &g_seg1229[0x06E5], &ds_dummy);
	LG8(0x5CDD) = (u8)fn1229_050A(LG8(0x5CDD), &g_seg1229[0x06F2], &ds_dummy);
	LG8(0x5CDE) = (u8)fn1229_050A(LG8(0x5CDE), &g_seg1229[0x06FF], &ds_dummy);
	LG8(0x5CDF) = (u8)fn1229_050A(LG8(0x5CDF), &g_seg1229[0x070C], &ds_dummy);

	if (LG8(0x5CDC) > 0x0A)
		LG8(0x5CDC) = 0x0A;
	LG8(0x5CDC) = (u8)fn1229_050A(LG8(0x5CDC), &g_seg1229[0x0719], &ds_dummy);
	if (LG8(0x5CDC) > 0x0A)
		LG8(0x5CDC) = 0x0A;

	/* --- l1229_0900: rewrite the RAD.DAT record --------------------- */
	bgi_get_text_cursor_attributes(0x0F);

	/* initialise the 0x219h record/stream block at [bp-0080h] */
	fn1EDA_0FA2(&g_seg1229[0x0726], buf80);
	(void)fn1EDA_0FD0(0x0219, buf80, &ds_dummy);
	(void)fn1EDA_04A9(0x0000, 0x0000, &ch_dummy, &ds_dummy);

	/* seek to record [5990h]:[598Eh] and write the current data */
	al_758 = fn1EDA_1123(LG16(0x598E), LG16(0x5990), buf80);
	(void)fn1EDA_04A9(0x0000, 0x0000, &ch_dummy, &ds_dummy);
	fn1EDA_108C(al_758, buf80);
	(void)fn1EDA_04A9(0x0000, 0x0000, &ch_dummy, &ds_dummy);

	/* position >= size: append a fresh record instead */
	b_1185 = (u8)fn1EDA_1185(buf80);
	(void)fn1EDA_04A9(0x0000, 0x0000, &ch_dummy, &ds_dummy);

	/* --- l1229_0969 ------------------------------------------------- */
	if (b_1185 != 0x00)
	{
		al_825 = fn1EDA_0A39(0x06, buf29A, &g_seg1229[0x072E], &ds_dummy);

		buf274[0x00] = 0x63;
		buf274[0x01] = 0x63;
		buf274[0x02] = 0x0A;
		buf274[0x03] = 0x63;
		buf274[0x04] = 0x00;
		buf274[0x05] = 0x00;

		/* copy 0x1EDh bytes of the default record ds:4DD6h */
		fn1EDA_0953(0x01ED, buf26E, &g_dgroup[0x4DD6]);
		bLoc293 = 0x00;

		/* buf274 and bLoc293 are part of the contiguous 0x219h record at
		 * [bp-029Ah].  The frozen fn1EDA_108C/1091 prototypes dropped the
		 * record's data-buffer argument (the flat port reads
		 * g_1EDA_io_buffer instead), so these two fields have no visible
		 * reader here; keep the writes and mark them read. */
		(void)buf274;
		(void)bLoc293;

		fn1EDA_108C(al_825, buf80);
		(void)fn1EDA_04A9(0x0000, 0x0000, &ch_dummy, &ds_dummy);
	}

	/* --- l1229_09C9: finish the stream and return ------------------- */
	ax_920 = fn1EDA_116A(buf80, &ds_dummy);
	(void)fn1EDA_04A9(0x0000, 0x0000, &ch_dummy, &ds_dummy);
	LG8(0x5CB2) = (u8)(ax_920 - 0x0002);
	fn1EDA_1051((u8)(ax_920 - 0x0002), buf80);
	(void)fn1EDA_04A9(0x0000, 0x0000, &ch_dummy, &ds_dummy);

	/* l1229_1150-style epilogue: show the cursor again */
	(void)fn133F_0141(&dx_967, &bp_962, &ds_966);

	*dxOut = dx_967;
	*(u16 *)bpOut = bp_962;
	*(u16 *)dsOut = ds_966;
	return 0x00;
}
