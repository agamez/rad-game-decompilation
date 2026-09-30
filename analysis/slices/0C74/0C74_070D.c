// 0C74:070D: Register (memptr Eq_17 Eq_21071) fn0C74_070D(Register Eq_17 ds, Stack Eq_17 wArg02, Stack Eq_17 wArg04, Register out (ptr16 Eq_21455) dsOut)
// Called from:
//      fn0C74_0CFA
//      fn0C74_0D43
//      fn0C74_0D94
//      fn0C74_0DE5
//      fn0C74_0E2E
//      fn0C74_0FA1
//      fn0C74_1B3B
//      fn0C74_1D95
//      fn0C74_1F08
//      fn0C74_2AD9
//      fn0C74_2E5A
//      fn0C74_3236
//      fn0C74_396E
//      fn0C74_3F74
//      fn0C74_45CE
//      fn0C74_4999
//      fn0C74_4DAC
//      fn0C74_4FD7
struct Eq_21071 Eq_17::* fn0C74_070D(Eq_17 ds, Eq_17 wArg02, Eq_17 wArg04, struct Eq_21455 & dsOut)
{
	struct Eq_21455 * ds_82;
	Eq_17 ds_50;
	int32 dx_ax_13 = CONVERT(Mem7[ds:22758:word16] *u16 wArg02, int16, word32);
	if (Mem20[ds:0x58B0:byte] != 0x00)
		fn11C8_0354(ds, wArg04);
	Eq_17 bp_46 = fn0C74_02D8(ds, dx_ax_13 /16 0x09, out ds_50);
	Eq_481 sp_54;
	sp_54.u0 = <invalid>;
	if (Mem41[ds_50:0x58B0:byte] != 0x00)
		fn11C8_033B(ds_50);
	selector ss;
	(ss->*sp_54).u1 = (ss->*bp_46.u3).t0004.u2;
	struct Eq_21071 Eq_17::* bp_92 = (struct Eq_21071 Eq_17::*) (ss->*(fn0C74_02D8)(ds_50, ss->*sp_54, out ds_82).u3).t0000.u2;
	dsOut = ds_82;
	return bp_92;
}
