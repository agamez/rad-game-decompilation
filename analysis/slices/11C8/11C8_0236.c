// 11C8:0236: Register word16 audio_write_adlib_port(Register Eq_17 ds, Stack byte bArg04)
// Called from:
//      audio_get_soundcard_port
//      audio_write_opl3_register
/* was audio_write_adlib_port */
word16 audio_write_adlib_port(Eq_17 ds, byte bArg04)
{
	__out<byte>(Mem7[ds:22904:word16] + 0x04, 0x04);
	__out<byte>(Mem7[ds:22904:word16] + 0x05, bArg04);
	__out<byte>(Mem7[ds:22904:word16] + 0x04, 0x22);
	__out<byte>(Mem7[ds:22904:word16] + 0x05, bArg04);
	__out<byte>(Mem7[ds:22904:word16] + 0x04, 0x26);
	uint16 ax_30 = Mem7[ds:22904:word16];
	__out<byte>(ax_30 + 0x05, bArg04);
	return ax_30 + 0x05;
}
