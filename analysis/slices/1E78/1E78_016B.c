// 1E78:016B: Register uint16 fn1E78_016B(Register Eq_17 ds, Stack Eq_17 wArg04, Register out word16 dxOut)
// Called from:
//      fn0800_0000
//      fn0800_2C0C
//      fn0C74_03D4
//      fn13E2_0193
//      fn1E78_0143
uint16 fn1E78_016B(Eq_17 ds, Eq_17 wArg04, word16 & dxOut)
{
	fn1E78_0097(wArg04);
	word16 dx_22;
	fn1E78_00E5(ds, out dx_22);
	uint8 al_27 = Mem0[ds:0xB8B8:byte];
	Mem28[ds:47278:byte] = al_27;
	dxOut = dx_22;
	return (uint16) al_27;
}
