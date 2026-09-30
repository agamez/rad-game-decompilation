// 1AB8:1AA6: void fn1AB8_1AA6(Register Eq_17 ds, Stack Eq_58058 ptrArg04)
// Called from:
//      fn1AB8_0BAE
void fn1AB8_1AA6(Eq_17 ds, Eq_58058 ptrArg04)
{
	fn1AB8_180A(ds);
	Mem21[ds:~0x4760:ptr32] = ptrArg04;
	Mem21[ds:0xB820:segptr32]();
}
