// 133F:0056: Register word16 fn133F_0056(Register Eq_17 ds, Register out Eq_17 dsOut)
// Called from:
//      fn133F_0816
word16 fn133F_0056(Eq_17 ds, union Eq_17 & dsOut)
{
	<unknown> Eq_17::* fp;
	Eq_17 ss;
	struct Eq_55496 * cs;
	Eq_17 ds_211 = fn1AB8_0BAE(ds, &cs->t0000, SEQ(ss, fp - 6), SEQ(ss, fp - 4));
	word16 Eq_17::* bp_238 = fp - 2;
	uint16 ax_46 = fn1AB8_04F3(ds_211);
	if (ax_46 != 0x00)
	{
		Eq_17 ptrLoc0212_341 = SEQ(ds_211, ~0x4643);
		word16 cx_381;
		fn1EDA_08CE(ds_211, 0x00, (char *) &cs->t0000 + 1, ptrLoc0212_341, out cx_381);
		Eq_17 ptrLoc0216_346 = SEQ(ss, fp - 0x020E);
		fn1AB8_027E(ds_211, ax_46, ptrLoc0216_346);
		Eq_481 cx_107;
		fn1EDA_08CE(ds_211, 0x00, ptrLoc0216_346, ptrLoc0212_341, out cx_107);
		Eq_17 ds_122 = fn1EDA_0848(0x00, cx_107, ds_211, ptrLoc0212_341);
		Eq_17 ptrLoc0212_353 = SEQ(ds_122, ~0x4643);
		Eq_481 cx_146;
		fn1EDA_08CE(ds_122, 0x00, (char *) &cs->t0000 + 20, ptrLoc0212_353, out cx_146);
		Eq_17 ds_161 = fn1EDA_0848(0x00, cx_146, ds_122, ptrLoc0212_353);
		Eq_17 ptrLoc0212_360 = SEQ(ds_161, ~0x4643);
		Eq_481 cx_185;
		fn1EDA_08CE(ds_161, 0x00, (char *) &cs->t0000 + 61, ptrLoc0212_360, out cx_185);
		fn1EDA_0848(0x00, cx_185, ds_161, ptrLoc0212_360);
		ds_211 = fn1EDA_00E9(0x01);
	}
	<unknown> Eq_17::* sp_225 = fp - 0x020E;
	if (fn13C8_0000() != 0x00)
	{
		Eq_481 sp_246;
		sp_246.u0 = <invalid>;
		bp_238 = fn13C8_000D(out ds_211);
		sp_225 = (word16) sp_246 + 8;
		if (Mem236[ds_211:46766:word16] != 0x00)
		{
			ss->*((word16) sp_246 + 6) = 0x00;
			ss->*((word16) sp_246 + 4) = 0x027F;
			fn13C8_00BF();
			Eq_481 sp_268;
			sp_268.u0 = <invalid>;
			ss->*((word16) sp_268 + 2) = 0x00;
			ss->*sp_268 = 0x01DF;
			Eq_481 sp_288;
			sp_288.u0 = <invalid>;
			bp_238 = fn13C8_00E4(out ds_211);
			sp_225 = (word16) sp_288 + 4;
		}
	}
	Mem296[ds_211:46493:byte] = 0x00;
	Mem297[ds_211:46498:byte] = 0x00;
	Mem298[ds_211:0x6CD0:byte] = 0x00;
	Mem299[ds_211:46492:byte] = 0x00;
	union Eq_17 Eq_17::* sp_301 = sp_225 - 2;
	(ss->*sp_301).u2 = (uint16) 0x00;
	fn1AB8_1250(ds_211, (ss->*sp_301).u2);
	(ss->*sp_301).u2 = (uint16) 0x0F;
	fn1AB8_1C32(ds_211, (ss->*sp_301).u0);
	word16 bp_322 = ss->*bp_238;
	dsOut = ds_211;
	return bp_322;
}
