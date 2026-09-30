;; fn1AB8_1C5A: 1AB8:1C5A
;;   Called from:
;;     1AB8:0B26 (in fn1AB8_0AEE)
fn1AB8_1C5A proc
	push	bp
	mov	bp,sp
	xor	al,al
	mov	si,3Ah
	call	dword ptr [0B820h]
	mov	ax,bx
	pop	bp
	retf
