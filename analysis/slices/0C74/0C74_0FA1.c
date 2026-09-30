// 0C74:0FA1: Register byte fn0C74_0FA1(Register Eq_17 ds, Register out (memptr Eq_17 Eq_24289) bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_1B3B
byte fn0C74_0FA1(Eq_17 ds, struct Eq_24289 & bpOut, union Eq_17 & dsOut)
{
	Eq_17 ds_1347;
	Eq_17 ds_2921;
	Eq_17 ds_2743;
	Eq_17 ds_2698;
	Eq_17 ds_2534;
	Eq_17 ds_2302;
	Eq_17 ds_2146;
	Eq_17 ds_1972;
	Eq_17 ds_1930;
	Eq_17 ds_1649;
	Eq_17 ds_1036;
	Eq_17 ds_1175;
	Eq_17 ds_500;
	Eq_17 ds_196;
	word16 bx_3489;
	word16 dx_3488;
	word16 cx_3487;
	Eq_17 ds_178;
	Eq_17 ds_38;
	Eq_17 ax_19 = fn1AB8_13A3(ds, 0x1B, 0x1C, 0x0D, 0x19);
	Eq_17 dx_ax_3477 = fn1EDA_023F(ds, 0x1C, 0x0D, ax_19, out ds_38);
	Eq_17 ds_56;
	fn1AB8_1E6B(ds_56, fn1EDA_023F(ds_38, 0x1C, 0x0D, ax_19, out ds_56), Mem78[ds_56:22712:word16] + 0x1B, Mem74[ds_56:22708:word16] + 0x1C, Mem70[ds_56:22712:word16] + 0x0D, Mem66[ds_56:22708:word16] + 0x19);
	word16 ax_102 = Mem90[ds_56:22708:word16];
	word16 ax_106 = Mem105[ds_56:22712:word16];
	fn1AB8_1E6B(ds_56, dx_ax_3477, Mem113[ds_56:22712:word16] + 0x1B, Mem109[ds_56:22708:word16] + 0x11, ax_106 + 0x0D, ax_102 + 0x0E);
	Eq_17 bp_1039 = fn0C74_02D8(ds_178, fn1EDA_098A(0x04, fn1EDA_096F(Mem146[ds_56:0x4D0C:word16], Mem146[ds_56:22758:word16], 0x00, 0x00), ax_106 + 0x0D, ax_102 + 0x0E, out cx_3487, out dx_3488, out bx_3489, out ds_178), out ds_196);
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
	word16 dx_3490;
	Eq_17 ds_277;
	fn1EDA_0254(ds_196, ss->*((word16) sp_200 - 8), ss->*((word16) sp_200 - 6), ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), out dx_3490, out ds_277);
	ss->*sp_200 = ss->*((word32) bp_1039 - 18);
	ss->*((word16) sp_200 - 2) = ss->*((word32) bp_1039 - 20);
	ss->*((word16) sp_200 - 4) = ss->*((word32) bp_1039 - 32);
	word16 dx_3491;
	Eq_17 ds_300;
	fn1EDA_0254(ds_277, ss->*((word16) sp_200 - 8), ss->*((word16) sp_200 - 6), ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), out dx_3491, out ds_300);
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
	word16 dx_3492;
	fn1AB8_1AF6(ds_300, ss->*((word16) sp_200 - 6), ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200, out dx_3492);
	Mem358[ss:sp_200 + 0x00:word16] = Mem348[ds_300:22708:word16] + 0x11;
	Mem362[ss:sp_200 + -2:word16] = Mem358[ds_300:22712:word16] + 0x0D;
	Mem366[ss:sp_200 + -4:word16] = Mem362[ds_300:22708:word16] + 0x11;
	Mem371[ss:sp_200 + -6:word16] = Mem366[ds_300:22712:word16] + 0x1B;
	word16 dx_3493;
	fn1AB8_1AF6(ds_300, ss->*((word16) sp_200 - 6), ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200, out dx_3493);
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
	Eq_17 dx_ax_3494 = fn1EDA_023F(ds_300, ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200, out ds_500);
	ss->*((word32) bp_1039 - 16) = (word16) dx_ax_3494;
	(ss->*((word32) bp_1039 - 0x0E)).u3 = SLICE(dx_ax_3494, word16, 16);
	ss->*sp_200 = ss->*((word32) bp_1039 - 32);
	Eq_17 dx_ax_3495 = fn1EDA_023F(ds_500, ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200, out ds_1175);
	ss->*((word32) bp_1039 - 20) = (word16) dx_ax_3495;
	(ss->*((word32) bp_1039 - 18)).u3 = SLICE(dx_ax_3495, word16, 16);
	Mem532[ss:sp_200 + 0x00:word16] = Mem528[ds_1175:22708:word16] + 0x19;
	Mem536[ss:sp_200 + -2:word16] = Mem532[ds_1175:22712:word16] + 0x0D;
	Mem540[ss:sp_200 + -4:word16] = Mem536[ds_1175:22708:word16] + 0x1D;
	Mem545[ss:sp_200 + -6:word16] = Mem540[ds_1175:22712:word16] + 0x1B;
	Eq_17 es_di_546 = ss->*((word32) bp_1039 - 20);
	ss->*((word16) sp_200 - 8) = SLICE(es_di_546, selector, 16);
	ss->*((word16) sp_200 - 0x0A) = (word16) es_di_546;
	fn1AB8_1E6B(ds_1175, ss->*((word16) sp_200 - 0x0A), ss->*((word16) sp_200 - 6), ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200);
	Mem567[ss:sp_200 + 0x00:word16] = Mem552[ds_1175:22708:word16] + 0x0D;
	Mem571[ss:sp_200 + -2:word16] = Mem567[ds_1175:22712:word16] + 0x0D;
	Mem575[ss:sp_200 + -4:word16] = Mem571[ds_1175:22708:word16] + 0x11;
	Mem580[ss:sp_200 + -6:word16] = Mem575[ds_1175:22712:word16] + 0x1B;
	Eq_17 es_di_581 = ss->*((word32) bp_1039 - 16);
	ss->*((word16) sp_200 - 8) = SLICE(es_di_581, selector, 16);
	ss->*((word16) sp_200 - 0x0A) = (word16) es_di_581;
	fn1AB8_1E6B(ds_1175, ss->*((word16) sp_200 - 0x0A), ss->*((word16) sp_200 - 6), ss->*((word16) sp_200 - 4), ss->*((word16) sp_200 - 2), ss->*sp_200);
	(ss->*((word32) bp_1039 - 4)).u0 = 0x01;
	struct Eq_24045 Eq_17::* sp_598 = (word16) sp_200 + 2;
	while (ss->*((word32) bp_1039 - 4) < 0x14)
	{
		struct Eq_24048 Eq_17::* sp_610 = sp_598 - 2;
		Mem611[ss:sp_610 + 0x00:word16] = Mem602[ds_1175:22708:word16] + 0x0C - Mem602[ss:bp_1039 + -4:word16];
		Mem616[ss:sp_610 + -2:word16] = Mem611[ds_1175:22712:word16] + 0x1B;
		byte dl_3496;
		if (fn1AB8_1E3C(ds_1175, (ss->*sp_610).tFFFE.u2, (ss->*sp_610).t0000.u2, out dl_3496) != 0x00)
			break;
		Mem635[ss:sp_610 + 0x00:word16] = Mem616[ds_1175:22708:word16] + 0x1E + Mem616[ss:bp_1039 + -4:word16];
		Mem640[ss:sp_610 + -2:word16] = Mem635[ds_1175:22712:word16] + 0x1B;
		byte dl_3497;
		if (fn1AB8_1E3C(ds_1175, (ss->*sp_610).tFFFE.u2, (ss->*sp_610).t0000.u2, out dl_3497) != 0x00)
			break;
		Mem659[ss:sp_610 + 0x00:word16] = Mem640[ds_1175:22708:word16] + 0x0C - Mem640[ss:bp_1039 + -4:word16];
		Mem664[ss:sp_610 + -2:word16] = Mem659[ds_1175:22712:word16] + 0x0D;
		byte dl_3500;
		if (fn1AB8_1E3C(ds_1175, (ss->*sp_610).tFFFE.u2, (ss->*sp_610).t0000.u2, out dl_3500) != 0x00)
			break;
		Mem683[ss:sp_610 + 0x00:word16] = Mem664[ds_1175:22708:word16] + 0x1E + Mem664[ss:bp_1039 + -4:word16];
		Mem688[ss:sp_610 + -2:word16] = Mem683[ds_1175:22712:word16] + 0x0D;
		byte dl_3501;
		if (fn1AB8_1E3C(ds_1175, (ss->*sp_610).tFFFE.u2, (ss->*sp_610).t0000.u2, out dl_3501) != 0x00)
			break;
		Mem707[ss:sp_610 + 0x00:word16] = Mem688[ds_1175:22708:word16] + 0x0C - Mem688[ss:bp_1039 + -4:word16];
		Mem712[ss:sp_610 + -2:word16] = Mem707[ds_1175:22712:word16] + 22;
		byte dl_3502;
		if (fn1AB8_1E3C(ds_1175, (ss->*sp_610).tFFFE.u2, (ss->*sp_610).t0000.u2, out dl_3502) != 0x00)
			break;
		Mem731[ss:sp_610 + 0x00:word16] = Mem712[ds_1175:22708:word16] + 0x1E + Mem712[ss:bp_1039 + -4:word16];
		Mem736[ss:sp_610 + -2:word16] = Mem731[ds_1175:22712:word16] + 22;
		byte dl_3503;
		if (fn1AB8_1E3C(ds_1175, (ss->*sp_610).tFFFE.u2, (ss->*sp_610).t0000.u2, out dl_3503) != 0x00)
			break;
		(ss->*sp_610).t0000.u2 = (uint16) 0xE6;
		(ss->*sp_610).tFFFE.u2 = (uint16) 0x19;
		bp_1039 = fn0C74_070D(ds_1175, (ss->*sp_610).tFFFE.u2, (ss->*sp_610).t0000.u2, out ds_1175);
		Eq_481 sp_765;
		sp_765.u0 = <invalid>;
		Mem775[ss:sp_765 + 0x02:word16] = Mem754[ds_1175:22708:word16] + 0x0D - Mem754[ss:bp_1039 + -4:word16];
		Mem780[ss:sp_765 + 0x00:word16] = Mem775[ds_1175:22712:word16] + 0x0D;
		Eq_17 es_di_781 = ss->*((word32) bp_1039 - 16);
		ss->*((word16) sp_765 - 2) = SLICE(es_di_781, selector, 16);
		ss->*((word16) sp_765 - 4) = (word16) es_di_781;
		ss->*((word16) sp_765 - 6) = 0x00;
		fn1AB8_13D7(ds_1175, ss->*((word16) sp_765 + 6), ss->*((word16) sp_765 - 4), ss->*sp_765, ss->*((word16) sp_765 + 2));
		Mem806[ss:sp_765 + 0x02:word16] = Mem789[ds_1175:22708:word16] + 0x19 + Mem789[ss:bp_1039 + -4:word16];
		Mem811[ss:sp_765 + 0x00:word16] = Mem806[ds_1175:22712:word16] + 0x0D;
		Eq_17 es_di_812 = ss->*((word32) bp_1039 - 20);
		ss->*((word16) sp_765 - 2) = SLICE(es_di_812, selector, 16);
		ss->*((word16) sp_765 - 4) = (word16) es_di_812;
		ss->*((word16) sp_765 - 6) = 0x00;
		fn1AB8_13D7(ds_1175, ss->*((word16) sp_765 + 6), ss->*((word16) sp_765 - 4), ss->*sp_765, ss->*((word16) sp_765 + 2));
		(ss->*((word32) bp_1039 - 4)).u3 = &(ss->*((word32) bp_1039 - 4)).u3->t0001.u0;
		sp_598 = (word16) sp_765 + 4;
	}
	struct Eq_24045 Eq_17::* sp_1215 = sp_598;
	Eq_17 bp_1129;
	Eq_17 ds_1150;
	if (ss->*((word32) bp_1039 - 4) != 0x14)
	{
		struct Eq_24167 Eq_17::* sp_3302 = sp_598 - 2;
		(ss->*sp_3302).t0000.u2 = (uint16) bp_1039;
		Eq_17 ds_3308;
		bp_1129 = fn0C74_0E2E(ds_1175, (ss->*sp_3302).t0000.u2, out ds_3308);
		Eq_481 sp_3313;
		sp_3313.u0 = <invalid>;
		ss->*sp_3313 = ss->*((word32) bp_1129 - 0x0E);
		ss->*((word16) sp_3313 - 2) = ss->*((word32) bp_1129 - 16);
		ss->*((word16) sp_3313 - 4) = ss->*((word32) bp_1129 - 32);
		word16 dx_3498;
		Eq_17 ds_3333;
		fn1EDA_0254(ds_3308, ss->*((word16) sp_3313 - 8), ss->*((word16) sp_3313 - 6), ss->*((word16) sp_3313 - 4), ss->*((word16) sp_3313 - 2), out dx_3498, out ds_3333);
		ss->*sp_3313 = ss->*((word32) bp_1129 - 18);
		ss->*((word16) sp_3313 - 2) = ss->*((word32) bp_1129 - 20);
		ss->*((word16) sp_3313 - 4) = ss->*((word32) bp_1129 - 32);
		word16 dx_3499;
		fn1EDA_0254(ds_3333, ss->*((word16) sp_3313 - 8), ss->*((word16) sp_3313 - 6), ss->*((word16) sp_3313 - 4), ss->*((word16) sp_3313 - 2), out dx_3499, out ds_1150);
		(ss->*((word32) bp_1129 - 1)).u3 = 0x00;
		goto l0C74_1B36;
	}
	Mem845[ss:bp_1039 + -0x0A:word16] = Mem838[ds_1175:22708:word16] + 0x1A + Mem838[ss:bp_1039 + -4:word16];
	Mem851[ss:bp_1039 + -0x0C:word16] = Mem845[ds_1175:22708:word16] + 0x0D - Mem845[ss:bp_1039 + -4:word16] + 0x02;
	if (Mem851[ds_1175:22888:word16] == ~0x00)
	{
		while (ss->*((word32) bp_1039 - 4) < 0x41)
		{
			struct Eq_27885 Eq_17::* sp_864 = sp_1215 - 2;
			Mem865[ss:sp_864 + 0x00:word16] = Mem856[ds_1175:22708:word16] + 0x1E + Mem856[ss:bp_1039 + -4:word16];
			Mem870[ss:sp_864 + -2:word16] = Mem865[ds_1175:22712:word16] + 0x1B;
			byte dl_3548;
			if (fn1AB8_1E3C(ds_1175, (ss->*sp_864).tFFFE.u2, (ss->*sp_864).t0000.u2, out dl_3548) != 0x00)
				break;
			Mem889[ss:sp_864 + 0x00:word16] = Mem870[ds_1175:22708:word16] + 0x1E + Mem870[ss:bp_1039 + -4:word16];
			Mem894[ss:sp_864 + -2:word16] = Mem889[ds_1175:22712:word16] + 0x0D;
			byte dl_3549;
			if (fn1AB8_1E3C(ds_1175, (ss->*sp_864).tFFFE.u2, (ss->*sp_864).t0000.u2, out dl_3549) != 0x00)
				break;
			(ss->*sp_864).t0000.u2 = (uint16) 0xE6;
			(ss->*sp_864).tFFFE.u2 = (uint16) 0x19;
			bp_1039 = fn0C74_070D(ds_1175, (ss->*sp_864).tFFFE.u2, (ss->*sp_864).t0000.u2, out ds_1175);
			Eq_481 sp_1179;
			sp_1179.u0 = <invalid>;
			Mem1189[ss:sp_1179 + 0x02:word16] = Mem1169[ds_1175:22708:word16] + 0x19 + Mem1169[ss:bp_1039 + -4:word16];
			Mem1194[ss:sp_1179 + 0x00:word16] = Mem1189[ds_1175:22712:word16] + 0x0D;
			Eq_17 es_di_1195 = ss->*((word32) bp_1039 - 20);
			ss->*((word16) sp_1179 - 2) = SLICE(es_di_1195, selector, 16);
			ss->*((word16) sp_1179 - 4) = (word16) es_di_1195;
			ss->*((word16) sp_1179 - 6) = 0x00;
			fn1AB8_13D7(ds_1175, ss->*((word16) sp_1179 + 6), ss->*((word16) sp_1179 - 4), ss->*sp_1179, ss->*((word16) sp_1179 + 2));
			(ss->*((word32) bp_1039 - 4)).u3 = &(ss->*((word32) bp_1039 - 4)).u3->t0001.u0;
			sp_1215 = (word16) sp_1179 + 4;
		}
		if (ss->*((word32) bp_1039 - 4) != 0x41)
		{
			struct Eq_28235 Eq_17::* sp_916 = sp_1215 - 2;
			(ss->*sp_916).t0000.u2 = (uint16) (ss->*((word32) bp_1039 - 18));
			(ss->*sp_916).tFFFE.u2 = (uint16) (ss->*((word32) bp_1039 - 20));
			(ss->*sp_916).tFFFC.u2 = (uint16) (ss->*((word32) bp_1039 - 32));
			word16 dx_3551;
			Eq_17 ds_931;
			fn1EDA_0254(ds_1175, (ss->*sp_916).tFFF8.u2, (ss->*sp_916).tFFFA.u2, (ss->*sp_916).tFFFC.u2, (ss->*sp_916).tFFFE.u3, out dx_3551, out ds_931);
			Mem945[ss:sp_916 + 0x00:word16] = Mem923[ds_931:22708:word16] + 0x19 + Mem923[ss:bp_1039 + -4:word16];
			Mem949[ss:sp_916 + -2:word16] = Mem945[ds_931:22712:word16] + 0x0D;
			Mem954[ss:sp_916 + -4:word16] = Mem949[ds_931:22708:word16] + 0x1D + Mem949[ss:bp_1039 + -4:word16];
			Mem959[ss:sp_916 + -6:word16] = Mem954[ds_931:22712:word16] + 0x1B;
			ss->*((word32) bp_1039 - 0x0022) = fn1AB8_13A3(ds_931, (ss->*sp_916).tFFFA.u2, (ss->*sp_916).tFFFC.u2, (ss->*sp_916).tFFFE.u2, (ss->*sp_916).t0000.u2);
			(ss->*sp_916).t0000.u2 = (uint16) (ss->*((word32) bp_1039 - 0x0022));
			Eq_17 dx_ax_3552 = fn1EDA_023F(ds_931, (ss->*sp_916).tFFFC.u2, (ss->*sp_916).tFFFE.u2, (ss->*sp_916).t0000.u2, out ds_1036);
			ss->*((word32) bp_1039 - 20) = (word16) dx_ax_3552;
			(ss->*((word32) bp_1039 - 18)).u3 = SLICE(dx_ax_3552, word16, 16);
			Mem993[ss:sp_916 + 0x00:word16] = Mem988[ds_1036:22708:word16] + 0x19 + Mem988[ss:bp_1039 + -4:word16];
			Mem997[ss:sp_916 + -2:word16] = Mem993[ds_1036:22712:word16] + 0x0D;
			Mem1002[ss:sp_916 + -4:word16] = Mem997[ds_1036:22708:word16] + 0x1D + Mem997[ss:bp_1039 + -4:word16];
			Mem1007[ss:sp_916 + -6:word16] = Mem1002[ds_1036:22712:word16] + 0x1B;
			Eq_17 es_di_1008 = ss->*((word32) bp_1039 - 20);
			(ss->*sp_916).tFFF8.u2 = (uint16) SLICE(es_di_1008, selector, 16);
			(ss->*sp_916).tFFF6.u2 = (uint16) (word16) es_di_1008;
			fn1AB8_1E6B(ds_1036, (ss->*sp_916).tFFF6.u3, (ss->*sp_916).tFFFA.u2, (ss->*sp_916).tFFFC.u2, (ss->*sp_916).tFFFE.u2, (ss->*sp_916).t0000.u2);
			struct Eq_28470 Eq_17::* sp_1025 = (struct Eq_28470 Eq_17::*) &sp_916->t0002.u0;
			Eq_17 ax_1026 = ss->*((word32) bp_1039 - 4);
			if (ax_1026 >= 0x13)
			{
				ss->*((word32) bp_1039 - 6) = ax_1026;
				while (true)
				{
					struct Eq_28615 Eq_17::* sp_1031 = sp_1025 - 2;
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
			struct Eq_28494 Eq_17::* sp_1094 = sp_1025 - 2;
			(ss->*sp_1094).t0000.u2 = (uint16) (ss->*((word32) bp_1039 - 18));
			(ss->*sp_1094).tFFFE.u2 = (uint16) (ss->*((word32) bp_1039 - 20));
			(ss->*sp_1094).tFFFC.u2 = (uint16) (ss->*((word32) bp_1039 - 0x0022));
			word16 dx_3553;
			Eq_17 ds_1108;
			fn1EDA_0254(ds_1036, (ss->*sp_1094).tFFF8.u2, (ss->*sp_1094).tFFFA.u2, (ss->*sp_1094).tFFFC.u2, (ss->*sp_1094).tFFFE.u3, out dx_3553, out ds_1108);
			(ss->*((word32) bp_1039 - 4)).u0 = 0x14;
			(ss->*sp_1094).t0000.u2 = (uint16) bp_1039;
			Eq_17 ds_1125;
			bp_1129 = fn0C74_0E2E(ds_1108, (ss->*sp_1094).t0000.u2, out ds_1125);
			Eq_481 sp_1130;
			sp_1130.u0 = <invalid>;
			ss->*sp_1130 = ss->*((word32) bp_1129 - 0x0E);
			ss->*((word16) sp_1130 - 2) = ss->*((word32) bp_1129 - 16);
			ss->*((word16) sp_1130 - 4) = ss->*((word32) bp_1129 - 32);
			word16 dx_3554;
			fn1EDA_0254(ds_1125, ss->*((word16) sp_1130 - 8), ss->*((word16) sp_1130 - 6), ss->*((word16) sp_1130 - 4), ss->*((word16) sp_1130 - 2), out dx_3554, out ds_1150);
			(ss->*((word32) bp_1129 - 1)).u3 = 0x00;
			goto l0C74_1B36;
		}
		Mem1165[ss:bp_1039 + -0x0A:word16] = Mem911[ds_1175:22708:word16] + 0x1A + Mem911[ss:bp_1039 + -4:word16];
	}
	if (Mem1220[ds_1175:22888:word16] != 0x01)
	{
l0C74_15E7:
		struct Eq_24620 Eq_17::* sp_1642 = sp_1215 - 2;
		word16 cx_3504;
		word16 dx_3505;
		word16 bx_3506;
		Eq_17 ds_1631;
		Mem1643[ss:sp_1642 + 0x00:word16] = fn1EDA_098A(0x04, fn1EDA_096F(Mem1591[ds_1175:0x4D0C:word16], Mem1591[ds_1175:22758:word16], 0x00, 0x00), Mem1591[ss:sp_1215 + -4:word16], Mem1591[ss:sp_1215 + -2:word16], out cx_3504, out dx_3505, out bx_3506, out ds_1631);
		Eq_17 bp_1645 = fn0C74_02D8(ds_1631, (ss->*sp_1642).t0000.u2, out ds_1649);
		Mem1661[ss:bp_1645 + -4:word16] = Mem1643[ds_1649:22712:word16] + 0x1C;
		Mem1665[ss:bp_1645 + -6:word16] = Mem1661[ds_1649:22712:word16] + 0x1C;
		Eq_481 sp_1653;
		sp_1653.u0 = <invalid>;
		word16 sp_1658 = (word16) sp_1653 + 2;
		while (true)
		{
			struct Eq_24723 Eq_17::* sp_1671 = sp_1658 - 2;
			(ss->*sp_1671).t0000.u2 = (uint16) (ss->*((word32) bp_1645 - 0x0C));
			(ss->*sp_1671).tFFFE.u2 = (uint16) (ss->*((word32) bp_1645 - 6));
			byte dl_3550;
			if (fn1AB8_1E3C(ds_1649, (ss->*sp_1671).tFFFE.u2, (ss->*sp_1671).t0000.u2, out dl_3550) != 0x00)
			{
				(ss->*sp_1671).t0000.u2 = (uint16) (ss->*((word32) bp_1645 - 0x0A));
				(ss->*sp_1671).tFFFE.u2 = (uint16) (ss->*((word32) bp_1645 - 4));
				byte dl_3508;
				if (fn1AB8_1E3C(ds_1649, (ss->*sp_1671).tFFFE.u2, (ss->*sp_1671).t0000.u2, out dl_3508) != 0x00)
				{
					word16 cx_3509;
					word16 dx_3510;
					word16 bx_3511;
					Eq_17 ds_1912;
					Mem1924[ss:sp_1671 + 0x00:word16] = fn1EDA_098A(0x04, fn1EDA_096F(Mem1696[ds_1649:0x4D0C:word16], Mem1696[ds_1649:22758:word16], 0x00, 0x00), Mem1696[ss:sp_1671 + -2:word16], Mem1696[ss:sp_1671 + 0x00:word16], out cx_3509, out dx_3510, out bx_3511, out ds_1912);
					Eq_17 bp_1926 = fn0C74_02D8(ds_1912, (ss->*sp_1671).t0000.u2, out ds_1930);
					Eq_481 sp_1934;
					sp_1934.u0 = <invalid>;
					Mem1942[ss:sp_1934 + 0x00:word16] = Mem1924[ds_1930:22708:word16];
					Mem1947[ss:sp_1934 + -2:word16] = Mem1942[ds_1930:22714:word16] - 0x0E;
					Mem1950[ss:sp_1934 + -4:word16] = Mem1947[ds_1930:22710:word16];
					Mem1953[ss:sp_1934 + -6:word16] = Mem1950[ds_1930:22714:word16];
					ss->*((word32) bp_1926 - 30) = fn1AB8_13A3(ds_1930, ss->*((word16) sp_1934 - 6), ss->*((word16) sp_1934 - 4), ss->*((word16) sp_1934 - 2), ss->*sp_1934);
					ss->*sp_1934 = ss->*((word32) bp_1926 - 30);
					Eq_17 dx_ax_3512 = fn1EDA_023F(ds_1930, ss->*((word16) sp_1934 - 4), ss->*((word16) sp_1934 - 2), ss->*sp_1934, out ds_1972);
					ss->*((word32) bp_1926 - 24) = (word16) dx_ax_3512;
					(ss->*((word32) bp_1926 - 22)).u3 = SLICE(dx_ax_3512, word16, 16);
					Mem1985[ss:sp_1934 + 0x00:word16] = Mem1982[ds_1972:22708:word16];
					Mem1990[ss:sp_1934 + -2:word16] = Mem1985[ds_1972:22714:word16] - 0x0E;
					Mem1993[ss:sp_1934 + -4:word16] = Mem1990[ds_1972:22710:word16];
					Mem1996[ss:sp_1934 + -6:word16] = Mem1993[ds_1972:22714:word16];
					Eq_17 es_di_1997 = ss->*((word32) bp_1926 - 24);
					ss->*((word16) sp_1934 - 8) = SLICE(es_di_1997, selector, 16);
					ss->*((word16) sp_1934 - 0x0A) = (word16) es_di_1997;
					fn1AB8_1E6B(ds_1972, ss->*((word16) sp_1934 - 0x0A), ss->*((word16) sp_1934 - 6), ss->*((word16) sp_1934 - 4), ss->*((word16) sp_1934 - 2), ss->*sp_1934);
					Mem2016[ds_1972:22714:word16] = Mem2003[ds_1972:22714:word16] - 0x01;
					Mem2019[ss:sp_1934 + 0x00:word16] = Mem2016[ds_1972:22708:word16];
					Mem2024[ss:sp_1934 + -2:word16] = Mem2019[ds_1972:22714:word16] - 0x0E;
					Eq_17 es_di_2025 = ss->*((word32) bp_1926 - 24);
					ss->*((word16) sp_1934 - 4) = SLICE(es_di_2025, selector, 16);
					ss->*((word16) sp_1934 - 6) = (word16) es_di_2025;
					ss->*((word16) sp_1934 - 8) = 0x00;
					fn1AB8_13D7(ds_1972, ss->*((word16) sp_1934 + 8), ss->*((word16) sp_1934 - 6), ss->*((word16) sp_1934 - 2), ss->*sp_1934);
					ss->*sp_1934 = ss->*((word32) bp_1926 - 22);
					ss->*((word16) sp_1934 - 2) = ss->*((word32) bp_1926 - 24);
					ss->*((word16) sp_1934 - 4) = ss->*((word32) bp_1926 - 30);
					word16 dx_3513;
					Eq_17 ds_2059;
					fn1EDA_0254(ds_1972, ss->*((word16) sp_1934 - 8), ss->*((word16) sp_1934 - 6), ss->*((word16) sp_1934 - 4), ss->*((word16) sp_1934 - 2), out dx_3513, out ds_2059);
					ss->*sp_1934 = 0x00;
					ss->*((word16) sp_1934 - 2) = 0x00;
					ss->*((word16) sp_1934 - 4) = 0x01;
					fn1AB8_10F4(ds_2059, ss->*((word16) sp_1934 - 4), ss->*((word16) sp_1934 - 2), ss->*sp_1934);
					ss->*sp_1934 = 0x00;
					fn1AB8_1C32(ds_2059, ss->*sp_1934);
					Mem2093[ss:sp_1934 + 0x00:word16] = Mem2086[ds_2059:22708:word16];
					Mem2097[ss:sp_1934 + -2:word16] = Mem2093[ds_2059:22714:word16] + 0x01;
					Mem2100[ss:sp_1934 + -4:word16] = Mem2097[ds_2059:22710:word16];
					Mem2105[ss:sp_1934 + -6:word16] = Mem2100[ds_2059:22714:word16] + 0x01;
					word16 dx_3514;
					fn1AB8_1AF6(ds_2059, ss->*((word16) sp_1934 - 6), ss->*((word16) sp_1934 - 4), ss->*((word16) sp_1934 - 2), ss->*sp_1934, out dx_3514);
					Mem2114[ss:sp_1934 + 0x00:word16] = Mem2105[ds_2059:22708:word16];
					Mem2119[ss:sp_1934 + -2:word16] = Mem2114[ds_2059:22714:word16] - 0x0D;
					Mem2122[ss:sp_1934 + -4:word16] = Mem2119[ds_2059:22710:word16];
					Mem2127[ss:sp_1934 + -6:word16] = Mem2122[ds_2059:22714:word16] + 0x01;
					ss->*((word32) bp_1926 - 30) = fn1AB8_13A3(ds_2059, ss->*((word16) sp_1934 - 6), ss->*((word16) sp_1934 - 4), ss->*((word16) sp_1934 - 2), ss->*sp_1934);
					ss->*sp_1934 = ss->*((word32) bp_1926 - 30);
					Eq_17 dx_ax_3515 = fn1EDA_023F(ds_2059, ss->*((word16) sp_1934 - 4), ss->*((word16) sp_1934 - 2), ss->*sp_1934, out ds_2146);
					ss->*((word32) bp_1926 - 24) = (word16) dx_ax_3515;
					(ss->*((word32) bp_1926 - 22)).u3 = SLICE(dx_ax_3515, word16, 16);
					Mem2159[ss:sp_1934 + 0x00:word16] = Mem2156[ds_2146:22708:word16];
					Mem2164[ss:sp_1934 + -2:word16] = Mem2159[ds_2146:22714:word16] - 0x0D;
					Mem2167[ss:sp_1934 + -4:word16] = Mem2164[ds_2146:22710:word16];
					Mem2172[ss:sp_1934 + -6:word16] = Mem2167[ds_2146:22714:word16] + 0x01;
					Eq_17 es_di_2173 = ss->*((word32) bp_1926 - 24);
					ss->*((word16) sp_1934 - 8) = SLICE(es_di_2173, selector, 16);
					ss->*((word16) sp_1934 - 0x0A) = (word16) es_di_2173;
					fn1AB8_1E6B(ds_2146, ss->*((word16) sp_1934 - 0x0A), ss->*((word16) sp_1934 - 6), ss->*((word16) sp_1934 - 4), ss->*((word16) sp_1934 - 2), ss->*sp_1934);
					struct Eq_25305 Eq_17::* sp_2190 = (word16) sp_1934 + 2;
					Eq_17 bp_2200;
					Eq_481 sp_2208;
					do
					{
						struct Eq_25486 Eq_17::* sp_2192 = sp_2190 - 2;
						(ss->*sp_2192).t0000.u2 = (uint16) 100;
						(ss->*sp_2192).tFFFE.u2 = (uint16) 0x3C;
						bp_2200 = fn0C74_070D(ds_2146, (ss->*sp_2192).tFFFE.u2, (ss->*sp_2192).t0000.u2, out ds_2146);
						Mem2215[ds_2146:22714:word16] = Mem2196[ds_2146:22714:word16] - 0x01;
						sp_2208.u0 = <invalid>;
						Mem2218[ss:sp_2208 + 0x02:word16] = Mem2215[ds_2146:22708:word16];
						Mem2223[ss:sp_2208 + 0x00:word16] = Mem2218[ds_2146:22714:word16] - 0x0D;
						Eq_17 es_di_2224 = ss->*((word32) bp_2200 - 24);
						ss->*((word16) sp_2208 - 2) = SLICE(es_di_2224, selector, 16);
						ss->*((word16) sp_2208 - 4) = (word16) es_di_2224;
						ss->*((word16) sp_2208 - 6) = 0x00;
						fn1AB8_13D7(ds_2146, ss->*((word16) sp_2208 + 6), ss->*((word16) sp_2208 - 4), ss->*sp_2208, ss->*((word16) sp_2208 + 2));
						sp_2190 = (word16) sp_2208 + 4;
					} while (Mem2232[ds_2146:22712:word16] + 0x2B != Mem2232[ds_2146:22714:word16]);
					ss->*((word16) sp_2208 + 2) = ss->*((word32) bp_2200 - 22);
					ss->*sp_2208 = ss->*((word32) bp_2200 - 24);
					ss->*((word16) sp_2208 - 2) = ss->*((word32) bp_2200 - 30);
					word16 dx_3518;
					Eq_17 ds_2262;
					fn1EDA_0254(ds_2146, ss->*((word16) sp_2208 - 6), ss->*((word16) sp_2208 - 4), ss->*((word16) sp_2208 - 2), ss->*sp_2208, out dx_3518, out ds_2262);
					Mem2274[ss:sp_2208 + 0x02:word16] = Mem2257[ds_2262:22708:word16];
					Mem2277[ss:sp_2208 + 0x00:word16] = Mem2274[ds_2262:22712:word16];
					Mem2280[ss:sp_2208 + -2:word16] = Mem2277[ds_2262:22710:word16];
					Mem2283[ss:sp_2208 + -4:word16] = Mem2280[ds_2262:22714:word16];
					ss->*((word32) bp_2200 - 40) = fn1AB8_13A3(ds_2262, ss->*((word16) sp_2208 - 4), ss->*((word16) sp_2208 - 2), ss->*sp_2208, ss->*((word16) sp_2208 + 2));
					ss->*((word16) sp_2208 + 2) = ss->*((word32) bp_2200 - 40);
					Eq_17 dx_ax_3519 = fn1EDA_023F(ds_2262, ss->*((word16) sp_2208 + 0x0000FFFE), ss->*sp_2208, ss->*((word16) sp_2208 + 2), out ds_2302);
					ss->*((word32) bp_2200 - 28) = (word16) dx_ax_3519;
					(ss->*((word32) bp_2200 - 26)).u3 = SLICE(dx_ax_3519, word16, 16);
					Mem2315[ss:sp_2208 + 0x02:word16] = Mem2312[ds_2302:22708:word16];
					Mem2318[ss:sp_2208 + 0x00:word16] = Mem2315[ds_2302:22712:word16];
					Mem2321[ss:sp_2208 + -2:word16] = Mem2318[ds_2302:22710:word16];
					Mem2324[ss:sp_2208 + -4:word16] = Mem2321[ds_2302:22714:word16];
					Eq_17 es_di_2325 = ss->*((word32) bp_2200 - 28);
					ss->*((word16) sp_2208 - 6) = SLICE(es_di_2325, selector, 16);
					ss->*((word16) sp_2208 - 8) = (word16) es_di_2325;
					fn1AB8_1E6B(ds_2302, ss->*((word16) sp_2208 - 8), ss->*((word16) sp_2208 - 4), ss->*((word16) sp_2208 - 2), ss->*sp_2208, ss->*((word16) sp_2208 + 2));
					word16 cx_3520;
					word16 dx_3521;
					word16 bx_3522;
					Eq_17 ds_2374;
					Mem2386[ss:sp_2208 + 0x02:word16] = fn1EDA_098A(0x04, fn1EDA_096F(Mem2331[ds_2302:0x4D0C:word16], Mem2331[ds_2302:22758:word16], 0x00, 0x00), Mem2331[ss:sp_2208 + 0x00:word16], Mem2331[ss:sp_2208 + 0x02:word16], out cx_3520, out dx_3521, out bx_3522, out ds_2374);
					Eq_17 ds_2392;
					(ss->*((word16) fn0C74_02D8(ds_2374, ss->*((word16) sp_2208 + 2), out ds_2392) - 8)).u3 = 0x01;
					Eq_481 sp_2396;
					sp_2396.u0 = <invalid>;
					struct Eq_25825 Eq_17::* sp_2401 = (word16) sp_2396 + 2;
					Eq_481 sp_2420;
					while (true)
					{
						struct Eq_25828 Eq_17::* sp_2404 = sp_2401 - 2;
						(ss->*sp_2404).t0000.u2 = (uint16) 0x32;
						(ss->*sp_2404).tFFFE.u2 = (uint16) 0x28;
						Eq_17 bp_2412 = fn0C74_070D(ds_2392, (ss->*sp_2404).tFFFE.u2, (ss->*sp_2404).t0000.u2, out ds_2392);
						Mem2438[ds_2392:22708:word16] = Mem2408[ds_2392:22708:word16] - Mem2408[ds_2392:22888:word16];
						Mem2452[ds_2392:22710:word16] = Mem2438[ds_2392:22710:word16] - Mem2438[ds_2392:22888:word16];
						sp_2420.u0 = <invalid>;
						Mem2455[ss:sp_2420 + 0x02:word16] = Mem2452[ds_2392:22708:word16];
						Mem2458[ss:sp_2420 + 0x00:word16] = Mem2455[ds_2392:22712:word16];
						Eq_17 es_di_2459 = ss->*((word32) bp_2412 - 28);
						ss->*((word16) sp_2420 - 2) = SLICE(es_di_2459, selector, 16);
						ss->*((word16) sp_2420 - 4) = (word16) es_di_2459;
						ss->*((word16) sp_2420 - 6) = 0x00;
						fn1AB8_13D7(ds_2392, ss->*((word16) sp_2420 + 6), ss->*((word16) sp_2420 - 4), ss->*sp_2420, ss->*((word16) sp_2420 + 2));
						sp_2401 = (word16) sp_2420 + 4;
						if (ss->*((word32) bp_2412 - 8) == 44)
							break;
						(ss->*((word32) bp_2412 - 8)).u3 = &(ss->*((word32) bp_2412 - 8)).u3->t0001.u0;
					}
					word16 cx_3523;
					word16 dx_3524;
					word16 bx_3525;
					Eq_17 ds_2516;
					Mem2528[ss:sp_2420 + 0x02:word16] = fn1EDA_098A(0x04, fn1EDA_096F(Mem2467[ds_2392:0x4D0C:word16], Mem2467[ds_2392:22758:word16], 0x00, 0x00), Mem2467[ss:sp_2420 + 0x00:word16], Mem2467[ss:sp_2420 + 0x02:word16], out cx_3523, out dx_3524, out bx_3525, out ds_2516);
					Eq_17 bp_2530 = fn0C74_02D8(ds_2516, ss->*((word16) sp_2420 + 2), out ds_2534);
					Eq_481 sp_2538;
					sp_2538.u0 = <invalid>;
					ss->*sp_2538 = ss->*((word32) bp_2530 - 26);
					ss->*((word16) sp_2538 - 2) = ss->*((word32) bp_2530 - 28);
					ss->*((word16) sp_2538 - 4) = ss->*((word32) bp_2530 - 40);
					word16 dx_3526;
					Eq_17 ds_2557;
					fn1EDA_0254(ds_2534, ss->*((word16) sp_2538 - 8), ss->*((word16) sp_2538 - 6), ss->*((word16) sp_2538 - 4), ss->*((word16) sp_2538 - 2), out dx_3526, out ds_2557);
					ss->*sp_2538 = 0x00;
					ss->*((word16) sp_2538 - 2) = 0x00;
					ss->*((word16) sp_2538 - 4) = 0x01;
					fn1AB8_10F4(ds_2557, ss->*((word16) sp_2538 - 4), ss->*((word16) sp_2538 - 2), ss->*sp_2538);
					ss->*sp_2538 = 0x00;
					fn1AB8_1C32(ds_2557, ss->*sp_2538);
					struct Eq_26072 Eq_17::* sp_2588 = (word16) sp_2538 + 2;
					while (Mem2590[ds_2557:22712:word16] + 0x1C <u Mem2590[ss:bp_2530 + -6:word16] || Mem2590[ds_2557:22712:word16] + 0x1C <u Mem2590[ss:bp_2530 + -4:word16])
					{
						if (Mem2590[ds_2557:22712:word16] + 0x1C <u Mem2590[ss:bp_2530 + -6:word16])
						{
							--ss->*((word32) bp_2530 - 6);
							struct Eq_26447 Eq_17::* sp_3225 = sp_2588 - 2;
							(ss->*sp_3225).t0000.u2 = (uint16) (ss->*((word32) bp_2530 - 0x0C));
							(ss->*sp_3225).tFFFE.u2 = (uint16) (ss->*((word32) bp_2530 - 6));
							(ss->*sp_3225).tFFFC.u2 = (uint16) &(ss->*((word32) bp_2530 - 0x0C)).u3->t0002.u0;
							(ss->*sp_3225).tFFFA.u2 = (uint16) (ss->*((word32) bp_2530 - 6));
							word16 dx_3533;
							fn1AB8_1AF6(ds_2557, (ss->*sp_3225).tFFFA.u2, (ss->*sp_3225).tFFFC.u2, (ss->*sp_3225).tFFFE.u2, (ss->*sp_3225).t0000.u2, out dx_3533);
						}
						if (Mem3246[ds_2557:22712:word16] + 0x1C <u Mem3246[ss:bp_2530 + -4:word16])
						{
							--ss->*((word32) bp_2530 - 4);
							struct Eq_26802 Eq_17::* sp_3257 = sp_2588 - 2;
							(ss->*sp_3257).t0000.u2 = (uint16) (ss->*((word32) bp_2530 - 0x0A));
							(ss->*sp_3257).tFFFE.u2 = (uint16) (ss->*((word32) bp_2530 - 4));
							(ss->*sp_3257).tFFFC.u2 = (uint16) &(ss->*((word32) bp_2530 - 0x0A)).u3->t0002.u0;
							(ss->*sp_3257).tFFFA.u2 = (uint16) (ss->*((word32) bp_2530 - 4));
							word16 dx_3536;
							fn1AB8_1AF6(ds_2557, (ss->*sp_3257).tFFFA.u2, (ss->*sp_3257).tFFFC.u2, (ss->*sp_3257).tFFFE.u2, (ss->*sp_3257).t0000.u2, out dx_3536);
						}
						struct Eq_26765 Eq_17::* sp_3278 = sp_2588 - 2;
						(ss->*sp_3278).t0000.u2 = (uint16) 0xFA;
						(ss->*sp_3278).tFFFE.u2 = (uint16) 0x1E;
						Eq_481 sp_3296;
						sp_3296.u0 = <invalid>;
						bp_2530 = fn0C74_070D(ds_2557, (ss->*sp_3278).tFFFE.u2, (ss->*sp_3278).t0000.u2, out ds_2557);
						sp_2588 = (word16) sp_3296 + 4;
					}
					struct Eq_26095 Eq_17::* sp_2603 = sp_2588 - 2;
					(ss->*sp_2603).t0000.u2 = (uint16) (ss->*((word32) bp_2530 - 0x0E));
					(ss->*sp_2603).tFFFE.u2 = (uint16) (ss->*((word32) bp_2530 - 16));
					(ss->*sp_2603).tFFFC.u2 = (uint16) (ss->*((word32) bp_2530 - 32));
					word16 dx_3527;
					Eq_17 ds_2616;
					fn1EDA_0254(ds_2557, (ss->*sp_2603).tFFF8.u2, (ss->*sp_2603).tFFFA.u2, (ss->*sp_2603).tFFFC.u2, (ss->*sp_2603).tFFFE.u3, out dx_3527, out ds_2616);
					(ss->*sp_2603).t0000.u2 = (uint16) (ss->*((word32) bp_2530 - 18));
					(ss->*sp_2603).tFFFE.u2 = (uint16) (ss->*((word32) bp_2530 - 20));
					(ss->*sp_2603).tFFFC.u2 = (uint16) (ss->*((word32) bp_2530 - 32));
					word16 dx_3528;
					struct Eq_26186 * ds_2639;
					fn1EDA_0254(ds_2616, (ss->*sp_2603).tFFF8.u2, (ss->*sp_2603).tFFFA.u2, (ss->*sp_2603).tFFFC.u2, (ss->*sp_2603).tFFFE.u3, out dx_3528, out ds_2639);
					word16 cx_3529;
					word16 dx_3530;
					word16 bx_3531;
					Eq_17 ds_2680;
					(ss->*sp_2603).t0000.u2 = (uint16) fn1EDA_098A(0x04, fn1EDA_096F(ds_2639->w4D0C, ds_2639->t58E6, 0x00, 0x00), (ss->*sp_2603).tFFFE.u2, (ss->*sp_2603).t0000.u2, out cx_3529, out dx_3530, out bx_3531, out ds_2680);
					Eq_17 bp_2694 = fn0C74_02D8(ds_2680, (ss->*sp_2603).t0000.u2, out ds_2698);
					Eq_481 sp_2702;
					sp_2702.u0 = <invalid>;
					ss->*sp_2702 = ss->*((word32) bp_2694 - 0x0A) - 0x01;
					Mem2715[ss:sp_2702 + -2:word16] = Mem2711[ds_2698:22712:word16] + 0x0D;
					ss->*((word16) sp_2702 - 4) = &(ss->*((word32) bp_2694 - 0x0A)).u3->t0004.u0;
					Mem2724[ss:sp_2702 + -6:word16] = Mem2719[ds_2698:22712:word16] + 0x1B;
					ss->*((word32) bp_2694 - 32) = fn1AB8_13A3(ds_2698, ss->*((word16) sp_2702 - 6), ss->*((word16) sp_2702 - 4), ss->*((word16) sp_2702 - 2), ss->*sp_2702);
					ss->*sp_2702 = ss->*((word32) bp_2694 - 32);
					Eq_17 dx_ax_3532 = fn1EDA_023F(ds_2698, ss->*((word16) sp_2702 - 4), ss->*((word16) sp_2702 - 2), ss->*sp_2702, out ds_2743);
					ss->*((word32) bp_2694 - 20) = (word16) dx_ax_3532;
					(ss->*((word32) bp_2694 - 18)).u3 = SLICE(dx_ax_3532, word16, 16);
					ss->*sp_2702 = ss->*((word32) bp_2694 - 0x0A) - 0x01;
					Mem2761[ss:sp_2702 + -2:word16] = Mem2757[ds_2743:22712:word16] + 0x0D;
					ss->*((word16) sp_2702 - 4) = &(ss->*((word32) bp_2694 - 0x0A)).u3->t0004.u0;
					Mem2770[ss:sp_2702 + -6:word16] = Mem2765[ds_2743:22712:word16] + 0x1B;
					Eq_17 es_di_2771 = ss->*((word32) bp_2694 - 20);
					ss->*((word16) sp_2702 - 8) = SLICE(es_di_2771, selector, 16);
					ss->*((word16) sp_2702 - 0x0A) = (word16) es_di_2771;
					fn1AB8_1E6B(ds_2743, ss->*((word16) sp_2702 - 0x0A), ss->*((word16) sp_2702 - 6), ss->*((word16) sp_2702 - 4), ss->*((word16) sp_2702 - 2), ss->*sp_2702);
					Mem2792[ss:bp_2694 + -42:word16] = Mem2777[ds_2743:22708:word16] + 44;
					struct Eq_26412 Eq_17::* sp_2788 = (word16) sp_2702 + 2;
					Eq_17 ax_2793 = ss->*((word32) bp_2694 - 0x0A);
					if (ax_2793 - 0x01 >= ss->*((word32) bp_2694 - 42))
					{
						ss->*((word32) bp_2694 - 6) = ax_2793 - 0x01;
						while (true)
						{
							struct Eq_27107 Eq_17::* sp_2799 = sp_2788 - 2;
							(ss->*sp_2799).t0000.u2 = (uint16) 0xE6;
							(ss->*sp_2799).tFFFE.u2 = (uint16) 0x19;
							bp_2694 = fn0C74_070D(ds_2743, (ss->*sp_2799).tFFFE.u2, (ss->*sp_2799).t0000.u2, out ds_2743);
							Eq_481 sp_2815;
							sp_2815.u0 = <invalid>;
							ss->*((word16) sp_2815 + 2) = ss->*((word32) bp_2694 - 6);
							Mem2828[ss:sp_2815 + 0x00:word16] = Mem2823[ds_2743:22712:word16] + 0x0D;
							Eq_17 es_di_2829 = ss->*((word32) bp_2694 - 20);
							ss->*((word16) sp_2815 - 2) = SLICE(es_di_2829, selector, 16);
							ss->*((word16) sp_2815 - 4) = (word16) es_di_2829;
							ss->*((word16) sp_2815 - 6) = 0x00;
							fn1AB8_13D7(ds_2743, ss->*((word16) sp_2815 + 6), ss->*((word16) sp_2815 - 4), ss->*sp_2815, ss->*((word16) sp_2815 + 2));
							sp_2788 = (word16) sp_2815 + 4;
							if (ss->*((word32) bp_2694 - 6) == ss->*((word32) bp_2694 - 42))
								break;
							--ss->*((word32) bp_2694 - 6);
						}
					}
					struct Eq_26859 Eq_17::* sp_2861 = sp_2788 - 2;
					(ss->*sp_2861).t0000.u2 = (uint16) (ss->*((word32) bp_2694 - 18));
					(ss->*sp_2861).tFFFE.u2 = (uint16) (ss->*((word32) bp_2694 - 20));
					(ss->*sp_2861).tFFFC.u2 = (uint16) (ss->*((word32) bp_2694 - 32));
					word16 dx_3537;
					Eq_17 ds_2875;
					fn1EDA_0254(ds_2743, (ss->*sp_2861).tFFF8.u2, (ss->*sp_2861).tFFFA.u2, (ss->*sp_2861).tFFFC.u2, (ss->*sp_2861).tFFFE.u3, out dx_3537, out ds_2875);
					(ss->*sp_2861).t0000.u2 = (uint16) (ss->*((word32) bp_2694 - 0x0C) - 0x02);
					Mem2893[ss:sp_2861 + -2:word16] = Mem2889[ds_2875:22712:word16] + 0x0D;
					(ss->*sp_2861).tFFFC.u2 = (uint16) ((word32) (ss->*((word32) bp_2694 - 0x0C)) + 3);
					Mem2902[ss:sp_2861 + -6:word16] = Mem2897[ds_2875:22712:word16] + 0x1B;
					ss->*((word32) bp_2694 - 32) = fn1AB8_13A3(ds_2875, (ss->*sp_2861).tFFFA.u2, (ss->*sp_2861).tFFFC.u2, (ss->*sp_2861).tFFFE.u2, (ss->*sp_2861).t0000.u2);
					(ss->*sp_2861).t0000.u2 = (uint16) (ss->*((word32) bp_2694 - 32));
					Eq_17 dx_ax_3538 = fn1EDA_023F(ds_2875, (ss->*sp_2861).tFFFC.u2, (ss->*sp_2861).tFFFE.u2, (ss->*sp_2861).t0000.u2, out ds_2921);
					ss->*((word32) bp_2694 - 16) = (word16) dx_ax_3538;
					(ss->*((word32) bp_2694 - 0x0E)).u3 = SLICE(dx_ax_3538, word16, 16);
					(ss->*sp_2861).t0000.u2 = (uint16) (ss->*((word32) bp_2694 - 0x0C) - 0x02);
					Mem2940[ss:sp_2861 + -2:word16] = Mem2936[ds_2921:22712:word16] + 0x0D;
					(ss->*sp_2861).tFFFC.u2 = (uint16) ((word32) (ss->*((word32) bp_2694 - 0x0C)) + 3);
					Mem2949[ss:sp_2861 + -6:word16] = Mem2944[ds_2921:22712:word16] + 0x1B;
					Eq_17 es_di_2950 = ss->*((word32) bp_2694 - 16);
					(ss->*sp_2861).tFFF8.u2 = (uint16) SLICE(es_di_2950, selector, 16);
					(ss->*sp_2861).tFFF6.u2 = (uint16) (word16) es_di_2950;
					fn1AB8_1E6B(ds_2921, (ss->*sp_2861).tFFF6.u3, (ss->*sp_2861).tFFFA.u2, (ss->*sp_2861).tFFFC.u2, (ss->*sp_2861).tFFFE.u2, (ss->*sp_2861).t0000.u2);
					Mem2971[ss:bp_2694 + -42:word16] = Mem2956[ds_2921:22708:word16] - 0x06;
					struct Eq_27087 Eq_17::* sp_2967 = (struct Eq_27087 Eq_17::*) ((char *) &sp_2861->t0000 + 2);
					Eq_17 ax_2972 = ss->*((word32) bp_2694 - 0x0C);
					if (ax_2972 - 0x02 <= ss->*((word32) bp_2694 - 42))
					{
						ss->*((word32) bp_2694 - 6) = ax_2972 - 0x02;
						while (true)
						{
							struct Eq_27571 Eq_17::* sp_2979 = sp_2967 - 2;
							(ss->*sp_2979).t0000.u2 = (uint16) 0xE6;
							(ss->*sp_2979).tFFFE.u2 = (uint16) 0x19;
							bp_2694 = fn0C74_070D(ds_2921, (ss->*sp_2979).tFFFE.u2, (ss->*sp_2979).t0000.u2, out ds_2921);
							Eq_481 sp_2995;
							sp_2995.u0 = <invalid>;
							ss->*((word16) sp_2995 + 2) = ss->*((word32) bp_2694 - 6);
							Mem3008[ss:sp_2995 + 0x00:word16] = Mem3003[ds_2921:22712:word16] + 0x0D;
							Eq_17 es_di_3009 = ss->*((word32) bp_2694 - 16);
							ss->*((word16) sp_2995 - 2) = SLICE(es_di_3009, selector, 16);
							ss->*((word16) sp_2995 - 4) = (word16) es_di_3009;
							ss->*((word16) sp_2995 - 6) = 0x00;
							fn1AB8_13D7(ds_2921, ss->*((word16) sp_2995 + 6), ss->*((word16) sp_2995 - 4), ss->*sp_2995, ss->*((word16) sp_2995 + 2));
							sp_2967 = (word16) sp_2995 + 4;
							if (ss->*((word32) bp_2694 - 6) == ss->*((word32) bp_2694 - 42))
								break;
							(ss->*((word32) bp_2694 - 6)).u3 = &(ss->*((word32) bp_2694 - 6)).u3->t0001.u0;
						}
					}
					struct Eq_27423 Eq_17::* sp_3041 = sp_2967 - 2;
					(ss->*sp_3041).t0000.u2 = (uint16) (ss->*((word32) bp_2694 - 0x0E));
					(ss->*sp_3041).tFFFE.u2 = (uint16) (ss->*((word32) bp_2694 - 16));
					(ss->*sp_3041).tFFFC.u2 = (uint16) (ss->*((word32) bp_2694 - 32));
					word16 dx_3541;
					Eq_17 ds_3055;
					fn1EDA_0254(ds_2921, (ss->*sp_3041).tFFF8.u2, (ss->*sp_3041).tFFFA.u2, (ss->*sp_3041).tFFFC.u2, (ss->*sp_3041).tFFFE.u3, out dx_3541, out ds_3055);
					(ss->*((word32) bp_2694 - 4)).u0 = 0x13;
					(ss->*sp_3041).t0000.u2 = (uint16) bp_2694;
					struct Eq_27485 * ds_3072;
					fn0C74_0E2E(ds_3055, (ss->*sp_3041).t0000.u2, out ds_3072);
					Eq_481 sp_3077;
					sp_3077.u0 = <invalid>;
					word16 cx_3542;
					word16 dx_3543;
					word16 bx_3544;
					Eq_17 ds_3115;
					ss->*sp_3077 = fn1EDA_098A(0x04, fn1EDA_096F(ds_3072->w4D0C, ds_3072->t58E6, 0x00, 0x00), ss->*((word16) sp_3077 + 0x0000FFFE), ss->*sp_3077, out cx_3542, out dx_3543, out bx_3544, out ds_3115);
					bp_1129 = fn0C74_02D8(ds_3115, ss->*sp_3077, out ds_1150);
					(ss->*((word32) bp_1129 - 1)).u3 = 0x01;
					Eq_481 sp_3137;
					sp_3137.u0 = <invalid>;
					Mem3146[ss:sp_3137 + 0x00:word16] = Mem3143[ds_1150:22708:word16];
					Mem3151[ss:sp_3137 + -2:word16] = Mem3146[ds_1150:22714:word16] + 0x01;
					byte dl_3545;
					if (fn1AB8_1E3C(ds_1150, ss->*((word16) sp_3137 - 2), ss->*sp_3137, out dl_3545) == 0x00)
					{
						Mem3168[ss:sp_3137 + 0x00:word16] = Mem3151[ds_1150:22710:word16];
						Mem3173[ss:sp_3137 + -2:word16] = Mem3168[ds_1150:22714:word16] + 0x01;
						byte dl_3546;
						if (fn1AB8_1E3C(ds_1150, ss->*((word16) sp_3137 - 2), ss->*sp_3137, out dl_3546) == 0x00)
						{
							bp_1129 = fn0C74_05B8(ds_1150, out ds_1150);
							fn0C74_0A35(ds_1150);
						}
					}
					goto l0C74_1B36;
				}
			}
			struct Eq_24687 Eq_17::* sp_1716 = sp_1658 - 2;
			(ss->*sp_1716).t0000.u2 = (uint16) (ss->*((word32) bp_1645 - 0x0C));
			(ss->*sp_1716).tFFFE.u2 = (uint16) (ss->*((word32) bp_1645 - 6));
			byte dl_3507;
			if (fn1AB8_1E3C(ds_1649, (ss->*sp_1716).tFFFE.u2, (ss->*sp_1716).t0000.u2, out dl_3507) == 0x00)
			{
				(ss->*sp_1716).t0000.u2 = (uint16) (ss->*((word32) bp_1645 - 0x0C));
				(ss->*sp_1716).tFFFE.u2 = (uint16) (ss->*((word32) bp_1645 - 6));
				(ss->*sp_1716).tFFFC.u2 = (uint16) 11;
				fn1AB8_1E54(ds_1649, (ss->*sp_1716).tFFFC.u0, (ss->*sp_1716).tFFFE.u2, (ss->*sp_1716).t0000.u2);
				(ss->*sp_1716).t0000.u2 = (uint16) &(ss->*((word32) bp_1645 - 0x0C)).u3->t0001.u0;
				(ss->*sp_1716).tFFFE.u2 = (uint16) (ss->*((word32) bp_1645 - 6));
				(ss->*sp_1716).tFFFC.u2 = (uint16) 0x03;
				fn1AB8_1E54(ds_1649, (ss->*sp_1716).tFFFC.u0, (ss->*sp_1716).tFFFE.u2, (ss->*sp_1716).t0000.u2);
				(ss->*sp_1716).t0000.u2 = (uint16) &(ss->*((word32) bp_1645 - 0x0C)).u3->t0002.u0;
				(ss->*sp_1716).tFFFE.u2 = (uint16) (ss->*((word32) bp_1645 - 6));
				(ss->*sp_1716).tFFFC.u2 = (uint16) 0x09;
				fn1AB8_1E54(ds_1649, (ss->*sp_1716).tFFFC.u0, (ss->*sp_1716).tFFFE.u2, (ss->*sp_1716).t0000.u2);
				(ss->*((word32) bp_1645 - 6)).u3 = &(ss->*((word32) bp_1645 - 6)).u3->t0001.u0;
			}
			struct Eq_27727 Eq_17::* sp_1788 = sp_1658 - 2;
			(ss->*sp_1788).t0000.u2 = (uint16) (ss->*((word32) bp_1645 - 0x0A));
			(ss->*sp_1788).tFFFE.u2 = (uint16) (ss->*((word32) bp_1645 - 4));
			byte dl_3547;
			if (fn1AB8_1E3C(ds_1649, (ss->*sp_1788).tFFFE.u2, (ss->*sp_1788).t0000.u2, out dl_3547) == 0x00)
			{
				(ss->*sp_1788).t0000.u2 = (uint16) (ss->*((word32) bp_1645 - 0x0A));
				(ss->*sp_1788).tFFFE.u2 = (uint16) (ss->*((word32) bp_1645 - 4));
				(ss->*sp_1788).tFFFC.u2 = (uint16) 11;
				fn1AB8_1E54(ds_1649, (ss->*sp_1788).tFFFC.u0, (ss->*sp_1788).tFFFE.u2, (ss->*sp_1788).t0000.u2);
				(ss->*sp_1788).t0000.u2 = (uint16) &(ss->*((word32) bp_1645 - 0x0A)).u3->t0001.u0;
				(ss->*sp_1788).tFFFE.u2 = (uint16) (ss->*((word32) bp_1645 - 4));
				(ss->*sp_1788).tFFFC.u2 = (uint16) 0x03;
				fn1AB8_1E54(ds_1649, (ss->*sp_1788).tFFFC.u0, (ss->*sp_1788).tFFFE.u2, (ss->*sp_1788).t0000.u2);
				(ss->*sp_1788).t0000.u2 = (uint16) &(ss->*((word32) bp_1645 - 0x0A)).u3->t0002.u0;
				(ss->*sp_1788).tFFFE.u2 = (uint16) (ss->*((word32) bp_1645 - 4));
				(ss->*sp_1788).tFFFC.u2 = (uint16) 0x09;
				fn1AB8_1E54(ds_1649, (ss->*sp_1788).tFFFC.u0, (ss->*sp_1788).tFFFE.u2, (ss->*sp_1788).t0000.u2);
				(ss->*((word32) bp_1645 - 4)).u3 = &(ss->*((word32) bp_1645 - 4)).u3->t0001.u0;
			}
			struct Eq_28057 Eq_17::* sp_1856 = sp_1658 - 2;
			(ss->*sp_1856).t0000.u2 = (uint16) 0xFA;
			(ss->*sp_1856).tFFFE.u2 = (uint16) 0x1E;
			Eq_481 sp_1875;
			sp_1875.u0 = <invalid>;
			bp_1645 = fn0C74_070D(ds_1649, (ss->*sp_1856).tFFFE.u2, (ss->*sp_1856).t0000.u2, out ds_1649);
			sp_1658 = (word16) sp_1875 + 4;
		}
	}
	while (ss->*((word32) bp_1039 - 4) < 0x41)
	{
		struct Eq_25314 Eq_17::* sp_1233 = sp_1215 - 2;
		Mem1234[ss:sp_1233 + 0x00:word16] = Mem1225[ds_1175:22708:word16] + 0x0C - Mem1225[ss:bp_1039 + -4:word16];
		Mem1239[ss:sp_1233 + -2:word16] = Mem1234[ds_1175:22712:word16] + 0x1B;
		byte dl_3516;
		if (fn1AB8_1E3C(ds_1175, (ss->*sp_1233).tFFFE.u2, (ss->*sp_1233).t0000.u2, out dl_3516) != 0x00)
			break;
		Mem1258[ss:sp_1233 + 0x00:word16] = Mem1239[ds_1175:22708:word16] + 0x0C - Mem1239[ss:bp_1039 + -4:word16];
		Mem1263[ss:sp_1233 + -2:word16] = Mem1258[ds_1175:22712:word16] + 0x0D;
		byte dl_3517;
		if (fn1AB8_1E3C(ds_1175, (ss->*sp_1233).tFFFE.u2, (ss->*sp_1233).t0000.u2, out dl_3517) != 0x00)
			break;
		(ss->*sp_1233).t0000.u2 = (uint16) 0xE6;
		(ss->*sp_1233).tFFFE.u2 = (uint16) 0x19;
		bp_1039 = fn0C74_070D(ds_1175, (ss->*sp_1233).tFFFE.u2, (ss->*sp_1233).t0000.u2, out ds_1175);
		Eq_481 sp_1550;
		sp_1550.u0 = <invalid>;
		Mem1560[ss:sp_1550 + 0x02:word16] = Mem1540[ds_1175:22708:word16] + 0x0D - Mem1540[ss:bp_1039 + -4:word16];
		Mem1565[ss:sp_1550 + 0x00:word16] = Mem1560[ds_1175:22712:word16] + 0x0D;
		Eq_17 es_di_1566 = ss->*((word32) bp_1039 - 16);
		ss->*((word16) sp_1550 - 2) = SLICE(es_di_1566, selector, 16);
		ss->*((word16) sp_1550 - 4) = (word16) es_di_1566;
		ss->*((word16) sp_1550 - 6) = 0x00;
		fn1AB8_13D7(ds_1175, ss->*((word16) sp_1550 + 6), ss->*((word16) sp_1550 - 4), ss->*sp_1550, ss->*((word16) sp_1550 + 2));
		(ss->*((word32) bp_1039 - 4)).u3 = &(ss->*((word32) bp_1039 - 4)).u3->t0001.u0;
		sp_1215 = (word16) sp_1550 + 4;
	}
	if (ss->*((word32) bp_1039 - 4) == 0x41)
	{
		Mem1536[ss:bp_1039 + -0x0C:word16] = Mem1280[ds_1175:22708:word16] + 0x0D - Mem1280[ss:bp_1039 + -4:word16] + 0x02;
		goto l0C74_15E7;
	}
	struct Eq_26504 Eq_17::* sp_1285 = sp_1215 - 2;
	(ss->*sp_1285).t0000.u2 = (uint16) (ss->*((word32) bp_1039 - 0x0E));
	(ss->*sp_1285).tFFFE.u2 = (uint16) (ss->*((word32) bp_1039 - 16));
	(ss->*sp_1285).tFFFC.u2 = (uint16) (ss->*((word32) bp_1039 - 32));
	word16 dx_3534;
	Eq_17 ds_1300;
	fn1EDA_0254(ds_1175, (ss->*sp_1285).tFFF8.u2, (ss->*sp_1285).tFFFA.u2, (ss->*sp_1285).tFFFC.u2, (ss->*sp_1285).tFFFE.u3, out dx_3534, out ds_1300);
	Mem1314[ss:sp_1285 + 0x00:word16] = Mem1292[ds_1300:22708:word16] + 0x0D - Mem1292[ss:bp_1039 + -4:word16];
	Mem1318[ss:sp_1285 + -2:word16] = Mem1314[ds_1300:22712:word16] + 0x0D;
	Mem1323[ss:sp_1285 + -4:word16] = Mem1318[ds_1300:22708:word16] + 0x11 - Mem1318[ss:bp_1039 + -4:word16];
	Mem1328[ss:sp_1285 + -6:word16] = Mem1323[ds_1300:22712:word16] + 0x1B;
	ss->*((word32) bp_1039 - 0x0022) = fn1AB8_13A3(ds_1300, (ss->*sp_1285).tFFFA.u2, (ss->*sp_1285).tFFFC.u2, (ss->*sp_1285).tFFFE.u2, (ss->*sp_1285).t0000.u2);
	(ss->*sp_1285).t0000.u2 = (uint16) (ss->*((word32) bp_1039 - 0x0022));
	Eq_17 dx_ax_3535 = fn1EDA_023F(ds_1300, (ss->*sp_1285).tFFFC.u2, (ss->*sp_1285).tFFFE.u2, (ss->*sp_1285).t0000.u2, out ds_1347);
	ss->*((word32) bp_1039 - 16) = (word16) dx_ax_3535;
	(ss->*((word32) bp_1039 - 0x0E)).u3 = SLICE(dx_ax_3535, word16, 16);
	Mem1362[ss:sp_1285 + 0x00:word16] = Mem1357[ds_1347:22708:word16] + 0x0D - Mem1357[ss:bp_1039 + -4:word16];
	Mem1366[ss:sp_1285 + -2:word16] = Mem1362[ds_1347:22712:word16] + 0x0D;
	Mem1371[ss:sp_1285 + -4:word16] = Mem1366[ds_1347:22708:word16] + 0x11 - Mem1366[ss:bp_1039 + -4:word16];
	Mem1376[ss:sp_1285 + -6:word16] = Mem1371[ds_1347:22712:word16] + 0x1B;
	Eq_17 es_di_1377 = ss->*((word32) bp_1039 - 16);
	(ss->*sp_1285).tFFF8.u2 = (uint16) SLICE(es_di_1377, selector, 16);
	(ss->*sp_1285).tFFF6.u2 = (uint16) (word16) es_di_1377;
	fn1AB8_1E6B(ds_1347, (ss->*sp_1285).tFFF6.u3, (ss->*sp_1285).tFFFA.u2, (ss->*sp_1285).tFFFC.u2, (ss->*sp_1285).tFFFE.u2, (ss->*sp_1285).t0000.u2);
	struct Eq_26739 Eq_17::* sp_1394 = (struct Eq_26739 Eq_17::*) &sp_1285->t0002.u0;
	Eq_17 ax_1395 = ss->*((word32) bp_1039 - 4);
	if (ax_1395 >= 0x13)
	{
		ss->*((word32) bp_1039 - 6) = ax_1395;
		while (true)
		{
			struct Eq_27319 Eq_17::* sp_1400 = sp_1394 - 2;
			(ss->*sp_1400).t0000.u2 = (uint16) 0xE6;
			(ss->*sp_1400).tFFFE.u2 = (uint16) 0x19;
			bp_1039 = fn0C74_070D(ds_1347, (ss->*sp_1400).tFFFE.u2, (ss->*sp_1400).t0000.u2, out ds_1347);
			Eq_481 sp_1416;
			sp_1416.u0 = <invalid>;
			Mem1426[ss:sp_1416 + 0x02:word16] = Mem1404[ds_1347:22708:word16] + 0x0D - Mem1404[ss:bp_1039 + -6:word16];
			Mem1431[ss:sp_1416 + 0x00:word16] = Mem1426[ds_1347:22712:word16] + 0x0D;
			Eq_17 es_di_1432 = ss->*((word32) bp_1039 - 16);
			ss->*((word16) sp_1416 - 2) = SLICE(es_di_1432, selector, 16);
			ss->*((word16) sp_1416 - 4) = (word16) es_di_1432;
			ss->*((word16) sp_1416 - 6) = 0x00;
			fn1AB8_13D7(ds_1347, ss->*((word16) sp_1416 + 6), ss->*((word16) sp_1416 - 4), ss->*sp_1416, ss->*((word16) sp_1416 + 2));
			sp_1394 = (word16) sp_1416 + 4;
			if (ss->*((word32) bp_1039 - 6) == 0x13)
				break;
			--ss->*((word32) bp_1039 - 6);
		}
	}
	(ss->*((word32) bp_1039 - 4)).u0 = 0x14;
	struct Eq_27203 Eq_17::* sp_1462 = sp_1394 - 2;
	(ss->*sp_1462).t0000.u2 = (uint16) bp_1039;
	Eq_17 ds_1470;
	bp_1129 = fn0C74_0E2E(ds_1347, (ss->*sp_1462).t0000.u2, out ds_1470);
	Eq_481 sp_1475;
	sp_1475.u0 = <invalid>;
	ss->*sp_1475 = ss->*((word32) bp_1129 - 0x0E);
	ss->*((word16) sp_1475 - 2) = ss->*((word32) bp_1129 - 16);
	ss->*((word16) sp_1475 - 4) = ss->*((word32) bp_1129 - 0x0022);
	word16 dx_3539;
	Eq_17 ds_1495;
	fn1EDA_0254(ds_1470, ss->*((word16) sp_1475 - 8), ss->*((word16) sp_1475 - 6), ss->*((word16) sp_1475 - 4), ss->*((word16) sp_1475 - 2), out dx_3539, out ds_1495);
	ss->*sp_1475 = ss->*((word32) bp_1129 - 18);
	ss->*((word16) sp_1475 - 2) = ss->*((word32) bp_1129 - 20);
	ss->*((word16) sp_1475 - 4) = ss->*((word32) bp_1129 - 32);
	word16 dx_3540;
	fn1EDA_0254(ds_1495, ss->*((word16) sp_1475 - 8), ss->*((word16) sp_1475 - 6), ss->*((word16) sp_1475 - 4), ss->*((word16) sp_1475 - 2), out dx_3540, out ds_1150);
	(ss->*((word32) bp_1129 - 1)).u3 = 0x00;
l0C74_1B36:
	byte al_3370 = (byte) (ss->*((word32) bp_1129 - 1));
	bpOut = (struct Eq_24289 Eq_17::*) (ss->*bp_1129.u3).t0000.u2;
	dsOut = ds_1150;
	return al_3370;
}
