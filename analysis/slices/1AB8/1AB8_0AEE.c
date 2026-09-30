// 1AB8:0AEE: Register Eq_17 fn1AB8_0AEE(Register Eq_17 ds)
// Called from:
//      fn1AB8_0BAE
Eq_17 fn1AB8_0AEE(Eq_17 ds)
{
	if (Mem7[ds:0xB84E:byte] == 0x00)
		ds = fn1AB8_008B(ds);
	fn1AB8_0F93(ds, 0x01, Mem41[ds:47044:word16], Mem37[ds:47042:word16], 0x00, 0x00);
	fn1AB8_1384(ds, SEQ(ds, 47226));
	fn1AB8_129A(ds, SEQ(ds, 47226));
	if (fn1AB8_1C5A(ds) != 0x01)
		fn1AB8_1250(ds, 0x00);
	Mem117[ds:0xB840:byte] = 0x00;
	fn1AB8_1C32(ds, (byte) fn1AB8_1C4A(ds));
	<unknown> Eq_58901::* fp;
	fn1EDA_1202(~0x00, 0x08, fp - 0x0A);
	fn1AB8_11A0(ds, fn1AB8_1C4A(ds), fp - 0x0A);
	fn1AB8_1175(ds, fn1AB8_1C4A(ds), 0x01);
	fn1AB8_10F4(ds, 0x01, 0x00, 0x00);
	Eq_17 ds_244;
	fn1AB8_1536(ds, 0x01, 0x00, 0x00, out ds_244);
	fn1AB8_14F4(ds_244, 0x02, 0x00);
	fn1AB8_194E(ds_244, 0x00);
	fn1AB8_108B(ds_244, 0x00, 0x00);
	return ds_244;
}
