// 1AB8:14F4: void fn1AB8_14F4(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06)
// Called from:
//      fn0800_04E3
//      fn0800_0619
//      fn0800_0768
//      fn0800_0D20
//      fn0800_149F
//      fn0800_166D
//      fn0800_184C
//      fn0800_19E1
//      fn0800_1E3F
//      fn0800_2004
//      fn0800_21E7
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
//      fn0800_391E
//      fn0800_4255
//      fn1229_0040
//      fn1229_0AA8
//      fn133F_014B
//      fn1AB8_0AEE
void fn1AB8_14F4(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06)
{
	if (wArg06 >= 0x00 && (wArg06 <= 0x02 && (wArg04 >= 0x00 && wArg04 <= 0x02)))
	{
		Mem19[ds:0xB892:word16] = wArg06;
		Mem21[ds:47252:word16] = wArg04;
		fn1AB8_1992(ds, (byte) wArg04, (byte) wArg06);
	}
	else
		Mem33[ds:0xB818:word16] = ~0x0A;
}
