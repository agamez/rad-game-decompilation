// 0800:3CFA: Register Eq_17 fn0800_3CFA(Register Eq_17 ds)
// Called from:
//      fn0800_3D9D
Eq_17 fn0800_3CFA(Eq_17 ds)
{
	Mem11[ds:21471:byte] = 0x01;
	fn1AB8_1C32(ds, 0x00);
	fn0800_3BF2(SEQ(ds, 0x555E));
	cui16 wLoc04_115 = 0x00;
	cui16 v12_66;
	cup16 ax_74;
	ci16 dx_78;
	do
	{
		v12_66 = wLoc04_115 + 0x01;
		ds = fn1AB8_122E(ds, 0x5A, 100, 100);
		wLoc04_115 = v12_66;
		ax_74 = fn0800_3C72(SEQ(ds, 0x555E), out dx_78);
	} while (dx_78 <= 0x00 && (dx_78 < 0x00 || ax_74 <= 100));
	Mem103[ds:22758:word16] = CONVERT(v12_66 << 0x03, uint16, uint32) /u 100;
	if (Mem103[ds:22758:word16] < 0x07)
		Mem106[ds:22758:word16] = 0x07;
	return ds;
}
