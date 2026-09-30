;; fn0800_3C72: 0800:3C72
;;   Called from:
;;     0800:3D2B (in fn0800_3CFA)
fn0800_3C72 proc
	enter	0Ch,0h
	lea	di,[bp-6h]
	push	ss
	push	di
	lea	di,[bp-8h]
	push	ss
	push	di
	lea	di,[bp-0Ah]
	push	ss
	push	di
	lea	di,[bp-0Ch]
	push	ss
	push	di
	call	far 1E5Fh:00A2h
	mov	ax,[bp-6h]
	xor	dx,dx
	mov	cx,7E40h
	mov	bx,5h
	call	far 1EDAh:096Fh
	mov	cx,ax
	mov	bx,dx
	imul	ax,[bp-8h],1770h
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	mov	cx,ax
	mov	bx,dx
	imul	ax,[bp-0Ah],64h
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp-0Ch]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	les	di,[bp+6h]
	mov	es:[di+0Ch],ax
	mov	es:[di+0Eh],dx
	les	di,[bp+6h]
	mov	ax,es:[di+0Ch]
	mov	dx,es:[di+0Eh]
	les	di,[bp+6h]
	sub	ax,es:[di+8h]
	sbb	dx,es:[di+0Ah]
	mov	[bp-4h],ax
	mov	[bp-2h],dx
	mov	ax,[bp-4h]
	mov	dx,[bp-2h]
	leave
	retf	4h
