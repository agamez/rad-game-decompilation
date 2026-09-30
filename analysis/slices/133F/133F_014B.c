// 133F:014B: Register byte fn133F_014B(Register Eq_17 ds, Stack Eq_17 ptrArg04, Stack Eq_17 wArg08, Stack Eq_17 wArg0A, Stack Eq_17 wArg0C, Stack Eq_17 wArg0E, Register out word16 dxOut, Register out Eq_17 dsOut)
// Called from:
//      fn133F_026B
//      fn133F_0352
byte fn133F_014B(Eq_17 ds, Eq_17 ptrArg04, Eq_17 wArg08, Eq_17 wArg0A, Eq_17 wArg0C, Eq_17 wArg0E, word16 & dxOut, union Eq_17 & dsOut)
{
	<unknown> Eq_55730::* fp;
	word16 dx_296;
	fn1EDA_0A39(~0x00, fp - 0x0102, ptrArg04, out dx_296);
	fn1AB8_14F4(ds, 0x01, 0x01);
	Eq_17 ds_65;
	fn1AB8_1536(ds, wArg08, 0x00, wArg0A, out ds_65);
	fn1AB8_0F93(ds_65, 0x01, &wArg0C.u3->t0000.u0 + ((fn1AB8_1783(ds_65, fp - 0x0102) >> 0x01) + 0x01), &wArg0E.u3->t0000.u0 + ((fn1AB8_1E0B(ds_65, fp - 0x0102) >> 0x01) + 0x01), wArg0C - ((fn1AB8_1783(ds_65, fp - 0x0102) >> 0x01) + 0x01), wArg0E - ((fn1AB8_1E0B(ds_65, fp - 0x0102) >> 0x01) + 0x01));
	fn1AB8_1028(ds_65);
	word16 dx_214 = fn1AB8_0F93(ds_65, 0x01, fn1AB8_10E1(ds_65), fn1AB8_10CE(ds_65), 0x00, 0x00);
	byte ch_297;
	fn1AB8_1D82(ds_65, fp - 0x0102, wArg0C, wArg0E, out ch_297);
	dxOut = dx_214;
	dsOut = ds_65;
	return 0x00;
}
