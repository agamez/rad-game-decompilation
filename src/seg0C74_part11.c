/* seg0C74_part11.c -- RAD V3.1 preservation port, segment 0C74 (GAME CORE),
 * part 11 of N: function 0C74:396E only.
 *
 * Literal recovery from analysis/slices/0C74/0C74_396E.asm (ground truth) and
 * the Reko slice 0C74_396E.c; frozen prototype from src/seg0C74.h
 * (analysis/summary/iface.tsv) adopted exactly:
 *
 *   u8 fn0C74_396E(void *bpOut, u16 *dsOut)
 *
 * See CONVENTIONS.md, analysis/SEGMAP.md and docs/notes-0C74.md ("## part 11").
 *
 * Hardware / DOS services replaced (CONVENTIONS.md rule 4):
 *   NONE directly.  No int 10h/16h/21h, no raw in/out port instruction, no
 *   __cli/__sti, no int 23h and no raw IVT dispatch occur in 396E.  Every
 *   hardware-touching action is reached indirectly through already-ported
 *   callees: the 1AB8 video/text driver (10F4/1AF6/1C32/1E3C/1E54) and the
 *   0C74 tick/frame drivers 070D / 02D8.
 *
 * Flat-model / ABI adaptations (recorded in docs/notes-0C74.md "## part 11"):
 *   - Reko's bp_XXXX frame-pointer locals (re-bound after each fn0C74_070D /
 *     02D8 call whose AX return is the caller's saved BP) are the current
 *     function's own frame; they are folded back onto the literal locals below
 *     (documented convention, notes-0C74.md part 1 section 3).
 *   - bpOut / dsOut register outputs are the caller's saved BP and the dropped
 *     DGROUP selector; both receive 0 (notes-0C74.md part 1 section 3).
 */

#include <stddef.h>
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0C74.h"
#include "seg1AB8.h"

/* 0C74:396E: u8 fn0C74_396E(void * bpOut, u16 * dsOut)
 *
 * Game-core "pull-in" update.  First scans a row upward (drawing a 13h/12h
 * rectangle each step through 1AF6) until either the row reaches 39h, a 1E3C
 * edge probe fires, or the row passes 27Eh.  If the row did not reach 39h it
 * erases the drawn column back down and clears the [bp-1] flag.  If it did
 * reach 39h it runs the two-stage bar animation: a growing bar (two 1AF6
 * strokes plus three 4D0Fh-table strokes per step), the bar growth/shrink
 * phases built from 1E54/1AF6, a 02D8 wait and the closing erase pass.  Every
 * path bumps [58B4h] once.  Returns the [bp-1] byte. */
u8 fn0C74_396E(void *bpOut, u16 *dsOut)
{
	u8  bLoc01 = 0x01;      /* [bp-01h] return flag (396E: mov [bp-1h],1h) */
	u8  bLoc02 = 0x1D;      /* [bp-02h] scan row counter, init 1Dh */
	u8  bLoc03 = 0x00;      /* [bp-03h] stage/loop counter */
	u16 wLoc06 = 0x0000;    /* [bp-06h] bar X origin */
	u16 wLoc08 = 0x0000;    /* [bp-08h] bar X origin 2 */
	u16 di     = 0x0000;    /* asm DI: 4D0Fh table index (bLoc03 +/- k) */
	u8  dlTmp  = 0x00;      /* fn1AB8_1E3C dlOut */
	u16 dxTmp  = 0x0000;    /* fn1AB8_1AF6 dxOut */
	u16 dsTmp  = 0x0000;    /* fn0C74_02D8 dsOut */
	void *dsv  = NULL;      /* fn0C74_070D dsOut */

	/* 3971: dec word ptr [58B4h] */
	LG16(0x58B4) = (u16)(LG16(0x58B4) - 0x0001);
	/* push 0h ; push 0h ; push 1h ; call far 1AB8h:10F4h */
	fn1AB8_10F4(0x0001, 0x0000, 0x0000);
	/* push 0Ch ; call far 1AB8h:1C32h */
	(void)fn1AB8_1C32(0x0C);
	/* 398D: mov byte ptr [bp-2h],1Dh */
	bLoc02 = 0x1D;

	/* l0C74_3990: scan rows while the probe is empty and the row stays
	 * below 27Eh; stop early when the row hits 39h. */
	do
	{
		/* 3990: fn1AB8_1AF6([58B8h]+13h, bLoc02+[58B4h],
		 *                   [58B8h]+12h, bLoc02+[58B4h]) */
		(void)fn1AB8_1AF6((u16)(LG16(0x58B8) + 0x0013),
		                  (u16)((u16)bLoc02 + LG16(0x58B4)),
		                  (u16)(LG16(0x58B8) + 0x0012),
		                  (u16)((u16)bLoc02 + LG16(0x58B4)),
		                  &dxTmp);
		/* 39B4: inc byte ptr [bp-2h] */
		bLoc02 = (u8)(bLoc02 + 0x01);
		/* push 12Ch ; push 14h ; call 070Dh */
		(void)fn0C74_070D(0x0014, 0x012C, &dsv);
		/* 39C0: cmp byte ptr [bp-2h],39h ; jz 39F0h */
		if (bLoc02 == 0x39)
			break;
		/* 39C8: fn1AB8_1E3C([58B8h]+13h, bLoc02+[58B4h]) ; jnz 39F0h */
		if (fn1AB8_1E3C((u16)(LG16(0x58B8) + 0x0013),
		                (u16)((u16)bLoc02 + LG16(0x58B4)),
		                &dlTmp) != 0)
			break;
		/* 39E2: cmp (bLoc02+[58B4h]),27Eh ; jc 3990h */
	} while ((u16)((u16)bLoc02 + LG16(0x58B4)) < 0x027E);

	/* l0C74_39F0: cmp byte ptr [bp-2h],39h ; jz 3A4Fh */
	if (bLoc02 != 0x39)
	{
		/* l0C74_39F6: push 0h ; call far 1AB8h:1C32h */
		(void)fn1AB8_1C32(0x00);
		/* 39FB: mov al,[bp-2h] ; xor ah,ah ; dec ax ; cmp al,1Dh ;
		 *       jc 3A44h */
		if ((u8)(bLoc02 - 0x01) >= 0x1D)
		{
			/* l0C74_3A07: mov [bp-3h],al */
			bLoc03 = (u8)(bLoc02 - 0x01);
			for (;;)
			{
				/* l0C74_3A0F: fn1AB8_1AF6([58B8h]+13h,
				 *   bLoc03+[58B4h], [58B8h]+12h, bLoc03+[58B4h]) */
				(void)fn1AB8_1AF6((u16)(LG16(0x58B8) + 0x0013),
				                  (u16)((u16)bLoc03 + LG16(0x58B4)),
				                  (u16)(LG16(0x58B8) + 0x0012),
				                  (u16)((u16)bLoc03 + LG16(0x58B4)),
				                  &dxTmp);
				(void)fn0C74_070D(0x0014, 0x012C, &dsv);
				/* 3A3C: cmp byte ptr [bp-3h],1Dh ; jnz 3A0Ch */
				if (bLoc03 == 0x1D)
					break;
				/* l0C74_3A0C: dec byte ptr [bp-3h] */
				bLoc03 = (u8)(bLoc03 - 0x01);
			}
		}
		/* l0C74_3A44: inc word ptr [58B4h] ; mov [bp-1h],0h */
		LG16(0x58B4) = (u16)(LG16(0x58B4) + 0x0001);
		bLoc01 = 0x00;
	}
	else
	{
		/* l0C74_3A4F: push 0Ah ; call far 1AB8h:1C32h */
		(void)fn1AB8_1C32(0x0A);
		/* 3A54: fn1AB8_1AF6([58B8h]+12h, [58B4h]+36h,
		 *                   [58B8h]+12h, [58B4h]+2Ah) */
		(void)fn1AB8_1AF6((u16)(LG16(0x58B8) + 0x0012),
		                  (u16)(LG16(0x58B4) + 0x0036),
		                  (u16)(LG16(0x58B8) + 0x0012),
		                  (u16)(LG16(0x58B4) + 0x002A),
		                  &dxTmp);
		(void)fn0C74_070D(0x0014, 0x012C, &dsv);
		/* 3A76: fn1AB8_1AF6([58B8h]+11h, [58B4h]+36h,
		 *                   [58B8h]+11h, [58B4h]+2Ah) */
		(void)fn1AB8_1AF6((u16)(LG16(0x58B8) + 0x0011),
		                  (u16)(LG16(0x58B4) + 0x0036),
		                  (u16)(LG16(0x58B8) + 0x0011),
		                  (u16)(LG16(0x58B4) + 0x002A),
		                  &dxTmp);
		(void)fn0C74_070D(0x0014, 0x012C, &dsv);
		/* 3A9C: mov byte ptr [bp-3h],3h */
		bLoc03 = 0x03;

		/* l0C74_3AB1: grow the bar; three 1AF6 strokes per step:
		 * di = bLoc03-2, then bLoc03, then bLoc03-1. */
		for (;;)
		{
			(void)fn1AB8_1C32(0x00);
			di = (u16)((u16)bLoc03 - 0x0002);
			(void)fn1AB8_1AF6((u16)(LG8((u16)(di + 0x4D4B)) + LG16(0x58B8)),
			                  (u16)(LG8((u16)(di + 0x4D37)) + LG16(0x58B4)),
			                  (u16)(LG8((u16)(di + 0x4D23)) + LG16(0x58B8)),
			                  (u16)(LG8((u16)(di + 0x4D0F)) + LG16(0x58B4)),
			                  &dxTmp);
			(void)fn1AB8_1C32(0x0A);
			di = (u16)bLoc03;
			(void)fn1AB8_1AF6((u16)(LG8((u16)(di + 0x4D4B)) + LG16(0x58B8)),
			                  (u16)(LG8((u16)(di + 0x4D37)) + LG16(0x58B4)),
			                  (u16)(LG8((u16)(di + 0x4D23)) + LG16(0x58B8)),
			                  (u16)(LG8((u16)(di + 0x4D0F)) + LG16(0x58B4)),
			                  &dxTmp);
			di = (u16)((u16)bLoc03 - 0x0001);
			(void)fn1AB8_1AF6((u16)(LG8((u16)(di + 0x4D4B)) + LG16(0x58B8)),
			                  (u16)(LG8((u16)(di + 0x4D37)) + LG16(0x58B4)),
			                  (u16)(LG8((u16)(di + 0x4D23)) + LG16(0x58B8)),
			                  (u16)(LG8((u16)(di + 0x4D0F)) + LG16(0x58B4)),
			                  &dxTmp);
			/* push 190h ; push 32h ; call 070Dh */
			(void)fn0C74_070D(0x0032, 0x0190, &dsv);
			/* 3BBD: cmp byte ptr [bp-3h],14h ; jz 3BC3h */
			if (bLoc03 == 0x14)
				break;
			/* l0C74_3AAE: inc byte ptr [bp-3h] */
			bLoc03 = (u8)(bLoc03 + 0x01);
		}

		/* l0C74_3BC3: fn1AB8_1E54(0, [58B8h]+11h, [58B4h]+36h) */
		(void)fn1AB8_1E54(0x00,
		                  (u16)(LG16(0x58B8) + 0x0011),
		                  (u16)(LG16(0x58B4) + 0x0036));
		/* 3BCF: fn1AB8_1AF6([58B8h]+10h, [58B4h]+37h,
		 *                   [58B8h]+6h,  [58B4h]+37h) */
		(void)fn1AB8_1AF6((u16)(LG16(0x58B8) + 0x0010),
		                  (u16)(LG16(0x58B4) + 0x0037),
		                  (u16)(LG16(0x58B8) + 0x0006),
		                  (u16)(LG16(0x58B4) + 0x0037),
		                  &dxTmp);
		/* 3BE7: mov ax,[58B8h]+6h ; mov [bp-6h],ax */
		wLoc06 = (u16)(LG16(0x58B8) + 0x0006);
		/* 3BEF: mov ax,[58B8h]+14h ; mov [bp-8h],ax */
		wLoc08 = (u16)(LG16(0x58B8) + 0x0014);
		/* 3BF7: mov byte ptr [bp-3h],1h */
		bLoc03 = 0x01;

		/* l0C74_3C14: first shrink pass (bar row to [58B4h]+37h). */
		for (;;)
		{
			(void)fn1AB8_1C32(0x00);
			(void)fn1AB8_1AF6(wLoc06,
			                  (u16)(LG16(0x58B4) + 0x0038),
			                  wLoc06,
			                  (u16)(LG16(0x58B4) + 0x0037),
			                  &dxTmp);
			(void)fn1AB8_1C32(0x0A);
			(void)fn1AB8_1AF6(wLoc08,
			                  (u16)(LG16(0x58B4) + 0x0038),
			                  wLoc08,
			                  (u16)(LG16(0x58B4) + 0x0037),
			                  &dxTmp);
			/* 3C4F: fn1AB8_1E54(0, wLoc08, [58B4h]+36h) */
			(void)fn1AB8_1E54(0x00, wLoc08, (u16)(LG16(0x58B4) + 0x0036));
			/* 3C63: fn1AB8_1E54(0, wLoc08, [58B4h]+39h) */
			(void)fn1AB8_1E54(0x00, wLoc08, (u16)(LG16(0x58B4) + 0x0039));
			/* 3C77: inc word ptr [bp-6h] ; inc word ptr [bp-8h] */
			wLoc06 = (u16)(wLoc06 + 0x0001);
			wLoc08 = (u16)(wLoc08 + 0x0001);
			/* push 64h ; push 64h ; call 070Dh */
			(void)fn0C74_070D(0x0064, 0x0064, &dsv);
			/* 3C83: cmp byte ptr [bp-3h],0Bh ; jnz 3C11h */
			if (bLoc03 == 0x0B)
				break;
			/* l0C74_3C11: inc byte ptr [bp-3h] */
			bLoc03 = (u8)(bLoc03 + 0x01);
		}

		/* l0C74_3C89: climb pass, 02D8 wait, then latch the next origin. */
		(void)fn1AB8_1C32(0x0A);
		(void)fn1AB8_1AF6(wLoc08,
		                  (u16)(LG16(0x58B4) + 0x0038),
		                  wLoc08,
		                  (u16)(LG16(0x58B4) + 0x0037),
		                  &dxTmp);
		(void)fn1AB8_1E54(0x00, wLoc08, (u16)(LG16(0x58B4) + 0x0036));
		(void)fn1AB8_1E54(0x00, wLoc08, (u16)(LG16(0x58B4) + 0x0039));
		/* 3CB0: push 1F4h ; call 02D8h */
		(void)fn0C74_02D8(0x01F4, &dsTmp);
		(void)fn1AB8_1C32(0x00);
		(void)fn1AB8_1AF6(wLoc08,
		                  (u16)(LG16(0x58B4) + 0x0038),
		                  wLoc08,
		                  (u16)(LG16(0x58B4) + 0x0037),
		                  &dxTmp);
		/* 3CDD: mov [bp-6h],[58B8h]+10h */
		wLoc06 = (u16)(LG16(0x58B8) + 0x0010);
		/* 3CE7: mov [bp-8h],[58B8h]+1Eh */
		wLoc08 = (u16)(LG16(0x58B8) + 0x001E);
		/* 3CF1: mov byte ptr [bp-3h],1h */
		bLoc03 = 0x01;

		/* l0C74_3D0C: second shrink pass (both origins step left). */
		for (;;)
		{
			(void)fn1AB8_1C32(0x0A);
			(void)fn1AB8_1AF6(wLoc06,
			                  (u16)(LG16(0x58B4) + 0x0038),
			                  wLoc06,
			                  (u16)(LG16(0x58B4) + 0x0037),
			                  &dxTmp);
			(void)fn1AB8_1C32(0x00);
			(void)fn1AB8_1AF6(wLoc08,
			                  (u16)(LG16(0x58B4) + 0x0038),
			                  wLoc08,
			                  (u16)(LG16(0x58B4) + 0x0037),
			                  &dxTmp);
			/* 3D3B: dec word ptr [bp-6h] ; dec word ptr [bp-8h] */
			wLoc06 = (u16)(wLoc06 - 0x0001);
			wLoc08 = (u16)(wLoc08 - 0x0001);
			(void)fn0C74_070D(0x0064, 0x0064, &dsv);
			if (bLoc03 == 0x0B)
				break;
			/* l0C74_3D09: inc byte ptr [bp-3h] */
			bLoc03 = (u8)(bLoc03 + 0x01);
		}

		/* l0C74_3D5F: mov byte ptr [bp-3h],14h ; closing bar pass;
		 * di = bLoc03, then bLoc03-2, then bLoc03-1. */
		bLoc03 = 0x14;
		for (;;)
		{
			/* l0C74_3D68 */
			(void)fn1AB8_1C32(0x00);
			di = (u16)bLoc03;
			(void)fn1AB8_1AF6((u16)(LG8((u16)(di + 0x4D4B)) + LG16(0x58B8)),
			                  (u16)(LG8((u16)(di + 0x4D37)) + LG16(0x58B4)),
			                  (u16)(LG8((u16)(di + 0x4D23)) + LG16(0x58B8)),
			                  (u16)(LG8((u16)(di + 0x4D0F)) + LG16(0x58B4)),
			                  &dxTmp);
			(void)fn1AB8_1C32(0x0A);
			di = (u16)((u16)bLoc03 - 0x0002);
			(void)fn1AB8_1AF6((u16)(LG8((u16)(di + 0x4D4B)) + LG16(0x58B8)),
			                  (u16)(LG8((u16)(di + 0x4D37)) + LG16(0x58B4)),
			                  (u16)(LG8((u16)(di + 0x4D23)) + LG16(0x58B8)),
			                  (u16)(LG8((u16)(di + 0x4D0F)) + LG16(0x58B4)),
			                  &dxTmp);
			di = (u16)((u16)bLoc03 - 0x0001);
			(void)fn1AB8_1AF6((u16)(LG8((u16)(di + 0x4D4B)) + LG16(0x58B8)),
			                  (u16)(LG8((u16)(di + 0x4D37)) + LG16(0x58B4)),
			                  (u16)(LG8((u16)(di + 0x4D23)) + LG16(0x58B8)),
			                  (u16)(LG8((u16)(di + 0x4D0F)) + LG16(0x58B4)),
			                  &dxTmp);
			(void)fn0C74_070D(0x0032, 0x0190, &dsv);
			/* 3E74: cmp byte ptr [bp-3h],3h ; jz 3E7Ah */
			if (bLoc03 == 0x03)
				break;
			/* l0C74_3D65: dec byte ptr [bp-3h] */
			bLoc03 = (u8)(bLoc03 - 0x01);
		}

		/* l0C74_3E7A: wipe the closing rows and restore the colour. */
		/* 3E7A: fn1AB8_1E54(0, [58B8h]+10h, [58B4h]+37h) */
		(void)fn1AB8_1E54(0x00,
		                  (u16)(LG16(0x58B8) + 0x0010),
		                  (u16)(LG16(0x58B4) + 0x0037));
		(void)fn1AB8_1C32(0x0A);
		(void)fn1AB8_1AF6((u16)(LG16(0x58B8) + 0x0011),
		                  (u16)(LG16(0x58B4) + 0x0036),
		                  (u16)(LG16(0x58B8) + 0x0011),
		                  (u16)(LG16(0x58B4) + 0x002A),
		                  &dxTmp);
		(void)fn0C74_02D8(0x01F4, &dsTmp);
		(void)fn1AB8_1C32(0x00);
		(void)fn1AB8_1AF6((u16)(LG16(0x58B8) + 0x0011),
		                  (u16)(LG16(0x58B4) + 0x0036),
		                  (u16)(LG16(0x58B8) + 0x0011),
		                  (u16)(LG16(0x58B4) + 0x002A),
		                  &dxTmp);
		(void)fn0C74_070D(0x0014, 0x012C, &dsv);
		(void)fn1AB8_1C32(0x0C);
		(void)fn1AB8_1AF6((u16)(LG16(0x58B8) + 0x0012),
		                  (u16)(LG16(0x58B4) + 0x0036),
		                  (u16)(LG16(0x58B8) + 0x0012),
		                  (u16)(LG16(0x58B4) + 0x002A),
		                  &dxTmp);
		(void)fn0C74_070D(0x0014, 0x012C, &dsv);
		(void)fn1AB8_1C32(0x00);
		/* 3F1A: mov al,[bp-2h] ; xor ah,ah ; dec ax ; cmp al,1Dh ;
		 *       jc 3F6Bh */
		if ((u8)(bLoc02 - 0x01) >= 0x1D)
		{
			/* l0C74_3F2E: mov [bp-3h],al */
			bLoc03 = (u8)(bLoc02 - 0x01);
			for (;;)
			{
				/* l0C74_3F36: fn1AB8_1AF6([58B8h]+13h,
				 *   bLoc03+[58B4h], [58B8h]+12h, bLoc03+[58B4h]) */
				(void)fn1AB8_1AF6((u16)(LG16(0x58B8) + 0x0013),
				                  (u16)((u16)bLoc03 + LG16(0x58B4)),
				                  (u16)(LG16(0x58B8) + 0x0012),
				                  (u16)((u16)bLoc03 + LG16(0x58B4)),
				                  &dxTmp);
				(void)fn0C74_070D(0x0014, 0x012C, &dsv);
				if (bLoc03 == 0x1D)
					break;
				/* l0C74_3F33: dec byte ptr [bp-3h] */
				bLoc03 = (u8)(bLoc03 - 0x01);
			}
		}
		/* l0C74_3F6B: inc word ptr [58B4h] */
		LG16(0x58B4) = (u16)(LG16(0x58B4) + 0x0001);
	}

	/* l0C74_3F6F: mov al,[bp-1h] ; leave ; ret */
	*(u16 *)bpOut = 0x0000;
	*dsOut = 0x0000;
	return bLoc01;
}
