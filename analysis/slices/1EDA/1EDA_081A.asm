;; fn1EDA_081A: 1EDA:081A
;;   Called from:
;;     0800:3A71 (in fn0800_391E)
fn1EDA_081A proc
	push	bp
	mov	bp,sp
	les	di,[bp+6h]
	push	es
	push	di
	call	0776h
	jnz	083Bh

l1EDA_0827:
	call	079Ah
	cmp	al,1Ah
	jz	083Bh

l1EDA_082E:
	inc	bx
	cmp	al,0Dh
	jnz	0827h

l1EDA_0833:
	call	079Ah
	cmp	al,0Ah
	jnz	083Bh

l1EDA_083A:
	inc	bx

l1EDA_083B:
	pop	di
	pop	es
	mov	es:[di+8h],bx
	call	0879h
	pop	bp
	retf	4h
