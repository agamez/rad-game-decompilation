;; fn1EDA_0254: 1EDA:0254
;;   Called from:
;;     0800:04BA (in fn0800_03F8)
;;     0800:11BC (in fn0800_0D20)
;;     0C43:00B0 (in fn0C43_0095)
;;     0C74:05A6 (in fn0C74_03D4)
;;     0C74:06B0 (in fn0C74_05B8)
;;     0C74:0F8A (in fn0C74_0E2E)
;;     0C74:0F98 (in fn0C74_0E2E)
;;     0C74:108A (in fn0C74_0FA1)
;;     0C74:1098 (in fn0C74_0FA1)
;;     0C74:12F5 (in fn0C74_0FA1)
;;     0C74:1303 (in fn0C74_0FA1)
;;     0C74:13A9 (in fn0C74_0FA1)
;;     0C74:1456 (in fn0C74_0FA1)
;;     0C74:146D (in fn0C74_0FA1)
;;     0C74:1507 (in fn0C74_0FA1)
;;     0C74:15BD (in fn0C74_0FA1)
;;     0C74:15CB (in fn0C74_0FA1)
;;     0C74:174B (in fn0C74_0FA1)
;;     0C74:17F8 (in fn0C74_0FA1)
;;     0C74:18D9 (in fn0C74_0FA1)
;;     0C74:195D (in fn0C74_0FA1)
;;     0C74:196B (in fn0C74_0FA1)
;;     0C74:1A30 (in fn0C74_0FA1)
;;     0C74:1AD8 (in fn0C74_0FA1)
;;     0C74:1CA3 (in fn0C74_1B3B)
;;     0C74:1D52 (in fn0C74_1B3B)
;;     0C74:1EF1 (in fn0C74_1D95)
;;     0C74:1EFF (in fn0C74_1D95)
;;     0C74:1FF1 (in fn0C74_1F08)
;;     0C74:1FFF (in fn0C74_1F08)
;;     0C74:225C (in fn0C74_1F08)
;;     0C74:226A (in fn0C74_1F08)
;;     0C74:2310 (in fn0C74_1F08)
;;     0C74:23C6 (in fn0C74_1F08)
;;     0C74:23D4 (in fn0C74_1F08)
;;     0C74:246E (in fn0C74_1F08)
;;     0C74:2524 (in fn0C74_1F08)
;;     0C74:2532 (in fn0C74_1F08)
;;     0C74:275C (in fn0C74_1F08)
;;     0C74:2871 (in fn0C74_1F08)
;;     0C74:2915 (in fn0C74_1F08)
;;     0C74:2923 (in fn0C74_1F08)
;;     0C74:29C8 (in fn0C74_1F08)
;;     0C74:2A70 (in fn0C74_1F08)
;;     0C74:2BB6 (in fn0C74_2AD9)
;;     0C74:2C64 (in fn0C74_2BBD)
;;     0C74:2E2C (in fn0C74_2BBD)
;;     0C74:301A (in fn0C74_2E5A)
;;     0C74:31AE (in fn0C74_2E5A)
;;     0C74:322C (in fn0C74_2E5A)
;;     0C74:33F5 (in fn0C74_3236)
;;     0C74:358D (in fn0C74_3236)
;;     0C74:360B (in fn0C74_3236)
;;     0C74:4F7E (in fn0C74_4DAC)
;;     0C74:5162 (in fn0C74_4FD7)
;;     0C74:541B (in fn0C74_5258)
;;     1229:0372 (in fn1229_0040)
fn1EDA_0254 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+6h]
	les	cx,[bp+8h]
	mov	bx,es
	call	03D3h
	pop	bp
	jc	0268h

l1EDA_0265:
	retf	6h

l1EDA_0268:
	mov	ax,0CCh
	jmp	00E2h
1EDA:026E                                           8B DC               ..
1EDA:0270 36 C4 7F 04 FC A1 5E 53 AB A1 60 53 AB CA 04 00 6.....^S..`S....
1EDA:0280 8B DC 36 C4 7F 04 26 C4 3D 89 3E 5E 53 8C 06 60 ..6...&.=.>^S..`
1EDA:0290 53 89 3E 66 53 8C 06 68 53 CA 04 00 BB B1 02 EB S.>fS..hS.......
1EDA:02A0 37 81 C2 00 10 EB 05 03 44 04 72 F5 03 54 06 C5 7.......D.r..T..
1EDA:02B0 34 8C DB 3B DF 75 F0 C3 BB D1 02 EB 1B 3B 54 06 4..;.u.......;T.
1EDA:02C0 77 0D 72 05 3B 44 04 73 06 8B 44 04 8B 54 06 C5 w.r.;D.s..D..T..
1EDA:02D0 34 8C DB 3B DF 75 E6 C3 A1 62 53 8B 16 64 53 2B 4..;.u...bS..dS+
1EDA:02E0 06 5E 53 1B 16 60 53 25 0F 00 1E 8B 3E 60 53 C5 .^S..`S%....>`S.
1EDA:02F0 36 66 53 FF D3 1F B1 04 D3 C2 8B CA 80 E1 F0 83 6fS.............
1EDA:0300 E2 0F 03 C1 83 D2 00 CB                         ........
