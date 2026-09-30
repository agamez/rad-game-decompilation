// 1AB8:1FED: FlagGroup bool fn1AB8_1FED()
// Called from:
//      fn1AB8_1F19
//      fn1AB8_1F9E
bool fn1AB8_1FED()
{
	byte bh_5;
	cu8 bl_6 = bios_video_get_DAC_color_page_state(out bh_5);
	if (true || bl_6 != 0x07 && (bl_6 != 0x08 && (bl_6 < 11 || bl_6 > 0x0C)))
		return false;
	return true;
}
