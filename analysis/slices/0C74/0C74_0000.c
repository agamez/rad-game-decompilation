// 0C74:0000: Register byte fn0C74_0000(Register Eq_17 ds, Stack Eq_17 ptrArg04, Register out word16 dxOut)
// Called from:
//      fn0800_0147
//      fn0800_03F8
//      fn0800_11EF
//      fn0800_2401
//      fn0800_2827
//      fn0800_4168
//      fn0C74_03D4
byte fn0C74_0000(Eq_17 ds, Eq_17 ptrArg04, word16 & dxOut)
{
	<unknown> Eq_19965::* fp;
	word16 dx_115;
	fn1EDA_0A39(~0x00, fp - 0x0104, ptrArg04, out dx_115);
	word16 dx_53 = fn1E5F_00DE(ds, fp - 0x0130, 0x3F, fp - 0x0104);
	byte bLoc0105_91;
	if (Mem48[ds:47270:word16] != 0x00)
		bLoc0105_91 = 0x00;
	else
		bLoc0105_91 = 0x01;
	dxOut = dx_53;
	return bLoc0105_91;
}
