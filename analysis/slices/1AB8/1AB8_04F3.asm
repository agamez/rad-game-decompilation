;; fn1AB8_04F3: 1AB8:04F3
;;   Called from:
;;     133F:0073 (in fn133F_0056)
;;     13E2:001E (in fn13E2_0001)
fn1AB8_04F3 proc
	push	bp
	mov	bp,sp
	sub	sp,2h
	mov	ax,[0B818h]
	mov	[bp-2h],ax
	xor	ax,ax
	mov	[0B818h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf
1AB8:050B                                  55 89 E5 83 EC            U....
1AB8:0510 02 C7 46 FE 01 00 8B 46 FE 89 EC 5D CA 02 00 55 ..F....F...]...U
1AB8:0520 89 E5 FF 76 06 9A 3F 02 DA 1E C4 7E 08 26 89 05 ...v..?....~.&..
1AB8:0530 26 89 55 02 5D CA 06 00 55 89 E5 C4 7E 08 26 8B &.U.]...U...~.&.
1AB8:0540 05 26 0B 45 02 74 12 C4 7E 08 26 FF 75 02 26 FF .&.E.t..~.&.u.&.
1AB8:0550 35 FF 76 06 9A 54 02 DA 1E C4 7E 08 31 C0 26 89 5.v..T....~.1.&.
1AB8:0560 05 26 89 45 02 5D CA 06 00                      .&.E.]...
