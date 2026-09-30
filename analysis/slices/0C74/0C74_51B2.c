// 0C74:51B2: Register Eq_17 fn0C74_51B2(Register Eq_17 ds)
// Called from:
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
Eq_17 fn0C74_51B2(Eq_17 ds)
{
	mp16 fp;
	struct Eq_49321 Eq_49368::* bp_129 = fp - 2;
	word16 ax_12 = Mem10[ds:22888:word16];
	switch (ax_12)
	{
	case 0x01:
		byte dl_260;
		byte dl_261;
		if (fn1AB8_1E3C(ds, Mem84[ds:22714:word16] + 0x01, Mem10[ds:22710:word16] + 0x01, out dl_260) != 0x00 || fn1AB8_1E3C(ds, Mem108[ds:22714:word16] + 0x01, Mem89[ds:22710:word16] + 0x17, out dl_261) != 0x00)
			return ds;
		bp_129 = fn0C74_2AD9(ds, out ds);
		break;
	case ~0x00:
		byte dl_262;
		byte dl_263;
		if (fn1AB8_1E3C(ds, Mem20[ds:22714:word16] + 0x01, Mem10[ds:22708:word16] - 0x01, out dl_262) != 0x00 || fn1AB8_1E3C(ds, Mem44[ds:22714:word16] + 0x01, Mem25[ds:22708:word16] - 0x17, out dl_263) != 0x00)
			return ds;
		bp_129 = fn0C74_2AD9(ds, out ds);
		break;
	}
	selector ss;
	(ss->*bp_129).bFFFF = 0x01;
	return ds;
}
