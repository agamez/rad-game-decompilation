// 133F:04B1: Register word16 fn133F_04B1(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08, Stack Eq_17 wArg0A, Register out (ptr16 Eq_54312) dsOut)
// Called from:
//      fn1229_0CCE
//      fn133F_04DE
word16 fn133F_04B1(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06, Eq_17 wArg08, Eq_17 wArg0A, struct Eq_54312 & dsOut)
{
	struct Eq_54312 * ds_57;
	fn133F_0200(ds, wArg04, wArg06, wArg08, wArg0A);
	struct Eq_55661 Eq_17::* bp_31 = fn13C8_00BF();
	Eq_481 sp_39;
	sp_39.u0 = <invalid>;
	selector ss;
	(ss->*((word16) sp_39 + 2)).u1 = (ss->*bp_31).t000A.u2;
	(ss->*sp_39).u1 = (ss->*bp_31).t0006.u2;
	word16 bp_68 = ss->*fn13C8_00E4(out ds_57);
	dsOut = ds_57;
	return bp_68;
}
