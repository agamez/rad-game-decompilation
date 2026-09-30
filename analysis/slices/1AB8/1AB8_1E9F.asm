;; fn1AB8_1E9F: 1AB8:1E9F
;;   Called from:
;;     1AB8:147E (in fn1AB8_13D7)
fn1AB8_1E9F proc
	push	bp
	mov	bp,sp
	les	bx,[bp+8h]
	mov	cx,[bp+0Eh]
	mov	dx,[bp+0Ch]
	mov	al,[bp+6h]
	mov	si,36h
	call	dword ptr [0B820h]
	pop	bp
	retf	0Ah
1AB8:1EB9                            00 00 00 01 01 01 02          .......
1AB8:1EC0 03 04 01 05 06 07 FF 00 04 05 01 00 00 00 00 05 ................
1AB8:1ED0 02 00 00 00 00 00 04 05 01 01 00 01 00 05 02 00 ................
1AB8:1EE0 00 00 7F                                        ...
