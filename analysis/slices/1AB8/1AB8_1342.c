// 1AB8:1342: Register byte fn1AB8_1342(Register Eq_17 ds, Stack Eq_17 bArg04, Stack Eq_17 wArg06)
// Called from:
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
//      fn0800_3D9D
//      fn0800_4255
//      fn13E2_003B
//      fn13E2_0080
//      fn13E2_00FB
byte fn1AB8_1342(Eq_17 ds, Eq_17 bArg04, Eq_17 wArg06)
{
	uint16 ax;
	if (Mem7[ds:0xB84E:byte] == 0x00)
		return SLICE(ax, byte, 8);
	uint16 ax_14 = CONVERT(Mem7[ds:47226:byte], uint8, uint16);
	ax = ax_14 - 0x01;
	if (ax_14 - 0x01 < wArg06 || bArg04 < 0x00)
		return SLICE(ax, byte, 8);
	ds->*((word32) wArg06 + 0x0000B87B) = bArg04;
	if (wArg06 == 0x00)
		Mem25[ds:0xB840:byte] = 0x00;
	ax = (uint16) fn1AB8_1CD7(ds, (int16) bArg04, wArg06);
	return SLICE(ax, byte, 8);
}
