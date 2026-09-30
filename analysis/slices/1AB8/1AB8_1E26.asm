;; fn1AB8_1E26: 1AB8:1E26
;;   Called from:
;;     1AB8:179E (in fn1AB8_1783)
fn1AB8_1E26 proc
	push	bp
	mov	bp,sp
	mov	cx,1h
	push	cs
	pop	es
	mov	bx,1E24h
	mov	si,28h
	call	dword ptr [0B820h]
	mov	ax,cx
	pop	bp
	retf
