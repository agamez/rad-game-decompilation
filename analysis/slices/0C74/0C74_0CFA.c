// 0C74:0CFA: Register word16 fn0C74_0CFA(Register Eq_17 ds, Stack Eq_17 bArg02, Register out (memptr Eq_17 Eq_21071) bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_1B3B
//      fn0C74_2AD9
//      fn0C74_3615
word16 fn0C74_0CFA(Eq_17 ds, Eq_17 bArg02, struct Eq_21071 & bpOut, union Eq_17 & dsOut)
{
	mp16 fp;
	Mem11[ds:22888:word16] = 0x01;
	Eq_17 bp_25 = fp - 2;
	struct Eq_22194 Eq_17::* sp_16 = fp - 4;
	selector ss;
	word16 dx;
	if (bArg02 >= 0x01)
	{
		while (true)
		{
			struct Eq_22206 Eq_17::* sp_17 = sp_16 - 2;
			(ss->*sp_17).t0000.u2 = (uint16) 100;
			(ss->*sp_17).tFFFE.u2 = (uint16) 0x14;
			bp_25 = fn0C74_070D(ds, (ss->*sp_17).tFFFE.u2, (ss->*sp_17).t0000.u2, out ds);
			Eq_481 sp_33;
			sp_33.u0 = <invalid>;
			Mem41[ss:sp_33 + 0x02:word16] = Mem21[ds:22708:word16];
			Mem44[ss:sp_33 + 0x00:word16] = Mem41[ds:22712:word16];
			segptr32 es_di_51 = (*((word32) ds + 22788))[(uint16) (ss->*((word32) bp_25 - 1))];
			ss->*((word16) sp_33 - 2) = SLICE(es_di_51, selector, 16);
			ss->*((word16) sp_33 - 4) = (word16) es_di_51;
			ss->*((word16) sp_33 - 6) = 0x00;
			dx = fn1AB8_13D7(ds, ss->*((word16) sp_33 + 6), ss->*((word16) sp_33 - 4), ss->*sp_33, ss->*((word16) sp_33 + 2));
			sp_16 = (word16) sp_33 + 4;
			if (ss->*((word32) bp_25 - 1) == 0x01)
				break;
			(ss->*((word32) bp_25 - 1)).u3 = ss->*((word32) bp_25 - 1) - 0x01;
		}
	}
	bpOut = (struct Eq_21071 Eq_17::*) (ss->*bp_25.u3).t0000.u2;
	dsOut = ds;
	return dx;
}
