// 0C74:37C3: Register uint8 fn0C74_37C3(Register Eq_17 ds, Register out word16 dxOut, Register out Eq_526 bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_542B
//      fn0C74_54F0
uint8 fn0C74_37C3(Eq_17 ds, word16 & dxOut, union Eq_526 & bpOut, union Eq_17 & dsOut)
{
	mp16 fp;
	word16 dx;
	byte dh_501 = SLICE(dx, byte, 8);
	Eq_17 bp_111 = fp - 2;
	selector ss;
	if (Mem10[ds:22708:word16] >u 0x01)
	{
		Mem14[ds:22705:byte] = 0x00;
		if (Mem14[ds:22888:word16] == 0x01)
		{
			dx = fn0C74_0D43(ds, 0x15, out bp_111, out ds);
			(ss->*((word32) bp_111 - 1)).u1 = 0x01;
			goto l0C74_3969;
		}
		byte dl_27;
		dx = SEQ(dh_501, dl_27);
		if (fn1AB8_1E3C(ds, Mem21[ds:22714:word16], Mem14[ds:22708:word16] - 0x01, out dl_27) == 0x00)
		{
			byte dl_50;
			dx = SEQ(dh_501, dl_50);
			if (fn1AB8_1E3C(ds, Mem42[ds:22714:word16] - 0x15, Mem24[ds:22708:word16] - 0x01, out dl_50) == 0x00)
			{
				byte dl_73;
				dx = SEQ(dh_501, dl_73);
				if (fn1AB8_1E3C(ds, Mem65[ds:22714:word16] - 0x29, Mem47[ds:22708:word16] - 0x01, out dl_73) == 0x00)
				{
					struct Eq_39366 Eq_17::* sp_102 = fp - 0x06;
					byte dl_96;
					dx = SEQ(dh_501, dl_96);
					if (fn1AB8_1E3C(ds, Mem88[ds:22714:word16] + 0x01, Mem70[ds:22708:word16] - 0x01, out dl_96) != 0x00)
					{
l0C74_3847:
						(ss->*((word32) bp_111 - 3)).u3 = 0x01;
						while (true)
						{
							union Eq_17 Eq_17::* sp_119 = sp_102 - 2;
							Mem121[ss:sp_119 + 0x00:word16] = Mem114[ds:22758:word16] << 0x01;
							bp_111 = fn0C74_02D8(ds, (ss->*sp_119).u2, out ds);
							(ss->*((word32) bp_111 - 2)).u3 = ss->*((word32) bp_111 - 2) - 0x01;
							Eq_481 sp_132;
							sp_132.u0 = <invalid>;
							if (ss->*((word32) bp_111 - 2) == 0x00)
							{
								(ss->*((word32) bp_111 - 2)).u1 = 0x04;
								if (Mem148[ds:0x58B0:byte] != 0x00)
								{
									ss->*sp_132 = 0x32;
									audio_write_opl3_register(ds, ss->*sp_132);
								}
							}
							else
								audio_get_soundcard_port(ds);
							union Eq_17 Eq_17::* sp_195 = (word16) sp_132 + 2;
							if (Mem164[ds:22708:word16] >u 0x01)
							{
								Mem169[ds:22708:word16] = Mem164[ds:22708:word16] - 0x01;
								Mem171[ds:22710:word16] = Mem169[ds:22710:word16] - 0x01;
							}
							if (Mem174[ds:22706:byte] != 0x00)
							{
								if (fn1E78_02FB(ds) != 0x00)
									Mem192[ds:22705:byte] = 0x01;
								ss->*sp_132 = 0x00;
								Eq_481 sp_213;
								sp_213.u0 = <invalid>;
								sp_195 = (word16) sp_213 + 2;
								byte ch_554;
								word16 dx_555;
								if ((byte) fn1206_015B(ds, out ch_554, out dx_555, out bp_111, out ds) != 0x00)
								{
									Mem225[ds:22752:byte] = 0x01;
									Mem226[ds:22705:byte] = 0x01;
								}
							}
							else if (Mem174[ds:22716:byte] == Mem174[ds:22717:byte])
								Mem180[ds:22705:byte] = 0x01;
							if (Mem229[ds:22708:word16] <=u 0x01)
								Mem233[ds:22705:byte] = 0x01;
							struct Eq_39523 Eq_17::* sp_240 = sp_195 - 2;
							Mem244[ss:sp_240 + 0x00:word16] = Mem235[ds:22708:word16];
							Mem247[ss:sp_240 + -2:word16] = Mem244[ds:22714:word16];
							byte dl_556;
							if (fn1AB8_1E3C(ds, (ss->*sp_240).tFFFE.u2, (ss->*sp_240).t0000.u2, out dl_556) != 0x00)
								break;
							Mem264[ss:sp_240 + 0x00:word16] = Mem247[ds:22708:word16];
							Mem269[ss:sp_240 + -2:word16] = Mem264[ds:22714:word16] - 0x15;
							byte dl_557;
							if (fn1AB8_1E3C(ds, (ss->*sp_240).tFFFE.u2, (ss->*sp_240).t0000.u2, out dl_557) != 0x00)
								break;
							Mem286[ss:sp_240 + 0x00:word16] = Mem269[ds:22708:word16];
							Mem291[ss:sp_240 + -2:word16] = Mem286[ds:22714:word16] - 0x29;
							byte dl_558;
							if (fn1AB8_1E3C(ds, (ss->*sp_240).tFFFE.u2, (ss->*sp_240).t0000.u2, out dl_558) != 0x00)
								break;
							Mem308[ss:sp_240 + 0x00:word16] = Mem291[ds:22708:word16];
							Mem313[ss:sp_240 + -2:word16] = Mem308[ds:22714:word16] + 0x01;
							byte dl_559;
							if (fn1AB8_1E3C(ds, (ss->*sp_240).tFFFE.u2, (ss->*sp_240).t0000.u2, out dl_559) == 0x00)
								break;
							Mem330[ss:sp_240 + 0x00:word16] = Mem313[ds:22708:word16];
							Mem333[ss:sp_240 + -2:word16] = Mem330[ds:22712:word16];
							segptr32 es_di_346 = (*((word32) ds + 22772))[(uint16) (ss->*((word32) bp_111 - 2))];
							(ss->*sp_240).ptrFFFC = SLICE(es_di_346, selector, 16);
							(ss->*sp_240).tFFFA.u2 = (uint16) (word16) es_di_346;
							(ss->*sp_240).wFFF8 = 0x00;
							dx = fn1AB8_13D7(ds, (ss->*sp_240).t0008.u0, (ss->*sp_240).tFFFA.u3, (ss->*sp_240).tFFFE.u2, (ss->*sp_240).t0000.u2);
							sp_102 = (struct Eq_39366 Eq_17::*) ((char *) &sp_240->t0000 + 2);
							if (ss->*((word32) bp_111 - 3) == 22)
							{
								if (Mem354[ds:22705:byte] == 0x00)
									Mem372[ds:22716:byte] = Mem354[ds:22716:byte] + 0x01;
								if (Mem375[ds:22705:byte] == 0x00)
									goto l0C74_3847;
								goto l0C74_3969;
							}
							(ss->*((word32) bp_111 - 3)).u3 = &(ss->*((word32) bp_111 - 3)).u3->t0001.u0;
						}
						Mem384[ds:22708:word16] = Mem382[ds:22708:word16] + 0x01;
						Mem386[ds:22710:word16] = Mem384[ds:22710:word16] + 0x01;
						dx = audio_get_soundcard_port(ds);
						goto l0C74_3969;
					}
				}
			}
		}
		goto l0C74_3969;
	}
	else
	{
l0C74_3969:
		uint8 al_423 = (uint8) (ss->*((word32) bp_111 - 1));
		Eq_526 bp_425 = (ss->*bp_111.u3).t0000.u2;
		dxOut = dx;
		bpOut = bp_425;
		dsOut = ds;
		return al_423;
	}
}
