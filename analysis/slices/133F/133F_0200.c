// 133F:0200: void fn133F_0200(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08, Stack Eq_17 wArg0A)
// Called from:
//      fn1229_0CCE
//      fn133F_04B1
void fn133F_0200(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06, Eq_17 wArg08, Eq_17 wArg0A)
{
	Mem11[ds:0x6CC8:word16] = wArg0A;
	Mem13[ds:0x6CCA:word16] = wArg08;
	Mem15[ds:0x6CCC:word16] = wArg06;
	Mem17[ds:0x6CCE:word16] = wArg04;
}
