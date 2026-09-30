// 1EDA:0D80: Register uint16 fn1EDA_0D80(Register Eq_17 ds, Stack Eq_3872 wArg04, Register out uint16 dxOut)
// Called from:
//      fn0800_149F
//      fn0800_166D
//      fn0C74_076B
//      fn0C74_0A35
uint16 fn1EDA_0D80(Eq_17 ds, Eq_3872 wArg04, uint16 & dxOut)
{
	uint16 dx_32 = fn1EDA_0DCF(ds);
	uint16 ax_13 = 0x00;
	if (wArg04 != 0x00)
	{
		uint32 dx_ax_26 = (uint32) dx_32;
		dx_32 = dx_ax_26 /u wArg04;
		ax_13 = dx_ax_26 % wArg04;
	}
	dxOut = dx_32;
	return ax_13;
}
