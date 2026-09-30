// 1E78:0097: void fn1E78_0097(Register Eq_17 ax)
// Called from:
//      fn1E78_002E
//      fn1E78_016B
void fn1E78_0097(Eq_17 ax)
{
	cu8 al = (byte) ax;
	byte ah = SLICE(ax, byte, 8);
	0040:0087 = (byte *) (0040:0087 & ~0x01);
	Eq_17 ax_18 = ax;
	if (al != 0x07)
	{
		ax_18 = ax;
		if (al >= 0x04)
			ax_18 = SEQ(ah, 0x03);
	}
	fn1E78_0609();
	if (SLICE(ax_18, byte, 8) != 0x00)
	{
		fn1E78_0609();
		fn1E78_0609();
		if (false)
		{
			0040:0087 = (byte *) (0040:0087 | 0x01);
			fn1E78_0609();
			fn1E78_0609();
		}
	}
}
