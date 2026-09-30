// 1EDA:08CE: Register byte fn1EDA_08CE(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 ptrArg06, Stack Eq_17 ptrArg0A, Register out Eq_481 cxOut)
// Called from:
//      fn0800_2C0C
//      fn0C74_03D4
//      fn11C8_0092
//      fn133F_0056
//      fn13E2_0193
//      fn1AB8_008B
byte fn1EDA_08CE(Eq_17 ds, Eq_17 wArg04, Eq_17 ptrArg06, Eq_17 ptrArg0A, union Eq_481 & cxOut)
{
	segptr32 es_bx_197;
	word16 bx_111 = (word16) es_bx_197;
	word16 dx_125;
	word16 di_124;
	Eq_481 ax;
	Eq_481 cx;
	if (!fn1EDA_07B6(ptrArg0A, ds, out es_bx_197, out dx_125, out di_124))
	{
		ax.u1 = (uint16) ptrArg06.u3->t0000.u0;
		Eq_481 cx_36 = wArg04 - ax;
		segptr32 es_bx_188 = es_bx_197;
		struct Eq_63916 * ds_si_199 = (struct Eq_63916 *) &(SLICE(ptrArg06, selector, 16)->*((char *) ((word16) ptrArg06) + 1));
		if (cx_36 > 0x00)
		{
			struct Eq_63916 * ds_si_205;
			word16 cx_53;
			do
			{
				byte ah_207;
				ds_si_205 = fn1EDA_07DA(es_bx_188, 0x20, cx_36, dx_125, di_124, ptrArg0A, out es_bx_197, out ah_207, out cx_53, out dx_125, out di_124);
				cx_36 = cx_53 - 0x01;
				es_bx_188 = es_bx_197;
			} while (cx_53 != 0x01);
			ax.u1 = (uint16) ds_si_205->bFFFF;
			ds_si_199 = ds_si_205;
		}
		bx_111 = (word16) es_bx_197;
		cx = ax;
		struct Eq_63916 * ds_si_191 = ds_si_199;
		segptr32 es_bx_194 = es_bx_197;
		if (ax != 0x00)
		{
			word16 cx_90;
			do
			{
				ax.u0 = <invalid>;
				segptr32 es_bx_204;
				bx_111 = (word16) es_bx_204;
				cx = cx_90 - 0x01;
				byte ah_208;
				ds_si_191 = fn1EDA_07DA(es_bx_194, ds_si_191->b0000, cx, dx_125, di_124, ptrArg0A, out es_bx_204, out ah_208, out cx_90, out dx_125, out di_124);
				es_bx_194 = es_bx_204;
			} while (cx_90 != 0x01);
		}
	}
	ptrArg0A.u3->ptr0008 = bx_111;
	cxOut = cx;
	return SLICE(ax, byte, 8);
}
