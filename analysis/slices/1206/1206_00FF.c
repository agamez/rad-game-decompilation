// 1206:00FF: Register word16 fn1206_00FF(Register Eq_17 ds, Register out Eq_17 dsOut)
// Called from:
//      fn0800_31B7
//      fn0800_4255
//      fn1206_01AC
word16 fn1206_00FF(Eq_17 ds, union Eq_17 & dsOut)
{
	struct Eq_51226 * ss;
	<unknown> Eq_51226::* fp;
	word16 Eq_51226::* bp_26 = fp - 2;
	if (Mem7[ds:22910:byte] != 0x00)
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
