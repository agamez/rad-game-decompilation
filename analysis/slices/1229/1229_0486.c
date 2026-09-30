// 1229:0486: Register Eq_17 fn1229_0486(Register Eq_17 ds)
// Called from:
//      fn1229_0DCC
Eq_17 fn1229_0486(Eq_17 ds)
{
	struct Eq_51946 * cs;
	Eq_17 ss;
	<unknown> Eq_17::* fp;
	fn1EDA_0FA2(&cs->t047E, SEQ(ss, fp - 0x0082));
	word16 dx_215;
	fn1EDA_0FD0(ds, 0x0219, SEQ(ss, fp - 0x0082), out dx_215);
	fn1EDA_1085(fn1EDA_1123(ds, Mem58[ds:22926:word16], Mem55[ds:22928:word16], SEQ(ss, fp - 0x0082)), ds, SEQ(ss, fp - 0x0082));
	uint16 ax_97 = fn1EDA_04A2(ds);
	uint16 ax_102 = ax_97;
	if (ax_97 != 0x00)
	{
		Mem112[ds:22926:ui32] = Mem108[ds:22926:ui32] - 0x01;
		fn1E78_02C7(0x96);
		word16 dx_219;
		fn1E78_029C(ds, 500, out dx_219);
		ax_102 = (uint16) fn1E78_02F4();
	}
	fn1EDA_1051((byte) ax_102, ds, SEQ(ss, fp - 0x0082));
	byte ch_218;
	Eq_17 ds_168;
	fn1EDA_04A9(ds, fp - 0x0082, ss, out ch_218, out ds_168);
	return ds_168;
}
