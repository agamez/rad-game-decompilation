// 1EDA:081A: Register Eq_17 fn1EDA_081A(Register ui16 cx, Register Eq_17 ds, Stack Eq_17 ptrArg04)
// Called from:
//      fn0800_391E
Eq_17 fn1EDA_081A(ui16 cx, Eq_17 ds, Eq_17 ptrArg04)
{
	segptr32 es_bx_112;
	<unknown> Eq_63780::* bx_17 = (word16) es_bx_112;
	segptr32 es_bx_109 = es_bx_112;
	<unknown> Eq_63780::* dx_19;
	word16 di_18;
	if (!fn1EDA_0776(ptrArg04, ds, out es_bx_112, out dx_19, out di_18))
	{
		struct Eq_63780 * es_40;
		byte al_46;
		do
		{
			Eq_481 ax_34;
			ax_34.u0 = <invalid>;
			byte al_114;
			ds.u3 = SLICE(fn1EDA_079A(es_bx_109, cx, dx_19, di_18, ptrArg04, out al_114, out cx, out dx_19, out bx_17, out di_18, out es_40), selector, 16);
			al_46 = (byte) ax_34;
			if (al_46 == 0x1A)
				goto l1EDA_083B;
			es_bx_109 = &(es_40->*((char *) bx_17 + 1));
		} while (al_46 != 0x0D);
		Eq_481 ax_53;
		ax_53.u0 = <invalid>;
		byte al_116;
		word16 cx_117;
		word16 dx_118;
		word16 di_119;
		selector es_120;
		ds.u3 = SLICE(fn1EDA_079A(&(es_40->*((char *) bx_17 + 1)), cx, dx_19, di_18, ptrArg04, out al_116, out cx_117, out dx_118, out bx_17, out di_119, out es_120), selector, 16);
		if ((byte) ax_53 == 0x0A)
			bx_17 = (<unknown> Eq_63780::*) ((char *) bx_17 + 1);
	}
l1EDA_083B:
	ptrArg04.u3->ptr0008 = bx_17;
	fn1EDA_0879(ptrArg04, ds);
	return ds;
}
