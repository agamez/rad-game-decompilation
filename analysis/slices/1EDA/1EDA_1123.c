// 1EDA:1123: Register byte fn1EDA_1123(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Stack Eq_17 ptrArg08)
// Called from:
//      fn0800_01FE
//      fn0800_2401
//      fn0800_2827
//      fn0800_31B7
//      fn0C43_00B9
//      fn1229_0486
//      fn1229_0735
byte fn1EDA_1123(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06, Eq_17 ptrArg08)
{
	fn1EDA_1076(ptrArg08, ds);
	Eq_65240 Z_15;
	Z_15.u1 = <invalid>;
	Eq_17 ax;
	if (!Z_15)
	{
		uint32 dx_ax_22 = ptrArg08.u3->t0004.u2 *32 wArg04;
		word32 dx_ax_32;
		ax = (word16) dx_ax_32;
		if (!msdos_set_file_position(ptrArg08.u3->t0000.u2, SEQ(ptrArg08.u3->t0004.u2 *16 wArg06 + SLICE(dx_ax_22, word16, 16), (word16) dx_ax_22), 0x00, out dx_ax_32))
			Mem35[ds:0x5380:word16] = ax;
	}
	return (byte) ax;
}
