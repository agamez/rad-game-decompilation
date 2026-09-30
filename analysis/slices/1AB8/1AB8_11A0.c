// 1AB8:11A0: void fn1AB8_11A0(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 ptrArg06)
// Called from:
//      fn1AB8_0AEE
//      fn1AB8_1028
void fn1AB8_11A0(Eq_17 ds, Eq_17 wArg04, Eq_17 ptrArg06)
{
	<unknown> Eq_60046::* fp;
	fn1EDA_0953(0x08, fp - 0x0A, ptrArg06);
	if (fn1AB8_1C4A(ds) < wArg04)
		Mem81[ds:0xB818:word16] = ~0x0A;
	else
	{
		Mem44[ds:47202:word16] = 0x0C;
		Mem46[ds:47204:word16] = wArg04;
		fn1EDA_0953(0x08, SEQ(ds, 0xB866), fp - 0x0A);
		fn1AB8_1968(ds, (byte) wArg04, fp - 0x0A);
	}
}
