// 1AB8:1968: void fn1AB8_1968(Register Eq_17 ds, Stack byte bArg04, Stack segptr32 ptrArg06)
// Called from:
//      fn1AB8_11A0
void fn1AB8_1968(Eq_17 ds, byte bArg04, segptr32 ptrArg06)
{
	Mem11[ds:47167:byte] = bArg04;
	Mem11[ds:0xB820:segptr32]();
	Mem17[ds:47170:byte] = 0x0C;
	Mem17[ds:0xB820:segptr32]();
}
