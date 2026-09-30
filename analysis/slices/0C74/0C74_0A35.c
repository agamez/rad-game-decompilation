// 0C74:0A35: Register word16 fn0C74_0A35(Register Eq_17 ds)
// Called from:
//      fn0800_08E9
//      fn0800_3D9D
//      fn0C74_0FA1
//      fn0C74_1F08
word16 fn0C74_0A35(Eq_17 ds)
{
	word16 dx_798;
	word16 dx_796;
	word16 dx_355;
	byte dl_96;
	word16 dx_78;
	word16 dx_794;
	Eq_3872 wLoc08_514;
	wLoc08_514.u0 = 0x00;
	cu16 ax_14 = Mem11[ds:22714:word16] - Mem11[ds:22712:word16];
	cup16 wLoc30EC_516;
	if (ax_14 >> 0x01 < 0x17)
		wLoc30EC_516 = 25000;
	else
		wLoc30EC_516 = 50000;
	Eq_17 ax_23 = Mem22[ds:22708:word16];
	word16 ax_29 = Mem27[ds:22712:word16] + (ax_14 >>u 0x01);
	word16 dx;
	struct Eq_21875 * ss;
	<unknown> Eq_21875::* fp;
	if (wLoc30EC_516 < 0x01)
	{
l0C74_0CA3:
		if (wLoc08_514 != 0x00 && wLoc08_514 >= 0x01)
		{
			Eq_3872 wLoc0A_629;
			wLoc0A_629.u0 = 0x01;
			while (true)
			{
				byte dh_740 = SLICE(dx, byte, 8);
				if ((&(ss->*((char *) fp + 55516)))[wLoc0A_629].w0000 != 500)
					dx = SEQ(dh_740, fn1AB8_1E54(ds, 0x00, (&(ss->*((char *) fp + 55516)))[wLoc0A_629].u2, (&(ss->*((char *) fp + 55514)))[wLoc0A_629].u2));
				if (wLoc0A_629 == wLoc08_514)
					break;
				wLoc0A_629 = (word16) wLoc0A_629 + 1;
			}
		}
		Mem500[ds:22707:byte] = 0x01;
		return dx;
	}
	cup16 wLoc06_523 = 0x01;
l0C74_0A8F:
	cup16 ax_52 = (cup16) (&fn1EDA_0D80(ds, 0x2D, out dx_794).u3->t0000.u0 + ((word32) ax_23 + 21));
	Eq_17 wLoc10_526 = ax_52 - 0x15;
	if ((word32) ax_23 + 30 < ax_52 - 0x15)
		wLoc10_526 = ax_52 - 22;
	Eq_17 ax_85 = &fn1EDA_0D80(ds, __align(ax_14, 2) + 0x02, out dx_78).u3->t0000.u0 + ax_29 - (ax_14 >> 0x01);
	byte al_103 = (byte) fn1AB8_1E3C(ds, ax_85, wLoc10_526, out dl_96);
	dx = SEQ(SLICE(dx_78, byte, 8), dl_96);
	if (al_103 == 0x00)
	{
		if (wLoc08_514 == 0x00)
			goto l0C74_0C97;
		Eq_17 ax_317 = fn1EDA_0D80(ds, wLoc08_514, out dx);
		if ((&(ss->*((char *) fp + 55516)))[&ax_317.u3->t0001.u0].w0000 != 500)
		{
			fn1AB8_1E54(ds, 0x00, (&(ss->*((char *) fp + 55516)))[&ax_317.u3->t0001.u0].u2, (&(ss->*((char *) fp + 55514)))[&ax_317.u3->t0001.u0].u2);
			byte dh_735 = SLICE(dx_355, byte, 8);
			dx = dx_355;
			if (fn1EDA_0D80(ds, 0x14, out dx_355) != 0x01)
			{
				byte dl_379;
				dx = SEQ(dh_735, dl_379);
				if (fn1AB8_1E3C(ds, (&(ss->*((char *) fp + 55516)))[&ax_317.u3->t0001.u0].w0000 + 0x01, (&(ss->*((char *) fp + 55514)))[&ax_317.u3->t0001.u0].u2, out dl_379) == 0x00 && ss:fp + 55516[(ax_317 + 0x01) * 0x04] + 0x02 <u Mem376[ds:22714:word16])
				{
					(&(ss->*((char *) fp + 55516)))[&ax_317.u3->t0001.u0].w0000 = (&(ss->*((char *) fp + 55516)))[&ax_317.u3->t0001.u0].w0000 + 0x01;
					dx = SEQ(dh_735, fn1AB8_1E54(ds, ss->*(((char *) fp + 0x0000CF19) + &(&(ss->*((ss->*ax_317.u3).t0001).u0))), (&(ss->*((char *) fp + 55516)))[&ax_317.u3->t0001.u0].u2, (&(ss->*((char *) fp + 55514)))[&ax_317.u3->t0001.u0].u2));
					goto l0C74_0C97;
				}
			}
			(&(ss->*((char *) fp + 55516)))[&ax_317.u3->t0001.u0].w0000 = 500;
			goto l0C74_0C97;
		}
	}
	else
	{
		fn1AB8_1E54(ds, 0x00, ax_85, wLoc10_526);
		if (fn1EDA_0D80(ds, 0x03, out dx) == 0x01)
		{
			if (Mem121[ds:0x58B0:byte] != 0x00)
			{
				word16 dx_797;
				fn11C8_0354(ds, fn1EDA_0D80(ds, 100, out dx_797));
			}
			word16 dx_795;
			fn1E78_029C(ds, CONVERT(Mem158[ds:22758:word16], int16, int32) /16 0x04, out dx_795);
			cup16 ax_195 = (cup16) (&fn1EDA_0D80(ds, 300, out dx_796).u3->t0000.u0 + ((word32) ax_23 + 21));
			Eq_17 wLoc10_549 = ax_195 - 0x96;
			if (ax_195 < 151)
				wLoc10_549.u0 = 0x01;
			if (wLoc10_549 > 0x027E)
				wLoc10_549.u0 = 0x027E;
			Eq_17 ax_214 = fn1EDA_0D80(ds, 200, out dx_798);
			Eq_17 ax_227 = ax_29 - ((word32) ax_214 + 22);
			byte dh_731 = SLICE((word32) ax_214 + 22, byte, 8);
			Eq_17 wLoc12_557 = ax_227;
			if (ax_227 < 0x01)
				wLoc12_557.u0 = 0x01;
			if (wLoc12_557 > 0x0177)
				wLoc12_557.u0 = 0x01;
			byte dl_253;
			dx = SEQ(dh_731, dl_253);
			if (fn1AB8_1E3C(ds, wLoc12_557, wLoc10_549, out dl_253) == 0x00)
			{
				Eq_3872 v40_265 = (word16) wLoc08_514 + 1;
				ss->*(((char *) fp + 0x0000CF19) + v40_265) = (word16) al_103;
				(&(ss->*((char *) fp + 55514)))[v40_265].u2 = (uint16) wLoc10_549;
				(&(ss->*((char *) fp + 55516)))[v40_265].u2 = (uint16) wLoc12_557;
				wLoc08_514 = v40_265;
				dx = SEQ(dh_731, fn1AB8_1E54(ds, ss->*(((char *) fp + 0x0000CF19) + v40_265), (&(ss->*((char *) fp + 55516)))[v40_265].u2, (&(ss->*((char *) fp + 55514)))[v40_265].u2));
			}
			if (Mem303[ds:0x58B0:byte] != 0x00)
				dx = fn11C8_033B(ds);
		}
	}
l0C74_0C97:
	if (wLoc06_523 == wLoc30EC_516)
		goto l0C74_0CA3;
	++wLoc06_523;
	goto l0C74_0A8F;
}
