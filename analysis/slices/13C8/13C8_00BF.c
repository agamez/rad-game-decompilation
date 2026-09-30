// 13C8:00BF: Register word16 fn13C8_00BF()
// Called from:
//      fn133F_0056
//      fn133F_04B1
//      fn13C8_0139
word16 fn13C8_00BF()
{
	<unknown> Eq_57240::* fp;
	byte ch_51;
	word16 dx_52;
	word16 Eq_57240::* bp_23;
	word16 si_53;
	selector es_54;
	selector ds_55;
	fn1E5F_000B(fp - 22, out ch_51, out dx_52, out bp_23, out si_53, out es_54, out ds_55);
	struct Eq_57240 * ss;
	return ss->*bp_23;
}
