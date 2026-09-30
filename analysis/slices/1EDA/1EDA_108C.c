// 1EDA:108C: void fn1EDA_108C(Register byte al, Register Eq_17 ds, Stack Eq_17 ptrArg08)
// Called from:
//      fn0800_31B7
//      fn1229_0735
void fn1EDA_108C(byte al, Eq_17 ds, Eq_17 ptrArg08)
{
	Eq_17 ax_8 = SEQ(0x40, al);
	fn1EDA_1091(ax_8, 101, ds, ptrArg08);
}
