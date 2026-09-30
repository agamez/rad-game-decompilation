/* seg1EDA_part5a.c -- RAD V3.1 preservation port, segment 1EDA, chunk 5a.
 *
 * Functions 1EDA:0E07 .. 1EDA:0E8E (3 functions, ascending offset):
 *   0E07 0E14 0E8E
 * Literal recovery from analysis/slices/1EDA/1EDA_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg1EDA.h.
 * See CONVENTIONS.md and docs/notes-1EDA.md ("## chunk 5a").
 *
 * Hardware / DOS services (CONVENTIONS.md rule 4):
 *   1EDA:0E07  int 21h AH=2Ch -> msdos_get_system_time
 * No other function in this range issues an int 10h / int 16h / int 21h or
 * port I/O; 0E14 / 0E8E are pure decimal/hex integer formatters.
 *
 * 1EDA:0E66 holds a 10-entry little-endian u32 power-of-ten table
 * (1000000000 .. 1) embedded in the code segment; it is read from the loaded
 * segment image g_seg1EDA (cs:[si] / cs:[si+2h]), following the
 * `segXXXX:off` -> `g_segXXXX[off]` rule of the memory model.
 *
 * Flat pointer conventions (see notes):
 *   0E14 `u16 di, void * es`  -- Reko's `di` is a plain 16-bit register and
 *        `es` a segment pointer, so ES is the flat base and DI the byte
 *        offset: the effective byte is (u8 *)es + di.  (Same shape as
 *        seg1E5F fn1E5F_0136.)
 *   0E8E `u8 * di, void * es` -- Reko's `di` is a `(memptr byte)`, which the
 *        port's memptr rule maps to the flat byte pointer; `di` is therefore
 *        used directly and the byte-segment `es` parameter is dropped.
 */

#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1EDA.h"
#include "pal.h"

/* Little-endian 32-bit read from the code-segment image (`cs:[si]`). */
static u32 seg1EDA_dword(u16 off)
{
	return (u32)g_seg1EDA[off]
	     | ((u32)g_seg1EDA[(u16)(off + 1)] << 8)
	     | ((u32)g_seg1EDA[(u16)(off + 2)] << 16)
	     | ((u32)g_seg1EDA[(u16)(off + 3)] << 24);
}

/* 1EDA:0E07 -- latch the current DOS time into DGROUP:0x5382 (CX = hour:
 * minute) and DGROUP:0x5384 (DX = second:hundredths).  int 21h AH=2Ch. */
void fn1EDA_0E07(void)
{
	u8 ch_5;                                    /* hour       */
	u8 cl_8;                                    /* minute     */
	u8 dh_6;                                    /* second     */
	u8 dl_7;                                    /* hundredths */

	msdos_get_system_time(&ch_5, &cl_8, &dh_6, &dl_7);
	LG16(0x5382) = (u16)(((u16)ch_5 << 8) | (u16)cl_8);   /* mov [5382h],cx */
	LG16(0x5384) = (u16)(((u16)dh_6 << 8) | (u16)dl_7);   /* mov [5384h],dx */
}

/* 1EDA:0E14 -- format the signed 32-bit value DX:AX into the ES:DI buffer as
 * a variable-width decimal string (no leading zeros beyond the leading digit),
 * writing a '-' first for a negative value.  The 8086 sequence walks the
 * 10-entry power-of-ten table at 1EDA:0E66 downwards, emitting one digit per
 * table entry.  Returns the number of bytes written (CX); the frozen
 * prototype types the return as `u8 *` (from Reko's memptr return), so the
 * 16-bit count is carried in the pointer value (see notes). */
u8 * fn1EDA_0E14(u32 dx_ax, u16 di, void * es)
{
	u8 *base = (u8 *)es;                /* es is the flat base; di an offset */
	u16 bx_102;                         /* low half of the value             */
	u16 dx_98;                          /* high half of the value            */
	u16 di_118 = di;                    /* output cursor                     */
	u16 si_106;                         /* table cursor (segment offset)     */
	u8 cl_30;                           /* remaining table entries           */
	u8 cl_49;                           /* number of digits to emit          */

	/* mov bx,ax ; or dx,dx ; jge 0E29h */
	if ((s32)dx_ax < 0)
	{
		/* not bx ; not dx ; add bx,1h ; adc dx,0h */
		u32 neg = ~dx_ax + 0x00000001u;

		bx_102 = (u16)neg;
		dx_98 = (u16)(neg >> 16);
		base[di_118] = 0x2D;            /* mov al,2Dh ; stosb */
		++di_118;
	}
	else
	{
		bx_102 = (u16)dx_ax;            /* mov bx,ax */
		dx_98 = (u16)(dx_ax >> 16);
	}

	/* mov si,0E66h ; mov cl,9h -- find the largest power of ten <= value. */
	si_106 = 0x0E66;
	cl_30 = 0x09;
l1EDA_0E2E:
	if (dx_98 < (u16)(seg1EDA_dword(si_106) >> 16))         /* cmp dx,cs:[si+2h] ; jc 0E3Bh */
		goto l1EDA_0E3B;
	/* l1EDA_0E34: ja 0E42h */
	if (dx_98 > (u16)(seg1EDA_dword(si_106) >> 16))
		goto l1EDA_0E42;
	/* l1EDA_0E36: cmp bx,cs:[si] ; jnc 0E42h */
	if (bx_102 >= (u16)seg1EDA_dword(si_106))
		goto l1EDA_0E42;
l1EDA_0E3B:
	si_106 = (u16)(si_106 + 4);                             /* add si,4h */
	--cl_30;                                                /* dec cl */
	if (cl_30 != 0)                                         /* jnz 0E2Eh */
		goto l1EDA_0E2E;

l1EDA_0E42:
	cl_49 = (u8)(cl_30 + 1);                                /* inc cl */
	do
	{
		u32 entry = seg1EDA_dword(si_106);
		u8 al_51 = 0x2F;                                    /* mov al,2Fh */
		u32 dv = ((u32)dx_98 << 16) | (u32)bx_102;
		u8 borrow;

		do
		{
			al_51 = (u8)(al_51 + 1);                        /* inc al */
			borrow = (u8)(dv < entry);                      /* sub/sbb borrow */
			dv = dv - entry;
		} while (borrow == 0);                                  /* jnc 0E46h */

		dv = dv + entry;                                        /* add bx,cs:[si] ; adc dx,cs:[si+2h] */
		bx_102 = (u16)dv;
		dx_98 = (u16)(dv >> 16);
		si_106 = (u16)(si_106 + 4);                             /* add si,4h */
		base[di_118] = al_51;                                   /* stosb */
		++di_118;
		--cl_49;
	} while (cl_49 != 0);                                           /* dec cl ; jnz 0E44h */

	/* mov cx,di ; pop di ; sub cx,di -- byte count returned in CX.  The
	 * frozen `u8 *` return cannot express CX, so the 16-bit count is the
	 * pointer value; callers recover it with (u16)(uintptr_t). */
	return (u8 *)(uintptr_t)(u16)(di_118 - di);
}

/* 1EDA:0E8E -- ASCII-to-integer scanner.  cx counts the available bytes and
 * di points at the first one.  Optional leading '+' / '-' (sign latched in
 * si), then either plain decimal digits or a '$'-prefixed hex number.
 * Accumulates into DX:AX, rejecting overflow (CF set).  Outputs:
 *   axOut = AX   cxOut = remaining CX   siOut = sign/result flag
 *   diOut = final DI pointer
 * Returns 1 when the original set CF (error/overflow), 0 when clear.
 *
 * `di` is a memptr in Reko, i.e. the flat byte pointer; the `es`
 * byte-segment parameter is redundant in the flat model and dropped. */
u8 fn1EDA_0E8E(u16 cx, u8 * di, void * es, u16 * axOut, u16 * cxOut, u16 * siOut, u8 * diOut)
{
	u16 ax_102 = 0x0000;                /* xor ax,ax */
	u16 dx_91 = 0x0000;                 /* xor dx,dx */
	u16 si_148 = 0x0000;                /* xor si,si */

	(void)es;                           /* see note above */

	if (cx == 0x0000)                   /* jcxz 0EEFh */
		goto l1EDA_0EEF;

	/* l1EDA_0E96: cmp byte es:[di],2Bh ; jz 0EA3h */
	if (*di == 0x2B)
		goto l1EDA_0EA3;
	/* l1EDA_0E9C: cmp byte es:[di],2Dh ; jnz 0EA7h */
	if (*di != 0x2D)
		goto l1EDA_0EA7;
	/* l1EDA_0EA2: inc si */
	si_148 = 0x0001;
l1EDA_0EA3:
	++di;                               /* inc di */
	--cx;                               /* dec cx */
	if (cx == 0x0000)                   /* jcxz 0EEFh */
		goto l1EDA_0EEF;

l1EDA_0EA7:
	if (*di == 0x24)                    /* cmp byte es:[di],24h ; jz 0EF1h */
		goto l1EDA_0EF1;

	/* ------------------------- decimal digits (0EAD) -------------------- */
l1EDA_0EAD:
	{
		u8 bl_86 = *di;                 /* mov bl,es:[di] */
		u8 bl_45 = (u8)(bl_86 - 0x3A);  /* sub bl,3Ah */
		u16 sum = (u16)bl_45 + 0x000A;  /* add bl,0Ah */
		u8 bl_46 = (u8)sum;

		if (sum <= 0x00FF)              /* jnc 0EE0h (not a decimal digit) */
			goto l1EDA_0EE0;
		if ((dx_91 & 0xF000) != 0x0000) /* test dx,0F000h ; jnz 0EEFh */
			goto l1EDA_0EEF;
		{
			/* shl ax,1 / rcl dx,1 x3 + adds == value * 10 + digit */
			u32 acc = ((u32)dx_91 << 16) | (u32)ax_102;

			acc = (acc * 10u) + (u32)bl_46;
			ax_102 = (u16)acc;
			dx_91 = (u16)(acc >> 16);
		}
		if ((dx_91 & 0x8000) != 0x0000) /* js 0EEFh */
			goto l1EDA_0EEF;
		++di;                           /* inc di */
		--cx;                           /* loop 0EADh */
		if (cx != 0x0000)
			goto l1EDA_0EAD;
		goto l1EDA_0EE0;
	}

	/* --------------------------- hex digits (0EF1) --------------------- */
l1EDA_0EF1:
	++di;                               /* inc di */
	--cx;                               /* dec cx */
	if (cx == 0x0000)                   /* jcxz 0EEFh */
		goto l1EDA_0EEF;

l1EDA_0EF5:
	{
		u8 bl_39 = *di;                 /* mov bl,es:[di] */
		u8 bl_46;

		if (bl_39 >= 0x61)              /* cmp bl,61h ; jc 0F00h */
			bl_39 = (u8)(bl_39 - 0x20); /* sub bl,20h (to upper case) */
		{
			u8 bl_45 = (u8)(bl_39 - 0x3A);  /* sub bl,3Ah */
			u16 s1 = (u16)bl_45 + 0x000A;   /* add bl,0Ah */

			bl_46 = (u8)s1;
			if (s1 > 0x00FF)                /* jc 0F13h (decimal digit) */
				goto l1EDA_0F13;
			{
				u8 bl2 = (u8)(bl_46 - 0x17);    /* sub bl,17h */
				u16 s2 = (u16)bl2 + 0x0006;     /* add bl,6h */

				bl_46 = (u8)s2;
				if (s2 <= 0x00FF)               /* jnc 0EE0h (not hex digit) */
					goto l1EDA_0EE0;
				bl_46 = (u8)(bl_46 + 0x0A);     /* add bl,0Ah */
			}
		}
	l1EDA_0F13:
		{
			u8 bh_55;

			for (bh_55 = 0x04; bh_55 != 0x00; --bh_55)      /* mov bh,4h */
			{
				u8 cout = (u8)(dx_91 >> 15);    /* CF out of rcl dx,1 */
				u32 acc = ((u32)dx_91 << 16) | (u32)ax_102;

				acc = acc << 1;                 /* shl ax,1 ; rcl dx,1 */
				ax_102 = (u16)acc;
				dx_91 = (u16)(acc >> 16);
				if (cout)                       /* jc 0EEFh */
					goto l1EDA_0EEF;
			}
		}
		ax_102 = (u16)(ax_102 | (u16)bl_46);    /* or al,bl */
		++di;                                   /* inc di */
		--cx;                                   /* loop 0EF5h */
		if (cx != 0x0000)
			goto l1EDA_0EF5;
		goto l1EDA_0EE0;                        /* 0F24: jmp 0EE0h */
	}

	/* ------------------------------ success ---------------------------- */
l1EDA_0EE0:
	{
		u16 si_154 = (u16)(si_148 - 0x0001);    /* dec si */
		u16 ax_157 = ax_102;

		if (si_154 == 0x0000)                   /* jnz 0EEDh (was negative) */
			ax_157 = (u16)((u16)~ax_102 + 0x0001);  /* not ax ; add ax,1 */
		*axOut = ax_157;
		*cxOut = cx;
		*siOut = si_154;
		*(u8 **)diOut = di;                     /* memptr out: store the flat pointer */
		return 0x00;                            /* clc */
	}

	/* ------------------------------- error ----------------------------- */
l1EDA_0EEF:
	*axOut = ax_102;
	*cxOut = cx;
	*siOut = si_148;
	*(u8 **)diOut = di;                             /* memptr out: store the flat pointer */
	return 0x01;                                /* stc */
}
