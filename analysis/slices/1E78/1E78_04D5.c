// 1E78:04D5: void fn1E78_04D5(Register cu8 dh, Register Eq_17 ds)
// Called from:
//      fn1E78_047C
void fn1E78_04D5(cu8 dh, Eq_17 ds)
{
	word16 dx;
	dh = SLICE(dx, byte, 8);
	if (dh + 0x01 >u Mem0[ds:~0x474C:byte])
		fn1E78_0609();
}
