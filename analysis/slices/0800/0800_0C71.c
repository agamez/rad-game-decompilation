// 0800:0C71: Register int16 fn0800_0C71(Register Eq_17 ds, Register out (memptr Eq_17 Eq_2579) bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
int16 fn0800_0C71(Eq_17 ds, struct Eq_2579 & bpOut, union Eq_17 & dsOut)
{
	mp16 fp;
	selector ds_23;
	Eq_17 wLoc06;
	Eq_17 wLoc04;
	word16 cx_212;
	word16 dx_24;
	word16 bx_213;
	Mem34[ds_23:22732:word16] = fn1EDA_098A(0x3C, Mem7[ds:22744:ui32], wLoc06, wLoc04, out cx_212, out dx_24, out bx_213, out ds_23);
	ds_23->w58CE = dx_24;
	Eq_17 cx_47;
	word16 dx_214;
	word16 bx_46;
	Eq_17 ds_110;
	fn1EDA_098A(0x3C, ds_23->t58D8, wLoc06, wLoc04, out cx_47, out dx_214, out bx_46, out ds_110);
	Mem61[ds_110:22748:word16] = cx_47;
	Mem62[ds_110:22750:word16] = bx_46;
	struct Eq_2579 Eq_17::* Eq_2575::* bp_106 = fp - 2;
	Eq_17 ax_63 = Mem62[ds_110:22748:word16];
	if (Mem62[ds_110:22750:word16] != Mem62[ds_110:22730:word16] || ax_63 != Mem62[ds_110:22728:word16])
	{
		bp_106 = fn0800_0AA1(ds_110, out ds_110);
		word16 dx_89 = Mem62[ds_110:22750:word16];
		Mem90[ds_110:22728:word16] = Mem62[ds_110:22748:word16];
		Mem91[ds_110:22730:word16] = dx_89;
	}
	Eq_17 ax_94 = Mem93[ds_110:22732:word16];
	int16 dx_122 = Mem93[ds_110:22734:word16];
	if (dx_122 != Mem93[ds_110:22726:word16] || ax_94 != Mem93[ds_110:22724:word16])
	{
		bp_106 = fn0800_0B42(ds_110, out ds_110);
		dx_122 = Mem93[ds_110:22734:word16];
		Mem123[ds_110:22724:word16] = Mem93[ds_110:22732:word16];
		Mem124[ds_110:22726:word16] = dx_122;
	}
	if (Mem126[ds_110:22746:word16] < 0x00 || Mem126[ds_110:22746:word16] <= 0x00 && Mem126[ds_110:22744:word16] <=u 0x00)
		dx_122 = fn0800_08E9(dx_122, ds_110);
	selector ss;
	bpOut = (struct Eq_2579 Eq_17::*) (ss->*bp_106);
	dsOut = ds_110;
	return dx_122;
}
