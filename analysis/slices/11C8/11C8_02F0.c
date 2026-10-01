/* was audio_configure_opl3_mixer */
// 11C8:02F0: void audio_configure_opl3_mixer()
// Called from:
//      audio_init_soundcard
/* was audio_configure_opl3_mixer */
void audio_configure_opl3_mixer()
{
	audio_write_adlib_register(0x01, 0x20);
	audio_write_adlib_register(0x10, 0x40);
	audio_write_adlib_register(0xF0, 0x60);
	audio_write_adlib_register(0x77, 0x80);
	audio_write_adlib_register(0x98, 0xA0);
	audio_write_adlib_register(0x01, 0x23);
	audio_write_adlib_register(0x00, 0x43);
	audio_write_adlib_register(0xF0, 99);
	audio_write_adlib_register(0x77, 131);
	audio_write_adlib_register(0x31, 0xB0);
}
