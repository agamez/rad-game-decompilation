// 0800:00C1: Register byte fn0800_00C1(Register Eq_17 ds, Stack Eq_17 wArg02, Stack Eq_17 wArg04, Register out word16 dxOut)
// Called from:
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
byte fn0800_00C1(Eq_17 ds, Eq_17 wArg02, Eq_17 wArg04, word16 & dxOut)
{
	selector seg0800;
	word16 dx;
	uint16 ax;
	if (Mem7[ds:22718:byte] == 0x00)
	{
		Mem16[ds:21474:word16] = 0x00;
		Mem19[ds:22744:word16] = wArg02;
		Mem20[ds:22746:word16] = wArg04;
		fn1E5F_0159(SEQ(ds, 22720), 0x1C);
		uint16 ax_90 = (uint16) fn1E5F_0171(&seg0800->t007B, 0x1C, out dx);
		Mem46[ds:22718:byte] = 0x01;
		ax = ax_90;
	}
	dxOut = dx;
	return SLICE(ax, byte, 8);
}
