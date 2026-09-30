// 0C74:3F74: Register byte fn0C74_3F74(Register Eq_17 ds, Register out (memptr Eq_17 Eq_42725) bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_5258
byte fn0C74_3F74(Eq_17 ds, struct Eq_42725 & bpOut, union Eq_17 & dsOut)
{
	Eq_17 ds_1003;
	Eq_17 ds_249;
	mp16 fp;
	Mem13[ds:22708:word16] = Mem10[ds:22708:word16] + 0x01;
	fn1AB8_10F4(ds, 0x01, 0x00, 0x00);
	fn1AB8_1C32(ds, 0x0C);
	Eq_17 bp_1159 = fp - 2;
	struct Eq_42236 Eq_17::* sp_138 = fp - 0x0C;
	selector ss;
	Eq_481 sp_103;
	cup16 ax_152;
	do
	{
		struct Eq_42300 Eq_17::* sp_55 = sp_138 - 2;
		Mem56[ss:sp_55 + 0x00:word16] = Mem40[ds:22708:word16] + Mem40[ss:bp_1159 + -4:word16];
		Mem60[ss:sp_55 + -2:word16] = Mem56[ds:22712:word16] + 0x12;
		Mem74[ss:sp_55 + -4:word16] = Mem60[ds:22708:word16] + Mem60[ss:bp_1159 + -4:word16];
		Mem79[ss:sp_55 + -6:word16] = Mem74[ds:22712:word16] + 0x13;
		word16 dx_1470;
		fn1AB8_1AF6(ds, (ss->*sp_55).tFFFA.u2, (ss->*sp_55).tFFFC.u2, (ss->*sp_55).tFFFE.u2, (ss->*sp_55).t0000.u2, out dx_1470);
		(ss->*((word32) bp_1159 - 4)).u3 = ss->*((word32) bp_1159 - 4) - 0x01;
		(ss->*sp_55).t0000.u2 = (uint16) 300;
		(ss->*sp_55).tFFFE.u2 = (uint16) 0x14;
		bp_1159 = fn0C74_070D(ds, (ss->*sp_55).tFFFE.u2, (ss->*sp_55).t0000.u2, out ds);
		sp_103.u0 = <invalid>;
		if (ss->*((word32) bp_1159 - 4) == ~0x0C)
			break;
		Mem124[ss:sp_103 + 0x02:word16] = Mem92[ds:22708:word16] + Mem92[ss:bp_1159 + -4:word16];
		Mem129[ss:sp_103 + 0x00:word16] = Mem124[ds:22712:word16] + 0x13;
		sp_138 = (word16) sp_103 + 4;
		byte dl_1469;
		if (fn1AB8_1E3C(ds, ss->*sp_103, ss->*((word16) sp_103 + 2), out dl_1469) != 0x00)
			break;
		Eq_42291 dx_ax_1373 = CONVERT(Mem129[ds:22708:word16] + Mem129[ss:bp_1159 + -4:word16], word16, uint32);
		ax_152 = (word16) dx_ax_1373;
	} while (true && (false || ax_152 > 0x01));
	if (ss->*((word32) bp_1159 - 4) != ~0x0C)
	{
		ss->*((word16) sp_103 + 2) = 0x00;
		fn1AB8_1C32(ds, ss->*((word16) sp_103 + 2));
		struct Eq_42585 Eq_17::* sp_1273 = (word16) sp_103 + 4;
		ci16 ax_1274 = (ci16) (ss->*((word32) bp_1159 - 4));
		if (ax_1274 <= 0x0C)
		{
			(ss->*((word32) bp_1159 - 6)).u3 = ax_1274 + 0x01;
			while (true)
			{
				struct Eq_42613 Eq_17::* sp_1296 = sp_1273 - 2;
				Mem1297[ss:sp_1296 + 0x00:word16] = Mem1281[ds:22708:word16] + Mem1281[ss:bp_1159 + -6:word16];
				Mem1301[ss:sp_1296 + -2:word16] = Mem1297[ds:22712:word16] + 0x12;
				Mem1315[ss:sp_1296 + -4:word16] = Mem1301[ds:22708:word16] + Mem1301[ss:bp_1159 + -6:word16];
				Mem1320[ss:sp_1296 + -6:word16] = Mem1315[ds:22712:word16] + 0x13;
				word16 dx_1473;
				fn1AB8_1AF6(ds, (ss->*sp_1296).tFFFA.u2, (ss->*sp_1296).tFFFC.u2, (ss->*sp_1296).tFFFE.u2, (ss->*sp_1296).t0000.u2, out dx_1473);
				(ss->*sp_1296).t0000.u2 = (uint16) 300;
				(ss->*sp_1296).tFFFE.u2 = (uint16) 0x14;
				Eq_481 sp_1341;
				sp_1341.u0 = <invalid>;
				bp_1159 = fn0C74_070D(ds, (ss->*sp_1296).tFFFE.u2, (ss->*sp_1296).t0000.u2, out ds);
				sp_1273 = (word16) sp_1341 + 4;
				if (ss->*((word32) bp_1159 - 6) == 0x0D)
					break;
				(ss->*((word32) bp_1159 - 6)).u3 = &(ss->*((word32) bp_1159 - 6)).u3->t0001.u0;
			}
		}
		Mem1355[ds:22708:word16] = Mem1353[ds:22708:word16] - 0x01;
		(ss->*((word32) bp_1159 - 1)).u3 = 0x00;
	}
	else
	{
		ss->*((word16) sp_103 + 2) = 0x0A;
		fn1AB8_1C32(ds, ss->*((word16) sp_103 + 2));
		Mem177[ss:sp_103 + 0x02:word16] = Mem168[ds:22708:word16] + 0x01;
		Mem181[ss:sp_103 + 0x00:word16] = Mem177[ds:22712:word16] + 0x12;
		Mem185[ss:sp_103 + -2:word16] = Mem181[ds:22708:word16] - 11;
		Mem190[ss:sp_103 + -4:word16] = Mem185[ds:22712:word16] + 0x12;
		word16 dx_1471;
		fn1AB8_1AF6(ds, ss->*((word16) sp_103 - 4), ss->*((word16) sp_103 - 2), ss->*sp_103, ss->*((word16) sp_103 + 2), out dx_1471);
		ss->*((word16) sp_103 + 2) = 300;
		ss->*sp_103 = 0x14;
		Eq_17 ds_207;
		fn0C74_070D(ds, ss->*sp_103, ss->*((word16) sp_103 + 2), out ds_207);
		Eq_481 sp_211;
		sp_211.u0 = <invalid>;
		Mem220[ss:sp_211 + 0x02:word16] = Mem200[ds_207:22708:word16] + 0x01;
		Mem224[ss:sp_211 + 0x00:word16] = Mem220[ds_207:22712:word16] + 0x11;
		Mem228[ss:sp_211 + -2:word16] = Mem224[ds_207:22708:word16] - 11;
		Mem233[ss:sp_211 + -4:word16] = Mem228[ds_207:22712:word16] + 0x11;
		word16 dx_1472;
		fn1AB8_1AF6(ds_207, ss->*((word16) sp_211 - 4), ss->*((word16) sp_211 - 2), ss->*sp_211, ss->*((word16) sp_211 + 2), out dx_1472);
		ss->*((word16) sp_211 + 2) = 300;
		ss->*sp_211 = 0x14;
		Eq_17 bp_245 = fn0C74_070D(ds_207, ss->*sp_211, ss->*((word16) sp_211 + 2), out ds_249);
		(ss->*((word32) bp_245 - 6)).u3 = 0x03;
		Eq_481 sp_253;
		sp_253.u0 = <invalid>;
		word16 sp_258 = (word16) sp_253 + 4;
		Eq_481 sp_448;
		while (true)
		{
			struct Eq_42729 Eq_17::* sp_261 = sp_258 - 2;
			(ss->*sp_261).t0000.u2 = (uint16) 0x00;
			fn1AB8_1C32(ds_249, (ss->*sp_261).t0000.u0);
			Mem288[ss:sp_261 + 0x00:word16] = Mem263[ds_249:22708:word16] - ds_249:0x4D5E[(Mem263[ss:bp_245 + -6:word16] - 0x02) * 0x02];
			Mem298[ss:sp_261 + -2:word16] = CONVERT(Mem288[ds_249:Mem288[ss:bp_245 + -6:word16] + 0x4D85:byte], uint8, uint16) + Mem288[ds_249:22712:word16];
			Mem310[ss:sp_261 + -4:word16] = Mem298[ds_249:22708:word16] - CONVERT(Mem298[ds_249:Mem298[ss:bp_245 + -6:word16] + 0x4D99:byte], uint8, uint16);
			Mem321[ss:sp_261 + -6:word16] = CONVERT(Mem310[ds_249:Mem310[ss:bp_245 + -6:word16] + 0x4DAD:byte], uint8, uint16) + Mem310[ds_249:22712:word16];
			word16 dx_1474;
			fn1AB8_1AF6(ds_249, (ss->*sp_261).tFFFA.u2, (ss->*sp_261).tFFFC.u2, (ss->*sp_261).tFFFE.u2, (ss->*sp_261).t0000.u2, out dx_1474);
			(ss->*sp_261).t0000.u2 = (uint16) 0x0A;
			fn1AB8_1C32(ds_249, (ss->*sp_261).t0000.u0);
			Mem349[ss:sp_261 + 0x00:word16] = Mem329[ds_249:22708:word16] - ds_249:0x4D5E[Mem329[ss:bp_245 + -6:word16] * 0x02];
			Mem356[ss:sp_261 + -2:word16] = CONVERT(Mem349[ds_249:Mem349[ss:bp_245 + -6:word16] + 0x4D87:byte], uint8, uint16) + Mem349[ds_249:22712:word16];
			Mem365[ss:sp_261 + -4:word16] = Mem356[ds_249:22708:word16] - CONVERT(Mem356[ds_249:Mem356[ss:bp_245 + -6:word16] + 0x4D9B:byte], uint8, uint16);
			Mem373[ss:sp_261 + -6:word16] = CONVERT(Mem365[ds_249:Mem365[ss:bp_245 + -6:word16] + 19887:byte], uint8, uint16) + Mem365[ds_249:22712:word16];
			word16 dx_1475;
			fn1AB8_1AF6(ds_249, (ss->*sp_261).tFFFA.u2, (ss->*sp_261).tFFFC.u2, (ss->*sp_261).tFFFE.u2, (ss->*sp_261).t0000.u2, out dx_1475);
			Mem397[ss:sp_261 + 0x00:word16] = Mem373[ds_249:22708:word16] - ds_249:0x4D5E[(Mem373[ss:bp_245 + -6:word16] - 0x01) * 0x02];
			Mem406[ss:sp_261 + -2:word16] = CONVERT(Mem397[ds_249:Mem397[ss:bp_245 + -6:word16] + 0x4D86:byte], uint8, uint16) + Mem397[ds_249:22712:word16];
			Mem417[ss:sp_261 + -4:word16] = Mem406[ds_249:22708:word16] - CONVERT(Mem406[ds_249:Mem406[ss:bp_245 + -6:word16] + 19866:byte], uint8, uint16);
			Mem427[ss:sp_261 + -6:word16] = CONVERT(Mem417[ds_249:Mem417[ss:bp_245 + -6:word16] + 19886:byte], uint8, uint16) + Mem417[ds_249:22712:word16];
			word16 dx_1476;
			fn1AB8_1AF6(ds_249, (ss->*sp_261).tFFFA.u2, (ss->*sp_261).tFFFC.u2, (ss->*sp_261).tFFFE.u2, (ss->*sp_261).t0000.u2, out dx_1476);
			(ss->*sp_261).t0000.u2 = (uint16) 400;
			(ss->*sp_261).tFFFE.u2 = (uint16) 0x32;
			sp_448.u0 = <invalid>;
			bp_245 = fn0C74_070D(ds_249, (ss->*sp_261).tFFFE.u2, (ss->*sp_261).t0000.u2, out ds_249);
			sp_258 = (word16) sp_448 + 4;
			if (ss->*((word32) bp_245 - 6) == 0x14)
				break;
			(ss->*((word32) bp_245 - 6)).u3 = &(ss->*((word32) bp_245 - 6)).u3->t0001.u0;
		}
		Mem459[ss:sp_448 + 0x02:word16] = Mem437[ds_249:22708:word16] - 11;
		Mem464[ss:sp_448 + 0x00:word16] = Mem459[ds_249:22712:word16] + 0x11;
		ss->*((word16) sp_448 - 2) = 0x00;
		fn1AB8_1E54(ds_249, ss->*((word16) sp_448 - 2), ss->*sp_448, ss->*((word16) sp_448 + 2));
		Mem475[ss:sp_448 + 0x02:word16] = Mem466[ds_249:22708:word16] - 0x0C;
		Mem479[ss:sp_448 + 0x00:word16] = Mem475[ds_249:22712:word16] + 0x06;
		Mem483[ss:sp_448 + -2:word16] = Mem479[ds_249:22708:word16] - 0x0C;
		Mem488[ss:sp_448 + -4:word16] = Mem483[ds_249:22712:word16] + 0x10;
		word16 dx_1477;
		fn1AB8_1AF6(ds_249, ss->*((word16) sp_448 - 4), ss->*((word16) sp_448 - 2), ss->*sp_448, ss->*((word16) sp_448 + 2), out dx_1477);
		Mem497[ss:bp_245 + -8:word16] = Mem488[ds_249:22712:word16] + 0x06;
		Mem501[ss:bp_245 + -0x0A:word16] = Mem497[ds_249:22712:word16] + 0x14;
		(ss->*((word32) bp_245 - 6)).u3 = 0x01;
		struct Eq_43168 Eq_17::* sp_494 = (word16) sp_448 + 4;
		Eq_481 sp_610;
		while (true)
		{
			struct Eq_43181 Eq_17::* sp_504 = sp_494 - 2;
			(ss->*sp_504).t0000.u2 = (uint16) 0x00;
			fn1AB8_1C32(ds_249, (ss->*sp_504).t0000.u0);
			Mem515[ss:sp_504 + 0x00:word16] = Mem506[ds_249:22708:word16] - 0x0C;
			(ss->*sp_504).tFFFE.u2 = (uint16) (ss->*((word32) bp_245 - 8));
			Mem524[ss:sp_504 + -4:word16] = Mem519[ds_249:22708:word16] - 0x0D;
			(ss->*sp_504).tFFFA.u2 = (uint16) (ss->*((word32) bp_245 - 8));
			word16 dx_1478;
			fn1AB8_1AF6(ds_249, (ss->*sp_504).tFFFA.u2, (ss->*sp_504).tFFFC.u2, (ss->*sp_504).tFFFE.u2, (ss->*sp_504).t0000.u2, out dx_1478);
			(ss->*sp_504).t0000.u2 = (uint16) 0x0A;
			fn1AB8_1C32(ds_249, (ss->*sp_504).t0000.u0);
			Mem543[ss:sp_504 + 0x00:word16] = Mem535[ds_249:22708:word16] - 0x0C;
			(ss->*sp_504).tFFFE.u2 = (uint16) (ss->*((word32) bp_245 - 0x0A));
			Mem551[ss:sp_504 + -4:word16] = Mem546[ds_249:22708:word16] - 0x0D;
			(ss->*sp_504).tFFFA.u2 = (uint16) (ss->*((word32) bp_245 - 0x0A));
			word16 dx_1479;
			fn1AB8_1AF6(ds_249, (ss->*sp_504).tFFFA.u2, (ss->*sp_504).tFFFC.u2, (ss->*sp_504).tFFFE.u2, (ss->*sp_504).t0000.u2, out dx_1479);
			Mem565[ss:sp_504 + 0x00:word16] = Mem554[ds_249:22708:word16] - 11;
			(ss->*sp_504).tFFFE.u2 = (uint16) (ss->*((word32) bp_245 - 0x0A));
			(ss->*sp_504).tFFFC.u2 = (uint16) 0x00;
			fn1AB8_1E54(ds_249, (ss->*sp_504).tFFFC.u0, (ss->*sp_504).tFFFE.u2, (ss->*sp_504).t0000.u2);
			Mem580[ss:sp_504 + 0x00:word16] = Mem570[ds_249:22708:word16] - 0x0E;
			(ss->*sp_504).tFFFE.u2 = (uint16) (ss->*((word32) bp_245 - 0x0A));
			(ss->*sp_504).tFFFC.u2 = (uint16) 0x00;
			fn1AB8_1E54(ds_249, (ss->*sp_504).tFFFC.u0, (ss->*sp_504).tFFFE.u2, (ss->*sp_504).t0000.u2);
			(ss->*((word32) bp_245 - 8)).u3 = &(ss->*((word32) bp_245 - 8)).u3->t0001.u0;
			(ss->*((word32) bp_245 - 0x0A)).u3 = &(ss->*((word32) bp_245 - 0x0A)).u3->t0001.u0;
			(ss->*sp_504).t0000.u2 = (uint16) 100;
			(ss->*sp_504).tFFFE.u2 = (uint16) 100;
			sp_610.u0 = <invalid>;
			bp_245 = fn0C74_070D(ds_249, (ss->*sp_504).tFFFE.u2, (ss->*sp_504).t0000.u2, out ds_249);
			sp_494 = (word16) sp_610 + 4;
			if (ss->*((word32) bp_245 - 6) == 11)
				break;
			(ss->*((word32) bp_245 - 6)).u3 = &(ss->*((word32) bp_245 - 6)).u3->t0001.u0;
		}
		ss->*((word16) sp_610 + 2) = 0x0A;
		fn1AB8_1C32(ds_249, ss->*((word16) sp_610 + 2));
		Mem630[ss:sp_610 + 0x02:word16] = Mem622[ds_249:22708:word16] - 0x0C;
		ss->*sp_610 = ss->*((word32) bp_245 - 0x0A);
		Mem638[ss:sp_610 + -2:word16] = Mem633[ds_249:22708:word16] - 0x0D;
		ss->*((word16) sp_610 - 4) = ss->*((word32) bp_245 - 0x0A);
		word16 dx_1480;
		fn1AB8_1AF6(ds_249, ss->*((word16) sp_610 - 4), ss->*((word16) sp_610 - 2), ss->*sp_610, ss->*((word16) sp_610 + 2), out dx_1480);
		Mem652[ss:sp_610 + 0x02:word16] = Mem641[ds_249:22708:word16] - 11;
		ss->*sp_610 = ss->*((word32) bp_245 - 0x0A);
		ss->*((word16) sp_610 - 2) = 0x00;
		fn1AB8_1E54(ds_249, ss->*((word16) sp_610 - 2), ss->*sp_610, ss->*((word16) sp_610 + 2));
		Mem667[ss:sp_610 + 0x02:word16] = Mem657[ds_249:22708:word16] - 0x0E;
		ss->*sp_610 = ss->*((word32) bp_245 - 0x0A);
		ss->*((word16) sp_610 - 2) = 0x00;
		fn1AB8_1E54(ds_249, ss->*((word16) sp_610 - 2), ss->*sp_610, ss->*((word16) sp_610 + 2));
		ss->*((word16) sp_610 + 2) = 500;
		Eq_17 bp_681 = fn0C74_02D8(ds_249, ss->*((word16) sp_610 + 2), out ds_1003);
		Eq_481 sp_689;
		sp_689.u0 = <invalid>;
		ss->*sp_689 = 0x00;
		fn1AB8_1C32(ds_1003, ss->*sp_689);
		Mem704[ss:sp_689 + 0x00:word16] = Mem696[ds_1003:22708:word16] - 0x0C;
		ss->*((word16) sp_689 - 2) = ss->*((word32) bp_681 - 0x0A);
		Mem712[ss:sp_689 + -4:word16] = Mem707[ds_1003:22708:word16] - 0x0D;
		ss->*((word16) sp_689 - 6) = ss->*((word32) bp_681 - 0x0A);
		word16 dx_1481;
		fn1AB8_1AF6(ds_1003, ss->*((word16) sp_689 - 6), ss->*((word16) sp_689 - 4), ss->*((word16) sp_689 - 2), ss->*sp_689, out dx_1481);
		Mem724[ss:bp_681 + -8:word16] = Mem715[ds_1003:22712:word16] + 0x10;
		Mem728[ss:bp_681 + -0x0A:word16] = Mem724[ds_1003:22712:word16] + 0x1E;
		(ss->*((word32) bp_681 - 6)).u3 = 0x01;
		struct Eq_43684 Eq_17::* sp_1012 = (word16) sp_689 + 2;
		while (true)
		{
			struct Eq_43687 Eq_17::* sp_731 = sp_1012 - 2;
			(ss->*sp_731).t0000.u2 = (uint16) 0x0A;
			fn1AB8_1C32(ds_1003, (ss->*sp_731).t0000.u0);
			Mem742[ss:sp_731 + 0x00:word16] = Mem733[ds_1003:22708:word16] - 0x0C;
			(ss->*sp_731).tFFFE.u2 = (uint16) (ss->*((word32) bp_681 - 8));
			Mem751[ss:sp_731 + -4:word16] = Mem746[ds_1003:22708:word16] - 0x0D;
			(ss->*sp_731).tFFFA.u2 = (uint16) (ss->*((word32) bp_681 - 8));
			word16 dx_1482;
			fn1AB8_1AF6(ds_1003, (ss->*sp_731).tFFFA.u2, (ss->*sp_731).tFFFC.u2, (ss->*sp_731).tFFFE.u2, (ss->*sp_731).t0000.u2, out dx_1482);
			(ss->*sp_731).t0000.u2 = (uint16) 0x00;
			fn1AB8_1C32(ds_1003, (ss->*sp_731).t0000.u0);
			Mem770[ss:sp_731 + 0x00:word16] = Mem762[ds_1003:22708:word16] - 0x0C;
			(ss->*sp_731).tFFFE.u2 = (uint16) (ss->*((word32) bp_681 - 0x0A));
			Mem778[ss:sp_731 + -4:word16] = Mem773[ds_1003:22708:word16] - 0x0D;
			(ss->*sp_731).tFFFA.u2 = (uint16) (ss->*((word32) bp_681 - 0x0A));
			word16 dx_1483;
			fn1AB8_1AF6(ds_1003, (ss->*sp_731).tFFFA.u2, (ss->*sp_731).tFFFC.u2, (ss->*sp_731).tFFFE.u2, (ss->*sp_731).t0000.u2, out dx_1483);
			--ss->*((word32) bp_681 - 8);
			--ss->*((word32) bp_681 - 0x0A);
			(ss->*sp_731).t0000.u2 = (uint16) 100;
			(ss->*sp_731).tFFFE.u2 = (uint16) 100;
			Eq_481 sp_807;
			sp_807.u0 = <invalid>;
			bp_681 = fn0C74_070D(ds_1003, (ss->*sp_731).tFFFE.u2, (ss->*sp_731).t0000.u2, out ds_1003);
			sp_1012 = (word16) sp_807 + 4;
			if (ss->*((word32) bp_681 - 6) == 11)
				break;
			(ss->*((word32) bp_681 - 6)).u3 = &(ss->*((word32) bp_681 - 6)).u3->t0001.u0;
		}
		(ss->*((word32) bp_681 - 6)).u3 = 0x14;
		Eq_481 sp_1007;
		while (true)
		{
			struct Eq_43885 Eq_17::* sp_820 = sp_1012 - 2;
			(ss->*sp_820).t0000.u2 = (uint16) 0x00;
			fn1AB8_1C32(ds_1003, (ss->*sp_820).t0000.u0);
			Mem844[ss:sp_820 + 0x00:word16] = Mem822[ds_1003:22708:word16] - ds_1003:0x4D5E[Mem822[ss:bp_681 + -6:word16] * 0x02];
			Mem851[ss:sp_820 + -2:word16] = CONVERT(Mem844[ds_1003:Mem844[ss:bp_681 + -6:word16] + 0x4D87:byte], uint8, uint16) + Mem844[ds_1003:22712:word16];
			Mem860[ss:sp_820 + -4:word16] = Mem851[ds_1003:22708:word16] - CONVERT(Mem851[ds_1003:Mem851[ss:bp_681 + -6:word16] + 0x4D9B:byte], uint8, uint16);
			Mem868[ss:sp_820 + -6:word16] = CONVERT(Mem860[ds_1003:Mem860[ss:bp_681 + -6:word16] + 19887:byte], uint8, uint16) + Mem860[ds_1003:22712:word16];
			word16 dx_1484;
			fn1AB8_1AF6(ds_1003, (ss->*sp_820).tFFFA.u2, (ss->*sp_820).tFFFC.u2, (ss->*sp_820).tFFFE.u2, (ss->*sp_820).t0000.u2, out dx_1484);
			(ss->*sp_820).t0000.u2 = (uint16) 0x0A;
			fn1AB8_1C32(ds_1003, (ss->*sp_820).t0000.u0);
			Mem899[ss:sp_820 + 0x00:word16] = Mem876[ds_1003:22708:word16] - ds_1003:0x4D5E[(Mem876[ss:bp_681 + -6:word16] - 0x02) * 0x02];
			Mem909[ss:sp_820 + -2:word16] = CONVERT(Mem899[ds_1003:Mem899[ss:bp_681 + -6:word16] + 0x4D85:byte], uint8, uint16) + Mem899[ds_1003:22712:word16];
			Mem921[ss:sp_820 + -4:word16] = Mem909[ds_1003:22708:word16] - CONVERT(Mem909[ds_1003:Mem909[ss:bp_681 + -6:word16] + 0x4D99:byte], uint8, uint16);
			Mem932[ss:sp_820 + -6:word16] = CONVERT(Mem921[ds_1003:Mem921[ss:bp_681 + -6:word16] + 0x4DAD:byte], uint8, uint16) + Mem921[ds_1003:22712:word16];
			word16 dx_1485;
			fn1AB8_1AF6(ds_1003, (ss->*sp_820).tFFFA.u2, (ss->*sp_820).tFFFC.u2, (ss->*sp_820).tFFFE.u2, (ss->*sp_820).t0000.u2, out dx_1485);
			Mem956[ss:sp_820 + 0x00:word16] = Mem932[ds_1003:22708:word16] - ds_1003:0x4D5E[(Mem932[ss:bp_681 + -6:word16] - 0x01) * 0x02];
			Mem965[ss:sp_820 + -2:word16] = CONVERT(Mem956[ds_1003:Mem956[ss:bp_681 + -6:word16] + 0x4D86:byte], uint8, uint16) + Mem956[ds_1003:22712:word16];
			Mem976[ss:sp_820 + -4:word16] = Mem965[ds_1003:22708:word16] - CONVERT(Mem965[ds_1003:Mem965[ss:bp_681 + -6:word16] + 19866:byte], uint8, uint16);
			Mem986[ss:sp_820 + -6:word16] = CONVERT(Mem976[ds_1003:Mem976[ss:bp_681 + -6:word16] + 19886:byte], uint8, uint16) + Mem976[ds_1003:22712:word16];
			word16 dx_1486;
			fn1AB8_1AF6(ds_1003, (ss->*sp_820).tFFFA.u2, (ss->*sp_820).tFFFC.u2, (ss->*sp_820).tFFFE.u2, (ss->*sp_820).t0000.u2, out dx_1486);
			(ss->*sp_820).t0000.u2 = (uint16) 400;
			(ss->*sp_820).tFFFE.u2 = (uint16) 0x32;
			sp_1007.u0 = <invalid>;
			bp_681 = fn0C74_070D(ds_1003, (ss->*sp_820).tFFFE.u2, (ss->*sp_820).t0000.u2, out ds_1003);
			sp_1012 = (word16) sp_1007 + 4;
			if (ss->*((word32) bp_681 - 6) == 0x03)
				break;
			(ss->*((word32) bp_681 - 6)).u3 = ss->*((word32) bp_681 - 6) - 0x01;
		}
		Mem1018[ss:sp_1007 + 0x02:word16] = Mem996[ds_1003:22708:word16] - 0x0C;
		Mem1023[ss:sp_1007 + 0x00:word16] = Mem1018[ds_1003:22712:word16] + 0x10;
		ss->*((word16) sp_1007 - 2) = 0x00;
		fn1AB8_1E54(ds_1003, ss->*((word16) sp_1007 - 2), ss->*sp_1007, ss->*((word16) sp_1007 + 2));
		ss->*((word16) sp_1007 + 2) = 0x0A;
		fn1AB8_1C32(ds_1003, ss->*((word16) sp_1007 + 2));
		Mem1040[ss:sp_1007 + 0x02:word16] = Mem1032[ds_1003:22708:word16] + 0x01;
		Mem1044[ss:sp_1007 + 0x00:word16] = Mem1040[ds_1003:22712:word16] + 0x11;
		Mem1048[ss:sp_1007 + -2:word16] = Mem1044[ds_1003:22708:word16] - 11;
		Mem1053[ss:sp_1007 + -4:word16] = Mem1048[ds_1003:22712:word16] + 0x11;
		word16 dx_1487;
		fn1AB8_1AF6(ds_1003, ss->*((word16) sp_1007 - 4), ss->*((word16) sp_1007 - 2), ss->*sp_1007, ss->*((word16) sp_1007 + 2), out dx_1487);
		ss->*((word16) sp_1007 + 2) = 500;
		Eq_17 ds_1067;
		fn0C74_02D8(ds_1003, ss->*((word16) sp_1007 + 2), out ds_1067);
		Eq_481 sp_1071;
		sp_1071.u0 = <invalid>;
		ss->*sp_1071 = 0x00;
		fn1AB8_1C32(ds_1067, ss->*sp_1071);
		Mem1086[ss:sp_1071 + 0x00:word16] = Mem1078[ds_1067:22708:word16] + 0x01;
		Mem1090[ss:sp_1071 + -2:word16] = Mem1086[ds_1067:22712:word16] + 0x11;
		Mem1094[ss:sp_1071 + -4:word16] = Mem1090[ds_1067:22708:word16] - 11;
		Mem1099[ss:sp_1071 + -6:word16] = Mem1094[ds_1067:22712:word16] + 0x11;
		word16 dx_1488;
		fn1AB8_1AF6(ds_1067, ss->*((word16) sp_1071 - 6), ss->*((word16) sp_1071 - 4), ss->*((word16) sp_1071 - 2), ss->*sp_1071, out dx_1488);
		ss->*sp_1071 = 300;
		ss->*((word16) sp_1071 - 2) = 0x14;
		Eq_17 ds_1115;
		fn0C74_070D(ds_1067, ss->*((word16) sp_1071 - 2), ss->*sp_1071, out ds_1115);
		Eq_481 sp_1119;
		sp_1119.u0 = <invalid>;
		ss->*((word16) sp_1119 + 2) = 0x0C;
		fn1AB8_1C32(ds_1115, ss->*((word16) sp_1119 + 2));
		Mem1134[ss:sp_1119 + 0x02:word16] = Mem1126[ds_1115:22708:word16] + 0x01;
		Mem1138[ss:sp_1119 + 0x00:word16] = Mem1134[ds_1115:22712:word16] + 0x12;
		Mem1142[ss:sp_1119 + -2:word16] = Mem1138[ds_1115:22708:word16] - 11;
		Mem1147[ss:sp_1119 + -4:word16] = Mem1142[ds_1115:22712:word16] + 0x12;
		word16 dx_1489;
		fn1AB8_1AF6(ds_1115, ss->*((word16) sp_1119 - 4), ss->*((word16) sp_1119 - 2), ss->*sp_1119, ss->*((word16) sp_1119 + 2), out dx_1489);
		ss->*((word16) sp_1119 + 2) = 300;
		ss->*sp_1119 = 0x14;
		bp_1159 = fn0C74_070D(ds_1115, ss->*sp_1119, ss->*((word16) sp_1119 + 2), out ds);
		Eq_481 sp_1167;
		sp_1167.u0 = <invalid>;
		ss->*((word16) sp_1167 + 2) = 0x00;
		fn1AB8_1C32(ds, ss->*((word16) sp_1167 + 2));
		struct Eq_44512 Eq_17::* sp_1178 = (word16) sp_1167 + 4;
		ci16 ax_1179 = (ci16) (ss->*((word32) bp_1159 - 4));
		if (ax_1179 <= 0x0C)
		{
			(ss->*((word32) bp_1159 - 6)).u3 = ax_1179 + 0x01;
			while (true)
			{
				struct Eq_44545 Eq_17::* sp_1201 = sp_1178 - 2;
				Mem1202[ss:sp_1201 + 0x00:word16] = Mem1186[ds:22708:word16] + Mem1186[ss:bp_1159 + -6:word16];
				Mem1206[ss:sp_1201 + -2:word16] = Mem1202[ds:22712:word16] + 0x12;
				Mem1220[ss:sp_1201 + -4:word16] = Mem1206[ds:22708:word16] + Mem1206[ss:bp_1159 + -6:word16];
				Mem1225[ss:sp_1201 + -6:word16] = Mem1220[ds:22712:word16] + 0x13;
				word16 dx_1490;
				fn1AB8_1AF6(ds, (ss->*sp_1201).tFFFA.u2, (ss->*sp_1201).tFFFC.u2, (ss->*sp_1201).tFFFE.u2, (ss->*sp_1201).t0000.u2, out dx_1490);
				(ss->*sp_1201).t0000.u2 = (uint16) 300;
				(ss->*sp_1201).tFFFE.u2 = (uint16) 0x14;
				Eq_481 sp_1246;
				sp_1246.u0 = <invalid>;
				bp_1159 = fn0C74_070D(ds, (ss->*sp_1201).tFFFE.u2, (ss->*sp_1201).t0000.u2, out ds);
				sp_1178 = (word16) sp_1246 + 4;
				if (ss->*((word32) bp_1159 - 6) == 0x0D)
					break;
				(ss->*((word32) bp_1159 - 6)).u3 = &(ss->*((word32) bp_1159 - 6)).u3->t0001.u0;
			}
		}
		Mem1260[ds:22708:word16] = Mem1258[ds:22708:word16] - 0x01;
	}
	byte al_1365 = (byte) (ss->*((word32) bp_1159 - 1));
	bpOut = (struct Eq_42725 Eq_17::*) (ss->*bp_1159.u3).t0000.u2;
	dsOut = ds;
	return al_1365;
}
