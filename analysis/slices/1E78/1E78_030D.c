// 1E78:030D: Register word16 fn1E78_030D(Register int16 dx, Register Eq_17 ds, Stack Eq_17 wArg02, Register out word16 dxOut)
// Called from:
//      fn0800_0768
//      fn0800_08E9
//      fn0800_0D20
//      fn0800_149F
//      fn0800_166D
//      fn0800_1E3F
//      fn0800_2004
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
//      fn0800_391E
//      fn0800_3D9D
//      fn0800_4255
//      fn1229_0040
//      fn133F_0528
word16 fn1E78_030D(int16 dx, Eq_17 ds, Eq_17 wArg02, word16 & dxOut)
{
	word16 dx_38;
	byte al_14;
	byte al_6 = Mem0[ds:~0x4746:byte];
	Mem7[ds:~0x4746:byte] = 0x00;
	if (al_6 == 0x00)
	{
		byte ah_15 = bios_kbd_get_keystroke(out al_14);
		if (al_14 == 0x00)
			Mem21[ds:~0x4746:byte] = ah_15;
	}
	word16 ax_35 = fn1E78_0143(dx, ds, wArg02, out dx_38);
	dxOut = dx_38;
	return ax_35;
}
