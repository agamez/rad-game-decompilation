// 1229:039D: void fn1229_039D(Register Eq_17 ds)
// Called from:
//      fn1229_0DCC
void fn1229_039D(Eq_17 ds)
{
	word16 dx_359;
	struct Eq_51835 * cs;
	if (Mem7[ds:0x6BBA:byte] != 0x00)
	{
		word16 dx_358;
		fn1EDA_0A39(0x06, SEQ(ds, 0x6BB2), SEQ(ds, 0x6BBA), out dx_358);
	}
	else
	{
		word16 dx_357;
		fn1EDA_0A39(0x06, SEQ(ds, 0x6BB2), &cs->t038E, out dx_357);
	}
	uint8 bLoc83_293 = 0x01;
	while (true)
	{
		Mem95[ds:CONVERT(bLoc83_293, uint8, uint16) + 0x6BB2:byte] = fn1EDA_1384(Mem69[ds:CONVERT(bLoc83_293, uint8, uint16) + 0x6BB2:byte]);
		if (bLoc83_293 == 0x06)
			break;
		++bLoc83_293;
	}
	<unknown> Eq_51871::* fp;
	fn1EDA_0FA2((char *) &cs->t038E + 7, fp - 0x0082);
	byte al_158 = fn1EDA_0FD0(ds, 0x0219, fp - 0x0082, out dx_359);
	Mem142[ds:22926:word16] = ~0x00;
	Mem143[ds:22928:word16] = ~0x00;
	word16 ax_257;
	word16 ax_356;
	word16 dx_362;
	do
	{
		fn1EDA_1085(al_158, ds, fp - 0x0082);
		Mem176[ds:22926:ui32] = Mem172[ds:22926:ui32] + 0x01;
		word16 ax_183 = fn1EDA_1185(ds, fp - 0x0082);
		ax_257 = ax_183;
		if ((byte) ax_183 != 0x00)
			break;
		word16 ax_355;
		ax_257 = ax_355;
		word16 dx_361;
		if (fn1EDA_0B24(SEQ(ds, 0x6BB2), SEQ(ds, 23732), out ax_355, out dx_361))
			break;
		al_158 = (byte) ax_356;
		ax_257 = ax_356;
	} while (fn1EDA_0B24(&cs->t038E, SEQ(ds, 23732), out ax_356, out dx_362));
	fn1EDA_1051((byte) ax_257, ds, fp - 0x0082);
}
