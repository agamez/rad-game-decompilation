// 1AB8:1855: void fn1AB8_1855(Register Eq_17 ds, Stack Eq_58058 ptrArg04)
// Called from:
//      fn1AB8_0BAE
void fn1AB8_1855(Eq_17 ds, Eq_58058 ptrArg04)
{
	Mem5[ds:47267:byte] = ~0x00;
	Eq_17 es_23;
	es_23.u3 = SLICE(ptrArg04, selector, 16);
	if (ptrArg04.u1->b0016 == 0x00)
		es_23 = Mem9[ds:0xB834:selector];
	Mem9[ds:0xB820:segptr32]();
	Eq_58058 bx_45;
	Mem48[ds:0xB83A:word16] = bx_45;
	Mem51[ds:47164:word16] = es_23;
}
