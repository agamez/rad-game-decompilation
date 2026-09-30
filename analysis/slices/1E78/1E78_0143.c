// 1E78:0143: Register word16 fn1E78_0143(Register int16 dx, Register Eq_17 ds, Stack Eq_17 wArg04, Register out int16 dxOut)
// Called from:
//      fn1E78_030D
word16 fn1E78_0143(int16 dx, Eq_17 ds, Eq_17 wArg04, int16 & dxOut)
{
	int16 dx_42;
	if (Mem0[ds:~0x4745:byte] != 0x00)
	{
		Mem8[ds:~0x4745:byte] = 0x00;
		byte al_10;
		byte ah_11;
		while (!bios_kbd_check_keystroke(out al_10, out ah_11))
		{
			byte al_48;
			bios_kbd_get_keystroke(out al_48);
		}
		fn1E78_047C(0x5E, dx, ds);
		fn1E78_047C(0x43, dx, ds);
		fn1E78_0475(0x00, dx, ds);
		__syscall<byte>(0x23);
		word16 ax_39 = fn1E78_016B(ds, wArg04, out dx_42);
		dxOut = dx_42;
		return ax_39;
	}
	else
	{
		dxOut = dx;
		word16 ax;
		return ax;
	}
}
