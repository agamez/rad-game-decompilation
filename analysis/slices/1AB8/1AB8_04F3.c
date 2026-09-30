// 1AB8:04F3: Register Eq_17 fn1AB8_04F3(Register Eq_17 ds)
// Called from:
//      fn133F_0056
//      fn13E2_0001
Eq_17 fn1AB8_04F3(Eq_17 ds)
{
	Eq_17 ax_11 = Mem7[ds:0xB818:word16];
	Mem17[ds:0xB818:word16] = 0x00;
	return ax_11;
}
