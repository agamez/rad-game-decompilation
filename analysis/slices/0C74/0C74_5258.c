// 0C74:5258: Register byte fn0C74_5258(Register Eq_17 ds, Register out Eq_17 dsOut)
// Called from:
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
byte fn0C74_5258(Eq_17 ds, union Eq_17 & dsOut)
{
	Eq_17 ds_366;
	mp16 fp;
	struct Eq_49455 Eq_17::* bp_148 = fp - 2;
	Eq_481 sp_118 = fp - 18;
	word16 ax_12 = Mem10[ds:22888:word16];
	selector ss;
	switch (ax_12)
	{
	case 0x01:
		sp_118 = fp - 0x12;
		byte dl_689;
		if (fn1AB8_1E3C(ds, Mem106[ds:22714:word16], Mem10[ds:22710:word16] + 0x01, out dl_689) != 0x00)
		{
			sp_118 = fp - 0x12;
			byte dl_690;
			if (fn1AB8_1E3C(ds, Mem127[ds:22714:word16] - 0x0C, Mem109[ds:22710:word16] + 0x0C, out dl_690) != 0x00)
			{
				(ss->*bp_148).bFFFE = fn0C74_396E(ds, out bp_148, out ds);
				sp_118.u0 = <invalid>;
			}
		}
		if ((ss->*bp_148).bFFFE != 0x00)
		{
			(ss->*bp_148).bFFFE = fn0C74_45CE(ds, out bp_148, out ds);
			sp_118.u0 = <invalid>;
		}
		break;
	case ~0x00:
		sp_118 = fp - 0x12;
		byte dl_691;
		if (fn1AB8_1E3C(ds, Mem21[ds:22714:word16], Mem10[ds:22708:word16] - 0x01, out dl_691) != 0x00)
		{
			sp_118 = fp - 0x12;
			byte dl_692;
			if (fn1AB8_1E3C(ds, Mem42[ds:22714:word16] - 0x0C, Mem24[ds:22708:word16] - 0x0C, out dl_692) != 0x00)
			{
				(ss->*bp_148).bFFFE = fn0C74_3F74(ds, out bp_148, out ds);
				sp_118.u0 = <invalid>;
			}
		}
		if ((ss->*bp_148).bFFFE != 0x00)
		{
			(ss->*bp_148).bFFFE = fn0C74_4999(ds, out bp_148, out ds);
			sp_118.u0 = <invalid>;
		}
		break;
	}
	if ((ss->*bp_148).bFFFE == 0x00)
	{
l0C74_5420:
		(ss->*bp_148).bFFFF = (ss->*bp_148).bFFFE;
		byte al_535 = (ss->*bp_148).bFFFF;
		dsOut = ds;
		return al_535;
	}
	if (Mem190[ds:22888:word16] == 0x01)
		Mem203[ss:bp_148 + -4:word16] = Mem190[ds:0x5970:word16] - 0x15;
	else
		Mem199[ss:bp_148 + -4:word16] = Mem190[ds:22892:word16];
	if (Mem205[ds:22888:word16] == 0x01)
		Mem215[ss:bp_148 + -8:word16] = Mem205[ds:0x5970:word16];
	else
		Mem213[ss:bp_148 + -8:word16] = Mem205[ds:22892:word16] + 0x15;
	struct Eq_49647 Eq_17::* sp_226 = sp_118 - 2;
	(ss->*sp_226).t0000.u2 = (ss->*bp_148).tFFF8.u2;
	Mem233[ss:sp_226 + -2:word16] = Mem227[ds:22894:word16] + 0x15;
	byte dl_693;
	if (fn1AB8_1E3C(ds, (ss->*sp_226).tFFFE.u2, (ss->*sp_226).t0000.u2, out dl_693) == 0x00)
	{
		(ss->*sp_226).t0000.u2 = (ss->*bp_148).tFFF8.u2;
		Mem255[ss:sp_226 + -2:word16] = Mem250[ds:22894:word16] + 0x14;
		byte dl_694;
		if (fn1AB8_1E3C(ds, (ss->*sp_226).tFFFE.u2, (ss->*sp_226).t0000.u2, out dl_694) != 0x00)
		{
			Mem281[ss:bp_148 + -6:word16] = Mem255[ds:22894:word16] + 0x15;
			(ss->*sp_226).t0000.u2 = (ss->*bp_148).tFFF8.u2;
			(ss->*sp_226).tFFFE.u2 = (ss->*bp_148).tFFFA.u2;
			(ss->*sp_226).tFFFC.u2 = (uint16) 0x08;
			fn1AB8_1E54(ds, (ss->*sp_226).tFFFC.u0, (ss->*sp_226).tFFFE.u2, (ss->*sp_226).t0000.u2);
l0C74_5363:
			(ss->*bp_148).tFFF6.u2 = (ss->*bp_148).tFFFA.u2;
			while ((ss->*bp_148).tFFFA.u2 > 0x02)
			{
				(ss->*((word16) sp_118 - 2)).u1 = (ss->*bp_148).tFFF8.u2;
				(ss->*((word16) sp_118 - 4)).u1 = (ss->*bp_148).tFFFA.u2;
				byte dl_695;
				if (fn1AB8_1E3C(ds, ss->*((word16) sp_118 - 4), ss->*((word16) sp_118 - 2), out dl_695) != 0x08)
					break;
				(ss->*bp_148).tFFFA.u2 = (uint16) ((ss->*bp_148).tFFFA.u2 - 22);
			}
			if ((ss->*bp_148).tFFFA.u2 != ((ss->*bp_148).tFFF6).u2)
			{
				(ss->*((word16) sp_118 - 2)).u1 = (ss->*bp_148).tFFFC.u2;
				ss->*((word16) sp_118 - 4) = (ss->*bp_148).tFFFA.u2 - 0x01;
				(ss->*((word16) sp_118 - 6)).u1 = (ss->*bp_148).tFFF8.u2;
				(ss->*((word16) sp_118 - 8)).u1 = (ss->*bp_148).tFFFA.u2;
				(ss->*bp_148).tFFF0.u2 = (uint16) fn1AB8_13A3(ds, ss->*((word16) sp_118 - 8), ss->*((word16) sp_118 - 6), ss->*((word16) sp_118 - 4), ss->*((word16) sp_118 - 2));
				(ss->*((word16) sp_118 - 2)).u1 = (ss->*bp_148).tFFF0.u2;
				Eq_17 dx_ax_696 = fn1EDA_023F(ds, ss->*((word16) sp_118 - 6), ss->*((word16) sp_118 - 4), ss->*((word16) sp_118 - 2), out ds_366);
				(ss->*bp_148).tFFF2.u2 = (uint16) (word16) dx_ax_696;
				(ss->*bp_148).tFFF4.u2 = SLICE(dx_ax_696, word16, 16);
				(ss->*((word16) sp_118 - 2)).u1 = (ss->*bp_148).tFFFC.u2;
				ss->*((word16) sp_118 - 4) = (ss->*bp_148).tFFFA.u2 - 0x01;
				(ss->*((word16) sp_118 - 6)).u1 = (ss->*bp_148).tFFF8.u2;
				(ss->*((word16) sp_118 - 8)).u1 = (ss->*bp_148).tFFFA.u2;
				Eq_17 es_di_391;
				es_di_391.u3 = (ss->*bp_148).tFFF2.u3;
				ss->*((word16) sp_118 - 0x0A) = SLICE(es_di_391, selector, 16);
				ss->*((word16) sp_118 - 0x0C) = (word16) es_di_391;
				fn1AB8_1E6B(ds_366, ss->*((word16) sp_118 - 0x0C), ss->*((word16) sp_118 - 8), ss->*((word16) sp_118 - 6), ss->*((word16) sp_118 - 4), ss->*((word16) sp_118 - 2));
				ss->*((word16) sp_118 - 2) = 0x00;
				ss->*((word16) sp_118 - 4) = 0x00;
				ss->*((word16) sp_118 - 6) = 0x01;
				fn1AB8_10F4(ds_366, ss->*((word16) sp_118 - 6), ss->*((word16) sp_118 - 4), ss->*((word16) sp_118 - 2));
				ss->*((word16) sp_118 - 2) = 0x00;
				fn1AB8_1C32(ds_366, ss->*((word16) sp_118 - 2));
				(ss->*((word16) sp_118 - 2)).u1 = (ss->*bp_148).tFFFC.u2;
				(ss->*((word16) sp_118 - 4)).u1 = (ss->*bp_148).tFFFA.u2;
				(ss->*((word16) sp_118 - 6)).u1 = (ss->*bp_148).tFFF8.u2;
				(ss->*((word16) sp_118 - 8)).u1 = (ss->*bp_148).tFFFA.u2;
				word16 dx_697;
				fn1AB8_1AF6(ds_366, ss->*((word16) sp_118 - 8), ss->*((word16) sp_118 - 6), ss->*((word16) sp_118 - 4), ss->*((word16) sp_118 - 2), out dx_697);
				(ss->*((word16) sp_118 - 2)).u1 = (ss->*bp_148).tFFFC.u2;
				(ss->*((word16) sp_118 - 4)).u1 = (ss->*bp_148).tFFFA.u2;
				(ss->*((word16) sp_118 - 6)).u1 = (ss->*bp_148).tFFF8.u2;
				(ss->*((word16) sp_118 - 8)).u1 = (ss->*bp_148).tFFF6.u2;
				Eq_17 ds_465 = fn0C74_2BBD(ds_366, ss->*((word16) sp_118 - 8), ss->*((word16) sp_118 - 6), ss->*((word16) sp_118 - 4), ss->*((word16) sp_118 - 2));
				(ss->*((word16) sp_118 - 2)).u1 = (ss->*bp_148).tFFFC.u2;
				ss->*((word16) sp_118 - 4) = (ss->*bp_148).tFFFA.u2 - 0x01;
				Eq_17 es_di_483;
				es_di_483.u3 = (ss->*bp_148).tFFF2.u3;
				ss->*((word16) sp_118 - 6) = SLICE(es_di_483, selector, 16);
				ss->*((word16) sp_118 - 8) = (word16) es_di_483;
				ss->*((word16) sp_118 - 0x0A) = 0x00;
				fn1AB8_13D7(ds_465, ss->*((word16) sp_118 + 0x0A), ss->*((word16) sp_118 - 8), ss->*((word16) sp_118 - 4), ss->*((word16) sp_118 - 2));
				(ss->*((word16) sp_118 - 2)).u1 = (ss->*bp_148).tFFF4.u2;
				(ss->*((word16) sp_118 - 4)).u1 = (ss->*bp_148).tFFF2.u2;
				(ss->*((word16) sp_118 - 6)).u1 = (ss->*bp_148).tFFF0.u2;
				word16 dx_698;
				fn1EDA_0254(ds_465, ss->*((word16) sp_118 - 0x0A), ss->*((word16) sp_118 - 8), ss->*((word16) sp_118 - 6), ss->*((word16) sp_118 - 4), out dx_698, out ds);
			}
			goto l0C74_5420;
		}
	}
	Mem277[ss:bp_148 + -6:word16] = Mem271[ds:22894:word16] - 0x01;
	goto l0C74_5363;
}
