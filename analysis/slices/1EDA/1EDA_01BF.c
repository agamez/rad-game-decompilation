// 1EDA:01BF: Register uint8 fn1EDA_01BF(Register uint8 al, Register bu8 cl)
// Called from:
//      fn1EDA_01B3
uint8 fn1EDA_01BF(uint8 al, bu8 cl)
{
	uint16 ax_6 = (uint16) al;
	uint8 ah_9 = ax_6 % cl;
	uint8 al_10 = ax_6 /u cl;
	fn1EDA_01E7(al_10 + 0x30);
	return ah_9;
}
