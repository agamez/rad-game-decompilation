// 1AB8:1992: void fn1AB8_1992(Register Eq_17 ds, Stack byte bArg04, Stack byte bArg06)
// Called from:
//      fn1AB8_14F4
void fn1AB8_1992(Eq_17 ds, byte bArg04, byte bArg06)
{
	Mem7[ds:0xB820:segptr32]();
}
