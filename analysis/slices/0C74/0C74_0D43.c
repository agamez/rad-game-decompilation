// 0C74:0D43: Register word16 fn0C74_0D43(Register Eq_17 ds, Stack Eq_17 bArg02, Register out (memptr Eq_17 Eq_21071) bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_1B3B
//      fn0C74_2AD9
//      fn0C74_37C3
word16 fn0C74_0D43(Eq_17 ds, Eq_17 bArg02, struct Eq_21071 & bpOut, union Eq_17 & dsOut)
{
	mp16 fp;
	Mem11[ds:22888:word16] = ~0x00;
	Eq_17 bp_27 = fp - 2;
	struct Eq_22319 Eq_17::* sp_18 = fp - 4;
	selector ss;
	word16 dx;
	if (bArg02 >= 0x01)
	{
		while (true)
		{
			struct Eq_22331 Eq_17::* sp_19 = sp_18 - 2;
			(ss->*sp_19).t0000.u2 = (uint16) 100;
			(ss->*sp_19).tFFFE.u2 = (uint16) 0x14;
			bp_27 = fn0C74_070D(ds, (ss->*sp_19).tFFFE.u2, (ss->*sp_19).t0000.u2, out ds);
			Eq_481 sp_35;
			sp_35.u0 = <invalid>;
			Mem43[ss:sp_35 + 0x02:word16] = Mem23[ds:22708:word16];
			Mem46[ss:sp_35 + 0x00:word16] = Mem43[ds:22712:word16];
			segptr32 es_di_53 = (*((word32) ds + 22788))[(uint16) (ss->*((word32) bp_27 - 1))];
			ss->*((word16) sp_35 - 2) = SLICE(es_di_53, selector, 16);
			ss->*((word16) sp_35 - 4) = (word16) es_di_53;
			ss->*((word16) sp_35 - 6) = 0x00;
			dx = fn1AB8_13D7(ds, ss->*((word16) sp_35 + 6), ss->*((word16) sp_35 - 4), ss->*sp_35, ss->*((word16) sp_35 + 2));
			sp_18 = (word16) sp_35 + 4;
			if (ss->*((word32) bp_27 - 1) == ss->*((word32) bp_27 - 2))
				break;
			(ss->*((word32) bp_27 - 1)).u3 = &(ss->*((word32) bp_27 - 1)).u3->t0001.u0;
		}
	}
	bpOut = (struct Eq_21071 Eq_17::*) (ss->*bp_27.u3).t0000.u2;
	dsOut = ds;
	return dx;
}
