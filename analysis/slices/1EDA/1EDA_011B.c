// 1EDA:011B: void fn1EDA_011B(Register Eq_17 cx, Register Eq_17 bx, Register Eq_17 ds)
// Called from:
//      fn1EDA_00E9
//      fn1EDA_00ED
void fn1EDA_011B(Eq_17 cx, Eq_17 bx, Eq_17 ds)
{
	Mem6[ds:0x5378:word16] = cx;
	Mem8[ds:0x537A:word16] = bx;
	Eq_62658 es_bx_9 = Mem8[ds:21362:segptr32];
	if (es_bx_9 == 0x00)
	{
		fn1EDA_05BF(ds, SEQ(ds, ~0x4743));
		fn1EDA_05BF(ds, SEQ(ds, ~0x4643));
		segptr32 Eq_17::* di_47 = ~0x4543;
		byte Eq_62692::* si_48 = Eq_62692::a01EE;
		word16 cx_49;
		for (cx_49 = 0x13; cx_49 != 0x00; --cx_49)
		{
			selector cs;
			msdos_set_interrupt_vector(cs->*si_48, ds->*di_47);
			++si_48;
			++di_47;
		}
		if ((Mem61[ds:0x5378:word16] | Mem61[ds:0x537A:word16]) != 0x00)
		{
			fn1EDA_01A5(&seg1EDA_t::b0201);
			fn1EDA_01B3(Mem61[ds:21366:byte]);
			fn1EDA_01A5(&seg1EDA_t::b0210);
			fn1EDA_01CD(Mem61[ds:0x537A:word16]);
			fn1EDA_01E7(0x3A);
			fn1EDA_01CD(Mem61[ds:0x5378:word16]);
			fn1EDA_01A5(&seg1EDA_t::b0215);
		}
		msdos_terminate(Mem61[ds:21366:byte]);
	}
	else
	{
		Mem133[ds:21362:word16] = 0x00;
		Mem134[ds:0x5374:word16] = 0x00;
		Mem135[ds:0x5380:word16] = 0x00;
	}
}
