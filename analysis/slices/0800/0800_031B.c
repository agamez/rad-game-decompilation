// 0800:031B: Register word16 fn0800_031B(Register Eq_17 ds, Register out Eq_526 bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0800_2401
//      fn0800_2C0C
//      fn0800_31B7
word16 fn0800_031B(Eq_17 ds, union Eq_526 & bpOut, union Eq_17 & dsOut)
{
	Eq_17 ds_104;
	struct Eq_473 Eq_17::* bp_106;
	word16 dx_164;
	byte ch_163;
	word16 ax_13 = fn1206_015B(ds, out ch_163, out dx_164, out bp_106, out ds_104);
	Eq_481 sp_22;
	sp_22.u0 = <invalid>;
	byte ah_140 = SLICE(ax_13, byte, 8);
	struct Eq_486 Eq_17::* sp_100 = (word16) sp_22 + 2;
	selector ss;
	if ((byte) ax_13 != 0x00)
	{
		Mem43[ss:bp_106 + -4:word16] = CONVERT(Mem11[ds_104:22914:word16] - 0x17, int16, int32) /16 0x34;
		if (Mem43[ds_104:22916:word16] > 0x0198 && Mem43[ds_104:22916:word16] < 0x01C4)
		{
			if (Mem43[ds_104:0x58B0:byte] != 0x00)
			{
				ss->*sp_22 = 400;
				audio_write_opl3_register(ds_104, ss->*sp_22);
			}
			sp_100 = (word16) sp_22 + 2;
			int16 ax_64 = (ss->*bp_106).wFFFC;
			if (ax_64 == 0x00)
				(ss->*bp_106).bFFF9 = 0x48;
			else if (ax_64 == 0x01)
				(ss->*bp_106).bFFF9 = 0x4B;
			else if (ax_64 == 0x02)
				(ss->*bp_106).bFFF9 = 0x20;
			else if (ax_64 == 0x03)
				(ss->*bp_106).bFFF9 = 77;
			else if (ax_64 == 0x04)
				(ss->*bp_106).bFFF9 = 0x50;
			else if (ax_64 == 0x05)
				(ss->*bp_106).bFFF9 = 0x3B;
			else if (ax_64 == 0x06)
				(ss->*bp_106).bFFF9 = 0x3C;
			else if (ax_64 == 0x07)
				(ss->*bp_106).bFFF9 = 0x3D;
			else if (ax_64 == 0x08)
				(ss->*bp_106).bFFF9 = 0x1B;
			audio_get_soundcard_port(ds_104);
		}
		word16 ax_105;
		do
		{
			(ss->*sp_100).wFFFE = 0x00;
			byte ch_165;
			word16 dx_166;
			ax_105 = fn1206_015B(ds_104, out ch_165, out dx_166, out bp_106, out ds_104);
			Eq_481 sp_114;
			sp_114.u0 = <invalid>;
			ah_140 = SLICE(ax_105, byte, 8);
			sp_100 = (word16) sp_114 + 2;
		} while ((byte) ax_105 != 0x00);
	}
	(ss->*bp_106).bFFFF = (ss->*bp_106).bFFF9;
	word16 ax_143 = SEQ(ah_140, (ss->*bp_106).bFFFF);
	bpOut.u1 = (ss->*bp_106).t0000.u1;
	dsOut = ds_104;
	return ax_143;
}
