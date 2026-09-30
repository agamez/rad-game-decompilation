// 1206:0217: Sequence segptr32 fn1206_0217(Register Eq_17 ds, Register out word16 bpOut, Register out (ptr16 Eq_18237) dsOut)
// Called from:
//      fn0800_4255
segptr32 fn1206_0217(Eq_17 ds, word16 & bpOut, struct Eq_18237 & dsOut)
{
	selector ss;
	<unknown> Eq_51503::* si_30;
	struct Eq_51503 * es_29;
	struct Eq_18237 * ds_27;
	bpOut = ss->*fn1206_01AC(ds, out si_30, out es_29, out ds_27);
	dsOut = ds_27;
	return si_30;
}
