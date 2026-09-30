// 1229:0000: void fn1229_0000(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08, Stack Eq_17 wArg0A)
// Called from:
//      fn1229_0040
void fn1229_0000(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06, Eq_17 wArg08, Eq_17 wArg0A)
{
	fn1AB8_0F93(ds, 0x01, wArg04, wArg06, wArg08, wArg0A);
	fn1AB8_1028(ds);
	fn1AB8_0F93(ds, 0x01, fn1AB8_10E1(ds), fn1AB8_10CE(ds), 0x00, 0x00);
}
