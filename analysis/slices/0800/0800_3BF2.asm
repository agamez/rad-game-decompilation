;; fn0800_3BF2: 0800:3BF2
;;   Called from:
;;     0800:3D14 (in fn0800_3CFA)
fn0800_3BF2 proc
	push	bp
	mov	bp,sp
	les	di,[bp+6h]
	push	es
	push	di
	les	di,[bp+6h]
	add	di,2h
	push	es
	push	di
	les	di,[bp+6h]
	add	di,4h
	push	es
	push	di
	les	di,[bp+6h]
	add	di,6h
	push	es
	push	di
	call	far 1E5Fh:00A2h
	les	di,[bp+6h]
	mov	ax,es:[di]
	xor	dx,dx
	mov	cx,7E40h
	mov	bx,5h
	call	far 1EDAh:096Fh
	mov	cx,ax
	mov	bx,dx
	les	di,[bp+6h]
	imul	ax,es:[di+2h],1770h
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	mov	cx,ax
	mov	bx,dx
	les	di,[bp+6h]
	imul	ax,es:[di+4h],64h
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	mov	cx,ax
	mov	bx,dx
	les	di,[bp+6h]
	mov	ax,es:[di+6h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	les	di,[bp+6h]
	mov	es:[di+8h],ax
	mov	es:[di+0Ah],dx
	leave
	retf	4h
