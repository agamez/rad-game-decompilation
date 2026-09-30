// 1EDA:01B3: void fn1EDA_01B3(Register uint8 al)
// Called from:
//      fn1EDA_00E9
void fn1EDA_01B3(uint8 al)
{
	uint8 al_20 = fn1EDA_01BF(fn1EDA_01BF(al, 100), 0x0A);
	fn1EDA_01E7(al_20 + 0x30);
}
