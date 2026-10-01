/* seg1EDA_part5b.c -- RAD V3.1 preservation port, segment 1EDA, chunk 5b.
 *
 * Functions 1EDA:0F26 .. 1EDA:1051 (5 functions, ascending offset):
 *   0F26 0F71 0FA2 0FD0 1051
 * Literal recovery from analysis/slices/1EDA/1EDA_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes adopted exactly from
 * src/seg1EDA.h.  See CONVENTIONS.md and docs/notes-1EDA.md ("## chunk 5b").
 *
 * DOS services (int 21h):
 *   0FD0:100F  AH=3Dh -> msdos_open_file(path, mode)  (mode = DGROUP:0x5386)
 *   1051:1066  AH=3Eh -> msdos_close_file(handle)     (handle > 4 only)
 * The DOS error word DGROUP:0x5380 is read/written directly via LG16().
 * No int 10h / int 16h, no port I/O, no __cli/__sti or int 23h sites.
 *
 * Shared staging: none.  All state is DGROUP (LG8(0x5386) open mode,
 * LG16(0x5380) error word) or the caller-supplied stream block; no file-scope
 * variable crosses this translation unit, so src/seg1EDA_shared.h is not
 * modified.  See the notes for the cross-range call interfaces that the frozen
 * prototypes cannot express exactly (0E14's count return, 0E8E's flag return
 * and 1076's flag return).
 */

#include <stdint.h>
#include <string.h>

#include "radtypes.h"
#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "seg1EDA.h"
#include "pal.h"

/* 1EDA:0F26 -- format dwArg0C as decimal and write a padded field to
 * ptrArg06.
 *
 * 0E14 converts the 32-bit value into the 0x20-byte stack scratch at
 * [bp-20h] (SS:DI) and returns the digit count; the count arrives in CX but
 * the frozen prototype types 0E14's return as `u8 *` (the Reko member-pointer
 * return), so the recovered call recovers the 16-bit count from the returned
 * pointer value (note 1).  The field written is:
 *   ptrArg06[0]     = min(wArg0A, wArg04)   (the width byte, stosb)
 *   then (width - n) 0x20 spaces (rep stosb) and the n digits (rep movsb),
 * where the digit count is first clamped to wArg04 and the width byte is
 * raised to n if it was smaller.  All comparisons are signed (jle/jge). */
void renamed_1eda_0f26(s16 wArg04, u8 * ptrArg06, s16 wArg0A, u32 dwArg0C)
{
	u8 tLoc22[0x20];            /* [bp-20h] decimal-conversion scratch */
	s16 cx_21;                  /* 0E14 digit count (from CX) */
	s16 ax_181;
	s16 ax_73;
	u16 cx_126;
	u8 *di_125;

	cx_21 = (s16)(uintptr_t)fn1EDA_0E14(dwArg0C, 0x0000, (void *)tLoc22);

	ax_181 = wArg0A;
	if (wArg0A > wArg04)                       /* cmp ax,dx ; jle */
		ax_181 = wArg04;
	if (cx_21 > wArg04)                        /* cmp cx,dx ; jle */
		cx_21 = wArg04;
	if (ax_181 < cx_21)                        /* cmp ax,cx ; jge */
		ax_181 = cx_21;

	*ptrArg06 = (u8)ax_181;                    /* stosb */

	di_125 = ptrArg06 + 1;
	ax_73 = (s16)(ax_181 - cx_21);             /* sub ax,cx ; jz */
	if (ax_73 != 0x0000)
	{
		for (cx_126 = (u16)ax_73; cx_126 != 0x0000; --cx_126)
		{
			*di_125 = 0x20;                /* mov al,20h ; rep stosb */
			++di_125;
		}
	}
	memcpy(di_125, tLoc22, (u32)(u16)cx_21);   /* rep movsb */
}

/* 1EDA:0F71 -- parse a number from the length-prefixed string ptrArg08.
 *
 * ptrArg08[0] is the field length; up to that many leading spaces are
 * skipped, then 0E8E parses digits (and an optional +/-/$ prefix) starting at
 * ES:DI.  When the parse succeeds and consumes the whole field (0E8E returns
 * no carry and CX == 0) the parsed value is returned and *ptrArg04 = 0;
 * on a parse error or leftover characters *ptrArg04 = (end - ptrArg08) and
 * the return is 0.  siOut receives 0E8E's sign word; esOut receives the flat
 * selector analog of ptrArg04 (note 5). */
u16 renamed_1eda_0f71(u8 * ptrArg04, u8 * ptrArg08, u16 * siOut, void * esOut)
{
	u8 *di_15 = ptrArg08 + 1;   /* inc di */
	u16 cx_17 = ptrArg08[0];    /* mov cl,es:[di] ; xor ch,ch */
	u16 ax_30;
	u16 cx_34;
	u16 si_33;
	u8 *di_35;
	u8 err;

	if (cx_17 != 0x0000)                       /* jcxz 0F88h */
	{
		while (*di_15 == 0x20)             /* cmp byte es:[di],20h ; jnz */
		{
			++di_15;                   /* inc di */
			--cx_17;                   /* loop */
			if (cx_17 == 0x0000)
				break;
		}
	}

	err = renamed_1eda_0e8e(cx_17, di_15, NULL, &ax_30, &cx_34, &si_33,
	                  (u8 *)&di_35);           /* call 0E8Eh */
	if (err || cx_34 != 0x0000)                /* jc 0F8Fh ; jcxz 0F98h */
	{
		cx_34 = (u16)(di_35 - ptrArg08);   /* mov cx,di ; sub cx,[bp+0Ah] */
		ax_30 = 0x0000;                    /* xor ax,ax */
	}

	*(u16 *)ptrArg04 = cx_34;                  /* les di,[bp+6h] ; mov es:[di],cx */
	*siOut = si_33;
	*(u8 **)esOut = ptrArg04;                  /* SLICE(ptrArg04,selector,16) */
	return ax_30;
}

/* 1EDA:0FA2 -- (re)initialise the stream block ptrArg08: word 0 at +0,
 * id 0xD7B0 at +2, +4..+0x2F zeroed (0x16 word stores), then the
 * length-prefixed string ptrArg04 is copied: count = min(ptrArg04[0],0x4F)
 * bytes from ptrArg04+1 land at +0x30 and a NUL byte terminates the name. */
void renamed_1eda_0fa2(u8 * ptrArg04, u8 * ptrArg08)
{
	u8 *di_19 = ptrArg08 + 4;
	u16 cx_24;
	u8 al_29;

	*(u16 *)(ptrArg08 + 0) = 0x0000;           /* xor ax,ax ; stosw */
	*(u16 *)(ptrArg08 + 2) = 0xD7B0;           /* mov ax,0D7B0h ; stosw */
	for (cx_24 = 0x16; cx_24 != 0x0000; --cx_24)
	{
		*(u16 *)di_19 = 0x0000;            /* rep stosw */
		di_19 = (u8 *)((char *)di_19 + 2);
	}

	al_29 = ptrArg04[0];                       /* lodsb */
	if (al_29 > 0x4F)                          /* cmp al,4Fh ; jbe */
		al_29 = 0x4F;
	memcpy(di_19, ptrArg04 + 1, (u32)al_29);   /* mov cl,al ; rep movsb */
	di_19 += al_29;
	*di_19 = 0x00;                             /* xor al,al ; stosb */
}

/* 1EDA:0FD0 -- open (AH=3Dh) or re-arm the stream block ptrArg06.
 *
 * The entry loads AL from the DGROUP open-mode byte 0x5386 and sets AH=3Dh.
 * id 0xD7B0 (closed) falls straight into the open body; id 0xD7B3 (append) is
 * first reset to 0xD7B0 through 1051; any other id sets the DOS error word
 * 0x5380 = 0x66 and returns.  An empty name (+0x30 == 0) takes the dummy
 * handle path (xchg dx,ax); otherwise the NUL-terminated name at +0x30 is
 * opened.  On success the block becomes id 0xD7B3 with the handle at +0 and
 * wArg04 at +4, and wArg04 is returned; dxOut receives the original DX (0 on
 * the dummy path, the name pointer on the open path). */
u8 renamed_1eda_0fd0(u16 wArg04, u8 * ptrArg06, u16 * dxOut)
{
	u8 al_6 = LG8(0x5386);                     /* mov al,[5386h] */
	u16 dx_124 = 0x0000;                       /* xor dx,dx */
	u16 ax_108 = (u16)(0x3D00 | al_6);         /* mov ah,3Dh */

	if (*(u16 *)(ptrArg06 + 2) != 0xD7B0)      /* cmp es:[di+2],0D7B0h */
	{
		if (*(u16 *)(ptrArg06 + 2) != 0xD7B3) /* cmp es:[di+2],0D7B3h */
		{
			LG16(0x5380) = 0x0066;     /* mov [5380h],66h */
			goto l1EDA_1031;
		}
		(void)renamed_1eda_1051(al_6, ptrArg06); /* call 1051h (restores AX,DX) */
	}

	if (ptrArg06[0x30] != 0x00)                /* cmp byte es:[di+30h],0 */
	{
		u16 h;

		dx_124 = (u16)(uintptr_t)(ptrArg06 + 0x30); /* lea dx,[di+30h] */
		h = msdos_open_file((char *)(ptrArg06 + 0x30), al_6); /* int 21h */
		if (h == 0xFFFF)                   /* jc 101Bh */
		{
			LG16(0x5380) = h;          /* mov [5380h],ax */
			goto l1EDA_1031;
		}
		ax_108 = h;
	}
	else
	{
		u16 t = ax_108;                    /* xchg dx,ax */

		ax_108 = dx_124;
		dx_124 = t;
	}

	*(u16 *)(ptrArg06 + 2) = 0xD7B3;           /* mov word es:[di+2],0D7B3h */
	*(u16 *)(ptrArg06 + 0) = ax_108;           /* mov es:[di],ax */
	*(u16 *)(ptrArg06 + 4) = wArg04;           /* mov ax,[bp+6h] ; mov es:[di+4h],ax */
	ax_108 = wArg04;

l1EDA_1031:
	*dxOut = dx_124;
	return (u8)ax_108;
}

/* 1EDA:1051 -- close/re-arm the stream block ptrArg04.
 *
 * Calls 1076, which sets the DOS error word 0x5380 = 0x67 unless the block id
 * is 0xD7B3.  Only when the id is 0xD7B3 does the body run: the handle at +0
 * is closed if greater than 4 (the predefined DOS device handles are left
 * alone; AH=3Eh) and the DOS error is latched into 0x5380 on failure, then the
 * id is forced back to 0xD7B0.  The `al` argument is not consumed by the
 * original body; the original leaves AX undefined at `retf 4h` and no caller
 * uses the result, so the flat function returns 0 (note 6). */
u16 renamed_1eda_1051(u8 al, u8 * ptrArg04)
{
	u16 bx_15;
	u16 ax_16;

	(void)al;
	(void)fn1EDA_1076(ptrArg04);               /* call 1076h ; jnz 1073h */

	if (*(u16 *)(ptrArg04 + 2) == 0xD7B3)      /* ZF from 1076's cmp */
	{
		bx_15 = *(u16 *)(ptrArg04 + 0);    /* mov bx,es:[di] */
		if (bx_15 > 0x0004)                /* cmp bx,4h ; jbe */
		{
			ax_16 = msdos_close_file(bx_15);   /* mov ah,3Eh ; int 21h */
			if (ax_16 == 0xFFFF)               /* jnc 106Dh */
				LG16(0x5380) = ax_16;      /* mov [5380h],ax */
		}
		*(u16 *)(ptrArg04 + 2) = 0xD7B0;   /* mov word es:[di+2],0D7B0h */
	}
	return 0x0000;
}
