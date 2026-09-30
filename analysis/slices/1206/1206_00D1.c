// 1206:00D1: Register word16 fn1206_00D1(Register (ptr16 Eq_13558) ds, Register out word16 siOut, Register out (ptr16 Eq_13580) esOut, Register out (ptr16 Eq_13558) dsOut)
// Called from:
//      fn0800_31B7
//      fn0800_4255
//      fn1206_01AC
word16 fn1206_00D1(struct Eq_13558 * ds, word16 & siOut, struct Eq_13580 & esOut, struct Eq_13558 & dsOut)
{
	struct Eq_51195 * ss;
	<unknown> Eq_51195::* fp;
	word16 Eq_51195::* bp_26 = fp - 2;
	word16 si;
	struct Eq_13580 * es;
	if (ds->b597E != 0x00)
	{
		byte ch_85;
		word16 dx_86;
		fn1E5F_000B(fp - 22, out ch_85, out dx_86, out bp_26, out si, out es, out ds);
	}
	word16 bp_44 = ss->*bp_26;
	siOut = si;
	esOut = es;
	dsOut = ds;
	return bp_44;
}
