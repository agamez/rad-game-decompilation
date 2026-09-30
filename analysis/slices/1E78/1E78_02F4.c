// 1E78:02F4: Register byte fn1E78_02F4()
// Called from:
//      fn11C8_033B
//      fn1229_0486
//      fn1229_0DCC
byte fn1E78_02F4()
{
	byte al_4 = __in<byte>(0x61);
	__out<byte>(0x61, al_4 & 252);
	return al_4 & 252;
}
