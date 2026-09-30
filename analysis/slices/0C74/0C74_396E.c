// 0C74:396E: Register byte fn0C74_396E(Register Eq_17 ds, Register out (memptr Eq_17 Eq_40272) bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_5258
byte fn0C74_396E(Eq_17 ds, struct Eq_40272 & bpOut, union Eq_17 & dsOut)
{
	Eq_17 ds_645;
	Eq_17 ds_214;
	mp16 fp;
	Mem13[ds:22708:word16] = Mem10[ds:22708:word16] - 0x01;
	fn1AB8_10F4(ds, 0x01, 0x00, 0x00);
	fn1AB8_1C32(ds, 0x0C);
	Eq_17 bp_1114 = fp - 2;
	struct Eq_39783 Eq_17::* sp_114 = fp - 0x0A;
	selector ss;
	Eq_481 sp_87;
	byte dl_1368;
	do
	{
		struct Eq_39843 Eq_17::* sp_47 = sp_114 - 2;
		Mem48[ss:sp_47 + 0x00:word16] = CONVERT(Mem40[ss:bp_1114 + -2:byte], uint8, uint16) + Mem40[ds:22708:word16];
		Mem52[ss:sp_47 + -2:word16] = Mem48[ds:22712:word16] + 0x12;
		Mem58[ss:sp_47 + -4:word16] = CONVERT(Mem52[ss:bp_1114 + -2:byte], uint8, uint16) + Mem52[ds:22708:word16];
		Mem63[ss:sp_47 + -6:word16] = Mem58[ds:22712:word16] + 0x13;
		word16 dx_1369;
		fn1AB8_1AF6(ds, (ss->*sp_47).tFFFA.u2, (ss->*sp_47).tFFFC.u2, (ss->*sp_47).tFFFE.u2, (ss->*sp_47).t0000.u2, out dx_1369);
		(ss->*((word32) bp_1114 - 2)).u3 = &(ss->*((word32) bp_1114 - 2)).u3->t0001.u0;
		(ss->*sp_47).t0000.u2 = (uint16) 300;
		(ss->*sp_47).tFFFE.u2 = (uint16) 0x14;
		bp_1114 = fn0C74_070D(ds, (ss->*sp_47).tFFFE.u2, (ss->*sp_47).t0000.u2, out ds);
		sp_87.u0 = <invalid>;
		if (ss->*((word32) bp_1114 - 2) == 0x39)
			break;
		Mem100[ss:sp_87 + 0x02:word16] = CONVERT(Mem76[ss:bp_1114 + -2:byte], uint8, uint16) + Mem76[ds:22708:word16];
		Mem105[ss:sp_87 + 0x00:word16] = Mem100[ds:22712:word16] + 0x13;
		sp_114 = (word16) sp_87 + 4;
	} while (fn1AB8_1E3C(ds, ss->*sp_87, ss->*((word16) sp_87 + 2), out dl_1368) == 0x00 && CONVERT(Mem105[ss:bp_1114 + -2:byte], uint8, uint16) + Mem105[ds:22708:word16] <u 0x027E);
	if (ss->*((word32) bp_1114 - 2) != 0x39)
	{
		ss->*((word16) sp_87 + 2) = 0x00;
		fn1AB8_1C32(ds, ss->*((word16) sp_87 + 2));
		struct Eq_40130 Eq_17::* sp_1215 = (word16) sp_87 + 4;
		uint8 al_1216 = (uint8) (ss->*((word32) bp_1114 - 2));
		if (al_1216 >= 0x1E)
		{
			(ss->*((word32) bp_1114 - 3)).u1 = al_1216 - 0x01;
			while (true)
			{
				struct Eq_40158 Eq_17::* sp_1233 = sp_1215 - 2;
				Mem1234[ss:sp_1233 + 0x00:word16] = CONVERT(Mem1226[ss:bp_1114 + -3:byte], uint8, uint16) + Mem1226[ds:22708:word16];
				Mem1238[ss:sp_1233 + -2:word16] = Mem1234[ds:22712:word16] + 0x12;
				Mem1244[ss:sp_1233 + -4:word16] = CONVERT(Mem1238[ss:bp_1114 + -3:byte], uint8, uint16) + Mem1238[ds:22708:word16];
				Mem1249[ss:sp_1233 + -6:word16] = Mem1244[ds:22712:word16] + 0x13;
				word16 dx_1372;
				fn1AB8_1AF6(ds, (ss->*sp_1233).tFFFA.u2, (ss->*sp_1233).tFFFC.u2, (ss->*sp_1233).tFFFE.u2, (ss->*sp_1233).t0000.u2, out dx_1372);
				(ss->*sp_1233).t0000.u2 = (uint16) 300;
				(ss->*sp_1233).tFFFE.u2 = (uint16) 0x14;
				Eq_481 sp_1270;
				sp_1270.u0 = <invalid>;
				bp_1114 = fn0C74_070D(ds, (ss->*sp_1233).tFFFE.u2, (ss->*sp_1233).t0000.u2, out ds);
				sp_1215 = (word16) sp_1270 + 4;
				if (ss->*((word32) bp_1114 - 3) == 0x1D)
					break;
				(ss->*((word32) bp_1114 - 3)).u1 = ss->*((word32) bp_1114 - 3) - 0x01;
			}
		}
		Mem1284[ds:22708:word16] = Mem1282[ds:22708:word16] + 0x01;
		(ss->*((word32) bp_1114 - 1)).u3 = 0x00;
	}
	else
	{
		ss->*((word16) sp_87 + 2) = 0x0A;
		fn1AB8_1C32(ds, ss->*((word16) sp_87 + 2));
		Mem142[ss:sp_87 + 0x02:word16] = Mem133[ds:22708:word16] + 0x2A;
		Mem146[ss:sp_87 + 0x00:word16] = Mem142[ds:22712:word16] + 0x12;
		Mem150[ss:sp_87 + -2:word16] = Mem146[ds:22708:word16] + 0x36;
		Mem155[ss:sp_87 + -4:word16] = Mem150[ds:22712:word16] + 0x12;
		word16 dx_1370;
		fn1AB8_1AF6(ds, ss->*((word16) sp_87 - 4), ss->*((word16) sp_87 - 2), ss->*sp_87, ss->*((word16) sp_87 + 2), out dx_1370);
		ss->*((word16) sp_87 + 2) = 300;
		ss->*sp_87 = 0x14;
		Eq_17 ds_172;
		fn0C74_070D(ds, ss->*sp_87, ss->*((word16) sp_87 + 2), out ds_172);
		Eq_481 sp_176;
		sp_176.u0 = <invalid>;
		Mem185[ss:sp_176 + 0x02:word16] = Mem165[ds_172:22708:word16] + 0x2A;
		Mem189[ss:sp_176 + 0x00:word16] = Mem185[ds_172:22712:word16] + 0x11;
		Mem193[ss:sp_176 + -2:word16] = Mem189[ds_172:22708:word16] + 0x36;
		Mem198[ss:sp_176 + -4:word16] = Mem193[ds_172:22712:word16] + 0x11;
		word16 dx_1371;
		fn1AB8_1AF6(ds_172, ss->*((word16) sp_176 - 4), ss->*((word16) sp_176 - 2), ss->*sp_176, ss->*((word16) sp_176 + 2), out dx_1371);
		ss->*((word16) sp_176 + 2) = 300;
		ss->*sp_176 = 0x14;
		Eq_17 bp_210 = fn0C74_070D(ds_172, ss->*sp_176, ss->*((word16) sp_176 + 2), out ds_214);
		(ss->*((word32) bp_210 - 3)).u1 = 0x03;
		Eq_481 sp_218;
		sp_218.u0 = <invalid>;
		word16 sp_223 = (word16) sp_218 + 4;
		Eq_481 sp_408;
		while (true)
		{
			struct Eq_40276 Eq_17::* sp_226 = sp_223 - 2;
			(ss->*sp_226).t0000.u2 = (uint16) 0x00;
			fn1AB8_1C32(ds_214, (ss->*sp_226).t0000.u0);
			Mem246[ss:sp_226 + 0x00:word16] = CONVERT(Mem228[ds_214:CONVERT(Mem228[ss:bp_210 + -3:byte], uint8, uint16) + 0x4D0D:byte], uint8, uint16) + Mem228[ds_214:22708:word16];
			Mem258[ss:sp_226 + -2:word16] = CONVERT(Mem246[ds_214:CONVERT(Mem246[ss:bp_210 + -3:byte], uint8, uint16) + 0x4D21:byte], uint8, uint16) + Mem246[ds_214:22712:word16];
			Mem270[ss:sp_226 + -4:word16] = CONVERT(Mem258[ds_214:CONVERT(Mem258[ss:bp_210 + -3:byte], uint8, uint16) + 0x4D35:byte], uint8, uint16) + Mem258[ds_214:22708:word16];
			Mem283[ss:sp_226 + -6:word16] = CONVERT(Mem270[ds_214:CONVERT(Mem270[ss:bp_210 + -3:byte], uint8, uint16) + 0x4D49:byte], uint8, uint16) + Mem270[ds_214:22712:word16];
			word16 dx_1373;
			fn1AB8_1AF6(ds_214, (ss->*sp_226).tFFFA.u2, (ss->*sp_226).tFFFC.u2, (ss->*sp_226).tFFFE.u2, (ss->*sp_226).t0000.u2, out dx_1373);
			(ss->*sp_226).t0000.u2 = (uint16) 0x0A;
			fn1AB8_1C32(ds_214, (ss->*sp_226).t0000.u0);
			Mem305[ss:sp_226 + 0x00:word16] = CONVERT(Mem291[ds_214:CONVERT(Mem291[ss:bp_210 + -3:byte], uint8, uint16) + 0x4D0F:byte], uint8, uint16) + Mem291[ds_214:22708:word16];
			Mem315[ss:sp_226 + -2:word16] = CONVERT(Mem305[ds_214:CONVERT(Mem305[ss:bp_210 + -3:byte], uint8, uint16) + 19747:byte], uint8, uint16) + Mem305[ds_214:22712:word16];
			Mem325[ss:sp_226 + -4:word16] = CONVERT(Mem315[ds_214:CONVERT(Mem315[ss:bp_210 + -3:byte], uint8, uint16) + 19767:byte], uint8, uint16) + Mem315[ds_214:22708:word16];
			Mem336[ss:sp_226 + -6:word16] = CONVERT(Mem325[ds_214:CONVERT(Mem325[ss:bp_210 + -3:byte], uint8, uint16) + 0x4D4B:byte], uint8, uint16) + Mem325[ds_214:22712:word16];
			word16 dx_1374;
			fn1AB8_1AF6(ds_214, (ss->*sp_226).tFFFA.u2, (ss->*sp_226).tFFFC.u2, (ss->*sp_226).tFFFE.u2, (ss->*sp_226).t0000.u2, out dx_1374);
			Mem353[ss:sp_226 + 0x00:word16] = CONVERT(Mem336[ds_214:CONVERT(Mem336[ss:bp_210 + -3:byte], uint8, uint16) + 0x4D0E:byte], uint8, uint16) + Mem336[ds_214:22708:word16];
			Mem364[ss:sp_226 + -2:word16] = CONVERT(Mem353[ds_214:CONVERT(Mem353[ss:bp_210 + -3:byte], uint8, uint16) + 0x4D22:byte], uint8, uint16) + Mem353[ds_214:22712:word16];
			Mem375[ss:sp_226 + -4:word16] = CONVERT(Mem364[ds_214:CONVERT(Mem364[ss:bp_210 + -3:byte], uint8, uint16) + 19766:byte], uint8, uint16) + Mem364[ds_214:22708:word16];
			Mem387[ss:sp_226 + -6:word16] = CONVERT(Mem375[ds_214:CONVERT(Mem375[ss:bp_210 + -3:byte], uint8, uint16) + 0x4D4A:byte], uint8, uint16) + Mem375[ds_214:22712:word16];
			word16 dx_1375;
			fn1AB8_1AF6(ds_214, (ss->*sp_226).tFFFA.u2, (ss->*sp_226).tFFFC.u2, (ss->*sp_226).tFFFE.u2, (ss->*sp_226).t0000.u2, out dx_1375);
			(ss->*sp_226).t0000.u2 = (uint16) 400;
			(ss->*sp_226).tFFFE.u2 = (uint16) 0x32;
			sp_408.u0 = <invalid>;
			bp_210 = fn0C74_070D(ds_214, (ss->*sp_226).tFFFE.u2, (ss->*sp_226).t0000.u2, out ds_214);
			sp_223 = (word16) sp_408 + 4;
			if (ss->*((word32) bp_210 - 3) == 0x14)
				break;
			(ss->*((word32) bp_210 - 3)).u3 = &(ss->*((word32) bp_210 - 3)).u3->t0001.u0;
		}
		Mem419[ss:sp_408 + 0x02:word16] = Mem397[ds_214:22708:word16] + 0x36;
		Mem424[ss:sp_408 + 0x00:word16] = Mem419[ds_214:22712:word16] + 0x11;
		ss->*((word16) sp_408 - 2) = 0x00;
		fn1AB8_1E54(ds_214, ss->*((word16) sp_408 - 2), ss->*sp_408, ss->*((word16) sp_408 + 2));
		Mem435[ss:sp_408 + 0x02:word16] = Mem426[ds_214:22708:word16] + 55;
		Mem439[ss:sp_408 + 0x00:word16] = Mem435[ds_214:22712:word16] + 0x06;
		Mem443[ss:sp_408 + -2:word16] = Mem439[ds_214:22708:word16] + 55;
		Mem448[ss:sp_408 + -4:word16] = Mem443[ds_214:22712:word16] + 0x10;
		word16 dx_1376;
		fn1AB8_1AF6(ds_214, ss->*((word16) sp_408 - 4), ss->*((word16) sp_408 - 2), ss->*sp_408, ss->*((word16) sp_408 + 2), out dx_1376);
		Mem457[ss:bp_210 + -6:word16] = Mem448[ds_214:22712:word16] + 0x06;
		Mem461[ss:bp_210 + -8:word16] = Mem457[ds_214:22712:word16] + 0x14;
		(ss->*((word32) bp_210 - 3)).u1 = 0x01;
		struct Eq_40723 Eq_17::* sp_454 = (word16) sp_408 + 4;
		Eq_481 sp_570;
		while (true)
		{
			struct Eq_40736 Eq_17::* sp_464 = sp_454 - 2;
			(ss->*sp_464).t0000.u2 = (uint16) 0x00;
			fn1AB8_1C32(ds_214, (ss->*sp_464).t0000.u0);
			Mem475[ss:sp_464 + 0x00:word16] = Mem466[ds_214:22708:word16] + 55;
			(ss->*sp_464).tFFFE.u2 = (uint16) (ss->*((word32) bp_210 - 6));
			Mem484[ss:sp_464 + -4:word16] = Mem479[ds_214:22708:word16] + 0x38;
			(ss->*sp_464).tFFFA.u2 = (uint16) (ss->*((word32) bp_210 - 6));
			word16 dx_1377;
			fn1AB8_1AF6(ds_214, (ss->*sp_464).tFFFA.u2, (ss->*sp_464).tFFFC.u2, (ss->*sp_464).tFFFE.u2, (ss->*sp_464).t0000.u2, out dx_1377);
			(ss->*sp_464).t0000.u2 = (uint16) 0x0A;
			fn1AB8_1C32(ds_214, (ss->*sp_464).t0000.u0);
			Mem503[ss:sp_464 + 0x00:word16] = Mem495[ds_214:22708:word16] + 55;
			(ss->*sp_464).tFFFE.u2 = (uint16) (ss->*((word32) bp_210 - 8));
			Mem511[ss:sp_464 + -4:word16] = Mem506[ds_214:22708:word16] + 0x38;
			(ss->*sp_464).tFFFA.u2 = (uint16) (ss->*((word32) bp_210 - 8));
			word16 dx_1378;
			fn1AB8_1AF6(ds_214, (ss->*sp_464).tFFFA.u2, (ss->*sp_464).tFFFC.u2, (ss->*sp_464).tFFFE.u2, (ss->*sp_464).t0000.u2, out dx_1378);
			Mem525[ss:sp_464 + 0x00:word16] = Mem514[ds_214:22708:word16] + 0x36;
			(ss->*sp_464).tFFFE.u2 = (uint16) (ss->*((word32) bp_210 - 8));
			(ss->*sp_464).tFFFC.u2 = (uint16) 0x00;
			fn1AB8_1E54(ds_214, (ss->*sp_464).tFFFC.u0, (ss->*sp_464).tFFFE.u2, (ss->*sp_464).t0000.u2);
			Mem540[ss:sp_464 + 0x00:word16] = Mem530[ds_214:22708:word16] + 0x39;
			(ss->*sp_464).tFFFE.u2 = (uint16) (ss->*((word32) bp_210 - 8));
			(ss->*sp_464).tFFFC.u2 = (uint16) 0x00;
			fn1AB8_1E54(ds_214, (ss->*sp_464).tFFFC.u0, (ss->*sp_464).tFFFE.u2, (ss->*sp_464).t0000.u2);
			(ss->*((word32) bp_210 - 6)).u3 = &(ss->*((word32) bp_210 - 6)).u3->t0001.u0;
			(ss->*((word32) bp_210 - 8)).u3 = &(ss->*((word32) bp_210 - 8)).u3->t0001.u0;
			(ss->*sp_464).t0000.u2 = (uint16) 100;
			(ss->*sp_464).tFFFE.u2 = (uint16) 100;
			sp_570.u0 = <invalid>;
			bp_210 = fn0C74_070D(ds_214, (ss->*sp_464).tFFFE.u2, (ss->*sp_464).t0000.u2, out ds_214);
			sp_454 = (word16) sp_570 + 4;
			if (ss->*((word32) bp_210 - 3) == 11)
				break;
			(ss->*((word32) bp_210 - 3)).u3 = &(ss->*((word32) bp_210 - 3)).u3->t0001.u0;
		}
		ss->*((word16) sp_570 + 2) = 0x0A;
		fn1AB8_1C32(ds_214, ss->*((word16) sp_570 + 2));
		Mem590[ss:sp_570 + 0x02:word16] = Mem582[ds_214:22708:word16] + 55;
		ss->*sp_570 = ss->*((word32) bp_210 - 8);
		Mem598[ss:sp_570 + -2:word16] = Mem593[ds_214:22708:word16] + 0x38;
		ss->*((word16) sp_570 - 4) = ss->*((word32) bp_210 - 8);
		word16 dx_1379;
		fn1AB8_1AF6(ds_214, ss->*((word16) sp_570 - 4), ss->*((word16) sp_570 - 2), ss->*sp_570, ss->*((word16) sp_570 + 2), out dx_1379);
		Mem612[ss:sp_570 + 0x02:word16] = Mem601[ds_214:22708:word16] + 0x36;
		ss->*sp_570 = ss->*((word32) bp_210 - 8);
		ss->*((word16) sp_570 - 2) = 0x00;
		fn1AB8_1E54(ds_214, ss->*((word16) sp_570 - 2), ss->*sp_570, ss->*((word16) sp_570 + 2));
		Mem627[ss:sp_570 + 0x02:word16] = Mem617[ds_214:22708:word16] + 0x39;
		ss->*sp_570 = ss->*((word32) bp_210 - 8);
		ss->*((word16) sp_570 - 2) = 0x00;
		fn1AB8_1E54(ds_214, ss->*((word16) sp_570 - 2), ss->*sp_570, ss->*((word16) sp_570 + 2));
		ss->*((word16) sp_570 + 2) = 500;
		Eq_17 bp_641 = fn0C74_02D8(ds_214, ss->*((word16) sp_570 + 2), out ds_645);
		Eq_481 sp_649;
		sp_649.u0 = <invalid>;
		ss->*sp_649 = 0x00;
		fn1AB8_1C32(ds_645, ss->*sp_649);
		Mem664[ss:sp_649 + 0x00:word16] = Mem656[ds_645:22708:word16] + 55;
		ss->*((word16) sp_649 - 2) = ss->*((word32) bp_641 - 8);
		Mem672[ss:sp_649 + -4:word16] = Mem667[ds_645:22708:word16] + 0x38;
		ss->*((word16) sp_649 - 6) = ss->*((word32) bp_641 - 8);
		word16 dx_1380;
		fn1AB8_1AF6(ds_645, ss->*((word16) sp_649 - 6), ss->*((word16) sp_649 - 4), ss->*((word16) sp_649 - 2), ss->*sp_649, out dx_1380);
		Mem684[ss:bp_641 + -6:word16] = Mem675[ds_645:22712:word16] + 0x10;
		Mem688[ss:bp_641 + -8:word16] = Mem684[ds_645:22712:word16] + 0x1E;
		(ss->*((word32) bp_641 - 3)).u1 = 0x01;
		struct Eq_41239 Eq_17::* sp_681 = (word16) sp_649 + 2;
		while (true)
		{
			struct Eq_41242 Eq_17::* sp_691 = sp_681 - 2;
			(ss->*sp_691).t0000.u2 = (uint16) 0x0A;
			fn1AB8_1C32(ds_645, (ss->*sp_691).t0000.u0);
			Mem702[ss:sp_691 + 0x00:word16] = Mem693[ds_645:22708:word16] + 55;
			(ss->*sp_691).tFFFE.u2 = (uint16) (ss->*((word32) bp_641 - 6));
			Mem711[ss:sp_691 + -4:word16] = Mem706[ds_645:22708:word16] + 0x38;
			(ss->*sp_691).tFFFA.u2 = (uint16) (ss->*((word32) bp_641 - 6));
			word16 dx_1381;
			fn1AB8_1AF6(ds_645, (ss->*sp_691).tFFFA.u2, (ss->*sp_691).tFFFC.u2, (ss->*sp_691).tFFFE.u2, (ss->*sp_691).t0000.u2, out dx_1381);
			(ss->*sp_691).t0000.u2 = (uint16) 0x00;
			fn1AB8_1C32(ds_645, (ss->*sp_691).t0000.u0);
			Mem730[ss:sp_691 + 0x00:word16] = Mem722[ds_645:22708:word16] + 55;
			(ss->*sp_691).tFFFE.u2 = (uint16) (ss->*((word32) bp_641 - 8));
			Mem738[ss:sp_691 + -4:word16] = Mem733[ds_645:22708:word16] + 0x38;
			(ss->*sp_691).tFFFA.u2 = (uint16) (ss->*((word32) bp_641 - 8));
			word16 dx_1382;
			fn1AB8_1AF6(ds_645, (ss->*sp_691).tFFFA.u2, (ss->*sp_691).tFFFC.u2, (ss->*sp_691).tFFFE.u2, (ss->*sp_691).t0000.u2, out dx_1382);
			--ss->*((word32) bp_641 - 6);
			--ss->*((word32) bp_641 - 8);
			(ss->*sp_691).t0000.u2 = (uint16) 100;
			(ss->*sp_691).tFFFE.u2 = (uint16) 100;
			Eq_481 sp_767;
			sp_767.u0 = <invalid>;
			bp_641 = fn0C74_070D(ds_645, (ss->*sp_691).tFFFE.u2, (ss->*sp_691).t0000.u2, out ds_645);
			sp_681 = (word16) sp_767 + 4;
			if (ss->*((word32) bp_641 - 3) == 11)
				break;
			(ss->*((word32) bp_641 - 3)).u3 = &(ss->*((word32) bp_641 - 3)).u3->t0001.u0;
		}
		(ss->*((word32) bp_641 - 3)).u1 = 0x14;
		Eq_481 sp_962;
		while (true)
		{
			struct Eq_41440 Eq_17::* sp_780 = sp_681 - 2;
			(ss->*sp_780).t0000.u2 = (uint16) 0x00;
			fn1AB8_1C32(ds_645, (ss->*sp_780).t0000.u0);
			Mem798[ss:sp_780 + 0x00:word16] = CONVERT(Mem782[ds_645:CONVERT(Mem782[ss:bp_641 + -3:byte], uint8, uint16) + 0x4D0F:byte], uint8, uint16) + Mem782[ds_645:22708:word16];
			Mem808[ss:sp_780 + -2:word16] = CONVERT(Mem798[ds_645:CONVERT(Mem798[ss:bp_641 + -3:byte], uint8, uint16) + 19747:byte], uint8, uint16) + Mem798[ds_645:22712:word16];
			Mem818[ss:sp_780 + -4:word16] = CONVERT(Mem808[ds_645:CONVERT(Mem808[ss:bp_641 + -3:byte], uint8, uint16) + 19767:byte], uint8, uint16) + Mem808[ds_645:22708:word16];
			Mem829[ss:sp_780 + -6:word16] = CONVERT(Mem818[ds_645:CONVERT(Mem818[ss:bp_641 + -3:byte], uint8, uint16) + 0x4D4B:byte], uint8, uint16) + Mem818[ds_645:22712:word16];
			word16 dx_1383;
			fn1AB8_1AF6(ds_645, (ss->*sp_780).tFFFA.u2, (ss->*sp_780).tFFFC.u2, (ss->*sp_780).tFFFE.u2, (ss->*sp_780).t0000.u2, out dx_1383);
			(ss->*sp_780).t0000.u2 = (uint16) 0x0A;
			fn1AB8_1C32(ds_645, (ss->*sp_780).t0000.u0);
			Mem853[ss:sp_780 + 0x00:word16] = CONVERT(Mem837[ds_645:CONVERT(Mem837[ss:bp_641 + -3:byte], uint8, uint16) + 0x4D0D:byte], uint8, uint16) + Mem837[ds_645:22708:word16];
			Mem865[ss:sp_780 + -2:word16] = CONVERT(Mem853[ds_645:CONVERT(Mem853[ss:bp_641 + -3:byte], uint8, uint16) + 0x4D21:byte], uint8, uint16) + Mem853[ds_645:22712:word16];
			Mem877[ss:sp_780 + -4:word16] = CONVERT(Mem865[ds_645:CONVERT(Mem865[ss:bp_641 + -3:byte], uint8, uint16) + 0x4D35:byte], uint8, uint16) + Mem865[ds_645:22708:word16];
			Mem890[ss:sp_780 + -6:word16] = CONVERT(Mem877[ds_645:CONVERT(Mem877[ss:bp_641 + -3:byte], uint8, uint16) + 0x4D49:byte], uint8, uint16) + Mem877[ds_645:22712:word16];
			word16 dx_1384;
			fn1AB8_1AF6(ds_645, (ss->*sp_780).tFFFA.u2, (ss->*sp_780).tFFFC.u2, (ss->*sp_780).tFFFE.u2, (ss->*sp_780).t0000.u2, out dx_1384);
			Mem907[ss:sp_780 + 0x00:word16] = CONVERT(Mem890[ds_645:CONVERT(Mem890[ss:bp_641 + -3:byte], uint8, uint16) + 0x4D0E:byte], uint8, uint16) + Mem890[ds_645:22708:word16];
			Mem918[ss:sp_780 + -2:word16] = CONVERT(Mem907[ds_645:CONVERT(Mem907[ss:bp_641 + -3:byte], uint8, uint16) + 0x4D22:byte], uint8, uint16) + Mem907[ds_645:22712:word16];
			Mem929[ss:sp_780 + -4:word16] = CONVERT(Mem918[ds_645:CONVERT(Mem918[ss:bp_641 + -3:byte], uint8, uint16) + 19766:byte], uint8, uint16) + Mem918[ds_645:22708:word16];
			Mem941[ss:sp_780 + -6:word16] = CONVERT(Mem929[ds_645:CONVERT(Mem929[ss:bp_641 + -3:byte], uint8, uint16) + 0x4D4A:byte], uint8, uint16) + Mem929[ds_645:22712:word16];
			word16 dx_1385;
			fn1AB8_1AF6(ds_645, (ss->*sp_780).tFFFA.u2, (ss->*sp_780).tFFFC.u2, (ss->*sp_780).tFFFE.u2, (ss->*sp_780).t0000.u2, out dx_1385);
			(ss->*sp_780).t0000.u2 = (uint16) 400;
			(ss->*sp_780).tFFFE.u2 = (uint16) 0x32;
			sp_962.u0 = <invalid>;
			bp_641 = fn0C74_070D(ds_645, (ss->*sp_780).tFFFE.u2, (ss->*sp_780).t0000.u2, out ds_645);
			sp_681 = (word16) sp_962 + 4;
			if (ss->*((word32) bp_641 - 3) == 0x03)
				break;
			(ss->*((word32) bp_641 - 3)).u1 = ss->*((word32) bp_641 - 3) - 0x01;
		}
		Mem973[ss:sp_962 + 0x02:word16] = Mem951[ds_645:22708:word16] + 55;
		Mem978[ss:sp_962 + 0x00:word16] = Mem973[ds_645:22712:word16] + 0x10;
		ss->*((word16) sp_962 - 2) = 0x00;
		fn1AB8_1E54(ds_645, ss->*((word16) sp_962 - 2), ss->*sp_962, ss->*((word16) sp_962 + 2));
		ss->*((word16) sp_962 + 2) = 0x0A;
		fn1AB8_1C32(ds_645, ss->*((word16) sp_962 + 2));
		Mem995[ss:sp_962 + 0x02:word16] = Mem987[ds_645:22708:word16] + 0x2A;
		Mem999[ss:sp_962 + 0x00:word16] = Mem995[ds_645:22712:word16] + 0x11;
		Mem1003[ss:sp_962 + -2:word16] = Mem999[ds_645:22708:word16] + 0x36;
		Mem1008[ss:sp_962 + -4:word16] = Mem1003[ds_645:22712:word16] + 0x11;
		word16 dx_1386;
		fn1AB8_1AF6(ds_645, ss->*((word16) sp_962 - 4), ss->*((word16) sp_962 - 2), ss->*sp_962, ss->*((word16) sp_962 + 2), out dx_1386);
		ss->*((word16) sp_962 + 2) = 500;
		Eq_17 ds_1022;
		fn0C74_02D8(ds_645, ss->*((word16) sp_962 + 2), out ds_1022);
		Eq_481 sp_1026;
		sp_1026.u0 = <invalid>;
		ss->*sp_1026 = 0x00;
		fn1AB8_1C32(ds_1022, ss->*sp_1026);
		Mem1041[ss:sp_1026 + 0x00:word16] = Mem1033[ds_1022:22708:word16] + 0x2A;
		Mem1045[ss:sp_1026 + -2:word16] = Mem1041[ds_1022:22712:word16] + 0x11;
		Mem1049[ss:sp_1026 + -4:word16] = Mem1045[ds_1022:22708:word16] + 0x36;
		Mem1054[ss:sp_1026 + -6:word16] = Mem1049[ds_1022:22712:word16] + 0x11;
		word16 dx_1387;
		fn1AB8_1AF6(ds_1022, ss->*((word16) sp_1026 - 6), ss->*((word16) sp_1026 - 4), ss->*((word16) sp_1026 - 2), ss->*sp_1026, out dx_1387);
		ss->*sp_1026 = 300;
		ss->*((word16) sp_1026 - 2) = 0x14;
		Eq_17 ds_1070;
		fn0C74_070D(ds_1022, ss->*((word16) sp_1026 - 2), ss->*sp_1026, out ds_1070);
		Eq_481 sp_1074;
		sp_1074.u0 = <invalid>;
		ss->*((word16) sp_1074 + 2) = 0x0C;
		fn1AB8_1C32(ds_1070, ss->*((word16) sp_1074 + 2));
		Mem1089[ss:sp_1074 + 0x02:word16] = Mem1081[ds_1070:22708:word16] + 0x2A;
		Mem1093[ss:sp_1074 + 0x00:word16] = Mem1089[ds_1070:22712:word16] + 0x12;
		Mem1097[ss:sp_1074 + -2:word16] = Mem1093[ds_1070:22708:word16] + 0x36;
		Mem1102[ss:sp_1074 + -4:word16] = Mem1097[ds_1070:22712:word16] + 0x12;
		word16 dx_1388;
		fn1AB8_1AF6(ds_1070, ss->*((word16) sp_1074 - 4), ss->*((word16) sp_1074 - 2), ss->*sp_1074, ss->*((word16) sp_1074 + 2), out dx_1388);
		ss->*((word16) sp_1074 + 2) = 300;
		ss->*sp_1074 = 0x14;
		bp_1114 = fn0C74_070D(ds_1070, ss->*sp_1074, ss->*((word16) sp_1074 + 2), out ds);
		Eq_481 sp_1122;
		sp_1122.u0 = <invalid>;
		ss->*((word16) sp_1122 + 2) = 0x00;
		fn1AB8_1C32(ds, ss->*((word16) sp_1122 + 2));
		struct Eq_42075 Eq_17::* sp_1133 = (word16) sp_1122 + 4;
		uint8 al_1134 = (uint8) (ss->*((word32) bp_1114 - 2));
		if (al_1134 >= 0x1E)
		{
			(ss->*((word32) bp_1114 - 3)).u1 = al_1134 - 0x01;
			while (true)
			{
				struct Eq_42108 Eq_17::* sp_1151 = sp_1133 - 2;
				Mem1152[ss:sp_1151 + 0x00:word16] = CONVERT(Mem1144[ss:bp_1114 + -3:byte], uint8, uint16) + Mem1144[ds:22708:word16];
				Mem1156[ss:sp_1151 + -2:word16] = Mem1152[ds:22712:word16] + 0x12;
				Mem1162[ss:sp_1151 + -4:word16] = CONVERT(Mem1156[ss:bp_1114 + -3:byte], uint8, uint16) + Mem1156[ds:22708:word16];
				Mem1167[ss:sp_1151 + -6:word16] = Mem1162[ds:22712:word16] + 0x13;
				word16 dx_1389;
				fn1AB8_1AF6(ds, (ss->*sp_1151).tFFFA.u2, (ss->*sp_1151).tFFFC.u2, (ss->*sp_1151).tFFFE.u2, (ss->*sp_1151).t0000.u2, out dx_1389);
				(ss->*sp_1151).t0000.u2 = (uint16) 300;
				(ss->*sp_1151).tFFFE.u2 = (uint16) 0x14;
				Eq_481 sp_1188;
				sp_1188.u0 = <invalid>;
				bp_1114 = fn0C74_070D(ds, (ss->*sp_1151).tFFFE.u2, (ss->*sp_1151).t0000.u2, out ds);
				sp_1133 = (word16) sp_1188 + 4;
				if (ss->*((word32) bp_1114 - 3) == 0x1D)
					break;
				(ss->*((word32) bp_1114 - 3)).u1 = ss->*((word32) bp_1114 - 3) - 0x01;
			}
		}
		Mem1202[ds:22708:word16] = Mem1200[ds:22708:word16] + 0x01;
	}
	byte al_1294 = (byte) (ss->*((word32) bp_1114 - 1));
	bpOut = (struct Eq_40272 Eq_17::*) (ss->*bp_1114.u3).t0000.u2;
	dsOut = ds;
	return al_1294;
}
