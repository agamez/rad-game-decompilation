// 1EDA:098A: Register int16 fn1EDA_098A(Sequence Eq_2449 bx_cx, Sequence Eq_17 dx_ax, Stack Eq_17 wArg00, Stack Eq_17 wArg02, Register out int16 cxOut, Register out int16 dxOut, Register out int16 bxOut, Register out (ptr16 Eq_2469) dsOut)
// Called from:
//      fn0800_0C71
//      fn0C74_02D8
//      fn0C74_0FA1
//      fn0C74_1B3B
//      fn0C74_1F08
//      fn0C74_2AD9
//      fn1AB8_11FB
//      fn1EDA_116A
int16 fn1EDA_098A(Eq_2449 bx_cx, Eq_17 dx_ax, Eq_17 wArg00, Eq_17 wArg02, int16 & cxOut, int16 & dxOut, int16 & bxOut, struct Eq_2469 & dsOut)
{
	ui32 DP_125;
	struct Eq_2469 * ds_23;
	int16 bx_21;
	int16 dx_24;
	int16 cx_22;
	ci16 bx = SLICE(bx_cx, word16, 16);
	int16 dx = SLICE(dx_ax, word16, 16);
	int16 ax = (word16) dx_ax;
	if (bx_cx == 0x00)
	{
		int16 ax_20 = fn1EDA_00E2(200, wArg00, wArg02, out cx_22, out dx_24, out bx_21, out ds_23);
		cxOut = cx_22;
		dxOut = dx_24;
		bxOut = bx_21;
		dsOut = ds_23;
		return ax_20;
	}
	word16 v13_37 = (word16) (cond(bx) | DP_125);
	Eq_2449 bx_cx_285 = bx_cx;
	if (bx < 0x00)
	{
		ui32 bx_cx_178 = ~bx_cx;
		bx_cx_285 = SEQ(SLICE(bx_cx_178 + 0x01, word16, 16), (word16) bx_cx_178 + 0x01);
	}
	int16 dx_114 = dx;
	word16 v18_56 = (word16) (cond(dx_114) | DP_125);
	if (dx < 0x00)
	{
		ui32 dx_ax_180 = ~dx_ax;
		ax = (word16) dx_ax_180 + 0x01;
		dx_114 = SLICE(dx_ax_180 + 0x01, word16, 16);
	}
	int16 cx_143 = 0x00;
	int16 bx_145 = 0x00;
	Eq_64189 C_115;
	C_115.u0 = 0x00;
	word16 bp_118 = 33;
	ui32 bx_cx_184;
	ui32 SCZDOP_127;
	do
	{
		bx_cx_184 = SEQ(__rcl<word16,byte>(bx_145, 0x01, (cx_143 & 0x8000) != 0x00), __rcl<word16,byte>(cx_143, 0x01, C_115)) - bx_cx_285;
		cup16 bx_96 = SLICE(bx_cx_184, word16, 16);
		DP_125 &= 0x28;
		ui32 C_104 = cond(bx_96) & 0x02;
		if (bx_96 < 0x00)
		{
			bx_cx_184 = (word32) bx_cx_285 + bx_cx_184;
			C_104 = cond(SLICE(bx_cx_184, word16, 16)) & 0x02;
		}
		ax = __rcl<word16,byte>(ax, 0x01, !C_104);
		--bp_118;
		C_115 = (dx_114 & 0x8000) != 0x00;
		bx_145 = SLICE(bx_cx_184, word16, 16);
		cx_143 = (word16) bx_cx_184;
		dx_114 = __rcl<word16,byte>(dx_114, 0x01, (ax & 0x8000) != 0x00);
		SCZDOP_127 = cond(bp_118) | C_115 | DP_125 & 0x28;
	} while (bp_118 != 0x00);
	ui32 SCZDOP_137 = SEQ(SLICE(SCZDOP_127, word16, 16), v18_56);
	if (!(SCZDOP_137 & 0x01))
	{
		ui32 bx_cx_188 = ~bx_cx_184;
		bx_145 = SLICE(bx_cx_188 + 0x01, word16, 16);
		cx_143 = (word16) bx_cx_188 + 0x01;
		if (!(SEQ(SLICE(cond(bx_145), word16, 16), v13_37) & 0x01))
			goto l1EDA_09EF;
	}
	else if (SEQ(SLICE(SCZDOP_127, word16, 16), v13_37) & 0x01)
		goto l1EDA_09EF;
	ui32 dx_ax_190 = ~SEQ(dx_114, ax);
	ax = (word16) dx_ax_190 + 0x01;
	dx_114 = SLICE(dx_ax_190 + 0x01, word16, 16);
l1EDA_09EF:
	cxOut = cx_143;
	dxOut = dx_114;
	bxOut = bx_145;
	struct Eq_2469 * ds;
	dsOut = ds;
	return ax;
}
