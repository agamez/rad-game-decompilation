// 1AB8:1F9E: void fn1AB8_1F9E(Register cu8 cl, Register word16 bx, Register Eq_17 ds)
// Called from:
//      fn1AB8_1F19
void fn1AB8_1F9E(cu8 cl, word16 bx, Eq_17 ds)
{
	byte bh = SLICE(bx, byte, 8);
	byte bl = (byte) bx;
	Mem5[ds:0xB89C:byte] = 0x04;
	if (bh == 0x01)
		Mem9[ds:0xB89C:byte] = 0x05;
	else if (!fn1AB8_1FDE(cl) && bl != 0x00)
	{
		Mem21[ds:0xB89C:byte] = 0x03;
		if (fn1AB8_1FED() || C000:0039 == 0x345A && C000:003B == 14644)
			Mem37[ds:0xB89C:byte] = 0x09;
	}
}
