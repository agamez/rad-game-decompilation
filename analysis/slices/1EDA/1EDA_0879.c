// 1EDA:0879: void fn1EDA_0879(Sequence Eq_17 es_di, Register Eq_17 ds)
// Called from:
//      fn1EDA_081A
//      fn1EDA_0848
//      fn1EDA_086C
void fn1EDA_0879(Eq_17 es_di, Eq_17 ds)
{
	if (es_di.u3->w001A == 0x00)
		return;
	if (Mem0[ds:0x5380:word16] == 0x00)
	{
		es_di.u3->ptr0018();
		Eq_17 ax_18;
		if (ax_18 != 0x00)
			Mem26[ds:0x5380:word16] = ax_18;
	}
}
