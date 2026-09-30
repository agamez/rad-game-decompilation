/* seg0800_part1.c -- RAD V3.1 preservation port, segment 0800, part 1.
 *
 * Functions 0800:0000 .. 0800:04E3 (11 functions, ascending offset):
 *   0000 0024 005A 00C1 0103 0147 01FE 031B 03F8 04CC 04E3
 *
 * Literal recovery from analysis/slices/0800/0800_<off>.asm (ground truth)
 * and the Reko decompilation; frozen prototypes from src/seg0800.h
 * (analysis/summary/iface.tsv).  See CONVENTIONS.md and
 * docs/notes-0800.md ("## part 1").
 *
 * Hardware / DOS replaced (CONVENTIONS.md rule 4):
 *   None.  No int 10h / int 16h / int 21h, no `in`/`out` port instruction,
 *   no __cli/__sti and no int 23h occur in 0000..04E3.  Every BIOS/DOS
 *   service reached from here goes through segment 1E5F (fn1E5F_0159 /
 *   0171, the AH=35h/25h vector wrappers), segment 1E78 (fn1E78_016B) and
 *   segment 1EDA/0C74/11C8, and is replaced in those ports, not here.
 *
 * Flat-model far pointers:
 *   The heap blocks allocated by fn1EDA_023F are 16:16 far values returned
 *   as (segment << 16) | offset, the port convention already used by
 *   seg1AB8/seg1229.  The DGROUP tables at 0x598E/0x5990 (stream record
 *   position) and 0x5992/0x5388 (far-pointer arrays: low word = offset,
 *   high word = segment) are kept as two literal words exactly as the
 *   original stores them.
 */

#include <stdint.h>
#include <time.h>

#include "radtypes.h"
#include "globals.h"
#include "seg0800.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1E5F.h"
#include "seg1E78.h"
#include "seg11C8.h"
#include "seg1206.h"
#include "seg0C74.h"
#include "seg13E2.h"

// 0800:0000: u16 fn0800_0000(void)
// Terminate/deinit path: video (1AB8) and keyboard/PIT (1E78) teardown, then
// the AdLib (11C8) shutdown, then the CRT fatal exit fn1EDA_00E9(0).
u16 fn0800_0000(void)
{
	u16 dx_69;

	fn1AB8_0EB5();
	fn1AB8_0E88();
	/* push word ptr [0B8ACh] ; call far 1E78h:016Bh */
	fn1E78_016B(LG16(0xB8AC), &dx_69);
	fn11C8_03BB();
	/* xor ax,ax ; call far 1EDAh:00E9h -- the process exit (no return).
	 * The frozen prototype returns u16, so the callee pointer result is
	 * narrowed the same way seg1AB8 does. */
	return (u16)(uintptr_t)fn1EDA_00E9(0x0000);
}

// 0800:0024: void fn0800_0024(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)
// Draw text via the video helper.  The second 1AB8:0F93 call's arguments are
// pushed in the order 10CE(), 10E1() (asm 0800:0030..003C), so they are
// evaluated left to right here.
void fn0800_0024(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)
{
	u16 wLoc10CE;
	u16 wLoc10E1;

	fn1AB8_0F93(0x01, wArg02, wArg04, wArg06, wArg08);
	fn1AB8_1028();
	wLoc10CE = fn1AB8_10CE();
	wLoc10E1 = fn1AB8_10E1();
	fn1AB8_0F93(0x01, wLoc10E1, wLoc10CE, 0x00, 0x00);
}

// 0800:005A: void fn0800_005A(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)
void fn0800_005A(u16 wArg02, u16 wArg04, u16 wArg06, u16 wArg08)
{
	/* push 1h ; push 3h ; call far 1AB8h:1175h */
	fn1AB8_1175(0x03, 0x01);
	fn1AB8_1B3E(wArg02, wArg04, wArg06, wArg08);
}

// 0800:00C1: u8 fn0800_00C1(u16 wArg02, u16 wArg04, u16 * dxOut)
// Install the 0800:007B interrupt handler on vector 1Ch the first time; save
// the previous vector at ds:58C0h and set the "installed" flag at 58BEh.
u8 fn0800_00C1(u16 wArg02, u16 wArg04, u16 * dxOut)
{
	u16 dx = 0x0000;
	u16 ax = 0x0000;

	if (LG8(0x58BE) == 0x00)
	{
		/* xor ax,ax ; mov [53E2h],ax */
		LG16(0x53E2) = 0x0000;
		/* mov ax,[bp+4h] ; mov dx,[bp+6h] ; mov [58D8h],ax ; mov [58DAh],dx */
		LG16(0x58D8) = wArg02;
		LG16(0x58DA) = wArg04;
		/* 0800:00E2: AH=35h save vector 1Ch at ds:58C0h. */
		fn1E5F_0159((u32 *)&g_dgroup[0x58C0], 0x1C);
		/* 0800:00F0: AH=25h install cs:007Bh on vector 1Ch. */
		ax = (u16)fn1E5F_0171(&g_seg0800[0x007B], 0x1C, &dx);
		LG8(0x58BE) = 0x01;
		fn0800_timer_reset();   /* the emulated 1Ch tick phase restarts here */
	}
	*dxOut = dx;
	return (u8)(ax >> 8);
}

// 0800:0103: void fn0800_0103(void)
// Restore the vector saved by fn0800_00C1 when installed.
void fn0800_0103(void)
{
	u16 dx_52 = 0x0000;

	if (LG8(0x58BE) != 0x00)
	{
		/* push 1Ch ; push [58C2h] ; push [58C0h] ; call far 1E5Fh:0171h */
		fn1E5F_0171((void *)(uintptr_t)LG32(0x58C0), 0x1C, &dx_52);
		LG8(0x58BE) = 0x00;
	}
}

/* ---- emulated int-1Ch handler (cs:007Bh) ------------------------------
 * The handler installed by fn0800_00C1 is, in the original binary:
 *   add word [53E2h],37h        ; one 55ms BIOS tick of milliseconds
 *   cmp word [53E2h],3E8h       ; reached 1000?
 *   jb done
 *   mov word [53E2h],0
 *   cmp word [58DAh],0          ; 32-bit clock 58D8h:58DAh > 0?
 *   jg dec / jl done / cmp word [58D8h],0 / jbe done
 * dec: sub word [58D8h],1 / sbb word [58DAh],0
 *
 * The port has no asynchronous interrupt source, so the same state
 * transition is applied lazily from the host monotonic clock: every call
 * applies 37h per elapsed 18.2065 Hz tick since the previous application,
 * only while the handler is installed (58BEh != 0).  Driven from fn0800_0C71h
 * (the per-frame tick) and from the 1E78 pacing primitive (time passes
 * inside long animation waits, as it does under real interrupts).  The tick
 * phase restarts at every fn0800_00C1 arm / fn0800_0103 disarm. */
static int g_timer_t0_valid;
static struct timespec g_timer_t0;
static unsigned long long g_timer_ticks_applied;

void fn0800_timer_reset(void)
{
	g_timer_t0_valid = 0;
	g_timer_ticks_applied = 0;
}

void fn0800_timer_service(void)
{
	struct timespec now;
	long double el;
	unsigned long long target;

	if (LG8(0x58BE) == 0x00)
	{
		g_timer_t0_valid = 0;
		return;
	}
	clock_gettime(CLOCK_MONOTONIC, &now);
	if (!g_timer_t0_valid)
	{
		g_timer_t0 = now;
		g_timer_t0_valid = 1;
		return;
	}
	el = (long double)(now.tv_sec - g_timer_t0.tv_sec) +
	     (long double)(now.tv_nsec - g_timer_t0.tv_nsec) / 1.0e9L;
	target = (unsigned long long)(el * 18.2065L);
	if (target <= g_timer_ticks_applied)
		return;
	while (g_timer_ticks_applied < target)
	{
		/* add word [53E2h],37h ; cmp 3E8h ; jb done ; mov 0 ; maybe dec */
		u16 ms = (u16)(LG16(0x53E2) + 0x0037);
		++g_timer_ticks_applied;
		if (ms < 0x03E8)
		{
			LG16(0x53E2) = ms;
			continue;
		}
		LG16(0x53E2) = 0x0000;
		/* the 32-bit compare: signed high word, then unsigned low word */
		if ((s16)LG16(0x58DA) > 0)
			goto dec;
		if ((s16)LG16(0x58DA) < 0)
			continue;
		if (LG16(0x58D8) == 0x0000)
			continue;
	dec:
		LG16(0x58D8) = (u16)(LG16(0x58D8) - 0x0001);
		if (LG16(0x58D8) == 0xFFFF)          /* sbb word [58DAh],0 borrow */
			LG16(0x58DA) = (u16)(LG16(0x58DA) - 0x0001);
	}
}

/* ---- end emulated int-1Ch handler ------------------------------------ */

// 0800:0147: u16 fn0800_0147(void)
// Load the .RAD.STR stream: open "RAD.STR", allocate one record per slot in
// the 0x5992 far-pointer table, read one record into each, then close.
u16 fn0800_0147(void)
{
	u8  abBuf[0x80];         /* [bp-0082h] DOS stream (DAT) block */
	u16 wLoc84;              /* [bp-0084h] record size (Reko wLoc8C_242) */
	u8  bLoc03;              /* [bp-0001h] table index (Reko bLoc03_244) */
	u16 dx_270;
	u16 dx_271;
	u16 ds_147 = 0x0000;     /* dropped DGROUP selector out of fn1EDA_023F */
	u16 ax_194 = 0x0000;
	u32 dx_ax_272;

	/* push 0 ; push 0 ; push 15h ; push 15h ; call far 1AB8h:13A3h */
	wLoc84 = fn1AB8_13A3(0x0015, 0x0015, 0x0000, 0x0000);

	/* cs:0125 = {7,"RAD.STR"}; on failure report via cs:012Dh. */
	if (fn0C74_0000(&g_seg0800[0x0125], &dx_270) == 0x00)
		fn13E2_0193(&g_seg0800[0x012D]);

	fn1EDA_0FA2(&g_seg0800[0x0125], abBuf);
	fn1EDA_0FD0(wLoc84, abBuf, &dx_271);

	bLoc03 = 0x00;
	for (;;)
	{
		fn0C74_00B2(0x02);
		/* allocate wLoc84 bytes; DX:AX = far block.  The asm's one stack
		 * word is the size and the frozen prototype places it in wArg04
		 * (see docs/notes-1EDA.md "## chunk 2a" uncertainty 5). */
		dx_ax_272 = fn1EDA_023F(wLoc84, 0x0000, 0x0000, &ds_147);
		LG16((u16)(0x5992 + (u16)bLoc03 * 4)) = (u16)dx_ax_272;
		LG16((u16)(0x5994 + (u16)bLoc03 * 4)) = (u16)(dx_ax_272 >> 16);
		/* read one record into the freshly allocated block: the block is
		 * the dropped [bp+0Ch] data pointer of fn1EDA_10BB (g_1EDA_io_buffer
		 * in the port); ptrArg04 = 0, wArg08 = 1, ptrArg0E = stream block. */
		ax_194 = fn1EDA_10BB((u8 *)0, 0x01,
		              (u8 *)far_ptr(LG32((u16)(0x5992 + (u16)bLoc03 * 4))), abBuf);
		if (bLoc03 == 0xC7)          /* cmp byte [bp-1h],0C7h ; jnz */
			break;
		++bLoc03;
	}
	fn1EDA_1051((u8)ax_194, abBuf);

	return 0x0000;   /* original returns the dropped DGROUP selector */
}

// 0800:01FE: void fn0800_01FE(void)
// Load the .RAD.DAT grid: read the saved level/mission parameters, clamp the
// mission byte to 10, then blit every occupied cell of the 0x10 x 0x1D tile
// table at 0x5CE0.
void fn0800_01FE(void)
{
	u8  abBuf[0x80];   /* [bp-0080h] DOS stream (DAT) block */
	u8  bLoc82;        /* [bp-0082h] outer row index (Reko bLoc84_301) */
	u8  bLoc81;        /* [bp-0081h] inner col index (Reko bLoc83_302) */
	u16 dx_346;
	u16 dx_348;
	u16 ax_1085;

	fn1EDA_0FA2(&g_seg0800[0x01F6], abBuf);          /* cs:01F6 = {7,"RAD.DAT"} */
	fn1EDA_0FD0(0x0219, abBuf, &dx_346);
	/* seek to record [5990h]:[598Eh], read one record (data pointer dropped). */
	ax_1085 = fn1EDA_1085((u8)fn1EDA_1123(LG16(0x598E), LG16(0x5990), abBuf), abBuf);
	fn1EDA_1051((u8)ax_1085, abBuf);
	/* mov di,[5CB4h] then [5ECEh]: copy 6 bytes */
	fn1EDA_0A39(0x06, &g_dgroup[0x5ECE], &g_dgroup[0x5CB4], &dx_348);

	LG8(0x53D9) = LG8(0x5CDE);
	LG8(0x53DA) = LG8(0x5CDF);
	LG8(0x53DB) = LG8(0x5CDA);
	LG8(0x53DC) = LG8(0x5CDB);
	if (LG8(0x5CDC) > 0x0A)
		LG8(0x5CDC) = 0x0A;
	LG8(0x53DD) = LG8(0x5CDC);
	LG8(0x53DE) = LG8(0x5CDD);

	fn0800_0024(0x0176, 0x027E, 0x0001, 0x0001);

	bLoc82 = 0x00;
	for (;;)
	{
		bLoc81 = 0x00;
		for (;;)
		{
			u16 idx = (u16)((u16)bLoc82 * 0x1D + (u16)bLoc81);
			if (LG8((u16)(0x5CE0 + idx)) != 0x00)
			{
				u16 rec = (u16)LG8((u16)(0x5CE0 + idx));
				u8 *blk = far_ptr(
					(((u32)LG16((u16)(0x5994 + rec * 4)) << 16) |
					(u32)LG16((u16)(0x5992 + rec * 4))));
				fn1AB8_13D7(0x00, blk,
				            (u16)((u16)bLoc82 * 0x16 + 0x0001),
				            (u16)((u16)bLoc81 * 0x16 + 0x0001));
			}
			if (bLoc81 == 0x1C)
				break;
			++bLoc81;
		}
		if (bLoc82 == 0x10)
			break;
		++bLoc82;
	}
}

// 0800:031B: u16 fn0800_031B(u16 * bpOut, u16 * dsOut)
// Poll one keyboard event, derive the "Fichier" selection from the cursor
// line (5982h-17h)/34h, map it to an attribute code and repaint.  Drains the
// event queue until a poll returns 0, then returns AX = (AH of the last poll)
// : result byte.
u16 fn0800_031B(u16 * bpOut, u16 * dsOut)
{
	s16  wLoc04;        /* [bp-0004h] selection index (Reko wFFFC) */
	u8   bLoc07;        /* [bp-0007h] attribute code (Reko bFFF9) */
	u8   bLoc01;        /* [bp-0001h] result byte (Reko bFFFF) */
	u8   ch;
	u16  dx = 0x0000;
	void *bp = (void *)0;
	u16  ds = 0x0000;
	u16  ax;
	u8   ah;

	/* push 0h ; call far 1206h:015Bh */
	ax = fn1206_015B(&ch, &dx, &bp, &ds);
	ah = (u8)(ax >> 8);
	if ((u8)ax != 0x00)
	{
		/* mov ax,[5982h] ; sub ax,17h ; cwd ; idiv 34h */
		wLoc04 = (s16)(((s32)(s16)(u16)(LG16(0x5982) - 0x0017)) / 0x0034);
		if (LG16(0x5984) > 0x0198 && LG16(0x5984) < 0x01C4)
		{
			if (LG8(0x58B0) != 0x00)
				fn11C8_0354(0x0190);
			/* The asm's switch has no default arm; [bp-7h] is left
			 * uninitialised if none of 0..8 matches.  Reko keeps the
			 * stale value; C needs a definite one, so seed 0. */
			bLoc07 = 0x00;
			switch (wLoc04)
			{
			case 0: bLoc07 = 0x48; break;    /* 'H' */
			case 1: bLoc07 = 0x4B; break;    /* 'K' */
			case 2: bLoc07 = 0x20; break;    /* ' ' */
			case 3: bLoc07 = 0x4D; break;    /* 'M' */
			case 4: bLoc07 = 0x50; break;    /* 'P' */
			case 5: bLoc07 = 0x3B; break;    /* ';' */
			case 6: bLoc07 = 0x3C; break;    /* '<' */
			case 7: bLoc07 = 0x3D; break;    /* '=' */
			case 8: bLoc07 = 0x1B; break;    /* ESC */
			}
			fn11C8_033B();
		}
		do
		{
			ax = fn1206_015B(&ch, &dx, &bp, &ds);
			ah = (u8)(ax >> 8);
		} while ((u8)ax != 0x00);
	}

	bLoc01 = bLoc07;
	*bpOut = 0x0000;   /* Reko-modelled saved-BP output; not meaningful here */
	*dsOut = 0x0000;   /* DGROUP selector dropped in the flat model */
	return (u16)(((u16)ah << 8) | (u16)bLoc01);
}

// 0800:03F8: u16 fn0800_03F8(void)
// Load the .RAD.BUT tile bitmap: open "RAD.BUT", allocate one record per
// 0x5388 far-pointer slot, read each record, then free the scratch block.
u16 fn0800_03F8(void)
{
	u8  abBuf[0x80];    /* [bp-0082h] DOS stream (DAT) block */
	u16 wLoc88;         /* [bp-0088h] per-slot record size (Reko ax_121) */
	u16 wLoc86;         /* [bp-0086h] scratch block offset (Reko wLoc8E_293) */
	u16 wLoc84;         /* [bp-0084h] scratch block segment (Reko wLoc90_294) */
	u8  bLoc03;         /* [bp-0001h] table index (Reko bLoc03_300) */
	u16 ax_04;
	u16 dx_333;
	u16 dx_334;
	u16 dx_336;
	u16 ds_139 = 0x0000;
	u16 ds_249 = 0x0000;
	u32 dx_ax_332;
	u32 dx_ax_335;

	(void)fn0800_0147();

	/* cs:03DD = {7,"RAD.BUT"}; on failure report via cs:03E5h. */
	if (fn0C74_0000(&g_seg0800[0x03DD], &dx_333) == 0x00)
		fn13E2_0193(&g_seg0800[0x03E5]);

	fn1EDA_0FA2(&g_seg0800[0x03DD], abBuf);
	ax_04 = LG16(0x0004);                /* record size = word at [0004h] */
	fn1EDA_0FD0(ax_04, abBuf, &dx_334);

	/* push 0 ; push 0 ; push 2Bh ; push 2Bh ; call far 1AB8h:13A3h */
	wLoc88 = fn1AB8_13A3(0x002B, 0x002B, 0x0000, 0x0000);

	/* first scratch allocation (freed after the loop); the asm's one stack
	 * word is the size, placed in wArg04 per the frozen prototype. */
	dx_ax_332 = fn1EDA_023F(ax_04, 0x0000, 0x0000, &ds_139);
	wLoc86 = (u16)dx_ax_332;
	wLoc84 = (u16)(dx_ax_332 >> 16);

	bLoc03 = 0x00;
	for (;;)
	{
		fn0C74_00B2(0x05);
		dx_ax_335 = fn1EDA_023F(wLoc88, 0x0000, 0x0000, &ds_139);
		LG16((u16)(0x5388 + (u16)bLoc03 * 4)) = (u16)dx_ax_335;
		LG16((u16)(0x538A + (u16)bLoc03 * 4)) = (u16)(dx_ax_335 >> 16);
		/* read one record into the allocated block (the block is the
		 * dropped data pointer of fn1EDA_10BB = g_1EDA_io_buffer). */
		(void)fn1EDA_10BB((u8 *)0, 0x01,
		                  (u8 *)far_ptr(LG32((u16)(0x5388 + (u16)bLoc03 * 4))), abBuf);
		if (bLoc03 == 0x10)
			break;
		++bLoc03;
	}
	{
		/* block far pointer = wLoc84:wLoc86 (seg:off); free it. */
		s16 ret_0254 = fn1EDA_0254(ax_04, wLoc86, wLoc84, 0,
		                           &dx_336, &ds_249);
		fn1EDA_1051((u8)ret_0254, abBuf);
	}

	(void)ds_249;
	return 0x0000;   /* original returns the dropped DGROUP selector */
}

// 0800:04CC: s16 fn0800_04CC(u8 bArg02)
// Grid coordinate: row/col index -> pixel line (index * 22 + 1).
s16 fn0800_04CC(u8 bArg02)
{
	u16 wLoc02;

	/* mov al,[bp+4h] ; xor ah,ah ; imul ax,ax,16h ; inc ax */
	wLoc02 = (u16)((u16)bArg02 * 0x16 + 0x0001);
	return (s16)wLoc02;
}

// 0800:04E3: u8 fn0800_04E3(u16 * dsOut)
// Render the six HUD counters (rows 53DBh/53DCh/53DEh) at the two on-screen
// positions used by the original.
u8 fn0800_04E3(u16 * dsOut)
{
	u8 *abBuf = g_dgroup + 0xF700;
	                    /* [bp-0100h] number/format scratch (Reko ptrLoc010A).
	                     * SS-resident, and SS==DS in the tiny model, so stage
	                     * at DGROUP 0xF700 for the ES:BX materialization that
	                     * fn1AB8_1D82 does for the driver's 0x26 text op (a C
	                     * stack buffer resolves to segment 0 and the op reads a
	                     * zeroed far arena, drawing nothing). */
	u16 ds_43 = 0x0000; /* dropped DGROUP selector out of fn1AB8_1536 */
	u8  ch;

	/* push 120h ; push 189h ; push 1A0h ; push 193h ; call 005Ah */
	fn0800_005A(0x0193, 0x01A0, 0x0189, 0x0120);
	fn1AB8_1536(0x01, 0x00, 0x00, &ds_43);
	fn1AB8_14F4(0x01, 0x01);
	fn1AB8_1C32(0x08);

	if (LG8(0x53DB) > 0x00)
	{
		fn0C74_004B((u32)LG8(0x53DB), abBuf);       /* x=12Fh,y=18Dh dropped */
		fn1AB8_1D82(abBuf, 0x018D, 0x012F, &ch);
	}
	if (LG8(0x53DC) > 0x00)
	{
		fn0C74_004B((u32)LG8(0x53DC), abBuf);       /* x=163h,y=18Dh dropped */
		fn1AB8_1D82(abBuf, 0x018D, 0x0163, &ch);
	}
	if (LG8(0x53DE) > 0x00)
	{
		fn0C74_004B((u32)LG8(0x53DE), abBuf);       /* x=197h,y=18Dh dropped */
		fn1AB8_1D82(abBuf, 0x018D, 0x0197, &ch);
	}

	fn1AB8_1C32(0x0E);

	if (LG8(0x53DB) > 0x00)
	{
		fn0C74_004B((u32)LG8(0x53DB), abBuf);       /* x=130h,y=18Eh dropped */
		fn1AB8_1D82(abBuf, 0x018E, 0x0130, &ch);
	}
	if (LG8(0x53DC) > 0x00)
	{
		fn0C74_004B((u32)LG8(0x53DC), abBuf);       /* x=164h,y=18Eh dropped */
		fn1AB8_1D82(abBuf, 0x018E, 0x0164, &ch);
	}
	if (LG8(0x53DE) > 0x00)
	{
		fn0C74_004B((u32)LG8(0x53DE), abBuf);       /* x=198h,y=18Eh dropped */
		fn1AB8_1D82(abBuf, 0x018E, 0x0198, &ch);
	}

	fn1AB8_1C32(0x00);
	*dsOut = ds_43;
	return 0x00;
}
