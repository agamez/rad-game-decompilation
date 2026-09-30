// 1EDA:0B61: void fn1EDA_0B61(Stack word16 wArg04, Stack Eq_17 ptrArg06, Stack Eq_17 ptrArg0A)
// Called from:
//      fn1AB8_05D3
//      fn1AB8_06CA
void fn1EDA_0B61(word16 wArg04, Eq_17 ptrArg06, Eq_17 ptrArg0A)
{
	ptrArg0A.u3->t0000.u0 = (int8) (byte) wArg04;
	memcpy(&ptrArg0A.u3->t0001.u0, ptrArg06, (uint32) wArg04);
}
