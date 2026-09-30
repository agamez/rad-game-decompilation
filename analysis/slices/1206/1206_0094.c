// 1206:0094: Register byte fn1206_0094(Register Eq_17 ds, Register out word16 dxOut, Register out mp16 bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0800_1D55
//      fn0800_3850
//      fn1206_015B
//      fn1206_01AC
byte fn1206_0094(Eq_17 ds, word16 & dxOut, mp16 & bpOut, union Eq_17 & dsOut)
{
	<unknown> Eq_51129::* fp;
	struct Eq_51121 Eq_51129::* bp_22 = fp - 2;
	word16 dx;
	struct Eq_51129 * ss;
	Eq_481 cx;
	if (Mem7[ds:22910:byte] != 0x00)
	{
		byte ch_92;
		word16 si_93;
		selector es_94;
		fn1E5F_000B(fp - 22, out ch_92, out dx, out bp_22, out si_93, out es_94, out ds);
		*(ss->*bp_22).ptr000A = (ss->*bp_22).wFFF0;
		*(ss->*bp_22).ptr0006 = (ss->*bp_22).wFFF2;
		*(ss->*bp_22).ptr000E = (ss->*bp_22).wFFEE;
		cx.u0 = <invalid>;
	}
	mp16 bp_55 = (ss->*bp_22).w0000;
	dxOut = dx;
	bpOut = bp_55;
	dsOut = ds;
	return SLICE(cx, byte, 8);
}
