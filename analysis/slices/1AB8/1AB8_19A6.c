// 1AB8:19A6: Register word16 fn1AB8_19A6(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08, Stack Eq_17 wArg0A)
// Called from:
//      fn1AB8_13A3
word16 fn1AB8_19A6(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06, Eq_17 wArg08, Eq_17 wArg0A)
{
	uint16 ax_33;
	wchar_t ax_10 = wArg06 - wArg0A;
	if (ax_10 < 0x00)
		ax_10 = -ax_10;
	uint16 ax_19 = ax_10 + 0x08 >> 0x01;
	Mem26[ds:0xB820:segptr32]();
	fn1AB8_1807();
	uint16 ax_56 = (ax_19 >> 0x02) * ax_33;
	Eq_61174 cx_47 = wArg04 - wArg08;
	if (cx_47 < 0x00)
		cx_47 = -cx_47;
	uint32 dx_ax_57 = ((word16) cx_47 + 1) *32 ax_56;
	cup16 ax_58 = (word16) dx_ax_57;
	word16 dx_62 = SLICE(dx_ax_57, word16, 16);
	word16 ax_59 = ax_58 + 0x06;
	if (ax_58 < ~0x05 || dx_62 != 0x00)
		ax_59 = 0x00;
	return ax_59;
}
