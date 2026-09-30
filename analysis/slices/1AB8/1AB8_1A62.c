// 1AB8:1A62: void fn1AB8_1A62(Sequence (ptr32 Eq_61231) ss_bp, Register Eq_17 ds)
// Called from:
//      fn1AB8_19EE
void fn1AB8_1A62(struct Eq_61231 * ss_bp, Eq_17 ds)
{
	fn1AB8_1EE3(ds);
	Eq_61049 al_22 = Mem7[ds:0xB89C:byte];
	uint16 * es_di_21 = ss_bp->ptr000A;
	uint16 ax_27 = (uint16) al_22;
	if (al_22 == ~0x00)
		ax_27 = SEQ(al_22, al_22);
	*es_di_21 = ax_27;
	Mem47[Mem34[ss_bp + 6:segptr32] + 0x00:word16] = CONVERT(Mem34[ds:~0x4764:byte], uint8, uint16);
}
