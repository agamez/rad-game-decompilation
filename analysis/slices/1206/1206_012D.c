// 1206:012D: Register word16 fn1206_012D(Register (ptr16 Eq_13540) ds, Register out (ptr16 Eq_13540) dsOut)
// Called from:
//      fn0800_31B7
//      fn0800_4255
//      fn1206_01AC
word16 fn1206_012D(struct Eq_13540 * ds, struct Eq_13540 & dsOut)
{
	struct Eq_51257 * ss;
	<unknown> Eq_51257::* fp;
	word16 Eq_51257::* bp_26 = fp - 2;
	if (ds->b597E != 0x00)
	{
		byte ch_83;
		word16 dx_84;
		word16 si_85;
		selector es_86;
		fn1E5F_000B(fp - 22, out ch_83, out dx_84, out bp_26, out si_85, out es_86, out ds);
	}
	word16 bp_44 = ss->*bp_26;
	dsOut = ds;
	return bp_44;
}
