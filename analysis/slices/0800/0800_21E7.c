// 0800:21E7: Register Eq_17 fn0800_21E7(Register Eq_17 ds)
// Called from:
//      fn0800_3D9D
Eq_17 fn0800_21E7(Eq_17 ds)
{
	Eq_17 ds_102;
	fn1AB8_1536(ds, 0x18, 0x00, 0x01, out ds_102);
	fn1AB8_14F4(ds_102, 0x01, 0x01);
	fn0800_1315(ds_102, 0x016A, 0x01E0, 0x14, 0x9C);
	fn1AB8_1C32(ds_102, 0x0A);
	Eq_17 cs;
	byte ch_650;
	fn1AB8_1D82(ds_102, SEQ(cs, 0x2155), 0x47, 0x0140, out ch_650);
	Eq_17 ss;
	<unknown> Eq_17::* fp;
	if (Mem75[ds_102:0x02:byte] >u 0x1E)
	{
		fn1AB8_1536(ds_102, 0x04, 0x00, 0x02, out ds_102);
		Eq_17 ptrLoc020A_611 = SEQ(ss, fp - 0x0202);
		fn1EDA_0A1F(SEQ(cs, 0x2159), ptrLoc020A_611);
		Eq_17 ptrLoc020E_618 = SEQ(ss, fp - 0x0102);
		fn0C74_004B(CONVERT(Mem140[ds_102:23730:byte], uint8, uint32), ptrLoc020E_618);
		fn1EDA_0AAC(ptrLoc020E_618, ptrLoc020A_611);
		fn1EDA_0AAC(SEQ(cs, 0x2170), ptrLoc020A_611);
		byte ch_651;
		fn1AB8_1D82(ds_102, ptrLoc020A_611, 0x96, 0x0140, out ch_651);
	}
	Eq_17 ds_234;
	word16 sp_244;
	if (Mem208[ds_102:22928:word16] == 0x00 && Mem208[ds_102:22926:word16] == 0x01)
	{
		word16 dx_654;
		word16 bp_655;
		fn0800_19E1(ds_102, SEQ(cs, 0x2180), out dx_654, out bp_655, out ds_234);
		Eq_481 sp_238;
		sp_238.u0 = <invalid>;
		sp_244 = (word16) sp_238 + 0x0C;
	}
	else
	{
		Eq_17 ptrLoc020C_636 = SEQ(ss, fp - 0x0102);
		fn1EDA_0A1F(SEQ(cs, 0x217A), ptrLoc020C_636);
		fn1EDA_0AAC(SEQ(ds_102, 24278), ptrLoc020C_636);
		fn1EDA_0AAC(SEQ(cs, 0x217E), ptrLoc020C_636);
		word16 dx_652;
		word16 bp_653;
		fn0800_19E1(ds_102, ptrLoc020C_636, out dx_652, out bp_653, out ds_234);
		Eq_481 sp_327;
		sp_327.u0 = <invalid>;
		sp_244 = (word16) sp_327 + 0x0C;
	}
	struct Eq_7450 Eq_17::* sp_335 = sp_244 - 2;
	(ss->*sp_335).w0000 = 0x02;
	(ss->*sp_335).wFFFE = 400;
	(ss->*sp_335).wFFFC = 0xB4;
	(ss->*sp_335).tFFFA.u2 = (uint16) cs;
	(ss->*sp_335).tFFF8.u2 = (uint16) 8588;
	(ss->*sp_335).wFFF6 = 0x00;
	word16 dx_656;
	word16 bp_657;
	Eq_17 ds_356;
	fn0800_19E1(ds_234, (ss->*sp_335).tFFF8.u3, out dx_656, out bp_657, out ds_356);
	Eq_481 sp_360;
	sp_360.u0 = <invalid>;
	ss->*((word16) sp_360 + 0x0A) = 0x03;
	ss->*((word16) sp_360 + 8) = 0xF0;
	ss->*((word16) sp_360 + 6) = 0xE6;
	ss->*((word16) sp_360 + 4) = cs;
	ss->*((word16) sp_360 + 2) = 8599;
	ss->*sp_360 = 0x00;
	word16 dx_658;
	word16 bp_659;
	Eq_17 ds_385;
	fn0800_19E1(ds_356, ss->*((word16) sp_360 + 2), out dx_658, out bp_659, out ds_385);
	Eq_481 sp_389;
	sp_389.u0 = <invalid>;
	Eq_17 ds_416;
	word16 sp_426;
	if (Mem379[ds_385:0x58B0:byte] != 0x00)
	{
		ss->*((word16) sp_389 + 0x0A) = 0x04;
		ss->*((word16) sp_389 + 8) = 400;
		ss->*((word16) sp_389 + 6) = 0xE6;
		ss->*((word16) sp_389 + 4) = cs;
		ss->*((word16) sp_389 + 2) = 0x21A2;
		ss->*sp_389 = 0x00;
		word16 dx_662;
		word16 bp_663;
		fn0800_19E1(ds_385, ss->*((word16) sp_389 + 2), out dx_662, out bp_663, out ds_416);
		Eq_481 sp_449;
		sp_449.u0 = <invalid>;
		sp_426 = (word16) sp_449 + 0x0C;
	}
	else
	{
		ss->*((word16) sp_389 + 0x0A) = 0x04;
		ss->*((word16) sp_389 + 8) = 400;
		ss->*((word16) sp_389 + 6) = 0xE6;
		ss->*((word16) sp_389 + 4) = cs;
		ss->*((word16) sp_389 + 2) = 0x21A2;
		ss->*sp_389 = 0x01;
		word16 dx_660;
		word16 bp_661;
		fn0800_19E1(ds_385, ss->*((word16) sp_389 + 2), out dx_660, out bp_661, out ds_416);
		Eq_481 sp_420;
		sp_420.u0 = <invalid>;
		sp_426 = (word16) sp_420 + 0x0C;
	}
	Eq_17 ds_481;
	word16 sp_491;
	if (Mem457[ds_416:0x02:byte] >u 0x1E)
	{
		struct Eq_7683 Eq_17::* sp_492 = sp_426 - 2;
		(ss->*sp_492).w0000 = 0x05;
		(ss->*sp_492).wFFFE = 0xF0;
		(ss->*sp_492).wFFFC = 0x0118;
		(ss->*sp_492).tFFFA.u2 = (uint16) cs;
		(ss->*sp_492).tFFF8.u2 = (uint16) 0x21AD;
		(ss->*sp_492).wFFF6 = 0x00;
		word16 dx_666;
		word16 bp_667;
		fn0800_19E1(ds_416, (ss->*sp_492).tFFF8.u3, out dx_666, out bp_667, out ds_481);
		Eq_481 sp_514;
		sp_514.u0 = <invalid>;
		sp_491 = (word16) sp_514 + 0x0C;
	}
	else
	{
		struct Eq_7635 Eq_17::* sp_461 = sp_426 - 2;
		(ss->*sp_461).w0000 = 0x05;
		(ss->*sp_461).wFFFE = 0xF0;
		(ss->*sp_461).wFFFC = 0x0118;
		(ss->*sp_461).tFFFA.u2 = (uint16) cs;
		(ss->*sp_461).tFFF8.u2 = (uint16) 8633;
		(ss->*sp_461).wFFF6 = 0x00;
		word16 dx_664;
		word16 bp_665;
		fn0800_19E1(ds_416, (ss->*sp_461).tFFF8.u3, out dx_664, out bp_665, out ds_481);
		Eq_481 sp_485;
		sp_485.u0 = <invalid>;
		sp_491 = (word16) sp_485 + 0x0C;
	}
	struct Eq_7729 Eq_17::* sp_522 = sp_491 - 2;
	(ss->*sp_522).w0000 = 0x06;
	(ss->*sp_522).wFFFE = 400;
	(ss->*sp_522).wFFFC = 0x0118;
	(ss->*sp_522).tFFFA.u2 = (uint16) cs;
	(ss->*sp_522).tFFF8.u2 = (uint16) 0x21C5;
	(ss->*sp_522).wFFF6 = 0x00;
	word16 dx_668;
	word16 bp_669;
	Eq_17 ds_543;
	fn0800_19E1(ds_481, (ss->*sp_522).tFFF8.u3, out dx_668, out bp_669, out ds_543);
	Eq_481 sp_547;
	sp_547.u0 = <invalid>;
	ss->*((word16) sp_547 + 0x0A) = 0x07;
	ss->*((word16) sp_547 + 8) = 0x0140;
	ss->*((word16) sp_547 + 6) = 330;
	ss->*((word16) sp_547 + 4) = cs;
	ss->*((word16) sp_547 + 2) = 8656;
	ss->*sp_547 = 0x00;
	word16 dx_670;
	word16 bp_568;
	Eq_17 ds_572;
	fn0800_19E1(ds_543, ss->*((word16) sp_547 + 2), out dx_670, out bp_568, out ds_572);
	return ds_572;
}
