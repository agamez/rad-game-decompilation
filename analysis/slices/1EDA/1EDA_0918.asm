;; fn1EDA_0918: 1EDA:0918
;;   Called from:
;;     0800:3AA1 (in fn0800_391E)
;;     0800:3B3E (in fn0800_391E)
;;     0800:3B8A (in fn0800_391E)
fn1EDA_0918 proc
	mov	cl,0h
	push	bp
	mov	bp,sp
	les	di,[bp+6h]
	push	es
	push	di
	call	0776h
	jnz	0943h

l1EDA_0927:
	call	079Ah
	cmp	al,1Ah
	jz	0947h

l1EDA_092E:
	test	cl,1h
	jz	0937h

l1EDA_0933:
	cmp	al,0Dh
	jz	0947h

l1EDA_0937:
	test	cl,2h
	jz	0943h

l1EDA_093C:
	cmp	al,20h
	ja	0943h

l1EDA_0940:
	inc	bx
	jmp	0927h

l1EDA_0943:
	mov	al,0h
	jmp	0949h

l1EDA_0947:
	mov	al,1h

l1EDA_0949:
	pop	di
	pop	es
	mov	es:[di+8h],bx
	pop	bp
	retf	4h
