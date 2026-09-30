/* seg1AB8_part3.c -- RAD V3.1 preservation port, segment 1AB8 (VIDEO).
 *
 * Chunk 3 of seg1AB8: functions 1AB8:0F80 .. 1AB8:11A0, ascending.
 * Literal recovery from analysis/slices/1AB8/1AB8_<off>.asm (ground truth)
 * and the Reko decompilation.  See CONVENTIONS.md and docs/notes-1AB8.md.
 *
 * Hardware abstracted through pal/: this chunk itself issues no raw port I/O
 * or int 10h/21h; the hardware work lives in the same-segment helpers it calls
 * (fn1AB8_1895 -> [0xB820] gateway, fn1AB8_1C4A, fn1AB8_1968).  No 0xA000 VGA
 * far-pointer literal appears here; the only far pointers are DGROUP
 * (g_dgroup + 0xB866) and caller-supplied.
 */

#include "radtypes.h"
#include "globals.h"
#include "seg1AB8.h"
#include "seg1EDA.h"

/* 1AB8:0F80 */
void fn1AB8_0F80(void)
{
	fn1AB8_1AC2();
	fn1AB8_108B(0x00, 0x00);
}

/* 1AB8:0F93 */
u16 fn1AB8_0F93(u8 bArg04, u16 wArg06, u16 wArg08, u16 wArg0A, u16 wArg0C)
{
	u16 dx;
	if ((s16)wArg0C >= 0x00 && (s16)wArg0A >= 0x00)
	{
		u16 ax_14 = LG16(0xB7C2);
		dx = 0x00;
		if (wArg08 <= ax_14)
		{
			u16 ax_29 = LG16(0xB7C4);
			dx = 0x00;
			if (wArg06 <= ax_29
			    && (s16)wArg08 >= (s16)wArg0C
			    && (s16)wArg06 >= (s16)wArg0A)
			{
				LG16(0xB852) = wArg0C;
				LG16(0xB854) = wArg0A;
				LG16(0xB856) = wArg08;
				LG16(0xB858) = wArg06;
				LG8(0xB85A) = bArg04;
				dx = fn1AB8_1895(bArg04, wArg06, wArg08, wArg0A, wArg0C);
				fn1AB8_108B(0x00, 0x00);
				return dx;
			}
		}
	}
	LG16(0xB818) = ~0x0A;
	return dx;
}

/* 1AB8:1028 */
void fn1AB8_1028(void)
{
	u16 ax_11 = LG16(0xB862);
	u16 dx_12 = LG16(0xB864);
	fn1AB8_1175(0x00, 0x00);
	fn1AB8_1B3E(LG16(0xB858) - LG16(0xB854),
	            LG16(0xB856) - LG16(0xB852),
	            0x00, 0x00);
	if (ax_11 == 0x0C)
		fn1AB8_11A0(dx_12, g_dgroup + 0xB866);
	else
		fn1AB8_1175(dx_12, ax_11);
	fn1AB8_108B(0x00, 0x00);
}

/* 1AB8:108B */
void fn1AB8_108B(u16 wArg04, u16 wArg06)
{
	fn1AB8_1ACE(wArg04, wArg06);
	LG16(0xB844) = wArg06;
	LG16(0xB846) = wArg04;
}

/* 1AB8:10A8 */
u16 fn1AB8_10A8(void)
{
	return LG16(0xB844);
}

/* 1AB8:10BB */
u16 fn1AB8_10BB(void)
{
	return LG16(0xB846);
}

/* 1AB8:10CE */
u16 fn1AB8_10CE(void)
{
	return LG16(0xB7C2);
}

/* 1AB8:10E1 */
u16 fn1AB8_10E1(void)
{
	return LG16(0xB7C4);
}

/* 1AB8:10F4 */
void fn1AB8_10F4(u16 wArg04, u16 wArg06, u16 wArg08)
{
	if (wArg08 <= 0x04 && wArg04 <= 0x03)
	{
		LG16(0xB85C) = wArg08;
		LG16(0xB85E) = wArg06;
		LG16(0xB860) = wArg04;
		fn1AB8_1CFF((u8)wArg04, wArg06, wArg08);
	}
	else
		LG16(0xB818) = ~0x0A;
}

/* 1AB8:112E */
u8 fn1AB8_112E(u16 wArg04, u16 wArg06, u16 wArg08, u16 wArg0A)
{
	u16 dx_105;
	u16 dx_106;
	u16 dx_107;
	u16 dx_108;
	fn1AB8_1AF6(wArg08, wArg06, wArg08, wArg0A, &dx_105);
	fn1AB8_1AF6(wArg04, wArg06, wArg08, wArg06, &dx_106);
	fn1AB8_1AF6(wArg04, wArg0A, wArg04, wArg06, &dx_107);
	fn1AB8_1AF6(wArg08, wArg0A, wArg04, wArg0A, &dx_108);
	return 0x00;
}

/* 1AB8:1175 */
void fn1AB8_1175(u16 wArg04, u16 wArg06)
{
	if (wArg06 > 11)
		LG16(0xB818) = ~0x0A;
	else
	{
		LG16(0xB862) = wArg06;
		LG16(0xB864) = wArg04;
		fn1AB8_1D5B((u8)wArg04, (u8)wArg06);
	}
}

/* 1AB8:11A0 */
void fn1AB8_11A0(u16 wArg04, u8 * ptrArg06)
{
	u8 buf[8];                  /* local [bp-8h], 8 bytes */
	fn1EDA_0953(0x08, buf, ptrArg06);
	if (fn1AB8_1C4A() < wArg04)
		LG16(0xB818) = ~0x0A;
	else
	{
		LG16(0xB862) = 0x0C;
		LG16(0xB864) = wArg04;
		fn1EDA_0953(0x08, g_dgroup + 0xB866, buf);
		fn1AB8_1968((u8)wArg04, buf);
	}
}
