// 0800:0D20: Register Eq_17 fn0800_0D20(Register Eq_17 ds, Stack Eq_17 ptrArg02, Stack Eq_17 wArg06, Stack Eq_17 wArg08, Stack Eq_17 wArg0A, Stack Eq_17 wArg0C, Stack Eq_17 ptrArg0E)
// Called from:
//      fn0800_11EF
Eq_17 fn0800_0D20(Eq_17 ds, Eq_17 ptrArg02, Eq_17 wArg06, Eq_17 wArg08, Eq_17 wArg0A, Eq_17 wArg0C, Eq_17 ptrArg0E)
{
	word16 dx_1876;
	int16 dx_696;
	Eq_17 ds_200;
	<unknown> Eq_2596::* fp;
	word16 dx_1869;
	fn1EDA_0A39(~0x00, fp - 0x0102, ptrArg02, out dx_1869);
	struct Eq_2608 * cs;
	fn1EDA_04F5(&cs->t0D07, fp - 0x0312);
	fn1EDA_0565(ds, fp - 0x0312);
	Eq_17 ptrLoc051E_1499;
	ptrLoc051E_1499.u3 = fp - 0x0312;
	fn1EDA_0896(ds, 0x06, fp - 0x031A, ptrLoc051E_1499);
	fn1EDA_086C(ds, ptrLoc051E_1499);
	fn1EDA_05BF(ds, fp - 0x0312);
	uint8 bLoc0208_1483 = 0x00;
	if (fn1EDA_04A2(ds) == 0x00)
	{
		word16 dx_1873;
		fn1EDA_0A39(~0x00, fp - 0x0208, fp - 0x031A, out dx_1873);
	}
	fn1AB8_1C32(ds, 11);
	Eq_17 ax_181 = fn1AB8_13A3(ds, wArg06, wArg08, wArg0A, wArg0C);
	Eq_17 dx_ax_1868 = fn1EDA_023F(ds, wArg08, wArg0A, ax_181, out ds_200);
	fn1AB8_1E6B(ds_200, dx_ax_1868, wArg06, wArg08, wArg0A, wArg0C);
	fn0800_0024(ds_200, wArg06, wArg08, wArg0A, wArg0C);
	fn1AB8_112E(ds_200, wArg06, wArg08, wArg0A, wArg0C);
	Eq_17 ds_296;
	fn1AB8_1536(ds_200, 0x01, 0x00, 0x00, out ds_296);
	fn1AB8_14F4(ds_296, 0x01, 0x00);
	Eq_17 ax_317;
	ax_317.u3 = &wArg0A.u3->t0000.u0 + (wArg06 - wArg0A >> 0x01);
	byte ch_1871;
	fn1AB8_1D82(ds_296, fp - 0x0102, ax_317, &wArg0C.u3->t0000.u0 + fn1AB8_1E0B(ds_296, (char *) (&cs->t0D07) + 8), out ch_1871);
	Eq_17 ptrLoc051E_1563;
	ptrLoc051E_1563.u3 = fp - 1050;
	fn1EDA_0A1F((char *) &cs->t0D07 + 11, ptrLoc051E_1563);
	fn1EDA_0AAC(fp - 0x0102, ptrLoc051E_1563);
	fn1AB8_108B(ds_296, ax_317, &wArg0C.u3->t0000.u0 + fn1AB8_1E0B(ds_296, ptrLoc051E_1563));
	Eq_17 ax_422 = fn1AB8_10A8(ds_296);
	fn1AB8_1C32(ds_296, 0x0A);
	byte ch_1872;
	fn1AB8_1D82(ds_296, fp - 0x0208, ax_317, ax_422, out ch_1872);
	Eq_17 ptrLoc051E_1582;
	ptrLoc051E_1582.u3 = fp - 1050;
	fn1EDA_0A1F((char *) &cs->t0D07 + 11, ptrLoc051E_1582);
	fn1EDA_0AAC(fp - 0x0102, ptrLoc051E_1582);
	fn1EDA_0AAC(fp - 0x0208, ptrLoc051E_1582);
	fn1AB8_108B(ds_296, ax_317, &wArg0C.u3->t0000.u0 + fn1AB8_1E0B(ds_296, ptrLoc051E_1582));
	Eq_17 ax_196 = (word16) dx_ax_1868;
	Eq_526 bLoc0209_1592;
	bLoc0209_1592.u0 = 0x25;
	word16 wLoc0212_1593 = 0x00;
	do
	{
		word16 v39_546 = wLoc0212_1593 + 0x01;
		wLoc0212_1593 = v39_546;
		if (v39_546 == 5000)
		{
			fn1AB8_1C32(ds_296, 11);
			word16 dx_1874;
			fn1AB8_1AF6(ds_296, ax_317 - 0x06, fn1AB8_10A8(ds_296), (word16) ax_317.u2 + 6, fn1AB8_10A8(ds_296), out dx_1874);
		}
		if (v39_546 == 10000)
		{
			fn1AB8_1C32(ds_296, 0x00);
			word16 dx_1875;
			fn1AB8_1AF6(ds_296, ax_317 - 0x06, fn1AB8_10A8(ds_296), (word16) ax_317.u2 + 6, fn1AB8_10A8(ds_296), out dx_1875);
			wLoc0212_1593 = 0x00;
		}
		if (fn1E78_02FB(ds_296) != 0x00)
		{
			fn1AB8_1C32(ds_296, 0x00);
			int16 dx_684;
			fn1AB8_1AF6(ds_296, ax_317 - 0x06, fn1AB8_10A8(ds_296), (word16) ax_317.u2 + 6, fn1AB8_10A8(ds_296), out dx_684);
			fn1AB8_1C32(ds_296, 0x0A);
			Eq_17 ax_693 = fn1E78_030D(dx_684, ds_296, 0x0A, out dx_696);
			Eq_526 al_704 = fn1EDA_1384((byte) ax_693);
			bLoc0209_1592 = al_704;
			if (al_704 == 0x00)
			{
				byte al_723 = (byte) fn1E78_030D(dx_696, ds_296, ax_693, out dx_1876);
				if (al_723 == 0x4B)
					bLoc0209_1592.u0 = 0x08;
				else if (al_723 == 0x53)
					bLoc0209_1592.u0 = 0x14;
				else
					bLoc0209_1592.u0 = 0x00;
			}
			if (bLoc0209_1592 >= 0x15 && bLoc0209_1592 <= ~0x00)
			{
				Eq_17 ax_1188 = wArg08 - fn1AB8_1E0B(ds_296, (char *) (&cs->t0D07) + 8);
				Eq_17 ax_1197 = fn1AB8_10A8(ds_296);
				if (false || true && ax_1197 < ax_1188)
				{
					Eq_17 ptrLoc051E_1711;
					ptrLoc051E_1711.u3 = fp - 1050;
					fn1EDA_0B4F(bLoc0209_1592, ptrLoc051E_1711);
					fn1AB8_1492(ds_296, ptrLoc051E_1711);
					Eq_17 ptrLoc051E_1717;
					ptrLoc051E_1717.u3 = fp - 0x051A;
					fn1EDA_0A1F(fp - 0x0208, ptrLoc051E_1717);
					Eq_17 ptrLoc0522_1722;
					ptrLoc0522_1722.u3 = fp - 1050;
					fn1EDA_0B4F(bLoc0209_1592, ptrLoc0522_1722);
					fn1EDA_0AAC(ptrLoc0522_1722, ptrLoc051E_1717);
					word16 dx_1880;
					fn1EDA_0A39(~0x00, fp - 0x0208, ptrLoc051E_1717, out dx_1880);
				}
			}
			else if (bLoc0209_1592 == 0x14)
			{
				fn0800_0024(ds_296, fn1AB8_10BB(ds_296) + (fn1AB8_1783(ds_296, (char *) (&cs->t0D07) + 16) >> 0x01), &ax_422.u3->t0000.u0 + fn1AB8_1E0B(ds_296, (char *) (&cs->t0D07) + 18), fn1AB8_10BB(ds_296) - (fn1AB8_1783(ds_296, (char *) (&cs->t0D07) + 16) >> 0x01), ax_422);
				fn1AB8_108B(ds_296, ax_317, ax_422);
				bLoc0208_1483 = 0x00;
			}
			else if (bLoc0209_1592 == 0x08)
			{
				Eq_17 ax_748 = fn1AB8_10A8(ds_296);
				if (false || true && ax_422 < ax_748)
				{
					Eq_17 ax_769 = fn1AB8_10A8(ds_296);
					fn0800_0024(ds_296, fn1AB8_10BB(ds_296) + (fn1AB8_1783(ds_296, (char *) (&cs->t0D07) + 16) >> 0x01), &fn1AB8_10A8(ds_296).u3->t0000.u0 + fn1AB8_1E0B(ds_296, (char *) (&cs->t0D07) + 16), fn1AB8_10BB(ds_296) - (fn1AB8_1783(ds_296, (char *) (&cs->t0D07) + 16) >> 0x01), fn1AB8_10A8(ds_296) - fn1AB8_1E0B(ds_296, (char *) (&cs->t0D07) + 16));
					fn1AB8_108B(ds_296, ax_317, ax_769 - fn1AB8_1E0B(ds_296, (char *) (&cs->t0D07) + 16));
					fn1EDA_0BD0(0x01, (uint16) bLoc0208_1483, fp - 0x0208);
				}
			}
		}
	} while (bLoc0209_1592 != 0x0D && bLoc0209_1592 != 0x1B);
	if (bLoc0209_1592 == 0x1B)
	{
		word16 dx_1879;
		fn1EDA_0A39(~0x00, fp - 0x0208, fp - 0x031A, out dx_1879);
	}
	fn1AB8_13D7(ds_296, 0x00, dx_ax_1868, wArg0A, wArg0C);
	word16 dx_1877;
	Eq_17 ds_1417;
	fn1EDA_0254(ds_296, 0x00, ax_196, ax_181, dx_ax_1868, out dx_1877, out ds_1417);
	word16 dx_1878;
	fn1EDA_0A39(~0x00, ptrArg0E, fp - 0x0208, out dx_1878);
	return ds_1417;
}
