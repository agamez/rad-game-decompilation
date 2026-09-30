// 1229:0C58: void fn1229_0C58(Register Eq_17 ds)
// Called from:
//      fn1229_0CCE
//      fn1229_0DCC
void fn1229_0C58(Eq_17 ds)
{
	uint8 bLoc05_81 = Mem7[ds:0x6CBA:byte];
	uint8 bLoc03_82 = 0x00;
	while (true)
	{
		uint8 bLoc04_83 = 0x00;
		while (true)
		{
			fn1AB8_13D7(ds, 0x00, ds.u3->ptr5992[(uint16) bLoc05_81].u3, (uint16) bLoc03_82 *s 22 + 0x0187, (uint16) bLoc04_83 *s 22 + 0x59);
			++bLoc05_81;
			if (bLoc04_83 == 0x18)
				break;
			++bLoc04_83;
		}
		if (bLoc03_82 == 0x03)
			break;
		++bLoc03_82;
	}
}
