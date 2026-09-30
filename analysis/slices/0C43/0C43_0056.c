// 0C43:0056: void fn0C43_0056(Register Eq_17 ds)
// Called from:
//      fn0C43_00B9
void fn0C43_0056(Eq_17 ds)
{
	Eq_17 ds_si_14 = Mem13[ds:22660:segptr32];
	byte Eq_19011::* si_15 = (word16) ds_si_14;
	selector es_6 = Mem0[ds:0x5882:selector];
	byte Eq_19005::* di_28 = Mem0[ds:22682:word16];
	struct Eq_19011 * ds_60 = SLICE(ds_si_14, selector, 16);
	byte Eq_19011::* bx_16 = Mem0[ds:22676:word16] + si_15;
	uint16 cx_37 = CONVERT(Mem0[ds:22674:byte], uint8, uint16);
	Eq_19020 cl_30;
	while (true)
	{
		byte ch_62 = SLICE(cx_37, byte, 8);
		cl_30 = (byte) cx_37;
		if (si_15 == bx_16)
			break;
		cu8 al_33 = ds_60->*si_15;
		++si_15;
		if (cl_30 <= 0x00)
		{
			if (al_33 >= 0xC0)
				cx_37 = SEQ(ch_62, al_33 ^ 0xC0);
			else
			{
				es_6->*di_28 = al_33;
				++di_28;
			}
		}
		else
		{
			for (; cx_37 != 0x00; --cx_37)
			{
				es_6->*di_28 = al_33;
				++di_28;
			}
		}
	}
	Mem29[ds:22682:word16] = di_28;
	Mem31[ds:22674:byte] = cl_30;
}
