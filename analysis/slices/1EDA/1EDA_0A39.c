// 1EDA:0A39: Register Eq_17 fn1EDA_0A39(Stack Eq_17 bArg04, Stack Eq_17 ptrArg06, Stack Eq_17 ptrArg0A, Register out (ptr16 Eq_350) dxOut)
// Called from:
//      fn0800_01FE
//      fn0800_0619
//      fn0800_0AA1
//      fn0800_0B42
//      fn0800_0D20
//      fn0800_11EF
//      fn0800_19E1
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
//      fn0800_3D9D
//      fn0C43_00B9
//      fn0C74_0000
//      fn0C74_004B
//      fn0C74_011E
//      fn0C74_020C
//      audio_transfer_rom_data
//      fn1229_0040
//      fn1229_039D
//      fn1229_050A
//      fn1229_061B
//      fn1229_0735
//      fn1229_09F9
//      fn1229_0AA8
//      fn1229_0CCE
//      fn1229_0DCC
//      fn133F_014B
//      fn133F_02DF
//      fn133F_0352
//      fn133F_04DE
//      fn13C1_0036
//      fn13E2_0193
//      fn1AB8_0000
//      fn1AB8_027E
//      fn1AB8_0887
//      fn1AB8_097B
//      fn1AB8_0BAE
//      fn1AB8_1492
//      fn1AB8_1536
//      fn1AB8_1783
//      fn1EDA_0B7C
//      fn1EDA_0BD0
Eq_17 fn1EDA_0A39(Eq_17 bArg04, Eq_17 ptrArg06, Eq_17 ptrArg0A, struct Eq_350 & dxOut)
{
	word16 wArg04;
	Eq_17 cl_17 = (byte) wArg04;
	Eq_17 al_15;
	al_15.u0 = ptrArg0A.u3->t0000.u0;
	if (al_15 > cl_17)
		al_15 = cl_17;
	ptrArg06.u3->t0000.u0 = (int8) al_15;
	memcpy(&ptrArg06.u3->t0001.u0, &ptrArg0A.u3->t0001.u0, (uint32) al_15);
	struct Eq_350 * ds;
	dxOut = ds;
	return al_15;
}
