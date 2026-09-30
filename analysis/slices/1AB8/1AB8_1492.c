// 1AB8:1492: void fn1AB8_1492(Register Eq_17 ds, Stack Eq_17 ptrArg04)
// Called from:
//      fn0800_0D20
//      fn1229_0040
void fn1AB8_1492(Eq_17 ds, Eq_17 ptrArg04)
{
	<unknown> Eq_60369::* fp;
	word16 dx_157;
	fn1EDA_0A39(~0x00, fp - 0x0102, ptrArg04, out dx_157);
	byte ch_158;
	fn1AB8_1D82(ds, fp - 0x0102, Mem42[ds:47174:word16], Mem25[ds:0xB844:word16], out ch_158);
	if (Mem50[ds:0xB892:word16] == 0x00 && Mem50[ds:0xB88E:word16] == 0x00)
	{
		struct Eq_60369 * ss;
		fn1AB8_108B(ds, Mem95[ds:47174:word16], Mem70[ds:0xB844:word16] + fn1AB8_1E0B(ds, SEQ(ss, fp - 0x0102)));
	}
}
