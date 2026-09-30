;; fn1AB8_1CD7: 1AB8:1CD7
;;   Called from:
;;     1AB8:137C (in fn1AB8_1342)
fn1AB8_1CD7 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+8h]
	xor	ah,ah
	mov	bx,[bp+6h]
	mov	si,1Ah
	call	dword ptr [0B820h]
	pop	bp
	retf	4h
