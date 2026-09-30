// 13E2:003B: Register byte fn13E2_003B(Register Eq_17 ds)
// Called from:
//      fn0800_184C
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_3D9D
//      fn0800_4255
byte fn13E2_003B(Eq_17 ds)
{
	word16 dx;
	if (Mem7[ds:0xB6C1:byte] != 0x00)
	{
		Mem12[ds:0xB6C1:byte] = 0x00;
		Mem13[ds:~0x4941:byte] = 0x0F;
		while (true)
		{
			dx = fn1AB8_1CBA(ds, 0x00, 0x00, 0x00, CONVERT(Mem15[ds:~0x4941:byte], uint8, uint16));
			fn1AB8_1342(ds, Mem49[ds:~0x4941:byte], CONVERT(Mem31[ds:~0x4941:byte], uint8, uint16));
			if (Mem53[ds:~0x4941:byte] == 0x00)
				break;
			Mem66[ds:~0x4941:byte] = Mem53[ds:~0x4941:byte] - 0x01;
		}
	}
	return SLICE(dx, byte, 8);
}
