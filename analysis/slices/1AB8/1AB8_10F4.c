// 1AB8:10F4: void fn1AB8_10F4(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08)
// Called from:
//      fn0800_09C2
//      fn0800_1315
//      fn0800_184C
//      fn0800_19E1
//      fn0800_31B7
//      fn0800_36E6
//      fn0800_3D9D
//      fn0C74_0FA1
//      fn0C74_1F08
//      fn0C74_2E5A
//      fn0C74_3236
//      fn0C74_396E
//      fn0C74_3F74
//      fn0C74_45CE
//      fn0C74_4999
//      fn0C74_5258
//      fn1AB8_0AEE
void fn1AB8_10F4(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06, Eq_17 wArg08)
{
	if (wArg08 <= 0x04 && wArg04 <= 0x03)
	{
		Mem15[ds:0xB85C:word16] = wArg08;
		Mem17[ds:~0x47A1:word16] = wArg06;
		Mem19[ds:0xB860:word16] = wArg04;
		fn1AB8_1CFF(ds, (byte) wArg04, wArg06, wArg08);
	}
	else
		Mem40[ds:0xB818:word16] = ~0x0A;
}
