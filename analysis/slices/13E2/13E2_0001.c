// 13E2:0001: Register byte fn13E2_0001(Register Eq_17 ds, Register out Eq_17 dsOut)
// Called from:
//      fn0800_4255
byte fn13E2_0001(Eq_17 ds, union Eq_17 & dsOut)
{
	<unknown> Eq_57413::* fp;
	struct Eq_57410 * cs;
	Eq_17 ds_36 = fn1AB8_0BAE(ds, &cs->t0000, fp - 8, fp - 6);
	byte bLoc03_75;
	if (fn1AB8_04F3(ds_36) != 0x00)
		bLoc03_75 = 0x00;
	else
		bLoc03_75 = 0x01;
	dsOut = ds_36;
	return bLoc03_75;
}
