;; fn1AB8_0569: 1AB8:0569
;;   Called from:
;;     1AB8:0692 (in fn1AB8_05D3)
;;     1AB8:07DB (in fn1AB8_06CA)
;;     1AB8:0BEE (in fn1AB8_0BAE)
fn1AB8_0569 proc
	push	bp
	mov	bp,sp
	sub	sp,8h
	les	di,[bp+8h]
	mov	ax,es:[di]
	add	[bp+0Ch],ax
	mov	ax,[bp+0Ch]
	mov	cx,4h
	shr	ax,cl
	add	ax,[bp+0Eh]
	mov	dx,ax
	xor	ax,ax
	mov	[bp-8h],ax
	mov	[bp-6h],dx
	mov	ax,[bp+0Ch]
	and	ax,0Fh
	or	ax,ax
	jz	05B8h

l1AB8_0597:
	les	di,[bp+0Ch]
	push	es
	push	di
	les	di,[bp-8h]
	push	es
	push	di
	les	di,[bp+4h]
	push	word ptr es:[di]
	call	far 1EDAh:11DFh
	mov	ax,[bp+0Ch]
	and	ax,0Fh
	les	di,[bp+8h]
	sub	es:[di],ax

l1AB8_05B8:
	mov	ax,[bp-8h]
	mov	dx,[bp-6h]
	mov	[bp-4h],ax
	mov	[bp-2h],dx
	mov	ax,[bp-4h]
	mov	dx,[bp-2h]
	mov	sp,bp
	pop	bp
	ret	0Ch
1AB8:05D0 02 70 6B                                        .pk
