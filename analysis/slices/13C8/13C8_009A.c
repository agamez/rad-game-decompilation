// 13C8:009A: Register word16 fn13C8_009A(Register out (memptr Eq_17 Eq_56253) bpOut, Register out (ptr16 Eq_56256) dsOut)
// Called from:
//      fn133F_04DE
//      fn133F_0528
word16 fn13C8_009A(struct Eq_56253 & bpOut, struct Eq_56256 & dsOut)
{
	<unknown> Eq_57216::* fp;
	byte ch_53;
	word16 dx_28;
	struct Eq_56253 Eq_17::* Eq_57216::* bp_23;
	word16 si_54;
	selector es_55;
	struct Eq_56256 * ds_27;
	fn1E5F_000B(fp - 22, out ch_53, out dx_28, out bp_23, out si_54, out es_55, out ds_27);
	struct Eq_57216 * ss;
	bpOut = (struct Eq_56253 Eq_17::*) (ss->*bp_23);
	dsOut = ds_27;
	return dx_28;
}
