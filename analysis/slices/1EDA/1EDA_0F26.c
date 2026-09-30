// 1EDA:0F26: void fn1EDA_0F26(Stack ci16 wArg04, Stack (ptr32 byte) ptrArg06, Stack ci16 wArg0A, Stack Eq_17 dwArg0C)
// Called from:
//      fn0C74_004B
//      fn1229_09F9
//      fn133F_026B
//      fn13C1_0036
//      fn1AB8_0000
void fn1EDA_0F26(ci16 wArg04, byte * ptrArg06, ci16 wArg0A, Eq_17 dwArg0C)
{
	struct Eq_64770 * ss;
	Eq_65027 tLoc22;
	ci16 cx_21 = fn1EDA_0E14(dwArg0C, &tLoc22, ss);
	struct Eq_65032 * es_61 = SLICE(ptrArg06, selector, 16);
	word16 di_65 = (word16) ptrArg06;
	ci16 ax_181 = wArg0A;
	if (wArg0A > wArg04)
		ax_181 = wArg04;
	if (cx_21 > wArg04)
		cx_21 = wArg04;
	if (ax_181 < cx_21)
		ax_181 = cx_21;
	*ptrArg06 = (byte) ax_181;
	byte Eq_65032::* di_125 = di_65 + 1;
	ci16 ax_73 = ax_181 - cx_21;
	if (ax_73 != 0x00)
	{
		ci16 cx_126;
		for (cx_126 = ax_73; cx_126 != 0x00; --cx_126)
		{
			es_61->*di_125 = 0x20;
			++di_125;
		}
	}
	memcpy(&(es_61->*di_125), &tLoc22, (uint32) cx_21);
}
