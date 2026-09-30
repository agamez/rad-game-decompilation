// 1EDA:01D4: void fn1EDA_01D4(Register byte al)
// Called from:
//      fn1EDA_01CD
void fn1EDA_01D4(byte al)
{
	word16 ax;
	bcu8 al_9 = (byte) ax;
	fn1EDA_01DF(al_9 >> 0x04);
	byte al_21 = (byte) ax;
	fn1EDA_01DF(al_21 & 0x0F);
}
