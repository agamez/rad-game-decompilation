// 0C74:2AD9: Register Eq_526 fn0C74_2AD9(Register Eq_17 ds, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_51B2
//      fn0C74_54B1
//      fn0C74_54F0
Eq_526 fn0C74_2AD9(Eq_17 ds, union Eq_17 & dsOut)
{
	Eq_17 ds_112;
	selector ss;
	struct Eq_29351 Eq_17::* bp_121;
	Eq_17 ds_38;
	word16 sp_47;
	if (Mem7[ds:22888:word16] == 0x01)
	{
		Eq_17 ds_55;
		fn0C74_02D8(ds, 200, out ds_55);
		Eq_481 sp_59;
		sp_59.u0 = <invalid>;
		ss->*sp_59 = 11;
		fn0C74_0D43(ds_55, ss->*sp_59, out bp_121, out ds_38);
		Eq_481 sp_76;
		sp_76.u0 = <invalid>;
		sp_47 = (word16) sp_76 + 2;
	}
	else
	{
		Eq_17 ds_21;
		fn0C74_02D8(ds, 200, out ds_21);
		Eq_481 sp_25;
		sp_25.u0 = <invalid>;
		ss->*sp_25 = 11;
		Eq_481 sp_42;
		sp_42.u0 = <invalid>;
		bp_121 = fn0C74_0D94(ds_21, ss->*sp_25, out ds_38);
		sp_47 = (word16) sp_42 + 2;
	}
	struct Eq_35806 Eq_17::* sp_83 = sp_47 - 2;
	(ss->*sp_83).t0000.u2 = (uint16) 0x00;
	(ss->*sp_83).tFFFE.u2 = (uint16) 0x00;
	(ss->*sp_83).tFFFC.u2 = (uint16) 0x1C;
	(ss->*sp_83).tFFFA.u2 = (uint16) 0x2B;
	Mem103[ds_38:22878:word16] = fn1AB8_13A3(ds_38, (ss->*sp_83).tFFFA.u2, (ss->*sp_83).tFFFC.u2, (ss->*sp_83).tFFFE.u2, (ss->*sp_83).t0000.u2);
	Mem106[ss:sp_83 + 0x00:word16] = Mem103[ds_38:22878:word16];
	Eq_17 dx_ax_423 = fn1EDA_023F(ds_38, (ss->*sp_83).tFFFC.u2, (ss->*sp_83).tFFFE.u2, (ss->*sp_83).t0000.u2, out ds_112);
	(ss->*bp_121).tFFFA.u0 = (word16) (word16) dx_ax_423;
	(ss->*bp_121).wFFFC = SLICE(dx_ax_423, word16, 16);
	Mem126[ss:sp_83 + 0x00:word16] = Mem123[ds_112:22708:word16];
	Mem129[ss:sp_83 + -2:word16] = Mem126[ds_112:22712:word16];
	Mem133[ss:sp_83 + -4:word16] = Mem129[ds_112:22708:word16] + 0x2B;
	Mem138[ss:sp_83 + -6:word16] = Mem133[ds_112:22712:word16] + 0x1C;
	Eq_29487 es_di_139;
	es_di_139.u1 = (ss->*bp_121).tFFFA.u1;
	(ss->*sp_83).ptrFFF8 = SLICE(es_di_139, selector, 16);
	(ss->*sp_83).tFFF6.u2 = (uint16) (word16) es_di_139;
	fn1AB8_1E6B(ds_112, (ss->*sp_83).tFFF6.u3, (ss->*sp_83).tFFFA.u2, (ss->*sp_83).tFFFC.u2, (ss->*sp_83).tFFFE.u2, (ss->*sp_83).t0000.u2);
	Eq_481 sp_166;
	sp_166.u0 = <invalid>;
	Eq_17 bp_158;
	Eq_17 ds_162;
	if (fn0C74_1F08(ds_112, out bp_158, out ds_162) != 0x00)
	{
		while (Mem180[ds_162:22714:word16] - 0x2B >u Mem180[ds_162:22712:word16])
		{
			struct Eq_35977 Eq_17::* sp_327 = sp_166 - 2;
			(ss->*sp_327).t0000.u2 = (uint16) 200;
			(ss->*sp_327).tFFFE.u2 = (uint16) 0x14;
			bp_158 = fn0C74_070D(ds_162, (ss->*sp_327).tFFFE.u2, (ss->*sp_327).t0000.u2, out ds_162);
			Mem347[ds_162:22712:word16] = Mem330[ds_162:22712:word16] + 0x01;
			Eq_481 sp_340;
			sp_340.u0 = <invalid>;
			Mem351[ss:sp_340 + 0x02:word16] = Mem347[ds_162:22708:word16];
			Mem354[ss:sp_340 + 0x00:word16] = Mem351[ds_162:22712:word16];
			Eq_17 es_di_355 = ss->*((word32) bp_158 - 6);
			ss->*((word16) sp_340 - 2) = SLICE(es_di_355, selector, 16);
			ss->*((word16) sp_340 - 4) = (word16) es_di_355;
			ss->*((word16) sp_340 - 6) = 0x00;
			fn1AB8_13D7(ds_162, ss->*((word16) sp_340 + 6), ss->*((word16) sp_340 - 4), ss->*sp_340, ss->*((word16) sp_340 + 2));
			sp_166 = (word16) sp_340 + 4;
		}
	}
	if (Mem186[ds_162:22707:byte] == 0x00)
	{
		struct Eq_36063 Eq_17::* sp_237 = sp_166 - 2;
		word16 cx_424;
		word16 dx_425;
		word16 bx_426;
		Eq_17 ds_226;
		Mem238[ss:sp_237 + 0x00:word16] = fn1EDA_098A(0x04, fn1EDA_096F(Mem186[ds_162:0x4D0C:word16], Mem186[ds_162:22758:word16], 0x00, 0x00), Mem186[ss:sp_166 + -4:word16], Mem186[ss:sp_166 + -2:word16], out cx_424, out dx_425, out bx_426, out ds_226);
		Eq_17 ds_244;
		fn0C74_02D8(ds_226, (ss->*sp_237).t0000.u2, out ds_244);
		Eq_481 sp_248;
		sp_248.u0 = <invalid>;
		Eq_17 ds_263;
		word16 sp_272;
		if (Mem238[ds_244:22888:word16] == 0x01)
		{
			ss->*sp_248 = 11;
			Eq_481 sp_284;
			sp_284.u0 = <invalid>;
			bp_158 = fn0C74_0DE5(ds_244, ss->*sp_248, out ds_263);
			sp_272 = (word16) sp_284 + 2;
		}
		else
		{
			ss->*sp_248 = 11;
			fn0C74_0CFA(ds_244, ss->*sp_248, out bp_158, out ds_263);
			Eq_481 sp_267;
			sp_267.u0 = <invalid>;
			sp_272 = (word16) sp_267 + 2;
		}
		struct Eq_36152 Eq_17::* sp_295 = sp_272 - 2;
		(ss->*sp_295).w0000 = (word16) (ss->*((word32) bp_158 - 4));
		(ss->*sp_295).tFFFE.u2 = (uint16) (ss->*((word32) bp_158 - 6));
		Mem303[ss:sp_295 + -4:word16] = Mem299[ds_263:22878:word16];
		word16 dx_427;
		fn1EDA_0254(ds_263, (ss->*sp_295).tFFF8.u2, (ss->*sp_295).tFFFA.u2, (ss->*sp_295).tFFFC.u2, (ss->*sp_295).tFFFE.u3, out dx_427, out ds_162);
	}
	Eq_526 bp_325 = (ss->*bp_158.u3).t0000.u2;
	dsOut = ds_162;
	return bp_325;
}
