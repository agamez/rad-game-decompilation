/* seg1E5F.c -- recovered segment 1E5F of RAD V3.1 (DOS utility wrappers).
 *
 * Recovered from analysis/reko/RAD_1E5F.{c,asm,dis}.  Ground truth = the .asm.
 * Function order = ascending offset; Reko offset comments retained.
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   1E5F:0081  int 21h AH=2Ch  -> msdos_get_system_time
 *   1E5F:0128  int 21h AH=1Ah  -> msdos_set_DTA
 *   1E5F:0124  int 21h AH=4Eh  -> msdos_find_first_file
 *   1E5F:0128  int 21h AH=4Fh  -> msdos_find_next_file   (dos_find_next_file)
 *   1E5F:0191  int 21h AH=35h  -> msdos_get_interrupt_vector
 *   1E5F:0213  int 21h AH=25h  -> msdos_set_interrupt_vector
 *   __cli()/__sti() dropped (no-ops), see dos_interrupt_trampoline.
 *
 * Hardware interior dispatch:
 *   dos_interrupt_trampoline performs an arbitrary software interrupt (IVT[vec], the
 *   callers pass vector 33h/10h) with a register image.  pal.h now exposes
 *   pal_int_dispatch(vec, frame) for exactly this; the 9-word image is
 *   marshalled into a 10-word frame, dispatched, and the 10 post-interrupt
 *   words are stored back.  See docs/notes-1E5F-1E78-11C8.md.
 */

#include <string.h>
#include <stdint.h>

#include "seg1E5F.h"
#include "globals.h"
#include "pal.h"

/* Carry flag produced by the preceding find-first/find-next DOS call, which
 * dos_fix_dta_name consumes (`jc 0155h` in the original).  C has no flag register;
 * dos_find_first_file/dos_find_next_file stage it here before calling dos_fix_dta_name. */
static u8 g_find_carry;

// 1E5F:000B: void dos_interrupt_trampoline(u8 * ptrArg04, u16 wArg06)
// Register-frame interrupt trampoline.  ptrArg04 is the caller's 0x14-byte
// frame; wArg06 is the interrupt vector.  The original loads a 9-word image
// (AX,BX,CX,DX,BP,SI,DI,DS,ES at offsets 0,2,...,0x10), saves FLAGS,
// far-calls IVT[vec] and the 1E5F:0045 continuation stores the 10 words
// (those 9 plus FLAGS at 0x12) back.  Here the image is seeded into a local
// 10-word frame, FLAGS starts 0, pal_int_dispatch() performs the interrupt,
// and all ten words are stored back into the caller's frame.  The original
// __cli()/__sti() are dropped (no-ops).
void dos_interrupt_trampoline(u8 * ptrArg04, u16 wArg06) /* was fn1E5F_000B */
{
	u16 frame[10];
	int i;

	for (i = 0; i < 9; i++)
		frame[i] = *(u16 *)(ptrArg04 + 2 * i);
	frame[9] = 0x0000;                 /* FLAGS */
	pal_int_dispatch(wArg06, frame);
	for (i = 0; i < 10; i++)
		*(u16 *)(ptrArg04 + 2 * i) = frame[i];
}

// 1E5F:00A2: void dos_get_system_time(u16 * ptrArg04, u16 * ptrArg08, u16 * ptrArg0C, void * ptrArg10)
void dos_get_system_time(u16 * ptrArg04, u16 * ptrArg08, u16 * ptrArg0C, void * ptrArg10) /* was fn1E5F_00A2 */
{
	u8 ch_10;
	u8 dh_11;
	u8 dl_12;
	u8 cl_13;
	msdos_get_system_time(&ch_10, &cl_13, &dh_11, &dl_12);
	*ptrArg04 = (u16)dl_12;
	*ptrArg08 = (u16)dh_11;
	*ptrArg0C = (u16)cl_13;
	*(u16 *)ptrArg10 = (u16)ch_10;
}

// 1E5F:00DE: u8 * dos_find_first_file(char * ptrArg04, u16 wArg08, u8 * ptrArg0A)
// DOS find-first wrapper.  ptrArg0A is a length-prefixed search pattern; the
// first byte is the pattern length (clamped to 4Fh), followed by the bytes.
// wArg08 is the DOS CX attributes mask (0C74 passes 3Fh); pal.h's
// msdos_find_first_file() has no attributes parameter, so it is unused here.
u8 * dos_find_first_file(char * ptrArg04, u16 wArg08, u8 * ptrArg0A) /* was fn1E5F_00DE */
{
	static u8 buf[0x50];
	u8 al_22 = *ptrArg0A;
	u16 ax_28;
	if (al_22 >= 0x4F)
		al_22 = 0x4F;
	ax_28 = (u16)al_22;
	memcpy(buf, ptrArg0A + 1, ax_28);
	buf[ax_28] = 0x00;
	msdos_set_DTA(ptrArg04);
	g_find_carry = msdos_find_first_file((char *)buf, (u8 *)ptrArg04) ? 0 : 1;
	dos_fix_dta_name(0x4E00, 0, ptrArg04);
	return buf;
}

// 1E5F:011C: void dos_find_next_file(void * ptrArg04)
// DOS find-next follow-up.  Not listed in analysis/summary/functions.tsv
// (Reko did not identify it as a function), but the brief requires the 4Fh
// service to be recovered; it wraps msdos_set_DTA + msdos_find_next_file and
// then the same DTA fix-up as dos_find_first_file.  Called from segment 0C74.
void dos_find_next_file(void * ptrArg04) /* was fn1E5F_011C */
{
	msdos_set_DTA(ptrArg04);
	g_find_carry = msdos_find_next_file((u8 *)ptrArg04) ? 0 : 1;
	dos_fix_dta_name(0x4F00, 0, ptrArg04);
}

// 1E5F:0136: void dos_fix_dta_name(u16 ax, u16 di, void * es)
// Operates on the DTA at ES:DI.  ES is the flat base, DI the byte offset
// (the port passes DI = 0 and ES = the DTA pointer).  On success (CF clear
// from the preceding find, modelled by g_find_carry) it converts the
// null-terminated name at DTA+1Eh into a length-prefixed string in place and
// stores AX = 0; on failure it stores AX unchanged (4E00h/4F00h).
void dos_fix_dta_name(u16 ax, u16 di, void * es) /* was fn1E5F_0136 */
{
	if (!g_find_carry)
	{
		u8 *di_107 = (u8 *)es + di + 0x1E;
		u16 cx_20 = 0x0100;
		u8 cl_31;
		u8 ch_68;
		u8 *di_37;
		u8 cl_34;
		u8 *si_39;
		u16 cx_42;

		/* repne scasb (AL = 0) */
		for (;;)
		{
			u8 v;
			if (cx_20 == 0x00)
				break;
			v = *di_107;
			--cx_20;
			++di_107;
			if (v == 0x00)
				break;
		}
		cl_31 = (u8)cx_20;
		ch_68 = (u8)(cx_20 >> 8);
		di_37 = di_107 - 0x01;
		cl_34 = (u8)~cl_31;
		si_39 = di_37 - 0x01;
		cx_42 = (u16)(((u16)ch_68 << 8) | cl_34);
		/* rep movsb, DF=1: copy backwards one byte */
		for (; cx_42 != 0x00; --cx_42)
		{
			*di_37 = *si_39;
			--si_39;
			--di_37;
		}
		*di_37 = cl_34;
		ax = 0x00;
	}
	LG16(0xB8A6) = ax;
}

// 1E5F:0159: void dos_get_interrupt_vector(u32 * ptrArg04, u8 bArg08)
void dos_get_interrupt_vector(u32 * ptrArg04, u8 bArg08) /* was fn1E5F_0159 */
{
	*ptrArg04 = (u32)(uintptr_t)msdos_get_interrupt_vector(bArg08);
}

// 1E5F:0171: u8 dos_set_interrupt_vector(void * ptrArg04, u8 bArg08, u16 * dxOut)
u8 dos_set_interrupt_vector(void * ptrArg04, u8 bArg08, u16 * dxOut) /* was fn1E5F_0171 */
{
	msdos_set_interrupt_vector(bArg08, ptrArg04);
	*dxOut = (u16)(uintptr_t)ptrArg04;
	return 0x25;
}
