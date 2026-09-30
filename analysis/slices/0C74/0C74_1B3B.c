// 0C74:1B3B: Register Eq_526 fn0C74_1B3B(Register Eq_17 ds, Register out (ptr16 Eq_29249) dsOut)
// Called from:
//      fn0C74_51AA
Eq_526 fn0C74_1B3B(Eq_17 ds, struct Eq_29249 & dsOut)
{
	Eq_17 ds_244;
	mp16 fp;
	fn1AB8_1E54(ds, 0x03, Mem14[ds:22712:word16] + 0x1C, Mem7[ds:22708:word16] + 0x17);
	fn1AB8_1E54(ds, 0x01, Mem30[ds:22712:word16] + 0x1C, Mem21[ds:22708:word16] + 0x18);
	fn1AB8_1E54(ds, 0x01, Mem46[ds:22712:word16] + 0x1C, Mem37[ds:22708:word16] + 0x19);
	Eq_17 v10_62 = Mem61[ds:22712:word16];
	Eq_17 ax_65 = Mem64[ds:22708:word16];
	Mem84[ds:22878:word16] = fn1AB8_13A3(ds, Mem68[ds:22712:word16] + 0x1C, ax_65 + 0x2B, v10_62, Mem53[ds:22708:word16]);
	Eq_17 ds_143;
	fn1AB8_1E6B(ds_143, fn1EDA_023F(ds, (word32) ax_65 + 43, v10_62, Mem84[ds:22878:word16], out ds_143), Mem113[ds_143:22712:word16] + 0x1C, Mem109[ds_143:22708:word16] + 0x2B, Mem106[ds_143:22712:word16], Mem103[ds_143:22708:word16]);
	Eq_17 bp_139 = fp - 2;
	struct Eq_28813 Eq_17::* sp_136 = fp - 0x08;
	selector ss;
	while (ss->*((word32) bp_139 - 1) < 88)
	{
		struct Eq_28866 Eq_17::* sp_146 = sp_136 - 2;
		Mem147[ss:sp_146 + 0x00:word16] = Mem140[ds_143:22708:word16];
		Mem152[ss:sp_146 + -2:word16] = Mem147[ds_143:22712:word16] - 0x01;
		byte dl_967;
		if (fn1AB8_1E3C(ds_143, (ss->*sp_146).tFFFE.u2, (ss->*sp_146).t0000.u2, out dl_967) != 0x00)
			break;
		Mem169[ss:sp_146 + 0x00:word16] = Mem152[ds_143:22710:word16];
		Mem174[ss:sp_146 + -2:word16] = Mem169[ds_143:22712:word16] - 0x01;
		byte dl_968;
		if (fn1AB8_1E3C(ds_143, (ss->*sp_146).tFFFE.u2, (ss->*sp_146).t0000.u2, out dl_968) != 0x00)
			break;
		(ss->*sp_146).t0000.u2 = (uint16) 200;
		(ss->*sp_146).tFFFE.u2 = (uint16) 0x0A;
		bp_139 = fn0C74_070D(ds_143, (ss->*sp_146).tFFFE.u2, (ss->*sp_146).t0000.u2, out ds_143);
		Mem870[ds_143:22712:word16] = Mem853[ds_143:22712:word16] - 0x01;
		Eq_481 sp_863;
		sp_863.u0 = <invalid>;
		Mem874[ss:sp_863 + 0x02:word16] = Mem870[ds_143:22708:word16];
		Mem877[ss:sp_863 + 0x00:word16] = Mem874[ds_143:22712:word16];
		Eq_17 es_di_878 = ss->*((word32) bp_139 - 6);
		ss->*((word16) sp_863 - 2) = SLICE(es_di_878, selector, 16);
		ss->*((word16) sp_863 - 4) = (word16) es_di_878;
		ss->*((word16) sp_863 - 6) = 0x00;
		fn1AB8_13D7(ds_143, ss->*((word16) sp_863 + 6), ss->*((word16) sp_863 - 4), ss->*sp_863, ss->*((word16) sp_863 + 2));
		(ss->*((word32) bp_139 - 1)).u3 = &(ss->*((word32) bp_139 - 1)).u3->t0001.u0;
		sp_136 = (word16) sp_863 + 4;
	}
	union Eq_17 Eq_17::* sp_237 = sp_136 - 2;
	word16 cx_964;
	word16 dx_965;
	word16 bx_966;
	Eq_17 ds_226;
	Mem238[ss:sp_237 + 0x00:word16] = fn1EDA_098A(0x04, fn1EDA_096F(Mem190[ds_143:0x4D0C:word16], Mem190[ds_143:22758:word16], 0x00, 0x00), Mem190[ss:sp_136 + -4:word16], Mem190[ss:sp_136 + -2:word16], out cx_964, out dx_965, out bx_966, out ds_226);
	Eq_481 sp_248;
	sp_248.u0 = <invalid>;
	Eq_17 bp_240 = fn0C74_02D8(ds_226, (ss->*sp_237).u2, out ds_244);
	struct Eq_28863 Eq_17::* sp_253 = (word16) sp_248 + 2;
	while (ss->*((word32) bp_240 - 1) > 0x00)
	{
		struct Eq_29034 Eq_17::* sp_263 = sp_253 - 2;
		Mem264[ss:sp_263 + 0x00:word16] = Mem256[ds_244:22708:word16] - 0x01;
		Mem269[ss:sp_263 + -2:word16] = Mem264[ds_244:22712:word16] + 44;
		byte dl_969;
		if (fn1AB8_1E3C(ds_244, (ss->*sp_263).tFFFE.u2, (ss->*sp_263).t0000.u2, out dl_969) != 0x00)
			break;
		Mem287[ss:sp_263 + 0x00:word16] = Mem269[ds_244:22710:word16] + 0x01;
		Mem292[ss:sp_263 + -2:word16] = Mem287[ds_244:22712:word16] + 44;
		byte dl_970;
		if (fn1AB8_1E3C(ds_244, (ss->*sp_263).tFFFE.u2, (ss->*sp_263).t0000.u2, out dl_970) != 0x00)
			break;
		(ss->*sp_263).t0000.u2 = (uint16) 200;
		(ss->*sp_263).tFFFE.u2 = (uint16) 0x0A;
		bp_240 = fn0C74_070D(ds_244, (ss->*sp_263).tFFFE.u2, (ss->*sp_263).t0000.u2, out ds_244);
		Mem818[ds_244:22712:word16] = Mem801[ds_244:22712:word16] + 0x01;
		Eq_481 sp_811;
		sp_811.u0 = <invalid>;
		Mem822[ss:sp_811 + 0x02:word16] = Mem818[ds_244:22708:word16];
		Mem825[ss:sp_811 + 0x00:word16] = Mem822[ds_244:22712:word16];
		Eq_17 es_di_826 = ss->*((word32) bp_240 - 6);
		ss->*((word16) sp_811 - 2) = SLICE(es_di_826, selector, 16);
		ss->*((word16) sp_811 - 4) = (word16) es_di_826;
		ss->*((word16) sp_811 - 6) = 0x00;
		fn1AB8_13D7(ds_244, ss->*((word16) sp_811 + 6), ss->*((word16) sp_811 - 4), ss->*sp_811, ss->*((word16) sp_811 + 2));
		(ss->*((word32) bp_240 - 1)).u1 = ss->*((word32) bp_240 - 1) - 0x01;
		sp_253 = (word16) sp_811 + 4;
	}
	struct Eq_29249 * ds_610;
	if (ss->*((word32) bp_240 - 1) == 0x00)
	{
		struct Eq_29205 Eq_17::* sp_770 = sp_253 - 2;
		(ss->*sp_770).t0000.u2 = (uint16) (ss->*((word32) bp_240 - 4));
		(ss->*sp_770).tFFFE.u2 = (uint16) (ss->*((word32) bp_240 - 6));
		Mem777[ss:sp_770 + -4:word16] = Mem774[ds_244:22878:word16];
		word16 dx_971;
		fn1EDA_0254(ds_244, (ss->*sp_770).tFFF8.u2, (ss->*sp_770).tFFFA.u2, (ss->*sp_770).tFFFC.u2, (ss->*sp_770).tFFFE.u3, out dx_971, out ds_610);
	}
	else
	{
		struct Eq_29351 Eq_17::* bp_406;
		Eq_17 ds_410;
		word16 sp_419;
		if (Mem309[ds_244:22888:word16] == 0x01)
		{
			struct Eq_29357 Eq_17::* sp_420 = sp_253 - 2;
			(ss->*sp_420).t0000.u2 = (uint16) 200;
			Eq_17 ds_427;
			fn0C74_02D8(ds_244, (ss->*sp_420).t0000.u2, out ds_427);
			Eq_481 sp_431;
			sp_431.u0 = <invalid>;
			ss->*sp_431 = 0x15;
			word16 bp_974;
			Eq_17 ds_444;
			fn0C74_0D43(ds_427, ss->*sp_431, out bp_974, out ds_444);
			Eq_481 sp_448;
			sp_448.u0 = <invalid>;
			ss->*sp_448 = 200;
			Eq_17 ds_461;
			fn0C74_02D8(ds_444, ss->*sp_448, out ds_461);
			Eq_481 sp_465;
			sp_465.u0 = <invalid>;
			ss->*sp_465 = 0x15;
			word16 bp_975;
			Eq_17 ds_478;
			fn0C74_0CFA(ds_461, ss->*sp_465, out bp_975, out ds_478);
			Eq_481 sp_482;
			sp_482.u0 = <invalid>;
			ss->*sp_482 = 200;
			Eq_17 ds_495;
			fn0C74_02D8(ds_478, ss->*sp_482, out ds_495);
			Eq_481 sp_499;
			sp_499.u0 = <invalid>;
			ss->*sp_499 = 11;
			fn0C74_0D43(ds_495, ss->*sp_499, out bp_406, out ds_410);
			Eq_481 sp_516;
			sp_516.u0 = <invalid>;
			sp_419 = (word16) sp_516 + 2;
		}
		else
		{
			struct Eq_29259 Eq_17::* sp_316 = sp_253 - 2;
			(ss->*sp_316).t0000.u2 = (uint16) 200;
			Eq_17 ds_325;
			fn0C74_02D8(ds_244, (ss->*sp_316).t0000.u2, out ds_325);
			Eq_481 sp_329;
			sp_329.u0 = <invalid>;
			ss->*sp_329 = 0x15;
			word16 bp_972;
			Eq_17 ds_342;
			fn0C74_0CFA(ds_325, ss->*sp_329, out bp_972, out ds_342);
			Eq_481 sp_346;
			sp_346.u0 = <invalid>;
			ss->*sp_346 = 200;
			Eq_17 ds_359;
			fn0C74_02D8(ds_342, ss->*sp_346, out ds_359);
			Eq_481 sp_363;
			sp_363.u0 = <invalid>;
			ss->*sp_363 = 0x15;
			word16 bp_973;
			Eq_17 ds_376;
			fn0C74_0D43(ds_359, ss->*sp_363, out bp_973, out ds_376);
			Eq_481 sp_380;
			sp_380.u0 = <invalid>;
			ss->*sp_380 = 200;
			Eq_17 ds_393;
			fn0C74_02D8(ds_376, ss->*sp_380, out ds_393);
			Eq_481 sp_397;
			sp_397.u0 = <invalid>;
			ss->*sp_397 = 11;
			Eq_481 sp_414;
			sp_414.u0 = <invalid>;
			bp_406 = fn0C74_0D94(ds_393, ss->*sp_397, out ds_410);
			sp_419 = (word16) sp_414 + 2;
		}
		struct Eq_29450 Eq_17::* sp_526 = sp_419 - 2;
		Mem528[ss:sp_526 + 0x00:word16] = Mem523[ds_410:22708:word16];
		Mem531[ss:sp_526 + -2:word16] = Mem528[ds_410:22712:word16];
		Mem535[ss:sp_526 + -4:word16] = Mem531[ds_410:22708:word16] + 0x2B;
		Mem540[ss:sp_526 + -6:word16] = Mem535[ds_410:22712:word16] + 0x1C;
		Eq_29487 es_di_542;
		es_di_542.u1 = (ss->*bp_406).tFFFA.u1;
		(ss->*sp_526).ptrFFF8 = SLICE(es_di_542, selector, 16);
		(ss->*sp_526).tFFF6.u2 = (uint16) (word16) es_di_542;
		fn1AB8_1E6B(ds_410, (ss->*sp_526).tFFF6.u3, (ss->*sp_526).tFFFA.u2, (ss->*sp_526).tFFFC.u2, (ss->*sp_526).tFFFE.u2, (ss->*sp_526).t0000.u2);
		Eq_481 sp_570;
		sp_570.u0 = <invalid>;
		Eq_17 ds_566;
		if (fn0C74_0FA1(ds_410, out bp_240, out ds_566) == 0x00)
		{
			while (ss->*((word32) bp_240 - 1) > 0x00)
			{
				struct Eq_29589 Eq_17::* sp_717 = sp_570 - 2;
				(ss->*sp_717).t0000.u2 = (uint16) 200;
				(ss->*sp_717).tFFFE.u2 = (uint16) 0x0A;
				bp_240 = fn0C74_070D(ds_566, (ss->*sp_717).tFFFE.u2, (ss->*sp_717).t0000.u2, out ds_566);
				Mem737[ds_566:22712:word16] = Mem720[ds_566:22712:word16] + 0x01;
				Eq_481 sp_730;
				sp_730.u0 = <invalid>;
				Mem741[ss:sp_730 + 0x02:word16] = Mem737[ds_566:22708:word16];
				Mem744[ss:sp_730 + 0x00:word16] = Mem741[ds_566:22712:word16];
				Eq_17 es_di_745 = ss->*((word32) bp_240 - 6);
				ss->*((word16) sp_730 - 2) = SLICE(es_di_745, selector, 16);
				ss->*((word16) sp_730 - 4) = (word16) es_di_745;
				ss->*((word16) sp_730 - 6) = 0x00;
				fn1AB8_13D7(ds_566, ss->*((word16) sp_730 + 6), ss->*((word16) sp_730 - 4), ss->*sp_730, ss->*((word16) sp_730 + 2));
				(ss->*((word32) bp_240 - 1)).u1 = ss->*((word32) bp_240 - 1) - 0x01;
				sp_570 = (word16) sp_730 + 4;
			}
		}
		struct Eq_29531 Eq_17::* sp_594 = sp_570 - 2;
		(ss->*sp_594).t0000.u2 = (uint16) (ss->*((word32) bp_240 - 4));
		(ss->*sp_594).tFFFE.u2 = (uint16) (ss->*((word32) bp_240 - 6));
		Mem603[ss:sp_594 + -4:word16] = Mem598[ds_566:22878:word16];
		word16 dx_976;
		fn1EDA_0254(ds_566, (ss->*sp_594).tFFF8.u2, (ss->*sp_594).tFFFA.u2, (ss->*sp_594).tFFFC.u2, (ss->*sp_594).tFFFE.u3, out dx_976, out ds_610);
		if (ds_610->b58B3 == 0x00)
		{
			word16 cx_977;
			word16 dx_978;
			word16 bx_979;
			Eq_17 ds_653;
			(ss->*sp_594).t0000.u2 = (uint16) fn1EDA_098A(0x04, fn1EDA_096F(ds_610->w4D0C, ds_610->t58E6, 0x00, 0x00), (ss->*sp_594).tFFFE.u2, (ss->*sp_594).t0000.u2, out cx_977, out dx_978, out bx_979, out ds_653);
			Eq_17 ds_671;
			fn0C74_02D8(ds_653, (ss->*sp_594).t0000.u2, out ds_671);
			Eq_481 sp_675;
			sp_675.u0 = <invalid>;
			if (Mem665[ds_671:22888:word16] == 0x01)
			{
				ss->*sp_675 = 11;
				bp_240 = fn0C74_0DE5(ds_671, ss->*sp_675, out ds_610);
			}
			else
			{
				ss->*sp_675 = 11;
				fn0C74_0CFA(ds_671, ss->*sp_675, out bp_240, out ds_610);
			}
		}
	}
	Eq_526 bp_796 = (ss->*bp_240.u3).t0000.u2;
	dsOut = ds_610;
	return bp_796;
}
