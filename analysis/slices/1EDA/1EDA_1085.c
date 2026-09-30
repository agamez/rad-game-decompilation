// 1EDA:1085: Register word16 fn1EDA_1085(Register byte al, Register Eq_17 ds, Stack Eq_17 ptrArg08)
// Called from:
//      fn0800_01FE
//      fn0800_11EF
//      fn0800_2401
//      fn0800_2827
//      fn1229_039D
//      fn1229_0486
word16 fn1EDA_1085(byte al, Eq_17 ds, Eq_17 ptrArg08)
{
	Eq_17 ax_8 = SEQ(0x3F, al);
	return fn1EDA_1091(ax_8, 100, ds, ptrArg08);
}
