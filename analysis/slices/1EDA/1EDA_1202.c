// 1EDA:1202: void fn1EDA_1202(Stack Eq_58896 bArg04, Stack Eq_17 wArg06, Stack Eq_17 ptrArg08)
// Called from:
//      fn1AB8_0AEE
//      fn1AB8_0BAE
void fn1EDA_1202(Eq_58896 bArg04, Eq_17 wArg06, Eq_17 ptrArg08)
{
	struct Eq_65535 * es_18 = SLICE(ptrArg08, selector, 16);
	byte Eq_65535::* di_14 = (word16) ptrArg08;
	Eq_17 cx_11;
	for (cx_11 = wArg06; cx_11 != 0x00; --cx_11)
	{
		es_18->*di_14 = (byte) bArg04;
		++di_14;
	}
}
