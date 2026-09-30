// 1EDA:0A1F: void fn1EDA_0A1F(Stack Eq_17 ptrArg04, Stack Eq_17 ptrArg08)
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
//      fn133F_026B
//      fn13E2_0193
//      fn1AB8_027E
//      fn1AB8_0887
//      fn1AB8_097B
//      fn1AB8_0BAE
//      fn1AB8_1536
void fn1EDA_0A1F(Eq_17 ptrArg04, Eq_17 ptrArg08)
{
	Eq_17 al_14;
	al_14.u0 = ptrArg04.u3->t0000.u0;
	ptrArg08.u3->t0000.u0 = (int8) al_14;
	memcpy(&ptrArg08.u3->t0001.u0, &ptrArg04.u3->t0001.u0, (uint32) al_14);
}
