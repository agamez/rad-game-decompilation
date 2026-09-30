// 1EDA:0848: Register Eq_17 fn1EDA_0848(Register byte ah, Register Eq_481 cx, Register Eq_17 ds, Stack Eq_17 ptrArg04)
// Called from:
//      fn0800_2C0C
//      fn0C74_03D4
//      fn133F_0056
//      fn13E2_0193
//      fn1AB8_008B
Eq_17 fn1EDA_0848(byte ah, Eq_481 cx, Eq_17 ds, Eq_17 ptrArg04)
{
	segptr32 es_bx_93;
	word16 bx_17 = (word16) es_bx_93;
	word16 dx_19;
	word16 di_18;
	if (!fn1EDA_07B6(ptrArg04, ds, out es_bx_93, out dx_19, out di_18))
	{
		segptr32 es_bx_94;
		byte ah_96;
		Eq_481 cx_32;
		word16 dx_35;
		word16 di_33;
		fn1EDA_07DA(es_bx_93, 0x0D, cx, dx_19, di_18, ptrArg04, out es_bx_94, out ah_96, out cx_32, out dx_35, out di_33);
		segptr32 es_bx_98;
		bx_17 = (word16) es_bx_98;
		byte ah_99;
		word16 cx_100;
		word16 dx_101;
		word16 di_102;
		ds.u3 = SLICE(fn1EDA_07DA(es_bx_94, 0x0A, cx_32, dx_35, di_33, ptrArg04, out es_bx_98, out ah_99, out cx_100, out dx_101, out di_102), selector, 16);
	}
	ptrArg04.u3->ptr0008 = bx_17;
	fn1EDA_0879(ptrArg04, ds);
	return ds;
}
