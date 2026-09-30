// 0C74:00B2: void fn0C74_00B2(Register Eq_17 ds, Stack uint8 bArg04)
// Called from:
//      fn0800_0147
//      fn0800_03F8
//      fn0C74_03D4
void fn0C74_00B2(Eq_17 ds, uint8 bArg04)
{
	fn1AB8_1B3E(ds, 0x01DF, CONVERT(bArg04, uint8, uint16) + Mem14[ds:22754:word16], 0x01D5, Mem7[ds:22754:word16]);
	Mem33[ds:22754:word16] = Mem23[ds:22754:word16] + CONVERT(bArg04, uint8, uint16);
}
