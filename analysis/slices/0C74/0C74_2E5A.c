// 0C74:2E5A: Register byte fn0C74_2E5A(Register Eq_17 ds, Register out word16 bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_522C
byte fn0C74_2E5A(Eq_17 ds, word16 & bpOut, union Eq_17 & dsOut)
{
	Eq_17 ds_240;
	mp16 fp;
	Eq_17 bp_1029 = fp - 2;
	selector ss;
	if (Mem10[ds:22708:word16] >u 0x01)
	{
		byte dl_1206;
		byte dl_1207;
		byte dl_1208;
		byte dl_1209;
		byte dl_1210;
		if (fn1AB8_1E3C(ds, Mem18[ds:22714:word16], Mem10[ds:22708:word16] - 0x01, out dl_1206) != 0x00 && (fn1AB8_1E3C(ds, Mem39[ds:22712:word16] + 22, Mem21[ds:22708:word16] - 0x09, out dl_1207) != 0x00 && (fn1AB8_1E3C(ds, Mem63[ds:22714:word16], Mem44[ds:22708:word16] - 0x17, out dl_1208) == 0x00 && (fn1AB8_1E3C(ds, Mem85[ds:22712:word16], Mem66[ds:22708:word16] - 0x01, out dl_1209) == 0x00 && fn1AB8_1E3C(ds, Mem106[ds:22712:word16] + 22, Mem88[ds:22708:word16] - 0x17, out dl_1210) == 0x00))))
		{
			Eq_17 ax_131 = Mem130[ds:22712:word16];
			Eq_17 v19_136 = Mem135[ds:22708:word16];
			Eq_17 ds_161;
			fn1AB8_1E6B(ds_161, fn1EDA_023F(ds, v19_136, (word32) ax_131 + 21, fn1AB8_13A3(ds, Mem138[ds:22714:word16], v19_136, ax_131 + 0x15, Mem126[ds:22708:word16] - 22), out ds_161), Mem183[ds_161:22714:word16], Mem180[ds_161:22708:word16], Mem175[ds_161:22712:word16] + 22, Mem171[ds_161:22708:word16] - 22);
			Eq_17 ax_209 = Mem208[ds_161:22712:word16];
			Eq_17 ax_213 = Mem212[ds_161:22708:word16];
			Eq_17 ax_222 = fn1AB8_13A3(ds_161, Mem216[ds_161:22712:word16] + 0x1B, ax_213 + 0x11, ax_209 + 0x0D, Mem193[ds_161:22708:word16] + 0x0D);
			Eq_17 dx_ax_1202 = fn1EDA_023F(ds_161, (word32) ax_213 + 0x0011, (word32) ax_209 + 0x0D, ax_222, out ds_240);
			fn1AB8_1E6B(ds_240, dx_ax_1202, Mem262[ds_240:22712:word16] + 0x1B, Mem258[ds_240:22708:word16] + 0x11, Mem254[ds_240:22712:word16] + 0x0D, Mem250[ds_240:22708:word16] + 0x0D);
			fn1AB8_13D7(ds_240, 0x00, dx_ax_1202, Mem293[ds_240:22712:word16] + 0x0D, Mem274[ds_240:22708:word16] + 0x0C);
			fn1AB8_10F4(ds_240, 0x01, 0x00, 0x00);
			fn1AB8_1C32(ds_240, 0x00);
			Eq_17 ax_354 = Mem353[ds_240:22712:word16];
			word16 dx_1211;
			fn1AB8_1AF6(ds_240, (word32) ax_354 + 27, Mem349[ds_240:22708:word16] + 0x11, Mem345[ds_240:22712:word16] + 0x0D, Mem337[ds_240:22708:word16] + 0x11, out dx_1211);
			fn1AB8_1E54(ds_240, 11, Mem368[ds_240:22712:word16] + 0x12, Mem358[ds_240:22708:word16] + 0x11);
			fn1AB8_1E54(ds_240, 0x03, Mem384[ds_240:22712:word16] + 0x13, Mem375[ds_240:22708:word16] + 0x11);
			fn1AB8_1E54(ds_240, 0x09, Mem400[ds_240:22712:word16] + 0x14, Mem391[ds_240:22708:word16] + 0x11);
			word16 dx_1212;
			Eq_17 ds_426;
			fn1EDA_0254(ds_240, 0x00, (word32) ax_354 + 27, ax_222, dx_ax_1202, out dx_1212, out ds_426);
			Eq_17 ax_440 = Mem439[ds_426:22712:word16];
			Eq_17 ax_444 = Mem443[ds_426:22708:word16];
			Eq_17 ds_471;
			fn1AB8_1E6B(ds_471, fn1EDA_023F(ds_426, (word32) ax_444 + 0x0011, (word32) ax_440 + 0x0D, fn1AB8_13A3(ds_426, Mem447[ds_426:22712:word16] + 0x1B, ax_444 + 0x11, ax_440 + 0x0D, Mem421[ds_426:22708:word16] + 0x0C), out ds_471), Mem493[ds_471:22712:word16] + 0x1B, Mem489[ds_471:22708:word16] + 0x11, Mem485[ds_471:22712:word16] + 0x0D, Mem481[ds_471:22708:word16] + 0x0C);
			struct Eq_36749 Eq_17::* sp_1023 = fp - 0x20;
			while (ss->*((word32) bp_1029 - 2) < 0x14)
			{
				struct Eq_36801 Eq_17::* sp_532 = sp_1023 - 2;
				Mem533[ss:sp_532 + 0x00:word16] = Mem520[ds_471:22708:word16] + 0x0C - CONVERT(Mem520[ss:bp_1029 + -2:byte], uint8, uint16);
				Mem538[ss:sp_532 + -2:word16] = Mem533[ds_471:22712:word16] + 0x1B;
				byte dl_1213;
				if (fn1AB8_1E3C(ds_471, (ss->*sp_532).tFFFE.u2, (ss->*sp_532).t0000.u2, out dl_1213) != 0x00)
					break;
				(ss->*sp_532).t0000.u2 = (uint16) 0xE6;
				(ss->*sp_532).tFFFE.u2 = (uint16) 0x0A;
				bp_1029 = fn0C74_070D(ds_471, (ss->*sp_532).tFFFE.u2, (ss->*sp_532).t0000.u2, out ds_471);
				Eq_481 sp_983;
				sp_983.u0 = <invalid>;
				Mem997[ss:sp_983 + 0x02:word16] = Mem972[ds_471:22708:word16] + 0x0D - CONVERT(Mem972[ss:bp_1029 + -2:byte], uint8, uint16);
				Mem1002[ss:sp_983 + 0x00:word16] = Mem997[ds_471:22712:word16] + 0x0D;
				Eq_17 es_di_1003 = ss->*((word32) bp_1029 - 30);
				ss->*((word16) sp_983 - 2) = SLICE(es_di_1003, selector, 16);
				ss->*((word16) sp_983 - 4) = (word16) es_di_1003;
				ss->*((word16) sp_983 - 6) = 0x00;
				fn1AB8_13D7(ds_471, ss->*((word16) sp_983 + 6), ss->*((word16) sp_983 - 4), ss->*sp_983, ss->*((word16) sp_983 + 2));
				(ss->*((word32) bp_1029 - 2)).u3 = &(ss->*((word32) bp_1029 - 2)).u3->t0001.u0;
				sp_1023 = (word16) sp_983 + 4;
			}
			(ss->*((word32) bp_1029 - 8)).u2 = (uint16) (ss->*((word32) bp_1029 - 2));
			Mem563[ss:bp_1029 + -20:word16] = Mem559[ds_471:22708:word16] - 22;
			Mem566[ss:bp_1029 + -22:word16] = Mem563[ds_471:22708:word16] - 0x01;
			Mem570[ss:bp_1029 + -24:word16] = Mem566[ds_471:22712:word16] + 0x15;
			Mem572[ss:bp_1029 + -26:word16] = Mem570[ds_471:22714:word16];
			(ss->*((word32) bp_1029 - 3)).u1 = 0x01;
			struct Eq_36749 Eq_17::* sp_1037 = sp_1023;
			Eq_481 sp_657;
			while (true)
			{
				--ss->*((word32) bp_1029 - 20);
				--ss->*((word32) bp_1029 - 22);
				struct Eq_36964 Eq_17::* sp_583 = sp_1037 - 2;
				(ss->*sp_583).t0000.u2 = (uint16) (ss->*((word32) bp_1029 - 20));
				(ss->*sp_583).tFFFE.u2 = (uint16) &(ss->*((word32) bp_1029 - 24)).u3->t0001.u0;
				Eq_17 es_di_590 = ss->*((word32) bp_1029 - 0x0E);
				(ss->*sp_583).ptrFFFC = SLICE(es_di_590, selector, 16);
				(ss->*sp_583).tFFFA.u2 = (uint16) (word16) es_di_590;
				(ss->*sp_583).wFFF8 = 0x00;
				fn1AB8_13D7(ds_471, (ss->*sp_583).t0008.u0, (ss->*sp_583).tFFFA.u3, (ss->*sp_583).tFFFE.u2, (ss->*sp_583).t0000.u2);
				(ss->*sp_583).t0000.u2 = (uint16) &(ss->*((word32) bp_1029 - 22)).u3->t0002.u0;
				Mem621[ss:sp_583 + -2:word16] = Mem616[ds_471:22712:word16] + 0x0D;
				Eq_17 es_di_622 = ss->*((word32) bp_1029 - 30);
				(ss->*sp_583).ptrFFFC = SLICE(es_di_622, selector, 16);
				(ss->*sp_583).tFFFA.u2 = (uint16) (word16) es_di_622;
				(ss->*sp_583).wFFF8 = 0x00;
				fn1AB8_13D7(ds_471, (ss->*sp_583).t0008.u0, (ss->*sp_583).tFFFA.u3, (ss->*sp_583).tFFFE.u2, (ss->*sp_583).t0000.u2);
				(ss->*sp_583).t0000.u2 = (uint16) 0xE6;
				(ss->*sp_583).tFFFE.u2 = (uint16) 0x14;
				sp_657.u0 = <invalid>;
				bp_1029 = fn0C74_070D(ds_471, (ss->*sp_583).tFFFE.u2, (ss->*sp_583).t0000.u2, out ds_471);
				sp_1037 = (word16) sp_657 + 4;
				if (ss->*((word32) bp_1029 - 3) == 22)
					break;
				(ss->*((word32) bp_1029 - 3)).u3 = &(ss->*((word32) bp_1029 - 3)).u3->t0001.u0;
			}
			ss->*((word16) sp_657 + 2) = ss->*((word32) bp_1029 - 22);
			ss->*sp_657 = &(ss->*((word32) bp_1029 - 26)).u3->t0001.u0;
			byte dl_1214;
			if (fn1AB8_1E3C(ds_471, ss->*sp_657, ss->*((word16) sp_657 + 2), out dl_1214) == 0x00)
			{
				ss->*((word16) sp_657 + 2) = ss->*((word32) bp_1029 - 20);
				ss->*sp_657 = ss->*((word32) bp_1029 - 24);
				ss->*((word16) sp_657 - 2) = ss->*((word32) bp_1029 - 22);
				ss->*((word16) sp_657 - 4) = ss->*((word32) bp_1029 - 26);
				ds_471 = fn0C74_2BBD(ds_471, ss->*((word16) sp_657 - 4), ss->*((word16) sp_657 - 2), ss->*sp_657, ss->*((word16) sp_657 + 2));
			}
			struct Eq_37152 Eq_17::* sp_727 = (word16) sp_657 + 4;
			uint8 al_721 = (uint8) ((word32) (ss->*((word32) bp_1029 + 8)) + 22);
			if (true)
			{
				(ss->*((word32) bp_1029 - 3)).u1 = al_721;
				while (true)
				{
					struct Eq_37280 Eq_17::* sp_728 = sp_727 - 2;
					(ss->*sp_728).t0000.u2 = (uint16) 0xE6;
					(ss->*sp_728).tFFFE.u2 = (uint16) 0x05;
					bp_1029 = fn0C74_070D(ds_471, (ss->*sp_728).tFFFE.u2, (ss->*sp_728).t0000.u2, out ds_471);
					Eq_481 sp_744;
					sp_744.u0 = <invalid>;
					Mem758[ss:sp_744 + 0x02:word16] = Mem732[ds_471:22708:word16] + 0x0D - CONVERT(Mem732[ss:bp_1029 + -3:byte], uint8, uint16);
					Mem763[ss:sp_744 + 0x00:word16] = Mem758[ds_471:22712:word16] + 0x0D;
					Eq_17 es_di_764 = ss->*((word32) bp_1029 - 30);
					ss->*((word16) sp_744 - 2) = SLICE(es_di_764, selector, 16);
					ss->*((word16) sp_744 - 4) = (word16) es_di_764;
					ss->*((word16) sp_744 - 6) = 0x00;
					fn1AB8_13D7(ds_471, ss->*((word16) sp_744 + 6), ss->*((word16) sp_744 - 4), ss->*sp_744, ss->*((word16) sp_744 + 2));
					sp_727 = (word16) sp_744 + 4;
					if (ss->*((word32) bp_1029 - 3) == 0x00)
						break;
					(ss->*((word32) bp_1029 - 3)).u1 = ss->*((word32) bp_1029 - 3) - 0x01;
				}
			}
			struct Eq_37214 Eq_17::* sp_796 = sp_727 - 2;
			(ss->*sp_796).t0000.u2 = (uint16) (ss->*((word32) bp_1029 - 28));
			(ss->*sp_796).tFFFE.u2 = (uint16) (ss->*((word32) bp_1029 - 30));
			(ss->*sp_796).tFFFC.u2 = (uint16) (ss->*((word32) bp_1029 - 18));
			word16 dx_1215;
			Eq_17 ds_812;
			fn1EDA_0254(ds_471, (ss->*sp_796).tFFF8.u2, (ss->*sp_796).tFFFA.u2, (ss->*sp_796).tFFFC.u2, (ss->*sp_796).tFFFE.u3, out dx_1215, out ds_812);
			(ss->*((word32) bp_1029 - 2)).u1 = 0x05;
			(ss->*((word32) bp_1029 - 3)).u1 = 0x01;
			struct Eq_37273 Eq_17::* sp_821 = (struct Eq_37273 Eq_17::*) &sp_796->t0002.u0;
			Eq_481 sp_862;
			while (true)
			{
				struct Eq_37375 Eq_17::* sp_836 = sp_821 - 2;
				Mem838[ss:sp_836 + 0x00:word16] = CONVERT(Mem825[ds_812:22758:word16], int16, int32) /16 0x02;
				word16 dx_1216;
				fn1E78_029C(ds_812, (ss->*sp_836).t0000.u2, out dx_1216);
				(ss->*sp_836).t0000.u2 = (uint16) 0x0A;
				bp_1029 = fn0C74_02D8(ds_812, (ss->*sp_836).t0000.u2, out ds_812);
				(ss->*((word32) bp_1029 - 2)).u1 = ss->*((word32) bp_1029 - 2) - 0x01;
				sp_862.u0 = <invalid>;
				if (ss->*((word32) bp_1029 - 2) == 0x00)
				{
					(ss->*((word32) bp_1029 - 2)).u1 = 0x04;
					if (Mem878[ds_812:0x58B0:byte] != 0x00)
					{
						ss->*sp_862 = 0x32;
						fn11C8_0354(ds_812, ss->*sp_862);
					}
				}
				else
					fn11C8_033B(ds_812);
				Mem897[ds_812:22708:word16] = Mem894[ds_812:22708:word16] - 0x01;
				Mem899[ds_812:22710:word16] = Mem897[ds_812:22710:word16] - 0x01;
				Mem906[ss:sp_862 + 0x00:word16] = Mem899[ds_812:22708:word16];
				Mem909[ss:sp_862 + -2:word16] = Mem906[ds_812:22712:word16];
				segptr32 es_di_918 = (*((word32) ds_812 + 22772))[(uint16) (ss->*((word32) bp_1029 - 2))];
				ss->*((word16) sp_862 - 4) = SLICE(es_di_918, selector, 16);
				ss->*((word16) sp_862 - 6) = (word16) es_di_918;
				ss->*((word16) sp_862 - 8) = 0x00;
				fn1AB8_13D7(ds_812, ss->*((word16) sp_862 + 8), ss->*((word16) sp_862 - 6), ss->*((word16) sp_862 - 2), ss->*sp_862);
				sp_821 = (word16) sp_862 + 2;
				if (ss->*((word32) bp_1029 - 3) == 22)
					break;
				(ss->*((word32) bp_1029 - 3)).u3 = &(ss->*((word32) bp_1029 - 3)).u3->t0001.u0;
			}
			ss->*sp_862 = ss->*((word32) bp_1029 - 0x0C);
			ss->*((word16) sp_862 - 2) = ss->*((word32) bp_1029 - 0x0E);
			ss->*((word16) sp_862 - 4) = ss->*((word32) bp_1029 - 16);
			word16 dx_1217;
			fn1EDA_0254(ds_812, ss->*((word16) sp_862 - 8), ss->*((word16) sp_862 - 6), ss->*((word16) sp_862 - 4), ss->*((word16) sp_862 - 2), out dx_1217, out ds);
		}
	}
	byte al_1033 = (byte) (ss->*((word32) bp_1029 - 1));
	bpOut = (ss->*bp_1029.u3).t0000.u2;
	dsOut = ds;
	return al_1033;
}
