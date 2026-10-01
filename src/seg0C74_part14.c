/* seg0C74_part14.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 14 of N: function 0C74:4999 only.
 *
 *   4999
 *
 * Literal recovery from analysis/slices/0C74/0C74_4999.asm (ground truth) and
 * the Reko skeleton 0C74_4999.c; frozen prototype from src/seg0C74.h
 * (analysis/summary/iface.tsv) adopted exactly:
 *
 *   u8 engine_bar_pull_out(void *bpOut, u16 *dsOut)
 *
 * See CONVENTIONS.md, analysis/SEGMAP.md and docs/notes-0C74.md ("## part 14").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   NONE directly.  No int 10h / int 16h / int 21h, no raw `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch
 *   (fn1E5F_000B is never called) occur in 4999.  Every hardware-touching
 *   action is reached indirectly through already-ported callees: the 1AB8
 *   video/text driver (10F4/1AF6/1C32/1E3C/13D7) and the 0C74 tick/frame
 *   drivers 070D / 02D8, plus the 11C8 sound helpers 0354/033B.
 *
 * Flat-model / ABI adaptations (recorded in docs/notes-0C74.md "## part 14"):
 *   - Reko's bp_39 / bp_172 / bp_XXXX frame-pointer locals (re-bound after
 *     each engine_scale_and_tick_clock / 02D8 call whose AX return is the caller's saved BP)
 *     are this function's own frame; they are folded back onto the literal
 *     [bp-Nh] locals below, per the notes-0C74 part 1 section 3 convention.
 *   - The far-pointer table at DGROUP:0x58F4 (4 bytes per entry) is read as a
 *     single u32 and cast to a host pointer, matching parts 2/3/8/9/10.
 *   - bpOut / dsOut register outputs are the caller's saved BP and the dropped
 *     DGROUP selector; both receive 0 (part 1 section 3).
 *   - The `1AF6` dxOut and `1E3C` dlOut register outputs are unused by the
 *     original; scratch locals are passed.
 *   - The `cmp word ptr [bp-4h],0F1h` immediates at 49FE / 4A49 are the
 *     sign-extended imm8 form 0xFFF1 (`~0x0E` in Reko), verified against the
 *     raw encoding (83 7E FC F1); recovered as 0xFFF1.
 */

#include <stddef.h>
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C74.h"
#include "seg1AB8.h"
#include "seg11C8.h"

/* 0C74:4999: u8 engine_bar_pull_out(void * bpOut, u16 * dsOut)
 *
 * Game-core bar "pull-out / settle" update (sibling of 396E/45CE).  Increments
 * [58B4h] and first draws a 13h/12h rectangle upward one row per step through
 * 1AF6 until the row counter reaches 0FFF1h, a 1E3C edge probe fires, or the
 * sign-extended 32-bit sum [bp-4h]+[58B4h] is no longer positive.  If the
 * counter did not reach 0FFF1h the drawn column is erased back down and the
 * [bp-1] flag is cleared.  If it did, the collision sequence runs: 02D8 wait,
 * grow two cached bars (1AF6 strokes) from [58B8h]+12h/+14h while the edge
 * probe is clear and the bar X stays below 1DEh, derive the [596Ch..5972h]
 * rectangle from [58B4h]/[58B8h]/[58BAh] with four 1E3C probes, lay down the
 * two 1AF6 strokes at the bar origin-1/-2, erase the column back down, then
 * pull the bar down while cycling the animation counter 5..1 (11C8 sound)
 * and blitting the DGROUP:58F4h sprite; finally calls engine_scatter_starfield with either
 * the live or the cached rectangle depending on a signed edge compare.
 * Returns the [bp-1] byte. */
u8 engine_bar_pull_out /* was fn0C74_4999 */(void *bpOut, u16 *dsOut)
{
	u8  bLoc01 = 0x01;      /* [bp-01h] return flag; 4999: mov [bp-1h],1h */
	u16 wLoc04 = 0x000D;    /* [bp-04h] scan/bar counter; 4999: mov [bp-4h],0Dh */
	u16 wLoc06 = 0x0000;    /* [bp-06h] erase / animation counter */
	u16 wLoc08 = 0x0000;    /* [bp-08h] pulled-row counter */
	u16 wLoc0A = 0x0000;    /* [bp-0Ah] bar X origin ([58B8h]+12h) */
	u16 wLoc0C = 0x0000;    /* [bp-0Ch] bar X origin 2 ([58B8h]+14h) */
	u8  dlTmp  = 0x00;      /* bgi_draw_line dlOut */
	u16 dxTmp  = 0x0000;    /* bgi_set_pixel dxOut */
	u16 dsTmp  = 0x0000;    /* engine_scale_and_tick_clock / 02D8 dsOut */
	void *dsv  = NULL;      /* engine_scale_and_tick_clock void * dsOut */

	/* 499D: push 0h ; push 0h ; push 1h ; call far 1AB8h:10F4h */
	bgi_set_text_background_color(0x0001, 0x0000, 0x0000);
	/* 49A8: push 0Ch ; call far 1AB8h:1C32h */
	(void)bgi_get_text_cursor_attributes(0x0C);
	/* 49B4: inc word ptr [58B4h] */
	LG16(0x58B4) = (u16)(LG16(0x58B4) + 0x0001);

	/* l0C74_49BC: draw the column upward, one 13h/12h rectangle per step,
	 * until the counter reaches 0FFF1h, the 1E3C probe fires, or the 32-bit
	 * sum [bp-4h]+[58B4h] is no longer > 0. */
	for (;;)
	{
		/* 49BC: 1AF6([58B8h]+13h, wLoc04+[58B4h], [58B8h]+12h,
		 *            wLoc04+[58B4h]) */
		(void)bgi_set_pixel((u16)(LG16(0x58B8) + 0x0013),
		                  (u16)(wLoc04 + LG16(0x58B4)),
		                  (u16)(LG16(0x58B8) + 0x0012),
		                  (u16)(wLoc04 + LG16(0x58B4)),
		                  &dxTmp);
		/* 49F3: dec word ptr [bp-4h] */
		wLoc04 = (u16)(wLoc04 - 0x0001);
		/* 49F6: push 12Ch ; push 14h ; call 070Dh */
		(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
		/* 49FE: cmp word ptr [bp-4h],0FFF1h ; jz 4A49h */
		if (wLoc04 == 0xFFF1)
			goto l0C74_4A49;
		/* l0C74_4A04: 1E3C([58B8h]+13h, wLoc04+[58B4h]) ; jnz 4A49h */
		if (bgi_draw_line((u16)(LG16(0x58B8) + 0x0013),
		                (u16)(wLoc04 + LG16(0x58B4)), &dlTmp) != 0x00)
			goto l0C74_4A49;
		/* l0C74_4A26: signed 32-bit sum [bp-4h]+[58B4h].
		 *   cmp dx,0h ; jl 4A49h ; jle 4A41h ; jmp 49BCh
		 *   cmp ax,0h ; jbe 4A49h ; jmp 49BCh */
		{
			s32 sum = (s32)(s16)wLoc04 + (s32)(u16)LG16(0x58B4);
			if (sum < 0)
				goto l0C74_4A49;
			if (sum > 0xFFFF)
				continue;
			if ((u16)sum <= 0x0000)
				goto l0C74_4A49;
		}
	}

l0C74_4A49:
	/* 4A49: cmp word ptr [bp-4h],0FFF1h ; jz 4AB7h */
	if (wLoc04 == 0xFFF1)
		goto l0C74_4AB7;

	/* l0C74_4A4F: push 0h ; call far 1AB8h:1C32h */
	(void)bgi_get_text_cursor_attributes(0x00);
	/* 4A56: mov ax,[bp-4h] ; inc ax ; cmp ax,0Dh ; jg 4AACh */
	wLoc06 = (u16)(wLoc04 + 0x0001);
	if ((s16)wLoc06 > 0x000D)
		goto l0C74_4AAC;
	/* l0C74_4A5F: erase the drawn column back down. */
	for (;;)
	{
		/* l0C74_4A67: 1AF6([58B8h]+13h, wLoc06+[58B4h],
		 *                   [58B8h]+12h, wLoc06+[58B4h]) */
		(void)bgi_set_pixel((u16)(LG16(0x58B8) + 0x0013),
		                  (u16)(wLoc06 + LG16(0x58B4)),
		                  (u16)(LG16(0x58B8) + 0x0012),
		                  (u16)(wLoc06 + LG16(0x58B4)),
		                  &dxTmp);
		/* 4A9E: push 12Ch ; push 14h ; call 070Dh */
		(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
		/* 4AA6: cmp word ptr [bp-6h],0Dh ; jnz 4A64h */
		if (wLoc06 == 0x000D)
			break;
		/* l0C74_4A64: inc word ptr [bp-6h] */
		wLoc06 = (u16)(wLoc06 + 0x0001);
	}

l0C74_4AAC:
	/* 4AAC: dec word ptr [58B4h] ; mov byte ptr [bp-1h],0h ; jmp 4DA7h */
	LG16(0x58B4) = (u16)(LG16(0x58B4) - 0x0001);
	bLoc01 = 0x00;
	goto l0C74_4DA7;

l0C74_4AB7:
	/* 4AB7: push 1F4h ; call 02D8h */
	(void)engine_clock_tick(0x01F4, &dsTmp);
	/* 4ABD: wLoc0A = [58B8h]+12h ; wLoc0C = [58B8h]+14h */
	wLoc0A = (u16)(LG16(0x58B8) + 0x0012);
	wLoc0C = (u16)(LG16(0x58B8) + 0x0014);

	/* l0C74_4ACF: grow the two cached bars one column per 28h tick until
	 * the edge probe fires or the bar X reaches 1DEh. */
	for (;;)
	{
		/* 4ACF: 1E3C(wLoc0C, [58B4h]-0Eh) ; jnz 4B36h */
		if (bgi_draw_line(wLoc0C, (u16)(LG16(0x58B4) - 0x000E),
		                &dlTmp) != 0x00)
			break;
		/* 4AE2: cmp word ptr [bp-0Ch],1DEh ; jnc 4B36h */
		if (wLoc0C >= 0x01DE)
			break;
		/* 4AE9: push 0Ch ; call far 1AB8h:1C32h */
		(void)bgi_get_text_cursor_attributes(0x0C);
		/* 4AF0: 1AF6(wLoc0C, [58B4h]-0Fh, wLoc0C, [58B4h]-0Bh) */
		(void)bgi_set_pixel(wLoc0C,
		                  (u16)(LG16(0x58B4) - 0x000F),
		                  wLoc0C,
		                  (u16)(LG16(0x58B4) - 0x000B),
		                  &dxTmp);
		/* 4B09: push 0h ; call far 1AB8h:1C32h */
		(void)bgi_get_text_cursor_attributes(0x00);
		/* 4B10: 1AF6(wLoc0A, [58B4h]-0Fh, wLoc0A, [58B4h]-0Bh) */
		(void)bgi_set_pixel(wLoc0A,
		                  (u16)(LG16(0x58B4) - 0x000F),
		                  wLoc0A,
		                  (u16)(LG16(0x58B4) - 0x000B),
		                  &dxTmp);
		/* 4B29: push 28h ; call 02D8h */
		(void)engine_clock_tick(0x0028, &dsTmp);
		/* 4B2E: inc [bp-0Ah] ; inc [bp-0Ch] ; jmp 4ACFh */
		wLoc0A = (u16)(wLoc0A + 0x0001);
		wLoc0C = (u16)(wLoc0C + 0x0001);
	}

	/* l0C74_4B36: derive the [596Ch..5972h] rectangle. */
	/* 4B36: [596Ch] = [58B4h]-2Dh ; [5970h] = [58B4h]-2 */
	LG16(0x596C) = (u16)(LG16(0x58B4) - 0x002D);
	LG16(0x5970) = (u16)(LG16(0x58B4) - 0x0002);
	/* 4B47: cmp word ptr [596Ch],1h ; jnl 4B54h */
	if ((s16)LG16(0x596C) < 0x0001)
		LG16(0x596C) = 0x0001;

	/* 4B54: mov ax,[bp-0Ch] ; cmp ax,[58BAh] ; jnc 4B6Bh */
	if (wLoc0C < LG16(0x58BA))
	{
		/* l0C74_4B5D */
		LG16(0x596E) = LG16(0x58B8);
		LG16(0x5972) = LG16(0x58BA);
	}
	else
	{
		/* l0C74_4B6B */
		LG16(0x596E) = (u16)(wLoc0C - 0x0016);
		LG16(0x5972) = (u16)(wLoc0C + 0x0015);
	}
	/* 4B7D: cmp word ptr [5972h],176h ; jng 4B91h */
	if ((s16)LG16(0x5972) > 0x0176)
	{
		/* l0C74_4B85 */
		LG16(0x5972) = 0x0176;
		LG16(0x596E) = 0x014A;
	}

	/* l0C74_4B91: four 1E3C probes refine the rectangle. */
	/* 4B91: 1E3C([5972h]-15h, [596Ch]) ; jnz 4BBBh */
	if (bgi_draw_line((u16)(LG16(0x5972) - 0x0015), LG16(0x596C),
	                &dlTmp) != 0x00)
		goto l0C74_4BBB;
	/* l0C74_4BA5: 1E3C([596Eh], [596Ch]) ; jnz 4BBBh */
	if (bgi_draw_line(LG16(0x596E), LG16(0x596C), &dlTmp) != 0x00)
		goto l0C74_4BBB;
	/* l0C74_4BB6: add word ptr [596Ch],16h */
	LG16(0x596C) = (u16)(LG16(0x596C) + 0x0016);

l0C74_4BBB:
	/* 4BBB: 1E3C([596Eh], [5970h]-15h) ; jnz 4BE8h */
	if (bgi_draw_line(LG16(0x596E), (u16)(LG16(0x5970) - 0x0015),
	                &dlTmp) != 0x00)
		goto l0C74_4BE8;
	/* l0C74_4BCF: 1E3C([596Eh], [5970h]-2Bh) ; jnz 4BE8h */
	if (bgi_draw_line(LG16(0x596E), (u16)(LG16(0x5970) - 0x002B),
	                &dlTmp) != 0x00)
		goto l0C74_4BE8;
	/* l0C74_4BE3: add word ptr [596Eh],12h */
	LG16(0x596E) = (u16)(LG16(0x596E) + 0x0012);

l0C74_4BE8:
	/* 4BE8: push 0Ch ; call far 1AB8h:1C32h */
	(void)bgi_get_text_cursor_attributes(0x0C);
	/* 4BEF: 1AF6(wLoc0A-1, [58B4h]-0Fh, wLoc0A-1, [58B4h]-0Bh) */
	(void)bgi_set_pixel((u16)(wLoc0A - 0x0001),
	                  (u16)(LG16(0x58B4) - 0x000F),
	                  (u16)(wLoc0A - 0x0001),
	                  (u16)(LG16(0x58B4) - 0x000B),
	                  &dxTmp);
	/* 4C0C: 1AF6(wLoc0A-2, [58B4h]-0Fh, wLoc0A-2, [58B4h]-0Bh) */
	(void)bgi_set_pixel((u16)(wLoc0A - 0x0002),
	                  (u16)(LG16(0x58B4) - 0x000F),
	                  (u16)(wLoc0A - 0x0002),
	                  (u16)(LG16(0x58B4) - 0x000B),
	                  &dxTmp);
	/* 4C2B: push 0h ; call far 1AB8h:1C32h */
	(void)bgi_get_text_cursor_attributes(0x00);
	/* 4C32: mov ax,[bp-4h] ; inc ax ; cmp ax,0Dh ; jg 4C88h */
	wLoc06 = (u16)(wLoc04 + 0x0001);
	if ((s16)wLoc06 > 0x000D)
		goto l0C74_4C88;
	/* l0C74_4C3B: erase the drawn column back down. */
	for (;;)
	{
		/* l0C74_4C43: 1AF6([58B8h]+13h, wLoc06+[58B4h],
		 *                   [58B8h]+12h, wLoc06+[58B4h]) */
		(void)bgi_set_pixel((u16)(LG16(0x58B8) + 0x0013),
		                  (u16)(wLoc06 + LG16(0x58B4)),
		                  (u16)(LG16(0x58B8) + 0x0012),
		                  (u16)(wLoc06 + LG16(0x58B4)),
		                  &dxTmp);
		/* 4C7A: push 12Ch ; push 14h ; call 070Dh */
		(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
		/* 4C82: cmp word ptr [bp-6h],0Dh ; jnz 4C40h */
		if (wLoc06 == 0x000D)
			break;
		/* l0C74_4C40: inc word ptr [bp-6h] */
		wLoc06 = (u16)(wLoc06 + 0x0001);
	}

l0C74_4C88:
	/* 4C88: dec word ptr [58B4h] ; xor ax,ax ; mov [bp-4h],ax ;
	 *       mov word ptr [bp-8h],1h ; mov word ptr [bp-6h],1h */
	LG16(0x58B4) = (u16)(LG16(0x58B4) - 0x0001);
	wLoc04 = 0x0000;
	wLoc08 = 0x0001;
	wLoc06 = 0x0001;

l0C74_4CA0:
	/* l0C74_4CA0: pull the bar down.  Each pass ticks 070D/02D8, cycles
	 * the animation counter 5..1 (11C8 sound), nudges [58B4h]/[58B6h],
	 * probes three edges and blits the 58F4h sprite when the third fires,
	 * then walks wLoc06 up from 1 to 2Ch. */
	for (;;)
	{
		/* 4CA0: push 12Ch ; push 14h ; call 070Dh */
		(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
		/* 4CA8: push 0Ah ; call 02D8h */
		(void)engine_clock_tick(0x000A, &dsTmp);
		/* 4CAD: inc word ptr [bp-4h] ; cmp [bp-4h],5h ; jnz 4CCBh */
		wLoc04 = (u16)(wLoc04 + 0x0001);
		if (wLoc04 == 0x0005)
		{
			/* l0C74_4CB6: mov word ptr [bp-4h],1h */
			wLoc04 = 0x0001;
			/* 4CBB: cmp byte ptr [58B0h],0h ; jz 4CC9h */
			if (LG8(0x58B0) == 0x00)
				goto l0C74_4CD0;
			/* l0C74_4CC2: push 32h ; call far 11C8h:0354h */
			fn11C8_0354(0x0032);
			goto l0C74_4CD0;
		}
		/* l0C74_4CCB: call far 11C8h:033Bh */
		(void)fn11C8_033B();

	l0C74_4CD0:
		/* 4CD0: cmp word ptr [58B6h],27Fh ; jnc 4CE3h */
		if (LG16(0x58B6) < 0x027F)
		{
			/* l0C74_4CD8 */
			LG16(0x58B4) = (u16)(LG16(0x58B4) + 0x0001);
			LG16(0x58B6) = (u16)(LG16(0x58B6) + 0x0001);
			wLoc08 = (u16)(wLoc08 + 0x0001);
		}

		/* 4CE3: cmp word ptr [58B6h],27Fh ; jnc 4D22h, then the three
		 * 1E3C edge probes (4CEB / 4CFC / 4D10). */
		if (LG16(0x58B6) < 0x027F &&
		    bgi_draw_line(LG16(0x58BA), LG16(0x58B6), &dlTmp) == 0x00 &&
		    bgi_draw_line((u16)(LG16(0x58BA) - 0x0015), LG16(0x58B6),
		                &dlTmp) == 0x00)
		{
			/* 4D10: 1E3C([58BAh]+1h, [58B6h]) ; jnz 4D34h */
			if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001), LG16(0x58B6),
			                &dlTmp) != 0x00)
			{
				/* l0C74_4D34: les di,[wLoc04*4 + 58F4h] ;
				 *             push es/di ; push [58B8h] ;
				 *             push [58B4h] ; call 13D7h */
				(void)bgi_signed_rectangle_intersect(0x00,
				    far_ptr(LG32((u16)(0x58F4 +
				                                (u16)(wLoc04 << 2)))),
				    LG16(0x58B8), LG16(0x58B4));
				goto l0C74_4D4F;
			}
			goto l0C74_4D22;
		}
		goto l0C74_4D22;

	l0C74_4D22:
		/* l0C74_4D22: dec [58B4h] ; dec [58B6h] ; dec [bp-8h] ;
		 *             call far 11C8h:033Bh ; jmp 4D4Fh */
		LG16(0x58B4) = (u16)(LG16(0x58B4) - 0x0001);
		LG16(0x58B6) = (u16)(LG16(0x58B6) - 0x0001);
		wLoc08 = (u16)(wLoc08 - 0x0001);
		(void)fn11C8_033B();

	l0C74_4D4F:
		/* 4D4F: cmp word ptr [bp-6h],2Ch ; jz 4D58h */
		if (wLoc06 != 0x002C)
		{
			/* l0C74_4D55: jmp 4C9Dh */
			/* l0C74_4C9D: inc word ptr [bp-6h] ; jmp 4CA0h */
			wLoc06 = (u16)(wLoc06 + 0x0001);
			goto l0C74_4CA0;
		}
		/* 4D58: cmp word ptr [bp-8h],16h ; jnl 4D93h */
		if (wLoc08 < 0x0016)
		{
			/* l0C74_4D5E: signed DX:AX compare.
			 *   cx = [58BAh]+17h (zero-extended), dx:ax = cwd([5972h]);
			 *   block taken when (s32)[5972h] <= (s32)cx. */
			u16 cx = (u16)(LG16(0x58BA) + 0x0017);

			if ((s32)(s16)LG16(0x5972) <= (s32)cx)
			{
				/* l0C74_4D78: 076B([58BAh], [58B6h],
				 *                   [596Eh], [596Ch]) */
				(void)engine_scatter_starfield(LG16(0x58BA), LG16(0x58B6),
				                  LG16(0x596E), LG16(0x596C));
				/* 4D8C: mov byte ptr [58B3h],1h */
				LG8(0x58B3) = 0x01;
				goto l0C74_4DA7;
			}
		}
		/* l0C74_4D93: 076B([5972h], [5970h], [596Eh], [596Ch]) */
		(void)engine_scatter_starfield(LG16(0x5972), LG16(0x5970),
		                  LG16(0x596E), LG16(0x596C));
		goto l0C74_4DA7;
	}

l0C74_4DA7:
	/* l0C74_4DA7: mov al,[bp-1h] ; leave ; ret.
	 * BP / DS are register artifacts; the flat model writes 0. */
	*(u16 *)bpOut = 0x0000;
	*dsOut = 0x0000;
	return bLoc01;
}
