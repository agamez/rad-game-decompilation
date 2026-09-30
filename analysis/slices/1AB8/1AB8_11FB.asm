;; fn1AB8_11FB: 1AB8:11FB
;;   Called from:
;;     1AB8:1244 (in fn1AB8_122E)
fn1AB8_11FB proc
	push	bp
	mov	bp,sp
	sub	sp,2h
	mov	ax,[0B84Ch]
	xor	dx,dx
	push	dx
	push	ax
	mov	ax,[0B84Ah]
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+4h]
	xor	dx,dx
	call	far 1EDAh:096Fh
	pop	cx
	pop	bx
	call	far 1EDAh:098Ah
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	ret	2h
