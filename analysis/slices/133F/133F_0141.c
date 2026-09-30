// 133F:0141: Register byte fn133F_0141(Register out int16 dxOut, Register out word16 bpOut, Register out (ptr16 Eq_53309) dsOut)
// Called from:
//      fn1229_0735
//      fn1229_0DCC
//      fn133F_04DE
byte fn133F_0141(int16 & dxOut, word16 & bpOut, struct Eq_53309 & dsOut)
{
	selector ss;
	int16 dx_15;
	word16 Eq_55714::* bp_10;
	struct Eq_53309 * ds_14;
	fn13C8_0038(out dx_15, out bp_10, out ds_14);
	word16 bp_25 = ss->*bp_10;
	dxOut = dx_15;
	bpOut = bp_25;
	dsOut = ds_14;
	return 0x00;
}
