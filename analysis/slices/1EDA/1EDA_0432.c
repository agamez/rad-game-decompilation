// 1EDA:0432: Sequence Eq_17 fn1EDA_0432(Sequence Eq_17 bx_cx, Sequence Eq_17 es_di, Register Eq_17 ds, Register out Eq_17 axOut, Register out Eq_17 dxOut)
// Called from:
//      fn1EDA_03D3
Eq_17 fn1EDA_0432(Eq_17 bx_cx, Eq_17 es_di, Eq_17 ds, union Eq_17 & axOut, union Eq_17 & dxOut)
{
	Eq_17 di = (word16) es_di;
	Eq_17 es;
	es.u3 = SLICE(es_di, selector, 16);
	Eq_17 cx = (word16) bx_cx;
	Eq_17 bx;
	bx.u3 = SLICE(bx_cx, word16, 16);
	word16 cx_13 = (word16) (&cx.u3->t0000.u0 + ((bx_cx.u3)->t0004).u2);
	byte cl_15 = (byte) cx_13;
	Eq_17 cx_24 = SEQ(SLICE(cx_13, byte, 8), cl_15 + 0xF0 & 0x0F);
	if (SLICE(cl_15 + 0xF0, word16, 8) != es || cx_24 != di)
	{
		bx_cx.u3->t0000.u2 = (uint16) di;
		bx_cx.u3->t0002.u2 = (uint16) es;
		axOut = di;
		dxOut = es;
		return CAFE:CAFE;
	}
	else if (es != Mem0[ds:0x5360:word16] || di != Mem0[ds:0x535E:word16])
	{
		bx_cx.u3->t0000.u2 = es_di.u3->t0000.u2;
		bx_cx.u3->t0002.u2 = es_di.u3->t0002.u2;
		word16 ax_70 = es_di.u3->t0004.u2 + ((bx_cx.u3)->t0004).u2;
		byte al_72 = (byte) ax_70;
		Eq_17 dx_76;
		dx_76.u3 = SLICE(SEQ(es_di.u3->t0006.u2 + ((bx_cx.u3)->t0006).u2, al_72) + 0xF0, word16, 8);
		Eq_17 ax_82 = SEQ(SLICE(ax_70, byte, 8), al_72 + 0xF0 & 0x0F);
		bx_cx.u3->t0004.u2 = (uint16) ax_82;
		bx_cx.u3->t0006.u2 = (uint16) dx_76;
		axOut = dx_76;
		dxOut = ax_82;
		return CAFE:CAFE;
	}
	else
	{
		Mem93[ds:0x535E:word16] = cx;
		Mem94[ds:0x5360:word16] = bx;
		axOut = di;
		dxOut = es;
		return CAFE:CAFE;
	}
}
