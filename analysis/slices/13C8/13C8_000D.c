// 13C8:000D: Register word16 fn13C8_000D(Register out (ptr16 Eq_55639) dsOut)
// Called from:
//      fn133F_0056
//      fn13C8_0139
word16 fn13C8_000D(struct Eq_55639 & dsOut)
{
	<unknown> Eq_57058::* fp;
	byte ch_58;
	word16 dx_59;
	struct Eq_57067 Eq_57058::* bp_23;
	word16 si_60;
	selector es_61;
	struct Eq_55639 * ds_27;
	fn1E5F_000B(fp - 22, out ch_58, out dx_59, out bp_23, out si_60, out es_61, out ds_27);
	struct Eq_57058 * ss;
	*(ss->*bp_23).ptr000A = (ss->*bp_23).wFFEC;
	*(ss->*bp_23).ptr0006 = (ss->*bp_23).wFFEE;
	word16 bp_48 = (ss->*bp_23).w0000;
	dsOut = ds_27;
	return bp_48;
}
