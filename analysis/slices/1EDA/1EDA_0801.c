// 1EDA:0801: Register Eq_17 fn1EDA_0801(Register Eq_17 ax, Register Eq_17 ds, Stack Eq_17 dwArg00, Register out word16 cxOut, Register out Eq_17 dxOut, Register out (memptr (ptr16 Eq_63780) Eq_63357) bxOut, Register out word16 siOut, Register out word16 diOut, Register out (ptr16 Eq_63728) esOut, Register out (ptr16 Eq_63731) dsOut)
// Called from:
//      fn1EDA_07DA
//      fn1EDA_07E9
Eq_17 fn1EDA_0801(Eq_17 ax, Eq_17 ds, Eq_17 dwArg00, word16 & cxOut, union Eq_17 & dxOut, <unknown>& bxOut, word16 & siOut, word16 & diOut, struct Eq_63728 & esOut, struct Eq_63731 & dsOut)
{
	Mem6[ds:0x5380:word16] = ax;
	Eq_63368 es_di_15;
	es_di_15.u1 = dwArg00.u3->t000C.u1;
	Eq_17 ax_12;
	ax_12.u2 = dwArg00.u3->t000A.u2;
	<unknown> Eq_63780::* bx_13 = dwArg00.u3->ptr0008;
	Eq_17 dx_14;
	dx_14.u2 = dwArg00.u3->t0004.u2;
	word16 wArg08;
	cxOut = wArg08;
	dxOut = dx_14;
	bxOut = bx_13;
	word16 wArg06;
	siOut = wArg06;
	diOut = (word16) es_di_15;
	esOut = SLICE(es_di_15, selector, 16);
	struct Eq_63731 * psegArg04;
	dsOut = psegArg04;
	return ax_12;
}
