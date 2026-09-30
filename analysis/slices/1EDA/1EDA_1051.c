// 1EDA:1051: Sequence Eq_17 fn1EDA_1051(Register byte al, Register Eq_17 ds, Stack Eq_17 ptrArg04)
// Called from:
//      fn0800_0147
//      fn0800_01FE
//      fn0800_03F8
//      fn0800_11EF
//      fn0800_2401
//      fn0800_2827
//      fn0800_31B7
//      fn0800_4168
//      fn0C43_0095
//      fn0C74_03D4
//      fn1229_039D
//      fn1229_0486
//      fn1229_0735
//      fn1AB8_0887
//      fn1AB8_097B
//      fn1AB8_1536
//      fn1EDA_0FD0
Eq_17 fn1EDA_1051(byte al, Eq_17 ds, Eq_17 ptrArg04)
{
	word16 ax;
	al = (byte) ax;
	fn1EDA_1076(ptrArg04, ds);
	Eq_65240 Z_13;
	Z_13.u1 = <invalid>;
	if (!Z_13)
	{
		Eq_17 bx_15;
		bx_15.u2 = ptrArg04.u3->t0000.u2;
		if (bx_15 > 0x04)
		{
			Eq_17 ax_21 = SEQ(0x3E, al);
			if (!msdos_close_file(bx_15))
				Mem22[ds:0x5380:word16] = ax_21;
		}
		ptrArg04.u3->t0002.u2 = (uint16) ~0x284F;
	}
	return ptrArg04;
}
