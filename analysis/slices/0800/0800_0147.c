// 0800:0147: Register Eq_17 fn0800_0147(Register Eq_17 ds)
// Called from:
//      fn0800_03F8
Eq_17 fn0800_0147(Eq_17 ds)
{
	Eq_17 ax_19 = fn1AB8_13A3(ds, 0x15, 0x15, 0x00, 0x00);
	struct Eq_182 * cs;
	word16 dx_270;
	if (fn0C74_0000(ds, &cs->t0125, out dx_270) == 0x00)
		ds = fn13E2_0193(ds, (char *) &cs->t0125 + 8);
	<unknown> Eq_197::* fp;
	fn1EDA_0FA2(&cs->t0125, fp - 0x84);
	word16 dx_271;
	fn1EDA_0FD0(ds, ax_19, fp - 0x84, out dx_271);
	Eq_17 wLoc8C_242 = ax_19;
	uint8 bLoc03_244 = 0x00;
	word16 ax_194;
	while (true)
	{
		fn0C74_00B2(ds, 0x02);
		Eq_17 dx_ax_272 = fn1EDA_023F(ds, wLoc8C_242, fp - 0x84, ax_19, out ds);
		uint16 ax_157 = (uint16) bLoc03_244;
		ds.u3->ptr5992[ax_157].w0000 = (word16) dx_ax_272;
		(*((word32) ds + 22932))[ax_157].w0000 = SLICE(dx_ax_272, word16, 16);
		wLoc8C_242.u5 = (*((word32) ds + 22932))[(uint16) bLoc03_244].u5;
		ax_194 = fn1EDA_10BB(ds, 0x00, 0x01, fp - 0x84);
		if (bLoc03_244 == 199)
			break;
		++bLoc03_244;
	}
	fn1EDA_1051((byte) ax_194, ds, fp - 0x84);
	return ds;
}
