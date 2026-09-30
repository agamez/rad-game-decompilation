// 0C74:542B: Register byte fn0C74_542B(Register Eq_17 ds, Register out Eq_17 dsOut)
// Called from:
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
byte fn0C74_542B(Eq_17 ds, union Eq_17 & dsOut)
{
	mp16 fp;
	struct Eq_50236 Eq_50285::* bp_166 = fp - 2;
	word16 ax_12 = Mem10[ds:22888:word16];
	selector ss;
	switch (ax_12)
	{
	case 0x01:
		byte dl_277;
		byte dl_278;
		if (fn1AB8_1E3C(ds, Mem100[ds:22714:word16] + 0x01, Mem10[ds:22710:word16] + 0x01, out dl_277) == 0x00 && fn1AB8_1E3C(ds, Mem123[ds:22714:word16] - 0x01, Mem105[ds:22710:word16] + 0x01, out dl_278) == 0x00)
		{
			struct Eq_50280 Eq_50285::* bp_147;
			Eq_17 ds_151;
			(ss->*bp_147).bFFFF = fn0C74_4FD7(ds, out bp_147, out ds_151);
			word16 dx_279;
			fn0C74_3615(ds_151, out dx_279, out bp_166, out ds);
		}
		break;
	case ~0x00:
		byte dl_280;
		byte dl_281;
		if (fn1AB8_1E3C(ds, Mem20[ds:22714:word16] + 0x01, Mem10[ds:22708:word16] - 0x01, out dl_280) == 0x00 && fn1AB8_1E3C(ds, Mem43[ds:22714:word16] - 0x01, Mem25[ds:22708:word16] - 0x01, out dl_281) == 0x00)
		{
			struct Eq_50336 Eq_50285::* bp_68;
			Eq_17 ds_72;
			(ss->*bp_68).bFFFF = fn0C74_4DAC(ds, out bp_68, out ds_72);
			word16 dx_282;
			fn0C74_37C3(ds_72, out dx_282, out bp_166, out ds);
		}
		break;
	}
	byte al_182 = (ss->*bp_166).bFFFF;
	dsOut = ds;
	return al_182;
}
