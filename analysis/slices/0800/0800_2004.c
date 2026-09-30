// 0800:2004: Register Eq_17 fn0800_2004(Register Eq_17 ds)
// Called from:
//      fn0800_3D9D
Eq_17 fn0800_2004(Eq_17 ds)
{
	Mem11[ds:21464:byte] = 0x00;
	fn0800_1315(ds, 0x016A, 0x01E0, 0x14, 0x9C);
	fn1AB8_14F4(ds, 0x01, 0x01);
	Eq_17 ds_70;
	fn1AB8_1536(ds, 0x01, 0x00, 0x00, out ds_70);
	Eq_17 bLoc0B_414;
	bLoc0B_414.u0 = 0x01;
	Eq_17 cs;
	while (true)
	{
		fn1AB8_1C32(ds_70, 0x00);
		byte ch_457;
		fn1AB8_1D82(ds_70, SEQ(ds_70, ((uint16) bLoc0B_414 << 0x08) + 0x3706), (uint16) bLoc0B_414 *s 0x0D + 0x1F, 0x0141, out ch_457);
		selector es_458;
		if (!fn1EDA_0CD4(SEQ(cs, 8117), bLoc0B_414, out es_458))
			fn1AB8_1C32(ds_70, 0x0A);
		else
			fn1AB8_1C32(ds_70, 11);
		byte ch_459;
		fn1AB8_1D82(ds_70, SEQ(ds_70, ((uint16) bLoc0B_414 << 0x08) + 0x3706), (uint16) bLoc0B_414 *s 0x0D + 0x20, 322, out ch_459);
		if (bLoc0B_414 == 0x15)
			break;
		bLoc0B_414.u3 = (byte) bLoc0B_414.u1 + 1;
	}
	int16 dx_221;
	word16 bp_460;
	Eq_17 ds_220;
	fn0800_19E1(ds_70, SEQ(cs, 0x1FD5), out dx_221, out bp_460, out ds_220);
	Eq_481 sp_224;
	sp_224.u0 = <invalid>;
	struct Eq_7185 Eq_17::* sp_230 = (word16) sp_224 + 0x0C;
	selector ss;
	while (fn1E78_02FB(ds_220) == 0x00)
	{
		(ss->*sp_230).tFFFE.u2 = (uint16) 0x00;
		Eq_481 sp_256;
		sp_256.u0 = <invalid>;
		sp_230 = (word16) sp_256 + 2;
		byte ch_461;
		word16 bp_462;
		if ((byte) fn1206_015B(ds_220, out ch_461, out dx_221, out bp_462, out ds_220) != 0x00)
			break;
	}
	if (fn1E78_02FB(ds_220) != 0x00)
	{
		struct Eq_7287 Eq_17::* sp_295 = sp_230 - 2;
		word16 dx_466;
		(ss->*sp_295).t0000.u2 = (uint16) fn1E78_030D(dx_221, ds_220, (ss->*sp_230).tFFFE.u2, out dx_466);
		(ss->*sp_295).tFFFE.u2 = (uint16) cs;
		(ss->*sp_295).tFFFC.u2 = (uint16) 0x1FE4;
		selector es_467;
		if (!fn1EDA_0CD4((ss->*sp_295).tFFFC.u3, (ss->*sp_295).t0000.u0, out es_467))
			Mem315[ds_220:21464:byte] = 0x01;
	}
	struct Eq_7218 Eq_17::* sp_317 = sp_230 - 2;
	(ss->*sp_317).w0000 = 0x05;
	(ss->*sp_317).tFFFE.u2 = (uint16) 0x0140;
	(ss->*sp_317).wFFFC = 330;
	(ss->*sp_317).tFFFA.u2 = (uint16) cs;
	(ss->*sp_317).tFFF8.u2 = (uint16) 0x1FD5;
	(ss->*sp_317).wFFF6 = 0x01;
	word16 dx_463;
	word16 bp_464;
	Eq_17 ds_338;
	fn0800_19E1(ds_220, (ss->*sp_317).tFFF8.u3, out dx_463, out bp_464, out ds_338);
	word16 bp_465;
	Eq_17 ds_354;
	fn1206_0066(ds_338, out bp_465, out ds_354);
	Eq_481 sp_358;
	sp_358.u0 = <invalid>;
	ss->*((word16) sp_358 - 2) = 0x96;
	int16 dx_366;
	fn1E78_029C(ds_354, ss->*((word16) sp_358 - 2), out dx_366);
	Eq_17 ds_381;
	fn0800_1E3F(dx_366, ds_354, out ds_381);
	return ds_381;
}
