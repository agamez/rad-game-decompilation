// 0C43:0000: Register word16 fn0C43_0000(Register Eq_17 ds, Stack byte bArg02, Register out (ptr16 Eq_18934) dsOut)
// Called from:
//      fn0C43_00B9
word16 fn0C43_0000(Eq_17 ds, byte bArg02, struct Eq_18934 & dsOut)
{
	selector ss;
	Mem10[ds:22685:byte] = 0x00;
	Mem12[ds:22684:byte] = bArg02;
	byte ch_46;
	word16 dx_47;
	word16 Eq_18938::* bp_21;
	word16 si_48;
	selector es_49;
	struct Eq_18934 * ds_25;
	fn1E5F_000B(SEQ(ds, 22684), out ch_46, out dx_47, out bp_21, out si_48, out es_49, out ds_25);
	word16 bp_36 = ss->*bp_21;
	dsOut = ds_25;
	return bp_36;
}
