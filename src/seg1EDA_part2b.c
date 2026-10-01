/* seg1EDA_part2b.c -- RAD V3.1 preservation port, segment 1EDA, chunk 2b.
 *
 * Functions 1EDA:03D3 .. 1EDA:04B7 (6 functions, ascending offset):
 *   03D3 0432 0491 04A2 04A9 04B7
 * Literal recovery from analysis/slices/1EDA/1EDA_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg1EDA.h.
 * See CONVENTIONS.md and docs/notes-1EDA.md ("## chunk 2b").
 *
 * DOS services: none of these functions issue an int 21h / int 10h / port
 * I/O site directly.  fn1EDA_04A9 and renamed_1eda_04b7 tail-jump to the
 * same-segment fatal-error dispatcher renamed_1eda_00e2, which performs the
 * msdos_set_interrupt_vector / msdos_terminate work (chunk 1).
 *
 * Free-list model: 03D3/0432 walk and relink the far-heap free list whose
 * head lives at DGROUP:0x5366.  The flat port does not reproduce the DOS
 * far heap (its base words are zero -- see docs/notes-1EDA.md chunk 1), so
 * the heap fetches/stores are modelled by the static far_heap_* helpers
 * below, exactly as chunk 1 did for renamed_1eda_00fc.  The DGROUP selector is
 * still resolved to the flat image so the head (DGROUP:0x5366) reads
 * correctly.
 */

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1EDA.h"
#include "seg1EDA_shared.h"
#include "pal.h"

/* DX half of renamed_1eda_0491's result; see src/seg1EDA_shared.h. */
u16 g_0491_dx;

/* ---------------------------------------------------------------- far heap
 * The original addresses nodes as segment:offset pairs.  The flat port keeps
 * the literal 16-bit segment/offset values but cannot map them onto a real
 * DOS heap; these accessors preserve the original read/modify shape. */

static u16 far_heap_word(u16 seg, u16 off)
{
	return *(u16 *)far_ptr(FAR_PTR(seg, off));
}

static void far_heap_setword(u16 seg, u16 off, u16 val)
{
	*(u16 *)far_ptr(FAR_PTR(seg, off)) = val;
}

/* 1EDA:0491 -- AX = (ax + 7) & 8; the 8086 sequence also leaves
 * DX = ((ax + 7) >> 4) | (carry-out-of-add << 12) in DX.  The frozen
 * prototype returns AX only, so the DX half is latched in g_0491_dx. */
u16 renamed_1eda_0491(u16 ax)
{
	u16 t;
	u8 carry;

	t = (u16)(ax + 0x0007);                 /* add ax,7h */
	carry = (u8)(((u32)ax + 0x0007) > 0xFFFF);  /* CF out of the add */
	g_0491_dx = (u16)((t >> 0x01) | ((u16)carry << 15));  /* rcr dx,1 */
	g_0491_dx = (u16)(g_0491_dx >> 0x01);   /* shr dx,1 */
	g_0491_dx = (u16)(g_0491_dx >> 0x01);   /* shr dx,1 */
	g_0491_dx = (u16)(g_0491_dx >> 0x01);   /* shr dx,1 */
	return (u16)(t & 0x0008);               /* and ax,8h */
}

/* 1EDA:0432 -- coalesce/split helper for the far-heap free list.
 * bx_cx = (segment:offset) of the node to link; es_di carries the adjacent
 * node as a flat pointer whose low/high 16 bits are its offset/segment.
 * Returns AX at the retf (identical to the axOut result on every path). */
u16 renamed_1eda_0432(u32 bx_cx, u8 * es_di, u16 * axOut, u16 * dxOut)
{
	u16 p_off = (u16)(uintptr_t)es_di;          /* di at entry (es_di.off) */
	u16 p_seg = (u16)((uintptr_t)es_di >> 16);  /* es at entry (es_di.seg) */
	u16 q_off = (u16)bx_cx;                     /* di after mov di,cx */
	u16 q_seg = (u16)(bx_cx >> 16);             /* es after mov es,bx */
	u16 cx_13;
	u16 bx_13;

	/* add cx,es:[di+4h] ; add bx,es:[di+6h] */
	cx_13 = (u16)(q_off + far_heap_word(q_seg, (u16)(q_off + 4)));
	bx_13 = (u16)(q_seg + far_heap_word(q_seg, (u16)(q_off + 6)));

	/* add cl,0F0h ; adc bx,0h ; and cl,0Fh */
	{
		u8 cl = (u8)cx_13;
		u8 t = (u8)(cl + 0xF0);
		u8 carry = (u8)(t < cl);
		bx_13 = (u16)(bx_13 + carry);
		cx_13 = (u16)((cx_13 & 0xFF00) | t);
		cx_13 = (u16)((cx_13 & 0xFF00) | ((u8)cx_13 & 0x0F));
	}

	/* cmp bx,dx ; jnz 0489h ; cmp cx,ax ; jnz 0489h */
	if (bx_13 != p_seg || cx_13 != p_off)
	{
		/* 1EDA:0489: store the adjacent node's far pointer in this node. */
		far_heap_setword(q_seg, q_off, p_off);
		far_heap_setword(q_seg, (u16)(q_off + 2), p_seg);
		*axOut = p_off;
		*dxOut = p_seg;
		return p_off;
	}

	/* cmp dx,[5360h] ; jnz 0468h ; cmp ax,[535Eh] ; jnz 0468h */
	if (p_seg != LG16(0x5360) || p_off != LG16(0x535E))
	{
		/* 1EDA:0468: copy the source node's next pointer, then fold its
		 * size fields into the destination's and normalize the low byte
		 * (movsw movsw / lodsw x2 / add / stosw x2). */
		u16 src4;
		u16 src6;
		u16 dst4;
		u16 dst6;
		u16 lo;
		u16 hi;

		far_heap_setword(q_seg, q_off,
		                 far_heap_word(p_seg, p_off));
		far_heap_setword(q_seg, (u16)(q_off + 2),
		                 far_heap_word(p_seg, (u16)(p_off + 2)));

		src4 = far_heap_word(p_seg, (u16)(p_off + 4));
		src6 = far_heap_word(p_seg, (u16)(p_off + 6));
		dst4 = far_heap_word(q_seg, (u16)(q_off + 4));
		dst6 = far_heap_word(q_seg, (u16)(q_off + 6));

		lo = (u16)(src4 + dst4);
		hi = (u16)(src6 + dst6);
		{
			u8 al = (u8)lo;
			u8 t = (u8)(al + 0xF0);
			u8 carry = (u8)(t < al);
			hi = (u16)(hi + carry);
			lo = (u16)((lo & 0xFF00) | t);
			lo = (u16)((lo & 0xFF00) | ((u8)lo & 0x0F));
		}
		far_heap_setword(q_seg, (u16)(q_off + 4), lo);
		far_heap_setword(q_seg, (u16)(q_off + 6), hi);
		*axOut = hi;                            /* AX at retf */
		*dxOut = lo;                            /* DX at retf */
		return hi;
	}

	/* 1EDA:045F: the adjacent node is the current heap high-water mark. */
	LG16(0x535E) = q_off;
	LG16(0x5360) = q_seg;
	*axOut = p_off;
	*dxOut = p_seg;
	return p_off;
}

/* 1EDA:03D3 -- validate a free-list insertion range and relink.
 * bx_cx = candidate block (segment:offset), ax = requested size.
 * Returns 1 when CF is set (rejected), 0 on success (cf clear at 042Dh).
 * dxOut is the 16-bit DX register result (the frozen prototype types the
 * slot as void *; the original is a 16-bit word, so two bytes are stored). */
u8 renamed_1eda_03d3(u32 bx_cx, u16 ax, u16 * axOut, void * dxOut)
{
	u16 cx = (u16)bx_cx;             /* mov cx, lo(bx_cx) */
	u16 bx = (u16)(bx_cx >> 16);     /* mov bx, hi(bx_cx) */
	u16 ax_124 = ax;
	u16 dx_124 = 0x0000;             /* DX is only assigned in the walk */
	u16 di;
	u16 es;

	if (ax == 0x0000)
	{
		/* 1EDA:0431: or ax,ax ; jz -- ret with CF clear. */
		*axOut = ax_124;
		*(u16 *)(void *)dxOut = dx_124;
		return 0x00;
	}

	/* 1EDA:03D7: test cx,0FFF7h ; jnz 0430h */
	if ((cx & 0xFFF7) != 0x0000)
		goto l1EDA_0430;

	/* 1EDA:03DD: cmp bx,[535Ch] ; ja 03EBh ; jc 0430h
	 *            cmp cx,[535Ah] ; jc 0430h */
	if (bx > LG16(0x535C))
		goto l1EDA_03EB;
	if (bx < LG16(0x535C))
		goto l1EDA_0430;
	if (cx < LG16(0x535A))
		goto l1EDA_0430;

l1EDA_03EB:
	/* 1EDA:03EB: cmp bx,[5360h] ; jc 03F9h ; ja 0430h
	 *            cmp cx,[535Eh] ; jnc 0430h */
	if (bx < LG16(0x5360))
		goto l1EDA_03F9;
	if (bx > LG16(0x5360))
		goto l1EDA_0430;
	if (cx >= LG16(0x535E))
		goto l1EDA_0430;

l1EDA_03F9:
	/* 1EDA:03F9: call 0491h ; mov di,cx ; mov es,bx
	 *            mov es:[di+4h],ax ; mov es:[di+6h],dx */
	{
		u16 ax_9 = renamed_1eda_0491(ax);
		far_heap_setword(bx, (u16)(cx + 4), ax_9);
		far_heap_setword(bx, (u16)(cx + 6), g_0491_dx);
	}

	/* 1EDA:0404: mov di,5366h ; mov ax,ds ; mov es,ax */
	di = 0x5366;
	es = 0x2014;                     /* ds = DGROUP selector 2014h */
	for (;;)
	{
		u16 si;
		u16 old_di;

		/* 1EDA:040F: mov ax,di ; mov dx,es ; les di,es:[di] ; mov si,es */
		old_di = di;
		ax_124 = di;                 /* mov ax,di */
		dx_124 = es;                 /* mov dx,es */
		di = far_heap_word(es, old_di);
		es = far_heap_word(es, (u16)(old_di + 2));

		si = es;
		if (bx > si)                 /* cmp bx,si ; ja 040Fh */
			continue;
		if (bx < si)                 /* 1EDA:041C: jc 0424h */
			break;
		if (cx > di)                 /* cmp cx,di ; ja 040Fh */
			continue;
		if (cx == di)                /* 1EDA:0422: jz 0430h */
			goto l1EDA_0430;
		break;                       /* cx < di -> fall to 0424 */
	}

	/* 1EDA:0424: push dx ; push ax ; call 0432h ;
	 *            pop cx ; pop bx ; call 0432h ; clc ; ret */
	{
		u16 out_ax_1;
		u16 out_dx_1;
		u16 out_ax_2;
		u16 out_dx_2;
		u16 prev_off = ax_124;       /* pushed AX */
		u16 prev_seg = dx_124;       /* pushed DX */
		u8 *node = (u8 *)(uintptr_t)(((u32)es << 16) | (u32)di);
		u8 *blk = (u8 *)(uintptr_t)bx_cx;

		(void)renamed_1eda_0432(bx_cx, node, &out_ax_1, &out_dx_1);
		(void)renamed_1eda_0432(((u32)prev_seg << 16) | (u32)prev_off, blk,
		                  &out_ax_2, &out_dx_2);
		*axOut = out_ax_2;
		*(u16 *)(void *)dxOut = out_dx_2;
		return 0x00;
	}

l1EDA_0430:
	/* 1EDA:0430: stc */
	*axOut = ax_124;
	*(u16 *)(void *)dxOut = dx_124;
	return 0x01;
}

/* 1EDA:04A2 -- atomically read and clear the DOS error word at DGROUP:5380. */
u8 renamed_1eda_04a2(void)
{
	/* xor ax,ax ; xchg [5380h],ax : AX <- old word, DGROUP:5380 = 0.
	 * The frozen prototype returns AL. */
	u16 v8_10 = LG16(0x5380);
	LG16(0x5380) = 0x0000;
	return (u8)v8_10;
}

/* 1EDA:04A9 -- pending-error trap.  When DGROUP:5380 is non-zero it tail-
 * enters the fatal-error dispatcher renamed_1eda_00e2 (which never returns);
 * otherwise it returns without touching DX:AX, so the caller's registers
 * survive.  The flat prototype can express the value only as a return, and
 * the register-preserving `retf` cannot be reproduced, so the surviving
 * path returns 0 (documented in docs/notes-1EDA.md).  wArg00/wArg02 are the
 * caller's return-address words that 00E2 pops as the error location. */
u32 fn1EDA_04A9(u16 wArg00, u16 wArg02, u8 * chOut, u16 * dsOut)
{
	u16 cx_13;
	u16 dx_15;
	u16 bx_46;
	void *ds_14 = NULL;

	/* cmp word ptr [5380h],0h ; jnz 04B1h */
	if (LG16(0x5380) != 0x0000)
	{
		/* 1EDA:04B1: mov ax,[5380h] ; jmp 00E2h */
		u16 ax_8 = LG16(0x5380);
		u16 ax_11 = renamed_1eda_00e2(ax_8, wArg00, wArg02,
		                        &cx_13, &dx_15, &bx_46, &ds_14);
		(void)chOut;                 /* CH is an <undefined> register output */
		*dsOut = 0x0000;             /* DGROUP selector dropped in flat model */
		return ((u32)dx_15 << 16) | (u32)ax_11;
	}

	/* 1EDA:04B0: retf with DX:AX unchanged (register-preserving trap). */
	(void)chOut;
	*dsOut = 0x0000;                 /* DGROUP selector dropped in flat model */
	return 0x00000000;
}

/* 1EDA:04B7 -- bounds check for INT 33h fn 13h (speed threshold).
 * DI points at the segment-local structure the caller placed at CS:0109
 * (`mov es,ss:[si+2]` recovers the caller's CS).  dx is signed, ax unsigned.
 * wArg00/psegArg02 are the caller's return-address words, used only by the
 * fatal-error tail-call.  Returns AX at the retf. */
u16 renamed_1eda_04b7(u16 ax, s16 dx, u8 * di, u16 wArg00, u16 psegArg02)
{
	/* cmp dx,es:[di+2h] ; jg 04CAh ; jl 04D9h ; cmp ax,es:[di] ; jc 04D9h */
	if ((dx > *(s16 *)(di + 2) ||
	     (dx >= *(s16 *)(di + 2) && ax >= *(u16 *)(di + 0))) &&
	    (dx < *(s16 *)(di + 6) ||
	     (dx <= *(s16 *)(di + 6) && ax <= *(u16 *)(di + 4))))
	{
		/* 1EDA:04D8: retf leaves AX unchanged. */
		return ax;
	}

	/* 1EDA:04D9: mov ax,0C9h ; jmp 00E2h */
	{
		u16 cx_96;
		u16 dx_97;
		u16 bx_98;
		void *ds_99 = NULL;

		return renamed_1eda_00e2(0xC9, wArg00, psegArg02,
		                   &cx_96, &dx_97, &bx_98, &ds_99);
	}
}
