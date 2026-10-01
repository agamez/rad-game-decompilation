// 0C74:076B: Register word16 fn0C74_076B(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08, Stack Eq_17 wArg0A)
// Called from:
//      fn0800_08E9
//      fn0C74_2BBD
//      fn0C74_45CE
//      fn0C74_4999
word16 fn0C74_076B(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06, Eq_17 wArg08, Eq_17 wArg0A)
{
	word16 dx_853;
	word16 dx_851;
	word16 dx_370;
	byte dl_91;
	uint32 dx_ax_27 = (wArg04 - wArg08) *32 (wArg06 - wArg0A);
	Eq_3872 wLoc08_538;
	wLoc08_538.u0 = 0x00;
	uint16 ax_15 = (word16) wArg0A.u2 + (wArg06 - wArg0A >> 0x01);
	uint16 ax_20 = (word16) wArg08.u2 + (wArg04 - wArg08 >> 0x01);
	int16 ax_28 = (word16) dx_ax_27;
	word16 dx_140 = SLICE(dx_ax_27, word16, 16);
	struct Eq_21536 * ss;
	<unknown> Eq_21536::* fp;
	if (ax_28 *s 0x0F < 0x01)
	{
l0C74_09E1:
		if (wLoc08_538 != 0x00 && wLoc08_538 >= 0x01)
		{
			Eq_3872 wLoc0A_654;
			wLoc0A_654.u0 = 0x01;
			while (true)
			{
				byte dh_786 = SLICE(dx_140, byte, 8);
				if ((&(ss->*((char *) fp + 55516)))[wLoc0A_654].w0000 != 500)
					dx_140 = SEQ(dh_786, fn1AB8_1E54(ds, 0x00, (&(ss->*((char *) fp + 55516)))[wLoc0A_654].u2, (&(ss->*((char *) fp + 55514)))[wLoc0A_654].u2));
				if (wLoc0A_654 == wLoc08_538)
					break;
				wLoc0A_654 = (word16) wLoc0A_654 + 1;
			}
		}
		return dx_140;
	}
	int16 wLoc06_549 = 0x01;
l0C74_07D1:
	Eq_17 ax_62;
	word16 dx_848;
	ax_62.u3 = fn1EDA_0D80(ds, wArg06 - wArg0A + 0x01, out dx_848) + wArg0A;
	Eq_17 ax_80;
	word16 dx_74;
	ax_80.u3 = fn1EDA_0D80(ds, wArg04 - wArg08 + 0x01, out dx_74) + wArg08;
	word16 ax_89 = fn1AB8_1E3C(ds, ax_80, ax_62, out dl_91);
	byte al_98 = (byte) ax_89;
	dx_140 = SEQ(SLICE(dx_74, byte, 8), dl_91);
	struct Eq_21523 * cs;
	selector es_849;
	if (!fn1EDA_0CD4(&cs->t074B, (byte) ax_89, out es_849))
	{
		if (wLoc08_538 == 0x00)
			goto l0C74_09D5;
		Eq_17 ax_332 = fn1EDA_0D80(ds, wLoc08_538, out dx_140);
		if ((&(ss->*((char *) fp + 55516)))[&ax_332.u3->t0001.u0].w0000 != 500)
		{
			fn1AB8_1E54(ds, 0x00, (&(ss->*((char *) fp + 55516)))[&ax_332.u3->t0001.u0].u2, (&(ss->*((char *) fp + 55514)))[&ax_332.u3->t0001.u0].u2);
			byte dh_781 = SLICE(dx_370, byte, 8);
			dx_140 = dx_370;
			if (fn1EDA_0D80(ds, 0x14, out dx_370) != 0x01)
			{
				byte dl_394;
				dx_140 = SEQ(dh_781, dl_394);
				if (fn1AB8_1E3C(ds, (&(ss->*((char *) fp + 55516)))[&ax_332.u3->t0001.u0].w0000 + 0x01, (&(ss->*((char *) fp + 55514)))[&ax_332.u3->t0001.u0].u2, out dl_394) == 0x00 && ss:fp + 55516[(ax_332 + 0x01) * 0x04] + 0x02 <u Mem391[ds:22714:word16])
				{
					(&(ss->*((char *) fp + 55516)))[&ax_332.u3->t0001.u0].w0000 = (&(ss->*((char *) fp + 55516)))[&ax_332.u3->t0001.u0].w0000 + 0x01;
					dx_140 = SEQ(dh_781, fn1AB8_1E54(ds, ss->*(((char *) fp + 0x0000CF19) + &(&(ss->*((ss->*ax_332.u3).t0001).u0))), (&(ss->*((char *) fp + 55516)))[&ax_332.u3->t0001.u0].u2, (&(ss->*((char *) fp + 55514)))[&ax_332.u3->t0001.u0].u2));
					goto l0C74_09D5;
				}
			}
			(&(ss->*((char *) fp + 55516)))[&ax_332.u3->t0001.u0].w0000 = 500;
			goto l0C74_09D5;
		}
	}
	else
	{
		fn1AB8_1E54(ds, 0x00, ax_80, ax_62);
		if (fn1EDA_0D80(ds, 0x03, out dx_140) == 0x01)
		{
			if (Mem136[ds:0x58B0:byte] != 0x00)
			{
				word16 dx_852;
				audio_write_opl3_register(ds, fn1EDA_0D80(ds, 100, out dx_852));
			}
			word16 dx_850;
			fn1E78_029C(ds, CONVERT(Mem173[ds:22758:word16], int16, word32) /16 0x04, out dx_850);
			cup16 ax_210 = (cup16) (&fn1EDA_0D80(ds, 300, out dx_851).u3->t0000.u0 + ax_15);
			Eq_17 wLoc10_577 = ax_210 - 0x96;
			if (ax_210 < 151)
				wLoc10_577.u0 = 0x01;
			if (wLoc10_577 > 0x027E)
				wLoc10_577.u0 = 0x027E;
			Eq_17 ax_229 = fn1EDA_0D80(ds, 200, out dx_853);
			Eq_17 ax_242 = ax_20 - ((word32) ax_229 + 22);
			byte dh_777 = SLICE((word32) ax_229 + 22, byte, 8);
			Eq_17 wLoc12_586 = ax_242;
			if (ax_242 < 0x01)
				wLoc12_586.u0 = 0x01;
			if (wLoc12_586 > 0x0177)
				wLoc12_586.u0 = 0x01;
			byte dl_268;
			dx_140 = SEQ(dh_777, dl_268);
			if (fn1AB8_1E3C(ds, wLoc12_586, wLoc10_577, out dl_268) == 0x00)
			{
				Eq_3872 v40_280 = (word16) wLoc08_538 + 1;
				ss->*(((char *) fp + 0x0000CF19) + v40_280) = (word16) al_98;
				(&(ss->*((char *) fp + 55514)))[v40_280].u2 = (uint16) wLoc10_577;
				(&(ss->*((char *) fp + 55516)))[v40_280].u2 = (uint16) wLoc12_586;
				wLoc08_538 = v40_280;
				dx_140 = SEQ(dh_777, fn1AB8_1E54(ds, ss->*(((char *) fp + 0x0000CF19) + v40_280), (&(ss->*((char *) fp + 55516)))[v40_280].u2, (&(ss->*((char *) fp + 55514)))[v40_280].u2));
			}
			if (Mem318[ds:0x58B0:byte] != 0x00)
				dx_140 = audio_get_soundcard_port(ds);
		}
	}
l0C74_09D5:
	if (wLoc06_549 == ax_28 *s 0x0F)
		goto l0C74_09E1;
	++wLoc06_549;
	goto l0C74_07D1;
}
