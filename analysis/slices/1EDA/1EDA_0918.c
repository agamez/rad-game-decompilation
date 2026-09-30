// 1EDA:0918: Register Eq_17 fn1EDA_0918(Register byte ch, Register Eq_17 ds, Stack Eq_17 ptrArg04)
// Called from:
//      fn0800_391E
Eq_17 fn1EDA_0918(byte ch, Eq_17 ds, Eq_17 ptrArg04)
{
	segptr32 es_bx_185;
	<unknown> Eq_63780::* bx_18 = (word16) es_bx_185;
	ui16 cx_30 = SEQ(ch, 0x00);
	segptr32 es_bx_180 = es_bx_185;
	<unknown> Eq_63780::* dx_20;
	word16 di_19;
	if (!fn1EDA_0776(ptrArg04, ds, out es_bx_185, out dx_20, out di_19))
	{
		while (true)
		{
			Eq_481 ax_35;
			ax_35.u0 = <invalid>;
			byte al_189;
			ui16 cx_37;
			struct Eq_63780 * es_41;
			ds.u3 = SLICE(fn1EDA_079A(es_bx_180, cx_30, dx_20, di_19, ptrArg04, out al_189, out cx_37, out dx_20, out bx_18, out di_19, out es_41), selector, 16);
			cu8 al_47 = (byte) ax_35;
			byte cl_50 = (byte) cx_37;
			if (al_47 == 0x1A || (cl_50 & 0x01) != 0x00 && al_47 == 0x0D)
				break;
			cx_30 = cx_37;
			if ((cl_50 & 0x02) == 0x00 || al_47 > 0x20)
				goto l1EDA_0943;
			es_bx_180 = &(es_41->*((char *) bx_18 + 1));
		}
	}
	else
	{
l1EDA_0943:
	}
	ptrArg04.u3->ptr0008 = bx_18;
	return ds;
}
