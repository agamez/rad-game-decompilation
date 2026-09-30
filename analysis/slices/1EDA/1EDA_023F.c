// 1EDA:023F: Sequence word32 fn1EDA_023F(Register Eq_17 ds, Stack Eq_17 wArg00, Stack Eq_17 wArg02, Stack Eq_17 wArg04, Register out Eq_17 dsOut)
// Called from:
//      fn0800_0147
//      fn0800_03F8
//      fn0800_0D20
//      fn0C43_00B9
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
word32 fn1EDA_023F(Eq_17 ds, Eq_17 wArg00, Eq_17 wArg02, Eq_17 wArg04, union Eq_17 & dsOut)
{
	Eq_17 ds_29;
	word16 bx_58;
	word16 dx_30;
	word16 cx_57;
	word16 ax_11;
	word16 dx_15;
	if (fn1EDA_0308(wArg04, ds, out ax_11, out dx_15))
	{
		int16 ax_26 = fn1EDA_00E2(0xCB, wArg00, wArg02, out cx_57, out dx_30, out bx_58, out ds_29);
		dsOut = ds_29;
		return SEQ(dx_30, ax_26);
	}
	else
	{
		dsOut = ds;
		return SEQ(dx_15, ax_11);
	}
}
