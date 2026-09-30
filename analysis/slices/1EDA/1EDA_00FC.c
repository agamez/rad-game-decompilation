// 1EDA:00FC: void fn1EDA_00FC(Register Eq_17 cx, Register Eq_17 bx, Register Eq_17 ds)
// Called from:
//      fn1EDA_00E9
//      fn1EDA_00ED
void fn1EDA_00FC(Eq_17 cx, Eq_17 bx, Eq_17 ds)
{
	Eq_17 ax_38 = Mem0[ds:21332:word16];
	while (ax_38 != 0x00)
	{
		if (bx == Mem0[ax_38:0x10:word16])
		{
			bx = ax_38;
			break;
		}
		ax_38 = Mem0[ax_38:0x14:word16];
	}
	ptr16 bx_23 = bx - Mem0[ds:21372:word16];
	fn1EDA_011B(cx, bx_23 - 0x10, ds);
}
