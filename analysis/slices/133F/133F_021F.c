// 133F:021F: Register byte fn133F_021F(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06)
// Called from:
//      fn133F_0528
byte fn133F_021F(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06)
{
	Eq_17 ax_13 = wArg06;
	if (wArg06 > Mem7[ds:0x6CC8:word16])
	{
		ax_13 = wArg06;
		if (wArg06 < Mem7[ds:0x6CCC:word16])
		{
			ax_13 = wArg04;
			if (wArg04 > Mem7[ds:0x6CCA:word16])
			{
				ax_13 = wArg04;
				if (wArg04 < Mem7[ds:0x6CCE:word16])
				{
					Mem23[ds:0x6CC4:word16] = wArg06;
					Mem25[ds:0x6CC6:word16] = wArg04;
					ax_13 = wArg04;
				}
			}
		}
	}
	return SLICE(ax_13, byte, 8);
}
