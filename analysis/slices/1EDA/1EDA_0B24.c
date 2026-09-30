// 1EDA:0B24: FlagGroup bool fn1EDA_0B24(Stack Eq_17 ptrArg04, Stack Eq_17 ptrArg08, Register out Eq_481 axOut, Register out (ptr16 Eq_993) dxOut)
// Called from:
//      fn0800_0619
//      fn0800_11EF
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_3D9D
//      fn1229_039D
//      fn1229_061B
//      fn1229_0DCC
//      fn1AB8_05D3
//      fn1AB8_06CA
bool fn1EDA_0B24(Eq_17 ptrArg04, Eq_17 ptrArg08, union Eq_481 & axOut, struct Eq_993 & dxOut)
{
	Eq_17 al_14;
	al_14.u0 = ptrArg08.u3->t0000.u0;
	Eq_17 ah_18;
	ah_18.u0 = ptrArg04.u3->t0000.u0;
	Eq_17 cl_20 = al_14;
	if (al_14 > ah_18)
		cl_20 = ah_18;
	ui32 Z_42;
	if (cl_20 != 0x00)
	{
		Eq_64572 cmpResult_36 = memcmp(&ptrArg08.u3->t0001.u0, &ptrArg04.u3->t0001.u0, (uint32) cl_20);
		Z_42 = cond(cmpResult_36) & 0x04;
		if (cmpResult_36 != 0x00)
		{
l1EDA_0B4A:
			axOut.u0 = <invalid>;
			struct Eq_993 * ds;
			dxOut = ds;
			return Z_42 != 0x00;
		}
	}
	Z_42 = cond(al_14 - ah_18) & 0x04;
	goto l1EDA_0B4A;
}
