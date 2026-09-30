// 0800:3BF2: void fn0800_3BF2(Stack (ptr32 Eq_16454) ptrArg04)
// Called from:
//      fn0800_3CFA
void fn0800_3BF2(struct Eq_16454 * ptrArg04)
{
	fn1E5F_00A2(&(SLICE(ptrArg04, selector, 16)->*((char *) ((word16) ptrArg04) + 6)), &(SLICE(ptrArg04, selector, 16)->*((char *) ((word16) ptrArg04) + 4)), &(SLICE(ptrArg04, selector, 16)->*((char *) ((word16) ptrArg04) + 2)), ptrArg04);
	ptrArg04->dw0008 = &(&(&fn1EDA_096F(ptrArg04->w0000, 32320, 0x00, 0x05).u3->t0000.u0 + (uint32) (ptrArg04->w0002 *s 6000))->t0000.u0 + (uint32) (ptrArg04->w0004 *s 100))->t0000.u0 + (uint32) ptrArg04->w0006;
}
