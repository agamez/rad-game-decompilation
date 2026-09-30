// 1AB8:097B: Register byte fn1AB8_097B(Register Eq_17 ds, Stack Eq_17 ptrArg02, Stack Eq_17 wArg06, Register out Eq_17 dsOut)
// Called from:
//      fn1AB8_0BAE
byte fn1AB8_097B(Eq_17 ds, Eq_17 ptrArg02, Eq_17 wArg06, union Eq_17 & dsOut)
{
	<unknown> Eq_58563::* fp;
	word16 dx_409;
	fn1EDA_0A39(~0x00, fp - 0x0104, ptrArg02, out dx_409);
	Eq_17 ptrLoc0214_341;
	ptrLoc0214_341.u3 = fp - 0x0210;
	fn1EDA_0A1F(SEQ(ds, wArg06 *16 0x1A + 0x50FC), ptrLoc0214_341);
	struct Eq_58583 * cs;
	fn1EDA_0AAC(&cs->t0976, ptrLoc0214_341);
	word16 dx_410;
	fn1EDA_0A39(0x0C, SEQ(ds, 46934), ptrLoc0214_341, out dx_410);
	byte bLoc03_335 = 0x00;
	if (((*((word32) ds + 0x00005112))[wArg06].w0000 | ((*((word32) ds + 0x00005114)))[wArg06].w0000) != 0x00)
	{
		struct seg1AB8_t * dx_307 = (*((word32) ds + 0x00005114))[wArg06].ptr0000;
		Mem308[ds:47154:word16] = ds:0x5112[wArg06 *16 0x1A];
		Mem309[ds:0xB834:word16] = dx_307;
		Mem311[ds:47144:word16] = 0x00;
		Mem312[ds:47146:word16] = 0x00;
		Mem317[ds:47148:word16] = 0x00;
		bLoc03_335 = 0x01;
		goto l1AB8_0AE5;
	}
	if (fn1AB8_0887(ds, ~0x03, SEQ(ds, 47148), SEQ(ds, 46934), fp - 0x0104, out ds) == 0x00)
		goto l1AB8_0AE5;
	struct seg1AB8_t * dx_158 = Mem136[ds:0x5370:word16];
	Mem159[ds:~0x4843:word16] = Mem136[ds:0x536E:word16];
	Mem160[ds:~0x4841:word16] = dx_158;
	Mem163[ds:0x536E:word16] = 0x050B;
	Mem164[ds:0x5370:word16] = 0x1AB8;
	Mem172[ds:46786:segptr32]();
	struct seg1AB8_t * dx_181 = Mem172[ds:~0x4841:word16];
	Mem182[ds:0x536E:word16] = Mem172[ds:~0x4843:word16];
	Mem183[ds:0x5370:word16] = dx_181;
	if ((Mem183[ds:47144:word16] | Mem183[ds:47146:word16]) == 0x00)
	{
		Mem301[ds:0xB818:word16] = ~0x04;
		goto l1AB8_0AE5;
	}
	struct Eq_58563 * ss;
	struct Eq_58697 Eq_58563::* sp_173;
	(ss->*sp_173).tFFFE.u2 = (uint16) ds;
	(ss->*sp_173).tFFFC.u2 = (uint16) 46794;
	Eq_17 es_di_195 = Mem194[ds:47144:segptr32];
	(ss->*sp_173).tFFFA.u2 = (uint16) SLICE(es_di_195, selector, 16);
	(ss->*sp_173).wFFF8 = (word16) es_di_195;
	Mem204[ss:sp_173 + -0x0A:word16] = Mem201[ds:47148:word16];
	(ss->*sp_173).ptrFFF4 = ss;
	(ss->*sp_173).tFFF2.u2 = (uint16) (fp - 0x010C);
	word16 ax_215 = fn1EDA_10BB(ds, (ss->*sp_173).tFFF2.u3, (ss->*sp_173).tFFF6.u2, (ss->*sp_173).tFFFC.u3);
	(ss->*sp_173).tFFFE.u2 = (uint16) ds;
	(ss->*sp_173).tFFFC.u2 = (uint16) 46794;
	fn1EDA_1051((byte) ax_215, ds, (ss->*sp_173).tFFFC.u3);
	Eq_17 wLoc010C;
	if (fn1EDA_04A2(ds) == 0x00 && wLoc010C == Mem225[ds:47148:word16])
	{
		Mem250[ss:sp_173 + -2:word16] = Mem225[ds:47146:word16];
		Mem253[ss:sp_173 + -4:word16] = Mem250[ds:47144:word16];
		if (fn1AB8_05D3(ds, (ss->*sp_173).tFFFC.u3) == wArg06)
		{
			struct seg1AB8_t * dx_275 = (*((word32) ds + 0x00005114))[wArg06].ptr0000;
			Mem276[ds:47154:word16] = ds:0x5112[wArg06 *16 0x1A];
			Mem277[ds:0xB834:word16] = dx_275;
			bLoc03_335 = 0x01;
l1AB8_0AE5:
			dsOut = ds;
			return bLoc03_335;
		}
	}
	Mem280[ds:0xB818:word16] = ~0x03;
	(ss->*sp_173).tFFFE.u2 = (uint16) ds;
	(ss->*sp_173).tFFFC.u2 = (uint16) 47144;
	Mem290[ss:sp_173 + -6:word16] = Mem287[ds:47148:word16];
	Mem290[ds:~0x4939:segptr32]();
	goto l1AB8_0AE5;
}
