// 1EDA:01DF: void fn1EDA_01DF(Register uint8 al)
// Called from:
//      fn1EDA_01D4
void fn1EDA_01DF(uint8 al)
{
	if (al < 0x0A)
		fn1EDA_01E7(al + 0x30);
	else
		fn1EDA_01E7(al + 55);
}
