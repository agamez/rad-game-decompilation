// 1AB8:1D5B: void fn1AB8_1D5B(Register Eq_17 ds, Stack byte bArg04, Stack byte bArg06)
// Called from:
//      fn1AB8_1175
void fn1AB8_1D5B(Eq_17 ds, byte bArg04, byte bArg06)
{
	Mem11[ds:47167:byte] = bArg04;
	Mem11[ds:0xB820:segptr32]();
	Mem19[ds:47170:byte] = bArg06;
	Mem19[ds:0xB820:segptr32]();
}
