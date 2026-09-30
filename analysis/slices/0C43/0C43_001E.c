// 0C43:001E: Register word16 fn0C43_001E(Register Eq_17 ds, Stack Eq_17 ptrArg02, Register out word16 bpOut, Register out (ptr16 Eq_18985) dsOut)
// Called from:
//      fn0C43_00B9
word16 fn0C43_001E(Eq_17 ds, Eq_17 ptrArg02, word16 & bpOut, struct Eq_18985 & dsOut)
{
	struct Eq_18985 * ds_38;
	selector es_63;
	word16 si_62;
	word16 Eq_18989::* bp_34;
	word16 dx_61;
	byte ch_60;
	Mem10[ds:22685:byte] = 0x10;
	Mem11[ds:22684:byte] = 0x12;
	Mem15[ds:22700:word16] = SLICE(ptrArg02, selector, 16);
	Mem19[ds:22690:word16] = SLICE(ptrArg02, word16, 0);
	Mem24[ds:22686:word16] = 0x00;
	Mem25[ds:22688:word16] = 0x0100;
	word16 ax_33 = fn1E5F_000B(SEQ(ds, 22684), out ch_60, out dx_61, out bp_34, out si_62, out es_63, out ds_38);
	selector ss;
	bpOut = ss->*bp_34;
	dsOut = ds_38;
	return ax_33;
}
