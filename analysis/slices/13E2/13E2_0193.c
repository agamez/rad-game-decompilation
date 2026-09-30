// 13E2:0193: Register Eq_17 fn13E2_0193(Register Eq_17 ds, Stack Eq_17 ptrArg04)
// Called from:
//      fn0800_0147
//      fn0800_03F8
//      fn0800_4255
//      fn13E2_0220
Eq_17 fn13E2_0193(Eq_17 ds, Eq_17 ptrArg04)
{
	<unknown> Eq_57633::* fp;
	word16 dx_228;
	fn1EDA_0A39(~0x00, fp - 0x0102, ptrArg04, out dx_228);
	fn1AB8_0EB5(ds);
	fn1AB8_0E88(ds);
	word16 dx_229;
	fn1E78_016B(ds, Mem23[ds:47276:word16], out dx_229);
	Eq_17 ptrLoc020A_215;
	ptrLoc020A_215.u3 = fp - 0x0202;
	fn1EDA_0A1F(fp - 0x0102, ptrLoc020A_215);
	struct Eq_57662 * cs;
	fn1EDA_0AAC(&cs->t0191, ptrLoc020A_215);
	fn1EDA_0AAC(&cs->t0191, ptrLoc020A_215);
	fn1EDA_0AAC(&cs->t0191, ptrLoc020A_215);
	Eq_17 ptrLoc0206_227 = SEQ(ds, ~0x4643);
	Eq_481 cx_160;
	fn1EDA_08CE(ds, 0x00, ptrLoc020A_215, ptrLoc0206_227, out cx_160);
	fn1EDA_0848(0x00, cx_160, ds, ptrLoc0206_227);
	return fn1EDA_00E9(0x00);
}
