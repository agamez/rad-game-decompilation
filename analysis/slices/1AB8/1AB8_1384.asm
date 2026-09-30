;; fn1AB8_1384: 1AB8:1384
;;   Called from:
;;     1AB8:0B19 (in fn1AB8_0AEE)
fn1AB8_1384 proc
	push	bp
	mov	bp,sp
	push	cs
	call	1C6Ah
	mov	di,ax
	mov	es,dx
	push	es
	push	di
	les	di,[bp+6h]
	push	es
	push	di
	mov	ax,11h
	push	ax
	call	far 1EDAh:0953h
	pop	bp
	retf	4h
