// 11C8:0354: void fn11C8_0354(Register Eq_17 ds, Stack Eq_17 wArg04)
// Called from:
//      fn0800_031B
//      fn0C74_070D
//      fn0C74_076B
//      fn0C74_0A35
//      fn0C74_2BBD
//      fn0C74_2E5A
//      fn0C74_3236
//      fn0C74_3615
//      fn0C74_37C3
//      fn0C74_45CE
//      fn0C74_4999
void fn11C8_0354(Eq_17 ds, Eq_17 wArg04)
{
	byte bArg04 = (byte) wArg04;
	byte bArg05 = SLICE(wArg04, byte, 8);
	if (Mem7[ds:22902:byte] == 0x00)
		fn1E78_02C7(wArg04);
	else
	{
		fn11C8_02DB(bArg04, Mem7[ds:0x5975:byte] + 0xA0);
		fn11C8_02DB(bArg05 | 0x10, Mem23[ds:0x5975:byte] + 0xB0);
		fn11C8_0236(ds, 200);
	}
}
