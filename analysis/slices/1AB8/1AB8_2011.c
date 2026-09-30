// 1AB8:2011: Register byte fn1AB8_2011()
// Called from:
//      fn1AB8_1F19
byte fn1AB8_2011()
{
	cu8 bl_19 = 0x00;
	byte al_6 = __in<byte>(0x03BA);
	word16 cx_12;
	for (cx_12 = 0x8000; cx_12 != 0x00; --cx_12)
	{
		if ((__in<byte>(0x03BA) & 0x80) != (al_6 & 0x80))
		{
			++bl_19;
			if (bl_19 >= 0x0A)
			{
				word16 cx_23;
				for (cx_23 = 0x8000; cx_23 != 0x00; --cx_23)
				{
					if ((__in<byte>(0x03BA) & 0x30) != 0x10)
						return 0x01;
				}
				return 0x02;
			}
		}
	}
	return 0x00;
}
