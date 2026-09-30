// 1E78:032F: void fn1E78_032F(Stack (ptr32 Eq_61994) ptrArg04)
// Called from:
//      fn1E78_0000
void fn1E78_032F(struct Eq_61994 * ptrArg04)
{
	ptrArg04->w0002 = ~0x284F;
	ptrArg04->w0004 = 0x80;
	ptrArg04->w000C = (word16) ptrArg04 + 0x80;
	ptrArg04->ptr000E = SLICE(ptrArg04, selector, 16);
	ptrArg04->w0010 = 858;
	struct Eq_62389 * cs;
	ptrArg04->ptr0012 = cs;
	ptrArg04->b0030 = 0x00;
}
