// 1AB8:1C4A: Register word16 fn1AB8_1C4A(Register Eq_17 ds)
// Called from:
//      fn1AB8_0AEE
//      fn1AB8_11A0
word16 fn1AB8_1C4A(Eq_17 ds)
{
	Mem7[ds:0xB820:segptr32]();
	word16 cx_17;
	return cx_17;
}
