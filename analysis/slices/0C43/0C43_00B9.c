// 0C43:00B9: Register word16 fn0C43_00B9(Register Eq_17 ds, Stack Eq_17 ptrArg04, Register out Eq_17 dsOut)
// Called from:
//      fn0800_4255
word16 fn0C43_00B9(Eq_17 ds, Eq_17 ptrArg04, union Eq_17 & dsOut)
{
	Eq_17 ds_602;
	Eq_17 bp_598;
	Eq_17 ds_470;
	byte ch_774;
	Eq_17 ds_217;
	byte ch_766;
	Eq_17 ds_172;
	byte ch_765;
	Eq_17 ds_126;
	Eq_17 ds_45;
	Eq_17 ss;
	<unknown> Eq_17::* fp;
	word16 dx_762;
	fn1EDA_0A39(0x4F, SEQ(ss, fp - 82), ptrArg04, out dx_762);
	Eq_17 bp_41 = fn0C43_0000(ds, 0x13, out ds_45);
	Eq_481 sp_49;
	sp_49.u0 = <invalid>;
	ss->*sp_49 = ss;
	ss->*((word16) sp_49 - 2) = bp_41 - 212;
	ss->*((word16) sp_49 - 4) = ss;
	ss->*((word16) sp_49 - 6) = bp_41 - 80;
	fn1EDA_0FA2(ss->*((word16) sp_49 - 6), ss->*((word16) sp_49 - 2));
	ss->*sp_49 = ss;
	ss->*((word16) sp_49 - 2) = bp_41 - 212;
	ss->*((word16) sp_49 - 4) = 0x01;
	word16 dx_621;
	fn1EDA_0FD0(ds_45, ss->*((word16) sp_49 - 4), ss->*((word16) sp_49 - 2), out dx_621);
	uint16 ax_95 = fn1EDA_04A2(ds_45);
	byte ah_106 = SLICE(ax_95, byte, 8);
	word16 ax_107 = SEQ(ah_106, 0x00);
	word16 ax_751 = SEQ(ah_106, 0x00);
	if (ax_95 != 0x00)
		ax_751 = SEQ(SLICE(ax_107 + 0x01, byte, 8), 0x01);
	Mem113[ds_45:0x556E:byte] = SLICE(ax_751, byte, 0);
	if (Mem113[ds_45:0x556E:byte] == 0x00)
	{
		ss->*sp_49 = ~0x0E;
		Eq_17 dx_ax_763 = fn1EDA_023F(ds_45, ss->*((word16) sp_49 - 4), ss->*((word16) sp_49 - 2), ss->*sp_49, out ds_126);
		Mem135[ds_126:22660:word16] = SLICE(dx_ax_763, word16, 0);
		Mem136[ds_126:22662:word16] = SLICE(dx_ax_763, word16, 16);
		ss->*sp_49 = ss;
		ss->*((word16) sp_49 - 2) = bp_41 - 212;
		ss->*((word16) sp_49 - 4) = ss;
		ss->*((word16) sp_49 - 6) = bp_41 - 0xE0;
		ss->*((word16) sp_49 - 8) = 0x02;
		ss->*((word16) sp_49 - 0x0A) = 0x00;
		ss->*((word16) sp_49 - 0x0C) = 0x00;
		fn1EDA_10BB(ds_126, ss->*((word16) sp_49 - 0x0C), ss->*((word16) sp_49 - 8), ss->*((word16) sp_49 - 2));
		byte ah_182 = SLICE(fn1EDA_04A9(ds_126, ss->*((word16) sp_49 + 0x0000FFFE), ss->*sp_49, out ch_765, out ds_172), byte, 8);
		word16 ax_183 = SEQ(ah_182, 0x00);
		word16 ax_754 = SEQ(ah_182, 0x00);
		if (ss->*((word32) bp_41 - 223) < 0x05)
			ax_754 = SEQ(SLICE(ax_183 + 0x01, byte, 8), 0x01);
		Mem189[ds_172:0x556E:byte] = SLICE(ax_754, byte, 0);
		if (Mem189[ds_172:0x556E:byte] != 0x00)
		{
			ss->*sp_49 = bp_41;
			dx_621 = fn0C43_0095(ax_754, ds_172, ss->*sp_49, out ds_45);
		}
		else
		{
			ss->*sp_49 = ss;
			ss->*((word16) sp_49 - 2) = bp_41 - 212;
			Eq_17 ds_207;
			fn1EDA_116A(ds_172, ss->*((word16) sp_49 - 2), out ds_207);
			ui32 dx_ax_757 = fn1EDA_04A9(ds_207, ss->*((word16) sp_49 + 0x0000FFFE), ss->*sp_49, out ch_766, out ds_217);
			ss->*((word32) bp_41 - 0x00D8) = (word16) dx_ax_757 - 0x0301;
			(ss->*((word32) bp_41 - 0x00D6)).u3 = SLICE(dx_ax_757 - 0x0301, word16, 16);
			ss->*sp_49 = ss;
			ss->*((word16) sp_49 - 2) = bp_41 - 212;
			ss->*((word16) sp_49 - 4) = 0x00;
			ss->*((word16) sp_49 - 6) = 0x80;
			fn1EDA_1123(ds_217, ss->*((word16) sp_49 - 6), ss->*((word16) sp_49 - 4), ss->*((word16) sp_49 - 2));
			byte ch_768;
			Eq_17 ds_254;
			fn1EDA_04A9(ds_217, ss->*((word16) sp_49 + 0x0000FFFE), ss->*sp_49, out ch_768, out ds_254);
			(ss->*((word32) bp_41 - 220)).u0 = 0x80;
			(ss->*((word32) bp_41 - 0x00DA)).u0 = 0x00;
			Mem263[ds_254:22674:byte] = 0x00;
			Mem268[ds_254:22682:word16] = 0x00;
			Eq_17 ax_392;
			Eq_17 dx_393;
			do
			{
				ss->*sp_49 = ss;
				ss->*((word16) sp_49 - 2) = bp_41 - 212;
				Eq_17 es_di_278 = Mem276[ds_254:22660:segptr32];
				ss->*((word16) sp_49 - 4) = SLICE(es_di_278, selector, 16);
				ss->*((word16) sp_49 - 6) = (word16) es_di_278;
				ss->*((word16) sp_49 - 8) = ~0x0E;
				ss->*((word16) sp_49 - 0x0A) = ds_254;
				ss->*((word16) sp_49 - 0x0C) = 22676;
				fn1EDA_10BB(ds_254, ss->*((word16) sp_49 - 0x0C), ss->*((word16) sp_49 - 8), ss->*((word16) sp_49 - 2));
				byte ch_776;
				Eq_17 ds_307;
				fn1EDA_04A9(ds_254, ss->*((word16) sp_49 + 0x0000FFFE), ss->*sp_49, out ch_776, out ds_307);
				Mem321[ss:bp_41 + -220:ui32] = Mem317[ss:bp_41 + -220:ui32] + CONVERT(Mem291[ds_307:22676:word16], word16, uint32);
				Eq_17 ax_322 = ss->*((word32) bp_41 - 220);
				Eq_17 dx_323 = ss->*((word32) bp_41 - 0x00DA);
				if (dx_323 > ss->*((word32) bp_41 - 0x00D6) || dx_323 >= ss->*((word32) bp_41 - 0x00D6) && ax_322 > ss->*((word32) bp_41 - 0x00D8))
					Mem340[ds_307:22676:word16] = Mem321[ds_307:22676:word16] - (Mem321[ss:bp_41 + 220:word16] - Mem321[ss:bp_41 + 0x00D8:word16]);
				fn0C43_0056(ds_307);
				ss->*sp_49 = ss;
				ss->*((word16) sp_49 - 2) = bp_41 - 212;
				fn1EDA_1185(ds_307, ss->*((word16) sp_49 - 2));
				byte ch_770;
				if ((byte) fn1EDA_04A9(ds_307, ss->*((word16) sp_49 - 2), ss->*sp_49, out ch_770, out ds_254) != 0x00)
					break;
				ax_392 = ss->*((word32) bp_41 - 220);
				dx_393 = ss->*((word32) bp_41 - 0x00DA);
			} while (dx_393 <= ss->*((word32) bp_41 - 0x00D6) && (dx_393 < ss->*((word32) bp_41 - 0x00D6) || ax_392 < ss->*((word32) bp_41 - 0x00D8)));
			ss->*sp_49 = ss;
			ss->*((word16) sp_49 - 2) = bp_41 - 212;
			ss->*((word16) sp_49 - 4) = ss->*((word32) bp_41 - 0x00D6);
			ss->*((word16) sp_49 - 6) = ss->*((word32) bp_41 - 0x00D8);
			fn1EDA_1123(ds_254, ss->*((word16) sp_49 - 6), ss->*((word16) sp_49 - 4), ss->*((word16) sp_49 - 2));
			byte ch_772;
			Eq_17 ds_429;
			fn1EDA_04A9(ds_254, ss->*((word16) sp_49 - 2), ss->*sp_49, out ch_772, out ds_429);
			ss->*sp_49 = ss;
			ss->*((word16) sp_49 - 2) = bp_41 - 212;
			ss->*((word16) sp_49 - 4) = ss;
			ss->*((word16) sp_49 - 6) = bp_41 - 0xDD;
			ss->*((word16) sp_49 - 8) = 0x01;
			ss->*((word16) sp_49 - 0x0A) = 0x00;
			ss->*((word16) sp_49 - 0x0C) = 0x00;
			fn1EDA_10BB(ds_429, ss->*((word16) sp_49 - 0x0C), ss->*((word16) sp_49 - 8), ss->*((word16) sp_49 - 2));
			byte ah_480 = SLICE(fn1EDA_04A9(ds_429, ss->*((word16) sp_49 - 2), ss->*sp_49, out ch_774, out ds_470), byte, 8);
			word16 ax_481 = SEQ(ah_480, 0x00);
			word16 ax_758 = SEQ(ah_480, 0x00);
			if (ss->*((word32) bp_41 - 0x00DD) != 0x0C)
				ax_758 = SEQ(SLICE(ax_481 + 0x01, byte, 8), 0x01);
			Mem487[ds_470:0x556E:byte] = SLICE(ax_758, byte, 0);
			if (Mem487[ds_470:0x556E:byte] != 0x00)
			{
				ss->*sp_49 = bp_41;
				dx_621 = fn0C43_0095(ax_758, ds_470, ss->*sp_49, out ds_45);
			}
			else
			{
				ss->*sp_49 = ss;
				ss->*((word16) sp_49 - 2) = bp_41 - 212;
				ss->*((word16) sp_49 - 4) = ds_470;
				ss->*((word16) sp_49 - 6) = 0x5582;
				ss->*((word16) sp_49 - 8) = 0x0300;
				ss->*((word16) sp_49 - 0x0A) = 0x00;
				ss->*((word16) sp_49 - 0x0C) = 0x00;
				fn1EDA_10BB(ds_470, ss->*((word16) sp_49 - 0x0C), ss->*((word16) sp_49 - 8), ss->*((word16) sp_49 - 2));
				byte ch_778;
				Eq_17 ds_528;
				fn1EDA_04A9(ds_470, ss->*((word16) sp_49 - 2), ss->*sp_49, out ch_778, out ds_528);
				(ss->*((word32) bp_41 - 81)).u1 = 0x00;
				while (true)
				{
					(ss->*((word32) bp_41 - 228)).u3 = (uint16) (ss->*((word32) bp_41 - 81)) * 0x03 + 0x5582;
					ss->*((word32) bp_41 - 226) = ds_528;
					(ss->*((word32) bp_41 - 228)).u3->t0000.u0 = (int8) (byte) ((uint16) (ss->*((word32) bp_41 - 228)).u3->t0000.u0 >> 0x02);
					(ss->*((word32) bp_41 - 228)).u3->t0001.u0 = (byte) ((uint16) (ss->*((word32) bp_41 - 228)).u3->t0001.u0 >> 0x02);
					(ss->*((word32) bp_41 - 228)).u3->t0002.u0 = (int8) (byte) ((uint16) (ss->*((word32) bp_41 - 228)).u3->t0002.u0 >> 0x02);
					if (ss->*((word32) bp_41 - 81) == ~0x00)
						break;
					(ss->*((word32) bp_41 - 81)).u3 = &(ss->*((word32) bp_41 - 81)).u3->t0001.u0;
				}
				ss->*sp_49 = ds_528;
				ss->*((word16) sp_49 - 2) = 0x5582;
				word16 ax_597 = fn0C43_001E(ds_528, ss->*((word16) sp_49 - 2), out bp_598, out ds_602);
				Eq_481 sp_606;
				sp_606.u0 = <invalid>;
				ss->*((word16) sp_606 + 2) = bp_598;
				dx_621 = fn0C43_0095(ax_597, ds_602, ss->*((word16) sp_606 + 2), out ds_45);
			}
		}
	}
	dsOut = ds_45;
	return dx_621;
}
