// 13C8:0139: void fn13C8_0139(Register (ptr16 Eq_18217) ds)
// Called from:
//      fn0800_4255
void fn13C8_0139(struct Eq_18217 * ds)
{
	ds->bB6B2 = 0x00;
	if (fn13C8_0000() != 0x00)
	{
		Eq_17 ds_32;
		fn13C8_000D(out ds_32);
		Eq_481 sp_36;
		sp_36.u0 = <invalid>;
		if (Mem26[ds_32:46766:word16] != 0x00)
			Mem45[ds_32:~0x494D:byte] = 0x01;
		if (Mem47[ds_32:~0x494D:byte] != 0x00)
		{
			selector ss;
			ss->*((word16) sp_36 + 6) = ds_32;
			ss->*((word16) sp_36 + 4) = ~0x494B;
			ss->*((word16) sp_36 + 2) = ds_32;
			ss->*sp_36 = ~0x4949;
			ss->*((word16) sp_36 - 2) = ds_32;
			ss->*((word16) sp_36 - 4) = 46776;
			word16 bp_171;
			selector ds_172;
			fn13C8_0066(out bp_171, out ds_172);
			Eq_481 sp_76;
			sp_76.u0 = <invalid>;
			ss->*((word16) sp_76 + 0x0A) = 0x00;
			ss->*((word16) sp_76 + 8) = 0x0280;
			fn13C8_00BF();
			Eq_481 sp_96;
			sp_96.u0 = <invalid>;
			ss->*((word16) sp_96 + 2) = 0x00;
			ss->*sp_96 = 0x01E0;
			selector ds_173;
			fn13C8_00E4(out ds_173);
		}
	}
}
