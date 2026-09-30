// 0800:04E3: Register byte fn0800_04E3(Register Eq_17 ds, Register out Eq_17 dsOut)
// Called from:
//      fn0800_09C2
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
byte fn0800_04E3(Eq_17 ds, union Eq_17 & dsOut)
{
	fn0800_005A(ds, 0x0193, 0x01A0, 393, 288);
	Eq_17 ds_43;
	fn1AB8_1536(ds, 0x01, 0x00, 0x00, out ds_43);
	fn1AB8_14F4(ds_43, 0x01, 0x01);
	fn1AB8_1C32(ds_43, 0x08);
	<unknown> Eq_827::* fp;
	if (Mem62[ds_43:0x53DB:byte] >u 0x00)
	{
		Eq_17 ptrLoc010A_404;
		ptrLoc010A_404.u3 = fp - 0x0102;
		fn0C74_004B(CONVERT(Mem77[ds_43:0x53DB:byte], uint8, uint32), ptrLoc010A_404);
		byte ch_520;
		fn1AB8_1D82(ds_43, ptrLoc010A_404, 0x018D, 303, out ch_520);
	}
	if (Mem114[ds_43:0x53DC:byte] >u 0x00)
	{
		Eq_17 ptrLoc010A_412;
		ptrLoc010A_412.u3 = fp - 0x0102;
		fn0C74_004B(CONVERT(Mem128[ds_43:0x53DC:byte], uint8, uint32), ptrLoc010A_412);
		byte ch_521;
		fn1AB8_1D82(ds_43, ptrLoc010A_412, 0x018D, 355, out ch_521);
	}
	if (Mem165[ds_43:0x53DE:byte] >u 0x00)
	{
		Eq_17 ptrLoc010A_420;
		ptrLoc010A_420.u3 = fp - 0x0102;
		fn0C74_004B(CONVERT(Mem179[ds_43:0x53DE:byte], uint8, uint32), ptrLoc010A_420);
		byte ch_522;
		fn1AB8_1D82(ds_43, ptrLoc010A_420, 0x018D, 0x0197, out ch_522);
	}
	fn1AB8_1C32(ds_43, 0x0E);
	if (Mem218[ds_43:0x53DB:byte] >u 0x00)
	{
		Eq_17 ptrLoc010A_430;
		ptrLoc010A_430.u3 = fp - 0x0102;
		fn0C74_004B(CONVERT(Mem235[ds_43:0x53DB:byte], uint8, uint32), ptrLoc010A_430);
		byte ch_523;
		fn1AB8_1D82(ds_43, ptrLoc010A_430, 0x018E, 0x0130, out ch_523);
	}
	if (Mem272[ds_43:0x53DC:byte] >u 0x00)
	{
		Eq_17 ptrLoc010A_438;
		ptrLoc010A_438.u3 = fp - 0x0102;
		fn0C74_004B(CONVERT(Mem286[ds_43:0x53DC:byte], uint8, uint32), ptrLoc010A_438);
		byte ch_524;
		fn1AB8_1D82(ds_43, ptrLoc010A_438, 0x018E, 0x0164, out ch_524);
	}
	if (Mem323[ds_43:0x53DE:byte] >u 0x00)
	{
		Eq_17 ptrLoc010A_446;
		ptrLoc010A_446.u3 = fp - 0x0102;
		fn0C74_004B(CONVERT(Mem337[ds_43:0x53DE:byte], uint8, uint32), ptrLoc010A_446);
		byte ch_525;
		fn1AB8_1D82(ds_43, ptrLoc010A_446, 0x018E, 0x0198, out ch_525);
	}
	fn1AB8_1C32(ds_43, 0x00);
	dsOut = ds_43;
	return 0x00;
}
