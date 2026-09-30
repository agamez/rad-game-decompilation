// 0800:0877: Register byte fn0800_0877(Register Eq_17 ds)
// Called from:
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
byte fn0800_0877(Eq_17 ds)
{
	byte bLoc03_64 = 0x00;
	uint8 bLoc04_65 = 0x00;
	byte dl_109;
	while (Mem14[ds:CONVERT(bLoc04_65, uint8, uint16) + 24240:byte] != 0x5E || fn1AB8_1E3C(ds, 0x0176, (uint16) bLoc04_65 *s 22 + 11, out dl_109) == 0x0F)
	{
		if (bLoc04_65 == 0x1C)
		{
			bLoc03_64 = 0x01;
			return bLoc03_64;
		}
		++bLoc04_65;
	}
	return bLoc03_64;
}
