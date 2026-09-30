;; fn1AB8_1C6A: 1AB8:1C6A
;;   Called from:
;;     1AB8:1387 (in fn1AB8_1384)
fn1AB8_1C6A proc
	push	bp
	mov	bp,sp
	mov	al,1h
	mov	si,3Ah
	call	dword ptr [0B820h]
	mov	dx,es
	mov	ax,bx
	pop	bp
	retf
1AB8:1C7C                                     55 8B EC B0             U...
1AB8:1C80 02 8B 4E 06 BE 00 00 FF 1E 20 B8 8C C2 8B C3 5D ..N...... .....]
1AB8:1C90 CA 02 00                                        ...
