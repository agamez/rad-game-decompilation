// 1AB8:17AE: void fn1AB8_17AE(Register Eq_17 ds)
// Called from:
//      fn0800_4255
void fn1AB8_17AE(Eq_17 ds)
{
	Mem14[ds:0xB818:word16] = 0x00;
	Mem15[ds:~0x4849:word16] = 0x1000;
	fn1AB8_1A84(ds);
	word16 dx_45;
	fn1AB8_0813(ds, out dx_45);
	Mem29[ds:46786:word16] = 1311;
	Mem30[ds:46788:word16] = 0x1AB8;
	Mem33[ds:~0x4939:word16] = 1336;
	Mem34[ds:0xB6C8:word16] = 0x1AB8;
	Mem35[ds:46924:byte] = 0x00;
	Mem36[ds:46934:byte] = 0x00;
	Mem37[ds:~0x4847:word16] = 0x06;
	Mem38[ds:~0x4845:word16] = 0x0A;
	Mem39[ds:0xB850:word16] = 0x01;
	Mem40[ds:47178:word16] = 0x01;
	Mem41[ds:0xB84C:word16] = 0x01;
}
