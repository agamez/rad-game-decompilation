// 13E2:0080: Register word16 fn13E2_0080(Register Eq_17 ds)
// Called from:
//      fn0800_166D
//      fn0800_3D9D
word16 fn13E2_0080(Eq_17 ds)
{
	word16 dx;
	if (Mem7[ds:0xB6C1:byte] == 0x00)
	{
		Mem12[ds:0xB6C1:byte] = 0x01;
		Mem13[ds:~0x4941:byte] = 0x00;
		while (true)
		{
			dx = fn1AB8_1CBA(ds, CONVERT(ds:0x50CE[CONVERT(Mem46[ds:~0x4941:byte], uint8, uint16) * 0x03], uint8, uint16), CONVERT(ds:0x50CD[CONVERT(Mem34[ds:~0x4941:byte], uint8, uint16) * 0x03], uint8, uint16), CONVERT(ds:0x50CC[CONVERT(Mem22[ds:~0x4941:byte], uint8, uint16) * 0x03], uint8, uint16), CONVERT(Mem15[ds:~0x4941:byte], uint8, uint16));
			fn1AB8_1342(ds, Mem79[ds:~0x4941:byte], CONVERT(Mem61[ds:~0x4941:byte], uint8, uint16));
			if (Mem83[ds:~0x4941:byte] == 0x0F)
				break;
			Mem96[ds:~0x4941:byte] = Mem83[ds:~0x4941:byte] + 0x01;
		}
	}
	return dx;
}
