/* seg1EDA_part3bii.c -- stream write/flush chain, 1EDA:07DA / 07E9 / 0801.
 *
 * Ground truth: analysis/slices/1EDA/1EDA_07DA.asm, 1EDA_07E9.asm,
 * 1EDA_0801.asm.  In the original these are ONE contiguous machine-code
 * flow: 07DA stores a byte at es:[bx+di] (ES:DI = stream buffer base from
 * the block, BX = position), increments BX and, when BX reaches the limit
 * DX, falls through into 07E9 (recovering the block far pointer from the
 * stack argument): block+8 is updated with BX and the callback at block
 * +0x14 is invoked with the block as its single far argument (retf 4).
 * The shared epilogue at 0801 reloads AX/BX/DX/ES:DI from the block and
 * unwinds; on callback error (AX != 0) the error word DGROUP:0x5380 first
 * receives AX (that is the only difference between the two entry points).
 *
 * Flat-port mapping (established by the converted callers, seg1EDA_part4.c):
 *   - es_bx carries the 16-bit BX position as a pointer value; the buffer
 *     base offset arrives as `di` (from 07B6/0776: les di,[block+0Ch]), so
 *     the written byte is g_dgroup[bx + di] for DGROUP buffers (all
 *     shipped streams; g_dgroup is 64 KiB-aligned so (u16)(uintptr_t)
 *     truncation yields the original offset).
 *   - block dword +0x0C is the buffer far pointer (off | seg<<16).
 *   - callback slots hold 16-bit offsets resolved by seg1EDA_stream_cb().
 */
#include "radtypes.h"
#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "seg1EDA.h"
#include "seg1EDA_shared.h"
#include "seg1E78.h"
#include <stdint.h>

/* Resolve a callback-slot offset (0x060C/0x06E8/0x0718/0x073D/0x075D, plus
 * the 1E78 console-stream slots 0x035A/0x0392/0x043F/0x0470) to the recovered
 * host function (chunk 3c + 1E78).  Shared with parts 3a/4 (extern). */
u16 (*seg1EDA_stream_cb(u16 off))(u8 *)
{
	switch (off) {
	case 0x060C: return renamed_1eda_060c;
	case 0x06E8: return renamed_1eda_06e8;
	case 0x0718: return renamed_1eda_0718;
	case 0x073D: return renamed_1eda_073d;
	case 0x075D: return renamed_1eda_075d;
	case 0x035A: return renamed_1e78_035a;   /* 1E78 console: open/arm  */
	case 0x0392: return renamed_1e78_0392;   /* 1E78 console: read line */
	case 0x043F: return renamed_1e78_043f;   /* 1E78 console: write     */
	case 0x0470: return renamed_1e78_0470;   /* 1E78 console: dummy     */
	default:     return 0;
	}
}

/* 1EDA:0801 -- the error/epilogue label as a helper: store AX into the
 * error word, then reload the register image from the block exactly as the
 * `pop di / pop es / mov ax,es:[di+0Ah] ...` sequence does. */
u16 renamed_1eda_0801(u16 ax, u32 dwArg00, u16 * cxOut, u16 * dxOut, void * bxOut,
                u16 * siOut, u16 * diOut, void * esOut, void * dsOut)
{
	u8 *block = g_dgroup + (u16)(uintptr_t)dwArg00; /* 16:16, seg 0x2014 */
	LG16(0x5380) = ax;                      /* mov [5380h],ax */
	*cxOut = 0;                             /* popped CX: unchanged by flow */
	*dxOut = *(u16 *)(block + 0x04);        /* mov dx,es:[di+4h] */
	*(u16 *)bxOut = *(u16 *)(block + 0x08); /* mov bx,es:[di+8h] */
	*siOut = 0;                             /* popped SI: unchanged by flow */
	*diOut = *(u16 *)(block + 0x0C);        /* les di,es:[di+0Ch]: DI=off */
	*(u16 *)esOut = *(u16 *)(block + 0x0E); /*                  ES=seg */
	*(u16 *)dsOut = 0;                      /* popped DS: unchanged by flow */
	return *(u16 *)(block + 0x0A);          /* mov ax,es:[di+0Ah] */
}

/* 1EDA:07E9 -- flush: block+8 = BX, invoke the +0x14 callback, then the
 * shared epilogue reload (0801 on error).  Direct entry from 079A. */
u8 * fn1EDA_07E9(u8 * es_di, u16 cx, u8 * bx, u16 * axOut, u16 * cxOut,
                 u16 * siOut, u16 * diOut, void * dsOut)
{
	u8 *block = es_di;
	u16 ax;
	*(u16 *)(block + 0x08) = (u16)(uintptr_t)bx;   /* mov es:[di+8h],bx */
	{
		u16 (*cb)(u8 *) = seg1EDA_stream_cb(*(u16 *)(block + 0x14));
		ax = cb(block);                     /* call dword ptr es:[di+14h] */
	}
	if (ax != 0x00) {
		u16 cx_r, dx_r, si_r, di_r;
		void *bx_r, *es_r, *ds_r;
		ax = renamed_1eda_0801(ax, (u32)((uintptr_t)block - (uintptr_t)g_dgroup),
		                 &cx_r, &dx_r, &bx_r, &si_r, &di_r, &es_r, &ds_r);
		*cxOut = cx;                        /* CX is preserved across 07E9 */
		*siOut = si_r;
		*diOut = di_r;
		(void)dsOut;
		(void)dx_r; (void)es_r;
		return bx_r;                        /* BX = block+8 (reloaded) */
	}
	/* success epilogue (0804): identical reload without the error store */
	*axOut = *(u16 *)(block + 0x0A);
	*cxOut = cx;
	*siOut = 0;                             /* SI unchanged by the flow */
	*diOut = *(u16 *)(block + 0x0C);
	*(u16 *)dsOut = 0;
	return (u8 *)(uintptr_t)*(u16 *)(block + 0x08);
}

/* 1EDA:07DA -- store one byte, advance BX, flush on reaching the limit.
 * The flush tail falls through into 07E9 with the block from the stack. */
u8 * fn1EDA_07DA(u8 * es_bx, u8 al, u16 cx, u16 dx, u16 di, u8 * ptrArg02,
                 u8 * es_bxOut, u8 * ahOut, u16 * cxOut, u16 * dxOut,
                 u16 * diOut)
{
	u16 bx = (u16)(uintptr_t)es_bx;         /* ES:BX position (flat=offset) */
	(void)di;   /* DI = [block+0Ch]; resolved through the block below */
	/* The buffer is block+0x80 in the flat model (04F5 stores
	 * [block+0x0C] = (u16)block + 0x80; block_buffer()/stream_buffer()
	 * resolve it the same way).  Addressing it through the block pointer
	 * (instead of g_dgroup[bx+di]) also serves non-DGROUP stream blocks --
	 * renamed_0800_2c0c builds its RAD.MEM block on the stack. */
	ptrArg02[0x80 + bx] = al;               /* mov es:[bx+di],al */
	bx++;                                   /* inc bx */
	if (bx == dx) {                         /* cmp bx,dx / jz 07E3 */
		/* 07E3: les di,ss:[di+2] -- recover the block argument, then
		 * 07E9's body with the block and the incremented BX. */
		u8 *block = ptrArg02;
		u16 ax;
		*(u16 *)(block + 0x08) = bx;        /* mov es:[di+8h],bx */
		{
			u16 (*cb)(u8 *) = seg1EDA_stream_cb(*(u16 *)(block + 0x14));
			ax = cb(block);                 /* call dword ptr es:[di+14h] */
		}
		if (ax != 0x00) {
			u16 cx_r, dx_r, si_r, di_r;
			void *bx_r, *es_r, *ds_r;
			(void)renamed_1eda_0801(ax,
			    (u32)((uintptr_t)block - (uintptr_t)g_dgroup),
			    &cx_r, &dx_r, &bx_r, &si_r, &di_r, &es_r, &ds_r);
		}
		/* shared epilogue reload (both paths) */
		*ahOut = (u8)(*(u16 *)(block + 0x0A) >> 8);
		*(u8 **)es_bxOut = (u8 *)(uintptr_t)*(u16 *)(block + 0x08);
		*cxOut = cx;                        /* CX unchanged */
		*dxOut = *(u16 *)(block + 0x04);
		*diOut = *(u16 *)(block + 0x0C);
		return (u8 *)(uintptr_t)*(u16 *)(block + 0x08);
	}
	/* l1EDA_07E2: early return, registers unchanged */
	*ahOut = 0;                             /* AH undefined in the original */
	*(u8 **)es_bxOut = (u8 *)(uintptr_t)bx;
	*cxOut = cx;
	*dxOut = dx;
	*diOut = di;
	return (u8 *)(uintptr_t)bx;
}
