// 1AB8:129A: void fn1AB8_129A(Register Eq_17 ds, Stack (ptr32 Eq_58870) ptrArg04)
// Called from:
//      fn1AB8_0AEE
void fn1AB8_129A(Eq_17 ds, struct Eq_58870 * ptrArg04)
{
	if (Mem7[ds:0xB84E:byte] != 0x00)
	{
		uint8 bLoc05_137;
		if (ptrArg04->b0000 > 0x10)
			bLoc05_137 = 0x10;
		else
			bLoc05_137 = ptrArg04->b0000;
		Eq_60172 ax_34;
		ax_34.u1 = (uint16) bLoc05_137;
		if (ax_34 >= 0x01)
		{
			Eq_60181 wLoc04_141;
			wLoc04_141.u0 = 0x00;
			while (true)
			{
				if (SLICE(ptrArg04, selector, 16)->*((word16) ((word16) ptrArg04 + wLoc04_141) + 1) > ~0x00)
					ds->*((word16) wLoc04_141 + 0x0000B87B) = SLICE(ptrArg04, selector, 16)->*((word16) ((word16) ptrArg04 + wLoc04_141) + 1);
				if (wLoc04_141 == ax_34 - 0x01)
					break;
				wLoc04_141 = (word16) wLoc04_141 + 1;
			}
		}
		if (ptrArg04->b0001 != ~0x00)
			Mem81[ds:0xB840:byte] = 0x00;
		<unknown> Eq_60194::* fp;
		fn1EDA_11DF(0x11, fp - 24, SEQ(ds, 47226));
		fn1AB8_1CED(ds, fp - 24);
	}
}
