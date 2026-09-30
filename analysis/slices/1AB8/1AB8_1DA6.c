// 1AB8:1DA6: Register Eq_17 fn1AB8_1DA6(Register Eq_17 ds, Stack Eq_17 bArg04, Stack Eq_17 bArg06, Stack Eq_17 bArg08)
// Called from:
//      fn1AB8_1536
Eq_17 fn1AB8_1DA6(Eq_17 ds, Eq_17 bArg04, Eq_17 bArg06, Eq_17 bArg08)
{
	Eq_17 es_11 = Mem7[ds:47164:selector];
	if (bArg08 != 0x00)
	{
		Eq_58058 es_di_31 = Mem7[ds:0xB83A:segptr32];
		es_11.u3 = SLICE(es_di_31, selector, 16);
		es_di_31.u1->b0001 == 0x03;
	}
	Mem7[ds:0xB820:segptr32]();
	return es_11;
}
