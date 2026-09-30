// 1229:0AA8: Register Eq_17 fn1229_0AA8(Register Eq_17 ds)
// Called from:
//      fn1229_0CCE
//      fn1229_0DCC
Eq_17 fn1229_0AA8(Eq_17 ds)
{
	fn1AB8_0F93(ds, 0x01, 0x0176, 0x027E, 0x01, 0x01);
	fn1AB8_1028(ds);
	fn1AB8_0F93(ds, 0x01, 0x01DF, 0x027F, 0x00, 0x00);
	uint8 bLoc04_623 = 0x00;
	while (true)
	{
		uint8 bLoc03_624 = 0x00;
		while (true)
		{
			if (ds->*((word16) ((word16) ((uint16) bLoc04_623 *s 0x1D) + (uint16) bLoc03_624) + 23776) != 0x00)
				fn1AB8_13D7(ds, 0x00, ds.u3->ptr5992[(uint16) (ds->*((word16) ((word16) ((uint16) bLoc04_623 *s 0x1D) + (uint16) bLoc03_624) + 23776))].u3, (uint16) bLoc04_623 *s 22 + 0x01, (uint16) bLoc03_624 *s 22 + 0x01);
			if (bLoc03_624 == 0x1C)
				break;
			++bLoc03_624;
		}
		if (bLoc04_623 == 0x10)
			break;
		++bLoc04_623;
	}
	fn1AB8_0F93(ds, 0x01, 0x0182, 0x027E, 0x0178, Mem134[ds:0x50C4:word16]);
	fn1AB8_1028(ds);
	fn1AB8_0F93(ds, 0x01, 0x01DF, 0x027F, 0x00, 0x00);
	fn1AB8_14F4(ds, 0x01, 0x00);
	Eq_17 ds_227;
	fn1AB8_1536(ds, 0x04, 0x00, 0x02, out ds_227);
	Eq_17 ptrLoc0608_658;
	<unknown> Eq_53644::* fp;
	ptrLoc0608_658.u3 = fp - 0x0204;
	fn1229_09F9(Mem238[ds_227:22926:byte], ptrLoc0608_658);
	struct Eq_53657 * cs;
	fn1EDA_0AAC(&cs->t0A8B, ptrLoc0608_658);
	fn1EDA_0AAC(SEQ(ds_227, 23732), ptrLoc0608_658);
	fn1EDA_0AAC(&cs->t0A8B, ptrLoc0608_658);
	fn1EDA_0AAC((char *) &cs->t0A8B + 2, ptrLoc0608_658);
	Eq_17 ptrLoc060C_675;
	ptrLoc060C_675.u3 = fp - 772;
	fn1229_09F9(Mem333[ds_227:23772:byte], ptrLoc060C_675);
	fn1EDA_0AAC(ptrLoc060C_675, ptrLoc0608_658);
	fn1EDA_0AAC((char *) &cs->t0A8B + 8, ptrLoc0608_658);
	Eq_17 ptrLoc060C_683;
	ptrLoc060C_683.u3 = fp - 0x0404;
	fn1229_09F9(Mem387[ds_227:23770:byte], ptrLoc060C_683);
	fn1EDA_0AAC(ptrLoc060C_683, ptrLoc0608_658);
	fn1EDA_0AAC((char *) &cs->t0A8B + 0x0F, ptrLoc0608_658);
	Eq_17 ptrLoc060C_691;
	ptrLoc060C_691.u3 = fp - 0x0504;
	fn1229_09F9(Mem441[ds_227:23773:byte], ptrLoc060C_691);
	fn1EDA_0AAC(ptrLoc060C_691, ptrLoc0608_658);
	fn1EDA_0AAC((char *) &cs->t0A8B + 22, ptrLoc0608_658);
	Eq_17 ptrLoc060C_699;
	ptrLoc060C_699.u3 = fp - 0x0604;
	fn1229_09F9(Mem495[ds_227:23771:byte], ptrLoc060C_699);
	fn1EDA_0AAC(ptrLoc060C_699, ptrLoc0608_658);
	fn1EDA_0AAC(&cs->t0A8B, ptrLoc0608_658);
	fn1EDA_0AAC(SEQ(ds_227, 0x5CBB), ptrLoc0608_658);
	word16 dx_724;
	fn1EDA_0A39(~0x00, fp - 0x0104, ptrLoc0608_658, out dx_724);
	byte ch_725;
	fn1AB8_1D82(ds_227, fp - 0x0104, 0x017D, Mem569[ds_227:0x50C4:word16] + 22, out ch_725);
	return ds_227;
}
