// 1EDA:05BF: Sequence Eq_17 fn1EDA_05BF(Register Eq_17 ds, Stack Eq_17 ptrArg04)
// Called from:
//      fn0800_0D20
//      fn0800_2C0C
//      fn0800_391E
//      fn1EDA_00E9
//      fn1EDA_0565
Eq_17 fn1EDA_05BF(Eq_17 ds, Eq_17 ptrArg04)
{
	struct Eq_63479 * es_11 = SLICE(ptrArg04, selector, 16);
	word16 di_12 = (word16) ptrArg04;
	if (ptrArg04.u3->t0002.u2 != 55217)
	{
		if (ptrArg04.u3->t0002.u2 != 55218)
		{
			Mem51[ds:0x5380:word16] = 0x67;
			return ptrArg04;
		}
		fn1EDA_05FB((char *) es_11 + 20, di_12, ds);
	}
	if (true)
	{
		fn1EDA_05FB((char *) es_11 + 28, di_12, ds);
		ptrArg04.u3->t0002.u2 = (uint16) ~0x284F;
	}
	return ptrArg04;
}
