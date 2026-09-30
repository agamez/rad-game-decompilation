// 0C74:1F08: Register byte fn0C74_1F08(Register Eq_17 ds, Register out word16 bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_2AD9
byte fn0C74_1F08(Eq_17 ds, word16 & bpOut, union Eq_17 & dsOut)
{
	Eq_17 ds_2925;
	Eq_17 ds_2747;
	Eq_17 ds_2656;
	Eq_17 ds_2385;
	Eq_17 ds_1990;
	Eq_17 ds_1942;
	Eq_17 ds_1648;
	Eq_17 ds_1346;
	Eq_17 ds_1036;
	Eq_17 ds_1174;
	Eq_17 ds_500;
	Eq_17 ds_196;
	word16 bx_3502;
	word16 dx_3501;
	word16 cx_3500;
	Eq_17 ds_178;
	Eq_17 ds_38;
	Eq_17 ax_19 = fn1AB8_13A3(ds, 0x1B, 0x1C, 0x0D, 0x19);
	Eq_17 dx_ax_3490 = fn1EDA_023F(ds, 0x1C, 0x0D, ax_19, out ds_38);
	Eq_17 ds_56;
	fn1AB8_1E6B(ds_56, fn1EDA_023F(ds_38, 0x1C, 0x0D, ax_19, out ds_56), Mem78[ds_56:22712:word16] + 0x1B, Mem74[ds_56:22708:word16] + 0x1C, Mem70[ds_56:22712:word16] + 0x0D, Mem66[ds_56:22708:word16] + 0x19);
	word16 ax_102 = Mem90[ds_56:22708:word16];
	word16 ax_106 = Mem105[ds_56:22712:word16];
	fn1AB8_1E6B(ds_56, dx_ax_3490, Mem113[ds_56:22712:word16] + 0x1B, Mem109[ds_56:22708:word16] + 0x11, ax_106 + 0x0D, ax_102 + 0x0E);
	Eq_17 bp_1039 = fn0C74_02D8(ds_178, fn1EDA_098A(0x04, fn1EDA_096F(Mem146[ds_56:0x4D0C:word16], Mem146[ds_56:22758:word16], 0x00, 0x00), ax_106 + 0x0D, ax_102 + 0x0E, out cx_3500, out dx_3501, out bx_3502, out ds_178), out ds_196);
	Eq_481 sp_200;
	sp_200.u0 = <invalid>;
	selector ss;
	ss->*sp_200 = ss->*((word32) bp_1039 - 36);
	Mem213[ss:sp_200 + -2:word16] = Mem208[ds_196:22712:word16] + 0x0D;
	Eq_17 es_di_214 = ss->*((word32) bp_1039 - 16);
	ss->*((word16) sp_200 - 4) = SLICE(es_di_214, selector, 16);
	ss->*((word16) sp_200 - 6) = (word16) es_di_214;
	ss->*((word16) sp_200 - 8) = 0x00;
	fn1AB8_13D7(ds_196, ss->*((word16) sp_200 + 8), ss->*((word16) sp_200 - 6), ss->*((word16) sp_200 - 2), ss->*sp_200);
	ss->*sp_200 = ss->*((word32) bp_1039 - 38);
	Mem242[ss:sp_200 + -2:word16] = Mem237[ds_196:22712:word16] + 0x0D;
	Eq_17 es_di_243 = ss->*((word32) bp_1039 - 20);
	ss->*((word16) sp_200 - 4) = SLICE(es_di_243, selector, 16);
	ss->*((word16) sp_200 - 6) = (word16) es_di_243;
	ss->*((word16) sp_200 - 8) = 0x00;
	fn1AB8_13D7(ds_196, ss->*((word16) sp_200 + 8), ss->*((word16) sp_200 - 6), ss->*((word16) sp_200 - 2), ss->*sp_200);
	ss->*sp_200 = ss->*((word32) bp_1039 - 0x0E);
	ss->*((word16) sp_200 - 2) = ss->*((word32) bp_1039 - 16);
	ss->*((word16) sp_200 - 4) = ss->*((word32) bp_1039 - 32);
	word16 dx_3503;
	Eq_17 ds_277;
	fn1EDA_0254(ds_196, ss->*((word16) sp_200 - 8), ss->*((word16) sp_200 - 6), ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), out dx_3503, out ds_277);
	ss->*sp_200 = ss->*((word32) bp_1039 - 18);
	ss->*((word16) sp_200 - 2) = ss->*((word32) bp_1039 - 20);
	ss->*((word16) sp_200 - 4) = ss->*((word32) bp_1039 - 32);
	word16 dx_3504;
	Eq_17 ds_300;
	fn1EDA_0254(ds_277, ss->*((word16) sp_200 - 8), ss->*((word16) sp_200 - 6), ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), out dx_3504, out ds_300);
	ss->*sp_200 = 0x00;
	ss->*((word16) sp_200 - 2) = 0x00;
	ss->*((word16) sp_200 - 4) = 0x01;
	fn1AB8_10F4(ds_300, ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200);
	ss->*sp_200 = 0x00;
	fn1AB8_1C32(ds_300, ss->*sp_200);
	Mem335[ss:sp_200 + 0x00:word16] = Mem327[ds_300:22708:word16] + 0x19;
	Mem339[ss:sp_200 + -2:word16] = Mem335[ds_300:22712:word16] + 0x0D;
	Mem343[ss:sp_200 + -4:word16] = Mem339[ds_300:22708:word16] + 0x19;
	Mem348[ss:sp_200 + -6:word16] = Mem343[ds_300:22712:word16] + 0x1B;
	word16 dx_3505;
	fn1AB8_1AF6(ds_300, ss->*((word16) sp_200 - 6), ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200, out dx_3505);
	Mem358[ss:sp_200 + 0x00:word16] = Mem348[ds_300:22708:word16] + 0x11;
	Mem362[ss:sp_200 + -2:word16] = Mem358[ds_300:22712:word16] + 0x0D;
	Mem366[ss:sp_200 + -4:word16] = Mem362[ds_300:22708:word16] + 0x11;
	Mem371[ss:sp_200 + -6:word16] = Mem366[ds_300:22712:word16] + 0x1B;
	word16 dx_3506;
	fn1AB8_1AF6(ds_300, ss->*((word16) sp_200 - 6), ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200, out dx_3506);
	Mem381[ss:sp_200 + 0x00:word16] = Mem371[ds_300:22708:word16] + 0x19;
	Mem386[ss:sp_200 + -2:word16] = Mem381[ds_300:22712:word16] + 0x12;
	ss->*((word16) sp_200 - 4) = 11;
	fn1AB8_1E54(ds_300, ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200);
	Mem397[ss:sp_200 + 0x00:word16] = Mem388[ds_300:22708:word16] + 0x19;
	Mem402[ss:sp_200 + -2:word16] = Mem397[ds_300:22712:word16] + 0x13;
	ss->*((word16) sp_200 - 4) = 0x03;
	fn1AB8_1E54(ds_300, ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200);
	Mem413[ss:sp_200 + 0x00:word16] = Mem404[ds_300:22708:word16] + 0x19;
	Mem418[ss:sp_200 + -2:word16] = Mem413[ds_300:22712:word16] + 0x14;
	ss->*((word16) sp_200 - 4) = 0x09;
	fn1AB8_1E54(ds_300, ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200);
	Mem429[ss:sp_200 + 0x00:word16] = Mem420[ds_300:22708:word16] + 0x11;
	Mem434[ss:sp_200 + -2:word16] = Mem429[ds_300:22712:word16] + 0x12;
	ss->*((word16) sp_200 - 4) = 11;
	fn1AB8_1E54(ds_300, ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200);
	Mem445[ss:sp_200 + 0x00:word16] = Mem436[ds_300:22708:word16] + 0x11;
	Mem450[ss:sp_200 + -2:word16] = Mem445[ds_300:22712:word16] + 0x13;
	ss->*((word16) sp_200 - 4) = 0x03;
	fn1AB8_1E54(ds_300, ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200);
	Mem461[ss:sp_200 + 0x00:word16] = Mem452[ds_300:22708:word16] + 0x11;
	Mem466[ss:sp_200 + -2:word16] = Mem461[ds_300:22712:word16] + 0x14;
	ss->*((word16) sp_200 - 4) = 0x09;
	fn1AB8_1E54(ds_300, ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200);
	ss->*sp_200 = 0x19;
	ss->*((word16) sp_200 - 2) = 0x0D;
	ss->*((word16) sp_200 - 4) = 0x1D;
	ss->*((word16) sp_200 - 6) = 0x1B;
	ss->*((word32) bp_1039 - 32) = fn1AB8_13A3(ds_300, ss->*((word16) sp_200 - 6), ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200);
	ss->*sp_200 = ss->*((word32) bp_1039 - 32);
	Eq_17 dx_ax_3507 = fn1EDA_023F(ds_300, ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200, out ds_500);
	ss->*((word32) bp_1039 - 16) = (word16) dx_ax_3507;
	(ss->*((word32) bp_1039 - 0x0E)).u3 = SLICE(dx_ax_3507, word16, 16);
	ss->*sp_200 = ss->*((word32) bp_1039 - 32);
	Eq_17 dx_ax_3508 = fn1EDA_023F(ds_500, ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200, out ds_1174);
	ss->*((word32) bp_1039 - 20) = (word16) dx_ax_3508;
	(ss->*((word32) bp_1039 - 18)).u3 = SLICE(dx_ax_3508, word16, 16);
	Mem532[ss:sp_200 + 0x00:word16] = Mem528[ds_1174:22708:word16] + 0x19;
	Mem536[ss:sp_200 + -2:word16] = Mem532[ds_1174:22712:word16] + 0x0D;
	Mem540[ss:sp_200 + -4:word16] = Mem536[ds_1174:22708:word16] + 0x1D;
	Mem545[ss:sp_200 + -6:word16] = Mem540[ds_1174:22712:word16] + 0x1B;
	Eq_17 es_di_546 = ss->*((word32) bp_1039 - 20);
	ss->*((word16) sp_200 - 8) = SLICE(es_di_546, selector, 16);
	ss->*((word16) sp_200 - 0x0A) = (word16) es_di_546;
	fn1AB8_1E6B(ds_1174, ss->*((word16) sp_200 - 0x0A), ss->*((word16) sp_200 - 6), ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200);
	Mem567[ss:sp_200 + 0x00:word16] = Mem552[ds_1174:22708:word16] + 0x0D;
	Mem571[ss:sp_200 + -2:word16] = Mem567[ds_1174:22712:word16] + 0x0D;
	Mem575[ss:sp_200 + -4:word16] = Mem571[ds_1174:22708:word16] + 0x11;
	Mem580[ss:sp_200 + -6:word16] = Mem575[ds_1174:22712:word16] + 0x1B;
	Eq_17 es_di_581 = ss->*((word32) bp_1039 - 16);
	ss->*((word16) sp_200 - 8) = SLICE(es_di_581, selector, 16);
	ss->*((word16) sp_200 - 0x0A) = (word16) es_di_581;
	fn1AB8_1E6B(ds_1174, ss->*((word16) sp_200 - 0x0A), ss->*((word16) sp_200 - 6), ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200);
	(ss->*((word32) bp_1039 - 4)).u0 = 0x01;
	struct Eq_31117 Eq_17::* sp_598 = (word16) sp_200 + 2;
	while (ss->*((word32) bp_1039 - 4) < 0x14)
	{
		struct Eq_31120 Eq_17::* sp_610 = sp_598 - 2;
		Mem611[ss:sp_610 + 0x00:word16] = Mem602[ds_1174:22708:word16] + 0x0C - Mem602[ss:bp_1039 + -4:word16];
		Mem616[ss:sp_610 + -2:word16] = Mem611[ds_1174:22712:word16] + 0x1B;
		byte dl_3509;
		if (fn1AB8_1E3C(ds_1174, (ss->*sp_610).tFFFE.u2, (ss->*sp_610).t0000.u2, out dl_3509) != 0x00)
			break;
		Mem635[ss:sp_610 + 0x00:word16] = Mem616[ds_1174:22708:word16] + 0x1E + Mem616[ss:bp_1039 + -4:word16];
		Mem640[ss:sp_610 + -2:word16] = Mem635[ds_1174:22712:word16] + 0x1B;
		byte dl_3510;
		if (fn1AB8_1E3C(ds_1174, (ss->*sp_610).tFFFE.u2, (ss->*sp_610).t0000.u2, out dl_3510) != 0x00)
			break;
		Mem659[ss:sp_610 + 0x00:word16] = Mem640[ds_1174:22708:word16] + 0x0C - Mem640[ss:bp_1039 + -4:word16];
		Mem664[ss:sp_610 + -2:word16] = Mem659[ds_1174:22712:word16] + 0x0D;
		byte dl_3513;
		if (fn1AB8_1E3C(ds_1174, (ss->*sp_610).tFFFE.u2, (ss->*sp_610).t0000.u2, out dl_3513) != 0x00)
			break;
		Mem683[ss:sp_610 + 0x00:word16] = Mem664[ds_1174:22708:word16] + 0x1E + Mem664[ss:bp_1039 + -4:word16];
		Mem688[ss:sp_610 + -2:word16] = Mem683[ds_1174:22712:word16] + 0x0D;
		byte dl_3514;
		if (fn1AB8_1E3C(ds_1174, (ss->*sp_610).tFFFE.u2, (ss->*sp_610).t0000.u2, out dl_3514) != 0x00)
			break;
		Mem707[ss:sp_610 + 0x00:word16] = Mem688[ds_1174:22708:word16] + 0x0C - Mem688[ss:bp_1039 + -4:word16];
		Mem712[ss:sp_610 + -2:word16] = Mem707[ds_1174:22712:word16] + 22;
		byte dl_3515;
		if (fn1AB8_1E3C(ds_1174, (ss->*sp_610).tFFFE.u2, (ss->*sp_610).t0000.u2, out dl_3515) != 0x00)
			break;
		Mem731[ss:sp_610 + 0x00:word16] = Mem712[ds_1174:22708:word16] + 0x1E + Mem712[ss:bp_1039 + -4:word16];
		Mem736[ss:sp_610 + -2:word16] = Mem731[ds_1174:22712:word16] + 22;
		byte dl_3516;
		if (fn1AB8_1E3C(ds_1174, (ss->*sp_610).tFFFE.u2, (ss->*sp_610).t0000.u2, out dl_3516) != 0x00)
			break;
		(ss->*sp_610).t0000.u2 = (uint16) 0xE6;
		(ss->*sp_610).tFFFE.u2 = (uint16) 0x0F;
		bp_1039 = fn0C74_070D(ds_1174, (ss->*sp_610).tFFFE.u2, (ss->*sp_610).t0000.u2, out ds_1174);
		Eq_481 sp_765;
		sp_765.u0 = <invalid>;
		Mem775[ss:sp_765 + 0x02:word16] = Mem754[ds_1174:22708:word16] + 0x0D - Mem754[ss:bp_1039 + -4:word16];
		Mem780[ss:sp_765 + 0x00:word16] = Mem775[ds_1174:22712:word16] + 0x0D;
		Eq_17 es_di_781 = ss->*((word32) bp_1039 - 16);
		ss->*((word16) sp_765 - 2) = SLICE(es_di_781, selector, 16);
		ss->*((word16) sp_765 - 4) = (word16) es_di_781;
		ss->*((word16) sp_765 - 6) = 0x00;
		fn1AB8_13D7(ds_1174, ss->*((word16) sp_765 + 6), ss->*((word16) sp_765 - 4), ss->*sp_765, ss->*((word16) sp_765 + 2));
		Mem806[ss:sp_765 + 0x02:word16] = Mem789[ds_1174:22708:word16] + 0x19 + Mem789[ss:bp_1039 + -4:word16];
		Mem811[ss:sp_765 + 0x00:word16] = Mem806[ds_1174:22712:word16] + 0x0D;
		Eq_17 es_di_812 = ss->*((word32) bp_1039 - 20);
		ss->*((word16) sp_765 - 2) = SLICE(es_di_812, selector, 16);
		ss->*((word16) sp_765 - 4) = (word16) es_di_812;
		ss->*((word16) sp_765 - 6) = 0x00;
		fn1AB8_13D7(ds_1174, ss->*((word16) sp_765 + 6), ss->*((word16) sp_765 - 4), ss->*sp_765, ss->*((word16) sp_765 + 2));
		(ss->*((word32) bp_1039 - 4)).u3 = &(ss->*((word32) bp_1039 - 4)).u3->t0001.u0;
		sp_598 = (word16) sp_765 + 4;
	}
	struct Eq_31117 Eq_17::* sp_1214 = sp_598;
	Eq_17 bp_1105;
	Eq_17 ds_1149;
	if (ss->*((word32) bp_1039 - 4) != 0x14)
	{
		struct Eq_31239 Eq_17::* sp_3309 = sp_598 - 2;
		(ss->*sp_3309).t0000.u2 = (uint16) bp_1039;
		Eq_17 ds_3315;
		bp_1105 = fn0C74_1D95(ds_1174, (ss->*sp_3309).t0000.u2, out ds_3315);
		Eq_481 sp_3320;
		sp_3320.u0 = <invalid>;
		ss->*sp_3320 = ss->*((word32) bp_1105 - 0x0E);
		ss->*((word16) sp_3320 - 2) = ss->*((word32) bp_1105 - 16);
		ss->*((word16) sp_3320 - 4) = ss->*((word32) bp_1105 - 32);
		word16 dx_3511;
		Eq_17 ds_3340;
		fn1EDA_0254(ds_3315, ss->*((word16) sp_3320 - 8), ss->*((word16) sp_3320 - 6), ss->*((word16) sp_3320 - 4), ss->*((word16) sp_3320 - 2), out dx_3511, out ds_3340);
		ss->*sp_3320 = ss->*((word32) bp_1105 - 18);
		ss->*((word16) sp_3320 - 2) = ss->*((word32) bp_1105 - 20);
		ss->*((word16) sp_3320 - 4) = ss->*((word32) bp_1105 - 32);
		word16 dx_3512;
		fn1EDA_0254(ds_3340, ss->*((word16) sp_3320 - 8), ss->*((word16) sp_3320 - 6), ss->*((word16) sp_3320 - 4), ss->*((word16) sp_3320 - 2), out dx_3512, out ds_1149);
		(ss->*((word32) bp_1105 - 1)).u3 = 0x00;
		goto l0C74_2AD4;
	}
	Mem845[ss:bp_1039 + -0x0A:word16] = Mem838[ds_1174:22708:word16] + 0x1A + Mem838[ss:bp_1039 + -4:word16];
	Mem851[ss:bp_1039 + -0x0C:word16] = Mem845[ds_1174:22708:word16] + 0x0D - Mem845[ss:bp_1039 + -4:word16] + 0x02;
	if (Mem851[ds_1174:22888:word16] == ~0x00)
	{
		while (ss->*((word32) bp_1039 - 4) < 0x41)
		{
			struct Eq_35064 Eq_17::* sp_864 = sp_1214 - 2;
			Mem865[ss:sp_864 + 0x00:word16] = Mem856[ds_1174:22708:word16] + 0x1E + Mem856[ss:bp_1039 + -4:word16];
			Mem870[ss:sp_864 + -2:word16] = Mem865[ds_1174:22712:word16] + 0x1B;
			byte dl_3562;
			if (fn1AB8_1E3C(ds_1174, (ss->*sp_864).tFFFE.u2, (ss->*sp_864).t0000.u2, out dl_3562) != 0x00)
				break;
			Mem889[ss:sp_864 + 0x00:word16] = Mem870[ds_1174:22708:word16] + 0x1E + Mem870[ss:bp_1039 + -4:word16];
			Mem894[ss:sp_864 + -2:word16] = Mem889[ds_1174:22712:word16] + 0x0D;
			byte dl_3563;
			if (fn1AB8_1E3C(ds_1174, (ss->*sp_864).tFFFE.u2, (ss->*sp_864).t0000.u2, out dl_3563) != 0x00)
				break;
			(ss->*sp_864).t0000.u2 = (uint16) 0xE6;
			(ss->*sp_864).tFFFE.u2 = (uint16) 0x0F;
			bp_1039 = fn0C74_070D(ds_1174, (ss->*sp_864).tFFFE.u2, (ss->*sp_864).t0000.u2, out ds_1174);
			Eq_481 sp_1178;
			sp_1178.u0 = <invalid>;
			Mem1188[ss:sp_1178 + 0x02:word16] = Mem1168[ds_1174:22708:word16] + 0x19 + Mem1168[ss:bp_1039 + -4:word16];
			Mem1193[ss:sp_1178 + 0x00:word16] = Mem1188[ds_1174:22712:word16] + 0x0D;
			Eq_17 es_di_1194 = ss->*((word32) bp_1039 - 20);
			ss->*((word16) sp_1178 - 2) = SLICE(es_di_1194, selector, 16);
			ss->*((word16) sp_1178 - 4) = (word16) es_di_1194;
			ss->*((word16) sp_1178 - 6) = 0x00;
			fn1AB8_13D7(ds_1174, ss->*((word16) sp_1178 + 6), ss->*((word16) sp_1178 - 4), ss->*sp_1178, ss->*((word16) sp_1178 + 2));
			(ss->*((word32) bp_1039 - 4)).u3 = &(ss->*((word32) bp_1039 - 4)).u3->t0001.u0;
			sp_1214 = (word16) sp_1178 + 4;
		}
		if (ss->*((word32) bp_1039 - 4) != 0x41)
		{
			struct Eq_35268 Eq_17::* sp_916 = sp_1214 - 2;
			(ss->*sp_916).t0000.u2 = (uint16) (ss->*((word32) bp_1039 - 18));
			(ss->*sp_916).tFFFE.u2 = (uint16) (ss->*((word32) bp_1039 - 20));
			(ss->*sp_916).tFFFC.u2 = (uint16) (ss->*((word32) bp_1039 - 32));
			word16 dx_3565;
			Eq_17 ds_931;
			fn1EDA_0254(ds_1174, (ss->*sp_916).tFFF8.u2, (ss->*sp_916).tFFFA.u2, (ss->*sp_916).tFFFC.u2, (ss->*sp_916).tFFFE.u3, out dx_3565, out ds_931);
			Mem945[ss:sp_916 + 0x00:word16] = Mem923[ds_931:22708:word16] + 0x19 + Mem923[ss:bp_1039 + -4:word16];
			Mem949[ss:sp_916 + -2:word16] = Mem945[ds_931:22712:word16] + 0x0D;
			Mem954[ss:sp_916 + -4:word16] = Mem949[ds_931:22708:word16] + 0x1D + Mem949[ss:bp_1039 + -4:word16];
			Mem959[ss:sp_916 + -6:word16] = Mem954[ds_931:22712:word16] + 0x1B;
			ss->*((word32) bp_1039 - 0x0022) = fn1AB8_13A3(ds_931, (ss->*sp_916).tFFFA.u2, (ss->*sp_916).tFFFC.u2, (ss->*sp_916).tFFFE.u2, (ss->*sp_916).t0000.u2);
			(ss->*sp_916).t0000.u2 = (uint16) (ss->*((word32) bp_1039 - 0x0022));
			Eq_17 dx_ax_3566 = fn1EDA_023F(ds_931, (ss->*sp_916).tFFFC.u2, (ss->*sp_916).tFFFE.u2, (ss->*sp_916).t0000.u2, out ds_1036);
			ss->*((word32) bp_1039 - 20) = (word16) dx_ax_3566;
			(ss->*((word32) bp_1039 - 18)).u3 = SLICE(dx_ax_3566, word16, 16);
			Mem993[ss:sp_916 + 0x00:word16] = Mem988[ds_1036:22708:word16] + 0x19 + Mem988[ss:bp_1039 + -4:word16];
			Mem997[ss:sp_916 + -2:word16] = Mem993[ds_1036:22712:word16] + 0x0D;
			Mem1002[ss:sp_916 + -4:word16] = Mem997[ds_1036:22708:word16] + 0x1D + Mem997[ss:bp_1039 + -4:word16];
			Mem1007[ss:sp_916 + -6:word16] = Mem1002[ds_1036:22712:word16] + 0x1B;
			Eq_17 es_di_1008 = ss->*((word32) bp_1039 - 20);
			(ss->*sp_916).tFFF8.u2 = (uint16) SLICE(es_di_1008, selector, 16);
			(ss->*sp_916).tFFF6.u2 = (uint16) (word16) es_di_1008;
			fn1AB8_1E6B(ds_1036, (ss->*sp_916).tFFF6.u3, (ss->*sp_916).tFFFA.u2, (ss->*sp_916).tFFFC.u2, (ss->*sp_916).tFFFE.u2, (ss->*sp_916).t0000.u2);
			struct Eq_35503 Eq_17::* sp_1025 = (struct Eq_35503 Eq_17::*) &sp_916->t0002.u0;
			Eq_17 ax_1026 = ss->*((word32) bp_1039 - 4);
			if (ax_1026 >= 0x13)
			{
				ss->*((word32) bp_1039 - 6) = ax_1026;
				while (true)
				{
					struct Eq_35648 Eq_17::* sp_1031 = sp_1025 - 2;
					(ss->*sp_1031).t0000.u2 = (uint16) 0xE6;
					(ss->*sp_1031).tFFFE.u2 = (uint16) 0x19;
					bp_1039 = fn0C74_070D(ds_1036, (ss->*sp_1031).tFFFE.u2, (ss->*sp_1031).t0000.u2, out ds_1036);
					Eq_481 sp_1047;
					sp_1047.u0 = <invalid>;
					Mem1057[ss:sp_1047 + 0x02:word16] = Mem1035[ds_1036:22708:word16] + 0x19 + Mem1035[ss:bp_1039 + -6:word16];
					Mem1062[ss:sp_1047 + 0x00:word16] = Mem1057[ds_1036:22712:word16] + 0x0D;
					Eq_17 es_di_1063 = ss->*((word32) bp_1039 - 20);
					ss->*((word16) sp_1047 - 2) = SLICE(es_di_1063, selector, 16);
					ss->*((word16) sp_1047 - 4) = (word16) es_di_1063;
					ss->*((word16) sp_1047 - 6) = 0x00;
					fn1AB8_13D7(ds_1036, ss->*((word16) sp_1047 + 6), ss->*((word16) sp_1047 - 4), ss->*sp_1047, ss->*((word16) sp_1047 + 2));
					sp_1025 = (word16) sp_1047 + 4;
					if (ss->*((word32) bp_1039 - 6) == 0x13)
						break;
					--ss->*((word32) bp_1039 - 6);
				}
			}
			(ss->*((word32) bp_1039 - 4)).u0 = 0x14;
			struct Eq_35532 Eq_17::* sp_1093 = sp_1025 - 2;
			(ss->*sp_1093).t0000.u2 = (uint16) bp_1039;
			Eq_17 ds_1101;
			bp_1105 = fn0C74_1D95(ds_1036, (ss->*sp_1093).t0000.u2, out ds_1101);
			Eq_481 sp_1106;
			sp_1106.u0 = <invalid>;
			ss->*sp_1106 = ss->*((word32) bp_1105 - 0x0E);
			ss->*((word16) sp_1106 - 2) = ss->*((word32) bp_1105 - 16);
			ss->*((word16) sp_1106 - 4) = ss->*((word32) bp_1105 - 32);
			word16 dx_3567;
			Eq_17 ds_1126;
			fn1EDA_0254(ds_1101, ss->*((word16) sp_1106 - 8), ss->*((word16) sp_1106 - 6), ss->*((word16) sp_1106 - 4), ss->*((word16) sp_1106 - 2), out dx_3567, out ds_1126);
			ss->*sp_1106 = ss->*((word32) bp_1105 - 18);
			ss->*((word16) sp_1106 - 2) = ss->*((word32) bp_1105 - 20);
			ss->*((word16) sp_1106 - 4) = ss->*((word32) bp_1105 - 0x0022);
			word16 dx_3568;
			fn1EDA_0254(ds_1126, ss->*((word16) sp_1106 - 8), ss->*((word16) sp_1106 - 6), ss->*((word16) sp_1106 - 4), ss->*((word16) sp_1106 - 2), out dx_3568, out ds_1149);
			(ss->*((word32) bp_1105 - 1)).u3 = 0x00;
			goto l0C74_2AD4;
		}
		Mem1164[ss:bp_1039 + -0x0A:word16] = Mem911[ds_1174:22708:word16] + 0x1A + Mem911[ss:bp_1039 + -4:word16];
	}
	if (Mem1219[ds_1174:22888:word16] == 0x01)
	{
		while (ss->*((word32) bp_1039 - 4) < 0x41)
		{
			struct Eq_31865 Eq_17::* sp_1232 = sp_1214 - 2;
			Mem1233[ss:sp_1232 + 0x00:word16] = Mem1224[ds_1174:22708:word16] + 0x0C - Mem1224[ss:bp_1039 + -4:word16];
			Mem1238[ss:sp_1232 + -2:word16] = Mem1233[ds_1174:22712:word16] + 0x1B;
			byte dl_3524;
			if (fn1AB8_1E3C(ds_1174, (ss->*sp_1232).tFFFE.u2, (ss->*sp_1232).t0000.u2, out dl_3524) != 0x00)
				break;
			Mem1257[ss:sp_1232 + 0x00:word16] = Mem1238[ds_1174:22708:word16] + 0x0C - Mem1238[ss:bp_1039 + -4:word16];
			Mem1262[ss:sp_1232 + -2:word16] = Mem1257[ds_1174:22712:word16] + 0x0D;
			byte dl_3525;
			if (fn1AB8_1E3C(ds_1174, (ss->*sp_1232).tFFFE.u2, (ss->*sp_1232).t0000.u2, out dl_3525) != 0x00)
				break;
			(ss->*sp_1232).t0000.u2 = (uint16) 0xE6;
			(ss->*sp_1232).tFFFE.u2 = (uint16) 0x0F;
			bp_1039 = fn0C74_070D(ds_1174, (ss->*sp_1232).tFFFE.u2, (ss->*sp_1232).t0000.u2, out ds_1174);
			Eq_481 sp_1549;
			sp_1549.u0 = <invalid>;
			Mem1559[ss:sp_1549 + 0x02:word16] = Mem1539[ds_1174:22708:word16] + 0x0D - Mem1539[ss:bp_1039 + -4:word16];
			Mem1564[ss:sp_1549 + 0x00:word16] = Mem1559[ds_1174:22712:word16] + 0x0D;
			Eq_17 es_di_1565 = ss->*((word32) bp_1039 - 16);
			ss->*((word16) sp_1549 - 2) = SLICE(es_di_1565, selector, 16);
			ss->*((word16) sp_1549 - 4) = (word16) es_di_1565;
			ss->*((word16) sp_1549 - 6) = 0x00;
			fn1AB8_13D7(ds_1174, ss->*((word16) sp_1549 + 6), ss->*((word16) sp_1549 - 4), ss->*sp_1549, ss->*((word16) sp_1549 + 2));
			(ss->*((word32) bp_1039 - 4)).u3 = &(ss->*((word32) bp_1039 - 4)).u3->t0001.u0;
			sp_1214 = (word16) sp_1549 + 4;
		}
		if (ss->*((word32) bp_1039 - 4) != 0x41)
		{
			struct Eq_32361 Eq_17::* sp_1284 = sp_1214 - 2;
			(ss->*sp_1284).t0000.u2 = (uint16) (ss->*((word32) bp_1039 - 0x0E));
			(ss->*sp_1284).tFFFE.u2 = (uint16) (ss->*((word32) bp_1039 - 16));
			(ss->*sp_1284).tFFFC.u2 = (uint16) (ss->*((word32) bp_1039 - 32));
			word16 dx_3532;
			Eq_17 ds_1299;
			fn1EDA_0254(ds_1174, (ss->*sp_1284).tFFF8.u2, (ss->*sp_1284).tFFFA.u2, (ss->*sp_1284).tFFFC.u2, (ss->*sp_1284).tFFFE.u3, out dx_3532, out ds_1299);
			Mem1313[ss:sp_1284 + 0x00:word16] = Mem1291[ds_1299:22708:word16] + 0x0D - Mem1291[ss:bp_1039 + -4:word16];
			Mem1317[ss:sp_1284 + -2:word16] = Mem1313[ds_1299:22712:word16] + 0x0D;
			Mem1322[ss:sp_1284 + -4:word16] = Mem1317[ds_1299:22708:word16] + 0x11 - Mem1317[ss:bp_1039 + -4:word16];
			Mem1327[ss:sp_1284 + -6:word16] = Mem1322[ds_1299:22712:word16] + 0x1B;
			ss->*((word32) bp_1039 - 0x0022) = fn1AB8_13A3(ds_1299, (ss->*sp_1284).tFFFA.u2, (ss->*sp_1284).tFFFC.u2, (ss->*sp_1284).tFFFE.u2, (ss->*sp_1284).t0000.u2);
			(ss->*sp_1284).t0000.u2 = (uint16) (ss->*((word32) bp_1039 - 0x0022));
			Eq_17 dx_ax_3533 = fn1EDA_023F(ds_1299, (ss->*sp_1284).tFFFC.u2, (ss->*sp_1284).tFFFE.u2, (ss->*sp_1284).t0000.u2, out ds_1346);
			ss->*((word32) bp_1039 - 16) = (word16) dx_ax_3533;
			(ss->*((word32) bp_1039 - 0x0E)).u3 = SLICE(dx_ax_3533, word16, 16);
			Mem1361[ss:sp_1284 + 0x00:word16] = Mem1356[ds_1346:22708:word16] + 0x0D - Mem1356[ss:bp_1039 + -4:word16];
			Mem1365[ss:sp_1284 + -2:word16] = Mem1361[ds_1346:22712:word16] + 0x0D;
			Mem1370[ss:sp_1284 + -4:word16] = Mem1365[ds_1346:22708:word16] + 0x11 - Mem1365[ss:bp_1039 + -4:word16];
			Mem1375[ss:sp_1284 + -6:word16] = Mem1370[ds_1346:22712:word16] + 0x1B;
			Eq_17 es_di_1376 = ss->*((word32) bp_1039 - 16);
			(ss->*sp_1284).tFFF8.u2 = (uint16) SLICE(es_di_1376, selector, 16);
			(ss->*sp_1284).tFFF6.u2 = (uint16) (word16) es_di_1376;
			fn1AB8_1E6B(ds_1346, (ss->*sp_1284).tFFF6.u3, (ss->*sp_1284).tFFFA.u2, (ss->*sp_1284).tFFFC.u2, (ss->*sp_1284).tFFFE.u2, (ss->*sp_1284).t0000.u2);
			struct Eq_32596 Eq_17::* sp_1393 = (struct Eq_32596 Eq_17::*) &sp_1284->t0002.u0;
			Eq_17 ax_1394 = ss->*((word32) bp_1039 - 4);
			if (ax_1394 >= 0x13)
			{
				ss->*((word32) bp_1039 - 6) = ax_1394;
				while (true)
				{
					struct Eq_34122 Eq_17::* sp_1399 = sp_1393 - 2;
					(ss->*sp_1399).t0000.u2 = (uint16) 0xE6;
					(ss->*sp_1399).tFFFE.u2 = (uint16) 0x0F;
					bp_1039 = fn0C74_070D(ds_1346, (ss->*sp_1399).tFFFE.u2, (ss->*sp_1399).t0000.u2, out ds_1346);
					Eq_481 sp_1415;
					sp_1415.u0 = <invalid>;
					Mem1425[ss:sp_1415 + 0x02:word16] = Mem1403[ds_1346:22708:word16] + 0x0D - Mem1403[ss:bp_1039 + -6:word16];
					Mem1430[ss:sp_1415 + 0x00:word16] = Mem1425[ds_1346:22712:word16] + 0x0D;
					Eq_17 es_di_1431 = ss->*((word32) bp_1039 - 16);
					ss->*((word16) sp_1415 - 2) = SLICE(es_di_1431, selector, 16);
					ss->*((word16) sp_1415 - 4) = (word16) es_di_1431;
					ss->*((word16) sp_1415 - 6) = 0x00;
					fn1AB8_13D7(ds_1346, ss->*((word16) sp_1415 + 6), ss->*((word16) sp_1415 - 4), ss->*sp_1415, ss->*((word16) sp_1415 + 2));
					sp_1393 = (word16) sp_1415 + 4;
					if (ss->*((word32) bp_1039 - 6) == 0x13)
						break;
					--ss->*((word32) bp_1039 - 6);
				}
			}
			(ss->*((word32) bp_1039 - 4)).u0 = 0x14;
			struct Eq_34006 Eq_17::* sp_1461 = sp_1393 - 2;
			(ss->*sp_1461).t0000.u2 = (uint16) bp_1039;
			Eq_17 ds_1469;
			bp_1105 = fn0C74_1D95(ds_1346, (ss->*sp_1461).t0000.u2, out ds_1469);
			Eq_481 sp_1474;
			sp_1474.u0 = <invalid>;
			ss->*sp_1474 = ss->*((word32) bp_1105 - 0x0E);
			ss->*((word16) sp_1474 - 2) = ss->*((word32) bp_1105 - 16);
			ss->*((word16) sp_1474 - 4) = ss->*((word32) bp_1105 - 0x0022);
			word16 dx_3554;
			Eq_17 ds_1494;
			fn1EDA_0254(ds_1469, ss->*((word16) sp_1474 - 8), ss->*((word16) sp_1474 - 6), ss->*((word16) sp_1474 - 4), ss->*((word16) sp_1474 - 2), out dx_3554, out ds_1494);
			ss->*sp_1474 = ss->*((word32) bp_1105 - 18);
			ss->*((word16) sp_1474 - 2) = ss->*((word32) bp_1105 - 20);
			ss->*((word16) sp_1474 - 4) = ss->*((word32) bp_1105 - 32);
			word16 dx_3555;
			fn1EDA_0254(ds_1494, ss->*((word16) sp_1474 - 8), ss->*((word16) sp_1474 - 6), ss->*((word16) sp_1474 - 4), ss->*((word16) sp_1474 - 2), out dx_3555, out ds_1149);
			(ss->*((word32) bp_1105 - 1)).u3 = 0x00;
			goto l0C74_2AD4;
		}
		Mem1535[ss:bp_1039 + -0x0C:word16] = Mem1279[ds_1174:22708:word16] + 0x0D - Mem1279[ss:bp_1039 + -4:word16] + 0x02;
	}
	struct Eq_31692 Eq_17::* sp_1641 = sp_1214 - 2;
	word16 cx_3517;
	word16 dx_3518;
	word16 bx_3519;
	Eq_17 ds_1630;
	Mem1642[ss:sp_1641 + 0x00:word16] = fn1EDA_098A(0x04, fn1EDA_096F(Mem1590[ds_1174:0x4D0C:word16], Mem1590[ds_1174:22758:word16], 0x00, 0x00), Mem1590[ss:sp_1214 + -4:word16], Mem1590[ss:sp_1214 + -2:word16], out cx_3517, out dx_3518, out bx_3519, out ds_1630);
	Eq_17 bp_1644 = fn0C74_02D8(ds_1630, (ss->*sp_1641).t0000.u2, out ds_1648);
	Mem1660[ss:bp_1644 + -4:word16] = Mem1642[ds_1648:22712:word16] + 0x1C;
	Mem1664[ss:bp_1644 + -6:word16] = Mem1660[ds_1648:22712:word16] + 0x1C;
	Eq_481 sp_1652;
	sp_1652.u0 = <invalid>;
	struct Eq_31756 Eq_17::* sp_1657 = (word16) sp_1652 + 2;
	while (true)
	{
		struct Eq_31772 Eq_17::* sp_1670 = sp_1657 - 2;
		(ss->*sp_1670).t0000.u2 = (uint16) (ss->*((word32) bp_1644 - 0x0C));
		(ss->*sp_1670).tFFFE.u2 = (uint16) (ss->*((word32) bp_1644 - 6));
		byte dl_3564;
		if (fn1AB8_1E3C(ds_1648, (ss->*sp_1670).tFFFE.u2, (ss->*sp_1670).t0000.u2, out dl_3564) != 0x00)
		{
			(ss->*sp_1670).t0000.u2 = (uint16) (ss->*((word32) bp_1644 - 0x0A));
			(ss->*sp_1670).tFFFE.u2 = (uint16) (ss->*((word32) bp_1644 - 4));
			byte dl_3520;
			if (fn1AB8_1E3C(ds_1648, (ss->*sp_1670).tFFFE.u2, (ss->*sp_1670).t0000.u2, out dl_3520) != 0x00)
			{
l0C74_2644:
				union Eq_17 Eq_17::* sp_1935 = sp_1657 - 2;
				word16 cx_3521;
				word16 dx_3522;
				word16 bx_3523;
				Eq_17 ds_1924;
				Mem1936[ss:sp_1935 + 0x00:word16] = fn1EDA_098A(0x04, fn1EDA_096F(Mem1889[ds_1648:0x4D0C:word16], Mem1889[ds_1648:22758:word16], 0x00, 0x00), Mem1889[ss:sp_1657 + -4:word16], Mem1889[ss:sp_1657 + -2:word16], out cx_3521, out dx_3522, out bx_3523, out ds_1924);
				Eq_481 sp_1946;
				sp_1946.u0 = <invalid>;
				Eq_17 bp_1938 = fn0C74_02D8(ds_1924, (ss->*sp_1935).u2, out ds_1942);
				struct Eq_31846 Eq_17::* sp_1951 = (word16) sp_1946 + 2;
				if (Mem1936[ds_1942:22714:word16] + 0x59 >u Mem1936[ss:bp_1938 + -4:word16] && Mem1936[ds_1942:22714:word16] + 0x59 >u Mem1936[ss:bp_1938 + -6:word16])
				{
					Mem1962[ss:sp_1946 + 0x00:word16] = Mem1936[ds_1942:22708:word16];
					Mem1965[ss:sp_1946 + -2:word16] = Mem1962[ds_1942:22712:word16];
					Mem1968[ss:sp_1946 + -4:word16] = Mem1965[ds_1942:22710:word16];
					Mem1971[ss:sp_1946 + -6:word16] = Mem1968[ds_1942:22714:word16];
					ss->*((word32) bp_1938 - 40) = fn1AB8_13A3(ds_1942, ss->*((word16) sp_1946 - 6), ss->*((word16) sp_1946 - 4), ss->*((word16) sp_1946 - 2), ss->*sp_1946);
					ss->*sp_1946 = ss->*((word32) bp_1938 - 40);
					Eq_17 dx_ax_3528 = fn1EDA_023F(ds_1942, ss->*((word16) sp_1946 - 4), ss->*((word16) sp_1946 - 2), ss->*sp_1946, out ds_1990);
					ss->*((word32) bp_1938 - 28) = (word16) dx_ax_3528;
					(ss->*((word32) bp_1938 - 26)).u3 = SLICE(dx_ax_3528, word16, 16);
					Mem2003[ss:sp_1946 + 0x00:word16] = Mem2000[ds_1990:22708:word16];
					Mem2006[ss:sp_1946 + -2:word16] = Mem2003[ds_1990:22712:word16];
					Mem2009[ss:sp_1946 + -4:word16] = Mem2006[ds_1990:22710:word16];
					Mem2012[ss:sp_1946 + -6:word16] = Mem2009[ds_1990:22714:word16];
					Eq_17 es_di_2013 = ss->*((word32) bp_1938 - 28);
					ss->*((word16) sp_1946 - 8) = SLICE(es_di_2013, selector, 16);
					ss->*((word16) sp_1946 - 0x0A) = (word16) es_di_2013;
					fn1AB8_1E6B(ds_1990, ss->*((word16) sp_1946 - 0x0A), ss->*((word16) sp_1946 - 6), ss->*((word16) sp_1946 - 4), ss->*((word16) sp_1946 - 2), ss->*sp_1946);
					word16 cx_3529;
					word16 dx_3530;
					word16 bx_3531;
					Eq_17 ds_2062;
					Mem2074[ss:sp_1946 + 0x00:word16] = fn1EDA_098A(0x04, fn1EDA_096F(Mem2019[ds_1990:0x4D0C:word16], Mem2019[ds_1990:22758:word16], 0x00, 0x00), Mem2019[ss:sp_1946 + ~0x01:word16], Mem2019[ss:sp_1946 + 0x00:word16], out cx_3529, out dx_3530, out bx_3531, out ds_2062);
					Eq_17 ds_2080;
					(ss->*((word16) fn0C74_02D8(ds_2062, ss->*sp_1946, out ds_2080) - 8)).u3 = 0x01;
					Eq_481 sp_2084;
					sp_2084.u0 = <invalid>;
					struct Eq_32358 Eq_17::* sp_2089 = (word16) sp_2084 + 2;
					Eq_481 sp_2108;
					while (true)
					{
						struct Eq_33051 Eq_17::* sp_2092 = sp_2089 - 2;
						(ss->*sp_2092).t0000.u2 = (uint16) 0x32;
						(ss->*sp_2092).tFFFE.u2 = (uint16) 0x14;
						Eq_17 bp_2100 = fn0C74_070D(ds_2080, (ss->*sp_2092).tFFFE.u2, (ss->*sp_2092).t0000.u2, out ds_2080);
						Mem2126[ds_2080:22708:word16] = Mem2096[ds_2080:22708:word16] - Mem2096[ds_2080:22888:word16];
						Mem2140[ds_2080:22710:word16] = Mem2126[ds_2080:22710:word16] - Mem2126[ds_2080:22888:word16];
						sp_2108.u0 = <invalid>;
						Mem2143[ss:sp_2108 + 0x02:word16] = Mem2140[ds_2080:22708:word16];
						Mem2146[ss:sp_2108 + 0x00:word16] = Mem2143[ds_2080:22712:word16];
						Eq_17 es_di_2147 = ss->*((word32) bp_2100 - 28);
						ss->*((word16) sp_2108 - 2) = SLICE(es_di_2147, selector, 16);
						ss->*((word16) sp_2108 - 4) = (word16) es_di_2147;
						ss->*((word16) sp_2108 - 6) = 0x00;
						fn1AB8_13D7(ds_2080, ss->*((word16) sp_2108 + 6), ss->*((word16) sp_2108 - 4), ss->*sp_2108, ss->*((word16) sp_2108 + 2));
						sp_2089 = (word16) sp_2108 + 4;
						if (ss->*((word32) bp_2100 - 8) == 44)
							break;
						(ss->*((word32) bp_2100 - 8)).u3 = &(ss->*((word32) bp_2100 - 8)).u3->t0001.u0;
					}
					word16 cx_3541;
					word16 dx_3542;
					word16 bx_3543;
					Eq_17 ds_2204;
					Mem2216[ss:sp_2108 + 0x02:word16] = fn1EDA_098A(0x04, fn1EDA_096F(Mem2155[ds_2080:0x4D0C:word16], Mem2155[ds_2080:22758:word16], 0x00, 0x00), Mem2155[ss:sp_2108 + 0x00:word16], Mem2155[ss:sp_2108 + 0x02:word16], out cx_3541, out dx_3542, out bx_3543, out ds_2204);
					Eq_17 ds_2222;
					bp_1938 = fn0C74_02D8(ds_2204, ss->*((word16) sp_2108 + 2), out ds_2222);
					Eq_481 sp_2226;
					sp_2226.u0 = <invalid>;
					ss->*sp_2226 = ss->*((word32) bp_1938 - 26);
					ss->*((word16) sp_2226 - 2) = ss->*((word32) bp_1938 - 28);
					ss->*((word16) sp_2226 - 4) = ss->*((word32) bp_1938 - 40);
					word16 dx_3544;
					fn1EDA_0254(ds_2222, ss->*((word16) sp_2226 - 8), ss->*((word16) sp_2226 - 6), ss->*((word16) sp_2226 - 4), ss->*((word16) sp_2226 - 2), out dx_3544, out ds_1942);
					sp_1951 = (word16) sp_2226 + 2;
				}
				struct Eq_32047 Eq_17::* sp_2259 = sp_1951 - 2;
				Mem2261[ss:sp_2259 + 0x00:word16] = Mem2256[ds_1942:22708:word16];
				Mem2266[ss:sp_2259 + -2:word16] = Mem2261[ds_1942:22714:word16] + 0x01;
				struct Eq_32066 Eq_17::* sp_2275 = (struct Eq_32066 Eq_17::*) ((char *) &sp_2259->t0000 + 2);
				byte dl_3526;
				if (fn1AB8_1E3C(ds_1942, (ss->*sp_2259).tFFFE.u2, (ss->*sp_2259).t0000.u2, out dl_3526) == 0x00)
				{
					Mem2283[ss:sp_2259 + 0x00:word16] = Mem2266[ds_1942:22710:word16];
					Mem2288[ss:sp_2259 + -2:word16] = Mem2283[ds_1942:22714:word16] + 0x01;
					sp_2275 = (struct Eq_32066 Eq_17::*) ((char *) &sp_2259->t0000 + 2);
					byte dl_3527;
					if (fn1AB8_1E3C(ds_1942, (ss->*sp_2259).tFFFE.u2, (ss->*sp_2259).t0000.u2, out dl_3527) == 0x00)
					{
						Mem2305[ss:sp_2259 + 0x00:word16] = Mem2288[ds_1942:22708:word16];
						Mem2310[ss:sp_2259 + -2:word16] = Mem2305[ds_1942:22714:word16] - 0x0E;
						Mem2313[ss:sp_2259 + -4:word16] = Mem2310[ds_1942:22710:word16];
						Mem2316[ss:sp_2259 + -6:word16] = Mem2313[ds_1942:22714:word16];
						ss->*((word32) bp_1938 - 30) = fn1AB8_13A3(ds_1942, (ss->*sp_2259).tFFFA.u2, (ss->*sp_2259).tFFFC.u2, (ss->*sp_2259).tFFFE.u2, (ss->*sp_2259).t0000.u2);
						Mem2332[ss:sp_2259 + 0x00:word16] = Mem2328[ds_1942:22708:word16] + 0x17;
						Mem2337[ss:sp_2259 + -2:word16] = Mem2332[ds_1942:22714:word16] - 0x0E;
						(ss->*sp_2259).tFFFC.u2 = (uint16) 0x03;
						fn1AB8_1E54(ds_1942, (ss->*sp_2259).tFFFC.u0, (ss->*sp_2259).tFFFE.u2, (ss->*sp_2259).t0000.u2);
						Mem2348[ss:sp_2259 + 0x00:word16] = Mem2339[ds_1942:22708:word16] + 0x18;
						Mem2353[ss:sp_2259 + -2:word16] = Mem2348[ds_1942:22714:word16] - 0x0E;
						(ss->*sp_2259).tFFFC.u2 = (uint16) 0x01;
						fn1AB8_1E54(ds_1942, (ss->*sp_2259).tFFFC.u0, (ss->*sp_2259).tFFFE.u2, (ss->*sp_2259).t0000.u2);
						Mem2364[ss:sp_2259 + 0x00:word16] = Mem2355[ds_1942:22708:word16] + 0x19;
						Mem2369[ss:sp_2259 + -2:word16] = Mem2364[ds_1942:22714:word16] - 0x0E;
						(ss->*sp_2259).tFFFC.u2 = (uint16) 0x01;
						fn1AB8_1E54(ds_1942, (ss->*sp_2259).tFFFC.u0, (ss->*sp_2259).tFFFE.u2, (ss->*sp_2259).t0000.u2);
						(ss->*sp_2259).t0000.u2 = (uint16) (ss->*((word32) bp_1938 - 30));
						Eq_17 dx_ax_3556 = fn1EDA_023F(ds_1942, (ss->*sp_2259).tFFFC.u2, (ss->*sp_2259).tFFFE.u2, (ss->*sp_2259).t0000.u2, out ds_2385);
						ss->*((word32) bp_1938 - 24) = (word16) dx_ax_3556;
						(ss->*((word32) bp_1938 - 22)).u3 = SLICE(dx_ax_3556, word16, 16);
						Mem2398[ss:sp_2259 + 0x00:word16] = Mem2395[ds_2385:22708:word16];
						Mem2403[ss:sp_2259 + -2:word16] = Mem2398[ds_2385:22714:word16] - 0x0E;
						Mem2406[ss:sp_2259 + -4:word16] = Mem2403[ds_2385:22710:word16];
						Mem2409[ss:sp_2259 + -6:word16] = Mem2406[ds_2385:22714:word16];
						Eq_17 es_di_2410 = ss->*((word32) bp_1938 - 24);
						(ss->*sp_2259).tFFF8.u2 = (uint16) SLICE(es_di_2410, selector, 16);
						(ss->*sp_2259).tFFF6.u2 = (uint16) (word16) es_di_2410;
						fn1AB8_1E6B(ds_2385, (ss->*sp_2259).tFFF6.u3, (ss->*sp_2259).tFFFA.u2, (ss->*sp_2259).tFFFC.u2, (ss->*sp_2259).tFFFE.u2, (ss->*sp_2259).t0000.u2);
						(ss->*((word32) bp_1938 - 8)).u3 = 0x00;
						struct Eq_34486 Eq_17::* sp_2427 = (struct Eq_34486 Eq_17::*) ((char *) &sp_2259->t0000 + 2);
						while (true)
						{
							struct Eq_34563 Eq_17::* sp_2438 = sp_2427 - 2;
							Mem2440[ss:sp_2438 + 0x00:word16] = Mem2434[ds_2385:22708:word16] + 0x01;
							Mem2445[ss:sp_2438 + -2:word16] = Mem2440[ds_2385:22714:word16] + 0x01;
							byte dl_3559;
							if (fn1AB8_1E3C(ds_2385, (ss->*sp_2438).tFFFE.u2, (ss->*sp_2438).t0000.u2, out dl_3559) != 0x00)
								break;
							Mem2463[ss:sp_2438 + 0x00:word16] = Mem2445[ds_2385:22710:word16] - 0x01;
							Mem2468[ss:sp_2438 + -2:word16] = Mem2463[ds_2385:22714:word16] + 0x01;
							byte dl_3558;
							if (fn1AB8_1E3C(ds_2385, (ss->*sp_2438).tFFFE.u2, (ss->*sp_2438).t0000.u2, out dl_3558) != 0x00 || ss->*((word32) bp_1938 - 8) >= 0x59)
								break;
							(ss->*sp_2438).t0000.u2 = (uint16) 100;
							(ss->*sp_2438).tFFFE.u2 = (uint16) 0x1E;
							bp_1938 = fn0C74_070D(ds_2385, (ss->*sp_2438).tFFFE.u2, (ss->*sp_2438).t0000.u2, out ds_2385);
							Mem2536[ds_2385:22714:word16] = Mem2519[ds_2385:22714:word16] + 0x01;
							(ss->*((word32) bp_1938 - 8)).u3 = &(ss->*((word32) bp_1938 - 8)).u3->t0001.u0;
							Eq_481 sp_2529;
							sp_2529.u0 = <invalid>;
							Mem2541[ss:sp_2529 + 0x02:word16] = Mem2538[ds_2385:22708:word16];
							Mem2546[ss:sp_2529 + 0x00:word16] = Mem2541[ds_2385:22714:word16] - 0x0E;
							Eq_17 es_di_2547 = ss->*((word32) bp_1938 - 24);
							ss->*((word16) sp_2529 - 2) = SLICE(es_di_2547, selector, 16);
							ss->*((word16) sp_2529 - 4) = (word16) es_di_2547;
							ss->*((word16) sp_2529 - 6) = 0x00;
							fn1AB8_13D7(ds_2385, ss->*((word16) sp_2529 + 6), ss->*((word16) sp_2529 - 4), ss->*sp_2529, ss->*((word16) sp_2529 + 2));
							sp_2427 = (word16) sp_2529 + 4;
						}
						struct Eq_34509 Eq_17::* sp_2491 = sp_2427 - 2;
						(ss->*sp_2491).t0000.u2 = (uint16) (ss->*((word32) bp_1938 - 22));
						(ss->*sp_2491).tFFFE.u2 = (uint16) (ss->*((word32) bp_1938 - 24));
						(ss->*sp_2491).tFFFC.u2 = (uint16) (ss->*((word32) bp_1938 - 30));
						word16 dx_3557;
						fn1EDA_0254(ds_2385, (ss->*sp_2491).tFFF8.u2, (ss->*sp_2491).tFFFA.u2, (ss->*sp_2491).tFFFC.u2, (ss->*sp_2491).tFFFE.u3, out dx_3557, out ds_1942);
						sp_2275 = (struct Eq_32066 Eq_17::*) ((char *) &sp_2491->t0000 + 2);
					}
				}
				struct Eq_32115 Eq_17::* sp_2569 = sp_2275 - 2;
				(ss->*sp_2569).t0000.u2 = (uint16) 0x00;
				(ss->*sp_2569).tFFFE.u2 = (uint16) 0x00;
				(ss->*sp_2569).tFFFC.u2 = (uint16) 0x01;
				fn1AB8_10F4(ds_1942, (ss->*sp_2569).tFFFC.u2, (ss->*sp_2569).tFFFE.u2, (ss->*sp_2569).t0000.u2);
				(ss->*sp_2569).t0000.u2 = (uint16) 0x00;
				fn1AB8_1C32(ds_1942, (ss->*sp_2569).t0000.u0);
				struct Eq_32158 Eq_17::* sp_2592 = (struct Eq_32158 Eq_17::*) ((char *) &sp_2569->t0000 + 2);
				while (Mem2594[ds_1942:22712:word16] + 0x1C <u Mem2594[ss:bp_1938 + -6:word16] || Mem2594[ds_1942:22712:word16] + 0x1C <u Mem2594[ss:bp_1938 + -4:word16])
				{
					if (Mem2594[ds_1942:22712:word16] + 0x1C <u Mem2594[ss:bp_1938 + -6:word16])
					{
						--ss->*((word32) bp_1938 - 6);
						struct Eq_32994 Eq_17::* sp_3232 = sp_2592 - 2;
						(ss->*sp_3232).t0000.u2 = (uint16) (ss->*((word32) bp_1938 - 0x0C));
						(ss->*sp_3232).tFFFE.u2 = (uint16) (ss->*((word32) bp_1938 - 6));
						(ss->*sp_3232).tFFFC.u2 = (uint16) &(ss->*((word32) bp_1938 - 0x0C)).u3->t0002.u0;
						(ss->*sp_3232).tFFFA.u2 = (uint16) (ss->*((word32) bp_1938 - 6));
						word16 dx_3540;
						fn1AB8_1AF6(ds_1942, (ss->*sp_3232).tFFFA.u2, (ss->*sp_3232).tFFFC.u2, (ss->*sp_3232).tFFFE.u2, (ss->*sp_3232).t0000.u2, out dx_3540);
					}
					if (Mem3253[ds_1942:22712:word16] + 0x1C <u Mem3253[ss:bp_1938 + -4:word16])
					{
						--ss->*((word32) bp_1938 - 4);
						struct Eq_33292 Eq_17::* sp_3264 = sp_2592 - 2;
						(ss->*sp_3264).t0000.u2 = (uint16) (ss->*((word32) bp_1938 - 0x0A));
						(ss->*sp_3264).tFFFE.u2 = (uint16) (ss->*((word32) bp_1938 - 4));
						(ss->*sp_3264).tFFFC.u2 = (uint16) &(ss->*((word32) bp_1938 - 0x0A)).u3->t0002.u0;
						(ss->*sp_3264).tFFFA.u2 = (uint16) (ss->*((word32) bp_1938 - 4));
						word16 dx_3545;
						fn1AB8_1AF6(ds_1942, (ss->*sp_3264).tFFFA.u2, (ss->*sp_3264).tFFFC.u2, (ss->*sp_3264).tFFFE.u2, (ss->*sp_3264).t0000.u2, out dx_3545);
					}
					struct Eq_33255 Eq_17::* sp_3285 = sp_2592 - 2;
					(ss->*sp_3285).t0000.u2 = (uint16) 0xFA;
					(ss->*sp_3285).tFFFE.u2 = (uint16) 0x0F;
					Eq_481 sp_3303;
					sp_3303.u0 = <invalid>;
					bp_1938 = fn0C74_070D(ds_1942, (ss->*sp_3285).tFFFE.u2, (ss->*sp_3285).t0000.u2, out ds_1942);
					sp_2592 = (word16) sp_3303 + 4;
				}
				struct Eq_32642 Eq_17::* sp_2649 = sp_2592 - 2;
				word16 cx_3534;
				word16 dx_3535;
				word16 bx_3536;
				Eq_17 ds_2638;
				Mem2650[ss:sp_2649 + 0x00:word16] = fn1EDA_098A(0x04, fn1EDA_096F(Mem2594[ds_1942:0x4D0C:word16], Mem2594[ds_1942:22758:word16], 0x00, 0x00), Mem2594[ss:sp_2592 + -4:word16], Mem2594[ss:sp_2592 + -2:word16], out cx_3534, out dx_3535, out bx_3536, out ds_2638);
				Eq_17 bp_2652 = fn0C74_02D8(ds_2638, (ss->*sp_2649).t0000.u2, out ds_2656);
				Eq_481 sp_2660;
				sp_2660.u0 = <invalid>;
				ss->*sp_2660 = ss->*((word32) bp_2652 - 0x0E);
				ss->*((word16) sp_2660 - 2) = ss->*((word32) bp_2652 - 16);
				ss->*((word16) sp_2660 - 4) = ss->*((word32) bp_2652 - 32);
				word16 dx_3537;
				Eq_17 ds_2679;
				fn1EDA_0254(ds_2656, ss->*((word16) sp_2660 - 8), ss->*((word16) sp_2660 - 6), ss->*((word16) sp_2660 - 4), ss->*((word16) sp_2660 - 2), out dx_3537, out ds_2679);
				ss->*sp_2660 = ss->*((word32) bp_2652 - 18);
				ss->*((word16) sp_2660 - 2) = ss->*((word32) bp_2652 - 20);
				ss->*((word16) sp_2660 - 4) = ss->*((word32) bp_2652 - 32);
				word16 dx_3538;
				Eq_17 ds_2702;
				fn1EDA_0254(ds_2679, ss->*((word16) sp_2660 - 8), ss->*((word16) sp_2660 - 6), ss->*((word16) sp_2660 - 4), ss->*((word16) sp_2660 - 2), out dx_3538, out ds_2702);
				ss->*sp_2660 = ss->*((word32) bp_2652 - 0x0A) - 0x01;
				Mem2719[ss:sp_2660 + -2:word16] = Mem2715[ds_2702:22712:word16] + 0x0D;
				ss->*((word16) sp_2660 - 4) = &(ss->*((word32) bp_2652 - 0x0A)).u3->t0004.u0;
				Mem2728[ss:sp_2660 + -6:word16] = Mem2723[ds_2702:22712:word16] + 0x1B;
				ss->*((word32) bp_2652 - 32) = fn1AB8_13A3(ds_2702, ss->*((word16) sp_2660 - 6), ss->*((word16) sp_2660 - 4), ss->*((word16) sp_2660 - 2), ss->*sp_2660);
				ss->*sp_2660 = ss->*((word32) bp_2652 - 32);
				Eq_17 dx_ax_3539 = fn1EDA_023F(ds_2702, ss->*((word16) sp_2660 - 4), ss->*((word16) sp_2660 - 2), ss->*sp_2660, out ds_2747);
				ss->*((word32) bp_2652 - 20) = (word16) dx_ax_3539;
				(ss->*((word32) bp_2652 - 18)).u3 = SLICE(dx_ax_3539, word16, 16);
				ss->*sp_2660 = ss->*((word32) bp_2652 - 0x0A) - 0x01;
				Mem2765[ss:sp_2660 + -2:word16] = Mem2761[ds_2747:22712:word16] + 0x0D;
				ss->*((word16) sp_2660 - 4) = &(ss->*((word32) bp_2652 - 0x0A)).u3->t0004.u0;
				Mem2774[ss:sp_2660 + -6:word16] = Mem2769[ds_2747:22712:word16] + 0x1B;
				Eq_17 es_di_2775 = ss->*((word32) bp_2652 - 20);
				ss->*((word16) sp_2660 - 8) = SLICE(es_di_2775, selector, 16);
				ss->*((word16) sp_2660 - 0x0A) = (word16) es_di_2775;
				fn1AB8_1E6B(ds_2747, ss->*((word16) sp_2660 - 0x0A), ss->*((word16) sp_2660 - 6), ss->*((word16) sp_2660 - 4), ss->*((word16) sp_2660 - 2), ss->*sp_2660);
				Mem2796[ss:bp_2652 + -42:word16] = Mem2781[ds_2747:22708:word16] + 44;
				struct Eq_32959 Eq_17::* sp_2792 = (word16) sp_2660 + 2;
				Eq_17 ax_2797 = ss->*((word32) bp_2652 - 0x0A);
				if (ax_2797 - 0x01 >= ss->*((word32) bp_2652 - 42))
				{
					ss->*((word32) bp_2652 - 6) = ax_2797 - 0x01;
					while (true)
					{
						struct Eq_33597 Eq_17::* sp_2803 = sp_2792 - 2;
						(ss->*sp_2803).t0000.u2 = (uint16) 0xE6;
						(ss->*sp_2803).tFFFE.u2 = (uint16) 0x0C;
						bp_2652 = fn0C74_070D(ds_2747, (ss->*sp_2803).tFFFE.u2, (ss->*sp_2803).t0000.u2, out ds_2747);
						Eq_481 sp_2819;
						sp_2819.u0 = <invalid>;
						ss->*((word16) sp_2819 + 2) = ss->*((word32) bp_2652 - 6);
						Mem2832[ss:sp_2819 + 0x00:word16] = Mem2827[ds_2747:22712:word16] + 0x0D;
						Eq_17 es_di_2833 = ss->*((word32) bp_2652 - 20);
						ss->*((word16) sp_2819 - 2) = SLICE(es_di_2833, selector, 16);
						ss->*((word16) sp_2819 - 4) = (word16) es_di_2833;
						ss->*((word16) sp_2819 - 6) = 0x00;
						fn1AB8_13D7(ds_2747, ss->*((word16) sp_2819 + 6), ss->*((word16) sp_2819 - 4), ss->*sp_2819, ss->*((word16) sp_2819 + 2));
						sp_2792 = (word16) sp_2819 + 4;
						if (ss->*((word32) bp_2652 - 6) == ss->*((word32) bp_2652 - 42))
							break;
						--ss->*((word32) bp_2652 - 6);
					}
				}
				struct Eq_33349 Eq_17::* sp_2865 = sp_2792 - 2;
				(ss->*sp_2865).t0000.u2 = (uint16) (ss->*((word32) bp_2652 - 18));
				(ss->*sp_2865).tFFFE.u2 = (uint16) (ss->*((word32) bp_2652 - 20));
				(ss->*sp_2865).tFFFC.u2 = (uint16) (ss->*((word32) bp_2652 - 32));
				word16 dx_3546;
				Eq_17 ds_2879;
				fn1EDA_0254(ds_2747, (ss->*sp_2865).tFFF8.u2, (ss->*sp_2865).tFFFA.u2, (ss->*sp_2865).tFFFC.u2, (ss->*sp_2865).tFFFE.u3, out dx_3546, out ds_2879);
				(ss->*sp_2865).t0000.u2 = (uint16) (ss->*((word32) bp_2652 - 0x0C) - 0x02);
				Mem2897[ss:sp_2865 + -2:word16] = Mem2893[ds_2879:22712:word16] + 0x0D;
				(ss->*sp_2865).tFFFC.u2 = (uint16) ((word32) (ss->*((word32) bp_2652 - 0x0C)) + 3);
				Mem2906[ss:sp_2865 + -6:word16] = Mem2901[ds_2879:22712:word16] + 0x1B;
				ss->*((word32) bp_2652 - 32) = fn1AB8_13A3(ds_2879, (ss->*sp_2865).tFFFA.u2, (ss->*sp_2865).tFFFC.u2, (ss->*sp_2865).tFFFE.u2, (ss->*sp_2865).t0000.u2);
				(ss->*sp_2865).t0000.u2 = (uint16) (ss->*((word32) bp_2652 - 32));
				Eq_17 dx_ax_3547 = fn1EDA_023F(ds_2879, (ss->*sp_2865).tFFFC.u2, (ss->*sp_2865).tFFFE.u2, (ss->*sp_2865).t0000.u2, out ds_2925);
				ss->*((word32) bp_2652 - 16) = (word16) dx_ax_3547;
				(ss->*((word32) bp_2652 - 0x0E)).u3 = SLICE(dx_ax_3547, word16, 16);
				(ss->*sp_2865).t0000.u2 = (uint16) (ss->*((word32) bp_2652 - 0x0C) - 0x02);
				Mem2944[ss:sp_2865 + -2:word16] = Mem2940[ds_2925:22712:word16] + 0x0D;
				(ss->*sp_2865).tFFFC.u2 = (uint16) ((word32) (ss->*((word32) bp_2652 - 0x0C)) + 3);
				Mem2953[ss:sp_2865 + -6:word16] = Mem2948[ds_2925:22712:word16] + 0x1B;
				Eq_17 es_di_2954 = ss->*((word32) bp_2652 - 16);
				(ss->*sp_2865).tFFF8.u2 = (uint16) SLICE(es_di_2954, selector, 16);
				(ss->*sp_2865).tFFF6.u2 = (uint16) (word16) es_di_2954;
				fn1AB8_1E6B(ds_2925, (ss->*sp_2865).tFFF6.u3, (ss->*sp_2865).tFFFA.u2, (ss->*sp_2865).tFFFC.u2, (ss->*sp_2865).tFFFE.u2, (ss->*sp_2865).t0000.u2);
				Mem2975[ss:bp_2652 + -42:word16] = Mem2960[ds_2925:22708:word16] - 0x06;
				struct Eq_33577 Eq_17::* sp_2971 = (struct Eq_33577 Eq_17::*) ((char *) &sp_2865->t0000 + 2);
				Eq_17 ax_2976 = ss->*((word32) bp_2652 - 0x0C);
				if (ax_2976 - 0x02 <= ss->*((word32) bp_2652 - 42))
				{
					ss->*((word32) bp_2652 - 6) = ax_2976 - 0x02;
					while (true)
					{
						struct Eq_33848 Eq_17::* sp_2983 = sp_2971 - 2;
						(ss->*sp_2983).t0000.u2 = (uint16) 0xE6;
						(ss->*sp_2983).tFFFE.u2 = (uint16) 0x0C;
						bp_2652 = fn0C74_070D(ds_2925, (ss->*sp_2983).tFFFE.u2, (ss->*sp_2983).t0000.u2, out ds_2925);
						Eq_481 sp_2999;
						sp_2999.u0 = <invalid>;
						ss->*((word16) sp_2999 + 2) = ss->*((word32) bp_2652 - 6);
						Mem3012[ss:sp_2999 + 0x00:word16] = Mem3007[ds_2925:22712:word16] + 0x0D;
						Eq_17 es_di_3013 = ss->*((word32) bp_2652 - 16);
						ss->*((word16) sp_2999 - 2) = SLICE(es_di_3013, selector, 16);
						ss->*((word16) sp_2999 - 4) = (word16) es_di_3013;
						ss->*((word16) sp_2999 - 6) = 0x00;
						fn1AB8_13D7(ds_2925, ss->*((word16) sp_2999 + 6), ss->*((word16) sp_2999 - 4), ss->*sp_2999, ss->*((word16) sp_2999 + 2));
						sp_2971 = (word16) sp_2999 + 4;
						if (ss->*((word32) bp_2652 - 6) == ss->*((word32) bp_2652 - 42))
							break;
						(ss->*((word32) bp_2652 - 6)).u3 = &(ss->*((word32) bp_2652 - 6)).u3->t0001.u0;
					}
				}
				struct Eq_33698 Eq_17::* sp_3045 = sp_2971 - 2;
				(ss->*sp_3045).t0000.u2 = (uint16) (ss->*((word32) bp_2652 - 0x0E));
				(ss->*sp_3045).tFFFE.u2 = (uint16) (ss->*((word32) bp_2652 - 16));
				(ss->*sp_3045).tFFFC.u2 = (uint16) (ss->*((word32) bp_2652 - 32));
				word16 dx_3548;
				Eq_17 ds_3059;
				fn1EDA_0254(ds_2925, (ss->*sp_3045).tFFF8.u2, (ss->*sp_3045).tFFFA.u2, (ss->*sp_3045).tFFFC.u2, (ss->*sp_3045).tFFFE.u3, out dx_3548, out ds_3059);
				(ss->*((word32) bp_2652 - 4)).u0 = 0x13;
				(ss->*sp_3045).t0000.u2 = (uint16) bp_2652;
				struct Eq_33760 * ds_3076;
				fn0C74_1D95(ds_3059, (ss->*sp_3045).t0000.u2, out ds_3076);
				Eq_481 sp_3081;
				sp_3081.u0 = <invalid>;
				word16 cx_3549;
				word16 dx_3550;
				word16 bx_3551;
				Eq_17 ds_3119;
				ss->*sp_3081 = fn1EDA_098A(0x04, fn1EDA_096F(ds_3076->w4D0C, ds_3076->t58E6, 0x00, 0x00), ss->*((word16) sp_3081 + 0x0000FFFE), ss->*sp_3081, out cx_3549, out dx_3550, out bx_3551, out ds_3119);
				bp_1105 = fn0C74_02D8(ds_3119, ss->*sp_3081, out ds_1149);
				(ss->*((word32) bp_1105 - 1)).u3 = 0x01;
				Eq_481 sp_3141;
				sp_3141.u0 = <invalid>;
				Mem3151[ss:sp_3141 + 0x00:word16] = Mem3147[ds_1149:22708:word16] + 0x01;
				Mem3156[ss:sp_3141 + -2:word16] = Mem3151[ds_1149:22714:word16] + 0x01;
				byte dl_3552;
				if (fn1AB8_1E3C(ds_1149, ss->*((word16) sp_3141 - 2), ss->*sp_3141, out dl_3552) == 0x00)
				{
					Mem3174[ss:sp_3141 + 0x00:word16] = Mem3156[ds_1149:22710:word16] - 0x01;
					Mem3179[ss:sp_3141 + -2:word16] = Mem3174[ds_1149:22714:word16] + 0x01;
					byte dl_3553;
					if (fn1AB8_1E3C(ds_1149, ss->*((word16) sp_3141 - 2), ss->*sp_3141, out dl_3553) == 0x00)
					{
						bp_1105 = fn0C74_05B8(ds_1149, out ds_1149);
						fn0C74_0A35(ds_1149);
						(ss->*((word32) bp_1105 - 1)).u3 = 0x00;
					}
				}
l0C74_2AD4:
				byte al_3377 = (byte) (ss->*((word32) bp_1105 - 1));
				bpOut = (ss->*bp_1105.u3).t0000.u2;
				dsOut = ds_1149;
				return al_3377;
			}
		}
		if (Mem1711[ds_1648:22714:word16] + 0x59 <=u Mem1711[ss:bp_1644 + -4:word16] || Mem1711[ds_1648:22714:word16] + 0x59 <=u Mem1711[ss:bp_1644 + -6:word16])
			goto l0C74_2644;
		struct Eq_34727 Eq_17::* sp_1724 = sp_1657 - 2;
		(ss->*sp_1724).t0000.u2 = (uint16) (ss->*((word32) bp_1644 - 0x0C));
		(ss->*sp_1724).tFFFE.u2 = (uint16) (ss->*((word32) bp_1644 - 6));
		byte dl_3560;
		if (fn1AB8_1E3C(ds_1648, (ss->*sp_1724).tFFFE.u2, (ss->*sp_1724).t0000.u2, out dl_3560) == 0x00)
		{
			(ss->*sp_1724).t0000.u2 = (uint16) (ss->*((word32) bp_1644 - 0x0C));
			(ss->*sp_1724).tFFFE.u2 = (uint16) (ss->*((word32) bp_1644 - 6));
			(ss->*sp_1724).tFFFC.u2 = (uint16) 11;
			fn1AB8_1E54(ds_1648, (ss->*sp_1724).tFFFC.u0, (ss->*sp_1724).tFFFE.u2, (ss->*sp_1724).t0000.u2);
			(ss->*sp_1724).t0000.u2 = (uint16) &(ss->*((word32) bp_1644 - 0x0C)).u3->t0001.u0;
			(ss->*sp_1724).tFFFE.u2 = (uint16) (ss->*((word32) bp_1644 - 6));
			(ss->*sp_1724).tFFFC.u2 = (uint16) 0x03;
			fn1AB8_1E54(ds_1648, (ss->*sp_1724).tFFFC.u0, (ss->*sp_1724).tFFFE.u2, (ss->*sp_1724).t0000.u2);
			(ss->*sp_1724).t0000.u2 = (uint16) &(ss->*((word32) bp_1644 - 0x0C)).u3->t0002.u0;
			(ss->*sp_1724).tFFFE.u2 = (uint16) (ss->*((word32) bp_1644 - 6));
			(ss->*sp_1724).tFFFC.u2 = (uint16) 0x09;
			fn1AB8_1E54(ds_1648, (ss->*sp_1724).tFFFC.u0, (ss->*sp_1724).tFFFE.u2, (ss->*sp_1724).t0000.u2);
			(ss->*((word32) bp_1644 - 6)).u3 = &(ss->*((word32) bp_1644 - 6)).u3->t0001.u0;
		}
		struct Eq_34760 Eq_17::* sp_1795 = sp_1657 - 2;
		(ss->*sp_1795).t0000.u2 = (uint16) (ss->*((word32) bp_1644 - 0x0A));
		(ss->*sp_1795).tFFFE.u2 = (uint16) (ss->*((word32) bp_1644 - 4));
		byte dl_3561;
		if (fn1AB8_1E3C(ds_1648, (ss->*sp_1795).tFFFE.u2, (ss->*sp_1795).t0000.u2, out dl_3561) == 0x00)
		{
			(ss->*sp_1795).t0000.u2 = (uint16) (ss->*((word32) bp_1644 - 0x0A));
			(ss->*sp_1795).tFFFE.u2 = (uint16) (ss->*((word32) bp_1644 - 4));
			(ss->*sp_1795).tFFFC.u2 = (uint16) 11;
			fn1AB8_1E54(ds_1648, (ss->*sp_1795).tFFFC.u0, (ss->*sp_1795).tFFFE.u2, (ss->*sp_1795).t0000.u2);
			(ss->*sp_1795).t0000.u2 = (uint16) &(ss->*((word32) bp_1644 - 0x0A)).u3->t0001.u0;
			(ss->*sp_1795).tFFFE.u2 = (uint16) (ss->*((word32) bp_1644 - 4));
			(ss->*sp_1795).tFFFC.u2 = (uint16) 0x03;
			fn1AB8_1E54(ds_1648, (ss->*sp_1795).tFFFC.u0, (ss->*sp_1795).tFFFE.u2, (ss->*sp_1795).t0000.u2);
			(ss->*sp_1795).t0000.u2 = (uint16) &(ss->*((word32) bp_1644 - 0x0A)).u3->t0002.u0;
			(ss->*sp_1795).tFFFE.u2 = (uint16) (ss->*((word32) bp_1644 - 4));
			(ss->*sp_1795).tFFFC.u2 = (uint16) 0x09;
			fn1AB8_1E54(ds_1648, (ss->*sp_1795).tFFFC.u0, (ss->*sp_1795).tFFFE.u2, (ss->*sp_1795).t0000.u2);
			(ss->*((word32) bp_1644 - 4)).u3 = &(ss->*((word32) bp_1644 - 4)).u3->t0001.u0;
		}
		struct Eq_34912 Eq_17::* sp_1863 = sp_1657 - 2;
		(ss->*sp_1863).t0000.u2 = (uint16) 0xFA;
		(ss->*sp_1863).tFFFE.u2 = (uint16) 0x0F;
		Eq_481 sp_1882;
		sp_1882.u0 = <invalid>;
		bp_1644 = fn0C74_070D(ds_1648, (ss->*sp_1863).tFFFE.u2, (ss->*sp_1863).t0000.u2, out ds_1648);
		sp_1657 = (word16) sp_1882 + 4;
	}
}
