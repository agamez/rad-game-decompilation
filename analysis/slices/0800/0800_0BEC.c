// 0800:0BEC: Register Eq_17 fn0800_0BEC(Register Eq_17 ds)
// Called from:
//      fn0800_2401
//      fn0800_2827
//      fn0800_2C0C
//      fn0800_31B7
Eq_17 fn0800_0BEC(Eq_17 ds)
{
	Mem14[ds:22732:word16] = CONVERT(Mem7[ds:0x53DD:byte], uint8, uint16);
	Mem15[ds:22734:word16] = 0x00;
	Mem17[ds:22748:word16] = 0x00;
	Mem18[ds:22750:word16] = 0x00;
	int16 dx_20 = Mem18[ds:22734:word16];
	Mem21[ds:22724:word16] = Mem18[ds:22732:word16];
	Mem22[ds:22726:word16] = dx_20;
	word16 dx_24 = Mem22[ds:22750:word16];
	Mem25[ds:22728:word16] = Mem22[ds:22748:word16];
	Mem26[ds:22730:word16] = dx_24;
	Mem27[ds:0x53E0:byte] = 0x00;
	Mem28[ds:0x53E1:byte] = 0x00;
	Mem36[ds:22740:word16] = CONVERT(Mem28[ds:0x53DD:byte], uint8, uint16) *s 0x5F;
	Mem38[ds:22742:word16] = 0x00;
	fn1AB8_1C32(ds, 0x08);
	struct Eq_2416 * cs;
	byte ch_140;
	fn1AB8_1D82(ds, &cs->t0BE1, 0x0196, 0x0233, out ch_140);
	fn1AB8_1C32(ds, 0x0A);
	byte ch_141;
	fn1AB8_1D82(ds, &cs->t0BE1, 0x0197, 0x0234, out ch_141);
	Eq_17 ds_97;
	fn0800_0B42(ds, out ds_97);
	Eq_17 ds_112;
	fn0800_0AA1(ds_97, out ds_112);
	return ds_112;
}
