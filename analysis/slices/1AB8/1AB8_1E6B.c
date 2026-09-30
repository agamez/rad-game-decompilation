// 1AB8:1E6B: void fn1AB8_1E6B(Register Eq_17 ds, Stack Eq_17 ptrArg04, Stack Eq_17 wArg08, Stack Eq_17 wArg0A, Stack Eq_17 wArg0C, Stack Eq_17 wArg0E)
// Called from:
//      fn0800_0D20
//      fn0C74_03D4
//      fn0C74_05B8
//      fn0C74_0E2E
//      fn0C74_0FA1
//      fn0C74_1B3B
//      fn0C74_1D95
//      fn0C74_1F08
//      fn0C74_2AD9
//      fn0C74_2BBD
//      fn0C74_2E5A
//      fn0C74_3236
//      fn0C74_4DAC
//      fn0C74_4FD7
//      fn0C74_5258
//      fn1229_0040
void fn1AB8_1E6B(Eq_17 ds, Eq_17 ptrArg04, Eq_17 wArg08, Eq_17 wArg0A, Eq_17 wArg0C, Eq_17 wArg0E)
{
	Eq_17 cx_10 = wArg0E;
	Eq_17 dx_11 = wArg0C;
	Eq_17 si_12 = wArg0A;
	Eq_17 di_13 = wArg08;
	if (wArg0E >= wArg0A)
	{
		cx_10 = wArg0A;
		si_12 = wArg0E;
	}
	if (wArg0C >= wArg08)
	{
		dx_11 = wArg08;
		di_13 = wArg0C;
	}
	ptrArg04.u3->t0000.u2 = (uint16) (si_12 - cx_10);
	ptrArg04.u3->t0002.u2 = (uint16) (di_13 - dx_11);
	Mem42[ds:0xB820:segptr32]();
}
