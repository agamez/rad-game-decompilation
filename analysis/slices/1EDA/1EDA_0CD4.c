// 1EDA:0CD4: FlagGroup bool fn1EDA_0CD4(Stack Eq_17 ptrArg04, Stack Eq_17 bArg08, Register out (ptr16 Eq_1850) esOut)
// Called from:
//      fn0800_09C2
//      fn0800_149F
//      fn0800_166D
//      fn0800_1E3F
//      fn0800_2004
//      fn0800_31B7
//      fn0800_391E
//      fn0800_4255
//      fn0C74_011E
//      fn0C74_020C
//      fn0C74_076B
bool fn1EDA_0CD4(Eq_17 ptrArg04, Eq_17 bArg08, struct Eq_1850 & esOut)
{
	struct Eq_1850 * es_18 = SLICE(ptrArg04, selector, 16);
	ui32 SZP_20 = cond(es_18->*(((uint16) bArg08 >> 0x03) + (word16) ptrArg04) & 0x01 << (bArg08 & 0x07));
	esOut = es_18;
	return (SZP_20 & 0x04) != 0x00;
}
