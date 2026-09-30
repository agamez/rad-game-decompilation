// 1AB8:1EE3: void fn1AB8_1EE3(Register Eq_17 ds)
// Called from:
//      fn1AB8_1A62
void fn1AB8_1EE3(Eq_17 ds)
{
	Mem5[ds:0xB89A:byte] = ~0x00;
	Mem6[ds:0xB89C:byte] = ~0x00;
	Mem7[ds:~0x4764:byte] = 0x00;
	fn1AB8_1F19(ds);
	Eq_61049 bl_18 = Mem7[ds:0xB89C:byte];
	if (bl_18 != ~0x00)
	{
		Eq_61532 bx_25;
		bx_25.u0 = (uint16) bl_18;
		Mem27[ds:0xB89A:byte] = Mem7[0x1AB8:bx_25 + 0x1EB9:byte];
		Mem29[ds:~0x4764:byte] = Mem27[0x1AB8:bx_25 + 7879:byte];
		Mem31[ds:~0x4762:byte] = Mem29[0x1AB8:bx_25 + 0x1ED5:byte];
	}
}
