// 1AB8:11FB: Register Eq_17 fn1AB8_11FB(Register Eq_17 ds, Stack uint16 wArg02, Register out (ptr16 Eq_60107) dsOut)
// Called from:
//      fn1AB8_122E
Eq_17 fn1AB8_11FB(Eq_17 ds, uint16 wArg02, struct Eq_60107 & dsOut)
{
	struct Eq_60107 * ds_46;
	word16 bx_71;
	word16 dx_70;
	word16 cx_69;
	Eq_17 ax_11 = Mem7[ds:0xB84C:word16];
	Eq_17 ax_43 = fn1EDA_098A((uint32) ax_11, fn1EDA_096F(wArg02, Mem16[ds:47178:word16], 0x00, 0x00), ax_11, 0x00, out cx_69, out dx_70, out bx_71, out ds_46);
	dsOut = ds_46;
	return ax_43;
}
