// 1EDA:0572: void fn1EDA_0572(Register Eq_17 dx, Register Eq_17 ds, Stack Eq_17 ptrArg04)
// Called from:
//      fn1EDA_0565
//      fn1EDA_056A
void fn1EDA_0572(Eq_17 dx, Eq_17 ds, Eq_17 ptrArg04)
{
	Eq_17 ax_12;
	Eq_17 es_di_97;
	ax_12.u2 = es_di_97.u3->t0002.u2;
	switch (ax_12)
	{
	case 55217:
	case 55218:
		es_di_97 = fn1EDA_05BF(ds, es_di_97);
		break;
	case ~0x284F:
	default:
		Mem64[ds:0x5380:word16] = 0x66;
		return;
	}
	es_di_97.u3->t0002.u2 = (uint16) dx;
	es_di_97.u3->ptr0008 = &Eq_63780::t0000;
	es_di_97.u3->t000A.u2 = (uint16) 0x00;
	if (!fn1EDA_05FB((word16) SLICE(es_di_97, selector, 16) + 16, (word16) es_di_97, ds))
		es_di_97.u3->t0002.u2 = (uint16) ~0x284F;
}
