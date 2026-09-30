// 1EDA:0AD8: Sequence segptr32 fn1EDA_0AD8(Stack Eq_17 ptrArg04, Stack Eq_17 ptrArg08, Register out word16 axOut)
// Called from:
//      fn0800_4255
segptr32 fn1EDA_0AD8(Eq_17 ptrArg04, Eq_17 ptrArg08, word16 & axOut)
{
	word16 wArg04_116 = (word16) ptrArg04;
	struct Eq_64443 * ds_21 = SLICE(ptrArg08, selector, 16);
	<unknown>* si_158 = (word16) ptrArg08;
	struct Eq_64447 * es_12 = SLICE(ptrArg04, selector, 16);
	word16 di_13 = (word16) ptrArg04;
	uint16 cx_19 = (uint16) ptrArg04.u3->t0000.u0;
	word16 ax_126;
	if (cx_19 != 0x00)
	{
		Eq_64453 al_23 = ptrArg08.u3->t0000.u0;
		byte Eq_64447::* di_173 = di_13 + 0x01;
		++si_158;
		bool v30_108 = al_23 != 0x01;
		if (al_23 < 0x01)
		{
l1EDA_0B1A:
			ax_126 = di_173 - wArg04_116;
l1EDA_0B20:
			axOut = ax_126;
			return si_158;
		}
		if (al_23 <= 0x01)
		{
			byte al_60 = ptrArg08.u3->t0001.u0;
			si_158 += 2;
			while (cx_19 != 0x00)
			{
				v30_108 = al_60 != es_12->*di_173;
				++di_173;
				--cx_19;
				if (al_60 != es_12->*di_173)
					break;
			}
			if (!v30_108)
			{
				--di_173;
				goto l1EDA_0B1A;
			}
		}
		else
		{
			uint16 ax_30 = (uint16) al_23;
			uint16 dx_31 = cx_19 - ax_30;
			if (dx_31 >= 0x00)
			{
				uint16 dx_34 = dx_31 + 0x01;
				do
				{
					Eq_64529 cmpResult_42 = memcmp(si_158, &(es_12->*di_173), (uint32) ax_30);
					Eq_64537 firstDifference_43 = __find_first_difference__(si_158, &(es_12->*di_173));
					uint16 cx_44 = ax_30 - firstDifference_43;
					si_158 = (<unknown>*) (si_158 + firstDifference_43);
					byte Eq_64447::* di_46 = di_173 + firstDifference_43;
					if (cmpResult_42 == 0x00)
					{
						di_173 = di_46 - ax_30;
						goto l1EDA_0B1A;
					}
					word16 cx_51 = cx_44 - ax_30;
					si_158 += cx_51;
					di_173 = di_46 + cx_51 + 1;
					--dx_34;
				} while (dx_34 != 0x00);
			}
		}
	}
	ax_126 = 0x00;
	goto l1EDA_0B20;
}
