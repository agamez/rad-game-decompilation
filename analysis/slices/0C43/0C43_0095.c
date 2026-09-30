// 0C43:0095: Register word16 fn0C43_0095(Register word16 ax, Register Eq_17 ds, Stack Eq_17 wArg02, Register out (ptr16 Eq_19084) dsOut)
// Called from:
//      fn0C43_00B9
word16 fn0C43_0095(word16 ax, Eq_17 ds, Eq_17 wArg02, struct Eq_19084 & dsOut)
{
	fn1EDA_1051((byte) ax, ds, (word32) wArg02 + 0x0000FF2C);
	Eq_17 wLoc0C;
	Eq_17 wLoc0A;
	word16 dx_41;
	struct Eq_19084 * ds_40;
	fn1EDA_0254(ds, wLoc0C, wLoc0A, ~0x0E, Mem15[ds:22660:word32], out dx_41, out ds_40);
	dsOut = ds_40;
	return dx_41;
}
