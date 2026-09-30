// 1AB8:112E: Register byte fn1AB8_112E(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08, Stack Eq_17 wArg0A)
// Called from:
//      fn0800_09C2
//      fn0800_0D20
//      fn0800_184C
//      fn0800_19E1
//      fn0800_31B7
//      fn0800_3D9D
//      fn1229_0040
//      fn1229_0CCE
//      fn133F_0352
byte fn1AB8_112E(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06, Eq_17 wArg08, Eq_17 wArg0A)
{
	word16 dx_105;
	fn1AB8_1AF6(ds, wArg08, wArg06, wArg08, wArg0A, out dx_105);
	word16 dx_106;
	fn1AB8_1AF6(ds, wArg04, wArg06, wArg08, wArg06, out dx_106);
	word16 dx_107;
	fn1AB8_1AF6(ds, wArg04, wArg0A, wArg04, wArg06, out dx_107);
	word16 dx_108;
	fn1AB8_1AF6(ds, wArg08, wArg0A, wArg04, wArg0A, out dx_108);
	return 0x00;
}
