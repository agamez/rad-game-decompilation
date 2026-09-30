// 1EDA:096F: Sequence word32 fn1EDA_096F(Register uint16 ax, Register Eq_16496 cx, Register uint16 dx, Register uint16 bx)
// Called from:
//      fn0800_3BF2
//      fn0800_3C72
//      fn0C74_0FA1
//      fn0C74_1B3B
//      fn0C74_1F08
//      fn0C74_2AD9
//      fn1AB8_11FB
word32 fn1EDA_096F(uint16 ax, Eq_16496 cx, uint16 dx, uint16 bx)
{
	uint32 dx_ax_9 = cx *32 ax;
	return SEQ((word16) dx_ax_9 + bx * ax + cx * dx, SLICE(dx_ax_9, word16, 16));
}
