// 1EDA:04A9: Sequence ui32 fn1EDA_04A9(Register Eq_17 ds, Stack Eq_17 wArg00, Stack Eq_17 wArg02, Register out byte chOut, Register out Eq_17 dsOut)
// Called from:
//      fn0800_11EF
//      fn0800_2C0C
//      fn0800_31B7
//      fn0800_391E
//      fn0800_4168
//      fn0C43_00B9
//      fn1229_0486
//      fn1229_0735
//      fn1AB8_008B
ui32 fn1EDA_04A9(Eq_17 ds, Eq_17 wArg00, Eq_17 wArg02, byte & chOut, union Eq_17 & dsOut)
{
	Eq_17 ds_14;
	word16 bx_46;
	ui16 dx_15;
	word16 cx_13;
	if (Mem0[ds:0x5380:word16] != 0x00)
	{
		Eq_17 ax_8 = Mem0[ds:0x5380:word16];
		int16 ax_11 = fn1EDA_00E2(ax_8, wArg00, wArg02, out cx_13, out dx_15, out bx_46, out ds_14);
		chOut = <invalid>;
		dsOut = ds_14;
		return SEQ(dx_15, ax_11);
	}
	else
	{
		chOut = <invalid>;
		dsOut = ds;
		ui32 dx_ax;
		return dx_ax;
	}
}
