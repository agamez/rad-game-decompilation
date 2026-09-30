// 11C8:03BB: void fn11C8_03BB(Register Eq_17 ds)
// Called from:
//      fn0800_0000
void fn11C8_03BB(Eq_17 ds)
{
	if (Mem7[ds:22902:byte] != 0x00)
	{
		fn11C8_02CC();
		fn11C8_02AB();
	}
}
