// 1EDA:01CD: void fn1EDA_01CD(Register Eq_17 ax)
// Called from:
//      fn1EDA_00E9
void fn1EDA_01CD(Eq_17 ax)
{
	byte ah_8 = SLICE(ax, byte, 8);
	fn1EDA_01D4(ah_8);
	fn1EDA_01D4((byte) ax);
}
