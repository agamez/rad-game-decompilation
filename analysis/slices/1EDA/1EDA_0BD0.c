// 1EDA:0BD0: void fn1EDA_0BD0(Stack ci16 wArg04, Stack uint16 wArg06, Stack Eq_17 ptrArg08)
// Called from:
//      fn0800_0D20
//      fn1229_0040
void fn1EDA_0BD0(ci16 wArg04, uint16 wArg06, Eq_17 ptrArg08)
{
	if (wArg04 > 0x00)
	{
		Eq_17 ptrLoc0206_130;
		<unknown> Eq_64631::* fp;
		ptrLoc0206_130.u3 = fp - 0x0102;
		fn1EDA_0A6B(wArg06 - 0x01, 0x01, ptrArg08, ptrLoc0206_130);
		Eq_17 ptrLoc020A_138;
		ptrLoc020A_138.u3 = fp - 0x0202;
		fn1EDA_0A6B(0xFF, wArg06 + wArg04, ptrArg08, ptrLoc020A_138);
		fn1EDA_0AAC(ptrLoc020A_138, ptrLoc0206_130);
		word16 dx_172;
		fn1EDA_0A39(~0x00, ptrArg08, ptrLoc0206_130, out dx_172);
	}
}
