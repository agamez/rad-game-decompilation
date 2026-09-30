// 1206:0066: Register byte fn1206_0066(Register Eq_17 ds, Register out (memptr Eq_17 Eq_1654) bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0800_09C2
//      fn0800_0AA1
//      fn0800_0B42
//      fn0800_11EF
//      fn0800_184C
//      fn0800_19E1
//      fn0800_1E3F
//      fn0800_2004
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
//      fn0800_391E
//      fn0800_3D9D
//      fn0C74_011E
//      fn0C74_020C
byte fn1206_0066(Eq_17 ds, struct Eq_1654 & bpOut, union Eq_17 & dsOut)
{
	mp16 fp;
	struct Eq_1654 Eq_17::* Eq_51050::* bp_25 = fp - 2;
	word16 ax;
	if (Mem7[ds:22910:byte] != 0x00 && Mem7[ds:22924:byte] != 0x00)
	{
		Mem15[ds:22924:byte] = 0x00;
		byte ch_82;
		word16 dx_83;
		word16 si_84;
		selector es_85;
		ax = fn1E5F_000B(fp - 22, out ch_82, out dx_83, out bp_25, out si_84, out es_85, out ds);
	}
	struct Eq_51050 * ss;
	bpOut = (struct Eq_1654 Eq_17::*) (ss->*bp_25);
	dsOut = ds;
	return SLICE(ax, byte, 8);
}
