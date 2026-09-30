// 1EDA:03D3: FlagGroup bool fn1EDA_03D3(Sequence Eq_17 bx_cx, Register Eq_17 ax, Register Eq_17 ds, Register out Eq_17 axOut, Register out (ptr16 Eq_62871) dxOut)
// Called from:
//      fn1EDA_0254
bool fn1EDA_03D3(Eq_17 bx_cx, Eq_17 ax, Eq_17 ds, union Eq_17 & axOut, struct Eq_62871 & dxOut)
{
	Eq_17 cx = (word16) bx_cx;
	Eq_17 bx;
	bx.u3 = SLICE(bx_cx, word16, 16);
	Eq_17 ax_124 = ax;
	word32 C_130 = 0x00;
	struct Eq_62871 * dx;
	if (ax != 0x00)
	{
		if ((cx & ~0x08) == 0x00 && (bx >u Mem0[ds:0x535C:word16] || bx >=u Mem0[ds:0x535C:word16] && cx >=u Mem0[ds:0x535A:word16]) && (bx <u Mem0[ds:0x5360:word16] || bx <=u Mem0[ds:0x5360:word16] && cx <u Mem0[ds:0x535E:word16]))
		{
			Eq_62977 dx_ax_211 = fn1EDA_0491(ax);
			bx_cx.u3->t0004.u2 = (uint16) (word16) dx_ax_211;
			bx_cx.u3->t0006.u2 = SLICE(dx_ax_211, word16, 16);
			Eq_17 es_di_207 = SEQ(ds, 0x5366);
			Eq_17 es_di_215;
			Eq_17 di_64;
			do
			{
				Eq_17 es_57;
				do
				{
					Eq_17 di_50 = (word16) es_di_215;
					es_di_207.u3 = (ds->*di_50.u3).t0000.u3;
					ax_124 = di_50;
					dx = SLICE(es_di_215, selector, 16);
					es_57.u3 = SLICE(es_di_207, selector, 16);
					di_64 = (word16) es_di_207;
					es_di_215 = es_di_207;
				} while (bx > es_57);
				if (bx < es_57)
					goto l1EDA_0424;
				Eq_17 es_di_216 = es_di_207;
			} while (cx > di_64);
			if (cx != di_64)
			{
l1EDA_0424:
				word16 ax_212;
				word16 dx_213;
				Eq_17 ax_108;
				struct Eq_62871 * dx_112;
				fn1EDA_0432(es_di_215, fn1EDA_0432(bx_cx, es_di_207, ds, out ax_212, out dx_213), ds, out ax_108, out dx_112);
				axOut = ax_108;
				dxOut = dx_112;
				return false;
			}
		}
		C_130 = 0x02;
	}
	axOut = ax_124;
	dxOut = dx;
	return C_130 != 0x00;
}
