;; fn1AB8_1AA6: 1AB8:1AA6
;;   Called from:
;;     1AB8:0E49 (in fn1AB8_0BAE)
fn1AB8_1AA6 proc
	push	bp
	mov	bp,sp
	call	180Ah
	les	bx,[bp+6h]
	mov	[0B89Fh],bx
	mov	[0B8A1h],es
	mov	si,2h
	call	dword ptr [0B820h]
	pop	bp
	retf	4h
