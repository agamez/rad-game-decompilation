// 0800:09C2: Register byte fn0800_09C2(Register Eq_17 ds, Stack Eq_17 bArg02, Register out Eq_526 bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0800_184C
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
byte fn0800_09C2(Eq_17 ds, Eq_17 bArg02, union Eq_526 & bpOut, union Eq_17 & dsOut)
{
	uint8 al_223;
	Mem12[ds:22756:byte] = bArg02;
	if (bArg02 >= 0x00 && bArg02 <= 0x08)
		fn0800_04CC(bArg02 << 0x01);
	else if (bArg02 >= 0x09 && bArg02 <= 0x10)
		fn0800_04CC(bArg02 - 0x09 << 0x01);
	fn1AB8_1C32(ds, 11);
	struct Eq_1653 Eq_17::* bp_236;
	Eq_17 ds_198;
	fn1206_0066(ds, out bp_236, out ds_198);
	Eq_481 sp_92;
	sp_92.u0 = <invalid>;
	selector ss;
	(ss->*((word16) sp_92 - 2)).u1 = (ss->*bp_236).tFFFE.u2;
	ss->*((word16) sp_92 - 4) = 0x0198;
	segptr32 es_di_108 = (*((word32) ds_198 + 0x00005388))[(uint16) (ss->*bp_236).t0004.u0];
	ss->*((word16) sp_92 - 6) = SLICE(es_di_108, selector, 16);
	ss->*((word16) sp_92 - 8) = (word16) es_di_108;
	ss->*((word16) sp_92 - 0x0A) = 0x00;
	fn1AB8_13D7(ds_198, ss->*((word16) sp_92 + 0x0A), ss->*((word16) sp_92 - 8), ss->*((word16) sp_92 - 4), ss->*((word16) sp_92 - 2));
	ss->*((word16) sp_92 - 2) = 0x00;
	ss->*((word16) sp_92 - 4) = 0x00;
	ss->*((word16) sp_92 - 6) = 0x01;
	fn1AB8_10F4(ds_198, ss->*((word16) sp_92 - 6), ss->*((word16) sp_92 - 4), ss->*((word16) sp_92 - 2));
	ss->*((word16) sp_92 - 2) = 0x00;
	fn1AB8_1C32(ds_198, ss->*((word16) sp_92 - 2));
	ss->*((word16) sp_92 - 2) = (ss->*bp_236).tFFFE.u2 - 0x01;
	ss->*((word16) sp_92 - 4) = 0x0197;
	ss->*((word16) sp_92 - 6) = (ss->*bp_236).tFFFE.u2 + 44;
	ss->*((word16) sp_92 - 8) = 0x01C4;
	fn1AB8_112E(ds_198, ss->*((word16) sp_92 - 8), ss->*((word16) sp_92 - 6), ss->*((word16) sp_92 - 4), ss->*((word16) sp_92 - 2));
	(ss->*((word16) sp_92 - 2)).u1 = (uint16) (ss->*bp_236).t0004.u0;
	Eq_17 cs;
	ss->*((word16) sp_92 - 4) = cs;
	ss->*((word16) sp_92 - 6) = 2434;
	selector es_297;
	if (!fn1EDA_0CD4(ss->*((word16) sp_92 - 6), ss->*((word16) sp_92 - 2), out es_297))
		fn0800_04E3(ds_198, out ds_198);
	(ss->*((word16) sp_92 - 2)).u1 = (uint16) (ss->*bp_236).t0004.u0;
	ss->*((word16) sp_92 - 4) = cs;
	ss->*((word16) sp_92 - 6) = 2466;
	uint16 ax_235 = (uint16) al_223;
	selector es_298;
	if (!fn1EDA_0CD4(ss->*((word16) sp_92 - 6), ss->*((word16) sp_92 - 2), out es_298))
	{
		byte ch_299;
		word16 dx_300;
		ax_235 = (uint16) fn1206_0038(ds_198, out ch_299, out dx_300, out bp_236, out ds_198);
	}
	bpOut.u1 = (ss->*bp_236).t0000.u1;
	dsOut = ds_198;
	return SLICE(ax_235, byte, 8);
}
