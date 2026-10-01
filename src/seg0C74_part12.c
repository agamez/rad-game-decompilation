/* seg0C74_part12.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 12 of N: function 0C74:3F74.
 *
 *   3F74
 *
 * Literal recovery from analysis/slices/0C74/0C74_3F74.asm (ground truth),
 * the Reko slice 0C74_3F74.c and analysis/reko/RAD_0C74.dis; frozen prototype
 * from src/seg0C74.h (analysis/summary/iface.tsv) adopted exactly:
 *
 *   u8 engine_reel_bar_pull(void * bpOut, u16 * dsOut)
 *
 * See CONVENTIONS.md, analysis/SEGMAP.md and docs/notes-0C74.md ("## part 12").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   NONE directly.  No int 10h / int 16h / int 21h, no raw `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch occur in
 *   3F74.  Every hardware-touching action is reached through already-ported
 *   callees: the 1AB8 video driver (10F4/1C32/1AF6/1E3C/1E54) and the 0C74
 *   helpers 070D / 02D8 (parts 1/2).  070D/02D8 in turn reach the 11C8 sound
 *   helpers (PC-speaker / AdLib), all guarded by DGROUP 0x58B0.
 *
 * Flat-model / ABI adaptations (recorded in docs/notes-0C74.md "## part 12"):
 *   - Reko's bp_XXXX frame-pointer locals (re-bound after every engine_scale_and_tick_clock /
 *     02D8 call whose AX/far return is the caller's saved BP) are the current
 *     function's own frame; they are folded back onto the literal stack locals
 *     below, per the part 1 section 3 convention.
 *   - The line/point-pair calls 1AF6 draw the horizontal/vertical patches at
 *     (x=[58B8h]+k, y=[58B4h]+n) exactly as the original push order proves
 *     (last-pushed word is the first C argument).
 *   - bpOut (Reko's saved-BP word) / dsOut (dropped DGROUP selector) are
 *     register artifacts with no flat-C equivalent; both receive 0.
 */

#include <stddef.h>
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C74.h"
#include "seg1AB8.h"

/* Three-segment line patch.  The original reloads DI from [bp-06h] for every
 * table access, so the index expression is evaluated per table here too.
 * DGROUP tables (word tables are indexed doubled, byte tables raw):
 *   0x4D5E (word) -> y = [58B4h] - t16[i*2]
 *   0x4D87 (byte) -> x = [58B8h] + t87[i]
 *   0x4D9B (byte) -> y = [58B4h] - t9B[i]
 *   0x4DAF (byte) -> x = [58B8h] + tAF[i]
 * Fn1AB8_1AF6's four arguments follow the original push order reversed:
 *   ([58B8h]+tAF[i], [58B4h]-t9B[i], [58B8h]+t87[i], [58B4h]-t16[i*2]) */
#define PATCH3(idx) \
	(void)bgi_set_pixel( \
	    (u16)(LG16(0x58B8) + LG8((u16)(0x4DAF + (idx)))), \
	    (u16)(LG16(0x58B4) - LG8((u16)(0x4D9B + (idx)))), \
	    (u16)(LG16(0x58B8) + LG8((u16)(0x4D87 + (idx)))), \
	    (u16)(LG16(0x58B4) - LG16((u16)(0x4D5E + (u16)((idx) << 1)))), \
	    &dxTmp)

// 0C74:3F74: u8 engine_reel_bar_pull(void * bpOut, u16 * dsOut)
//
// Animated "reel/bar pull-in" update.  It bumps [58B4h] and walks a shrinking
// horizontal line down the playfield; on a failed edge probe or when the scan
// offset reaches -13 it switches to a full redraw: the bar is stamped with two
// vertical edge lines, then a run of table-driven three-segment patches marches
// (3..14h), followed by a four-stage patch/clock sequence, a 02D8(1F4h) wait,
// and a second table march (14h..3) plus a final shrink to the scan position.
// Returns the [bp-1] byte (0 = the "then" path ran; 1 otherwise).
u8 engine_reel_bar_pull /* was fn0C74_3F74 */(void *bpOut, u16 *dsOut)
{
	u8  bLoc01 = 0x00;      /* [bp-01h] result flag (Reko al_1365) */
	u16 wLoc04 = 0x0000;    /* [bp-04h] shrinking scan offset (starts 0Dh) */
	u16 wLoc06 = 0x0000;    /* [bp-06h] loop/index counter */
	u16 wLoc08 = 0x0000;    /* [bp-08h] left patch x */
	u16 wLoc0A = 0x0000;    /* [bp-0Ah] right patch x */
	u16 dsTmp = 0x0000;     /* reusable u16 dsOut for engine_clock_tick */
	void *dsv = NULL;       /* reusable void * dsOut for engine_scale_and_tick_clock */
	u16 dxTmp = 0x0000;     /* bgi_set_pixel dxOut */
	u8  dlTmp = 0x00;       /* bgi_draw_line dlOut */

	/* 3F76..3F90: flag, [58B4h]++, video latch, scan offset. */
	bLoc01 = 0x01;                                   /* mov [bp-1],1 */
	LG16(0x58B4) = (u16)(LG16(0x58B4) + 0x0001);     /* inc [58B4h] */
	bgi_set_text_background_color(0x0001, 0x0000, 0x0000);
	(void)bgi_get_text_cursor_attributes(0x0C);
	wLoc04 = 0x000D;                                 /* mov [bp-4h],0Dh */

	/* 3F97..4021: first scan loop. */
	for (;;)
	{
		/* l0C74_3F97: patch line at x=[58B8h]+12h/13h, y=[58B4h]+wLoc04. */
		bgi_set_pixel((u16)(LG16(0x58B8) + 0x0013),
		            (u16)(LG16(0x58B4) + wLoc04),
		            (u16)(LG16(0x58B8) + 0x0012),
		            (u16)(LG16(0x58B4) + wLoc04),
		            &dxTmp);
		/* 3FC5..3FD6: dec [bp-4h], tick 070D(14h,12Ch). */
		wLoc04 = (u16)(wLoc04 - 0x0001);
		(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
		if (wLoc04 == 0xFFF3)                        /* cmp [bp-4h],0FFF3h */
			break;

		/* l0C74_3FDF: edge probe at ([58B8h]+13h, [58B4h]+wLoc04). */
		if (bgi_draw_line((u16)(LG16(0x58B8) + 0x0013),
		                (u16)(LG16(0x58B4) + wLoc04),
		                &dlTmp) != 0x00)
			break;

		/* 4001..4021: 32-bit sign-extended ([58B4h] + wLoc04) test.
		 * cmp dx,0h ; jl 4024h ; jle 401Ch ; jmp 3F97h ;
		 * 401C: cmp ax,1h ; jbe 4024h ; jmp 3F97h. */
		{
			u32 v = (u32)LG16(0x58B4) + (u32)(s32)(s16)wLoc04;
			s16 vhi = (s16)(u16)(v >> 16);
			if (vhi < 0)
				break;
			if (vhi == 0 && (u16)v <= 0x0001)
				break;
		}
	}

	/* 4024: cmp [bp-4h],0FFF3h ; jz 4092h */
	if (wLoc04 != 0xFFF3)
	{
		/* l0C74_402A: "then" -- shrink to the scan position. */
		(void)bgi_get_text_cursor_attributes(0x00);
		{
			u16 ax = (u16)(wLoc04 + 0x0001);         /* 402E..4032 */
			if ((s16)ax <= 0x000D)                   /* cmp ax,0Dh ; jg 4087h */
			{
				wLoc06 = ax;                     /* l0C74_403A */
				for (;;)
				{
					/* l0C74_4042 */
					bgi_set_pixel((u16)(LG16(0x58B8) + 0x0013),
					            (u16)(LG16(0x58B4) + wLoc06),
					            (u16)(LG16(0x58B8) + 0x0012),
					            (u16)(LG16(0x58B4) + wLoc06),
					            &dxTmp);
					(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
					if (wLoc06 == 0x000D)    /* cmp [bp-6h],0Dh ; jnz 403Fh */
						break;
					wLoc06 = (u16)(wLoc06 + 0x0001); /* l0C74_403F */
				}
			}
		}
		/* l0C74_4087 */
		LG16(0x58B4) = (u16)(LG16(0x58B4) - 0x0001);
		bLoc01 = 0x00;
	}
	else
	{
		/* l0C74_4092: "else" -- full bar redraw. */
		(void)bgi_get_text_cursor_attributes(0x0A);
		bgi_set_pixel((u16)(LG16(0x58B8) + 0x0012),
		            (u16)(LG16(0x58B4) - 0x000B),
		            (u16)(LG16(0x58B8) + 0x0012),
		            (u16)(LG16(0x58B4) + 0x0001),
		            &dxTmp);
		(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
		bgi_set_pixel((u16)(LG16(0x58B8) + 0x0011),
		            (u16)(LG16(0x58B4) - 0x000B),
		            (u16)(LG16(0x58B8) + 0x0011),
		            (u16)(LG16(0x58B4) + 0x0001),
		            &dxTmp);
		(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);

		/* 40E6..4204: three table patches per step, wLoc06 = 3..14h. */
		wLoc06 = 0x0003;
		for (;;)
		{
			(void)bgi_get_text_cursor_attributes(0x00);
			PATCH3((u16)(wLoc06 - 0x0002));
			(void)bgi_get_text_cursor_attributes(0x0A);
			PATCH3(wLoc06);
			PATCH3((u16)(wLoc06 - 0x0001));
			(void)engine_scale_and_tick_clock(0x0032, 0x0190, &dsv);
			if (wLoc06 == 0x0014)            /* cmp [bp-6h],14h ; jz 420Ah */
				break;
			wLoc06 = (u16)(wLoc06 + 0x0001); /* l0C74_40EE */
		}

		/* l0C74_420A: edge stamp + horizontal patch, then wLoc08/wLoc0A. */
		(void)bgi_get_line_attributes(0x00, (u16)(LG16(0x58B8) + 0x0011),
		                  (u16)(LG16(0x58B4) - 0x000B));
		bgi_set_pixel((u16)(LG16(0x58B8) + 0x0010),
		            (u16)(LG16(0x58B4) - 0x000C),
		            (u16)(LG16(0x58B8) + 0x0006),
		            (u16)(LG16(0x58B4) - 0x000C),
		            &dxTmp);
		wLoc08 = (u16)(LG16(0x58B8) + 0x0006);   /* [bp-8h] */
		wLoc0A = (u16)(LG16(0x58B8) + 0x0014);   /* [bp-0Ah] */
		wLoc06 = 0x0001;
		for (;;)
		{
			/* l0C74_425C: two vertical patches + two edge stamps, step +1. */
			(void)bgi_get_text_cursor_attributes(0x00);
			bgi_set_pixel(wLoc08, (u16)(LG16(0x58B4) - 0x000D),
			            wLoc08, (u16)(LG16(0x58B4) - 0x000C), &dxTmp);
			(void)bgi_get_text_cursor_attributes(0x0A);
			bgi_set_pixel(wLoc0A, (u16)(LG16(0x58B4) - 0x000D),
			            wLoc0A, (u16)(LG16(0x58B4) - 0x000C), &dxTmp);
			(void)bgi_get_line_attributes(0x00, wLoc0A, (u16)(LG16(0x58B4) - 0x000B));
			(void)bgi_get_line_attributes(0x00, wLoc0A, (u16)(LG16(0x58B4) - 0x000E));
			wLoc08 = (u16)(wLoc08 + 0x0001);
			wLoc0A = (u16)(wLoc0A + 0x0001);
			(void)engine_scale_and_tick_clock(0x0064, 0x0064, &dsv);
			if (wLoc06 == 0x000B)            /* cmp [bp-6h],0Bh ; jnz 4259h */
				break;
			wLoc06 = (u16)(wLoc06 + 0x0001); /* l0C74_4259 */
		}

		/* l0C74_42D1: closing patch/clock, then wLoc08/wLoc0A reset. */
		(void)bgi_get_text_cursor_attributes(0x0A);
		bgi_set_pixel(wLoc0A, (u16)(LG16(0x58B4) - 0x000D),
		            wLoc0A, (u16)(LG16(0x58B4) - 0x000C), &dxTmp);
		(void)bgi_get_line_attributes(0x00, wLoc0A, (u16)(LG16(0x58B4) - 0x000B));
		(void)bgi_get_line_attributes(0x00, wLoc0A, (u16)(LG16(0x58B4) - 0x000E));
		(void)engine_clock_tick(0x01F4, &dsTmp);
		(void)bgi_get_text_cursor_attributes(0x00);
		bgi_set_pixel(wLoc0A, (u16)(LG16(0x58B4) - 0x000D),
		            wLoc0A, (u16)(LG16(0x58B4) - 0x000C), &dxTmp);
		wLoc08 = (u16)(LG16(0x58B8) + 0x0010);
		wLoc0A = (u16)(LG16(0x58B8) + 0x001E);
		wLoc06 = 0x0001;
		for (;;)
		{
			/* l0C74_4355: two vertical patches, step -1. */
			(void)bgi_get_text_cursor_attributes(0x0A);
			bgi_set_pixel(wLoc08, (u16)(LG16(0x58B4) - 0x000D),
			            wLoc08, (u16)(LG16(0x58B4) - 0x000C), &dxTmp);
			(void)bgi_get_text_cursor_attributes(0x00);
			bgi_set_pixel(wLoc0A, (u16)(LG16(0x58B4) - 0x000D),
			            wLoc0A, (u16)(LG16(0x58B4) - 0x000C), &dxTmp);
			wLoc08 = (u16)(wLoc08 - 0x0001);
			wLoc0A = (u16)(wLoc0A - 0x0001);
			(void)engine_scale_and_tick_clock(0x0064, 0x0064, &dsv);
			if (wLoc06 == 0x000B)            /* cmp [bp-6h],0Bh ; jnz 4352h */
				break;
			wLoc06 = (u16)(wLoc06 + 0x0001); /* l0C74_4352 */
		}

		/* l0C74_43A8: three table patches per step, wLoc06 = 14h..3. */
		wLoc06 = 0x0014;
		for (;;)
		{
			(void)bgi_get_text_cursor_attributes(0x00);
			PATCH3(wLoc06);
			(void)bgi_get_text_cursor_attributes(0x0A);
			PATCH3((u16)(wLoc06 - 0x0002));
			PATCH3((u16)(wLoc06 - 0x0001));
			(void)engine_scale_and_tick_clock(0x0032, 0x0190, &dsv);
			if (wLoc06 == 0x0003)            /* cmp [bp-6h],3h ; jz 44CBh */
				break;
			wLoc06 = (u16)(wLoc06 - 0x0001); /* l0C74_43AF */
		}

		/* l0C74_44CB: final edge stamps and patches. */
		(void)bgi_get_line_attributes(0x00, (u16)(LG16(0x58B8) + 0x0010),
		                  (u16)(LG16(0x58B4) - 0x000C));
		(void)bgi_get_text_cursor_attributes(0x0A);
		bgi_set_pixel((u16)(LG16(0x58B8) + 0x0011),
		            (u16)(LG16(0x58B4) - 0x000B),
		            (u16)(LG16(0x58B8) + 0x0011),
		            (u16)(LG16(0x58B4) + 0x0001), &dxTmp);
		(void)engine_clock_tick(0x01F4, &dsTmp);
		(void)bgi_get_text_cursor_attributes(0x00);
		bgi_set_pixel((u16)(LG16(0x58B8) + 0x0011),
		            (u16)(LG16(0x58B4) - 0x000B),
		            (u16)(LG16(0x58B8) + 0x0011),
		            (u16)(LG16(0x58B4) + 0x0001), &dxTmp);
		(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
		(void)bgi_get_text_cursor_attributes(0x0C);
		bgi_set_pixel((u16)(LG16(0x58B8) + 0x0012),
		            (u16)(LG16(0x58B4) - 0x000B),
		            (u16)(LG16(0x58B8) + 0x0012),
		            (u16)(LG16(0x58B4) + 0x0001), &dxTmp);
		(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);

		/* 45??: shrink loop from (wLoc04+1) up to 0Dh. */
		(void)bgi_get_text_cursor_attributes(0x00);
		{
			u16 ax = (u16)(wLoc04 + 0x0001);
			if ((s16)ax <= 0x000D)           /* cmp ax,0Dh ; jg 45C5h */
			{
				wLoc06 = ax;             /* l0C74_4578 */
				for (;;)
				{
					/* l0C74_4580 */
					bgi_set_pixel((u16)(LG16(0x58B8) + 0x0013),
					            (u16)(LG16(0x58B4) + wLoc06),
					            (u16)(LG16(0x58B8) + 0x0012),
					            (u16)(LG16(0x58B4) + wLoc06),
					            &dxTmp);
					(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
					if (wLoc06 == 0x000D)
						break;
					wLoc06 = (u16)(wLoc06 + 0x0001); /* l0C74_457D */
				}
			}
		}
		/* l0C74_45C5 */
		LG16(0x58B4) = (u16)(LG16(0x58B4) - 0x0001);
	}

	/* l0C74_45C9: mov al,[bp-1h] ; leave ; ret.  bpOut / dsOut are register
	 * artifacts with no flat-C equivalent; both receive 0 (part 1 section 3). */
	*(u16 *)bpOut = 0x0000;
	*dsOut = 0x0000;
	return bLoc01;
}
