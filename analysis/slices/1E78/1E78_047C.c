// 1E78:047C: Register byte fn1E78_047C(Register byte al, Register int16 dx, Register Eq_17 ds)
// Called from:
//      fn1E78_0143
//      fn1E78_0475
byte fn1E78_047C(byte al, int16 dx, Eq_17 ds)
{
	word16 ax;
	Eq_62161 dl_38 = (byte) dx;
	fn1E78_04F6();
	byte al_29 = (byte) ax;
	if (al_29 == 0x07)
	{
		fn1E78_0609();
		goto l1E78_04CD;
	}
	if (al_29 != 0x08 && al_29 != 0x0D)
	{
		if (al_29 == 0x0A)
		{
l1E78_04CA:
			fn1E78_04D5((byte) dx, ds);
			goto l1E78_04CD;
		}
		fn1E78_0609();
		byte dh_69 = SLICE(dx, byte, 8);
		if (SLICE(dx, byte, 0) + 0x01 >u Mem57[ds:0xB8B2:byte])
		{
			dx = SEQ(dh_69, Mem57[ds:0xB8B0:byte]);
			goto l1E78_04CA;
		}
	}
l1E78_04CD:
	fn1E78_04FD();
	return 0x00;
}
