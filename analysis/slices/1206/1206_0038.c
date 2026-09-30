// 1206:0038: Register byte fn1206_0038(Register Eq_17 ds, Register out byte chOut, Register out word16 dxOut, Register out (memptr Eq_17 Eq_1654) bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0800_09C2
//      fn0800_0AA1
//      fn0800_0B42
//      fn0800_11EF
//      fn0800_184C
//      fn0800_19E1
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_391E
//      fn0800_3D9D
//      fn0C74_011E
//      fn0C74_020C
byte fn1206_0038(Eq_17 ds, byte & chOut, word16 & dxOut, struct Eq_1654 & bpOut, union Eq_17 & dsOut)
{
	struct Eq_51050 * ss;
	mp16 fp;
	struct Eq_1654 Eq_17::* Eq_51050::* bp_25 = fp - 2;
	word16 ax;
	word16 dx;
	if (Mem7[ds:22910:byte] != 0x00 && Mem7[ds:22924:byte] == 0x00)
	{
		Mem15[ds:22924:byte] = 0x01;
		byte ch_84;
		word16 si_85;
		selector es_86;
		ax = fn1E5F_000B(fp - 22, out ch_84, out dx, out bp_25, out si_85, out es_86, out ds);
	}
	struct Eq_1654 Eq_17::* bp_43 = (struct Eq_1654 Eq_17::*) (ss->*bp_25);
	chOut = <invalid>;
	dxOut = dx;
	bpOut = bp_43;
	dsOut = ds;
	return SLICE(ax, byte, 8);
}
