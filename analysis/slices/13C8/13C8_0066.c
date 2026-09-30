// 13C8:0066: Register word16 fn13C8_0066(Register out (memptr Eq_17 Eq_56329) bpOut, Register out (ptr16 Eq_56331) dsOut)
// Called from:
//      fn133F_0528
//      fn13C8_0139
word16 fn13C8_0066(struct Eq_56329 & bpOut, struct Eq_56331 & dsOut)
{
	<unknown> Eq_57159::* fp;
	byte ch_60;
	word16 dx_24;
	struct Eq_57168 Eq_57159::* bp_19;
	word16 si_61;
	selector es_62;
	struct Eq_56331 * ds_23;
	fn1E5F_000B(fp - 22, out ch_60, out dx_24, out bp_19, out si_61, out es_62, out ds_23);
	struct Eq_57159 * ss;
	*(ss->*bp_19).ptr000A = (ss->*bp_19).wFFF0;
	*(ss->*bp_19).ptr0006 = (ss->*bp_19).wFFF2;
	*(ss->*bp_19).ptr000E = (ss->*bp_19).wFFEE;
	bpOut = (ss->*bp_19).ptr0000;
	dsOut = ds_23;
	return dx_24;
}
