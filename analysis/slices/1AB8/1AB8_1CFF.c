// 1AB8:1CFF: void fn1AB8_1CFF(Register Eq_17 ds, Stack byte bArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08)
// Called from:
//      fn1AB8_10F4
void fn1AB8_1CFF(Eq_17 ds, byte bArg04, Eq_17 wArg06, Eq_17 wArg08)
{
	Mem12[ds:0xB841:byte] = SLICE(wArg08, byte, 0);
	Mem15[ds:47262:byte] = bArg04;
	Mem15[ds:0xB820:segptr32]();
}
