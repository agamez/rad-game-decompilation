// 1EDA:0F71: Register word16 fn1EDA_0F71(Stack Eq_17 ptrArg04, Stack Eq_17 ptrArg08, Register out word16 siOut, Register out (ptr16 Eq_18483) esOut)
// Called from:
//      fn0800_4255
//      fn1229_050A
word16 fn1EDA_0F71(Eq_17 ptrArg04, Eq_17 ptrArg08, word16 & siOut, struct Eq_18483 & esOut)
{
	word16 wArg08_75 = (word16) ptrArg08;
	struct Eq_64859 * es_10 = SLICE(ptrArg08, selector, 16);
	byte Eq_64859::* di_15 = (word16) ptrArg08 + 0x01;
	uint16 cx_17 = (uint16) ptrArg08.u3->t0000.u0;
	if (cx_17 != 0x00)
	{
		while (es_10->*di_15 == 0x20)
		{
			++di_15;
			--cx_17;
			if (cx_17 == 0x00)
				break;
		}
	}
	word16 ax_30;
	Eq_64453 cx_34;
	word16 si_33;
	word16 di_35;
	if (fn1EDA_0E8E(cx_17, di_15, es_10, out ax_30, out cx_34, out si_33, out di_35) || cx_34 != 0x00)
	{
		cx_34 = di_35 - wArg08_75;
		ax_30 = 0x00;
	}
	ptrArg04.u3->t0000.u2 = (uint16) cx_34;
	siOut = si_33;
	esOut = SLICE(ptrArg04, selector, 16);
	return ax_30;
}
