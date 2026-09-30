// 1229:050A: Register word16 fn1229_050A(Register Eq_17 ds, Stack Eq_17 bArg02, Stack Eq_17 ptrArg04, Register out Eq_17 dsOut)
// Called from:
//      fn1229_0735
word16 fn1229_050A(Eq_17 ds, Eq_17 bArg02, Eq_17 ptrArg04, union Eq_17 & dsOut)
{
	selector es_402;
	word16 si_401;
	<unknown> Eq_52023::* fp;
	word16 dx_399;
	fn1EDA_0A39(~0x00, fp - 0x0104, ptrArg04, out dx_399);
	Eq_17 ax_55 = (int32) fn1AB8_10CE(ds) /16 0x02 - 0x68;
	Eq_17 ax_71 = (int32) fn1AB8_10E1(ds) /16 0x02 - 0x10;
	Eq_17 ax_87 = (int32) fn1AB8_10CE(ds) /16 0x02 + 0x68;
	Eq_17 ax_103 = (int32) fn1AB8_10E1(ds) /16 0x02 + 0x10;
	Eq_17 ptrLoc041C_339;
	ptrLoc041C_339.u3 = fp - 0x020C;
	struct Eq_52068 * cs;
	fn1EDA_0A1F(&cs->t0503, ptrLoc041C_339);
	fn1EDA_0AAC(fp - 0x0104, ptrLoc041C_339);
	fn1EDA_0AAC((char *) &cs->t0503 + 2, ptrLoc041C_339);
	Eq_17 ptrLoc0420_353;
	ptrLoc0420_353.u3 = fp - 0x030C;
	fn13C1_0036((uint32) bArg02, ptrLoc0420_353);
	fn1EDA_0AAC(ptrLoc0420_353, ptrLoc041C_339);
	fn1EDA_0AAC((char *) &cs->t0503 + 4, ptrLoc041C_339);
	Eq_17 ptrLoc0410_357;
	ptrLoc0410_357.u3 = fp - 0x040C;
	Eq_17 ds_231;
	fn1229_0040(ds, ptrLoc041C_339, ax_103, ax_87, ax_71, ax_55, ptrLoc0410_357, out ds_231);
	word16 dx_400;
	fn1EDA_0A39(0x02, fp - 0x0108, ptrLoc0410_357, out dx_400);
	Eq_17 bLoc010C_371 = (byte) fn1EDA_0F71(fp - 266, fp - 0x0108, out si_401, out es_402);
	word16 wLoc010A;
	if (wLoc010A != 0x00)
		bLoc010C_371 = bArg02;
	byte ah_302;
	do
		ah_302 = <invalid>;
	while (fn1E78_02FB(ds_231) != 0x00);
	dsOut = ds_231;
	return SEQ(ah_302, bLoc010C_371);
}
