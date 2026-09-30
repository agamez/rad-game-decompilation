// 1AB8:1CBA: Register word16 fn1AB8_1CBA(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08, Stack Eq_17 wArg0A)
// Called from:
//      fn0800_3D9D
//      fn0800_4255
//      fn1229_0DCC
//      fn13E2_003B
//      fn13E2_0080
//      fn13E2_00FB
word16 fn1AB8_1CBA(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06, Eq_17 wArg08, Eq_17 wArg0A)
{
	Mem7[ds:0xB820:segptr32]();
	word16 dx_26;
	return dx_26;
}
