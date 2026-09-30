// 0C74:02D8: Register word16 fn0C74_02D8(Register Eq_17 ds, Stack Eq_17 wArg02, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_05B8
//      fn0C74_070D
//      fn0C74_0FA1
//      fn0C74_1B3B
//      fn0C74_1F08
//      fn0C74_2AD9
//      fn0C74_2E5A
//      fn0C74_3236
//      fn0C74_3615
//      fn0C74_37C3
//      fn0C74_396E
//      fn0C74_3F74
//      fn0C74_45CE
//      fn0C74_4999
//      fn0C74_4DAC
//      fn0C74_4FD7
word16 fn0C74_02D8(Eq_17 ds, Eq_17 wArg02, union Eq_17 & dsOut)
{
	mp16 fp;
	struct Eq_20614 Eq_20633::* bp_106 = fp - 2;
	struct Eq_20617 Eq_20633::* sp_154 = fp - 6;
	selector ss;
	if (Mem7[ds:22718:byte] == 0x00)
	{
		word16 dx_269;
		fn1E78_029C(ds, wArg02, out dx_269);
	}
	else if ((uint32) wArg02 /u 0x07 >= 0x00)
	{
		while (true)
		{
			selector ds_44;
			word16 cx_270;
			word16 dx_45;
			word16 bx_271;
			Mem55[ds_44:22732:word16] = fn1EDA_098A(0x3C, Mem28[ds:22744:word32], Mem28[ss:sp_154 + -4:word16], Mem28[ss:sp_154 + -2:word16], out cx_270, out dx_45, out bx_271, out ds_44);
			ds_44->w58CE = dx_45;
			Eq_17 cx_68;
			word16 dx_272;
			word16 bx_67;
			fn1EDA_098A(0x3C, ds_44->t58D8, (ss->*sp_154).wFFFC, (ss->*sp_154).wFFFE, out cx_68, out dx_272, out bx_67, out ds);
			Mem82[ds:22748:word16] = cx_68;
			Mem83[ds:22750:word16] = bx_67;
			Eq_17 ax_84 = Mem83[ds:22748:word16];
			struct Eq_20729 Eq_20633::* sp_102;
			if (Mem83[ds:22750:word16] == Mem83[ds:22730:word16] && ax_84 == Mem83[ds:22728:word16])
			{
				struct Eq_20736 Eq_20633::* sp_90 = sp_154 - 2;
				(ss->*sp_90).t0000.u2 = (uint16) 0x02;
				word16 dx_273;
				fn1E78_029C(ds, (ss->*sp_90).t0000.u2, out dx_273);
				sp_102 = (struct Eq_20729 Eq_20633::*) (sp_90 + 1);
			}
			else
			{
				(ss->*sp_154).wFFFE = bp_106;
				bp_106 = fn0C74_011E(ds, out ds);
				word16 dx_129 = Mem108[ds:22750:word16];
				Mem130[ds:22728:word16] = Mem108[ds:22748:word16];
				Mem131[ds:22730:word16] = dx_129;
				Eq_481 sp_120;
				sp_120.u0 = <invalid>;
				sp_102 = (word16) sp_120 + 2;
			}
			Eq_17 ax_134 = Mem133[ds:22732:word16];
			if (Mem133[ds:22734:word16] == Mem133[ds:22726:word16] && ax_134 == Mem133[ds:22724:word16])
			{
				struct Eq_20793 Eq_20633::* sp_141 = sp_102 - 2;
				(ss->*sp_141).t0000.u2 = (uint16) 0x02;
				word16 dx_274;
				fn1E78_029C(ds, (ss->*sp_141).t0000.u2, out dx_274);
				sp_154 = (struct Eq_20617 Eq_20633::*) (sp_141 + 1);
			}
			else
			{
				(ss->*sp_102).wFFFE = bp_106;
				bp_106 = fn0C74_020C(ds, out ds);
				word16 dx_182 = Mem160[ds:22734:word16];
				Mem183[ds:22724:word16] = Mem160[ds:22732:word16];
				Mem184[ds:22726:word16] = dx_182;
				Eq_481 sp_173;
				sp_173.u0 = <invalid>;
				sp_154 = (word16) sp_173 + 2;
			}
			if ((ss->*bp_106).wFFFE == (ss->*bp_106).wFFFC)
				break;
			++(ss->*bp_106).wFFFE;
		}
	}
	word16 bp_212 = (ss->*bp_106).w0000;
	dsOut = ds;
	return bp_212;
}
