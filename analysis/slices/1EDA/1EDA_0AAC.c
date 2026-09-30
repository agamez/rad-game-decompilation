// 1EDA:0AAC: void fn1EDA_0AAC(Stack Eq_17 ptrArg04, Stack Eq_17 ptrArg08)
// Called from:
//      fn0800_0619
//      fn0800_0AA1
//      fn0800_0B42
//      fn0800_0D20
//      fn0800_21E7
//      fn0800_3D9D
//      fn0C74_011E
//      fn0C74_020C
//      fn1229_0040
//      fn1229_050A
//      fn1229_061B
//      fn1229_0735
//      fn1229_09F9
//      fn1229_0AA8
//      fn133F_026B
//      fn13E2_0193
//      fn1AB8_027E
//      fn1AB8_0887
//      fn1AB8_097B
//      fn1AB8_0BAE
//      fn1AB8_1536
//      fn1EDA_0B7C
//      fn1EDA_0BD0
void fn1EDA_0AAC(Eq_17 ptrArg04, Eq_17 ptrArg08)
{
	Eq_17 al_18;
	al_18.u0 = ptrArg04.u3->t0000.u0;
	Eq_17 cl_14;
	cl_14.u0 = ptrArg08.u3->t0000.u0;
	Eq_17 v20_20;
	v20_20.u3 = (byte) al_18.u1 + ((ptrArg08.u3)->t0000).u0;
	ptrArg08.u3->t0000.u0 = (int8) v20_20;
	struct Eq_64411 * es_12 = SLICE(ptrArg08, selector, 16);
	word16 di_13 = (word16) ptrArg08;
	uint16 cx_28 = (uint16) cl_14;
	if (v20_20 < 0x00)
	{
		ptrArg08.u3->t0000.u0 = ~0x00;
		al_18 = ~cl_14;
		cx_28 = (uint16) cl_14;
	}
	memcpy(di_13 + cx_28 + 0x01, &ptrArg04.u3->t0001.u0, (uint32) SEQ(SLICE(cx_28, byte, 8), al_18));
}
