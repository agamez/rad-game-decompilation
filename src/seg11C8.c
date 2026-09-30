/* seg11C8.c -- recovered segment 11C8 of RAD V3.1 (AdLib/OPL2 sound engine).
 *
 * Recovered from analysis/reko/RAD_11C8.{c,asm,dis}.  Ground truth = the .asm.
 * Function order = ascending offset; Reko offset comments retained.
 *
 * Hardware replaced (CONVENTIONS.md rule 4): every `in al,dx` / `out dx,al`
 * site became pal_inport()/pal_outport() with the literal port kept:
 *   0x388 AdLib register select / status read, 0x389 AdLib data write.
 *   The dynamic SB DSP ports are g_5978 + {4,5,6,A,C,E} (0x5978 is the
 *   detected Sound Blaster base port); they are preserved literally.
 * No int 10h/int 21h in this segment.
 */

#include "seg11C8.h"
#include "seg1E78.h"
#include "seg1EDA.h"
#include "globals.h"
#include "pal.h"

// 11C8:0000: void fn11C8_0000(u8 bArg02, u16 wArg04, u8 * ptrArg06)
void fn11C8_0000(u8 bArg02, u16 wArg04, u8 * ptrArg06)
{
	u8 buf1[0x102];
	u8 buf2[0x102];
	u8 bLoc03_111;
	u16 dx_146;

	buf2[0] = 0x00;
	if (bArg02 >= 0x01)
	{
		bLoc03_111 = 0x01;
		while (1)
		{
			fn1EDA_0B4F(LG8((u16)(wArg04 & 0x0F) + 0x4DC4), buf1);
			fn1EDA_0B7C(0x01, 0xFF, buf2, buf1);
			wArg04 >>= 0x04;
			if (bLoc03_111 == bArg02)
				break;
			++bLoc03_111;
		}
	}
	fn1EDA_0A39(0xFF, ptrArg06, buf2, &dx_146);
}

// 11C8:0092: void fn11C8_0092(void)
void fn11C8_0092(void)
{
	u8 buf[0x100];
	u8 bLoc0F_324 = 0x00;
	u8 bLoc03_325 = 0x01;

	fn1E78_01C0();
	while (bLoc03_325 < 0x07 && bLoc0F_324 == 0x00)
	{
		u16 wLoc0A_328 = 0x00;
		u8 bLoc10_329 = 0x00;

		LG16(0x5978) = (u16)(((u16)bLoc03_325 << 0x04) + 0x0200);
		wLoc0A_328 = 0x00;
		bLoc10_329 = 0x00;
		while (wLoc0A_328 < 0x0201 && bLoc10_329 == 0x00)
		{
			if ((pal_inport((u16)(LG16(0x5978) + 0x0C)) & 0x80) == 0x00)
				bLoc10_329 = 0x01;
			++wLoc0A_328;
		}
		if (bLoc10_329 != 0x00)
		{
			u8 bLoc03_342 = pal_inport((u16)(LG16(0x5978) + 0x0C));
			u8 bLoc04_342;
			u8 bLoc10_344;
			u8 v23_142;
			u16 wLoc0C_334;

			pal_outport((u16)(LG16(0x5978) + 0x0C), 0xD3);
			for (wLoc0C_334 = 0x01; wLoc0C_334 != 0x1000; ++wLoc0C_334)
				;
			bLoc04_342 = pal_inport((u16)(LG16(0x5978) + 0x06));
			pal_outport((u16)(LG16(0x5978) + 0x06), 0x01);
			(void)pal_inport((u16)(LG16(0x5978) + 0x06));
			(void)pal_inport((u16)(LG16(0x5978) + 0x06));
			(void)pal_inport((u16)(LG16(0x5978) + 0x06));
			(void)pal_inport((u16)(LG16(0x5978) + 0x06));
			pal_outport((u16)(LG16(0x5978) + 0x06), 0x00);
			v23_142 = 0x00;
			do
			{
				u16 wLoc0A_343 = 0x00;

				bLoc10_344 = 0x00;
				while (wLoc0A_343 < 0x0201 && bLoc10_344 == 0x00)
				{
					if ((pal_inport((u16)(LG16(0x5978) + 0x0E)) & 0x80) == 0x80)
						bLoc10_344 = 0x01;
					++wLoc0A_343;
				}
				if (bLoc10_344 != 0x00 && pal_inport((u16)(LG16(0x5978) + 0x0A)) == 0xAA)
					bLoc0F_324 = 0x01;
				++v23_142;
			} while (v23_142 != 0x10 && bLoc10_344 == 0x00);
			if (bLoc10_344 == 0x00)
			{
				pal_outport((u16)(LG16(0x5978) + 0x0C), bLoc03_342);
				pal_outport((u16)(LG16(0x5978) + 0x06), bLoc04_342);
			}
		}
		if (bLoc0F_324 != 0x00)
		{
			u16 cx_586;
			u16 cx_587;

			fn1EDA_08CE(0x00, &g_seg11C8[0x71], &g_dgroup[0xB9BC], &cx_586);
			fn11C8_0000(0x03, LG16(0x5978), buf);
			fn1EDA_08CE(0x00, buf, &g_dgroup[0xB9BC], &cx_587);
			fn1EDA_086C(&g_dgroup[0xB9BC]);
			LG8(0x5976) = 0x01;
		}
		else
			++bLoc03_325;
	}
	if (bLoc0F_324 == 0x00)
		LG8(0x5976) = 0x00;
}

// 11C8:0236: u16 fn11C8_0236(u8 bArg04)
u16 fn11C8_0236(u8 bArg04)
{
	u16 ax_30;

	pal_outport((u16)(LG16(0x5978) + 0x04), 0x04);
	pal_outport((u16)(LG16(0x5978) + 0x05), bArg04);
	pal_outport((u16)(LG16(0x5978) + 0x04), 0x22);
	pal_outport((u16)(LG16(0x5978) + 0x05), bArg04);
	pal_outport((u16)(LG16(0x5978) + 0x04), 0x26);
	ax_30 = LG16(0x5978);
	pal_outport((u16)(ax_30 + 0x05), bArg04);
	return (u16)(ax_30 + 0x05);
}

// 11C8:0282: void fn11C8_0282(u8 bArg02)
void fn11C8_0282(u8 bArg02)
{
	u16 cx_11;

	pal_outport(0x0388, bArg02);
	for (cx_11 = 0x06; cx_11 != 0x00; --cx_11)
		(void)pal_inport(0x0388);
}

// 11C8:0296: void fn11C8_0296(u8 bArg02)
void fn11C8_0296(u8 bArg02)
{
	u16 cx_11;

	pal_outport(0x0389, bArg02);
	for (cx_11 = 0x35; cx_11 != 0x00; --cx_11)
		(void)pal_inport(0x0388);
}

// 11C8:02AB: void fn11C8_02AB(void)
void fn11C8_02AB(void)
{
	u8 bLoc03_43 = 0x01;

	while (1)
	{
		fn11C8_0282(bLoc03_43);
		fn11C8_0296(0x00);
		if (bLoc03_43 == 0xF5)
			break;
		++bLoc03_43;
	}
}

// 11C8:02CC: void fn11C8_02CC(void)
void fn11C8_02CC(void)
{
	fn11C8_0282(0xB0);
	fn11C8_0296(0x11);
}

// 11C8:02DB: void fn11C8_02DB(u8 bArg02, u8 bArg04)
void fn11C8_02DB(u8 bArg02, u8 bArg04)
{
	fn11C8_0282(bArg04);
	fn11C8_0296(bArg02);
}

// 11C8:02F0: void fn11C8_02F0(void)
void fn11C8_02F0(void)
{
	fn11C8_02DB(0x01, 0x20);
	fn11C8_02DB(0x10, 0x40);
	fn11C8_02DB(0xF0, 0x60);
	fn11C8_02DB(0x77, 0x80);
	fn11C8_02DB(0x98, 0xA0);
	fn11C8_02DB(0x01, 0x23);
	fn11C8_02DB(0x00, 0x43);
	fn11C8_02DB(0xF0, 0x63);
	fn11C8_02DB(0x77, 0x83);
	fn11C8_02DB(0x31, 0xB0);
}

// 11C8:033B: u16 fn11C8_033B(void)
u16 fn11C8_033B(void)
{
	u16 dx;

	if (LG8(0x5976) == 0x00)
		dx = (u16)fn1E78_02F4();
	else
		dx = fn11C8_0236(0x00);
	return dx;
}

// 11C8:0354: void fn11C8_0354(u16 wArg04)
void fn11C8_0354(u16 wArg04)
{
	u8 bArg04 = (u8)wArg04;
	u8 bArg05 = (u8)(wArg04 >> 8);

	if (LG8(0x5976) == 0x00)
		fn1E78_02C7(wArg04);
	else
	{
		fn11C8_02DB(bArg04, (u8)(LG8(0x5975) + 0xA0));
		fn11C8_02DB((u8)(bArg05 | 0x10), (u8)(LG8(0x5975) + 0xB0));
		fn11C8_0236(0xC8);
	}
}

// 11C8:0394: void fn11C8_0394(void)
void fn11C8_0394(void)
{
	fn11C8_0092();
	if (LG8(0x5976) != 0x00)
	{
		LG8(0x5975) = 0x00;
		fn11C8_02AB();
		fn11C8_02DB(0x10, 0x01);
		fn11C8_02F0();
		fn11C8_033B();
	}
}

// 11C8:03BB: void fn11C8_03BB(void)
void fn11C8_03BB(void)
{
	if (LG8(0x5976) != 0x00)
	{
		fn11C8_02CC();
		fn11C8_02AB();
	}
}

// 11C8:03CF: void fn11C8_03CF(void)
void fn11C8_03CF(void)
{
	LG8(0x5976) = 0x00;
}
