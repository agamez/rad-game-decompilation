// 1EDA:079A: Sequence ptr32 fn1EDA_079A(Sequence segptr32 es_bx, Register ui16 cx, Register (memptr (ptr16 Eq_63780) Eq_63357) dx, Register word16 di, Stack Eq_17 ptrArg02, Register out byte alOut, Register out ui16 cxOut, Register out (memptr (ptr16 Eq_63780) Eq_63357) dxOut, Register out (memptr (ptr16 Eq_63780) Eq_63357) bxOut, Register out word16 diOut, Register out (ptr16 Eq_63604) esOut)
// Called from:
//      fn1EDA_081A
//      fn1EDA_0896
//      fn1EDA_0918
ptr32 fn1EDA_079A(segptr32 es_bx, ui16 cx, <unknown> Eq_63780::* dx, word16 di, Eq_17 ptrArg02, byte & alOut, ui16 & cxOut, <unknown>& dxOut, <unknown>& bxOut, word16 & diOut, struct Eq_63604 & esOut)
{
	struct Eq_63599 * ds_21;
	<unknown> Eq_63599::* si_22;
	<unknown> Eq_63780::* ax_15;
	ptr32 ds_si;
	<unknown> Eq_63780::* bx = (word16) es_bx;
	segptr32 es_bx_75 = es_bx;
	ptr32 ds_si_86 = ds_si;
	if (bx == dx)
	{
		segptr32 es_bx_79 = fn1EDA_07E9(ptrArg02, cx, bx, out ax_15, out cx, out si_22, out di, out ds_21);
		struct Eq_63604 * es_19 = SLICE(es_bx_79, selector, 16);
		<unknown> Eq_63780::* bx_16 = (word16) es_bx_79;
		dx = ax_15;
		es_bx_75 = es_bx_79;
		ds_si_86 = (ptr32) si_22;
		if (bx_16 == ax_15)
		{
			alOut = <invalid>;
			cxOut = cx;
			dxOut = ax_15;
			bxOut = bx_16;
			diOut = di;
			esOut = es_19;
			return si_22;
		}
	}
	alOut = <invalid>;
	cxOut = cx;
	dxOut = dx;
	bxOut = (word16) es_bx_75;
	diOut = di;
	esOut = SLICE(es_bx_75, selector, 16);
	return ds_si_86;
}
