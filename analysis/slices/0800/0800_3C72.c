// 0800:3C72: Register word16 fn0800_3C72(Stack (ptr32 Eq_16513) ptrArg04, Register out ci16 dxOut)
// Called from:
//      fn0800_3CFA
word16 fn0800_3C72(struct Eq_16513 * ptrArg04, ci16 & dxOut)
{
	<unknown> Eq_16515::* fp;
	fn1E5F_00A2(fp - 0x0E, fp - 0x0C, fp - 0x0A, fp - 8);
	uint16 wLoc08;
	int16 wLoc0A;
	int16 wLoc0C;
	word16 wLoc0E;
	ptrArg04->dw000C = &(&(&fn1EDA_096F(wLoc08, 32320, 0x00, 0x05).u3->t0000.u0 + (uint32) (wLoc0A *s 6000))->t0000.u0 + (uint32) (wLoc0C *s 100))->t0000.u0 + (uint32) wLoc0E;
	ui32 dx_ax_115 = ptrArg04->dw000C - ptrArg04->dw0008;
	dxOut = SLICE(dx_ax_115, word16, 16);
	return (word16) dx_ax_115;
}
