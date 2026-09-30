;; fn1EDA_0896: 1EDA:0896
;;   Called from:
;;     0800:0D6A (in fn0800_0D20)
;;     0800:3A6C (in fn0800_391E)
fn1EDA_0896 proc
	push	bp
	mov	bp,sp
	push	ds
	les	di,[bp+0Ch]
	push	es
	push	di
	call	0776h
	lds	si,[bp+8h]
	mov	cx,0h
	jnz	08BFh

l1EDA_08AA:
	call	079Ah
	cmp	al,0Dh
	jz	08BFh

l1EDA_08B1:
	cmp	al,1Ah
	jz	08BFh

l1EDA_08B5:
	inc	bx
	inc	cx
	inc	si
	mov	[si],al
	cmp	cx,[bp+6h]
	jnz	08AAh

l1EDA_08BF:
	sub	si,cx
	mov	[si],cl
	pop	di
	pop	es
	mov	es:[di+8h],bx
	pop	ds
	pop	bp
	retf	6h
