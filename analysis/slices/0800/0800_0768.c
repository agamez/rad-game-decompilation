// 0800:0768: Register int16 fn0800_0768(Register Eq_17 ds, Register out Eq_526 bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0800_2C0C
//      fn0800_31B7
int16 fn0800_0768(Eq_17 ds, union Eq_526 & bpOut, union Eq_17 & dsOut)
{
	mp16 fp;
	Eq_17 ds_111;
	fn1AB8_1536(ds, 0x00, 0x00, 0x00, out ds_111);
	fn1AB8_14F4(ds_111, 0x01, 0x01);
	fn1AB8_1C32(ds_111, 0x08);
	fn0800_005A(ds_111, 0x01CF, 0x0264, 0x01A7, 0x0204);
	Eq_17 cs;
	byte ch_440;
	fn1AB8_1D82(ds_111, SEQ(cs, 0x0755), 0x01AE, 0x0233, out ch_440);
	byte ch_441;
	fn1AB8_1D82(ds_111, SEQ(cs, 1885), 454, 0x0233, out ch_441);
	struct Eq_1179 Eq_17::* bp_157 = fp - 2;
	struct Eq_1182 Eq_17::* sp_106 = fp - 0x04;
l0800_07B6:
	struct Eq_1368 Eq_17::* sp_108 = sp_106 - 2;
	selector ss;
	(ss->*sp_108).t0000.u2 = (uint16) 11;
	fn1AB8_1C32(ds_111, (ss->*sp_108).t0000.u0);
	(ss->*sp_108).t0000.u2 = (uint16) 0x0234;
	(ss->*sp_108).tFFFE.u2 = (uint16) 0x01AF;
	(ss->*sp_108).tFFFC.u2 = (uint16) cs;
	(ss->*sp_108).tFFFA.u2 = (uint16) 0x0755;
	byte ch_446;
	fn1AB8_1D82(ds_111, (ss->*sp_108).tFFFA.u3, (ss->*sp_108).tFFFE.u2, (ss->*sp_108).t0000.u2, out ch_446);
	(ss->*sp_108).t0000.u2 = (uint16) 0x0234;
	(ss->*sp_108).tFFFE.u2 = (uint16) 455;
	(ss->*sp_108).tFFFC.u2 = (uint16) cs;
	(ss->*sp_108).tFFFA.u2 = (uint16) 1885;
	byte ch_447;
	fn1AB8_1D82(ds_111, (ss->*sp_108).tFFFA.u3, (ss->*sp_108).tFFFE.u2, (ss->*sp_108).t0000.u2, out ch_447);
	(ss->*bp_157).tFFFE.u1 = 0x01;
	struct Eq_1186 Eq_17::* sp_156 = (struct Eq_1186 Eq_17::*) ((char *) &sp_108->t0000 + 2);
	int16 dx_170;
	while (true)
	{
		(ss->*sp_156).tFFFE.u2 = (uint16) 0x00;
		Eq_481 sp_173;
		sp_173.u0 = <invalid>;
		sp_156 = (word16) sp_173 + 2;
		byte ch_442;
		if ((byte) fn1206_015B(ds_111, out ch_442, out dx_170, out bp_157, out ds_111) != 0x00 || fn1E78_02FB(ds_111) != 0x00)
			break;
		if ((ss->*bp_157).tFFFE.u1 == 2500)
		{
			ss->*sp_173 = 0x0E;
			fn1AB8_1C32(ds_111, ss->*sp_173);
			ss->*sp_173 = 0x0234;
			ss->*((word16) sp_173 - 2) = 0x01AF;
			ss->*((word16) sp_173 - 4) = cs;
			ss->*((word16) sp_173 - 6) = 0x0755;
			byte ch_443;
			fn1AB8_1D82(ds_111, ss->*((word16) sp_173 - 6), ss->*((word16) sp_173 - 2), ss->*sp_173, out ch_443);
			ss->*sp_173 = 0x0234;
			ss->*((word16) sp_173 - 2) = 455;
			ss->*((word16) sp_173 - 4) = cs;
			ss->*((word16) sp_173 - 6) = 1885;
			byte ch_444;
			fn1AB8_1D82(ds_111, ss->*((word16) sp_173 - 6), ss->*((word16) sp_173 - 2), ss->*sp_173, out ch_444);
			(ss->*bp_157).tFFFE.u1 = 0x01;
			sp_106 = (word16) sp_173 + 2;
			while (true)
			{
				(ss->*sp_106).tFFFE.u2 = (uint16) 0x00;
				Eq_481 sp_263;
				sp_263.u0 = <invalid>;
				sp_106 = (word16) sp_263 + 2;
				byte ch_445;
				if ((byte) fn1206_015B(ds_111, out ch_445, out dx_170, out bp_157, out ds_111) != 0x00 || fn1E78_02FB(ds_111) != 0x00)
					break;
				if ((ss->*bp_157).tFFFE.u1 == 5000)
				{
					if (fn1E78_02FB(ds_111) == 0x00)
						goto l0800_07B6;
					while (fn1E78_02FB(ds_111) != 0x00)
						fn1E78_030D(dx_170, ds_111, ss->*sp_263, out dx_170);
					ss->*sp_263 = 0x00;
					fn1AB8_1C32(ds_111, ss->*sp_263);
					goto l0800_0875;
				}
				(ss->*bp_157).tFFFE.u1 = (word16) ((ss->*bp_157).tFFFE.u1 + 0x01);
			}
			goto l0800_0875;
		}
		(ss->*bp_157).tFFFE.u1 = (word16) ((ss->*bp_157).tFFFE.u1 + 0x01);
	}
l0800_0875:
	bpOut.u1 = (ss->*bp_157).t0000.u1;
	dsOut = ds_111;
	return dx_170;
}
