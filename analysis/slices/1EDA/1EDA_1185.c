// 1EDA:1185: Register word16 fn1EDA_1185(Register Eq_17 ds, Stack Eq_17 ptrArg04)
// Called from:
//      fn0800_11EF
//      fn0C43_00B9
//      fn1229_039D
//      fn1229_0735
word16 fn1EDA_1185(Eq_17 ds, Eq_17 ptrArg04)
{
	ui32 dx_ax_61;
	byte ah_33 = SLICE(dx_ax_61, byte, 8);
	ui32 bx_cx_62;
	ptr32 es_di_63;
	if (fn1EDA_119A(ds, ptrArg04, out bx_cx_62, out dx_ax_61, out es_di_63))
		return SEQ(ah_33, 0x00);
	ui32 dx_ax_30 = dx_ax_61 - bx_cx_62;
	ah_33 = SLICE(dx_ax_30, byte, 8);
	if (SLICE(dx_ax_30, word16, 16) < 0x00)
		return SEQ(ah_33, 0x00);
	return SEQ(ah_33, 0x01);
}
