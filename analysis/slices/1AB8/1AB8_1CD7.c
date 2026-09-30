// 1AB8:1CD7: Register byte fn1AB8_1CD7(Register Eq_17 ds, Stack int16 wArg04, Stack Eq_17 wArg06)
// Called from:
//      fn1AB8_1342
byte fn1AB8_1CD7(Eq_17 ds, int16 wArg04, Eq_17 wArg06)
{
	Mem7[ds:0xB820:segptr32]();
	word16 ax_20;
	return SLICE(ax_20, byte, 8);
}
