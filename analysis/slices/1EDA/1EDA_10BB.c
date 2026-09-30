// 1EDA:10BB: Register Eq_17 fn1EDA_10BB(Register Eq_17 ds, Stack Eq_17 ptrArg04, Stack Eq_17 wArg08, Stack Eq_17 ptrArg0E)
// Called from:
//      fn0800_0147
//      fn0800_03F8
//      fn0C43_00B9
//      fn0C74_03D4
//      fn1AB8_097B
//      fn1AB8_1536
Eq_17 fn1EDA_10BB(Eq_17 ds, Eq_17 ptrArg04, Eq_17 wArg08, Eq_17 ptrArg0E)
{
	fn1EDA_1076(ptrArg0E, ds);
	Eq_65240 Z_17;
	Z_17.u1 = <invalid>;
	Eq_17 ax;
	if (!Z_17)
	{
		ax = wArg08;
		if (wArg08 == 0x00)
		{
l1EDA_10F5:
			if (ptrArg04 != 0x00)
				ptrArg04.u3->t0000.u2 = (uint16) ax;
			else if (ax != wArg08)
				Mem84[ds:0x5380:word16] = 100;
			return ax;
		}
		uint32 dx_ax_29 = ptrArg0E.u3->t0004.u2 *32 wArg08;
		__syscall<byte>(33);
		ax = SEQ(0x3F, (byte) dx_ax_29);
		if (dx_ax_29 >= 0x00)
		{
			ax = (uint32) ax /u ((ptrArg0E.u3)->t0004).u2;
			goto l1EDA_10F5;
		}
		Mem43[ds:0x5380:word16] = ax;
	}
	if (ptrArg04 != 0x00)
	{
		ptrArg04.u3->t0000.u2 = (uint16) 0x00;
		ax.u0 = 0x00;
	}
	return ax;
}
