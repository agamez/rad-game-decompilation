;; fn1AB8_1285: 1AB8:1285
;;   Called from:
;;     0C74:016C (in fn0C74_011E)
;;     0C74:025A (in fn0C74_020C)
fn1AB8_1285 proc
	push	bp
	mov	bp,sp
	sub	sp,2h
	mov	al,[0B83Eh]
	xor	ah,ah
	mov	[bp-2h],ax
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf
