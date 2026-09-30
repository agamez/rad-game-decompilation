// 1AB8:1536: Register (ptr16 Eq_60440) fn1AB8_1536(Register Eq_17 ds, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08, Register out Eq_17 dsOut)
// Called from:
//      fn0800_04E3
//      fn0800_0619
//      fn0800_0768
//      fn0800_0D20
//      fn0800_149F
//      fn0800_166D
//      fn0800_184C
//      fn0800_19E1
//      fn0800_1E3F
//      fn0800_2004
//      fn0800_21E7
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
//      fn0800_391E
//      fn0800_3D9D
//      fn0800_4255
//      fn1229_0040
//      fn1229_0AA8
//      fn133F_014B
//      fn1AB8_0AEE
struct Eq_60440 * fn1AB8_1536(Eq_17 ds, Eq_17 wArg04, Eq_17 wArg06, Eq_17 wArg08, union Eq_17 & dsOut)
{
	mp16 fp;
	segptr32 ptrLoc08;
	Eq_17 wLoc08 = (word16) ptrLoc08;
	Eq_17 wLoc06;
	wLoc06.u3 = SLICE(ptrLoc08, word16, 16);
	struct Eq_60448 Eq_17::* sp_112 = fp - 0x010C;
	if (wArg08 > 0x14 || (wArg08 < 0x00 || wArg08 != 0x00 && ((*((word32) ds + 0x00005215)))[wArg08].b0000 == 0x00))
	{
		Mem434[ds:0xB818:word16] = ~0x0D;
		wArg08.u0 = 0x00;
		wArg04.u0 = 0x01;
		goto l1AB8_175E;
	}
	Eq_17 ss;
	if (wArg08 == 0x00 || wArg08 == Mem7[ds:47244:word16])
	{
l1AB8_175E:
		Mem449[ds:47244:word16] = wArg08;
		Mem451[ds:0xB88E:word16] = wArg06;
		Mem453[ds:0xB890:word16] = wArg04;
		struct Eq_60481 Eq_17::* sp_460 = sp_112 - 2;
		(ss->*sp_460).t0000.u2 = (uint16) wArg08;
		(ss->*sp_460).tFFFE.u2 = (uint16) wArg06;
		(ss->*sp_460).tFFFC.u2 = (uint16) wArg04;
		struct Eq_60440 * es_472 = fn1AB8_1DA6(ds, (ss->*sp_460).tFFFC.u0, (ss->*sp_460).tFFFE.u0, (ss->*sp_460).t0000.u0);
		dsOut = ds;
		return es_472;
	}
	if (wArg08 == Mem7[ds:46922:word16])
	{
l1AB8_1747:
		word16 dx_430 = (*((word32) ds + 0x00005211))[wArg08].w0000;
		Mem431[ds:0xB836:word16] = ds:0x520F[wArg08 *16 0x0F];
		Mem432[ds:0xB838:word16] = dx_430;
		goto l1AB8_175E;
	}
	if (Mem7[ds:46922:word16] != 0x00)
	{
		uint16 ax_39 = Mem7[ds:46922:word16] *u 0x0F;
		struct Eq_60568 * ptrLoc0C_487 = SEQ(ds, ax_39 + 0x520B);
		if (ptrLoc0C_487->w0008 != 0x00)
		{
			Mem62[ds:~0x4939:segptr32]();
			ptrLoc0C_487->w0000 = 0x00;
			ptrLoc0C_487->w0002 = 0x00;
			ptrLoc0C_487->w0004 = 0x00;
			ptrLoc0C_487->w0006 = 0x00;
			ptrLoc0C_487->w0008 = 0x00;
		}
	}
	struct Eq_60549 * ptrLoc0C_495 = SEQ(ds, wArg08 *16 0x0F + 0x520B);
	if ((ptrLoc0C_495->w0004 | ptrLoc0C_495->w0006) == 0x00)
	{
		struct Eq_60599 Eq_17::* sp_113 = sp_112 - 2;
		(ss->*sp_113).t0000.u2 = (uint16) ss;
		(ss->*sp_113).tFFFE.u2 = (uint16) (fp - 0x010C);
		(ss->*sp_113).tFFFC.u2 = (uint16) ds;
		(ss->*sp_113).tFFFA.u2 = (uint16) (wArg08 *16 0x0F + 0x5215);
		fn1EDA_0A1F((ss->*sp_113).tFFFA.u3, (ss->*sp_113).tFFFE.u3);
		Eq_17 cs;
		(ss->*sp_113).tFFFC.u2 = (uint16) cs;
		(ss->*sp_113).tFFFA.u2 = (uint16) 0x1531;
		fn1EDA_0AAC((ss->*sp_113).tFFFA.u3, (ss->*sp_113).tFFFE.u3);
		(ss->*sp_113).tFFFC.u2 = (uint16) ds;
		(ss->*sp_113).tFFFA.u2 = (uint16) 46924;
		(ss->*sp_113).tFFF8.u2 = (uint16) 0x08;
		word16 dx_564;
		fn1EDA_0A39((ss->*sp_113).t0008.u0, (ss->*sp_113).tFFFA.u3, (ss->*sp_113).tFFFE.u3, out dx_564);
		(ss->*sp_113).t0000.u2 = (uint16) ds;
		(ss->*sp_113).tFFFE.u2 = (uint16) 46948;
		(ss->*sp_113).tFFFC.u2 = (uint16) ds;
		(ss->*sp_113).tFFFA.u2 = (uint16) 46924;
		(ss->*sp_113).tFFF8.u2 = (uint16) ss;
		(ss->*sp_113).tFFF6.u2 = (uint16) (fp - 4);
		(ss->*sp_113).wFFF4 = ~0x0C;
		sp_112 = (struct Eq_60448 Eq_17::*) ((char *) &sp_113->t0000 + 2);
		if (fn1AB8_0887(ds, (ss->*sp_113).wFFF4, (ss->*sp_113).tFFF6.u3, (ss->*sp_113).tFFFA.u3, (ss->*sp_113).tFFFE.u3, out ds) == 0x00)
		{
			if (Mem198[ds:0xB818:word16] == ~0x02)
				Mem404[ds:0xB818:word16] = ~0x07;
			wArg08.u0 = 0x00;
			wArg04.u0 = 0x01;
			goto l1AB8_175E;
		}
		struct seg1AB8_t * dx_220 = Mem198[ds:0x5370:word16];
		Mem221[ds:~0x4843:word16] = Mem198[ds:0x536E:word16];
		Mem222[ds:~0x4841:word16] = dx_220;
		Mem225[ds:0x536E:word16] = 0x050B;
		Mem226[ds:0x5370:word16] = 0x1AB8;
		(ss->*sp_113).t0000.u2 = (uint16) ss;
		(ss->*sp_113).tFFFE.u2 = (uint16) (fp - 8);
		Eq_17 wLoc04;
		(ss->*sp_113).tFFFC.u2 = (uint16) wLoc04;
		Mem234[ds:46786:segptr32]();
		struct seg1AB8_t * dx_244 = Mem234[ds:~0x4841:word16];
		Mem245[ds:0x536E:word16] = Mem234[ds:~0x4843:word16];
		Mem246[ds:0x5370:word16] = dx_244;
		cui16 ax_248 = wLoc08 | wLoc06;
		struct Eq_60448 Eq_17::* sp_236;
		if (ax_248 == 0x00)
		{
			(ss->*sp_236).tFFFE.u2 = (uint16) ds;
			(ss->*sp_236).tFFFC.u2 = (uint16) 46794;
			fn1EDA_1051((byte) ax_248, ds, (ss->*sp_236).tFFFC.u3);
			Mem395[ds:0xB818:word16] = ~0x08;
			sp_112 = sp_236;
			wArg08.u0 = 0x00;
			wArg04.u0 = 0x01;
			goto l1AB8_175E;
		}
		(ss->*sp_236).tFFFE.u2 = (uint16) ds;
		(ss->*sp_236).tFFFC.u2 = (uint16) 46794;
		(ss->*sp_236).tFFFA.u2 = (uint16) wLoc06;
		(ss->*sp_236).tFFF8.u2 = (uint16) wLoc08;
		(ss->*sp_236).tFFF6.u2 = (uint16) wLoc04;
		(ss->*sp_236).wFFF4 = 0x00;
		(ss->*sp_236).tFFF2.u2 = (uint16) 0x00;
		word16 ax_281 = fn1EDA_10BB(ds, (ss->*sp_236).tFFF2.u3, (ss->*sp_236).tFFF6.u2, (ss->*sp_236).tFFFC.u3);
		(ss->*sp_236).tFFFE.u2 = (uint16) ds;
		(ss->*sp_236).tFFFC.u2 = (uint16) 46794;
		fn1EDA_1051((byte) ax_281, ds, (ss->*sp_236).tFFFC.u3);
		if (fn1EDA_04A2(ds) == 0x00)
		{
			(ss->*sp_236).tFFFE.u2 = (uint16) wLoc06;
			(ss->*sp_236).tFFFC.u2 = (uint16) wLoc08;
			Eq_17 ax_317 = fn1AB8_06CA(ds, (ss->*sp_236).tFFFC.u3);
			sp_112 = sp_236;
			if (true && wArg08 == ax_317)
			{
				ptrLoc0C_495->t0008.u2 = (uint16) wLoc04;
				ptrLoc0C_495->t0000.u2 = (uint16) wLoc08;
				ptrLoc0C_495->t0002.u2 = (uint16) wLoc06;
				goto l1AB8_1741;
			}
		}
		Mem354[ds:0xB818:word16] = ~0x0C;
		(ss->*sp_236).tFFFE.u2 = (uint16) ss;
		(ss->*sp_236).tFFFC.u2 = (uint16) (fp - 8);
		(ss->*sp_236).tFFFA.u2 = (uint16) wLoc04;
		Mem365[ds:~0x4939:segptr32]();
		wArg08.u0 = 0x00;
		wArg04.u0 = 0x01;
		goto l1AB8_175E;
	}
	else
	{
l1AB8_1741:
		Mem418[ds:46922:word16] = wArg08;
		goto l1AB8_1747;
	}
}
