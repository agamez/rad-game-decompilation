// 1EDA:00E2: Register Eq_17 fn1EDA_00E2(Register Eq_17 ax, Stack Eq_17 wArg00, Stack Eq_17 wArg02, Register out Eq_17 cxOut, Register out word16 dxOut, Register out word16 bxOut, Register out (ptr16 Eq_62593) dsOut)
// Called from:
//      fn1EDA_023F
//      fn1EDA_0254
//      fn1EDA_04A9
//      fn1EDA_04B7
//      fn1EDA_098A
Eq_17 fn1EDA_00E2(Eq_17 ax, Eq_17 wArg00, Eq_17 wArg02, union Eq_17 & cxOut, word16 & dxOut, word16 & bxOut, struct Eq_62593 & dsOut)
{
	struct Eq_62593 * ds_14 = fn1EDA_00ED(ax, wArg00, wArg02);
	cxOut = wArg00;
	word16 dx_15;
	dxOut = dx_15;
	word16 bx_13;
	bxOut = bx_13;
	dsOut = ds_14;
	Eq_17 ax_12;
	return ax_12;
}
