// 1AB8:1E9F: Register word16 fn1AB8_1E9F(Register Eq_17 ds, Stack byte bArg04, Stack Eq_17 ptrArg06, Stack Eq_17 wArg0A, Stack Eq_17 wArg0C)
// Called from:
//      fn1AB8_13D7
word16 fn1AB8_1E9F(Eq_17 ds, byte bArg04, Eq_17 ptrArg06, Eq_17 wArg0A, Eq_17 wArg0C)
{
	Mem7[ds:0xB820:segptr32]();
	word16 dx_17;
	return dx_17;
}
