// 1EDA:01A5: void fn1EDA_01A5(Register (memptr (ptr16 Eq_16) byte) bx)
// Called from:
//      fn1EDA_00E9
void fn1EDA_01A5(byte seg1EDA_t::* bx)
{
	while (true)
	{
		Eq_62743 al_6 = 7898->*bx;
		if (al_6 == 0x00)
			break;
		fn1EDA_01E7(al_6);
		++bx;
	}
}
