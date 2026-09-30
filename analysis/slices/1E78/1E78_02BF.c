// 1E78:02BF: Register uint16 fn1E78_02BF(Sequence (ptr32 uint8) es_di, Register uint8 al, Register uint16 cx)
// Called from:
//      fn1E78_002E
//      fn1E78_029C
uint16 fn1E78_02BF(uint8 * es_di, uint8 al, uint16 cx)
{
	while (al == *es_di)
	{
		--cx;
		if (cx == 0x00)
			return cx;
	}
	return cx;
}
