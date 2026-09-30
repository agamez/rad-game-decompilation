// 0C74:1D95: Register word16 fn0C74_1D95(Register Eq_17 ds, Stack Eq_17 wArg02, Register out (ptr16 Eq_30003) dsOut)
// Called from:
//      fn0C74_1F08
word16 fn0C74_1D95(Eq_17 ds, Eq_17 wArg02, struct Eq_30003 & dsOut)
{
	mp16 fp;
	Eq_17 ds_83;
	selector ss;
	Eq_17 ax_32 = fn1AB8_13A3(ds, Mem26[ds:22712:word16] + 0x1B, Mem20[ds:22708:word16] + 0x1D + Mem20[ss:wArg02 + -4:word16], Mem16[ds:22712:word16] + 0x0D, Mem7[ds:22708:word16] + 0x19 + Mem7[ss:wArg02 + -4:word16]);
	Eq_17 ax_49 = Mem48[ds:22712:word16];
	Eq_17 ax_56 = Mem52[ds:22708:word16] + 0x11 - Mem52[ss:wArg02 + -4:word16];
	Eq_17 dx_ax_387 = fn1EDA_023F(ds, ax_56, (word32) ax_49 + 0x0D, fn1AB8_13A3(ds, Mem58[ds:22712:word16] + 0x1B, ax_56, ax_49 + 0x0D, Mem42[ds:22708:word16] + 0x0D - Mem42[ss:wArg02 + -4:word16]), out ds_83);
	Eq_17 ds_101;
	fn1AB8_1E6B(ds_101, fn1EDA_023F(ds_83, ax_56, (word32) ax_49 + 0x0D, ax_32, out ds_101), Mem127[ds_101:22712:word16] + 0x1B, Mem121[ds_101:22708:word16] + 0x1D + Mem121[ss:wArg02 + -4:word16], Mem117[ds_101:22712:word16] + 0x0D, Mem111[ds_101:22708:word16] + 0x19 + Mem111[ss:wArg02 + -4:word16]);
	fn1AB8_1E6B(ds_101, dx_ax_387, Mem166[ds_101:22712:word16] + 0x1B, Mem160[ds_101:22708:word16] + 0x11 - Mem160[ss:wArg02 + -4:word16], Mem156[ds_101:22712:word16] + 0x0D, Mem139[ds_101:22708:word16] + 0x0D - Mem139[ss:wArg02 + -4:word16]);
	Eq_17 bp_206 = fp - 2;
	struct Eq_29908 Eq_17::* sp_189 = fp - 0x10;
	if (true)
	{
		while (true)
		{
			struct Eq_30013 Eq_17::* sp_198 = sp_189 - 2;
			(ss->*sp_198).t0000.u2 = (uint16) 0xE6;
			(ss->*sp_198).tFFFE.u2 = (uint16) 0x0A;
			bp_206 = fn0C74_070D(ds_101, (ss->*sp_198).tFFFE.u2, (ss->*sp_198).t0000.u2, out ds_101);
			Eq_481 sp_214;
			sp_214.u0 = <invalid>;
			Mem228[ss:sp_214 + 0x02:word16] = Mem202[ds_101:22708:word16] + 0x19 + CONVERT(Mem202[ss:bp_206 + -1:byte], uint8, uint16);
			Mem233[ss:sp_214 + 0x00:word16] = Mem228[ds_101:22712:word16] + 0x0D;
			Eq_17 es_di_234 = ss->*((word32) bp_206 - 0x0E);
			ss->*((word16) sp_214 - 2) = SLICE(es_di_234, selector, 16);
			ss->*((word16) sp_214 - 4) = (word16) es_di_234;
			ss->*((word16) sp_214 - 6) = 0x00;
			fn1AB8_13D7(ds_101, ss->*((word16) sp_214 + 6), ss->*((word16) sp_214 - 4), ss->*sp_214, ss->*((word16) sp_214 + 2));
			Mem263[ss:sp_214 + 0x02:word16] = Mem242[ds_101:22708:word16] + 0x0D - CONVERT(Mem242[ss:bp_206 + -1:byte], uint8, uint16);
			Mem268[ss:sp_214 + 0x00:word16] = Mem263[ds_101:22712:word16] + 0x0D;
			Eq_17 es_di_269 = ss->*((word32) bp_206 - 0x0A);
			ss->*((word16) sp_214 - 2) = SLICE(es_di_269, selector, 16);
			ss->*((word16) sp_214 - 4) = (word16) es_di_269;
			ss->*((word16) sp_214 - 6) = 0x00;
			fn1AB8_13D7(ds_101, ss->*((word16) sp_214 + 6), ss->*((word16) sp_214 - 4), ss->*sp_214, ss->*((word16) sp_214 + 2));
			sp_189 = (word16) sp_214 + 4;
			if (ss->*((word32) bp_206 - 1) == 0x00)
				break;
			(ss->*((word32) bp_206 - 1)).u1 = ss->*((word32) bp_206 - 1) - 0x01;
		}
	}
	struct Eq_29912 Eq_17::* sp_300 = sp_189 - 2;
	(ss->*sp_300).w0000 = (word16) (ss->*((word32) bp_206 - 8));
	(ss->*sp_300).tFFFE.u2 = (uint16) (ss->*((word32) bp_206 - 0x0A));
	(ss->*sp_300).tFFFC.u2 = (uint16) (ss->*((word32) bp_206 - 6));
	word16 dx_389;
	Eq_17 ds_314;
	fn1EDA_0254(ds_101, (ss->*sp_300).tFFF8.u2, (ss->*sp_300).tFFFA.u2, (ss->*sp_300).tFFFC.u2, (ss->*sp_300).tFFFE.u3, out dx_389, out ds_314);
	(ss->*sp_300).w0000 = (word16) (ss->*((word32) bp_206 - 0x0C));
	(ss->*sp_300).tFFFE.u2 = (uint16) (ss->*((word32) bp_206 - 0x0E));
	(ss->*sp_300).tFFFC.u2 = (uint16) (ss->*((word32) bp_206 - 4));
	word16 dx_390;
	struct Eq_30003 * ds_337;
	fn1EDA_0254(ds_314, (ss->*sp_300).tFFF8.u2, (ss->*sp_300).tFFFA.u2, (ss->*sp_300).tFFFC.u2, (ss->*sp_300).tFFFE.u3, out dx_390, out ds_337);
	word16 bp_347 = (ss->*bp_206.u3).t0000.u2;
	dsOut = ds_337;
	return bp_347;
}
