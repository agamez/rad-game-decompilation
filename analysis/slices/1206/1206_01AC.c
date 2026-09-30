// 1206:01AC: Register word16 fn1206_01AC(Register Eq_17 ds, Register out word16 siOut, Register out (ptr16 Eq_4896) esOut, Register out Eq_17 dsOut)
// Called from:
//      fn0800_184C
//      fn0800_3D9D
//      fn1206_0217
word16 fn1206_01AC(Eq_17 ds, word16 & siOut, struct Eq_4896 & esOut, union Eq_17 & dsOut)
{
	struct Eq_13558 * ds_115;
	struct Eq_13540 * ds_94;
	mp16 fp;
	Mem10[ds:22910:byte] = 0x00;
	word16 Eq_17::* bp_132 = fp - 2;
	word16 si;
	struct Eq_4896 * es;
	selector ss;
	if (fn1206_0000() != 0x00)
	{
		bp_132 = fn1206_000D(out si, out es, out ds);
		Eq_481 sp_36;
		sp_36.u0 = <invalid>;
		if (Mem26[ds:22906:word16] != 0x00)
			Mem45[ds:22910:byte] = 0x01;
		if (Mem47[ds:22910:byte] != 0x00)
		{
			Mem50[ds:22924:byte] = 0x00;
			ss->*((word16) sp_36 + 6) = ds;
			ss->*((word16) sp_36 + 4) = 22912;
			ss->*((word16) sp_36 + 2) = ds;
			ss->*sp_36 = 22914;
			ss->*((word16) sp_36 - 2) = ds;
			ss->*((word16) sp_36 - 4) = 22916;
			word16 dx_197;
			struct Eq_51427 Eq_17::* bp_69;
			Eq_17 ds_73;
			fn1206_0094(ds, out dx_197, out bp_69, out ds_73);
			Eq_481 sp_77;
			sp_77.u0 = <invalid>;
			(ss->*((word16) sp_77 + 0x0A)).u1 = (ss->*bp_69).t0010.u2;
			(ss->*((word16) sp_77 + 8)).u1 = (ss->*bp_69).t000C.u2;
			struct Eq_13543 Eq_17::* bp_90 = fn1206_00FF(ds_73, out ds_94);
			Eq_481 sp_98;
			sp_98.u0 = <invalid>;
			(ss->*((word16) sp_98 + 2)).u1 = (ss->*bp_90).t000E.u2;
			(ss->*sp_98).u1 = (ss->*bp_90).t000A.u2;
			struct Eq_13561 Eq_17::* bp_111 = fn1206_012D(ds_94, out ds_115);
			Eq_481 sp_119;
			sp_119.u0 = <invalid>;
			(ss->*((word16) sp_119 + 2)).u1 = (ss->*bp_111).t0008.u2;
			(ss->*sp_119).u1 = (ss->*bp_111).t0006.u2;
			bp_132 = fn1206_00D1(ds_115, out si, out es, out ds);
		}
	}
	word16 bp_151 = ss->*bp_132;
	siOut = si;
	esOut = es;
	dsOut = ds;
	return bp_151;
}
