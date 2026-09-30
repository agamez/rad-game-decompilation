// 13E2:00FB: void fn13E2_00FB(Register Eq_17 ds)
// Called from:
//      fn0800_2827
//      fn0800_2C0C
void fn13E2_00FB(Eq_17 ds)
{
	if (Mem7[ds:0xB6C1:byte] == 0x00)
	{
		Mem12[ds:0xB6C1:byte] = 0x01;
		Mem13[ds:~0x4941:byte] = 0x00;
		while (true)
		{
			if (Mem15[ds:~0x4941:byte] == 0x08)
				fn1AB8_1CBA(ds, 0x00, 0x00, 0x00, CONVERT(Mem15[ds:~0x4941:byte], uint8, uint16));
			else
				fn1AB8_1CBA(ds, CONVERT(ds:0x50CE[CONVERT(Mem48[ds:~0x4941:byte], uint8, uint16) * 0x03], uint8, uint16), CONVERT(ds:0x50CD[CONVERT(Mem36[ds:~0x4941:byte], uint8, uint16) * 0x03], uint8, uint16), CONVERT(ds:0x50CC[CONVERT(Mem24[ds:~0x4941:byte], uint8, uint16) * 0x03], uint8, uint16), CONVERT(Mem15[ds:~0x4941:byte], uint8, uint16));
			fn1AB8_1342(ds, Mem109[ds:~0x4941:byte], CONVERT(Mem99[ds:~0x4941:byte], uint8, uint16));
			if (Mem113[ds:~0x4941:byte] == 0x0F)
				break;
			Mem126[ds:~0x4941:byte] = Mem113[ds:~0x4941:byte] + 0x01;
		}
	}
}
