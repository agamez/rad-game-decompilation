// 0C74:06B7: Register Eq_17 fn0C74_06B7(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06)
// Called from:
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
//      fn0800_3D9D
Eq_17 fn0C74_06B7(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06)
{
	Mem10[ds:22888:word16] = 0x01;
	Mem11[ds:22707:byte] = 0x00;
	Mem12[ds:22705:byte] = 0x01;
	Mem14[ds:22708:word16] = wArg06;
	Mem16[ds:22712:word16] = wArg04;
	Mem19[ds:22710:word16] = wArg06 + 0x2B;
	Mem23[ds:22714:word16] = wArg04 + 0x2B;
	Mem24[ds:22891:byte] = 44;
	Mem25[ds:22890:byte] = 44;
	fn1AB8_13D7(ds, 0x00, Mem31[ds:0x58E8:segptr32], wArg04, wArg06);
	Eq_17 ds_58;
	fn0C74_05B8(ds, out ds_58);
	return ds_58;
}
