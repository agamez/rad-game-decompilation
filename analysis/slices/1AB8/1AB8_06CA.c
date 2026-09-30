// 1AB8:06CA: Register uint16 fn1AB8_06CA(Register Eq_17 ds, Stack Eq_17 ptrArg04)
// Called from:
//      fn13E2_0220
//      fn1AB8_1536
uint16 fn1AB8_06CA(Eq_17 ds, Eq_17 ptrArg04)
{
	Mem12[ds:0xB818:word16] = ~0x0C;
	uint16 wLoc04_275 = Mem12[ds:0xB818:word16];
	Eq_17 ptrLoc0118_282;
	<unknown> Eq_58189::* fp;
	ptrLoc0118_282.u3 = fp - 0x010C;
	fn1EDA_0B61(0x02, ptrArg04, ptrLoc0118_282);
	struct Eq_58199 * cs;
	word16 ax_384;
	word16 dx_385;
	if (fn1EDA_0B24(&cs->t06C7, ptrLoc0118_282, out ax_384, out dx_385))
	{
		Eq_58207 wLoc0C_287;
		wLoc0C_287.u0 = 0x00;
		struct seg1AB8_t * wArg06_317;
		Eq_58036 wArg04_318;
		while (true)
		{
			wArg06_317 = SLICE(ptrArg04, word16, 16);
			wArg04_318 = (word16) ptrArg04;
			if (SLICE(ptrArg04, selector, 16)->*((word16) ptrArg04 + wLoc0C_287) == 0x1A || wLoc0C_287 >= 0x0101)
				break;
			wLoc0C_287 = (word16) wLoc0C_287 + 1;
		}
		if (wLoc0C_287 < 0x0100)
		{
			word16 ax_84 = (word16) wLoc0C_287 + (word16) ptrArg04;
			struct Eq_58229 * es_87 = SLICE(ptrArg04, selector, 16);
			struct Eq_58233 * ptrLoc08_294 = (struct Eq_58233 *) (ax_84 + 0x01);
			if (ptrLoc08_294->b0008 >= 0x01 && ptrLoc08_294->b000A <= 0x01)
			{
				uint16 wLoc0A_296 = 0x01;
				while (true)
				{
					Eq_17 ptrLoc011C_306;
					ptrLoc011C_306.u3 = fp - 0x0110;
					fn1EDA_0B61(0x04, ax_84 + 0x03, ptrLoc011C_306);
					word16 ax_386;
					word16 dx_387;
					if (!fn1EDA_0B24(ptrLoc011C_306, SEQ(ds, wLoc0A_296 * 0x0F + 0x5215), out ax_386, out dx_387))
						break;
					if (wLoc0A_296 == 0x14)
						return wLoc04_275;
					++wLoc0A_296;
				}
				uint16 ax_168 = wLoc0A_296 * 0x0F;
				struct Eq_58275 * ptrLoc0114_312 = SEQ(ds, ax_168 + 0x520B);
				Mem186[ds:~0x4939:segptr32]();
				ptrLoc0114_312->w0000 = 0x00;
				ptrLoc0114_312->w0002 = 0x00;
				struct Eq_58189 * ss;
				struct Eq_58288 Eq_58189::* sp_193;
				(ss->*sp_193).ptrFFFE = wArg06_317;
				(ss->*sp_193).tFFFC.u0 = (cui16) wArg04_318;
				(ss->*sp_193).ptrFFFA = es_87;
				(ss->*sp_193).tFFF8.u0 = (cui16) (ax_84 + 0x01);
				(ss->*sp_193).ptrFFF6 = es_87;
				(ss->*sp_193).tFFF4.u0 = (word16) (ax_84 + 0x07);
				word16 dx_231;
				ptrLoc0114_312->t0004.u0 = (cui16) fn1AB8_0569((ss->*sp_193).tFFF4.u1, (ss->*sp_193).tFFF8.u1, (ss->*sp_193).tFFFC.u0, (ss->*sp_193).ptrFFFE, out dx_231);
				ptrLoc0114_312->w0006 = dx_231;
				ptrLoc0114_312->w0008 = 0x00;
				Mem256[ds:0xB818:word16] = 0x00;
				wLoc04_275 = wLoc0A_296;
			}
		}
	}
	return wLoc04_275;
}
