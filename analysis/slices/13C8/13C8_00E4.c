// 13C8:00E4: Register word16 fn13C8_00E4(Register out (ptr16 Eq_55676) dsOut)
// Called from:
//      fn133F_0056
//      fn133F_04B1
//      fn13C8_0139
word16 fn13C8_00E4(struct Eq_55676 & dsOut)
{
	struct Eq_57264 * ss;
	<unknown> Eq_57264::* fp;
	byte ch_52;
	word16 dx_53;
	word16 Eq_57264::* bp_23;
	word16 si_54;
	selector es_55;
	struct Eq_55676 * ds_27;
	fn1E5F_000B(fp - 22, out ch_52, out dx_53, out bp_23, out si_54, out es_55, out ds_27);
	word16 bp_38 = ss->*bp_23;
	dsOut = ds_27;
	return bp_38;
}
