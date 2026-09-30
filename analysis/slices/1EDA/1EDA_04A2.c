// 1EDA:04A2: Register Eq_17 fn1EDA_04A2(Register Eq_17 ds)
// Called from:
//      fn0800_0D20
//      fn0800_2C0C
//      fn0800_391E
//      fn0C43_00B9
//      fn1229_0486
//      fn1AB8_0887
//      fn1AB8_097B
//      fn1AB8_1536
Eq_17 fn1EDA_04A2(Eq_17 ds)
{
	Eq_17 v8_10 = Mem0[ds:0x5380:word16];
	Mem11[ds:0x5380:word16] = 0x00;
	return v8_10;
}
