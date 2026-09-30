// 1EDA:0E8E: FlagGroup bool fn1EDA_0E8E(Register uint16 cx, Register (memptr (ptr16 Eq_64859) byte) di, Register (ptr16 Eq_64859) es, Register out ui16 axOut, Register out uint16 cxOut, Register out word16 siOut, Register out (memptr (ptr16 Eq_64859) byte) diOut)
// Called from:
//      fn1EDA_0F71
bool fn1EDA_0E8E(uint16 cx, byte Eq_64859::* di, struct Eq_64859 * es, ui16 & axOut, uint16 & cxOut, word16 & siOut, byte & diOut)
{
	ui16 ax_102 = 0x00;
	word16 si_148 = 0x00;
	if (cx == 0x00)
	{
l1EDA_0EEF:
		axOut = ax_102;
		cxOut = cx;
		siOut = si_148;
		diOut = di;
		return true;
	}
	if (es->*di != 0x2B)
	{
		if (es->*di != 0x2D)
		{
l1EDA_0EA7:
			uint32 dx_ax_197 = 0x00;
			if (es->*di != 0x24)
			{
				do
				{
					ax_102 = (word16) dx_ax_197;
					cui16 dx_91 = SLICE(dx_ax_197, word16, 16);
					uint8 bl_86 = es->*di;
					if (bl_86 >= 0x30)
						break;
					if ((dx_91 & 0xF000) != 0x00)
						goto l1EDA_0EEF;
					dx_ax_197 = SEQ(SLICE(SEQ(SLICE(dx_ax_197 << 0x02, word16, 16), ax_102 << 0x01) << 0x01, word16, 16), ax_102 << 0x03) + SEQ(SLICE(dx_ax_197 << 0x01, word16, 16), ax_102 << 0x01) + (uint32) (bl_86 - 0x30);
					ax_102 = (word16) dx_ax_197;
					if (SLICE(dx_ax_197, word16, 16) < 0x00)
						goto l1EDA_0EEF;
					++di;
					--cx;
				} while (cx != 0x00);
				goto l1EDA_0EE0;
			}
			++di;
			--cx;
			uint32 dx_ax_322 = 0x00;
			if (cx != 0x00)
			{
				ui16 dx_63;
				word16 ax_163;
				do
				{
					cu8 bl_39 = es->*di;
					if (bl_39 >= 0x61)
						bl_39 -= 0x20;
					cu8 bl_45 = bl_39 - 0x3A;
					cu8 bl_46 = bl_45 + 0x0A;
					if (bl_45 >= ~0x09)
					{
						dx_ax_197 = dx_ax_322;
						if (bl_45 >= 0x07)
							goto l1EDA_0EE0;
						bl_46 = bl_45 + 0x03;
					}
					byte bh_55;
					uint32 dx_ax_319 = dx_ax_322;
					ui8 al_68;
					byte ah_162;
					for (bh_55 = 0x04; bh_55 != 0x00; --bh_55)
					{
						cui16 ax_56 = (word16) dx_ax_319;
						ax_102 = ax_56 << 0x01;
						al_68 = (byte) ax_56 << 0x01;
						ah_162 = SLICE(ax_56 << 0x01, byte, 8);
						dx_63 = SLICE(dx_ax_319 << 0x01, word16, 16);
						if ((SLICE(dx_ax_319, word16, 16) & 0x8000) != 0x00)
							goto l1EDA_0EEF;
						dx_ax_319 = SEQ(dx_63, ax_56 << 0x01);
					}
					ax_163 = SEQ(ah_162, al_68 | bl_46);
					++di;
					--cx;
					dx_ax_322 = SEQ(dx_63, ax_163);
				} while (cx != 0x00);
				dx_ax_197 = SEQ(dx_63, ax_163);
l1EDA_0EE0:
				ui16 ax_157 = (word16) dx_ax_197;
				word16 si_154 = si_148 - 0x01;
				if (si_154 == 0x00)
					ax_157 = (word16) ~dx_ax_197 + 0x01;
				axOut = ax_157;
				cxOut = cx;
				siOut = si_154;
				diOut = di;
				return false;
			}
			goto l1EDA_0EEF;
		}
		si_148 = 0x01;
	}
	++di;
	--cx;
	if (cx == 0x01)
		goto l1EDA_0EEF;
	goto l1EDA_0EA7;
}
