// 0C74:05B8: Register (memptr Eq_17 Eq_21071) fn0C74_05B8(Register Eq_17 ds, Register out Eq_17 dsOut)
// Called from:
//      fn0C74_06B7
//      fn0C74_0FA1
//      fn0C74_1F08
//      fn0C74_522C
struct Eq_21071 Eq_17::* fn0C74_05B8(Eq_17 ds, union Eq_17 & dsOut)
{
	mp16 fp;
	Eq_17 ax_11 = fn1AB8_10E1(ds);
	Eq_17 bp_221 = fp - 2;
	Eq_17 ax_21 = Mem7[ds:22714:word16];
	byte dl_370;
	byte dl_371;
	selector ss;
	if ((false || true && ax_21 < ax_11) && (fn1AB8_1E3C(ds, Mem34[ds:22714:word16] + 0x01, Mem7[ds:22708:word16], out dl_370) == 0x00 && fn1AB8_1E3C(ds, Mem56[ds:22714:word16] + 0x01, Mem39[ds:22710:word16], out dl_371) == 0x00))
	{
		Eq_17 v22_79 = Mem78[ds:22712:word16];
		Eq_17 v23_82 = Mem81[ds:22710:word16];
		Eq_17 ds_109;
		fn1AB8_1E6B(ds_109, fn1EDA_023F(ds, v23_82, v22_79, fn1AB8_13A3(ds, Mem84[ds:22714:word16], v23_82, v22_79, Mem61[ds:22708:word16]), out ds_109), Mem128[ds_109:22714:word16], Mem125[ds_109:22710:word16], Mem122[ds_109:22712:word16], Mem119[ds_109:22708:word16]);
		mp16 sp_149 = fp - 0x08;
		while (true)
		{
			Eq_17 ax_151 = fn1AB8_10E1(ds_109);
			Eq_17 ax_162 = Mem161[ds_109:22714:word16];
			if (true && (false || ax_162 >= ax_151))
				break;
			struct Eq_21160 Eq_17::* sp_174 = sp_149 - 2;
			Mem177[ss:sp_174 + 0x00:word16] = Mem161[ds_109:22708:word16];
			Mem182[ss:sp_174 + -2:word16] = Mem177[ds_109:22714:word16] + 0x01;
			byte dl_372;
			if (fn1AB8_1E3C(ds_109, (ss->*sp_174).tFFFE.u2, (ss->*sp_174).t0000.u2, out dl_372) != 0x00)
				break;
			Mem199[ss:sp_174 + 0x00:word16] = Mem182[ds_109:22710:word16];
			Mem204[ss:sp_174 + -2:word16] = Mem199[ds_109:22714:word16] + 0x01;
			byte dl_374;
			if (fn1AB8_1E3C(ds_109, (ss->*sp_174).tFFFE.u2, (ss->*sp_174).t0000.u2, out dl_374) != 0x00)
				break;
			Mem253[ds_109:22712:word16] = Mem204[ds_109:22712:word16] + 0x01;
			Mem255[ds_109:22714:word16] = Mem253[ds_109:22714:word16] + 0x01;
			Mem259[ss:sp_174 + 0x00:word16] = Mem255[ds_109:22708:word16];
			Mem262[ss:sp_174 + -2:word16] = Mem259[ds_109:22712:word16];
			Eq_17 es_di_263 = ss->*((word32) bp_221 - 4);
			(ss->*sp_174).ptrFFFC = SLICE(es_di_263, selector, 16);
			(ss->*sp_174).tFFFA.u2 = (uint16) (word16) es_di_263;
			(ss->*sp_174).wFFF8 = 0x00;
			fn1AB8_13D7(ds_109, (ss->*sp_174).t0008.u0, (ss->*sp_174).tFFFA.u3, (ss->*sp_174).tFFFE.u2, (ss->*sp_174).t0000.u2);
			Mem286[ss:sp_174 + 0x00:word16] = Mem271[ds_109:22758:word16];
			Eq_481 sp_296;
			sp_296.u0 = <invalid>;
			bp_221 = fn0C74_02D8(ds_109, (ss->*sp_174).t0000.u2, out ds_109);
			sp_149 = (word16) sp_296 + 2;
		}
		struct Eq_21194 Eq_17::* sp_226 = sp_149 - 2;
		(ss->*sp_226).t0000.u1 = (word16) (ss->*((word32) bp_221 - 2));
		(ss->*sp_226).tFFFE.u2 = (uint16) (ss->*((word32) bp_221 - 4));
		(ss->*sp_226).tFFFC.u2 = (uint16) (ss->*((word32) bp_221 - 6));
		word16 dx_373;
		fn1EDA_0254(ds_109, (ss->*sp_226).tFFF8.u2, (ss->*sp_226).tFFFA.u2, (ss->*sp_226).tFFFC.u2, (ss->*sp_226).tFFFE.u3, out dx_373, out ds);
	}
	struct Eq_21071 Eq_17::* bp_306 = (struct Eq_21071 Eq_17::*) (ss->*bp_221.u3).t0000.u2;
	dsOut = ds;
	return bp_306;
}
