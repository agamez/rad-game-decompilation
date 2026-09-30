// 133F:0256: void fn133F_0256(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06)
// Called from:
//      fn1229_0CCE
void fn133F_0256(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06)
{
	Mem11[ds:0x6CC0:word16] = wArg06;
	Mem13[ds:0x6CC2:word16] = wArg04;
}
