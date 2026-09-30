// 0800:391E: Register Eq_17 fn0800_391E(Register Eq_17 ds)
// Called from:
//      fn0800_3D9D
Eq_17 fn0800_391E(Eq_17 ds)
{
	byte ch_996;
	Eq_17 cs;
	Eq_17 ss;
	<unknown> Eq_17::* fp;
	fn1EDA_04F5(SEQ(cs, 0x38E0), SEQ(ss, fp - 0x0112));
	int16 dx_42 = fn1EDA_0565(ds, SEQ(ss, fp - 0x0112));
	if (fn1EDA_04A2(ds) == 0x00)
	{
		while (fn1E78_02FB(ds) != 0x00)
			fn1E78_030D(dx_42, ds, ss, out dx_42);
		fn1AB8_10CE(ds);
		struct Eq_15296 Eq_17::* bp_85;
		Eq_17 ds_89;
		fn1206_0066(ds, out bp_85, out ds_89);
		Eq_481 sp_93;
		sp_93.u0 = <invalid>;
		(ss->*((word16) sp_93 - 2)).u1 = (ss->*bp_85).tFFFE.u2;
		(ss->*((word16) sp_93 - 4)).u1 = (ss->*bp_85).tFFFA.u2;
		(ss->*((word16) sp_93 - 6)).u1 = (ss->*bp_85).tFFFC.u2;
		(ss->*((word16) sp_93 - 8)).u1 = (ss->*bp_85).tFFF8.u2;
		fn0800_1315(ds_89, ss->*((word16) sp_93 - 8), ss->*((word16) sp_93 - 6), ss->*((word16) sp_93 - 4), ss->*((word16) sp_93 - 2));
		ss->*((word16) sp_93 - 2) = (ss->*bp_85).tFFFE.u2 + 0x08;
		ss->*((word16) sp_93 - 4) = (ss->*bp_85).tFFFA.u2 + 0x0A;
		ss->*((word16) sp_93 - 6) = (ss->*bp_85).tFFFC.u2 - 0x08;
		ss->*((word16) sp_93 - 8) = (ss->*bp_85).tFFF8.u2 - 0x32;
		fn0800_36E6(ds_89, ss->*((word16) sp_93 - 8), ss->*((word16) sp_93 - 6), ss->*((word16) sp_93 - 4), ss->*((word16) sp_93 - 2));
		ss->*((word16) sp_93 - 2) = 0x01;
		ss->*((word16) sp_93 - 4) = 0x07;
		fn1AB8_1175(ds_89, ss->*((word16) sp_93 - 4), ss->*((word16) sp_93 - 2));
		ss->*((word16) sp_93 - 2) = (ss->*bp_85).tFFFE.u2 + 0x08;
		ss->*((word16) sp_93 - 4) = (ss->*bp_85).tFFFA.u2 + 0x0D;
		ss->*((word16) sp_93 - 6) = (ss->*bp_85).tFFFC.u2 - 0x09;
		ss->*((word16) sp_93 - 8) = (ss->*bp_85).tFFF8.u2 - 0x34;
		fn1AB8_1B3E(ds_89, ss->*((word16) sp_93 - 8), ss->*((word16) sp_93 - 6), ss->*((word16) sp_93 - 4), ss->*((word16) sp_93 - 2));
		(ss->*bp_85).wFFF6 = (ss->*bp_85).tFFFE.u2 + 0x30;
		(ss->*bp_85).wFFF4 = (ss->*bp_85).tFFFA.u2 + 0x0C;
		ss->*((word16) sp_93 - 2) = 0x01;
		ss->*((word16) sp_93 - 4) = 0xF0;
		ss->*((word16) sp_93 - 6) = 334;
		ss->*((word16) sp_93 - 8) = cs;
		ss->*((word16) sp_93 - 0x0A) = 0x38E8;
		ss->*((word16) sp_93 - 0x0C) = 0x00;
		word16 dx_982;
		word16 bp_983;
		Eq_17 ds_207;
		fn0800_19E1(ds_89, ss->*((word16) sp_93 - 0x0A), out dx_982, out bp_983, out ds_207);
		Eq_481 sp_211;
		sp_211.u0 = <invalid>;
		ss->*((word16) sp_211 + 0x0A) = 0x02;
		ss->*((word16) sp_211 + 8) = 400;
		ss->*((word16) sp_211 + 6) = 334;
		ss->*((word16) sp_211 + 4) = cs;
		ss->*((word16) sp_211 + 2) = 0x38F4;
		ss->*sp_211 = 0x00;
		word16 dx_984;
		word16 bp_985;
		Eq_17 ds_236;
		fn0800_19E1(ds_207, ss->*((word16) sp_211 + 2), out dx_984, out bp_985, out ds_236);
		Eq_17 ds_479;
		byte ch_760;
		struct Eq_16072 Eq_17::* sp_754;
		byte ch_1000;
		do
		{
			struct Eq_15600 Eq_17::* bp_250;
			Eq_17 ds_254;
			fn1206_0066(ds_236, out bp_250, out ds_254);
			Eq_481 sp_258;
			sp_258.u0 = <invalid>;
			ss->*((word16) sp_258 - 2) = 0x01;
			ss->*((word16) sp_258 - 4) = 0x07;
			fn1AB8_1175(ds_254, ss->*((word16) sp_258 - 4), ss->*((word16) sp_258 - 2));
			ss->*((word16) sp_258 - 2) = (ss->*bp_250).wFFFE + 0x08;
			ss->*((word16) sp_258 - 4) = (ss->*bp_250).wFFFA + 0x0D;
			ss->*((word16) sp_258 - 6) = (ss->*bp_250).wFFFC - 0x09;
			ss->*((word16) sp_258 - 8) = (ss->*bp_250).wFFF8 - 0x34;
			fn1AB8_1B3E(ds_254, ss->*((word16) sp_258 - 8), ss->*((word16) sp_258 - 6), ss->*((word16) sp_258 - 4), ss->*((word16) sp_258 - 2));
			Mem304[ss:sp_258 + -2:word16] = CONVERT(Mem290[ds_254:0x4D06:byte], uint8, uint16);
			fn1AB8_1C32(ds_254, ss->*((word16) sp_258 - 2));
			ss->*((word16) sp_258 - 2) = 0x00;
			ss->*((word16) sp_258 - 4) = 0x01;
			fn1AB8_14F4(ds_254, ss->*((word16) sp_258 - 4), ss->*((word16) sp_258 - 2));
			ss->*((word16) sp_258 - 2) = 0x02;
			ss->*((word16) sp_258 - 4) = 0x00;
			ss->*((word16) sp_258 - 6) = 0x04;
			Eq_17 ds_334;
			fn1AB8_1536(ds_254, ss->*((word16) sp_258 - 6), ss->*((word16) sp_258 - 4), ss->*((word16) sp_258 - 2), out ds_334);
			(ss->*bp_250).bFFF1 = 0x01;
			byte ch_412;
			while (true)
			{
				ss->*((word16) sp_258 - 2) = ss;
				ss->*((word16) sp_258 - 4) = bp_250 - 0x0110;
				ss->*((word16) sp_258 - 6) = ss;
				ss->*((word16) sp_258 - 8) = bp_250 - 0x0210;
				ss->*((word16) sp_258 - 0x0A) = 0xFF;
				byte ch_987;
				fn1EDA_04A9(fn1EDA_081A(fn1EDA_0896(ds_334, ss->*((word16) sp_258 - 0x0A), ss->*((word16) sp_258 - 8), ss->*((word16) sp_258 - 4)), ds_334, ss->*((word16) sp_258 - 4)), ss->*((word16) sp_258 + 0x0000FFFC), ss->*((word16) sp_258 - 2), out ch_987, out ds_334);
				(ss->*((word16) sp_258 - 2)).u1 = (ss->*bp_250).tFFF6.u2;
				ss->*((word16) sp_258 - 4) = (uint16) (ss->*bp_250).bFFF1 *s 0x0D + (ss->*bp_250).wFFF4;
				ss->*((word16) sp_258 - 6) = ss;
				ss->*((word16) sp_258 - 8) = bp_250 - 0x0210;
				fn1AB8_1D82(ds_334, ss->*((word16) sp_258 - 8), ss->*((word16) sp_258 - 4), ss->*((word16) sp_258 - 2), out ch_412);
				if ((ss->*bp_250).bFFF1 == 0x14)
					break;
				++(ss->*bp_250).bFFF1;
			}
			ss->*((word16) sp_258 - 2) = ss;
			ss->*((word16) sp_258 - 4) = bp_250 - 0x0110;
			byte ch_989;
			Eq_17 ds_448;
			int16 dx_480;
			Eq_481 sp_489;
			if ((byte) fn1EDA_04A9(fn1EDA_0918(ch_412, ds_334, ss->*((word16) sp_258 - 4)), ss->*((word16) sp_258 + 0x0000FFFC), ss->*((word16) sp_258 - 2), out ch_989, out ds_448) != 0x00)
			{
				Mem493[ss:sp_258 + -2:word16] = Mem430[ds_448:0x53E4:word16] - 0x04;
				Mem497[ss:sp_258 + -4:word16] = Mem493[ds_448:0x53F2:word16] - 0x01;
				Mem501[ss:sp_258 + -6:word16] = Mem497[ds_448:0x5400:word16] + 0x04;
				Mem506[ss:sp_258 + -8:word16] = Mem501[ds_448:0x540E:word16] + 0x03;
				fn0800_005A(ds_448, ss->*((word16) sp_258 - 8), ss->*((word16) sp_258 - 6), ss->*((word16) sp_258 - 4), ss->*((word16) sp_258 - 2));
				byte ch_991;
				word16 bp_992;
				fn1206_0038(ds_448, out ch_991, out dx_480, out bp_992, out ds_479);
				sp_489.u0 = <invalid>;
			}
			else
			{
				ss->*((word16) sp_258 - 2) = 0x01;
				ss->*((word16) sp_258 - 4) = 0xF0;
				ss->*((word16) sp_258 - 6) = 334;
				ss->*((word16) sp_258 - 8) = cs;
				ss->*((word16) sp_258 - 0x0A) = 0x38E8;
				ss->*((word16) sp_258 - 0x0C) = 0x00;
				word16 bp_990;
				fn0800_19E1(ds_448, ss->*((word16) sp_258 - 0x0A), out dx_480, out bp_990, out ds_479);
				Eq_481 sp_483;
				sp_483.u0 = <invalid>;
				sp_489 = (word16) sp_483 + 0x0C;
			}
			Eq_17 bp_604;
			struct Eq_15937 Eq_17::* sp_646;
			selector es_998;
			do
			{
				Mem532[ds_479:0x53D2:byte] = ~0x00;
				if (fn1E78_02FB(ds_479) != 0x00)
				{
					int16 dx_550;
					Mem557[ds_479:0x53D2:byte] = SLICE(fn1E78_030D(dx_480, ds_479, ss->*((word16) sp_489 - 2), out dx_550), byte, 0);
					if (Mem557[ds_479:0x53D2:byte] == 0x00)
						Mem570[ds_479:0x53D2:byte] = SLICE(fn1E78_030D(dx_550, ds_479, ss->*((word16) sp_489 - 2), out dx_550), byte, 0);
					byte ah_573;
					while (true)
					{
						ah_573 = <invalid>;
						if (fn1E78_02FB(ds_479) == 0x00)
							break;
						fn1E78_030D(dx_550, ds_479, ss->*((word16) sp_489 - 2), out dx_550);
					}
					struct Eq_16000 Eq_17::* sp_586 = sp_489 - 2;
					Mem589[ss:sp_586 + 0x00:word16] = SEQ(ah_573, Mem583[ds_479:0x53D2:byte]);
					Mem597[ds_479:0x53D2:byte] = fn1EDA_1384((ss->*sp_586).t0000.u0);
				}
				ss->*((word16) sp_489 - 2) = 0x00;
				Eq_481 cx_606;
				cx_606.u0 = <invalid>;
				Eq_481 sp_612;
				sp_612.u0 = <invalid>;
				byte ch_652 = SLICE(cx_606, byte, 8);
				word16 sp_617 = (word16) sp_612 + 2;
				byte ch_993;
				word16 dx_994;
				Eq_17 ds_608;
				if ((byte) fn1206_015B(ds_479, out ch_993, out dx_994, out bp_604, out ds_608) != 0x00)
				{
					ss->*sp_612 = bp_604;
					byte ch_997;
					Mem642[ds_608:0x53D2:byte] = fn0800_3850(ds_608, out ch_997, out bp_604, out ds_608);
					Eq_481 cx_629;
					cx_629.u0 = <invalid>;
					Eq_481 sp_635;
					sp_635.u0 = <invalid>;
					ch_652 = SLICE(cx_629, byte, 8);
					sp_617 = (word16) sp_635 + 2;
				}
				sp_646 = sp_617 - 2;
				(ss->*sp_646).t0000.u2 = (uint16) ss;
				(ss->*sp_646).tFFFE.u2 = (uint16) (bp_604 - 0x0110);
				ui32 dx_ax_995 = fn1EDA_04A9(fn1EDA_0918(ch_652, ds_608, (ss->*sp_646).tFFFE.u3), (ss->*sp_646).tFFFE.u2, (ss->*sp_646).t0000.u2, out ch_996, out ds_479);
				word16 ax_673 = (word16) dx_ax_995;
				Eq_481 cx_675;
				cx_675.u0 = <invalid>;
				dx_480 = SLICE(dx_ax_995, word16, 16);
				byte ah_698 = SLICE(ax_673, byte, 8);
				ch_760 = SLICE(cx_675, byte, 8);
				if ((byte) ax_673 != 0x00 && Mem650[ds_479:0x53D2:byte] == 0x53)
					Mem691[ds_479:0x53D2:byte] = 0x00;
				Mem701[ss:sp_646 + 0x00:word16] = SEQ(ah_698, Mem693[ds_479:0x53D2:byte]);
				(ss->*sp_646).tFFFE.u2 = (uint16) cs;
				(ss->*sp_646).tFFFC.u2 = (uint16) 0x38FE;
				sp_489 = (char *) &sp_646->t0000 + 2;
			} while (!fn1EDA_0CD4((ss->*sp_646).tFFFC.u3, (ss->*sp_646).t0000.u0, out es_998));
			if (Mem707[ds_479:0x53D2:byte] == 0x53)
			{
				(ss->*sp_646).t0000.u2 = (uint16) 0x01;
				(ss->*sp_646).tFFFE.u2 = (uint16) 0xF0;
				(ss->*sp_646).tFFFC.u2 = (uint16) 334;
				(ss->*sp_646).tFFFA.u2 = (uint16) cs;
				(ss->*sp_646).tFFF8.u2 = (uint16) 0x38E8;
				(ss->*sp_646).wFFF6 = 0x01;
				word16 dx_1001;
				fn0800_19E1(ds_479, (ss->*sp_646).tFFF8.u3, out dx_1001, out bp_604, out ds_479);
				Eq_481 sp_743;
				sp_743.u0 = <invalid>;
				ch_760 = 0x00;
				sp_489 = (word16) sp_743 + 0x0C;
			}
			sp_754 = sp_489 - 2;
			(ss->*sp_754).t0000.u2 = (uint16) ss;
			(ss->*sp_754).tFFFE.u2 = (uint16) (bp_604 - 0x0110);
		} while ((byte) fn1EDA_04A9(fn1EDA_0918(ch_760, ds_479, (ss->*sp_754).tFFFE.u3), (ss->*sp_754).tFFFE.u2, (ss->*sp_754).t0000.u2, out ch_1000, out ds_236) == 0x00 && Mem758[ds_236:0x53D2:byte] != 0x46);
		(ss->*sp_754).t0000.u2 = (uint16) 0x02;
		(ss->*sp_754).tFFFE.u2 = (uint16) 400;
		(ss->*sp_754).tFFFC.u2 = (uint16) 334;
		(ss->*sp_754).tFFFA.u2 = (uint16) cs;
		(ss->*sp_754).tFFF8.u2 = (uint16) 0x38F4;
		(ss->*sp_754).wFFF6 = 0x01;
		word16 dx_1002;
		word16 bp_815;
		Eq_17 ds_819;
		fn0800_19E1(ds_236, (ss->*sp_754).tFFF8.u3, out dx_1002, out bp_815, out ds_819);
		Eq_481 sp_823;
		sp_823.u0 = <invalid>;
		ss->*((word16) sp_823 + 0x0A) = ss;
		ss->*((word16) sp_823 + 8) = bp_815 - 0x0110;
		fn1EDA_05BF(ds_819, ss->*((word16) sp_823 + 8));
		byte ch_1005;
		Eq_17 ds_847;
		fn1EDA_04A9(ds_819, ss->*((word16) sp_823 + 8), ss->*((word16) sp_823 + 0x0A), out ch_1005, out ds_847);
		struct Eq_16221 Eq_17::* bp_855;
		fn1206_0066(ds_847, out bp_855, out ds);
		Eq_481 sp_863;
		sp_863.u0 = <invalid>;
		ss->*((word16) sp_863 - 2) = 0x96;
		word16 dx_1006;
		fn1E78_029C(ds, ss->*((word16) sp_863 - 2), out dx_1006);
		ss->*((word16) sp_863 - 2) = (ss->*bp_855).wFFFE - 0x14;
		ss->*((word16) sp_863 - 4) = (ss->*bp_855).wFFFA - 0x0C;
		ss->*((word16) sp_863 - 6) = (ss->*bp_855).wFFFC + 0x04;
		ss->*((word16) sp_863 - 8) = (ss->*bp_855).wFFF8 + 0x04;
		fn0800_0024(ds, ss->*((word16) sp_863 - 8), ss->*((word16) sp_863 - 6), ss->*((word16) sp_863 - 4), ss->*((word16) sp_863 - 2));
	}
	return ds;
}
