// 1AB8:1F19: void fn1AB8_1F19(Register Eq_17 ds)
// Called from:
//      fn1AB8_1EE3
void fn1AB8_1F19(Eq_17 ds)
{
	byte ah_5;
	byte bh_6;
	word16 bx_84;
	Eq_481 cx_161;
	if (bios_video_get_current_video_mode(out ah_5, out bh_6) != 0x07)
	{
		if (!fn1AB8_200E())
		{
			Mem96[ds:0xB89C:byte] = 0x06;
			return;
		}
		Eq_481 cx_167;
		cx_167.u0 = <invalid>;
		word16 bx_160;
		bx_84 = bx_160;
		cx_161 = cx_167;
		byte cl_169;
		if (fn1AB8_1F80(out cl_169, out bx_160))
		{
			if (fn1AB8_2043() == 0x00)
			{
				Mem74[ds:0xB89C:byte] = 0x01;
				if (!fn1AB8_1FED())
					Mem82[ds:0xB89C:byte] = 0x02;
				return;
			}
			else
			{
				Mem83[ds:0xB89C:byte] = 0x0A;
				return;
			}
		}
	}
	else
	{
		Eq_481 cx_166;
		cx_166.u0 = <invalid>;
		word16 bx_159;
		bx_84 = bx_159;
		cx_161 = cx_166;
		byte cl_168;
		if (!fn1AB8_1F80(out cl_168, out bx_159))
		{
			if (fn1AB8_2011() == 0x00)
			{
				word16 ax_38 = ~B800:0000;
				B800:0000 = (word16 *) ~B800:0000;
				if (ax_38 == B800:0000)
					Mem44[ds:0xB89C:byte] = 0x01;
				return;
			}
			else
			{
				Mem45[ds:0xB89C:byte] = 0x07;
				return;
			}
		}
	}
	fn1AB8_1F9E((byte) cx_161, bx_84, ds);
}
