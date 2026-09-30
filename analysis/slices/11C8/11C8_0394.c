// 11C8:0394: void fn11C8_0394(Register Eq_17 ds)
// Called from:
//      fn0800_4255
void fn11C8_0394(Eq_17 ds)
{
	fn11C8_0092(ds);
	if (Mem7[ds:22902:byte] != 0x00)
	{
		Mem24[ds:0x5975:byte] = 0x00;
		fn11C8_02AB();
		fn11C8_02DB(0x10, 0x01);
		fn11C8_02F0();
		fn11C8_033B(ds);
	}
}
