// 1EDA:0FD0: Register byte fn1EDA_0FD0(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 ptrArg06, Register out Eq_17 dxOut)
// Called from:
//      fn0800_0147
//      fn0800_01FE
//      fn0800_03F8
//      fn0800_11EF
//      fn0800_2401
//      fn0800_2827
//      fn0800_31B7
//      fn0800_4168
//      fn0C43_00B9
//      fn0C74_03D4
//      fn1229_039D
//      fn1229_0486
//      fn1229_0735
//      fn1AB8_0887
byte fn1EDA_0FD0(Eq_17 ds, Eq_17 wArg04, Eq_17 ptrArg06, union Eq_17 & dxOut)
{
	byte al_6 = Mem0[ds:21382:byte];
	Eq_17 dx_124;
	dx_124.u0 = 0x00;
	Eq_17 ax_108 = SEQ(0x3D, al_6);
	Eq_17 es_di_142;
	if (es_di_142.u3->t0002.u2 != ~0x284F)
	{
		if (es_di_142.u3->t0002.u2 != 55219)
		{
			Mem86[ds:0x5380:word16] = 0x66;
			goto l1EDA_1031;
		}
		es_di_142 = fn1EDA_1051(al_6, ds, es_di_142);
	}
	<unknown> Eq_65188::* di_47 = (word16) es_di_142;
	struct Eq_65188 * es_46 = SLICE(es_di_142, selector, 16);
	if (es_di_142.u3->b0030 != 0x00)
	{
		dx_124.u3 = (char *) di_47 + 48;
		if (!msdos_open_file(&(es_46->*((char *) di_47 + 48)), al_6, out ax_108))
		{
			Mem85[ds:0x5380:word16] = ax_108;
l1EDA_1031:
			dxOut = dx_124;
			return (byte) ax_108;
		}
	}
	else
	{
		dx_124 = ax_108;
		ax_108.u0 = 0x00;
	}
	es_di_142.u3->t0002.u2 = (uint16) 55219;
	es_di_142.u3->t0000.u2 = (uint16) ax_108;
	es_di_142.u3->t0004.u2 = (uint16) wArg04;
	ax_108 = wArg04;
	goto l1EDA_1031;
}
