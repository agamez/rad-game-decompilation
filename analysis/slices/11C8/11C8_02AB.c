// 11C8:02AB: void fn11C8_02AB()
// Called from:
//      fn11C8_0394
//      fn11C8_03BB
void fn11C8_02AB()
{
	byte bLoc03_43 = 0x01;
	while (true)
	{
		fn11C8_0282(bLoc03_43);
		fn11C8_0296(0x00);
		if (bLoc03_43 == ~0x0A)
			break;
		++bLoc03_43;
	}
}
