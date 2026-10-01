/* was audio_write_adlib_address */
// 11C8:0282: void audio_write_adlib_address(Stack byte bArg02)
// Called from:
//      audio_sweep_adlib_ports
//      audio_enable_opl3
//      audio_write_adlib_register
/* was audio_write_adlib_address */
void audio_write_adlib_address(byte bArg02)
{
	__out<byte>(0x0388, bArg02);
	word16 cx_11;
	for (cx_11 = 0x06; cx_11 != 0x00; --cx_11)
		__in<byte>(0x0388);
}
