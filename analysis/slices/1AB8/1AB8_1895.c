// 1AB8:1895: Register word16 fn1AB8_1895(Register Eq_17 ds, Stack byte bArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08, Stack Eq_17 wArg0A, Stack Eq_17 wArg0C)
// Called from:
//      fn1AB8_0F93
word16 fn1AB8_1895(Eq_17 ds, byte bArg04, Eq_17 wArg06, Eq_17 wArg08, Eq_17 wArg0A, Eq_17 wArg0C)
{
	Mem7[ds:0xB820:segptr32]();
	word16 dx_32;
	return dx_32;
}
