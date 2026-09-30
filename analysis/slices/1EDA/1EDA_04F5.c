// 1EDA:04F5: void fn1EDA_04F5(Stack Eq_17 ptrArg04, Stack Eq_17 ptrArg08)
// Called from:
//      fn0800_0D20
//      fn0800_2C0C
//      fn0800_391E
//      fn1EDA_0000
void fn1EDA_04F5(Eq_17 ptrArg04, Eq_17 ptrArg08)
{
	ptrArg08.u3->t0000.u2 = (uint16) 0x00;
	ptrArg08.u3->t0002.u2 = (uint16) ~0x284F;
	ptrArg08.u3->t0004.u2 = (uint16) 0x80;
	ptrArg08.u3->t0006.u2 = (uint16) 0x00;
	ptrArg08.u3->ptr0008 = &Eq_63780::t0000;
	ptrArg08.u3->t000A.u2 = (uint16) 0x00;
	word16 di_14 = (word16) ptrArg08;
	ptrArg08.u3->t000C.u0 = (word16) (di_14 + 0x0080);
	struct Eq_63372 * es_13 = SLICE(ptrArg08, selector, 16);
	ptrArg08.u3->ptr000E = es_13;
	ptrArg08.u3->t0010.u2 = (uint16) 0x060C;
	struct Eq_63381 * cs;
	ptrArg08.u3->ptr0012 = cs;
	union Eq_63386 Eq_63372::* di_42 = di_14 + 20;
	word16 cx_47;
	for (cx_47 = 0x0E; cx_47 != 0x00; --cx_47)
	{
		(es_13->*di_42).u0 = 0x00;
		di_42 = (union Eq_63386 Eq_63372::*) ((char *) di_42 + 2);
	}
	Eq_17 al_52;
	al_52.u0 = ptrArg04.u3->t0000.u0;
	if (al_52 > 0x4F)
		al_52.u0 = 0x4F;
	Eq_63407 cx_60;
	cx_60.u1 = (uint16) al_52;
	memcpy(&&(es_13->*(es_13->*di_42).u0), &ptrArg04.u3->t0001.u0, (uint32) cx_60);
	es_13->*(di_42 + cx_60) = (word16) 0x00;
}
