/* seg1AB8_part5a.c -- RAD V3.1 preservation port, segment 1AB8 (VIDEO),
 * chunk 5a of N: functions 1AB8:1536 .. 1AB8:17AE (3 functions, ascending).
 *
 * Literal recovery from analysis/slices/1AB8/1AB8_<off>.asm (ground truth)
 * and the per-function Reko slices; frozen prototypes from src/seg1AB8.h
 * (analysis/summary/iface.tsv) are adopted exactly.  See CONVENTIONS.md and
 * docs/notes-1AB8.md ("## chunk 5a").
 *
 * Hardware / DOS: no raw port I/O (no in/out), no int 10h/16h/21h, no
 * __cli/__sti and no int 23h occur in this chunk.  Every BIOS/DOS service is
 * reached through segment 1EDA (fn1EDA_*) and replaced there.  No segment-0xA000
 * VGA far pointer literal appears either: the only far pointers here are
 * DGROUP (g_dgroup + off), the code segment (g_seg1AB8 + off) and the runtime
 * 16:16 allocation/dispatch slots documented inline.
 *
 * DGROUP dispatch slots consumed here (all installed by bgi_init_graphics_driver, this
 * chunk): [0xB6C2]/[0xB6C4] = 1AB8:051F and [0xB6C6]/[0xB6C8] = 1AB8:0538.
 * They are called indirectly (`call dword ptr [0B6C2h]` / `[0B6C6h]`); as in
 * chunks 1-2 the flat model calls the recovered file-static helpers directly
 * (the two far-pointer thunks cannot be invoked from flat C).  See
 * docs/notes-1AB8.md.
 */
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1AB8.h"
#include "seg1EDA.h"

/* Original 1AB8:051F.  Target of the DGROUP far code pointer at
 * [0xB6C2]/[0xB6C4], assigned by bgi_init_graphics_driver (`mov ax,51Fh; mov dx,1AB8h`).
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
 * slot, so fn1EDA_023F's u32 return is stored directly.  Same file-static
 * copy as chunk 2 (the two TUs do not share the symbol). */
static void bgi_alloc_driver_blob(u16 wArg06, u32 * ptrArg08)  /* was fn1AB8_051F */
{
	u16 dsOut_051F = 0x0000;

	*ptrArg08 = fn1EDA_023F(wArg06, 0x0000, 0x0000, &dsOut_051F);
}

/* Original 1AB8:0538.  Target of the DGROUP far code pointer at
 * [0xB6C6]/[0xB6C8], assigned by bgi_init_graphics_driver (`mov ax,538h; mov dx,1AB8h`).
 * The original thunk is:
 *
 *     push bp / mov bp,sp
 *     les di,[bp+8h]               ; ptrArg08 = far pointer slot
 *     mov ax,es:[di]
 *     or ax,es:[di+2h]             ; offset | segment
 *     jz done
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
 * Same file-static copy as chunk 2. */
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

/* Video-driver record consumed by bgi_load_video_driver_file: 0x0F-byte stride starting at
 * DGROUP 0x520B (the same layout chunk 2 named TRec520B).  Word fields at
 * +0,+2 (far code pointer), +4,+6 (allocation) and +8 (file size); the
 * display-driver name string starts at +0x0A.  bgi_load_video_driver_file addresses it with
 * byte offsets (pRec + n) as the original does. */

// 1AB8:1536: void * bgi_load_video_driver_file(u16 wArg04, u16 wArg06, u16 wArg08, u16 * dsOut)
void * bgi_load_video_driver_file(u16 wArg04, u16 wArg06, u16 wArg08, u16 * dsOut)  /* was fn1AB8_1536 */
{
	u8  abBuf[0x100];   /* [bp-010Ah] 0x100-byte name/format scratch */
	u16 wLoc02;         /* [bp-0002h] file size / handle from bgi_open_video_driver_file */
	u32 dwLoc06;        /* [bp-0006h]/[bp-0004h] allocated driver blob (off|seg<<16) */
	u8 *pRec;           /* [bp-000Ah]/[bp-0008h] driver record at 0x520B + n*0x0F */
	u16 dx_45;
	u16 ax_10BB;
	u16 ax_06CA;
	u16 ds_1536 = 0x0000;

	if (wArg08 > 0x14u)
		goto l1AB8_155E;
	if ((s16)wArg08 < 0)               /* asm cmp 0 / jc (16-bit below-zero) */
		goto l1AB8_155E;
	if (wArg08 == 0x0000 || LG8((u16)(wArg08 * 0x0F + 0x5215)) != 0x00)
		goto l1AB8_1571;               /* asm 154F jnz 1571h */
	goto l1AB8_155E;

l1AB8_155E:
	LG16(0xB818) = 0xFFF2;
	wArg08 = 0x0000;
	wArg04 = 0x0001;
	goto l1AB8_175E;

l1AB8_1571:
	if (wArg08 == 0x0000)
		goto l1AB8_175E;
	if (wArg08 == LG16(0xB88C))
		goto l1AB8_175E;
	if (wArg08 == LG16(0xB74A))
		goto l1AB8_1747;

	/* 1592: tear down the previously installed driver record. */
	if (LG16(0xB74A) == 0x0000)
		goto l1AB8_15E8;
	{
		u8 *pOld = &g_dgroup[(u16)(LG16(0xB74A) * 0x0F + 0x520B)];

		if (*(u16 *)&pOld[0x08] == 0x0000)
			goto l1AB8_15E8;
		/* original: call dword ptr [0B6C6h] (1AB8:0538) */
		bgi_free_driver_blob(*(u16 *)&pOld[0x08], (u32 *)pOld);
		*(u16 *)&pOld[0x00] = 0x0000;
		*(u16 *)&pOld[0x02] = 0x0000;
		*(u16 *)&pOld[0x04] = 0x0000;
		*(u16 *)&pOld[0x06] = 0x0000;
		*(u16 *)&pOld[0x08] = 0x0000;
	}

l1AB8_15E8:
	pRec = &g_dgroup[(u16)(wArg08 * 0x0F + 0x520B)];   /* [bp-000Ah] */
	if ((*(u16 *)&pRec[0x04] | *(u16 *)&pRec[0x06]) != 0x0000)
		goto l1AB8_1741;                               /* 1607 jmp 1741 */

	/* 160A: build the file name "<record name><suffix at 1AB8:1531>" then
	 * open it.  bgi_open_video_driver_file(0xFFF3, &size, ds:0B74Ch, ds:0B764h, dsOut). */
	renamed_1eda_0a1f((u8 *)pRec + 0x0A, abBuf);
	renamed_1eda_0aac(&g_seg1AB8[0x1531], abBuf);
	renamed_1eda_0a39(0x08, &g_dgroup[0xB74C], abBuf, &dx_45);

	if (bgi_open_video_driver_file(0xFFF3, (u8 *)&wLoc02, &g_dgroup[0xB74C],
	                &g_dgroup[0xB764], &ds_1536) == 0x00)
	{
		/* 1650 */
		if (LG16(0xB818) == 0xFFFD)
			LG16(0xB818) = 0xFFF8;
		wArg08 = 0x0000;
		wArg04 = 0x0001;
		goto l1AB8_175E;
	}

	/* 166A: allocate the driver blob, temporarily overriding the INT 21h
	 * vector words [536Eh]/[5370h] with 1AB8:050B for the allocator. */
	{
		u16 ax_1C = LG16(0x536E);
		u16 dx_1C = LG16(0x5370);

		LG16(0xB7BC) = ax_1C;
		LG16(0xB7BE) = dx_1C;
		LG16(0x536E) = 0x050B;
		LG16(0x5370) = 0x1AB8;
		/* original: call dword ptr [0B6C2h] (1AB8:051F) */
		bgi_alloc_driver_blob(wLoc02, &dwLoc06);
		LG16(0x536E) = LG16(0xB7BC);
		LG16(0x5370) = LG16(0xB7BE);
	}

	if (dwLoc06 == 0x00000000u)
	{
		/* 16A7: allocation failed. */
		renamed_1eda_1051(0x00, &g_dgroup[0xB6CA]);
		LG16(0xB818) = 0xFFF7;
		wArg08 = 0x0000;
		wArg04 = 0x0001;
		goto l1AB8_175E;
	}

	/* 16C4: read the blob into the allocation, close, then validate it. */
	ax_10BB = renamed_1eda_10bb((u8 *)0, wLoc02,
	                      (u8 *)far_ptr(dwLoc06), &g_dgroup[0xB6CA]);
	renamed_1eda_1051((u8)ax_10BB, &g_dgroup[0xB6CA]);
	if (renamed_1eda_04a2() != 0x00)
		goto l1AB8_1709;

	ax_06CA = bgi_unload_video_driver(far_ptr(dwLoc06));
	/* original: cwd / cmp dx,bx / cmp ax,cx against (u16)wArg08 (16-bit). */
	if ((s32)(s16)ax_06CA != (s32)wArg08)
		goto l1AB8_1709;

	/* 1727: commit the record: +8 = size, +0/+2 = far blob pointer. */
	*(u16 *)&pRec[0x08] = wLoc02;
	*(u16 *)&pRec[0x00] = (u16)(dwLoc06 & 0xFFFFu);
	*(u16 *)&pRec[0x02] = (u16)((dwLoc06 >> 16) & 0xFFFFu);

l1AB8_1741:
	LG16(0xB74A) = wArg08;

l1AB8_1747:
	LG16(0xB836) = LG16((u16)(wArg08 * 0x0F + 0x520F));
	LG16(0xB838) = LG16((u16)(wArg08 * 0x0F + 0x5211));
	goto l1AB8_175E;                          /* asm: 1747 falls through to 175E */

l1AB8_1709:
	LG16(0xB818) = 0xFFF3;
	/* original: call dword ptr [0B6C6h] (1AB8:0538) */
	bgi_free_driver_blob(wLoc02, &dwLoc06);
	wArg08 = 0x0000;
	wArg04 = 0x0001;
	goto l1AB8_175E;

l1AB8_175E:
	LG16(0xB88C) = wArg08;
	LG16(0xB88E) = wArg06;
	LG16(0xB890) = wArg04;
	*dsOut = 0x0000;   /* DGROUP selector dropped in the flat model */
	return (void *)(uintptr_t)bgi_get_text_color_selector((u8)wArg04, (u8)wArg06, (u8)wArg08);
}

// 1AB8:1783: u16 bgi_display_error_string(u8 * ptrArg04)
u16 bgi_display_error_string(u8 * ptrArg04)  /* was fn1AB8_1783 */
{
	u8  abBuf[0x100];   /* [bp-0102h] renamed_1eda_0a39 destination (0x100 bytes) */
	u16 wLoc02;         /* [bp-0002h] */
	u16 dx_60;

	renamed_1eda_0a39(0xFF, abBuf, ptrArg04, &dx_60);
	wLoc02 = bgi_get_string_length();
	return wLoc02;
}

// 1AB8:17AE: void bgi_init_graphics_driver(void)
void bgi_init_graphics_driver(void)  /* was fn1AB8_17AE */
{
	u16 dx_45;

	LG16(0xB818) = 0x0000;
	LG16(0xB7B6) = 0x1000;
	bgi_clear_video_state();
	(void)bgi_init_graphics_error(&dx_45);

	/* Driver / helper dispatch table installed in DGROUP (off|seg<<16):
	 *   [0xB6C2]/[0xB6C4] = 1AB8:051F  (allocate blob)
	 *   [0xB6C6]/[0xB6C8] = 1AB8:0538  (free blob)
	 * bgi_init_graphics_error() has just staged the default [0xB820]/[0xB822] =
	 * 1AB8:008B ("graphics not initialized").  The loaded driver entry
	 * 1AB8:2093 (blob headed at 1AB8:2073) is staged later by bgi_load_bgi_driver,
	 * not here.  See the chunk 5a notes. */
	LG16(0xB6C2) = 0x051F;
	LG16(0xB6C4) = 0x1AB8;
	LG16(0xB6C6) = 0x0538;
	LG16(0xB6C8) = 0x1AB8;

	LG8(0xB74C) = 0x00;
	LG8(0xB756) = 0x00;
	LG16(0xB7B8) = 0x0006;
	LG16(0xB7BA) = 0x000A;
	LG16(0xB850) = 0x0001;   /* asm shows [renamed_0800_3850]; bytes are C7 06 50 B8 */
	LG16(0xB84A) = 0x0001;
	LG16(0xB84C) = 0x0001;
}
