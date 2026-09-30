// 1AB8:0569: Register word16 fn1AB8_0569(Stack Eq_58035 ptrArg02, Stack Eq_58036 ptrArg06, Stack Eq_58036 wArg0A, Stack (ptr16 Eq_13) wArg0C, Register out uint16 dxOut)
// Called from:
//      fn1AB8_05D3
//      fn1AB8_06CA
//      fn1AB8_0BAE
word16 fn1AB8_0569(Eq_58035 ptrArg02, Eq_58036 ptrArg06, Eq_58036 wArg0A, struct seg1AB8_t * wArg0C, uint16 & dxOut)
{
	cu16 v11_14 = (cu16) ((char *) wArg0A.u1 + *ptrArg06.u1);
	uint16 ax_20 = wArg0C + (v11_14 >> 0x04);
	if ((v11_14 & 0x0F) != 0x00)
	{
		fn1EDA_11DF(*ptrArg02.u1, SEQ(ax_20, 0x00), v11_14);
		*ptrArg06.u1 -= v11_14 & 0x0F;
	}
	dxOut = ax_20;
	return 0x00;
}
