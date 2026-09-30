// 1EDA:0308: FlagGroup bool fn1EDA_0308(Register Eq_17 ax, Register Eq_17 ds, Register out Eq_17 axOut, Register out Eq_17 dxOut)
// Called from:
//      fn1EDA_023F
bool fn1EDA_0308(Eq_17 ax, Eq_17 ds, union Eq_17 & axOut, union Eq_17 & dxOut)
{
	Eq_17 ax_12 = ax;
	ui32 C_195 = 0x00;
	Eq_17 dx;
	if (ax != 0x00)
	{
		Mem11[ds:0xBB08:word16] = ax;
l1EDA_030F:
		Eq_62977 dx_ax_291 = fn1EDA_0491(ax_12);
		cup16 dx_14 = SLICE(dx_ax_291, word16, 16);
		cup16 ax_13 = (word16) dx_ax_291;
		struct Eq_62923 * es_di_289 = SEQ(ds, 0x5366);
		struct Eq_62923 * es_di_294;
		Eq_17 es_30;
		Eq_17 di_35;
		bool v28_208;
		do
		{
			es_di_289 = (struct Eq_62923 *) (ds->*(word16) es_di_294);
			es_30.u3 = SLICE(es_di_289, selector, 16);
			di_35 = (word16) es_di_289;
			if (es_30 == Mem196[ds:0x5360:word16])
			{
				word16 ax_36 = (word16) (&di_35.u3->t0000.u0 + ax_13);
				byte al_39 = (byte) ax_36;
				Eq_17 dx_43;
				dx_43.u3 = SLICE(al_39 + 0xF0, word16, 8);
				Eq_17 ax_49 = SEQ(SLICE(ax_36, byte, 8), al_39 + 0xF0 & 0x0F);
				if (dx_43 <u Mem196[ds:0x5364:word16] || dx_43 <=u Mem196[ds:0x5364:word16] && ax_49 <=u Mem196[ds:0x5362:word16])
				{
					Mem95[ds:0x535E:word16] = ax_49;
					Mem97[ds:0x5360:word16] = dx_43;
					es_di_294->t0000.u2 = (uint16) ax_49;
					es_di_294->t0002.u2 = (uint16) dx_43;
					Mem105[ds:0x536E:segptr32]();
					axOut = di_35;
					dxOut = es_30;
					return false;
				}
				Mem60[ds:0x536E:segptr32]();
				cu8 al_71 = (byte) ax_12;
				C_195 = cond(al_71 - 0x01) & 0x02;
				if (al_71 < 0x01)
					goto l1EDA_0382;
				if (al_71 == 0x01)
				{
					axOut.u0 = 0x00;
					dxOut.u0 = 0x00;
					return false;
				}
				else
				{
					ax_12 = Mem60[ds:0xBB08:word16];
					goto l1EDA_030F;
				}
			}
			v28_208 = dx_14 == es_di_289->w0006;
			es_di_294 = es_di_289;
			if (dx_14 > es_di_289->w0006)
				continue;
			if (dx_14 < es_di_289->w0006)
				break;
			v28_208 = ax_13 == es_di_289->w0004;
			struct Eq_62923 * es_di_295 = es_di_289;
		} while (ax_13 > es_di_289->w0004);
		Eq_17 cx_138;
		cx_138.u2 = es_di_289->t0000.u2;
		Eq_17 bx_139;
		bx_139.u2 = es_di_289->t0002.u2;
		if (!v28_208)
		{
			cup16 ax_156 = (cup16) (&di_35.u3->t0000.u0 + ax_13);
			byte al_159 = (byte) ax_156;
			Eq_62978 bx_cx_205 = es_di_289->w0004 - dx_ax_291;
			Eq_17 dx_163;
			dx_163.u3 = SLICE(al_159 + 0xF0, word16, 8);
			Eq_17 ax_169 = SEQ(SLICE(ax_156, byte, 8), al_159 + 0xF0 & 0x0F);
			(dx_163->*ax_169.u3).t0000.u2 = (uint16) cx_138;
			(dx_163->*ax_169.u3).t0002.u2 = (uint16) bx_139;
			(dx_163->*ax_169.u3).t0004.u2 = (word16) bx_cx_205 & 0x0F;
			(dx_163->*ax_169.u3).t0006.u2 = SLICE(bx_cx_205, word16, 16);
			cx_138 = ax_169;
			bx_139 = dx_163;
		}
		es_di_294->t0000.u2 = (uint16) cx_138;
		es_di_294->t0002.u2 = (uint16) bx_139;
		ax_12 = di_35;
		dx = es_30;
		C_195 = 0x00;
	}
l1EDA_0382:
	axOut = ax_12;
	dxOut = dx;
	return C_195 != 0x00;
}
