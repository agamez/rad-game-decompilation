// 0800:0103: void fn0800_0103(Register Eq_17 ds)
// Called from:
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
void fn0800_0103(Eq_17 ds)
{
	if (Mem7[ds:22718:byte] != 0x00)
	{
		word16 dx_52;
		fn1E5F_0171(Mem13[ds:22720:word32], 0x1C, out dx_52);
		Mem24[ds:22718:byte] = 0x00;
	}
}
