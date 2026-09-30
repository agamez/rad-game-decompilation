;; fn1EDA_0432: 1EDA:0432
;;   Called from:
;;     1EDA:0426 (in fn1EDA_03D3)
;;     1EDA:042B (in fn1EDA_03D3)
fn1EDA_0432 proc
	mov	ax,di
	mov	dx,es
	mov	di,cx
	mov	es,bx
	add	cx,es:[di+4h]
	add	bx,es:[di+6h]
	add	cl,0F0h
	adc	bx,0h
	and	cl,0Fh
	cmp	bx,dx
	jnz	0489h

l1EDA_044F:
	cmp	cx,ax
	jnz	0489h

l1EDA_0453:
	cmp	dx,[5360h]
	jnz	0468h

l1EDA_0459:
	cmp	ax,[535Eh]
	jnz	0468h

l1EDA_045F:
	mov	[535Eh],di
	mov	[5360h],es
	ret

l1EDA_0468:
	push	ds
	push	di
	mov	si,ax
	mov	ds,dx
	cld
	movsw
	movsw
	lodsw
	xchg	dx,ax
	lodsw
	xchg	dx,ax
	add	ax,es:[di]
	add	dx,es:[di+2h]
	add	al,0F0h
	adc	dx,0h
	and	al,0Fh
	stosw
	xchg	dx,ax
	stosw
	pop	di
	pop	ds
	ret

l1EDA_0489:
	mov	es:[di],ax
	mov	es:[di+2h],dx
	ret
