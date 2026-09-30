// 1AB8:180A: void fn1AB8_180A(Register Eq_17 ds)
// Called from:
//      fn1AB8_1AA6
void fn1AB8_180A(Eq_17 ds)
{
	if (Mem0[ds:47267:byte] != ~0x00)
		return;
	if (Mem0[ds:0xB850:byte] != 0xA5)
	{
		byte ah_11;
		byte bh_12;
		Mem14[ds:47267:byte] = bios_video_get_current_video_mode(out ah_11, out bh_12);
		byte al_18 = (byte) 0040:0010;
		Mem19[ds:0xB8A4:byte] = al_18;
		if (Mem19[ds:0xB89C:byte] != 0x05 && Mem19[ds:0xB89C:byte] != 0x07)
			0040:0010 = (byte *) (al_18 & ~0x30 | 0x20);
	}
	else
		Mem30[ds:47267:byte] = 0x00;
}
