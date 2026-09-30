// 1EDA:00ED: Register (ptr16 Eq_62607) fn1EDA_00ED(Register Eq_17 ax, Register Eq_17 cx, Register Eq_17 bx)
// Called from:
//      fn1EDA_00E9
//      fn1EDA_098A
struct Eq_62607 * fn1EDA_00ED(Eq_17 ax, Eq_17 cx, Eq_17 bx)
{
	__sti();
	selector seg2014;
	seg2014->t5376 = ax;
	if ((cx | bx) == 0x00)
	{
		fn1EDA_011B(cx, bx, 8212);
		return;
	}
	else
	{
		fn1EDA_00FC(cx, bx, 8212);
		return;
	}
}
