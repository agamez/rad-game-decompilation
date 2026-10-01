/* seg1EDA_part2a.c -- RAD V3.1 preservation port, segment 1EDA, chunk 2a.
 *
 * Functions 1EDA:01E7 .. 1EDA:0308 (4 functions, ascending offset):
 *   01E7 023F 0254 0308
 * Literal recovery from analysis/slices/1EDA/1EDA_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg1EDA.h.
 * See CONVENTIONS.md and docs/notes-1EDA.md ("## chunk 2a").
 *
 * DOS services (int 21h):
 *   1EDA:01EB  AH=06h with DL=al -> direct console output.  pal.h's frozen
 *              contract exposes only msdos_direct_console_input (the AH=06h
 *              DL=FF input half); there is no output entry point and pal.h
 *              may not be edited, so the byte is written to the host console
 *              by the file-static dos_console_output() below.  This is the
 *              only DOS/hardware deviation in the chunk.
 *
 * Free-list model: renamed_1eda_0308 walks the far-heap free list headed at
 * DGROUP:0x5366, relinks nodes and, at DGROUP:0x536E, far-calls the code
 * stub at 1EDA:00A9 (`xor ax,ax ; retf 2`).  As in chunk 2b, the flat port
 * models the far-heap node fetches with file-static far_heap_word /
 * far_heap_setword accessors (segment 0x2014 resolves to the LG image) and
 * the 1EDA:00A9 stub with the file-static heap_grow() helper.  See
 * docs/notes-1EDA.md ("## chunk 2a").
 *
 * Cross-part staging: renamed_1eda_0308 consumes the DX half of renamed_1eda_0491's
 * result through the extern `g_0491_dx` declared in src/seg1EDA_shared.h
 * (defined in src/seg1EDA_part2b.c).
 */

#include <stdint.h>
#include <stdio.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1EDA.h"
#include "seg1EDA_shared.h"
#include "pal.h"

/* ---------------------------------------------------------------- far heap
 * The original addresses nodes as segment:offset pairs.  The flat port keeps
 * the literal 16-bit segment/offset values but cannot map them onto a real
 * DOS heap; these accessors preserve the original read/modify shape exactly
 * as chunk 1 (renamed_1eda_00fc) and chunk 2b (renamed_1eda_03d3/0432) did. */

static u16 far_heap_word(u16 seg, u16 off)
{
	return *(u16 *)far_ptr(FAR_PTR(seg, off));
}

static void far_heap_setword(u16 seg, u16 off, u16 val)
{
	*(u16 *)far_ptr(FAR_PTR(seg, off)) = val;
}

/* The far call at 1EDA:039C / 1EDA:03BB goes through the DGROUP far code
 * pointer [536Eh]/[5370h].  renamed_1eda_0000 installs 1EDA:00A9 there and every
 * recovered flow leaves it in place; the shipped stub is
 * `xor ax,ax ; retf 2`, i.e. it consumes one word argument and returns 0.
 * (seg1AB8 temporarily installs 1AB8:050B around its own direct helper call
 * and restores the vector before any allocator use, so it is unreachable
 * here.)  A 16:16 code pointer is not callable from flat C, so this models
 * the stub. */
static u16 heap_grow(u16 size)
{
	(void)size;
	return 0x0000;
}

/* 1EDA:01EB int 21h AH=06h direct console output (DL != FF).  pal.h has no
 * output entry point; write the character to the host console. */
static void dos_console_output(u8 al)
{
	putchar((int)al);
}

/* 1EDA:01E7 */
void renamed_1eda_01e7(u8 al)
{
	/* mov dl,al ; mov ah,6h ; int 21h -- direct console output */
	dos_console_output(al);
}

/* 1EDA:023F -- allocate from the far heap; on success returns DX:AX = block
 * (segment:offset).  Only the word at [bp+6h] is a real argument (the frozen
 * wArg04); wArg00/wArg02 are the far return-address words that the fatal-error
 * dispatcher renamed_1eda_00e2 pops.  The size is handed to renamed_1eda_0308 and its
 * carry flag decides the borrow/error path. */
u32 fn1EDA_023F(u16 wArg00, u16 wArg02, u16 wArg04, u16 * dsOut)
{
	u16 ax_11;
	u16 dx_15;

	/* mov ax,[bp+6h] ; call 0308h -- the size is the word pushed by the
	 * caller, i.e. the FIRST flat argument (wArg00; wArg02/wArg04 model the
	 * far-return words of the original frame). */
	if (renamed_1eda_0308(wArg00, &ax_11, &dx_15))
	{
		/* 1EDA:024E: mov ax,0CBh ; jmp 00E2h */
		u16 cx_57;
		u16 dx_30;
		u16 bx_58;
		void *ds_29 = NULL;
		u16 ax_26 = renamed_1eda_00e2(0xCB, wArg00, wArg02,
		                        &cx_57, &dx_30, &bx_58, &ds_29);

		*dsOut = 0x0000;            /* DGROUP selector dropped in flat model */
		return ((u32)dx_30 << 16) | (u32)ax_26;
	}

	/* 1EDA:024B: retf 2h -- DX:AX = the allocated block address. */
	*dsOut = 0x0000;                /* DGROUP selector dropped in flat model */
	return ((u32)dx_15 << 16) | (u32)ax_11;
}

/* 1EDA:0254 -- free a far-heap block.  The real arguments are wArg04 (the
 * requested size passed in AX) and ptrArg06 (the 16:16 block address); the
 * frozen wArg00/wArg02 are the far return-address words used only by the
 * fatal-error tail call.  Validation is renamed_1eda_03d3's carry flag. */
s16 renamed_1eda_0254(u16 wArg00, u16 wArg02, u16 wArg04, u8 * ptrArg06,
                u16 * dxOut, u16 * dsOut)
{
	u16 ax_16;
	u16 dx_20;

	/* mov ax,[bp+6h] ; les cx,[bp+8h] ; mov bx,es ; call 03D3h --
	 * size = wArg00, block far pointer = (wArg02 offset, wArg04 segment). */
	if (renamed_1eda_03d3(FAR_PTR(wArg04, wArg02), wArg00,
	                &ax_16, (void *)&dx_20))
	{
		/* 1EDA:0268: mov ax,0CCh ; jmp 00E2h */
		u16 cx_66;
		u16 dx_36;
		u16 bx_67;
		void *ds_35 = NULL;
		u16 ax_32 = renamed_1eda_00e2(0xCC, wArg00, wArg02,
		                        &cx_66, &dx_36, &bx_67, &ds_35);

		*dxOut = dx_36;
		*dsOut = 0x0000;            /* DGROUP selector dropped in flat model */
		return (s16)ax_32;
	}

	/* 1EDA:0265: retf 6h */
	*dxOut = dx_20;
	*dsOut = 0x0000;                /* DGROUP selector dropped in flat model */
	return (s16)ax_16;
}

/* 1EDA:0308 -- far-heap allocator core.  AX = requested byte count; returns
 * the carry flag (1 = failure) and yields the block address in axOut (offset)
 * / dxOut (segment).  The free list is headed at DGROUP:0x5366; a node is a
 * far pointer (offset at +0, segment at +2) followed by a 32-bit paragraph
 * size (low at +4, high at +6).  The walk stops when the next node's segment
 * equals the high-water segment [5360]. */
u8 renamed_1eda_0308(u16 ax, u16 * axOut, u16 * dxOut)
{
	u16 ax_12 = ax;                 /* requested size (latched at 030C) */
	u16 dx = 0x0000;                /* DX register; set by renamed_1eda_0491 */
	u16 di = 0x0000;
	u16 es = 0x0000;
	u16 cx = 0x0000;
	u16 bx = 0x0000;
	u16 si = 0x0000;

	/* or ax,ax ; jz 0382h */
	if (ax == 0x0000)
		goto l1EDA_0382;

	/* l1EDA_030C */
	LG16(0xBB08) = ax_12;           /* mov [0BB08h],ax */

l1EDA_030F:
	/* call 0491h : AX = (size + 7) & 8; DX half latched in g_0491_dx */
	ax_12 = renamed_1eda_0491(ax_12);
	dx = g_0491_dx;

	/* mov di,5366h ; mov cx,ds ; mov es,cx */
	di = 0x5366;
	cx = 0x2014;
	es = cx;

l1EDA_0319:
	/* mov cx,di ; mov bx,es ; les di,es:[di] ; mov si,es */
	cx = di;
	bx = es;
	{
		u16 old_di = di;
		u16 old_es = es;

		di = far_heap_word(old_es, old_di);
		es = far_heap_word(old_es, (u16)(old_di + 0x02));
	}
	si = es;
	/* cmp si,[5360h] ; jz 0383h */
	if (si == LG16(0x5360))
		goto l1EDA_0383;

	/* l1EDA_0328: cmp dx,es:[di+6h] ; ja 0319h */
	if (dx > far_heap_word(es, (u16)(di + 0x06)))
		goto l1EDA_0319;

	/* cmp dx,es:[di+6h] ; jc 0336h */
	if (dx < far_heap_word(es, (u16)(di + 0x06)))
		goto l1EDA_0336;

	/* l1EDA_0330: cmp ax,es:[di+4h] ; ja 0319h */
	if (ax_12 > far_heap_word(es, (u16)(di + 0x04)))
		goto l1EDA_0319;

l1EDA_0336:
	{
		u16 node_off = di;              /* the block to hand out */
		u16 node_seg = es;
		u16 prev_off = cx;              /* the node that links to it */
		u16 prev_seg = bx;
		u16 next_off = far_heap_word(es, di);                /* mov cx,es:[di] */
		u16 next_seg = far_heap_word(es, (u16)(di + 0x02));  /* mov bx,es:[di+2] */
		u8 exact_fit =
			(u8)(dx == far_heap_word(es, (u16)(di + 0x06)) &&
			     ax_12 == far_heap_word(es, (u16)(di + 0x04)));

		/* push es ; push di ; push bx ; push cx ; ... ; jz 0376h */
		if (!exact_fit)
		{
			/* 1EDA:0343: split the node; the low address is handed out,
			 * the remainder becomes a new free-list node. */
			u16 rem_lo;
			u16 rem_hi;
			u16 new_off;
			u16 new_seg;
			u32 sz;
			u32 req;
			u32 rem;
			u8 al;
			u8 t;
			u16 carry_adc;

			/* mov cx,es:[di+4h] ; mov bx,es:[di+6h] ;
			 * sub cx,ax ; sbb bx,dx ; and cx,0Fh */
			sz = ((u32)far_heap_word(es, (u16)(di + 0x06)) << 16) |
			     (u32)far_heap_word(es, (u16)(di + 0x04));
			req = ((u32)dx << 16) | (u32)ax_12;
			rem = sz - req;
			rem_lo = (u16)((u16)rem & 0x000F);
			rem_hi = (u16)(rem >> 16);

			/* add ax,di ; add dx,si ; add al,0F0h ; adc dx,0h ; and al,0Fh */
			new_off = (u16)(ax_12 + di);
			new_seg = (u16)(dx + si + (u16)(new_off < ax_12));
			al = (u8)new_off;
			t = (u8)(al + 0xF0);
			carry_adc = (u16)(t < al);
			new_seg = (u16)(new_seg + carry_adc);
			new_off = (u16)((new_off & 0xFF00) | (t & 0x0F));

			/* mov di,ax ; mov es,dx ; pop es:[di] ; pop es:[di+2h] ;
			 * mov es:[di+4h],cx ; mov es:[di+6h],bx ; mov cx,di ; mov bx,es */
			di = new_off;
			es = new_seg;
			far_heap_setword(es, di, next_off);
			far_heap_setword(es, (u16)(di + 0x02), next_seg);
			far_heap_setword(es, (u16)(di + 0x04), rem_lo);
			far_heap_setword(es, (u16)(di + 0x06), rem_hi);
			cx = di;
			bx = es;
		}
		else
		{
			cx = next_off;
			bx = next_seg;
		}

		/* l1EDA_0376: pop di ; pop es ; mov es:[di],cx ;
		 * mov es:[di+2h],bx ; pop ax ; pop dx ; clc */
		far_heap_setword(prev_seg, prev_off, cx);
		far_heap_setword(prev_seg, (u16)(prev_off + 0x02), bx);
		*axOut = node_off;
		*dxOut = node_seg;
		return 0x00;
	}

l1EDA_0383:
	{
		u16 hw_off = di;                /* the old high-water block */
		u16 hw_seg = es;
		u8 al;
		u8 t;
		u16 carry_adc;

		/* add ax,di ; add dx,si ; add al,0F0h ; adc dx,0h ; and al,0Fh */
		{
			u16 lo = (u16)(ax_12 + di);
			u16 carry_add = (u16)(lo < ax_12);
			ax_12 = lo;
			dx = (u16)(dx + si + carry_add);
		}
		al = (u8)ax_12;
		t = (u8)(al + 0xF0);
		carry_adc = (u16)(t < al);
		dx = (u16)(dx + carry_adc);
		ax_12 = (u16)((ax_12 & 0xFF00) | (t & 0x0F));

		/* cmp dx,[5364h] ; jc 039Ch ; ja 03BBh ; cmp ax,[5362h] ; ja 03BBh */
		if (dx < LG16(0x5364))
			goto l1EDA_039C;
		if (dx > LG16(0x5364))
			goto l1EDA_03BB;
		if (ax_12 > LG16(0x5362))
			goto l1EDA_03BB;

l1EDA_039C:
		/* mov [535Eh],ax ; mov [5360h],dx ; mov es:[di],ax ;
		 * mov es:[di+2h],dx ; xor ax,ax ; push ax ; call [536Eh] ;
		 * pop ax ; pop dx ; clc */
		LG16(0x535E) = ax_12;
		LG16(0x5360) = dx;
		far_heap_setword(bx, cx, ax_12);            /* prev.next = new top */
		far_heap_setword(bx, (u16)(cx + 0x02), dx);
		(void)heap_grow(0x0000);
		*axOut = hw_off;
		*dxOut = hw_seg;
		return 0x00;
	}

l1EDA_03BB:
	{
		/* push word ptr [0BB08h] ; call [536Eh] ; cmp al,1h */
		u16 ax_65 = heap_grow(LG16(0xBB08));
		u8 al_71 = (u8)ax_65;

		/* jc 0382h -- AL < 1: growth failed, CF set at the ret. */
		if (al_71 < 0x01)
		{
			*axOut = ax_65;
			*dxOut = dx;
			return 0x01;
		}
		/* jz 03CFh -- AL == 1: xor ax,ax ; cwd ; ret (CF clear). */
		if (al_71 == 0x01)
		{
			*axOut = 0x0000;
			*dxOut = 0x0000;
			return 0x00;
		}
		/* 1EDA:03C9: mov ax,[0BB08h] ; jmp 030Fh */
		ax_12 = LG16(0xBB08);
		goto l1EDA_030F;
	}

l1EDA_0382:
	*axOut = ax_12;
	*dxOut = dx;
	return 0x00;
}
