// 133F:0137: Register byte fn133F_0137(Register out word16 dxOut, Register out word16 bpOut, Register out (ptr16 Eq_52242) dsOut)
// Called from:
//      fn1229_0735
//      fn1229_0CCE
//      fn1229_0DCC
byte fn133F_0137(word16 & dxOut, word16 & bpOut, struct Eq_52242 & dsOut)
{
	selector ss;
	word16 dx_15;
	word16 Eq_55694::* bp_10;
	struct Eq_52242 * ds_14;
	fn13C8_004F(out dx_15, out bp_10, out ds_14);
	word16 bp_25 = ss->*bp_10;
	dxOut = dx_15;
	bpOut = bp_25;
	dsOut = ds_14;
	return 0x00;
}
