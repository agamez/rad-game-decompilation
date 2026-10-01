/* was audio_write_adlib_register */
// 11C8:02DB: void audio_write_adlib_register(Stack byte bArg02, Stack byte bArg04)
// Called from:
//      audio_configure_opl3_mixer
//      audio_write_opl3_register
//      audio_init_soundcard
/* was audio_write_adlib_register */
void audio_write_adlib_register(byte bArg02, byte bArg04)
{
	audio_write_adlib_address(bArg04);
	audio_write_adlib_data(bArg02);
}
