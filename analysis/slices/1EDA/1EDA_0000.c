// 1EDA:0000: Register Eq_17 fn1EDA_0000(Register (ptr16 Eq_18201) es)
// Called from:
//      fn0800_4255
Eq_17 fn1EDA_0000(struct Eq_18201 * es)
{
	selector ss;
	Eq_62478 fp;
	selector seg2014;
	seg2014->t537C = (<unknown>) es;
	uint16 ax_15 = ((word16) fp + 19 >> 0x04) + ss;
	seg2014->t534E = ax_15;
	seg2014->t5350 = ax_15;
	uint16 ax_18 = ax_15 + seg2014->t5348;
	seg2014->t5352 = ax_18;
	seg2014->t535C = ax_18;
	seg2014->t5360 = ax_18;
	seg2014->t5368 = ax_18;
	seg2014->t5364 = es->w0002;
	seg2014->t536E = 0xA9;
	struct Eq_62510 * cs;
	seg2014->t5370 = (<unknown>) cs;
	word32 Eq_17::* di_29 = ~0x4543;
	byte Eq_62510::* si_30 = Eq_62510::a01EE;
	word16 cx_31;
	for (cx_31 = 0x13; cx_31 != 0x00; --cx_31)
	{
		8212->*di_29 = msdos_get_interrupt_vector(cs->*si_30);
		++si_30;
		++di_29;
	}
	msdos_set_interrupt_vector(0x00, &cs->t00DF);
	msdos_set_interrupt_vector(0x23, &cs->t00E6);
	msdos_set_interrupt_vector(0x24, &cs->t00AE);
	msdos_set_interrupt_vector(0x3F, &cs->t00D7);
	fn1EDA_04F5(cs->a01EE + 42, &seg2014->tB8BC);
	fn1EDA_0565(8212, &seg2014->tB8BC);
	fn1EDA_04F5(cs->a01EE + 42, &seg2014->tB9BC);
	fn1EDA_056A(8212, &seg2014->tB9BC);
	return 8212;
}
