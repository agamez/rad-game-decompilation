;; fn1AB8_1B3E: 1AB8:1B3E
;;   Called from:
;;     0800:0072 (in fn0800_005A)
;;     0800:1338 (in fn0800_1315)
;;     0800:1B3A (in fn0800_19E1)
;;     0800:3709 (in fn0800_36E6)
;;     0800:39CB (in fn0800_391E)
;;     0800:3A30 (in fn0800_391E)
;;     0800:3F84 (in fn0800_3D9D)
;;     0C74:00C9 (in fn0C74_00B2)
;;     0C74:00F3 (in fn0C74_00DB)
;;     1AB8:105B (in fn1AB8_1028)
fn1AB8_1B3E proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+0Ch]
	mov	bx,[bp+0Ah]
	mov	cx,[bp+8h]
	mov	dx,[bp+6h]
	mov	si,12h
	call	dword ptr [0B820h]
	pop	bp
	retf	8h
1AB8:1B58                         55 8B EC 8B 46 10 8B 5E         U...F..^
1AB8:1B60 0E 8B 4E 0C 8B 56 0A 3B C1 72 01 91 3B DA 73 02 ..N..V.;.r..;.s.
1AB8:1B70 87 DA 51 52 BE 08 00 FF 1E 20 B8 5B 58 8B 4E 08 ..QR..... .[X.N.
1AB8:1B80 8A 56 06 32 F6 BE 10 00 FF 1E 20 B8 5D CA 0C 00 .V.2...... .]...
