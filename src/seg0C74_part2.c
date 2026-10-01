/* seg0C74_part2.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 2 of N: functions 0C74:03D4 .. 0C74:076B (5 functions, ascending).
 *
 *   03D4 05B8 06B7 070D 076B
 *
 * Literal recovery from analysis/slices/0C74/0C74_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg0C74.h
 * (analysis/summary/iface.tsv) adopted exactly.  See CONVENTIONS.md,
 * analysis/SEGMAP.md and docs/notes-0C74.md ("## part 2").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4): none.  No
 * int 10h/16h/21h, no raw `in`/`out` port instruction, no __cli/__sti and
 * no int 23h occur in 03D4..076B; there is no raw IVT dispatch.  Every
 * hardware-touching operation is reached indirectly through already-ported
 * callees (seg1AB8 / 1EDA / 1E78 / 11C8).
 *
 * Flat-model / ABI adaptations (documented in docs/notes-0C74.md):
 *   - Far-heap blocks from fn1EDA_023F are 16:16 segment:offset pairs.  As
 *     in seg0800_part1.c they are combined as (segment<<16)|offset and cast
 *     to u8*; the far-heap node fetches themselves live in the 1EDA port.
 *   - Saved-BP / DS-register "outputs" have no flat-C equivalent (no BP
 *     chain): out pointers receive 0 and the artifact return values are 0.
 *   - engine_scatter_starfield addresses a 0x30EE-byte frame by literal BP displacement,
 *     including two deliberately overlapping arrays; abFrame[] reproduces
 *     that exact layout.
 */

#include <stddef.h>
#include <stdint.h>
#include <time.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C74.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg11C8.h"
#include "seg1E78.h"

// 0C74:03D4: u16 engine_load_resources(void)
// Probe the "RAD.DES" description stream (engine_probe_file) and, when present,
// open the file into the DGROUP stream block at 0x58E8's neighbourhood.  If
// the probe fails, format/open the file through the 0B9BC text stream first.
// Then lay out 0x1D indexed resource records (four ranges), draw each frame
// and finally release the scratch block.
u16 engine_load_resources /* was fn0C74_03D4 */(void)
{
	u8  abLoc82[0x82];      /* [bp+0FF7Eh] = bp-0x82 DOS stream (DAT) block  */
	u16 wLoc88;             /* [bp+0FF78h] first bgi_clamp_rectangle_coords result (023F sz)*/
	u16 wLoc8A;             /* [bp+0FF76h] second bgi_clamp_rectangle_coords result (unused)*/
	u16 wLoc86;             /* [bp+0FF7Ah] 023F block offset                 */
	u16 wLoc84;             /* [bp+0FF7Ch] 023F block segment                */
	u8  bLoc03;             /* [bp-0001h] resource index 1..1Dh              */
	u16 dx_719;             /* engine_probe_file dxOut                             */
	u16 dx_721;             /* fn1E78_016B dxOut                             */
	u16 cx_85;              /* fn1EDA_08CE cxOut                             */
	u16 dx_720;             /* fn1EDA_0FD0 dxOut                             */
	u16 ds_552 = 0x0000;    /* dropped DGROUP selector out of 1EDA calls     */
	u16 dx_724;             /* fn1EDA_0254 dxOut                             */

	/* mov di,3B2h ; push cs ; push di ; push cs ; call 0000h */
	if (engine_probe_file(&g_seg0C74[0x03B2], &dx_719) == 0x00)
	{
		bgi_shutdown_video_driver();
		bgi_swap_graphics_gateway();
		/* push [0B8ACh] ; call far 1E78h:016Bh */
		(void)fn1E78_016B(LG16(0xB8AC), &dx_721);
		/* fn1EDA_08CE(0, cs:03BA, ds:0B9BC, &cx_85) then the paired
		 * fn1EDA_0848(0, cx_85, ds:0B9BC) append-CRLF (stack reuse). */
		(void)fn1EDA_08CE(0x0000, &g_seg0C74[0x03BA],
		                  &g_dgroup[0xB9BC], &cx_85);
		(void)fn1EDA_0848(0x00, cx_85, &g_dgroup[0xB9BC]);
		/* xor ax,ax ; call far 1EDAh:00E9h */
		(void)fn1EDA_00E9(0x0000);
	}

	/* fn1EDA_0FA2(cs:03B2, ss:bp-0x82) ; fn1EDA_0FD0([4D0Eh], ss:bp-0x82) */
	fn1EDA_0FA2(&g_seg0C74[0x03B2], abLoc82);
	(void)fn1EDA_0FD0(LG16(0x4D0E), abLoc82, &dx_720);

	/* push 0 ; push 0 ; push 2Bh ; push 18h ; call 13A3h */
	wLoc88 = bgi_clamp_rectangle_coords(0x0018, 0x002B, 0x0000, 0x0000);
	/* push 0 ; push 0 ; push 2Bh ; push 2Bh ; call 13A3h (result unused) */
	wLoc8A = bgi_clamp_rectangle_coords(0x002B, 0x002B, 0x0000, 0x0000);
	(void)wLoc8A;

	/* push [4D0Eh] ; call 023Fh -> DX:AX scratch block */
	{
		u32 dx_ax_718 = fn1EDA_023F(LG16(0x4D0E), 0x0000, 0x0000, &ds_552);
		wLoc86 = (u16)dx_ax_718;
		wLoc84 = (u16)(dx_ax_718 >> 16);
	}

	bLoc03 = 0x01;
	for (;;)
	{
		u8 b;

		/* push 5h ; push cs ; call 00B2h */
		engine_advance_stream_cursor(0x05);
		b = bLoc03;
		if (b >= 0x01 && b <= 0x04)
		{
			/* push [4D0Eh] ; call 023Fh ; table[58E4h + b*4] = DX:AX;
			 * fn1EDA_10BB(NULL, 1, ss:bp-0x82) (block data ptr dropped). */
			u32 blk = fn1EDA_023F(LG16(0x4D0E), 0x0000, 0x0000, &ds_552);
			u16 idx = (u16)b;
			LG16((u16)(0x58E4 + (u16)(idx * 4))) = (u16)blk;
			LG16((u16)(0x58E6 + (u16)(idx * 4))) = (u16)(blk >> 16);
			(void)fn1EDA_10BB((u8 *)0, 0x01,
			                  (u8 *)far_ptr(LG32((u16)(0x58E4 + (u16)(b * 4)))), abLoc82);
		}
		else if (b >= 0x05 && b <= 0x19)
		{
			/* fn1EDA_10BB(NULL, 1, buf); bgi_signed_rectangle_intersect(0, scratch, 0, 0);
			 * then allocate wLoc88 bytes -> table[5904h + (b-4)*4] and
			 * bgi_draw_clip_rectangle(block, 18h, 2Bh, 0, 0). */
			u8 *pScratch = (u8 *)far_ptr(FAR_PTR(wLoc84, wLoc86));

			(void)fn1EDA_10BB((u8 *)0, 0x01, pScratch, abLoc82);
			bgi_signed_rectangle_intersect(0x00, pScratch, 0x0000, 0x0000);
			{
				u32 blk = fn1EDA_023F(wLoc88, 0x0000, 0x0000, &ds_552);
				u16 idx = (u16)(b - 0x04);
				u8 *pBlk;

				LG16((u16)(0x5904 + (u16)(idx * 4))) = (u16)blk;
				LG16((u16)(0x5906 + (u16)(idx * 4))) = (u16)(blk >> 16);
				pBlk = far_ptr(LG32((u16)(0x5904 + (u16)(idx * 4))));
				bgi_draw_clip_rectangle(pBlk, 0x0018, 0x002B, 0x0000, 0x0000);
			}
		}
		else if (b >= 0x1A && b <= 0x1D)
		{
			/* push [4D0Eh] ; call 023Fh ; table[58F4h + (b-19h)*4] = DX:AX;
			 * fn1EDA_10BB(NULL, 1, buf). */
			u32 blk = fn1EDA_023F(LG16(0x4D0E), 0x0000, 0x0000, &ds_552);
			u16 idx = (u16)(b - 0x19);
			LG16((u16)(0x58F4 + (u16)(idx * 4))) = (u16)blk;
			LG16((u16)(0x58F6 + (u16)(idx * 4))) = (u16)(blk >> 16);
			(void)fn1EDA_10BB((u8 *)0, 0x01,
			                  (u8 *)far_ptr(LG32((u16)(0x58F4 + (u16)((b - 0x19) * 4)))), abLoc82);
		}

		/* push 0 ; push 0 ; push 2Ch ; push 2Ch ; call 007Ch */
		engine_repaint_rect(0x002C, 0x002C, 0x0000, 0x0000);

		if (bLoc03 == 0x1D)
			break;
		++bLoc03;
	}

	/* push [bp-0FF7Ch](seg) ; push [bp-0FF7Ah](off) ; push [4D0Eh] ;
	 * call 0254h -> free the 03FE scratch block.  AL is passed on to 1051h. */
	{
		s16 ax_0254 = fn1EDA_0254(LG16(0x4D0E), wLoc86, wLoc84, 0,
		                          &dx_724, &ds_552);

		/* lea di,[bp+0FF7Eh] ; push ss ; push di ; call 1051h -- close. */
		(void)fn1EDA_1051((u8)ax_0254, abLoc82);
	}

	return 0x0000;   /* original returns the dropped DGROUP selector */
}

// 0C74:05B8: u8 * engine_scroll_blit(u16 * dsOut)
// Scroll/blit driver: when the odd counter 0x58BA is below the 10E1 measured
// bound, allocate the 13A3-sized window buffer, fill it once via 1E6B, then
// walk rows while the counter stays below and the next row probes empty,
// shifting the rectangle one row at a time and ticking 02D8.  Finally free
// the buffer.
u8 * engine_scroll_blit /* was fn0C74_05B8 */(u16 * dsOut)
{
	u16 wLoc06 = 0x0000;    /* [bp-0006h] bgi_clamp_rectangle_coords window size / 023F size */
	u16 wLoc04 = 0x0000;    /* [bp-0004h] 023F block offset                   */
	u16 wLoc02 = 0x0000;    /* [bp-0002h] 023F block segment                  */
	u16 ds_109 = 0x0000;    /* dropped DGROUP selector out of 1EDA calls      */
	u16 dx_373;             /* fn1EDA_0254 dxOut                              */
	u8  dl_370;
	u8  dl_371;

	/* call 10E1h ; cwd ; compare DX:AX(10E1) against DX:AX=[58BAh] */
	{
		u16 ax11 = bgi_get_text_rows();
		if (!(((ax11 & 0x8000u) == 0x0000) && (LG16(0x58BA) < ax11)))
			goto l05B8_06B5;
	}

	/* bgi_draw_line([58BAh]+1, [58B4h]) ; bgi_draw_line([58BAh]+1, [58B6h]) */
	if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001), LG16(0x58B4), &dl_370) != 0x00)
		goto l05B8_06B5;
	if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001), LG16(0x58B6), &dl_371) != 0x00)
		goto l05B8_06B5;

	/* push [58B4h] ; push [58B8h] ; push [58B6h] ; push [58BAh] ; call 13A3h */
	wLoc06 = bgi_clamp_rectangle_coords(LG16(0x58BA), LG16(0x58B6),
	                     LG16(0x58B8), LG16(0x58B4));
	/* push [bp-6h] ; call 023Fh -> DX:AX block */
	{
		u32 blk = fn1EDA_023F(wLoc06, 0x0000, 0x0000, &ds_109);
		wLoc04 = (u16)blk;
		wLoc02 = (u16)(blk >> 16);
	}
	/* push [58B4h]..[58BAh] ; les di,[bp-4h] ; push es/di ; call 1E6Bh */
	bgi_draw_clip_rectangle((u8 *)far_ptr(FAR_PTR(wLoc02, wLoc04)),
	            LG16(0x58BA), LG16(0x58B6), LG16(0x58B8), LG16(0x58B4));

	for (;;)
	{
		u8 dl_372;
		u8 dl_374;
		u16 ax11;

		/* call 10E1h ; cwd ; cmp DX:AX([58BAh]) vs DX:AX(10E1), signed */
		ax11 = bgi_get_text_rows();
		if (!(((ax11 & 0x8000u) == 0x0000) && (LG16(0x58BA) < ax11)))
			break;

		if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001), LG16(0x58B4),
		                &dl_372) != 0x00)
			break;
		if (bgi_draw_line((u16)(LG16(0x58BA) + 0x0001), LG16(0x58B6),
		                &dl_374) != 0x00)
			break;

		/* inc [58B8h] ; inc [58BAh] ; push [58B4h] ; push [58B8h] ;
		 * les di,[bp-4h] ; push es/di ; push 0 ; call 13D7h */
		LG16(0x58B8) = (u16)(LG16(0x58B8) + 0x0001);
		LG16(0x58BA) = (u16)(LG16(0x58BA) + 0x0001);
		bgi_signed_rectangle_intersect(0x00,
		            (u8 *)far_ptr(FAR_PTR(wLoc02, wLoc04)),
		            LG16(0x58B8), LG16(0x58B4));
		/* push [58E6h] ; call 02D8h */
		(void)engine_clock_tick(LG16(0x58E6), &ds_109);
	}

	/* push [bp-2h] ; push [bp-4h] ; push [bp-6h] ; call 0254h */
	(void)fn1EDA_0254(wLoc06, wLoc04, wLoc02, 0,
	                  &dx_373, &ds_109);

l05B8_06B5:
	*dsOut = 0x0000;   /* DGROUP selector dropped in the flat model */
	return (u8 *)0;    /* saved-BP artifact; no caller consumes it   */
}

// 0C74:06B7: u16 engine_arm_window_geometry(u16 wArg04, u16 wArg06)
// Arm the window geometry at DGROUP 0x58B1..0x58BA (from the two arguments),
// clear the target rectangle through bgi_signed_rectangle_intersect and run the 05B8 driver.
u16 engine_arm_window_geometry /* was fn0C74_06B7 */(u16 wArg04, u16 wArg06)
{
	u16 ds_58 = 0x0000;   /* dropped DGROUP selector out of engine_scroll_blit */
	u8 *p;                /* [58E8h] stored far pointer, flat           */

	LG16(0x5968) = 0x0001;
	LG8(0x58B3) = 0x00;
	LG8(0x58B1) = 0x01;
	LG16(0x58B4) = wArg06;
	LG16(0x58B8) = wArg04;
	LG16(0x58B6) = (u16)(wArg06 + 0x002B);
	LG16(0x58BA) = (u16)(wArg04 + 0x002B);
	LG8(0x596B) = 0x2C;
	LG8(0x596A) = 0x2C;

	/* push [bp+8h] ; push [bp+6h] ; les di,[58E8h] ; push es/di ; push 0 ;
	 * call 13D7h */
	p = far_ptr(LG32(0x58E8));
	bgi_signed_rectangle_intersect(0x00, p, wArg04, wArg06);

	/* push cs ; call 05B8h */
	(void)engine_scroll_blit(&ds_58);

	return ds_58;
}

// 0C74:070D: u8 * engine_scale_and_tick_clock(u16 wArg02, u16 wArg04, void * dsOut)
// Scale wArg02 by DGROUP:58E6 then divide by 9 (the original mul/cwd/idiv
// sequence), optionally bracket the two 02D8 ticks with 11C8:0354/033B.
u8 * engine_scale_and_tick_clock /* was fn0C74_070D */(u16 wArg02, u16 wArg04, void * dsOut)
{
	u16 ds_50 = 0x0000;   /* dropped DGROUP selector out of first 02D8  */
	u16 ds_82 = 0x0000;   /* dropped DGROUP selector out of second 02D8 */
	u16 prod;
	s32 dx_ax;
	long long t0 = 0;
	extern int rad_pace_trace_on(void);
	extern void rad_pace_trace(const char *, unsigned, unsigned, long long);

	if (rad_pace_trace_on())
	{
		struct timespec ts;
		clock_gettime(CLOCK_MONOTONIC, &ts);
		t0 = (long long)ts.tv_sec * 1000000000ll + ts.tv_nsec;
	}

	/* mov ax,[bp+4h] ; mul [58E6h] ; cwd ; mov cx,9 ; idiv cx */
	prod = (u16)(wArg02 * LG16(0x58E6));
	dx_ax = (s32)(s16)prod;
	wArg02 = (u16)(dx_ax / 0x0009);

	if (LG8(0x58B0) != 0x00)
		audio_write_opl3_register(wArg04);

	(void)engine_clock_tick(wArg02, &ds_50);

	if (LG8(0x58B0) != 0x00)
		(void)audio_get_soundcard_port();

	(void)engine_clock_tick(wArg02, &ds_82);

	if (rad_pace_trace_on())
	{
		struct timespec ts;
		long long t1;
		clock_gettime(CLOCK_MONOTONIC, &ts);
		t1 = (long long)ts.tv_sec * 1000000000ll + ts.tv_nsec;
		rad_pace_trace("070D", wArg02, wArg04, t1 - t0);
	}

	*(u16 *)dsOut = 0x0000;   /* DGROUP selector dropped in the flat model */
	return (u8 *)0;           /* saved-BP artifact; no caller consumes it   */
}

// 0C74:076B: u16 engine_scatter_starfield(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)
// Scatter a starfield into the rectangle (wArg0A,wArg08)-(wArg06,wArg04):
// try `area` random points; unoccupied ones are stored in the local point
// tables and drawn, occupied ones nudge a previously stored point.  Finally
// every stored point whose Y is not 0x1F4 is drawn.
//
// The original addresses its 0x30EE-byte frame by literal BP displacement
// with three intentionally overlapping arrays (X/Y word pairs indexed at
// bp-0x2724, a byte attribute array indexed at bp-0x30E5, and scalars at
// bp-0x30EE..bp-1).  abFrame[] reproduces that exact layout.
u16 engine_scatter_starfield /* was fn0C74_076B */(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)
{
	u8  abFrame[0x30EE];   /* [bp-0x30EE .. bp-1] whole local frame image */
	u16 dx_rt;             /* fn1EDA_0D80 dxOut scratch                   */
	u8 *es_849 = NULL;     /* fn1EDA_0CD4 esOut                           */
	u8  dl_scratch;        /* bgi_draw_line dlOut scratch                   */

#define F8(mag)    (*(u8  *)&abFrame[(0x30EE - (mag))])
#define F16(mag)   (*(u16 *)&abFrame[(0x30EE - (mag))])
#define AATTR(i)   F8(0x30E5 - (u16)(i))
#define AX_ARR(i)  F16(0x2724 - (u16)((u16)(i) << 2))
#define AY_ARR(i)  F16(0x2722 - (u16)((u16)(i) << 2))

	F16(0x06) = 0x0000;                                       /* count = 0 */

	/* wLoc30EA = (wArg06 - wArg0A)/2 + wArg0A  (x centre) */
	F16(0x30EA) = (u16)((((u16)(wArg06 - wArg0A)) >> 1) + wArg0A);
	/* wLoc30EC = (wArg04 - wArg08)/2 + wArg08  (y centre) */
	F16(0x30EC) = (u16)((((u16)(wArg04 - wArg08)) >> 1) + wArg08);
	/* wLoc30E6 = low16((wArg04-wArg08)*(wArg06-wArg0A)) * 15 */
	{
		u16 prod = (u16)((u16)(wArg04 - wArg08) * (u16)(wArg06 - wArg0A));
		F16(0x30E6) = (u16)(prod * 0x000F);
	}
	F16(0x0A) = wArg0A;
	F16(0x0C) = wArg08;
	F16(0x30EE) = F16(0x30E6);                                /* loop count */

	/* mov ax,1 ; cmp ax,[bp+0CF12h] ; jbe main */
	if (F16(0x30EE) >= 0x0001)
	{
		u16 wLoc04 = 0x0001;

		for (;;)
		{
			/* wLoc0E = rand(wArg06 - wArg0A + 1) + wArg0A */
			F16(0x0E) = (u16)(fn1EDA_0D80((u16)(wArg06 - wArg0A + 0x0001),
			                              &dx_rt) + wArg0A);
			/* wLoc10 = rand(wArg04 - wArg08 + 1) + wArg08 */
			F16(0x10) = (u16)(fn1EDA_0D80((u16)(wArg04 - wArg08 + 0x0001),
			                              &dx_rt) + wArg08);

			/* bgi_draw_line(wLoc10, wLoc0E) -> AL stored at bLoc30E7 */
			F8(0x30E7) = (u8)bgi_draw_line(F16(0x10), F16(0x0E), &dl_scratch);

			/* asm 0802h: call 0CD4h ; jz 081Ah -- the jz (table bit
			 * CLEAR, i.e. the color is destructible) takes the 081Ah
			 * erase-and-spawn-particle path; the bit-SET colors
			 * {0,5,Dh} take the 0918h star-nudge path.  fn1EDA_0CD4
			 * returns nonzero exactly when the bit is CLEAR, so the
			 * nonzero case must select 081Ah.  (The two paths were
			 * swapped here once, which left every bomb blast unable
			 * to destroy anything but already-empty pixels -- the
			 * mission-002 AUTO replay divergence.) */
			if (fn1EDA_0CD4(&g_seg0C74[0x074B], F8(0x30E7),
			                &es_849) != 0x00)
			{
				/* Destructible color (asm 081Ah): erase the pixel,
				 * then with probability 1/3 spawn a falling
				 * debris particle of the same color nearby. */
				bgi_get_line_attributes(0x00, F16(0x10), F16(0x0E));
				if (fn1EDA_0D80(0x0003, &dx_rt) == 0x0001)
				{
					if (LG8(0x58B0) != 0x00)
						audio_write_opl3_register((u16)fn1EDA_0D80(0x0064, &dx_rt));

					/* fn1E78_029C((s16)LG16(0x58E6) / 4) */
					(void)fn1E78_029C((u16)((s16)LG16(0x58E6) / 0x0004),
					                  &dx_rt);

					F16(0x0E) = (u16)(fn1EDA_0D80(0x012C, &dx_rt) +
					                  F16(0x30EA) - 0x0096);
					if (F16(0x0E) < 0x0001)
						F16(0x0E) = 0x0001;
					if (F16(0x0E) > 0x027E)
						F16(0x0E) = 0x027E;

					F16(0x10) = (u16)(F16(0x30EC) -
					                  (fn1EDA_0D80(0x00C8, &dx_rt) +
					                   0x0016));
					if (F16(0x10) < 0x0001)
						F16(0x10) = 0x0001;
					if (F16(0x10) > 0x0177)
						F16(0x10) = 0x0001;   /* asm: clamped to 1, not 177h */

					if (bgi_draw_line(F16(0x10), F16(0x0E),
					                &dl_scratch) == 0x00)
					{
						u16 n = (u16)(F16(0x06) + 0x0001);

						F16(0x06) = n;
						AATTR(n) = F8(0x30E7);
						AX_ARR(n) = F16(0x0E);
						AY_ARR(n) = F16(0x10);
						bgi_get_line_attributes(AATTR(n), AY_ARR(n), AX_ARR(n));
					}

					if (LG8(0x58B0) != 0x00)
						(void)audio_get_soundcard_port();
				}
			}
			else
			{
				/* Reserved color {0,5,Dh} (asm 0918h): nudge a
				 * stored particle one row down. */
				if (F16(0x06) != 0x0000)
				{
					u16 idx;

					F16(0x08) = (u16)(fn1EDA_0D80(F16(0x06),
					                              &dx_rt) + 0x0001);
					idx = F16(0x08);
					if (AY_ARR(idx) != 0x01F4)
					{
						/* draw at the stored point (colour 0) */
						bgi_get_line_attributes(0x00, AY_ARR(idx), AX_ARR(idx));
						F16(0x0E) = fn1EDA_0D80(0x0014, &dx_rt);
						if (F16(0x0E) == 0x0001 ||
						    bgi_draw_line((u16)(AY_ARR(idx) + 0x0001),
						                AX_ARR(idx),
						                &dl_scratch) != 0x00)
						{
							AY_ARR(idx) = 0x01F4;
						}
						else if ((u16)(AY_ARR(idx) + 0x0002) <
						         LG16(0x58BA))
						{
							AY_ARR(idx) = (u16)(AY_ARR(idx) + 0x0001);
							bgi_get_line_attributes(AATTR(idx), AY_ARR(idx),
							            AX_ARR(idx));
						}
						else
						{
							AY_ARR(idx) = 0x01F4;
						}
					}
				}
			}

			/* 09D5h: loop check */
			if (wLoc04 == F16(0x30EE))
				break;
			++wLoc04;
		}
	}

	/* 09E1h: redraw the stored points that were not retired. */
	if (F16(0x06) != 0x0000)
	{
		F16(0x30EE) = F16(0x06);
		if (F16(0x30EE) >= 0x0001)
		{
			F16(0x08) = 0x0001;
			for (;;)
			{
				if (AY_ARR(F16(0x08)) != 0x01F4)
					bgi_get_line_attributes(0x00, AY_ARR(F16(0x08)),
					            AX_ARR(F16(0x08)));
				if (F16(0x08) == F16(0x30EE))
					break;
				F16(0x08) = (u16)(F16(0x08) + 0x0001);
			}
		}
	}

#undef F8
#undef F16
#undef AATTR
#undef AX_ARR
#undef AY_ARR

	return 0x0000;   /* original leaves AX undefined; no caller consumes it */
}
