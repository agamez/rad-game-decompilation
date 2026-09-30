// 1AB8:0887: Register byte fn1AB8_0887(Register Eq_17 ds, Stack uint16 wArg02, Stack Eq_17 ptrArg04, Stack Eq_17 ptrArg08, Stack Eq_17 ptrArg0C, Register out Eq_17 dsOut)
// Called from:
//      fn1AB8_097B
//      fn1AB8_1536
byte fn1AB8_0887(Eq_17 ds, uint16 wArg02, Eq_17 ptrArg04, Eq_17 ptrArg08, Eq_17 ptrArg0C, union Eq_17 & dsOut)
{
	<unknown> Eq_58454::* fp;
	word16 dx_368;
	fn1EDA_0A39(~0x00, fp - 0x0104, ptrArg0C, out dx_368);
	word16 dx_369;
	fn1EDA_0A39(~0x00, fp - 0x0204, ptrArg08, out dx_369);
	Mem69[ds:0xB818:word16] = ~0x02;
	ptrArg04.u3->t0000.u2 = (uint16) 0x00;
	Eq_17 ptrLoc030C_303;
	ptrLoc030C_303.u3 = fp - 772;
	fn1EDA_0A1F(fp - 0x0104, ptrLoc030C_303);
	fn1EDA_0AAC(fp - 0x0204, ptrLoc030C_303);
	fn1EDA_0FA2(ptrLoc030C_303, SEQ(ds, 46794));
	word16 dx_370;
	fn1EDA_0FD0(ds, 0x01, SEQ(ds, 46794), out dx_370);
	byte bLoc03_295 = 0x00;
	if (fn1EDA_04A2(ds) != 0x00)
	{
		byte bLoc0104;
		if (bLoc0104 == 0x00)
			goto l1AB8_096D;
		fn1EDA_0FA2(fp - 0x0204, SEQ(ds, 46794));
		word16 dx_371;
		fn1EDA_0FD0(ds, 0x01, SEQ(ds, 46794), out dx_371);
		if (fn1EDA_04A2(ds) != 0x00)
		{
l1AB8_096D:
			dsOut = ds;
			return bLoc03_295;
		}
	}
	Mem221[ds:0xB818:word16] = 0x00;
	ptrArg04.u3->t0000.u2 = (uint16) fn1EDA_116A(ds, SEQ(ds, 46794), out ds);
	if (ptrArg04.u3->t0000.u2 > ~0x00)
	{
		Mem256[ds:0xB818:word16] = wArg02;
		fn1EDA_1051((byte) wArg02, ds, SEQ(ds, 46794));
	}
	else
		bLoc03_295 = 0x01;
	goto l1AB8_096D;
}
