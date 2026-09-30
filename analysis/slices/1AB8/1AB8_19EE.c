// 1AB8:19EE: void fn1AB8_19EE(Register Eq_17 ds, Stack Eq_59090 ptrArg04, Stack Eq_59080 ptrArg08, Stack Eq_59070 ptrArg0C)
// Called from:
//      fn1AB8_0BAE
void fn1AB8_19EE(Eq_17 ds, Eq_59090 ptrArg04, Eq_59080 ptrArg08, Eq_59070 ptrArg0C)
{
	Mem10[ds:0xB89A:byte] = ~0x00;
	Mem11[ds:~0x4764:byte] = 0x00;
	Mem12[ds:~0x4762:byte] = 0x0A;
	Eq_61049 al_16;
	al_16.u0 = ptrArg08.u0->u0;
	Mem17[ds:0xB89C:byte] = al_16;
	uint8 al_48;
	if (al_16 == 0x00)
	{
		<unknown> Eq_61233::* fp;
		fn1AB8_1A62(fp - 2, ds);
		al_48 = Mem17[ds:0xB89A:byte];
	}
	else
	{
		Mem27[ds:~0x4764:byte] = Mem17[ptrArg04 + 0x00:byte];
		Eq_61049 bl_31;
		bl_31.u0 = ptrArg08.u0->u0;
		if (bl_31 < 0x00)
			return;
		cu8 al_38 = 0x0A - bl_31;
		if (al_38 < 0x00)
			al_48 = -al_38;
		else
		{
			Eq_61252 bx_45;
			bx_45.u0 = (uint16) bl_31;
			Mem47[ds:~0x4762:byte] = Mem27[0x1AB8:bx_45 + 0x1ED5:byte];
			al_48 = (uint8) (0x1AB8->*((word16) bx_45 + 7865));
			Mem49[ds:0xB89A:byte] = al_48;
		}
	}
	*ptrArg0C.u0 = (uint16) al_48;
}
