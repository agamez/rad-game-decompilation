// 0C74:011E: Register Eq_526 fn0C74_011E(Register Eq_17 ds, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_02D8
Eq_526 fn0C74_011E(Eq_17 ds, union Eq_17 & dsOut)
{
	<unknown> Eq_17::* fp;
	Eq_17 ss;
	Eq_17 ptrLoc010C_298 = SEQ(ss, fp - 0x0108);
	fn0C74_004B(Mem14[ds:22748:word32], ptrLoc010C_298);
	word16 dx_343;
	fn1EDA_0A39(0x02, SEQ(ss, fp - 6), ptrLoc010C_298, out dx_343);
	struct Eq_20089 Eq_17::* bp_152 = fp - 2;
	cu8 bLoc06;
	Eq_17 cs;
	if (bLoc06 < 0x02)
	{
		Eq_17 ptrLoc010C_308 = SEQ(ss, fp - 0x0108);
		fn1EDA_0A1F(SEQ(cs, 252), ptrLoc010C_308);
		fn1EDA_0AAC(SEQ(ss, fp - 6), ptrLoc010C_308);
		word16 dx_345;
		fn1EDA_0A39(0x02, SEQ(ss, fp - 6), ptrLoc010C_308, out dx_345);
	}
	fn1AB8_1285();
	Eq_481 sp_150 = fp - 0x0108;
	selector es_344;
	if (!fn1EDA_0CD4(SEQ(cs, 0xFE), Mem127[ds:22756:byte], out es_344))
	{
		fn1206_0066(ds, out bp_152, out ds);
		sp_150.u0 = <invalid>;
	}
	struct Eq_20132 Eq_17::* sp_166 = sp_150 - 2;
	(ss->*sp_166).t0000.u2 = (uint16) 0x024B;
	(ss->*sp_166).tFFFE.u2 = (uint16) 0x0192;
	(ss->*sp_166).tFFFC.u2 = (uint16) 0x025C;
	(ss->*sp_166).tFFFA.u2 = (uint16) 411;
	(ss->*sp_166).tFFF8.u2 = (ss->*bp_152).t0004.u2;
	fn0C74_00DB(ds, (ss->*sp_166).tFFFA.u2, (ss->*sp_166).tFFFC.u2, (ss->*sp_166).tFFFE.u2, (ss->*sp_166).t0000.u2);
	(ss->*sp_166).t0000.u2 = (uint16) 0x08;
	fn1AB8_1C32(ds, (ss->*sp_166).t0000.u0);
	(ss->*sp_166).t0000.u2 = (uint16) 595;
	(ss->*sp_166).tFFFE.u2 = (uint16) 0x0196;
	(ss->*sp_166).tFFFC.u2 = (uint16) ss;
	(ss->*sp_166).tFFFA.u2 = (uint16) (bp_152 - 4);
	byte ch_346;
	fn1AB8_1D82(ds, (ss->*sp_166).tFFFA.u3, (ss->*sp_166).tFFFE.u2, (ss->*sp_166).t0000.u2, out ch_346);
	(ss->*sp_166).t0000.u2 = (uint16) 0x0A;
	fn1AB8_1C32(ds, (ss->*sp_166).t0000.u0);
	(ss->*sp_166).t0000.u2 = (uint16) 0x0254;
	(ss->*sp_166).tFFFE.u2 = (uint16) 0x0197;
	(ss->*sp_166).tFFFC.u2 = (uint16) ss;
	(ss->*sp_166).tFFFA.u2 = (uint16) (bp_152 - 4);
	byte ch_347;
	fn1AB8_1D82(ds, (ss->*sp_166).tFFFA.u3, (ss->*sp_166).tFFFE.u2, (ss->*sp_166).t0000.u2, out ch_347);
	Mem246[ss:sp_166 + 0x00:word16] = CONVERT(Mem230[ds:22756:byte], uint8, uint16);
	(ss->*sp_166).tFFFE.u2 = (uint16) cs;
	(ss->*sp_166).tFFFC.u2 = (uint16) 0xFE;
	Eq_481 sp_263 = (char *) &sp_166->t0000 + 2;
	selector es_348;
	if (!fn1EDA_0CD4((ss->*sp_166).tFFFC.u3, (ss->*sp_166).t0000.u0, out es_348))
	{
		byte ch_349;
		word16 dx_350;
		fn1206_0038(ds, out ch_349, out dx_350, out bp_152, out ds);
		sp_263.u0 = <invalid>;
	}
	struct Eq_20312 Eq_17::* sp_283 = sp_263 - 2;
	(ss->*sp_283).t0000.u2 = (ss->*bp_152).tFFFA.u2;
	fn1AB8_1C32(ds, (ss->*sp_283).t0000.u0);
	Eq_526 bp_290;
	bp_290.u1 = (ss->*bp_152).t0000.u1;
	dsOut = ds;
	return bp_290;
}
