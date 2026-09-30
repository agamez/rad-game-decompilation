;; fn1EDA_0308: 1EDA:0308
;;   Called from:
;;     1EDA:0245 (in fn1EDA_023F)
fn1EDA_0308 proc
	or	ax,ax
	jz	0382h

l1EDA_030C:
	mov	[0BB08h],ax

l1EDA_030F:
	call	0491h
	mov	di,5366h
	mov	cx,ds
	mov	es,cx

l1EDA_0319:
	mov	cx,di
	mov	bx,es
	les	di,es:[di]
	mov	si,es
	cmp	si,[5360h]
	jz	0383h

l1EDA_0328:
	cmp	dx,es:[di+6h]
	ja	0319h

l1EDA_032E:
	jc	0336h

l1EDA_0330:
	cmp	ax,es:[di+4h]
	ja	0319h

l1EDA_0336:
	push	es
	push	di
	push	bx
	push	cx
	mov	cx,es:[di]
	mov	bx,es:[di+2h]
	jz	0376h

l1EDA_0343:
	push	bx
	push	cx
	mov	cx,es:[di+4h]
	mov	bx,es:[di+6h]
	sub	cx,ax
	sbb	bx,dx
	and	cx,0Fh
	add	ax,di
	add	dx,si
	add	al,0F0h
	adc	dx,0h
	and	al,0Fh
	mov	di,ax
	mov	es,dx
	pop	word ptr es:[di]
	pop	word ptr es:[di+2h]
	mov	es:[di+4h],cx
	mov	es:[di+6h],bx
	mov	cx,di
	mov	bx,es

l1EDA_0376:
	pop	di
	pop	es
	mov	es:[di],cx
	mov	es:[di+2h],bx
	pop	ax
	pop	dx
	clc

l1EDA_0382:
	ret

l1EDA_0383:
	add	ax,di
	add	dx,si
	add	al,0F0h
	adc	dx,0h
	and	al,0Fh
	cmp	dx,[5364h]
	jc	039Ch

l1EDA_0394:
	ja	03BBh

l1EDA_0396:
	cmp	ax,[5362h]
	ja	03BBh

l1EDA_039C:
	push	es
	push	di
	mov	di,cx
	mov	es,bx
	mov	[535Eh],ax
	mov	[5360h],dx
	mov	es:[di],ax
	mov	es:[di+2h],dx
	xor	ax,ax
	push	ax
	call	dword ptr [536Eh]
	pop	ax
	pop	dx
	clc
	ret

l1EDA_03BB:
	push	word ptr [0BB08h]
	call	dword ptr [536Eh]
	cmp	al,1h
	jc	0382h

l1EDA_03C7:
	jz	03CFh

l1EDA_03C9:
	mov	ax,[0BB08h]
	jmp	030Fh

l1EDA_03CF:
	xor	ax,ax
	cwd
	ret
