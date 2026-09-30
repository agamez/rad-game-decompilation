// 1EDA:0491: Sequence Eq_63252 fn1EDA_0491(Register Eq_17 ax)
// Called from:
//      fn1EDA_0308
//      fn1EDA_03D3
Eq_63252 fn1EDA_0491(Eq_17 ax)
{
	return SEQ(__rcr<word16,byte>((word32) ax + 7, 0x01, cond((word32) ax + 7) & 0x02) >> 0x03, (word32) ax + 7 & 0x08);
}
