// 1EDA:04B7: void fn1EDA_04B7(Register cup16 ax, Register ci16 dx, Register (memptr Eq_17 Eq_57292) di, Stack Eq_17 wArg00, Stack Eq_17 psegArg02)
// Called from:
//      fn13C8_0111
void fn1EDA_04B7(cup16 ax, ci16 dx, struct Eq_57292 Eq_17::* di, Eq_17 wArg00, Eq_17 psegArg02)
{
	if ((dx > (psegArg02->*di).w0002 || dx >= (psegArg02->*di).w0002 && ax >= (psegArg02->*di).w0000) && (dx < (psegArg02->*di).w0006 || dx <= (psegArg02->*di).w0006 && ax <= (psegArg02->*di).w0004))
		return;
	word16 cx_96;
	word16 dx_97;
	word16 bx_98;
	selector ds_99;
	fn1EDA_00E2(0xC9, wArg00, psegArg02, out cx_96, out dx_97, out bx_98, out ds_99);
}
