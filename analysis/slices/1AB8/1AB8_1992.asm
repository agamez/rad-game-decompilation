;; fn1AB8_1992: 1AB8:1992
;;   Called from:
;;     1AB8:1529 (in fn1AB8_14F4)
fn1AB8_1992 proc
	push	bp
	mov	bp,sp
	mov	ah,[bp+8h]
	mov	al,[bp+6h]
	mov	si,2Ah
	call	dword ptr [0B820h]
	pop	bp
	retf	4h
