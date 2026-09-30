/* seg1EDA_part4b.c -- RAD V3.1 preservation port, segment 1EDA, chunk 4b.
 *
 * Functions 1EDA:0A39 .. 1EDA:0DCF (12 functions, ascending offset):
 *   0A39 0A6B 0AAC 0AD8 0B24 0B4F 0B61 0B7C 0BD0 0CD4 0D80 0DCF
 * Literal recovery from analysis/slices/1EDA/1EDA_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg1EDA.h.
 * See CONVENTIONS.md and docs/notes-1EDA.md ("## chunk 4b").
 *
 * Hardware / DOS services: none of these functions issues an int 10h /
 * int 16h / int 21h or port I/O.  The only DGROUP cells touched are the
 * 32-bit counter at 0x5382/0x5384 (0DCF) and the code-segment constant at
 * 1EDA:0E05 (0DCF's `mul word ptr cs:[0E05h]`, read from g_seg1EDA).
 *
 * Record helpers (0A39/0A6B/0AAC/0B4F/0B61/0AD8/0B24) operate on the
 * Turbo-C length-prefixed strings: byte 0 is the length, bytes 1.. are the
 * data.  The far pointers the original exchanged on the stack (SS/ES/DS
 * selectors) are flat pointers here; the original's "stack-reuse" calling
 * pattern (a destination far pointer pushed once and shared by a following
 * 0A6B/0AAC/0A39 call) is recovered with explicit arguments, following the
 * part-4 convention (`fn1EDA_0A1F`).
 *
 * 0B7C / 0BD0 each carve two 0x100-byte records out of a single 0x200-byte
 * stack frame: buffer1 = [bp-0x100], buffer2 = [bp-0x200]; they are the
 * `fp-0x102`/`fp-0x202` locals of the Reko output.
 */

#include <stdint.h>
#include <string.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1EDA.h"
#include "pal.h"

/* Little-endian 16-bit read from the code-segment image (`cs:[off]`). */
static u16 seg1EDA_word(u16 off)
{
	return (u16)((u16)g_seg1EDA[off] | ((u16)g_seg1EDA[(u16)(off + 1)] << 8));
}

/* 1EDA:0A39 -- copy the length-prefixed record ptrArg0A to ptrArg06, clamped
 * to at most bArg04 bytes of payload (lodsb/stosb/rep movsb). */
u8 fn1EDA_0A39(u8 bArg04, u8 * ptrArg06, u8 * ptrArg0A, void * dxOut)
{
	u8 cl_17 = bArg04;                      /* mov cx,ss:[bx+4h] (cl) */
	u8 al_15 = ptrArg0A[0];                 /* lodsb */
	u16 count;

	if (al_15 > cl_17)                      /* cmp al,cl ; jbe 0A51h */
		al_15 = cl_17;
	ptrArg06[0] = al_15;                    /* stosb */
	count = (u16)al_15;                     /* mov cl,al ; xor ch,ch */
	memcpy(ptrArg06 + 1, ptrArg0A + 1, (u32)count);   /* rep movsb */
	/* Reko's dxOut = ds (the caller's restored DS selector); dropped. */
	*(u16 *)dxOut = 0x0000;
	return al_15;
}

/* 1EDA:0A6B -- extract a substring of the record ptrArg08 starting at offset
 * wArg06 (forced to 1 when <= 0), length min(srcLen - offset + 1, wArg04
 * clamped to >= 0), storing it as a record at ptrArg0C.  A start beyond the
 * source length yields an empty record. */
void fn1EDA_0A6B(u16 wArg04, u16 wArg06, u8 * ptrArg08, u8 * ptrArg0C)
{
	u16 ax_27 = (u16)ptrArg08[0];           /* lodsb ; xor ah,ah */
	u16 cx_17 = wArg06;                     /* mov cx,ss:[bx+6h] */
	u8 *  si_25;
	u16 ax_114;

	if ((s16)cx_17 <= 0x0000)               /* or cx,cx ; jg 0A87h */
		cx_17 = 0x0001;
	si_25 = ptrArg08 + cx_17;               /* add si,cx */
	if (ax_27 < cx_17)                      /* sub ax,cx ; jc 0AA0h */
	{
		ax_114 = 0x0000;                /* xor ax,ax */
	}
	else
	{
		ax_114 = (u16)((u16)(ax_27 - cx_17) + 0x0001);   /* inc ax */
		cx_17 = wArg04;                 /* mov cx,ss:[bx+4h] */
		if ((s16)cx_17 < 0x0000)        /* or cx,cx ; jge 0A98h */
			cx_17 = 0x0000;
		if (ax_114 > cx_17)             /* cmp ax,cx ; jbe 0AA2h */
			ax_114 = cx_17;         /* mov ax,cx */
	}
	ptrArg0C[0] = (u8)ax_114;               /* stosb */
	memcpy(ptrArg0C + 1, si_25, (u32)ax_114);   /* mov cx,ax ; rep movsb */
}

/* 1EDA:0AAC -- append the record ptrArg04 to the record ptrArg08.  The
 * destination length byte saturates at 0xFF; on overflow only the bytes that
 * fit (0xFF - oldLength) are copied (rep movsb count = ~oldLength). */
void fn1EDA_0AAC(u8 * ptrArg04, u8 * ptrArg08)
{
	u8  cl_14 = ptrArg08[0];                /* mov cl,es:[di] */
	u8  al_18 = ptrArg04[0];                /* lodsb */
	u16 sum = (u16)ptrArg08[0] + (u16)al_18;
	u16 count;

	ptrArg08[0] = (u8)sum;                  /* add es:[di],al */
	if (sum > 0x00FF)                       /* jnc 0ACCh */
	{
		ptrArg08[0] = 0xFF;             /* mov byte es:[di],0FFh */
		al_18 = (u8)~cl_14;             /* mov al,cl ; not al */
	}
	count = (u16)al_18;                     /* mov cl,al */
	memcpy(ptrArg08 + 1 + (u16)cl_14, ptrArg04 + 1, (u32)count);   /* rep movsb */
}

/* 1EDA:0AD8 -- startup path selector / length-prefixed-string matcher.
 * ptrArg04[0] is the text length; the text data starts at ptrArg04+1.
 * ptrArg08 is the pattern, dispatched on its length byte:
 *   0   -> immediate "match" at offset 1;
 *   1   -> the single byte ptrArg08[1] is searched in the text (repne scasb);
 *   >1  -> the pattern bytes ptrArg08[1..len] are compared at successive
 *          text offsets (the outer dx = textLen - patternLen + 1 positions).
 * Returns the advanced pattern pointer (Reko's DS:SI; SI points just past the
 * matched pattern, or ptrArg08+1 / ptrArg08+2 / left at the exhausted
 * position) and stores the 0-based match offset in *axOut (0 = no match). */
u8 * fn1EDA_0AD8(u8 * ptrArg04, u8 * ptrArg08, u16 * axOut)
{
	u8 * di = ptrArg04;                     /* les di,ss:[bx+4h] */
	u8 * si = ptrArg08;                     /* lds si,ss:[bx+8h] */
	u16 cx_19 = (u16)ptrArg04[0];           /* mov cl,es:[di] ; xor ch,ch */
	u16 ax_126;
	u16 ax_30;
	u16 dx_31;
	u16 n;
	u8  all_equal;
	u8  target;
	u8  zf;
	u8  v;

	if (cx_19 == 0x0000)                    /* jcxz 0B14h */
	{
		ax_126 = 0x0000;
		goto l1EDA_0B20;
	}

	++di;                                   /* inc di */
	ax_126 = (u16)si[0];                    /* lodsb */
	++si;
	if ((u8)ax_126 < 0x01)                  /* cmp al,1h ; jc 0B1Ah */
		goto l1EDA_0B1A;
	if ((u8)ax_126 > 0x01)                  /* ja 0AFBh */
		goto l1EDA_0AFB;

	/* al == 1: repne scasb for the next pattern byte over the text. */
	target = si[0];                         /* lodsb */
	++si;
	zf = 0x00;
	while (cx_19 != 0x0000)
	{
		v = *di;
		++di;
		--cx_19;
		if (v == target)
		{
			zf = 0x01;
			break;
		}
	}
	if (zf == 0x00)                         /* jnz 0B14h */
	{
		ax_126 = 0x0000;
		goto l1EDA_0B20;
	}
	--di;                                   /* dec di */
	goto l1EDA_0B1A;

l1EDA_0AFB:
	ax_30 = (u16)(u8)ax_126;                /* xor ah,ah */
	if (cx_19 < ax_30)                      /* mov dx,cx ; sub dx,ax ; jc */
	{
		ax_126 = 0x0000;
		goto l1EDA_0B20;
	}
	dx_31 = (u16)((u16)(cx_19 - ax_30) + 0x0001);   /* inc dx */
	for (;;)
	{
		n = ax_30;                      /* mov cx,ax */
		all_equal = 0x01;
		while (n != 0x0000)             /* rep cmpsb */
		{
			u8 a = *si;
			u8 b = *di;

			++si;
			++di;
			--n;
			if (a != b)
			{
				all_equal = 0x00;
				break;
			}
		}
		if (all_equal != 0x00)          /* jz 0B18h */
		{
			di -= ax_30;            /* sub di,ax */
			ax_126 = (u16)(di - ptrArg04);   /* 0B1Ah */
			break;
		}
		n = (u16)(n - ax_30);           /* sub cx,ax */
		si += (s16)n;                   /* add si,cx (16-bit wrap -> rewind) */
		di += (s16)n;                   /* add di,cx */
		++di;                           /* inc di */
		if (--dx_31 == 0x0000)          /* dec dx ; jnz 0B04h */
		{
			ax_126 = 0x0000;
			break;
		}
	}
	goto l1EDA_0B20;

l1EDA_0B1A:
	ax_126 = (u16)(di - ptrArg04);          /* mov ax,di ; sub ax,[bp+4h] */
l1EDA_0B20:
	*axOut = ax_126;                        /* pop ds ; retf 8h */
	return si;
}

/* 1EDA:0B24 -- length-prefixed string compare.  Compares min(lenA,lenB) data
 * bytes; when they are equal the result is (lenA == lenB), otherwise 0.  The
 * frozen u8 return carries the ZF (nonzero on equality), matching the
 * documented correction in src/seg1AB8_part1.c.  *axOut receives the AX left
 * by the compare path (which Reko left undefined), ah = ptrArg04[0],
 * al = ptrArg08[0]; dxOut is the dropped DS selector. */
u8 fn1EDA_0B24(u8 * ptrArg04, u8 * ptrArg08, u16 * axOut, void * dxOut)
{
	u8 al_14 = ptrArg08[0];                 /* lodsb */
	u8 ah_18 = ptrArg04[0];                 /* mov ah,es:[di] */
	u8 cl_20 = al_14;                       /* mov cl,al */
	u8 zf;

	if (al_14 > ah_18)                      /* cmp cl,ah ; jbe 0B3Eh */
		cl_20 = ah_18;
	if (cl_20 != 0x00)                      /* or cl,cl ; jz 0B48h */
	{
		int cmp = memcmp(ptrArg08 + 1, ptrArg04 + 1, (u32)cl_20);   /* rep cmpsb */
		if (cmp != 0x00)                /* jnz 0B4Ah */
			zf = 0x00;
		else
			zf = (u8)(al_14 == ah_18);  /* cmp al,ah */
	}
	else
	{
		zf = (u8)(al_14 == ah_18);
	}
	*axOut = (u16)(((u16)ah_18 << 8) | (u16)al_14);
	*(u16 *)dxOut = 0x0000;                 /* dropped DS selector */
	return zf;
}

/* 1EDA:0B4F -- build the 2-byte record {1, bArg04} at ptrArg06. */
void fn1EDA_0B4F(u8 bArg04, u8 * ptrArg06)
{
	ptrArg06[0] = 0x01;                     /* mov al,1h ; stosb */
	ptrArg06[1] = bArg04;                   /* mov al,ss:[bx+4h] ; stosb */
}

/* 1EDA:0B61 -- build the length-prefixed record {wArg04, ptrArg06[0..]} at
 * ptrArg0A (stosb + rep movsb; the length byte is wArg04's low byte, the copy
 * count is the full word). */
void fn1EDA_0B61(u16 wArg04, u8 * ptrArg06, u8 * ptrArg0A)
{
	ptrArg0A[0] = (u8)wArg04;               /* stosb (al) */
	memcpy(ptrArg0A + 1, ptrArg06, (u32)wArg04);   /* mov cx,ax ; rep movsb */
}

/* 1EDA:0B7C -- build a record in the two 0x100-byte stack buffers and copy it
 * back to ptrArg08.  buffer1 = substring(ptrArg08, 1, wArg04-1); append
 * ptrArg0C; buffer2 = substring(ptrArg08, wArg04, 0xFF); append buffer2;
 * then clamp-copy buffer1 into ptrArg08 with width (u8)wArg06. */
void fn1EDA_0B7C(u16 wArg04, u16 wArg06, u8 * ptrArg08, u8 * ptrArg0C)
{
	u8  buf1[0x100];                        /* [bp-0100h] ptrLoc0206 */
	u8  buf2[0x100];                        /* [bp-0200h] ptrLoc020A */
	u16 dx_163;

	fn1EDA_0A6B((u16)(wArg04 - 0x0001), 0x0001, ptrArg08, buf1);
	fn1EDA_0AAC(ptrArg0C, buf1);
	fn1EDA_0A6B(0x00FF, wArg04, ptrArg08, buf2);
	fn1EDA_0AAC(buf2, buf1);
	(void)fn1EDA_0A39((u8)wArg06, ptrArg08, buf1, &dx_163);
}

/* 1EDA:0BD0 -- as 0B7C but only when wArg04 > 0: buffer1 =
 * substring(ptrArg08, 1, wArg06-1); buffer2 = substring(ptrArg08, wArg06,
 * wArg06+wArg04); append buffer2 to buffer1; clamp-copy buffer1 (0xFF) to
 * ptrArg08. */
void fn1EDA_0BD0(s16 wArg04, u16 wArg06, u8 * ptrArg08)
{
	u8  buf1[0x100];                        /* [bp-0100h] ptrLoc0206 */
	u8  buf2[0x100];                        /* [bp-0200h] ptrLoc020A */
	u16 dx_172;

	if (wArg04 > 0x0000)                    /* cmp word [bp+6h],0 ; jle */
	{
		fn1EDA_0A6B((u16)(wArg06 - 0x0001), 0x0001, ptrArg08, buf1);
		fn1EDA_0A6B(0x00FF, (u16)(wArg06 + wArg04), ptrArg08, buf2);
		fn1EDA_0AAC(buf2, buf1);
		(void)fn1EDA_0A39(0x00FF, ptrArg08, buf1, &dx_172);
	}
}

/* 1EDA:0CD4 -- bit test: returns the ZF left by `test es:[bx+di],al`, i.e.
 * nonzero when bit (bArg08 & 7) of ptrArg04[bArg08 >> 3] is CLEAR.  esOut is
 * the dropped ES selector of ptrArg04 (flat analog = ptrArg04, part-5b
 * convention). */
u8 fn1EDA_0CD4(u8 * ptrArg04, u8 bArg08, void * esOut)
{
	u16 bx = (u16)bArg08;                   /* mov bl,al ; xor bh,bh */
	u8  cl_19;
	u8  mask;
	u8  value;

	bx >>= 3;                               /* mov cl,3h ; shr bx,cl */
	cl_19 = (u8)(bArg08 & 0x07);            /* mov cl,al ; and cl,7h */
	mask = (u8)(1u << cl_19);               /* mov al,1h ; shl al,cl */
	value = ptrArg04[bx];                   /* test es:[bx+di],al */
	*(u8 **)esOut = ptrArg04;               /* SLICE(ptrArg04,selector,16) */
	return (u8)((value & mask) == 0x00);    /* ZF */
}

/* 1EDA:0D80 -- divide the 0DCF counter (DX half) by wArg04: *dxOut gets the
 * quotient, the function returns the remainder; wArg04 == 0 leaves both as the
 * counter DX and 0.  The original does the divide as `div bx` on DX:AX = 0:DX
 * so the quotient cannot overflow. */
u16 fn1EDA_0D80(u16 wArg04, u16 * dxOut)
{
	u16 dx_32 = fn1EDA_0DCF();              /* call 0DCFh */
	u16 ax_13 = 0x0000;                     /* xor ax,ax */

	if (wArg04 != 0x0000)                   /* or bx,bx ; jz 0D93h */
	{
		u16 d = dx_32;

		dx_32 = (u16)(d / wArg04);      /* xchg dx,ax ; div bx ; xchg */
		ax_13 = (u16)(d % wArg04);
	}
	*dxOut = dx_32;
	return ax_13;
}

/* 1EDA:0DCF -- advance the 32-bit pseudo-random counter at DGROUP:0x5382/
 * 0x5384 by one step and return its high word (DX).  The literal 8086
 * sequence: DX:AX = counter * cs:[0E05h] (0x8405), then a long series of
 * partial `add ch,cl` / `add dh,bl` byte adds (which do NOT carry into the
 * neighbouring byte), `add ax,1 ; adc dx,0`, store both halves. */
u16 fn1EDA_0DCF(void)
{
	u16 ax_6 = LG16(0x5382);
	u16 bx_7 = LG16(0x5384);
	u16 los;
	u16 dx;
	u16 cx;
	u16 bx;
	u32 prod;
	u32 s;
	u8  dh;

	prod = (u32)ax_6 * (u32)seg1EDA_word(0x0E05);   /* mul word cs:[0E05h] */
	los = (u16)prod;
	dx = (u16)(prod >> 16);
	cx = (u16)(ax_6 << 3);                  /* mov cx,ax ; shl cx,1 x3 */

	dh = (u8)(dx >> 8);                     /* add ch,cl */
	dh = (u8)(dh + (u8)cx);
	dx = (u16)(((u16)dh << 8) | (u8)dx);

	dx = (u16)(dx + cx);                    /* add dx,cx */
	dx = (u16)(dx + bx_7);                  /* add dx,bx */

	bx = (u16)(bx_7 << 2);                  /* shl bx,1 x2 */
	dx = (u16)(dx + bx);                    /* add dx,bx */

	dh = (u8)(dx >> 8);                     /* add dh,bl */
	dh = (u8)(dh + (u8)bx);
	dx = (u16)(((u16)dh << 8) | (u8)dx);

	bx = (u16)(bx << 5);                    /* mov cl,5h ; shl bx,cl */
	dh = (u8)(dh + (u8)bx);                 /* add dh,bl */
	dx = (u16)(((u16)dh << 8) | (u8)dx);

	s = (u32)los + 0x0001;                  /* add ax,1h ; adc dx,0h */
	los = (u16)s;
	dx = (u16)(dx + (u16)(s >> 16));

	LG16(0x5382) = los;                     /* mov [5382h],ax */
	LG16(0x5384) = dx;                      /* mov [5384h],dx */
	return dx;
}
