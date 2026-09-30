// 0800:01FE: void fn0800_01FE(Register Eq_17 ds)
// Called from:
//      fn0800_2827
//      fn0800_2C0C
void fn0800_01FE(Eq_17 ds)
{
	struct Eq_291 * cs;
	<unknown> Eq_294::* fp;
	fn1EDA_0FA2(&cs->t01F6, fp - 0x0082);
	word16 dx_346;
	fn1EDA_0FD0(ds, 0x0219, fp - 0x0082, out dx_346);
	struct Eq_294 * ss;
	fn1EDA_1051(SLICE(fn1EDA_1085(fn1EDA_1123(ds, Mem58[ds:22926:word16], Mem55[ds:22928:word16], SEQ(ss, fp - 0x0082)), ds, SEQ(ss, fp - 0x0082)), byte, 0), ds, SEQ(ss, fp - 0x0082));
	word16 dx_348;
	fn1EDA_0A39(0x06, SEQ(ds, 0x5ECE), SEQ(ds, 23732), out dx_348);
	Mem137[ds:0x53D9:byte] = Mem122[ds:23774:byte];
	Mem139[ds:21466:byte] = Mem137[ds:23775:byte];
	Mem141[ds:0x53DB:byte] = Mem139[ds:23770:byte];
	Mem143[ds:0x53DC:byte] = Mem141[ds:23771:byte];
	if (Mem143[ds:23772:byte] >u 0x0A)
		Mem146[ds:23772:byte] = 0x0A;
	Mem150[ds:0x53DD:byte] = Mem148[ds:23772:byte];
	Mem152[ds:0x53DE:byte] = Mem150[ds:23773:byte];
	fn0800_0024(ds, 0x0176, 0x027E, 0x01, 0x01);
	uint8 bLoc84_301 = 0x00;
	while (true)
	{
		uint8 bLoc83_302 = 0x00;
		while (true)
		{
			if (ds->*((word16) ((word16) ((uint16) bLoc84_301 *s 0x1D) + (uint16) bLoc83_302) + 23776) != 0x00)
				fn1AB8_13D7(ds, 0x00, ds.u3->ptr5992[(uint16) (ds->*((word16) ((word16) ((uint16) bLoc84_301 *s 0x1D) + (uint16) bLoc83_302) + 23776))].u3, (uint16) bLoc84_301 *s 22 + 0x01, (uint16) bLoc83_302 *s 22 + 0x01);
			if (bLoc83_302 == 0x1C)
				break;
			++bLoc83_302;
		}
		if (bLoc84_301 == 0x10)
			break;
		++bLoc84_301;
	}
}
