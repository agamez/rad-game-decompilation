// 0800:0619: Register Eq_17 fn0800_0619(Register Eq_17 ds)
// Called from:
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
Eq_17 fn0800_0619(Eq_17 ds)
{
	fn0800_005A(ds, 0x01CF, 0x0264, 0x01A7, 0x0204);
	Eq_17 ds_43;
	fn1AB8_1536(ds, 0x00, 0x00, 0x00, out ds_43);
	fn1AB8_14F4(ds_43, 0x01, 0x01);
	struct Eq_984 * cs;
	word16 ax_569;
	word16 dx_570;
	<unknown> Eq_998::* fp;
	if (!fn1EDA_0B24(&cs->t0605, SEQ(ds_43, 0x5ECE), out ax_569, out dx_570))
	{
		Eq_17 ptrLoc010A_491;
		ptrLoc010A_491.u3 = fp - 262;
		fn0C74_004B(Mem114[ds_43:22926:word32], ptrLoc010A_491);
		word16 dx_572;
		fn1EDA_0A39(0x03, fp - 6, ptrLoc010A_491, out dx_572);
	}
	else
	{
		word16 dx_571;
		fn1EDA_0A39(0x03, fp - 6, (char *) &cs->t0605 + 5, out dx_571);
	}
	cu8 bLoc06;
	if (bLoc06 < 0x02)
	{
		Eq_17 ptrLoc010A_502;
		ptrLoc010A_502.u3 = fp - 262;
		fn1EDA_0A1F((char *) &cs->t0605 + 9, ptrLoc010A_502);
		fn1EDA_0AAC(fp - 6, ptrLoc010A_502);
		word16 dx_573;
		fn1EDA_0A39(0x03, fp - 6, ptrLoc010A_502, out dx_573);
	}
	if (bLoc06 < 0x03)
	{
		Eq_17 ptrLoc010A_516;
		ptrLoc010A_516.u3 = fp - 262;
		fn1EDA_0A1F((char *) &cs->t0605 + 9, ptrLoc010A_516);
		fn1EDA_0AAC(fp - 6, ptrLoc010A_516);
		word16 dx_578;
		fn1EDA_0A39(0x03, fp - 6, ptrLoc010A_516, out dx_578);
	}
	fn1AB8_1C32(ds_43, 0x08);
	Eq_17 ptrLoc010E_533;
	ptrLoc010E_533.u3 = fp - 262;
	fn1EDA_0A1F((char *) &cs->t0605 + 11, ptrLoc010E_533);
	fn1EDA_0AAC(fp - 6, ptrLoc010E_533);
	byte ch_574;
	fn1AB8_1D82(ds_43, ptrLoc010E_533, 0x01AE, 0x0233, out ch_574);
	byte ch_575;
	fn1AB8_1D82(ds_43, SEQ(ds_43, 0x5ECE), 454, 0x0233, out ch_575);
	fn1AB8_1C32(ds_43, 11);
	Eq_17 ptrLoc010E_551;
	ptrLoc010E_551.u3 = fp - 262;
	fn1EDA_0A1F((char *) &cs->t0605 + 11, ptrLoc010E_551);
	fn1EDA_0AAC(fp - 6, ptrLoc010E_551);
	byte ch_576;
	fn1AB8_1D82(ds_43, ptrLoc010E_551, 0x01AF, 0x0234, out ch_576);
	byte ch_577;
	fn1AB8_1D82(ds_43, SEQ(ds_43, 0x5ECE), 455, 0x0234, out ch_577);
	return ds_43;
}
