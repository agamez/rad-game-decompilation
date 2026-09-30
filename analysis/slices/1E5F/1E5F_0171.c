// 1E5F:0171: Register byte fn1E5F_0171(Stack (ptr32 code) ptrArg04, Stack byte bArg08, Register out word16 dxOut)
// Called from:
//      fn0800_00C1
//      fn0800_0103
byte fn1E5F_0171(<anonymous> * ptrArg04, byte bArg08, word16 & dxOut)
{
	msdos_set_interrupt_vector(bArg08, ptrArg04);
	dxOut = (word16) ptrArg04;
	return 0x25;
}
