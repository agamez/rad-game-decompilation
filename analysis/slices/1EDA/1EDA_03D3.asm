;; fn1EDA_03D3: 1EDA:03D3
;;   Called from:
;;     1EDA:025F (in fn1EDA_0254)
fn1EDA_03D3 proc
	or	ax,ax
	jz	0431h

l1EDA_03D7:
	test	cx,0FFF7h
	jnz	0430h

l1EDA_03DD:
	cmp	bx,[535Ch]
	ja	03EBh

l1EDA_03E3:
	jc	0430h

l1EDA_03E5:
	cmp	cx,[535Ah]
	jc	0430h

l1EDA_03EB:
	cmp	bx,[5360h]
	jc	03F9h

l1EDA_03F1:
	ja	0430h

l1EDA_03F3:
	cmp	cx,[535Eh]
	jnc	0430h

l1EDA_03F9:
	call	0491h
	mov	di,cx
	mov	es,bx
	mov	es:[di+4h],ax
	mov	es:[di+6h],dx
	mov	di,5366h
	mov	ax,ds
	mov	es,ax

l1EDA_040F:
	mov	ax,di
	mov	dx,es
	les	di,es:[di]
	mov	si,es
	cmp	bx,si
	ja	040Fh

l1EDA_041C:
	jc	0424h

l1EDA_041E:
	cmp	cx,di
	ja	040Fh

l1EDA_0422:
	jz	0430h

l1EDA_0424:
	push	dx
	push	ax
	call	0432h
	pop	cx
	pop	bx
	call	0432h
	clc
	ret

l1EDA_0430:
	stc

l1EDA_0431:
	ret
