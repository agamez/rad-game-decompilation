;; fn1AB8_1AC2: 1AB8:1AC2
;;   Called from:
;;     1AB8:0F83 (in fn1AB8_0F80)
fn1AB8_1AC2 proc
	push	bp
	mov	bp,sp
	mov	si,4h
	call	dword ptr [0B820h]
	pop	bp
	retf
