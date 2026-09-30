// 13C8:0038: Register byte fn13C8_0038(Register out word16 dxOut, Register out word16 bpOut, Register out (ptr16 Eq_55711) dsOut)
// Called from:
//      fn133F_0141
byte fn13C8_0038(word16 & dxOut, word16 & bpOut, struct Eq_55711 & dsOut)
{
	struct Eq_57105 * ss;
	struct Eq_55711 * ds_23;
	selector es_48;
	word16 si_47;
	word16 Eq_57105::* bp_19;
	word16 dx_24;
	byte ch_46;
	<unknown> Eq_57105::* fp;
	word16 ax_18 = fn1E5F_000B(fp - 22, out ch_46, out dx_24, out bp_19, out si_47, out es_48, out ds_23);
	word16 bp_34 = ss->*bp_19;
	dxOut = dx_24;
	bpOut = bp_34;
	dsOut = ds_23;
	return SLICE(ax_18, byte, 8);
}
