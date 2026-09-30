// 1EDA:1076: FlagGroup ui32 fn1EDA_1076(Sequence Eq_17 es_di, Register Eq_17 ds)
// Called from:
//      fn1EDA_1051
//      fn1EDA_1085
//      fn1EDA_10BB
//      fn1EDA_1123
ui32 fn1EDA_1076(Eq_17 es_di, Eq_17 ds)
{
	ui32 SCZO_7 = cond(es_di.u3->t0002.u2 - 55219);
	if (es_di.u3->t0002.u2 != 55219)
		Mem10[ds:0x5380:word16] = 0x67;
	return SCZO_7 & 0x02 | SCZO_7 & 0x04;
}
