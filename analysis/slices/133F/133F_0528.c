// 133F:0528: Register word16 fn133F_0528(Register int16 dx, Register Eq_17 ds, Stack Eq_54567 ptrArg06, Stack Eq_54558 ptrArg0A, Stack Eq_54549 ptrArg0E, Register out int16 dxOut, Register out word16 bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn1229_0DCC
word16 fn133F_0528(int16 dx, Eq_17 ds, Eq_54567 ptrArg06, Eq_54558 ptrArg0A, Eq_54549 ptrArg0E, int16 & dxOut, word16 & bpOut, union Eq_17 & dsOut)
{
	Eq_17 wLoc0A;
	mp16 fp;
	*ptrArg0E.u1 = 0x00;
	Mem24[ptrArg0A + 0x00:word16] = Mem18[ds:0x6CC4:word16];
	Mem29[ptrArg06 + 0x00:word16] = Mem24[ds:0x6CC6:word16];
	struct Eq_56286 Eq_17::* bp_109 = fp - 2;
	struct Eq_56289 Eq_17::* sp_137 = fp - 8;
	byte ah_253 = <invalid>;
	selector ss;
	if (fn1E78_02FB(ds) == 0x00)
	{
		if (Mem29[ds:~0x494D:byte] == 0x00)
			goto l133F_080F;
		dx = fn13C8_0066(out bp_109, out ds);
		Eq_481 sp_445;
		sp_445.u0 = <invalid>;
		if (*(ss->*bp_109).ptr0010 != 0x00)
		{
			(ss->*bp_109).bFFFF = 0x01;
			if (*(ss->*bp_109).ptr0010 == 0x01)
			{
				Mem464[ss:bp_109 + -5:byte] = Mem457[ds:0x6CD0:byte];
				if ((ss->*bp_109).bFFFB >= 0x01)
				{
					(ss->*bp_109).bFFFC = 0x01;
					while (ds:27858[CONVERT(Mem471[ss:bp_109 + -4:byte], uint8, uint16) * 0x02] >= Mem471[ds:0x6CC4:word16] || (ds:0x6D10[CONVERT(Mem471[ss:bp_109 + -4:byte], uint8, uint16) * 0x02] <= Mem471[ds:0x6CC4:word16] || (ds:27982[CONVERT(Mem471[ss:bp_109 + -4:byte], uint8, uint16) * 0x02] >= Mem471[ds:0x6CC6:word16] || ds:28044[CONVERT(Mem471[ss:bp_109 + -4:byte], uint8, uint16) * 0x02] <= Mem471[ds:0x6CC6:word16])))
					{
						if ((ss->*bp_109).bFFFC == (ss->*bp_109).bFFFB)
							goto l133F_07D3;
						++(ss->*bp_109).bFFFC;
					}
					Mem519[ss:bp_109 + -3:byte] = Mem471[ds:CONVERT(Mem471[ss:bp_109 + -4:byte], uint8, uint16) + 0x6DCA:byte];
					*(ss->*bp_109).ptr0010 = (uint16) (ss->*bp_109).bFFFD;
					ah_253 = 0x00;
					goto l133F_080F;
				}
			}
		}
l133F_07D3:
		if (Mem532[Mem532[ss:bp_109 + 0x0C:segptr32] + 0x00:word16] != Mem532[ds:0x6CC4:word16])
		{
l133F_07EB:
			(ss->*((word16) sp_445 + 0x0A)).u1 = (ss->*bp_109).ptr000C->u2;
			(ss->*((word16) sp_445 + 8)).u1 = (ss->*bp_109).ptr0008->u2;
			fn133F_021F(ds, ss->*((word16) sp_445 + 8), ss->*((word16) sp_445 + 0x0A));
			(ss->*bp_109).bFFFF = 0x01;
			ah_253 = 0x00;
			if ((ss->*bp_109).b0006 != 0x00)
			{
				ss->*((word16) sp_445 + 0x0A) = 0x026A;
				ss->*((word16) sp_445 + 8) = 383;
				fn133F_026B(ds, ss->*((word16) sp_445 + 8), ss->*((word16) sp_445 + 0x0A), out dx, out ds);
				ah_253 = 0x00;
			}
			goto l133F_080F;
		}
		Eq_17 ax_544;
		ax_544.u2 = (ss->*bp_109).ptr0008->u2;
		ah_253 = SLICE(ax_544, byte, 8);
		if (ax_544 != Mem532[ds:0x6CC6:word16])
			goto l133F_07EB;
	}
	else
	{
		Eq_17 ax_42 = fn1E78_030D(dx, ds, wLoc0A, out dx);
		cu8 al_51 = (byte) ax_42;
		ah_253 = SLICE(ax_42, byte, 8);
		if (al_51 == 0x0D)
			*ptrArg0E.u1 = 0x01;
		else if (al_51 == 0x1B)
			*ptrArg0E.u1 = 0x1B;
		else if (al_51 >= 33 && al_51 <= 0x7D)
		{
			*ptrArg0E.u1 = (uint16) fn1EDA_1384((byte) ax_42);
			sp_137 = fp - 0x08;
			ah_253 = 0x00;
		}
		else if (al_51 == 0x00)
		{
			Eq_17 ax_70 = fn1E78_030D(dx, ds, wLoc0A, out dx);
			uint8 al_79 = (byte) ax_70;
			ah_253 = SLICE(ax_70, byte, 8);
			if (al_79 >= 0x3B && al_79 <= 0x40)
			{
				*ptrArg0E.u1 = (uint16) al_79;
				ah_253 = 0x00;
			}
			else if (al_79 == 0x4B)
			{
				dx = fn13C8_009A(out bp_109, out ds);
				Eq_481 sp_231;
				sp_231.u0 = <invalid>;
				Mem242[ss:sp_231 + 0x02:word16] = Mem221[ds:0x6CC4:word16] - Mem221[ds:0x6CC0:word16];
				Mem245[ss:sp_231 + 0x00:word16] = Mem242[ds:0x6CC6:word16];
				fn133F_021F(ds, ss->*sp_231, ss->*((word16) sp_231 + 2));
				ah_253 = 0x00;
				sp_137 = (word16) sp_231 + 4;
			}
			else if (al_79 == 0x48)
			{
				dx = fn13C8_009A(out bp_109, out ds);
				Eq_481 sp_193;
				sp_193.u0 = <invalid>;
				Mem202[ss:sp_193 + 0x02:word16] = Mem183[ds:0x6CC4:word16];
				Mem207[ss:sp_193 + 0x00:word16] = Mem202[ds:0x6CC6:word16] - Mem202[ds:0x6CC2:word16];
				fn133F_021F(ds, ss->*sp_193, ss->*((word16) sp_193 + 2));
				ah_253 = 0x00;
				sp_137 = (word16) sp_193 + 4;
			}
			else if (al_79 == 0x50)
			{
				dx = fn13C8_009A(out bp_109, out ds);
				Eq_481 sp_155;
				sp_155.u0 = <invalid>;
				Mem164[ss:sp_155 + 0x02:word16] = Mem145[ds:0x6CC4:word16];
				Mem169[ss:sp_155 + 0x00:word16] = Mem164[ds:0x6CC6:word16] + Mem164[ds:0x6CC2:word16];
				fn133F_021F(ds, ss->*sp_155, ss->*((word16) sp_155 + 2));
				ah_253 = 0x00;
				sp_137 = (word16) sp_155 + 4;
			}
			else if (al_79 == 77)
			{
				dx = fn13C8_009A(out bp_109, out ds);
				Eq_481 sp_117;
				sp_117.u0 = <invalid>;
				Mem128[ss:sp_117 + 0x02:word16] = Mem107[ds:0x6CC4:word16] + Mem107[ds:0x6CC0:word16];
				Mem131[ss:sp_117 + 0x00:word16] = Mem128[ds:0x6CC6:word16];
				fn133F_021F(ds, ss->*sp_117, ss->*((word16) sp_117 + 2));
				ah_253 = 0x00;
				sp_137 = (word16) sp_117 + 4;
			}
		}
		if (*(ss->*bp_109).ptr0010 != 0x00)
		{
			(ss->*bp_109).bFFFF = 0x01;
			if (*(ss->*bp_109).ptr0010 == 0x01)
			{
				Mem308[ss:bp_109 + -5:byte] = Mem300[ds:0x6CD0:byte];
				if ((ss->*bp_109).bFFFB >= 0x01)
				{
					(ss->*bp_109).bFFFC = 0x01;
					while (true)
					{
						Eq_17 ax_322;
						ax_322.u2 = (*((word32) ds + 27858))[(uint16) (ss->*bp_109).bFFFC].t0000.u2;
						ah_253 = SLICE(ax_322, byte, 8);
						if (ax_322 < Mem315[ds:0x6CC4:word16])
						{
							Eq_17 ax_330;
							ax_330.u2 = (*((word32) ds + 27920))[(uint16) (ss->*bp_109).bFFFC].t0000.u2;
							ah_253 = SLICE(ax_330, byte, 8);
							if (ax_330 > Mem315[ds:0x6CC4:word16])
							{
								Eq_17 ax_338;
								ax_338.u2 = (*((word32) ds + 27982))[(uint16) (ss->*bp_109).bFFFC].t0000.u2;
								ah_253 = SLICE(ax_338, byte, 8);
								if (ax_338 < Mem315[ds:0x6CC6:word16])
								{
									Eq_17 ax_346;
									ax_346.u2 = (*((word32) ds + 28044))[(uint16) (ss->*bp_109).bFFFC].t0000.u2;
									ah_253 = SLICE(ax_346, byte, 8);
									if (ax_346 > Mem315[ds:0x6CC6:word16])
									{
										Mem363[ss:bp_109 + -3:byte] = Mem315[ds:CONVERT(Mem315[ss:bp_109 + -4:byte], uint8, uint16) + 0x6DCA:byte];
										*(ss->*bp_109).ptr0010 = (uint16) (ss->*bp_109).bFFFD;
										ah_253 = 0x00;
										goto l133F_080F;
									}
								}
							}
						}
						if ((ss->*bp_109).bFFFC == (ss->*bp_109).bFFFB)
							break;
						++(ss->*bp_109).bFFFC;
					}
				}
			}
		}
		if ((ss->*bp_109).b0006 != 0x00)
		{
			struct Eq_56406 Eq_17::* sp_383 = sp_137 - 2;
			(ss->*sp_383).t0000.u2 = (uint16) 0x026A;
			(ss->*sp_383).tFFFE.u2 = (uint16) 383;
			fn133F_026B(ds, (ss->*sp_383).tFFFE.u2, (ss->*sp_383).t0000.u2, out dx, out ds);
			ah_253 = 0x00;
		}
		(ss->*bp_109).bFFFF = 0x01;
	}
l133F_080F:
	word16 bp_603 = (ss->*bp_109).w0000;
	word16 ax_651 = SEQ(ah_253, (ss->*bp_109).bFFFF);
	dxOut = dx;
	bpOut = bp_603;
	dsOut = ds;
	return ax_651;
}
