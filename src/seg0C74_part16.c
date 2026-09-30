/* seg0C74_part16.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 16 of N: functions 0C74:522C .. 0C74:552F (6 functions, ascending).
 *
 *   522C 5258 542B 54B1 54F0 552F
 *
 * Literal recovery from analysis/slices/0C74/0C74_<off>.asm (ground truth)
 * and the Reko slices 0C74_<off>.c; frozen prototypes from src/seg0C74.h
 * (analysis/summary/iface.tsv) adopted exactly:
 *
 *   u8   fn0C74_522C(u16 * bpOut, void * dsOut)
 *   u8   fn0C74_5258(u16 * dsOut)
 *   u8   fn0C74_542B(u16 * dsOut)
 *   u8   fn0C74_54B1(u16 * dxOut, u16 * bpOut, void * dsOut)
 *   u8   fn0C74_54F0(u16 * dxOut, u16 * bpOut, void * dsOut)
 *   void fn0C74_552F(void)
 *
 * See CONVENTIONS.md, analysis/SEGMAP.md and docs/notes-0C74.md ("## part 16").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   NONE directly.  No int 10h / int 16h / int 21h, no raw `in`/`out` port
 *   instruction, no __cli/__sti, no int 23h and no raw IVT dispatch occur in
 *   522C..552F.  Hardware is reached only indirectly through already-ported
 *   callees: the 1AB8 video/text driver (1E3C / 1E54 / 13A3 / 1E6B / 10F4 /
 *   1C32 / 1AF6 / 13D7), the 1EDA far-heap helpers (023F / 0254) and the 0C74
 *   game-core helpers 3236 / 2E5A / 05B8 / 396E / 45CE / 3F74 / 4999 / 4DAC /
 *   4FD7 / 3615 / 37C3 / 2AD9 / 2BBD (their own chunks own the port I/O,
 *   reached transitively via 02D8 / 070D -> 11C8).
 *
 * Flat-model / ABI adaptations (recorded in docs/notes-0C74.md "## part 16"):
 *   - Reko's bp_XXXX frame-pointer locals (re-bound after a callee whose AX
 *     return is the caller's saved BP) are the current function's own frame;
 *     they are folded back onto the literal [bp-..] locals below (documented
 *     convention, notes-0C74.md part 1 section 3).
 *   - bpOut / dsOut / dxOut register outputs are the caller's saved BP, the
 *     dropped DGROUP selector and the threaded DX artifact; each receives 0
 *     (part 1 section 3, parts 9/10/11).  Where the frozen prototype spells the
 *     slot `void *`, a 2-byte zero is written (part 2's fn0C74_070D precedent).
 *   - The `push cs` before each `call 05B8h` is the extra stack word of a near
 *     call into an `enter`-framed routine that never reads [bp+4]; it is
 *     dropped exactly as in part 2's fn0C74_06B7.
 */

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C74.h"
#include "seg1AB8.h"
#include "seg1EDA.h"

// 0C74:522C: u8 fn0C74_522C(u16 * bpOut, void * dsOut)
//
// Frame dispatch on the game-core state word [5968h]: state 1 runs the pull
// helper fn0C74_3236 into the [bp-1h] flag, state 0FFFFh runs fn0C74_2E5A,
// then the 05B8 scroll driver ticks.  Returns the [bp-1h] byte.
u8 fn0C74_522C(u16 *bpOut, void *dsOut)
{
	u8  bLoc01 = 0x01;      /* [bp-01h] return flag, init 1 (522C) */
	u16 bpTmp  = 0x0000;    /* fn0C74_3236 / 2E5A bpOut scratch */
	u16 dsTmp  = 0x0000;    /* dropped DGROUP selector scratch */

	/* 522C: mov ax,[5968h] ; cmp ax,1h ; jnz 5244h */
	switch (LG16(0x5968))
	{
	case 0x0001:
		/* l0C74_523C: call 3236h ; mov [bp-1h],al */
		bLoc01 = fn0C74_3236(&bpTmp, &dsTmp);
		break;
	case 0xFFFF:
		/* l0C74_5249: call 2E5Ah ; mov [bp-1h],al */
		bLoc01 = fn0C74_2E5A(&bpTmp, &dsTmp);
		break;
	}

	/* l0C74_524F: push cs ; call 05B8h */
	(void)fn0C74_05B8(&dsTmp);

	/* 5259: mov al,[bp-1h] ; leave ; retf */
	*bpOut = 0x0000;          /* saved-BP artifact (part 1 section 3) */
	*(u16 *)dsOut = 0x0000;   /* dropped DGROUP selector */
	return bLoc01;
}

// 0C74:5258: u8 fn0C74_5258(u16 * dsOut)
//
// Extended "pull-in" frame update.  Dispatches on [5968h] exactly as 522C but
// runs two edge probes per state (fn1AB8_1E3C) before invoking the state's
// pair of drawing helpers (396E/45CE for state 1, 3F74/4999 for 0FFFFh).  It
// then sets up the [bp-4h]/[bp-8h] rectangle edges from [596C]/[5970]
// according to the state, probes the [596Eh]+15h/+14h pixels, picks a start row
// [bp-6h] (either [596Eh]+15h with a 1E54 plot, or [596Eh]-1), and while the row
// exceeds 2 and the next 1E3C probe returns 8h, steps it back by 16h.  When the
// row changed it builds a 13A3-sized 023F block, blits it with 1E6B, sets the
// colour via 10F4/1C32, draws with 1AF6, runs the 2BBD grow animation, blits
// the block with 13D7 and frees it with 0254.  Returns the [bp-2h] flag byte.
u8 fn0C74_5258(u16 *dsOut)
{
	u8  bLoc02 = 0x01;      /* [bp-02h] state/result flag, init 1 (5258) */
	u16 wLoc04 = 0x0000;    /* [bp-04h] left  edge / blit x */
	u16 wLoc06 = 0x0000;    /* [bp-06h] scan row */
	u16 wLoc08 = 0x0000;    /* [bp-08h] right edge / blit x */
	u16 wLoc0A = 0x0000;    /* [bp-0Ah] saved start row */
	u16 wLoc0C = 0x0000;    /* [bp-0Ch] 023F block segment */
	u16 wLoc0E = 0x0000;    /* [bp-0Eh] 023F block offset */
	u16 wLoc10 = 0x0000;    /* [bp-10h] fn1AB8_13A3 size */
	u16 bpTmp  = 0x0000;    /* 396E / 45CE / 3F74 / 4999 bpOut scratch */
	u16 dsTmp  = 0x0000;    /* dropped DGROUP selector scratch */
	u16 dxTmp  = 0x0000;    /* fn1AB8_1AF6 / fn1EDA_0254 dxOut */
	u8  dlTmp  = 0x00;      /* fn1AB8_1E3C dlOut */
	{
		static int tr = -1;
		if (tr < 0) tr = (getenv("RAD_ROBOT_TRACE") != NULL);
		if (tr) fprintf(stderr, "ROBOT 5258 bomb entry: 5968=%d 53DE=%d B4=%u B8=%u\n",
		                (int)LG16(0x5968), (int)LG8(0x53DE),
		                LG16(0x58B4), LG16(0x58B8));
	}

	/* 5258: mov ax,[5968h] ; cmp ax,1h ; jnz 52A5h */
	switch (LG16(0x5968))
	{
	case 0x0001:
		/* 5268: fn1AB8_1E3C([58BAh], [58B6h]+1) ; jz 5297h */
		if (fn1AB8_1E3C(LG16(0x58BA), (u16)(LG16(0x58B6) + 0x0001),
		                &dlTmp) != 0x00)
		{
			/* 527A: fn1AB8_1E3C([58BAh]-0Ch, [58B6h]+0Ch) ; jz 5297h */
			if (fn1AB8_1E3C((u16)(LG16(0x58BA) - 0x000C),
			                (u16)(LG16(0x58B6) + 0x000C), &dlTmp) != 0x00)
			{
				/* l0C74_5291: call 396Eh ; mov [bp-2h],al */
				bLoc02 = fn0C74_396E(&bpTmp, &dsTmp);
			}
		}
		/* l0C74_5297: cmp byte [bp-2h],0 ; jz 52A3h */
		if (bLoc02 != 0x00)
		{
			/* l0C74_529D: call 45CEh ; mov [bp-2h],al */
			bLoc02 = fn0C74_45CE(&bpTmp, &dsTmp);
		}
		break;

	case 0xFFFF:
		/* 52AA: fn1AB8_1E3C([58BAh], [58B4h]-1) ; jz 52D9h */
		if (fn1AB8_1E3C(LG16(0x58BA), (u16)(LG16(0x58B4) - 0x0001),
		                &dlTmp) != 0x00)
		{
			/* 52BC: fn1AB8_1E3C([58BAh]-0Ch, [58B4h]-0Ch) ; jz 52D9h */
			if (fn1AB8_1E3C((u16)(LG16(0x58BA) - 0x000C),
			                (u16)(LG16(0x58B4) - 0x000C), &dlTmp) != 0x00)
			{
				/* l0C74_52D3: call 3F74h ; mov [bp-2h],al */
				bLoc02 = fn0C74_3F74(&bpTmp, &dsTmp);
			}
		}
		/* l0C74_52D9: cmp byte [bp-2h],0 ; jz 52E5h */
		if (bLoc02 != 0x00)
		{
			/* l0C74_52DF: call 4999h ; mov [bp-2h],al */
			bLoc02 = fn0C74_4999(&bpTmp, &dsTmp);
		}
		break;
	}

	/* l0C74_52E5: cmp byte [bp-2h],0 ; jnz 52EEh */
	if (bLoc02 == 0x00)
		goto l0C74_5420;         /* l0C74_52EB: jmp 5420h */

	/* 52EE: cmp word [5968h],1h ; jnz 5300h */
	if (LG16(0x5968) == 0x0001)
		wLoc04 = (u16)(LG16(0x5970) - 0x0015);   /* 52F5 */
	else
		wLoc04 = LG16(0x596C);                    /* 5300 */
	/* 5306: cmp word [5968h],1h ; jnz 5315h */
	if (LG16(0x5968) == 0x0001)
		wLoc08 = LG16(0x5970);                    /* 530D */
	else
		wLoc08 = (u16)(LG16(0x596C) + 0x0015);    /* 5315 */

	/* 531E: fn1AB8_1E3C([596Eh]+15h, [bp-8h]) ; jnz 535Ch */
	if (fn1AB8_1E3C((u16)(LG16(0x596E) + 0x0015), wLoc08, &dlTmp) == 0x00)
	{
		/* 5331: fn1AB8_1E3C([596Eh]+14h, [bp-8h]) ; jz 535Ch */
		if (fn1AB8_1E3C((u16)(LG16(0x596E) + 0x0014), wLoc08,
		                &dlTmp) != 0x00)
		{
			/* 5344: mov [bp-6h],[596Eh]+15h ;
			 *       fn1AB8_1E54(8h, [bp-6h], [bp-8h]) ; jmp 5363h */
			wLoc06 = (u16)(LG16(0x596E) + 0x0015);
			(void)fn1AB8_1E54(0x08, wLoc06, wLoc08);
			goto l0C74_5363;
		}
	}
	/* l0C74_535C: mov ax,[596Eh] ; dec ax ; mov [bp-6h],ax */
	wLoc06 = (u16)(LG16(0x596E) - 0x0001);

l0C74_5363:
	/* 5363: mov ax,[bp-6h] ; mov [bp-0Ah],ax */
	wLoc0A = wLoc06;

	/* l0C74_5369: while ([bp-6h] > 2h) {
	 *   if (fn1AB8_1E3C([bp-6h],[bp-8h]) != 8h) break;
	 *   [bp-6h] -= 16h; } */
	while (wLoc06 > 0x0002)
	{
		if (fn1AB8_1E3C(wLoc06, wLoc08, &dlTmp) != 0x08)
			break;
		wLoc06 = (u16)(wLoc06 - 0x0016);
	}

	/* l0C74_5385: cmp ax,[bp-0Ah] ; jnz 5390h */
	if (wLoc06 == wLoc0A)
		goto l0C74_5420;         /* l0C74_538D: jmp 5420h */

	/* 5390: push [bp-4h] ; push [bp-6h]-1 ; push [bp-8h] ; push [bp-6h] ;
	 *       call far 13A3h ; mov [bp-10h],ax */
	wLoc10 = fn1AB8_13A3(wLoc06, wLoc08, (u16)(wLoc06 - 0x0001), wLoc04);

	/* 53A6: push [bp-10h] ; call far 023Fh ;
	 *       mov [bp-0Eh],ax ; mov [bp-0Ch],dx */
	{
		u32 blk = fn1EDA_023F(wLoc10, 0x0000, 0x0000, &dsTmp);
		wLoc0E = (u16)blk;
		wLoc0C = (u16)(blk >> 16);
	}

	/* 53B3: push [bp-4h] ; push [bp-6h]-1 ; push [bp-8h] ; push [bp-6h] ;
	 *       les di,[bp-0Eh] ; push es ; push di ; call far 1E6Bh */
	fn1AB8_1E6B((u8 *)far_ptr(FAR_PTR(wLoc0C, wLoc0E)),
	            wLoc06, wLoc08, (u16)(wLoc06 - 0x0001), wLoc04);

	/* 53D0: push 0h ; push 0h ; push 1h ; call far 10F4h */
	fn1AB8_10F4(0x0001, 0x0000, 0x0000);
	/* 53E2: push 0h ; call far 1C32h */
	(void)fn1AB8_1C32(0x00);

	/* 53E9: push [bp-4h] ; push [bp-6h] ; push [bp-8h] ; push [bp-6h] ;
	 *       call far 1AF6h */
	(void)fn1AB8_1AF6(wLoc06, wLoc08, wLoc06, wLoc04, &dxTmp);

	/* 53FB: push [bp-4h] ; push [bp-6h] ; push [bp-8h] ; push [bp-0Ah] ;
	 *       call 2BBDh */
	(void)fn0C74_2BBD(wLoc0A, wLoc08, wLoc06, wLoc04);

	/* 5405: push [bp-4h] ; push [bp-6h]-1 ; les di,[bp-0Eh] ; push es ;
	 *       push di ; push 0h ; call far 13D7h */
	(void)fn1AB8_13D7(0x00,
	                  (u8 *)far_ptr(FAR_PTR(wLoc0C, wLoc0E)),
	                  (u16)(wLoc06 - 0x0001), wLoc04);

	/* 5417: push [bp-0Ch] ; push [bp-0Eh] ; push [bp-10h] ; call far 0254h */
	(void)fn1EDA_0254(wLoc10, wLoc0E, wLoc0C, 0,
	                  &dxTmp, &dsTmp);

l0C74_5420:
	/* 5420: mov al,[bp-2h] ; mov [bp-1h],al ; mov al,[bp-1h] ; leave ; retf */
	*dsOut = 0x0000;          /* dropped DGROUP selector (part 1 section 3) */
	return bLoc02;
}

// 0C74:542B: u8 fn0C74_542B(u16 * dsOut)
//
// Frame "retract" update.  State 1 probes ([58BAh]+1,[58B6h]+1) and
// ([58BAh]-1,[58B6h]+1); if both are empty it runs fn0C74_4FD7 then fn0C74_3615
// (the [bp-1h] flag comes from 4FD7), otherwise clears the flag.  State 0FFFFh
// does the same with ([58BAh]±1,[58B4h]-1) and fn0C74_4DAC / fn0C74_37C3.
u8 fn0C74_542B(u16 *dsOut)
{
	u8  bLoc01 = 0x01;      /* [bp-01h] return flag, init 1 (542B) */
	u16 bpTmp  = 0x0000;    /* 4FD7 / 4DAC bpOut scratch */
	u16 dsTmp  = 0x0000;    /* dropped DGROUP selector scratch */
	u16 dxTmp  = 0x0000;    /* fn0C74_3615 / 37C3 dxOut scratch */
	u8  dlTmp  = 0x00;      /* fn1AB8_1E3C dlOut */

	/* 542B: mov ax,[5968h] ; cmp ax,1h ; jnz 5472h */
	switch (LG16(0x5968))
	{
	case 0x0001:
		/* 543B: fn1AB8_1E3C([58BAh]+1, [58B6h]+1) ; jnz 546Ch */
		if (fn1AB8_1E3C((u16)(LG16(0x58BA) + 0x0001),
		                (u16)(LG16(0x58B6) + 0x0001), &dlTmp) != 0x00)
		{
			bLoc01 = 0x00;         /* l0C74_546C */
			break;
		}
		/* 544E: fn1AB8_1E3C([58BAh]-1, [58B6h]+1) ; jnz 546Ch */
		if (fn1AB8_1E3C((u16)(LG16(0x58BA) - 0x0001),
		                (u16)(LG16(0x58B6) + 0x0001), &dlTmp) != 0x00)
		{
			bLoc01 = 0x00;         /* l0C74_546C */
			break;
		}
		/* l0C74_5461: call 4FD7h ; mov [bp-1h],al ; call 3615h */
		bLoc01 = fn0C74_4FD7(&bpTmp, &dsTmp);
		(void)fn0C74_3615(&dxTmp, &bpTmp, &dsTmp);
		break;

	case 0xFFFF:
		/* 5477: fn1AB8_1E3C([58BAh]+1, [58B4h]-1) ; jnz 54A8h */
		if (fn1AB8_1E3C((u16)(LG16(0x58BA) + 0x0001),
		                (u16)(LG16(0x58B4) - 0x0001), &dlTmp) != 0x00)
		{
			bLoc01 = 0x00;         /* l0C74_54A8 */
			break;
		}
		/* 548A: fn1AB8_1E3C([58BAh]-1, [58B4h]-1) ; jnz 54A8h */
		if (fn1AB8_1E3C((u16)(LG16(0x58BA) - 0x0001),
		                (u16)(LG16(0x58B4) - 0x0001), &dlTmp) != 0x00)
		{
			bLoc01 = 0x00;         /* l0C74_54A8 */
			break;
		}
		/* l0C74_549D: call 4DACh ; mov [bp-1h],al ; call 37C3h */
		bLoc01 = fn0C74_4DAC(&bpTmp, &dsTmp);
		(void)fn0C74_37C3(&dxTmp, &bpTmp, &dsTmp);
		break;
	}

	/* l0C74_54AC: mov al,[bp-1h] ; leave ; retf */
	*dsOut = 0x0000;          /* dropped DGROUP selector (part 1 section 3) */
	return bLoc01;
}

// 0C74:54B1: u8 fn0C74_54B1(u16 * dxOut, u16 * bpOut, void * dsOut)
//
// Latch [58BCh]=1, then probe ([58BAh]+1,[58B6h]+1) and
// ([58BAh]+1,[58B6h]+17h); when the first is empty and the second is occupied
// run fn0C74_2AD9.  Always tail-runs fn0C74_3615 and returns its [bp-1h] byte.
u8 fn0C74_54B1(u16 *dxOut, u16 *bpOut, void *dsOut)
{
	u8  bLoc01 = 0x00;      /* [bp-01h] fn0C74_3615 result */
	u16 bpTmp  = 0x0000;    /* fn0C74_3615 bpOut scratch */
	u16 dsTmp  = 0x0000;    /* dropped DGROUP selector scratch */
	u16 dxTmp  = 0x0000;    /* fn0C74_3615 dxOut scratch */
	u8  dlTmp  = 0x00;      /* fn1AB8_1E3C dlOut */

	/* 54B1: mov byte [58BCh],1h */
	LG8(0x58BC) = 0x01;

	/* 54B8: fn1AB8_1E3C([58BAh]+1, [58B6h]+1) ; jnz 54E5h */
	if (fn1AB8_1E3C((u16)(LG16(0x58BA) + 0x0001),
	                (u16)(LG16(0x58B6) + 0x0001), &dlTmp) == 0x00)
	{
		/* 54CD: fn1AB8_1E3C([58BAh]+1, [58B6h]+17h) ; jz 54E5h */
		if (fn1AB8_1E3C((u16)(LG16(0x58BA) + 0x0001),
		                (u16)(LG16(0x58B6) + 0x0017), &dlTmp) != 0x00)
		{
			/* l0C74_54E2: call 2AD9h */
			(void)fn0C74_2AD9(&dsTmp);
		}
	}

	/* l0C74_54E5: call 3615h ; mov [bp-1h],al */
	bLoc01 = fn0C74_3615(&dxTmp, &bpTmp, &dsTmp);

	/* l54EC: mov al,[bp-1h] ; leave ; retf */
	*dxOut = 0x0000;          /* threaded DX artifact (parts 9/10) */
	*bpOut = 0x0000;          /* saved-BP artifact (part 1 section 3) */
	*(u16 *)dsOut = 0x0000;   /* dropped DGROUP selector */
	return bLoc01;
}

// 0C74:54F0: u8 fn0C74_54F0(u16 * dxOut, u16 * bpOut, void * dsOut)
//
// Mirror of 54B1 along the other axis: latch [58BCh]=1, probe
// ([58BAh]+1,[58B4h]-1) and ([58BAh]+1,[58B4h]-17h); when the first is empty
// and the second is occupied run fn0C74_2AD9.  Always tail-runs fn0C74_37C3
// and returns its [bp-1h] byte.
u8 fn0C74_54F0(u16 *dxOut, u16 *bpOut, void *dsOut)
{
	u8  bLoc01 = 0x00;      /* [bp-01h] fn0C74_37C3 result */
	u16 bpTmp  = 0x0000;    /* fn0C74_37C3 bpOut scratch */
	u16 dsTmp  = 0x0000;    /* dropped DGROUP selector scratch */
	u16 dxTmp  = 0x0000;    /* fn0C74_37C3 dxOut scratch */
	u8  dlTmp  = 0x00;      /* fn1AB8_1E3C dlOut */

	/* 54F0: mov byte [58BCh],1h */
	LG8(0x58BC) = 0x01;

	/* 54F7: fn1AB8_1E3C([58BAh]+1, [58B4h]-1) ; jnz 5524h */
	if (fn1AB8_1E3C((u16)(LG16(0x58BA) + 0x0001),
	                (u16)(LG16(0x58B4) - 0x0001), &dlTmp) == 0x00)
	{
		/* 550C: fn1AB8_1E3C([58BAh]+1, [58B4h]-17h) ; jz 5524h */
		if (fn1AB8_1E3C((u16)(LG16(0x58BA) + 0x0001),
		                (u16)(LG16(0x58B4) - 0x0017), &dlTmp) != 0x00)
		{
			/* l0C74_5521: call 2AD9h */
			(void)fn0C74_2AD9(&dsTmp);
		}
	}

	/* l0C74_5524: call 37C3h ; mov [bp-1h],al */
	bLoc01 = fn0C74_37C3(&dxTmp, &bpTmp, &dsTmp);

	/* l552B: mov al,[bp-1h] ; leave ; retf */
	*dxOut = 0x0000;          /* threaded DX artifact (parts 9/10) */
	*bpOut = 0x0000;          /* saved-BP artifact (part 1 section 3) */
	*(u16 *)dsOut = 0x0000;   /* dropped DGROUP selector */
	return bLoc01;
}

// 0C74:552F: void fn0C74_552F(void)
//
// CRT startup hook (called from fn0800_4255): arm the input-poll latch
// DGROUP:58B2h.
void fn0C74_552F(void)
{
	/* 552F: push bp ; mov bp,sp ; mov byte [58B2h],1h ; leave ; retf */
	LG8(0x58B2) = 0x01;
}
