// 1E78:02FB: Register byte fn1E78_02FB(Register Eq_17 ds)
// Called from:
//      fn0800_0768
//      fn0800_08E9
//      fn0800_0D20
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
//      fn0C74_3615
//      fn0C74_37C3
//      fn1229_0040
//      fn1229_050A
//      fn1229_061B
//      fn133F_0528
byte fn1E78_02FB(Eq_17 ds)
{
	byte al_12;
	if (Mem0[ds:~0x4746:byte] == 0x00)
	{
		al_12 = 0x00;
		byte al_9;
		byte ah_10;
		if (bios_kbd_check_keystroke(out al_9, out ah_10))
			return al_12;
	}
	al_12 = 0x01;
	return al_12;
}
