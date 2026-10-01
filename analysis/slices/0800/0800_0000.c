// 0800:0000: Register Eq_17 fn0800_0000(Register Eq_17 ds)
// Called from:
//      fn0800_11EF
//      fn0800_3D9D
//      fn0800_4168
Eq_17 fn0800_0000(Eq_17 ds)
{
	fn1AB8_0EB5(ds);
	fn1AB8_0E88(ds);
	word16 dx_69;
	fn1E78_016B(ds, Mem7[ds:47276:word16], out dx_69);
	audio_init_opl3(ds);
	return fn1EDA_00E9(0x00);
}
