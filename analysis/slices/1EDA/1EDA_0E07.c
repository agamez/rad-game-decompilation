// 1EDA:0E07: void fn1EDA_0E07(Register Eq_17 ds)
// Called from:
//      fn0800_4255
void fn1EDA_0E07(Eq_17 ds)
{
	byte dl_7;
	byte dh_6;
	byte ch_5;
	byte cl_8 = msdos_get_system_time(out ch_5, out dh_6, out dl_7);
	Mem11[ds:0x5382:word16] = SEQ(ch_5, cl_8);
	Mem13[ds:0x5384:word16] = SEQ(dh_6, dl_7);
}
