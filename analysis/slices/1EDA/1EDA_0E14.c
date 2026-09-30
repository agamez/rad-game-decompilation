// 1EDA:0E14: Register (memptr (ptr16 Eq_64770) byte) fn1EDA_0E14(Sequence Eq_17 dx_ax, Register Eq_64769 di, Register (ptr16 Eq_64770) es)
// Called from:
//      fn1EDA_0F26
byte Eq_64770::* fn1EDA_0E14(Eq_17 dx_ax, Eq_64769 di, struct Eq_64770 * es)
{
	ci16 dx = SLICE(dx_ax, word16, 16);
	Eq_17 dx_bx_154 = dx_ax;
	Eq_64769 di_118 = di;
	if (dx < 0x00)
	{
		es->*di = 0x2D;
		ui32 dx_bx_120 = ~dx_ax;
		di_118 = (word16) di + 1;
		dx_bx_154 = SEQ(SLICE(dx_bx_120 + 0x01, word16, 16), (word16) dx_bx_120 + 0x01);
	}
	cup16 bx_102 = (word16) dx_bx_154;
	cup16 dx_98 = SLICE(dx_bx_154, word16, 16);
	struct Eq_64781 seg1EDA_t::* si_106 = &seg1EDA_t::t0E66;
	byte cl_30 = 0x09;
	while (dx_98 < (7898->*si_106).w0002 || dx_98 <= (7898->*si_106).w0002 && bx_102 < ((7898->*si_106).t0000).u1)
	{
		++si_106;
		--cl_30;
		if (cl_30 == 0x00)
			break;
	}
	byte cl_49 = cl_30 + 0x01;
	Eq_17 dx_bx_125 = dx_bx_154;
	do
	{
		byte al_51 = 0x2F;
		Eq_17 dx_bx_123 = dx_bx_125;
		do
		{
			dx_bx_123 -= (7898->*si_106).t0000.u0;
			++al_51;
		} while (SLICE(dx_bx_123, word16, 16) >= 0x00);
		dx_bx_125.u3 = &dx_bx_123.u3->t0000.u0 + ((7898->*si_106).t0000).u0;
		es->*di_118 = al_51;
		++si_106;
		di_118 = (word16) di_118 + 1;
		--cl_49;
	} while (cl_49 != 0x00);
	return di_118 - di;
}

Eq_64781 g_t0E66 = // 1EDA:0E66
	{
		
		{
			1000000000
		},
		15258,
	};
