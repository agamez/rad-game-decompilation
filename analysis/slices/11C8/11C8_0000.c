/* was audio_transfer_rom_data */
// 11C8:0000: void audio_transfer_rom_data(Register Eq_17 ds, Stack cu8 bArg02, Stack uint16 wArg04, Stack Eq_17 ptrArg06)
// Called from:
//      audio_detect_and_init_sb
/* was audio_transfer_rom_data */
void audio_transfer_rom_data(Eq_17 ds, cu8 bArg02, uint16 wArg04, Eq_17 ptrArg06)
{
	<unknown> Eq_50490::* fp;
	if (bArg02 >= 0x01)
	{
		cu8 bLoc03_111 = 0x01;
		while (true)
		{
			Eq_17 ptrLoc020A_116;
			ptrLoc020A_116.u3 = fp - 0x0206;
			fn1EDA_0B4F(ds->*((word16) (wArg04 & 0x0F) + 0x00004DC4), ptrLoc020A_116);
			fn1EDA_0B7C(0x01, 0xFF, fp - 0x0104, ptrLoc020A_116);
			wArg04 >>= 0x04;
			if (bLoc03_111 == bArg02)
				break;
			++bLoc03_111;
		}
	}
	word16 dx_146;
	fn1EDA_0A39(~0x00, ptrArg06, fp - 0x0104, out dx_146);
}
