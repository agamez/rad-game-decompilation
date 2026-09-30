// 0800:2C0C: Register Eq_526 fn0800_2C0C(Register int16 dx, Register Eq_17 ds, Register out Eq_17 dsOut)
// Called from:
//      fn0800_3D9D
Eq_526 fn0800_2C0C(int16 dx, Eq_17 ds, union Eq_17 & dsOut)
{
	while (fn1E78_02FB(ds) != 0x00)
	{
		Eq_17 wLoc0106;
		fn1E78_030D(dx, ds, wLoc0106, out dx);
	}
	struct Eq_10496 Eq_17::* bp_1005;
	Eq_17 ds_1065;
	Eq_17 ss;
	while (true)
	{
		fn1206_0066(ds, out bp_1005, out ds_1065);
		fn13E2_003B(ds_1065);
		fn0800_01FE(ds_1065);
		Eq_481 sp_33;
		sp_33.u0 = <invalid>;
		ss->*((word16) sp_33 - 2) = ds_1065;
		ss->*((word16) sp_33 - 4) = 0x5ECE;
		Eq_17 cs;
		ss->*((word16) sp_33 - 6) = cs;
		ss->*((word16) sp_33 - 8) = 11075;
		word16 ax_2262;
		word16 dx_2263;
		if (!fn1EDA_0B24(ss->*((word16) sp_33 - 8), ss->*((word16) sp_33 - 4), out ax_2262, out dx_2263))
			break;
		ss->*((word16) sp_33 - 2) = ds_1065;
		ss->*((word16) sp_33 - 4) = 0x5ECE;
		ss->*((word16) sp_33 - 6) = cs;
		ss->*((word16) sp_33 - 8) = 11082;
		Eq_481 sp_108 = sp_33;
		word16 ax_2264;
		word16 dx_2265;
		if (fn1EDA_0B24(ss->*((word16) sp_33 - 8), ss->*((word16) sp_33 - 4), out ax_2264, out dx_2265))
		{
			ss->*((word16) sp_33 - 2) = ss;
			ss->*((word16) sp_33 - 4) = bp_1005 - 0x0102;
			ss->*((word16) sp_33 - 6) = cs;
			ss->*((word16) sp_33 - 8) = 11087;
			fn1EDA_04F5(ss->*((word16) sp_33 - 8), ss->*((word16) sp_33 - 4));
			ss->*((word16) sp_33 - 2) = ss;
			ss->*((word16) sp_33 - 4) = bp_1005 - 0x0102;
			fn1EDA_056A(ds_1065, ss->*((word16) sp_33 - 4));
			ss->*((word16) sp_33 - 6) = ss;
			ss->*((word16) sp_33 - 8) = bp_1005 - 0x0102;
			ss->*((word16) sp_33 - 0x0A) = ds_1065;
			ss->*((word16) sp_33 - 0x0C) = 0x5ECE;
			ss->*((word16) sp_33 - 0x0E) = 0x00;
			Eq_481 cx_162;
			fn1EDA_08CE(ds_1065, ss->*((word16) sp_33 - 0x0E), ss->*((word16) sp_33 - 0x0C), ss->*((word16) sp_33 - 8), out cx_162);
			ds_1065 = fn1EDA_0848(0x00, cx_162, ds_1065, ss->*((word16) sp_33 - 8));
			ss->*((word16) sp_33 - 6) = ss;
			ss->*((word16) sp_33 - 8) = bp_1005 - 0x0102;
			fn1EDA_05BF(ds_1065, ss->*((word16) sp_33 - 8));
			sp_108 = sp_33 - 0x04;
			if (fn1EDA_04A2(ds_1065) != 0x00)
			{
				Mem210[ss:sp_33 + -6:word16] = Mem188[ds_1065:47276:word16];
				word16 dx_2269;
				fn1E78_016B(ds_1065, ss->*((word16) sp_33 - 6), out dx_2269);
				ss->*((word16) sp_33 - 6) = ds_1065;
				ss->*((word16) sp_33 - 8) = ~0x4643;
				ss->*((word16) sp_33 - 0x0A) = cs;
				ss->*((word16) sp_33 - 0x0C) = 11095;
				ss->*((word16) sp_33 - 0x0E) = 0x00;
				Eq_481 cx_238;
				fn1EDA_08CE(ds_1065, ss->*((word16) sp_33 - 0x0E), ss->*((word16) sp_33 - 0x0C), ss->*((word16) sp_33 - 8), out cx_238);
				byte ch_2271;
				Eq_17 ds_263;
				fn1EDA_04A9(fn1EDA_0848(0x00, cx_238, ds_1065, ss->*((word16) sp_33 - 8)), ss->*((word16) sp_33 + 0x0000FFF8), ss->*((word16) sp_33 - 6), out ch_2271, out ds_263);
				ss->*((word16) sp_33 - 6) = ds_263;
				ss->*((word16) sp_33 - 8) = ~0x4643;
				ss->*((word16) sp_33 - 0x0A) = cs;
				ss->*((word16) sp_33 - 0x0C) = 11138;
				ss->*((word16) sp_33 - 0x0E) = 0x00;
				Eq_481 cx_287;
				fn1EDA_08CE(ds_263, ss->*((word16) sp_33 - 0x0E), ss->*((word16) sp_33 - 0x0C), ss->*((word16) sp_33 - 8), out cx_287);
				byte ch_2273;
				Eq_17 ds_312;
				fn1EDA_04A9(fn1EDA_0848(0x00, cx_287, ds_263, ss->*((word16) sp_33 - 8)), ss->*((word16) sp_33 + 0x0000FFF8), ss->*((word16) sp_33 - 6), out ch_2273, out ds_312);
				ss->*((word16) sp_33 - 6) = ds_312;
				ss->*((word16) sp_33 - 8) = ~0x4643;
				ss->*((word16) sp_33 - 0x0A) = cs;
				ss->*((word16) sp_33 - 0x0C) = 11183;
				ss->*((word16) sp_33 - 0x0E) = 0x00;
				Eq_481 cx_336;
				fn1EDA_08CE(ds_312, ss->*((word16) sp_33 - 0x0E), ss->*((word16) sp_33 - 0x0C), ss->*((word16) sp_33 - 8), out cx_336);
				byte ch_2275;
				Eq_17 ds_361;
				fn1EDA_04A9(fn1EDA_0848(0x00, cx_336, ds_312, ss->*((word16) sp_33 - 8)), ss->*((word16) sp_33 + 0x0000FFF8), ss->*((word16) sp_33 - 6), out ch_2275, out ds_361);
				ss->*((word16) sp_33 - 6) = ds_361;
				ss->*((word16) sp_33 - 8) = ~0x4643;
				ss->*((word16) sp_33 - 0x0A) = cs;
				ss->*((word16) sp_33 - 0x0C) = 11226;
				ss->*((word16) sp_33 - 0x0E) = 0x00;
				Eq_481 cx_385;
				fn1EDA_08CE(ds_361, ss->*((word16) sp_33 - 0x0E), ss->*((word16) sp_33 - 0x0C), ss->*((word16) sp_33 - 8), out cx_385);
				byte ch_2277;
				Eq_17 ds_410;
				word16 dx_2278;
				fn1E78_030D(SLICE(fn1EDA_04A9(fn1EDA_0848(0x00, cx_385, ds_361, ss->*((word16) sp_33 - 8)), ss->*((word16) sp_33 + 0x0000FFF8), ss->*((word16) sp_33 - 6), out ch_2277, out ds_410), word16, 16), ds_410, ss->*((word16) sp_33 - 6), out dx_2278);
				sp_108 = sp_33 - 0x04;
				ds_1065 = fn1EDA_00E9(0x00);
			}
		}
		struct Eq_10724 Eq_17::* sp_441 = sp_108 - 2;
		(ss->*sp_441).t0000.u2 = (uint16) 0x00;
		(ss->*sp_441).tFFFE.u2 = (uint16) 0x00;
		(ss->*sp_441).tFFFC.u2 = (uint16) 0x01;
		Eq_17 ds_457;
		fn1AB8_1536(ds_1065, (ss->*sp_441).tFFFC.u2, (ss->*sp_441).tFFFE.u2, (ss->*sp_441).t0000.u2, out ds_457);
		(ss->*sp_441).t0000.u2 = (uint16) 0x01;
		(ss->*sp_441).tFFFE.u2 = (uint16) 0x01;
		fn1AB8_14F4(ds_457, (ss->*sp_441).tFFFE.u2, (ss->*sp_441).t0000.u2);
		(ss->*sp_441).t0000.u2 = (uint16) 0x0F;
		(ss->*sp_441).tFFFE.u2 = (uint16) 388;
		(ss->*sp_441).tFFFC.u2 = (uint16) 0x0114;
		(ss->*sp_441).tFFFA.u2 = (uint16) 399;
		fn0800_005A(ds_457, (ss->*sp_441).tFFFA.u2, (ss->*sp_441).tFFFC.u2, (ss->*sp_441).tFFFE.u2, (ss->*sp_441).t0000.u2);
		(ss->*sp_441).t0000.u2 = (uint16) 0x08;
		fn1AB8_1C32(ds_457, (ss->*sp_441).t0000.u0);
		(ss->*sp_441).t0000.u2 = (uint16) ds_457;
		(ss->*sp_441).tFFFE.u2 = (uint16) 0x5ECE;
		(ss->*sp_441).tFFFC.u2 = (uint16) cs;
		(ss->*sp_441).tFFFA.u2 = (uint16) 11082;
		word16 ax_2267;
		word16 dx_2268;
		if (!fn1EDA_0B24((ss->*sp_441).tFFFA.u3, (ss->*sp_441).tFFFE.u3, out ax_2267, out dx_2268))
		{
			(ss->*sp_441).t0000.u2 = (uint16) 0x93;
			(ss->*sp_441).tFFFE.u2 = (uint16) 393;
			(ss->*sp_441).tFFFC.u2 = (uint16) ds_457;
			(ss->*sp_441).tFFFA.u2 = (uint16) 0x5CBB;
			byte ch_2280;
			fn1AB8_1D82(ds_457, (ss->*sp_441).tFFFA.u3, (ss->*sp_441).tFFFE.u2, (ss->*sp_441).t0000.u2, out ch_2280);
		}
		else
		{
			(ss->*sp_441).t0000.u2 = (uint16) 0x93;
			(ss->*sp_441).tFFFE.u2 = (uint16) 393;
			(ss->*sp_441).tFFFC.u2 = (uint16) cs;
			(ss->*sp_441).tFFFA.u2 = (uint16) 11245;
			byte ch_2279;
			fn1AB8_1D82(ds_457, (ss->*sp_441).tFFFA.u3, (ss->*sp_441).tFFFE.u2, (ss->*sp_441).t0000.u2, out ch_2279);
		}
		struct Eq_11198 Eq_17::* sp_564 = sp_108 - 2;
		(ss->*sp_564).t0000.u2 = (uint16) 0x0A;
		fn1AB8_1C32(ds_457, (ss->*sp_564).t0000.u0);
		(ss->*sp_564).t0000.u2 = (uint16) ds_457;
		(ss->*sp_564).tFFFE.u2 = (uint16) 0x5ECE;
		(ss->*sp_564).tFFFC.u2 = (uint16) cs;
		(ss->*sp_564).tFFFA.u2 = (uint16) 11082;
		word16 ax_2281;
		word16 dx_2282;
		if (!fn1EDA_0B24((ss->*sp_564).tFFFA.u3, (ss->*sp_564).tFFFE.u3, out ax_2281, out dx_2282))
		{
			(ss->*sp_564).t0000.u2 = (uint16) 0x94;
			(ss->*sp_564).tFFFE.u2 = (uint16) 0x018A;
			(ss->*sp_564).tFFFC.u2 = (uint16) ds_457;
			(ss->*sp_564).tFFFA.u2 = (uint16) 0x5CBB;
			byte ch_2284;
			fn1AB8_1D82(ds_457, (ss->*sp_564).tFFFA.u3, (ss->*sp_564).tFFFE.u2, (ss->*sp_564).t0000.u2, out ch_2284);
		}
		else
		{
			(ss->*sp_564).t0000.u2 = (uint16) 0x94;
			(ss->*sp_564).tFFFE.u2 = (uint16) 0x018A;
			(ss->*sp_564).tFFFC.u2 = (uint16) cs;
			(ss->*sp_564).tFFFA.u2 = (uint16) 11245;
			byte ch_2283;
			fn1AB8_1D82(ds_457, (ss->*sp_564).tFFFA.u3, (ss->*sp_564).tFFFE.u2, (ss->*sp_564).t0000.u2, out ch_2283);
		}
		Eq_17 ds_644;
		fn0800_04E3(ds_457, out ds_644);
		struct Eq_11318 Eq_17::* sp_655 = sp_108 - 2;
		(ss->*sp_655).t0000.u2 = (uint16) ds_644;
		(ss->*sp_655).tFFFE.u2 = (uint16) 0x5ECE;
		(ss->*sp_655).tFFFC.u2 = (uint16) ds_644;
		(ss->*sp_655).tFFFA.u2 = (uint16) 24278;
		(ss->*sp_655).tFFF8.u2 = (uint16) 0x06;
		word16 dx_2285;
		fn1EDA_0A39((ss->*sp_655).t0008.u0, (ss->*sp_655).tFFFA.u3, (ss->*sp_655).tFFFE.u3, out dx_2285);
		Eq_17 ds_697 = fn0800_0BEC(fn0800_0619(ds_644));
		fn13E2_00FB(ds_697);
		Eq_481 sp_701;
		sp_701.u0 = <invalid>;
		ss->*((word16) sp_701 - 2) = 0x08;
		ss->*((word16) sp_701 - 4) = 0x00;
		fn1AB8_1342(ds_697, ss->*((word16) sp_701 - 4), ss->*((word16) sp_701 - 2));
		word16 bp_2286;
		Eq_17 ds_735;
		fn1206_0066(ds_697, out bp_2286, out ds_735);
		Eq_481 sp_739;
		sp_739.u0 = <invalid>;
		Mem748[ss:sp_739 + -2:word16] = CONVERT(Mem720[ds_735:0x53D9:byte], uint8, uint16);
		Eq_17 ax_749 = fn0800_04CC(ss->*((word16) sp_739 - 2));
		ss->*((word16) sp_739 - 2) = ax_749;
		Mem761[ss:sp_739 + -4:word16] = SEQ(SLICE(ax_749, byte, 8), Mem756[ds_735:21466:byte]);
		ss->*((word16) sp_739 - 4) = fn0800_04CC(ss->*((word16) sp_739 - 4));
		byte ch_2287;
		word16 dx_2288;
		fn1206_0038(fn0C74_06B7(ds_735, ss->*((word16) sp_739 - 4), ss->*((word16) sp_739 - 2)), out ch_2287, out dx_2288, out bp_1005, out ds_1065);
		Eq_481 sp_794;
		sp_794.u0 = <invalid>;
		ss->*((word16) sp_794 - 2) = ds_1065;
		ss->*((word16) sp_794 - 4) = 0x5ECE;
		ss->*((word16) sp_794 - 6) = cs;
		ss->*((word16) sp_794 - 8) = 11082;
		Eq_481 sp_822 = sp_794;
		word16 ax_2289;
		word16 dx_2290;
		if (!fn1EDA_0B24(ss->*((word16) sp_794 - 8), ss->*((word16) sp_794 - 4), out ax_2289, out dx_2290))
		{
			ss->*((word16) sp_794 - 2) = 11;
			word16 bp_2291;
			Eq_17 ds_2333;
			fn0800_09C2(ds_1065, ss->*((word16) sp_794 - 2), out bp_2291, out ds_2333);
			Eq_481 sp_834;
			sp_834.u0 = <invalid>;
			struct Eq_11540 Eq_17::* sp_840 = (word16) sp_834 + 2;
			while (fn1E78_02FB(ds_2333) == 0x00)
			{
				(ss->*sp_840).wFFFE = 0x00;
				Eq_481 sp_866;
				sp_866.u0 = <invalid>;
				sp_840 = (word16) sp_866 + 2;
				byte ch_2292;
				word16 dx_2293;
				word16 bp_2294;
				if ((byte) fn1206_015B(ds_2333, out ch_2292, out dx_2293, out bp_2294, out ds_2333) != 0x00)
					break;
			}
			union Eq_17 Eq_17::* sp_879 = sp_840 - 2;
			(ss->*sp_879).u2 = (uint16) 0x02;
			fn0800_09C2(ds_2333, (ss->*sp_879).u0, out bp_1005, out ds_1065);
			Eq_481 sp_894;
			sp_894.u0 = <invalid>;
			sp_822 = (word16) sp_894 + 2;
		}
		Eq_17 ax_915 = CONVERT(Mem902[ds_1065:0x53DD:byte], uint8, uint16) *s 0x3C;
		struct Eq_11492 Eq_17::* sp_910 = sp_822 - 2;
		(ss->*sp_910).t0000.u2 = (uint16) 0x00;
		(ss->*sp_910).tFFFE.u2 = (uint16) ax_915;
		int16 dx_1020;
		fn0800_00C1(ds_1065, (ss->*sp_910).tFFFE.u2, (ss->*sp_910).t0000.u2, out dx_1020);
		(ss->*bp_1005).bFFFF = 0x01;
		Eq_481 sp_1013 = (char *) &sp_910->t0000 + 2;
		do
		{
			if (fn1E78_02FB(ds_1065) == 0x00)
			{
				ss->*((word16) sp_1013 - 2) = 0x00;
				Eq_481 sp_954;
				sp_954.u0 = <invalid>;
				sp_1013 = (word16) sp_954 + 2;
				byte ch_2295;
				if ((byte) fn1206_015B(ds_1065, out ch_2295, out dx_1020, out bp_1005, out ds_1065) != 0x00)
					goto l0800_2E71;
				ss->*sp_954 = ds_1065;
				ss->*((word16) sp_954 - 2) = 0x5ECE;
				ss->*((word16) sp_954 - 4) = cs;
				ss->*((word16) sp_954 - 6) = 11082;
				sp_1013 = (word16) sp_954 + 2;
				word16 ax_2296;
				if (!fn1EDA_0B24(ss->*((word16) sp_954 - 6), ss->*((word16) sp_954 - 2), out ax_2296, out dx_1020))
					goto l0800_3087;
			}
l0800_2E71:
			if (fn1E78_02FB(ds_1065) != 0x00)
			{
				int16 dx_1028;
				Mem1035[ds_1065:0x53D2:byte] = SLICE(fn1E78_030D(dx_1020, ds_1065, ss->*((word16) sp_1013 - 2), out dx_1028), byte, 0);
				if (Mem1035[ds_1065:0x53D2:byte] == 0x00)
					Mem1048[ds_1065:0x53D2:byte] = SLICE(fn1E78_030D(dx_1028, ds_1065, ss->*((word16) sp_1013 - 2), out dx_1028), byte, 0);
				while (fn1E78_02FB(ds_1065) != 0x00)
					fn1E78_030D(dx_1028, ds_1065, ss->*((word16) sp_1013 - 2), out dx_1028);
			}
			else
			{
				Eq_17 ds_1009;
				Mem1019[ds_1009:0x53D2:byte] = SLICE(fn0800_031B(ds_1065, out bp_1005, out ds_1009), byte, 0);
				sp_1013.u0 = <invalid>;
				ds_1065 = ds_1009;
			}
			struct Eq_11773 Eq_17::* sp_1064 = sp_1013 - 2;
			(ss->*sp_1064).t0000.u2 = (uint16) ds_1065;
			(ss->*sp_1064).tFFFE.u2 = (uint16) 0x5ECE;
			(ss->*sp_1064).tFFFC.u2 = (uint16) cs;
			(ss->*sp_1064).tFFFA.u2 = (uint16) 11082;
			word16 ax_2299;
			word16 dx_2300;
			if (!fn1EDA_0B24((ss->*sp_1064).tFFFA.u3, (ss->*sp_1064).tFFFE.u3, out ax_2299, out dx_2300))
			{
				if (Mem1078[ds_1065:0x53D2:byte] != 0x1B)
					Mem1105[ds_1065:0x53D2:byte] = Mem1078[ds_1065:CONVERT(Mem1078[ss:bp_1005 + -1:byte], uint8, uint16) + 0x5CBB:byte];
				++(ss->*bp_1005).bFFFF;
			}
			Eq_526 al_1115 = Mem1114[ds_1065:0x53D2:byte];
			switch (al_1115)
			{
			case 0x3B:
				(ss->*sp_1064).t0000.u2 = (uint16) 0x0E;
				word16 bp_2302;
				Eq_17 ds_1839;
				fn0800_09C2(ds_1065, (ss->*sp_1064).t0000.u0, out bp_2302, out ds_1839);
				Eq_481 sp_1843;
				sp_1843.u0 = <invalid>;
				Eq_481 sp_1849 = (word16) sp_1843 + 2;
				if (Mem1833[ds_1839:0x53DB:byte] >u 0x00)
				{
					sp_1849.u0 = <invalid>;
					word16 bp_2304;
					if (fn0C74_522C(ds_1839, out bp_2304, out ds_1839) != 0x00)
						Mem1873[ds_1839:0x53DB:byte] = Mem1833[ds_1839:0x53DB:byte] - 0x01;
				}
				union Eq_17 Eq_17::* sp_1876 = sp_1849 - 2;
				(ss->*sp_1876).u2 = (uint16) 0x05;
				word16 bp_2303;
				fn0800_09C2(ds_1839, (ss->*sp_1876).u0, out bp_2303, out ds_1065);
				break;
			case 0x3C:
				(ss->*sp_1064).t0000.u2 = (uint16) 0x0F;
				word16 bp_2305;
				Eq_17 ds_1774;
				fn0800_09C2(ds_1065, (ss->*sp_1064).t0000.u0, out bp_2305, out ds_1774);
				Eq_481 sp_1778;
				sp_1778.u0 = <invalid>;
				Eq_481 sp_1784 = (word16) sp_1778 + 2;
				if (Mem1768[ds_1774:0x53DC:byte] >u 0x00)
				{
					sp_1784.u0 = <invalid>;
					if (fn0C74_542B(ds_1774, out ds_1774) != 0x00)
						Mem1808[ds_1774:0x53DC:byte] = Mem1768[ds_1774:0x53DC:byte] - 0x01;
				}
				union Eq_17 Eq_17::* sp_1811 = sp_1784 - 2;
				(ss->*sp_1811).u2 = (uint16) 0x06;
				word16 bp_2306;
				fn0800_09C2(ds_1774, (ss->*sp_1811).u0, out bp_2306, out ds_1065);
				break;
			case 0x3D:
				(ss->*sp_1064).t0000.u2 = (uint16) 0x10;
				word16 bp_2307;
				Eq_17 ds_1711;
				fn0800_09C2(ds_1065, (ss->*sp_1064).t0000.u0, out bp_2307, out ds_1711);
				Eq_481 sp_1715;
				sp_1715.u0 = <invalid>;
				if (Mem1705[ds_1711:0x53DE:byte] >u 0x00 && fn0C74_5258(ds_1711, out ds_1711) != 0x00)
					Mem1743[ds_1711:0x53DE:byte] = Mem1705[ds_1711:0x53DE:byte] - 0x01;
				ss->*sp_1715 = 0x07;
				word16 bp_2308;
				fn0800_09C2(ds_1711, ss->*sp_1715, out bp_2308, out ds_1065);
				break;
			case 0x3F:
			case 44:
				Mem1584[ds_1065:22706:byte] = 0x00;
				Eq_17 ds_1592 = fn0800_2401(ds_1065);
				Mem1602[ds_1592:22706:byte] = 0x01;
				Eq_481 sp_1596;
				sp_1596.u0 = <invalid>;
				ss->*((word16) sp_1596 - 2) = 0x00;
				ss->*((word16) sp_1596 - 4) = 0x00;
				ss->*((word16) sp_1596 - 6) = 0x01;
				fn1AB8_1536(ds_1592, ss->*((word16) sp_1596 - 6), ss->*((word16) sp_1596 - 4), ss->*((word16) sp_1596 - 2), out ds_1065);
				ss->*((word16) sp_1596 - 2) = 0x01;
				ss->*((word16) sp_1596 - 4) = 0x01;
				fn1AB8_14F4(ds_1065, ss->*((word16) sp_1596 - 4), ss->*((word16) sp_1596 - 2));
				ss->*((word16) sp_1596 - 2) = 0x0F;
				ss->*((word16) sp_1596 - 4) = 388;
				ss->*((word16) sp_1596 - 6) = 0x0114;
				ss->*((word16) sp_1596 - 8) = 399;
				fn0800_005A(ds_1065, ss->*((word16) sp_1596 - 8), ss->*((word16) sp_1596 - 6), ss->*((word16) sp_1596 - 4), ss->*((word16) sp_1596 - 2));
				ss->*((word16) sp_1596 - 2) = 0x08;
				fn1AB8_1C32(ds_1065, ss->*((word16) sp_1596 - 2));
				ss->*((word16) sp_1596 - 2) = 0x93;
				ss->*((word16) sp_1596 - 4) = 393;
				ss->*((word16) sp_1596 - 6) = ds_1065;
				ss->*((word16) sp_1596 - 8) = 0x5CBB;
				byte ch_2309;
				fn1AB8_1D82(ds_1065, ss->*((word16) sp_1596 - 8), ss->*((word16) sp_1596 - 4), ss->*((word16) sp_1596 - 2), out ch_2309);
				ss->*((word16) sp_1596 - 2) = 0x0A;
				fn1AB8_1C32(ds_1065, ss->*((word16) sp_1596 - 2));
				ss->*((word16) sp_1596 - 2) = 0x94;
				ss->*((word16) sp_1596 - 4) = 0x018A;
				ss->*((word16) sp_1596 - 6) = ds_1065;
				ss->*((word16) sp_1596 - 8) = 0x5CBB;
				byte ch_2310;
				fn1AB8_1D82(ds_1065, ss->*((word16) sp_1596 - 8), ss->*((word16) sp_1596 - 4), ss->*((word16) sp_1596 - 2), out ch_2310);
				break;
			default:
				if (al_1115 == 0x1B)
				{
					fn0800_0103(ds_1065);
					goto l0800_3110;
				}
				if (al_1115 == 0x20)
				{
					Eq_17 dx_1472 = Mem1114[ds_1065:22746:word16];
					Mem1473[ds_1065:0x58D0:word16] = Mem1114[ds_1065:22744:word16];
					Mem1474[ds_1065:22738:word16] = dx_1472;
					fn0800_0103(ds_1065);
					(ss->*sp_1064).t0000.u2 = (uint16) 11;
					word16 bp_2311;
					Eq_17 ds_1489;
					fn0800_09C2(ds_1065, (ss->*sp_1064).t0000.u0, out bp_2311, out ds_1489);
					Eq_481 sp_1493;
					sp_1493.u0 = <invalid>;
					struct Eq_12272 Eq_17::* sp_1499 = (word16) sp_1493 + 2;
					while (fn1E78_02FB(ds_1489) == 0x00)
					{
						(ss->*sp_1499).wFFFE = 0x00;
						Eq_481 sp_1525;
						sp_1525.u0 = <invalid>;
						sp_1499 = (word16) sp_1525 + 2;
						byte ch_2314;
						word16 dx_2315;
						word16 bp_2316;
						if ((byte) fn1206_015B(ds_1489, out ch_2314, out dx_2315, out bp_2316, out ds_1489) != 0x00)
							break;
					}
					union Eq_17 Eq_17::* sp_1538 = sp_1499 - 2;
					(ss->*sp_1538).u2 = (uint16) 0x02;
					word16 bp_2312;
					fn0800_09C2(ds_1489, (ss->*sp_1538).u0, out bp_2312, out ds_1065);
					Eq_481 sp_1553;
					sp_1553.u0 = <invalid>;
					Mem1562[ss:sp_1553 + 0x00:word16] = Mem1540[ds_1065:22738:word16];
					Mem1565[ss:sp_1553 + -2:word16] = Mem1562[ds_1065:0x58D0:word16];
					word16 dx_2313;
					fn0800_00C1(ds_1065, ss->*((word16) sp_1553 - 2), ss->*sp_1553, out dx_2313);
				}
				else if (al_1115 == 0x44)
				{
					if (Mem1114[ds_1065:0x58B0:byte] != 0x00)
						Mem1470[ds_1065:0x58B0:byte] = 0x00;
					else
						Mem1469[ds_1065:0x58B0:byte] = 0x01;
				}
				else if (al_1115 == 0x48)
				{
					(ss->*sp_1064).t0000.u2 = (uint16) 0x09;
					word16 bp_2317;
					Eq_17 ds_1422;
					fn0800_09C2(ds_1065, (ss->*sp_1064).t0000.u0, out bp_2317, out ds_1422);
					Eq_17 ds_1438 = fn0C74_51AA(ds_1422);
					Eq_481 sp_1442;
					sp_1442.u0 = <invalid>;
					ss->*((word16) sp_1442 - 2) = 0x00;
					word16 bp_2318;
					fn0800_09C2(ds_1438, ss->*((word16) sp_1442 - 2), out bp_2318, out ds_1065);
				}
				else if (al_1115 == 0x4B)
				{
					(ss->*sp_1064).t0000.u2 = (uint16) 0x0A;
					word16 bp_2319;
					Eq_17 ds_1312;
					fn0800_09C2(ds_1065, (ss->*sp_1064).t0000.u0, out bp_2319, out ds_1312);
					Eq_481 sp_1332;
					sp_1332.u0 = <invalid>;
					word16 dx_2320;
					word16 bp_2321;
					Eq_17 ds_1328;
					if (fn0C74_54F0(ds_1312, out dx_2320, out bp_2321, out ds_1328) == 0x00)
					{
						ss->*((word16) sp_1332 - 2) = 0x0E;
						word16 bp_2323;
						Eq_17 ds_1350;
						fn0800_09C2(ds_1328, ss->*((word16) sp_1332 - 2), out bp_2323, out ds_1350);
						Eq_17 ds_1366 = fn0800_08C0(ds_1350);
						Eq_481 sp_1370;
						sp_1370.u0 = <invalid>;
						ss->*((word16) sp_1370 - 2) = 0x05;
						word16 bp_2324;
						fn0800_09C2(ds_1366, ss->*((word16) sp_1370 - 2), out bp_2324, out ds_1328);
						Eq_481 sp_1386;
						sp_1386.u0 = <invalid>;
						sp_1332 = (word16) sp_1386 + 2;
					}
					union Eq_17 Eq_17::* sp_1394 = sp_1332 - 2;
					(ss->*sp_1394).u2 = (uint16) 0x01;
					word16 bp_2322;
					fn0800_09C2(ds_1328, (ss->*sp_1394).u0, out bp_2322, out ds_1065);
				}
				else if (al_1115 == 77)
				{
					(ss->*sp_1064).t0000.u2 = (uint16) 0x0C;
					word16 bp_2325;
					Eq_17 ds_1202;
					fn0800_09C2(ds_1065, (ss->*sp_1064).t0000.u0, out bp_2325, out ds_1202);
					Eq_481 sp_1222;
					sp_1222.u0 = <invalid>;
					word16 dx_2326;
					word16 bp_2327;
					Eq_17 ds_1218;
					if (fn0C74_54B1(ds_1202, out dx_2326, out bp_2327, out ds_1218) == 0x00)
					{
						ss->*((word16) sp_1222 - 2) = 0x0E;
						word16 bp_2329;
						Eq_17 ds_1240;
						fn0800_09C2(ds_1218, ss->*((word16) sp_1222 - 2), out bp_2329, out ds_1240);
						Eq_17 ds_1256 = fn0800_08C0(ds_1240);
						Eq_481 sp_1260;
						sp_1260.u0 = <invalid>;
						ss->*((word16) sp_1260 - 2) = 0x05;
						word16 bp_2330;
						fn0800_09C2(ds_1256, ss->*((word16) sp_1260 - 2), out bp_2330, out ds_1218);
						Eq_481 sp_1276;
						sp_1276.u0 = <invalid>;
						sp_1222 = (word16) sp_1276 + 2;
					}
					union Eq_17 Eq_17::* sp_1284 = sp_1222 - 2;
					(ss->*sp_1284).u2 = (uint16) 0x03;
					word16 bp_2328;
					fn0800_09C2(ds_1218, (ss->*sp_1284).u0, out bp_2328, out ds_1065);
				}
				else if (al_1115 == 0x50)
				{
					(ss->*sp_1064).t0000.u2 = (uint16) 0x0D;
					word16 bp_2331;
					Eq_17 ds_1152;
					fn0800_09C2(ds_1065, (ss->*sp_1064).t0000.u0, out bp_2331, out ds_1152);
					Eq_17 ds_1170 = fn0C74_51B2(ds_1152);
					Eq_481 sp_1172;
					sp_1172.u0 = <invalid>;
					ss->*((word16) sp_1172 - 2) = 0x04;
					word16 bp_2332;
					fn0800_09C2(ds_1170, ss->*((word16) sp_1172 - 2), out bp_2332, out ds_1065);
				}
				break;
			}
l0800_3087:
			dx_1020 = fn0800_0C71(ds_1065, out bp_1005, out ds_1065);
			sp_1013.u0 = <invalid>;
		} while (fn0800_0877(ds_1065) == 0x00 && Mem1942[ds_1065:22707:byte] == 0x00);
		fn0800_0103(ds_1065);
		ss->*((word16) sp_1013 - 2) = ds_1065;
		ss->*((word16) sp_1013 - 4) = 0x5ECE;
		ss->*((word16) sp_1013 - 6) = cs;
		ss->*((word16) sp_1013 - 8) = 11082;
		word16 ax_2297;
		word16 dx_2298;
		if (!fn1EDA_0B24(ss->*((word16) sp_1013 - 8), ss->*((word16) sp_1013 - 4), out ax_2297, out dx_2298))
			goto l0800_3110;
		if (fn0800_0877(ds_1065) != 0x00)
		{
			int16 dx_1999 = fn0800_0768(ds_1065, out bp_1005, out ds_1065);
			Eq_481 sp_2002;
			sp_2002.u0 = <invalid>;
			while (fn1E78_02FB(ds_1065) != 0x00)
				fn1E78_030D(dx_1999, ds_1065, ss->*((word16) sp_2002 - 2), out dx_1999);
			Mem2026[ds_1065:22926:ui32] = Mem2022[ds_1065:22926:ui32] + 0x01;
			Eq_17 ax_2032 = CONVERT(Mem2026[ds_1065:0x02:byte], uint8, uint16);
			if (Mem2026[ds_1065:22928:word16] == 0x00 && ax_2032 == Mem2026[ds_1065:22926:word16])
			{
				ds_1065 = fn0800_166D(ds_1065);
				goto l0800_3110;
			}
			if (Mem2026[ds_1065:22928:word16] == 0x00 && Mem2026[ds_1065:22926:word16] == 0xFA)
			{
				Mem2041[ds_1065:22926:word16] = 0x01;
				Mem2042[ds_1065:22928:word16] = 0x00;
			}
		}
		word16 bp_2301;
		fn1206_0066(ds_1065, out bp_2301, out ds);
	}
	Mem2086[ds_1065:22926:word16] = 0x01;
	Mem2087[ds_1065:22928:word16] = 0x00;
l0800_3110:
	Eq_526 bp_2095;
	bp_2095.u1 = (ss->*bp_1005).t0000.u1;
	dsOut = ds_1065;
	return bp_2095;
}
