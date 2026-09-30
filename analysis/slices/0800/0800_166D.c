// 0800:166D: Register Eq_17 fn0800_166D(Register Eq_17 ds)
// Called from:
//      fn0800_2827
//      fn0800_2C0C
Eq_17 fn0800_166D(Eq_17 ds)
{
	fn1AB8_0F80(ds);
	int16 dx_22 = fn13E2_0080(ds);
	while (fn1E78_02FB(ds) != 0x00)
	{
		Eq_17 wLoc0112;
		fn1E78_030D(dx_22, ds, wLoc0112, out dx_22);
	}
	Eq_17 ax_44 = fn1AB8_10CE(ds);
	Eq_17 ax_52 = fn1AB8_10E1(ds);
	fn0800_1315(ds, ax_52 - 0x6A, ax_44 - 0x2A, 0x6A, 0x2A);
	fn1AB8_14F4(ds, 0x01, 0x00);
	Eq_17 ds_115;
	fn1AB8_1536(ds, 0x01, 0x00, 0x00, out ds_115);
	uint8 bLoc0D_446 = 0x01;
	int16 dx_327;
	while (true)
	{
		uint8 al_132 = (*((word32) ds_115 + 0x00001106))[(uint16) bLoc0D_446].b0000;
		if (al_132 >= 0x01)
		{
			uint8 bLoc0E_449 = 0x01;
			while (true)
			{
				fn1AB8_1C32(ds_115, 0x00);
				Eq_17 ptrLoc0118_461;
				<unknown> Eq_3962::* fp;
				ptrLoc0118_461.u3 = fp - 0x0110;
				fn1EDA_0B4F(ds_115->*((word16) ((word16) ((uint16) bLoc0D_446 << 0x08) + (uint16) bLoc0E_449) + 0x00001106), ptrLoc0118_461);
				byte ch_542;
				fn1AB8_1D82(ds_115, ptrLoc0118_461, (uint16) bLoc0D_446 *s 0x0D + 113, ((uint16) bLoc0E_449 << 0x03) + 0x31, out ch_542);
				struct Eq_3994 * cs;
				selector es_543;
				if (!fn1EDA_0CD4(&cs->t164D, ds_115->*((word16) ((word16) ((uint16) bLoc0D_446 << 0x08) + (uint16) bLoc0E_449) + 0x00001106), out es_543))
					fn1AB8_1C32(ds_115, 0x0A);
				else
					fn1AB8_1C32(ds_115, 11);
				Eq_17 ptrLoc0118_481;
				ptrLoc0118_481.u3 = fp - 0x0110;
				fn1EDA_0B4F(ds_115->*((word16) ((word16) ((uint16) bLoc0D_446 << 0x08) + (uint16) bLoc0E_449) + 0x00001106), ptrLoc0118_481);
				byte ch_545;
				fn1AB8_1D82(ds_115, ptrLoc0118_481, (uint16) bLoc0D_446 *s 0x0D + 114, ((uint16) bLoc0E_449 << 0x03) + 0x32, out ch_545);
				word16 dx_546;
				fn1E78_029C(ds_115, 0x1E, out dx_546);
				if (bLoc0E_449 == al_132)
					break;
				++bLoc0E_449;
			}
		}
		fn1E78_029C(ds_115, 500, out dx_327);
		if (bLoc0D_446 == 0x12)
			break;
		++bLoc0D_446;
	}
	word16 dx_544;
	fn1E78_030D(dx_327, ds_115, 500, out dx_544);
	word16 wLoc0C_489 = 0x01;
	while (true)
	{
		word16 dx_548;
		word16 dx_547;
		fn1AB8_1E54(ds_115, 0x00, (word16) fn1EDA_0D80(ds_115, ax_52 - 220, out dx_548) + 114, (word16) fn1EDA_0D80(ds_115, ax_44 - 0x5C, out dx_547) + 50);
		if (wLoc0C_489 == 0x7D00)
			break;
		++wLoc0C_489;
	}
	fn1AB8_0F80(ds_115);
	return ds_115;
}
