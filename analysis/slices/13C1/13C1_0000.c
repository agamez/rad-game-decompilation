// 13C1:0000: Register word16 fn13C1_0000(Register out (ptr16 Eq_57006) dsOut)
// Called from:
//      fn13C1_0067
word16 fn13C1_0000(struct Eq_57006 & dsOut)
{
	Eq_17 ss;
	<unknown> Eq_17::* fp;
	byte ch_80;
	word16 dx_81;
	struct Eq_56961 Eq_17::* bp_19;
	word16 si_82;
	selector es_83;
	selector ds_84;
	fn1E5F_000B(SEQ(ss, fp - 22), out ch_80, out dx_81, out bp_19, out si_82, out es_83, out ds_84);
	(ss->*bp_19).bFFED = 0x03;
	Eq_481 sp_27;
	sp_27.u0 = <invalid>;
	ss->*((word16) sp_27 - 2) = 0x10;
	ss->*((word16) sp_27 - 4) = ss;
	ss->*((word16) sp_27 - 6) = bp_19 - 20;
	byte ch_85;
	word16 dx_86;
	struct Eq_57000 Eq_17::* bp_42;
	word16 si_87;
	selector es_88;
	struct Eq_57006 * ds_46;
	fn1E5F_000B(ss->*((word16) sp_27 - 6), out ch_85, out dx_86, out bp_42, out si_87, out es_88, out ds_46);
	ds_46->wB6A8 = (uint16) (ss->*bp_42).bFFF1;
	ds_46->wB6AA = (uint16) (ss->*bp_42).bFFF0;
	word16 bp_68 = (ss->*bp_42).w0000;
	dsOut = ds_46;
	return bp_68;
}
