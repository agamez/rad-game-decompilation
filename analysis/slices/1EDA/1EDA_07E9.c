// 1EDA:07E9: Sequence segptr32 fn1EDA_07E9(Sequence Eq_17 es_di, Register ui16 cx, Register (memptr (ptr16 Eq_63780) Eq_63357) bx, Register out Eq_17 axOut, Register out ui16 cxOut, Register out word16 siOut, Register out word16 diOut, Register out (ptr16 Eq_63600) dsOut)
// Called from:
//      fn1EDA_079A
segptr32 fn1EDA_07E9(Eq_17 es_di, ui16 cx, <unknown> Eq_63780::* bx, union Eq_17 & axOut, ui16 & cxOut, word16 & siOut, word16 & diOut, struct Eq_63600 & dsOut)
{
	es_di.u3->ptr0008 = bx;
	es_di.u3->t0014.u3();
	Eq_17 ax_32;
	if (ax_32 == 0x00)
	{
		Eq_63368 es_di_47;
		es_di_47.u1 = es_di.u3->t000C.u1;
		<unknown> Eq_63780::* bx_45 = es_di.u3->ptr0008;
		axOut.u2 = es_di.u3->t000A.u2;
		cxOut = cx;
		word16 si;
		siOut = si;
		diOut = (word16) es_di_47;
		struct Eq_63600 * ds;
		dsOut = ds;
		return bx_45;
	}
	else
	{
		ui16 cx_56;
		word16 dx_96;
		<unknown> Eq_63793::* bx_55;
		word16 si_61;
		word16 di_57;
		struct Eq_63793 * es_60;
		struct Eq_63600 * ds_58;
		axOut = fn1EDA_0801(ax_32, 8212, es_di, out cx_56, out dx_96, out bx_55, out si_61, out di_57, out es_60, out ds_58);
		cxOut = cx_56;
		siOut = si_61;
		diOut = di_57;
		dsOut = ds_58;
		return bx_55;
	}
}
