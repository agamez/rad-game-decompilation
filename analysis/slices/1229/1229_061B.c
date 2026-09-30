// 1229:061B: Register word16 fn1229_061B(Register Eq_17 ds, Register out int16 dxOut, Register out Eq_17 dsOut)
// Called from:
//      fn1229_0DCC
word16 fn1229_061B(Eq_17 ds, int16 & dxOut, union Eq_17 & dsOut)
{
	Eq_17 ax_29 = (int32) fn1AB8_10CE(ds) /16 0x02 - 0xB0;
	Eq_17 ax_45 = (int32) fn1AB8_10E1(ds) /16 0x02 - 0x10;
	Eq_17 ax_61 = (int32) fn1AB8_10CE(ds) /16 0x02 + 0xB0;
	Eq_17 ax_77 = (int32) fn1AB8_10E1(ds) /16 0x02 + 0x10;
	Eq_17 ptrLoc021A_242;
	<unknown> Eq_52172::* fp;
	ptrLoc021A_242.u3 = fp - 266;
	struct Eq_52179 * cs;
	fn1EDA_0A1F(&cs->t05F8, ptrLoc021A_242);
	fn1EDA_0AAC(SEQ(ds, 23732), ptrLoc021A_242);
	fn1EDA_0AAC((char *) &cs->t05F8 + 2, ptrLoc021A_242);
	Eq_17 ptrLoc020E_250;
	ptrLoc020E_250.u3 = fp - 522;
	Eq_17 ds_145;
	fn1229_0040(ds, ptrLoc021A_242, ax_77, ax_61, ax_45, ax_29, ptrLoc020E_250, out ds_145);
	word16 dx_289;
	fn1EDA_0A39(0x01, fp - 6, ptrLoc020E_250, out dx_289);
	byte bLoc03_231 = 0x00;
	word16 ax_290;
	int16 dx_191;
	if (!fn1EDA_0B24((char *) &cs->t05F8 + 33, fp - 6, out ax_290, out dx_191))
		bLoc03_231 = 0x01;
	fn1AB8_1C32(ds_145, 0x0F);
	byte ah_212;
	do
		ah_212 = <invalid>;
	while (fn1E78_02FB(ds_145) != 0x00);
	dxOut = dx_191;
	dsOut = ds_145;
	return SEQ(ah_212, bLoc03_231);
}
