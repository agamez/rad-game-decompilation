// 11C8:033B: Register word16 fn11C8_033B(Register Eq_17 ds)
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
//      fn11C8_0394
word16 fn11C8_033B(Eq_17 ds)
{
	word16 dx;
	if (Mem7[ds:22902:byte] == 0x00)
		fn1E78_02F4();
	else
		dx = fn11C8_0236(ds, 0x00);
	return dx;
}
