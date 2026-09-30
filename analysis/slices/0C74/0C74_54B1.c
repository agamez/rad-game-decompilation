// 0C74:54B1: Register byte fn0C74_54B1(Register Eq_17 ds, Register out word16 dxOut, Register out word16 bpOut, Register out (ptr16 Eq_9207) dsOut)
// Called from:
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
//      fn0800_3D9D
byte fn0C74_54B1(Eq_17 ds, word16 & dxOut, word16 & bpOut, struct Eq_9207 & dsOut)
{
	Mem11[ds:22716:byte] = 0x01;
	byte dl_114;
	byte dl_115;
	if (fn1AB8_1E3C(ds, Mem15[ds:22714:word16] + 0x01, Mem11[ds:22710:word16] + 0x01, out dl_114) == 0x00 && fn1AB8_1E3C(ds, Mem39[ds:22714:word16] + 0x01, Mem20[ds:22710:word16] + 0x17, out dl_115) != 0x00)
		fn0C74_2AD9(ds, out ds);
	selector ss;
	struct Eq_50376 Eq_50381::* bp_83;
	word16 dx_81;
	struct Eq_9207 * ds_86;
	(ss->*bp_83).bFFFF = fn0C74_3615(ds, out dx_81, out bp_83, out ds_86);
	byte al_95 = (ss->*bp_83).bFFFF;
	word16 bp_97 = (ss->*bp_83).w0000;
	dxOut = dx_81;
	bpOut = bp_97;
	dsOut = ds_86;
	return al_95;
}
