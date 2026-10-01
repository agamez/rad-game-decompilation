/* seg0C74_part3.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 3 of N: functions 0C74:0A35 .. 0C74:0E2E (6 functions, ascending).
 *
 *   0A35 0CFA 0D43 0D94 0DE5 0E2E
 *
 * Literal recovery from analysis/slices/0C74/0C74_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg0C74.h
 * (analysis/summary/iface.tsv) adopted exactly.  See CONVENTIONS.md,
 * analysis/SEGMAP.md and docs/notes-0C74.md ("## part 3").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   NONE directly.  No int 10h / int 16h / int 21h, no raw `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch occur in
 *   0A35..0E2E.  Every hardware-touching operation is reached indirectly
 *   through already-ported callees: engine_scale_and_tick_clock -> engine_clock_tick and
 *   fn11C8_0354/033B (sound, seg11C8.c); fn1E78_029C (keyboard/pacing,
 *   seg1E78.c); fn1AB8_* (video driver); fn1EDA_023F/0254 (far heap).  The
 *   PC-speaker / AdLib ports attributed to 0E2E by analysis/summary/
 *   functions.tsv are transitive (0E2E itself issues none).
 *
 * Flat-model / ABI adaptations (recorded in docs/notes-0C74.md "## part 3"):
 *   - engine_scatter_muck addresses a 0x30EC-byte frame by literal BP displacement,
 *     with the same two deliberately overlapping arrays as engine_scatter_starfield
 *     (part 2): X/Y word pairs indexed at bp-0x2724 and a byte attribute
 *     array indexed at bp-0x30E5.  abFrame[] with the F8/F16/AATTR/AX_ARR/
 *     AY_ARR access macros reproduces the exact byte layout.
 *   - The 16:16 far blocks returned by fn1EDA_023F are carried as u32
 *     (offset | segment<<16) and materialised with far_ptr(dw), the
 *     same convention as seg0800_part3.c / seg1229_part1.c / seg0C74_part2.c.
 *   - fn1EDA_023F / 0254 require stack words the original never pushes (the
 *     far-return-address words used only on their fatal-error path); seeded 0.
 *   - engine_draw_status_sprites reads ss:[wArg02-4] through the `push bp` caller-frame
 *     argument, i.e. the caller's ([bp-4]) word.  Flat C has no SS:BP chain,
 *     so the four call sites (all inside engine_per_frame_muck) pass that word's VALUE
 *     (the arm-extension index) and 0E2E consumes it directly (see
 *     seg0C74_part4.c; notes-0C74.md part 4 §5).
 *   - Saved-BP / DS-register "outputs" have no flat-C equivalent (no BP
 *     chain): out pointers receive 0 and the artifact return values are 0
 *     (per docs/notes-0800.md and part 1/2 of this segment).
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

// 0C74:0A35: u16 engine_scatter_muck(void)
// Muck/level scatter driver: for `limit` (25000/50000) random points in the
// field rectangle, draw unoccupied points and record a bounded number of them
// in the local X/Y/attribute tables; occupied points nudge a stored point.
// Finally every stored point whose Y is not 0x1F4 is redrawn, then 58B3h = 1.
//
// The original addresses its 0x30EC-byte frame by literal BP displacement with
// two deliberately overlapping arrays (X/Y word pairs at bp-0x2724, byte
// attribute array at bp-0x30E5) plus scalars; abFrame[] reproduces that layout.
u16 engine_scatter_muck /* was fn0C74_0A35 */(void)
{
	u8  abFrame[0x30EC];   /* [bp-0x30EC .. bp-1] whole local frame image */
	u16 dx_a, dx_b, dx_c;  /* fn1EDA_0D80 dxOut scratch */
	u8  dl_96;             /* fn1AB8_1E3C dlOut scratch   */

#define F8(mag)    (*(u8  *)&abFrame[(0x30EC - (mag))])
#define F16(mag)   (*(u16 *)&abFrame[(0x30EC - (mag))])
#define AATTR(i)   F8(0x30E5 - (u16)(i))
#define AX_ARR(i)  F16(0x2724 - (u16)((u16)(i) << 2))
#define AY_ARR(i)  F16(0x2722 - (u16)((u16)(i) << 2))

	F16(0x06) = 0x0000;                          /* xor ax,ax ; [bp-6h] = 0 */

	/* mov ax,[58BAh] ; sub ax,[58B8h] ; shr ax,1h ; mov [bp+0CF18h],ax */
	F16(0x30E8) = (u16)((u16)(LG16(0x58BA) - LG16(0x58B8)) >> 1);

	/* cmp word [bp+0CF18h],17h ; jnc -> 61A8h (25000) / 0C350h (50000) */
	if (F16(0x30E8) < 0x0017)
		F16(0x30EA) = 0x61A8;
	else
		F16(0x30EA) = 0xC350;

	F16(0x0A) = (u16)(LG16(0x58B4) + 0x0015);
	F16(0x0C) = (u16)(LG16(0x58B8) + F16(0x30E8));
	F16(0x30EC) = F16(0x30EA);                   /* [bp+0CF14h] = [bp+0CF16h] */

	/* mov ax,1h ; cmp ax,[bp+0CF14h] ; jbe main (else straight to 0CA3) */
	if (F16(0x30EC) >= 0x0001)
	{
		F16(0x04) = 0x0001;
		for (;;)
		{
			/* 0A8F: wLoc0E = rand(2Dh) + (58B4h+15h) - 15h, then clamp. */
			F16(0x0E) = (u16)(fn1EDA_0D80(0x002D, &dx_a) +
			                  F16(0x0A) - 0x0015);
			if ((u16)(F16(0x0A) + 0x0009) < F16(0x0E))
				F16(0x0E) = (u16)(F16(0x0E) - 0x0001);
			/* wLoc10 = rand(2*(58BA-58B8)/2 + 2) + (58B8h+...)-... */
			F16(0x10) = (u16)(fn1EDA_0D80(
			                     (u16)((u16)(F16(0x30E8) << 1) + 0x0002),
			                     &dx_b) +
			                  F16(0x0C) - F16(0x30E8));

			/* push [bp-0Eh] ; push [bp-10h] ; 1E3Ch ; [bp+0CF1Bh] = al */
			AATTR(0) = (u8)fn1AB8_1E3C(F16(0x10), F16(0x0E), &dl_96);

			if (AATTR(0) != 0x00)
			{
				/* 0ADE: free point -> draw at (wLoc10, wLoc0E) colour 0. */
				(void)fn1AB8_1E54(0x00, F16(0x10), F16(0x0E));
				if (fn1EDA_0D80(0x0003, &dx_c) != 0x0001)
					goto l0C74_0C97;

				if (LG8(0x58B0) != 0x00)
					fn11C8_0354((u16)fn1EDA_0D80(0x0064, &dx_a));

				(void)fn1E78_029C((u16)((s16)LG16(0x58E6) / 0x0004),
				                  &dx_a);

				F16(0x0E) = (u16)(fn1EDA_0D80(0x012C, &dx_b) +
				                  F16(0x0A) - 0x0096);
				if (F16(0x0E) < 0x0001)
					F16(0x0E) = 0x0001;
				if (F16(0x0E) > 0x027E)
					F16(0x0E) = 0x027E;

				F16(0x10) = (u16)(F16(0x0C) -
				                  (fn1EDA_0D80(0x00C8, &dx_c) + 0x0016));
				if (F16(0x10) < 0x0001)
					F16(0x10) = 0x0001;
				if (F16(0x10) > 0x0177)
					F16(0x10) = 0x0001;   /* asm clamps to 1, not 177h */

				if (fn1AB8_1E3C(F16(0x10), F16(0x0E), &dl_96) == 0x00)
				{
					u16 n = (u16)(F16(0x06) + 0x0001);

					F16(0x06) = n;
					AATTR(n) = AATTR(0);
					AX_ARR(n) = F16(0x0E);
					AY_ARR(n) = F16(0x10);
					(void)fn1AB8_1E54(AATTR(n), AY_ARR(n), AX_ARR(n));
				}

				if (LG8(0x58B0) != 0x00)
					(void)fn11C8_033B();
			}
			else
			{
				/* 0BDA: occupied -> nudge a stored point. */
				if (F16(0x06) != 0x0000)
				{
					F16(0x08) = (u16)(fn1EDA_0D80(F16(0x06), &dx_a) +
					                  0x0001);
					if (AY_ARR(F16(0x08)) != 0x01F4)
					{
						/* draw the stored point (colour 0) first */
						(void)fn1AB8_1E54(0x00,
						                  AY_ARR(F16(0x08)),
						                  AX_ARR(F16(0x08)));
						F16(0x0E) = fn1EDA_0D80(0x0014, &dx_b);
						if (F16(0x0E) == 0x0001 ||
						    fn1AB8_1E3C(
						        (u16)(AY_ARR(F16(0x08)) + 0x0001),
						        AX_ARR(F16(0x08)),
						        &dl_96) != 0x00)
						{
							AY_ARR(F16(0x08)) = 0x01F4;
						}
						else if ((u16)(AY_ARR(F16(0x08)) + 0x0002) <
						         LG16(0x58BA))
						{
							AY_ARR(F16(0x08)) =
							    (u16)(AY_ARR(F16(0x08)) + 0x0001);
							(void)fn1AB8_1E54(AATTR(F16(0x08)),
							                  AY_ARR(F16(0x08)),
							                  AX_ARR(F16(0x08)));
						}
						else
						{
							AY_ARR(F16(0x08)) = 0x01F4;
						}
					}
				}
			}

		l0C74_0C97:
			/* mov ax,[bp-4h] ; cmp ax,[bp+0CF14h] ; jz 0CA3h ; jmp 0A8Ch */
			if (F16(0x04) == F16(0x30EC))
				break;
			F16(0x04) = (u16)(F16(0x04) + 0x0001);
		}
	}

	/* 0CA3: redraw every stored point whose Y is not 0x1F4. */
	if (F16(0x06) != 0x0000)
	{
		F16(0x30EC) = F16(0x06);
		if (F16(0x30EC) >= 0x0001)
		{
			F16(0x08) = 0x0001;
			for (;;)
			{
				if (AY_ARR(F16(0x08)) != 0x01F4)
					(void)fn1AB8_1E54(0x00,
					                  AY_ARR(F16(0x08)),
					                  AX_ARR(F16(0x08)));
				if (F16(0x08) == F16(0x30EC))
					break;
				F16(0x08) = (u16)(F16(0x08) + 0x0001);
			}
		}
	}

	LG8(0x58B3) = 0x01;               /* mov byte [58B3h],1h */

#undef F8
#undef F16
#undef AATTR
#undef AX_ARR
#undef AY_ARR

	/* original leaves AX/DX undefined (Reko models DX); no caller consumes it */
	return 0x0000;
}

// 0C74:0CFA: u16 engine_redraw_bars_down(u8 bArg02, void * bpOut, u16 * dsOut)
// 58B3h = 1; then for index bArg02 down to 1, tick engine_scale_and_tick_clock(14h, 64h) and
// blit the DGROUP:5904h[bArg02] far block through fn1AB8_13D7.
u16 engine_redraw_bars_down /* was fn0C74_0CFA */(u8 bArg02, void * bpOut, u16 * dsOut)
{
	u8  bLoc01;              /* [bp-1] loop index (Reko bArg02/bp-1) */
	u16 ds_45 = 0x0000;      /* engine_scale_and_tick_clock dsOut (dropped selector) */

	LG16(0x5968) = 0x0001;   /* mov word [5968h],1h */

	/* mov al,[bp+4h] ; cmp al,1h ; jc 0D3Fh */
	if (bArg02 >= 0x01)
	{
		bLoc01 = bArg02;
		for (;;)
		{
			/* push 64h ; push 14h ; call 070Dh */
			(void)engine_scale_and_tick_clock(0x0014, 0x0064, &ds_45);
			/* push [58B4h] ; push [58B8h] ; les di,[di+5904h] ;
			 * push es ; push di ; push 0h ; call 13D7h */
			(void)fn1AB8_13D7(
			    0x00,
			    far_ptr(LG32((u16)(0x5904 +
			                                ((u16)bLoc01 << 2)))),
			    LG16(0x58B8), LG16(0x58B4));
			if (bLoc01 == 0x01)
				break;
			--bLoc01;                    /* 0D10: dec byte [bp-1h] */
		}
	}

	*(u16 *)bpOut = 0x0000;  /* saved-BP register output (flat: 0) */
	*dsOut = 0x0000;         /* DGROUP selector dropped */
	return 0x0000;           /* DX register artifact; no caller consumes it */
}

// 0C74:0D43: u16 engine_redraw_bars_up(u8 bArg02, void * bpOut, u16 * dsOut)
// 58B3h = 0FFFFh; then for index 1 up to bArg02, tick engine_scale_and_tick_clock(14h, 64h)
// and blit DGROUP:5904h[index].
u16 engine_redraw_bars_up /* was fn0C74_0D43 */(u8 bArg02, void * bpOut, u16 * dsOut)
{
	u8  bLoc01;              /* [bp-1] loop index */
	u8  bLoc02;              /* [bp-2] upper bound = bArg02 */
	u16 ds_45 = 0x0000;

	LG16(0x5968) = 0xFFFF;   /* mov word [5968h],0FFFFh */

	bLoc02 = bArg02;         /* mov [bp-2h],al */
	/* mov al,1h ; cmp al,[bp-2h] ; ja 0D90h */
	if (bArg02 >= 0x01)
	{
		bLoc01 = 0x01;
		for (;;)
		{
			(void)engine_scale_and_tick_clock(0x0014, 0x0064, &ds_45);
			(void)fn1AB8_13D7(
			    0x00,
			    far_ptr(LG32((u16)(0x5904 +
			                                ((u16)bLoc01 << 2)))),
			    LG16(0x58B8), LG16(0x58B4));
			if (bLoc01 == bLoc02)
				break;
			++bLoc01;                    /* 0D5F: inc byte [bp-1h] */
		}
	}

	*(u16 *)bpOut = 0x0000;
	*dsOut = 0x0000;
	return 0x0000;
}

// 0C74:0D94: u8 * engine_redraw_bars_down_15(u8 bArg02, u16 * dsOut)
// 58B3h = 1; then for index 15h down to bArg02, tick engine_scale_and_tick_clock(14h, 64h)
// and blit DGROUP:5904h[index].
u8 * engine_redraw_bars_down_15 /* was fn0C74_0D94 */(u8 bArg02, u16 * dsOut)
{
	u8  bLoc01;              /* [bp-1] loop index */
	u8  bLoc02;              /* [bp-2] lower bound = bArg02 */
	u16 ds_45 = 0x0000;

	LG16(0x5968) = 0x0001;

	bLoc02 = bArg02;         /* mov [bp-2h],al */
	/* mov al,15h ; cmp al,[bp-2h] ; jc 0DE1h */
	if (bArg02 <= 0x15)
	{
		bLoc01 = 0x15;
		for (;;)
		{
			(void)engine_scale_and_tick_clock(0x0014, 0x0064, &ds_45);
			(void)fn1AB8_13D7(
			    0x00,
			    far_ptr(LG32((u16)(0x5904 +
			                                ((u16)bLoc01 << 2)))),
			    LG16(0x58B8), LG16(0x58B4));
			if (bLoc01 == bLoc02)
				break;
			--bLoc01;                    /* 0DB0: dec byte [bp-1h] */
		}
	}

	*dsOut = 0x0000;
	return NULL;             /* saved-BP register output (flat: NULL) */
}

// 0C74:0DE5: u8 * engine_redraw_bars_up_15(u8 bArg02, u16 * dsOut)
// 58B3h = 0FFFFh; then for index bArg02 up to 15h, tick engine_scale_and_tick_clock(14h, 64h)
// and blit DGROUP:5904h[index].
u8 * engine_redraw_bars_up_15 /* was fn0C74_0DE5 */(u8 bArg02, u16 * dsOut)
{
	u8  bLoc01;              /* [bp-1] loop index */
	u16 ds_45 = 0x0000;

	LG16(0x5968) = 0xFFFF;

	/* mov al,[bp+4h] ; cmp al,15h ; ja 0E2Ah */
	if (bArg02 <= 0x15)
	{
		bLoc01 = bArg02;
		for (;;)
		{
			(void)engine_scale_and_tick_clock(0x0014, 0x0064, &ds_45);
			(void)fn1AB8_13D7(
			    0x00,
			    far_ptr(LG32((u16)(0x5904 +
			                                ((u16)bLoc01 << 2)))),
			    LG16(0x58B8), LG16(0x58B4));
			if (bLoc01 == 0x15)
				break;
			++bLoc01;                    /* 0DFB: inc byte [bp-1h] */
		}
	}

	*dsOut = 0x0000;
	return NULL;
}

// 0C74:0E2E: u8 * engine_draw_status_sprites(u16 wArg02, void * dsOut)
// Draw the two status-field "sprites": build two rectangles with fn1AB8_13A3,
// allocate a far block each (fn1EDA_023F), stamp the rectangles into the blocks
// (fn1AB8_1E6B), then for the caller-frame offset down to 0 tick
// engine_scale_and_tick_clock(0Ah, 0E6h) and blit both blocks, finally free them.
//
// wArg02 carries the CALLER's [bp-4] word: every call site is `push bp ;
// call 0E2E` from engine_per_frame_muck and the callee reads ss:[bp_caller-4], which is
// 0FA1's arm-extension index (12E8 abort: the index reached; 2476/2628: 14h;
// 3175: 13h -- the asm stores those constants into [bp-4] right before the
// call).  The flat model has no SS:BP chain, so the value is passed directly.
u8 * engine_draw_status_sprites /* was fn0C74_0E2E */(u16 wArg02, void * dsOut)
{
	u16 wL4;                 /* [bp-4] first  fn1AB8_13A3 result (blk4 size) */
	u16 wL6;                 /* [bp-6] second fn1AB8_13A3 result (blk6 size) */
	u16 dx_389;              /* fn1EDA_0254 dxOut */
	u16 dx_390;              /* fn1EDA_0254 dxOut */
	u16 ds_314 = 0x0000;     /* fn1EDA_023F/0254 dsOut (dropped selector) */
	u32 blk6;                /* DX:AX of 023F(wL6) */
	u32 blk4;                /* DX:AX of 023F(wL4) */
	u8  bLoc01;              /* [bp-1] blit-loop counter */
	u16 wCallerL4 = wArg02;  /* the caller's [bp-4] word (see above) */

	/* push (58B4h+19h+N) ; (58B8h+0Dh) ; (58B4h+1Dh+N) ; (58B8h+1Bh) ; 13A3 */
	wL4 = fn1AB8_13A3((u16)(LG16(0x58B8) + 0x001B),
	                  (u16)(LG16(0x58B4) + 0x001D + wCallerL4),
	                  (u16)(LG16(0x58B8) + 0x000D),
	                  (u16)(LG16(0x58B4) + 0x0019 + wCallerL4));
	/* push (58B4h+0Dh-N) ; (58B8h+0Dh) ; (58B4h+11h-N) ; (58B8h+1Bh) ; 13A3 */
	wL6 = fn1AB8_13A3((u16)(LG16(0x58B8) + 0x001B),
	                  (u16)(LG16(0x58B4) + 0x0011 - wCallerL4),
	                  (u16)(LG16(0x58B8) + 0x000D),
	                  (u16)(LG16(0x58B4) + 0x000D - wCallerL4));

	/* push [bp-6h] ; call 023Fh -> DX:AX = blk6 */
	blk6 = fn1EDA_023F(wL6, 0x0000, 0x0000, &ds_314);
	/* push [bp-4h] ; call 023Fh -> DX:AX = blk4 */
	blk4 = fn1EDA_023F(wL4, 0x0000, 0x0000, &ds_314);

	/* first 1E6B: stamp the wL4 rectangle into blk4 */
	fn1AB8_1E6B(far_ptr(blk4),
	            (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(LG16(0x58B4) + 0x001D + wCallerL4),
	            (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x0019 + wCallerL4));
	/* second 1E6B: stamp the wL6 rectangle into blk6 */
	fn1AB8_1E6B(far_ptr(blk6),
	            (u16)(LG16(0x58B8) + 0x001B),
	            (u16)(LG16(0x58B4) + 0x0011 - wCallerL4),
	            (u16)(LG16(0x58B8) + 0x000D),
	            (u16)(LG16(0x58B4) + 0x000D - wCallerL4));

	/* mov al,ss:[di-4h] ; or al,al ; jc (never taken) ; blit loop */
	bLoc01 = (u8)wCallerL4;
	for (;;)
	{
		(void)engine_scale_and_tick_clock(0x000A, 0x00E6, &ds_314);
		/* push (58B4h+19h+c) ; (58B8h+0Dh) ; es:di=blk4 ; 0 ; 13D7 */
		(void)fn1AB8_13D7(0x00,
		                  far_ptr(blk4),
		                  (u16)(LG16(0x58B8) + 0x000D),
		                  (u16)(LG16(0x58B4) + 0x0019 + bLoc01));
		/* push (58B4h+0Dh-c) ; (58B8h+0Dh) ; es:di=blk6 ; 0 ; 13D7 */
		(void)fn1AB8_13D7(0x00,
		                  far_ptr(blk6),
		                  (u16)(LG16(0x58B8) + 0x000D),
		                  (u16)(LG16(0x58B4) + 0x000D - bLoc01));
		if (bLoc01 == 0x00)
			break;
		--bLoc01;                /* 0F2A: dec byte [bp-1h] */
	}

	/* push [bp-8h] ; push [bp-0Ah] ; push [bp-6h] ; call 0254h */
	fn1EDA_0254(wL6, (u16)((blk6) & 0xFFFFu), (u16)((blk6) >> 16), 0,
	            &dx_389, &ds_314);
	/* push [bp-0Ch] ; push [bp-0Eh] ; push [bp-4h] ; call 0254h */
	fn1EDA_0254(wL4, (u16)((blk4) & 0xFFFFu), (u16)((blk4) >> 16), 0,
	            &dx_390, &ds_314);

	*(u16 *)dsOut = 0x0000;
	return NULL;             /* saved-BP register output (flat: NULL) */
}
