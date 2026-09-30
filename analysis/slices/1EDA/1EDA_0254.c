// 1EDA:0254: Register int16 fn1EDA_0254(Register Eq_17 ds, Stack Eq_17 wArg00, Stack Eq_17 wArg02, Stack Eq_17 wArg04, Stack Eq_17 ptrArg06, Register out word16 dxOut, Register out Eq_17 dsOut)
// Called from:
//      fn0800_03F8
//      fn0800_0D20
//      fn0C43_0095
//      fn0C74_03D4
//      fn0C74_05B8
//      fn0C74_0E2E
//      fn0C74_0FA1
//      fn0C74_1B3B
//      fn0C74_1D95
//      fn0C74_1F08
//      fn0C74_2AD9
//      fn0C74_2BBD
//      fn0C74_2E5A
//      fn0C74_3236
//      fn0C74_4DAC
//      fn0C74_4FD7
//      fn0C74_5258
//      fn1229_0040
int16 fn1EDA_0254(Eq_17 ds, Eq_17 wArg00, Eq_17 wArg02, Eq_17 wArg04, Eq_17 ptrArg06, word16 & dxOut, union Eq_17 & dsOut)
{
	Eq_17 ds_35;
	word16 bx_67;
	word16 dx_36;
	word16 cx_66;
	int16 ax_16;
	word16 dx_20;
	if (fn1EDA_03D3(ptrArg06, wArg04, ds, out ax_16, out dx_20))
	{
		int16 ax_32 = fn1EDA_00E2(0xCC, wArg00, wArg02, out cx_66, out dx_36, out bx_67, out ds_35);
		dxOut = dx_36;
		dsOut = ds_35;
		return ax_32;
	}
	else
	{
		dxOut = dx_20;
		dsOut = ds;
		return ax_16;
	}
}
