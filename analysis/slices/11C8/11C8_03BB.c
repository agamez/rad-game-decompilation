/* was audio_init_opl3 */
// 11C8:03BB: void audio_init_opl3(Register Eq_17 ds)
// Called from:
//      fn0800_0000
/* was audio_init_opl3 */
void audio_init_opl3(Eq_17 ds)
{
	if (Mem7[ds:22902:byte] != 0x00)
	{
		audio_enable_opl3();
		audio_sweep_adlib_ports();
	}
}
