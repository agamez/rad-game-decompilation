;; fn1EDA_00FC: 1EDA:00FC
;;   Called from:
;;     1EDA:00FA (in fn1EDA_00ED)
;;     1EDA:00FA (in fn1EDA_00ED)
fn1EDA_00FC proc
	mov	ax,[5354h]

l1EDA_00FF:
	or	ax,ax
	jz	0114h

l1EDA_0103:
	mov	es,ax
	cmp	bx,es:[0010h]
	jz	0112h

l1EDA_010C:
	mov	ax,es:[0014h]
	jmp	00FFh

l1EDA_0112:
	mov	bx,es

l1EDA_0114:
	sub	bx,[537Ch]
	sub	bx,10h
