// 1EDA:0896: Register ui16 fn1EDA_0896(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 ptrArg06, Stack Eq_17 ptrArg0A)
// Called from:
//      fn0800_0D20
//      fn0800_391E
ui16 fn1EDA_0896(Eq_17 ds, Eq_17 wArg04, Eq_17 ptrArg06, Eq_17 ptrArg0A)
{
	struct Eq_63780 * es_44;
	byte al_118;
	segptr32 es_bx_117;
	<unknown> Eq_63780::* bx_19 = (word16) es_bx_117;
	byte Eq_63959::* si_45 = (word16) ptrArg06;
	struct Eq_63959 * ds_42 = SLICE(ptrArg06, selector, 16);
	ui16 cx_28 = 0x00;
	segptr32 es_bx_113 = es_bx_117;
	<unknown> Eq_63780::* dx_21;
	word16 di_20;
	if (!fn1EDA_0776(ptrArg0A, ds, out es_bx_117, out dx_21, out di_20))
	{
		do
		{
			struct Eq_63854 * ds_si_116 = fn1EDA_079A(es_bx_113, cx_28, dx_21, di_20, ptrArg0A, out al_118, out cx_28, out dx_21, out bx_19, out di_20, out es_44);
			Eq_481 ax_38;
			ax_38.u0 = <invalid>;
			ds_42 = SLICE(ds_si_116, selector, 16);
			si_45 = (word16) ds_si_116;
			byte al_50 = (byte) ax_38;
			if (al_50 == 0x0D || al_50 == 0x1A)
				break;
			ds_si_116->b0001 = al_50;
			bx_19 = (<unknown> Eq_63780::*) ((char *) bx_19 + 1);
			++cx_28;
			++si_45;
			es_bx_113 = &(es_44->*((char *) bx_19 + 1));
		} while (cx_28 + 0x01 != wArg04);
	}
	ds_42->*(si_45 - cx_28) = (byte) cx_28;
	ptrArg0A.u3->ptr0008 = bx_19;
	return cx_28;
}
