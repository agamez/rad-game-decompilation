// 1EDA:0DCF: Register cui16 fn1EDA_0DCF(Register Eq_17 ds)
// Called from:
//      fn1EDA_0D80
cui16 fn1EDA_0DCF(Eq_17 ds)
{
	selector seg1EDA;
	uint16 ax_6 = Mem0[ds:0x5382:word16];
	uint32 dx_ax_9 = seg1EDA->w0E05 *32 ax_6;
	ui8 cl_14 = (byte) ax_6 << 0x03;
	cui16 bx_7 = Mem0[ds:0x5384:word16];
	word16 ax_30 = (word16) dx_ax_9;
	Mem38[ds:0x5382:word16] = ax_30 + 0x01;
	word16 dx_22 = SLICE(dx_ax_9, word16, 16) + SEQ(SLICE(ax_6 << 0x03, byte, 8) + cl_14, cl_14) + bx_7 + (bx_7 << 0x02);
	cui16 dx_36 = SLICE(SEQ(SLICE(dx_22, byte, 8) + ((byte) bx_7 << 0x02) + ((byte) bx_7 << 0x07), (byte) dx_22, ax_30) + 0x01, word16, 16);
	Mem39[ds:0x5384:word16] = dx_36;
	return dx_36;
}

uint16 g_w0E05 = 33797; // 1EDA:0E05
