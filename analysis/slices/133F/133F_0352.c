// 133F:0352: Register Eq_17 fn133F_0352(Register Eq_17 ds, Stack Eq_17 ptrArg04, Stack Eq_17 wArg08, Stack Eq_17 wArg0A, Stack Eq_17 wArg0C, Stack Eq_17 wArg0E, Stack Eq_17 bArg10)
// Called from:
//      fn1229_0CCE
Eq_17 fn133F_0352(Eq_17 ds, Eq_17 ptrArg04, Eq_17 wArg08, Eq_17 wArg0A, Eq_17 wArg0C, Eq_17 wArg0E, Eq_17 bArg10)
{
	<unknown> Eq_55994::* fp;
	word16 dx_325;
	fn1EDA_0A39(~0x00, fp - 0x0102, ptrArg04, out dx_325);
	Mem39[ds:0x6CD0:byte] = Mem23[ds:0x6CD0:byte] + 0x01;
	Mem45[ds:CONVERT(Mem39[ds:0x6CD0:byte], uint8, uint16) + 0x6DCA:byte] = bArg10;
	ds:27858[CONVERT(Mem45[ds:0x6CD0:byte], uint8, uint16) * 0x02] = wArg0E;
	ds:0x6D10[CONVERT(Mem52[ds:0x6CD0:byte], uint8, uint16) * 0x02] = wArg0A;
	ds:27982[CONVERT(Mem59[ds:0x6CD0:byte], uint8, uint16) * 0x02] = wArg0C;
	ds:28044[CONVERT(Mem66[ds:0x6CD0:byte], uint8, uint16) * 0x02] = wArg08;
	fn1AB8_112E(ds, wArg08, wArg0A, wArg0C, wArg0E);
	word16 dx_326;
	fn1AB8_1AF6(ds, wArg0C + Mem102[ds:0x50CA:word16], wArg0E - Mem98[ds:0x50CA:word16], wArg0C, wArg0E, out dx_326);
	word16 dx_327;
	fn1AB8_1AF6(ds, wArg08 + Mem125[ds:0x50CA:word16], wArg0E - Mem121[ds:0x50CA:word16], wArg0C + Mem117[ds:0x50CA:word16], wArg0E - Mem107[ds:0x50CA:word16], out dx_327);
	word16 dx_328;
	fn1AB8_1AF6(ds, wArg08 + Mem148[ds:0x50CA:word16], wArg0A - Mem144[ds:0x50CA:word16], wArg08 + Mem140[ds:0x50CA:word16], wArg0E - Mem130[ds:0x50CA:word16], out dx_328);
	word16 dx_329;
	fn1AB8_1AF6(ds, wArg08 + Mem169[ds:0x50CA:word16], wArg0A - Mem165[ds:0x50CA:word16], wArg08, wArg0A, out dx_329);
	word16 dx_330;
	fn1AB8_1AF6(ds, wArg08, wArg0E, wArg08 + Mem184[ds:0x50CA:word16], wArg0E - Mem174[ds:0x50CA:word16], out dx_330);
	word16 dx_331;
	Eq_17 ds_240;
	fn133F_014B(ds, fp - 0x0102, 0x01, 0x00, &wArg0C.u3->t0000.u0 + (int32) (wArg08 - wArg0C) /16 0x02, &wArg0E.u3->t0000.u0 + (int32) (wArg0A - wArg0E) /16 0x02, out dx_331, out ds_240);
	fn133F_02DF(ds_240, fp - 0x0102, Mem234[ds_240:0x6CD0:byte]);
	return ds_240;
}
