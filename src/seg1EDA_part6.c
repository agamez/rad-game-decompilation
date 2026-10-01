/* seg1EDA_part6.c -- RAD V3.1 preservation port, segment 1EDA, chunk 6.
 *
 * Functions 1EDA:1076 .. 1EDA:1384 (16 functions, ascending offset):
 *   1076 1085 108C 1091 10BB 1123 116A 1185 119A 11DF 1202 1216 1265 126C
 *   129E 1384
 * Literal recovery from analysis/slices/1EDA/1EDA_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg1EDA.h.
 * See CONVENTIONS.md and docs/notes-1EDA.md ("## chunk 6").
 *
 * This range is the DOS file-record layer of the CRT stream package plus the
 * environment / command-line helpers:
 *   1076      stream-id guard (block[+2] == 0xD7B3?) -- returns ZF
 *   1085/108C/1091   read/write a record (INT 21h AH=3F/40)
 *   10BB      read `count` records of block[+4] bytes (INT 21h AH=3F)
 *   1123      seek to record offset wArg06:wArg04 (INT 21h AH=42 AL=00)
 *   116A/1185 record count / file-position compare (via 119A + 098A)
 *   119A      size+restore seek (three INT 21h AH=42 calls)
 *   11DF      overlap-aware far copy (rep movsb, direction from SI/DI)
 *   1202      rep stosb fill
 *   1216      argv/environment buffer fill (INT 21h AH=30 + PSP env walk)
 *   1265/126C PSP command-line tokenizer
 *   129E      "X:\cwd" length-prefixed builder (INT 21h AH=19 + AH=47)
 *   1384      lowercase -> uppercase (a-z)
 *
 * DOS service map (all INT 21h sites in this range):
 *   1085/108C -> 1091   AH=3F/40  msdos_read_file / msdos_write_file
 *   1091:10E5           AH=3F/40  msdos_read_file / msdos_write_file
 *   10BB:10CC           AH=3F     msdos_read_file (read entry 1EDA:10BB)
 *   1123:1142           AH=42 AL=00 msdos_set_file_position (SEEK_SET)
 *   119A:11B2/11C1/11D0 AH=42 AL=01/02/00 msdos_set_file_position x3
 *   1216:1227           AH=30     msdos_get_dos_version
 *   129E:12B5           AH=19     msdos_get_current_default_drive
 *   129E:12C8           AH=47     msdos_get_current_directory
 * (The write entry 1EDA:10C2 has no frozen prototype; see notes.)
 *
 * Shared staging (src/seg1EDA_shared.h):
 *   g_1EDA_io_buffer -- data-buffer far pointer dropped by the frozen
 *       prototypes of 1091/10BB (Reko folded it into its dropped `ds`).
 *   g_1EDA_psp       -- PSP base used by 126C/1216 (DGROUP:0x537C selector
 *       is unresolvable in the flat model).
 */

#include <stdint.h>
#include <string.h>

#include "radtypes.h"
#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "seg1EDA.h"
#include "seg1EDA_shared.h"
#include "pal.h"

/* Definitions of the cross-part slots declared in seg1EDA_shared.h.  The
 * defaults reproduce the only buffer/PSP the recovered port can prove:
 *   - 0x5CB4 is the DGROUP record buffer of the startup load path
 *     (renamed_0800_01fe -> renamed_1eda_1085/1091);
 *   - g_dgroup stands in for the unreachable PSP segment. */
u8 *g_1EDA_io_buffer = (u8 *)&g_dgroup[0x5CB4];
u8 *g_1EDA_psp = g_dgroup;

/* 1EDA:1076 -- guard: compare the stream block's id word with 0xD7B3.  The
 * original leaves the flags from `cmp word ptr es:[di+2h],0D7B3h` at the ret,
 * so the raw ZF (1 when equal) is returned; every caller branches with `jnz`.
 * On mismatch the DOS error word DGROUP:0x5380 is set to 0x67. */
u32 fn1EDA_1076(u8 * es_di)
{
	if (*(u16 *)(es_di + 0x02) != 0xD7B3)
	{
		LG16(0x5380) = 0x0067;
		return 0x00000000u;         /* ZF clear */
	}
	return 0x00000001u;             /* ZF set: id == 0xD7B3 */
}

/* 1EDA:1085 -- mov ah,3Fh ; mov dx,64h ; jmp 1091h (read record). */
u16 renamed_1eda_1085(u8 al, u8 * ptrArg08)
{
	return renamed_1eda_1091((u16)(0x3F00u | (u16)al), 0x0064u, ptrArg08);
}

/* 1EDA:108C -- mov ah,40h ; mov dx,65h (falls through into 1091h; the result
 * survives 1091's retf 4h but the frozen prototype is void). */
void renamed_1eda_108c(u8 al, u8 * ptrArg08)
{
	(void)renamed_1eda_1091((u16)(0x4000u | (u16)al), 0x0065u, ptrArg08);
}

/* 1EDA:1091 -- read/write one record.  AX = the INT 21h function (AH=3F/40),
 * DX = the 0x64/0x65 error sentinel, ptrArg08 = the stream block (handle at
 * +0, record size at +4).  The original also loaded the data-buffer far
 * pointer from [bp+6h]; the frozen prototype dropped it, so the flat port
 * reads g_1EDA_io_buffer (see notes).  The record count is block[+4]. */
u16 renamed_1eda_1091(u16 ax, u16 dx, u8 * ptrArg08)
{
	u8 ah = (u8)(ax >> 8);
	u16 handle;
	u16 count;
	u16 r;

	if (fn1EDA_1076(ptrArg08) == 0x00000000u)
		return ax;                  /* 10B7: id not open, AX unchanged */

	handle = *(u16 *)(ptrArg08 + 0x00);
	count = *(u16 *)(ptrArg08 + 0x04);
	if (ah == 0x3F)
		r = msdos_read_file(handle, g_1EDA_io_buffer, count);
	else
		r = msdos_write_file(handle, g_1EDA_io_buffer, count);

	if (r == 0xFFFFu)               /* jc 10B4h: DOS error */
	{
		LG16(0x5380) = r;
		return r;
	}
	if (r == count)                 /* jz 10B7h */
		return r;
	LG16(0x5380) = dx;              /* 10B2: short transfer */
	return dx;
}

/* 1EDA:10BB -- read wArg08 records of block[+4] bytes each (INT 21h AH=3F),
 * store the number of whole records read at *ptrArg04 and return it.  The
 * entry at 1EDA:10C2 is the same body with AH=40 (write); index.tsv freezes
 * only the read entry, so the flat port always reads (the header cannot carry
 * BL).  The data buffer is the dropped [bp+0Ch] argument (g_1EDA_io_buffer).
 * wArg08 == 0 short-circuits straight to the result store. */
u16 renamed_1eda_10bb(u8 * ptrArg04, u16 wArg08, u8 * ptrArg0C, u8 * ptrArg0E)
{
	u16 ax = 0x0000;

	if (fn1EDA_1076(ptrArg0E) == 0x00000000u)   /* jnz 1111h */
		goto l1EDA_1111;

	ax = wArg08;                                /* mov ax,[bp+0Ah] */
	if (ax == 0x0000)                           /* or ax,ax ; jz 10F5h */
		goto l1EDA_10F5;

	/* l1EDA_10D9 */
	{
		u16 handle = *(u16 *)(ptrArg0E + 0x00);
		u16 recsize = *(u16 *)(ptrArg0E + 0x04);
		u16 bytecount = (u16)(ax * recsize);    /* mul es:[di+4h] */
		/* lds dx,[bp+0Ch]: the read destination is the caller-supplied far
		 * pointer (ptrArg0C), NOT a fixed DGROUP buffer. */
		u16 r = msdos_read_file(handle, ptrArg0C, bytecount);

		if (r == 0xFFFFu)                       /* jc 110Eh */
		{
			LG16(0x5380) = r;
			ax = r;
			goto l1EDA_1111;
		}

		/* l1EDA_10EF: xor dx,dx ; div es:[di+4h] */
		if (recsize == 0x0000)
		{
			/* The original would fault (#DE); keep the port total. */
			LG16(0x5380) = 0x0000;
			ax = 0x0000;
			goto l1EDA_1111;
		}
		ax = (u16)(r / recsize);
	}

l1EDA_10F5:
	if (ptrArg04 != NULL)                       /* les di,[bp+6h] ; or dx,di */
	{
		*(u16 *)ptrArg04 = ax;                  /* mov es:[di],ax */
		return ax;                              /* jmp 111Fh */
	}
	if (ax == wArg08)                           /* cmp ax,[bp+0Ah] ; jz 111Fh */
		return ax;
	LG16(0x5380) = 0x0064u;                     /* mov [5380h],cx (CX=64h) */
	return ax;

l1EDA_1111:
	if (ptrArg04 != NULL)                       /* les di,[bp+6h] ; or dx,di */
	{
		*(u16 *)ptrArg04 = 0x0000;              /* xor ax,ax ; mov es:[di],ax */
		ax = 0x0000;                            /* xor ax,ax (AX cleared) */
	}
	return ax;
}

/* 1EDA:1123 -- position the stream at record offset wArg06:wArg04 (record
 * index = wArg04 + (wArg06 << 16)), i.e. offset = index * block[+4].  INT 21h
 * AH=42 AL=00.  Returns AX (the new position low word; on error the DOS word)
 * and latches a failure into DGROUP:0x5380. */
u8 renamed_1eda_1123(u16 wArg04, u16 wArg06, u8 * ptrArg08)
{
	u16 ax = 0x0000;

	if (fn1EDA_1076(ptrArg08) != 0x00000000u)   /* jnz 114Fh */
	{
		u16 handle = *(u16 *)(ptrArg08 + 0x00);
		u16 recsize = *(u16 *)(ptrArg08 + 0x04);
		u32 m1 = (u32)wArg06 * (u32)recsize;
		u32 m2 = (u32)wArg04 * (u32)recsize;
		/* CX (high) = low(wArg06*recsize) + high(wArg04*recsize),
		 * DX (low)  = low(wArg04*recsize) */
		u32 off = ((u32)((u16)m1 + (u16)(m2 >> 16)) << 16) | (u16)m2;
		s32 r = msdos_set_file_position(handle, (s32)off, 0x00);

		ax = (u16)r;
		if (r < 0)                              /* jc 114Ch */
			LG16(0x5380) = ax;
	}
	return (u8)ax;
}

/* 1EDA:116A -- file-length in records: 119A yields DX:AX = current position
 * and BX:CX = file size; the quotient size / block[+4] is returned (record
 * size 1 skips the division).  dsOut is the dropped DGROUP selector. */
u16 renamed_1eda_116a(u8 * ptrArg04, u16 * dsOut)
{
	u32 bx_cx;
	s32 dx_ax;
	u8 *es_di;
	u16 ax;

	if (renamed_1eda_119a(ptrArg04, &bx_cx, &dx_ax, (u8 *)&es_di) != 0x00)  /* jc 1182h */
	{
		*dsOut = 0x0000;
		return 0x0000;              /* AX left by 119A's error path */
	}

	ax = (u16)bx_cx;                /* mov ax,cx (file size low) */
	{
		u16 rec = *(u16 *)(es_di + 0x04);
		if (rec != 0x0001)          /* cmp cx,1h ; jz 1182h */
		{
			s16 cx_72;
			s16 dx_73;
			s16 bx_74;
			void *ds_098A = NULL;
			/* BX=0, CX=recsize -> bx_cx = recsize; DX:AX = file size. */
			ax = (u16)renamed_1eda_098a((u32)rec, bx_cx, 0x0000, 0x0000,
			                      &cx_72, &dx_73, &bx_74, &ds_098A);
		}
	}
	*dsOut = 0x0000;                /* DGROUP selector dropped in flat model */
	return ax;
}

/* 1EDA:1185 -- 1 if position >= file size else 0: 119A yields DX:AX =
 * position and BX:CX = size; `sub ax,cx ; sbb dx,bx ; jc`. */
u16 renamed_1eda_1185(u8 * ptrArg04)
{
	u32 bx_cx;
	s32 dx_ax;
	u8 *es_di;
	u16 ax;
	u16 dx;
	u16 cx;
	u16 bx;

	if (renamed_1eda_119a(ptrArg04, &bx_cx, &dx_ax, (u8 *)&es_di) != 0x00)  /* jc 1195h */
		return 0x0000;

	ax = (u16)dx_ax;                /* AX = position low  */
	dx = (u16)(dx_ax >> 16);        /* DX = position high */
	cx = (u16)bx_cx;                /* CX = size low      */
	bx = (u16)(bx_cx >> 16);        /* BX = size high     */
	{
		u32 a = ((u32)dx << 16) | (u32)ax;
		u32 b = ((u32)bx << 16) | (u32)cx;
		if (a < b)                  /* borrow from sub/sbb */
			return 0x0000;
	}
	return 0x0001;
}

/* 1EDA:119A -- measure the stream size and restore the position: seek current
 * (+0), seek end (+0) and seek back to the original position, all
 * INT 21h AH=42.  Out: BX:CX = file size, DX:AX = current position, ES:DI =
 * the block; returns the carry of the last seek (1 = error).  DS:DI/CX/BX
 * values cross the frozen pointer signatures as 16-bit casts. */
u8 renamed_1eda_119a(u8 * ptrArg06, u32 * bx_cxOut, s32 * dx_axOut, u8 * es_diOut)
{
	u16 handle;

	if (*(u16 *)(ptrArg06 + 0x02) != 0xD7B3)     /* jnz 11D3h */
	{
		LG16(0x5380) = 0x0067;
		*bx_cxOut = 0x00000000u;
		*dx_axOut = 0;
		*(u8 **)es_diOut = ptrArg06;            /* ES:DI unchanged */
		return 0x01;                            /* stc */
	}

	handle = *(u16 *)(ptrArg06 + 0x00);
	{
		s32 pos = msdos_set_file_position(handle, 0, 0x01);   /* AL=01 */
		s32 size = msdos_set_file_position(handle, 0, 0x02);  /* AL=02 */
		s32 back = msdos_set_file_position(handle, (s32)pos, 0x00); /* AL=00 */

		*bx_cxOut = (u32)size;      /* BX:CX = size (BX high, CX low) */
		*dx_axOut = back;           /* DX:AX = position (DX high, AX low) */
		*(u8 **)es_diOut = ptrArg06;/* ES:DI = block */
		return (u8)(back < 0);      /* carry of the last seek */
	}
}

/* 1EDA:11DF -- copy wArg04 bytes from ptrArg0A to ptrArg06.  The original
 * compares the 16-bit SI/DI offsets and uses a backward `rep movsb` when
 * source < destination, otherwise a forward one. */
void renamed_1eda_11df(u16 wArg04, u8 * ptrArg06, u8 * ptrArg0A)
{
	u16 si_off = (u16)(uintptr_t)ptrArg0A;
	u16 di_off = (u16)(uintptr_t)ptrArg06;

	if (si_off < di_off)            /* cmp si,di ; jnc 11FBh */
	{
		u16 n = wArg04;
		while (n != 0x0000)         /* add si,cx ; add di,cx ; dec ; std */
		{
			--n;
			ptrArg06[n] = ptrArg0A[n];
		}
	}
	else
	{
		u16 n;
		for (n = 0; n != wArg04; ++n)   /* rep movsb (forward) */
			ptrArg06[n] = ptrArg0A[n];
	}
}

/* 1EDA:1202 -- xor al,al-independent `rep stosb`: fill wArg06 bytes at
 * ptrArg08 with bArg04 (the original stores AL = [bp+4h]). */
void renamed_1eda_1202(u8 bArg04, u16 wArg06, u8 * ptrArg08)
{
	memset(ptrArg08, (int)bArg04, (u32)wArg06);
}

/* 1EDA:1216 -- fill the caller's buffer with a length-prefixed string:
 *   wArg04 != 0 -> the wArg04-th PSP command-line token (via 126C);
 *   wArg04 == 0 -> the program path from the DOS environment (PSP:002C),
 *                  falling back to es_si when DOS < 3.
 * The buffer is ptrArg06: [0] = length, [1..] = bytes. */
void renamed_1eda_1216(void * es_si, u16 wArg04, u8 * ptrArg06)
{
	u8 *src;
	u16 ax;

	if (wArg04 != 0x0000)           /* or dx,dx ; jz 1225h */
	{
		u16 bx;
		src = fn1EDA_126C(wArg04, &ax, &bx);
	}
	else
	{
		ax = 0x0000;                /* mov ax,0h */
		src = (u8 *)es_si;
		if (msdos_get_dos_version() >= 0x03)    /* cmp al,3h ; jc 1255h */
		{
			/* The flat model has no environment segment; an all-zero
			 * stand-in yields the empty program path (see notes). */
			static u8 env[0x200];
			u16 di = 0x0000;
			u16 si;
			u16 cx;
			u8 al = 0x00;

			/* l1EDA_1230..123Ch: walk to the environment double-NUL. */
			for (;;)
			{
				if (al == env[di])  /* cmp al,es:[di] ; jz 1248h */
					break;
				cx = 0xFFFF;        /* repne scasb */
				while (cx != 0x0000)
				{
					u8 v = env[di];
					++di;
					--cx;
					if (v == al)
						break;
				}
			}

			/* l1EDA_1248: skip the 3-byte trailer, scan the program
			 * path for its NUL (max 0x100 bytes). */
			di = (u16)(di + 0x0003);    /* add di,3h */
			si = di;                    /* mov si,di */
			cx = 0x0100;                /* mov cx,100h */
			while (cx != 0x0000)        /* repne scasb */
			{
				u8 v = env[di];
				++di;
				--cx;
				if (v == al)
					break;
			}
			/* l1EDA_1252: xchg cx,ax ; not al */
			ax = cx;
			ax = (u16)((ax & 0xFF00u) | (u16)(u8)~(u8)cx);
			src = env + si;
		}
	}

	/* l1EDA_1255: stosb ; xchg cx,ax ; rep movsb */
	ptrArg06[0] = (u8)ax;
	memcpy(&ptrArg06[1], src, (u32)(u16)ax);
}

/* 1EDA:1265 -- count the PSP command-line tokens (dx = 0 -> all): returns the
 * last token pointer and *axOut = token count (the original's `xchg bx,ax`). */
void * fn1EDA_1265(u16 * axOut)
{
	u16 bx;
	u16 ax;
	u8 *src = fn1EDA_126C(0x0000, &ax, &bx);

	*axOut = bx;
	return (void *)src;
}

/* 1EDA:126C -- tokenize the PSP command line at PSP:0080h (length) / 0081h.
 * Scans up to DX tokens, stopping early on a zero-length token.  Out: *axOut =
 * last token length, *bxOut = token count; returns the last token start
 * (ES:SI).  The PSP base comes from g_1EDA_psp (see notes). */
u8 * fn1EDA_126C(u16 dx, u16 * axOut, u16 * bxOut)
{
	u8 *es = g_1EDA_psp;
	u16 di = 0x0080;
	u16 cx;
	u16 si = 0x0000;
	u16 bx = 0x0000;
	u16 ax = 0x0000;

	cx = (u16)es[di];               /* mov cl,es:[di] ; xor ch,ch */
	++di;                           /* inc di -> 0081h */

	for (;;)
	{
		/* l1EDA_127B: skip whitespace. */
		if (cx != 0x0000)           /* jcxz 1286h */
		{
			while (es[di] <= 0x20)  /* cmp es:[di],20h ; ja 1286h */
			{
				++di;               /* inc di */
				--cx;               /* loop 127Dh */
				if (cx == 0x0000)
					break;
			}
		}

		/* l1EDA_1286: take the token. */
		si = di;                    /* mov si,di */
		if (cx != 0x0000)           /* jcxz 1293h */
		{
			while (es[di] > 0x20)   /* cmp es:[di],20h ; jbe 1293h */
			{
				++di;               /* inc di */
				--cx;               /* loop 128Ah */
				if (cx == 0x0000)
					break;
			}
		}

		/* l1EDA_1293: mov ax,di ; sub ax,si ; jz 129Dh */
		ax = (u16)(di - si);
		if (ax == 0x0000)
			break;

		/* l1EDA_1299: inc bx ; dec dx ; jnz 127Bh */
		++bx;
		--dx;
		if (dx == 0x0000)
			break;
	}

	/* l1EDA_129D */
	*axOut = ax;
	*bxOut = bx;
	return es + si;
}

/* 1EDA:129E -- build the length-prefixed path "X:\cwd" into ptrArg06 (max
 * wArg04 characters).  bArg0A == 0 selects the current default drive,
 * otherwise it is the DOS drive number; DL = drive.  The carry path of the
 * AH=47 call writes a NUL at buffer[3]; the pal call reports no failure. */
u8 renamed_1eda_129e(u8 dh, u16 wArg04, u8 * ptrArg06, u8 bArg0A)
{
	u8 buffer[0x80];                /* [bp-80h] */
	u8 al;
	u16 cx;
	u16 bx;
	u16 i;

	(void)dh;

	al = bArg0A;
	if (bArg0A == 0x00)
		al = (u8)(msdos_get_current_default_drive() + 0x01);  /* inc al */

	/* mov [si],al ; inc si ; mov word ptr [si],5C3Ah ; inc si ; inc si */
	buffer[0] = (u8)(al + 0x40);    /* drive letter */
	buffer[1] = 0x3A;               /* ':' */
	buffer[2] = 0x5C;               /* '\' */

	/* mov ah,47h ; int 21h (DS:DX = SS:SI = buffer+3, DL = drive) */
	msdos_get_current_directory((char *)&buffer[3]);

	/* l1EDA_12CE: mov es:[di],bl after the copy. */
	cx = wArg04;
	bx = 0x0000;
	i = 0x0000;
	for (;;)                        /* l1EDA_12DA: lodsb/or/jz/inc bx/stosb/loop */
	{
		al = buffer[i];
		++i;
		if (al == 0x00)
			break;
		++bx;
		ptrArg06[bx] = al;
		--cx;
		if (cx == 0x0000)
			break;
	}
	ptrArg06[0] = (u8)bx;           /* mov es:[di],bl */
	return 0x47;                    /* AH survives */
}

/* 1EDA:1384 -- fold a-z to A-Z (unsigned compares). */
u8 renamed_1eda_1384(u8 bArg04)
{
	u8 al = bArg04;

	if (bArg04 >= 0x61 && bArg04 <= 0x7A)   /* cmp al,61h ; jc ; cmp al,7Ah ; ja */
		al = (u8)(bArg04 - 0x20);
	return al;
}
