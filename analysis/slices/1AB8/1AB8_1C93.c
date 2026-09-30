// 1AB8:1C93: Register word16 fn1AB8_1C93(Register Eq_17 ds)
// Called from:
//      fn1AB8_0BAE
word16 fn1AB8_1C93(Eq_17 ds)
{
	Mem7[ds:0xB820:segptr32]();
	word16 cx_14;
	return cx_14 - 0x01;
}
