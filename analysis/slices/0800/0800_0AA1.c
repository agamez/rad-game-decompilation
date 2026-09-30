// 0800:0AA1: Register word16 fn0800_0AA1(Register Eq_17 ds, Register out Eq_17 dsOut)
// Called from:
//      fn0800_0BEC
//      fn0800_0C71
word16 fn0800_0AA1(Eq_17 ds, union Eq_17 & dsOut)
{
	<unknown> Eq_17::* fp;
	Eq_17 ss;
	Eq_17 ptrLoc010A_233 = SEQ(ss, fp - 262);
	fn0C74_004B(Mem14[ds:22748:word32], ptrLoc010A_233);
	word16 dx_257;
	fn1EDA_0A39(0x02, SEQ(ss, fp - 6), ptrLoc010A_233, out dx_257);
	cu8 bLoc06;
	if (bLoc06 < 0x02)
	{
		Eq_17 ptrLoc010A_243 = SEQ(ss, fp - 262);
		struct Eq_2116 * cs;
		fn1EDA_0A1F(&cs->t0A9F, ptrLoc010A_243);
		fn1EDA_0AAC(SEQ(ss, fp - 6), ptrLoc010A_243);
		word16 dx_262;
		fn1EDA_0A39(0x02, SEQ(ss, fp - 6), ptrLoc010A_243, out dx_262);
	}
	word16 bp_122;
	Eq_17 ds_126;
	fn1206_0066(ds, out bp_122, out ds_126);
	Eq_481 sp_130;
	sp_130.u0 = <invalid>;
	ss->*((word16) sp_130 - 2) = 0x024B;
	ss->*((word16) sp_130 - 4) = 0x0192;
	ss->*((word16) sp_130 - 6) = 0x025C;
	ss->*((word16) sp_130 - 8) = 411;
	fn0800_005A(ds_126, ss->*((word16) sp_130 - 8), ss->*((word16) sp_130 - 6), ss->*((word16) sp_130 - 4), ss->*((word16) sp_130 - 2));
	ss->*((word16) sp_130 - 2) = 0x08;
	fn1AB8_1C32(ds_126, ss->*((word16) sp_130 - 2));
	ss->*((word16) sp_130 - 2) = 595;
	ss->*((word16) sp_130 - 4) = 0x0196;
	ss->*((word16) sp_130 - 6) = ss;
	ss->*((word16) sp_130 - 8) = bp_122 - 4;
	byte ch_258;
	fn1AB8_1D82(ds_126, ss->*((word16) sp_130 - 8), ss->*((word16) sp_130 - 4), ss->*((word16) sp_130 - 2), out ch_258);
	ss->*((word16) sp_130 - 2) = 0x0A;
	fn1AB8_1C32(ds_126, ss->*((word16) sp_130 - 2));
	ss->*((word16) sp_130 - 2) = 0x0254;
	ss->*((word16) sp_130 - 4) = 0x0197;
	ss->*((word16) sp_130 - 6) = ss;
	ss->*((word16) sp_130 - 8) = bp_122 - 4;
	byte ch_259;
	fn1AB8_1D82(ds_126, ss->*((word16) sp_130 - 8), ss->*((word16) sp_130 - 4), ss->*((word16) sp_130 - 2), out ch_259);
	byte ch_260;
	word16 dx_261;
	word16 Eq_17::* bp_206;
	Eq_17 ds_210;
	fn1206_0038(ds_126, out ch_260, out dx_261, out bp_206, out ds_210);
	Eq_481 sp_214;
	sp_214.u0 = <invalid>;
	ss->*((word16) sp_214 - 2) = 0x00;
	fn1AB8_1C32(ds_210, ss->*((word16) sp_214 - 2));
	word16 bp_225 = ss->*bp_206;
	dsOut = ds_210;
	return bp_225;
}
