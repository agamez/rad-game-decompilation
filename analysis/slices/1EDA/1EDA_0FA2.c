// 1EDA:0FA2: void fn1EDA_0FA2(Stack Eq_17 ptrArg04, Stack Eq_17 ptrArg08)
// Called from:
//      fn0800_0147
//      fn0800_01FE
//      fn0800_03F8
//      fn0800_11EF
//      fn0800_2401
//      fn0800_2827
//      fn0800_31B7
//      fn0800_4168
//      fn0C43_00B9
//      fn0C74_03D4
//      fn1229_039D
//      fn1229_0486
//      fn1229_0735
//      fn1AB8_0887
void fn1EDA_0FA2(Eq_17 ptrArg04, Eq_17 ptrArg08)
{
	ptrArg08.u3->t0000.u2 = (uint16) 0x00;
	ptrArg08.u3->t0002.u2 = (uint16) ~0x284F;
	struct Eq_65128 * es_13 = SLICE(ptrArg08, selector, 16);
	union Eq_65132 Eq_65128::* di_19 = (word16) ptrArg08 + 4;
	word16 cx_24;
	for (cx_24 = 22; cx_24 != 0x00; --cx_24)
	{
		(es_13->*di_19).u0 = 0x00;
		di_19 = (union Eq_65132 Eq_65128::*) ((char *) di_19 + 2);
	}
	Eq_17 al_29;
	al_29.u0 = ptrArg04.u3->t0000.u0;
	if (al_29 > 0x4F)
		al_29.u0 = 0x4F;
	Eq_65153 cx_37;
	cx_37.u1 = (uint16) al_29;
	memcpy(&&(es_13->*(es_13->*di_19).u0), &ptrArg04.u3->t0001.u0, (uint32) cx_37);
	es_13->*(di_19 + cx_37) = (word16) 0x00;
}
