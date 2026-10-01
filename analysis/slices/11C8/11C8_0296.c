/* was audio_write_adlib_data */
// 11C8:0296: void audio_write_adlib_data(Stack byte bArg02)
// Called from:
//      audio_sweep_adlib_ports
//      audio_enable_opl3
//      audio_write_adlib_register
/* was audio_write_adlib_data */
void audio_write_adlib_data(byte bArg02)
{
	__out<byte>(0x0389, bArg02);
	word16 cx_11;
	for (cx_11 = 0x35; cx_11 != 0x00; --cx_11)
		__in<byte>(0x0388);
}
