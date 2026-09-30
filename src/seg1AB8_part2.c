/* seg1AB8_part2.c -- RAD V3.1 segment 1AB8 (VIDEO), chunk 2 of N.
 *
 * Functions 097B..0EB5 (ascending offset), recovered from
 * analysis/reko/RAD_1AB8.{asm,c} and the per-function slices under
 * analysis/slices/1AB8/.  Ground truth = the .asm.
 *
 * This chunk contains no direct hardware instruction: no int 10h/16h/21h,
 * no in/out port sites, no __cli/__sti and no int 23h.  Every DOS/BIOS
 * service reached from here goes through segment 1EDA (fn1EDA_*) and is
 * replaced there, not here.
 *
 * Frozen prototypes (src/seg1AB8.h, from analysis/summary/iface.tsv) are
 * adopted exactly; the dropped `ds` register arguments and the flat-memory
 * adaptations are annotated inline.  See docs/notes-1AB8.md ("## chunk 2")
 * for the uncertain sites: the DGROUP far code-pointer callbacks [0xB6C2] /
 * [0xB6C6], the display-driver record callback [0xB896], the far data
 * pointers [0xB828]/[0xB83A] and the 1AB8:0569 caller convention.
 */
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1AB8.h"
#include "seg1EDA.h"

/* Original 1AB8:051F.  It is the target of the DGROUP far code pointer at
 * [0xB6C2]/[0xB6C4], assigned by fn1AB8_17AE (`mov ax,51Fh; mov dx,1AB8h`).
 * The original thunk is:
 *
 *     push bp / mov bp,sp
 *     push word ptr [bp+6h]        ; wArg06
 *     call far 1EDA:023F           ; DX:AX = allocate
 *     les di,[bp+8h]               ; ptrArg08 = far pointer slot
 *     mov es:[di],ax               ; store offset
 *     mov es:[di+2h],dx            ; store segment
 *     pop bp / retf 6h
 *
 * Flat model: the 16:16 result is kept as one 32-bit value in the DGROUP
 * slot, so fn1EDA_023F's u32 return is stored directly.  The extra
 * wArg02/wArg04/dsOut parameters are the iface.tsv artifact for
 * fn1EDA_023F (the .asm pops only the one argument). */
static void fn1AB8_051F(u16 wArg06, u32 * ptrArg08)
{
	u16 dsOut_051F = 0x0000;

	*ptrArg08 = fn1EDA_023F(wArg06, 0x0000, 0x0000, &dsOut_051F);
}

/* Original 1AB8:0538.  It is the target of the DGROUP far code pointer at
 * [0xB6C6]/[0xB6C8], assigned by fn1AB8_17AE (`mov ax,538h; mov dx,1AB8h`).
 * The original thunk is:
 *
 *     push bp / mov bp,sp
 *     les di,[bp+8h]               ; ptrArg08 = far pointer slot
 *     mov ax,es:[di]
 *     or ax,es:[di+2h]             ; offset | segment
 *     jz  done
 *     push es:[di+2h]              ; segment
 *     push es:[di]                 ; offset
 *     push word ptr [bp+6h]        ; wArg06
 *     call far 1EDA:0254           ; free
 * done:
 *     les di,[bp+8h]
 *     xor ax,ax
 *     mov es:[di],ax
 *     mov es:[di+2h],ax            ; clear the slot
 *     pop bp / retf 6h
 *
 * fn1EDA_0254's ptrArg06/dxOut/dsOut parameters are the iface.tsv artifact
 * (the .asm pops only wArg00/wArg02/wArg04). */
static void fn1AB8_0538(u16 wArg06, u32 * ptrArg08)
{
	u16 dxOut_0538 = 0x0000;
	u16 dsOut_0538 = 0x0000;

	if (*ptrArg08 != 0x00000000u)
		(void)fn1EDA_0254(wArg06, (u16)(*ptrArg08 & 0xFFFFu),
		                  (u16)((*ptrArg08 >> 16) & 0xFFFFu),
		                  0, &dxOut_0538, &dsOut_0538);
	*ptrArg08 = 0x00000000u;
}

/* The 1AB8:0C39 indirect call goes through the DGROUP far code-pointer slot
 * [0xB896]/[0xB898], which is loaded from the display-driver record fields
 * +0x12/+0x14 (records at 0x50FC + n*0x1A).  The shipped image leaves every
 * one of those callbacks zero, so the guard in fn1AB8_0BAE skips the call.
 * A 16:16 code pointer cannot be called from flat C and no record callback
 * maps to a recovered function, so this stands in for the call: it reads the
 * staged selector pair and returns the AX value (0) the caller consumes.
 * See docs/notes-1AB8.md ("## chunk 2"). */
static u16 fn1AB8_call_0B896(void)
{
	u16 off_0B896 = LG16(0xB896);
	u16 seg_0B896 = LG16(0xB898);

	(void)off_0B896;
	(void)seg_0B896;
	return 0x0000;
}

/* Video-driver record used by fn1AB8_0EB5: 0x0F-byte stride starting at
 * DGROUP 0x520B.  Word fields at +0,+2,+4,+6,+8 and a byte at +0x0A. */
typedef struct {
	u16 w0000;
	u16 w0002;
	u16 w0004;
	u16 w0006;
	u16 w0008;
	u8  b000A;
} TRec520B;

// 1AB8:097B: u8 fn1AB8_097B(u8 * ptrArg02, u16 wArg06, u16 * dsOut)
u8 fn1AB8_097B(u8 * ptrArg02, u16 wArg06, u16 * dsOut)
{
	u8 abBuf20E[0x10C];   /* [bp-020Eh] name scratch; original word at [bp-010Ah] overlapped this buffer */
	u8 abBuf102[0x100];   /* [bp-0102h] path scratch */
	u16 wLoc10A;          /* [bp-010Ah] fn1EDA_10BB output word */
	u8 bLoc03 = 0x00;     /* [bp-001h] */
	u16 dx_409;
	u16 dx_410;
	u16 ax_10BB;
	u16 ds_097B = 0x0000;

	fn1EDA_0A39(0xFF, abBuf102, ptrArg02, &dx_409);
	bLoc03 = 0x00;
	fn1EDA_0A1F(&g_dgroup[(u16)(wArg06 * 0x1A + 0x50FC)], abBuf20E);
	fn1EDA_0AAC(&g_seg1AB8[0x0976], abBuf20E);
	fn1EDA_0A39(0x0C, &g_dgroup[0xB756], abBuf20E, &dx_410);

	if ((LG16((u16)(wArg06 * 0x1A + 0x5112)) |
	     LG16((u16)(wArg06 * 0x1A + 0x5114))) != 0x00)
	{
		u16 dx_307 = LG16((u16)(wArg06 * 0x1A + 0x5114));

		LG16(0xB832) = LG16((u16)(wArg06 * 0x1A + 0x5112));
		LG16(0xB834) = dx_307;
		LG16(0xB828) = 0x0000;
		LG16(0xB82A) = 0x0000;
		LG16(0xB82C) = 0x0000;
		bLoc03 = 0x01;
		goto l1AB8_0AE5;
	}

	/* original: fn1AB8_0887(0FFFCh, ds:0B82Ch, ds:0B756h, ss:bp-0102h) */
	if (fn1AB8_0887(0xFFFC, &g_dgroup[0xB82C], &g_dgroup[0xB756],
	                abBuf102, &ds_097B) == 0x00)
		goto l1AB8_0AE5;

	{
		u16 dx_158 = LG16(0x5370);

		LG16(0xB7BC) = LG16(0x536E);
		LG16(0xB7BE) = dx_158;
		LG16(0x536E) = 0x050B;
		LG16(0x5370) = 0x1AB8;
		/* original: call dword ptr [0B6C2h] (1AB8:051F) */
		fn1AB8_051F(LG16(0xB82C), (u32 *)&g_dgroup[0xB828]);
		LG16(0x536E) = LG16(0xB7BC);
		LG16(0x5370) = LG16(0xB7BE);
	}

	if ((LG16(0xB828) | LG16(0xB82A)) == 0x00)
	{
		LG16(0xB818) = 0xFFFB;
		goto l1AB8_0AE5;
	}

	/* original: fn1EDA_10BB(ss:bp-010Ah, [0B82Ch], ds:0B6CAh) */
	ax_10BB = fn1EDA_10BB((u8 *)&wLoc10A, LG16(0xB82C),
	                      (u8 *)far_ptr(LG32(0xB828)), &g_dgroup[0xB6CA]);
	fn1EDA_1051((u8)ax_10BB, &g_dgroup[0xB6CA]);

	if (fn1EDA_04A2() != 0x00)
		goto l1AB8_0AB5;
	if (wLoc10A != LG16(0xB82C))
		goto l1AB8_0AB5;

	/* original: fn1AB8_05D3(far pointer held at ds:0B828h) */
	if (fn1AB8_05D3(far_ptr(LG32(0xB828))) == wArg06)
		goto l1AB8_0ACA;

l1AB8_0AB5:
	LG16(0xB818) = 0xFFFC;
	/* original: call dword ptr [0B6C6h] (1AB8:0538) */
	fn1AB8_0538(LG16(0xB82C), (u32 *)&g_dgroup[0xB828]);
	goto l1AB8_0AE5;

l1AB8_0ACA:
	{
		u16 dx_275 = LG16((u16)(wArg06 * 0x1A + 0x5114));

		LG16(0xB832) = LG16((u16)(wArg06 * 0x1A + 0x5112));
		LG16(0xB834) = dx_275;
		bLoc03 = 0x01;
	}

l1AB8_0AE5:
	*dsOut = 0x0000;   /* DGROUP selector dropped in the flat model */
	return bLoc03;
}

// 1AB8:0AEE: u16 fn1AB8_0AEE(void)
u16 fn1AB8_0AEE(void)
{
	u8 abLoc08[8];       /* [bp-0008h] */
	u16 ds_244 = 0x0000;

	if (LG8(0xB84E) == 0x00)
		fn1AB8_008B();
	fn1AB8_0F93(0x01, LG16(0xB7C4), LG16(0xB7C2), 0x00, 0x00);
	fn1AB8_1384(&g_dgroup[0xB87A]);
	fn1AB8_129A(&g_dgroup[0xB87A]);
	if (fn1AB8_1C5A() != 0x01)
		fn1AB8_1250(0x00);
	LG8(0xB840) = 0x00;
	fn1AB8_1C32((u8)fn1AB8_1C4A());
	fn1EDA_1202(0xFF, 0x08, abLoc08);
	fn1AB8_11A0(fn1AB8_1C4A(), abLoc08);
	fn1AB8_1175(fn1AB8_1C4A(), 0x01);
	fn1AB8_10F4(0x01, 0x00, 0x00);
	fn1AB8_1536(0x01, 0x00, 0x00, &ds_244);
	fn1AB8_14F4(0x02, 0x00);
	fn1AB8_194E(0x00);
	fn1AB8_108B(0x00, 0x00);
	return 0x0000;   /* DGROUP selector dropped in the flat model */
}

// 1AB8:0BAE: u16 fn1AB8_0BAE(u8 * ptrArg04, s16 * ptrArg08, u8 * ptrArg0C)
u16 fn1AB8_0BAE(u8 * ptrArg04, s16 * ptrArg08, u8 * ptrArg0C)
{
	u8  abLoc208[0x100];   /* [bp-0208h] */
	u8  abLoc100[0x100];   /* [bp-0100h] */
	u16 wLoc0106;          /* [bp-0104h] */
	s16 wLoc0108;          /* [bp-0106h] */
	u8  bLoc0109 = 0x00;   /* [bp-0107h] */
	u8  bLoc0101;          /* [bp-0101h] */
	u16 dx_695;
	u16 dx_696;
	u16 dx_697;
	u16 dx_698;
	u16 ax_69;
	u16 dx_69;

	fn1EDA_0A39(0xFF, abLoc100, ptrArg04, &dx_695);
	LG16(0xB820) = 0x2073;
	LG16(0xB822) = 0x1AB8;
	/* original: fn1AB8_0569 with the far pointer 1AB8:2073 twice
	 * (second one +2) plus its offset/segment words; see notes. */
	ax_69 = fn1AB8_0569(&g_seg1AB8[0x2075], &g_seg1AB8[0x2073],
	                    0x2073, (void *)(uintptr_t)0x1AB8, &dx_69);
	LG16(0xB820) = ax_69;
	LG16(0xB822) = dx_69;

	bLoc0109 = 0x00;
	if ((*(u16 *)ptrArg0C) != 0x00)
		goto l1AB8_0C86;

	wLoc0106 = 0x0000;
	wLoc0108 = (s16)0xFFFF;
	while ((s16)wLoc0106 < (s16)LG16(0xB7B8) && wLoc0108 < 0x0000)
	{
		u8 *rec = &g_dgroup[(u16)(wLoc0106 * 0x1A + 0x510E)];

		if ((*(u16 *)&rec[0] | *(u16 *)&rec[2]) != 0x00)
		{
			LG16(0xB896) = *(u16 *)&rec[0];
			LG16(0xB898) = *(u16 *)&rec[2];
			/* original: call dword ptr [0B896h] */
			wLoc0108 = (s16)fn1AB8_call_0B896();
			if (wLoc0108 >= 0x0000)
			{
				LG16(0xB814) = wLoc0106;
				*(u16 *)ptrArg0C = wLoc0106;
				*ptrArg08 = (s16)wLoc0108;
				bLoc0109 = 0x01;
			}
		}
		++wLoc0106;
	}

l1AB8_0C86:
	if (bLoc0109 == 0x00)
		fn1AB8_19EE((u8 *)ptrArg08, ptrArg0C, &g_dgroup[0xB814]);
	else
	{
		wLoc0106 = LG16(0xB814);
		wLoc0108 = (s16)(*(u16 *)ptrArg0C + 0x80);
		fn1AB8_19EE((u8 *)ptrArg08, (u8 *)&wLoc0108, (u8 *)&wLoc0106);
	}

	if ((s16)(*(u16 *)ptrArg0C) < 0x0000)
	{
		LG16(0xB818) = 0xFFFE;
		*(u16 *)ptrArg0C = 0xFFFE;
		fn1AB8_0813(&dx_695);
		goto l1AB8_0E82;
	}

	LG16(0xB816) = *(u16 *)ptrArg08;
	fn1EDA_0A39(0x50, abLoc100, &g_dgroup[0xB764], &dx_696);

	if (LG8(0xB764) == 0x00)
		goto l1AB8_0D52;

	bLoc0101 = LG8((u16)(0xB764 + LG8(0xB764)));
	if (bLoc0101 == 0x3A)
		goto l1AB8_0D52;
	if (bLoc0101 == 0x5C)
		goto l1AB8_0D52;

	fn1EDA_0A1F(abLoc100, abLoc208);
	fn1EDA_0AAC(&g_seg1AB8[0x0BAC], abLoc208);
	fn1EDA_0A39(0x50, &g_dgroup[0xB764], abLoc208, &dx_697);

l1AB8_0D52:
	if (fn1AB8_097B(&g_dgroup[0xB764], LG16(0xB814), &dx_698) == 0x00)
	{
		*(u16 *)ptrArg0C = LG16(0xB818);
		fn1AB8_0813(&dx_695);
		goto l1AB8_0E82;
	}

	fn1EDA_1202(0x00, 0x3F, &g_dgroup[0xB7D4]);
	LG16(0xB7BC) = LG16(0x536E);
	LG16(0xB7BE) = LG16(0x5370);
	LG16(0x536E) = 0x050B;
	LG16(0x5370) = 0x1AB8;
	/* original: call dword ptr [0B6C2h] (1AB8:051F) */
	fn1AB8_051F(LG16(0xB7B6), (u32 *)&g_dgroup[0xB7E0]);
	LG16(0x536E) = LG16(0xB7BC);
	LG16(0x5370) = LG16(0xB7BE);

	if ((LG16(0xB7E0) | LG16(0xB7E2)) == 0x00)
	{
		LG16(0xB818) = 0xFFFB;
		*(u16 *)ptrArg0C = 0xFFFB;
		/* original: call dword ptr [0B6C6h] (1AB8:0538) */
		fn1AB8_0538(LG16(0xB82C), (u32 *)&g_dgroup[0xB828]);
		fn1AB8_0813(&dx_695);
		goto l1AB8_0E82;
	}

	LG8(0xB7D5) = 0x00;
	LG8(0xB7EA) = 0x00;
	LG16(0xB82E) = LG16(0xB7E0);
	LG16(0xB830) = LG16(0xB7E2);
	LG16(0xB7E4) = LG16(0xB7B6);
	LG16(0xB7FA) = LG16(0xB7E0);
	LG16(0xB7FC) = LG16(0xB7E2);
	LG16(0xB7FE) = LG16(0xB7B6);
	LG16(0xB7EE) = 0xB818;
	LG16(0xB7F0) = 0x0000;   /* DS selector dropped in the flat model */

	fn1AB8_1855(&g_dgroup[0xB7D4]);
	/* original: fn1EDA_11DF(13h, ds:0B7C0h, far pointer held at ds:0B83Ah) */
	fn1EDA_11DF(0x13, &g_dgroup[0xB7C0], (u8 *)far_ptr(LG32(0xB83A)));
	fn1AB8_1AA6(&g_dgroup[0xB7D4]);

	if (LG8(0xB7C0) != 0x00)
	{
		LG16(0xB818) = (u16)LG8(0xB7C0);
		fn1AB8_0813(&dx_695);
		goto l1AB8_0E82;
	}

	LG16(0xB848) = fn1AB8_1C93();
	LG16(0xB84A) = LG16(0xB7CE);
	LG16(0xB84C) = 0x2710;
	LG8(0xB84E) = 0x01;
	fn1AB8_0AEE();
	LG16(0xB818) = 0x0000;

l1AB8_0E82:
	return 0x0000;   /* DGROUP selector dropped in the flat model */
}

// 1AB8:0E88: void fn1AB8_0E88(void)
void fn1AB8_0E88(void)
{
	fn1AB8_18E3();
	if ((LG16(0xB824) | LG16(0xB826)) == 0x00)
	{
		u16 dx_25 = LG16(0xB822);

		LG16(0xB824) = LG16(0xB820);
		LG16(0xB826) = dx_25;
		LG16(0xB820) = 0x008B;
		LG16(0xB822) = 0x1AB8;
	}
}

// 1AB8:0EB5: void fn1AB8_0EB5(void)
void fn1AB8_0EB5(void)
{
	u16 wLoc02;     /* [bp-0002h] loop index */
	u16 dx_72;

	if (LG8(0xB84E) == 0x00)
	{
		LG16(0xB818) = 0xFFFF;
		return;
	}

	fn1AB8_0E88();
	/* original: call dword ptr [0B6C6h] (1AB8:0538) */
	fn1AB8_0538(LG16(0xB7B6), (u32 *)&g_dgroup[0xB82E]);

	if ((LG16(0xB828) | LG16(0xB82A)) != 0x00)
	{
		u16 off_e5 = (u16)(LG16(0xB814) * 0x1A);

		LG16((u16)(off_e5 + 0x5112)) = 0x0000;
		LG16((u16)(off_e5 + 0x5114)) = 0x0000;
	}

	/* original: call dword ptr [0B6C6h] (1AB8:0538) */
	fn1AB8_0538(LG16(0xB82C), (u32 *)&g_dgroup[0xB828]);
	fn1AB8_0813(&dx_72);

	wLoc02 = 0x0001;
	for (;;)
	{
		TRec520B *ptrLoc08 = (TRec520B *)&g_dgroup[(u16)(wLoc02 * 0x0F + 0x520B)];

		if (ptrLoc08->b000A != 0x00 && ptrLoc08->w0008 != 0x00 &&
		    (ptrLoc08->w0000 | ptrLoc08->w0002) != 0x00)
		{
			/* original: call dword ptr [0B6C6h] (1AB8:0538) */
			fn1AB8_0538(ptrLoc08->w0008, (u32 *)ptrLoc08);
			ptrLoc08->w0008 = 0x0000;
			ptrLoc08->w0000 = 0x0000;
			ptrLoc08->w0002 = 0x0000;
			ptrLoc08->w0004 = 0x0000;
			ptrLoc08->w0006 = 0x0000;
		}
		if (wLoc02 == 0x14)
			break;
		++wLoc02;
	}
}
