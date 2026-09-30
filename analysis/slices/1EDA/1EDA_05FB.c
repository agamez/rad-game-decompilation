// 1EDA:05FB: FlagGroup bool fn1EDA_05FB(Sequence segptr32 es_bx, Register word16 di, Register Eq_17 ds)
// Called from:
//      fn1EDA_0565
//      fn1EDA_05BF
bool fn1EDA_05FB(segptr32 es_bx, word16 di, Eq_17 ds)
{
	Eq_17 ax_18;
	word16 bx = (word16) es_bx;
	(*((word32) es_bx + (uipr32) di))();
	ui32 SZ_22 = cond(ax_18);
	if (ax_18 != 0x00)
		Mem27[ds:0x5380:word16] = ax_18;
	return (SZ_22 & 0x04) != 0x00;
}
