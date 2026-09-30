// 0800:149F: Register Eq_17 fn0800_149F(Register Eq_17 ds)
// Called from:
//      fn0800_3D9D
Eq_17 fn0800_149F(Eq_17 ds)
{
	fn1AB8_0F80(ds);
	Eq_17 ax_20 = fn1AB8_10CE(ds);
	Eq_17 ax_28 = fn1AB8_10E1(ds);
	fn0800_1315(ds, ax_28 - 0x6A, ax_20 - 0x2A, 0x6A, 0x2A);
	fn1AB8_14F4(ds, 0x01, 0x00);
	Eq_17 ds_90;
	fn1AB8_1536(ds, 0x01, 0x00, 0x00, out ds_90);
	uint8 bLoc0D_409 = 0x01;
	int16 dx_302;
	while (true)
	{
		uint8 al_107 = (uint8) (ds_90->*((word16) ((uint16) bLoc0D_409 << 0x08) - 0x00FA));
		if (al_107 >= 0x01)
		{
			uint8 bLoc0E_412 = 0x01;
			while (true)
			{
				fn1AB8_1C32(ds_90, 0x00);
				Eq_17 ptrLoc0118_424;
				<unknown> Eq_3765::* fp;
				ptrLoc0118_424.u3 = fp - 0x0110;
				fn1EDA_0B4F(ds_90->*((word16) ((word16) ((uint16) bLoc0D_409 << 0x08) + (uint16) bLoc0E_412) - 0x00FA), ptrLoc0118_424);
				byte ch_500;
				fn1AB8_1D82(ds_90, ptrLoc0118_424, (uint16) bLoc0D_409 *s 0x0D + 113, ((uint16) bLoc0E_412 << 0x03) + 0x31, out ch_500);
				struct Eq_3797 * cs;
				selector es_501;
				if (!fn1EDA_0CD4(&cs->t147F, ds_90->*((word16) ((word16) ((uint16) bLoc0D_409 << 0x08) + (uint16) bLoc0E_412) - 0x00FA), out es_501))
					fn1AB8_1C32(ds_90, 0x0A);
				else
					fn1AB8_1C32(ds_90, 11);
				Eq_17 ptrLoc0118_444;
				ptrLoc0118_444.u3 = fp - 0x0110;
				fn1EDA_0B4F(ds_90->*((word16) ((word16) ((uint16) bLoc0D_409 << 0x08) + (uint16) bLoc0E_412) - 0x00FA), ptrLoc0118_444);
				byte ch_503;
				fn1AB8_1D82(ds_90, ptrLoc0118_444, (uint16) bLoc0D_409 *s 0x0D + 114, ((uint16) bLoc0E_412 << 0x03) + 0x32, out ch_503);
				word16 dx_504;
				fn1E78_029C(ds_90, 0x1E, out dx_504);
				if (bLoc0E_412 == al_107)
					break;
				++bLoc0E_412;
			}
		}
		fn1E78_029C(ds_90, 500, out dx_302);
		if (bLoc0D_409 == 0x12)
			break;
		++bLoc0D_409;
	}
	word16 dx_502;
	fn1E78_030D(dx_302, ds_90, 500, out dx_502);
	word16 wLoc0C_452 = 0x01;
	while (true)
	{
		word16 dx_506;
		word16 dx_505;
		fn1AB8_1E54(ds_90, 0x00, (word16) fn1EDA_0D80(ds_90, ax_28 - 220, out dx_506) + 114, (word16) fn1EDA_0D80(ds_90, ax_20 - 0x5C, out dx_505) + 50);
		if (wLoc0C_452 == 0x7D00)
			break;
		++wLoc0C_452;
	}
	fn1AB8_0F80(ds_90);
	return ds_90;
}
