// 1E78:0000: void fn1E78_0000(Register Eq_17 ds)
// Called from:
//      fn0800_4255
void fn1E78_0000(Eq_17 ds)
{
	fn1E78_002E(ds);
	fn1E78_032F(SEQ(ds, ~0x4743));
	fn1EDA_0565(ds, SEQ(ds, ~0x4743));
	fn1E78_032F(SEQ(ds, ~0x4643));
	fn1EDA_056A(ds, SEQ(ds, ~0x4643));
}
