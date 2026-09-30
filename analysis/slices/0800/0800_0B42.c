// 0800:0B42: Register word16 fn0800_0B42(Register Eq_17 ds, Register out (ptr16 Eq_2314) dsOut)
// Called from:
//      fn0800_0BEC
//      fn0800_0C71
word16 fn0800_0B42(Eq_17 ds, struct Eq_2314 & dsOut)
{
	<unknown> Eq_17::* fp;
	Eq_17 ss;
	Eq_17 ptrLoc010A_234 = SEQ(ss, fp - 262);
	fn0C74_004B(Mem14[ds:22732:word32], ptrLoc010A_234);
	word16 dx_256;
	fn1EDA_0A39(0x02, SEQ(ss, fp - 6), ptrLoc010A_234, out dx_256);
	cu8 bLoc06;
	if (bLoc06 < 0x02)
	{
		Eq_17 ptrLoc010A_244 = SEQ(ss, fp - 262);
		struct Eq_2328 * cs;
		fn1EDA_0A1F(&cs->t0B40, ptrLoc010A_244);
		fn1EDA_0AAC(SEQ(ss, fp - 6), ptrLoc010A_244);
		word16 dx_261;
		fn1EDA_0A39(0x02, SEQ(ss, fp - 6), ptrLoc010A_244, out dx_261);
	}
	word16 bp_122;
	Eq_17 ds_126;
	fn1206_0066(ds, out bp_122, out ds_126);
	Eq_481 sp_130;
	sp_130.u0 = <invalid>;
	ss->*((word16) sp_130 - 2) = 0x0233;
	ss->*((word16) sp_130 - 4) = 0x0192;
	ss->*((word16) sp_130 - 6) = 0x0244;
	ss->*((word16) sp_130 - 8) = 411;
	fn0800_005A(ds_126, ss->*((word16) sp_130 - 8), ss->*((word16) sp_130 - 6), ss->*((word16) sp_130 - 4), ss->*((word16) sp_130 - 2));
	ss->*((word16) sp_130 - 2) = 0x08;
	fn1AB8_1C32(ds_126, ss->*((word16) sp_130 - 2));
	ss->*((word16) sp_130 - 2) = 0x023B;
	ss->*((word16) sp_130 - 4) = 0x0196;
	ss->*((word16) sp_130 - 6) = ss;
	ss->*((word16) sp_130 - 8) = bp_122 - 4;
	byte ch_257;
	fn1AB8_1D82(ds_126, ss->*((word16) sp_130 - 8), ss->*((word16) sp_130 - 4), ss->*((word16) sp_130 - 2), out ch_257);
	ss->*((word16) sp_130 - 2) = 0x0A;
	fn1AB8_1C32(ds_126, ss->*((word16) sp_130 - 2));
	ss->*((word16) sp_130 - 2) = 0x023C;
	ss->*((word16) sp_130 - 4) = 0x0197;
	ss->*((word16) sp_130 - 6) = ss;
	ss->*((word16) sp_130 - 8) = bp_122 - 4;
	byte ch_258;
	fn1AB8_1D82(ds_126, ss->*((word16) sp_130 - 8), ss->*((word16) sp_130 - 4), ss->*((word16) sp_130 - 2), out ch_258);
	ss->*((word16) sp_130 - 2) = 0x00;
	fn1AB8_1C32(ds_126, ss->*((word16) sp_130 - 2));
	byte ch_259;
	word16 dx_260;
	word16 Eq_17::* bp_212;
	struct Eq_2314 * ds_216;
	fn1206_0038(ds_126, out ch_259, out dx_260, out bp_212, out ds_216);
	word16 bp_226 = ss->*bp_212;
	dsOut = ds_216;
	return bp_226;
}
