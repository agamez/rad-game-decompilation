// 1AB8:1F80: FlagGroup bool fn1AB8_1F80(Register out byte clOut, Register out Eq_481 bxOut)
// Called from:
//      fn1AB8_1F19
bool fn1AB8_1F80(byte & clOut, union Eq_481 & bxOut)
{
	ci8 cl_9;
	byte ch_8;
	ci8 bl_7;
	ci8 bh_10 = bios_video_get_EGA_info(out bl_7, out ch_8, out cl_9);
	if (cl_9 >= 0x0C || (bh_10 > 0x01 || bl_7 > 0x03))
	{
		clOut = <invalid>;
		bxOut.u0 = <invalid>;
		return false;
	}
	else
	{
		clOut = <invalid>;
		bxOut.u0 = <invalid>;
		return true;
	}
}
