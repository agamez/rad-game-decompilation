// 1229:09F9: void fn1229_09F9(Stack Eq_17 bArg02, Stack Eq_17 ptrArg04)
// Called from:
//      fn1229_0AA8
void fn1229_09F9(Eq_17 bArg02, Eq_17 ptrArg04)
{
	<unknown> Eq_53484::* fp;
	fn1EDA_0F26(0xFF, fp - 0x0102, 0x00, (uint32) bArg02);
	struct Eq_53501 * cs;
	if (bArg02 < 0x0A)
	{
		Eq_17 dwLoc0206_221;
		dwLoc0206_221.u3 = fp - 0x0202;
		fn1EDA_0A1F(&cs->t09F7, dwLoc0206_221);
		fn1EDA_0AAC(fp - 0x0102, dwLoc0206_221);
		word16 dx_262;
		fn1EDA_0A39(~0x00, fp - 0x0102, dwLoc0206_221, out dx_262);
	}
	if (bArg02 < 100)
	{
		Eq_17 dwLoc0206_235;
		dwLoc0206_235.u3 = fp - 0x0202;
		fn1EDA_0A1F(&cs->t09F7, dwLoc0206_235);
		fn1EDA_0AAC(fp - 0x0102, dwLoc0206_235);
		word16 dx_264;
		fn1EDA_0A39(~0x00, fp - 0x0102, dwLoc0206_235, out dx_264);
	}
	word16 dx_263;
	fn1EDA_0A39(~0x00, ptrArg04, fp - 0x0102, out dx_263);
}
