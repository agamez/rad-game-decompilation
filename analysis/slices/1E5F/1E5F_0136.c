// 1E5F:0136: void fn1E5F_0136(Register cui16 ax, Register word16 di, Register (ptr16 Eq_61907) es, Register Eq_17 ds)
// Called from:
//      fn1E5F_00DE
void fn1E5F_0136(cui16 ax, word16 di, struct Eq_61907 * es, Eq_17 ds)
{
	Eq_61915 C;
	if (!C)
	{
		byte Eq_61907::* di_107 = di + 0x1E;
		word16 cx_20 = 0x0100;
		byte cl_31;
		byte ch_68;
		do
		{
			cl_31 = (byte) cx_20;
			ch_68 = SLICE(cx_20, byte, 8);
			if (cx_20 == 0x00)
				break;
			--cx_20;
			++di_107;
			cl_31 = (byte) cx_20;
			ch_68 = SLICE(cx_20, byte, 8);
		} while (es->*di_107 == 0x00);
		byte Eq_61907::* di_37 = di_107 - 0x01;
		byte cl_34 = ~cl_31;
		byte Eq_61907::* si_39 = di_37 - 0x01;
		word16 cx_42;
		for (cx_42 = SEQ(ch_68, cl_34); cx_42 != 0x00; --cx_42)
		{
			es->*di_37 = es->*si_39;
			--si_39;
			--di_37;
		}
		es->*di_37 = cl_34;
		ax = 0x00;
	}
	Mem59[ds:47270:word16] = ax;
}
