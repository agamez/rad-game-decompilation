// 1AB8:1CA4: void fn1AB8_1CA4(Register Eq_17 ds, Stack byte bArg04)
// Called from:
//      fn1AB8_1250
void fn1AB8_1CA4(Eq_17 ds, byte bArg04)
{
	Mem7[ds:0xB820:segptr32]();
}
