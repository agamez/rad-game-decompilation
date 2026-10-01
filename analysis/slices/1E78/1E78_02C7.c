// 1E78:02C7: void fn1E78_02C7(Stack Eq_17 wArg04)
// Called from:
//      audio_write_opl3_register
//      fn1229_0486
//      fn1229_0DCC
void fn1E78_02C7(Eq_17 wArg04)
{
	if (wArg04 > 0x12)
	{
		uint16 ax_15 = 1193181 /u wArg04;
		byte bl_28 = (byte) ax_15;
		byte bh_31 = SLICE(ax_15, byte, 8);
		byte al_17 = __in<byte>(0x61);
		if ((al_17 & 0x03) == 0x00)
		{
			__out<byte>(0x61, al_17 | 0x03);
			__out<byte>(0x43, ~0x49);
		}
		__out<byte>(66, bl_28);
		__out<byte>(66, bh_31);
	}
}
