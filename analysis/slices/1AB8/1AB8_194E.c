// 1AB8:194E: void fn1AB8_194E(Register Eq_17 ds, Stack uint8 bArg04)
// Called from:
//      fn1AB8_0AEE
void fn1AB8_194E(Eq_17 ds, uint8 bArg04)
{
	uint16 ax_15 = (uint16) bArg04;
	Mem16[ds:0xB820:segptr32]();
	fn1AB8_1807();
}
