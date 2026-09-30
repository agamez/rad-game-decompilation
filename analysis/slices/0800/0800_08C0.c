// 0800:08C0: Register Eq_17 fn0800_08C0(Register Eq_17 ds)
// Called from:
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
Eq_17 fn0800_08C0(Eq_17 ds)
{
	struct Eq_1525 Eq_1534::* bp_16;
	if (Mem10[ds:0x53DB:byte] >u 0x00 && fn0C74_522C(ds, out bp_16, out ds) != 0x00)
	{
		selector ss;
		(ss->*bp_16).bFFFF = 0x01;
		Mem37[ds:0x53DB:byte] = Mem35[ds:0x53DB:byte] - 0x01;
	}
	return ds;
}
