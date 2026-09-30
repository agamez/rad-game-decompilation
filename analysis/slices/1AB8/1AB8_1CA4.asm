;; fn1AB8_1CA4: 1AB8:1CA4
;;   Called from:
;;     1AB8:127D (in fn1AB8_1250)
fn1AB8_1CA4 proc
	push	bp
	mov	bp,sp
	mov	bl,[bp+6h]
	xor	bh,bh
	mov	ax,0FFFFh
	mov	si,1Ah
	call	dword ptr [0B820h]
	pop	bp
	retf	2h
