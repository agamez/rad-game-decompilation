// 0C74:03D4: Register Eq_17 fn0C74_03D4(Register Eq_17 ds)
// Called from:
//      fn0800_4255
Eq_17 fn0C74_03D4(Eq_17 ds)
{
	Eq_17 ds_211;
	struct Eq_20830 * cs;
	word16 dx_719;
	Eq_17 wLoc96;
	if (fn0C74_0000(ds, &cs->t03B2, out dx_719) == 0x00)
	{
		fn1AB8_0EB5(ds);
		fn1AB8_0E88(ds);
		word16 dx_721;
		fn1E78_016B(ds, Mem15[ds:47276:word16], out dx_721);
		Eq_17 ptrLoc90_591 = SEQ(ds, ~0x4643);
		Eq_481 cx_85;
		fn1EDA_08CE(ds, 0x00, (char *) &cs->t03B2 + 8, ptrLoc90_591, out cx_85);
		fn1EDA_0848(0x00, cx_85, ds, ptrLoc90_591);
		wLoc96.u0 = 0x00;
		ds = fn1EDA_00E9(0x00);
	}
	<unknown> Eq_20841::* fp;
	fn1EDA_0FA2(&cs->t03B2, fp - 0x84);
	struct Eq_20841 * ss;
	word16 dx_720;
	fn1EDA_0FD0(ds, Mem151[ds:0x4D0E:word16], SEQ(ss, fp - 0x84), out dx_720);
	Eq_17 ax_174 = fn1AB8_13A3(ds, 0x18, 0x2B, 0x00, 0x00);
	fn1AB8_13A3(ds, 0x2B, 0x2B, 0x00, 0x00);
	Eq_17 dx_ax_718 = fn1EDA_023F(ds, 0x2B, 0x00, Mem203[ds:0x4D0E:word16], out ds_211);
	Eq_17 wLoc92_610;
	wLoc92_610.u0 = 0x2B;
	Eq_17 dx_212;
	dx_212.u3 = SLICE(dx_ax_718, word16, 16);
	uint8 bLoc03_616 = 0x01;
	while (true)
	{
		fn0C74_00B2(ds_211, 0x05);
		if (bLoc03_616 >= 0x01 && bLoc03_616 <= 0x04)
		{
			Eq_17 dx_ax_722 = fn1EDA_023F(ds_211, wLoc92_610, 0x00, Mem226[ds_211:0x4D0E:word16], out ds_211);
			uint16 ax_469 = (uint16) bLoc03_616;
			ds_211.u3->t58E4.u3[ax_469].w0000 = (word16) dx_ax_722;
			(*((word32) ds_211 + 22758))[ax_469].w0000 = SLICE(dx_ax_722, word16, 16);
			fn1EDA_10BB(ds_211, 0x00, 0x01, fp - 0x84);
			wLoc96.u0 = 0x01;
		}
		else if (bLoc03_616 >= 0x05 && bLoc03_616 <= 0x19)
		{
			fn1EDA_10BB(ds_211, 0x00, 0x01, fp - 0x84);
			fn1AB8_13D7(ds_211, 0x00, dx_ax_718, 0x00, 0x00);
			Eq_17 dx_ax_723 = fn1EDA_023F(ds_211, dx_212, 0x00, ax_174, out ds_211);
			uint16 ax_410 = (uint16) bLoc03_616;
			(*((word32) ds_211 + 22788))[ax_410 - 0x04].w0000 = (word16) dx_ax_723;
			(*((word32) ds_211 + 22790))[ax_410 - 0x04].w0000 = SLICE(dx_ax_723, word16, 16);
			Eq_17 es_di_431;
			es_di_431.u3 = (*((word32) ds_211 + 22788))[(uint16) bLoc03_616 - 0x04].u3;
			fn1AB8_1E6B(ds_211, es_di_431, 0x18, 0x2B, 0x00, 0x00);
			wLoc96.u3 = SLICE(es_di_431, selector, 16);
		}
		else if (bLoc03_616 >= 0x1A && bLoc03_616 <= 0x1D)
		{
			Eq_17 dx_ax_726 = fn1EDA_023F(ds_211, wLoc92_610, 0x00, Mem226[ds_211:0x4D0E:word16], out ds_211);
			uint16 ax_287 = (uint16) bLoc03_616;
			(*((word32) ds_211 + 22772))[ax_287 - 0x19].w0000 = (word16) dx_ax_726;
			(*((word32) ds_211 + 22774))[ax_287 - 0x19].w0000 = SLICE(dx_ax_726, word16, 16);
			fn1EDA_10BB(ds_211, 0x00, 0x01, fp - 0x84);
			wLoc96.u0 = 0x01;
		}
		fn0C74_007C(ds_211, 44, 44, 0x00, 0x00);
		wLoc92_610.u0 = 44;
		if (bLoc03_616 == 0x1D)
			break;
		++bLoc03_616;
	}
	word16 dx_724;
	Eq_17 ds_552;
	fn1EDA_1051(SLICE(fn1EDA_0254(ds_211, wLoc96, 44, Mem543[ds_211:0x4D0E:word16], dx_ax_718, out dx_724, out ds_552), byte, 0), ds_552, SEQ(ss, fp - 0x84));
	return ds_552;
}
