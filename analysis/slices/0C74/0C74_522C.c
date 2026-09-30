// 0C74:522C: Register byte fn0C74_522C(Register Eq_17 ds, Register out word16 bpOut, Register out (ptr16 Eq_1528) dsOut)
// Called from:
//      fn0800_08C0
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
byte fn0C74_522C(Eq_17 ds, word16 & bpOut, struct Eq_1528 & dsOut)
{
	struct Eq_1528 * ds_57;
	word16 ax_12 = Mem10[ds:22888:word16];
	selector ss;
	switch (ax_12)
	{
	case 0x01:
		struct Eq_49419 Eq_49423::* bp_38;
		(ss->*bp_38).bFFFF = fn0C74_3236(ds, out bp_38, out ds);
		break;
	case ~0x00:
		struct Eq_49444 Eq_49423::* bp_22;
		(ss->*bp_22).bFFFF = fn0C74_2E5A(ds, out bp_22, out ds);
		break;
	}
	Eq_17 bp_61 = fn0C74_05B8(ds, out ds_57);
	byte al_68 = (byte) (ss->*((word32) bp_61 - 1));
	bpOut = (ss->*bp_61.u3).t0000.u2;
	dsOut = ds_57;
	return al_68;
}
