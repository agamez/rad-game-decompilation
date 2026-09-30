// 1E5F:000B: Register word16 fn1E5F_000B(Stack Eq_17 ptrArg04, Register out byte chOut, Register out word16 dxOut, Register out (memptr (ptr16 Eq_51050) (memptr Eq_17 Eq_1654)) bpOut, Register out word16 siOut, Register out (ptr16 Eq_18932) esOut, Register out (ptr16 Eq_18935) dsOut)
// Called from:
//      fn0C43_0000
//      fn0C43_001E
//      fn1206_000D
//      fn1206_0038
//      fn1206_0066
//      fn1206_0094
//      fn1206_00D1
//      fn1206_00FF
//      fn1206_012D
//      fn13C1_0000
//      fn13C8_000D
//      fn13C8_0038
//      fn13C8_004F
//      fn13C8_0066
//      fn13C8_009A
//      fn13C8_00BF
//      fn13C8_00E4
//      fn13C8_0111
word16 fn1E5F_000B(Eq_17 ptrArg04, byte & chOut, word16 & dxOut, struct Eq_1654 & bpOut, word16 & siOut, struct Eq_18932 & esOut, struct Eq_18935 & dsOut)
{
	word16 ax_41 = ptrArg04.u3->t0000.u2;
	word16 ax_51 = ptrArg04.u3->t0006.u2;
	struct Eq_1654 Eq_17::* Eq_51050::* ax_54 = (struct Eq_1654 Eq_17::* Eq_51050::*) ptrArg04.u3->ptr0008;
	word16 ax_57 = ptrArg04.u3->t000A.u2;
	struct Eq_18935 * ax_64 = (struct Eq_18935 *) ptrArg04.u3->ptr000E;
	struct Eq_18932 * ax_68 = ptrArg04.u3->t0010.u2;
	__cli();
	chOut = <invalid>;
	dxOut = ax_51;
	bpOut = ax_54;
	siOut = ax_57;
	esOut = ax_68;
	dsOut = ax_64;
	return ax_41;
}
