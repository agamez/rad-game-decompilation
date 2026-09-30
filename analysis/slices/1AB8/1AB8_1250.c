// 1AB8:1250: void fn1AB8_1250(Register Eq_17 ds, Stack Eq_17 wArg04)
// Called from:
//      fn133F_0056
//      fn1AB8_0AEE
void fn1AB8_1250(Eq_17 ds, Eq_17 wArg04)
{
	byte bArg04_44 = (byte) wArg04;
	if (wArg04 <= 0x0F)
	{
		Mem13[ds:0xB840:byte] = bArg04_44;
		if (wArg04 == 0x00)
			Mem19[ds:47227:byte] = 0x00;
		else
			Mem18[ds:47227:byte] = Mem13[ds:wArg04 + 47227:byte];
		fn1AB8_1CA4(ds, Mem21[ds:47227:byte]);
	}
}
