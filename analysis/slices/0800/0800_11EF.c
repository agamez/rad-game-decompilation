// 0800:11EF: Register Eq_17 fn0800_11EF(Register Eq_17 ds)
// Called from:
//      fn0800_3D9D
Eq_17 fn0800_11EF(Eq_17 ds)
{
	byte ch_469;
	Eq_17 ds_204;
	byte ch_461;
	word16 bp_12;
	Eq_17 ds_16;
	fn1206_0066(ds, out bp_12, out ds_16);
	Eq_481 sp_20;
	sp_20.u0 = <invalid>;
	Eq_17 ss;
	ss->*((word16) sp_20 - 2) = ss;
	ss->*((word16) sp_20 - 4) = bp_12 - 0x018C;
	ss->*((word16) sp_20 - 6) = (int32) fn1AB8_10CE(ds_16) /16 0x02 - 0x68;
	ss->*((word16) sp_20 - 8) = 0x8E;
	ss->*((word16) sp_20 - 0x0A) = (int32) fn1AB8_10CE(ds_16) /16 0x02 + 0x68;
	ss->*((word16) sp_20 - 0x0C) = 0xA0;
	Eq_17 cs;
	ss->*((word16) sp_20 - 0x0E) = cs;
	ss->*((word16) sp_20 - 16) = 0x11D8;
	Eq_17 ds_76 = fn0800_0D20(ds_16, ss->*((word16) sp_20 - 16), ss->*((word16) sp_20 - 0x0C), ss->*((word16) sp_20 - 0x0A), ss->*((word16) sp_20 - 8), ss->*((word16) sp_20 - 6), ss->*((word16) sp_20 - 4));
	ss->*((word16) sp_20 - 6) = ss;
	ss->*((word16) sp_20 - 8) = bp_12 - 8;
	ss->*((word16) sp_20 - 0x0A) = 0x06;
	word16 dx_455;
	fn1EDA_0A39(ss->*((word16) sp_20 + 0x0A), ss->*((word16) sp_20 - 8), ss->*((word16) sp_20 - 4), out dx_455);
	byte ch_456;
	word16 dx_457;
	word16 bp_108;
	Eq_17 ds_112;
	fn1206_0038(ds_76, out ch_456, out dx_457, out bp_108, out ds_112);
	Eq_481 sp_116;
	sp_116.u0 = <invalid>;
	ss->*((word16) sp_116 - 2) = cs;
	ss->*((word16) sp_116 - 4) = 0x11E7;
	word16 dx_458;
	if (fn0C74_0000(ds_112, ss->*((word16) sp_116 - 4), out dx_458) == 0x00)
		ds_112 = fn0800_0000(ds_112);
	ss->*((word16) sp_116 - 2) = ss;
	ss->*((word16) sp_116 - 4) = bp_108 - 0x88;
	ss->*((word16) sp_116 - 6) = cs;
	ss->*((word16) sp_116 - 8) = 0x11E7;
	fn1EDA_0FA2(ss->*((word16) sp_116 - 8), ss->*((word16) sp_116 - 4));
	ss->*((word16) sp_116 - 2) = ss;
	ss->*((word16) sp_116 - 4) = bp_108 - 0x88;
	ss->*((word16) sp_116 - 6) = 0x0219;
	word16 dx_459;
	fn1EDA_0FD0(ds_112, ss->*((word16) sp_116 - 6), ss->*((word16) sp_116 - 4), out dx_459);
	byte al_235 = (byte) fn1EDA_04A9(ds_112, ss->*((word16) sp_116 - 4), ss->*((word16) sp_116 - 2), out ch_461, out ds_204);
	Mem211[ds_204:22926:word16] = ~0x00;
	Mem212[ds_204:22928:word16] = ~0x00;
	Eq_17 ax_324;
	do
	{
		Mem220[ds_204:22926:ui32] = Mem216[ds_204:22926:ui32] + 0x01;
		ss->*((word16) sp_116 - 2) = ss;
		ss->*((word16) sp_116 - 4) = bp_108 - 0x88;
		ss->*((word16) sp_116 - 6) = ds_204;
		ss->*((word16) sp_116 - 8) = 23732;
		fn1EDA_1085(al_235, ds_204, ss->*((word16) sp_116 - 4));
		byte ch_471;
		fn1EDA_04A9(ds_204, ss->*((word16) sp_116 + 0x0000FFFC), ss->*((word16) sp_116 - 2), out ch_471, out ds_204);
		ss->*((word16) sp_116 - 2) = ds_204;
		ss->*((word16) sp_116 - 4) = 23732;
		ss->*((word16) sp_116 - 6) = ss;
		ss->*((word16) sp_116 - 8) = bp_108 - 8;
		Eq_17 ax_454;
		ax_324 = ax_454;
		word16 dx_472;
		if (fn1EDA_0B24(ss->*((word16) sp_116 - 8), ss->*((word16) sp_116 - 4), out ax_454, out dx_472))
			break;
		ss->*((word16) sp_116 - 2) = ss;
		ss->*((word16) sp_116 - 4) = bp_108 - 0x88;
		fn1EDA_1185(ds_204, ss->*((word16) sp_116 - 4));
		Eq_17 ax_300 = (word16) fn1EDA_04A9(ds_204, ss->*((word16) sp_116 - 4), ss->*((word16) sp_116 - 2), out ch_469, out ds_204);
		ax_324 = ax_300;
		if ((byte) ax_300 != 0x00)
			break;
		int32 dx_ax_320 = CONVERT(CONVERT(Mem288[ds_204:0x02:byte], uint8, uint16) - 0x01, int16, int32);
		ax_324 = (word16) dx_ax_320;
		al_235 = (byte) dx_ax_320;
	} while (Mem288[ds_204:22928:word16] != 0x00 || ax_324 != Mem288[ds_204:22926:word16]);
	ss->*((word16) sp_116 - 2) = ss;
	ss->*((word16) sp_116 - 4) = bp_108 - 0x88;
	fn1EDA_1051((byte) ax_324, ds_204, ss->*((word16) sp_116 - 4));
	byte ch_464;
	Eq_17 ds_353;
	fn1EDA_04A9(ds_204, ss->*((word16) sp_116 + 0x0000FFFC), ss->*((word16) sp_116 - 2), out ch_464, out ds_353);
	ss->*((word16) sp_116 - 2) = ss;
	ss->*((word16) sp_116 - 4) = bp_108 - 8;
	ss->*((word16) sp_116 - 6) = ds_353;
	ss->*((word16) sp_116 - 8) = 24278;
	ss->*((word16) sp_116 - 0x0A) = 0x06;
	word16 dx_465;
	fn1EDA_0A39(ss->*((word16) sp_116 + 0x0A), ss->*((word16) sp_116 - 8), ss->*((word16) sp_116 - 4), out dx_465);
	ss->*((word16) sp_116 - 2) = ds_353;
	ss->*((word16) sp_116 - 4) = 23732;
	ss->*((word16) sp_116 - 6) = ss;
	ss->*((word16) sp_116 - 8) = bp_108 - 8;
	word16 ax_466;
	word16 dx_467;
	if (!fn1EDA_0B24(ss->*((word16) sp_116 - 8), ss->*((word16) sp_116 - 4), out ax_466, out dx_467))
	{
		Mem409[ds_353:22926:word16] = 0x01;
		Mem410[ds_353:22928:word16] = 0x00;
	}
	return ds_353;
}
