/* was audio_sweep_adlib_ports */
// 11C8:02AB: void audio_sweep_adlib_ports()
// Called from:
//      audio_init_soundcard
//      audio_init_opl3
/* was audio_sweep_adlib_ports */
void audio_sweep_adlib_ports()
{
	byte bLoc03_43 = 0x01;
	while (true)
	{
		audio_write_adlib_address(bLoc03_43);
		audio_write_adlib_data(0x00);
		if (bLoc03_43 == ~0x0A)
			break;
		++bLoc03_43;
	}
}
