// 1EDA:0A6B: void fn1EDA_0A6B(Stack Eq_52584 wArg04, Stack Eq_50514 wArg06, Stack Eq_17 ptrArg08, Stack Eq_17 ptrArg0C)
// Called from:
//      fn1229_0735
//      fn133F_02DF
//      fn1EDA_0B7C
//      fn1EDA_0BD0
void fn1EDA_0A6B(Eq_52584 wArg04, Eq_50514 wArg06, Eq_17 ptrArg08, Eq_17 ptrArg0C)
{
	struct Eq_64346 * ds_12 = SLICE(ptrArg08, selector, 16);
	word16 si_13 = (word16) ptrArg08;
	Eq_50514 cx_17 = wArg06;
	uint16 ax_27 = (uint16) ptrArg08.u3->t0000.u0;
	if (wArg06 <= 0x00)
		cx_17.u0 = 0x01;
	word16 si_25 = (word16) cx_17.u1 + si_13;
	uint16 ax_28 = ax_27 - cx_17;
	Eq_52584 ax_114;
	if (ax_28 >= 0x00)
	{
		byte al_57 = (byte) ax_28 + 0x01;
		byte ah_71 = SLICE(ax_28 + 0x01, byte, 8);
		ax_114 = wArg04;
		if (wArg04 < 0x00)
			ax_114.u0 = 0x00;
		ax_114 = SEQ(ah_71, al_57);
	}
	else
		ax_114.u0 = 0x00;
	ptrArg0C.u3->t0000.u0 = (int8) (byte) ax_114;
	memcpy(&ptrArg0C.u3->t0001.u0, si_25, (uint32) ax_114);
}
