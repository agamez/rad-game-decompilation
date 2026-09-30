// 1AB8:05D3: Register Eq_58075 fn1AB8_05D3(Register Eq_17 ds, Stack Eq_17 ptrArg04)
// Called from:
//      fn13E2_0220
//      fn1AB8_097B
Eq_58075 fn1AB8_05D3(Eq_17 ds, Eq_17 ptrArg04)
{
	Eq_58036 wArg04_202 = (word16) ptrArg04;
	struct seg1AB8_t * wArg06_203 = SLICE(ptrArg04, word16, 16);
	Eq_58075 wLoc04_190;
	if (Mem7[ds:0xB84E:byte] != 0x00)
	{
		Mem177[ds:0xB818:word16] = ~0x0A;
		wLoc04_190.u0 = ~0x0A;
	}
	else
	{
		Mem13[ds:0xB818:word16] = ~0x03;
		Eq_17 ptrLoc010E_197;
		<unknown> Eq_58089::* fp;
		ptrLoc010E_197.u3 = fp - 266;
		fn1EDA_0B61(0x02, ptrArg04, ptrLoc010E_197);
		wLoc04_190.u0 = ~0x03;
		struct Eq_58105 * cs;
		word16 ax_290;
		word16 dx_291;
		if (fn1EDA_0B24(&cs->t05D0, ptrLoc010E_197, out ax_290, out dx_291))
		{
			struct Eq_58120 * ptrLoc08_206 = (word32) wArg04_202 + 0x0080;
			if (ptrLoc08_206->b0006 >= 0x02 && ptrLoc08_206->b0008 <= 0x01)
			{
				Eq_58075 ax_79 = Mem68[ds:~0x4847:word16];
				if (ax_79 >= 0x00)
				{
					Eq_58075 wLoc0A_209;
					wLoc0A_209.u0 = 0x00;
					word16 ax_292;
					word16 dx_293;
					while (fn1EDA_0B24((word32) wArg04_202 + 0x008A, SEQ(ds, wLoc0A_209 * 0x1A + 0x50FC), out ax_292, out dx_293))
					{
						if (wLoc0A_209 == ax_79)
							return wLoc04_190;
						wLoc0A_209 = (word16) wLoc0A_209.u1 + 1;
					}
					word16 dx_153;
					(*((word32) ds + 0x00005112))[wLoc0A_209].t0000.u0 = (cui16) fn1AB8_0569((word32) wArg04_202 + 0x0084, (word32) wArg04_202 + 0x0080, wArg04_202, wArg06_203, out dx_153);
					(*((word32) ds + 0x00005114))[wLoc0A_209].w0000 = dx_153;
					Mem176[ds:0xB818:word16] = 0x00;
					wLoc04_190 = wLoc0A_209;
				}
			}
		}
	}
	return wLoc04_190;
}
