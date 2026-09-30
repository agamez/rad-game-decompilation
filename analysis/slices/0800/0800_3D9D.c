// 0800:3D9D: Register Eq_17 fn0800_3D9D(Register Eq_17 ds)
// Called from:
//      fn0800_4255
Eq_17 fn0800_3D9D(Eq_17 ds)
{
	word16 bp_1624;
	word16 bp_1592;
	Eq_17 ds_16;
	fn1206_0066(ds, out bp_1592, out ds_16);
	fn13E2_003B(ds_16);
	fn1AB8_0F80(ds_16);
	if (Mem7[ds_16:21471:byte] == 0x00)
		ds_16 = fn0800_3CFA(ds_16);
	fn13E2_0080(ds_16);
	Eq_17 ds_77 = fn0800_21E7(ds_16);
	Eq_481 sp_81;
	sp_81.u0 = <invalid>;
	Eq_17 ss;
	ss->*((word16) sp_81 - 2) = 0x07;
	fn1AB8_1C32(ds_77, ss->*((word16) sp_81 - 2));
	ss->*((word16) sp_81 - 2) = 0x01;
	ss->*((word16) sp_81 - 4) = 0x00;
	ss->*((word16) sp_81 - 6) = 0x02;
	Eq_17 ds_106;
	fn1AB8_1536(ds_77, ss->*((word16) sp_81 - 6), ss->*((word16) sp_81 - 4), ss->*((word16) sp_81 - 2), out ds_106);
	word16 bp_1593;
	Eq_17 ds_118;
	fn1206_0066(ds_106, out bp_1593, out ds_118);
	Eq_481 sp_122;
	sp_122.u0 = <invalid>;
	ss->*((word16) sp_122 - 2) = 0x0140;
	ss->*((word16) sp_122 - 4) = 0x01CE;
	Eq_17 cs;
	ss->*((word16) sp_122 - 6) = cs;
	ss->*((word16) sp_122 - 8) = 0x3D5A;
	byte ch_1594;
	fn1AB8_1D82(ds_118, ss->*((word16) sp_122 - 8), ss->*((word16) sp_122 - 4), ss->*((word16) sp_122 - 2), out ch_1594);
	ss->*((word16) sp_122 - 2) = 0x02;
	ss->*((word16) sp_122 - 4) = 0x00;
	ss->*((word16) sp_122 - 6) = 0x00;
	ss->*((word16) sp_122 - 8) = 0x00;
	fn1AB8_1CBA(ds_118, ss->*((word16) sp_122 - 8), ss->*((word16) sp_122 - 6), ss->*((word16) sp_122 - 4), ss->*((word16) sp_122 - 2));
	ss->*((word16) sp_122 - 2) = 0x02;
	ss->*((word16) sp_122 - 4) = 0x02;
	fn1AB8_1342(ds_118, ss->*((word16) sp_122 - 4), ss->*((word16) sp_122 - 2));
	ss->*((word16) sp_122 - 2) = 0x02;
	fn1AB8_1C32(ds_118, ss->*((word16) sp_122 - 2));
	ss->*((word16) sp_122 - 2) = 0x00;
	ss->*((word16) sp_122 - 4) = 0x00;
	ss->*((word16) sp_122 - 6) = 0x01;
	fn1AB8_10F4(ds_118, ss->*((word16) sp_122 - 6), ss->*((word16) sp_122 - 4), ss->*((word16) sp_122 - 2));
	ss->*((word16) sp_122 - 2) = 0x6A;
	ss->*((word16) sp_122 - 4) = 0x016D;
	ss->*((word16) sp_122 - 6) = 515;
	ss->*((word16) sp_122 - 8) = 0x01C9;
	fn1AB8_112E(ds_118, ss->*((word16) sp_122 - 8), ss->*((word16) sp_122 - 6), ss->*((word16) sp_122 - 4), ss->*((word16) sp_122 - 2));
	ss->*((word16) sp_122 - 2) = 121;
	ss->*((word16) sp_122 - 4) = 411;
	Eq_17 ds_223 = fn0C74_06B7(ds_118, ss->*((word16) sp_122 - 4), ss->*((word16) sp_122 - 2));
	Eq_481 sp_227;
	sp_227.u0 = <invalid>;
	ss->*((word16) sp_227 + 2) = 0x9C;
	ss->*sp_227 = 0x14;
	ss->*((word16) sp_227 - 2) = 0x01E0;
	ss->*((word16) sp_227 - 4) = 0x016A;
	ss->*((word16) sp_227 - 6) = 0x0140;
	ss->*((word16) sp_227 - 8) = 0xB4;
	word16 si_1595;
	selector es_1596;
	Eq_17 ds_250;
	fn1206_01AC(ds_223, out si_1595, out es_1596, out ds_250);
	byte ch_1597;
	int16 dx_1109;
	struct Eq_16937 Eq_17::* bp_1104;
	Eq_17 ds_1108;
	fn1206_0038(ds_250, out ch_1597, out dx_1109, out bp_1104, out ds_1108);
	Eq_481 sp_1112;
	sp_1112.u0 = <invalid>;
	Eq_17 ds_1009;
	do
	{
		Mem275[ds_1108:22752:byte] = 0x00;
		(ss->*bp_1104).bFFFF = ~0x00;
		if (fn1E78_02FB(ds_1108) == 0x00 && Mem278[ds_1108:22752:byte] == 0x00)
		{
			fn0C74_54B1(ds_1108, out dx_1109, out bp_1104, out ds_1108);
			sp_1112.u0 = <invalid>;
		}
		if (fn1E78_02FB(ds_1108) == 0x00 && Mem278[ds_1108:22752:byte] == 0x00)
		{
			fn0C74_54B1(ds_1108, out dx_1109, out bp_1104, out ds_1108);
			sp_1112.u0 = <invalid>;
		}
		if (fn1E78_02FB(ds_1108) == 0x00 && Mem278[ds_1108:22752:byte] == 0x00)
		{
			fn0C74_54F0(ds_1108, out dx_1109, out bp_1104, out ds_1108);
			sp_1112.u0 = <invalid>;
		}
		if (fn1E78_02FB(ds_1108) == 0x00 && Mem278[ds_1108:22752:byte] == 0x00)
		{
			fn0C74_54F0(ds_1108, out dx_1109, out bp_1104, out ds_1108);
			sp_1112.u0 = <invalid>;
		}
		if (fn1E78_02FB(ds_1108) != 0x00)
		{
			(ss->*bp_1104).bFFFF = (byte) fn1E78_030D(dx_1109, ds_1108, ss->*((word16) sp_1112 - 2), out dx_1109);
			if ((ss->*bp_1104).bFFFF == 0x00)
				(ss->*bp_1104).bFFFF = (byte) fn1E78_030D(dx_1109, ds_1108, ss->*((word16) sp_1112 - 2), out dx_1109);
			while (fn1E78_02FB(ds_1108) != 0x00)
				fn1E78_030D(dx_1109, ds_1108, ss->*((word16) sp_1112 - 2), out dx_1109);
		}
		if (Mem465[ds_1108:22752:byte] != 0x00)
		{
			(ss->*bp_1104).bFFFF = fn0800_1D55(ds_1108, out dx_1109, out bp_1104, out ds_1108);
			sp_1112.u0 = <invalid>;
		}
		uint8 al_492 = (ss->*bp_1104).bFFFF;
		if (al_492 == 33)
		{
			word16 bp_1598;
			Eq_17 ds_1465;
			fn1206_0066(ds_1108, out bp_1598, out ds_1465);
			Eq_17 ds_1479;
			fn0800_184C(ds_1465, out ds_1479);
			Mem1490[ds_1479:22706:byte] = 0x00;
			fn0800_2827(ds_1479, out ds_1009);
			Mem1506[ds_1009:22706:byte] = 0x01;
			return ds_1009;
		}
		if (al_492 == 0x3B)
		{
			struct Eq_17094 Eq_17::* sp_1368 = sp_1112 - 2;
			(ss->*sp_1368).w0000 = 0x01;
			Mem1372[ss:sp_1368 + -2:word16] = Mem1369[ds_1108:21532:word16];
			Mem1375[ss:sp_1368 + -4:word16] = Mem1372[ds_1108:0x542A:word16];
			(ss->*sp_1368).tFFFA.u2 = (uint16) ds_1108;
			(ss->*sp_1368).tFFF8.u2 = (uint16) 0x5438;
			(ss->*sp_1368).wFFF6 = 0x01;
			word16 dx_1599;
			word16 bp_1600;
			Eq_17 ds_1388;
			fn0800_19E1(ds_1108, (ss->*sp_1368).tFFF8.u3, out dx_1599, out bp_1600, out ds_1388);
			word16 bp_1601;
			Eq_17 ds_1420;
			fn1206_0066(fn0C74_51AA(ds_1388), out bp_1601, out ds_1420);
			Eq_17 ds_1434;
			fn0800_2C0C(fn0800_184C(ds_1420, out ds_1434), ds_1434, out ds_1009);
			return ds_1009;
		}
		if (al_492 != 0x3C)
		{
			if (al_492 == 0x3D)
			{
				struct Eq_17491 Eq_17::* sp_1271 = sp_1112 - 2;
				(ss->*sp_1271).w0000 = 0x03;
				Mem1275[ss:sp_1271 + -2:word16] = Mem1272[ds_1108:0x5420:word16];
				Mem1278[ss:sp_1271 + -4:word16] = Mem1275[ds_1108:21550:word16];
				(ss->*sp_1271).tFFFA.u2 = (uint16) ds_1108;
				(ss->*sp_1271).tFFF8.u2 = (uint16) 21612;
				(ss->*sp_1271).wFFF6 = 0x01;
				word16 dx_1605;
				word16 bp_1606;
				Eq_17 ds_1291;
				fn0800_19E1(ds_1108, (ss->*sp_1271).tFFF8.u3, out dx_1605, out bp_1606, out ds_1291);
				Mem1306[ds_1291:22926:word16] = 0x00;
				Mem1307[ds_1291:22928:word16] = 0x00;
				word16 bp_1607;
				Eq_17 ds_1313;
				fn1206_0066(ds_1291, out bp_1607, out ds_1313);
				Eq_17 ds_1340;
				fn0800_2C0C(fn0800_184C(fn0800_149F(ds_1313), out ds_1340), ds_1340, out ds_1009);
				Mem1366[ds_1009:22926:word16] = 0x01;
				Mem1367[ds_1009:22928:word16] = 0x00;
				return ds_1009;
			}
			if (al_492 == 0x3E)
			{
				if (Mem491[ds_1108:0x58B0:byte] != 0x00)
				{
					Mem1151[ds_1108:0x58B0:byte] = 0x00;
					struct Eq_17640 Eq_17::* sp_1152 = sp_1112 - 2;
					(ss->*sp_1152).w0000 = 0x04;
					Mem1156[ss:sp_1152 + -2:word16] = Mem1153[ds_1108:0x5422:word16];
					Mem1159[ss:sp_1152 + -4:word16] = Mem1156[ds_1108:21552:word16];
					(ss->*sp_1152).tFFFA.u2 = (uint16) ds_1108;
					(ss->*sp_1152).tFFF8.u2 = (uint16) 0x5486;
					(ss->*sp_1152).wFFF6 = 0x01;
					fn0800_19E1(ds_1108, (ss->*sp_1152).tFFF8.u3, out dx_1109, out bp_1104, out ds_1108);
					Eq_481 sp_1176;
					sp_1176.u0 = <invalid>;
					sp_1112 = (word16) sp_1176 + 0x0C;
				}
				else
				{
					Mem1119[ds_1108:0x58B0:byte] = 0x01;
					struct Eq_17588 Eq_17::* sp_1120 = sp_1112 - 2;
					(ss->*sp_1120).w0000 = 0x04;
					Mem1124[ss:sp_1120 + -2:word16] = Mem1121[ds_1108:0x5422:word16];
					Mem1127[ss:sp_1120 + -4:word16] = Mem1124[ds_1108:21552:word16];
					(ss->*sp_1120).tFFFA.u2 = (uint16) ds_1108;
					(ss->*sp_1120).tFFF8.u2 = (uint16) 0x5486;
					(ss->*sp_1120).wFFF6 = 0x00;
					fn0800_19E1(ds_1108, (ss->*sp_1120).tFFF8.u3, out dx_1109, out bp_1104, out ds_1108);
					Eq_481 sp_1144;
					sp_1144.u0 = <invalid>;
					sp_1112 = (word16) sp_1144 + 0x0C;
				}
			}
			else if (al_492 != 0x3F)
			{
				if (al_492 == 0x40)
				{
					struct Eq_17834 Eq_17::* sp_1015 = sp_1112 - 2;
					(ss->*sp_1015).w0000 = 0x06;
					Mem1019[ss:sp_1015 + -2:word16] = Mem1016[ds_1108:21542:word16];
					Mem1022[ss:sp_1015 + -4:word16] = Mem1019[ds_1108:0x5434:word16];
					(ss->*sp_1015).tFFFA.u2 = (uint16) ds_1108;
					(ss->*sp_1015).tFFF8.u2 = (uint16) 0x54BA;
					(ss->*sp_1015).wFFF6 = 0x01;
					word16 dx_1615;
					word16 bp_1616;
					Eq_17 ds_1035;
					fn0800_19E1(ds_1108, (ss->*sp_1015).tFFF8.u3, out dx_1615, out bp_1616, out ds_1035);
					Eq_481 sp_1039;
					sp_1039.u0 = <invalid>;
					ss->*((word16) sp_1039 + 0x0A) = 100;
					word16 dx_1617;
					fn1E78_029C(ds_1035, ss->*((word16) sp_1039 + 0x0A), out dx_1617);
					word16 bp_1618;
					Eq_17 ds_1064;
					fn1206_0066(ds_1035, out bp_1618, out ds_1064);
					byte ch_1619;
					fn1206_0038(fn0800_21E7(fn0800_391E(ds_1064)), out ch_1619, out dx_1109, out bp_1104, out ds_1108);
					sp_1112.u0 = <invalid>;
				}
			}
			else
			{
				struct Eq_17759 Eq_17::* sp_750 = sp_1112 - 2;
				(ss->*sp_750).w0000 = 0x05;
				Mem754[ss:sp_750 + -2:word16] = Mem751[ds_1108:0x5424:word16];
				Mem757[ss:sp_750 + -4:word16] = Mem754[ds_1108:21554:word16];
				(ss->*sp_750).tFFFA.u2 = (uint16) ds_1108;
				(ss->*sp_750).tFFF8.u2 = (uint16) 0x54A0;
				(ss->*sp_750).wFFF6 = 0x01;
				word16 dx_1611;
				word16 bp_1612;
				Eq_17 ds_770;
				fn0800_19E1(ds_1108, (ss->*sp_750).tFFF8.u3, out dx_1611, out bp_1612, out ds_770);
				word16 bp_1613;
				fn1206_0066(ds_770, out bp_1613, out ds_1009);
				Eq_481 sp_790;
				sp_790.u0 = <invalid>;
				ss->*((word16) sp_790 - 2) = 100;
				word16 dx_1614;
				fn1E78_029C(ds_1009, ss->*((word16) sp_790 - 2), out dx_1614);
				Eq_481 sp_1002 = sp_790;
				if (Mem796[ds_1009:0x02:byte] >u 0x1E)
				{
					do
					{
						struct Eq_17925 Eq_17::* sp_856 = sp_1002 - 2;
						(ss->*sp_856).t0000.u2 = (uint16) 0x02;
						(ss->*sp_856).tFFFE.u2 = (uint16) 0x00;
						(ss->*sp_856).tFFFC.u2 = (uint16) 0x2A;
						(ss->*sp_856).tFFFA.u2 = (uint16) 0x00;
						fn1AB8_1CBA(ds_1009, (ss->*sp_856).tFFFA.u2, (ss->*sp_856).tFFFC.u2, (ss->*sp_856).tFFFE.u2, (ss->*sp_856).t0000.u2);
						(ss->*sp_856).t0000.u2 = (uint16) 0x02;
						(ss->*sp_856).tFFFE.u2 = (uint16) 0x02;
						fn1AB8_1342(ds_1009, (ss->*sp_856).tFFFE.u0, (ss->*sp_856).t0000.u2);
						word16 bp_1621;
						Eq_17 ds_894;
						fn1206_0066(ds_1009, out bp_1621, out ds_894);
						Eq_481 sp_898;
						sp_898.u0 = <invalid>;
						ss->*((word16) sp_898 - 2) = 0x08;
						ss->*((word16) sp_898 - 4) = 0x00;
						fn1AB8_1342(ds_894, ss->*((word16) sp_898 - 4), ss->*((word16) sp_898 - 2));
						ss->*((word16) sp_898 - 2) = ds_894;
						ss->*((word16) sp_898 - 4) = 24278;
						ss->*((word16) sp_898 - 6) = cs;
						ss->*((word16) sp_898 - 8) = 15761;
						word16 ax_1622;
						word16 dx_1623;
						if (!fn1EDA_0B24(ss->*((word16) sp_898 - 8), ss->*((word16) sp_898 - 4), out ax_1622, out dx_1623))
						{
							ss->*((word16) sp_898 - 2) = cs;
							ss->*((word16) sp_898 - 4) = 15766;
							ss->*((word16) sp_898 - 6) = ds_894;
							ss->*((word16) sp_898 - 8) = 24278;
							ss->*((word16) sp_898 - 0x0A) = 0x06;
							word16 dx_1625;
							fn1EDA_0A39(ss->*((word16) sp_898 + 0x0A), ss->*((word16) sp_898 - 8), ss->*((word16) sp_898 - 4), out dx_1625);
						}
						ss->*((word16) sp_898 - 2) = ds_894;
						ss->*((word16) sp_898 - 4) = 24278;
						Eq_481 sp_984;
						sp_984.u0 = <invalid>;
						int16 dx_981 = fn1229_0DCC(ds_894, ss->*((word16) sp_898 - 4), out bp_1624, out ds_1009);
						sp_1002 = (word16) sp_984 + 4;
						if (Mem973[ds_1009:23731:byte] == 0x00)
						{
							fn0800_31B7(dx_981, ds_1009, out ds_1009);
							sp_1002.u0 = <invalid>;
						}
					} while (Mem973[ds_1009:23731:byte] == 0x00);
					return ds_1009;
				}
				byte ch_1620;
				fn1206_0038(fn0800_21E7(fn0800_2004(ds_1009)), out ch_1620, out dx_1109, out bp_1104, out ds_1108);
				sp_1112.u0 = <invalid>;
			}
		}
		else
		{
			struct Eq_17158 Eq_17::* sp_502 = sp_1112 - 2;
			(ss->*sp_502).w0000 = 0x02;
			Mem507[ss:sp_502 + -2:word16] = Mem503[ds_1108:0x541E:word16];
			Mem510[ss:sp_502 + -4:word16] = Mem507[ds_1108:0x542C:word16];
			(ss->*sp_502).tFFFA.u2 = (uint16) ds_1108;
			(ss->*sp_502).tFFF8.u2 = (uint16) 0x5452;
			(ss->*sp_502).wFFF6 = 0x01;
			word16 dx_1602;
			word16 bp_1603;
			Eq_17 ds_527;
			fn0800_19E1(ds_1108, (ss->*sp_502).tFFF8.u3, out dx_1602, out bp_1603, out ds_527);
			Eq_17 ds_543 = fn0800_11EF(ds_527);
			Eq_481 sp_547;
			sp_547.u0 = <invalid>;
			ss->*((word16) sp_547 - 2) = 0x02;
			Mem558[ss:sp_547 + -4:word16] = Mem555[ds_543:0x541E:word16];
			Mem561[ss:sp_547 + -6:word16] = Mem558[ds_543:0x542C:word16];
			ss->*((word16) sp_547 - 8) = ds_543;
			ss->*((word16) sp_547 - 0x0A) = 0x5452;
			ss->*((word16) sp_547 - 0x0C) = 0x00;
			word16 dx_1604;
			word16 bp_570;
			Eq_17 ds_574;
			fn0800_19E1(ds_543, ss->*((word16) sp_547 - 0x0A), out dx_1604, out bp_570, out ds_574);
			Eq_481 sp_578;
			sp_578.u0 = <invalid>;
			ss->*((word16) sp_578 + 0x0A) = 0x01;
			ss->*((word16) sp_578 + 8) = 0x03;
			fn1AB8_1175(ds_574, ss->*((word16) sp_578 + 8), ss->*((word16) sp_578 + 0x0A));
			Mem599[ss:sp_578 + 0x0A:word16] = Mem588[ds_574:0x53E4:word16] - 0x04;
			Mem603[ss:sp_578 + 0x08:word16] = Mem599[ds_574:0x53F2:word16] - 0x01;
			Mem607[ss:sp_578 + 0x06:word16] = Mem603[ds_574:0x5400:word16] + 0x04;
			Mem612[ss:sp_578 + 0x04:word16] = Mem607[ds_574:0x540E:word16] + 0x03;
			fn1AB8_1B3E(ds_574, ss->*((word16) sp_578 + 4), ss->*((word16) sp_578 + 6), ss->*((word16) sp_578 + 8), ss->*((word16) sp_578 + 0x0A));
			if (Mem612[ds_574:22928:word16] == 0x00 && Mem612[ds_574:22926:word16] == 0x01)
			{
				ss->*((word16) sp_578 + 0x0A) = 0x01;
				Mem627[ss:sp_578 + 0x08:word16] = Mem624[ds_574:21532:word16];
				Mem630[ss:sp_578 + 0x06:word16] = Mem627[ds_574:0x542A:word16];
				ss->*((word16) sp_578 + 4) = cs;
				ss->*((word16) sp_578 + 2) = 0x3D85;
				ss->*sp_578 = 0x00;
				fn0800_19E1(ds_574, ss->*((word16) sp_578 + 2), out dx_1109, out bp_1104, out ds_1108);
				Eq_481 sp_647;
				sp_647.u0 = <invalid>;
				sp_1112 = (word16) sp_647 + 0x0C;
			}
			else
			{
				ss->*((word16) sp_578 + 0x0A) = 0x01;
				Mem661[ss:sp_578 + 0x08:word16] = Mem657[ds_574:21532:word16];
				Mem664[ss:sp_578 + 0x06:word16] = Mem661[ds_574:0x542A:word16];
				ss->*((word16) sp_578 + 4) = ss;
				ss->*((word16) sp_578 + 2) = bp_570 - 262;
				ss->*sp_578 = cs;
				ss->*((word16) sp_578 - 2) = 0x3D7F;
				fn1EDA_0A1F(ss->*((word16) sp_578 - 2), ss->*((word16) sp_578 + 2));
				ss->*sp_578 = ds_574;
				ss->*((word16) sp_578 - 2) = 24278;
				fn1EDA_0AAC(ss->*((word16) sp_578 - 2), ss->*((word16) sp_578 + 2));
				ss->*sp_578 = cs;
				ss->*((word16) sp_578 - 2) = 0x3D83;
				fn1EDA_0AAC(ss->*((word16) sp_578 - 2), ss->*((word16) sp_578 + 2));
				ss->*sp_578 = 0x00;
				fn0800_19E1(ds_574, ss->*((word16) sp_578 + 2), out dx_1109, out bp_1104, out ds_1108);
				Eq_481 sp_737;
				sp_737.u0 = <invalid>;
				sp_1112 = (word16) sp_737 + 0x0C;
			}
		}
	} while ((ss->*bp_1104).bFFFF != 0x41);
	struct Eq_17688 Eq_17::* sp_1197 = sp_1112 - 2;
	(ss->*sp_1197).w0000 = 0x07;
	Mem1204[ss:sp_1197 + -2:word16] = Mem1198[ds_1108:21544:word16];
	Mem1207[ss:sp_1197 + -4:word16] = Mem1204[ds_1108:21558:word16];
	(ss->*sp_1197).tFFFA.u2 = (uint16) ds_1108;
	(ss->*sp_1197).tFFF8.u2 = (uint16) 0x54D4;
	(ss->*sp_1197).wFFF6 = 0x01;
	word16 dx_1608;
	word16 bp_1609;
	Eq_17 ds_1223;
	fn0800_19E1(ds_1108, (ss->*sp_1197).tFFF8.u3, out dx_1608, out bp_1609, out ds_1223);
	fn0C74_0A35(ds_1223);
	word16 bp_1610;
	Eq_17 ds_1250;
	fn1206_0066(ds_1223, out bp_1610, out ds_1250);
	ds_1009 = fn0800_0000(ds_1250);
	return ds_1009;
}
