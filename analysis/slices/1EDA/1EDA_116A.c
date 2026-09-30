// 1EDA:116A: Register Eq_17 fn1EDA_116A(Register Eq_17 ds, Stack Eq_17 ptrArg04, Register out Eq_17 dsOut)
// Called from:
//      fn0800_4168
//      fn0C43_00B9
//      fn1229_0735
//      fn1AB8_0887
Eq_17 fn1EDA_116A(Eq_17 ds, Eq_17 ptrArg04, union Eq_17 & dsOut)
{
	Eq_17 bx_cx_69;
	ui32 dx_ax_71;
	Eq_17 ax_17 = (word16) dx_ax_71;
	Eq_17 cx_12 = (word16) bx_cx_69;
	struct Eq_65411 * es_di_68;
	if (!fn1EDA_119A(ds, ptrArg04, out bx_cx_69, out dx_ax_71, out es_di_68))
	{
		ax_17 = cx_12;
		uint16 cx_19 = es_di_68->w0004;
		if (cx_19 != 0x01)
		{
			Eq_17 wLoc04;
			Eq_17 wLoc02;
			word16 cx_72;
			word16 dx_73;
			word16 bx_74;
			ax_17 = fn1EDA_098A((uint32) cx_19, bx_cx_69, wLoc04, wLoc02, out cx_72, out dx_73, out bx_74, out ds);
		}
	}
	dsOut = ds;
	return ax_17;
}
