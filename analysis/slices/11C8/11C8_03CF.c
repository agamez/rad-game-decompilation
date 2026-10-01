/* was audio_disable_soundcard */
// 11C8:03CF: void audio_disable_soundcard(Register Eq_17 ds)
// Called from:
//      fn0800_4255
/* was audio_disable_soundcard */
void audio_disable_soundcard(Eq_17 ds)
{
	Mem10[ds:22902:byte] = 0x00;
}
