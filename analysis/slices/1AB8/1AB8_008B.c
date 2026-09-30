// 1AB8:008B: Register Eq_17 fn1AB8_008B(Register Eq_17 ds)
// Called from:
//      fn1AB8_0AEE
Eq_17 fn1AB8_008B(Eq_17 ds)
{
	struct Eq_57756 * cs;
	if (Mem7[ds:0xB84E:byte] == 0x00)
	{
		Eq_17 ptrLoc06_149 = SEQ(ds, ~0x4643);
		Eq_481 cx_87;
		fn1EDA_08CE(ds, 0x00, (char *) cs + 54, ptrLoc06_149, out cx_87);
		byte ch_160;
		selector ds_161;
		fn1EDA_04A9(fn1EDA_0848(0x00, cx_87, ds, ptrLoc06_149), ~0x4643, ds, out ch_160, out ds_161);
	}
	else
	{
		Eq_17 ptrLoc06_142 = SEQ(ds, ~0x4643);
		Eq_481 cx_34;
		fn1EDA_08CE(ds, 0x00, &cs->t006A, ptrLoc06_142, out cx_34);
		byte ch_157;
		selector ds_158;
		fn1EDA_04A9(fn1EDA_0848(0x00, cx_34, ds, ptrLoc06_142), ~0x4643, ds, out ch_157, out ds_158);
	}
	return fn1EDA_00E9(0x01);
}
