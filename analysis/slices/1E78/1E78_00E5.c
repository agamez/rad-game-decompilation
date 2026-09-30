// 1E78:00E5: Register byte fn1E78_00E5(Register Eq_17 ds, Register out Eq_62020 dxOut)
// Called from:
//      fn1E78_002E
//      fn1E78_016B
byte fn1E78_00E5(Eq_17 ds, union Eq_62020 & dxOut)
{
	Eq_62012 ax_71 = fn1E78_0609();
	fn1E78_0609();
	byte ah_5 = SLICE(ax_71, byte, 8);
	uint8 al_6 = (byte) ax_71;
	byte cl_20 = 0x00;
	cu8 dl_21 = 0x00;
	if (true)
	{
		dl_21 = 0x18;
		if (al_6 <= 0x03)
			cl_20 = 0x01;
	}
	Eq_17 ax_41;
	ax_41.u2 = (uint16) al_6;
	Eq_62020 dx_50 = SEQ(dl_21, ah_5 - 0x01);
	if (dl_21 > 0x18)
		ax_41 = SEQ(0x01, al_6);
	Mem48[ds:47276:word16] = ax_41;
	Mem51[ds:~0x4749:word16] = dx_50;
	Mem54[ds:~0x4754:byte] = cl_20;
	Mem55[ds:47274:byte] = 0x01;
	Mem60[ds:0xB8B0:word16] = 0x00;
	Mem61[ds:0xB8B2:word16] = dx_50;
	dxOut = dx_50;
	return 0x00;
}
