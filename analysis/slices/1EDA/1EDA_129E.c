// 1EDA:129E: Register byte fn1EDA_129E(Register byte dh, Stack Eq_17 wArg04, Stack Eq_17 ptrArg06, Stack Eq_17 bArg0A)
// Called from:
//      fn0800_4255
byte fn1EDA_129E(byte dh, Eq_17 wArg04, Eq_17 ptrArg06, Eq_17 bArg0A)
{
	mp16 fp;
	Eq_17 al_19 = bArg0A;
	if (bArg0A == 0x00)
		al_19 = msdos_get_current_default_drive() + 0x01;
	struct Eq_65702 * ss;
	msdos_get_current_directory(al_19, ss, SEQ(dh, al_19));
	byte Eq_65702::* si_47 = fp - 0x0082;
	Eq_17 cx_52 = wArg04;
	word16 bx_145 = 0x00;
	do
	{
		byte al_61 = ss->*si_47;
		++si_47;
		if (al_61 == 0x00)
			break;
		++bx_145;
		(&ptrArg06.u3->t0000.u0)[(uipr32) bx_145] = al_61;
		--cx_52;
	} while (cx_52 != 0x00);
	ptrArg06.u3->t0000.u0 = (int8) (byte) bx_145;
	return 0x47;
}
