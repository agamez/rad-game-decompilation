// 1EDA:07DA: Sequence ptr32 fn1EDA_07DA(Sequence segptr32 es_bx, Register byte al, Register Eq_481 cx, Register word16 dx, Register word16 di, Stack Eq_17 ptrArg02, Sequence out segptr32 es_bxOut, Register out byte ahOut, Register out Eq_481 cxOut, Register out word16 dxOut, Register out word16 diOut)
// Called from:
//      fn1EDA_0848
//      fn1EDA_08CE
ptr32 fn1EDA_07DA(segptr32 es_bx, byte al, Eq_481 cx, word16 dx, word16 di, Eq_17 ptrArg02, segptr32 & es_bxOut, byte & ahOut, union Eq_481 & cxOut, word16 & dxOut, word16 & diOut)
{
	Eq_17 ax_40;
	word16 ax;
	al = (byte) ax;
	word16 bx = (word16) es_bx;
	*((word32) es_bx + (uipr32) di) = (segptr32) al;
	if (bx + 0x01 == dx)
	{
		ptrArg02.u3->ptr0008 = bx + 0x01;
		struct Eq_63684 * es_27 = SLICE(ptrArg02, selector, 16);
		word16 di_28 = (word16) ptrArg02;
		ptrArg02.u3->t0014.u3();
		byte ah_96 = SLICE(ax_40, byte, 8);
		selector ss;
		union Eq_17 Eq_63706::* sp_38;
		if (ax_40 == 0x00)
		{
			Eq_481 cx_52;
			word16 dx_55;
			word16 bx_51;
			<unknown> Eq_63752::* si_57;
			word16 di_53;
			selector es_56;
			struct Eq_63752 * ds_54;
			fn1EDA_0801(ax_40, 8212, (ss->*sp_38).u3, out cx_52, out dx_55, out bx_51, out si_57, out di_53, out es_56, out ds_54);
			es_bxOut = <invalid>;
			ahOut = <invalid>;
			cxOut = cx_52;
			dxOut = dx_55;
			diOut = di_53;
			return si_57;
		}
		else
		{
			Eq_481 cx_61;
			word16 dx_64;
			word16 bx_60;
			<unknown> Eq_63730::* si_66;
			word16 di_62;
			selector es_65;
			struct Eq_63730 * ds_63;
			fn1EDA_0801(ax_40, 8212, (ss->*sp_38).u3, out cx_61, out dx_64, out bx_60, out si_66, out di_62, out es_65, out ds_63);
			es_bxOut = <invalid>;
			ahOut = <invalid>;
			cxOut = cx_61;
			dxOut = dx_64;
			diOut = di_62;
			return si_66;
		}
	}
	else
	{
		es_bxOut = <invalid>;
		ahOut = <invalid>;
		cxOut = cx;
		dxOut = dx;
		diOut = di;
		ptr32 ds_si;
		return ds_si;
	}
}
