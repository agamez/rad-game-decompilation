// 0C74:4DAC: Register byte fn0C74_4DAC(Register Eq_17 ds, Register out word16 bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_542B
byte fn0C74_4DAC(Eq_17 ds, word16 & bpOut, union Eq_17 & dsOut)
{
	Eq_17 ds_230;
	mp16 fp;
	Eq_17 bp_104 = fp - 2;
	struct Eq_47643 Eq_17::* sp_147 = fp - 0x0E;
	selector ss;
	Eq_481 sp_112;
	cup16 ax_161;
	do
	{
		struct Eq_47707 Eq_17::* sp_29 = sp_147 - 2;
		Mem30[ss:sp_29 + 0x00:word16] = Mem14[ds:22708:word16] + Mem14[ss:bp_104 + -4:word16];
		Mem35[ss:sp_29 + -2:word16] = Mem30[ds:22712:word16] + 0x12;
		(ss->*sp_29).tFFFC.u2 = (uint16) 0x0A;
		fn1AB8_1E54(ds, (ss->*sp_29).tFFFC.u0, (ss->*sp_29).tFFFE.u2, (ss->*sp_29).t0000.u2);
		Mem56[ss:sp_29 + 0x00:word16] = Mem37[ds:22708:word16] + Mem37[ss:bp_104 + -4:word16];
		Mem61[ss:sp_29 + -2:word16] = Mem56[ds:22712:word16] + 0x13;
		(ss->*sp_29).tFFFC.u2 = (uint16) 0x02;
		fn1AB8_1E54(ds, (ss->*sp_29).tFFFC.u0, (ss->*sp_29).tFFFE.u2, (ss->*sp_29).t0000.u2);
		Mem82[ss:sp_29 + 0x00:word16] = Mem63[ds:22708:word16] + Mem63[ss:bp_104 + -4:word16];
		Mem87[ss:sp_29 + -2:word16] = Mem82[ds:22712:word16] + 0x14;
		(ss->*sp_29).tFFFC.u2 = (uint16) 0x08;
		fn1AB8_1E54(ds, (ss->*sp_29).tFFFC.u0, (ss->*sp_29).tFFFE.u2, (ss->*sp_29).t0000.u2);
		(ss->*((word32) bp_104 - 4)).u3 = ss->*((word32) bp_104 - 4) - 0x01;
		(ss->*sp_29).t0000.u2 = (uint16) 300;
		(ss->*sp_29).tFFFE.u2 = (uint16) 0x14;
		bp_104 = fn0C74_070D(ds, (ss->*sp_29).tFFFE.u2, (ss->*sp_29).t0000.u2, out ds);
		sp_112.u0 = <invalid>;
		if (ss->*((word32) bp_104 - 4) == ~0x16)
			break;
		Mem133[ss:sp_112 + 0x02:word16] = Mem101[ds:22708:word16] + Mem101[ss:bp_104 + -4:word16];
		Mem138[ss:sp_112 + 0x00:word16] = Mem133[ds:22712:word16] + 0x13;
		sp_147 = (word16) sp_112 + 4;
		byte dl_641;
		if (fn1AB8_1E3C(ds, ss->*sp_112, ss->*((word16) sp_112 + 2), out dl_641) != 0x00)
			break;
		Eq_47698 dx_ax_560 = CONVERT(Mem138[ds:22708:word16] + Mem138[ss:bp_104 + -4:word16], word16, uint32);
		ax_161 = (word16) dx_ax_560;
	} while (true && (false || ax_161 > 0x01));
	if (ss->*((word32) bp_104 - 4) != ~0x16)
	{
		ss->*((word16) sp_112 + 2) = 0x00;
		fn1AB8_1C32(ds, ss->*((word16) sp_112 + 2));
		struct Eq_48064 Eq_17::* sp_466 = (word16) sp_112 + 4;
		ci16 ax_467 = (ci16) (ss->*((word32) bp_104 - 4));
		if (ax_467 <= 0x0C)
		{
			(ss->*((word32) bp_104 - 6)).u3 = ax_467 + 0x01;
			while (true)
			{
				struct Eq_48085 Eq_17::* sp_489 = sp_466 - 2;
				Mem490[ss:sp_489 + 0x00:word16] = Mem474[ds:22708:word16] + Mem474[ss:bp_104 + -6:word16];
				Mem494[ss:sp_489 + -2:word16] = Mem490[ds:22712:word16] + 0x12;
				Mem508[ss:sp_489 + -4:word16] = Mem494[ds:22708:word16] + Mem494[ss:bp_104 + -6:word16];
				Mem513[ss:sp_489 + -6:word16] = Mem508[ds:22712:word16] + 0x14;
				word16 dx_643;
				fn1AB8_1AF6(ds, (ss->*sp_489).tFFFA.u2, (ss->*sp_489).tFFFC.u2, (ss->*sp_489).tFFFE.u2, (ss->*sp_489).t0000.u2, out dx_643);
				(ss->*sp_489).t0000.u2 = (uint16) 300;
				(ss->*sp_489).tFFFE.u2 = (uint16) 0x14;
				Eq_481 sp_534;
				sp_534.u0 = <invalid>;
				bp_104 = fn0C74_070D(ds, (ss->*sp_489).tFFFE.u2, (ss->*sp_489).t0000.u2, out ds);
				sp_466 = (word16) sp_534 + 4;
				if (ss->*((word32) bp_104 - 6) == 0x0D)
					break;
				(ss->*((word32) bp_104 - 6)).u3 = &(ss->*((word32) bp_104 - 6)).u3->t0001.u0;
			}
		}
		(ss->*((word32) bp_104 - 1)).u3 = 0x00;
	}
	else
	{
		ss->*((word16) sp_112 + 2) = 500;
		Eq_17 ds_185;
		bp_104 = fn0C74_02D8(ds, ss->*((word16) sp_112 + 2), out ds_185);
		Eq_481 sp_189;
		sp_189.u0 = <invalid>;
		Mem198[ss:sp_189 + 0x00:word16] = Mem177[ds_185:22708:word16] - 22;
		Mem202[ss:sp_189 + -2:word16] = Mem198[ds_185:22712:word16] + 0x11;
		Mem206[ss:sp_189 + -4:word16] = Mem202[ds_185:22708:word16] - 0x01;
		Mem211[ss:sp_189 + -6:word16] = Mem206[ds_185:22712:word16] + 0x14;
		ss->*((word32) bp_104 - 8) = fn1AB8_13A3(ds_185, ss->*((word16) sp_189 - 6), ss->*((word16) sp_189 - 4), ss->*((word16) sp_189 - 2), ss->*sp_189);
		ss->*sp_189 = ss->*((word32) bp_104 - 8);
		Eq_17 dx_ax_642 = fn1EDA_023F(ds_185, ss->*((word16) sp_189 - 4), ss->*((word16) sp_189 - 2), ss->*sp_189, out ds_230);
		ss->*((word32) bp_104 - 0x0C) = (word16) dx_ax_642;
		(ss->*((word32) bp_104 - 0x0A)).u3 = SLICE(dx_ax_642, word16, 16);
		Mem244[ss:sp_189 + 0x00:word16] = Mem240[ds_230:22708:word16] - 22;
		Mem248[ss:sp_189 + -2:word16] = Mem244[ds_230:22712:word16] + 0x11;
		Mem252[ss:sp_189 + -4:word16] = Mem248[ds_230:22708:word16] - 0x01;
		Mem257[ss:sp_189 + -6:word16] = Mem252[ds_230:22712:word16] + 0x14;
		Eq_17 es_di_258 = ss->*((word32) bp_104 - 0x0C);
		ss->*((word16) sp_189 - 8) = SLICE(es_di_258, selector, 16);
		ss->*((word16) sp_189 - 0x0A) = (word16) es_di_258;
		fn1AB8_1E6B(ds_230, ss->*((word16) sp_189 - 0x0A), ss->*((word16) sp_189 - 6), ss->*((word16) sp_189 - 4), ss->*((word16) sp_189 - 2), ss->*sp_189);
		(ss->*((word32) bp_104 - 4)).u3 = 0x12;
		struct Eq_48051 Eq_17::* sp_275 = (word16) sp_189 + 2;
		Eq_481 sp_353;
		while (true)
		{
			struct Eq_48201 Eq_17::* sp_282 = sp_275 - 2;
			Mem284[ss:sp_282 + 0x00:word16] = Mem278[ds_230:22708:word16] - 22;
			Mem300[ss:sp_282 + -2:word16] = Mem284[ds_230:22712:word16] + Mem284[ss:bp_104 + -4:word16];
			Eq_17 es_di_301 = ss->*((word32) bp_104 - 0x0C);
			(ss->*sp_282).tFFFC.u2 = (uint16) SLICE(es_di_301, selector, 16);
			(ss->*sp_282).tFFFA.u2 = (uint16) (word16) es_di_301;
			(ss->*sp_282).tFFF8.u2 = (uint16) 0x00;
			fn1AB8_13D7(ds_230, (ss->*sp_282).t0008.u0, (ss->*sp_282).tFFFA.u3, (ss->*sp_282).tFFFE.u2, (ss->*sp_282).t0000.u2);
			(ss->*sp_282).t0000.u2 = (uint16) 300;
			(ss->*sp_282).tFFFE.u2 = (uint16) 0x14;
			Eq_17 ds_332;
			fn0C74_070D(ds_230, (ss->*sp_282).tFFFE.u2, (ss->*sp_282).t0000.u2, out ds_332);
			Eq_481 sp_336;
			sp_336.u0 = <invalid>;
			ss->*((word16) sp_336 + 2) = 0x28;
			sp_353.u0 = <invalid>;
			bp_104 = fn0C74_02D8(ds_332, ss->*((word16) sp_336 + 2), out ds_230);
			sp_275 = (word16) sp_353 + 2;
			if (ss->*((word32) bp_104 - 4) == 0x2B)
				break;
			(ss->*((word32) bp_104 - 4)).u3 = &(ss->*((word32) bp_104 - 4)).u3->t0001.u0;
		}
		ss->*sp_353 = ss->*((word32) bp_104 - 0x0A);
		ss->*((word16) sp_353 - 2) = ss->*((word32) bp_104 - 0x0C);
		ss->*((word16) sp_353 - 4) = ss->*((word32) bp_104 - 8);
		word16 dx_644;
		fn1EDA_0254(ds_230, ss->*((word16) sp_353 - 8), ss->*((word16) sp_353 - 6), ss->*((word16) sp_353 - 4), ss->*((word16) sp_353 - 2), out dx_644, out ds);
		(ss->*((word32) bp_104 - 6)).u3 = ~0x15;
		struct Eq_48366 Eq_17::* sp_386 = (word16) sp_353 + 2;
		while (true)
		{
			struct Eq_48369 Eq_17::* sp_405 = sp_386 - 2;
			Mem406[ss:sp_405 + 0x00:word16] = Mem390[ds:22708:word16] + Mem390[ss:bp_104 + -6:word16];
			Mem410[ss:sp_405 + -2:word16] = Mem406[ds:22712:word16] + 0x12;
			Mem424[ss:sp_405 + -4:word16] = Mem410[ds:22708:word16] + Mem410[ss:bp_104 + -6:word16];
			Mem429[ss:sp_405 + -6:word16] = Mem424[ds:22712:word16] + 0x14;
			word16 dx_645;
			fn1AB8_1AF6(ds, (ss->*sp_405).tFFFA.u2, (ss->*sp_405).tFFFC.u2, (ss->*sp_405).tFFFE.u2, (ss->*sp_405).t0000.u2, out dx_645);
			(ss->*sp_405).t0000.u2 = (uint16) 300;
			(ss->*sp_405).tFFFE.u2 = (uint16) 0x14;
			Eq_481 sp_450;
			sp_450.u0 = <invalid>;
			bp_104 = fn0C74_070D(ds, (ss->*sp_405).tFFFE.u2, (ss->*sp_405).t0000.u2, out ds);
			sp_386 = (word16) sp_450 + 4;
			if (ss->*((word32) bp_104 - 6) == 0x0D)
				break;
			(ss->*((word32) bp_104 - 6)).u3 = &(ss->*((word32) bp_104 - 6)).u3->t0001.u0;
		}
	}
	byte al_551 = (byte) (ss->*((word32) bp_104 - 1));
	bpOut = (ss->*bp_104.u3).t0000.u2;
	dsOut = ds;
	return al_551;
}
