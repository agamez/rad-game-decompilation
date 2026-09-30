// 0C74:4FD7: Register byte fn0C74_4FD7(Register Eq_17 ds, Register out word16 bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_542B
byte fn0C74_4FD7(Eq_17 ds, word16 & bpOut, union Eq_17 & dsOut)
{
	Eq_17 ds_187;
	mp16 fp;
	Eq_17 bp_13 = fp - 2;
	struct Eq_48480 Eq_17::* sp_115 = fp - 0x0C;
	selector ss;
	Eq_481 sp_88;
	byte dl_540;
	do
	{
		struct Eq_48540 Eq_17::* sp_21 = sp_115 - 2;
		Mem22[ss:sp_21 + 0x00:word16] = CONVERT(Mem14[ss:bp_13 + -2:byte], uint8, uint16) + Mem14[ds:22708:word16];
		Mem27[ss:sp_21 + -2:word16] = Mem22[ds:22712:word16] + 0x12;
		(ss->*sp_21).tFFFC.u2 = (uint16) 0x0A;
		fn1AB8_1E54(ds, (ss->*sp_21).tFFFC.u0, (ss->*sp_21).tFFFE.u2, (ss->*sp_21).t0000.u2);
		Mem40[ss:sp_21 + 0x00:word16] = CONVERT(Mem29[ss:bp_13 + -2:byte], uint8, uint16) + Mem29[ds:22708:word16];
		Mem45[ss:sp_21 + -2:word16] = Mem40[ds:22712:word16] + 0x13;
		(ss->*sp_21).tFFFC.u2 = (uint16) 0x02;
		fn1AB8_1E54(ds, (ss->*sp_21).tFFFC.u0, (ss->*sp_21).tFFFE.u2, (ss->*sp_21).t0000.u2);
		Mem58[ss:sp_21 + 0x00:word16] = CONVERT(Mem47[ss:bp_13 + -2:byte], uint8, uint16) + Mem47[ds:22708:word16];
		Mem63[ss:sp_21 + -2:word16] = Mem58[ds:22712:word16] + 0x14;
		(ss->*sp_21).tFFFC.u2 = (uint16) 0x08;
		fn1AB8_1E54(ds, (ss->*sp_21).tFFFC.u0, (ss->*sp_21).tFFFE.u2, (ss->*sp_21).t0000.u2);
		(ss->*((word32) bp_13 - 2)).u3 = &(ss->*((word32) bp_13 - 2)).u3->t0001.u0;
		(ss->*sp_21).t0000.u2 = (uint16) 300;
		(ss->*sp_21).tFFFE.u2 = (uint16) 0x14;
		bp_13 = fn0C74_070D(ds, (ss->*sp_21).tFFFE.u2, (ss->*sp_21).t0000.u2, out ds);
		sp_88.u0 = <invalid>;
		if (ss->*((word32) bp_13 - 2) == 66)
			break;
		Mem101[ss:sp_88 + 0x02:word16] = CONVERT(Mem77[ss:bp_13 + -2:byte], uint8, uint16) + Mem77[ds:22708:word16];
		Mem106[ss:sp_88 + 0x00:word16] = Mem101[ds:22712:word16] + 0x13;
		sp_115 = (word16) sp_88 + 4;
	} while (fn1AB8_1E3C(ds, ss->*sp_88, ss->*((word16) sp_88 + 2), out dl_540) == 0x00 && CONVERT(Mem106[ss:bp_13 + -2:byte], uint8, uint16) + Mem106[ds:22708:word16] <u 0x027E);
	if (ss->*((word32) bp_13 - 2) != 66)
	{
		ss->*((word16) sp_88 + 2) = 0x00;
		fn1AB8_1C32(ds, ss->*((word16) sp_88 + 2));
		struct Eq_48900 Eq_17::* sp_399 = (word16) sp_88 + 4;
		uint8 al_400 = (uint8) (ss->*((word32) bp_13 - 2));
		if (al_400 >= 0x1E)
		{
			(ss->*((word32) bp_13 - 3)).u1 = al_400 - 0x01;
			while (true)
			{
				struct Eq_48921 Eq_17::* sp_417 = sp_399 - 2;
				Mem418[ss:sp_417 + 0x00:word16] = CONVERT(Mem410[ss:bp_13 + -3:byte], uint8, uint16) + Mem410[ds:22708:word16];
				Mem422[ss:sp_417 + -2:word16] = Mem418[ds:22712:word16] + 0x12;
				Mem428[ss:sp_417 + -4:word16] = CONVERT(Mem422[ss:bp_13 + -3:byte], uint8, uint16) + Mem422[ds:22708:word16];
				Mem433[ss:sp_417 + -6:word16] = Mem428[ds:22712:word16] + 0x14;
				word16 dx_542;
				fn1AB8_1AF6(ds, (ss->*sp_417).tFFFA.u2, (ss->*sp_417).tFFFC.u2, (ss->*sp_417).tFFFE.u2, (ss->*sp_417).t0000.u2, out dx_542);
				(ss->*sp_417).t0000.u2 = (uint16) 300;
				(ss->*sp_417).tFFFE.u2 = (uint16) 0x14;
				Eq_481 sp_454;
				sp_454.u0 = <invalid>;
				bp_13 = fn0C74_070D(ds, (ss->*sp_417).tFFFE.u2, (ss->*sp_417).t0000.u2, out ds);
				sp_399 = (word16) sp_454 + 4;
				if (ss->*((word32) bp_13 - 3) == 0x1D)
					break;
				(ss->*((word32) bp_13 - 3)).u1 = ss->*((word32) bp_13 - 3) - 0x01;
			}
		}
		(ss->*((word32) bp_13 - 1)).u3 = 0x00;
	}
	else
	{
		ss->*((word16) sp_88 + 2) = 500;
		Eq_17 ds_142;
		bp_13 = fn0C74_02D8(ds, ss->*((word16) sp_88 + 2), out ds_142);
		Eq_481 sp_146;
		sp_146.u0 = <invalid>;
		Mem155[ss:sp_146 + 0x00:word16] = Mem134[ds_142:22708:word16] + 44;
		Mem159[ss:sp_146 + -2:word16] = Mem155[ds_142:22712:word16] + 0x11;
		Mem163[ss:sp_146 + -4:word16] = Mem159[ds_142:22708:word16] + 0x41;
		Mem168[ss:sp_146 + -6:word16] = Mem163[ds_142:22712:word16] + 0x14;
		ss->*((word32) bp_13 - 6) = fn1AB8_13A3(ds_142, ss->*((word16) sp_146 - 6), ss->*((word16) sp_146 - 4), ss->*((word16) sp_146 - 2), ss->*sp_146);
		ss->*sp_146 = ss->*((word32) bp_13 - 6);
		Eq_17 dx_ax_541 = fn1EDA_023F(ds_142, ss->*((word16) sp_146 - 4), ss->*((word16) sp_146 - 2), ss->*sp_146, out ds_187);
		ss->*((word32) bp_13 - 0x0A) = (word16) dx_ax_541;
		(ss->*((word32) bp_13 - 8)).u3 = SLICE(dx_ax_541, word16, 16);
		Mem201[ss:sp_146 + 0x00:word16] = Mem197[ds_187:22708:word16] + 44;
		Mem205[ss:sp_146 + -2:word16] = Mem201[ds_187:22712:word16] + 0x11;
		Mem209[ss:sp_146 + -4:word16] = Mem205[ds_187:22708:word16] + 0x41;
		Mem214[ss:sp_146 + -6:word16] = Mem209[ds_187:22712:word16] + 0x14;
		Eq_17 es_di_215 = ss->*((word32) bp_13 - 0x0A);
		ss->*((word16) sp_146 - 8) = SLICE(es_di_215, selector, 16);
		ss->*((word16) sp_146 - 0x0A) = (word16) es_di_215;
		fn1AB8_1E6B(ds_187, ss->*((word16) sp_146 - 0x0A), ss->*((word16) sp_146 - 6), ss->*((word16) sp_146 - 4), ss->*((word16) sp_146 - 2), ss->*sp_146);
		(ss->*((word32) bp_13 - 2)).u1 = 0x12;
		struct Eq_48887 Eq_17::* sp_232 = (word16) sp_146 + 2;
		Eq_481 sp_302;
		while (true)
		{
			struct Eq_49039 Eq_17::* sp_239 = sp_232 - 2;
			Mem241[ss:sp_239 + 0x00:word16] = Mem235[ds_187:22708:word16] + 44;
			Mem249[ss:sp_239 + -2:word16] = CONVERT(Mem241[ss:bp_13 + -2:byte], uint8, uint16) + Mem241[ds_187:22712:word16];
			Eq_17 es_di_250 = ss->*((word32) bp_13 - 0x0A);
			(ss->*sp_239).tFFFC.u2 = (uint16) SLICE(es_di_250, selector, 16);
			(ss->*sp_239).tFFFA.u2 = (uint16) (word16) es_di_250;
			(ss->*sp_239).tFFF8.u2 = (uint16) 0x00;
			fn1AB8_13D7(ds_187, (ss->*sp_239).t0008.u0, (ss->*sp_239).tFFFA.u3, (ss->*sp_239).tFFFE.u2, (ss->*sp_239).t0000.u2);
			(ss->*sp_239).t0000.u2 = (uint16) 300;
			(ss->*sp_239).tFFFE.u2 = (uint16) 0x14;
			Eq_17 ds_281;
			fn0C74_070D(ds_187, (ss->*sp_239).tFFFE.u2, (ss->*sp_239).t0000.u2, out ds_281);
			Eq_481 sp_285;
			sp_285.u0 = <invalid>;
			ss->*((word16) sp_285 + 2) = 0x28;
			sp_302.u0 = <invalid>;
			bp_13 = fn0C74_02D8(ds_281, ss->*((word16) sp_285 + 2), out ds_187);
			sp_232 = (word16) sp_302 + 2;
			if (ss->*((word32) bp_13 - 2) == 0x2B)
				break;
			(ss->*((word32) bp_13 - 2)).u3 = &(ss->*((word32) bp_13 - 2)).u3->t0001.u0;
		}
		ss->*sp_302 = ss->*((word32) bp_13 - 8);
		ss->*((word16) sp_302 - 2) = ss->*((word32) bp_13 - 0x0A);
		ss->*((word16) sp_302 - 4) = ss->*((word32) bp_13 - 6);
		word16 dx_543;
		fn1EDA_0254(ds_187, ss->*((word16) sp_302 - 8), ss->*((word16) sp_302 - 6), ss->*((word16) sp_302 - 4), ss->*((word16) sp_302 - 2), out dx_543, out ds);
		(ss->*((word32) bp_13 - 3)).u1 = 44;
		struct Eq_49205 Eq_17::* sp_335 = (word16) sp_302 + 2;
		while (true)
		{
			struct Eq_49208 Eq_17::* sp_346 = sp_335 - 2;
			Mem347[ss:sp_346 + 0x00:word16] = CONVERT(Mem339[ss:bp_13 + -3:byte], uint8, uint16) + Mem339[ds:22708:word16];
			Mem351[ss:sp_346 + -2:word16] = Mem347[ds:22712:word16] + 0x12;
			Mem357[ss:sp_346 + -4:word16] = CONVERT(Mem351[ss:bp_13 + -3:byte], uint8, uint16) + Mem351[ds:22708:word16];
			Mem362[ss:sp_346 + -6:word16] = Mem357[ds:22712:word16] + 0x14;
			word16 dx_544;
			fn1AB8_1AF6(ds, (ss->*sp_346).tFFFA.u2, (ss->*sp_346).tFFFC.u2, (ss->*sp_346).tFFFE.u2, (ss->*sp_346).t0000.u2, out dx_544);
			(ss->*sp_346).t0000.u2 = (uint16) 300;
			(ss->*sp_346).tFFFE.u2 = (uint16) 0x14;
			Eq_481 sp_383;
			sp_383.u0 = <invalid>;
			bp_13 = fn0C74_070D(ds, (ss->*sp_346).tFFFE.u2, (ss->*sp_346).t0000.u2, out ds);
			sp_335 = (word16) sp_383 + 4;
			if (ss->*((word32) bp_13 - 3) == 0x1D)
				break;
			(ss->*((word32) bp_13 - 3)).u1 = ss->*((word32) bp_13 - 3) - 0x01;
		}
	}
	byte al_471 = (byte) (ss->*((word32) bp_13 - 1));
	bpOut = (ss->*bp_13.u3).t0000.u2;
	dsOut = ds;
	return al_471;
}
