/* seg0C74_part15.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 15 of N: functions 0C74:4DAC .. 0C74:51B2 (4 functions, ascending).
 *
 *   4DAC 4FD7 51AA 51B2
 *
 * Literal recovery from analysis/slices/0C74/0C74_<off>.asm (ground truth)
 * and the Reko slices 0C74_4DAC.c / 0C74_4FD7.c / 0C74_51AA.c /
 * 0C74_51B2.c; frozen prototypes from src/seg0C74.h
 * (analysis/summary/iface.tsv) adopted exactly:
 *
 *   u8  engine_column_cells_down(u16 *bpOut, u16 *dsOut)
 *   u8  engine_column_cells_up(u16 *bpOut, u16 *dsOut)
 *   u16 engine_call_rocket_trajectory(void)
 *   u16 engine_edge_collision_probe(void)
 *
 * See CONVENTIONS.md, analysis/SEGMAP.md and docs/notes-0C74.md ("## part 15").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   NONE directly.  No int 10h / int 16h / int 21h, no raw `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch occur in
 *   4DAC..51B2.  Every hardware-touching action is reached through
 *   already-ported callees: the 1AB8 video/text driver
 *   (13A3/13D7/1AF6/1C32/1E3C/1E54/1E6B) and the 1EDA far-heap helpers
 *   (023F/0254); 4DAC/4FD7 tick and delay through engine_scale_and_tick_clock / 02D8.
 *
 * Flat-model / ABI adaptations (recorded in docs/notes-0C74.md "## part 15"):
 *   - Reko's bp_XXXX frame-pointer locals (re-bound after each engine_scale_and_tick_clock /
 *     02D8 call whose AX return is the caller's saved BP) are the current
 *     function's own frame; they are folded back onto the literal locals,
 *     per the notes-0C74 part 1 section 3 convention.
 *   - The 16:16 far blocks returned by fn1EDA_023F are carried as u32
 *     (offset | segment<<16, low word at the lower address, matching the
 *     original [bp-0Ah]/[bp-0Ch] and [bp-08h]/[bp-0Ah] pairs) and
 *     materialised through far_ptr() at the call sites, the same
 *     convention as parts 2/3/4/6/7/8/9.
 *   - fn1EDA_023F / 0254 require leading stack words the original never pushes
 *     (far-return-address words read only on the fatal divide-by-zero
 *     dispatcher path); they are seeded 0 (parts 4/6/7/8/9).
 *   - bpOut / dsOut register outputs are the caller's saved BP and the dropped
 *     DGROUP selector; both receive 0 (part 1 section 3).
 *   - engine_call_rocket_trajectory is a one-line far wrapper around engine_rocket_trajectory; the dropped DS
 *     output receives a u16 scratch and the callee's AX return is forwarded.
 */

#include <stddef.h>
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C74.h"
#include "seg1AB8.h"
#include "seg1EDA.h"

// 0C74:4DAC: u8 engine_column_cells_down(u16 * bpOut, u16 * dsOut)
//
// Draw a column of three-character cells (0Ah/02h/08h) upward while the cell
// above stays on-screen: each step paints [58B8h]+12h/13h/14h at
// [58B4h]+[bp-4h], decrements the row counter and ticks 070Dh.  The walk stops
// when the counter reaches 0FFE9h (the `cmp ...,0E9h` imm8 sign-extended), when
// the 1E3C edge probe fires, or when the
// sign-extended 32-bit sum [bp-4h]+[58B4h] drops to 1 or below.  If the counter
// did not reach 0FFE9h an erase pass redraws the same column downward through
// 1AF6 and clears the [bp-1] flag; if it did, a scratch block is allocated with
// 13A3/023F, the 0Ah..08h markers are stamped, the block rows are blitted with
// 13D7 while the counter walks 12h..2Bh, freed with 0254 and the column erased
// downward again.  Returns the [bp-1] byte.
u8 engine_column_cells_down /* was fn0C74_4DAC */(u16 *bpOut, u16 *dsOut)
{
	u8  bLoc01 = 0x01;      /* [bp-01h] return flag; 4DAC: mov [bp-1h],1h */
	u16 wLoc04 = 0x000D;    /* [bp-04h] row counter; 4DAC: mov [bp-4h],0Dh */
	u16 wLoc06 = 0x0000;    /* [bp-06h] redraw/erase counter */
	u16 wLoc08 = 0x0000;    /* [bp-08h] 13A3 size of the scratch block */
	u32 blk    = 0;         /* [bp-0Ah]:[bp-0Ch] 023F block, low = [bp-0Ch] */
	u8  dlTmp  = 0x00;      /* bgi_draw_line dlOut */
	u16 dxTmp  = 0x0000;    /* bgi_set_pixel dxOut */
	u16 dsTmp  = 0x0000;    /* engine_scale_and_tick_clock / 02D8 / 023F / 0254 dsOut */
	void *dsv  = NULL;      /* engine_scale_and_tick_clock void * dsOut */

	/* l0C74_4DB9: paint the three marker cells and tick upward. */
	for (;;)
	{
		/* 4DB9: 1E54(0Ah, [58B8h]+12h, [bp-4h]+[58B4h]) */
		(void)bgi_get_line_attributes(0x0A, (u16)(LG16(0x58B8) + 0x0012),
		                  (u16)(wLoc04 + LG16(0x58B4)));
		/* 4DDD: 1E54(2h, [58B8h]+13h, [bp-4h]+[58B4h]) */
		(void)bgi_get_line_attributes(0x02, (u16)(LG16(0x58B8) + 0x0013),
		                  (u16)(wLoc04 + LG16(0x58B4)));
		/* 4E01: 1E54(8h, [58B8h]+14h, [bp-4h]+[58B4h]) */
		(void)bgi_get_line_attributes(0x08, (u16)(LG16(0x58B8) + 0x0014),
		                  (u16)(wLoc04 + LG16(0x58B4)));
		/* 4E25: dec word ptr [bp-4h] */
		wLoc04 = (u16)(wLoc04 - 0x0001);
		/* 4E28: push 12Ch ; push 14h ; call 070Dh */
		(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
		/* 4E2?: cmp word ptr [bp-4h],0E9h ; jz 4E6Fh.
		 * The imm8 0E9h is sign-extended to 0FFE9h (Reko `~0x16`), so
		 * the counter walks 0Dh..00h..0FFE9h (36 steps). */
		if (wLoc04 == 0xFFE9)
			break;
		/* l0C74_4E2A: 1E3C([58B8h]+13h, [bp-4h]+[58B4h]) ; jnz 4E6Fh */
		if (bgi_draw_line((u16)(LG16(0x58B8) + 0x0013),
		                (u16)(wLoc04 + LG16(0x58B4)), &dlTmp) != 0x00)
			break;
		/* l0C74_4E4C: 32-bit sign-extended [bp-4h] + zero-extended [58B4h].
		 * jl 4E6Fh on DX<0 ; jle 4E67h on DX==0 ; then cmp AX,1h ; jbe. */
		{
			s32 sum = (s32)(s16)wLoc04 + (s32)(u16)LG16(0x58B4);
			if (sum < 0)
				break;
			if (sum <= 0xFFFF)
			{
				if ((u16)sum <= 0x0001)
					break;
			}
		}
	}

	/* l0C74_4E6F: cmp word ptr [bp-4h],0E9h ; jz 4ED9h
	 * (sign-extended 0FFE9h, as above) */
	if (wLoc04 == 0xFFE9)
	{
		/* l0C74_4ED9: push 1F4h ; call 02D8h */
		(void)engine_clock_tick(0x01F4, &dsTmp);
		/* 4EDE: wLoc08 = 13A3([58B8h]+14h, [58B4h]-1,
		 *                       [58B8h]+11h, [58B4h]-16h) */
		wLoc08 = bgi_clamp_rectangle_coords((u16)(LG16(0x58B8) + 0x0014),
		                     (u16)(LG16(0x58B4) - 0x0001),
		                     (u16)(LG16(0x58B8) + 0x0011),
		                     (u16)(LG16(0x58B4) - 0x0016));
		/* 4F0C: push wLoc08 ; call far 1EDAh:023Fh */
		blk = fn1EDA_023F(wLoc08, 0x0000, 0x0000, &dsTmp);
		/* 4F1D: 1E6B(blk, [58B8h]+14h, [58B4h]-1,
		 *             [58B8h]+11h, [58B4h]-16h) */
		bgi_draw_clip_rectangle((u8 *)far_ptr(blk),
		            (u16)(LG16(0x58B8) + 0x0014),
		            (u16)(LG16(0x58B4) - 0x0001),
		            (u16)(LG16(0x58B8) + 0x0011),
		            (u16)(LG16(0x58B4) - 0x0016));
		/* 4F4B: mov word ptr [bp-4h],12h */
		wLoc04 = 0x0012;

		/* l0C74_4F3D: blit the block row [bp-4h]+[58B8h]. */
		for (;;)
		{
			/* 4F3D: 13D7(0h, blk, [bp-4h]+[58B8h], [58B4h]-16h) */
			(void)bgi_signed_rectangle_intersect(0x00, (u8 *)far_ptr(blk),
			                  (u16)(wLoc04 + LG16(0x58B8)),
			                  (u16)(LG16(0x58B4) - 0x0016));
			/* 4F5C: push 12Ch ; push 14h ; call 070Dh */
			(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
			/* 4F64: push 28h ; call 02D8h */
			(void)engine_clock_tick(0x0028, &dsTmp);
			/* 4F6B: cmp word ptr [bp-4h],2Bh ; jnz 4F3Ah */
			if (wLoc04 == 0x002B)
				break;
			wLoc04 = (u16)(wLoc04 + 0x0001);   /* l0C74_4F3A */
		}

		/* l0C74_4F75: push [bp-0Ah] ; push [bp-0Ch] ; push [bp-8h] ;
		 *             call far 1EDAh:0254h */
		(void)renamed_1eda_0254(wLoc08, (u16)(blk & 0xFFFFu), (u16)(blk >> 16), 0, &dxTmp, &dsTmp);

		/* 4F80: mov word ptr [bp-6h],0FFEAh */
		wLoc06 = 0xFFEA;

		/* l0C74_4F8D: erase the column downward with 1AF6. */
		for (;;)
		{
			/* 4F8D: 1AF6([58B8h]+14h, [bp-6h]+[58B4h],
			 *            [58B8h]+12h, [bp-6h]+[58B4h]) */
			(void)bgi_set_pixel((u16)(LG16(0x58B8) + 0x0014),
			                  (u16)(wLoc06 + LG16(0x58B4)),
			                  (u16)(LG16(0x58B8) + 0x0012),
			                  (u16)(wLoc06 + LG16(0x58B4)),
			                  &dxTmp);
			/* 4FBC: push 12Ch ; push 14h ; call 070Dh */
			(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
			/* 4FC4: cmp word ptr [bp-6h],0Dh ; jnz 4F8Ah */
			if (wLoc06 == 0x000D)
				break;
			wLoc06 = (u16)(wLoc06 + 0x0001);   /* l0C74_4F8A */
		}
	}
	else
	{
		/* l0C74_4E75: push 0h ; call far 1AB8h:1C32h */
		(void)bgi_get_text_cursor_attributes(0x00);
		/* 4E7A: mov ax,[bp-4h] ; inc ax ; cmp ax,0Dh ; jg 4ED2h */
		wLoc06 = (u16)(wLoc04 + 0x0001);
		if ((s16)wLoc06 <= 0x000D)
		{
			/* l0C74_4E85..4E8D: erase the column downward. */
			for (;;)
			{
				/* 4E8D: 1AF6([58B8h]+14h, [bp-6h]+[58B4h],
				 *            [58B8h]+12h, [bp-6h]+[58B4h]) */
				(void)bgi_set_pixel((u16)(LG16(0x58B8) + 0x0014),
				                  (u16)(wLoc06 + LG16(0x58B4)),
				                  (u16)(LG16(0x58B8) + 0x0012),
				                  (u16)(wLoc06 + LG16(0x58B4)),
				                  &dxTmp);
				/* 4E??: push 12Ch ; push 14h ; call 070Dh */
				(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
				/* 4E??: cmp word ptr [bp-6h],0Dh ; jnz 4E8Ah */
				if (wLoc06 == 0x000D)
					break;
				wLoc06 = (u16)(wLoc06 + 0x0001);   /* l0C74_4E8A */
			}
		}
		/* l0C74_4ED2: mov byte ptr [bp-1h],0h */
		bLoc01 = 0x00;
	}

	/* l0C74_4FD2: mov al,[bp-1h] ; leave ; ret */
	*bpOut = 0x0000;
	*dsOut = 0x0000;
	return bLoc01;
}

// 0C74:4FD7: u8 engine_column_cells_up(u16 * bpOut, u16 * dsOut)
//
// Sibling of 4DAC for the opposite direction.  Draw a column of 0Ah/02h/08h
// cells upward at [58B8h]+12h/13h/14h while the row counter stays below 42h,
// the 1E3C edge probe is clear and the row [58B4h]+[bp-2h] stays under 27Eh,
// ticking 070Dh per step.  If the counter reached 42h a scratch block is
// allocated (13A3/023F), the markers are stamped and the block rows are blitted
// with 13D7 while the counter walks 12h..2Bh, freed with 0254 and the column
// erased downward (1AF6) from 2Ch to 1Dh.  Otherwise the column is erased
// downward and the [bp-1] flag cleared.  Returns the [bp-1] byte.
u8 engine_column_cells_up /* was fn0C74_4FD7 */(u16 *bpOut, u16 *dsOut)
{
	u8  bLoc01 = 0x01;      /* [bp-01h] return flag; 4FD7: mov [bp-1h],1h */
	u8  bLoc02 = 0x1D;      /* [bp-02h] scan counter; 4FD7: mov [bp-2h],1Dh */
	u8  bLoc03 = 0x00;      /* [bp-03h] erase counter */
	u16 wLoc06 = 0x0000;    /* [bp-06h] 13A3 size of the scratch block */
	u32 blk    = 0;         /* [bp-08h]:[bp-0Ah] 023F block, low = [bp-0Ah] */
	u8  dlTmp  = 0x00;      /* bgi_draw_line dlOut */
	u16 dxTmp  = 0x0000;    /* bgi_set_pixel dxOut */
	u16 dsTmp  = 0x0000;    /* engine_scale_and_tick_clock / 02D8 / 023F / 0254 dsOut */
	void *dsv  = NULL;      /* engine_scale_and_tick_clock void * dsOut */

	/* l0C74_4FE3: paint the marker cells and tick upward. */
	for (;;)
	{
		/* 4FE3: 1E54(0Ah, [58B8h]+12h, [bp-2h]+[58B4h]) */
		(void)bgi_get_line_attributes(0x0A, (u16)(LG16(0x58B8) + 0x0012),
		                  (u16)((u16)bLoc02 + LG16(0x58B4)));
		/* 5007: 1E54(2h, [58B8h]+13h, [bp-2h]+[58B4h]) */
		(void)bgi_get_line_attributes(0x02, (u16)(LG16(0x58B8) + 0x0013),
		                  (u16)((u16)bLoc02 + LG16(0x58B4)));
		/* 501D: 1E54(8h, [58B8h]+14h, [bp-2h]+[58B4h]) */
		(void)bgi_get_line_attributes(0x08, (u16)(LG16(0x58B8) + 0x0014),
		                  (u16)((u16)bLoc02 + LG16(0x58B4)));
		/* 5033: inc byte ptr [bp-2h] */
		bLoc02 = (u8)(bLoc02 + 0x01);
		/* 5035: push 12Ch ; push 14h ; call 070Dh */
		(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
		/* 503C: cmp byte ptr [bp-2h],42h ; jz 5067h */
		if (bLoc02 == 0x42)
			break;
		/* 5046: 1E3C([58B8h]+13h, [bp-2h]+[58B4h]) ; jnz 5067h */
		if (bgi_draw_line((u16)(LG16(0x58B8) + 0x0013),
		                (u16)((u16)bLoc02 + LG16(0x58B4)), &dlTmp) != 0x00)
			break;
		/* 5056: cmp (bLoc02+[58B4h]),27Eh ; jnc 5067h */
		if ((u16)((u16)bLoc02 + LG16(0x58B4)) >= 0x027E)
			break;
	}

	/* l0C74_5067: cmp byte ptr [bp-2h],42h ; jz 50C2h */
	if (bLoc02 != 0x42)
	{
		/* l0C74_506D: push 0h ; call far 1AB8h:1C32h */
		(void)bgi_get_text_cursor_attributes(0x00);
		/* 5072: mov al,[bp-2h] ; xor ah,ah ; dec ax ; cmp al,1Dh ;
		 *       jc 50BBh */
		if ((u8)(bLoc02 - 0x01) >= 0x1D)
		{
			/* l0C74_507E: mov [bp-3h],al */
			bLoc03 = (u8)(bLoc02 - 0x01);
			for (;;)
			{
				/* l0C74_5086: 1AF6([58B8h]+14h, [bp-3h]+[58B4h],
				 *                   [58B8h]+12h, [bp-3h]+[58B4h]) */
				(void)bgi_set_pixel((u16)(LG16(0x58B8) + 0x0014),
				                  (u16)((u16)bLoc03 + LG16(0x58B4)),
				                  (u16)(LG16(0x58B8) + 0x0012),
				                  (u16)((u16)bLoc03 + LG16(0x58B4)),
				                  &dxTmp);
				/* 50AB: push 12Ch ; push 14h ; call 070Dh */
				(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
				/* 50B6: cmp byte ptr [bp-3h],1Dh ; jnz 5083h */
				if (bLoc03 == 0x1D)
					break;
				/* l0C74_5083: dec byte ptr [bp-3h] */
				bLoc03 = (u8)(bLoc03 - 0x01);
			}
		}
		/* l0C74_50BB: mov byte ptr [bp-1h],0h */
		bLoc01 = 0x00;
	}
	else
	{
		/* l0C74_50C2: push 1F4h ; call 02D8h */
		(void)engine_clock_tick(0x01F4, &dsTmp);
		/* 50C7: wLoc06 = 13A3([58B8h]+14h, [58B4h]+41h,
		 *                      [58B8h]+11h, [58B4h]+2Ch) */
		wLoc06 = bgi_clamp_rectangle_coords((u16)(LG16(0x58B8) + 0x0014),
		                     (u16)(LG16(0x58B4) + 0x0041),
		                     (u16)(LG16(0x58B8) + 0x0011),
		                     (u16)(LG16(0x58B4) + 0x002C));
		/* 50F5: push wLoc06 ; call far 1EDAh:023Fh */
		blk = fn1EDA_023F(wLoc06, 0x0000, 0x0000, &dsTmp);
		/* 5106: 1E6B(blk, [58B8h]+14h, [58B4h]+41h,
		 *             [58B8h]+11h, [58B4h]+2Ch) */
		bgi_draw_clip_rectangle((u8 *)far_ptr(blk),
		            (u16)(LG16(0x58B8) + 0x0014),
		            (u16)(LG16(0x58B4) + 0x0041),
		            (u16)(LG16(0x58B8) + 0x0011),
		            (u16)(LG16(0x58B4) + 0x002C));
		/* 511? : mov byte ptr [bp-2h],12h */
		bLoc02 = 0x12;

		/* l0C74_5129: blit the block row [bp-2h]+[58B8h]. */
		for (;;)
		{
			/* 5129: 13D7(0h, blk, [bp-2h]+[58B8h], [58B4h]+2Ch) */
			(void)bgi_signed_rectangle_intersect(0x00, (u8 *)far_ptr(blk),
			                  (u16)((u16)bLoc02 + LG16(0x58B8)),
			                  (u16)(LG16(0x58B4) + 0x002C));
			/* 5148: push 12Ch ; push 14h ; call 070Dh */
			(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
			/* 5150: push 28h ; call 02D8h */
			(void)engine_clock_tick(0x0028, &dsTmp);
			/* 5157: cmp byte ptr [bp-2h],2Bh ; jnz 5126h */
			if (bLoc02 == 0x2B)
				break;
			/* l0C74_5126: inc byte ptr [bp-2h] */
			bLoc02 = (u8)(bLoc02 + 0x01);
		}

		/* l0C74_5159: push [bp-8h] ; push [bp-0Ah] ; push [bp-6h] ;
		 *             call far 1EDAh:0254h */
		(void)renamed_1eda_0254(wLoc06, (u16)(blk & 0xFFFFu), (u16)(blk >> 16), 0, &dxTmp, &dsTmp);

		/* 5164: mov byte ptr [bp-3h],2Ch */
		bLoc03 = 0x2C;

		/* l0C74_5170: erase the column downward with 1AF6. */
		for (;;)
		{
			/* 5170: 1AF6([58B8h]+14h, [bp-3h]+[58B4h],
			 *            [58B8h]+12h, [bp-3h]+[58B4h]) */
			(void)bgi_set_pixel((u16)(LG16(0x58B8) + 0x0014),
			                  (u16)((u16)bLoc03 + LG16(0x58B4)),
			                  (u16)(LG16(0x58B8) + 0x0012),
			                  (u16)((u16)bLoc03 + LG16(0x58B4)),
			                  &dxTmp);
			/* 5195: push 12Ch ; push 14h ; call 070Dh */
			(void)engine_scale_and_tick_clock(0x0014, 0x012C, &dsv);
			/* 51A0: cmp byte ptr [bp-3h],1Dh ; jnz 516Dh */
			if (bLoc03 == 0x1D)
				break;
			/* l0C74_516D: dec byte ptr [bp-3h] */
			bLoc03 = (u8)(bLoc03 - 0x01);
		}
	}

	/* l0C74_51A5: mov al,[bp-1h] ; leave ; ret */
	*bpOut = 0x0000;
	*dsOut = 0x0000;
	return bLoc01;
}

// 0C74:51AA: u16 engine_call_rocket_trajectory(void)
//
// One-line far wrapper: run the rocket/explosion trajectory animation
// (engine_rocket_trajectory) and hand its AX return back to the caller.  The dropped DS
// output receives a local scratch (flat model).
u16 engine_call_rocket_trajectory /* was fn0C74_51AA */(void)
{
	u16 dsTmp = 0x0000;     /* engine_rocket_trajectory dropped-DS scratch */

	return engine_rocket_trajectory(&dsTmp);
}

// 0C74:51B2: u16 engine_edge_collision_probe(void)
//
// Screen-edge collision probe used by the seg0800 direction handlers.  Reads
// the state word [5968h]: when it is 1 the two edge probes test the left bars
// at [58BAh]+1 against [58B6h]+1 and [58B6h]+17h; when it is 0FFFFh they test
// the right bars at [58BAh]+1 against [58B4h]-1 and [58B4h]-17h.  If both probes
// are clear the animation helper engine_level_edge_march runs and the [bp-1] flag is set;
// any probe hit leaves the flag 0, and a state word that is neither 1 nor
// 0FFFFh sets the flag 1 without probing.  Returns the [bp-1] byte.
u16 engine_edge_collision_probe /* was fn0C74_51B2 */(void)
{
	u8  bLoc01 = 0x00;      /* [bp-01h] collision flag */
	u16 dsTmp  = 0x0000;    /* engine_level_edge_march dsOut */
	u8  dlTmp  = 0x00;      /* bgi_draw_line dlOut */

	/* 51B2: mov ax,[5968h] ; cmp ax,1h ; jnz 51F1h */
	if (LG16(0x5968) == 0x0001)
	{
		/* l0C74_51C2: 1E3C([58BAh]+1, [58B6h]+1) ; jnz 51EAh */
		if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001),
		                (u16)(LG16(0x58B6) + 0x0001), &dlTmp) != 0x00)
			return (u16)bLoc01;
		/* l0C74_51D5: 1E3C([58BAh]+1, [58B6h]+17h) ; jz 51ECh */
		if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001),
		                (u16)(LG16(0x58B6) + 0x0017), &dlTmp) != 0x00)
			return (u16)bLoc01;
		/* l0C74_51EC: call 2AD9h */
		(void)engine_level_edge_march(&dsTmp);
		bLoc01 = 0x01;
	}
	else if (LG16(0x5968) == 0xFFFF)
	{
		/* l0C74_51F6: 1E3C([58BAh]+1, [58B4h]-1) ; jnz 521Eh */
		if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001),
		                (u16)(LG16(0x58B4) - 0x0001), &dlTmp) != 0x00)
			return (u16)bLoc01;
		/* l0C74_5209: 1E3C([58BAh]+1, [58B4h]-17h) ; jz 5220h */
		if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001),
		                (u16)(LG16(0x58B4) - 0x0017), &dlTmp) != 0x00)
			return (u16)bLoc01;
		/* l0C74_5220: call 2AD9h */
		(void)engine_level_edge_march(&dsTmp);
		bLoc01 = 0x01;
	}
	else
	{
		/* l0C74_51F1: cmp ax,0FFFFh ; jnz 5223h */
		bLoc01 = 0x01;
	}

	/* l0C74_5227: mov al,[bp-1h] ; leave ; retf */
	return (u16)bLoc01;
}
