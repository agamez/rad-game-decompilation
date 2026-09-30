// 1AB8:0813: Register word16 fn1AB8_0813(Register Eq_17 ds, Register out (ptr16 Eq_13) dxOut)
// Called from:
//      fn1AB8_0BAE
//      fn1AB8_0EB5
//      fn1AB8_17AE
word16 fn1AB8_0813(Eq_17 ds, struct seg1AB8_t & dxOut)
{
	Mem11[ds:0xB820:word16] = 0x8B;
	Mem12[ds:0xB822:word16] = 0x1AB8;
	Mem15[ds:47154:word16] = 0x8B;
	Mem16[ds:0xB834:word16] = 0x1AB8;
	Mem18[ds:47140:word16] = 0x00;
	Mem19[ds:47142:word16] = 0x00;
	Mem21[ds:0xB836:word16] = 0x00;
	Mem22[ds:0xB838:word16] = 0x00;
	Mem24[ds:47144:word16] = 0x00;
	Mem25[ds:47146:word16] = 0x00;
	Mem27[ds:0xB82E:word16] = 0x00;
	Mem28[ds:0xB830:word16] = 0x00;
	Mem30[ds:~0x481F:word16] = 0x00;
	Mem31[ds:47074:word16] = 0x00;
	Mem33[ds:47076:word16] = 0x00;
	Mem35[ds:~0x4805:word16] = 0x00;
	Mem36[ds:47100:word16] = 0x00;
	Mem38[ds:~0x4801:word16] = 0x00;
	Mem39[ds:~0x4815:byte] = 0x00;
	Mem40[ds:47178:word16] = 0x01;
	Mem41[ds:0xB84C:word16] = 0x01;
	Mem46[ds:46922:word16] = 0x00;
	Mem47[ds:0xB84E:byte] = 0x00;
	selector seg1AB8;
	dxOut = seg1AB8;
	return 0x00;
}
