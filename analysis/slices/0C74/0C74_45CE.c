// 0C74:45CE: Register byte fn0C74_45CE(Register Eq_17 ds, Register out (memptr Eq_17 Eq_45021) bpOut, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_5258
byte fn0C74_45CE(Eq_17 ds, struct Eq_45021 & bpOut, union Eq_17 & dsOut)
{
	mp16 fp;
	Mem13[ds:22708:word16] = Mem10[ds:22708:word16] - 0x01;
	fn1AB8_10F4(ds, 0x01, 0x00, 0x00);
	fn1AB8_1C32(ds, 0x0C);
	Eq_17 bp_39 = fp - 2;
	struct Eq_44671 Eq_17::* sp_114 = fp - 0x0A;
	selector ss;
	Eq_481 sp_87;
	byte dl_1011;
	do
	{
		struct Eq_44731 Eq_17::* sp_47 = sp_114 - 2;
		Mem48[ss:sp_47 + 0x00:word16] = CONVERT(Mem40[ss:bp_39 + -2:byte], uint8, uint16) + Mem40[ds:22708:word16];
		Mem52[ss:sp_47 + -2:word16] = Mem48[ds:22712:word16] + 0x12;
		Mem58[ss:sp_47 + -4:word16] = CONVERT(Mem52[ss:bp_39 + -2:byte], uint8, uint16) + Mem52[ds:22708:word16];
		Mem63[ss:sp_47 + -6:word16] = Mem58[ds:22712:word16] + 0x13;
		word16 dx_1012;
		fn1AB8_1AF6(ds, (ss->*sp_47).tFFFA.u2, (ss->*sp_47).tFFFC.u2, (ss->*sp_47).tFFFE.u2, (ss->*sp_47).t0000.u2, out dx_1012);
		(ss->*((word32) bp_39 - 2)).u3 = &(ss->*((word32) bp_39 - 2)).u3->t0001.u0;
		(ss->*sp_47).t0000.u2 = (uint16) 300;
		(ss->*sp_47).tFFFE.u2 = (uint16) 0x14;
		bp_39 = fn0C74_070D(ds, (ss->*sp_47).tFFFE.u2, (ss->*sp_47).t0000.u2, out ds);
		sp_87.u0 = <invalid>;
		if (ss->*((word32) bp_39 - 2) == 0x3A)
			break;
		Mem100[ss:sp_87 + 0x02:word16] = CONVERT(Mem76[ss:bp_39 + -2:byte], uint8, uint16) + Mem76[ds:22708:word16];
		Mem105[ss:sp_87 + 0x00:word16] = Mem100[ds:22712:word16] + 0x13;
		sp_114 = (word16) sp_87 + 4;
	} while (fn1AB8_1E3C(ds, ss->*sp_87, ss->*((word16) sp_87 + 2), out dl_1011) == 0x00 && CONVERT(Mem105[ss:bp_39 + -2:byte], uint8, uint16) + Mem105[ds:22708:word16] <u 0x027E);
	if (ss->*((word32) bp_39 - 2) != 0x3A)
	{
		ss->*((word16) sp_87 + 2) = 0x00;
		fn1AB8_1C32(ds, ss->*((word16) sp_87 + 2));
		struct Eq_44879 Eq_17::* sp_851 = (word16) sp_87 + 4;
		uint8 al_852 = (uint8) (ss->*((word32) bp_39 - 2));
		if (al_852 >= 0x1E)
		{
			(ss->*((word32) bp_39 - 3)).u1 = al_852 - 0x01;
			while (true)
			{
				struct Eq_44907 Eq_17::* sp_869 = sp_851 - 2;
				Mem870[ss:sp_869 + 0x00:word16] = CONVERT(Mem862[ss:bp_39 + -3:byte], uint8, uint16) + Mem862[ds:22708:word16];
				Mem874[ss:sp_869 + -2:word16] = Mem870[ds:22712:word16] + 0x12;
				Mem880[ss:sp_869 + -4:word16] = CONVERT(Mem874[ss:bp_39 + -3:byte], uint8, uint16) + Mem874[ds:22708:word16];
				Mem885[ss:sp_869 + -6:word16] = Mem880[ds:22712:word16] + 0x13;
				word16 dx_1013;
				fn1AB8_1AF6(ds, (ss->*sp_869).tFFFA.u2, (ss->*sp_869).tFFFC.u2, (ss->*sp_869).tFFFE.u2, (ss->*sp_869).t0000.u2, out dx_1013);
				(ss->*sp_869).t0000.u2 = (uint16) 300;
				(ss->*sp_869).tFFFE.u2 = (uint16) 0x14;
				Eq_481 sp_906;
				sp_906.u0 = <invalid>;
				bp_39 = fn0C74_070D(ds, (ss->*sp_869).tFFFE.u2, (ss->*sp_869).t0000.u2, out ds);
				sp_851 = (word16) sp_906 + 4;
				if (ss->*((word32) bp_39 - 3) == 0x1D)
					break;
				(ss->*((word32) bp_39 - 3)).u1 = ss->*((word32) bp_39 - 3) - 0x01;
			}
		}
		Mem920[ds:22708:word16] = Mem918[ds:22708:word16] + 0x01;
		(ss->*((word32) bp_39 - 1)).u3 = 0x00;
l0C74_4994:
		byte al_930 = (byte) (ss->*((word32) bp_39 - 1));
		bpOut = (struct Eq_45021 Eq_17::*) (ss->*bp_39.u3).t0000.u2;
		dsOut = ds;
		return al_930;
	}
	ss->*((word16) sp_87 + 2) = 500;
	Eq_17 bp_137 = fn0C74_02D8(ds, ss->*((word16) sp_87 + 2), out ds);
	Mem153[ss:bp_137 + -6:word16] = Mem133[ds:22712:word16] + 0x12;
	Mem157[ss:bp_137 + -8:word16] = Mem153[ds:22712:word16] + 0x14;
	Eq_481 sp_145;
	sp_145.u0 = <invalid>;
	word16 sp_150 = (word16) sp_145 + 2;
	struct Eq_45052 Eq_17::* sp_164;
	while (true)
	{
		sp_164 = sp_150 - 2;
		Mem166[ss:sp_164 + 0x00:word16] = Mem159[ds:22708:word16] + 0x39;
		(ss->*sp_164).tFFFE.u2 = (uint16) (ss->*((word32) bp_137 - 8));
		byte dl_1016;
		if (fn1AB8_1E3C(ds, (ss->*sp_164).tFFFE.u2, (ss->*sp_164).t0000.u2, out dl_1016) != 0x00 || ss->*((word32) bp_137 - 8) >= 0x01DE)
			break;
		(ss->*sp_164).t0000.u2 = (uint16) 0x0C;
		fn1AB8_1C32(ds, (ss->*sp_164).t0000.u0);
		Mem778[ss:sp_164 + 0x00:word16] = Mem770[ds:22708:word16] + 0x36;
		(ss->*sp_164).tFFFE.u2 = (uint16) (ss->*((word32) bp_137 - 8));
		Mem786[ss:sp_164 + -4:word16] = Mem781[ds:22708:word16] + 0x3A;
		(ss->*sp_164).tFFFA.u2 = (uint16) (ss->*((word32) bp_137 - 8));
		word16 dx_1014;
		fn1AB8_1AF6(ds, (ss->*sp_164).tFFFA.u2, (ss->*sp_164).tFFFC.u2, (ss->*sp_164).tFFFE.u2, (ss->*sp_164).t0000.u2, out dx_1014);
		(ss->*sp_164).t0000.u2 = (uint16) 0x00;
		fn1AB8_1C32(ds, (ss->*sp_164).t0000.u0);
		Mem805[ss:sp_164 + 0x00:word16] = Mem797[ds:22708:word16] + 0x36;
		(ss->*sp_164).tFFFE.u2 = (uint16) (ss->*((word32) bp_137 - 6));
		Mem813[ss:sp_164 + -4:word16] = Mem808[ds:22708:word16] + 0x3A;
		(ss->*sp_164).tFFFA.u2 = (uint16) (ss->*((word32) bp_137 - 6));
		word16 dx_1015;
		fn1AB8_1AF6(ds, (ss->*sp_164).tFFFA.u2, (ss->*sp_164).tFFFC.u2, (ss->*sp_164).tFFFE.u2, (ss->*sp_164).t0000.u2, out dx_1015);
		(ss->*sp_164).t0000.u2 = (uint16) 0x1E;
		bp_137 = fn0C74_02D8(ds, (ss->*sp_164).t0000.u2, out ds);
		(ss->*((word32) bp_137 - 6)).u3 = &(ss->*((word32) bp_137 - 6)).u3->t0001.u0;
		(ss->*((word32) bp_137 - 8)).u3 = &(ss->*((word32) bp_137 - 8)).u3->t0001.u0;
		Eq_481 sp_835;
		sp_835.u0 = <invalid>;
		sp_150 = (word16) sp_835 + 2;
	}
	Mem191[ds:22892:word16] = Mem170[ds:22710:word16] + 0x01;
	Mem194[ds:0x5970:word16] = Mem191[ds:22710:word16] + 44;
	if (Mem194[ds:0x5970:word16] > 0x027E)
		Mem197[ds:0x5970:word16] = 0x027E;
	if (Mem202[ss:bp_137 + -8:word16] <u Mem202[ds:22714:word16])
	{
		Mem215[ds:22894:word16] = Mem202[ds:22712:word16];
		Mem217[ds:22898:word16] = Mem215[ds:22714:word16];
	}
	else
	{
		Mem209[ds:22894:word16] = Mem202[ss:bp_137 + -8:word16] - 22;
		Mem213[ds:22898:word16] = Mem209[ss:bp_137 + -8:word16] + 0x15;
	}
	if (Mem219[ds:22898:word16] > 0x0176)
	{
		Mem222[ds:22898:word16] = 0x0176;
		Mem223[ds:22894:word16] = 330;
	}
	Mem235[ss:sp_164 + 0x00:word16] = Mem225[ds:0x5970:word16] - 0x15;
	Mem240[ss:sp_164 + -2:word16] = Mem235[ds:22898:word16] - 0x15;
	byte dl_1017;
	if (fn1AB8_1E3C(ds, (ss->*sp_164).tFFFE.u2, (ss->*sp_164).t0000.u2, out dl_1017) == 0x00)
	{
		Mem258[ss:sp_164 + 0x00:word16] = Mem240[ds:0x5970:word16] - 0x15;
		Mem263[ss:sp_164 + -2:word16] = Mem258[ds:22898:word16] - 0x2B;
		byte dl_1019;
		if (fn1AB8_1E3C(ds, (ss->*sp_164).tFFFE.u2, (ss->*sp_164).t0000.u2, out dl_1019) == 0x00)
			Mem279[ds:0x5970:word16] = Mem263[ds:0x5970:word16] - 22;
	}
	struct Eq_45338 Eq_17::* sp_287 = sp_150 - 2;
	Mem289[ss:sp_287 + 0x00:word16] = Mem282[ds:22892:word16] + 22;
	Mem292[ss:sp_287 + -2:word16] = Mem289[ds:22894:word16];
	byte dl_1018;
	if (fn1AB8_1E3C(ds, (ss->*sp_287).tFFFE.u2, (ss->*sp_287).t0000.u2, out dl_1018) == 0x00)
	{
		Mem309[ss:sp_287 + 0x00:word16] = Mem292[ds:22892:word16];
		Mem312[ss:sp_287 + -2:word16] = Mem309[ds:22894:word16];
		byte dl_1022;
		if (fn1AB8_1E3C(ds, (ss->*sp_287).tFFFE.u2, (ss->*sp_287).t0000.u2, out dl_1022) == 0x00)
			Mem328[ds:22894:word16] = Mem312[ds:22894:word16] + 0x12;
	}
	struct Eq_45410 Eq_17::* sp_331 = sp_150 - 2;
	(ss->*sp_331).t0000.u2 = (uint16) 0x0C;
	fn1AB8_1C32(ds, (ss->*sp_331).t0000.u0);
	Mem342[ss:sp_331 + 0x00:word16] = Mem333[ds:22708:word16] + 0x36;
	(ss->*sp_331).tFFFE.u2 = (uint16) (ss->*((word32) bp_137 - 6) - 0x01);
	Mem355[ss:sp_331 + -4:word16] = Mem350[ds:22708:word16] + 0x3A;
	(ss->*sp_331).tFFFA.u2 = (uint16) (ss->*((word32) bp_137 - 6) - 0x01);
	word16 dx_1020;
	fn1AB8_1AF6(ds, (ss->*sp_331).tFFFA.u2, (ss->*sp_331).tFFFC.u2, (ss->*sp_331).tFFFE.u2, (ss->*sp_331).t0000.u2, out dx_1020);
	Mem370[ss:sp_331 + 0x00:word16] = Mem360[ds:22708:word16] + 0x36;
	(ss->*sp_331).tFFFE.u2 = (uint16) (ss->*((word32) bp_137 - 6) - 0x02);
	Mem380[ss:sp_331 + -4:word16] = Mem375[ds:22708:word16] + 0x3A;
	(ss->*sp_331).tFFFA.u2 = (uint16) (ss->*((word32) bp_137 - 6) - 0x02);
	word16 dx_1021;
	fn1AB8_1AF6(ds, (ss->*sp_331).tFFFA.u2, (ss->*sp_331).tFFFC.u2, (ss->*sp_331).tFFFE.u2, (ss->*sp_331).t0000.u2, out dx_1021);
	(ss->*sp_331).t0000.u2 = (uint16) 0x00;
	fn1AB8_1C32(ds, (ss->*sp_331).t0000.u0);
	struct Eq_45551 Eq_17::* sp_398 = (struct Eq_45551 Eq_17::*) ((char *) &sp_331->t0000 + 2);
	uint8 al_399 = (uint8) (ss->*((word32) bp_137 - 2));
	if (al_399 >= 0x1E)
	{
		(ss->*((word32) bp_137 - 3)).u1 = al_399 - 0x01;
		while (true)
		{
			struct Eq_45624 Eq_17::* sp_416 = sp_398 - 2;
			Mem417[ss:sp_416 + 0x00:word16] = CONVERT(Mem409[ss:bp_137 + -3:byte], uint8, uint16) + Mem409[ds:22708:word16];
			Mem421[ss:sp_416 + -2:word16] = Mem417[ds:22712:word16] + 0x12;
			Mem427[ss:sp_416 + -4:word16] = CONVERT(Mem421[ss:bp_137 + -3:byte], uint8, uint16) + Mem421[ds:22708:word16];
			Mem432[ss:sp_416 + -6:word16] = Mem427[ds:22712:word16] + 0x13;
			word16 dx_1023;
			fn1AB8_1AF6(ds, (ss->*sp_416).tFFFA.u2, (ss->*sp_416).tFFFC.u2, (ss->*sp_416).tFFFE.u2, (ss->*sp_416).t0000.u2, out dx_1023);
			(ss->*sp_416).t0000.u2 = (uint16) 300;
			(ss->*sp_416).tFFFE.u2 = (uint16) 0x14;
			Eq_481 sp_453;
			sp_453.u0 = <invalid>;
			bp_137 = fn0C74_070D(ds, (ss->*sp_416).tFFFE.u2, (ss->*sp_416).t0000.u2, out ds);
			sp_398 = (word16) sp_453 + 4;
			if (ss->*((word32) bp_137 - 3) == 0x1D)
				break;
			(ss->*((word32) bp_137 - 3)).u1 = ss->*((word32) bp_137 - 3) - 0x01;
		}
	}
	Mem467[ds:22708:word16] = Mem465[ds:22708:word16] + 0x01;
	(ss->*((word32) bp_137 - 2)).u1 = 0x05;
	(ss->*((word32) bp_137 - 4)).u3 = 0x01;
	(ss->*((word32) bp_137 - 3)).u1 = 0x01;
l0C74_488C:
	struct Eq_45721 Eq_17::* sp_475 = sp_398 - 2;
	(ss->*sp_475).t0000.u2 = (uint16) 300;
	(ss->*sp_475).tFFFE.u2 = (uint16) 0x14;
	Eq_17 ds_487;
	fn0C74_070D(ds, (ss->*sp_475).tFFFE.u2, (ss->*sp_475).t0000.u2, out ds_487);
	Eq_481 sp_491;
	sp_491.u0 = <invalid>;
	ss->*((word16) sp_491 + 2) = 0x0A;
	bp_39 = fn0C74_02D8(ds_487, ss->*((word16) sp_491 + 2), out ds);
	(ss->*((word32) bp_39 - 2)).u1 = ss->*((word32) bp_39 - 2) - 0x01;
	Eq_481 sp_508;
	sp_508.u0 = <invalid>;
	if (ss->*((word32) bp_39 - 2) == 0x00)
	{
		(ss->*((word32) bp_39 - 2)).u1 = 0x04;
		if (Mem524[ds:0x58B0:byte] != 0x00)
		{
			ss->*sp_508 = 0x32;
			fn11C8_0354(ds, ss->*sp_508);
		}
	}
	else
		fn11C8_033B(ds);
	if (Mem540[ds:22708:word16] >u 0x00)
	{
		(ss->*((word32) bp_39 - 4)).u3 = &(ss->*((word32) bp_39 - 4)).u3->t0001.u0;
		Mem551[ds:22708:word16] = Mem549[ds:22708:word16] - 0x01;
		Mem553[ds:22710:word16] = Mem551[ds:22710:word16] - 0x01;
	}
	if (Mem556[ds:22710:word16] >u 0x00)
	{
		Mem565[ss:sp_508 + 0x00:word16] = Mem556[ds:22708:word16];
		Mem568[ss:sp_508 + -2:word16] = Mem565[ds:22714:word16];
		byte dl_1024;
		if (fn1AB8_1E3C(ds, ss->*((word16) sp_508 - 2), ss->*sp_508, out dl_1024) == 0x00)
		{
			Mem585[ss:sp_508 + 0x00:word16] = Mem568[ds:22708:word16];
			Mem590[ss:sp_508 + -2:word16] = Mem585[ds:22714:word16] - 0x15;
			byte dl_1025;
			if (fn1AB8_1E3C(ds, ss->*((word16) sp_508 - 2), ss->*sp_508, out dl_1025) == 0x00)
			{
				Mem607[ss:sp_508 + 0x00:word16] = Mem590[ds:22708:word16];
				Mem612[ss:sp_508 + -2:word16] = Mem607[ds:22714:word16] + 0x01;
				byte dl_1026;
				if (fn1AB8_1E3C(ds, ss->*((word16) sp_508 - 2), ss->*sp_508, out dl_1026) != 0x00)
				{
					Mem629[ss:sp_508 + 0x00:word16] = Mem612[ds:22708:word16];
					Mem632[ss:sp_508 + -2:word16] = Mem629[ds:22712:word16];
					segptr32 es_di_640 = ds.u3->t58E4.u3[(uint16) (ss->*((word32) bp_39 - 2))];
					ss->*((word16) sp_508 - 4) = SLICE(es_di_640, selector, 16);
					ss->*((word16) sp_508 - 6) = (word16) es_di_640;
					ss->*((word16) sp_508 - 8) = 0x00;
					fn1AB8_13D7(ds, ss->*((word16) sp_508 + 8), ss->*((word16) sp_508 - 6), ss->*((word16) sp_508 - 2), ss->*sp_508);
l0C74_493C:
					sp_398 = (word16) sp_508 + 2;
					if (ss->*((word32) bp_39 - 3) == 44)
					{
						if (ss->*((word32) bp_39 - 4) < 22)
						{
							Eq_17 ax_686 = Mem680[ds:22714:word16];
							Eq_17 ax_691 = Mem680[ds:22898:word16];
							if (false || true && ax_691 <= (word32) ax_686 + 23)
							{
								Mem742[ss:sp_508 + 0x00:word16] = Mem680[ds:22708:word16];
								Mem745[ss:sp_508 + -2:word16] = Mem742[ds:22712:word16];
								Mem748[ss:sp_508 + -4:word16] = Mem745[ds:0x5970:word16];
								Mem751[ss:sp_508 + -6:word16] = Mem748[ds:22898:word16];
								fn0C74_076B(ds, ss->*((word16) sp_508 - 6), ss->*((word16) sp_508 - 4), ss->*((word16) sp_508 - 2), ss->*sp_508);
								Mem765[ds:22707:byte] = 0x01;
								goto l0C74_4994;
							}
						}
						Mem708[ss:sp_508 + 0x00:word16] = Mem680[ds:22892:word16];
						Mem711[ss:sp_508 + -2:word16] = Mem708[ds:22894:word16];
						Mem714[ss:sp_508 + -4:word16] = Mem711[ds:0x5970:word16];
						Mem717[ss:sp_508 + -6:word16] = Mem714[ds:22898:word16];
						fn0C74_076B(ds, ss->*((word16) sp_508 - 6), ss->*((word16) sp_508 - 4), ss->*((word16) sp_508 - 2), ss->*sp_508);
						goto l0C74_4994;
					}
					(ss->*((word32) bp_39 - 3)).u3 = &(ss->*((word32) bp_39 - 3)).u3->t0001.u0;
					goto l0C74_488C;
				}
			}
		}
	}
	(ss->*((word32) bp_39 - 4)).u3 = ss->*((word32) bp_39 - 4) - 0x01;
	Mem668[ds:22708:word16] = Mem665[ds:22708:word16] + 0x01;
	Mem670[ds:22710:word16] = Mem668[ds:22710:word16] + 0x01;
	fn11C8_033B(ds);
	goto l0C74_493C;
}
