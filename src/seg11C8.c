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

// 11C8:0000: void audio_transfer_rom_data(u8 bArg02, u16 wArg04, u8 * ptrArg06)
/* was fn11C8_0000 */
void audio_transfer_rom_data(u8 bArg02, u16 wArg04, u8 * ptrArg06)
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
			renamed_1eda_0b4f(LG8((u16)(wArg04 & 0x0F) + 0x4DC4), buf1);
			renamed_1eda_0b7c(0x01, 0xFF, buf2, buf1);
			wArg04 >>= 0x04;
			if (bLoc03_111 == bArg02)
				break;
			++bLoc03_111;
		}
	}
	renamed_1eda_0a39(0xFF, ptrArg06, buf2, &dx_146);
}

// 11C8:0092: void audio_detect_and_init_sb(void)
/* was fn11C8_0092 */
void audio_detect_and_init_sb(void)
{
	u8 buf[0x100];
	u8 bLoc0F_324 = 0x00;
	u8 bLoc03_325 = 0x01;

	renamed_1e78_01c0();
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

			renamed_1eda_08ce(0x00, &g_seg11C8[0x71], &g_dgroup[0xB9BC], &cx_586);
			audio_transfer_rom_data(0x03, LG16(0x5978), buf);
			renamed_1eda_08ce(0x00, buf, &g_dgroup[0xB9BC], &cx_587);
			renamed_1eda_086c(&g_dgroup[0xB9BC]);
			LG8(0x5976) = 0x01;
		}
		else
			++bLoc03_325;
	}
	if (bLoc0F_324 == 0x00)
		LG8(0x5976) = 0x00;
}

// 11C8:0236: u16 audio_write_adlib_port(u8 bArg04)
/* was fn11C8_0236 */
u16 audio_write_adlib_port(u8 bArg04)
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

// 11C8:0282: void audio_write_adlib_address(u8 bArg02)
/* was fn11C8_0282 */
void audio_write_adlib_address(u8 bArg02)
{
	u16 cx_11;

	pal_outport(0x0388, bArg02);
	for (cx_11 = 0x06; cx_11 != 0x00; --cx_11)
		(void)pal_inport(0x0388);
}

// 11C8:0296: void audio_write_adlib_data(u8 bArg02)
/* was fn11C8_0296 */
void audio_write_adlib_data(u8 bArg02)
{
	u16 cx_11;

	pal_outport(0x0389, bArg02);
	for (cx_11 = 0x35; cx_11 != 0x00; --cx_11)
		(void)pal_inport(0x0388);
}

// 11C8:02AB: void audio_sweep_adlib_ports(void)
/* was fn11C8_02AB */
void audio_sweep_adlib_ports(void)
{
	u8 bLoc03_43 = 0x01;

	while (1)
	{
		audio_write_adlib_address(bLoc03_43);
		audio_write_adlib_data(0x00);
		if (bLoc03_43 == 0xF5)
			break;
		++bLoc03_43;
	}
}

// 11C8:02CC: void audio_enable_opl3(void)
/* was fn11C8_02CC */
void audio_enable_opl3(void)
{
	audio_write_adlib_address(0xB0);
	audio_write_adlib_data(0x11);
}

// 11C8:02DB: void audio_write_adlib_register(u8 bArg02, u8 bArg04)
/* was fn11C8_02DB */
void audio_write_adlib_register(u8 bArg02, u8 bArg04)
{
	audio_write_adlib_address(bArg04);
	audio_write_adlib_data(bArg02);
}

// 11C8:02F0: void audio_configure_opl3_mixer(void)
/* was fn11C8_02F0 */
void audio_configure_opl3_mixer(void)
{
	audio_write_adlib_register(0x01, 0x20);
	audio_write_adlib_register(0x10, 0x40);
	audio_write_adlib_register(0xF0, 0x60);
	audio_write_adlib_register(0x77, 0x80);
	audio_write_adlib_register(0x98, 0xA0);
	audio_write_adlib_register(0x01, 0x23);
	audio_write_adlib_register(0x00, 0x43);
	audio_write_adlib_register(0xF0, 0x63);
	audio_write_adlib_register(0x77, 0x83);
	audio_write_adlib_register(0x31, 0xB0);
}

// 11C8:033B: u16 audio_get_soundcard_port(void)
/* was fn11C8_033B */
u16 audio_get_soundcard_port(void)
{
	u16 dx;

	if (LG8(0x5976) == 0x00)
		dx = (u16)renamed_1e78_02f4();
	else
		dx = audio_write_adlib_port(0x00);
	return dx;
}

// 11C8:0354: void audio_write_opl3_register(u16 wArg04)
/* was fn11C8_0354 */
void audio_write_opl3_register(u16 wArg04)
{
	u8 bArg04 = (u8)wArg04;
	u8 bArg05 = (u8)(wArg04 >> 8);

	if (LG8(0x5976) == 0x00)
		renamed_1e78_02c7(wArg04);
	else
	{
		audio_write_adlib_register(bArg04, (u8)(LG8(0x5975) + 0xA0));
		audio_write_adlib_register((u8)(bArg05 | 0x10), (u8)(LG8(0x5975) + 0xB0));
		audio_write_adlib_port(0xC8);
	}
}

// 11C8:0394: void audio_init_soundcard(void)
/* was fn11C8_0394 */
void audio_init_soundcard(void)
{
	audio_detect_and_init_sb();
	if (LG8(0x5976) != 0x00)
	{
		LG8(0x5975) = 0x00;
		audio_sweep_adlib_ports();
		audio_write_adlib_register(0x10, 0x01);
		audio_configure_opl3_mixer();
		audio_get_soundcard_port();
	}
}

// 11C8:03BB: void audio_init_opl3(void)
/* was fn11C8_03BB */
void audio_init_opl3(void)
{
	if (LG8(0x5976) != 0x00)
	{
		audio_enable_opl3();
		audio_sweep_adlib_ports();
	}
}

// 11C8:03CF: void audio_disable_soundcard(void)
/* was fn11C8_03CF */
void audio_disable_soundcard(void)
{
	LG8(0x5976) = 0x00;
}
