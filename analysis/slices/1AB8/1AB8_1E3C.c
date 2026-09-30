// 1AB8:1E3C: Register uint16 fn1AB8_1E3C(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Register out uint8 dlOut)
// Called from:
//      fn0800_0877
//      fn0800_08E9
//      fn0C74_05B8
//      fn0C74_076B
//      fn0C74_0A35
//      fn0C74_0FA1
//      fn0C74_1B3B
//      fn0C74_1F08
//      fn0C74_2BBD
//      fn0C74_2E5A
//      fn0C74_3236
//      fn0C74_3615
//      fn0C74_37C3
//      fn0C74_396E
//      fn0C74_3F74
//      fn0C74_45CE
//      fn0C74_4999
//      fn0C74_4DAC
//      fn0C74_4FD7
//      fn0C74_51B2
//      fn0C74_5258
//      fn0C74_542B
//      fn0C74_54B1
//      fn0C74_54F0
uint16 fn1AB8_1E3C(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06, uint8 & dlOut)
{
	Mem7[ds:0xB820:segptr32]();
	uint8 dl_16;
	dlOut = dl_16;
	return (uint16) dl_16;
}
