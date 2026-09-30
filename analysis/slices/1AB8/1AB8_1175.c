// 1AB8:1175: void fn1AB8_1175(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06)
// Called from:
//      fn0800_005A
//      fn0800_1315
//      fn0800_19E1
//      fn0800_36E6
//      fn0800_391E
//      fn0800_3D9D
//      fn0800_4255
//      fn0C74_00DB
//      fn1AB8_0AEE
//      fn1AB8_1028
void fn1AB8_1175(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06)
{
	if (wArg06 > 11)
		Mem26[ds:0xB818:word16] = ~0x0A;
	else
	{
		Mem13[ds:47202:word16] = wArg06;
		Mem15[ds:47204:word16] = wArg04;
		fn1AB8_1D5B(ds, (byte) wArg04, (byte) wArg06);
	}
}
