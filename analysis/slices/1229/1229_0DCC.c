// 1229:0DCC: Register word16 fn1229_0DCC(Register Eq_17 ds, Stack Eq_17 ptrArg04, Register out word16 bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0800_3D9D
word16 fn1229_0DCC(Eq_17 ds, Eq_17 ptrArg04, word16 & bpOut, union Eq_17 & dsOut)
{
	struct Eq_54601 Eq_17::* bp_186;
	Eq_17 ss;
	<unknown> Eq_17::* fp;
	word16 dx_1359;
	fn1EDA_0A39(~0x00, SEQ(ss, fp - 0x0102), ptrArg04, out dx_1359);
	fn1AB8_0F80(ds);
	fn1AB8_1CBA(ds, 0x3F, 0x3F, 0x3F, 0x0F);
	word16 dx_1360;
	fn1EDA_0A39(~0x00, SEQ(ds, 0x6BBA), SEQ(ss, fp - 0x0102), out dx_1360);
	Mem88[ds:0x62DB:byte] = 0x00;
	Mem89[ds:25291:byte] = 0x01;
	Mem90[ds:0x6CBA:byte] = 0x00;
	fn1229_039D(fn13C8_0111(0x01));
	fn1229_0CCE();
	int16 dx_1022;
	struct Eq_54433 Eq_17::* bp_138;
	Eq_17 ds_1002;
	fn133F_0141(out dx_1022, out bp_138, out ds_1002);
	(ss->*bp_138).bFEFF = 0x00;
	Eq_481 sp_1000;
	sp_1000.u0 = <invalid>;
	byte ah_1019 = 0x00;
	do
	{
		struct Eq_54543 Eq_17::* sp_155 = sp_1000 - 2;
		(ss->*sp_155).t0000.u2 = (uint16) ds_1002;
		(ss->*sp_155).tFFFE.u0 = 25294;
		(ss->*sp_155).tFFFC.u2 = (uint16) ds_1002;
		(ss->*sp_155).tFFFA.u0 = 0x62D0;
		(ss->*sp_155).tFFF8.u2 = (uint16) ds_1002;
		(ss->*sp_155).tFFF6.u0 = 0x62D2;
		Mem175[ss:sp_155 + -0x0C:word16] = SEQ(ah_1019, Mem170[ds_1002:0x50C7:byte]);
		word16 ax_178 = fn133F_0528(dx_1022, ds_1002, (ss->*sp_155).tFFF6.u1, (ss->*sp_155).tFFFA.u1, (ss->*sp_155).tFFFE.u1, out dx_1022, out bp_186, out ds_1002);
		Eq_481 sp_187;
		sp_187.u0 = <invalid>;
		ah_1019 = SLICE(ax_178, byte, 8);
		sp_1000 = (word16) sp_187 + 0x0E;
		if ((byte) ax_178 != 0x00)
		{
			if (Mem175[ds_1002:25294:word16] == 0x01 && (Mem175[ds_1002:0x62D0:word16] > 0x59 && Mem175[ds_1002:0x62D2:word16] > 0x0187))
			{
				ss->*((word16) sp_187 + 0x0C) = 0xF0;
				fn1E78_02C7(ss->*((word16) sp_187 + 0x0C));
				ss->*((word16) sp_187 + 0x0C) = 100;
				word16 dx_1361;
				fn1E78_029C(ds_1002, ss->*((word16) sp_187 + 0x0C), out dx_1361);
				int16 ax_247 = CONVERT(Mem217[ds_1002:0x62D0:word16] - 0x59, int16, int32) /16 22 + (CONVERT(Mem217[ds_1002:0x62D2:word16] - 0x0187, int16, int32) /16 22) *s 0x19;
				Mem255[ds_1002:25291:byte] = Mem217[ds_1002:0x6CBA:byte] + SLICE(ax_247, byte, 0);
				fn1E78_02F4();
				dx_1022 = ax_247;
			}
			sp_1000 = (word16) sp_187 + 0x0E;
			if (Mem262[ds_1002:25294:word16] == 0x01 && Mem262[ds_1002:0x62D2:word16] < 0x0177)
			{
				word16 dx_1364;
				struct Eq_54749 Eq_17::* bp_269;
				Eq_17 ds_273;
				fn133F_0137(out dx_1364, out bp_269, out ds_273);
				Eq_481 sp_277;
				sp_277.u0 = <invalid>;
				Mem287[ss:sp_277 + -2:word16] = CONVERT(Mem262[ds_273:25291:byte], uint8, uint16);
				Mem310[ds_273:CONVERT(Mem287[ds_273:0x62D2:word16] - 0x01, int16, int32) /16 22 *s 0x1D + CONVERT(Mem287[ds_273:0x62D0:word16] - 0x01, int16, int32) /16 22 + 0x5CE0:byte] = Mem287[ss:sp_277 + 2:byte];
				Mem322[ss:sp_277 + -2:word16] = CONVERT(Mem310[ds_273:0x62D0:word16] - 0x01, int16, int32) /16 22 *s 22 + 0x01;
				Mem335[ss:sp_277 + -4:word16] = CONVERT(Mem322[ds_273:0x62D2:word16] - 0x01, int16, int32) /16 22 *s 22 + 0x01;
				segptr32 es_di_342 = ds_273:0x5992[CONVERT(Mem335[ds_273:25291:byte], uint8, uint16) * 0x04];
				ss->*((word16) sp_277 - 6) = SLICE(es_di_342, selector, 16);
				ss->*((word16) sp_277 - 8) = (word16) es_di_342;
				ss->*((word16) sp_277 - 0x0A) = 0x00;
				fn1AB8_13D7(ds_273, ss->*((word16) sp_277 + 0x0A), ss->*((word16) sp_277 - 8), ss->*((word16) sp_277 - 4), ss->*((word16) sp_277 - 2));
				(ss->*bp_269).bFEFF = 0x01;
				fn133F_0141(out dx_1022, out bp_186, out ds_1002);
				sp_1000.u0 = <invalid>;
			}
			if (Mem380[ds_1002:25294:word16] == 0x02 && Mem380[ds_1002:0x62D2:word16] < 0x0177)
			{
				word16 dx_1365;
				struct Eq_54890 Eq_17::* bp_387;
				Eq_17 ds_391;
				fn133F_0137(out dx_1365, out bp_387, out ds_391);
				Mem420[ds_391:CONVERT(Mem380[ds_391:0x62D2:word16] - 0x01, int16, int32) /16 22 *s 0x1D + CONVERT(Mem380[ds_391:0x62D0:word16] - 0x01, int16, int32) /16 22 + 0x5CE0:byte] = 0x00;
				Eq_481 sp_395;
				sp_395.u0 = <invalid>;
				Mem432[ss:sp_395 + -2:word16] = CONVERT(Mem420[ds_391:0x62D0:word16] - 0x01, int16, int32) /16 22 *s 22 + 0x01;
				Mem447[ss:sp_395 + -4:word16] = CONVERT(Mem432[ds_391:0x62D2:word16] - 0x01, int16, int32) /16 22 *s 22 + 0x01;
				segptr32 es_di_448 = Mem447[ds_391:0x5992:segptr32];
				ss->*((word16) sp_395 - 6) = SLICE(es_di_448, selector, 16);
				ss->*((word16) sp_395 - 8) = (word16) es_di_448;
				ss->*((word16) sp_395 - 0x0A) = 0x00;
				fn1AB8_13D7(ds_391, ss->*((word16) sp_395 + 0x0A), ss->*((word16) sp_395 - 8), ss->*((word16) sp_395 - 4), ss->*((word16) sp_395 - 2));
				(ss->*bp_387).bFEFF = 0x01;
				fn133F_0141(out dx_1022, out bp_186, out ds_1002);
				sp_1000.u0 = <invalid>;
			}
			word16 ax_487 = Mem486[ds_1002:25294:word16];
			ah_1019 = SLICE(ax_487, byte, 8);
			if (ax_487 == 0x2B)
			{
				if (Mem486[ds_1002:22928:word16] < 0x00 || Mem486[ds_1002:22928:word16] <= 0x00 && Mem486[ds_1002:22926:word16] <u 0xFA)
				{
					word16 dx_1366;
					struct Eq_55009 Eq_17::* bp_891;
					Eq_17 ds_895;
					fn133F_0137(out dx_1366, out bp_891, out ds_895);
					word16 dx_1368;
					if ((ss->*bp_891).bFEFF != 0x00 && (byte) fn1229_061B(ds_895, out dx_1368, out ds_895) != 0x00)
					{
						word16 dx_1369;
						fn1229_0735(out dx_1369, out bp_891, out ds_895);
					}
					Mem952[ds_895:22926:ui32] = Mem948[ds_895:22926:ui32] + 0x01;
					Eq_17 ds_960 = fn1229_0486(ds_895);
					(ss->*bp_891).bFEFF = 0x00;
					fn1229_0AA8(ds_960);
					word16 bp_1367;
					fn133F_0141(out dx_1022, out bp_1367, out ds_1002);
					sp_1000.u0 = <invalid>;
					ah_1019 = 0x00;
					word16 ax_1024;
					do
					{
						struct Eq_55071 Eq_17::* sp_1001 = sp_1000 - 2;
						(ss->*sp_1001).t0000.u2 = (uint16) ds_1002;
						(ss->*sp_1001).tFFFE.u0 = 25294;
						(ss->*sp_1001).tFFFC.u2 = (uint16) ds_1002;
						(ss->*sp_1001).tFFFA.u0 = 0x62D0;
						(ss->*sp_1001).tFFF8.u2 = (uint16) ds_1002;
						(ss->*sp_1001).tFFF6.u0 = 0x62D2;
						Mem1021[ss:sp_1001 + -0x0C:word16] = SEQ(ah_1019, Mem1016[ds_1002:0x50C7:byte]);
						word16 bp_1370;
						ax_1024 = fn133F_0528(dx_1022, ds_1002, (ss->*sp_1001).tFFF6.u1, (ss->*sp_1001).tFFFA.u1, (ss->*sp_1001).tFFFE.u1, out dx_1022, out bp_1370, out ds_1002);
						Eq_481 sp_1033;
						sp_1033.u0 = <invalid>;
						ah_1019 = SLICE(ax_1024, byte, 8);
						sp_1000 = (word16) sp_1033 + 0x0E;
					} while ((byte) ax_1024 != 0x00);
				}
			}
			else if (ax_487 == 0x2D)
			{
				if (Mem486[ds_1002:22928:word16] > 0x00 || Mem486[ds_1002:22928:word16] >= 0x00 && Mem486[ds_1002:22926:word16] >u 0x01)
				{
					word16 dx_1371;
					struct Eq_55144 Eq_17::* bp_730;
					Eq_17 ds_734;
					fn133F_0137(out dx_1371, out bp_730, out ds_734);
					word16 dx_1373;
					if ((ss->*bp_730).bFEFF != 0x00 && (byte) fn1229_061B(ds_734, out dx_1373, out ds_734) != 0x00)
					{
						word16 dx_1374;
						fn1229_0735(out dx_1374, out bp_730, out ds_734);
					}
					Mem791[ds_734:22926:ui32] = Mem787[ds_734:22926:ui32] - 0x01;
					Eq_17 ds_799 = fn1229_0486(ds_734);
					(ss->*bp_730).bFEFF = 0x00;
					fn1229_0AA8(ds_799);
					word16 bp_1372;
					fn133F_0141(out dx_1022, out bp_1372, out ds_1002);
					sp_1000.u0 = <invalid>;
					ah_1019 = 0x00;
					word16 ax_863;
					do
					{
						struct Eq_55331 Eq_17::* sp_840 = sp_1000 - 2;
						(ss->*sp_840).t0000.u2 = (uint16) ds_1002;
						(ss->*sp_840).tFFFE.u0 = 25294;
						(ss->*sp_840).tFFFC.u2 = (uint16) ds_1002;
						(ss->*sp_840).tFFFA.u0 = 0x62D0;
						(ss->*sp_840).tFFF8.u2 = (uint16) ds_1002;
						(ss->*sp_840).tFFF6.u0 = 0x62D2;
						Mem860[ss:sp_840 + -0x0C:word16] = SEQ(ah_1019, Mem855[ds_1002:0x50C7:byte]);
						word16 bp_1378;
						ax_863 = fn133F_0528(dx_1022, ds_1002, (ss->*sp_840).tFFF6.u1, (ss->*sp_840).tFFFA.u1, (ss->*sp_840).tFFFE.u1, out dx_1022, out bp_1378, out ds_1002);
						Eq_481 sp_872;
						sp_872.u0 = <invalid>;
						ah_1019 = SLICE(ax_863, byte, 8);
						sp_1000 = (word16) sp_872 + 0x0E;
					} while ((byte) ax_863 != 0x00);
				}
			}
			else if (ax_487 == 0x51)
			{
				Mem637[ds_1002:0x62DB:byte] = 0x01;
				Mem638[ds_1002:23731:byte] = 0x01;
				if ((ss->*bp_186).bFEFF != 0x00)
				{
					word16 ax_641 = fn1229_061B(ds_1002, out dx_1022, out ds_1002);
					ah_1019 = SLICE(ax_641, byte, 8);
					if ((byte) ax_641 != 0x00)
					{
						word16 bp_1376;
						fn1229_0735(out dx_1022, out bp_1376, out ds_1002);
						sp_1000.u0 = <invalid>;
						ah_1019 = 0x00;
					}
				}
				word16 ax_702;
				do
				{
					struct Eq_55219 Eq_17::* sp_679 = sp_1000 - 2;
					(ss->*sp_679).t0000.u2 = (uint16) ds_1002;
					(ss->*sp_679).tFFFE.u0 = 25294;
					(ss->*sp_679).tFFFC.u2 = (uint16) ds_1002;
					(ss->*sp_679).tFFFA.u0 = 0x62D0;
					(ss->*sp_679).tFFF8.u2 = (uint16) ds_1002;
					(ss->*sp_679).tFFF6.u0 = 0x62D2;
					Mem699[ss:sp_679 + -0x0C:word16] = SEQ(ah_1019, Mem694[ds_1002:0x50C7:byte]);
					word16 bp_1375;
					ax_702 = fn133F_0528(dx_1022, ds_1002, (ss->*sp_679).tFFF6.u1, (ss->*sp_679).tFFFA.u1, (ss->*sp_679).tFFFE.u1, out dx_1022, out bp_1375, out ds_1002);
					Eq_481 sp_711;
					sp_711.u0 = <invalid>;
					ah_1019 = SLICE(ax_702, byte, 8);
					sp_1000 = (word16) sp_711 + 0x0E;
				} while ((byte) ax_702 != 0x00);
			}
			else if (ax_487 == 0x54)
			{
				Mem591[ds_1002:23731:byte] = 0x00;
				Mem592[ds_1002:0x62DB:byte] = 0x01;
				if ((ss->*bp_186).bFEFF != 0x00)
				{
					word16 ax_601 = fn1229_061B(ds_1002, out dx_1022, out ds_1002);
					ah_1019 = SLICE(ax_601, byte, 8);
					if ((byte) ax_601 != 0x00)
					{
						word16 bp_1377;
						fn1229_0735(out dx_1022, out bp_1377, out ds_1002);
						sp_1000.u0 = <invalid>;
						ah_1019 = 0x00;
					}
				}
			}
			else if (ax_487 == 0x53)
			{
				if (Mem486[ds_1002:0x6CBA:byte] == 100)
					Mem501[ds_1002:0x6CBA:byte] = 0x00;
				else
					Mem500[ds_1002:0x6CBA:byte] = 100;
				word16 dx_1379;
				word16 bp_1380;
				Eq_17 ds_509;
				fn133F_0137(out dx_1379, out bp_1380, out ds_509);
				fn1229_0C58(ds_509);
				word16 bp_1381;
				fn133F_0141(out dx_1022, out bp_1381, out ds_1002);
				sp_1000.u0 = <invalid>;
				ah_1019 = 0x00;
				word16 ax_570;
				do
				{
					struct Eq_55425 Eq_17::* sp_547 = sp_1000 - 2;
					(ss->*sp_547).t0000.u2 = (uint16) ds_1002;
					(ss->*sp_547).tFFFE.u0 = 25294;
					(ss->*sp_547).tFFFC.u2 = (uint16) ds_1002;
					(ss->*sp_547).tFFFA.u0 = 0x62D0;
					(ss->*sp_547).tFFF8.u2 = (uint16) ds_1002;
					(ss->*sp_547).tFFF6.u0 = 0x62D2;
					Mem567[ss:sp_547 + -0x0C:word16] = SEQ(ah_1019, Mem562[ds_1002:0x50C7:byte]);
					word16 bp_1382;
					ax_570 = fn133F_0528(dx_1022, ds_1002, (ss->*sp_547).tFFF6.u1, (ss->*sp_547).tFFFA.u1, (ss->*sp_547).tFFFE.u1, out dx_1022, out bp_1382, out ds_1002);
					Eq_481 sp_579;
					sp_579.u0 = <invalid>;
					ah_1019 = SLICE(ax_570, byte, 8);
					sp_1000 = (word16) sp_579 + 0x0E;
				} while ((byte) ax_570 != 0x00);
			}
		}
	} while (Mem1049[ds_1002:0x62DB:byte] == 0x00);
	fn133F_04A7(ds_1002);
	word16 dx_1065;
	word16 Eq_17::* bp_1060;
	Eq_17 ds_1064;
	fn133F_0137(out dx_1065, out bp_1060, out ds_1064);
	Eq_481 sp_1068;
	sp_1068.u0 = <invalid>;
	if (Mem1049[ds_1064:23731:byte] != 0x00)
	{
		fn1AB8_0F80(ds_1064);
		ss->*((word16) sp_1068 - 2) = ds_1064;
		ss->*((word16) sp_1068 - 4) = 23732;
		Eq_17 cs;
		ss->*((word16) sp_1068 - 6) = cs;
		ss->*((word16) sp_1068 - 8) = 3525;
		word16 ax_1362;
		if (!fn1EDA_0B24(ss->*((word16) sp_1068 - 8), ss->*((word16) sp_1068 - 4), out ax_1362, out dx_1065))
		{
			Mem1161[ds_1064:22926:word16] = 0x01;
			Mem1162[ds_1064:22928:word16] = 0x00;
		}
		else
		{
			ss->*((word16) sp_1068 - 2) = ds_1064;
			ss->*((word16) sp_1068 - 4) = 23732;
			ss->*((word16) sp_1068 - 6) = ds_1064;
			ss->*((word16) sp_1068 - 8) = 24278;
			ss->*((word16) sp_1068 - 0x0A) = 0x06;
			word16 dx_1363;
			fn1EDA_0A39(ss->*((word16) sp_1068 + 0x0A), ss->*((word16) sp_1068 - 8), ss->*((word16) sp_1068 - 4), out dx_1363);
			ss->*((word16) sp_1068 - 2) = ds_1064;
			ss->*((word16) sp_1068 - 4) = 24278;
			ss->*((word16) sp_1068 - 6) = ds_1064;
			ss->*((word16) sp_1068 - 8) = 0x5ECE;
			ss->*((word16) sp_1068 - 0x0A) = 0x06;
			fn1EDA_0A39(ss->*((word16) sp_1068 + 0x0A), ss->*((word16) sp_1068 - 8), ss->*((word16) sp_1068 - 4), out dx_1065);
		}
	}
	bpOut = ss->*bp_1060;
	dsOut = ds_1064;
	return dx_1065;
}
