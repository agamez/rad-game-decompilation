/* seg0C74_part1.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 1 of N: functions 0C74:0000 .. 0C74:02D8 (8 functions, ascending).
 *
 *   0000 004B 007C 00B2 00DB 011E 020C 02D8
 *
 * Literal recovery from analysis/slices/0C74/0C74_<off>.asm (ground truth)
 * and the Reko decompilation / .dis; frozen prototypes from src/seg0C74.h
 * (analysis/summary/iface.tsv) adopted exactly.  See CONVENTIONS.md,
 * analysis/SEGMAP.md and docs/notes-0C74.md ("## part 1").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   None in this range.  No int 10h / int 16h / int 21h, no `in`/`out` port
 *   instruction, no __cli/__sti and no int 23h occur in 0000..02D8.  Mouse
 *   traffic (INT 33h) reaches the hardware only through fn1206_0066 /
 *   fn1206_0038 (already ported in seg1206.c) and the keyboard/pacing helpers
 *   through fn1E78_029C (seg1E78.c).  Every other callee is a file/video/string
 *   helper already ported in segments 1AB8 / 1EDA / 1E5F.
 *
 * Stack-frame / ABI adaptations (documented in docs/notes-0C74.md):
 *   - The Turbo C "stack-reuse" string helpers fn1EDA_0A1F / 0AAC / 0A39 use
 *     the CPU stack as a persistent scratch area: a callee leaves a far
 *     pointer staged for the next call.  Reko recovered the staged values
 *     (ptrLoc010C_*) from the pushed buffer; they are passed explicitly here
 *     (same convention as seg0800 parts 1/3 and seg1229 part 2b).
 *   - fn1AB8_1285 has a `void` frozen prototype but materialises AX =
 *     (u16)LG8(0xB83E); its 0C74 callers consume that AX (`mov [bp-6h],ax`),
 *     so it is re-read from DGROUP after the call (see seg1AB8_part4.c).
 *   - Register-output / saved-BP artifacts (fn1206_0066/0038 BP+DS outputs,
 *     the BP return of 011E/020C/02D8) have no flat-C equivalent; they are
 *     written as 0 and the functions return 0, per docs/notes-0800.md.
 */

#include <stddef.h>
#include <stdint.h>
#include <time.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C74.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1E5F.h"
#include "seg1E78.h"
#include "seg1206.h"

// 0C74:0000: u8 engine_probe_file(u8 * ptrArg04, u16 * dxOut)
// Probe for a file (DOS find-first): copy the caller's length-prefixed record
// into a local 0FFh-clamped pattern, run fn1E5F_00DE, then return 1 when the
// DGROUP find-flag 0xB8A6 is zero.  Uses the 44-byte DOS DTA at [bp-012Eh].
u8 engine_probe_file /* was fn0C74_0000 */(u8 * ptrArg04, u16 * dxOut)
{
	u8  abLoc0104[0x100];   /* [bp-0102h] search pattern (Reko ptrLoc010A) */
	u8  abLoc012E[0x2C];    /* [bp-012Eh] DOS DTA, 44 bytes (Reko fp-0x130) */
	u8  bLoc0105_91;        /* [bp-0103h] return byte (Reko bLoc0105_91) */
	u16 dx_115;             /* fn1EDA_0A39 dxOut */

	/* fn1EDA_0A39(0FFh, ss:bp-0102h, ptrArg04) -- copy ptrArg04 into abLoc0104. */
	fn1EDA_0A39(0xFF, abLoc0104, ptrArg04, &dx_115);

	/* fn1E5F_00DE(ds, ss:bp-012Eh, 3Fh, ss:bp-0102h) -- find first with the
	 * DTA at abLoc012E and the pattern at abLoc0104.  Reko names its DX
	 * result dx_53 and assigns it to dxOut; no caller reads it (the flat port
	 * writes 0 below), so the value is discarded here. */
	(void)fn1E5F_00DE((char *)abLoc012E, 0x3F, abLoc0104);

	if (LG16(0xB8A6) != 0x0000)
		bLoc0105_91 = 0x00;
	else
		bLoc0105_91 = 0x01;

	/* Reko models dxOut = dx_53 (the DX register left by 1E5F:00DE, i.e. the
	 * DTA offset).  No caller reads it; the flat model writes 0. */
	*dxOut = 0x0000;
	return bLoc0105_91;
}

// 0C74:004B: void engine_format_u32(u32 dwArg04, u8 * ptrArg08)
// Format a 32-bit value into a local 100h-byte record then copy that record
// (clamped to 0FFh) to ptrArg08.  The heavy lifting is fn1EDA_0F26 / 0A39.
void engine_format_u32 /* was fn0C74_004B */(u32 dwArg04, u8 * ptrArg08)
{
	u8  abLoc0100[0x100];   /* [bp-0100h] number scratch (Reko fp-0x102) */
	u16 dx_89;              /* fn1EDA_0A39 dxOut */

	/* push [bp+8h] ; push [bp+6h] ; push 0 ; push ss:bp-0100h ; push 0FFh */
	fn1EDA_0F26(0xFF, abLoc0100, 0x00, dwArg04);
	/* fn1EDA_0A39(0FFh, ptrArg08, ss:bp-0100h) */
	fn1EDA_0A39(0xFF, ptrArg08, abLoc0100, &dx_89);
}

// 0C74:007C: void engine_repaint_rect(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)
// Repaint a rectangle via the 1AB8 text driver: first with the caller's four
// coordinates, then hide-and-restore the cursor with 10CE/10E1.
void engine_repaint_rect /* was fn0C74_007C */(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)
{
	u16 ax_10CE;
	u16 ax_10E1;

	/* push wArg08 ; push wArg06 ; push wArg04 ; push wArg02 ; push 1h */
	fn1AB8_0F93(0x01, wArg02, wArg04, wArg06, wArg08);
	fn1AB8_1028();

	/* push 0h ; push 0h ; call 10CEh ; push ax ; call 10E1h ; push ax ;
	 * push 1h ; call 0F93h  -- 10CE first, then 10E1; the two 0h are the
	 * staged 0F93 wArg0A/wArg0C. */
	ax_10CE = fn1AB8_10CE();
	ax_10E1 = fn1AB8_10E1();
	fn1AB8_0F93(0x01, ax_10E1, ax_10CE, 0x00, 0x00);
}

// 0C74:00B2: void engine_advance_stream_cursor(u8 bArg04)
// Advance the DGROUP stream cursor at 0x58E2 and write a text run at the old
// position: fn1AB8_1B3E(0x1DF, bArg04+old, 0x1D5, old); then old += bArg04.
void engine_advance_stream_cursor /* was fn0C74_00B2 */(u8 bArg04)
{
	u16 wOld = LG16(0x58E2);

	/* push [58E2h] ; push 1D5h ; push ax(bArg04+[58E2h]) ; push 1DFh */
	fn1AB8_1B3E(0x01DF, (u16)((u16)bArg04 + wOld), 0x01D5, wOld);
	/* mov al,[bp+6h] ; xor ah,ah ; add [58E2h],ax */
	LG16(0x58E2) = (u16)(wOld + (u16)bArg04);
}

// 0C74:00DB: void engine_set_attr_and_emit_text(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)
// Set a 1AB8 draw attribute (1175(3,1)) then emit a text run at the caller's
// coordinates (1B3E).
void engine_set_attr_and_emit_text /* was fn0C74_00DB */(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)
{
	/* push 1h ; push 3h */
	fn1AB8_1175(0x03, 0x01);
	/* push wArg0A ; push wArg08 ; push wArg06 ; push wArg04 */
	fn1AB8_1B3E(wArg04, wArg06, wArg08, wArg0A);
}

// 0C74:011E: u16 engine_redraw_clock_seconds(u16 * dsOut)
// Redraw the "seconds" half of the clock field: format DGROUP:58DCh into a
// two-digit record at [bp-0004h] (zero-padding a single digit with cs:00FCh),
// then repaint the field and show the mouse cursor.
//
// Local frame: [bp-0106h] abLoc0106 staged scratch (Reko ptrLoc010C_298/308);
// [bp-0006h] wLoc06 = fn1AB8_1285 AX result; [bp-0004h] bLoc06 record.
// bLoc06 is staged at DGROUP 0xF800 (like fn0800_0AA1's 0xF6E0 / fn0800_0B42's
// 0xF6F0): fn1AB8_1D82 materializes the record as ES:BX for the driver's 0x26
// text op, and a C stack buffer resolves to segment 0 there -- the glyphs drew
// nothing, leaving the clock digits blanked during move animations (the 02D8
// repaint path).  The original's tiny model had SS==DS so this only bites the
// flat port.
u16 engine_redraw_clock_seconds /* was fn0C74_011E */(u16 * dsOut)
{
	u8  abLoc0106[0x100];   /* [bp-0106h] staged scratch (Reko ptrLoc010C_*) */
	u8 *bLoc06 = g_dgroup + 0xF800;   /* [bp-0004h] 2-digit record (staged) */
	u16 wLoc06;             /* [bp-0006h] fn1AB8_1285 AX result */
	u16 dx_343;
	u16 dx_345;
	u16 dx_350;
	u8  ch_346;
	u8  ch_347;
	u8  ch_349;
	u16 bp_152 = 0x0000;    /* saved-BP artifact out of fn1206_0066 */
	u16 ds_152 = 0x0000;    /* dropped DGROUP selector out of fn1206_0066 */
	u8 *es_344 = NULL;      /* fn1EDA_0CD4 esOut */
	u8 *es_348 = NULL;      /* fn1EDA_0CD4 esOut */

	/* engine_format_u32(58DCh, ss:bp-0106h) ; fn1EDA_0A39(2, ss:bp-0004h, <staged>) */
	engine_format_u32(LG32(0x58DC), abLoc0106);
	fn1EDA_0A39(0x02, bLoc06, abLoc0106, &dx_343);

	/* cmp byte [bp-4h],2h ; jnc 016Ch -- pad a 1-digit record */
	if (bLoc06[0] < 0x02)
	{
		fn1EDA_0A1F(&g_seg0C74[0x00FC], abLoc0106);   /* {1,"0"} */
		fn1EDA_0AAC(bLoc06, abLoc0106);
		fn1EDA_0A39(0x02, bLoc06, abLoc0106, &dx_345);
	}

	fn1AB8_1285();
	wLoc06 = (u16)LG8(0xB83E);   /* AX = (u16)LG8(0xB83E) (see seg1AB8) */

	/* mov al,[58E4h] ; fn1EDA_0CD4(cs:00FEh, al) ; jnz 0189h */
	if (fn1EDA_0CD4(&g_seg0C74[0x00FE], LG8(0x58E4), &es_344) == 0x00)
		(void)fn1206_0066(&bp_152, &ds_152);

	/* push 24Bh ; push 192h ; push 25Ch ; push 19Bh ; call 00DBh */
	engine_set_attr_and_emit_text(0x019B, 0x025C, 0x0192, 0x024B);

	(void)fn1AB8_1C32(0x08);
	/* push 253h ; push 196h ; push ss:bp-4h ; call 1D82h */
	(void)fn1AB8_1D82(bLoc06, 0x0196, 0x0253, &ch_346);
	(void)fn1AB8_1C32(0x0A);
	/* push 254h ; push 197h ; push ss:bp-4h ; call 1D82h */
	(void)fn1AB8_1D82(bLoc06, 0x0197, 0x0254, &ch_347);

	/* mov al,[58E4h] ; fn1EDA_0CD4(cs:00FEh, al) ; jnz 01DEh */
	if (fn1EDA_0CD4(&g_seg0C74[0x00FE], LG8(0x58E4), &es_348) == 0x00)
		(void)fn1206_0038(&ch_349, &dx_350, &bp_152, &ds_152);

	/* push word [bp-6h] ; call 1C32h */
	(void)fn1AB8_1C32((u8)wLoc06);

	*dsOut = 0x0000;   /* DGROUP selector dropped in the flat model */
	return 0x0000;     /* BP return artifact: not meaningful in flat C */
}

// 0C74:020C: u16 engine_redraw_clock_minutes(u16 * dsOut)
// Redraw the "minutes" half of the clock field (DGROUP:58CCh), same structure
// as 011E but with the cs:01EAh pad record and the 0233/0244/023B/023Ch field
// geometry.
u16 engine_redraw_clock_minutes /* was fn0C74_020C */(u16 * dsOut)
{
	u8  abLoc0106[0x100];   /* [bp-0106h] staged scratch (Reko ptrLoc010C_*) */
	u8 *bLoc06 = g_dgroup + 0xF820;   /* [bp-0004h] 2-digit record (staged,
	                                   * see the engine_redraw_clock_seconds note above) */
	u16 wLoc06;             /* [bp-0006h] fn1AB8_1285 AX result */
	u16 dx_343;
	u16 dx_345;
	u16 dx_350;
	u8  ch_346;
	u8  ch_347;
	u8  ch_349;
	u16 bp_152 = 0x0000;    /* saved-BP artifact out of fn1206_0066 */
	u16 ds_152 = 0x0000;    /* dropped DGROUP selector out of fn1206_0066 */
	u8 *es_344 = NULL;      /* fn1EDA_0CD4 esOut */
	u8 *es_348 = NULL;      /* fn1EDA_0CD4 esOut */

	engine_format_u32(LG32(0x58CC), abLoc0106);
	fn1EDA_0A39(0x02, bLoc06, abLoc0106, &dx_343);

	if (bLoc06[0] < 0x02)
	{
		fn1EDA_0A1F(&g_seg0C74[0x01EA], abLoc0106);   /* {1,"0"} */
		fn1EDA_0AAC(bLoc06, abLoc0106);
		fn1EDA_0A39(0x02, bLoc06, abLoc0106, &dx_345);
	}

	fn1AB8_1285();
	wLoc06 = (u16)LG8(0xB83E);   /* AX = (u16)LG8(0xB83E) (see seg1AB8) */

	if (fn1EDA_0CD4(&g_seg0C74[0x01EC], LG8(0x58E4), &es_344) == 0x00)
		(void)fn1206_0066(&bp_152, &ds_152);

	/* push 233h ; push 192h ; push 244h ; push 19Bh ; call 00DBh */
	engine_set_attr_and_emit_text(0x019B, 0x0244, 0x0192, 0x0233);

	(void)fn1AB8_1C32(0x08);
	/* push 23Bh ; push 196h ; push ss:bp-4h ; call 1D82h */
	(void)fn1AB8_1D82(bLoc06, 0x0196, 0x023B, &ch_346);
	(void)fn1AB8_1C32(0x0A);
	/* push 23Ch ; push 197h ; push ss:bp-4h ; call 1D82h */
	(void)fn1AB8_1D82(bLoc06, 0x0197, 0x023C, &ch_347);

	/* push word [bp-6h] ; call 1C32h ; mov al,[58E4h] ; call 0CD4h */
	(void)fn1AB8_1C32((u8)wLoc06);
	if (fn1EDA_0CD4(&g_seg0C74[0x01EC], LG8(0x58E4), &es_348) == 0x00)
		(void)fn1206_0038(&ch_349, &dx_350, &bp_152, &ds_152);

	*dsOut = 0x0000;   /* DGROUP selector dropped in the flat model */
	return 0x0000;     /* BP return artifact: not meaningful in flat C */
}

// 0C74:02D8: u16 engine_clock_tick(u16 wArg02, u16 * dsOut)
// Clock-tick redraw driver: when the 0x58BE enable byte is clear, just flash
// the period (1E78:029C(wArg02)).  Otherwise divide wArg02 by 7, then for each
// iteration divide DGROUP:58D8h by 60 (1EDA:098A) and repaint the seconds
// (011E) and minutes (020C) halves whenever their quotients/remainders changed,
// else flash the period.
u16 engine_clock_tick /* was fn0C74_02D8 */(u16 wArg02, u16 * dsOut)
{
	u16 wLoc02;             /* [bp-0002h] loop index (Reko bp_106->wFFFE) */
	u16 wLoc04;             /* [bp-0004h] loop count (Reko bp_106->wFFFC) */
	u16 dx_269;
	u16 dx_273;
	u16 dx_274;
	u16 ds_44 = 0x0000;     /* fn1EDA_098A DS output (dropped selector) */
	s16 cx_270;
	s16 dx_45;
	s16 bx_271;
	s16 cx_68;
	s16 dx_272;
	s16 bx_67;
	long long t0 = 0;
	int repaints = 0;
	extern int rad_pace_trace_on(void);
	extern void rad_pace_trace(const char *, unsigned, unsigned, long long);

	if (rad_pace_trace_on())
	{
		struct timespec ts;
		clock_gettime(CLOCK_MONOTONIC, &ts);
		t0 = (long long)ts.tv_sec * 1000000000ll + ts.tv_nsec;
	}

	/* cmp byte [58BEh],0 ; jnz 02EEh */
	if (LG8(0x58BE) == 0x00)
	{
		(void)fn1E78_029C(wArg02, &dx_269);
		if (rad_pace_trace_on())
			rad_pace_trace("02D8-idle", wArg02, 0, 0);
	}
	else
	{
		/* mov ax,[bp+4h] ; xor dx,dx ; mov cx,7 ; div cx ; mov [bp-4h],ax */
		wLoc04 = (u16)(wArg02 / 0x0007);
		/* xor ax,ax ; cmp ax,[bp-4h] ; jbe 030Bh -- unsigned, always taken */
		if (wLoc04 >= 0x0000)
		{
			wLoc02 = 0x0000;
			do
			{
				/* First 098Ah: quotient ([58DAh]:[58D8h] / 3Ch) -> 58CCh:58CEh.
				 * The unused wArg00/wArg02 stack slots are seeded 0 (they are
				 * only read on the divide-by-zero fatal path, not taken). */
				LG16(0x58CC) = (u16)fn1EDA_098A(0x003C, LG32(0x58D8),
				                                0x0000, 0x0000,
				                                &cx_270, &dx_45, &bx_271,
				                                (void *)&ds_44);
				LG16(0x58CE) = (u16)dx_45;

				/* Second (identical) 098Ah: remainder -> 58DCh:58DEh. */
				(void)fn1EDA_098A(0x003C, LG32(0x58D8),
				                  0x0000, 0x0000,
				                  &cx_68, &dx_272, &bx_67,
				                  (void *)&ds_44);
				LG16(0x58DC) = (u16)cx_68;
				LG16(0x58DE) = (u16)bx_67;

				/* cmp dx,[58CAh] ; jnz 035Ah ; cmp ax,[58C8h] ; jz 036Eh */
				if (LG16(0x58DE) != LG16(0x58CA) ||
				    LG16(0x58DC) != LG16(0x58C8))
				{
					(void)engine_redraw_clock_seconds(dsOut);
					++repaints;
					LG16(0x58C8) = LG16(0x58DC);
					LG16(0x58CA) = LG16(0x58DE);
				}
				else
				{
					(void)fn1E78_029C(0x0002, &dx_273);
				}

				/* cmp dx,[58C6h] ; jnz 0388h ; cmp ax,[58C4h] ; jz 039Ch */
				if (LG16(0x58CE) != LG16(0x58C6) ||
				    LG16(0x58CC) != LG16(0x58C4))
				{
					(void)engine_redraw_clock_minutes(dsOut);
					++repaints;
					LG16(0x58C4) = LG16(0x58CC);
					LG16(0x58C6) = LG16(0x58CE);
				}
				else
				{
					(void)fn1E78_029C(0x0002, &dx_274);
				}

				/* mov ax,[bp-2h] ; cmp ax,[bp-4h] ; jz 03AEh ; jmp 0310h */
				if (wLoc02 == wLoc04)
					break;
				++wLoc02;
			} while (1);
		}
	}

	if (rad_pace_trace_on())
	{
		struct timespec ts;
		long long t1;
		clock_gettime(CLOCK_MONOTONIC, &ts);
		t1 = (long long)ts.tv_sec * 1000000000ll + ts.tv_nsec;
		rad_pace_trace("02D8", wArg02, repaints, t1 - t0);
	}

	*dsOut = 0x0000;   /* DGROUP selector dropped in the flat model */
	return 0x0000;     /* BP return artifact: not meaningful in flat C */
}
