// 1E5F:0159: void fn1E5F_0159(Stack (ptr32 word32) ptrArg04, Stack byte bArg08)
// Called from:
//      fn0800_00C1
void fn1E5F_0159(word32 * ptrArg04, byte bArg08)
{
	*ptrArg04 = msdos_get_interrupt_vector(bArg08);
}
