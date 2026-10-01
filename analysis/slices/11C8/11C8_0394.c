/* was audio_init_soundcard */
// 11C8:0394: void audio_init_soundcard(Register Eq_17 ds)
// Called from:
//      fn0800_4255
/* was audio_init_soundcard */
void audio_init_soundcard(Eq_17 ds)
{
	audio_detect_and_init_sb(ds);
	if (Mem7[ds:22902:byte] != 0x00)
	{
		Mem24[ds:0x5975:byte] = 0x00;
		audio_sweep_adlib_ports();
		audio_write_adlib_register(0x10, 0x01);
		audio_configure_opl3_mixer();
		audio_get_soundcard_port(ds);
	}
}
