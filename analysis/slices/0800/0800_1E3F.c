// 0800:1E3F: Register word16 fn0800_1E3F(Register int16 dx, Register Eq_17 ds, Register out Eq_17 dsOut)
// Called from:
//      fn0800_2004
word16 fn0800_1E3F(int16 dx, Eq_17 ds, union Eq_17 & dsOut)
{
	while (fn1E78_02FB(ds) != 0x00)
	{
		Eq_17 wLoc10;
		fn1E78_030D(dx, ds, wLoc10, out dx);
	}
	fn1AB8_10CE(ds);
	struct Eq_6512 Eq_17::* bp_36;
	Eq_17 ds_40;
	fn1206_0066(ds, out bp_36, out ds_40);
	Eq_481 sp_44;
	sp_44.u0 = <invalid>;
	selector ss;
	(ss->*((word16) sp_44 - 2)).u1 = (ss->*bp_36).tFFFE.u2;
	(ss->*((word16) sp_44 - 4)).u1 = (ss->*bp_36).tFFFA.u2;
	(ss->*((word16) sp_44 - 6)).u1 = (ss->*bp_36).tFFFC.u2;
	(ss->*((word16) sp_44 - 8)).u1 = (ss->*bp_36).tFFF8.u2;
	fn0800_1315(ds_40, ss->*((word16) sp_44 - 8), ss->*((word16) sp_44 - 6), ss->*((word16) sp_44 - 4), ss->*((word16) sp_44 - 2));
	(ss->*bp_36).tFFFE.u2 = (uint16) ((ss->*bp_36).tFFFE.u2 + 0x08);
	(ss->*bp_36).tFFFA.u2 = (uint16) ((ss->*bp_36).tFFFA.u2 + 0x08);
	ss->*((word16) sp_44 - 2) = 0x00;
	ss->*((word16) sp_44 - 4) = 0x01;
	fn1AB8_14F4(ds_40, ss->*((word16) sp_44 - 4), ss->*((word16) sp_44 - 2));
	ss->*((word16) sp_44 - 2) = 0x00;
	ss->*((word16) sp_44 - 4) = 0x00;
	ss->*((word16) sp_44 - 6) = 0x01;
	Eq_17 ds_103;
	fn1AB8_1536(ds_40, ss->*((word16) sp_44 - 6), ss->*((word16) sp_44 - 4), ss->*((word16) sp_44 - 2), out ds_103);
	(ss->*bp_36).bFFF5 = 0x01;
	Eq_17 cs;
	while (true)
	{
		ss->*((word16) sp_44 - 2) = 0x00;
		fn1AB8_1C32(ds_103, ss->*((word16) sp_44 - 2));
		ss->*((word16) sp_44 - 2) = (ss->*bp_36).tFFFE.u2 - 0x01;
		ss->*((word16) sp_44 - 4) = (uint16) (ss->*bp_36).bFFF5 *s 0x0D + ((ss->*bp_36).tFFFA).u2 - 0x01;
		Eq_17 di_138 = ((uint16) (ss->*bp_36).bFFF5 << 0x08) + 8966;
		ss->*((word16) sp_44 - 6) = ds_103;
		ss->*((word16) sp_44 - 8) = di_138;
		byte ch_472;
		fn1AB8_1D82(ds_103, ss->*((word16) sp_44 - 8), ss->*((word16) sp_44 - 4), ss->*((word16) sp_44 - 2), out ch_472);
		(ss->*((word16) sp_44 - 2)).u1 = (uint16) (ss->*bp_36).bFFF5;
		ss->*((word16) sp_44 - 4) = cs;
		ss->*((word16) sp_44 - 6) = 0x1DE0;
		selector es_473;
		if (!fn1EDA_0CD4(ss->*((word16) sp_44 - 6), ss->*((word16) sp_44 - 2), out es_473))
		{
			ss->*((word16) sp_44 - 2) = 0x0A;
			fn1AB8_1C32(ds_103, ss->*((word16) sp_44 - 2));
		}
		else
		{
			ss->*((word16) sp_44 - 2) = 11;
			fn1AB8_1C32(ds_103, ss->*((word16) sp_44 - 2));
		}
		(ss->*((word16) sp_44 - 2)).u1 = (ss->*bp_36).tFFFE.u2;
		ss->*((word16) sp_44 - 4) = (uint16) (ss->*bp_36).bFFF5 *s 0x0D + ((ss->*bp_36).tFFFA).u2;
		Eq_17 di_208 = ((uint16) (ss->*bp_36).bFFF5 << 0x08) + 8966;
		ss->*((word16) sp_44 - 6) = ds_103;
		ss->*((word16) sp_44 - 8) = di_208;
		byte ch_474;
		fn1AB8_1D82(ds_103, ss->*((word16) sp_44 - 8), ss->*((word16) sp_44 - 4), ss->*((word16) sp_44 - 2), out ch_474);
		if ((ss->*bp_36).bFFF5 == 0x14)
			break;
		++(ss->*bp_36).bFFF5;
	}
	ss->*((word16) sp_44 - 2) = 0x05;
	ss->*((word16) sp_44 - 4) = 0x0140;
	ss->*((word16) sp_44 - 6) = 330;
	ss->*((word16) sp_44 - 8) = cs;
	ss->*((word16) sp_44 - 0x0A) = 0x1E00;
	ss->*((word16) sp_44 - 0x0C) = 0x00;
	int16 dx_251;
	word16 bp_475;
	Eq_17 ds_250;
	fn0800_19E1(ds_103, ss->*((word16) sp_44 - 0x0A), out dx_251, out bp_475, out ds_250);
	Eq_481 sp_254;
	sp_254.u0 = <invalid>;
	struct Eq_6897 Eq_17::* sp_260 = (word16) sp_254 + 0x0C;
	while (fn1E78_02FB(ds_250) == 0x00)
	{
		(ss->*sp_260).tFFFE.u2 = (uint16) 0x00;
		Eq_481 sp_286;
		sp_286.u0 = <invalid>;
		sp_260 = (word16) sp_286 + 2;
		byte ch_476;
		word16 bp_477;
		if ((byte) fn1206_015B(ds_250, out ch_476, out dx_251, out bp_477, out ds_250) != 0x00)
			break;
	}
	if (fn1E78_02FB(ds_250) != 0x00)
	{
		struct Eq_7055 Eq_17::* sp_325 = sp_260 - 2;
		word16 dx_481;
		(ss->*sp_325).t0000.u2 = (uint16) fn1E78_030D(dx_251, ds_250, (ss->*sp_260).tFFFE.u2, out dx_481);
		(ss->*sp_325).tFFFE.u2 = (uint16) cs;
		(ss->*sp_325).tFFFC.u2 = (uint16) 7711;
		selector es_482;
		if (!fn1EDA_0CD4((ss->*sp_325).tFFFC.u3, (ss->*sp_325).t0000.u0, out es_482) && Mem333[ds_250:21464:byte] != 0x00)
			Mem347[ds_250:0x02:byte] = ~0x00;
	}
	struct Eq_6927 Eq_17::* sp_349 = sp_260 - 2;
	(ss->*sp_349).w0000 = 0x05;
	(ss->*sp_349).tFFFE.u2 = (uint16) 0x0140;
	(ss->*sp_349).wFFFC = 330;
	(ss->*sp_349).tFFFA.u2 = (uint16) cs;
	(ss->*sp_349).tFFF8.u2 = (uint16) 0x1E00;
	(ss->*sp_349).wFFF6 = 0x01;
	word16 dx_478;
	word16 bp_479;
	Eq_17 ds_370;
	fn0800_19E1(ds_250, (ss->*sp_349).tFFF8.u3, out dx_478, out bp_479, out ds_370);
	struct Eq_6971 Eq_17::* bp_382;
	Eq_17 ds_386;
	fn1206_0066(ds_370, out bp_382, out ds_386);
	Eq_481 sp_390;
	sp_390.u0 = <invalid>;
	ss->*((word16) sp_390 - 2) = 0x96;
	word16 dx_480;
	fn1E78_029C(ds_386, ss->*((word16) sp_390 - 2), out dx_480);
	ss->*((word16) sp_390 - 2) = (ss->*bp_382).wFFFE - 0x0C;
	ss->*((word16) sp_390 - 4) = (ss->*bp_382).wFFFA - 0x0C;
	ss->*((word16) sp_390 - 6) = (ss->*bp_382).wFFFC + 0x04;
	ss->*((word16) sp_390 - 8) = (ss->*bp_382).wFFF8 + 0x04;
	fn0800_0024(ds_386, ss->*((word16) sp_390 - 8), ss->*((word16) sp_390 - 6), ss->*((word16) sp_390 - 4), ss->*((word16) sp_390 - 2));
	word16 bp_437 = (ss->*bp_382).w0000;
	dsOut = ds_386;
	return bp_437;
}
