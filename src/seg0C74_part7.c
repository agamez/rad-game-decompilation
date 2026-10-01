/* seg0C74_part7.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 7 of N: functions 0C74:2AD9 .. 0C74:2BBD (2 functions, ascending).
 *
 *   2AD9 2BBD
 *
 * Literal recovery from analysis/slices/0C74/0C74_<off>.asm (ground truth)
 * and the Reko decompilation / .dis; frozen prototypes from src/seg0C74.h
 * (analysis/summary/iface.tsv) adopted exactly.  See CONVENTIONS.md,
 * analysis/SEGMAP.md and docs/notes-0C74.md ("## part 7").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   None directly.  No int 10h / int 16h / int 21h, no raw `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch occur in
 *   2AD9..2BBD.  Every hardware-touching operation is reached indirectly
 *   through already-ported callees: the 1AB8 video driver (13A3/1E6B/13D7/
 *   1C32/1AF6/1E3C/1E54), the 1EDA far-heap helpers (023F/0254/096F/098A),
 *   fn1E78_029C (keyboard/pacing) and audio_write_opl3_register/033B (sound).  engine_clock_tick /
 *   070D / 0D43 / 0D94 / 0CFA / 0DE5 / 1F08 / 076B are 0C74 helpers handled by
 *   their own chunks.
 *
 * Flat-model / ABI adaptations (recorded in docs/notes-0C74.md "## part 7"):
 *   - Reko's `bp_121` / `bp_158` / `bp_325` frame-pointer locals (re-bound
 *     after each call to 0D43/0D94/070D whose AX/pointer return is the caller's
 *     saved BP) are the current function's own frame; they are folded back
 *     onto the literal locals ([bp-4h]/[bp-6h], notes-0C74.md part 1 §3).
 *   - The 16:16 far blocks allocated by fn1EDA_023F are carried as `u32`
 *     (offset | segment<<16, low word at the lower address) and materialised
 *     through the segment mapper at the call sites, the same convention as
 *     seg0800_part3.c / seg0C74_part4.c / seg0C74_part6.c.
 *   - fn1EDA_098A's frozen `void * dsOut` receives a `void *` local (`dsv`).
 *   - fn1EDA_023F / 098A / 0254 take stack words the original never pushes
 *     (far-return-address / leftover slots, read only on the fatal
 *     divide-by-zero dispatcher path); they are seeded 0.
 *   - `bpOut` / `dsOut` register outputs are the caller's saved BP and the
 *     DGROUP selector; both receive 0.
 */

#include <stddef.h>
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C74.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1E78.h"
#include "seg11C8.h"

// 0C74:2AD9: u16 engine_level_edge_march(u16 * dsOut)
//
// Level/edge "march" driver shared by the intro and game-core loops.  When the
// state word at 0x5968 is 1 it ticks the left field (0D43), otherwise the right
// field (0D94); both start with a 02D8 clock tick.  It then allocates a 023F
// block sized by the 13A3 rectangle ([58B8h],[58B4h],+1Ch,+2Bh), blits it with
// 1E6B, and while engine_per_frame_level reports "advance" and [58BAh]-2Bh > [58B8h],
// steps [58B8h] and pushes another 070D tick + 13D7 blit.  Unless 58B3h says
// stop, it then converts [58E6h]*[4D0Ch] (signed 16x16->32, 096F), divides the
// product by 4 (098A), ticks 02D8, advances the matching field (0DE5/0CFA) and
// finally frees the block with 0254.
u16 engine_level_edge_march /* was fn0C74_2AD9 */(u16 *dsOut)
{
	u16 wLoc04 = 0x0000;    /* [bp-04h] fn1EDA_023F block segment (DX) */
	u16 wLoc06 = 0x0000;    /* [bp-06h] fn1EDA_023F block offset  (AX) */
	u16 bpv    = 0x0000;    /* saved-BP out of 0D43/0CFA/1F08 (flat: 0) */
	u16 dsTmp  = 0x0000;    /* dropped DGROUP selector out */
	u16 dsTmp2 = 0x0000;    /* dropped DGROUP selector out (2B79 branch) */
	u16 dxTmp  = 0x0000;    /* fn1EDA_0254 dxOut */
	void *dsv  = NULL;      /* engine_scale_and_tick_clock / fn1EDA_098A dsOut */
	s16 cxT = 0, dxT = 0, bxT = 0;  /* fn1EDA_098A cx/dx/bx outs */

	/* cmp word [5968h],1h ; jnz 2AF1h */
	if (LG16(0x5968) == 0x0001)
	{
		/* push 0C8h ; call 02D8h */
		(void)engine_clock_tick(0x00C8, &dsTmp);
		/* push 0Bh ; call 0D43h */
		(void)engine_redraw_bars_up(0x0B, &bpv, &dsTmp);
	}
	else
	{
		/* push 0C8h ; call 02D8h */
		(void)engine_clock_tick(0x00C8, &dsTmp);
		/* push 0Bh ; call 0D94h */
		(void)engine_redraw_bars_down_15(0x0B, &dsTmp);
	}

	/* push 0h ; push 0h ; push 1Ch ; push 2Bh ; call 13A3h */
	LG16(0x595E) = bgi_clamp_rectangle_coords(0x002B, 0x001C, 0x0000, 0x0000);

	/* push [595Eh] ; call 023Fh -> DX:AX block */
	{
		u32 blk = fn1EDA_023F(LG16(0x595E), 0x0000, 0x0000, &dsTmp);
		wLoc06 = (u16)blk;
		wLoc04 = (u16)(blk >> 16);
	}

	/* push [58B4h] ; push [58B8h] ; push ([58B4h]+2Bh) ; push ([58B8h]+1Ch) ;
	 * les di,[bp-6h] ; push es ; push di ; call 1E6Bh */
	bgi_draw_clip_rectangle(far_ptr(((u32)wLoc04 << 16) | (u32)wLoc06),
	            (u16)(LG16(0x58B8) + 0x001C),
	            (u16)(LG16(0x58B4) + 0x002B),
	            LG16(0x58B8), LG16(0x58B4));

	/* call 1F08h ; or al,al ; jz 2B70h */
	if (engine_per_frame_level(&bpv, &dsTmp) != 0x00)
	{
		/* 2B42: mov ax,[58BAh] ; sub ax,2Bh ; cmp ax,[58B8h] ; jbe 2B70h */
		while ((u16)(LG16(0x58BA) - 0x002B) > LG16(0x58B8))
		{
			/* push 0C8h ; push 14h ; call 070Dh */
			(void)engine_scale_and_tick_clock(0x0014, 0x00C8, &dsv);
			/* inc word [58B8h] */
			LG16(0x58B8) = (u16)(LG16(0x58B8) + 0x0001);
			/* push [58B4h] ; push [58B8h] ; les di,[bp-6h] ;
			 * push es ; push di ; push 0h ; call 13D7h */
			bgi_signed_rectangle_intersect(0x00,
			            far_ptr(((u32)wLoc04 << 16) | (u32)wLoc06),
			            LG16(0x58B8), LG16(0x58B4));
		}
	}

	/* cmp byte [58B3h],0h ; jz 2B79h ; jmp 2BBBh */
	if (LG8(0x58B3) == 0x00)
	{
		u32 prod;

		/* mov ax,[58E6h] ; cwd ; mov cx,ax ; mov bx,dx ;
		 * mov ax,[4D0Ch] ; xor dx,dx ; call 096Fh
		 *   BX:CX = sign-extended [58E6h] (BX is the sign word, DX's cwd
		 *   result), DX:AX = 0:[4D0Ch]; 096F forms the 32-bit product
		 *   [4D0Ch] * [58E6h] (16x16->32).  It feeds 098A/4 below. */
		prod = fn1EDA_096F(LG16(0x4D0C), LG16(0x58E6), 0x0000,
		                   (u16)((s16)LG16(0x58E6) < 0 ? 0xFFFFu : 0x0000u));
		/* mov cx,4h ; xor bx,bx ; call 098Ah ; push ax ; call 02D8h */
		(void)engine_clock_tick(
		    (u16)fn1EDA_098A(0x00000004, prod, 0x0000, 0x0000,
		                     &cxT, &dxT, &bxT, &dsv),
		    &dsTmp2);

		/* cmp word [5968h],1h ; jnz 2BA7h */
		if (LG16(0x5968) == 0x0001)
		{
			/* push 0Bh ; call 0DE5h */
			(void)engine_redraw_bars_up_15(0x0B, &dsTmp2);
		}
		else
		{
			/* push 0Bh ; call 0CFAh */
			(void)engine_redraw_bars_down(0x0B, &bpv, &dsTmp2);
		}

		/* push [bp-4h] ; push [bp-6h] ; push [595Eh] ; call 0254h */
		(void)fn1EDA_0254(LG16(0x595E), (u16)(wLoc06), (u16)(wLoc04), 0,
		                  &dxTmp, &dsTmp2);
	}

	*dsOut = 0x0000;   /* DGROUP selector dropped in the flat model */
	return 0x0000;     /* saved-BP artifact; no caller consumes it */
}

// 0C74:2BBD: u16 engine_sprite_grow(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)
//
// Sprite "grow" animation.  Builds two 13A3 far blocks (sizes wLoc0C/wLoc0A)
// and a pair of 023F scratch blocks, blits the background (block2) with 1E6B /
// 13D7, draws the sprite (block1) with 1E6B, then marches wArg02/wArg06 while
// the 1E3C attribute probe returns 0.  When wArg02 reaches 0x176 and the first
// probe returned 0x0F it runs a nested 8x11x21 colour-fade that hammers
// audio_write_opl3_register (sound) and bgi_get_line_attributes (pixel plots), then restores the HUD and
// ticks the sound.  It finally frees block1 and, if the counter stayed below
// DGROUP:4D0Ah and wArg02 < 0x172, calls engine_scatter_starfield.
u16 engine_sprite_grow /* was fn0C74_2BBD */(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)
{
	u16 wLoc02 = 0x0000;   /* [bp-02h] block1 segment (DX of first 023F) */
	u16 wLoc04 = 0x0000;   /* [bp-04h] block1 offset  (AX of first 023F) */
	u16 wLoc06 = 0x0000;   /* [bp-06h] block2 segment (DX of second 023F) */
	u16 wLoc08 = 0x0000;   /* [bp-08h] block2 offset  (AX of second 023F) */
	u16 wLoc0A = 0x0000;   /* [bp-0Ah] second bgi_clamp_rectangle_coords size (block2) */
	u16 wLoc0C = 0x0000;   /* [bp-0Ch] first  bgi_clamp_rectangle_coords size (block1) */
	u16 wLoc0E = 0x0000;   /* [bp-0Eh] loop counter (compared to 4D0Ah) */
	u8  bLoc0F = 0x00;     /* [bp-0Fh] first bgi_draw_line result (attribute) */
	u8  bLoc10 = 0x01;     /* [bp-10h] inner loop index */
	u8  bLoc11 = 0x00;     /* [bp-11h] middle loop index */
	u8  bLoc12 = 0x0F;     /* [bp-12h] outer loop index */
	u16 dsTmp  = 0x0000;   /* dropped DGROUP selector out */
	u16 dxTmp  = 0x0000;   /* bgi_set_pixel / fn1EDA_0254 dxOut */
	u8  dlTmp  = 0x00;     /* bgi_draw_line dlOut */

	/* push [bp+0Ah] ; push [bp+8h] ; push [bp+6h] ; push [bp+4h] ; call 13A3h */
	wLoc0C = bgi_clamp_rectangle_coords(wArg02, wArg04, wArg06, wArg08);
	/* push [bp+0Ah] ; push [bp+8h] ; push [bp+6h] ; push [bp+8h] ; call 13A3h */
	wLoc0A = bgi_clamp_rectangle_coords(wArg06, wArg04, wArg06, wArg08);

	/* push [bp-0Ch] ; call 023Fh  -> block1 */
	{
		u32 b1 = fn1EDA_023F(wLoc0C, 0x0000, 0x0000, &dsTmp);
		wLoc04 = (u16)b1;
		wLoc02 = (u16)(b1 >> 16);
	}
	/* push [bp-0Ah] ; call 023Fh  -> block2 */
	{
		u32 b2 = fn1EDA_023F(wLoc0A, 0x0000, 0x0000, &dsTmp);
		wLoc08 = (u16)b2;
		wLoc06 = (u16)(b2 >> 16);
	}

	/* push wArg08 ; push wArg06 ; push wArg04 ; push wArg06 ;
	 * les di,[bp-8h] ; push es ; push di ; call 1E6Bh */
	bgi_draw_clip_rectangle(far_ptr(((u32)wLoc06 << 16) | (u32)wLoc08),
	            wArg06, wArg04, wArg06, wArg08);

	/* push 0h ; call 1C32h */
	(void)bgi_get_text_cursor_attributes(0x00);

	/* push wArg08 ; push wArg06 ; push wArg04 ; push wArg06 ; call 1AF6h */
	(void)bgi_set_pixel(wArg06, wArg04, wArg06, wArg08, &dxTmp);

	/* push wArg08 ; push wArg06 ; push wArg04 ; push wArg02 ;
	 * les di,[bp-4h] ; push es ; push di ; call 1E6Bh */
	bgi_draw_clip_rectangle(far_ptr(((u32)wLoc02 << 16) | (u32)wLoc04),
	            wArg02, wArg04, wArg06, wArg08);

	/* push wArg08 ; push wArg06 ; les di,[bp-8h] ; push es ; push di ;
	 * push 0h ; call 13D7h */
	bgi_signed_rectangle_intersect(0x00,
	            far_ptr(((u32)wLoc06 << 16) | (u32)wLoc08),
	            wArg06, wArg08);

	/* push [bp-6h] ; push [bp-8h] ; push [bp-0Ah] ; call 0254h */
	(void)fn1EDA_0254(wLoc0A, (u16)(wLoc08), (u16)(wLoc06), 0,
	                  &dxTmp, &dsTmp);

	/* push wArg08+0Bh ; push wArg02 ; call 1E3Ch ; mov [bp-0Fh],al */
	bLoc0F = (u8)bgi_draw_line(wArg02, (u16)(wArg08 + 0x000B), &dlTmp);
	/* xor ax,ax ; mov [bp-0Eh],ax */
	wLoc0E = 0x0000;

	/* 2C80: while (1E3C(wArg02+1, wArg08+0Bh) == 0) { ... } */
	while (bgi_draw_line((u16)(wArg02 + 0x0001), (u16)(wArg08 + 0x000B),
	                   &dlTmp) == 0x0000)
	{
		/* mov ax,[58E6h] ; cwd ; mov cx,4h ; idiv cx ; push ax ; call 029Ch */
		(void)fn1E78_029C((u16)((s16)LG16(0x58E6) / 0x0004), &dxTmp);

		/* inc word [bp+8h] ; inc word [bp+4h] ; inc word [bp-0Eh] */
		wArg06 = (u16)(wArg06 + 0x0001);
		wArg02 = (u16)(wArg02 + 0x0001);
		wLoc0E = (u16)(wLoc0E + 0x0001);

		/* push wArg08 ; push wArg06 ; les di,[bp-4h] ; push es ; push di ;
		 * push 0h ; call 13D7h */
		bgi_signed_rectangle_intersect(0x00,
		            far_ptr(((u32)wLoc02 << 16) | (u32)wLoc04),
		            wArg06, wArg08);

		/* cmp word [bp+4h],176h ; jz 2CCCh ; jmp 2E20h
		 * cmp byte [bp-0Fh],0Fh ; jz 2CD5h ; jmp 2E20h */
		if (wArg02 == 0x0176 && bLoc0F == 0x0F)
		{
			/* 2CD5: mov byte [bp-12h],0Fh */
			bLoc12 = 0x0F;
			do
			{
				/* 2CDE: mov byte [bp-11h],0h */
				bLoc11 = 0x00;
				do
				{
					/* 2CE7: mov byte [bp-10h],1h */
					bLoc10 = 0x01;
					do
					{
						/* cmp byte [58B0h],0 ; jz 2D15h */
						if (LG8(0x58B0) != 0x00)
							audio_write_opl3_register((u16)((u16)(((u16)bLoc11 + 0x0001) *
							                        (u16)bLoc12) *
							                  (u16)bLoc10));

						/* push 1h ; call 029Ch */
						(void)fn1E78_029C(0x0001, &dxTmp);

						/* mov al,[bp-10h] ; cwd ; mov cx,3 ; div cx ;
						 * xchg dx,ax ; or ax,ax ; jnz 2D4Ch/2DA4h */
						if (((u16)bLoc10 % 0x0003) == 0x0000)
						{
							/* 2D2C / 2D7D */
							(void)bgi_get_line_attributes(bLoc12,
							    (u16)((u16)bLoc10 + 0x0161),
							    (u16)(wArg08 + (u16)bLoc11));
						}
						else
						{
							/* 2D4C / 2DA4 */
							(void)bgi_get_line_attributes((u8)(bLoc12 - 0x08),
							    (u16)((u16)bLoc10 + 0x0161),
							    (u16)(wArg08 + (u16)bLoc11));
						}
						if (((u16)bLoc10 % 0x0003) == 0x0000)
						{
							(void)bgi_get_line_attributes(bLoc12,
							    (u16)((u16)bLoc10 + 0x0161),
							    (u16)((u16)(wArg08 + 0x0015) - (u16)bLoc11));
						}
						else
						{
							(void)bgi_get_line_attributes((u8)(bLoc12 - 0x08),
							    (u16)((u16)bLoc10 + 0x0161),
							    (u16)((u16)(wArg08 + 0x0015) - (u16)bLoc11));
						}

						/* cmp byte [bp-10h],15h ; jz 2DD5h ; jmp 2CEDh */
						if (bLoc10 == 0x15)
							break;
						++bLoc10;        /* 2CED */
					} while (1);

					/* cmp byte [bp-11h],0Ah ; jz 2DDEh ; jmp 2CE4h */
					if (bLoc11 == 0x0A)
						break;
					++bLoc11;            /* 2CE4 */
				} while (1);

				/* cmp byte [bp-12h],8h ; jz 2DE7h ; jmp 2CDBh */
				if (bLoc12 == 0x08)
					break;
				--bLoc12;                /* 2CDB */
			} while (1);

			/* 2DE7: mov al,[bp-0Fh] ; push ax ; call 1C32h */
			(void)bgi_get_text_cursor_attributes(bLoc0F);
			/* push wArg08 ; push wArg02 ; push wArg04 ; push wArg02 ; call 1AF6h */
			(void)bgi_set_pixel(wArg02, wArg04, wArg02, wArg08, &dxTmp);
			/* push 0Ah ; call 1C32h */
			(void)bgi_get_text_cursor_attributes(0x0A);
			/* push wArg08 ; push 161h ; push wArg04 ; push 161h ; call 1AF6h */
			(void)bgi_set_pixel(0x0161, wArg04, 0x0161, wArg08, &dxTmp);
			/* call 033Bh */
			(void)audio_get_soundcard_port();
		}
	}

	/* 2E23: push [bp-2h] ; push [bp-4h] ; push [bp-0Ch] ; call 0254h */
	(void)fn1EDA_0254(wLoc0C, (u16)(wLoc04), (u16)(wLoc02), 0,
	                  &dxTmp, &dsTmp);

	/* mov al,[4D0Ah] ; xor ah,ah ; cmp ax,[bp-0Eh] ; jnc 2E56h
	 * cmp word [bp+4h],172h ; jnc 2E56h */
	if ((u16)LG8(0x4D0A) < wLoc0E && wArg02 < 0x0172)
	{
		/* push wArg08 ; push wArg06 ; push wArg04 ; push wArg02+16h ;
		 * push cs ; call 076Bh */
		(void)engine_scatter_starfield((u16)(wArg02 + 0x0016), wArg04, wArg06, wArg08);
	}

	return 0x0000;   /* saved-BP artifact; no caller consumes it */
}
