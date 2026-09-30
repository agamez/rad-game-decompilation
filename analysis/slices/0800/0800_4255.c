// 0800:4255: void fn0800_4255(Register (ptr16 Eq_18201) es)
void fn0800_4255(struct Eq_18201 * es)
{
	struct Eq_18482 * es_277;
	<unknown> Eq_18482::* si_278;
	Eq_17 ax_220;
	word16 ax_141;
	Eq_17 ds_102;
	Eq_17 bp_98;
	Eq_17 ds_12 = fn1EDA_0000(es);
	fn1E78_0000(ds_12);
	fn1AB8_17AE(ds_12);
	fn13C8_0139(fn13E2_0220(ds_12));
	<unknown>* es_si_736 = fn1206_0217(fn133F_0816(fn13C1_0067()), out bp_98, out ds_102);
	fn11C8_03CF(ds_102);
	fn0C74_552F(ds_102);
	fn0C43_02FB(ds_102);
	Eq_481 sp_106;
	sp_106.u0 = <invalid>;
	Eq_17 ss;
	ss->*((word16) sp_106 - 2) = bp_98;
	Eq_17 cs;
	ss->*((word16) sp_106 - 516) = cs;
	ss->*((word16) sp_106 - 518) = 0x41C7;
	ss->*((word16) sp_106 - 520) = ss;
	ss->*((word16) sp_106 - 522) = sp_106 - 0x0102;
	ss->*((word16) sp_106 - 524) = 0x01;
	fn1EDA_1216(es_si_736, ds_102, ss->*((word16) sp_106 - 524), ss->*((word16) sp_106 - 522));
	<unknown>* es_si_737 = fn1EDA_0AD8(ss->*((word16) sp_106 - 522), ss->*((word16) sp_106 - 518), out ax_141);
	if (ax_141 == 0x00)
	{
		ss->*((word16) sp_106 - 516) = cs;
		ss->*((word16) sp_106 - 518) = 16841;
		ss->*((word16) sp_106 - 520) = ss;
		ss->*((word16) sp_106 - 522) = sp_106 - 0x0202;
		ss->*((word16) sp_106 - 524) = 0x01;
		fn1EDA_1216(es_si_737, ds_102, ss->*((word16) sp_106 - 524), ss->*((word16) sp_106 - 522));
		word16 ax_185;
		fn1EDA_0AD8(ss->*((word16) sp_106 - 522), ss->*((word16) sp_106 - 518), out ax_185);
		if (ax_185 == 0x00)
		{
l0800_42CB:
			Mem218[ds_102:22758:word16] = 0x07;
			Mem219[ds_102:21471:byte] = 0x00;
			<unknown>* es_si_741 = fn1EDA_1265(ds_102, out ax_220);
			ss->*((word16) sp_106 - 4) = ax_220;
			if (ss->*((word16) sp_106 - 4) >= 0x01)
			{
				Mem238[ds_102:21462:word16] = 0x01;
				<unknown>* es_si_738 = es_si_741;
				while (true)
				{
					ss->*((word16) sp_106 - 516) = ss;
					ss->*((word16) sp_106 - 518) = sp_106 - 0x0104;
					Mem250[ss:sp_106 + -520:word16] = Mem246[ds_102:21462:word16];
					fn1EDA_1216(es_si_738, ds_102, ss->*((word16) sp_106 - 520), ss->*((word16) sp_106 - 518));
					ss->*((word16) sp_106 - 520) = ds_102;
					ss->*((word16) sp_106 - 522) = 0x53D4;
					word16 ax_272 = fn1EDA_0F71(ss->*((word16) sp_106 - 522), ss->*((word16) sp_106 - 518), out si_278, out es_277);
					Mem286[ds_102:21471:byte] = SLICE(ax_272, byte, 0);
					byte ah_291 = SLICE(ax_272, byte, 8);
					if (Mem286[ds_102:0x53D4:word16] == 0x00)
					{
						Mem293[ss:sp_106 + -516:word16] = SEQ(ah_291, Mem286[ds_102:21471:byte]);
						ss->*((word16) sp_106 - 518) = cs;
						ss->*((word16) sp_106 - 520) = 0x41CB;
						if (!fn1EDA_0CD4(ss->*((word16) sp_106 - 520), ss->*((word16) sp_106 - 516), out es_277))
							Mem316[ds_102:22758:word16] = CONVERT(Mem299[ds_102:21471:byte], uint8, uint16) *s 0x07;
					}
					if (Mem318[ds_102:21462:word16] == Mem318[ss:sp_106 + -4:word16])
						break;
					Mem325[ds_102:21462:word16] = Mem318[ds_102:21462:word16] + 0x01;
					es_si_738 = (<unknown>*) si_278;
				}
			}
			ss->*((word16) sp_106 - 516) = cs;
			ss->*((word16) sp_106 - 518) = 0x41EB;
			Eq_481 sp_350;
			sp_350.u0 = <invalid>;
			Eq_17 ds_346;
			int16 dx_360;
			fn1E78_030D(fn0C43_00B9(ds_102, ss->*((word16) sp_106 - 518), out ds_346), ds_346, ss->*((word16) sp_350 + 2), out dx_360);
			while (fn1E78_02FB(ds_346) != 0x00)
				fn1E78_030D(dx_360, ds_346, ss->*((word16) sp_350 + 2), out dx_360);
			Eq_17 ds_384;
			if (fn13E2_0001(ds_346, out ds_384) == 0x00)
			{
				ss->*((word16) sp_350 + 2) = cs;
				ss->*sp_350 = 16883;
				ds_384 = fn13E2_0193(ds_384, ss->*sp_350);
			}
			fn1EDA_0E07(ds_384);
			Mem423[ds_384:22718:byte] = 0x00;
			fn13E2_003B(ds_384);
			ss->*((word16) sp_350 + 2) = 0x00;
			ss->*sp_350 = ds_384;
			ss->*((word16) sp_350 - 2) = 0x550E;
			ss->*((word16) sp_350 - 4) = 0x4F;
			Mem463[ss:sp_350 + 0x02:word16] = SEQ(fn1EDA_129E(0x00, ss->*((word16) sp_350 - 4), ss->*((word16) sp_350 - 2), ss->*((word16) sp_350 + 2)), Mem444[ds_384:0x550F:byte]);
			ss->*sp_350 = cs;
			ss->*((word16) sp_350 - 2) = 16926;
			selector es_743;
			if (!fn1EDA_0CD4(ss->*((word16) sp_350 - 2), ss->*((word16) sp_350 + 2), out es_743))
			{
				ss->*((word16) sp_350 + 2) = 0x0F;
				ss->*sp_350 = 0x3F;
				ss->*((word16) sp_350 - 2) = 0x3F;
				ss->*((word16) sp_350 - 4) = 0x3F;
				fn1AB8_1CBA(ds_384, ss->*((word16) sp_350 - 4), ss->*((word16) sp_350 - 2), ss->*sp_350, ss->*((word16) sp_350 + 2));
				ss->*((word16) sp_350 + 2) = 0x0F;
				ss->*sp_350 = 0x0F;
				fn1AB8_1342(ds_384, ss->*sp_350, ss->*((word16) sp_350 + 2));
				ss->*((word16) sp_350 + 2) = 0x01;
				ss->*sp_350 = 0x00;
				ss->*((word16) sp_350 - 2) = 0x04;
				fn1AB8_1536(ds_384, ss->*((word16) sp_350 - 2), ss->*sp_350, ss->*((word16) sp_350 + 2), out ds_384);
				ss->*((word16) sp_350 + 2) = 0x01;
				ss->*sp_350 = 0x01;
				fn1AB8_14F4(ds_384, ss->*sp_350, ss->*((word16) sp_350 + 2));
				ss->*((word16) sp_350 + 2) = (int32) fn1AB8_10CE(ds_384) /16 0x02;
				ss->*sp_350 = 442;
				ss->*((word16) sp_350 - 2) = cs;
				ss->*((word16) sp_350 - 4) = 0x423E;
				byte ch_746;
				fn1AB8_1D82(ds_384, ss->*((word16) sp_350 - 4), ss->*sp_350, ss->*((word16) sp_350 + 2), out ch_746);
			}
			Mem581[ds_384:22754:word16] = 0x00;
			ss->*((word16) sp_350 + 2) = 0x01;
			ss->*sp_350 = 0x0F;
			fn1AB8_1175(ds_384, ss->*sp_350, ss->*((word16) sp_350 + 2));
			Mem595[ds_384:0x58B0:byte] = 0x01;
			Mem596[ds_384:22926:word16] = 0x01;
			Mem597[ds_384:22928:word16] = 0x00;
			Eq_17 ds_631 = fn0800_4168(fn0800_03F8(fn0C74_03D4(ds_384)));
			ss->*((word16) sp_350 + 2) = 0x01;
			ss->*sp_350 = 22;
			ss->*sp_350 = fn0800_04CC(ss->*sp_350);
			struct Eq_13540 * ds_657;
			fn1206_00FF(ds_631, out ds_657);
			Eq_481 sp_661;
			sp_661.u0 = <invalid>;
			ss->*((word16) sp_661 + 2) = 0x01B0;
			ss->*sp_661 = 0x01D1;
			struct Eq_13558 * ds_676;
			fn1206_012D(ds_657, out ds_676);
			Eq_481 sp_680;
			sp_680.u0 = <invalid>;
			ss->*((word16) sp_680 + 2) = 100;
			ss->*sp_680 = 0x01C2;
			word16 si_744;
			selector es_745;
			Eq_17 ds_695;
			fn1206_00D1(ds_676, out si_744, out es_745, out ds_695);
			while (true)
				ds_695 = fn0800_3D9D(ds_695);
		}
	}
	fn11C8_0394(ds_102);
	goto l0800_42CB;
}
