// 11C8:0282: void fn11C8_0282(Stack byte bArg02)
// Called from:
//      fn11C8_02AB
//      fn11C8_02CC
//      fn11C8_02DB
void fn11C8_0282(byte bArg02)
{
	__out<byte>(0x0388, bArg02);
	word16 cx_11;
	for (cx_11 = 0x06; cx_11 != 0x00; --cx_11)
		__in<byte>(0x0388);
}
