// 11C8:0296: void fn11C8_0296(Stack byte bArg02)
// Called from:
//      fn11C8_02AB
//      fn11C8_02CC
//      fn11C8_02DB
void fn11C8_0296(byte bArg02)
{
	__out<byte>(0x0389, bArg02);
	word16 cx_11;
	for (cx_11 = 0x35; cx_11 != 0x00; --cx_11)
		__in<byte>(0x0388);
}
