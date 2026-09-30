// 133F:04DE: Register Eq_17 fn133F_04DE(Register Eq_17 ds, Stack Eq_17 ptrArg04)
// Called from:
//      fn1229_0CCE
Eq_17 fn133F_04DE(Eq_17 ds, Eq_17 ptrArg04)
{
	struct Eq_56215 * ds_61;
	Eq_17 ss;
	<unknown> Eq_17::* fp;
	word16 dx_129;
	fn1EDA_0A39(~0x00, SEQ(ss, fp - 0x0102), ptrArg04, out dx_129);
	struct Eq_54314 Eq_17::* bp_57 = fn133F_04B1(ds, fn1AB8_10E1(ds), fn1AB8_10CE(ds), 0x00, 0x00, out ds_61);
	ds_61->tB6B6.u2 = (ss->*bp_57).t0010.u2;
	ds_61->tB6B8.u2 = (ss->*bp_57).t000E.u2;
	Eq_481 sp_65;
	sp_65.u0 = <invalid>;
	(ss->*((word16) sp_65 + 6)).u1 = (ss->*bp_57).t0010.u2;
	(ss->*((word16) sp_65 + 4)).u1 = (ss->*bp_57).t000E.u2;
	word16 bp_130;
	selector ds_131;
	fn13C8_009A(out bp_130, out ds_131);
	word16 dx_132;
	word16 bp_99;
	Eq_17 ds_103;
	fn133F_0141(out dx_132, out bp_99, out ds_103);
	return ds_103;
}
