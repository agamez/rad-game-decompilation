// 1AB8:027E: void fn1AB8_027E(Register Eq_17 ds, Stack uint16 wArg04, Stack Eq_17 ptrArg06)
// Called from:
//      fn133F_0056
void fn1AB8_027E(Eq_17 ds, uint16 wArg04, Eq_17 ptrArg06)
{
	switch (wArg04)
	{
	case 0x00:
		struct Eq_57801 * cs;
		word16 dx_1036;
		fn1EDA_0A39(~0x00, ptrArg06, &cs->t00D9, out dx_1036);
		break;
	case ~0x00:
		word16 dx_1037;
		fn1EDA_0A39(~0x00, ptrArg06, (char *) &cs->t00D9 + 9, out dx_1037);
		break;
	case ~0x01:
		word16 dx_1038;
		fn1EDA_0A39(~0x00, ptrArg06, (char *) &cs->t00D9 + 38, out dx_1038);
		break;
	case ~0x02:
		Eq_17 ptrLoc0206_955;
		<unknown> Eq_57827::* fp;
		ptrLoc0206_955.u3 = fp - 0x0102;
		fn1EDA_0A1F((char *) &cs->t00D9 + 69, ptrLoc0206_955);
		fn1EDA_0AAC(SEQ(ds, 46934), ptrLoc0206_955);
		fn1EDA_0AAC((char *) &cs->t00D9 + 100, ptrLoc0206_955);
		word16 dx_1039;
		fn1EDA_0A39(~0x00, ptrArg06, ptrLoc0206_955, out dx_1039);
		break;
	case ~0x03:
		Eq_17 ptrLoc0206_939;
		ptrLoc0206_939.u3 = fp - 0x0102;
		fn1EDA_0A1F((char *) &cs->t00D9 + 0x0066, ptrLoc0206_939);
		fn1EDA_0AAC(SEQ(ds, 46934), ptrLoc0206_939);
		fn1EDA_0AAC((char *) &cs->t00D9 + 100, ptrLoc0206_939);
		word16 dx_1040;
		fn1EDA_0A39(~0x00, ptrArg06, ptrLoc0206_939, out dx_1040);
		break;
	case ~0x04:
		word16 dx_1041;
		fn1EDA_0A39(~0x00, ptrArg06, (char *) &cs->t00D9 + 131, out dx_1041);
		break;
	case ~0x05:
		word16 dx_1042;
		fn1EDA_0A39(~0x00, ptrArg06, (char *) &cs->t00D9 + 0x00A4, out dx_1042);
		break;
	case ~0x06:
		word16 dx_1043;
		fn1EDA_0A39(~0x00, ptrArg06, (char *) &cs->t00D9 + 191, out dx_1043);
		break;
	case ~0x07:
		Eq_17 ptrLoc0206_902;
		ptrLoc0206_902.u3 = fp - 0x0102;
		fn1EDA_0A1F((char *) &cs->t00D9 + 0x00DB, ptrLoc0206_902);
		fn1EDA_0AAC(SEQ(ds, 46924), ptrLoc0206_902);
		fn1EDA_0AAC((char *) &cs->t00D9 + 100, ptrLoc0206_902);
		word16 dx_1044;
		fn1EDA_0A39(~0x00, ptrArg06, ptrLoc0206_902, out dx_1044);
		break;
	case ~0x08:
		word16 dx_1045;
		fn1EDA_0A39(~0x00, ptrArg06, (char *) &cs->t00D9 + 0x00F1, out dx_1045);
		break;
	case ~0x09:
		word16 dx_1046;
		fn1EDA_0A39(~0x00, ptrArg06, (char *) &cs->t00D9 + 272, out dx_1046);
		break;
	case ~0x0A:
		word16 dx_1047;
		fn1EDA_0A39(~0x00, ptrArg06, (char *) &cs->t00D9 + 314, out dx_1047);
		break;
	case ~0x0B:
		word16 dx_1048;
		fn1EDA_0A39(~0x00, ptrArg06, (char *) &cs->t00D9 + 329, out dx_1048);
		break;
	case ~0x0C:
		Eq_17 ptrLoc0206_858;
		ptrLoc0206_858.u3 = fp - 0x0102;
		fn1EDA_0A1F((char *) &cs->t00D9 + 348, ptrLoc0206_858);
		fn1EDA_0AAC(SEQ(ds, 46924), ptrLoc0206_858);
		fn1EDA_0AAC((char *) &cs->t00D9 + 100, ptrLoc0206_858);
		word16 dx_1049;
		fn1EDA_0A39(~0x00, ptrArg06, ptrLoc0206_858, out dx_1049);
		break;
	case ~0x0D:
		word16 dx_1050;
		fn1EDA_0A39(~0x00, ptrArg06, (char *) &cs->t00D9 + 368, out dx_1050);
		break;
	case ~0x11:
		word16 dx_1052;
		fn1EDA_0A39(~0x00, ptrArg06, (char *) &cs->t00D9 + 388, out dx_1052);
		break;
	default:
		Eq_17 ptrLoc0206_824;
		ptrLoc0206_824.u3 = fp - 0x0202;
		fn1EDA_0A1F((char *) &cs->t00D9 + 404, ptrLoc0206_824);
		Eq_17 ptrLoc020A_831;
		ptrLoc020A_831.u3 = fp - 0x0102;
		fn1AB8_0000((uint32) wArg04, ptrLoc020A_831);
		fn1EDA_0AAC(ptrLoc020A_831, ptrLoc0206_824);
		fn1EDA_0AAC((char *) &cs->t00D9 + 100, ptrLoc0206_824);
		word16 dx_1051;
		fn1EDA_0A39(~0x00, ptrArg06, ptrLoc0206_824, out dx_1051);
		break;
	}
}
