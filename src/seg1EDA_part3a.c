/* seg1EDA_part3a.c -- RAD V3.1 preservation port, segment 1EDA, chunk 3a.
 *
 * Functions 1EDA:04F5 .. 1EDA:05FB (6 functions, ascending offset):
 *   04F5 0565 056A 0572 05BF 05FB
 * Literal recovery from analysis/slices/1EDA/1EDA_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg1EDA.h.
 * See CONVENTIONS.md and docs/notes-1EDA.md ("## chunk 3a").
 *
 * These are the Turbo-C buffered-stream open/close layer built on the block
 * laid out by 04F5 (also see chunk 4's read/write drivers):
 *   +0x00 zero            +0x02 id (0xD7B0 closed / 0xD7B1 / 0xD7B2)
 *   +0x04 limit           +0x06 zero
 *   +0x08 cursor          +0x0A limit
 *   +0x0C..0x0E buffer far pointer (offset = block+0x80)
 *   +0x10..0x12 callback  +0x14..+0x2F zeroed callback slots
 *   +0x30 string image
 *   04F5 builds the block; 0565/056A/0572 select its id and reopen it;
 *   05BF closes it; 05FB dispatches the callback stored at block+BX.
 *
 * DOS services: none of these six functions issues an int 10h / int 16h /
 * int 21h or port-I/O site directly.  The original stream callbacks
 * (1EDA:060C/068E/06E8/0718/075D) -- where the int 21h file services live --
 * are NOT recovered functions: Reko left them undecoded inside fn1EDA_05FB's
 * symbol range and they do not appear in analysis/slices/1EDA/index.tsv, so
 * no frozen prototype exists for them and they cannot be invoked from flat C
 * (see docs/notes-1EDA.md "## chunk 3a").
 *
 * Shared staging: none.  All state lives in DGROUP (g_dgroup / the LG16
 * macro) or in the caller-supplied stream block; no file-scope variable is
 * shared with a function outside this range, so src/seg1EDA_shared.h is
 * unchanged.
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

/* 1EDA:04F5 -- initialise a stream block: id 0xD7B0, 0x80-byte buffer,
 * callback slots at +0x10/+0x14/+0x18/+0x1C zeroed (the +0x10 open callback
 * literal offset is stored, segment dropped) and the NUL-terminated source
 * string copied to +0x30 (at most 0x4F bytes, lodsb/rep movsb/stosb). */
void fn1EDA_04F5(u8 * ptrArg04, u8 * ptrArg08)
{
	u16 di_14 = (u16)(uintptr_t)ptrArg08;   /* (word16) ptrArg08 */
	u8 *di_42;
	u16 cx_47;
	u8 al_52;
	u16 cx_60;

	/* stosw sequence.  The far pointer to the 0x80-byte buffer at +0x0C
	 * keeps its literal offset ((word16)base + 0x80) but its DS selector is
	 * dropped in the flat model (same convention as fn1E78_032F).  The
	 * +0x10 callback offset is the literal 0x060C; its CS selector is
	 * likewise dropped. */
	*(u16 *)(ptrArg08 + 0x00) = 0x0000;     /* t0000 */
	*(u16 *)(ptrArg08 + 0x02) = 0xD7B0;     /* t0002 = (uint16) ~0x284F */
	*(u16 *)(ptrArg08 + 0x04) = 0x0080;     /* t0004 */
	*(u16 *)(ptrArg08 + 0x06) = 0x0000;     /* t0006 */
	*(u16 *)(ptrArg08 + 0x08) = 0x0000;     /* ptr0008 */
	*(u16 *)(ptrArg08 + 0x0A) = 0x0000;     /* t000A */
	*(u16 *)(ptrArg08 + 0x0C) = (u16)(di_14 + 0x0080);  /* buffer offset */
	*(u16 *)(ptrArg08 + 0x0E) = 0x0000;     /* buffer segment: DS dropped */
	*(u16 *)(ptrArg08 + 0x10) = 0x060C;     /* open-callback offset */
	*(u16 *)(ptrArg08 + 0x12) = 0x0000;     /* callback segment: CS dropped */

	/* xor ax,ax ; mov cx,0Eh ; rep stosw : zero +0x14..+0x2F. */
	di_42 = ptrArg08 + 0x14;
	for (cx_47 = 0x0E; cx_47 != 0x00; --cx_47)
	{
		*(u16 *)di_42 = 0x0000;
		di_42 = di_42 + 2;
	}

	/* lodsb ; cmp al,4Fh ; jbe ; mov al,4Fh ; mov cl,al ; xor ch,ch ;
	 * rep movsb ; xor al,al ; stosb. */
	al_52 = ptrArg04[0];
	if (al_52 > 0x4F)
		al_52 = 0x4F;
	cx_60 = (u16)al_52;
	memcpy(di_42, ptrArg04 + 1, (u32)cx_60);
	di_42[cx_60] = 0x00;
}

/* 1EDA:0565 -- mov dx,0D7B1h ; jmp 0572h (tail call).  DX survives 0572's
 * retf 4h, so Reko models it as the u16 result; the flat model returns the
 * literal constant. */
u16 fn1EDA_0565(u8 * ptrArg04)
{
	fn1EDA_0572(0xD7B1, ptrArg04);
	return 0xD7B1;
}

/* 1EDA:056A -- mov dx,0D7B2h ; jmp 0572h (tail call). */
void fn1EDA_056A(u8 * ptrArg04)
{
	fn1EDA_0572(0xD7B2, ptrArg04);
}

/* 1EDA:0572 -- reopen a stream block selected by its id:
 *   id 0xD7B1/0xD7B2 -> 0593 calls 05BF (which discards the old buffer),
 *                       then falls through to 059B;
 *   id 0xD7B0        -> straight to 059B;
 *   anything else    -> DGROUP:0x5380 = 0x66 and return.
 * 059B installs the new id DX, clears the cursor/limit, then dispatches the
 * +0x10 open callback through 05FB; if it fails the id is forced back to
 * 0xD7B0 (closed). */
void fn1EDA_0572(u16 dx, u8 * ptrArg04)
{
	u16 ax_12;

	ax_12 = *(u16 *)(ptrArg04 + 0x02);      /* mov ax,es:[di+2h] */
	if (ax_12 == 0xD7B1 || ax_12 == 0xD7B2)
	{
		/* 0593: push dx ; push es ; push di ; push cs ; call 05BFh.
		 * 05BF's retf 4h pops the block argument and `pop dx` restores
		 * DX, so DX is not an argument to 05BF. */
		(void)fn1EDA_05BF(ptrArg04);
	}
	else if (ax_12 != 0xD7B0)
	{
		/* 058B: mov word ptr [5380h],66h ; jmp 05B7h. */
		LG16(0x5380) = 0x0066;
		return;
	}

	/* 059B: xor ax,ax ; mov es:[di+2h],dx ; mov es:[di+8h],ax ;
	 *       mov es:[di+0Ah],ax ; mov bx,10h ; call 05FBh ; jz 05B7h ;
	 *       mov word ptr es:[di+2h],0D7B0h. */
	*(u16 *)(ptrArg04 + 0x02) = dx;
	*(u16 *)(ptrArg04 + 0x08) = 0x0000;
	*(u16 *)(ptrArg04 + 0x0A) = 0x0000;
	if (fn1EDA_05FB(ptrArg04, 0x10) == 0x00)
		*(u16 *)(ptrArg04 + 0x02) = 0xD7B0;
}

/* 1EDA:05BF -- close a stream block:
 *   id 0xD7B1        -> dispatch the +0x1C close callback (05FB);
 *   id 0xD7B2        -> dispatch the +0x14 callback, then the +0x1C one;
 *   anything else    -> DGROUP:0x5380 = 0x67 and return.
 * On the two close paths the id is forced to 0xD7B0.  ABI: 05FB is called
 * with BX = slot offset (0x14/0x1C) and ES:DI = block; the flat ABI passes
 * (block, offset).  Return is the last 05FB AL (AH is not modelled; the
 * frozen prototype has no u16 register output). */
u16 fn1EDA_05BF(u8 * ptrArg04)
{
	u8 al_ret = 0x01;                       /* mov al,1h */
	u16 ax_ret = 0x0001;
	u16 ax_12;

	ax_12 = *(u16 *)(ptrArg04 + 0x02);
	if (ax_12 != 0xD7B1)
	{
		if (ax_12 != 0xD7B2)
		{
			/* 05D7: mov word ptr [5380h],67h ; jmp 05F7h. */
			LG16(0x5380) = 0x0067;
			return ax_ret;
		}
		/* 05DF: push ax ; mov bx,14h ; call 05FBh ; pop ax (restores
		 * AL = 1 before the `or al,al` test). */
		ax_ret = (u16)fn1EDA_05FB(ptrArg04, 0x14);
		al_ret = 0x01;
	}
	/* 05E7: or al,al ; jz 05F7h. */
	if (al_ret != 0x00)
	{
		/* 05EB: mov bx,1Ch ; call 05FBh ; mov es:[di+2h],0D7B0h. */
		ax_ret = (u16)fn1EDA_05FB(ptrArg04, 0x1C);
		*(u16 *)(ptrArg04 + 0x02) = 0xD7B0;
	}
	return ax_ret;
}

/* 1EDA:05FB -- dispatch the callback stored at block + di:
 *   push es ; push di ; push es ; push di ; call dword ptr es:[bx+di].
 * The first ES:DI pair saves 05FB's registers; the second is the single far
 * block pointer passed to the callback, whose own `retf 4h` pops it.  At
 * entry the original has BX = callback-slot offset (0x10/0x14/0x1C) and
 * ES:DI = block, so the effective address is block + offset; the flat ABI
 * carries the block in `es_bx` and that offset in `di`.
 *
 * The slot is treated as a host function pointer (the same convention the
 * chunk-4 fn1EDA_0879 uses for the +0x18 slot): the original 16:16 targets
 * (1EDA:060C/06E8/0718/075D) are not recovered functions, so the literal
 * segment words are dropped at their producers.  AX is the callback result:
 * a nonzero value is latched into DGROUP:0x5380 and the function returns 1
 * when the callback returned 0 (the ZF the callers test with `jz`). */
u8 fn1EDA_05FB(u8 * es_bx, u16 di)
{
	u16 ax_18;

	/* The slot holds a 16-bit callback OFFSET within segment 1EDA
	 * (0x060C/0x06E8/0x0718/0x073D/0x075D) -- resolve it to the recovered
	 * host function (chunk 3c) instead of dereferencing the raw value. */
	{
		u16 (*cb)(u8 *) = seg1EDA_stream_cb(*(u16 *)(es_bx + di));
		ax_18 = cb ? cb(es_bx) : 0xFFFF;    /* unresolved slot: error */
	}
	if (ax_18 != 0x00)
		LG16(0x5380) = ax_18;
	return (u8)(ax_18 == 0x00);
}
