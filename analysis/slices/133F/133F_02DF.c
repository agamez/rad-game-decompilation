// 133F:02DF: void fn133F_02DF(Register Eq_17 ds, Stack Eq_17 ptrArg04, Stack uint8 bArg08)
// Called from:
//      fn133F_0352
void fn133F_02DF(Eq_17 ds, Eq_17 ptrArg04, uint8 bArg08)
{
	byte Eq_55940::* fp;
	word16 dx_170;
	fn1EDA_0A39(~0x00, fp - 0x0102, ptrArg04, out dx_170);
	uint8 bLoc0102;
	while ((fp - 0x0102)[(uint16) bLoc0102] == 0x20)
	{
		Eq_17 ptrLoc0206_160;
		ptrLoc0206_160.u3 = fp - 0x0202;
		fn1EDA_0A6B((uint16) bLoc0102 - 0x01, 0x01, fp - 0x0102, ptrLoc0206_160);
		word16 dx_172;
		fn1EDA_0A39(~0x00, fp - 0x0102, ptrLoc0206_160, out dx_172);
	}
	word16 dx_171;
	fn1EDA_0A39(~0x00, SEQ(ds, ((uint16) bArg08 << 0x08) + 28138), fp - 0x0102, out dx_171);
}
