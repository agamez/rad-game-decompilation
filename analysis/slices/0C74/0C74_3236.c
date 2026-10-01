// 0C74:3236: Register byte fn0C74_3236(Register Eq_17 ds, Register out word16 bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_522C
byte fn0C74_3236(Eq_17 ds, word16 & bpOut, union Eq_17 & dsOut)
{
	Eq_17 ds_240;
	mp16 fp;
	Eq_17 bp_1030 = fp - 2;
	selector ss;
	if (Mem10[ds:22708:word16] <u 0x027E)
	{
		byte dl_1206;
		byte dl_1207;
		byte dl_1208;
		byte dl_1209;
		byte dl_1210;
		if (fn1AB8_1E3C(ds, Mem18[ds:22714:word16], Mem10[ds:22710:word16] + 0x01, out dl_1206) != 0x00 && (fn1AB8_1E3C(ds, Mem39[ds:22712:word16] + 22, Mem21[ds:22710:word16] + 0x01, out dl_1207) != 0x00 && (fn1AB8_1E3C(ds, Mem63[ds:22714:word16], Mem44[ds:22710:word16] + 0x17, out dl_1208) == 0x00 && (fn1AB8_1E3C(ds, Mem85[ds:22712:word16], Mem66[ds:22710:word16] + 0x01, out dl_1209) == 0x00 && fn1AB8_1E3C(ds, Mem106[ds:22712:word16] + 22, Mem88[ds:22710:word16] + 0x17, out dl_1210) == 0x00))))
		{
			Eq_17 ax_130 = Mem129[ds:22712:word16];
			Eq_17 ax_134 = Mem133[ds:22710:word16];
			Eq_17 ds_161;
			fn1AB8_1E6B(ds_161, fn1EDA_023F(ds, (word32) ax_134 + 22, (word32) ax_130 + 21, fn1AB8_13A3(ds, Mem138[ds:22714:word16], ax_134 + 22, ax_130 + 0x15, Mem126[ds:22710:word16]), out ds_161), Mem183[ds_161:22714:word16], Mem178[ds_161:22710:word16] + 22, Mem174[ds_161:22712:word16] + 22, Mem171[ds_161:22710:word16]);
			Eq_17 ax_209 = Mem208[ds_161:22712:word16];
			Eq_17 ax_213 = Mem212[ds_161:22708:word16];
			Eq_17 ax_222 = fn1AB8_13A3(ds_161, Mem216[ds_161:22712:word16] + 0x1B, ax_213 + 0x1D, ax_209 + 0x0D, Mem193[ds_161:22708:word16] + 0x19);
			Eq_17 dx_ax_1202 = fn1EDA_023F(ds_161, (word32) ax_213 + 29, (word32) ax_209 + 0x0D, ax_222, out ds_240);
			fn1AB8_1E6B(ds_240, dx_ax_1202, Mem262[ds_240:22712:word16] + 0x1B, Mem258[ds_240:22708:word16] + 0x1D, Mem254[ds_240:22712:word16] + 0x0D, Mem250[ds_240:22708:word16] + 0x19);
			fn1AB8_13D7(ds_240, 0x00, dx_ax_1202, Mem293[ds_240:22712:word16] + 0x0D, Mem274[ds_240:22708:word16] + 0x1A);
			fn1AB8_10F4(ds_240, 0x01, 0x00, 0x00);
			fn1AB8_1C32(ds_240, 0x00);
			Eq_17 ax_354 = Mem353[ds_240:22712:word16];
			word16 dx_1211;
			fn1AB8_1AF6(ds_240, (word32) ax_354 + 27, Mem349[ds_240:22708:word16] + 0x19, Mem345[ds_240:22712:word16] + 0x0D, Mem337[ds_240:22708:word16] + 0x19, out dx_1211);
			fn1AB8_1E54(ds_240, 11, Mem368[ds_240:22712:word16] + 0x12, Mem358[ds_240:22708:word16] + 0x19);
			fn1AB8_1E54(ds_240, 0x03, Mem384[ds_240:22712:word16] + 0x13, Mem375[ds_240:22708:word16] + 0x19);
			fn1AB8_1E54(ds_240, 0x09, Mem400[ds_240:22712:word16] + 0x14, Mem391[ds_240:22708:word16] + 0x19);
			word16 dx_1212;
			Eq_17 ds_426;
			fn1EDA_0254(ds_240, 0x00, (word32) ax_354 + 27, ax_222, dx_ax_1202, out dx_1212, out ds_426);
			Eq_17 ax_440 = Mem439[ds_426:22712:word16];
			Eq_17 ax_444 = Mem443[ds_426:22708:word16];
			Eq_17 ds_471;
			fn1AB8_1E6B(ds_471, fn1EDA_023F(ds_426, (word32) ax_444 + 30, (word32) ax_440 + 0x0D, fn1AB8_13A3(ds_426, Mem447[ds_426:22712:word16] + 0x1B, ax_444 + 0x1E, ax_440 + 0x0D, Mem421[ds_426:22708:word16] + 0x19), out ds_471), Mem493[ds_471:22712:word16] + 0x1B, Mem489[ds_471:22708:word16] + 0x1E, Mem485[ds_471:22712:word16] + 0x0D, Mem481[ds_471:22708:word16] + 0x19);
			struct Eq_37933 Eq_17::* sp_1024 = fp - 0x1E;
			while (ss->*((word32) bp_1030 - 2) < 0x14)
			{
				struct Eq_37983 Eq_17::* sp_532 = sp_1024 - 2;
				Mem533[ss:sp_532 + 0x00:word16] = Mem520[ds_471:22708:word16] + 0x1E + CONVERT(Mem520[ss:bp_1030 + -2:byte], uint8, uint16);
				Mem538[ss:sp_532 + -2:word16] = Mem533[ds_471:22712:word16] + 0x1B;
				byte dl_1213;
				if (fn1AB8_1E3C(ds_471, (ss->*sp_532).tFFFE.u2, (ss->*sp_532).t0000.u2, out dl_1213) != 0x00)
					break;
				(ss->*sp_532).t0000.u2 = (uint16) 0xE6;
				(ss->*sp_532).tFFFE.u2 = (uint16) 0x0A;
				bp_1030 = fn0C74_070D(ds_471, (ss->*sp_532).tFFFE.u2, (ss->*sp_532).t0000.u2, out ds_471);
				Eq_481 sp_984;
				sp_984.u0 = <invalid>;
				Mem998[ss:sp_984 + 0x02:word16] = Mem973[ds_471:22708:word16] + 0x19 + CONVERT(Mem973[ss:bp_1030 + -2:byte], uint8, uint16);
				Mem1003[ss:sp_984 + 0x00:word16] = Mem998[ds_471:22712:word16] + 0x0D;
				Eq_17 es_di_1004 = ss->*((word32) bp_1030 - 28);
				ss->*((word16) sp_984 - 2) = SLICE(es_di_1004, selector, 16);
				ss->*((word16) sp_984 - 4) = (word16) es_di_1004;
				ss->*((word16) sp_984 - 6) = 0x00;
				fn1AB8_13D7(ds_471, ss->*((word16) sp_984 + 6), ss->*((word16) sp_984 - 4), ss->*sp_984, ss->*((word16) sp_984 + 2));
				(ss->*((word32) bp_1030 - 2)).u3 = &(ss->*((word32) bp_1030 - 2)).u3->t0001.u0;
				sp_1024 = (word16) sp_984 + 4;
			}
			(ss->*((word32) bp_1030 - 6)).u2 = (uint16) (ss->*((word32) bp_1030 - 2));
			Mem562[ss:bp_1030 + -18:word16] = Mem559[ds_471:22710:word16];
			Mem565[ss:bp_1030 + -20:word16] = Mem562[ds_471:22710:word16] + 22;
			Mem569[ss:bp_1030 + -22:word16] = Mem565[ds_471:22712:word16] + 0x15;
			Mem571[ss:bp_1030 + -24:word16] = Mem569[ds_471:22714:word16];
			(ss->*((word32) bp_1030 - 3)).u1 = 0x01;
			struct Eq_37933 Eq_17::* sp_1038 = sp_1024;
			Eq_481 sp_655;
			while (true)
			{
				(ss->*((word32) bp_1030 - 18)).u3 = &(ss->*((word32) bp_1030 - 18)).u3->t0001.u0;
				(ss->*((word32) bp_1030 - 20)).u3 = &(ss->*((word32) bp_1030 - 20)).u3->t0001.u0;
				struct Eq_38146 Eq_17::* sp_582 = sp_1038 - 2;
				(ss->*sp_582).t0000.u2 = (uint16) (ss->*((word32) bp_1030 - 18));
				(ss->*sp_582).tFFFE.u2 = (uint16) &(ss->*((word32) bp_1030 - 22)).u3->t0001.u0;
				Eq_17 es_di_589 = ss->*((word32) bp_1030 - 0x0C);
				(ss->*sp_582).ptrFFFC = SLICE(es_di_589, selector, 16);
				(ss->*sp_582).tFFFA.u2 = (uint16) (word16) es_di_589;
				(ss->*sp_582).wFFF8 = 0x00;
				fn1AB8_13D7(ds_471, (ss->*sp_582).t0008.u0, (ss->*sp_582).tFFFA.u3, (ss->*sp_582).tFFFE.u2, (ss->*sp_582).t0000.u2);
				(ss->*sp_582).t0000.u2 = (uint16) (ss->*((word32) bp_1030 - 18) - 0x05);
				Mem619[ss:sp_582 + -2:word16] = Mem614[ds_471:22712:word16] + 0x0D;
				Eq_17 es_di_620 = ss->*((word32) bp_1030 - 28);
				(ss->*sp_582).ptrFFFC = SLICE(es_di_620, selector, 16);
				(ss->*sp_582).tFFFA.u2 = (uint16) (word16) es_di_620;
				(ss->*sp_582).wFFF8 = 0x00;
				fn1AB8_13D7(ds_471, (ss->*sp_582).t0008.u0, (ss->*sp_582).tFFFA.u3, (ss->*sp_582).tFFFE.u2, (ss->*sp_582).t0000.u2);
				(ss->*sp_582).t0000.u2 = (uint16) 0xE6;
				(ss->*sp_582).tFFFE.u2 = (uint16) 0x14;
				sp_655.u0 = <invalid>;
				bp_1030 = fn0C74_070D(ds_471, (ss->*sp_582).tFFFE.u2, (ss->*sp_582).t0000.u2, out ds_471);
				sp_1038 = (word16) sp_655 + 4;
				if (ss->*((word32) bp_1030 - 3) == 22)
					break;
				(ss->*((word32) bp_1030 - 3)).u3 = &(ss->*((word32) bp_1030 - 3)).u3->t0001.u0;
			}
			ss->*((word16) sp_655 + 2) = &(ss->*((word32) bp_1030 - 18)).u3->t0001.u0;
			ss->*sp_655 = &(ss->*((word32) bp_1030 - 24)).u3->t0001.u0;
			byte dl_1214;
			if (fn1AB8_1E3C(ds_471, ss->*sp_655, ss->*((word16) sp_655 + 2), out dl_1214) == 0x00)
			{
				ss->*((word16) sp_655 + 2) = &(ss->*((word32) bp_1030 - 18)).u3->t0001.u0;
				ss->*sp_655 = ss->*((word32) bp_1030 - 22);
				ss->*((word16) sp_655 - 2) = ss->*((word32) bp_1030 - 20);
				ss->*((word16) sp_655 - 4) = ss->*((word32) bp_1030 - 24);
				ds_471 = fn0C74_2BBD(ds_471, ss->*((word16) sp_655 - 4), ss->*((word16) sp_655 - 2), ss->*sp_655, ss->*((word16) sp_655 + 2));
			}
			struct Eq_38336 Eq_17::* sp_728 = (word16) sp_655 + 4;
			uint8 al_722 = (ss->*bp_1030.u3).t0006.u0 + 0x15;
			if (true)
			{
				(ss->*((word32) bp_1030 - 3)).u1 = al_722;
				while (true)
				{
					struct Eq_38465 Eq_17::* sp_729 = sp_728 - 2;
					(ss->*sp_729).t0000.u2 = (uint16) 0xE6;
					(ss->*sp_729).tFFFE.u2 = (uint16) 0x05;
					bp_1030 = fn0C74_070D(ds_471, (ss->*sp_729).tFFFE.u2, (ss->*sp_729).t0000.u2, out ds_471);
					Eq_481 sp_745;
					sp_745.u0 = <invalid>;
					Mem759[ss:sp_745 + 0x02:word16] = Mem733[ds_471:22708:word16] + 0x19 + CONVERT(Mem733[ss:bp_1030 + -3:byte], uint8, uint16);
					Mem764[ss:sp_745 + 0x00:word16] = Mem759[ds_471:22712:word16] + 0x0D;
					Eq_17 es_di_765 = ss->*((word32) bp_1030 - 28);
					ss->*((word16) sp_745 - 2) = SLICE(es_di_765, selector, 16);
					ss->*((word16) sp_745 - 4) = (word16) es_di_765;
					ss->*((word16) sp_745 - 6) = 0x00;
					fn1AB8_13D7(ds_471, ss->*((word16) sp_745 + 6), ss->*((word16) sp_745 - 4), ss->*sp_745, ss->*((word16) sp_745 + 2));
					sp_728 = (word16) sp_745 + 4;
					if (ss->*((word32) bp_1030 - 3) == 0x00)
						break;
					(ss->*((word32) bp_1030 - 3)).u1 = ss->*((word32) bp_1030 - 3) - 0x01;
				}
			}
			struct Eq_38399 Eq_17::* sp_797 = sp_728 - 2;
			(ss->*sp_797).t0000.u2 = (uint16) (ss->*((word32) bp_1030 - 26));
			(ss->*sp_797).tFFFE.u2 = (uint16) (ss->*((word32) bp_1030 - 28));
			(ss->*sp_797).tFFFC.u2 = (uint16) (ss->*((word32) bp_1030 - 16));
			word16 dx_1215;
			Eq_17 ds_813;
			fn1EDA_0254(ds_471, (ss->*sp_797).tFFF8.u2, (ss->*sp_797).tFFFA.u2, (ss->*sp_797).tFFFC.u2, (ss->*sp_797).tFFFE.u3, out dx_1215, out ds_813);
			(ss->*((word32) bp_1030 - 2)).u1 = 0x01;
			(ss->*((word32) bp_1030 - 3)).u1 = 0x01;
			struct Eq_38458 Eq_17::* sp_822 = (struct Eq_38458 Eq_17::*) &sp_797->t0002.u0;
			Eq_481 sp_863;
			while (true)
			{
				struct Eq_38560 Eq_17::* sp_837 = sp_822 - 2;
				Mem839[ss:sp_837 + 0x00:word16] = CONVERT(Mem826[ds_813:22758:word16], int16, int32) /16 0x02;
				word16 dx_1216;
				fn1E78_029C(ds_813, (ss->*sp_837).t0000.u2, out dx_1216);
				(ss->*sp_837).t0000.u2 = (uint16) 0x0A;
				bp_1030 = fn0C74_02D8(ds_813, (ss->*sp_837).t0000.u2, out ds_813);
				(ss->*((word32) bp_1030 - 2)).u3 = &(ss->*((word32) bp_1030 - 2)).u3->t0001.u0;
				sp_863.u0 = <invalid>;
				if (ss->*((word32) bp_1030 - 2) == 0x05)
				{
					(ss->*((word32) bp_1030 - 2)).u1 = 0x01;
					if (Mem879[ds_813:0x58B0:byte] != 0x00)
					{
						ss->*sp_863 = 0x32;
						audio_write_opl3_register(ds_813, ss->*sp_863);
					}
				}
				else
					audio_get_soundcard_port(ds_813);
				Mem898[ds_813:22708:word16] = Mem895[ds_813:22708:word16] + 0x01;
				Mem900[ds_813:22710:word16] = Mem898[ds_813:22710:word16] + 0x01;
				Mem907[ss:sp_863 + 0x00:word16] = Mem900[ds_813:22708:word16];
				Mem910[ss:sp_863 + -2:word16] = Mem907[ds_813:22712:word16];
				segptr32 es_di_919 = ds_813.u3->t58E4.u3[(uint16) (ss->*((word32) bp_1030 - 2))];
				ss->*((word16) sp_863 - 4) = SLICE(es_di_919, selector, 16);
				ss->*((word16) sp_863 - 6) = (word16) es_di_919;
				ss->*((word16) sp_863 - 8) = 0x00;
				fn1AB8_13D7(ds_813, ss->*((word16) sp_863 + 8), ss->*((word16) sp_863 - 6), ss->*((word16) sp_863 - 2), ss->*sp_863);
				sp_822 = (word16) sp_863 + 2;
				if (ss->*((word32) bp_1030 - 3) == 22)
					break;
				(ss->*((word32) bp_1030 - 3)).u3 = &(ss->*((word32) bp_1030 - 3)).u3->t0001.u0;
			}
			ss->*sp_863 = ss->*((word32) bp_1030 - 0x0A);
			ss->*((word16) sp_863 - 2) = ss->*((word32) bp_1030 - 0x0C);
			ss->*((word16) sp_863 - 4) = ss->*((word32) bp_1030 - 0x0E);
			word16 dx_1217;
			fn1EDA_0254(ds_813, ss->*((word16) sp_863 - 8), ss->*((word16) sp_863 - 6), ss->*((word16) sp_863 - 4), ss->*((word16) sp_863 - 2), out dx_1217, out ds);
		}
	}
	byte al_1034 = (byte) (ss->*((word32) bp_1030 - 1));
	bpOut = (ss->*bp_1030.u3).t0000.u2;
	dsOut = ds;
	return al_1034;
}
