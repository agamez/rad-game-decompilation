// 1E78:029C: Register byte fn1E78_029C(Register Eq_17 ds, Stack Eq_17 wArg04, Register out Eq_17 dxOut)
// Called from:
//      fn0800_149F
//      fn0800_166D
//      fn0800_1E3F
//      fn0800_2004
//      fn0800_391E
//      fn0800_3D9D
//      fn0C74_02D8
//      fn0C74_076B
//      fn0C74_0A35
//      fn0C74_2BBD
//      fn0C74_2E5A
//      fn0C74_3236
//      fn1229_0486
//      fn1229_0DCC
byte fn1E78_029C(Eq_17 ds, Eq_17 wArg04, union Eq_17 & dxOut)
{
	Eq_17 dx_33 = wArg04;
	uint16 ax;
	if (wArg04 != 0x00)
	{
		uint8 al_19 = (uint8) 0040:0000;
		uint16 bx_21 = Mem0[ds:0xB8B4:word16];
		do
		{
			fn1E78_02BF(0040:0000, al_19, bx_21);
			--dx_33;
			ax = (uint16) al_19;
		} while (dx_33 != 0x00);
	}
	dxOut = dx_33;
	return SLICE(ax, byte, 8);
}
