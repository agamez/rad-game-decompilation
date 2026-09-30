// 1AB8:1AC2: void fn1AB8_1AC2(Register Eq_17 ds)
// Called from:
//      fn1AB8_0F80
void fn1AB8_1AC2(Eq_17 ds)
{
	Mem7[ds:0xB820:segptr32]();
}
