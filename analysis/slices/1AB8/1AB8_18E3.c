// 1AB8:18E3: void fn1AB8_18E3(Register Eq_17 ds)
// Called from:
//      fn1AB8_0E88
void fn1AB8_18E3(Eq_17 ds)
{
	if (Mem7[ds:47267:byte] != ~0x00)
	{
		Mem7[ds:0xB820:segptr32]();
		if (Mem7[ds:0xB850:byte] != 0xA5)
		{
			Mem24[0040:0010:byte] = Mem7[ds:0xB8A4:byte];
			bios_video_set_mode(Mem24[ds:47267:byte]);
		}
	}
	Mem31[ds:47267:byte] = ~0x00;
}
