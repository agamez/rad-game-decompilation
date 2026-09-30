// 1AB8:13A3: Register word16 fn1AB8_13A3(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08, Stack Eq_17 wArg0A)
// Called from:
//      fn0800_0147
//      fn0800_03F8
//      fn0800_0D20
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
word16 fn1AB8_13A3(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06, Eq_17 wArg08, Eq_17 wArg0A)
{
	word16 ax_24 = fn1AB8_19A6(ds, wArg04, wArg06, wArg08, wArg0A);
	if (ax_24 == ~0x00)
		Mem37[ds:0xB818:word16] = ~0x0A;
	return ax_24;
}
