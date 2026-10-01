/* seg0C74_part13.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 13 of N: function 0C74:45CE only.
 *
 *   45CE
 *
 * Literal recovery from analysis/slices/0C74/0C74_45CE.asm (ground truth) and
 * the Reko slice 0C74_45CE.c; frozen prototype from src/seg0C74.h
 * (analysis/summary/iface.tsv) adopted exactly:
 *
 *   u8 engine_starfield_pull_in(void *bpOut, u16 *dsOut)
 *
 * See CONVENTIONS.md, analysis/SEGMAP.md and docs/notes-0C74.md ("## part 13").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   NONE directly.  No int 10h / int 16h / int 21h, no raw `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch occur in
 *   45CE.  Every hardware-touching action is reached indirectly through
 *   already-ported callees: the 1AB8 video/text driver (10F4/1AF6/1C32/1E3C/
 *   13D7) and the 0C74 tick/frame drivers 070D / 02D8, plus the 11C8 sound
 *   helpers 0354/033B.
 *
 * Flat-model / ABI adaptations (recorded in docs/notes-0C74.md "## part 13"):
 *   - Reko's bp_XXXX frame-pointer locals (re-bound after each engine_scale_and_tick_clock /
 *     02D8 call whose AX return is the caller's saved BP) are this function's
 *     own frame; they are folded back onto the literal [bp-Nh] locals below,
 *     per the part 1 section 3 convention.
 *   - The far-pointer table at DGROUP:0x58E4 (4 bytes per entry) is read as a
 *     single u32 and cast to a host pointer, matching parts 2/8/9.
 *   - bpOut / dsOut register outputs are the caller's saved BP and the dropped
 *     DGROUP selector; both receive 0 (part 1 section 3).
 *   - The `1AF6` dxOut and `1E3C` dlOut register outputs are unused by the
 *     original; scratch locals are passed.
 */

#include <stddef.h>
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C74.h"
#include "seg1AB8.h"
#include "seg11C8.h"

/* 0C74:45CE: u8 engine_starfield_pull_in(void * bpOut, u16 * dsOut)
 *
 * Game-core "starfield pull-in" update (sibling of 396E).  Decrements [58B4h]
 * and first scans a row upward (drawing a 13h/12h rectangle each step through
 * 1AF6) until either the row reaches 3Ah, a 1E3C edge probe fires, or the row
 * passes 27Eh.  If the row did not reach 3Ah it erases the drawn column back
 * down and clears the [bp-1] flag.  If it did reach 3Ah it runs the collision
 * sequence: grow two cached bars (1AF6 strokes) from [58B8h]+12h/+14h while
 * the edge probe is clear, derive the [596Ch..5972h] rectangle from [58B6h]
 * and [58B8h] with four more 1E3C probes, lay down the two 1AF6 strokes at the
 * bar origin-1/-2, erase the column back down, then pull the bar down 2Ch rows
 * (each pass ticking 070D/02D8, advancing the animation counter, probing three
 * edges and blitting the DGROUP:58E4h sprite) and finally call engine_scatter_starfield
 * with either the live or the cached rectangle depending on a signed edge
 * compare.  Returns the [bp-1] byte. */
u8 engine_starfield_pull_in /* was fn0C74_45CE */(void *bpOut, u16 *dsOut)
{
	u8  bLoc01 = 0x01;      /* [bp-01h] return flag (45CE: mov [bp-1h],1h) */
	u8  bLoc02 = 0x1D;      /* [bp-02h] scan row / animation counter, init 1Dh */
	u8  bLoc03 = 0x00;      /* [bp-03h] erase/column loop counter */
	u8  bLoc04 = 0x00;      /* [bp-04h] bar height counter */
	u16 wLoc06 = 0x0000;    /* [bp-06h] bar X origin ([58B8h]+12h) */
	u16 wLoc08 = 0x0000;    /* [bp-08h] bar X origin 2 ([58B8h]+14h) */
	u8  dlTmp  = 0x00;      /* bgi_draw_line dlOut */
	u16 dxTmp  = 0x0000;    /* bgi_set_pixel dxOut */
	u16 dsTmp  = 0x0000;    /* engine_clock_tick dsOut */
	void *dsv  = NULL;      /* engine_scale_and_tick_clock dsOut */

	/* 45D2: mov byte ptr [bp-1h],1h  (bLoc01 initialiser) */
	/* 45D6: dec word ptr [58B4h] */
	LG16(0x58B4) = (u16)(LG16(0x58B4) - 0x0001);
	/* 45DA: push 0h ; push 0h ; push 1h ; call far 1AB8h:10F4h */
	bgi_set_text_background_color(0x0001, 0x0000, 0x0000);
	/* 45E5: push 0Ch ; call far 1AB8h:1C32h */
	(void)bgi_get_text_cursor_attributes(0x0C);
	/* 45EC: mov byte ptr [bp-2h],1Dh */
	bLoc02 = 0x1D;

	/* l0C74_45F0: scan rows while the probe is empty and the row stays
	 * below 27Eh; stop early when the row hits 3Ah. */
	do
	{
		/* 45F0: bgi_set_pixel([58B8h]+13h, bLoc02+[58B4h],
		 *                   [58B8h]+12h, bLoc02+[58B4h]) */
		(void)bgi_set_pixel((u16)(LG16(0x58B8) + 0x0013),
		                  (u16)((u16)bLoc02 + LG16(0x58B4)),
		                  (u16)(LG16(0x58B8) + 0x0012),
		                  (u16)((u16)bLoc02 + LG16(0x58B4)),
		                  &dxTmp);
		/* 4617: inc byte ptr [bp-2h] */
		bLoc02 = (u8)(bLoc02 + 0x01);
		/* 461A: push 12Ch ; push 14h ; call 070Dh */
		(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
		/* 4622: cmp byte ptr [bp-2h],3Ah ; jz 4650h */
		if (bLoc02 == 0x3A)
			break;
		/* 4628: bgi_draw_line([58B8h]+13h, bLoc02+[58B4h]) ; jnz 4650h */
		if (bgi_draw_line((u16)(LG16(0x58B8) + 0x0013),
		                (u16)((u16)bLoc02 + LG16(0x58B4)),
		                &dlTmp) != 0)
			break;
		/* 4642: cmp (bLoc02+[58B4h]),27Eh ; jc 45F0h */
	} while ((u16)((u16)bLoc02 + LG16(0x58B4)) < 0x027E);

	/* l0C74_4650: cmp byte ptr [bp-2h],3Ah ; jz 46AFh */
	if (bLoc02 != 0x3A)
	{
		/* l0C74_4656: push 0h ; call far 1AB8h:1C32h */
		(void)bgi_get_text_cursor_attributes(0x00);
		/* 465D: mov al,[bp-2h] ; xor ah,ah ; dec ax ; cmp al,1Dh ;
		 *       jc 46A4h */
		if ((u8)(bLoc02 - 0x01) >= 0x1D)
		{
			/* l0C74_4667: mov [bp-3h],al */
			bLoc03 = (u8)(bLoc02 - 0x01);
			for (;;)
			{
				/* l0C74_466F: erase the drawn column back down. */
				(void)bgi_set_pixel((u16)(LG16(0x58B8) + 0x0013),
				                  (u16)((u16)bLoc03 + LG16(0x58B4)),
				                  (u16)(LG16(0x58B8) + 0x0012),
				                  (u16)((u16)bLoc03 + LG16(0x58B4)),
				                  &dxTmp);
				(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
				/* 469E: cmp byte ptr [bp-3h],1Dh ; jnz 466Ch */
				if (bLoc03 == 0x1D)
					break;
				/* l0C74_466C: dec byte ptr [bp-3h] */
				bLoc03 = (u8)(bLoc03 - 0x01);
			}
		}
		/* l0C74_46A4: inc word ptr [58B4h] ; mov byte ptr [bp-1h],0h */
		LG16(0x58B4) = (u16)(LG16(0x58B4) + 0x0001);
		bLoc01 = 0x00;
		goto l0C74_4994;
	}

	/* ---- bLoc02 == 3Ah: the collision / starfield sequence ---- */

	/* l0C74_46AF: push 1F4h ; call 02D8h */
	(void)engine_clock_tick(0x01F4, &dsTmp);
	/* 46B5: mov [bp-6h],[58B8h]+12h ; mov [bp-8h],[58B8h]+14h */
	wLoc06 = (u16)(LG16(0x58B8) + 0x0012);
	wLoc08 = (u16)(LG16(0x58B8) + 0x0014);

	/* l0C74_46C7: grow the two cached bars one column per 1Eh tick until
	 * the edge probe fires or the row reaches 1DEh. */
	for (;;)
	{
		/* 46C7: bgi_draw_line(wLoc08, [58B4h]+39h) ; jnz 472Eh */
		if (bgi_draw_line(wLoc08, (u16)(LG16(0x58B4) + 0x0039),
		                &dlTmp) != 0)
			break;
		/* 46DA: cmp word ptr [bp-8h],1DEh ; jnc 472Eh */
		if (wLoc08 >= 0x01DE)
			break;
		/* 46E1: push 0Ch ; call far 1AB8h:1C32h */
		(void)bgi_get_text_cursor_attributes(0x0C);
		/* 46E8: 1AF6(wLoc08, [58B4h]+3Ah, wLoc08, [58B4h]+36h) */
		(void)bgi_set_pixel(wLoc08,
		                  (u16)(LG16(0x58B4) + 0x003A),
		                  wLoc08,
		                  (u16)(LG16(0x58B4) + 0x0036),
		                  &dxTmp);
		/* 4701: push 0h ; call far 1AB8h:1C32h */
		(void)bgi_get_text_cursor_attributes(0x00);
		/* 471C: 1AF6(wLoc06, [58B4h]+3Ah, wLoc06, [58B4h]+36h) */
		(void)bgi_set_pixel(wLoc06,
		                  (u16)(LG16(0x58B4) + 0x003A),
		                  wLoc06,
		                  (u16)(LG16(0x58B4) + 0x0036),
		                  &dxTmp);
		/* 4721: push 1Eh ; call 02D8h */
		(void)engine_clock_tick(0x001E, &dsTmp);
		/* 4726: inc word ptr [bp-6h] ; inc word ptr [bp-8h] ; jmp 46C7h */
		wLoc06 = (u16)(wLoc06 + 0x0001);
		wLoc08 = (u16)(wLoc08 + 0x0001);
	}

	/* l0C74_472E: derive the [596Ch..5972h] rectangle. */
	LG16(0x596C) = (u16)(LG16(0x58B6) + 0x0001);
	LG16(0x5970) = (u16)(LG16(0x58B6) + 0x002C);
	if (LG16(0x5970) > 0x027E)
		LG16(0x5970) = 0x027E;

	/* l0C74_474C: mov ax,[bp-8h] ; cmp ax,[58BAh] ; jnc 4763h */
	if (wLoc08 < LG16(0x58BA))
	{
		/* l0C74_4755 */
		LG16(0x596E) = LG16(0x58B8);
		LG16(0x5972) = LG16(0x58BA);
	}
	else
	{
		/* l0C74_4763 */
		LG16(0x596E) = (u16)(wLoc08 - 0x0016);
		LG16(0x5972) = (u16)(wLoc08 + 0x0015);
	}

	/* l0C74_4775: cmp word ptr [5972h],176h ; jle 4789h */
	if (LG16(0x5972) > 0x0176)
	{
		/* l0C74_477D */
		LG16(0x5972) = 0x0176;
		LG16(0x596E) = 0x014A;
	}

	/* l0C74_4789: 1E3C([5972h]-15h, [5970h]-15h) ; jnz 47BCh */
	if (bgi_draw_line((u16)(LG16(0x5972) - 0x0015),
	                (u16)(LG16(0x5970) - 0x0015), &dlTmp) != 0)
		goto l0C74_47BC;
	/* l0C74_47A0: 1E3C([5972h]-2Bh, [5970h]-15h) ; jnz 47BCh */
	if (bgi_draw_line((u16)(LG16(0x5972) - 0x002B),
	                (u16)(LG16(0x5970) - 0x0015), &dlTmp) != 0)
		goto l0C74_47BC;
	/* l0C74_47B7: sub word ptr [5970h],16h */
	LG16(0x5970) = (u16)(LG16(0x5970) - 0x0016);

l0C74_47BC:
	/* 47BC: 1E3C([596Eh], [596Ch]+16h) ; jnz 47E6h */
	if (bgi_draw_line(LG16(0x596E),
	                (u16)(LG16(0x596C) + 0x0016), &dlTmp) != 0)
		goto l0C74_47E6;
	/* 47D0: 1E3C([596Eh], [596Ch]) ; jnz 47E6h */
	if (bgi_draw_line(LG16(0x596E), LG16(0x596C), &dlTmp) != 0)
		goto l0C74_47E6;
	/* l0C74_47E1: add word ptr [596Eh],12h */
	LG16(0x596E) = (u16)(LG16(0x596E) + 0x0012);

l0C74_47E6:
	/* 47E6: push 0Ch ; call far 1AB8h:1C32h */
	(void)bgi_get_text_cursor_attributes(0x0C);
	/* 47ED: 1AF6(wLoc06-1, [58B4h]+3Ah, wLoc06-1, [58B4h]+36h) */
	(void)bgi_set_pixel((u16)(wLoc06 - 0x0001),
	                  (u16)(LG16(0x58B4) + 0x003A),
	                  (u16)(wLoc06 - 0x0001),
	                  (u16)(LG16(0x58B4) + 0x0036),
	                  &dxTmp);
	/* 480A: 1AF6(wLoc06-2, [58B4h]+3Ah, wLoc06-2, [58B4h]+36h) */
	(void)bgi_set_pixel((u16)(wLoc06 - 0x0002),
	                  (u16)(LG16(0x58B4) + 0x003A),
	                  (u16)(wLoc06 - 0x0002),
	                  (u16)(LG16(0x58B4) + 0x0036),
	                  &dxTmp);
	/* 4829: push 0h ; call far 1AB8h:1C32h */
	(void)bgi_get_text_cursor_attributes(0x00);
	/* 4830: mov al,[bp-2h] ; xor ah,ah ; dec ax ; cmp al,1Dh ; jc 4877h */
	if ((u8)(bLoc02 - 0x01) >= 0x1D)
	{
		/* l0C74_483A: mov [bp-3h],al */
		bLoc03 = (u8)(bLoc02 - 0x01);
		for (;;)
		{
			/* l0C74_4842: erase the drawn column back down. */
			(void)bgi_set_pixel((u16)(LG16(0x58B8) + 0x0013),
			                  (u16)((u16)bLoc03 + LG16(0x58B4)),
			                  (u16)(LG16(0x58B8) + 0x0012),
			                  (u16)((u16)bLoc03 + LG16(0x58B4)),
			                  &dxTmp);
			(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
			/* 4871: cmp byte ptr [bp-3h],1Dh ; jnz 483Fh */
			if (bLoc03 == 0x1D)
				break;
			/* l0C74_483F: dec byte ptr [bp-3h] */
			bLoc03 = (u8)(bLoc03 - 0x01);
		}
	}

	/* l0C74_4877: inc word ptr [58B4h] ;
	 *             mov [bp-2h],5h ; mov [bp-4h],1h ; mov [bp-3h],1h */
	LG16(0x58B4) = (u16)(LG16(0x58B4) + 0x0001);
	bLoc02 = 0x05;
	bLoc04 = 0x01;
	bLoc03 = 0x01;

	/* l0C74_488C: pull the bar down.  Each pass ticks 070D/02D8, cycles
	 * the animation counter 5..1 (11C8 sound), nudges [58B4h]/[58B6h],
	 * probes three edges and blits the 58E4h sprite when they are clear,
	 * then walks bLoc03 up from 1 to 2Ch. */
	for (;;)
	{
		/* 488C: push 12Ch ; push 14h ; call 070Dh */
		(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
		/* 4894: push 0Ah ; call 02D8h */
		(void)engine_clock_tick(0x000A, &dsTmp);
		/* 4899: dec byte ptr [bp-2h] ; cmp [bp-2h],0h ; jnz 48B6h */
		bLoc02 = (u8)(bLoc02 - 0x01);
		if (bLoc02 == 0x00)
		{
			/* l0C74_48A2: mov byte ptr [bp-2h],4h */
			bLoc02 = 0x04;
			/* 48A6: cmp byte ptr [58B0h],0h ; jz 48B4h */
			if (LG8(0x58B0) != 0x00)
				fn11C8_0354(0x0032);
		}
		else
		{
			/* l0C74_48B6 */
			(void)fn11C8_033B();
		}

		/* l0C74_48BB: cmp word ptr [58B4h],0h ; jbe 48CDh */
		if (LG16(0x58B4) > 0x0000)
		{
			/* l0C74_48C2 */
			bLoc04 = (u8)(bLoc04 + 0x01);
			LG16(0x58B4) = (u16)(LG16(0x58B4) - 0x0001);
			LG16(0x58B6) = (u16)(LG16(0x58B6) - 0x0001);
		}

		/* l0C74_48CD: cmp word ptr [58B6h],0h ; jbe 490Bh, then the
		 * three 1E3C edge probes (48D4 / 48E5 / 48F9). */
		if (LG16(0x58B6) > 0x0000 &&
		    bgi_draw_line(LG16(0x58BA), LG16(0x58B4), &dlTmp) == 0x00 &&
		    bgi_draw_line((u16)(LG16(0x58BA) - 0x0015), LG16(0x58B4),
		                &dlTmp) == 0x00 &&
		    bgi_draw_line((u16)(LG16(0x58BA) + 0x0001), LG16(0x58B4),
		                &dlTmp) != 0x00)
		{
			/* l0C74_491D: les di,[58E4h + bLoc02*4] ; push es/di ;
			 *             push [58B8h] ; push [58B4h] ; call 13D7h */
			(void)bgi_signed_rectangle_intersect(0x00,
			    far_ptr(LG32((u16)(0x58E4 +
			                                (u16)((u16)bLoc02 << 2)))),
			    LG16(0x58B8), LG16(0x58B4));
		}
		else
		{
			/* l0C74_490B: dec [bp-4h] ; inc [58B4h] ; inc [58B6h] ;
			 *              call 11C8h:033Bh */
			bLoc04 = (u8)(bLoc04 - 0x01);
			LG16(0x58B4) = (u16)(LG16(0x58B4) + 0x0001);
			LG16(0x58B6) = (u16)(LG16(0x58B6) + 0x0001);
			(void)fn11C8_033B();
		}

		/* l0C74_493C: cmp byte ptr [bp-3h],2Ch ; jz 4945h */
		if (bLoc03 == 0x2C)
			break;
		/* l0C74_4889: inc byte ptr [bp-3h] ; jmp 488Ch */
		bLoc03 = (u8)(bLoc03 + 0x01);
	}

	/* l0C74_4945: cmp byte ptr [bp-4h],16h ; jnc 4980h */
	if (bLoc04 < 0x16)
	{
		/* l0C74_494B: signed DX:AX compare.
		 *   cx = [58BAh]+17h (zero-extended), dx:ax = cwd([5972h]);
		 *   block taken when (s32)[5972h] <= (s32)cx. */
		u16 cx = (u16)(LG16(0x58BA) + 0x0017);

		if ((s32)(s16)LG16(0x5972) <= (s32)cx)
		{
			/* l0C74_4965: 076B([5972h],[5970h],[58B8h],[58B4h]) */
			(void)engine_scatter_starfield(LG16(0x5972), LG16(0x5970),
			                  LG16(0x58B8), LG16(0x58B4));
			/* 4979: mov byte ptr [58B3h],1h */
			LG8(0x58B3) = 0x01;
			goto l0C74_4994;
		}
	}

	/* l0C74_4980: 076B([5972h],[5970h],[596Eh],[596Ch]) */
	(void)engine_scatter_starfield(LG16(0x5972), LG16(0x5970),
	                  LG16(0x596E), LG16(0x596C));

l0C74_4994:
	/* l0C74_4994: mov al,[bp-1h] ; leave ; ret.
	 * BP / DS are register artifacts; the flat model writes 0. */
	*(u16 *)bpOut = 0x0000;
	*dsOut = 0x0000;
	return bLoc01;
}
