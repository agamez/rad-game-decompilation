// 0800:1315: Register byte fn0800_1315(Register Eq_17 ds, Stack Eq_17 wArg02, Stack Eq_17 wArg04, Stack Eq_17 wArg06, Stack Eq_17 wArg08)
// Called from:
//      fn0800_149F
//      fn0800_166D
//      fn0800_184C
//      fn0800_1E3F
//      fn0800_2004
//      fn0800_21E7
//      fn0800_2401
//      fn0800_31B7
//      fn0800_391E
byte fn0800_1315(Eq_17 ds, Eq_17 wArg02, Eq_17 wArg04, Eq_17 wArg06, Eq_17 wArg08)
{
	fn1AB8_1175(ds, 0x03, 0x01);
	fn1AB8_10F4(ds, 0x01, 0x00, 0x00);
	fn1AB8_1B3E(ds, wArg02, wArg04, wArg06, wArg08);
	fn1AB8_1C32(ds, 11);
	word16 dx_419;
	fn1AB8_1AF6(ds, wArg06, (word32) wArg04 + 3, wArg06, wArg08 - 0x03, out dx_419);
	word16 dx_420;
	fn1AB8_1AF6(ds, &wArg06.u3->t0001.u0, &wArg04.u3->t0001.u0, &wArg06.u3->t0001.u0, wArg08 - 0x02, out dx_420);
	word16 dx_421;
	fn1AB8_1AF6(ds, &wArg06.u3->t0002.u0, wArg04, &wArg06.u3->t0002.u0, wArg08 - 0x01, out dx_421);
	word16 dx_422;
	fn1AB8_1AF6(ds, &wArg02.u3->t0002.u0, wArg08 - 0x03, wArg06, wArg08 - 0x03, out dx_422);
	word16 dx_423;
	fn1AB8_1AF6(ds, &wArg02.u3->t0001.u0, wArg08 - 0x02, &wArg06.u3->t0001.u0, wArg08 - 0x02, out dx_423);
	word16 dx_424;
	fn1AB8_1AF6(ds, wArg02, wArg08 - 0x01, &wArg06.u3->t0002.u0, wArg08 - 0x01, out dx_424);
	fn1AB8_1C32(ds, 0x08);
	word16 dx_425;
	fn1AB8_1AF6(ds, &wArg02.u3->t0001.u0, (word32) wArg04 + 3, wArg06, (word32) wArg04 + 3, out dx_425);
	word16 dx_426;
	fn1AB8_1AF6(ds, wArg02, &wArg04.u3->t0002.u0, &wArg06.u3->t0001.u0, &wArg04.u3->t0002.u0, out dx_426);
	word16 dx_427;
	fn1AB8_1AF6(ds, wArg02 - 0x01, &wArg04.u3->t0001.u0, &wArg06.u3->t0002.u0, &wArg04.u3->t0001.u0, out dx_427);
	word16 dx_428;
	fn1AB8_1AF6(ds, &wArg02.u3->t0002.u0, &wArg04.u3->t0002.u0, &wArg02.u3->t0002.u0, wArg08 - 0x02, out dx_428);
	word16 dx_429;
	fn1AB8_1AF6(ds, &wArg02.u3->t0001.u0, &wArg04.u3->t0001.u0, &wArg02.u3->t0001.u0, wArg08 - 0x01, out dx_429);
	word16 dx_430;
	fn1AB8_1AF6(ds, wArg02, wArg04, wArg02, wArg08, out dx_430);
	return 0x00;
}
