// 0800:2401: Register Eq_17 fn0800_2401(Register Eq_17 ds)
// Called from:
//      fn0800_2C0C
Eq_17 fn0800_2401(Eq_17 ds)
{
	Eq_17 cs;
	int16 dx_1493;
	if (fn0C74_0000(ds, SEQ(cs, 9066), out dx_1493) != 0x00)
	{
		while (fn1E78_02FB(ds) != 0x00)
			fn1E78_030D(dx_1493, ds, cs, out dx_1493);
		Eq_17 ss;
		<unknown> Eq_17::* fp;
		fn1EDA_0FA2(SEQ(cs, 0x2372), SEQ(ss, fp - 0x0182));
		word16 dx_1641;
		fn1EDA_0FD0(ds, 0x0100, SEQ(ss, fp - 0x0182), out dx_1641);
		fn1EDA_1051(SLICE(fn1EDA_1085(fn1EDA_1123(ds, Mem98[ds:22926:word16], Mem95[ds:22928:word16], SEQ(ss, fp - 0x0182)), ds, SEQ(ss, fp - 0x0182)), byte, 0), ds, SEQ(ss, fp - 0x0182));
		byte bLoc0101;
		if (bLoc0101 != 0x20)
		{
			word16 bp_154;
			Eq_17 ds_158;
			fn1206_0066(ds, out bp_154, out ds_158);
			Eq_481 sp_162;
			sp_162.u0 = <invalid>;
			ss->*((word16) sp_162 - 2) = (int32) fn1AB8_10CE(ds_158) /16 0x02 - 0x82;
			ss->*((word16) sp_162 - 4) = 0x96;
			ss->*((word16) sp_162 - 6) = (int32) fn1AB8_10CE(ds_158) /16 0x02 + 0x82;
			ss->*((word16) sp_162 - 8) = 0xE6;
			fn0800_1315(ds_158, ss->*((word16) sp_162 - 8), ss->*((word16) sp_162 - 6), ss->*((word16) sp_162 - 4), ss->*((word16) sp_162 - 2));
			ss->*((word16) sp_162 - 2) = 0x00;
			ss->*((word16) sp_162 - 4) = 0x00;
			ss->*((word16) sp_162 - 6) = 0x01;
			fn1AB8_1536(ds_158, ss->*((word16) sp_162 - 6), ss->*((word16) sp_162 - 4), ss->*((word16) sp_162 - 2), out ds);
			ss->*((word16) sp_162 - 2) = 0x04;
			fn1AB8_1C32(ds, ss->*((word16) sp_162 - 2));
			ss->*((word16) sp_162 - 2) = 0x0140;
			ss->*((word16) sp_162 - 4) = 0xA4;
			ss->*((word16) sp_162 - 6) = cs;
			ss->*((word16) sp_162 - 8) = 0x237A;
			byte ch_1643;
			fn1AB8_1D82(ds, ss->*((word16) sp_162 - 8), ss->*((word16) sp_162 - 4), ss->*((word16) sp_162 - 2), out ch_1643);
			ss->*((word16) sp_162 - 2) = 0x01;
			fn1AB8_1C32(ds, ss->*((word16) sp_162 - 2));
			ss->*((word16) sp_162 - 2) = 0x0140;
			ss->*((word16) sp_162 - 4) = 0xB4;
			ss->*((word16) sp_162 - 6) = cs;
			ss->*((word16) sp_162 - 8) = 0x238E;
			byte ch_1644;
			fn1AB8_1D82(ds, ss->*((word16) sp_162 - 8), ss->*((word16) sp_162 - 4), ss->*((word16) sp_162 - 2), out ch_1644);
			ss->*((word16) sp_162 - 2) = 0x0140;
			ss->*((word16) sp_162 - 4) = 0xC0;
			ss->*((word16) sp_162 - 6) = cs;
			ss->*((word16) sp_162 - 8) = 0x23AC;
			byte ch_1645;
			fn1AB8_1D82(ds, ss->*((word16) sp_162 - 8), ss->*((word16) sp_162 - 4), ss->*((word16) sp_162 - 2), out ch_1645);
			ss->*((word16) sp_162 - 2) = 0x0140;
			ss->*((word16) sp_162 - 4) = 0xCC;
			ss->*((word16) sp_162 - 6) = cs;
			ss->*((word16) sp_162 - 8) = 0x23C3;
			byte ch_1646;
			fn1AB8_1D82(ds, ss->*((word16) sp_162 - 8), ss->*((word16) sp_162 - 4), ss->*((word16) sp_162 - 2), out ch_1646);
			while (fn1E78_02FB(ds) == 0x00)
				;
			Mem339[ds:0x53D9:byte] = Mem313[ds:23774:byte];
			Mem341[ds:21466:byte] = Mem339[ds:23775:byte];
			Mem343[ds:0x53DB:byte] = Mem341[ds:23770:byte];
			Mem345[ds:0x53DC:byte] = Mem343[ds:23771:byte];
			if (Mem345[ds:23772:byte] >u 0x0A)
				Mem348[ds:23772:byte] = 0x0A;
			Mem352[ds:0x53DD:byte] = Mem350[ds:23772:byte];
			Mem354[ds:0x53DE:byte] = Mem352[ds:23773:byte];
			Mem359[ds:21462:word16] = 0x00;
			while (true)
			{
				Mem365[ds:0x53D4:word16] = 0x00;
				while (true)
				{
					Mem373[ss:sp_162 + -2:word16] = Mem367[ds:0x53D4:word16] *s 22 + 0x01;
					Mem377[ss:sp_162 + -4:word16] = Mem373[ds:21462:word16] *s 22 + 0x01;
					segptr32 es_di_387 = ds:0x5992[CONVERT(Mem377[ds:Mem377[ds:21462:word16] *s 0x1D + Mem377[ds:0x53D4:word16] + 0x5CE0:byte], uint8, uint16) * 0x04];
					ss->*((word16) sp_162 - 6) = SLICE(es_di_387, selector, 16);
					ss->*((word16) sp_162 - 8) = (word16) es_di_387;
					ss->*((word16) sp_162 - 0x0A) = 0x00;
					fn1AB8_13D7(ds, ss->*((word16) sp_162 + 0x0A), ss->*((word16) sp_162 - 8), ss->*((word16) sp_162 - 4), ss->*((word16) sp_162 - 2));
					if (Mem395[ds:0x53D4:word16] == 0x1C)
						break;
					Mem411[ds:0x53D4:word16] = Mem395[ds:0x53D4:word16] + 0x01;
				}
				if (Mem395[ds:21462:word16] == 0x10)
					break;
				Mem416[ds:21462:word16] = Mem395[ds:21462:word16] + 0x01;
			}
			ss->*((word16) sp_162 - 2) = ds;
			ss->*((word16) sp_162 - 4) = 0x5ECE;
			ss->*((word16) sp_162 - 6) = cs;
			ss->*((word16) sp_162 - 8) = 0x23E1;
			word16 ax_1647;
			word16 dx_1648;
			if (!fn1EDA_0B24(ss->*((word16) sp_162 - 8), ss->*((word16) sp_162 - 4), out ax_1647, out dx_1648))
			{
				Mem1491[ds:22926:word16] = 0x01;
				Mem1492[ds:22928:word16] = 0x00;
			}
			else
			{
				ss->*((word16) sp_162 - 2) = 0x00;
				ss->*((word16) sp_162 - 4) = 0x00;
				ss->*((word16) sp_162 - 6) = 0x01;
				Eq_17 ds_459;
				fn1AB8_1536(ds, ss->*((word16) sp_162 - 6), ss->*((word16) sp_162 - 4), ss->*((word16) sp_162 - 2), out ds_459);
				ss->*((word16) sp_162 - 2) = 0x01;
				ss->*((word16) sp_162 - 4) = 0x01;
				fn1AB8_14F4(ds_459, ss->*((word16) sp_162 - 4), ss->*((word16) sp_162 - 2));
				ss->*((word16) sp_162 - 2) = 0x0F;
				ss->*((word16) sp_162 - 4) = 388;
				ss->*((word16) sp_162 - 6) = 0x0114;
				ss->*((word16) sp_162 - 8) = 399;
				fn0800_005A(ds_459, ss->*((word16) sp_162 - 8), ss->*((word16) sp_162 - 6), ss->*((word16) sp_162 - 4), ss->*((word16) sp_162 - 2));
				ss->*((word16) sp_162 - 2) = 0x08;
				fn1AB8_1C32(ds_459, ss->*((word16) sp_162 - 2));
				ss->*((word16) sp_162 - 2) = 0x93;
				ss->*((word16) sp_162 - 4) = 393;
				ss->*((word16) sp_162 - 6) = cs;
				ss->*((word16) sp_162 - 8) = 9192;
				byte ch_1649;
				fn1AB8_1D82(ds_459, ss->*((word16) sp_162 - 8), ss->*((word16) sp_162 - 4), ss->*((word16) sp_162 - 2), out ch_1649);
				ss->*((word16) sp_162 - 2) = 0x0C;
				fn1AB8_1C32(ds_459, ss->*((word16) sp_162 - 2));
				ss->*((word16) sp_162 - 2) = 0x94;
				ss->*((word16) sp_162 - 4) = 0x018A;
				ss->*((word16) sp_162 - 6) = cs;
				ss->*((word16) sp_162 - 8) = 9192;
				byte ch_1650;
				fn1AB8_1D82(ds_459, ss->*((word16) sp_162 - 8), ss->*((word16) sp_162 - 4), ss->*((word16) sp_162 - 2), out ch_1650);
				Eq_17 ds_551;
				fn0800_04E3(ds_459, out ds_551);
				ss->*((word16) sp_162 - 2) = ds_551;
				ss->*((word16) sp_162 - 4) = 0x5ECE;
				ss->*((word16) sp_162 - 6) = ds_551;
				ss->*((word16) sp_162 - 8) = 24278;
				ss->*((word16) sp_162 - 0x0A) = 0x06;
				word16 dx_1651;
				fn1EDA_0A39(ss->*((word16) sp_162 + 0x0A), ss->*((word16) sp_162 - 8), ss->*((word16) sp_162 - 4), out dx_1651);
				word16 bp_1652;
				Eq_17 ds_618;
				fn1206_0066(fn0800_0BEC(fn0800_0619(ds_551)), out bp_1652, out ds_618);
				Eq_481 sp_622;
				sp_622.u0 = <invalid>;
				Mem631[ss:sp_622 + -2:word16] = CONVERT(Mem571[ds_618:0x53D9:byte], uint8, uint16);
				Eq_17 ax_632 = fn0800_04CC(ss->*((word16) sp_622 - 2));
				ss->*((word16) sp_622 - 2) = ax_632;
				Mem644[ss:sp_622 + -4:word16] = SEQ(SLICE(ax_632, byte, 8), Mem639[ds_618:21466:byte]);
				ss->*((word16) sp_622 - 4) = fn0800_04CC(ss->*((word16) sp_622 - 4));
				byte ch_1653;
				word16 dx_1654;
				struct Eq_8604 Eq_17::* bp_1428;
				fn1206_0038(fn0C74_06B7(ds_618, ss->*((word16) sp_622 - 4), ss->*((word16) sp_622 - 2)), out ch_1653, out dx_1654, out bp_1428, out ds);
				Eq_481 sp_677;
				sp_677.u0 = <invalid>;
				Eq_17 ax_692 = CONVERT(Mem652[ds:0x53DD:byte], uint8, uint16) *s 0x3C;
				ss->*((word16) sp_677 - 2) = 0x00;
				ss->*((word16) sp_677 - 4) = ax_692;
				int16 dx_1433;
				fn0800_00C1(ds, ss->*((word16) sp_677 - 4), ss->*((word16) sp_677 - 2), out dx_1433);
				(ss->*bp_1428).bFE7F = 0x01;
				Eq_481 sp_1436 = sp_677;
				do
				{
					while (fn1E78_02FB(ds) != 0x00)
						fn1E78_030D(dx_1433, ds, ss->*((word16) sp_1436 - 2), out dx_1433);
					while (fn1E78_02FB(ds) == 0x00)
					{
						ss->*((word16) sp_1436 - 2) = 0x00;
						Eq_481 sp_742;
						sp_742.u0 = <invalid>;
						sp_1436 = (word16) sp_742 + 2;
						byte ch_1655;
						if ((byte) fn1206_015B(ds, out ch_1655, out dx_1433, out bp_1428, out ds) != 0x00)
							break;
					}
					if (fn1E78_02FB(ds) != 0x00)
					{
						word16 dx_1658;
						Mem823[ds:0x53D2:byte] = SLICE(fn1E78_030D(dx_1433, ds, ss->*((word16) sp_1436 - 2), out dx_1658), byte, 0);
						if (Mem823[ds:0x53D2:byte] == 0x1B)
						{
							fn0800_0103(ds);
							return ds;
						}
					}
					else
					{
						ss->*((word16) sp_1436 - 2) = 0x00;
						Eq_481 sp_779;
						sp_779.u0 = <invalid>;
						sp_1436 = (word16) sp_779 + 2;
						byte ch_1656;
						word16 dx_1657;
						if ((byte) fn1206_015B(ds, out ch_1656, out dx_1657, out bp_1428, out ds) != 0x00)
						{
							Eq_17 ds_796;
							Mem806[ds_796:0x53D2:byte] = SLICE(fn0800_031B(ds, out bp_1428, out ds_796), byte, 0);
							sp_1436.u0 = <invalid>;
							ds = ds_796;
						}
					}
					if (Mem827[ds:0x53D2:byte] == 0x1B)
					{
						fn0800_0103(ds);
						return ds;
					}
					if ((ss->*bp_1428).bFE7F < ~0x00)
					{
						Mem843[ds:0x53D2:byte] = Mem827[ss:bp_1428 - 0x0100 + CONVERT(Mem827[ss:bp_1428 + -0x0181:byte], uint8, uint16):byte];
						++(ss->*bp_1428).bFE7F;
					}
					Eq_526 al_849 = Mem848[ds:0x53D2:byte];
					if (al_849 == 0x3B)
					{
						struct Eq_8783 Eq_17::* sp_1359 = sp_1436 - 2;
						(ss->*sp_1359).t0000.u2 = (uint16) 0x0E;
						word16 bp_1659;
						Eq_17 ds_1366;
						fn0800_09C2(ds, (ss->*sp_1359).t0000.u0, out bp_1659, out ds_1366);
						Eq_481 sp_1370;
						sp_1370.u0 = <invalid>;
						Eq_481 sp_1376 = (word16) sp_1370 + 2;
						if (Mem1360[ds_1366:0x53DB:byte] >u 0x00)
						{
							sp_1376.u0 = <invalid>;
							word16 bp_1661;
							if (fn0C74_522C(ds_1366, out bp_1661, out ds_1366) != 0x00)
								Mem1400[ds_1366:0x53DB:byte] = Mem1360[ds_1366:0x53DB:byte] - 0x01;
						}
						union Eq_17 Eq_17::* sp_1403 = sp_1376 - 2;
						(ss->*sp_1403).u2 = (uint16) 0x05;
						word16 bp_1660;
						fn0800_09C2(ds_1366, (ss->*sp_1403).u0, out bp_1660, out ds);
					}
					else if (al_849 == 0x3C)
					{
						struct Eq_8843 Eq_17::* sp_1286 = sp_1436 - 2;
						(ss->*sp_1286).t0000.u2 = (uint16) 0x0F;
						struct Eq_8855 Eq_17::* bp_1289;
						Eq_17 ds_1293;
						fn0800_09C2(ds, (ss->*sp_1286).t0000.u0, out bp_1289, out ds_1293);
						Mem1309[ds_1293:22717:byte] = Mem1287[ss:bp_1289 - 0x0100 + CONVERT(Mem1287[ss:bp_1289 + -0x0181:byte], uint8, uint16):byte];
						++(ss->*bp_1289).bFE7F;
						Eq_481 sp_1297;
						sp_1297.u0 = <invalid>;
						Eq_481 sp_1303 = (word16) sp_1297 + 2;
						if (Mem1311[ds_1293:0x53DC:byte] >u 0x00)
						{
							sp_1303.u0 = <invalid>;
							if (fn0C74_542B(ds_1293, out ds_1293) != 0x00)
								Mem1335[ds_1293:0x53DC:byte] = Mem1311[ds_1293:0x53DC:byte] - 0x01;
						}
						union Eq_17 Eq_17::* sp_1338 = sp_1303 - 2;
						(ss->*sp_1338).u2 = (uint16) 0x06;
						word16 bp_1662;
						fn0800_09C2(ds_1293, (ss->*sp_1338).u0, out bp_1662, out ds);
					}
					else if (al_849 == 0x3D)
					{
						struct Eq_8944 Eq_17::* sp_1223 = sp_1436 - 2;
						(ss->*sp_1223).t0000.u2 = (uint16) 0x10;
						word16 bp_1663;
						Eq_17 ds_1230;
						fn0800_09C2(ds, (ss->*sp_1223).t0000.u0, out bp_1663, out ds_1230);
						Eq_481 sp_1234;
						sp_1234.u0 = <invalid>;
						if (Mem1224[ds_1230:0x53DE:byte] >u 0x00 && fn0C74_5258(ds_1230, out ds_1230) != 0x00)
							Mem1262[ds_1230:0x53DE:byte] = Mem1224[ds_1230:0x53DE:byte] - 0x01;
						ss->*sp_1234 = 0x07;
						word16 bp_1664;
						fn0800_09C2(ds_1230, ss->*sp_1234, out bp_1664, out ds);
					}
					else
					{
						if (al_849 == 0x1B)
						{
							fn0800_0103(ds);
							return ds;
						}
						if (al_849 == 0x48)
						{
							struct Eq_9003 Eq_17::* sp_1164 = sp_1436 - 2;
							(ss->*sp_1164).t0000.u2 = (uint16) 0x09;
							word16 bp_1665;
							Eq_17 ds_1171;
							fn0800_09C2(ds, (ss->*sp_1164).t0000.u0, out bp_1665, out ds_1171);
							Eq_17 ds_1187 = fn0C74_51AA(ds_1171);
							Eq_481 sp_1191;
							sp_1191.u0 = <invalid>;
							ss->*((word16) sp_1191 - 2) = 0x00;
							word16 bp_1666;
							fn0800_09C2(ds_1187, ss->*((word16) sp_1191 - 2), out bp_1666, out ds);
						}
						else if (al_849 == 0x4B)
						{
							struct Eq_9043 Eq_17::* sp_1044 = sp_1436 - 2;
							(ss->*sp_1044).t0000.u2 = (uint16) 0x0A;
							struct Eq_9055 Eq_17::* bp_1047;
							Eq_17 ds_1051;
							fn0800_09C2(ds, (ss->*sp_1044).t0000.u0, out bp_1047, out ds_1051);
							Mem1068[ds_1051:22717:byte] = Mem1045[ss:bp_1047 - 0x0100 + CONVERT(Mem1045[ss:bp_1047 + -0x0181:byte], uint8, uint16):byte];
							++(ss->*bp_1047).bFE7F;
							Eq_481 sp_1081;
							sp_1081.u0 = <invalid>;
							word16 dx_1667;
							word16 bp_1668;
							Eq_17 ds_1077;
							if (fn0C74_54F0(ds_1051, out dx_1667, out bp_1668, out ds_1077) == 0x00)
							{
								ss->*((word16) sp_1081 - 2) = 0x0E;
								word16 bp_1670;
								Eq_17 ds_1099;
								fn0800_09C2(ds_1077, ss->*((word16) sp_1081 - 2), out bp_1670, out ds_1099);
								Eq_17 ds_1115 = fn0800_08C0(ds_1099);
								Eq_481 sp_1119;
								sp_1119.u0 = <invalid>;
								ss->*((word16) sp_1119 - 2) = 0x05;
								word16 bp_1671;
								fn0800_09C2(ds_1115, ss->*((word16) sp_1119 - 2), out bp_1671, out ds_1077);
								Eq_481 sp_1135;
								sp_1135.u0 = <invalid>;
								sp_1081 = (word16) sp_1135 + 2;
							}
							union Eq_17 Eq_17::* sp_1143 = sp_1081 - 2;
							(ss->*sp_1143).u2 = (uint16) 0x01;
							word16 bp_1669;
							fn0800_09C2(ds_1077, (ss->*sp_1143).u0, out bp_1669, out ds);
						}
						else if (al_849 == 77)
						{
							struct Eq_9156 Eq_17::* sp_924 = sp_1436 - 2;
							(ss->*sp_924).t0000.u2 = (uint16) 0x0C;
							struct Eq_9168 Eq_17::* bp_927;
							Eq_17 ds_931;
							fn0800_09C2(ds, (ss->*sp_924).t0000.u0, out bp_927, out ds_931);
							Mem948[ds_931:22717:byte] = Mem925[ss:bp_927 - 0x0100 + CONVERT(Mem925[ss:bp_927 + -0x0181:byte], uint8, uint16):byte];
							++(ss->*bp_927).bFE7F;
							Eq_481 sp_1021;
							sp_1021.u0 = <invalid>;
							word16 dx_1672;
							word16 bp_1673;
							Eq_17 ds_1011;
							if (fn0C74_54B1(ds_931, out dx_1672, out bp_1673, out ds_1011) == 0x00)
							{
								ss->*((word16) sp_1021 - 2) = 0x0E;
								word16 bp_1675;
								Eq_17 ds_979;
								fn0800_09C2(ds_1011, ss->*((word16) sp_1021 - 2), out bp_1675, out ds_979);
								Eq_17 ds_995 = fn0800_08C0(ds_979);
								Eq_481 sp_999;
								sp_999.u0 = <invalid>;
								ss->*((word16) sp_999 - 2) = 0x05;
								word16 bp_1676;
								fn0800_09C2(ds_995, ss->*((word16) sp_999 - 2), out bp_1676, out ds_1011);
								Eq_481 sp_1015;
								sp_1015.u0 = <invalid>;
								sp_1021 = (word16) sp_1015 + 2;
							}
							union Eq_17 Eq_17::* sp_1023 = sp_1021 - 2;
							(ss->*sp_1023).u2 = (uint16) 0x03;
							word16 bp_1674;
							fn0800_09C2(ds_1011, (ss->*sp_1023).u0, out bp_1674, out ds);
						}
						else if (al_849 == 0x50)
						{
							struct Eq_9266 Eq_17::* sp_868 = sp_1436 - 2;
							(ss->*sp_868).t0000.u2 = (uint16) 0x0D;
							word16 bp_1677;
							Eq_17 ds_881;
							fn0800_09C2(ds, (ss->*sp_868).t0000.u0, out bp_1677, out ds_881);
							Eq_17 ds_899 = fn0C74_51B2(ds_881);
							Eq_481 sp_901;
							sp_901.u0 = <invalid>;
							ss->*((word16) sp_901 - 2) = 0x04;
							word16 bp_1678;
							fn0800_09C2(ds_899, ss->*((word16) sp_901 - 2), out bp_1678, out ds);
						}
					}
					dx_1433 = fn0800_0C71(ds, out bp_1428, out ds);
					sp_1436.u0 = <invalid>;
				} while (fn0800_0877(ds) == 0x00 && Mem1455[ds:22707:byte] == 0x00);
				fn0800_0103(ds);
			}
		}
	}
	return ds;
}
