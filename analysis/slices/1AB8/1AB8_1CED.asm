;; fn1AB8_1CED: 1AB8:1CED
;;   Called from:
;;     1AB8:1338 (in fn1AB8_129A)
fn1AB8_1CED proc
	push	bp
	mov	bp,sp
	les	bx,[bp+6h]
	inc	bx
	mov	si,1Ch
	call	dword ptr [0B820h]
	pop	bp
	retf	4h
