// 0800:3850: Register byte fn0800_3850(Register Eq_17 ds, Register out byte chOut, Register out word16 bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0800_391E
byte fn0800_3850(Eq_17 ds, byte & chOut, word16 & bpOut, union Eq_17 & dsOut)
{
	mp16 fp;
	struct Eq_15102 Eq_15110::* bp_10 = fp - 2;
	mp16 sp_12 = fp - 0x0C;
	struct Eq_15110 * ss;
	do
	{
		struct Eq_15108 Eq_15110::* sp_13 = sp_12 - 2;
		(ss->*sp_13).ptr0000 = ss;
		(ss->*sp_13).wFFFE = bp_10 - 4;
		(ss->*sp_13).ptrFFFC = ss;
		(ss->*sp_13).wFFFA = bp_10 - 6;
		(ss->*sp_13).ptrFFF8 = ss;
		(ss->*sp_13).wFFF6 = bp_10 - 8;
		word16 dx_152;
		fn1206_0094(ds, out dx_152, out bp_10, out ds);
		Eq_481 sp_38;
		sp_38.u0 = <invalid>;
		sp_12 = (word16) sp_38 + 0x0C;
	} while ((ss->*bp_10).wFFFC != 0x00);
	(ss->*bp_10).bFFFF = 0x00;
	(ss->*bp_10).bFFF7 = 0x01;
	while ((*((word32) ds + 21474))[(uint16) (ss->*bp_10).bFFF7] >= (ss->*bp_10).wFFFA || ((*((word32) ds + 21502))[(uint16) (ss->*bp_10).bFFF7] <= (ss->*bp_10).wFFFA || ((*((word32) ds + 21488))[(uint16) (ss->*bp_10).bFFF7] >= (ss->*bp_10).wFFF8 || (*((word32) ds + 21516))[(uint16) (ss->*bp_10).bFFF7] <= (ss->*bp_10).wFFF8)))
	{
		if ((ss->*bp_10).bFFF7 == 0x02)
			goto l0800_38D9;
		++(ss->*bp_10).bFFF7;
	}
	Mem100[ss:bp_10 + -1:byte] = Mem50[ds:CONVERT(Mem50[ss:bp_10 + -9:byte], uint8, uint16) + 19719:byte];
l0800_38D9:
	byte al_104 = (ss->*bp_10).bFFFF;
	word16 bp_106 = (ss->*bp_10).w0000;
	chOut = <invalid>;
	bpOut = bp_106;
	dsOut = ds;
	return al_104;
}
