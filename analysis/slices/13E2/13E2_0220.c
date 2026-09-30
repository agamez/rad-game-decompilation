// 13E2:0220: Register Eq_17 fn13E2_0220(Register Eq_17 ds)
// Called from:
//      fn0800_4255
Eq_17 fn13E2_0220(Eq_17 ds)
{
	selector seg13E2;
	struct Eq_57705 * cs;
	if (fn1AB8_05D3(ds, &seg13E2->t0278) < 0x00)
		ds = fn13E2_0193(ds, &cs->t0208);
	if (fn1AB8_06CA(ds, &seg13E2->t182A) < 0x00)
		ds = fn13E2_0193(ds, &cs->t0208);
	if (fn1AB8_06CA(ds, &seg13E2->t594F) < 0x00)
		ds = fn13E2_0193(ds, &cs->t0208);
	Mem151[ds:0xB6C1:byte] = 0x01;
	return ds;
}

<unknown> g_t0278 = // 13E2:0278;
<unknown> g_t182A = // 13E2:182A;
<unknown> g_t594F = // 13E2:594F;
