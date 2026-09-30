// 11C8:0092: void fn11C8_0092(Register Eq_17 ds)
// Called from:
//      fn11C8_0394
void fn11C8_0092(Eq_17 ds)
{
	fn1E78_01C0();
	byte bLoc0F_324 = 0x00;
	uint8 bLoc03_325 = 0x01;
	while (bLoc03_325 < 0x07 && bLoc0F_324 == 0x00)
	{
		Mem34[ds:22904:word16] = (CONVERT(bLoc03_325, uint8, uint16) << 0x04) + 0x0200;
		cup16 wLoc0A_328 = 0x00;
		byte bLoc10_329 = 0x00;
		while (wLoc0A_328 < 0x0201 && bLoc10_329 == 0x00)
		{
			if ((__in<byte>(Mem43[ds:22904:word16] + 0x0C) & 0x80) == 0x00)
				bLoc10_329 = 0x01;
			++wLoc0A_328;
		}
		if (bLoc10_329 != 0x00)
		{
			byte al_58 = __in<byte>(Mem43[ds:22904:word16] + 0x0C);
			__out<byte>(Mem59[ds:22904:word16] + 0x0C, 211);
			word16 wLoc0C_334;
			for (wLoc0C_334 = 0x01; wLoc0C_334 != 0x1000; ++wLoc0C_334)
				;
			byte al_78 = __in<byte>(Mem68[ds:22904:word16] + 0x06);
			__out<byte>(Mem79[ds:22904:word16] + 0x06, 0x01);
			__in<byte>(Mem79[ds:22904:word16] + 0x06);
			__in<byte>(Mem88[ds:22904:word16] + 0x06);
			__in<byte>(Mem93[ds:22904:word16] + 0x06);
			__in<byte>(Mem98[ds:22904:word16] + 0x06);
			__out<byte>(Mem103[ds:22904:word16] + 0x06, 0x00);
			byte bLoc04_342 = 0x00;
			byte bLoc10_344;
			byte v23_142;
			do
			{
				cup16 wLoc0A_343 = 0x00;
				bLoc10_344 = 0x00;
				while (wLoc0A_343 < 0x0201 && bLoc10_344 == 0x00)
				{
					if ((__in<byte>(Mem120[ds:22904:word16] + 0x0E) & 0x80) == 0x80)
						bLoc10_344 = 0x01;
					++wLoc0A_343;
				}
				if (bLoc10_344 != 0x00 && __in<byte>(Mem120[ds:22904:word16] + 0x0A) == 0xAA)
					bLoc0F_324 = 0x01;
				v23_142 = bLoc04_342 + 0x01;
				bLoc04_342 = v23_142;
			} while (v23_142 != 0x10 && bLoc10_344 == 0x00);
			if (bLoc10_344 == 0x00)
			{
				__out<byte>(Mem143[ds:22904:word16] + 0x0C, al_58);
				__out<byte>(Mem143[ds:22904:word16] + 0x06, al_78);
			}
		}
		if (bLoc0F_324 != 0x00)
		{
			Eq_17 ptrLoc0114_392 = SEQ(ds, ~0x4643);
			struct Eq_50611 * cs;
			word16 cx_586;
			fn1EDA_08CE(ds, 0x00, &cs->t0071, ptrLoc0114_392, out cx_586);
			Eq_17 ptrLoc0118_399;
			<unknown> Eq_50617::* fp;
			ptrLoc0118_399.u3 = fp - 0x0110;
			fn11C8_0000(ds, 0x03, Mem236[ds:22904:word16], ptrLoc0118_399);
			word16 cx_587;
			fn1EDA_08CE(ds, 0x00, ptrLoc0118_399, ptrLoc0114_392, out cx_587);
			fn1EDA_086C(ds, ptrLoc0114_392);
			Mem278[ds:22902:byte] = 0x01;
		}
		else
			++bLoc03_325;
	}
	if (bLoc0F_324 == 0x00)
		Mem302[ds:22902:byte] = 0x00;
}
