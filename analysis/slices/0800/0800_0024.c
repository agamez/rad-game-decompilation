// 0800:0024: void fn0800_0024(Register Eq_17 ds, Stack Eq_17 wArg02, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08)
// Called from:
//      fn0800_01FE
//      fn0800_0D20
//      fn0800_1E3F
//      fn0800_31B7
//      fn0800_391E
void fn0800_0024(Eq_17 ds, Eq_17 wArg02, Eq_17 wArg04, Eq_17 wArg06, Eq_17 wArg08)
{
	fn1AB8_0F93(ds, 0x01, wArg02, wArg04, wArg06, wArg08);
	fn1AB8_1028(ds);
	fn1AB8_0F93(ds, 0x01, fn1AB8_10E1(ds), fn1AB8_10CE(ds), 0x00, 0x00);
}
