/* seg1EDA_part1.c -- RAD V3.1 preservation port, segment 1EDA, chunk 1.
 *
 * Functions 1EDA:0000 .. 1EDA:01DF (12 functions, ascending offset).
 * Literal recovery from analysis/slices/1EDA/1EDA_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg1EDA.h.
 * See CONVENTIONS.md and docs/notes-1EDA.md ("## chunk 1").
 *
 * DOS services replaced (CONVENTIONS.md rule 4), all int 21h:
 *   1EDA:004B  AH=35h -> msdos_get_interrupt_vector   (0x13 table entries)
 *   1EDA:0062  AH=25h -> msdos_set_interrupt_vector   (vec 00/23/24/3F)
 *   1EDA:015C  AH=25h -> msdos_set_interrupt_vector   (restore 0x13)
 *   1EDA:019E  AH=4Ch -> msdos_terminate
 * Dropped: __sti (1EDA:00F2) and the far-jump through DGROUP:5372 at
 * 1EDA:012D (an installed overlay chain; Reko drops it too).
 *
 * Interrupt-handler addresses are kept as literal segment-image offsets
 * (g_seg1EDA[...]); they are never invoked in the port.
 */

#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1EDA.h"
#include "pal.h"

/* 1EDA:00FC walks a chain of paragraph blocks whose segment selectors are
 * linked through DGROUP 0x5354 (module/overlay descriptors: the key at
 * [node:0010h] is a code segment).  The flat port has no segmented heap and
 * no recovered code ever stores a selector at 0x5354 (it stays the zero
 * DGROUP value), so the walk is never entered; the node fetches are
 * modelled as zero so the recovered shape still compiles. */
static u16 far_heap_word(u16 seg, u16 off)
{
	return *(u16 *)far_ptr(FAR_PTR(seg, off));
}

/* 1EDA:0000 */
u16 fn1EDA_0000(void * es)
{
	u16 ss;
	u16 fp;
	u16 ax_15;
	u16 ax_18;
	u8 *si_30;
	u16 di_29;
	u16 cx_31;

	/* mov dx,2014h ; mov ds,dx -- flat DGROUP, no-op. */
	LG16(0x537C) = (u16)(uintptr_t)es;          /* mov [537Ch],es */

	/* mov ax,sp ; add ax,13h ; shr ax,4 ; add ax,ss : heap base.
	 * The flat host has no real-mode SS:SP; the emulated stack lives at
	 * paragraph 0x2BC5 (= load base 0x800 + e_ss 0x23C5) with the original
	 * e_sp 0xFDE8, giving the original formula's value 0x39A4 -- just above
	 * the emulated stack, below the PSP memtop (0x9FFF). */
	ss = 0x2BC5;
	fp = 0xFDE8;
	ax_15 = (u16)(((u16)(fp + 0x13) >> 0x04) + ss);
	LG16(0x534E) = ax_15;
	LG16(0x5350) = ax_15;
	/* t5348 ships zero and is not written before this point: the far heap
	 * starts with its top AT the base and grows toward the PSP memtop
	 * ([0x5364]) as allocations extend it (fn1EDA_0308 l1EDA_039C). */
	ax_18 = (u16)(ax_15 + LG16(0x5348));
	LG16(0x5352) = ax_18;
	LG16(0x535C) = ax_18;
	LG16(0x5360) = ax_18;
	LG16(0x5368) = ax_18;
	LG16(0x5364) = *(u16 *)((u8 *)es + 2);      /* es:[0002h] */
	LG16(0x536E) = 0xA9;
	LG16(0x5370) = 0x1EDA;                      /* mov [5370h],cs */

	/* Save the 0x13 interrupt vectors listed at 1EDA:01EE (AH=35h).
	 * Each entry is stored as a 32-bit value at DGROUP 0xBABC + i*4, the
	 * flat-port convention used by fn1E5F_0159 (offset:segment in DOS). */
	si_30 = &g_seg1EDA[0x01EE];
	di_29 = 0xBABC;
	for (cx_31 = 0x13; cx_31 != 0x00; --cx_31)
	{
		LG32(di_29) = (u32)(uintptr_t)msdos_get_interrupt_vector(*si_30);
		++si_30;
		di_29 = (u16)(di_29 + 0x04);
	}

	/* Install the new handlers (AH=25h); literals are image offsets. */
	msdos_set_interrupt_vector(0x00, &g_seg1EDA[0x00DF]);
	msdos_set_interrupt_vector(0x23, &g_seg1EDA[0x00E6]);
	msdos_set_interrupt_vector(0x24, &g_seg1EDA[0x00AE]);
	msdos_set_interrupt_vector(0x3F, &g_seg1EDA[0x00D7]);

	/* Build the two DGROUP:0B8BC / 0B9BC string blocks from the table at
	 * 1EDA:0218 (Reko: a01EE + 42). */
	fn1EDA_04F5(&g_seg1EDA[0x0218], &g_dgroup[0xB8BC]);
	fn1EDA_0565(&g_dgroup[0xB8BC]);
	fn1EDA_04F5(&g_seg1EDA[0x0218], &g_dgroup[0xB9BC]);
	fn1EDA_056A(&g_dgroup[0xB9BC]);

	/* Normal path leaves AX = 0 at the retf (see REPORT.md); the sole
	 * caller only keeps the word as a dropped ds selector. */
	return 0x0000;
}

/* 1EDA:00E2 */
u16 fn1EDA_00E2(u16 ax, u16 wArg00, u16 wArg02, u16 * cxOut, u16 * dxOut, u16 * bxOut, void * dsOut)
{
	/* pop cx ; pop bx ; jmp 00EDh : tail entry into the fatal-error
	 * dispatcher (00ED).  Reko models the popped CX as wArg00 (which is
	 * also the CX register result) and the popped BX as 00ED's bx. */
	(void)fn1EDA_00ED(ax, wArg00, wArg02);
	*cxOut = wArg00;
	/* The DX/BX/DS register outputs are never produced on any path (the
	 * dispatcher does not return), so no caller memory is written here;
	 * selector outputs are dropped per CONVENTIONS.md. */
	(void)dxOut;
	(void)bxOut;
	(void)dsOut;
	return 0x0000;
}

/* 1EDA:00E9 */
void * fn1EDA_00E9(u16 ax)
{
	/* xor cx,cx ; xor bx,bx ; -> 00ED */
	return fn1EDA_00ED(ax, 0x00, 0x00);
}

/* 1EDA:00ED */
void * fn1EDA_00ED(u16 ax, u16 cx, u16 bx)
{
	/* mov dx,2014h ; mov ds,dx ; sti (dropped) */
	LG16(0x5376) = ax;
	if ((u16)(cx | bx) == 0x00)
		fn1EDA_011B(cx, bx);        /* jz 011Bh */
	else
		fn1EDA_00FC(cx, bx);        /* fall through to 00FC */
	/* DS holds the DGROUP selector 2014h; the flat model maps it to the
	 * DGROUP image.  The value is only ever passed as a (dropped) ds arg. */
	return g_dgroup;
}

/* 1EDA:00FC */
void fn1EDA_00FC(u16 cx, u16 bx)
{
	u16 ax_38;
	u16 bx_23;

	ax_38 = LG16(0x5354);
	while (ax_38 != 0x00)
	{
		if (bx == far_heap_word(ax_38, 0x10))
		{
			bx = ax_38;
			break;
		}
		ax_38 = far_heap_word(ax_38, 0x14);
	}
	bx_23 = (u16)(bx - LG16(0x537C));
	fn1EDA_011B(cx, (u16)(bx_23 - 0x10));
}

/* 1EDA:011B */
void fn1EDA_011B(u16 cx, u16 bx)
{
	u16 cx_49;
	u8 *si_48;
	u16 di_47;

	LG16(0x5378) = cx;
	LG16(0x537A) = bx;
	if ((u16)(LG16(0x5372) | LG16(0x5374)) == 0x00)
	{
		/* 1EDA:0140: release the two DGROUP blocks, then restore the
		 * 0x13 vectors saved by fn1EDA_0000 (AH=25h). */
		fn1EDA_05BF(&g_dgroup[0xB8BC]);
		fn1EDA_05BF(&g_dgroup[0xB9BC]);
		si_48 = &g_seg1EDA[0x01EE];
		di_47 = 0xBABC;
		for (cx_49 = 0x13; cx_49 != 0x00; --cx_49)
		{
			msdos_set_interrupt_vector(*si_48, (void *)(uintptr_t)LG32(di_47));
			++si_48;
			di_47 = (u16)(di_47 + 0x04);
		}
		if ((u16)(LG16(0x5378) | LG16(0x537A)) != 0x00)
		{
			fn1EDA_01A5(&g_seg1EDA[0x0201]);   /* "Runtime error " */
			fn1EDA_01B3(LG8(0x5376));
			fn1EDA_01A5(&g_seg1EDA[0x0210]);   /* " at " */
			fn1EDA_01CD(LG16(0x537A));
			fn1EDA_01E7(0x3A);
			fn1EDA_01CD(LG16(0x5378));
			fn1EDA_01A5(&g_seg1EDA[0x0215]);   /* ".\r\n" */
		}
		msdos_terminate(LG8(0x5376));
	}
	else
	{
		/* 1EDA:012D: clear the exit-handler fields.  The original then
		 * far-jumps through DGROUP:5372 (the installed overlay chain)
		 * and resumes at 1EDA:0123; Reko drops that jump, so only the
		 * stores are recovered.  The chain is never installed here. */
		LG16(0x5372) = 0x00;
		LG16(0x5374) = 0x00;
		LG16(0x5380) = 0x00;
	}
}

/* 1EDA:01A5 */
void fn1EDA_01A5(u8 * bx)
{
	while (1)
	{
		u8 al_6 = *bx;
		if (al_6 == 0x00)
			break;
		fn1EDA_01E7(al_6);
		++bx;
	}
}

/* 1EDA:01B3 */
void fn1EDA_01B3(u8 al)
{
	u8 al_20 = fn1EDA_01BF(fn1EDA_01BF(al, 0x64), 0x0A);
	fn1EDA_01E7((u8)(al_20 + 0x30));
}

/* 1EDA:01BF */
u8 fn1EDA_01BF(u8 al, u8 cl)
{
	u16 ax_6 = (u16)al;
	u8 ah_9 = (u8)(ax_6 % cl);
	u8 al_10 = (u8)(ax_6 / cl);
	fn1EDA_01E7((u8)(al_10 + 0x30));
	return ah_9;
}

/* 1EDA:01CD */
void fn1EDA_01CD(u16 ax)
{
	u8 ah_8 = (u8)(ax >> 8);
	fn1EDA_01D4(ah_8);
	fn1EDA_01D4((u8)ax);
}

/* 1EDA:01D4 */
void fn1EDA_01D4(u8 al)
{
	/* push ax / pop ax preserve AL across the first call. */
	u8 al_9 = al;
	u8 al_21 = al;
	fn1EDA_01DF((u8)(al_9 >> 0x04));
	fn1EDA_01DF((u8)(al_21 & 0x0F));
}

/* 1EDA:01DF */
void fn1EDA_01DF(u8 al)
{
	if (al < 0x0A)
		fn1EDA_01E7((u8)(al + 0x30));
	else
		fn1EDA_01E7((u8)(al + 55));
}
