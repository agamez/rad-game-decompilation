// 1AB8:0E88: void fn1AB8_0E88(Register Eq_17 ds)
// Called from:
//      fn0800_0000
//      fn0C74_03D4
//      fn13E2_0193
//      fn1AB8_0EB5
void fn1AB8_0E88(Eq_17 ds)
{
	fn1AB8_18E3(ds);
	if ((Mem7[ds:47140:word16] | Mem7[ds:47142:word16]) == 0x00)
	{
		struct seg1AB8_t * dx_25 = Mem7[ds:0xB822:word16];
		Mem26[ds:47140:word16] = Mem7[ds:0xB820:word16];
		Mem27[ds:47142:word16] = dx_25;
		Mem30[ds:0xB820:word16] = 0x8B;
		Mem31[ds:0xB822:word16] = 0x1AB8;
	}
}
