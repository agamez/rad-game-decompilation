// 1EDA:119A: FlagGroup bool fn1EDA_119A(Register Eq_17 ds, Stack Eq_17 ptrArg06, Sequence out ui32 bx_cxOut, Sequence out (ptr32 int32) dx_axOut, Sequence out segptr32 es_diOut)
// Called from:
//      fn1EDA_116A
//      fn1EDA_1185
bool fn1EDA_119A(Eq_17 ds, Eq_17 ptrArg06, ui32 & bx_cxOut, int32 & dx_axOut, segptr32 & es_diOut)
{
	int32 * dx_ax_58;
	if (ptrArg06.u3->t0002.u2 != 55219)
	{
		Mem13[ds:0x5380:word16] = 0x67;
		bx_cxOut = <invalid>;
		dx_axOut = (int32 *) <invalid>;
		es_diOut = <invalid>;
		return true;
	}
	else
	{
		int32 * dx_ax_25;
		msdos_set_file_position(ptrArg06.u3->t0000.u2, 0x00000000<p32>, 0x01, out dx_ax_25);
		int32 * dx_ax_41;
		msdos_set_file_position(ptrArg06.u3->t0000.u2, 0x00000000<p32>, 0x02, out dx_ax_41);
		word32 C_59 = msdos_set_file_position(ptrArg06.u3->t0000.u2, dx_ax_25, 0x00, out dx_ax_58);
		bx_cxOut = <invalid>;
		dx_axOut = (int32 *) <invalid>;
		es_diOut = <invalid>;
		return C_59 != 0x00;
	}
}
