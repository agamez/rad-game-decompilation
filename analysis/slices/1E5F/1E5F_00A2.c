// 1E5F:00A2: void fn1E5F_00A2(Stack (ptr32 uint16) ptrArg04, Stack (ptr32 uint16) ptrArg08, Stack (ptr32 uint16) ptrArg0C, Stack (ptr32 Eq_16454) ptrArg10)
// Called from:
//      fn0800_3BF2
//      fn0800_3C72
void fn1E5F_00A2(uint16 * ptrArg04, uint16 * ptrArg08, uint16 * ptrArg0C, struct Eq_16454 * ptrArg10)
{
	uint8 dl_12;
	uint8 dh_11;
	uint8 ch_10;
	uint8 cl_13 = msdos_get_system_time(out ch_10, out dh_11, out dl_12);
	*ptrArg04 = (uint16) dl_12;
	*ptrArg08 = (uint16) dh_11;
	*ptrArg0C = (uint16) cl_13;
	ptrArg10->w0000 = (uint16) ch_10;
}
