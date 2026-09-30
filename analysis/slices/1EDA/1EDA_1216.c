// 1EDA:1216: void fn1EDA_1216(Sequence (ptr32 Eq_18239) es_si, Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 ptrArg06)
// Called from:
//      fn0800_4255
void fn1EDA_1216(<unknown>* es_si, Eq_17 ds, Eq_17 wArg04, Eq_17 ptrArg06)
{
	<unknown>* es_si_182;
	cui16 ax_179;
	if (wArg04 != 0x00)
	{
		word16 bx_188;
		es_si_182 = fn1EDA_126C(wArg04, ds, out ax_179, out bx_188);
	}
	else
	{
		ax_179 = 0x00;
		es_si_182 = es_si;
		byte ah_16;
		if (msdos_get_dos_version(out ah_16) >= 0x03)
		{
			struct Eq_65591 * es_23 = Mem7[ds:21372:selector]->ptr002C;
			byte Eq_65591::* di_24 = &Eq_65591::b0000;
			while (es_23->*di_24 != 0x00)
				di_24 += (word32) strlen(&(es_23->*di_24)) + 1;
			byte Eq_65591::* di_35 = di_24 + 3;
			word16 cx_38 = 0x0100;
			byte Eq_65591::* di_42 = di_35;
			while (cx_38 != 0x00)
			{
				byte Eq_65591::* di_189;
				di_42 = di_189 + 1;
				--cx_38;
				di_189 = di_42;
				if (es_23->*di_189 != 0x00)
					break;
			}
			ax_179 = SEQ(SLICE(cx_38, byte, 8), ~(byte) cx_38);
			es_si_182 = (<unknown>*) &(es_23->*di_35);
		}
	}
	ptrArg06.u3->t0000.u0 = (int8) (byte) ax_179;
	memcpy(&ptrArg06.u3->t0001.u0, es_si_182, (uint32) ax_179);
}
