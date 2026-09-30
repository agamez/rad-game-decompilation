// 0C74:2BBD: Register Eq_17 fn0C74_2BBD(Register Eq_17 ds, Stack Eq_17 wArg02, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08)
// Called from:
//      fn0C74_2E5A
//      fn0C74_3236
//      fn0C74_5258
Eq_17 fn0C74_2BBD(Eq_17 ds, Eq_17 wArg02, Eq_17 wArg04, Eq_17 wArg06, Eq_17 wArg08)
{
	byte dl_952;
	Eq_17 ds_83;
	Eq_17 ds_65;
	Eq_17 ax_23 = fn1AB8_13A3(ds, wArg02, wArg04, wArg06, wArg08);
	Eq_17 ax_46 = fn1AB8_13A3(ds, wArg06, wArg04, wArg06, wArg08);
	Eq_17 dx_ax_949 = fn1EDA_023F(ds, wArg04, wArg06, ax_23, out ds_65);
	Eq_17 dx_ax_948 = fn1EDA_023F(ds_65, wArg04, wArg06, ax_46, out ds_83);
	fn1AB8_1E6B(ds_83, dx_ax_948, wArg06, wArg04, wArg06, wArg08);
	fn1AB8_1C32(ds_83, 0x00);
	word16 dx_950;
	fn1AB8_1AF6(ds_83, wArg06, wArg04, wArg06, wArg08, out dx_950);
	fn1AB8_1E6B(ds_83, dx_ax_949, wArg02, wArg04, wArg06, wArg08);
	fn1AB8_13D7(ds_83, 0x00, dx_ax_948, wArg06, wArg08);
	Eq_17 ax_79 = (word16) dx_ax_948;
	word16 dx_951;
	Eq_17 ds_218;
	fn1EDA_0254(ds_83, 0x00, ax_79, ax_46, dx_ax_948, out dx_951, out ds_218);
	Eq_17 ax_61 = (word16) dx_ax_949;
	Eq_17 wLoc1C_753 = ax_79;
	Eq_17 al_245 = (byte) fn1AB8_1E3C(ds_218, wArg02, (word32) wArg08 + 11, out dl_952);
	uint16 wLoc10_763 = 0x00;
	byte dl_955;
	while (fn1AB8_1E3C(ds_218, &wArg02.u3->t0001.u0, (word32) wArg08 + 11, out dl_955) == 0x00)
	{
		word16 dx_953;
		fn1E78_029C(ds_218, CONVERT(Mem265[ds_218:22758:word16], int16, int32) /16 0x04, out dx_953);
		Eq_17 v50_303;
		v50_303.u3 = &wArg06.u3->t0001.u0;
		fn1AB8_13D7(ds_218, 0x00, dx_ax_949, v50_303, wArg08);
		Eq_17 v51_305;
		v51_305.u3 = &wArg02.u3->t0001.u0;
		wArg06 = v50_303;
		wArg02 = v51_305;
		++wLoc10_763;
		wLoc1C_753 = ax_61;
		if (v51_305 == 0x0176 && al_245 == 0x0F)
		{
			Eq_17 bLoc14_782;
			bLoc14_782.u0 = 0x0F;
			while (true)
			{
				uint8 bLoc13_783 = 0x00;
				while (true)
				{
					uint8 bLoc12_784 = 0x01;
					while (true)
					{
						if (Mem349[ds_218:0x58B0:byte] != 0x00)
							fn11C8_0354(ds_218, (uint16) bLoc12_784 * (((uint16) bLoc13_783 + 0x01) * (uint16) bLoc14_782));
						word16 dx_956;
						fn1E78_029C(ds_218, 0x01, out dx_956);
						if ((int32) bLoc12_784 % 0x03 == 0x00)
							fn1AB8_1E54(ds_218, bLoc14_782, (uint16) bLoc12_784 + 0x0161, &wArg08.u3->t0000.u0 + (uint16) bLoc13_783);
						else
							fn1AB8_1E54(ds_218, bLoc14_782 - 0x08, (uint16) bLoc12_784 + 0x0161, &wArg08.u3->t0000.u0 + (uint16) bLoc13_783);
						if ((int32) bLoc12_784 % 0x03 == 0x00)
							fn1AB8_1E54(ds_218, bLoc14_782, (uint16) bLoc12_784 + 0x0161, (word32) wArg08 + 21 - (uint16) bLoc13_783);
						else
							fn1AB8_1E54(ds_218, bLoc14_782 - 0x08, (uint16) bLoc12_784 + 0x0161, (word32) wArg08 + 21 - (uint16) bLoc13_783);
						if (bLoc12_784 == 0x15)
							break;
						++bLoc12_784;
					}
					if (bLoc13_783 == 0x0A)
						break;
					++bLoc13_783;
				}
				if (bLoc14_782 == 0x08)
					break;
				--bLoc14_782;
			}
			fn1AB8_1C32(ds_218, al_245);
			word16 dx_957;
			fn1AB8_1AF6(ds_218, v51_305, wArg04, v51_305, wArg08, out dx_957);
			fn1AB8_1C32(ds_218, 0x0A);
			word16 dx_958;
			fn1AB8_1AF6(ds_218, 0x0161, wArg04, 0x0161, wArg08, out dx_958);
			fn11C8_033B(ds_218);
			wLoc1C_753.u0 = 0x0161;
		}
	}
	word16 dx_954;
	Eq_17 ds_649;
	fn1EDA_0254(ds_218, 0x00, wLoc1C_753, ax_23, dx_ax_949, out dx_954, out ds_649);
	if (CONVERT(Mem636[ds_649:0x4D0A:byte], uint8, uint16) <u wLoc10_763 && wArg02 < 0x0172)
		fn0C74_076B(ds_649, (word32) wArg02 + 22, wArg04, wArg06, wArg08);
	return ds_649;
}
