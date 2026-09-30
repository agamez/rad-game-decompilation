// 1EDA:1384: Register Eq_2862 fn1EDA_1384(Stack Eq_2862 bArg04)
// Called from:
//      fn0800_0D20
//      fn0800_391E
//      fn1229_0040
//      fn1229_039D
//      fn133F_0528
Eq_2862 fn1EDA_1384(Eq_2862 bArg04)
{
	Eq_2862 al_12 = bArg04;
	if (bArg04 >= 0x61 && bArg04 <= 122)
		al_12 = bArg04 - 0x20;
	return al_12;
}
