// 1AB8:0F93: Register word16 fn1AB8_0F93(Register Eq_17 ds, Stack byte bArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08, Stack Eq_17 wArg0A, Stack Eq_17 wArg0C)
// Called from:
//      fn0800_0024
//      fn0C74_007C
//      fn1229_0000
//      fn1229_0AA8
//      fn133F_014B
//      fn1AB8_0AEE
word16 fn1AB8_0F93(Eq_17 ds, byte bArg04, Eq_17 wArg06, Eq_17 wArg08, Eq_17 wArg0A, Eq_17 wArg0C)
{
	word16 dx;
	if (wArg0C >= 0x00 && wArg0A >= 0x00)
	{
		Eq_17 ax_14 = Mem7[ds:47042:word16];
		dx = 0x00;
		if (true && (false || wArg08 <= ax_14))
		{
			Eq_17 ax_29 = Mem7[ds:47044:word16];
			dx = 0x00;
			if (true && (false || wArg06 <= ax_29) && (wArg08 >= wArg0C && wArg06 >= wArg0A))
			{
				Mem55[ds:0xB852:word16] = wArg0C;
				Mem57[ds:47188:word16] = wArg0A;
				Mem59[ds:0xB856:word16] = wArg08;
				Mem61[ds:0xB858:word16] = wArg06;
				Mem63[ds:47194:byte] = bArg04;
				dx = fn1AB8_1895(ds, bArg04, wArg06, wArg08, wArg0A, wArg0C);
				fn1AB8_108B(ds, 0x00, 0x00);
				return dx;
			}
		}
	}
	Mem107[ds:0xB818:word16] = ~0x0A;
	return dx;
}
