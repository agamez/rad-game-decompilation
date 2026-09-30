// 0800:2827: Register Eq_526 fn0800_2827(Register Eq_17 ds, Register out Eq_17 dsOut)
// Called from:
//      fn0800_3D9D
Eq_526 fn0800_2827(Eq_17 ds, union Eq_17 & dsOut)
{
	mp16 fp;
	struct Eq_9307 Eq_17::* bp_1121 = fp - 2;
	Eq_481 sp_11 = fp - 644;
	Eq_17 ss;
	while (true)
	{
		struct Eq_9368 Eq_17::* sp_12 = sp_11 - 2;
		Eq_17 cs;
		(ss->*sp_12).t0000.u2 = (uint16) cs;
		(ss->*sp_12).tFFFE.u2 = (uint16) 0x2810;
		int16 dx_1236;
		if (fn0C74_0000(ds, (ss->*sp_12).tFFFE.u3, out dx_1236) == 0x00)
			break;
		while (fn1E78_02FB(ds) != 0x00)
			fn1E78_030D(dx_1236, ds, (ss->*sp_12).t0000.u2, out dx_1236);
		fn1206_0066(ds, out bp_1121, out ds);
		fn13E2_003B(ds);
		fn0800_01FE(ds);
		Eq_481 sp_60;
		sp_60.u0 = <invalid>;
		ss->*((word16) sp_60 - 2) = ds;
		ss->*((word16) sp_60 - 4) = 0x5ECE;
		ss->*((word16) sp_60 - 6) = cs;
		ss->*((word16) sp_60 - 8) = 0x2818;
		word16 ax_1369;
		word16 dx_1370;
		if (!fn1EDA_0B24(ss->*((word16) sp_60 - 8), ss->*((word16) sp_60 - 4), out ax_1369, out dx_1370))
		{
			Mem1234[ds:22926:word16] = 0x01;
			Mem1235[ds:22928:word16] = 0x00;
			break;
		}
		ss->*((word16) sp_60 - 2) = ss;
		ss->*((word16) sp_60 - 4) = bp_1121 - 0x0180;
		ss->*((word16) sp_60 - 6) = cs;
		ss->*((word16) sp_60 - 8) = 10271;
		fn1EDA_0FA2(ss->*((word16) sp_60 - 8), ss->*((word16) sp_60 - 4));
		ss->*((word16) sp_60 - 2) = ss;
		ss->*((word16) sp_60 - 4) = bp_1121 - 0x0180;
		ss->*((word16) sp_60 - 6) = 0x0100;
		word16 dx_1371;
		fn1EDA_0FD0(ds, ss->*((word16) sp_60 - 6), ss->*((word16) sp_60 - 4), out dx_1371);
		ss->*((word16) sp_60 - 2) = ss;
		ss->*((word16) sp_60 - 4) = bp_1121 - 0x0180;
		Mem158[ss:sp_60 + -6:word16] = Mem155[ds:22928:word16];
		Mem161[ss:sp_60 + -8:word16] = Mem158[ds:22926:word16];
		byte al_183 = fn1EDA_1123(ds, ss->*((word16) sp_60 - 8), ss->*((word16) sp_60 - 6), ss->*((word16) sp_60 - 4));
		ss->*((word16) sp_60 - 2) = ss;
		ss->*((word16) sp_60 - 4) = bp_1121 - 0x0180;
		ss->*((word16) sp_60 - 6) = ss;
		ss->*((word16) sp_60 - 8) = bp_1121 - 0x0100;
		word16 ax_184 = fn1EDA_1085(al_183, ds, ss->*((word16) sp_60 - 4));
		ss->*((word16) sp_60 - 2) = ss;
		ss->*((word16) sp_60 - 4) = bp_1121 - 0x0180;
		fn1EDA_1051((byte) ax_184, ds, ss->*((word16) sp_60 - 4));
		if ((ss->*bp_1121).bFF01 == 0x20)
			break;
		ss->*((word16) sp_60 - 2) = 0x00;
		ss->*((word16) sp_60 - 4) = 0x00;
		ss->*((word16) sp_60 - 6) = 0x01;
		Eq_17 ds_226;
		fn1AB8_1536(ds, ss->*((word16) sp_60 - 6), ss->*((word16) sp_60 - 4), ss->*((word16) sp_60 - 2), out ds_226);
		ss->*((word16) sp_60 - 2) = 0x01;
		ss->*((word16) sp_60 - 4) = 0x01;
		fn1AB8_14F4(ds_226, ss->*((word16) sp_60 - 4), ss->*((word16) sp_60 - 2));
		ss->*((word16) sp_60 - 2) = 0x0F;
		ss->*((word16) sp_60 - 4) = 388;
		ss->*((word16) sp_60 - 6) = 0x0114;
		ss->*((word16) sp_60 - 8) = 399;
		fn0800_005A(ds_226, ss->*((word16) sp_60 - 8), ss->*((word16) sp_60 - 6), ss->*((word16) sp_60 - 4), ss->*((word16) sp_60 - 2));
		ss->*((word16) sp_60 - 2) = 0x08;
		fn1AB8_1C32(ds_226, ss->*((word16) sp_60 - 2));
		ss->*((word16) sp_60 - 2) = 0x94;
		ss->*((word16) sp_60 - 4) = 0x018A;
		ss->*((word16) sp_60 - 6) = ds_226;
		ss->*((word16) sp_60 - 8) = 0x5CBB;
		byte ch_1373;
		fn1AB8_1D82(ds_226, ss->*((word16) sp_60 - 8), ss->*((word16) sp_60 - 4), ss->*((word16) sp_60 - 2), out ch_1373);
		ss->*((word16) sp_60 - 2) = 0x0A;
		fn1AB8_1C32(ds_226, ss->*((word16) sp_60 - 2));
		ss->*((word16) sp_60 - 2) = 0x94;
		ss->*((word16) sp_60 - 4) = 0x018A;
		ss->*((word16) sp_60 - 6) = ds_226;
		ss->*((word16) sp_60 - 8) = 0x5CBB;
		byte ch_1374;
		fn1AB8_1D82(ds_226, ss->*((word16) sp_60 - 8), ss->*((word16) sp_60 - 4), ss->*((word16) sp_60 - 2), out ch_1374);
		Eq_17 ds_318;
		fn0800_04E3(ds_226, out ds_318);
		ss->*((word16) sp_60 - 2) = ds_318;
		ss->*((word16) sp_60 - 4) = 0x5ECE;
		ss->*((word16) sp_60 - 6) = ds_318;
		ss->*((word16) sp_60 - 8) = 24278;
		ss->*((word16) sp_60 - 0x0A) = 0x06;
		word16 dx_1375;
		fn1EDA_0A39(ss->*((word16) sp_60 + 0x0A), ss->*((word16) sp_60 - 8), ss->*((word16) sp_60 - 4), out dx_1375);
		Eq_17 ds_370 = fn0800_0BEC(fn0800_0619(ds_318));
		fn13E2_00FB(ds_370);
		Eq_481 sp_374;
		sp_374.u0 = <invalid>;
		ss->*((word16) sp_374 - 2) = 0x08;
		ss->*((word16) sp_374 - 4) = 0x00;
		fn1AB8_1342(ds_370, ss->*((word16) sp_374 - 4), ss->*((word16) sp_374 - 2));
		word16 bp_1376;
		Eq_17 ds_408;
		fn1206_0066(ds_370, out bp_1376, out ds_408);
		Eq_481 sp_412;
		sp_412.u0 = <invalid>;
		Mem421[ss:sp_412 + -2:word16] = CONVERT(Mem393[ds_408:0x53D9:byte], uint8, uint16);
		Eq_17 ax_422 = fn0800_04CC(ss->*((word16) sp_412 - 2));
		ss->*((word16) sp_412 - 2) = ax_422;
		Mem434[ss:sp_412 + -4:word16] = SEQ(SLICE(ax_422, byte, 8), Mem429[ds_408:21466:byte]);
		ss->*((word16) sp_412 - 4) = fn0800_04CC(ss->*((word16) sp_412 - 4));
		byte ch_1377;
		word16 dx_1378;
		fn1206_0038(fn0C74_06B7(ds_408, ss->*((word16) sp_412 - 4), ss->*((word16) sp_412 - 2)), out ch_1377, out dx_1378, out bp_1121, out ds);
		Eq_481 sp_467;
		sp_467.u0 = <invalid>;
		Eq_17 ax_482 = CONVERT(Mem442[ds:0x53DD:byte], uint8, uint16) *s 0x3C;
		ss->*((word16) sp_467 - 2) = 0x00;
		ss->*((word16) sp_467 - 4) = ax_482;
		word16 dx_1379;
		fn0800_00C1(ds, ss->*((word16) sp_467 - 4), ss->*((word16) sp_467 - 2), out dx_1379);
		(ss->*bp_1121).bFE7F = 0x01;
		Eq_481 sp_1129 = sp_467;
		do
		{
			if (fn1E78_02FB(ds) != 0x00)
			{
l0800_2991:
				fn0800_0103(ds);
				goto l0800_2B41;
			}
			ss->*((word16) sp_1129 - 2) = 0x00;
			Eq_481 sp_520;
			sp_520.u0 = <invalid>;
			byte ch_1380;
			word16 dx_1381;
			if ((byte) fn1206_015B(ds, out ch_1380, out dx_1381, out bp_1121, out ds) != 0x00)
				goto l0800_2991;
			if ((ss->*bp_1121).bFE7F < ~0x00)
			{
				Mem540[ds:0x53D2:byte] = Mem510[ss:bp_1121 - 0x0100 + CONVERT(Mem510[ss:bp_1121 + -0x0181:byte], uint8, uint16):byte];
				++(ss->*bp_1121).bFE7F;
			}
			Eq_526 al_546 = Mem545[ds:0x53D2:byte];
			switch (al_546)
			{
			case 0x3B:
				ss->*sp_520 = 0x0E;
				word16 bp_1382;
				Eq_17 ds_1059;
				fn0800_09C2(ds, ss->*sp_520, out bp_1382, out ds_1059);
				Eq_481 sp_1063;
				sp_1063.u0 = <invalid>;
				Eq_481 sp_1069 = (word16) sp_1063 + 2;
				if (Mem1053[ds_1059:0x53DB:byte] >u 0x00)
				{
					sp_1069.u0 = <invalid>;
					word16 bp_1384;
					if (fn0C74_522C(ds_1059, out bp_1384, out ds_1059) != 0x00)
						Mem1093[ds_1059:0x53DB:byte] = Mem1053[ds_1059:0x53DB:byte] - 0x01;
				}
				union Eq_17 Eq_17::* sp_1096 = sp_1069 - 2;
				(ss->*sp_1096).u2 = (uint16) 0x05;
				word16 bp_1383;
				fn0800_09C2(ds_1059, (ss->*sp_1096).u0, out bp_1383, out ds);
				break;
			case 0x3C:
				ss->*sp_520 = 0x0F;
				struct Eq_10007 Eq_17::* bp_982;
				Eq_17 ds_1014;
				fn0800_09C2(ds, ss->*sp_520, out bp_982, out ds_1014);
				Mem1002[ds_1014:22717:byte] = Mem980[ss:bp_982 - 0x0100 + CONVERT(Mem980[ss:bp_982 + -0x0181:byte], uint8, uint16):byte];
				++(ss->*bp_982).bFE7F;
				Eq_481 sp_990;
				sp_990.u0 = <invalid>;
				Eq_481 sp_1016 = (word16) sp_990 + 2;
				if (Mem1004[ds_1014:0x53DC:byte] >u 0x00)
				{
					sp_1016.u0 = <invalid>;
					if (fn0C74_542B(ds_1014, out ds_1014) != 0x00)
						Mem1028[ds_1014:0x53DC:byte] = Mem1004[ds_1014:0x53DC:byte] - 0x01;
				}
				union Eq_17 Eq_17::* sp_1031 = sp_1016 - 2;
				(ss->*sp_1031).u2 = (uint16) 0x06;
				word16 bp_1385;
				fn0800_09C2(ds_1014, (ss->*sp_1031).u0, out bp_1385, out ds);
				break;
			case 0x3D:
				ss->*sp_520 = 0x10;
				word16 bp_1386;
				Eq_17 ds_923;
				fn0800_09C2(ds, ss->*sp_520, out bp_1386, out ds_923);
				Eq_481 sp_927;
				sp_927.u0 = <invalid>;
				if (Mem917[ds_923:0x53DE:byte] >u 0x00 && fn0C74_5258(ds_923, out ds_923) != 0x00)
					Mem955[ds_923:0x53DE:byte] = Mem917[ds_923:0x53DE:byte] - 0x01;
				ss->*sp_927 = 0x07;
				word16 bp_1387;
				fn0800_09C2(ds_923, ss->*sp_927, out bp_1387, out ds);
				break;
			default:
				if (al_546 == 0x1B)
				{
					fn0800_0103(ds);
					goto l0800_2B41;
				}
				if (al_546 == 0x48)
				{
					ss->*sp_520 = 0x09;
					word16 bp_1388;
					Eq_17 ds_864;
					fn0800_09C2(ds, ss->*sp_520, out bp_1388, out ds_864);
					Eq_17 ds_880 = fn0C74_51AA(ds_864);
					Eq_481 sp_884;
					sp_884.u0 = <invalid>;
					ss->*((word16) sp_884 - 2) = 0x00;
					word16 bp_1389;
					fn0800_09C2(ds_880, ss->*((word16) sp_884 - 2), out bp_1389, out ds);
				}
				else if (al_546 == 0x4B)
				{
					ss->*sp_520 = 0x0A;
					struct Eq_10263 Eq_17::* bp_740;
					Eq_17 ds_744;
					fn0800_09C2(ds, ss->*sp_520, out bp_740, out ds_744);
					Mem761[ds_744:22717:byte] = Mem738[ss:bp_740 - 0x0100 + CONVERT(Mem738[ss:bp_740 + -0x0181:byte], uint8, uint16):byte];
					++(ss->*bp_740).bFE7F;
					Eq_481 sp_774;
					sp_774.u0 = <invalid>;
					word16 dx_1390;
					word16 bp_1391;
					Eq_17 ds_770;
					if (fn0C74_54F0(ds_744, out dx_1390, out bp_1391, out ds_770) == 0x00)
					{
						ss->*((word16) sp_774 - 2) = 0x0E;
						word16 bp_1393;
						Eq_17 ds_792;
						fn0800_09C2(ds_770, ss->*((word16) sp_774 - 2), out bp_1393, out ds_792);
						Eq_17 ds_808 = fn0800_08C0(ds_792);
						Eq_481 sp_812;
						sp_812.u0 = <invalid>;
						ss->*((word16) sp_812 - 2) = 0x05;
						word16 bp_1394;
						fn0800_09C2(ds_808, ss->*((word16) sp_812 - 2), out bp_1394, out ds_770);
						Eq_481 sp_828;
						sp_828.u0 = <invalid>;
						sp_774 = (word16) sp_828 + 2;
					}
					union Eq_17 Eq_17::* sp_836 = sp_774 - 2;
					(ss->*sp_836).u2 = (uint16) 0x01;
					word16 bp_1392;
					fn0800_09C2(ds_770, (ss->*sp_836).u0, out bp_1392, out ds);
				}
				else if (al_546 == 77)
				{
					ss->*sp_520 = 0x0C;
					struct Eq_10367 Eq_17::* bp_620;
					Eq_17 ds_624;
					fn0800_09C2(ds, ss->*sp_520, out bp_620, out ds_624);
					Mem641[ds_624:22717:byte] = Mem618[ss:bp_620 - 0x0100 + CONVERT(Mem618[ss:bp_620 + -0x0181:byte], uint8, uint16):byte];
					++(ss->*bp_620).bFE7F;
					Eq_481 sp_654;
					sp_654.u0 = <invalid>;
					word16 dx_1395;
					word16 bp_1396;
					Eq_17 ds_650;
					if (fn0C74_54B1(ds_624, out dx_1395, out bp_1396, out ds_650) == 0x00)
					{
						ss->*((word16) sp_654 - 2) = 0x0E;
						word16 bp_1398;
						Eq_17 ds_672;
						fn0800_09C2(ds_650, ss->*((word16) sp_654 - 2), out bp_1398, out ds_672);
						Eq_17 ds_688 = fn0800_08C0(ds_672);
						Eq_481 sp_692;
						sp_692.u0 = <invalid>;
						ss->*((word16) sp_692 - 2) = 0x05;
						word16 bp_1399;
						fn0800_09C2(ds_688, ss->*((word16) sp_692 - 2), out bp_1399, out ds_650);
						Eq_481 sp_708;
						sp_708.u0 = <invalid>;
						sp_654 = (word16) sp_708 + 2;
					}
					union Eq_17 Eq_17::* sp_716 = sp_654 - 2;
					(ss->*sp_716).u2 = (uint16) 0x03;
					word16 bp_1397;
					fn0800_09C2(ds_650, (ss->*sp_716).u0, out bp_1397, out ds);
				}
				else if (al_546 == 0x50)
				{
					ss->*sp_520 = 0x0D;
					word16 bp_1400;
					Eq_17 ds_574;
					fn0800_09C2(ds, ss->*sp_520, out bp_1400, out ds_574);
					Eq_17 ds_592 = fn0C74_51B2(ds_574);
					Eq_481 sp_594;
					sp_594.u0 = <invalid>;
					ss->*((word16) sp_594 - 2) = 0x04;
					word16 bp_1401;
					fn0800_09C2(ds_592, ss->*((word16) sp_594 - 2), out bp_1401, out ds);
				}
				break;
			}
			fn0800_0C71(ds, out bp_1121, out ds);
			sp_1129.u0 = <invalid>;
		} while (fn0800_0877(ds) == 0x00 && Mem1148[ds:22707:byte] == 0x00);
		fn0800_0103(ds);
		if (fn0800_0877(ds) != 0x00)
		{
			Mem1177[ds:22926:ui32] = Mem1173[ds:22926:ui32] + 0x01;
			Eq_17 ax_1183 = CONVERT(Mem1177[ds:0x02:byte], uint8, uint16);
			if (Mem1177[ds:22928:word16] == 0x00 && ax_1183 == Mem1177[ds:22926:word16])
			{
				ds = fn0800_166D(ds);
				break;
			}
			if (Mem1177[ds:22928:word16] == 0x00 && Mem1177[ds:22926:word16] == 0xFA)
			{
				Mem1192[ds:22926:word16] = 0x01;
				Mem1193[ds:22928:word16] = 0x00;
			}
		}
		fn1206_0066(ds, out bp_1121, out ds);
		sp_11.u0 = <invalid>;
	}
l0800_2B41:
	Eq_526 bp_1260;
	bp_1260.u1 = (ss->*bp_1121).a0000[0].u1;
	dsOut = ds;
	return bp_1260;
}
