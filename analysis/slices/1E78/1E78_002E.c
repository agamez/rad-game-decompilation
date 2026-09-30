// 1E78:002E: void fn1E78_002E(Register Eq_17 ds)
// Called from:
//      fn1E78_0000
void fn1E78_002E(Eq_17 ds)
{
	Eq_62012 al_6 = fn1E78_0609();
	if (al_6 != 0x07 && al_6 > 0x03)
		fn1E78_0097(0x03);
	word16 dx_117;
	fn1E78_00E5(ds, out dx_117);
	Eq_62012 ah_38 = fn1E78_0609();
	Mem43[ds:0xB8B8:byte] = ah_38 & 0x7F;
	Mem44[ds:47278:byte] = ah_38 & 0x7F;
	Mem48[ds:47273:byte] = 0x00;
	Mem49[ds:~0x4746:byte] = 0x00;
	Mem50[ds:~0x4745:byte] = 0x00;
	Mem54[ds:47272:byte] = 0x01;
	uint8 al_58 = (uint8) 0040:006C;
	while (al_58 == 0040:006C)
		;
	Mem84[ds:0xB8B4:word16] = CONVERT(~fn1E78_02BF(0040:006C, 0040:006C, ~0x00), uint16, uint32) /u 55;
	struct Eq_62083 * cs;
	msdos_set_interrupt_vector(0x1B, &cs->t012D);
}
