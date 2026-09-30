// 1AB8:0EB5: void fn1AB8_0EB5(Register Eq_17 ds)
// Called from:
//      fn0800_0000
//      fn0C74_03D4
//      fn13E2_0193
void fn1AB8_0EB5(Eq_17 ds)
{
	word16 sp_109;
	word16 dx_72;
	if (Mem7[ds:0xB84E:byte] == 0x00)
		Mem157[ds:0xB818:word16] = ~0x00;
	else
	{
		fn1AB8_0E88(ds);
		Mem29[ds:~0x4939:segptr32]();
		cui16 ax_37 = Mem29[ds:47144:word16] | Mem29[ds:47146:word16];
		if (ax_37 != 0x00)
		{
			ds:0x5112[Mem29[ds:47124:word16] * 0x1A] = 0x00;
			ds:0x5114[Mem29[ds:47124:word16] * 0x1A] = 0x00;
		}
		selector ss;
		struct Eq_59732 Eq_59731::* sp_30;
		(ss->*sp_30).tFFFE.u2 = (uint16) ds;
		(ss->*sp_30).wFFFC = 47144;
		Mem62[ss:sp_30 + -6:word16] = Mem59[ds:47148:word16];
		Mem62[ds:~0x4939:segptr32]();
		word16 ax_71 = fn1AB8_0813(ds, out dx_72);
		uint16 wLoc04_171 = 0x01;
		while (true)
		{
			uint16 ax_83 = wLoc04_171 * 0x0F;
			struct Eq_59780 * ptrLoc08_175 = SEQ(ds, ax_83 + 0x520B);
			if (ptrLoc08_175->b000A != 0x00 && (ptrLoc08_175->w0008 != 0x00 && (ptrLoc08_175->w0000 | ptrLoc08_175->w0002) != 0x00))
			{
				struct Eq_59805 Eq_59731::* sp_110 = sp_109 - 2;
				(ss->*sp_110).t0000.u2 = (uint16) ds;
				(ss->*sp_110).wFFFE = ax_83 + 0x520B;
				(ss->*sp_110).wFFFC = ptrLoc08_175->w0008;
				Mem121[ds:~0x4939:segptr32]();
				ptrLoc08_175->w0008 = 0x00;
				ptrLoc08_175->w0000 = 0x00;
				ptrLoc08_175->w0002 = 0x00;
				ptrLoc08_175->w0004 = 0x00;
				ptrLoc08_175->w0006 = 0x00;
			}
			if (wLoc04_171 == 0x14)
				break;
			++wLoc04_171;
		}
	}
}
