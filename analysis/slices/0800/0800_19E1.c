// 0800:19E1: Register byte fn0800_19E1(Register Eq_17 ds, Stack Eq_17 ptrArg04, Register out word16 dxOut, Register out (memptr Eq_17 Eq_6316) bpOut, Register out (ptr16 Eq_6310) dsOut)
// Called from:
//      fn0800_1E3F
//      fn0800_2004
//      fn0800_21E7
//      fn0800_391E
//      fn0800_3D9D
byte fn0800_19E1(Eq_17 ds, Eq_17 ptrArg04, word16 & dxOut, struct Eq_6316 & bpOut, struct Eq_6310 & dsOut)
{
	Eq_17 ss;
	<unknown> Eq_17::* fp;
	word16 dx_819;
	fn1EDA_0A39(~0x00, SEQ(ss, fp - 0x0102), ptrArg04, out dx_819);
	struct Eq_4927 Eq_17::* bp_39;
	Eq_17 ds_43;
	fn1206_0066(ds, out bp_39, out ds_43);
	Eq_481 sp_47;
	sp_47.u0 = <invalid>;
	ss->*((word16) sp_47 - 2) = 0x01;
	ss->*((word16) sp_47 - 4) = 0x00;
	ss->*((word16) sp_47 - 6) = 0x03;
	Eq_17 ds_66;
	fn1AB8_1536(ds_43, ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2), out ds_66);
	ss->*((word16) sp_47 - 2) = 0x01;
	ss->*((word16) sp_47 - 4) = 0x03;
	fn1AB8_1175(ds_66, ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2));
	ss->*((word16) sp_47 - 2) = 0x00;
	ss->*((word16) sp_47 - 4) = 0x00;
	ss->*((word16) sp_47 - 6) = 0x01;
	fn1AB8_10F4(ds_66, ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2));
	ss->*((word16) sp_47 - 2) = 0x01;
	ss->*((word16) sp_47 - 4) = 0x01;
	fn1AB8_14F4(ds_66, ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2));
	ss->*((word16) sp_47 - 2) = ss;
	ss->*((word16) sp_47 - 4) = bp_39 - 0x0100;
	(*((word32) ds_66 + 21474))[(ss->*bp_39).w000E] = (ss->*bp_39).t000C.u2 - (fn1AB8_1E0B(ds_66, ss->*((word16) sp_47 - 4)) >> 0x01) - 0x05;
	ss->*((word16) sp_47 - 2) = ss;
	ss->*((word16) sp_47 - 4) = bp_39 - 0x0100;
	(*((word32) ds_66 + 21502))[(ss->*bp_39).w000E] = (ss->*bp_39).t000C.u2 + (fn1AB8_1E0B(ds_66, ss->*((word16) sp_47 - 4)) >> 0x01) + 0x05;
	ss->*((word16) sp_47 - 2) = ss;
	ss->*((word16) sp_47 - 4) = bp_39 - 0x0100;
	(*((word32) ds_66 + 21488))[(ss->*bp_39).w000E] = (ss->*bp_39).t000A.u2 - (fn1AB8_1783(ds_66, ss->*((word16) sp_47 - 4)) >> 0x01);
	ss->*((word16) sp_47 - 2) = ss;
	ss->*((word16) sp_47 - 4) = bp_39 - 0x0100;
	(*((word32) ds_66 + 21516))[(ss->*bp_39).w000E] = (ss->*bp_39).t000A.u2 + (fn1AB8_1783(ds_66, ss->*((word16) sp_47 - 4)) >> 0x01) + 0x05;
	(*((word32) ds_66 + 0x0000541A))[(ss->*bp_39).w000E].t0000.u2 = (ss->*bp_39).t000C.u2;
	(*((word32) ds_66 + 21544))[(ss->*bp_39).w000E].t0000.u2 = (ss->*bp_39).t000A.u2;
	ss->*((word16) sp_47 - 2) = ss;
	ss->*((word16) sp_47 - 4) = bp_39 - 0x0100;
	int16 di_267 = (ss->*bp_39).w000E *s 0x1A;
	ss->*((word16) sp_47 - 6) = ds_66;
	ss->*((word16) sp_47 - 8) = di_267 + 0x541E;
	ss->*((word16) sp_47 - 0x0A) = 0x19;
	word16 dx_820;
	fn1EDA_0A39(ss->*((word16) sp_47 + 0x0A), ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 4), out dx_820);
	(ss->*bp_39).tFEFE.u2 = (*((word32) ds_66 + 21474))[(ss->*bp_39).w000E].t0000.u2;
	(ss->*bp_39).tFEFA.u2 = (*((word32) ds_66 + 21502))[(ss->*bp_39).w000E].t0000.u2;
	(ss->*bp_39).tFEFC.u2 = (*((word32) ds_66 + 21488))[(ss->*bp_39).w000E].t0000.u2;
	(ss->*bp_39).tFEF8.u2 = (*((word32) ds_66 + 21516))[(ss->*bp_39).w000E].t0000.u2;
	(ss->*((word16) sp_47 - 2)).u1 = (ss->*bp_39).tFEFE.u2;
	(ss->*((word16) sp_47 - 4)).u1 = (ss->*bp_39).tFEFC.u2;
	(ss->*((word16) sp_47 - 6)).u1 = (ss->*bp_39).tFEFA.u2;
	(ss->*((word16) sp_47 - 8)).u1 = (ss->*bp_39).tFEF8.u2;
	fn1AB8_1B3E(ds_66, ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2));
	ss->*((word16) sp_47 - 2) = 11;
	fn1AB8_1C32(ds_66, ss->*((word16) sp_47 - 2));
	if ((ss->*bp_39).b0004 != 0x00)
	{
		ss->*((word16) sp_47 - 2) = 0x00;
		fn1AB8_1C32(ds_66, ss->*((word16) sp_47 - 2));
	}
	ss->*((word16) sp_47 - 2) = (ss->*bp_39).tFEFE.u2 - 0x03;
	(ss->*((word16) sp_47 - 4)).u1 = (ss->*bp_39).tFEFC.u2;
	ss->*((word16) sp_47 - 6) = (ss->*bp_39).tFEFA.u2 + 0x03;
	(ss->*((word16) sp_47 - 8)).u1 = (ss->*bp_39).tFEFC.u2;
	word16 dx_821;
	fn1AB8_1AF6(ds_66, ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2), out dx_821);
	ss->*((word16) sp_47 - 2) = (ss->*bp_39).tFEFE.u2 - 0x02;
	ss->*((word16) sp_47 - 4) = (ss->*bp_39).tFEFC.u2 + 0x01;
	ss->*((word16) sp_47 - 6) = (ss->*bp_39).tFEFA.u2 + 0x01;
	ss->*((word16) sp_47 - 8) = (ss->*bp_39).tFEFC.u2 + 0x01;
	word16 dx_822;
	fn1AB8_1AF6(ds_66, ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2), out dx_822);
	ss->*((word16) sp_47 - 2) = 11;
	fn1AB8_1C32(ds_66, ss->*((word16) sp_47 - 2));
	ss->*((word16) sp_47 - 2) = (ss->*bp_39).tFEFE.u2 - 0x01;
	ss->*((word16) sp_47 - 4) = (ss->*bp_39).tFEFC.u2 + 0x02;
	(ss->*((word16) sp_47 - 6)).u1 = (ss->*bp_39).tFEFA.u2;
	ss->*((word16) sp_47 - 8) = (ss->*bp_39).tFEFC.u2 + 0x02;
	word16 dx_823;
	fn1AB8_1AF6(ds_66, ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2), out dx_823);
	if ((ss->*bp_39).b0004 != 0x00)
	{
		ss->*((word16) sp_47 - 2) = 0x00;
		fn1AB8_1C32(ds_66, ss->*((word16) sp_47 - 2));
	}
	ss->*((word16) sp_47 - 2) = (ss->*bp_39).tFEFE.u2 - 0x03;
	(ss->*((word16) sp_47 - 4)).u1 = (ss->*bp_39).tFEFC.u2;
	ss->*((word16) sp_47 - 6) = (ss->*bp_39).tFEFE.u2 - 0x03;
	ss->*((word16) sp_47 - 8) = (ss->*bp_39).tFEF8.u2 + 0x02;
	word16 dx_824;
	fn1AB8_1AF6(ds_66, ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2), out dx_824);
	ss->*((word16) sp_47 - 2) = (ss->*bp_39).tFEFE.u2 - 0x02;
	ss->*((word16) sp_47 - 4) = (ss->*bp_39).tFEFC.u2 + 0x01;
	ss->*((word16) sp_47 - 6) = (ss->*bp_39).tFEFE.u2 - 0x02;
	ss->*((word16) sp_47 - 8) = (ss->*bp_39).tFEF8.u2 + 0x01;
	word16 dx_825;
	fn1AB8_1AF6(ds_66, ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2), out dx_825);
	ss->*((word16) sp_47 - 2) = 11;
	fn1AB8_1C32(ds_66, ss->*((word16) sp_47 - 2));
	ss->*((word16) sp_47 - 2) = (ss->*bp_39).tFEFE.u2 - 0x01;
	ss->*((word16) sp_47 - 4) = (ss->*bp_39).tFEFC.u2 + 0x02;
	ss->*((word16) sp_47 - 6) = (ss->*bp_39).tFEFE.u2 - 0x01;
	(ss->*((word16) sp_47 - 8)).u1 = (ss->*bp_39).tFEF8.u2;
	word16 dx_826;
	fn1AB8_1AF6(ds_66, ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2), out dx_826);
	ss->*((word16) sp_47 - 2) = 0x08;
	fn1AB8_1C32(ds_66, ss->*((word16) sp_47 - 2));
	if ((ss->*bp_39).b0004 != 0x00)
	{
		ss->*((word16) sp_47 - 2) = 0x00;
		fn1AB8_1C32(ds_66, ss->*((word16) sp_47 - 2));
	}
	ss->*((word16) sp_47 - 2) = (ss->*bp_39).tFEFA.u2 + 0x03;
	(ss->*((word16) sp_47 - 4)).u1 = (ss->*bp_39).tFEFC.u2;
	ss->*((word16) sp_47 - 6) = (ss->*bp_39).tFEFA.u2 + 0x03;
	ss->*((word16) sp_47 - 8) = (ss->*bp_39).tFEF8.u2 + 0x01;
	word16 dx_827;
	fn1AB8_1AF6(ds_66, ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2), out dx_827);
	ss->*((word16) sp_47 - 2) = (ss->*bp_39).tFEFA.u2 + 0x02;
	ss->*((word16) sp_47 - 4) = (ss->*bp_39).tFEFC.u2 + 0x01;
	ss->*((word16) sp_47 - 6) = (ss->*bp_39).tFEFA.u2 + 0x02;
	(ss->*((word16) sp_47 - 8)).u1 = (ss->*bp_39).tFEF8.u2;
	word16 dx_828;
	fn1AB8_1AF6(ds_66, ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2), out dx_828);
	ss->*((word16) sp_47 - 2) = 0x08;
	fn1AB8_1C32(ds_66, ss->*((word16) sp_47 - 2));
	ss->*((word16) sp_47 - 2) = (ss->*bp_39).tFEFA.u2 + 0x01;
	ss->*((word16) sp_47 - 4) = (ss->*bp_39).tFEFC.u2 + 0x02;
	ss->*((word16) sp_47 - 6) = (ss->*bp_39).tFEFA.u2 + 0x01;
	ss->*((word16) sp_47 - 8) = (ss->*bp_39).tFEF8.u2 - 0x01;
	word16 dx_829;
	fn1AB8_1AF6(ds_66, ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2), out dx_829);
	if ((ss->*bp_39).b0004 != 0x00)
	{
		ss->*((word16) sp_47 - 2) = 0x00;
		fn1AB8_1C32(ds_66, ss->*((word16) sp_47 - 2));
	}
	ss->*((word16) sp_47 - 2) = (ss->*bp_39).tFEFE.u2 - 0x02;
	ss->*((word16) sp_47 - 4) = (ss->*bp_39).tFEF8.u2 + 0x02;
	ss->*((word16) sp_47 - 6) = (ss->*bp_39).tFEFA.u2 + 0x02;
	ss->*((word16) sp_47 - 8) = (ss->*bp_39).tFEF8.u2 + 0x02;
	word16 dx_830;
	fn1AB8_1AF6(ds_66, ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2), out dx_830);
	ss->*((word16) sp_47 - 2) = (ss->*bp_39).tFEFE.u2 - 0x01;
	ss->*((word16) sp_47 - 4) = (ss->*bp_39).tFEF8.u2 + 0x01;
	ss->*((word16) sp_47 - 6) = (ss->*bp_39).tFEFA.u2 + 0x01;
	ss->*((word16) sp_47 - 8) = (ss->*bp_39).tFEF8.u2 + 0x01;
	word16 dx_831;
	fn1AB8_1AF6(ds_66, ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2), out dx_831);
	ss->*((word16) sp_47 - 2) = 0x08;
	fn1AB8_1C32(ds_66, ss->*((word16) sp_47 - 2));
	(ss->*((word16) sp_47 - 2)).u1 = (ss->*bp_39).tFEFE.u2;
	(ss->*((word16) sp_47 - 4)).u1 = (ss->*bp_39).tFEF8.u2;
	(ss->*((word16) sp_47 - 6)).u1 = (ss->*bp_39).tFEFA.u2;
	(ss->*((word16) sp_47 - 8)).u1 = (ss->*bp_39).tFEF8.u2;
	word16 dx_832;
	fn1AB8_1AF6(ds_66, ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2), out dx_832);
	ss->*((word16) sp_47 - 2) = 0x00;
	fn1AB8_1C32(ds_66, ss->*((word16) sp_47 - 2));
	ss->*((word16) sp_47 - 2) = (ss->*bp_39).tFEFE.u2 - 0x04;
	ss->*((word16) sp_47 - 4) = (ss->*bp_39).tFEFC.u2 - 0x01;
	ss->*((word16) sp_47 - 6) = (ss->*bp_39).tFEFA.u2 + 0x04;
	ss->*((word16) sp_47 - 8) = (ss->*bp_39).tFEF8.u2 + 0x03;
	fn1AB8_112E(ds_66, ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 6), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2));
	ss->*((word16) sp_47 - 2) = 0x01;
	fn1AB8_1C32(ds_66, ss->*((word16) sp_47 - 2));
	if ((ss->*bp_39).b0004 != 0x00)
	{
		ss->*((word16) sp_47 - 2) = 0x0E;
		fn1AB8_1C32(ds_66, ss->*((word16) sp_47 - 2));
	}
	(ss->*((word16) sp_47 - 2)).u1 = (ss->*bp_39).t000C.u2;
	(ss->*((word16) sp_47 - 4)).u1 = (ss->*bp_39).t000A.u2;
	ss->*((word16) sp_47 - 6) = ss;
	ss->*((word16) sp_47 - 8) = bp_39 - 0x0100;
	byte ch_833;
	fn1AB8_1D82(ds_66, ss->*((word16) sp_47 - 8), ss->*((word16) sp_47 - 4), ss->*((word16) sp_47 - 2), out ch_833);
	byte ch_834;
	word16 dx_768;
	struct Eq_6316 Eq_17::* Eq_17::* bp_763;
	struct Eq_6310 * ds_767;
	fn1206_0038(ds_66, out ch_834, out dx_768, out bp_763, out ds_767);
	struct Eq_6316 Eq_17::* bp_777 = (struct Eq_6316 Eq_17::*) (ss->*bp_763);
	dxOut = dx_768;
	bpOut = bp_777;
	dsOut = ds_767;
	Eq_481 cx_765;
	cx_765.u0 = <invalid>;
	return SLICE(cx_765, byte, 8);
}
