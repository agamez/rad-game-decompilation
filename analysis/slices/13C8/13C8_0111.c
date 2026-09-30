// 13C8:0111: Register (ptr16 Eq_57287) fn13C8_0111(Stack cup16 wArg04)
// Called from:
//      fn1229_0DCC
struct Eq_57287 * fn13C8_0111(cup16 wArg04)
{
	word16 wLoc1A;
	selector psegLoc18;
	fn1EDA_04B7(wArg04, 0x00, 0x0109, wLoc1A, psegLoc18);
	<unknown> Eq_57301::* fp;
	byte ch_65;
	word16 dx_66;
	word16 bp_67;
	word16 si_68;
	selector es_69;
	struct Eq_57287 * ds_41;
	fn1E5F_000B(fp - 22, out ch_65, out dx_66, out bp_67, out si_68, out es_69, out ds_41);
	return ds_41;
}
