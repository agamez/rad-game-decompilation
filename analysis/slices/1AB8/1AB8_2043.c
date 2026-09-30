// 1AB8:2043: Register word16 fn1AB8_2043()
// Called from:
//      fn1AB8_1F19
word16 fn1AB8_2043()
{
	bios_video_unknown_1030();
	if (false)
	{
		byte al_20 = (byte) 0000:0002;
		if ((al_20 == 0x00 || al_20 == 0x02) && (__in<byte>(0x0188) & 0x04) != 0x00)
			return 0x01;
	}
	return 0x00;
}
