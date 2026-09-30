// 1AB8:1E0B: Register word16 fn1AB8_1E0B(Register Eq_17 ds, Stack Eq_17 ptrArg04)
// Called from:
//      fn0800_0D20
//      fn0800_19E1
//      fn1229_0040
//      fn133F_014B
//      fn1AB8_1492
word16 fn1AB8_1E0B(Eq_17 ds, Eq_17 ptrArg04)
{
	Mem7[ds:0xB820:segptr32]();
	word16 bx_22;
	return bx_22;
}
