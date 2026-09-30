// 1206:000D: Register word16 fn1206_000D(Register out word16 siOut, Register out (ptr16 Eq_51032) esOut, Register out (ptr16 Eq_51000) dsOut)
// Called from:
//      fn1206_01AC
word16 fn1206_000D(word16 & siOut, struct Eq_51032 & esOut, struct Eq_51000 & dsOut)
{
	<unknown> Eq_50985::* fp;
	byte ch_60;
	word16 dx_61;
	struct Eq_50994 Eq_50985::* bp_23;
	word16 si_30;
	selector es_62;
	struct Eq_51000 * ds_27;
	fn1E5F_000B(fp - 22, out ch_60, out dx_61, out bp_23, out si_30, out es_62, out ds_27);
	struct Eq_50985 * ss;
	*(ss->*bp_23).ptr000A = (ss->*bp_23).wFFEC;
	word16 * es_di_43 = (ss->*bp_23).ptr0006;
	*es_di_43 = (ss->*bp_23).wFFEE;
	word16 bp_48 = (ss->*bp_23).w0000;
	siOut = si_30;
	esOut = SLICE(es_di_43, selector, 16);
	dsOut = ds_27;
	return bp_48;
}
