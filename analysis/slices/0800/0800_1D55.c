// 0800:1D55: Register byte fn0800_1D55(Register Eq_17 ds, Register out word16 dxOut, Register out (memptr Eq_17 Eq_6491) bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0800_3D9D
byte fn0800_1D55(Eq_17 ds, word16 & dxOut, struct Eq_6491 & bpOut, union Eq_17 & dsOut)
{
	mp16 fp;
	struct Eq_6338 Eq_6346::* bp_10 = fp - 2;
	mp16 sp_12 = fp - 0x0C;
	struct Eq_6346 * ss;
	word16 dx_35;
	do
	{
		struct Eq_6344 Eq_6346::* sp_13 = sp_12 - 2;
		(ss->*sp_13).ptr0000 = ss;
		(ss->*sp_13).wFFFE = bp_10 - 4;
		(ss->*sp_13).ptrFFFC = ss;
		(ss->*sp_13).wFFFA = bp_10 - 6;
		(ss->*sp_13).ptrFFF8 = ss;
		(ss->*sp_13).wFFF6 = bp_10 - 8;
		fn1206_0094(ds, out dx_35, out bp_10, out ds);
		Eq_481 sp_38;
		sp_38.u0 = <invalid>;
		sp_12 = (word16) sp_38 + 0x0C;
	} while ((ss->*bp_10).wFFFC != 0x00);
	(ss->*bp_10).bFFFF = 0x00;
	(ss->*bp_10).bFFF7 = 0x01;
	while ((*((word32) ds + 21474))[(uint16) (ss->*bp_10).bFFF7] >= (ss->*bp_10).wFFFA || ((*((word32) ds + 21502))[(uint16) (ss->*bp_10).bFFF7] <= (ss->*bp_10).wFFFA || ((*((word32) ds + 21488))[(uint16) (ss->*bp_10).bFFF7] >= (ss->*bp_10).wFFF8 || (*((word32) ds + 21516))[(uint16) (ss->*bp_10).bFFF7] <= (ss->*bp_10).wFFF8)))
	{
		if ((ss->*bp_10).bFFF7 == 0x07)
			goto l0800_1DDB;
		++(ss->*bp_10).bFFF7;
	}
	(ss->*bp_10).bFFFF = (ss->*bp_10).bFFF7 + 0x3A;
l0800_1DDB:
	byte al_102 = (ss->*bp_10).bFFFF;
	struct Eq_6491 Eq_17::* bp_104 = (ss->*bp_10).ptr0000;
	dxOut = dx_35;
	bpOut = bp_104;
	dsOut = ds;
	return al_102;
}
