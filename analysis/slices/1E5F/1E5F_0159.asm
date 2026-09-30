;; fn1E5F_0159: 1E5F:0159
;;   Called from:
;;     0800:00E6 (in fn0800_00C1)
fn1E5F_0159 proc
	push	bp
	mov	bp,sp
	mov	al,[bp+0Ah]
	mov	ah,35h
	int	21h
	mov	ax,es
	les	di,[bp+6h]
	cld
	xchg	bx,ax
	stosw
	xchg	bx,ax
	stosw
	pop	bp
	retf	6h
