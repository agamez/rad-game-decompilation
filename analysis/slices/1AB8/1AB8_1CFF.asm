;; fn1AB8_1CFF: 1AB8:1CFF
;;   Called from:
;;     1AB8:1126 (in fn1AB8_10F4)
fn1AB8_1CFF proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+0Ah]
	mov	[0B841h],al
	mov	bx,[bp+8h]
	mov	cl,[bp+6h]
	mov	[0B89Eh],cl
	xor	ch,ch
	mov	si,22h
	call	dword ptr [0B820h]
	pop	bp
	retf	6h
1AB8:1D1F                                              55                U
1AB8:1D20 8B EC 8B 46 0A 8B 5E 08 8B 4E 06 C4 36 9F B8 26 ...F..^..N..6..&
1AB8:1D30 8B 7C 0C 26 8B 54 0E 26 03 7C 10 83 EF 02 FA 87 .|.&.T.&.|......
1AB8:1D40 E7 8C D5 8E D2 FB 57 55 BE 2C 00 FF 1E 20 B8 5B ......WU.,... .[
1AB8:1D50 58 FA 8E D3 8B E0 FB 5D CA 06 00                X......]...
