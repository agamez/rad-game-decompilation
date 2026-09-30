// 0800:08E9: Register int16 fn0800_08E9(Register int16 dx, Register Eq_17 ds)
// Called from:
//      fn0800_0C71
int16 fn0800_08E9(int16 dx, Eq_17 ds)
{
	uint8 bLoc04_166 = 0x00;
	while (true)
	{
		uint8 bLoc03_167 = 0x00;
		int16 dx_134;
		while (true)
		{
			byte dh_156 = SLICE(dx, byte, 8);
			Eq_17 wLoc08;
			if (fn1E78_02FB(ds) != 0x00)
			{
				dh_156 = SLICE(dx_134, byte, 8);
				if ((byte) fn1E78_030D(dx, ds, wLoc08, out dx_134) == 0x1B)
				{
					Mem144[ds:22707:byte] = 0x01;
					return dx_134;
				}
			}
			Eq_17 ax_51 = (uint16) bLoc03_167 *s 22 + 0x01;
			wLoc08 = ax_51;
			byte dl_67;
			dx = SEQ(dh_156, dl_67);
			if (fn1AB8_1E3C(ds, (uint16) bLoc04_166 *s 22 + 0x01, ax_51, out dl_67) == 0x0F)
			{
				Eq_17 ax_80 = (uint16) bLoc03_167 *s 22 + 0x01;
				wLoc08 = ax_80;
				dx = fn0C74_076B(ds, (uint16) bLoc04_166 *s 22 + 22, (uint16) bLoc03_167 *s 22 + 22, (uint16) bLoc04_166 *s 22 + 0x01, ax_80);
			}
			if (bLoc03_167 == 0x1D)
				break;
			++bLoc03_167;
		}
		if (bLoc04_166 == 0x11)
		{
			dx_134 = fn0C74_0A35(ds);
			return dx_134;
		}
		++bLoc04_166;
	}
}
