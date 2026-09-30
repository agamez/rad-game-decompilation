// 1E5F:00DE: Register (memptr (ptr16 Eq_61877) byte) fn1E5F_00DE(Register Eq_17 ds, Stack (ptr32 char) ptrArg04, Stack word16 wArg08, Stack (ptr32 Eq_61866) ptrArg0A)
// Called from:
//      fn0C74_0000
byte Eq_61877::* fn1E5F_00DE(Eq_17 ds, char * ptrArg04, word16 wArg08, union Eq_61866 * ptrArg0A)
{
	Eq_61866 al_22;
	al_22.u0 = ptrArg0A->u0;
	if (al_22 >= 0x4F)
		al_22.u0 = 0x4F;
	int16 ax_28 = (int16) al_22;
	byte Eq_61877::* fp;
	memcpy(fp - 82, (char *) ptrArg0A + 1, (uint32) ax_28);
	(fp - 82)[ax_28] = 0x00;
	msdos_set_DTA(ptrArg04);
	struct Eq_61877 * ss;
	msdos_find_first_file(wArg08, &(ss->*(fp - 82)));
	fn1E5F_0136(0x4E00, (word16) ptrArg04, SLICE(ptrArg04, selector, 16), ds);
	return fp - 82;
}
