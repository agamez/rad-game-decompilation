// 1EDA:11DF: void fn1EDA_11DF(Stack cup16 wArg04, Stack Eq_58057 ptrArg06, Stack Eq_58058 ptrArg0A)
// Called from:
//      fn1AB8_0569
//      fn1AB8_0BAE
//      fn1AB8_129A
void fn1EDA_11DF(cup16 wArg04, Eq_58057 ptrArg06, Eq_58058 ptrArg0A)
{
	<unknown>* si_13 = (word16) ptrArg0A;
	struct Eq_65513 * ds_30 = SLICE(ptrArg0A, selector, 16);
	<unknown>* di_14 = (word16) ptrArg06;
	struct Eq_65517 * es_27 = SLICE(ptrArg06, selector, 16);
	if (si_13 < di_14)
	{
		si_13 = (<unknown>*) ((char *) si_13 + wArg04 - 0x01);
		di_14 = (<unknown>*) ((char *) di_14 + wArg04 - 0x01);
	}
	memcpy(di_14, si_13, (uint32) wArg04);
}
