// 0800:4168: Register Eq_17 fn0800_4168(Register Eq_17 ds)
// Called from:
//      fn0800_4255
Eq_17 fn0800_4168(Eq_17 ds)
{
	Eq_17 ds_123;
	byte ch_193;
	struct Eq_18126 * cs;
	word16 dx_189;
	if (fn0C74_0000(ds, &cs->t4160, out dx_189) == 0x00)
		ds = fn0800_0000(ds);
	Eq_17 ss;
	<unknown> Eq_17::* fp;
	fn1EDA_0FA2(&cs->t4160, SEQ(ss, fp - 0x0082));
	word16 dx_190;
	fn1EDA_0FD0(ds, 0x0219, SEQ(ss, fp - 0x0082), out dx_190);
	byte ch_192;
	Eq_17 ds_95;
	fn1EDA_04A9(ds, fp - 0x0082, ss, out ch_192, out ds_95);
	Eq_17 ds_113;
	fn1EDA_116A(ds_95, SEQ(ss, fp - 0x0082), out ds_113);
	word16 ax_120 = (word16) fn1EDA_04A9(ds_113, fp - 0x0082, ss, out ch_193, out ds_123);
	Mem136[ds_123:23730:byte] = SLICE(ax_120, byte, 0) - 0x02;
	fn1EDA_1051((byte) ax_120 - 0x02, ds_123, SEQ(ss, fp - 0x0082));
	byte ch_196;
	Eq_17 ds_154;
	fn1EDA_04A9(ds_123, fp - 0x0082, ss, out ch_196, out ds_154);
	return ds_154;
}
