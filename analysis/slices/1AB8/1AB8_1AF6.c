// 1AB8:1AF6: Register byte fn1AB8_1AF6(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08, Stack Eq_17 wArg0A, Register out word16 dxOut)
// Called from:
//      fn0800_0D20
//      fn0800_1315
//      fn0800_19E1
//      fn0800_36E6
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
//      fn133F_0352
//      fn1AB8_112E
byte fn1AB8_1AF6(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06, Eq_17 wArg08, Eq_17 wArg0A, word16 & dxOut)
{
	Mem7[ds:0xB820:segptr32]();
	word16 dx_19;
	dxOut = dx_19;
	word16 ax_16;
	return SLICE(ax_16, byte, 8);
}
