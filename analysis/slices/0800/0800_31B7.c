// 0800:31B7: Register Eq_526 fn0800_31B7(Register int16 dx, Register Eq_17 ds, Register out Eq_17 dsOut)
// Called from:
//      fn0800_3D9D
Eq_526 fn0800_31B7(int16 dx, Eq_17 ds, union Eq_17 & dsOut)
{
	Eq_17 ds_2025;
	word16 bp_2211;
	Eq_17 ds_1979;
	byte ch_2218;
	Eq_17 ds_1946;
	byte ch_2216;
	while (fn1E78_02FB(ds) != 0x00)
	{
		Eq_17 wLoc0288;
		fn1E78_030D(dx, ds, wLoc0288, out dx);
	}
	Eq_17 ss;
	<unknown> Eq_17::* fp;
	Eq_17 cs;
	word16 dx_2182;
	fn1EDA_0A39(~0x00, SEQ(ss, fp - 0x0206), SEQ(cs, 0x3112), out dx_2182);
	struct Eq_12604 Eq_17::* bp_210;
	Eq_17 ds_218;
	fn1206_0066(ds, out bp_210, out ds_218);
	Eq_481 sp_60;
	sp_60.u0 = <invalid>;
	ss->*((word16) sp_60 - 2) = 0x08;
	fn1AB8_1C32(ds_218, ss->*((word16) sp_60 - 2));
	ss->*((word16) sp_60 - 2) = 0x00;
	ss->*((word16) sp_60 - 4) = 0x00;
	ss->*((word16) sp_60 - 6) = 0x01;
	fn1AB8_10F4(ds_218, ss->*((word16) sp_60 - 6), ss->*((word16) sp_60 - 4), ss->*((word16) sp_60 - 2));
	ss->*((word16) sp_60 - 2) = 0x00;
	ss->*((word16) sp_60 - 4) = 0x00;
	ss->*((word16) sp_60 - 6) = 0x027F;
	ss->*((word16) sp_60 - 8) = 0x0177;
	fn1AB8_112E(ds_218, ss->*((word16) sp_60 - 8), ss->*((word16) sp_60 - 6), ss->*((word16) sp_60 - 4), ss->*((word16) sp_60 - 2));
	ss->*((word16) sp_60 - 2) = 0x00;
	ss->*((word16) sp_60 - 4) = 377;
	ss->*((word16) sp_60 - 6) = 0x027F;
	ss->*((word16) sp_60 - 8) = 0x01DF;
	fn0800_0024(ds_218, ss->*((word16) sp_60 - 8), ss->*((word16) sp_60 - 6), ss->*((word16) sp_60 - 4), ss->*((word16) sp_60 - 2));
	ss->*((word16) sp_60 - 2) = 0x03;
	ss->*((word16) sp_60 - 4) = 0x017B;
	ss->*((word16) sp_60 - 6) = 636;
	ss->*((word16) sp_60 - 8) = 474;
	fn0800_1315(ds_218, ss->*((word16) sp_60 - 8), ss->*((word16) sp_60 - 6), ss->*((word16) sp_60 - 4), ss->*((word16) sp_60 - 2));
	ss->*((word16) sp_60 - 2) = ds_218;
	ss->*((word16) sp_60 - 4) = 23732;
	ss->*((word16) sp_60 - 6) = ds_218;
	ss->*((word16) sp_60 - 8) = 0x5ECE;
	ss->*((word16) sp_60 - 0x0A) = 0x06;
	word16 dx_2183;
	fn1EDA_0A39(ss->*((word16) sp_60 + 0x0A), ss->*((word16) sp_60 - 8), ss->*((word16) sp_60 - 4), out dx_2183);
	ss->*((word16) sp_60 - 2) = ds_218;
	ss->*((word16) sp_60 - 4) = 23732;
	ss->*((word16) sp_60 - 6) = ds_218;
	ss->*((word16) sp_60 - 8) = 24278;
	ss->*((word16) sp_60 - 0x0A) = 0x06;
	word16 dx_2184;
	fn1EDA_0A39(ss->*((word16) sp_60 + 0x0A), ss->*((word16) sp_60 - 8), ss->*((word16) sp_60 - 4), out dx_2184);
	Mem190[ds_218:0x53D9:byte] = Mem175[ds_218:23774:byte];
	Mem192[ds_218:21466:byte] = Mem190[ds_218:23775:byte];
	Mem194[ds_218:0x53DB:byte] = Mem192[ds_218:23770:byte];
	Mem196[ds_218:0x53DC:byte] = Mem194[ds_218:23771:byte];
	Eq_481 sp_188 = sp_60;
	if (Mem196[ds_218:23772:byte] >u 0x0A)
		Mem199[ds_218:23772:byte] = 0x0A;
	Mem203[ds_218:0x53DD:byte] = Mem201[ds_218:23772:byte];
	Mem205[ds_218:0x53DE:byte] = Mem203[ds_218:23773:byte];
	(ss->*bp_210).tFFFE.u0 = 0x00;
	while (true)
	{
		struct Eq_12902 Eq_17::* sp_214 = sp_188 - 2;
		(ss->*sp_214).t0000.u2 = (uint16) (ss->*bp_210).tFFFE.u0;
		word16 bp_2185;
		Eq_17 ds_225;
		fn0800_09C2(ds_218, (ss->*sp_214).t0000.u0, out bp_2185, out ds_225);
		fn1206_0066(ds_225, out bp_210, out ds_218);
		sp_188.u0 = <invalid>;
		if ((ss->*bp_210).tFFFE.u0 == 0x08)
			break;
		(ss->*bp_210).tFFFE.u0 = (int8) ((ss->*bp_210).tFFFE.u0 + 0x01);
	}
	ss->*((word16) sp_188 - 2) = 0x00;
	ss->*((word16) sp_188 - 4) = 0x00;
	ss->*((word16) sp_188 - 6) = 0x01;
	Eq_17 ds_268;
	fn1AB8_1536(ds_218, ss->*((word16) sp_188 - 6), ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2), out ds_268);
	ss->*((word16) sp_188 - 2) = 0x01;
	ss->*((word16) sp_188 - 4) = 0x01;
	fn1AB8_14F4(ds_268, ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2));
	ss->*((word16) sp_188 - 2) = 0x08;
	fn1AB8_1C32(ds_268, ss->*((word16) sp_188 - 2));
	ss->*((word16) sp_188 - 2) = 0x43;
	ss->*((word16) sp_188 - 4) = 0x01CE;
	ss->*((word16) sp_188 - 6) = cs;
	ss->*((word16) sp_188 - 8) = 0x3153;
	byte ch_2186;
	fn1AB8_1D82(ds_268, ss->*((word16) sp_188 - 8), ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2), out ch_2186);
	ss->*((word16) sp_188 - 2) = 0x93;
	ss->*((word16) sp_188 - 4) = 0x01CE;
	ss->*((word16) sp_188 - 6) = cs;
	ss->*((word16) sp_188 - 8) = 0x315B;
	byte ch_2187;
	fn1AB8_1D82(ds_268, ss->*((word16) sp_188 - 8), ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2), out ch_2187);
	ss->*((word16) sp_188 - 2) = 227;
	ss->*((word16) sp_188 - 4) = 0x01CE;
	ss->*((word16) sp_188 - 6) = cs;
	ss->*((word16) sp_188 - 8) = 0x3153;
	byte ch_2188;
	fn1AB8_1D82(ds_268, ss->*((word16) sp_188 - 8), ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2), out ch_2188);
	ss->*((word16) sp_188 - 2) = 303;
	ss->*((word16) sp_188 - 4) = 0x01CE;
	ss->*((word16) sp_188 - 6) = cs;
	ss->*((word16) sp_188 - 8) = 12642;
	byte ch_2189;
	fn1AB8_1D82(ds_268, ss->*((word16) sp_188 - 8), ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2), out ch_2189);
	ss->*((word16) sp_188 - 2) = 355;
	ss->*((word16) sp_188 - 4) = 0x01CE;
	ss->*((word16) sp_188 - 6) = cs;
	ss->*((word16) sp_188 - 8) = 0x3165;
	byte ch_2190;
	fn1AB8_1D82(ds_268, ss->*((word16) sp_188 - 8), ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2), out ch_2190);
	ss->*((word16) sp_188 - 2) = 0x0197;
	ss->*((word16) sp_188 - 4) = 0x01CE;
	ss->*((word16) sp_188 - 6) = cs;
	ss->*((word16) sp_188 - 8) = 0x3168;
	byte ch_2191;
	fn1AB8_1D82(ds_268, ss->*((word16) sp_188 - 8), ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2), out ch_2191);
	ss->*((word16) sp_188 - 2) = 0x01CB;
	ss->*((word16) sp_188 - 4) = 0x01CE;
	ss->*((word16) sp_188 - 6) = cs;
	ss->*((word16) sp_188 - 8) = 12651;
	byte ch_2192;
	fn1AB8_1D82(ds_268, ss->*((word16) sp_188 - 8), ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2), out ch_2192);
	ss->*((word16) sp_188 - 2) = 11;
	fn1AB8_1C32(ds_268, ss->*((word16) sp_188 - 2));
	ss->*((word16) sp_188 - 2) = 0x44;
	ss->*((word16) sp_188 - 4) = 0x01CF;
	ss->*((word16) sp_188 - 6) = cs;
	ss->*((word16) sp_188 - 8) = 0x3153;
	byte ch_2193;
	fn1AB8_1D82(ds_268, ss->*((word16) sp_188 - 8), ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2), out ch_2193);
	ss->*((word16) sp_188 - 2) = 0x94;
	ss->*((word16) sp_188 - 4) = 0x01CF;
	ss->*((word16) sp_188 - 6) = cs;
	ss->*((word16) sp_188 - 8) = 0x315B;
	byte ch_2194;
	fn1AB8_1D82(ds_268, ss->*((word16) sp_188 - 8), ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2), out ch_2194);
	ss->*((word16) sp_188 - 2) = 228;
	ss->*((word16) sp_188 - 4) = 0x01CF;
	ss->*((word16) sp_188 - 6) = cs;
	ss->*((word16) sp_188 - 8) = 0x3153;
	byte ch_2195;
	fn1AB8_1D82(ds_268, ss->*((word16) sp_188 - 8), ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2), out ch_2195);
	ss->*((word16) sp_188 - 2) = 0x0130;
	ss->*((word16) sp_188 - 4) = 0x01CF;
	ss->*((word16) sp_188 - 6) = cs;
	ss->*((word16) sp_188 - 8) = 12642;
	byte ch_2196;
	fn1AB8_1D82(ds_268, ss->*((word16) sp_188 - 8), ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2), out ch_2196);
	ss->*((word16) sp_188 - 2) = 0x0164;
	ss->*((word16) sp_188 - 4) = 0x01CF;
	ss->*((word16) sp_188 - 6) = cs;
	ss->*((word16) sp_188 - 8) = 0x3165;
	byte ch_2197;
	fn1AB8_1D82(ds_268, ss->*((word16) sp_188 - 8), ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2), out ch_2197);
	ss->*((word16) sp_188 - 2) = 0x0198;
	ss->*((word16) sp_188 - 4) = 0x01CF;
	ss->*((word16) sp_188 - 6) = cs;
	ss->*((word16) sp_188 - 8) = 0x3168;
	byte ch_2198;
	fn1AB8_1D82(ds_268, ss->*((word16) sp_188 - 8), ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2), out ch_2198);
	ss->*((word16) sp_188 - 2) = 0x01CC;
	ss->*((word16) sp_188 - 4) = 0x01CF;
	ss->*((word16) sp_188 - 6) = cs;
	ss->*((word16) sp_188 - 8) = 12651;
	byte ch_2199;
	fn1AB8_1D82(ds_268, ss->*((word16) sp_188 - 8), ss->*((word16) sp_188 - 4), ss->*((word16) sp_188 - 2), out ch_2199);
	ss->*((word16) sp_188 - 2) = 0x00;
	fn1AB8_1C32(ds_268, ss->*((word16) sp_188 - 2));
	ss->*((word16) sp_188 - 2) = 0x01;
	ss->*((word16) sp_188 - 4) = 22;
	ss->*((word16) sp_188 - 4) = fn0800_04CC(ss->*((word16) sp_188 - 4));
	struct Eq_13540 * ds_601;
	fn1206_00FF(ds_268, out ds_601);
	Eq_481 sp_605;
	sp_605.u0 = <invalid>;
	ss->*((word16) sp_605 + 2) = 0x0198;
	ss->*sp_605 = 0x01D1;
	struct Eq_13558 * ds_620;
	fn1206_012D(ds_601, out ds_620);
	Eq_481 sp_624;
	sp_624.u0 = <invalid>;
	ss->*((word16) sp_624 + 2) = 0x9C;
	ss->*sp_624 = 0x01B4;
	word16 si_2200;
	selector es_2201;
	Eq_17 ds_639;
	fn1206_00D1(ds_620, out si_2200, out es_2201, out ds_639);
	Eq_481 sp_643;
	sp_643.u0 = <invalid>;
	ss->*((word16) sp_643 + 2) = 0x00;
	ss->*sp_643 = 0x00;
	ss->*((word16) sp_643 - 2) = 0x01;
	Eq_17 ds_662;
	fn1AB8_1536(ds_639, ss->*((word16) sp_643 - 2), ss->*sp_643, ss->*((word16) sp_643 + 2), out ds_662);
	ss->*((word16) sp_643 + 2) = 0x01;
	ss->*sp_643 = 0x01;
	fn1AB8_14F4(ds_662, ss->*sp_643, ss->*((word16) sp_643 + 2));
	ss->*((word16) sp_643 + 2) = 0x0F;
	ss->*sp_643 = 388;
	ss->*((word16) sp_643 - 2) = 0x0114;
	ss->*((word16) sp_643 - 4) = 399;
	fn0800_005A(ds_662, ss->*((word16) sp_643 - 4), ss->*((word16) sp_643 - 2), ss->*sp_643, ss->*((word16) sp_643 + 2));
	ss->*((word16) sp_643 + 2) = 0x08;
	fn1AB8_1C32(ds_662, ss->*((word16) sp_643 + 2));
	ss->*((word16) sp_643 + 2) = 0x93;
	ss->*sp_643 = 393;
	ss->*((word16) sp_643 - 2) = ds_662;
	ss->*((word16) sp_643 - 4) = 0x5CBB;
	byte ch_2202;
	fn1AB8_1D82(ds_662, ss->*((word16) sp_643 - 4), ss->*sp_643, ss->*((word16) sp_643 + 2), out ch_2202);
	ss->*((word16) sp_643 + 2) = 0x0A;
	fn1AB8_1C32(ds_662, ss->*((word16) sp_643 + 2));
	ss->*((word16) sp_643 + 2) = 0x94;
	ss->*sp_643 = 0x018A;
	ss->*((word16) sp_643 - 2) = ds_662;
	ss->*((word16) sp_643 - 4) = 0x5CBB;
	byte ch_2203;
	fn1AB8_1D82(ds_662, ss->*((word16) sp_643 - 4), ss->*sp_643, ss->*((word16) sp_643 + 2), out ch_2203);
	Eq_17 ds_754;
	fn0800_04E3(ds_662, out ds_754);
	Eq_17 ds_781 = fn0800_0BEC(fn0800_0619(ds_754));
	Eq_481 sp_785;
	sp_785.u0 = <invalid>;
	ss->*((word16) sp_785 - 2) = 0x08;
	ss->*((word16) sp_785 - 4) = 0x00;
	fn1AB8_1342(ds_781, ss->*((word16) sp_785 - 4), ss->*((word16) sp_785 - 2));
	Mem808[ss:sp_785 + -2:word16] = CONVERT(Mem794[ds_781:0x53D9:byte], uint8, uint16);
	Eq_17 ax_809 = fn0800_04CC(ss->*((word16) sp_785 - 2));
	ss->*((word16) sp_785 - 2) = ax_809;
	Mem821[ss:sp_785 + -4:word16] = SEQ(SLICE(ax_809, byte, 8), Mem816[ds_781:21466:byte]);
	ss->*((word16) sp_785 - 4) = fn0800_04CC(ss->*((word16) sp_785 - 4));
	Eq_17 ds_835 = fn0C74_06B7(ds_781, ss->*((word16) sp_785 - 4), ss->*((word16) sp_785 - 2));
	Eq_481 sp_839;
	sp_839.u0 = <invalid>;
	ss->*((word16) sp_839 + 2) = 11;
	word16 bp_2204;
	Eq_17 ds_2243;
	fn0800_09C2(ds_835, ss->*((word16) sp_839 + 2), out bp_2204, out ds_2243);
	Eq_481 sp_856;
	sp_856.u0 = <invalid>;
	struct Eq_13862 Eq_17::* sp_862 = (word16) sp_856 + 2;
	while (fn1E78_02FB(ds_2243) == 0x00)
	{
		(ss->*sp_862).wFFFE = 0x00;
		Eq_481 sp_888;
		sp_888.u0 = <invalid>;
		sp_862 = (word16) sp_888 + 2;
		byte ch_2205;
		word16 dx_2206;
		word16 bp_2207;
		if ((byte) fn1206_015B(ds_2243, out ch_2205, out dx_2206, out bp_2207, out ds_2243) != 0x00)
			break;
	}
	union Eq_17 Eq_17::* sp_901 = sp_862 - 2;
	(ss->*sp_901).u2 = (uint16) 0x02;
	struct Eq_13877 Eq_17::* bp_1120;
	Eq_17 ds_1001;
	fn0800_09C2(ds_2243, (ss->*sp_901).u0, out bp_1120, out ds_1001);
	Eq_481 sp_916;
	sp_916.u0 = <invalid>;
	Eq_17 ax_933 = CONVERT(Mem903[ds_1001:0x53DD:byte], uint8, uint16) *s 0x3C;
	ss->*sp_916 = 0x00;
	ss->*((word16) sp_916 - 2) = ax_933;
	int16 dx_1012;
	fn0800_00C1(ds_1001, ss->*((word16) sp_916 - 2), ss->*sp_916, out dx_1012);
	(ss->*bp_1120).bFFFF = 0x01;
	Eq_481 sp_1005 = (word16) sp_916 + 2;
	do
	{
		if (fn1E78_02FB(ds_1001) == 0x00)
		{
			ss->*((word16) sp_1005 - 2) = 0x00;
			Eq_481 sp_971;
			sp_971.u0 = <invalid>;
			sp_1005 = (word16) sp_971 + 2;
			byte ch_2208;
			if ((byte) fn1206_015B(ds_1001, out ch_2208, out dx_1012, out bp_1120, out ds_1001) == 0x00)
				goto l0800_364A;
		}
		byte ah_1043;
		if (fn1E78_02FB(ds_1001) != 0x00)
		{
			int16 dx_1020;
			Mem1027[ds_1001:0x53D2:byte] = SLICE(fn1E78_030D(dx_1012, ds_1001, ss->*((word16) sp_1005 - 2), out dx_1020), byte, 0);
			if (Mem1027[ds_1001:0x53D2:byte] == 0x00)
				Mem1040[ds_1001:0x53D2:byte] = SLICE(fn1E78_030D(dx_1020, ds_1001, ss->*((word16) sp_1005 - 2), out dx_1020), byte, 0);
			while (true)
			{
				ah_1043 = <invalid>;
				if (fn1E78_02FB(ds_1001) == 0x00)
					break;
				fn1E78_030D(dx_1020, ds_1001, ss->*((word16) sp_1005 - 2), out dx_1020);
			}
		}
		else
		{
			word16 ax_996 = fn0800_031B(ds_1001, out bp_1120, out ds_1001);
			Mem1011[ds_1001:0x53D2:byte] = SLICE(ax_996, byte, 0);
			sp_1005.u0 = <invalid>;
			ah_1043 = SLICE(ax_996, byte, 8);
		}
		Eq_526 al_1056 = Mem1054[ds_1001:0x53D2:byte];
		switch (al_1056)
		{
		case 0x3B:
			struct Eq_14041 Eq_17::* sp_1651 = sp_1005 - 2;
			(ss->*sp_1651).t0000.u2 = (uint16) 0x0E;
			word16 bp_2209;
			Eq_17 ds_1658;
			fn0800_09C2(ds_1001, (ss->*sp_1651).t0000.u0, out bp_2209, out ds_1658);
			Eq_481 sp_1662;
			sp_1662.u0 = <invalid>;
			Eq_481 sp_1668 = (word16) sp_1662 + 2;
			if (Mem1652[ds_1658:0x53DB:byte] >u 0x00)
			{
				sp_1668.u0 = <invalid>;
				word16 bp_2210;
				if (fn0C74_522C(ds_1658, out bp_2210, out ds_1658) != 0x00)
					Mem1692[ds_1658:0x53DB:byte] = Mem1652[ds_1658:0x53DB:byte] - 0x01;
			}
			union Eq_17 Eq_17::* sp_1695 = sp_1668 - 2;
			(ss->*sp_1695).u2 = (uint16) 0x05;
			fn0800_09C2(ds_1658, (ss->*sp_1695).u0, out bp_1120, out ds_1001);
			Eq_481 sp_1709;
			sp_1709.u0 = <invalid>;
			ah_1043 = 0x00;
			sp_1005 = (word16) sp_1709 + 2;
			break;
		case 0x3C:
			struct Eq_14419 Eq_17::* sp_1586 = sp_1005 - 2;
			(ss->*sp_1586).t0000.u2 = (uint16) 0x0F;
			word16 bp_2224;
			Eq_17 ds_1593;
			fn0800_09C2(ds_1001, (ss->*sp_1586).t0000.u0, out bp_2224, out ds_1593);
			Eq_481 sp_1597;
			sp_1597.u0 = <invalid>;
			Eq_481 sp_1603 = (word16) sp_1597 + 2;
			if (Mem1587[ds_1593:0x53DC:byte] >u 0x00)
			{
				sp_1603.u0 = <invalid>;
				if (fn0C74_542B(ds_1593, out ds_1593) != 0x00)
					Mem1627[ds_1593:0x53DC:byte] = Mem1587[ds_1593:0x53DC:byte] - 0x01;
			}
			union Eq_17 Eq_17::* sp_1630 = sp_1603 - 2;
			(ss->*sp_1630).u2 = (uint16) 0x06;
			fn0800_09C2(ds_1593, (ss->*sp_1630).u0, out bp_1120, out ds_1001);
			Eq_481 sp_1644;
			sp_1644.u0 = <invalid>;
			ah_1043 = 0x00;
			sp_1005 = (word16) sp_1644 + 2;
			break;
		case 0x3D:
			struct Eq_14509 Eq_17::* sp_1523 = sp_1005 - 2;
			(ss->*sp_1523).t0000.u2 = (uint16) 0x10;
			word16 bp_2225;
			Eq_17 ds_1530;
			fn0800_09C2(ds_1001, (ss->*sp_1523).t0000.u0, out bp_2225, out ds_1530);
			Eq_481 sp_1534;
			sp_1534.u0 = <invalid>;
			if (Mem1524[ds_1530:0x53DE:byte] >u 0x00 && fn0C74_5258(ds_1530, out ds_1530) != 0x00)
				Mem1562[ds_1530:0x53DE:byte] = Mem1524[ds_1530:0x53DE:byte] - 0x01;
			ss->*sp_1534 = 0x07;
			fn0800_09C2(ds_1530, ss->*sp_1534, out bp_1120, out ds_1001);
			Eq_481 sp_1579;
			sp_1579.u0 = <invalid>;
			ah_1043 = 0x00;
			sp_1005 = (word16) sp_1579 + 2;
			break;
		default:
			if (al_1056 == 0x1B)
			{
				fn0800_0103(ds_1001);
				goto l0800_36E4;
			}
			if (al_1056 == 0x20)
			{
				Eq_17 dx_1412 = Mem1054[ds_1001:22746:word16];
				Mem1413[ds_1001:0x58D0:word16] = Mem1054[ds_1001:22744:word16];
				Mem1414[ds_1001:22738:word16] = dx_1412;
				fn0800_0103(ds_1001);
				struct Eq_14594 Eq_17::* sp_1422 = sp_1005 - 2;
				(ss->*sp_1422).t0000.u2 = (uint16) 11;
				word16 bp_2226;
				Eq_17 ds_1429;
				fn0800_09C2(ds_1001, (ss->*sp_1422).t0000.u0, out bp_2226, out ds_1429);
				Eq_481 sp_1433;
				sp_1433.u0 = <invalid>;
				struct Eq_14613 Eq_17::* sp_1439 = (word16) sp_1433 + 2;
				while (fn1E78_02FB(ds_1429) == 0x00)
				{
					(ss->*sp_1439).wFFFE = 0x00;
					Eq_481 sp_1465;
					sp_1465.u0 = <invalid>;
					sp_1439 = (word16) sp_1465 + 2;
					byte ch_2228;
					word16 dx_2229;
					word16 bp_2230;
					if ((byte) fn1206_015B(ds_1429, out ch_2228, out dx_2229, out bp_2230, out ds_1429) != 0x00)
						break;
				}
				union Eq_17 Eq_17::* sp_1478 = sp_1439 - 2;
				(ss->*sp_1478).u2 = (uint16) 0x02;
				fn0800_09C2(ds_1429, (ss->*sp_1478).u0, out bp_1120, out ds_1001);
				Eq_481 sp_1493;
				sp_1493.u0 = <invalid>;
				Mem1502[ss:sp_1493 + 0x00:word16] = Mem1480[ds_1001:22738:word16];
				Mem1505[ss:sp_1493 + -2:word16] = Mem1502[ds_1001:0x58D0:word16];
				word16 dx_2227;
				fn0800_00C1(ds_1001, ss->*((word16) sp_1493 - 2), ss->*sp_1493, out dx_2227);
				ah_1043 = 0x00;
				sp_1005 = (word16) sp_1493 + 2;
			}
			else if (al_1056 == 0x44)
			{
				if (Mem1054[ds_1001:0x58B0:byte] != 0x00)
					Mem1410[ds_1001:0x58B0:byte] = 0x00;
				else
					Mem1409[ds_1001:0x58B0:byte] = 0x01;
			}
			else if (al_1056 == 0x48)
			{
				struct Eq_14703 Eq_17::* sp_1355 = sp_1005 - 2;
				(ss->*sp_1355).t0000.u2 = (uint16) 0x09;
				word16 bp_2231;
				Eq_17 ds_1362;
				fn0800_09C2(ds_1001, (ss->*sp_1355).t0000.u0, out bp_2231, out ds_1362);
				Eq_17 ds_1378 = fn0C74_51AA(ds_1362);
				Eq_481 sp_1382;
				sp_1382.u0 = <invalid>;
				ss->*((word16) sp_1382 - 2) = 0x00;
				fn0800_09C2(ds_1378, ss->*((word16) sp_1382 - 2), out bp_1120, out ds_1001);
				Eq_481 sp_1400;
				sp_1400.u0 = <invalid>;
				ah_1043 = 0x00;
				sp_1005 = (word16) sp_1400 + 2;
			}
			else if (al_1056 == 0x4B)
			{
				struct Eq_14744 Eq_17::* sp_1245 = sp_1005 - 2;
				(ss->*sp_1245).t0000.u2 = (uint16) 0x0A;
				word16 bp_2232;
				Eq_17 ds_1252;
				fn0800_09C2(ds_1001, (ss->*sp_1245).t0000.u0, out bp_2232, out ds_1252);
				Eq_481 sp_1272;
				sp_1272.u0 = <invalid>;
				word16 dx_2233;
				word16 bp_2234;
				Eq_17 ds_1268;
				if (fn0C74_54F0(ds_1252, out dx_2233, out bp_2234, out ds_1268) == 0x00)
				{
					ss->*((word16) sp_1272 - 2) = 0x0E;
					word16 bp_2235;
					Eq_17 ds_1290;
					fn0800_09C2(ds_1268, ss->*((word16) sp_1272 - 2), out bp_2235, out ds_1290);
					Eq_17 ds_1306 = fn0800_08C0(ds_1290);
					Eq_481 sp_1310;
					sp_1310.u0 = <invalid>;
					ss->*((word16) sp_1310 - 2) = 0x05;
					word16 bp_2236;
					fn0800_09C2(ds_1306, ss->*((word16) sp_1310 - 2), out bp_2236, out ds_1268);
					Eq_481 sp_1326;
					sp_1326.u0 = <invalid>;
					sp_1272 = (word16) sp_1326 + 2;
				}
				union Eq_17 Eq_17::* sp_1334 = sp_1272 - 2;
				(ss->*sp_1334).u2 = (uint16) 0x01;
				fn0800_09C2(ds_1268, (ss->*sp_1334).u0, out bp_1120, out ds_1001);
				Eq_481 sp_1348;
				sp_1348.u0 = <invalid>;
				ah_1043 = 0x00;
				sp_1005 = (word16) sp_1348 + 2;
			}
			else if (al_1056 == 77)
			{
				struct Eq_14831 Eq_17::* sp_1135 = sp_1005 - 2;
				(ss->*sp_1135).t0000.u2 = (uint16) 0x0C;
				word16 bp_2237;
				Eq_17 ds_1142;
				fn0800_09C2(ds_1001, (ss->*sp_1135).t0000.u0, out bp_2237, out ds_1142);
				Eq_481 sp_1162;
				sp_1162.u0 = <invalid>;
				word16 dx_2238;
				word16 bp_2239;
				Eq_17 ds_1158;
				if (fn0C74_54B1(ds_1142, out dx_2238, out bp_2239, out ds_1158) == 0x00)
				{
					ss->*((word16) sp_1162 - 2) = 0x0E;
					word16 bp_2240;
					Eq_17 ds_1180;
					fn0800_09C2(ds_1158, ss->*((word16) sp_1162 - 2), out bp_2240, out ds_1180);
					Eq_17 ds_1196 = fn0800_08C0(ds_1180);
					Eq_481 sp_1200;
					sp_1200.u0 = <invalid>;
					ss->*((word16) sp_1200 - 2) = 0x05;
					word16 bp_2241;
					fn0800_09C2(ds_1196, ss->*((word16) sp_1200 - 2), out bp_2241, out ds_1158);
					Eq_481 sp_1216;
					sp_1216.u0 = <invalid>;
					sp_1162 = (word16) sp_1216 + 2;
				}
				union Eq_17 Eq_17::* sp_1224 = sp_1162 - 2;
				(ss->*sp_1224).u2 = (uint16) 0x03;
				fn0800_09C2(ds_1158, (ss->*sp_1224).u0, out bp_1120, out ds_1001);
				Eq_481 sp_1238;
				sp_1238.u0 = <invalid>;
				ah_1043 = 0x00;
				sp_1005 = (word16) sp_1238 + 2;
			}
			else if (al_1056 == 0x50)
			{
				struct Eq_14916 Eq_17::* sp_1079 = sp_1005 - 2;
				(ss->*sp_1079).t0000.u2 = (uint16) 0x0D;
				word16 bp_2242;
				Eq_17 ds_1092;
				fn0800_09C2(ds_1001, (ss->*sp_1079).t0000.u0, out bp_2242, out ds_1092);
				Eq_17 ds_1110 = fn0C74_51B2(ds_1092);
				Eq_481 sp_1112;
				sp_1112.u0 = <invalid>;
				ss->*((word16) sp_1112 - 2) = 0x04;
				fn0800_09C2(ds_1110, ss->*((word16) sp_1112 - 2), out bp_1120, out ds_1001);
				Eq_481 sp_1128;
				sp_1128.u0 = <invalid>;
				ah_1043 = 0x00;
				sp_1005 = (word16) sp_1128 + 2;
			}
			break;
		}
		struct Eq_14312 Eq_17::* sp_1723 = sp_1005 - 2;
		Mem1739[ss:sp_1723 + 0x00:word16] = SEQ(ah_1043, Mem1718[ds_1001:0x53D2:byte]);
		(ss->*sp_1723).tFFFE.u2 = (uint16) cs;
		(ss->*sp_1723).tFFFC.u2 = (uint16) 12655;
		selector es_2222;
		if (!fn1EDA_0CD4((ss->*sp_1723).tFFFC.u3, (ss->*sp_1723).t0000.u0, out es_2222))
		{
			Mem1767[ss:bp_1120 - 0x0204 + CONVERT(Mem1746[ss:bp_1120 + -1:byte], uint8, uint16):byte] = Mem1746[ds_1001:0x53D2:byte];
			if ((ss->*bp_1120).bFFFF < ~0x00)
				++(ss->*bp_1120).bFFFF;
			Mem1781[ss:sp_1723 + 0x00:word16] = CONVERT(Mem1774[ds_1001:0x53D2:byte], uint8, uint16);
			(ss->*sp_1723).tFFFE.u2 = (uint16) cs;
			(ss->*sp_1723).tFFFC.u2 = (uint16) 0x318F;
			selector es_2223;
			if (!fn1EDA_0CD4((ss->*sp_1723).tFFFC.u3, (ss->*sp_1723).t0000.u0, out es_2223))
			{
				Mem1805[ss:bp_1120 - 0x0204 + CONVERT(Mem1787[ss:bp_1120 + -1:byte], uint8, uint16):byte] = Mem1787[ds_1001:22716:byte];
				if ((ss->*bp_1120).bFFFF < ~0x00)
					++(ss->*bp_1120).bFFFF;
			}
		}
l0800_364A:
		dx_1012 = fn0800_0C71(ds_1001, out bp_1120, out ds_1001);
		sp_1005.u0 = <invalid>;
	} while (fn0800_0877(ds_1001) == 0x00 && Mem1852[ds_1001:22707:byte] == 0x00);
	if (fn0800_0877(ds_1001) != 0x00)
	{
		ss->*((word16) sp_1005 - 2) = ss;
		ss->*((word16) sp_1005 - 4) = bp_1120 - 644;
		ss->*((word16) sp_1005 - 6) = cs;
		ss->*((word16) sp_1005 - 8) = 12719;
		fn1EDA_0FA2(ss->*((word16) sp_1005 - 8), ss->*((word16) sp_1005 - 4));
		ss->*((word16) sp_1005 - 2) = ss;
		ss->*((word16) sp_1005 - 4) = bp_1120 - 644;
		ss->*((word16) sp_1005 - 6) = 0x0100;
		word16 dx_2212;
		fn1EDA_0FD0(ds_1001, ss->*((word16) sp_1005 - 6), ss->*((word16) sp_1005 - 4), out dx_2212);
		byte ch_2214;
		Eq_17 ds_1914;
		fn1EDA_04A9(ds_1001, ss->*((word16) sp_1005 - 4), ss->*((word16) sp_1005 - 2), out ch_2214, out ds_1914);
		ss->*((word16) sp_1005 - 2) = ss;
		ss->*((word16) sp_1005 - 4) = bp_1120 - 644;
		Mem1928[ss:sp_1005 + -6:word16] = Mem1925[ds_1914:22928:word16];
		Mem1931[ss:sp_1005 + -8:word16] = Mem1928[ds_1914:22926:word16];
		fn1EDA_1123(ds_1914, ss->*((word16) sp_1005 - 8), ss->*((word16) sp_1005 - 6), ss->*((word16) sp_1005 - 4));
		byte al_1963 = (byte) fn1EDA_04A9(ds_1914, ss->*((word16) sp_1005 - 4), ss->*((word16) sp_1005 - 2), out ch_2216, out ds_1946);
		ss->*((word16) sp_1005 - 2) = ss;
		ss->*((word16) sp_1005 - 4) = bp_1120 - 644;
		ss->*((word16) sp_1005 - 6) = ss;
		ss->*((word16) sp_1005 - 8) = bp_1120 - 0x0204;
		fn1EDA_108C(al_1963, ds_1946, ss->*((word16) sp_1005 - 4));
		word16 ax_1976 = (word16) fn1EDA_04A9(ds_1946, ss->*((word16) sp_1005 + 0x0000FFF8), ss->*((word16) sp_1005 - 6), out ch_2218, out ds_1979);
		ss->*((word16) sp_1005 - 6) = ss;
		ss->*((word16) sp_1005 - 8) = bp_1120 - 644;
		fn1EDA_1051((byte) ax_1976, ds_1979, ss->*((word16) sp_1005 - 8));
		byte ch_2221;
		fn1EDA_04A9(ds_1979, ss->*((word16) sp_1005 + 0x0000FFF8), ss->*((word16) sp_1005 - 6), out ch_2221, out ds_1001);
	}
	fn0800_0103(ds_1001);
	int16 dx_2026 = fn0800_0768(ds_1001, out bp_2211, out ds_2025);
	Eq_481 sp_2029;
	sp_2029.u0 = <invalid>;
	while (fn1E78_02FB(ds_2025) != 0x00)
		fn1E78_030D(dx_2026, ds_2025, ss->*((word16) sp_2029 - 2), out dx_2026);
	fn1206_0066(ds_2025, out bp_1120, out ds_1001);
l0800_36E4:
	Eq_526 bp_2067;
	bp_2067.u1 = (ss->*bp_1120).a0000[0].u1;
	dsOut = ds_1001;
	return bp_2067;
}
