// 1EDA:126C: Sequence segptr32 fn1EDA_126C(Register Eq_17 dx, Register Eq_17 ds, Register out Eq_65567 axOut, Register out word16 bxOut)
// Called from:
//      fn1EDA_1216
//      fn1EDA_1265
segptr32 fn1EDA_126C(Eq_17 dx, Eq_17 ds, union Eq_65567 & axOut, word16 & bxOut)
{
	struct Eq_62643 * es_6 = Mem0[ds:21372:selector];
	Eq_65647 di_10;
	di_10.u0 = 0x81;
	word16 bx_11 = 0x00;
	uint16 cx_15 = (uint16) es_6->b0080;
	Eq_65567 ax_42;
	do
	{
		if (cx_15 != 0x00)
		{
			while (es_6->*di_10 <= 0x20)
			{
				di_10 = (word16) di_10 + 1;
				--cx_15;
				if (cx_15 == 0x00)
					break;
			}
		}
		if (cx_15 != 0x00)
		{
			while (es_6->*di_10 > 0x20)
			{
				di_10 = (word16) di_10 + 1;
				--cx_15;
				if (cx_15 == 0x00)
					break;
			}
		}
		ax_42 = di_10 - di_10;
		if (ax_42 == 0x00)
			break;
		++bx_11;
		--dx;
	} while (dx != 0x00);
	axOut = ax_42;
	bxOut = bx_11;
	return di_10;
}
