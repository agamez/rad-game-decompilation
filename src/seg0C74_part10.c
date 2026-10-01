/* seg0C74_part10.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 10 of N: function 0C74:37C3 only.
 *
 *   37C3
 *
 * Literal recovery from analysis/slices/0C74/0C74_37C3.asm (ground truth) and
 * the Reko slice 0C74_37C3.c; frozen prototype from src/seg0C74.h
 * (analysis/summary/iface.tsv) adopted exactly:
 *
 *   u8 engine_bar_retract(u16 *dxOut, u16 *bpOut, u16 *dsOut)
 *
 * See CONVENTIONS.md, analysis/SEGMAP.md and docs/notes-0C74.md ("## part 10").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   NONE directly.  No int 10h / int 16h / int 21h, no raw `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch occur in
 *   37C3.  Every hardware-touching action is reached through already-ported
 *   callees: the 1AB8 video driver (13D7 / 1E3C), renamed_1e78_02fb (input poll),
 *   renamed_1206_015b (INT 33h mouse wrapper, seg1206.c), audio_get_soundcard_port / 0354 (sound)
 *   and the 0C74 helpers 0D43 / 02D8.
 *
 * Flat-model / ABI adaptations (recorded in docs/notes-0C74.md "## part 10"):
 *   - Reko's bp_XXXX frame-pointer local (re-bound after the engine_clock_tick call
 *     whose AX return is the caller's saved BP) is the current function's own
 *     frame; it is folded back onto the literal locals, per the part 1
 *     section 3 convention.
 *   - The far-pointer table at DGROUP:0x58F4 (4 bytes per entry) is read as a
 *     single u32 and cast to a host pointer, matching parts 2/3/8/9.
 *   - bpOut / dsOut register outputs are the caller's saved BP and the dropped
 *     DGROUP selector; both receive 0 (part 1 section 3).  dxOut is the DX
 *     register left by the last call; the flat port writes 0 and records the
 *     loss (same treatment as engine_probe_file's / 3615's dxOut).
 */

#include <stddef.h>
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C74.h"
#include "seg1AB8.h"
#include "seg1E78.h"
#include "seg11C8.h"
#include "seg1206.h"

// 0C74:37C3: u8 engine_bar_retract(u16 * dxOut, u16 * bpOut, u16 * dsOut)
//
// Fourth game-core "bar" update and the mirror of engine_bar_march: it shrinks the
// live bar.  It returns immediately when [58B4h] <= 1, clears [58B1h], and
// either runs the 0D43 full redraw when the state word [5968h] is 1, or (four
// edge probes) enters the main march: tick 02D8 with [58E6h]*2, cycle the
// animation counter 5..1 (11C8 sound), retract the live position while [58B4h]
// > 1, poll input/mouse (02FB, 1206:015B) or the [58BCh]/[58BDh] latch, then
// repeatedly probe four edges; on success blit the DGROUP:0x58F4 sprite for the
// current counter and continue, or a failed probe advances the position one
// step and stops.  After 16h rows it either bumps [58BCh] and restarts or
// stops.  Returns the [bp-1] byte (0 = gate failed).
u8 engine_bar_retract /* was fn0C74_37C3 */(u16 *dxOut, u16 *bpOut, u16 *dsOut)
{
	u8  bLoc01 = 0x00;      /* [bp-01h] result flag */
	u8  bLoc02 = 0x00;      /* [bp-02h] animation counter (5..1) / sprite index */
	u8  bLoc03 = 0x00;      /* [bp-03h] row counter (1..16h) */
	u8  dlTmp = 0x00;       /* bgi_draw_line dlOut */
	u8  chTmp = 0x00;       /* renamed_1206_015b chOut */
	u16 dxTmp = 0x0000;     /* renamed_1206_015b dxOut */
	u16 bpScratch = 0x0000; /* engine_redraw_bars_up / renamed_1206_015b bpOut artifact */
	u16 dsTmp = 0x0000;     /* reusable u16 dsOut for 0D43 / 02D8 / 1206 */

	/* 37C3..37D4: cmp word [58B4h],1h ; ja 37D5h -- only run above 1. */
	if (LG16(0x58B4) <= 0x0001)
		goto l0C74_3969;

	/* 37D5: mov byte [58B1h],0h */
	LG8(0x58B1) = 0x00;

	/* 37DB..37EC: cmp word [5968h],1h ; jnz 37EDh -- the 1 state runs the
	 * 0D43 full redraw and returns. */
	if (LG16(0x5968) == 0x0001)
	{
		(void)engine_redraw_bars_up(0x15, &bpScratch, &dsTmp);
		bLoc01 = 0x01;
		goto l0C74_3969;
	}

	/* 37ED..383E: four edge probes.  Each of the first three must be zero;
	 * the fourth must be non-zero to fall into the main march.  Any other
	 * result jumps to 383C (jmp 3969). */
	if (bgi_draw_line(LG16(0x58BA), (u16)(LG16(0x58B4) - 0x0001),
	                &dlTmp) != 0x00)
		goto l0C74_3969;
	if (bgi_draw_line((u16)(LG16(0x58BA) - 0x0015),
	                (u16)(LG16(0x58B4) - 0x0001), &dlTmp) != 0x00)
		goto l0C74_3969;
	if (bgi_draw_line((u16)(LG16(0x58BA) - 0x0029),
	                (u16)(LG16(0x58B4) - 0x0001), &dlTmp) != 0x00)
		goto l0C74_3969;
	if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001),
	                (u16)(LG16(0x58B4) - 0x0001), &dlTmp) == 0x00)
		goto l0C74_3969;

	/* 383F: mov byte [bp-1h],1h ; mov byte [bp-2h],5h */
	bLoc01 = 0x01;
	bLoc02 = 0x05;

l0C74_3847:
	/* mov byte [bp-3h],1h ; jmp 3850h */
	bLoc03 = 0x01;
	goto l0C74_3850;

l0C74_384D:
	/* inc byte [bp-3h] */
	++bLoc03;

l0C74_3850:
	/* mov ax,[58E6h] ; shl ax,1h ; push ax ; call 02D8h */
	(void)engine_clock_tick((u16)(LG16(0x58E6) << 1), &dsTmp);

	/* dec byte [bp-2h] ; cmp byte [bp-2h],0h ; jnz 3876h */
	--bLoc02;
	if (bLoc02 == 0x00)
	{
		/* 3862: mov byte [bp-2h],4h ; cmp byte [58B0h],0h ; jz 3874h */
		bLoc02 = 0x04;
		if (LG8(0x58B0) != 0x00)
			audio_write_opl3_register(0x0032);   /* push 32h */
	}
	else
		(void)audio_get_soundcard_port();

	/* 387B: cmp word [58B4h],1h ; jbe 388Ah */
	if (LG16(0x58B4) > 0x0001)
	{
		LG16(0x58B4) = (u16)(LG16(0x58B4) - 0x0001);
		LG16(0x58B6) = (u16)(LG16(0x58B6) - 0x0001);
	}

	/* 388A: cmp byte [58B2h],0h ; jz 38B6h */
	if (LG8(0x58B2) != 0x00)
	{
		/* 3891: call 1E78:02FBh ; or al,al ; jz 389Fh */
		if (renamed_1e78_02fb() != 0x00)
			LG8(0x58B1) = 0x01;

		/* 389F: push 0h ; call 1206:015Bh ; or al,al ; jz 38B4h */
		if ((u8)renamed_1206_015b(&chTmp, &dxTmp, &bpScratch, &dsTmp) != 0x00)
		{
			LG8(0x58E0) = 0x01;
			LG8(0x58B1) = 0x01;
		}
	}
	/* 38B6: mov al,[58BCh] ; cmp al,[58BDh] ; jnz 38C4h */
	else if (LG8(0x58BC) == LG8(0x58BD))
		LG8(0x58B1) = 0x01;

	/* 38C4: cmp word [58B4h],1h ; ja 38D0h -- clamp the flag at the floor. */
	if (LG16(0x58B4) <= 0x0001)
		LG8(0x58B1) = 0x01;

	/* 38D0..392B: four edge probes; any of the first three non-zero (or the
	 * fourth zero) advances the position one step and stops. */
	if (bgi_draw_line(LG16(0x58BA), LG16(0x58B4), &dlTmp) != 0x00)
		goto l0C74_391B;
	if (bgi_draw_line((u16)(LG16(0x58BA) - 0x0015), LG16(0x58B4),
	                &dlTmp) != 0x00)
		goto l0C74_391B;
	if (bgi_draw_line((u16)(LG16(0x58BA) - 0x0029), LG16(0x58B4),
	                &dlTmp) != 0x00)
		goto l0C74_391B;
	if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001), LG16(0x58B4),
	                &dlTmp) != 0x00)
		goto l0C74_392C;

l0C74_391B:
	/* inc word [58B4h] ; inc word [58B6h] ; call 11C8:033Bh ; jmp 3969h */
	LG16(0x58B4) = (u16)(LG16(0x58B4) + 0x0001);
	LG16(0x58B6) = (u16)(LG16(0x58B6) + 0x0001);
	(void)audio_get_soundcard_port();
	goto l0C74_3969;

l0C74_392C:
	/* push [58B4h] ; push [58B8h] ; mov al,[bp-2h] ; xor ah,ah ; mov di,ax ;
	 * shl di,2h ; les di,[di+58F4h] ; push es ; push di ; push 0h ;
	 * call 1AB8:13D7h */
	(void)bgi_signed_rectangle_intersect(0x00,
	    far_ptr(LG32((u16)(0x58F4 +
	                                (u16)((u16)bLoc02 << 2)))),
	    LG16(0x58B8), LG16(0x58B4));

	/* cmp byte [bp-3h],16h ; jz 3954h */
	if (bLoc03 == 0x16)
		goto l0C74_3954;
	goto l0C74_384D;

l0C74_3954:
	/* cmp byte [58B1h],0h ; jnz 395Fh ; inc byte [58BCh] */
	if (LG8(0x58B1) == 0x00)
		LG8(0x58BC) = (u8)(LG8(0x58BC) + 0x01);

	/* 395F: cmp byte [58B1h],0h ; jnz 3969h ; jmp 3847h (fall-through) */
	if (LG8(0x58B1) != 0x00)
		goto l0C74_3969;
	goto l0C74_3847;

l0C74_3969:
	/* mov al,[bp-1h] ; leave ; ret.  DX / BP / DS are register artifacts;
	 * the flat model writes 0 (part 1 section 3 / section 6). */
	*dxOut = 0x0000;
	*bpOut = 0x0000;
	*dsOut = 0x0000;
	return bLoc01;
}
