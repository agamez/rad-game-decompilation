// 1AB8:0BAE: Register Eq_17 fn1AB8_0BAE(Register Eq_17 ds, Stack Eq_17 ptrArg04, Stack (ptr32 ci16) ptrArg08, Stack (ptr32 Eq_17) ptrArg0C)
// Called from:
//      fn133F_0056
//      fn13E2_0001
Eq_17 fn1AB8_0BAE(Eq_17 ds, Eq_17 ptrArg04, ci16 * ptrArg08, union Eq_17 * ptrArg0C)
{
	Eq_17 ss;
	<unknown> Eq_17::* fp;
	word16 dx_693;
	fn1EDA_0A39(~0x00, SEQ(ss, fp - 0x0102), ptrArg04, out dx_693);
	Mem42[ds:0xB820:word16] = 0x2073;
	Mem43[ds:0xB822:word16] = 0x1AB8;
	Eq_58036 es_di_57 = Mem56[ds:0xB820:segptr32];
	struct seg1AB8_t * dx_69;
	Mem78[ds:0xB820:word16] = fn1AB8_0569(&(SLICE(es_di_57, selector, 16)->*((char *) ((word16) es_di_57) + 2)), Mem49[ds:0xB820:segptr32], Mem46[ds:0xB820:word16], Mem43[ds:0xB822:word16], out dx_69);
	Mem79[ds:0xB822:word16] = dx_69;
	<unknown> Eq_17::* sp_121 = fp - 522;
	byte bLoc0109_632 = 0x00;
	if (ptrArg0C->u2 == 0x00)
	{
		Eq_17 wLoc0106_634;
		wLoc0106_634.u0 = 0x00;
		ci16 wLoc0108_635 = ~0x00;
		while (wLoc0106_634 < Mem94[ds:~0x4847:word16] && wLoc0108_635 < 0x00)
		{
			if (((*((word32) ds + 20750))[wLoc0106_634].w0000 | ((*((word32) ds + 0x00005110)))[wLoc0106_634].w0000) != 0x00)
			{
				Eq_59033 ax_117;
				ax_117.u0 = (*((word32) ds + 20750))[wLoc0106_634].t0000.u0;
				word16 dx_118 = (*((word32) ds + 0x00005110))[wLoc0106_634].w0000;
				Mem119[ds:47254:word16] = ax_117;
				Mem120[ds:0xB898:word16] = dx_118;
				Mem120[ds:47254:segptr32]();
				ci16 ax_124;
				wLoc0108_635 = ax_124;
				if (ax_124 >= 0x00)
				{
					Mem134[ds:47124:word16] = wLoc0106_634;
					ptrArg0C->u2 = (uint16) wLoc0106_634;
					*ptrArg08 = ax_124;
					bLoc0109_632 = 0x01;
				}
			}
			wLoc0106_634.u3 = &wLoc0106_634.u3->t0001.u0;
		}
	}
	if (bLoc0109_632 == 0x00)
	{
		struct Eq_59115 Eq_17::* sp_198 = sp_121 - 2;
		(ss->*sp_198).t0000.u2 = (uint16) ds;
		(ss->*sp_198).tFFFE.u1 = (<unknown> Eq_17::*) 47124;
		(ss->*sp_198).ptrFFFC = SLICE(ptrArg0C, selector, 16);
		(ss->*sp_198).tFFFA.u1 = (<unknown> Eq_17::*) (word16) ptrArg0C;
		(ss->*sp_198).ptrFFF8 = SLICE(ptrArg08, selector, 16);
		(ss->*sp_198).tFFF6.u0 = (word16) (word16) ptrArg08;
		fn1AB8_19EE(ds, (ss->*sp_198).tFFF6.u1, (ss->*sp_198).tFFFA.u0, (ss->*sp_198).tFFFE.u0);
	}
	else
	{
		struct Eq_59063 Eq_17::* sp_169 = sp_121 - 2;
		(ss->*sp_169).t0000.u2 = (uint16) ss;
		(ss->*sp_169).tFFFE.u1 = (<unknown> Eq_17::*) (fp - 262);
		(ss->*sp_169).tFFFC.u2 = (uint16) ss;
		(ss->*sp_169).tFFFA.u1 = (<unknown> Eq_17::*) (fp - 0x0108);
		(ss->*sp_169).ptrFFF8 = SLICE(ptrArg08, selector, 16);
		(ss->*sp_169).tFFF6.u0 = (word16) (word16) ptrArg08;
		fn1AB8_19EE(ds, (ss->*sp_169).tFFF6.u1, (ss->*sp_169).tFFFA.u0, (ss->*sp_169).tFFFE.u0);
	}
	if (ptrArg0C->u2 < 0x00)
	{
		Mem595[ds:0xB818:word16] = ~0x01;
		ptrArg0C->u2 = (uint16) ~0x01;
		word16 dx_695;
		fn1AB8_0813(ds, out dx_695);
	}
	else
	{
		Mem241[ds:0xB816:word16] = Mem230[ptrArg08 + 0x00:word16];
		struct Eq_59172 Eq_17::* sp_244 = sp_121 - 2;
		(ss->*sp_244).t0000.u2 = (uint16) ss;
		(ss->*sp_244).tFFFE.u2 = (uint16) (fp - 0x0102);
		(ss->*sp_244).tFFFC.u2 = (uint16) ds;
		(ss->*sp_244).tFFFA.u2 = (uint16) 46948;
		(ss->*sp_244).wFFF8 = 0x50;
		word16 dx_694;
		fn1EDA_0A39((ss->*sp_244).t0008.u0, (ss->*sp_244).tFFFA.u3, (ss->*sp_244).tFFFE.u3, out dx_694);
		if (Mem255[ds:46948:byte] != 0x00)
		{
			byte al_275 = Mem255[ds:CONVERT(Mem255[ds:46948:byte], uint8, uint16) + 46948:byte];
			if (al_275 != 0x3A && al_275 != 0x5C)
			{
				(ss->*sp_244).t0000.u2 = (uint16) ss;
				(ss->*sp_244).tFFFE.u2 = (uint16) (fp - 522);
				(ss->*sp_244).tFFFC.u2 = (uint16) ss;
				(ss->*sp_244).tFFFA.u2 = (uint16) (fp - 0x0102);
				fn1EDA_0A1F((ss->*sp_244).tFFFA.u3, (ss->*sp_244).tFFFE.u3);
				Eq_17 cs;
				(ss->*sp_244).tFFFC.u2 = (uint16) cs;
				(ss->*sp_244).tFFFA.u2 = (uint16) 2988;
				fn1EDA_0AAC((ss->*sp_244).tFFFA.u3, (ss->*sp_244).tFFFE.u3);
				(ss->*sp_244).tFFFC.u2 = (uint16) ds;
				(ss->*sp_244).tFFFA.u2 = (uint16) 46948;
				(ss->*sp_244).wFFF8 = 0x50;
				word16 dx_696;
				fn1EDA_0A39((ss->*sp_244).t0008.u0, (ss->*sp_244).tFFFA.u3, (ss->*sp_244).tFFFE.u3, out dx_696);
			}
		}
		struct Eq_59237 Eq_17::* sp_352 = sp_121 - 2;
		Mem354[ss:sp_352 + 0x00:word16] = Mem349[ds:47124:word16];
		(ss->*sp_352).tFFFE.u2 = (uint16) ds;
		(ss->*sp_352).tFFFC.u2 = (uint16) 46948;
		if (fn1AB8_097B(ds, (ss->*sp_352).tFFFC.u3, (ss->*sp_352).t0000.u2, out ds) == 0x00)
		{
			Mem588[ptrArg0C + 0x00:word16] = Mem359[ds:0xB818:word16];
			word16 dx_697;
			fn1AB8_0813(ds, out dx_697);
		}
		else
		{
			(ss->*sp_352).t0000.u2 = (uint16) ds;
			(ss->*sp_352).tFFFE.u2 = (uint16) 47060;
			(ss->*sp_352).tFFFC.u2 = (uint16) 0x3F;
			(ss->*sp_352).tFFFA.u0 = 0x00;
			fn1EDA_1202((ss->*sp_352).tFFFA.u1, (ss->*sp_352).tFFFC.u2, (ss->*sp_352).tFFFE.u3);
			struct seg1AB8_t * dx_402 = Mem393[ds:0x5370:word16];
			Mem403[ds:~0x4843:word16] = Mem393[ds:0x536E:word16];
			Mem404[ds:~0x4841:word16] = dx_402;
			Mem407[ds:0x536E:word16] = 0x050B;
			Mem408[ds:0x5370:word16] = 0x1AB8;
			(ss->*sp_352).t0000.u2 = (uint16) ds;
			(ss->*sp_352).tFFFE.u2 = (uint16) ~0x481F;
			Mem416[ss:sp_352 + -4:word16] = Mem413[ds:~0x4849:word16];
			Mem416[ds:46786:segptr32]();
			struct seg1AB8_t * dx_429 = Mem416[ds:~0x4841:word16];
			Mem430[ds:0x536E:word16] = Mem416[ds:~0x4843:word16];
			Mem431[ds:0x5370:word16] = dx_429;
			struct Eq_59519 Eq_17::* sp_421;
			if ((Mem431[ds:~0x481F:word16] | Mem431[ds:47074:word16]) == 0x00)
			{
				Mem558[ds:0xB818:word16] = ~0x04;
				ptrArg0C->u2 = (uint16) ~0x04;
				(ss->*sp_421).tFFFE.u2 = (uint16) ds;
				(ss->*sp_421).tFFFC.u0 = 47144;
				Mem570[ss:sp_421 + -6:word16] = Mem567[ds:47148:word16];
				Mem570[ds:~0x4939:segptr32]();
				word16 dx_698;
				fn1AB8_0813(ds, out dx_698);
			}
			else
			{
				Mem438[ds:~0x482A:byte] = 0x00;
				Mem439[ds:~0x4815:byte] = 0x00;
				cui16 dx_441 = Mem439[ds:47074:word16];
				Mem442[ds:0xB82E:word16] = Mem439[ds:~0x481F:word16];
				Mem443[ds:0xB830:word16] = dx_441;
				Mem445[ds:47076:word16] = Mem443[ds:~0x4849:word16];
				cui16 dx_447 = Mem445[ds:47074:word16];
				Mem448[ds:~0x4805:word16] = Mem445[ds:~0x481F:word16];
				Mem449[ds:47100:word16] = dx_447;
				Mem451[ds:~0x4801:word16] = Mem449[ds:~0x4849:word16];
				Mem454[ds:~0x4811:word16] = 0xB818;
				Mem455[ds:~0x480F:word16] = ds;
				(ss->*sp_421).tFFFE.u2 = (uint16) ds;
				(ss->*sp_421).tFFFC.u0 = 47060;
				fn1AB8_1855(ds, (ss->*sp_421).tFFFC.u1);
				Eq_58058 ax_472 = Mem460[ds:0xB83A:word16];
				Mem477[ss:sp_421 + -2:word16] = Mem460[ds:47164:word16];
				(ss->*sp_421).tFFFC.u0 = (word16) ax_472;
				(ss->*sp_421).tFFFA.u2 = (uint16) ds;
				(ss->*sp_421).tFFF8.u1 = 47040;
				(ss->*sp_421).wFFF6 = 0x13;
				fn1EDA_11DF((ss->*sp_421).wFFF6, (ss->*sp_421).tFFF8.u2, (ss->*sp_421).tFFFC.u1);
				(ss->*sp_421).tFFFE.u2 = (uint16) ds;
				(ss->*sp_421).tFFFC.u0 = 47060;
				fn1AB8_1AA6(ds, (ss->*sp_421).tFFFC.u1);
				if (Mem504[ds:47040:byte] != 0x00)
				{
					Mem551[ds:0xB818:word16] = CONVERT(Mem504[ds:47040:byte], uint8, uint16);
					word16 dx_699;
					fn1AB8_0813(ds, out dx_699);
				}
				else
				{
					Mem522[ds:0xB848:word16] = fn1AB8_1C93(ds);
					Mem524[ds:47178:word16] = Mem522[ds:47054:word16];
					Mem525[ds:0xB84C:word16] = 10000;
					Mem526[ds:0xB84E:byte] = 0x01;
					ds = fn1AB8_0AEE(ds);
					Mem544[ds:0xB818:word16] = 0x00;
				}
			}
		}
	}
	return ds;
}
