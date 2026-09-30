// 1EDA:0B7C: void fn1EDA_0B7C(Stack Eq_50514 wArg04, Stack word16 wArg06, Stack Eq_17 ptrArg08, Stack Eq_17 ptrArg0C)
// Called from:
//      fn11C8_0000
void fn1EDA_0B7C(Eq_50514 wArg04, word16 wArg06, Eq_17 ptrArg08, Eq_17 ptrArg0C)
{
	Eq_17 ptrLoc0206_142;
	<unknown> Eq_64602::* fp;
	ptrLoc0206_142.u3 = fp - 0x0102;
	fn1EDA_0A6B(wArg04 - 0x01, 0x01, ptrArg08, ptrLoc0206_142);
	fn1EDA_0AAC(ptrArg0C, ptrLoc0206_142);
	Eq_17 ptrLoc020A_154;
	ptrLoc020A_154.u3 = fp - 0x0202;
	fn1EDA_0A6B(0xFF, wArg04, ptrArg08, ptrLoc020A_154);
	fn1EDA_0AAC(ptrLoc020A_154, ptrLoc0206_142);
	word16 dx_163;
	fn1EDA_0A39((byte) wArg06, ptrArg08, ptrLoc0206_142, out dx_163);
}
