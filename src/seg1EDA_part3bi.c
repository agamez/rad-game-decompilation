/* seg1EDA_part3bi.c -- RAD V3.1 preservation port, segment 1EDA, chunk 3b-i.
 *
 * Functions 1EDA:0776, 1EDA:079A, 1EDA:07B6 (three functions, ascending):
 *   0776 079A 07B6
 * Literal recovery from analysis/slices/1EDA/1EDA_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg1EDA.h.
 * See CONVENTIONS.md and docs/notes-1EDA.md ("## chunk 3b-i").
 *
 * These are the buffered-stream character primitives used by the chunk-4
 * line drivers (fn1EDA_081A / 0896 / 0918 read, fn1EDA_0848 / 08CE write).
 * The stream block is the Turbo-C descriptor built by fn1EDA_04F5 (chunk 3a):
 *   +0x00 handle   +0x02 id (0xD7B0 closed / 0xD7B1 read / 0xD7B2 write)
 *   +0x04 limit (write path)   +0x08 cursor   +0x0A limit (read path)
 *   +0x0C..+0x0E buffer far pointer (the offset word encodes low16(block)+0x80)
 * 0776/07B6 are the "prepare for getc/putc" preludes: they validate the stream
 * id against the error word DGROUP:0x5380, then load BX = block[+0x08],
 * DX = block[+0x0A] (0776) or block[+0x04] (07B6) and ES:DI = block[+0x0C].
 * 079A is the getc body: `cmp bx,dx` decides whether the buffer is exhausted;
 * if so it refills through fn1EDA_07E9 (out of range here, frozen prototype in
 * src/seg1EDA.h) and re-tests, otherwise it returns the byte at the cursor.
 *
 * Flat model (matches the chunk-4 call sites; see docs/notes-1EDA.md):
 * the far BX/DX/ES:DI register triple is collapsed onto the 16-bit values the
 * port carries in pointer-typed slots.  es_bxOut/bxOut receive the cursor word
 * as (u8 *)(uintptr_t)bx, dxOut/diOut carry 16-bit words, and esOut (the
 * buffer selector) is dropped (0) so the caller's `esOut + bx` reconstruction
 * yields the cursor.  The buffer byte is read from block+0x80 (the +0x0C
 * word's block-relative offset), the same recovery chunk 3c's block_buffer
 * uses for the far buffer pointer.
 *
 * DOS services: none.  No function here issues int 10h / int 16h / int 21h or
 * port I/O.
 *
 * Shared staging: none.  All state is DGROUP (the error word at 0x5380 via the
 * LG16 macro) or the caller-supplied stream block; src/seg1EDA_shared.h is
 * unchanged.
 */

#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1EDA.h"

/* Flat reconstruction of the `es:[bx+di]` buffer access: ES:DI is the stream
 * buffer far pointer.  fn1EDA_04F5 stores its block-relative offset
 * (low16(block)+0x80) in the +0x0C word with the segment half dropped, so the
 * flat host pointer is recovered from the block base exactly as the chunk-3c
 * cb helpers do. */
static u8 * stream_buffer(u8 * block)
{
	return block + (u16)(*(u16 *)(block + 0x0C) - (u16)(uintptr_t)block);
}

/* 1EDA:0776 -- getc prelude.  When the error word DGROUP:0x5380 is already
 * non-zero it is left alone and the prelude reports failure (zero).  Otherwise
 * the stream id (+0x02) is compared with 0xD7B1: a match reports success (the
 * ZF the caller's `jnz` tests), a mismatch latches error 0x68 into 0x5380 and
 * reports failure.  It then loads BX = +0x08, DX = +0x0A and ES:DI = +0x0C;
 * the flat outputs carry the cursor word in es_bxOut, the limit word in dxOut
 * and the buffer offset word in diOut.  ES (the +0x0E segment) is dropped. */
u8 fn1EDA_0776(u8 * es_di, u8 * es_bxOut, u16 * dxOut, u16 * diOut)
{
	u8 z;

	if (LG16(0x5380) == 0x0000)
	{
		u16 id = *(u16 *)(es_di + 0x02);

		z = (u8)(id == 0xD7B1);
		if (id != 0xD7B1)
			LG16(0x5380) = 0x0068;
	}
	else
	{
		z = 0x00;
	}

	*(u8 **)es_bxOut = (u8 *)(uintptr_t)*(u16 *)(es_di + 0x08);
	*dxOut = *(u16 *)(es_di + 0x0A);
	*diOut = *(u16 *)(es_di + 0x0C);
	return z;
}

/* 1EDA:07B6 -- putc prelude, the write-path twin of 0776: id 0xD7B2, error
 * code 0x69, and DX = block[+0x04] (the write buffer limit) instead of
 * block[+0x0A].  The outputs are otherwise the same. */
u8 fn1EDA_07B6(u8 * es_di, u8 * es_bxOut, u16 * dxOut, u16 * diOut)
{
	u8 z;

	if (LG16(0x5380) == 0x0000)
	{
		u16 id = *(u16 *)(es_di + 0x02);

		z = (u8)(id == 0xD7B2);
		if (id != 0xD7B2)
			LG16(0x5380) = 0x0069;
	}
	else
	{
		z = 0x00;
	}

	*(u8 **)es_bxOut = (u8 *)(uintptr_t)*(u16 *)(es_di + 0x08);
	*dxOut = *(u16 *)(es_di + 0x04);
	*diOut = *(u16 *)(es_di + 0x0C);
	return z;
}

/* 1EDA:079A -- getc body.  BX (the first argument) is the buffer cursor and DX
 * the read limit; ES:DI is the buffer far pointer.  If BX != DX it returns the
 * byte at the cursor (carry clear).  Otherwise the buffer is exhausted:
 * `mov di,sp ; les di,ss:[di+2h]` reloads ES:DI with the caller's pushed block
 * pointer (the stack argument ptrArg02) and calls fn1EDA_07E9 to refill.  The
 * refill returns the new cursor in the low word of its far-pointer result, the
 * new limit in its ax output, and DI in its di output; `mov dx,ax ; cmp bx,dx`
 * then re-tests.  When the refilled cursor still equals the limit the stream is
 * at EOF: return 0x1A with carry set.  Carry is not expressible in the frozen
 * prototype and is dropped; every caller tests AL instead.
 *
 * The return value is the unresolved register result of this function in Reko:
 * the DS:SI far pointer, i.e. the SI word fn1EDA_07E9 leaves (undefined when no
 * refill happened).  It is carried as a flat pointer and is discarded by all
 * callers; see docs/notes-1EDA.md ("## chunk 3b-i"). */
u8 * fn1EDA_079A(u8 * es_bx, u16 cx, u8 * dx, u16 di, u8 * ptrArg02,
                 u8 * alOut, u16 * cxOut, void * dxOut, void * bxOut,
                 u16 * diOut, void * esOut)
{
	u16 bx = (u16)(uintptr_t)es_bx;   /* BX at entry */
	u16 dx_v = (u16)(uintptr_t)dx;    /* DX at entry */
	u16 si_ret = 0x0000;              /* SI at ret (undefined without refill) */

	if (bx == dx_v)
	{
		/* 07A3: mov di,sp ; les di,ss:[di+2h] ; call 07E9h */
		u16 ax_15;
		u16 cx_15;
		u16 si_15;
		u16 di_15;
		void *ds_15 = (void *)0;
		u8 *es_bx_79;

		es_bx_79 = fn1EDA_07E9(ptrArg02, cx, (u8 *)(uintptr_t)bx,
		                       &ax_15, &cx_15, &si_15, &di_15, &ds_15);
		dx_v = ax_15;                     /* mov dx,ax */
		bx = (u16)(uintptr_t)es_bx_79;    /* low word of the far-ptr result */
		cx = cx_15;                       /* cx out of 07E9 */
		di = di_15;                       /* di out of 07E9 */
		si_ret = si_15;
		if (bx == dx_v)                   /* cmp bx,dx ; jnz 079Eh */
		{
			/* 07B2: mov al,1Ah ; stc */
			*alOut = 0x1A;
			*cxOut = cx;
			*(u16 *)dxOut = dx_v;
			*(u8 **)bxOut = (u8 *)(uintptr_t)bx;
			*diOut = di;
			*(u8 **)esOut = (u8 *)0;      /* ES selector dropped */
			return (u8 *)(uintptr_t)si_ret;
		}
	}

	/* 079E: mov al,es:[bx+di] ; clc */
	*alOut = stream_buffer(ptrArg02)[bx];
	*cxOut = cx;
	*(u16 *)dxOut = dx_v;
	*(u8 **)bxOut = (u8 *)(uintptr_t)bx;
	*diOut = di;
	*(u8 **)esOut = (u8 *)0;              /* ES selector dropped */
	return (u8 *)(uintptr_t)si_ret;
}
