// 1EDA:07B6: FlagGroup bool fn1EDA_07B6(Sequence Eq_17 es_di, Register Eq_17 ds, Sequence out segptr32 es_bxOut, Register out Eq_17 dxOut, Register out Eq_63368 diOut)
// Called from:
//      fn1EDA_0848
//      fn1EDA_08CE
bool fn1EDA_07B6(Eq_17 es_di, Eq_17 ds, segptr32 & es_bxOut, union Eq_17 & dxOut, union Eq_63368 & diOut)
{
	ui32 Z_11 = cond(Mem0[ds:0x5380:word16] - 0x00) & 0x04;
	if (Mem0[ds:0x5380:word16] == 0x00)
	{
		Z_11 = cond(es_di.u3->t0002.u2 - 55218) & 0x04;
		if (es_di.u3->t0002.u2 != 55218)
			Mem12[ds:0x5380:word16] = 0x69;
	}
	Eq_17 dx_17;
	dx_17.u2 = es_di.u3->t0004.u2;
	Eq_63368 di_22;
	di_22.u0 = es_di.u3->t000C.u0;
	es_bxOut = <invalid>;
	dxOut = dx_17;
	diOut = di_22;
	return Z_11 != 0x00;
}
