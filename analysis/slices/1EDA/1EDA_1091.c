// 1EDA:1091: Register Eq_17 fn1EDA_1091(Register Eq_17 ax, Register Eq_17 dx, Register Eq_17 ds, Stack Eq_17 ptrArg08)
// Called from:
//      fn1EDA_1085
//      fn1EDA_108C
Eq_17 fn1EDA_1091(Eq_17 ax, Eq_17 dx, Eq_17 ds, Eq_17 ptrArg08)
{
	fn1EDA_1076(ptrArg08, ds);
	Eq_65240 Z_15;
	Z_15.u1 = <invalid>;
	Eq_65240 C_14;
	C_14.u1 = <invalid>;
	if (Z_15)
		return ax;
	Eq_17 cx_23;
	cx_23.u2 = ptrArg08.u3->t0004.u2;
	__syscall<byte>(33);
	if (!C_14)
	{
		if (ax == cx_23)
			return ax;
		ax = dx;
	}
	Mem35[ds:0x5380:word16] = ax;
	return ax;
}
