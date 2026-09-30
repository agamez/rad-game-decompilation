// 1AB8:1D82: Register byte fn1AB8_1D82(Register Eq_17 ds, Stack Eq_17 ptrArg04, Stack Eq_17 wArg08, Stack Eq_17 wArg0A, Register out byte chOut)
// Called from:
//      fn0800_04E3
//      fn0800_0619
//      fn0800_0768
//      fn0800_0AA1
//      fn0800_0B42
//      fn0800_0BEC
//      fn0800_0D20
//      fn0800_149F
//      fn0800_166D
//      fn0800_184C
//      fn0800_19E1
//      fn0800_1E3F
//      fn0800_2004
//      fn0800_21E7
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
//      fn0800_391E
//      fn0800_3D9D
//      fn0800_4255
//      fn0C74_011E
//      fn0C74_020C
//      fn1229_0040
//      fn1229_0AA8
//      fn133F_014B
//      fn1AB8_1492
byte fn1AB8_1D82(Eq_17 ds, Eq_17 ptrArg04, Eq_17 wArg08, Eq_17 wArg0A, byte & chOut)
{
	Mem7[ds:0xB820:segptr32]();
	Mem7[ds:0xB820:segptr32]();
	byte ch_33;
	chOut = ch_33;
	word16 ax_30;
	return SLICE(ax_30, byte, 8);
}
