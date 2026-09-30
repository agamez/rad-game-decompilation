// 1229:0040: Register byte fn1229_0040(Register Eq_17 ds, Stack Eq_17 ptrArg04, Stack Eq_17 wArg08, Stack Eq_17 wArg0A, Stack Eq_17 wArg0C, Stack Eq_17 wArg0E, Stack Eq_17 ptrArg10, Register out (ptr16 Eq_51749) dsOut)
// Called from:
//      fn1229_050A
//      fn1229_061B
//      fn1229_0735
byte fn1229_0040(Eq_17 ds, Eq_17 ptrArg04, Eq_17 wArg08, Eq_17 wArg0A, Eq_17 wArg0C, Eq_17 wArg0E, Eq_17 ptrArg10, struct Eq_51749 & dsOut)
{
	struct Eq_51749 * ds_976;
	word16 dx_1314;
	word16 dx_1312;
	Eq_17 ds_75;
	<unknown> Eq_51542::* fp;
	word16 dx_1308;
	fn1EDA_0A39(~0x00, fp - 0x0102, ptrArg04, out dx_1308);
	fn1AB8_1C32(ds, 11);
	Eq_17 ax_56 = fn1AB8_13A3(ds, wArg08, wArg0A, wArg0C, wArg0E);
	Eq_17 dx_ax_1306 = fn1EDA_023F(ds, wArg0A, wArg0C, ax_56, out ds_75);
	fn1AB8_1E6B(ds_75, dx_ax_1306, wArg08, wArg0A, wArg0C, wArg0E);
	fn1229_0000(ds_75, wArg08, wArg0A, wArg0C, wArg0E);
	fn1AB8_112E(ds_75, wArg08, wArg0A, wArg0C, wArg0E);
	Eq_17 ds_171;
	fn1AB8_1536(ds_75, 0x01, 0x00, 0x00, out ds_171);
	fn1AB8_14F4(ds_171, 0x01, 0x00);
	Eq_17 ax_192;
	ax_192.u3 = &wArg0C.u3->t0000.u0 + (wArg08 - wArg0C >> 0x01);
	struct Eq_51589 * cs;
	byte ch_1309;
	fn1AB8_1D82(ds_171, fp - 0x0102, ax_192, &wArg0E.u3->t0000.u0 + fn1AB8_1E0B(ds_171, &cs->t0036), out ch_1309);
	Eq_17 ptrLoc0416_1084;
	ptrLoc0416_1084.u3 = fp - 0x0312;
	fn1EDA_0A1F((char *) &cs->t0036 + 3, ptrLoc0416_1084);
	fn1EDA_0AAC(fp - 0x0102, ptrLoc0416_1084);
	fn1AB8_108B(ds_171, ax_192, &wArg0E.u3->t0000.u0 + fn1AB8_1E0B(ds_171, ptrLoc0416_1084));
	Eq_17 ax_71 = (word16) dx_ax_1306;
	Eq_17 ax_297 = fn1AB8_10A8(ds_171);
	Eq_526 bLoc0209_1093;
	bLoc0209_1093.u0 = 0x25;
	word16 wLoc0212_1094 = 0x00;
	do
	{
		word16 v35_313 = wLoc0212_1094 + 0x01;
		wLoc0212_1094 = v35_313;
		if (v35_313 == 5000)
		{
			fn1AB8_1C32(ds_171, 11);
			word16 dx_1310;
			fn1AB8_1AF6(ds_171, ax_192 - 0x06, fn1AB8_10A8(ds_171), (word16) ax_192.u2 + 6, fn1AB8_10A8(ds_171), out dx_1310);
		}
		if (v35_313 == 10000)
		{
			fn1AB8_1C32(ds_171, 0x00);
			word16 dx_1311;
			fn1AB8_1AF6(ds_171, ax_192 - 0x06, fn1AB8_10A8(ds_171), (word16) ax_192.u2 + 6, fn1AB8_10A8(ds_171), out dx_1311);
			wLoc0212_1094 = 0x00;
		}
		if (fn1E78_02FB(ds_171) != 0x00)
		{
			fn1AB8_1C32(ds_171, 0x00);
			int16 dx_451;
			fn1AB8_1AF6(ds_171, ax_192 - 0x06, fn1AB8_10A8(ds_171), (word16) ax_192.u2 + 6, fn1AB8_10A8(ds_171), out dx_451);
			fn1AB8_1C32(ds_171, 0x0A);
			Eq_526 al_471 = fn1EDA_1384((byte) fn1E78_030D(dx_451, ds_171, 0x0A, out dx_1312));
			bLoc0209_1093 = al_471;
			if (al_471 >= 0x15 && al_471 <= ~0x00)
			{
				Eq_17 ax_788 = wArg0A - fn1AB8_1E0B(ds_171, &cs->t0036);
				Eq_17 ax_797 = fn1AB8_10A8(ds_171);
				if (false || true && ax_797 < ax_788)
				{
					Eq_17 ptrLoc0416_1183;
					ptrLoc0416_1183.u3 = fp - 0x0312;
					fn1EDA_0B4F(al_471, ptrLoc0416_1183);
					fn1AB8_1492(ds_171, ptrLoc0416_1183);
					Eq_17 ptrLoc0416_1189;
					ptrLoc0416_1189.u3 = fp - 0x0412;
					fn1EDA_0A1F(fp - 0x0208, ptrLoc0416_1189);
					Eq_17 ptrLoc041A_1194;
					ptrLoc041A_1194.u3 = fp - 0x0312;
					fn1EDA_0B4F(al_471, ptrLoc041A_1194);
					fn1EDA_0AAC(ptrLoc041A_1194, ptrLoc0416_1189);
					word16 dx_1313;
					fn1EDA_0A39(~0x00, fp - 0x0208, ptrLoc0416_1189, out dx_1313);
				}
			}
			else if (al_471 == 0x08)
			{
				Eq_17 ax_488 = fn1AB8_10A8(ds_171);
				if (false || true && ax_297 < ax_488)
				{
					Eq_17 ax_509 = fn1AB8_10A8(ds_171);
					fn1229_0000(ds_171, fn1AB8_10BB(ds_171) + (fn1AB8_1783(ds_171, (char *) (&cs->t0036) + 8) >> 0x01), &fn1AB8_10A8(ds_171).u3->t0000.u0 + fn1AB8_1E0B(ds_171, (char *) (&cs->t0036) + 8), fn1AB8_10BB(ds_171) - (fn1AB8_1783(ds_171, (char *) (&cs->t0036) + 8) >> 0x01), fn1AB8_10A8(ds_171) - fn1AB8_1E0B(ds_171, (char *) (&cs->t0036) + 8));
					fn1AB8_108B(ds_171, ax_192, ax_509 - fn1AB8_1E0B(ds_171, (char *) (&cs->t0036) + 8));
					fn1EDA_0BD0(0x01, (uint16) 0x00, fp - 0x0208);
				}
			}
		}
	} while (bLoc0209_1093 != 0x0D);
	fn1AB8_13D7(ds_171, 0x00, dx_ax_1306, wArg0C, wArg0E);
	byte ah_1296 = SLICE(fn1EDA_0254(ds_171, 0x00, ax_71, ax_56, dx_ax_1306, out dx_1314, out ds_976), byte, 8);
	word16 dx_1315;
	fn1EDA_0A39(~0x00, ptrArg10, fp - 0x0208, out dx_1315);
	dsOut = ds_976;
	return ah_1296;
}
