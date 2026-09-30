;; fn1AB8_1C93: 1AB8:1C93
;;   Called from:
;;     1AB8:0E61 (in fn1AB8_0BAE)
fn1AB8_1C93 proc
	push	bp
	mov	bp,sp
	mov	al,1h
	mov	si,0h
	call	dword ptr [0B820h]
	mov	ax,cx
	dec	ax
	pop	bp
	retf
