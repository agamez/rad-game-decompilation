// 0800:03F8: Register Eq_17 fn0800_03F8(Register Eq_17 ds)
// Called from:
//      fn0800_4255
Eq_17 fn0800_03F8(Eq_17 ds)
{
	Eq_17 ds_139;
	Eq_17 ds_16 = fn0800_0147(ds);
	struct Eq_653 * cs;
	word16 dx_333;
	if (fn0C74_0000(ds_16, &cs->t03DD, out dx_333) == 0x00)
		ds_16 = fn13E2_0193(ds_16, (char *) &cs->t03DD + 8);
	<unknown> Eq_664::* fp;
	fn1EDA_0FA2(&cs->t03DD, fp - 0x84);
	struct Eq_664 * ss;
	word16 dx_334;
	fn1EDA_0FD0(ds_16, Mem98[ds_16:0x04:word16], SEQ(ss, fp - 0x84), out dx_334);
	Eq_17 ax_121 = fn1AB8_13A3(ds_16, 0x2B, 0x2B, 0x00, 0x00);
	Eq_17 wLoc8E_293;
	wLoc8E_293.u0 = 0x00;
	Eq_17 wLoc90_294;
	wLoc90_294.u0 = 0x2B;
	word32 dx_ax_332 = fn1EDA_023F(ds_16, 0x2B, 0x00, Mem131[ds_16:0x04:word16], out ds_139);
	uint8 bLoc03_300 = 0x00;
	Eq_17 di_208;
	while (true)
	{
		fn0C74_00B2(ds_139, 0x05);
		Eq_17 dx_ax_335 = fn1EDA_023F(ds_139, wLoc90_294, wLoc8E_293, ax_121, out ds_139);
		uint16 ax_188 = (uint16) bLoc03_300;
		(*((word32) ds_139 + 0x00005388))[ax_188].w0000 = (word16) dx_ax_335;
		(*((word32) ds_139 + 0x0000538A))[ax_188].w0000 = SLICE(dx_ax_335, word16, 16);
		segptr32 es_di_203 = (*((word32) ds_139 + 0x00005388))[(uint16) bLoc03_300];
		fn1EDA_10BB(ds_139, 0x00, 0x01, fp - 0x84);
		wLoc8E_293 = fp - 0x84;
		di_208 = (word16) es_di_203;
		wLoc90_294.u3 = SLICE(es_di_203, selector, 16);
		if (bLoc03_300 == 0x10)
			break;
		++bLoc03_300;
	}
	word16 dx_336;
	Eq_17 ds_249;
	fn1EDA_1051(SLICE(fn1EDA_0254(ds_139, 0x01, di_208, Mem241[ds_139:0x04:word16], dx_ax_332, out dx_336, out ds_249), byte, 0), ds_249, SEQ(ss, fp - 0x84));
	return ds_249;
}
