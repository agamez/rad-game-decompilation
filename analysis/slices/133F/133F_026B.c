// 133F:026B: Register byte fn133F_026B(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Register out word16 dxOut, Register out (ptr16 Eq_55929) dsOut)
// Called from:
//      fn133F_0528
byte fn133F_026B(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06, word16 & dxOut, struct Eq_55929 & dsOut)
{
	<unknown> Eq_55864::* fp;
	fn1EDA_0F26(0x02, fp - 6, 0x02, CONVERT(CONVERT(Mem7[ds:0x6CC4:word16] - Mem7[ds:0x6CC8:word16], int16, int32) /16 Mem7[ds:0x6CC0:word16], uint16, uint32));
	fn1EDA_0F26(0x02, fp - 0x0A, 0x02, CONVERT(CONVERT(Mem35[ds:0x6CC6:word16] - Mem35[ds:0x6CCA:word16], int16, int32) /16 Mem35[ds:0x6CC2:word16], uint16, uint32));
	Eq_17 ptrLoc0116_200;
	ptrLoc0116_200.u3 = fp - 266;
	fn1EDA_0A1F(fp - 6, ptrLoc0116_200);
	struct Eq_55914 * cs;
	fn1EDA_0AAC(&cs->t0269, ptrLoc0116_200);
	fn1EDA_0AAC(fp - 0x0A, ptrLoc0116_200);
	word16 dx_162;
	struct Eq_55929 * ds_161;
	fn133F_014B(ds, ptrLoc0116_200, 0x01, 0x00, wArg04, wArg06, out dx_162, out ds_161);
	dxOut = dx_162;
	dsOut = ds_161;
	return 0x00;
}
