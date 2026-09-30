// 1206:015B: Register word16 fn1206_015B(Register Eq_17 ds, Register out byte chOut, Register out word16 dxOut, Register out (memptr Eq_17 Eq_474) bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0800_031B
//      fn0800_0768
//      fn0800_1E3F
//      fn0800_2004
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
//      fn0800_391E
//      fn0C74_3615
//      fn0C74_37C3
word16 fn1206_015B(Eq_17 ds, byte & chOut, word16 & dxOut, struct Eq_474 & bpOut, union Eq_17 & dsOut)
{
	mp16 fp;
	struct Eq_51280 Eq_51293::* bp_30 = fp - 2;
	word16 dx;
	selector ss;
	byte ah;
	if (Mem10[ds:22910:byte] != 0x00)
	{
		fn1206_0094(ds, out dx, out bp_30, out ds);
		Mem45[ds:22914:word16] = Mem28[ss:bp_30 + -6:word16];
		ci16 ax_46 = (ss->*bp_30).wFFF8;
		Mem47[ds:22916:word16] = ax_46;
		ah = SLICE(ax_46, byte, 8);
		if ((ss->*bp_30).wFFFC == 0x00)
			goto l1206_01A5;
		if ((ss->*bp_30).w0006 != 0x00)
		{
			word16 ax_52 = (ss->*bp_30).wFFFC;
			ah = SLICE(ax_52, byte, 8);
			if (ax_52 != (ss->*bp_30).w0006)
				goto l1206_01A5;
		}
		(ss->*bp_30).bFFFF = 0x01;
		goto l1206_01A5;
	}
	else
	{
l1206_01A5:
		struct Eq_474 Eq_17::* bp_63 = (ss->*bp_30).ptr0000;
		word16 ax_78 = SEQ(ah, (ss->*bp_30).bFFFF);
		chOut = <invalid>;
		dxOut = dx;
		bpOut = bp_63;
		dsOut = ds;
		return ax_78;
	}
}
