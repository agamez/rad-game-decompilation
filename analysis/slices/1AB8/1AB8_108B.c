// 1AB8:108B: void fn1AB8_108B(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06)
// Called from:
//      fn0800_0D20
//      fn1229_0040
//      fn1AB8_0AEE
//      fn1AB8_0F80
//      fn1AB8_0F93
//      fn1AB8_1028
//      fn1AB8_1492
void fn1AB8_108B(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06)
{
	fn1AB8_1ACE(ds, wArg04, wArg06);
	Mem21[ds:0xB844:word16] = wArg06;
	Mem23[ds:47174:word16] = wArg04;
}
