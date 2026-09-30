// 1AB8:122E: Register Eq_17 fn1AB8_122E(Register Eq_17 ds, Stack uint16 wArg04, Stack word16 wArg06, Stack word16 wArg08)
// Called from:
//      fn0800_3CFA
Eq_17 fn1AB8_122E(Eq_17 ds, uint16 wArg04, word16 wArg06, word16 wArg08)
{
	Eq_17 ds_36;
	fn1AB8_1B90(ds_36, fn1AB8_11FB(ds, wArg04, out ds_36), wArg04, 0x0168, 0x00, wArg06, wArg08);
	return ds_36;
}
