/* seg1AB8_part4.c -- RAD V3.1 preservation port, segment 1AB8 (VIDEO),
 * chunk 4 of N: functions 1AB8:11FB .. 1AB8:14F4 (11 functions, ascending).
 *
 * Literal recovery from analysis/slices/1AB8/1AB8_<off>.asm (ground truth),
 * the per-function Reko slices and analysis/reko/RAD_1AB8.dis (Reko IR);
 * frozen prototypes from src/seg1AB8.h (analysis/summary/iface.tsv) are
 * adopted exactly.  See CONVENTIONS.md and docs/notes-1AB8.md ("## chunk 4").
 *
 * Hardware / DOS: this chunk issues no raw port I/O (no in/out), no int
 * 10h/16h/21h, no __cli/__sti and no int 23h, so it references no pal_*
 * entry point.  Every BIOS/DOS service reached from here goes through
 * segment 1EDA (fn1EDA_096F, 098A, 0953, 11DF, 0A39) or through the
 * graphics-driver dispatch helpers fn1AB8_1C6A/1CED/1D82/1E0B (segment
 * 1AB8), all replaced in their own ports, not here.
 *
 * VGA far pointers: no segment-0xA000 literal occurs in this chunk, so
 * pal_vga_memory() is not referenced.  The far pointers here are DGROUP
 * (g_dgroup + off), stack buffers, or caller-supplied flat pointers.
 *
 * Shared staging: none required.  No file-scope variable is shared with a
 * function outside 11FB..14F4, so src/seg1AB8_shared.h is not created.
 */
#include <stddef.h>
#include <stdint.h>

#include "radtypes.h"
#include "globals.h"
#include "seg1AB8.h"
#include "seg1EDA.h"
#include "seg1E78.h"

// 1AB8:11FB: u16 fn1AB8_11FB(u16 wArg02, void * dsOut)
u16 fn1AB8_11FB(u16 wArg02, void * dsOut)
{
	s16 cx_69;
	s16 dx_70;
	s16 bx_71;
	void * ds_46 = NULL;                   /* 098A's DS register output */
	u16 ax_11 = LG16(0xB84C);
	u16 ax_43;

	/* asm: push dx(=0) / push ax(=[0B84Ch]) save the divisor bx:cx across the
	 * 096F multiply; the pops restore it as bx:cx.  The two stack words 098A
	 * receives (wArg00/wArg02) are the values Reko's IR recovered (ax_11 and
	 * 0); the original relies on the leftover stack slots.  See notes. */
	ax_43 = (u16)fn1EDA_098A((u32)ax_11,
	                         fn1EDA_096F(wArg02, LG16(0xB84A), 0x0000, 0x0000),
	                         ax_11, 0x0000,
	                         &cx_69, &dx_70, &bx_71, &ds_46);
	*(u16 *)dsOut = (u16)(uintptr_t)ds_46;  /* 16-bit dropped selector */
	return ax_43;
}

// 1AB8:122E: u16 fn1AB8_122E(u16 wArg04, u16 wArg06, u16 wArg08)
//
// Draw one scaled number with the BGI text driver.  The ONLY caller in the
// whole program is fn0800_3CFA's machine-speed calibration poll (0800:3D1E):
// 3CFA counts how many of these polls fit in a fixed 100-centisecond window
// and stores count*8/100 at DGROUP:58E6h -- the game-wide animation speed
// index (the 02D8h/070Dh tick units are derived from it).  On the emulated
// era machine one poll (this BGI text draw plus the clock read) costs
// ~10-16ms, so the window holds ~88-99 polls and 58E6h settles at the game's
// own startup default of 7 (see fn0800_4255: `mov word [58E6h],7h`).  The
// host executes the draw thousands of times faster, which would store a
// garbage-high index and re-time every animation; this hook therefore gives
// each poll the emulated machine's cost, exactly like the calibrated 029Ch
// busy-wait in seg1E78.  With ~10.5ms per poll the window yields ~95 counts
// -> 58E6h = 7, the designed and DOSBox-observed value.
u16 fn1AB8_122E(u16 wArg04, u16 wArg06, u16 wArg08)
{
	void * ds_36 = NULL;
	u16 ax_11FB;

	ax_11FB = fn1AB8_11FB(wArg04, &ds_36);
	fn1AB8_1B90(ax_11FB, wArg04, 0x0168, 0x0000, wArg06, wArg08);
	fn1E78_pace_ns(10500000ull);   /* emulated BGI text-draw cost (3CFA poll) */
	return 0x0000;   /* DGROUP selector dropped in the flat model */
}

// 1AB8:1250: void fn1AB8_1250(u16 wArg04)
void fn1AB8_1250(u16 wArg04)
{
	if (wArg04 <= 0x000F)
	{
		LG8(0xB840) = (u8)wArg04;
		if (wArg04 == 0x0000)
			LG8(0xB87B) = 0x00;
		else
			LG8(0xB87B) = LG8((u16)(wArg04 + 0xB87B));
		fn1AB8_1CA4(LG8(0xB87B));
	}
}

// 1AB8:1285: void fn1AB8_1285(void)
void fn1AB8_1285(void)
{
	/* 1AB8:1285 materialises AX = (u16)LG8(0xB83E) and its fn0C74 callers
	 * consume it (`call far 1AB8h:1285h ; mov [bp-6h],ax`), but the frozen
	 * prototype (iface.tsv, confidence "mech") is `void`, so the value cannot
	 * be returned without editing src/seg1AB8.h.  The original read is kept;
	 * see docs/notes-1AB8.md ("## chunk 4", uncertain site). */
	(void)LG8(0xB83E);
}

// 1AB8:129A: void fn1AB8_129A(void * ptrArg04)
void fn1AB8_129A(void * ptrArg04)
{
	u8 * p = (u8 *)ptrArg04;
	u8  buf[0x12];       /* [bp-16h]: 0x11 copied bytes + NUL at [bp-5h] */
	u8  bLoc05;          /* [bp-03h]: count, clamped to 0x10 */
	u16 wLoc04;          /* [bp-02h]: loop index */
	u16 wLoc1C;          /* [bp-1Ch]: count - 1 */
	u16 ax_34;

	if (LG8(0xB84E) == 0x00)
		return;

	if (p[0] > 0x10)               /* asm: cmp es:[di],10h ; jbe -> else */
		bLoc05 = 0x10;
	else
		bLoc05 = p[0];

	ax_34 = (u16)bLoc05;
	wLoc1C = (u16)(ax_34 - 0x0001);   /* mov al,bLoc05; xor ah,ah; dec ax */
	if (ax_34 >= 0x0001)              /* dis: branch ax_34 < 1 -> skip loop */
	{
		wLoc04 = 0x0000;
		do
		{
			/* asm: cmp byte ptr es:[di+1],0FFh ; jle 1305h  (0xFF = -1
			 * signed): store only for bytes 0x00..0x7F. */
			if ((s8)p[1 + wLoc04] >= 0)
				LG8((u16)(wLoc04 + 0xB87B)) = p[1 + wLoc04];
			if (wLoc04 == wLoc1C)   /* asm: cmp ax,[bp-1Ch] */
				break;
			++wLoc04;
		} while (1);
	}

	if (p[1] != 0xFF)              /* cmp byte ptr es:[di+1],0FFh ; jz */
		LG8(0xB840) = 0x00;

	fn1EDA_11DF(0x11, buf, &g_dgroup[0xB87A]);
	buf[0x11] = 0x00;              /* mov byte ptr [bp-5h],0 */
	fn1AB8_1CED(buf);
}

// 1AB8:1342: u8 fn1AB8_1342(u8 bArg04, u16 wArg06)
u8 fn1AB8_1342(u8 bArg04, u16 wArg06)
{
	u16 ax = 0x0000;
	u16 ax_14;

	if (LG8(0xB84E) == 0x00)
		return (u8)(ax >> 8);
	ax_14 = (u16)LG8(0xB87A);
	ax = (u16)(ax_14 - 0x0001);
	/* dis: branch (ax_14 - 1) <u wArg06 -- keep the 16-bit wrap of the
	 * subtraction (C would otherwise promote to a signed int). */
	if ((u16)(ax_14 - 0x0001) < wArg06 || (s8)bArg04 < 0x00)
		return (u8)(ax >> 8);
	LG8((u16)(wArg06 + 0xB87B)) = bArg04;
	if (wArg06 == 0x0000)
		LG8(0xB840) = 0x00;
	ax = (u16)fn1AB8_1CD7((s16)bArg04, wArg06);
	return (u8)(ax >> 8);          /* SLICE(ax, byte, 8) */
}

// 1AB8:1384: void fn1AB8_1384(u8 * ptrArg04)
void fn1AB8_1384(u8 * ptrArg04)
{
	/* fn1EDA_0953 copies 0x11 bytes from the pointer returned by fn1AB8_1C6A
	 * into ptrArg04 (asm pushes the destination first, source last). */
	fn1EDA_0953(0x11, ptrArg04, fn1AB8_1C6A());
}

// 1AB8:13A3: u16 fn1AB8_13A3(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)
u16 fn1AB8_13A3(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)
{
	u16 ax_24 = fn1AB8_19A6(wArg04, wArg06, wArg08, wArg0A);

	if (ax_24 == 0xFFFF)           /* asm cmp word ptr [bp-4h],0FFh (sign-ext) */
		LG16(0xB818) = 0xFFF5;
	return ax_24;
}

// 1AB8:13D7: u16 fn1AB8_13D7(u8 bArg04, u8 * ptrArg06, u16 wArg0A, u16 wArg0C)
u16 fn1AB8_13D7(u8 bArg04, u8 * ptrArg06, u16 wArg0A, u16 wArg0C)
{
	u16 ax_13;                     /* [bp-02h]: old word at ptrArg06+2 */
	s32 t;
	u16 sum_lo;
	u16 dx_119 = 0x0000;

	ax_13 = *(u16 *)(ptrArg06 + 2);
	/* asm: ax = (wArg0A + [0B854h]); cwd ; [0B7C4h] - that 32-bit value,
	 * low word stored. */
	t = (s32)(s16)(u16)(wArg0A + LG16(0xB854));
	*(u16 *)(ptrArg06 + 2) = (u16)((u32)LG16(0xB7C4) - (u32)t);
	if (*(u16 *)(ptrArg06 + 2) > ax_13)
		*(u16 *)(ptrArg06 + 2) = ax_13;

	/* 1419: compare [0B7C2h] with (wArg0C + [0B852h]) + ptrArg06[0].
	 * The asm also compares the 32-bit high words dx(=0)/bx, but the IR
	 * proves both branches are dead (`branch false`), and the negative-sum
	 * case is caught by the 1444 test below; the result is the unsigned
	 * low-word compare. */
	sum_lo = (u16)(wArg0C + LG16(0xB852) + *(u16 *)ptrArg06);
	if (LG16(0xB7C2) < sum_lo)     /* 1440: cmp ax,cx ; jc */
		goto l1AB8_1464;
	if ((s16)(wArg0C + LG16(0xB852)) < 0x00)   /* 1444: or ax,ax ; jl */
		goto l1AB8_1464;
	/* 144F: cmp word ptr es:[di+2h],0 ; jc -- an unsigned `<u 0` test on the
	 * u16 field, always false (IR: unsigned `<u 0` on ptrArg06+2), so no
	 * branch is emitted. */
	if ((s16)(wArg0A + LG16(0xB854)) >= 0x00)  /* 1459: or ax,ax ; jge */
		goto l1AB8_1470;

l1AB8_1464:
	*(u16 *)(ptrArg06 + 2) = ax_13;
	goto l1AB8_148C;

l1AB8_1470:
	dx_119 = fn1AB8_1E9F(bArg04, ptrArg06, wArg0A, wArg0C);
	*(u16 *)(ptrArg06 + 2) = ax_13;

l1AB8_148C:
	return dx_119;
}

// 1AB8:1492: void fn1AB8_1492(u8 * ptrArg04)
void fn1AB8_1492(u8 * ptrArg04)
{
	u8  buf[0x100];                /* [bp-0100h] */
	u16 dx_157;
	u8  ch_158;
	u16 ax_1E0B;

	fn1EDA_0A39(0xFF, buf, ptrArg04, &dx_157);
	(void)fn1AB8_1D82(buf, LG16(0xB846), LG16(0xB844), &ch_158);
	if (LG16(0xB892) == 0x0000 && LG16(0xB88E) == 0x0000)
	{
		/* asm: ax = fn1AB8_1E0B(buf); cwd ; add ax,[0B844h] ; adc dx,0,
		 * then fn1AB8_108B([0B846h], low word). */
		ax_1E0B = fn1AB8_1E0B(buf);
		fn1AB8_108B(LG16(0xB846), (u16)(LG16(0xB844) + ax_1E0B));
	}
}

// 1AB8:14F4: void fn1AB8_14F4(u16 wArg04, u16 wArg06)
void fn1AB8_14F4(u16 wArg04, u16 wArg06)
{
	/* The asm's first and third tests are `cmp word ptr [bp+N],0 ; jc`,
	 * i.e. unsigned `x <u 0`, which is never taken (IR: `branch ... <u 0`);
	 * the >u 2 test already rejects 0x8000..0xFFFF.  The dead branches are
	 * therefore omitted; the effective range check is unchanged. */
	if (wArg06 > 0x0002u)
		goto l1AB8_150F;
	if (wArg04 <= 0x0002u)
		goto l1AB8_1517;

l1AB8_150F:
	LG16(0xB818) = 0xFFF5;
	goto l1AB8_152D;

l1AB8_1517:
	LG16(0xB892) = wArg06;
	LG16(0xB894) = wArg04;
	fn1AB8_1992((u8)wArg04, (u8)wArg06);

l1AB8_152D:
	return;
}
