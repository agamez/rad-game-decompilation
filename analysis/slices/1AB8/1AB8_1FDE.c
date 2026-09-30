// 1AB8:1FDE: FlagGroup bool fn1AB8_1FDE(Register cu8 cl)
// Called from:
//      fn1AB8_1F9E
bool fn1AB8_1FDE(cu8 cl)
{
	ui32 C_11 = cond(cl - 0x02) & 0x02;
	if (cl >= 0x02)
	{
		C_11 = !(cond(cl - 0x06) & 0x02);
		if (cl >= 0x06)
			C_11 = cond(cl - 0x08) & 0x02;
	}
	return C_11 != 0x00;
}
