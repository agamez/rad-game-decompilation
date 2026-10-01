/* was audio_enable_opl3 */
// 11C8:02CC: void audio_enable_opl3()
// Called from:
//      audio_init_opl3
/* was audio_enable_opl3 */
void audio_enable_opl3()
{
	audio_write_adlib_address(0xB0);
	audio_write_adlib_data(0x11);
}
