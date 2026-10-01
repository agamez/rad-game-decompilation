/* seg1AB8_part1.c -- RAD V3.1 preservation port, segment 1AB8 (VIDEO),
 * chunk 1 of N: functions 1AB8:0000 .. 1AB8:0887 (9 functions, ascending).
 *
 * Literal recovery from analysis/slices/1AB8/1AB8_<off>.asm (ground truth)
 * and analysis/reko/RAD_1AB8.{asm,c}; frozen prototypes from src/seg1AB8.h
 * (analysis/summary/iface.tsv).  See CONVENTIONS.md and docs/notes-1AB8.md
 * ("## chunk 1").
 *
 * Hardware / DOS: no direct `int 10h` / `int 16h` / `int 21h`, no `in`/`out`
 * port instruction, and no __cli/__sti occur in this chunk.  Every BIOS/DOS
 * service reached from here goes through segment 1EDA (fn1EDA_*) and is
 * replaced in the 1EDA port, not here.  No segment-0xA000 VGA far pointer
 * literal occurs either: the far pointers in this chunk are DGROUP
 * (g_dgroup + off), code-segment (g_seg1AB8 + off), stack locals, or runtime
 * values carried in the DGROUP allocation slots -- documented inline.
 */
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1AB8.h"
#include "seg1EDA.h"

/* 1AB8:0538.  It is the target of the DGROUP far code pointer at
 * [0xB6C6]/[0xB6C8], assigned by bgi_init_graphics_driver (`mov ax,538h; mov dx,1AB8h`)
 * and called indirectly at 1AB8:079D in bgi_unload_video_driver.  The original thunk is:
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
 * Flat model: the 16:16 allocation pointer is kept as one 32-bit value, so
 * renamed_1eda_0254's offset/segment words are recovered from it.  This is a
 * file-static copy of the helper part2 also defines (the two TUs do not
 * share the symbol).  renamed_1eda_0254's ptrArg06/dxOut/dsOut parameters are the
 * iface.tsv artifact (the .asm pops only wArg00/wArg02/wArg04). */
static void bgi_free_driver_blob(u16 wArg06, u32 * ptrArg08)  /* was fn1AB8_0538 */
{
	u16 dxOut_0538 = 0x0000;
	u16 dsOut_0538 = 0x0000;

	if (*ptrArg08 != 0x00000000u)
		(void)renamed_1eda_0254(wArg06, (u16)(*ptrArg08 & 0xFFFFu),
		                  (u16)((*ptrArg08 >> 16) & 0xFFFFu),
		                  0, &dxOut_0538, &dsOut_0538);
	*ptrArg08 = 0x00000000u;
}

// 1AB8:0000: void bgi_print_error_code(u32 dwArg02, u8 * ptrArg06)
void bgi_print_error_code(u32 dwArg02, u8 * ptrArg06)  /* was fn1AB8_0000 */
{
	u8  abBuf[8];          /* [bp-0008h] */
	u16 dx_95;

	/* original: renamed_1eda_0f26(6, ss:bp-8, 0, dwArg02) ; renamed_1eda_0a39(~0, ptrArg06, ss:bp-8) */
	renamed_1eda_0f26(0x0006, abBuf, 0x0000, dwArg02);
	renamed_1eda_0a39(0xFF, ptrArg06, abBuf, &dx_95);
}

// 1AB8:008B: u16 bgi_error_not_initialized(void)
u16 bgi_error_not_initialized(void)  /* was fn1AB8_008B */
{
	u16 cx_87;
	u16 dsSel;
	u8  ch_160;
	u16 ds_161;

	if (LG8(0xB84E) == 0x00)
	{
		/* strings at 1AB8:0036 ("...not initialized") / 1AB8:00D9 (table) */
		renamed_1eda_08ce(0x0000, &g_seg1AB8[0x0036], &g_dgroup[0xB9BC], &cx_87);
		dsSel = renamed_1eda_0848(0x00, cx_87, &g_dgroup[0xB9BC]);
		(void)fn1EDA_04A9(dsSel, 0xB9BC, &ch_160, &ds_161);
	}
	else
	{
		/* strings at 1AB8:006A ("...Not in graphics mode") */
		renamed_1eda_08ce(0x0000, &g_seg1AB8[0x006A], &g_dgroup[0xB9BC], &cx_87);
		dsSel = renamed_1eda_0848(0x00, cx_87, &g_dgroup[0xB9BC]);
		(void)fn1EDA_04A9(dsSel, 0xB9BC, &ch_160, &ds_161);
	}

	/* fn1EDA_00E9(1) is the fatal BGI error dispatcher; it does not return
	 * in the original.  AX is its result. */
	return (u16)(uintptr_t)fn1EDA_00E9(0x0001);
}

// 1AB8:027E: void bgi_color_name_to_string(u16 wArg04, u8 * ptrArg06)
void bgi_color_name_to_string(u16 wArg04, u8 * ptrArg06)  /* was fn1AB8_027E */
{
	u8  abBuf[0x200];        /* [bp-0200h] 512-byte scratch */
	u8 *buf1 = abBuf + 0x100;/* [bp-0100h] overlaps abBuf (bytes 0..0x1FF) */
	u16 dx_1036;

	switch (wArg04)
	{
	case 0x0000:
		renamed_1eda_0a39(0xFF, ptrArg06, &g_seg1AB8[0x00D9], &dx_1036);
		break;
	case 0xFFFF:
		renamed_1eda_0a39(0xFF, ptrArg06, &g_seg1AB8[0x00E2], &dx_1036);
		break;
	case 0xFFFE:
		renamed_1eda_0a39(0xFF, ptrArg06, &g_seg1AB8[0x00FF], &dx_1036);
		break;
	case 0xFFFD:
		renamed_1eda_0a1f(&g_seg1AB8[0x011E], buf1);
		renamed_1eda_0aac(&g_dgroup[0xB756], buf1);
		renamed_1eda_0aac(&g_seg1AB8[0x013D], buf1);
		renamed_1eda_0a39(0xFF, ptrArg06, buf1, &dx_1036);
		break;
	case 0xFFFC:
		renamed_1eda_0a1f(&g_seg1AB8[0x013F], buf1);
		renamed_1eda_0aac(&g_dgroup[0xB756], buf1);
		renamed_1eda_0aac(&g_seg1AB8[0x013D], buf1);
		renamed_1eda_0a39(0xFF, ptrArg06, buf1, &dx_1036);
		break;
	case 0xFFFB:
		renamed_1eda_0a39(0xFF, ptrArg06, &g_seg1AB8[0x015C], &dx_1036);
		break;
	case 0xFFFA:
		renamed_1eda_0a39(0xFF, ptrArg06, &g_seg1AB8[0x017D], &dx_1036);
		break;
	case 0xFFF9:
		renamed_1eda_0a39(0xFF, ptrArg06, &g_seg1AB8[0x0198], &dx_1036);
		break;
	case 0xFFF8:
		renamed_1eda_0a1f(&g_seg1AB8[0x01B4], buf1);
		renamed_1eda_0aac(&g_dgroup[0xB74C], buf1);
		renamed_1eda_0aac(&g_seg1AB8[0x013D], buf1);
		renamed_1eda_0a39(0xFF, ptrArg06, buf1, &dx_1036);
		break;
	case 0xFFF7:
		renamed_1eda_0a39(0xFF, ptrArg06, &g_seg1AB8[0x01CA], &dx_1036);
		break;
	case 0xFFF6:
		renamed_1eda_0a39(0xFF, ptrArg06, &g_seg1AB8[0x01E9], &dx_1036);
		break;
	case 0xFFF5:
		renamed_1eda_0a39(0xFF, ptrArg06, &g_seg1AB8[0x0213], &dx_1036);
		break;
	case 0xFFF4:
		renamed_1eda_0a39(0xFF, ptrArg06, &g_seg1AB8[0x0222], &dx_1036);
		break;
	case 0xFFF3:
		renamed_1eda_0a1f(&g_seg1AB8[0x0235], buf1);
		renamed_1eda_0aac(&g_dgroup[0xB74C], buf1);
		renamed_1eda_0aac(&g_seg1AB8[0x013D], buf1);
		renamed_1eda_0a39(0xFF, ptrArg06, buf1, &dx_1036);
		break;
	case 0xFFF2:
		renamed_1eda_0a39(0xFF, ptrArg06, &g_seg1AB8[0x0249], &dx_1036);
		break;
	case 0xFFEE:
		renamed_1eda_0a39(0xFF, ptrArg06, &g_seg1AB8[0x025D], &dx_1036);
		break;
	default:
		/* [bp-0200h] formatter buffer, [bp-0100h] number buffer */
		renamed_1eda_0a1f(&g_seg1AB8[0x026D], abBuf);
		/* original pushes cwd(dwArg02) then ss:bp-0100h: AX:DX = (s32)(s16)wArg04 */
		bgi_print_error_code((u32)(s32)(s16)wArg04, buf1);
		renamed_1eda_0aac(buf1, abBuf);
		renamed_1eda_0aac(&g_seg1AB8[0x013D], abBuf);
		renamed_1eda_0a39(0xFF, ptrArg06, abBuf, &dx_1036);
		break;
	}
}

// 1AB8:04F3: u16 bgi_get_error_code(void)
u16 bgi_get_error_code(void)  /* was fn1AB8_04F3 */
{
	u16 ax_11 = LG16(0xB818);

	LG16(0xB818) = 0x0000;
	return ax_11;
}

// 1AB8:0569: u16 bgi_reloc_copy_with_alignment(u8 * ptrArg02, u8 * ptrArg06, u16 wArg0A, void * wArg0C, u16 * dxOut)
u16 bgi_reloc_copy_with_alignment(u8 * ptrArg02, u8 * ptrArg06, u16 wArg0A, void * wArg0C, u16 * dxOut)  /* was fn1AB8_0569 */
{
	u16 v11_14 = (u16)(wArg0A + *(u16 *)ptrArg06);
	u16 ax_20  = (u16)((u16)(uintptr_t)wArg0C + (v11_14 >> 0x04));

	if ((v11_14 & 0x0F) != 0x00)
	{
		/* original: renamed_1eda_11df(count, dst = MK_FP(ax_20, 0),
		 *                       src = MK_FP(wArg0C, v11_14))
		 * The 16:16 far addresses are carried as off | seg<<16, the
		 * flat-port convention also used by bgi_load_bgi_driver's 1EDA:11DF
		 * call.  ptrArg02/ptrArg06 are host pointers to the source
		 * record/count words. */
		renamed_1eda_11df(*(u16 *)ptrArg02,
		            (u8 *)far_ptr(FAR_PTR(ax_20, 0x0000)),
		            (u8 *)far_ptr(FAR_PTR((u16)(uintptr_t)wArg0C, v11_14)));
		*(u16 *)ptrArg06 -= (u16)(v11_14 & 0x0F);
	}

	*dxOut = ax_20;
	return 0x0000;
}

// 1AB8:05D3: u16 bgi_find_video_driver_index(u8 * ptrArg04)
u16 bgi_find_video_driver_index(u8 * ptrArg04)  /* was fn1AB8_05D3 */
{
	u8  abBuf[0x108];        /* [bp-0108h] renamed_1eda_0b61 output */
	u16 wLoc02;              /* [bp-0002h] result / [0B818h] mirror */
	u16 wLoc0E;              /* [bp-000Eh] record count (0B7B8) */
	u16 wLoc08;              /* [bp-0008h] record index */
	u16 wArg04_202;          /* (word16) ptrArg04: original far offset word */
	u16 wArg06_203;          /* SLICE(ptrArg04,word16,16): far segment word */
	u8 *pRec;                /* [bp-000Ch] ptrArg04 + 0x80 */
	u16 ax_0B24;
	u16 dx_0B24;
	u16 ax_0569;
	u16 dx_0569;

	if (LG8(0xB84E) != 0x00)
	{
		LG16(0xB818) = 0xFFF5;
		wLoc02 = 0xFFF5;
		return wLoc02;
	}

	LG16(0xB818) = 0xFFFC;
	wLoc02 = 0xFFFC;
	renamed_1eda_0b61(0x0002, ptrArg04, abBuf);
	if (renamed_1eda_0b24(&g_seg1AB8[0x05D0], abBuf, &ax_0B24, &dx_0B24) == 0x00)
		return wLoc02;                   /* 061A jmp 06BE */

	wArg04_202 = (u16)(uintptr_t)ptrArg04;
	wArg06_203 = far_seg_of(ptrArg04);
	pRec = ptrArg04 + 0x80;              /* 061D */
	if (pRec[0x06] < 0x02)
		return wLoc02;                   /* 0649 jmp 06BE */
	if (pRec[0x08] > 0x01)
		return wLoc02;                   /* 0649 jmp 06BE */

	wLoc0E = LG16(0xB7B8);               /* 064B */
	if ((s16)wLoc0E < 0x0000)            /* xor ax,ax ; cmp ax,count ; jg 06BE */
		return wLoc02;

	wLoc08 = 0x0000;                     /* 0658 */
	for (;;)
	{
		/* 0660: compare pRec+0x0A with the display-driver record.
		 * 0B24 returns nonzero on a match (asm `jz`/`jnz` path). */
		if (renamed_1eda_0b24(pRec + 0x0A,
		                &g_dgroup[(u16)(wLoc08 * 0x1A + 0x50FC)],
		                &ax_0B24, &dx_0B24) != 0x00)
		{
			/* 067E: found -- store the returned far pointer in the
			 * record table at ds:5112/5114 + n*0x1A. */
			ax_0569 = bgi_reloc_copy_with_alignment(pRec + 0x04, pRec, wArg04_202,
			                      (void *)(uintptr_t)wArg06_203, &dx_0569);
			LG16((u16)(wLoc08 * 0x1A + 0x5112)) = ax_0569;
			LG16((u16)(wLoc08 * 0x1A + 0x5114)) = dx_0569;
			LG16(0xB818) = 0x0000;
			wLoc02 = wLoc08;
			return wLoc02;
		}
		if (wLoc08 == wLoc0E)            /* 06B6 */
			return wLoc02;
		++wLoc08;                        /* 065D */
	}
}

// 1AB8:06CA: u16 bgi_unload_video_driver(u8 * ptrArg04)
u16 bgi_unload_video_driver(u8 * ptrArg04)  /* was fn1AB8_06CA */
{
	u8  abBuf1[0x08];        /* [bp-010Ah] renamed_1eda_0b61 output (first test) */
	u8  abBuf2[0x08];        /* [bp-010Eh] renamed_1eda_0b61 output (record test) */
	u16 wLoc02;              /* [bp-0002h] result */
	u16 wLoc08;              /* [bp-0008h] record index */
	u16 wLoc0A;              /* [bp-000Ah] string scan index */
	u16 wArg04_318;          /* (word16) ptrArg04: original far offset word */
	u16 wArg06_317;          /* SLICE(ptrArg04,word16,16): far segment word */
	u8 *pRec;                /* [bp-000Eh] ptrArg04 + wLoc0A + 1 */
	u8 *pRec520B;            /* [bp-0112h] DGROUP 0x520B + n*0x0F record */
	u16 ax_0B24;
	u16 dx_0B24;
	u16 ax_0569;
	u16 dx_0569;

	LG16(0xB818) = 0xFFF3;
	wLoc02 = LG16(0xB818);

	renamed_1eda_0b61(0x0002, ptrArg04, abBuf1);
	if (renamed_1eda_0b24(&g_seg1AB8[0x06C7], abBuf1, &ax_0B24, &dx_0B24) == 0x00)
		return wLoc02;                   /* 06FD jmp 080A */

	wLoc0A = 0x0000;                     /* 0700 */
	while (!(ptrArg04[wLoc0A] == 0x1A || wLoc0A >= 0x0101))
		++wLoc0A;                        /* 0705..071A */
	if (wLoc0A >= 0x0100)
		return wLoc02;                   /* 0726 jmp 080A */

	pRec = ptrArg04 + wLoc0A + 0x01;     /* 0729 (offset only in the original) */
	if (pRec[0x08] < 0x01)
		return wLoc02;                   /* 075A jmp 080A */
	if (pRec[0x0A] > 0x01)
		return wLoc02;                   /* 075A jmp 080A */

	wLoc08 = 0x0001;                     /* 075D */
	for (;;)
	{
		/* 0767: build the 4-byte key from pRec+2, compare against the
		 * video-driver record.  0B24 returns nonzero on a match. */
		renamed_1eda_0b61(0x0004, pRec + 0x02, abBuf2);
		if (renamed_1eda_0b24(abBuf2,
		                &g_dgroup[(u16)(wLoc08 * 0x0F + 0x5215)],
		                &ax_0B24, &dx_0B24) != 0x00)
			break;                       /* match -> 0794 */
		if (wLoc08 == 0x14)
			return wLoc02;               /* 0801 */
		++wLoc08;                        /* 0764 */
	}

	/* 0794: found.  [bp-0112h] held a DGROUP far pointer to the record. */
	pRec520B = &g_dgroup[(u16)(wLoc08 * 0x0F + 0x520B)];
	/* original: call dword ptr [0B6C6h] (1AB8:0538) with the record far
	 * pointer and its word at +8. */
	bgi_free_driver_blob(*(u16 *)&pRec520B[0x08], (u32 *)pRec520B);
	*(u16 *)&pRec520B[0x00] = 0x0000;
	*(u16 *)&pRec520B[0x02] = 0x0000;

	wArg04_318 = (u16)(uintptr_t)ptrArg04;
	wArg06_317 = far_seg_of(ptrArg04);
	ax_0569 = bgi_reloc_copy_with_alignment(pRec + 0x06, pRec, wArg04_318,
	                      (void *)(uintptr_t)wArg06_317, &dx_0569);
	*(u16 *)&pRec520B[0x04] = ax_0569;
	*(u16 *)&pRec520B[0x06] = dx_0569;
	*(u16 *)&pRec520B[0x08] = 0x0000;

	wLoc02 = wLoc08;
	LG16(0xB818) = 0x0000;
	return wLoc02;
}

// 1AB8:0813: u16 bgi_init_graphics_error(void * dxOut)
u16 bgi_init_graphics_error(void * dxOut)  /* was fn1AB8_0813 */
{
	LG16(0xB820) = 0x008B;
	LG16(0xB822) = 0x1AB8;
	LG16(0xB832) = 0x008B;
	LG16(0xB834) = 0x1AB8;
	LG16(0xB824) = 0x0000;
	LG16(0xB826) = 0x0000;
	LG16(0xB836) = 0x0000;
	LG16(0xB838) = 0x0000;
	LG16(0xB828) = 0x0000;
	LG16(0xB82A) = 0x0000;
	LG16(0xB82E) = 0x0000;
	LG16(0xB830) = 0x0000;
	LG16(0xB7E0) = 0x0000;
	LG16(0xB7E2) = 0x0000;
	LG16(0xB7E4) = 0x0000;
	LG16(0xB7FA) = 0x0000;
	LG16(0xB7FC) = 0x0000;
	LG16(0xB7FE) = 0x0000;
	LG8(0xB7EA) = 0x00;
	LG16(0xB84A) = 0x0001;
	LG16(0xB84C) = 0x0001;
	LG16(0xB74A) = 0x0000;
	LG8(0xB84E) = 0x00;

	/* original: DX = code segment 1AB8 (selector).  The callers pass the
	 * address of a 16-bit scratch (see bgi_load_bgi_driver / bgi_shutdown_video_driver), so the
	 * write is kept 16-bit rather than overrunning the frozen `void *`
	 * target in the flat model. */
	*(u16 *)dxOut = 0x1AB8;
	return 0x0000;
}

// 1AB8:0887: u8 bgi_open_video_driver_file(u16 wArg02, u8 * ptrArg04, u8 * ptrArg08, u8 * ptrArg0C, u16 * dsOut)
u8 bgi_open_video_driver_file(u16 wArg02, u8 * ptrArg04, u8 * ptrArg08, u8 * ptrArg0C, u16 * dsOut)  /* was fn1AB8_0887 */
{
	u8  abBuf[0x302];        /* [bp-0302h] 256-byte scratch x3 */
	u8 *buf1 = abBuf + 0x200;/* [bp-0102h] */
	u8 *buf2 = abBuf + 0x100;/* [bp-0202h] */
	u8 *buf3 = abBuf + 0x000;/* [bp-0302h] */
	u8  bLoc03 = 0x00;       /* [bp-0001h] */
	u16 dx_368;
	u16 dx_369;
	u16 dx_370;
	u16 dx_371;
	u16 ax_116A;
	u16 ds_0887;

	/* 0887:089D: copy the two caller strings into the stack buffers. */
	renamed_1eda_0a39(0xFF, buf1, ptrArg0C, &dx_368);
	renamed_1eda_0a39(0xFF, buf2, ptrArg08, &dx_369);
	LG16(0xB818) = 0xFFFD;
	*(u16 *)ptrArg04 = 0x0000;

	/* 0887:08C6: build the 0xB6CA file block. */
	renamed_1eda_0a1f(buf1, buf3);
	renamed_1eda_0aac(buf2, buf3);
	renamed_1eda_0fa2(buf3, &g_dgroup[0xB6CA]);
	renamed_1eda_0fd0(0x0001, &g_dgroup[0xB6CA], &dx_370);

	if (renamed_1eda_04a2() != 0x00)
	{
		if (buf1[0] != 0x00)
		{
			renamed_1eda_0fa2(buf2, &g_dgroup[0xB6CA]);
			renamed_1eda_0fd0(0x0001, &g_dgroup[0xB6CA], &dx_371);
			if (renamed_1eda_04a2() != 0x00)
				goto l1AB8_096D;
		}
		else
			goto l1AB8_096D;
	}

	/* 0887:0939 */
	LG16(0xB818) = 0x0000;
	ax_116A = renamed_1eda_116a(&g_dgroup[0xB6CA], &ds_0887);
	*(u16 *)ptrArg04 = ax_116A;
	if (*(u16 *)ptrArg04 > 0x00FF)
	{
		LG16(0xB818) = wArg02;
		(void)renamed_1eda_1051((u8)wArg02, &g_dgroup[0xB6CA]);
	}
	else
		bLoc03 = 0x01;

l1AB8_096D:
	*dsOut = 0x0000;   /* DGROUP selector dropped in the flat model */
	return bLoc03;
}
