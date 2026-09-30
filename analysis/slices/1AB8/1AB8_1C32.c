// 1AB8:1C32: Register byte fn1AB8_1C32(Register Eq_17 ds, Stack Eq_17 bArg04)
// Called from:
//      fn0800_04E3
//      fn0800_0619
//      fn0800_0768
//      fn0800_09C2
//      fn0800_0AA1
//      fn0800_0B42
//      fn0800_0BEC
//      fn0800_0D20
//      fn0800_1315
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
//      fn0800_36E6
//      fn0800_391E
//      fn0800_3CFA
//      fn0800_3D9D
//      fn0C74_011E
//      fn0C74_020C
//      fn0C74_0FA1
//      fn0C74_1F08
//      fn0C74_2BBD
//      fn0C74_2E5A
//      fn0C74_3236
//      fn0C74_396E
//      fn0C74_3F74
//      fn0C74_45CE
//      fn0C74_4999
//      fn0C74_4DAC
//      fn0C74_4FD7
//      fn0C74_5258
//      fn1229_0040
//      fn1229_061B
//      fn1229_0735
//      fn1229_0CCE
//      fn133F_0056
//      fn1AB8_0AEE
byte fn1AB8_1C32(Eq_17 ds, Eq_17 bArg04)
{
	Mem11[ds:47166:byte] = bArg04;
	Mem11[ds:0xB820:segptr32]();
	byte ah_16;
	return ah_16;
}
