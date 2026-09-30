// 1AB8:13D7: Register word16 fn1AB8_13D7(Register Eq_17 ds, Stack Eq_17 bArg04, Stack Eq_17 ptrArg06, Stack Eq_17 wArg0A, Stack Eq_17 wArg0C)
// Called from:
//      fn0800_01FE
//      fn0800_09C2
//      fn0800_0D20
//      fn0800_2401
//      fn0C74_03D4
//      fn0C74_05B8
//      fn0C74_06B7
//      fn0C74_0CFA
//      fn0C74_0D43
//      fn0C74_0D94
//      fn0C74_0DE5
//      fn0C74_0E2E
//      fn0C74_0FA1
//      fn0C74_1B3B
//      fn0C74_1D95
//      fn0C74_1F08
//      fn0C74_2AD9
//      fn0C74_2BBD
//      fn0C74_2E5A
//      fn0C74_3236
//      fn0C74_3615
//      fn0C74_37C3
//      fn0C74_45CE
//      fn0C74_4999
//      fn0C74_4DAC
//      fn0C74_4FD7
//      fn0C74_5258
//      fn1229_0040
//      fn1229_0AA8
//      fn1229_0C58
//      fn1229_0DCC
word16 fn1AB8_13D7(Eq_17 ds, Eq_17 bArg04, Eq_17 ptrArg06, Eq_17 wArg0A, Eq_17 wArg0C)
{
	Eq_17 ax_13;
	ax_13.u2 = ptrArg06.u3->t0002.u2;
	Mem32[ptrArg06 + 2:word16] = Mem14[ds:47044:word16] - (wArg0A + Mem14[ds:47188:word16]);
	if (ptrArg06.u3->t0002.u2 > ax_13)
		ptrArg06.u3->t0002.u2 = (uint16) ax_13;
	Eq_60318 dx_ax_146 = CONVERT(wArg0C + Mem46[ds:0xB852:word16] + Mem46[ptrArg06 + 0x00:word16], uint16, uint32);
	Eq_17 ax_59 = (word16) dx_ax_146;
	Eq_17 ax_66 = Mem46[ds:47042:word16];
	word16 dx_119 = 0x00;
	if (true && (false || ax_66 >= ax_59) && (wArg0C + Mem46[ds:0xB852:word16] >= 0x00 && (((ptrArg06.u3)->t0002).u2 >= 0x00 && wArg0A + Mem46[ds:47188:word16] >= 0x00)))
	{
		word16 wArg04;
		dx_119 = fn1AB8_1E9F(ds, (byte) wArg04, ptrArg06, wArg0A, wArg0C);
		ptrArg06.u3->t0002.u2 = (uint16) ax_13;
	}
	else
		ptrArg06.u3->t0002.u2 = (uint16) ax_13;
	return dx_119;
}
