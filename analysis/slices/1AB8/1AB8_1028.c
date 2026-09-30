// 1AB8:1028: void fn1AB8_1028(Register Eq_17 ds)
// Called from:
//      fn0800_0024
//      fn0C74_007C
//      fn1229_0000
//      fn1229_0AA8
//      fn133F_014B
void fn1AB8_1028(Eq_17 ds)
{
	Eq_17 ax_11 = Mem7[ds:47202:word16];
	Eq_17 dx_12 = Mem7[ds:47204:word16];
	fn1AB8_1175(ds, 0x00, 0x00);
	fn1AB8_1B3E(ds, Mem40[ds:0xB858:word16] - Mem40[ds:47188:word16], Mem36[ds:0xB856:word16] - Mem36[ds:0xB852:word16], 0x00, 0x00);
	if (ax_11 == 0x0C)
		fn1AB8_11A0(ds, dx_12, SEQ(ds, 0xB866));
	else
		fn1AB8_1175(ds, dx_12, ax_11);
	fn1AB8_108B(ds, 0x00, 0x00);
}
