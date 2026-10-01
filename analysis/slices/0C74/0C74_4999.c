// 0C74:4999: Register byte fn0C74_4999(Register Eq_17 ds, Register out (memptr Eq_17 Eq_46518) bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_5258
byte fn0C74_4999(Eq_17 ds, struct Eq_46518 & bpOut, union Eq_17 & dsOut)
{
	mp16 fp;
	fn1AB8_10F4(ds, 0x01, 0x00, 0x00);
	fn1AB8_1C32(ds, 0x0C);
	Mem35[ds:22708:word16] = Mem33[ds:22708:word16] + 0x01;
	Eq_17 bp_39 = fp - 2;
	struct Eq_46168 Eq_17::* sp_138 = fp - 0x0E;
	selector ss;
	Eq_481 sp_103;
	cup16 ax_152;
	do
	{
		struct Eq_46232 Eq_17::* sp_55 = sp_138 - 2;
		Mem56[ss:sp_55 + 0x00:word16] = Mem40[ds:22708:word16] + Mem40[ss:bp_39 + -4:word16];
		Mem60[ss:sp_55 + -2:word16] = Mem56[ds:22712:word16] + 0x12;
		Mem74[ss:sp_55 + -4:word16] = Mem60[ds:22708:word16] + Mem60[ss:bp_39 + -4:word16];
		Mem79[ss:sp_55 + -6:word16] = Mem74[ds:22712:word16] + 0x13;
		word16 dx_1089;
		fn1AB8_1AF6(ds, (ss->*sp_55).tFFFA.u2, (ss->*sp_55).tFFFC.u2, (ss->*sp_55).tFFFE.u2, (ss->*sp_55).t0000.u2, out dx_1089);
		(ss->*((word32) bp_39 - 4)).u3 = ss->*((word32) bp_39 - 4) - 0x01;
		(ss->*sp_55).t0000.u2 = (uint16) 300;
		(ss->*sp_55).tFFFE.u2 = (uint16) 0x14;
		bp_39 = fn0C74_070D(ds, (ss->*sp_55).tFFFE.u2, (ss->*sp_55).t0000.u2, out ds);
		sp_103.u0 = <invalid>;
		if (ss->*((word32) bp_39 - 4) == ~0x0E)
			break;
		Mem124[ss:sp_103 + 0x02:word16] = Mem92[ds:22708:word16] + Mem92[ss:bp_39 + -4:word16];
		Mem129[ss:sp_103 + 0x00:word16] = Mem124[ds:22712:word16] + 0x13;
		sp_138 = (word16) sp_103 + 4;
		byte dl_1088;
		if (fn1AB8_1E3C(ds, ss->*sp_103, ss->*((word16) sp_103 + 2), out dl_1088) != 0x00)
			break;
		Eq_46223 dx_ax_1006 = CONVERT(Mem129[ds:22708:word16] + Mem129[ss:bp_39 + -4:word16], word16, uint32);
		ax_152 = (word16) dx_ax_1006;
	} while (true && (false || ax_152 > 0x00));
	if (ss->*((word32) bp_39 - 4) != ~0x0E)
	{
		ss->*((word16) sp_103 + 2) = 0x00;
		fn1AB8_1C32(ds, ss->*((word16) sp_103 + 2));
		struct Eq_46378 Eq_17::* sp_898 = (word16) sp_103 + 4;
		int16 ax_899 = (int16) (ss->*((word32) bp_39 - 4));
		if (ax_899 <= 0x0C)
		{
			(ss->*((word32) bp_39 - 6)).u3 = ax_899 + 0x01;
			while (true)
			{
				struct Eq_46406 Eq_17::* sp_921 = sp_898 - 2;
				Mem922[ss:sp_921 + 0x00:word16] = Mem906[ds:22708:word16] + Mem906[ss:bp_39 + -6:word16];
				Mem926[ss:sp_921 + -2:word16] = Mem922[ds:22712:word16] + 0x12;
				Mem940[ss:sp_921 + -4:word16] = Mem926[ds:22708:word16] + Mem926[ss:bp_39 + -6:word16];
				Mem945[ss:sp_921 + -6:word16] = Mem940[ds:22712:word16] + 0x13;
				word16 dx_1090;
				fn1AB8_1AF6(ds, (ss->*sp_921).tFFFA.u2, (ss->*sp_921).tFFFC.u2, (ss->*sp_921).tFFFE.u2, (ss->*sp_921).t0000.u2, out dx_1090);
				(ss->*sp_921).t0000.u2 = (uint16) 300;
				(ss->*sp_921).tFFFE.u2 = (uint16) 0x14;
				Eq_481 sp_966;
				sp_966.u0 = <invalid>;
				bp_39 = fn0C74_070D(ds, (ss->*sp_921).tFFFE.u2, (ss->*sp_921).t0000.u2, out ds);
				sp_898 = (word16) sp_966 + 4;
				if (ss->*((word32) bp_39 - 6) == 0x0D)
					break;
				(ss->*((word32) bp_39 - 6)).u3 = &(ss->*((word32) bp_39 - 6)).u3->t0001.u0;
			}
		}
		Mem980[ds:22708:word16] = Mem978[ds:22708:word16] - 0x01;
		(ss->*((word32) bp_39 - 1)).u3 = 0x00;
l0C74_4DA7:
		byte al_990 = (byte) (ss->*((word32) bp_39 - 1));
		bpOut = (struct Eq_46518 Eq_17::*) (ss->*bp_39.u3).t0000.u2;
		dsOut = ds;
		return al_990;
	}
	ss->*((word16) sp_103 + 2) = 500;
	Eq_17 bp_172 = fn0C74_02D8(ds, ss->*((word16) sp_103 + 2), out ds);
	Mem188[ss:bp_172 + -0x0A:word16] = Mem168[ds:22712:word16] + 0x12;
	Mem192[ss:bp_172 + -0x0C:word16] = Mem188[ds:22712:word16] + 0x14;
	Eq_481 sp_180;
	sp_180.u0 = <invalid>;
	word16 sp_185 = (word16) sp_180 + 2;
	struct Eq_46549 Eq_17::* sp_199;
	while (true)
	{
		sp_199 = sp_185 - 2;
		Mem201[ss:sp_199 + 0x00:word16] = Mem194[ds:22708:word16] - 0x0E;
		(ss->*sp_199).tFFFE.u2 = (uint16) (ss->*((word32) bp_172 - 0x0C));
		byte dl_1093;
		if (fn1AB8_1E3C(ds, (ss->*sp_199).tFFFE.u2, (ss->*sp_199).t0000.u2, out dl_1093) != 0x00 || ss->*((word32) bp_172 - 0x0C) >= 0x01DE)
			break;
		(ss->*sp_199).t0000.u2 = (uint16) 0x0C;
		fn1AB8_1C32(ds, (ss->*sp_199).t0000.u0);
		Mem825[ss:sp_199 + 0x00:word16] = Mem817[ds:22708:word16] - 11;
		(ss->*sp_199).tFFFE.u2 = (uint16) (ss->*((word32) bp_172 - 0x0C));
		Mem833[ss:sp_199 + -4:word16] = Mem828[ds:22708:word16] - 0x0F;
		(ss->*sp_199).tFFFA.u2 = (uint16) (ss->*((word32) bp_172 - 0x0C));
		word16 dx_1091;
		fn1AB8_1AF6(ds, (ss->*sp_199).tFFFA.u2, (ss->*sp_199).tFFFC.u2, (ss->*sp_199).tFFFE.u2, (ss->*sp_199).t0000.u2, out dx_1091);
		(ss->*sp_199).t0000.u2 = (uint16) 0x00;
		fn1AB8_1C32(ds, (ss->*sp_199).t0000.u0);
		Mem852[ss:sp_199 + 0x00:word16] = Mem844[ds:22708:word16] - 11;
		(ss->*sp_199).tFFFE.u2 = (uint16) (ss->*((word32) bp_172 - 0x0A));
		Mem860[ss:sp_199 + -4:word16] = Mem855[ds:22708:word16] - 0x0F;
		(ss->*sp_199).tFFFA.u2 = (uint16) (ss->*((word32) bp_172 - 0x0A));
		word16 dx_1092;
		fn1AB8_1AF6(ds, (ss->*sp_199).tFFFA.u2, (ss->*sp_199).tFFFC.u2, (ss->*sp_199).tFFFE.u2, (ss->*sp_199).t0000.u2, out dx_1092);
		(ss->*sp_199).t0000.u2 = (uint16) 0x28;
		bp_172 = fn0C74_02D8(ds, (ss->*sp_199).t0000.u2, out ds);
		(ss->*((word32) bp_172 - 0x0A)).u3 = &(ss->*((word32) bp_172 - 0x0A)).u3->t0001.u0;
		(ss->*((word32) bp_172 - 0x0C)).u3 = &(ss->*((word32) bp_172 - 0x0C)).u3->t0001.u0;
		Eq_481 sp_882;
		sp_882.u0 = <invalid>;
		sp_185 = (word16) sp_882 + 2;
	}
	Mem226[ds:22892:word16] = Mem205[ds:22708:word16] - 0x2D;
	Mem230[ds:0x5970:word16] = Mem226[ds:22708:word16] - 0x02;
	if (Mem230[ds:22892:word16] < 0x01)
		Mem233[ds:22892:word16] = 0x01;
	if (Mem238[ss:bp_172 + -0x0C:word16] <u Mem238[ds:22714:word16])
	{
		Mem251[ds:22894:word16] = Mem238[ds:22712:word16];
		Mem253[ds:22898:word16] = Mem251[ds:22714:word16];
	}
	else
	{
		Mem245[ds:22894:word16] = Mem238[ss:bp_172 + -0x0C:word16] - 22;
		Mem249[ds:22898:word16] = Mem245[ss:bp_172 + -0x0C:word16] + 0x15;
	}
	if (Mem255[ds:22898:word16] > 0x0176)
	{
		Mem258[ds:22898:word16] = 0x0176;
		Mem259[ds:22894:word16] = 330;
	}
	Mem270[ss:sp_199 + 0x00:word16] = Mem261[ds:22892:word16];
	Mem275[ss:sp_199 + -2:word16] = Mem270[ds:22898:word16] - 0x15;
	byte dl_1094;
	if (fn1AB8_1E3C(ds, (ss->*sp_199).tFFFE.u2, (ss->*sp_199).t0000.u2, out dl_1094) == 0x00)
	{
		Mem292[ss:sp_199 + 0x00:word16] = Mem275[ds:22892:word16];
		Mem295[ss:sp_199 + -2:word16] = Mem292[ds:22894:word16];
		byte dl_1096;
		if (fn1AB8_1E3C(ds, (ss->*sp_199).tFFFE.u2, (ss->*sp_199).t0000.u2, out dl_1096) == 0x00)
			Mem311[ds:22892:word16] = Mem295[ds:22892:word16] + 22;
	}
	struct Eq_46833 Eq_17::* sp_319 = sp_185 - 2;
	Mem321[ss:sp_319 + 0x00:word16] = Mem314[ds:0x5970:word16] - 0x15;
	Mem324[ss:sp_319 + -2:word16] = Mem321[ds:22894:word16];
	byte dl_1095;
	if (fn1AB8_1E3C(ds, (ss->*sp_319).tFFFE.u2, (ss->*sp_319).t0000.u2, out dl_1095) == 0x00)
	{
		Mem343[ss:sp_319 + 0x00:word16] = Mem324[ds:0x5970:word16] - 0x2B;
		Mem346[ss:sp_319 + -2:word16] = Mem343[ds:22894:word16];
		byte dl_1099;
		if (fn1AB8_1E3C(ds, (ss->*sp_319).tFFFE.u2, (ss->*sp_319).t0000.u2, out dl_1099) == 0x00)
			Mem362[ds:22894:word16] = Mem346[ds:22894:word16] + 0x12;
	}
	struct Eq_46901 Eq_17::* sp_365 = sp_185 - 2;
	(ss->*sp_365).t0000.u2 = (uint16) 0x0C;
	fn1AB8_1C32(ds, (ss->*sp_365).t0000.u0);
	Mem376[ss:sp_365 + 0x00:word16] = Mem367[ds:22708:word16] - 11;
	(ss->*sp_365).tFFFE.u2 = (uint16) (ss->*((word32) bp_172 - 0x0A) - 0x01);
	Mem389[ss:sp_365 + -4:word16] = Mem384[ds:22708:word16] - 0x0F;
	(ss->*sp_365).tFFFA.u2 = (uint16) (ss->*((word32) bp_172 - 0x0A) - 0x01);
	word16 dx_1097;
	fn1AB8_1AF6(ds, (ss->*sp_365).tFFFA.u2, (ss->*sp_365).tFFFC.u2, (ss->*sp_365).tFFFE.u2, (ss->*sp_365).t0000.u2, out dx_1097);
	Mem404[ss:sp_365 + 0x00:word16] = Mem394[ds:22708:word16] - 11;
	(ss->*sp_365).tFFFE.u2 = (uint16) (ss->*((word32) bp_172 - 0x0A) - 0x02);
	Mem414[ss:sp_365 + -4:word16] = Mem409[ds:22708:word16] - 0x0F;
	(ss->*sp_365).tFFFA.u2 = (uint16) (ss->*((word32) bp_172 - 0x0A) - 0x02);
	word16 dx_1098;
	fn1AB8_1AF6(ds, (ss->*sp_365).tFFFA.u2, (ss->*sp_365).tFFFC.u2, (ss->*sp_365).tFFFE.u2, (ss->*sp_365).t0000.u2, out dx_1098);
	(ss->*sp_365).t0000.u2 = (uint16) 0x00;
	fn1AB8_1C32(ds, (ss->*sp_365).t0000.u0);
	struct Eq_47042 Eq_17::* sp_1001 = (struct Eq_47042 Eq_17::*) ((char *) &sp_365->t0000 + 2);
	int16 ax_433 = (int16) (ss->*((word32) bp_172 - 4));
	if (ax_433 <= 0x0C)
	{
		(ss->*((word32) bp_172 - 6)).u3 = ax_433 + 0x01;
		while (true)
		{
			struct Eq_47117 Eq_17::* sp_455 = sp_1001 - 2;
			Mem456[ss:sp_455 + 0x00:word16] = Mem440[ds:22708:word16] + Mem440[ss:bp_172 + -6:word16];
			Mem460[ss:sp_455 + -2:word16] = Mem456[ds:22712:word16] + 0x12;
			Mem474[ss:sp_455 + -4:word16] = Mem460[ds:22708:word16] + Mem460[ss:bp_172 + -6:word16];
			Mem479[ss:sp_455 + -6:word16] = Mem474[ds:22712:word16] + 0x13;
			word16 dx_1100;
			fn1AB8_1AF6(ds, (ss->*sp_455).tFFFA.u2, (ss->*sp_455).tFFFC.u2, (ss->*sp_455).tFFFE.u2, (ss->*sp_455).t0000.u2, out dx_1100);
			(ss->*sp_455).t0000.u2 = (uint16) 300;
			(ss->*sp_455).tFFFE.u2 = (uint16) 0x14;
			Eq_481 sp_500;
			sp_500.u0 = <invalid>;
			bp_172 = fn0C74_070D(ds, (ss->*sp_455).tFFFE.u2, (ss->*sp_455).t0000.u2, out ds);
			sp_1001 = (word16) sp_500 + 4;
			if (ss->*((word32) bp_172 - 6) == 0x0D)
				break;
			(ss->*((word32) bp_172 - 6)).u3 = &(ss->*((word32) bp_172 - 6)).u3->t0001.u0;
		}
	}
	Mem514[ds:22708:word16] = Mem512[ds:22708:word16] - 0x01;
	(ss->*((word32) bp_172 - 4)).u3 = 0x00;
	(ss->*((word32) bp_172 - 8)).u3 = 0x01;
	(ss->*((word32) bp_172 - 6)).u3 = 0x01;
l0C74_4CA0:
	struct Eq_47212 Eq_17::* sp_525 = sp_1001 - 2;
	(ss->*sp_525).t0000.u2 = (uint16) 300;
	(ss->*sp_525).tFFFE.u2 = (uint16) 0x14;
	Eq_17 ds_537;
	fn0C74_070D(ds, (ss->*sp_525).tFFFE.u2, (ss->*sp_525).t0000.u2, out ds_537);
	Eq_481 sp_541;
	sp_541.u0 = <invalid>;
	ss->*((word16) sp_541 + 2) = 0x0A;
	bp_39 = fn0C74_02D8(ds_537, ss->*((word16) sp_541 + 2), out ds);
	(ss->*((word32) bp_39 - 4)).u3 = &(ss->*((word32) bp_39 - 4)).u3->t0001.u0;
	Eq_481 sp_558;
	sp_558.u0 = <invalid>;
	if (ss->*((word32) bp_39 - 4) == 0x05)
	{
		(ss->*((word32) bp_39 - 4)).u3 = 0x01;
		if (Mem574[ds:0x58B0:byte] != 0x00)
		{
			ss->*sp_558 = 0x32;
			audio_write_opl3_register(ds, ss->*sp_558);
		}
	}
	else
		audio_get_soundcard_port(ds);
	if (Mem590[ds:22710:word16] <u 0x027F)
	{
		Mem595[ds:22708:word16] = Mem590[ds:22708:word16] + 0x01;
		Mem597[ds:22710:word16] = Mem595[ds:22710:word16] + 0x01;
		(ss->*((word32) bp_39 - 8)).u3 = &(ss->*((word32) bp_39 - 8)).u3->t0001.u0;
	}
	if (Mem606[ds:22710:word16] <u 0x027F)
	{
		Mem615[ss:sp_558 + 0x00:word16] = Mem606[ds:22710:word16];
		Mem618[ss:sp_558 + -2:word16] = Mem615[ds:22714:word16];
		byte dl_1101;
		if (fn1AB8_1E3C(ds, ss->*((word16) sp_558 - 2), ss->*sp_558, out dl_1101) == 0x00)
		{
			Mem635[ss:sp_558 + 0x00:word16] = Mem618[ds:22710:word16];
			Mem640[ss:sp_558 + -2:word16] = Mem635[ds:22714:word16] - 0x15;
			byte dl_1102;
			if (fn1AB8_1E3C(ds, ss->*((word16) sp_558 - 2), ss->*sp_558, out dl_1102) == 0x00)
			{
				Mem657[ss:sp_558 + 0x00:word16] = Mem640[ds:22710:word16];
				Mem662[ss:sp_558 + -2:word16] = Mem657[ds:22714:word16] + 0x01;
				byte dl_1103;
				if (fn1AB8_1E3C(ds, ss->*((word16) sp_558 - 2), ss->*sp_558, out dl_1103) != 0x00)
				{
					Mem679[ss:sp_558 + 0x00:word16] = Mem662[ds:22708:word16];
					Mem682[ss:sp_558 + -2:word16] = Mem679[ds:22712:word16];
					segptr32 es_di_687 = (*((word32) ds + 22772))[ss->*((word32) bp_39 - 4)];
					ss->*((word16) sp_558 - 4) = SLICE(es_di_687, selector, 16);
					ss->*((word16) sp_558 - 6) = (word16) es_di_687;
					ss->*((word16) sp_558 - 8) = 0x00;
					fn1AB8_13D7(ds, ss->*((word16) sp_558 + 8), ss->*((word16) sp_558 - 6), ss->*((word16) sp_558 - 2), ss->*sp_558);
l0C74_4D4F:
					sp_1001 = (word16) sp_558 + 2;
					if (ss->*((word32) bp_39 - 6) == 44)
					{
						if (ss->*((word32) bp_39 - 8) < 22)
						{
							Eq_17 ax_733 = Mem727[ds:22714:word16];
							Eq_17 ax_738 = Mem727[ds:22898:word16];
							if (false || true && ax_738 <= (word32) ax_733 + 23)
							{
								Mem789[ss:sp_558 + 0x00:word16] = Mem727[ds:22892:word16];
								Mem792[ss:sp_558 + -2:word16] = Mem789[ds:22894:word16];
								Mem795[ss:sp_558 + -4:word16] = Mem792[ds:22710:word16];
								Mem798[ss:sp_558 + -6:word16] = Mem795[ds:22714:word16];
								fn0C74_076B(ds, ss->*((word16) sp_558 - 6), ss->*((word16) sp_558 - 4), ss->*((word16) sp_558 - 2), ss->*sp_558);
								Mem812[ds:22707:byte] = 0x01;
								goto l0C74_4DA7;
							}
						}
						Mem755[ss:sp_558 + 0x00:word16] = Mem727[ds:22892:word16];
						Mem758[ss:sp_558 + -2:word16] = Mem755[ds:22894:word16];
						Mem761[ss:sp_558 + -4:word16] = Mem758[ds:0x5970:word16];
						Mem764[ss:sp_558 + -6:word16] = Mem761[ds:22898:word16];
						fn0C74_076B(ds, ss->*((word16) sp_558 - 6), ss->*((word16) sp_558 - 4), ss->*((word16) sp_558 - 2), ss->*sp_558);
						goto l0C74_4DA7;
					}
					(ss->*((word32) bp_39 - 6)).u3 = &(ss->*((word32) bp_39 - 6)).u3->t0001.u0;
					goto l0C74_4CA0;
				}
			}
		}
	}
	Mem711[ds:22708:word16] = Mem709[ds:22708:word16] - 0x01;
	Mem713[ds:22710:word16] = Mem711[ds:22710:word16] - 0x01;
	(ss->*((word32) bp_39 - 8)).u3 = ss->*((word32) bp_39 - 8) - 0x01;
	audio_get_soundcard_port(ds);
	goto l0C74_4D4F;
}
