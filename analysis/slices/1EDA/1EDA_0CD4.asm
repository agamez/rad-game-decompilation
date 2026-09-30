;; fn1EDA_0CD4: 1EDA:0CD4
;;   Called from:
;;     0800:0A7C (in fn0800_09C2)
;;     0800:0A8F (in fn0800_09C2)
;;     0800:158F (in fn0800_149F)
;;     0800:1772 (in fn0800_166D)
;;     0800:1EE7 (in fn0800_1E3F)
;;     0800:1F62 (in fn0800_1E3F)
;;     0800:209E (in fn0800_2004)
;;     0800:2125 (in fn0800_2004)
;;     0800:3603 (in fn0800_31B7)
;;     0800:362B (in fn0800_31B7)
;;     0800:3B61 (in fn0800_391E)
;;     0800:431B (in fn0800_4255)
;;     0800:438D (in fn0800_4255)
;;     0C74:017D (in fn0C74_011E)
;;     0C74:01D2 (in fn0C74_011E)
;;     0C74:026B (in fn0C74_020C)
;;     0C74:02C8 (in fn0C74_020C)
;;     0C74:0810 (in fn0C74_076B)
fn1EDA_0CD4 proc
	mov	bx,sp
	les	di,ss:[bx+4h]
	mov	al,ss:[bx+8h]
	mov	bl,al
	xor	bh,bh
	mov	cl,3h
	shr	bx,cl
	mov	cl,al
	and	cl,7h
	mov	al,1h
	shl	al,cl
	test	es:[bx+di],al
	retf	6h
1EDA:0CF5                FC 8B DC 8C DA 36 C4 7F 08 36 C5      .....6...6.
1EDA:0D00 77 04 B9 10 00 AD 26 0B 05 AB E2 F9 8E DA CA 04 w.....&.........
1EDA:0D10 00 FC 8B DC 8C DA 36 C4 7F 08 36 C5 77 04 B9 10 ......6...6.w...
1EDA:0D20 00 AD F7 D0 26 23 05 AB E2 F7 8E DA CA 04 00 FC ....&#..........
1EDA:0D30 8B DC 8C DA 36 C4 7F 08 36 C5 77 04 B9 10 00 AD ....6...6.w.....
1EDA:0D40 26 23 05 AB E2 F9 8E DA CA 04 00 FC 8B DC 8C DA &#..............
1EDA:0D50 36 C4 7F 08 36 C5 77 04 B9 10 00 F3 A7 8E DA CA 6...6.w.........
1EDA:0D60 08 00 FC 8B DC 8C DA 36 C4 7F 08 36 C5 77 04 B9 .......6...6.w..
1EDA:0D70 10 00 AD 26 0B 05 AF 75 02 E2 F7 8E DA CA 08 00 ...&...u........
