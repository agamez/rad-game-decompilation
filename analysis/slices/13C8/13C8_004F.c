// 13C8:004F: Register byte fn13C8_004F(Register out word16 dxOut, Register out word16 bpOut, Register out (ptr16 Eq_55691) dsOut)
// Called from:
//      fn133F_0137
byte fn13C8_004F(word16 & dxOut, word16 & bpOut, struct Eq_55691 & dsOut)
{
	struct Eq_57132 * ss;
	struct Eq_55691 * ds_23;
	selector es_48;
	word16 si_47;
	word16 Eq_57132::* bp_19;
	word16 dx_24;
	byte ch_46;
	<unknown> Eq_57132::* fp;
	word16 ax_18 = fn1E5F_000B(fp - 22, out ch_46, out dx_24, out bp_19, out si_47, out es_48, out ds_23);
	word16 bp_34 = ss->*bp_19;
	dxOut = dx_24;
	bpOut = bp_34;
	dsOut = ds_23;
	return SLICE(ax_18, byte, 8);
}
