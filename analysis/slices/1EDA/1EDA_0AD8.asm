;; fn1EDA_0AD8: 1EDA:0AD8
;;   Called from:
;;     0800:42A2 (in fn0800_4255)
;;     0800:42BD (in fn0800_4255)
fn1EDA_0AD8 proc
	cld
	mov	bx,sp
	push	ds
	lds	si,ss:[bx+8h]
	les	di,ss:[bx+4h]
	mov	cl,es:[di]
	xor	ch,ch
	jcxz	0B14h

l1EDA_0AEB:
	inc	di
	lodsb
	cmp	al,1h
	jc	0B1Ah

l1EDA_0AF1:
	ja	0AFBh

l1EDA_0AF3:
	lodsb

l1EDA_0AF4:
	repne scasb

l1EDA_0AF6:
	jnz	0B14h

l1EDA_0AF8:
	dec	di
	jmp	0B1Ah

l1EDA_0AFB:
	xor	ah,ah
	mov	dx,cx
	sub	dx,ax
	jc	0B14h

l1EDA_0B03:
	inc	dx

l1EDA_0B04:
	mov	cx,ax
	rep cmpsb
	jz	0B18h

l1EDA_0B0A:
	sub	cx,ax
	add	si,cx
	add	di,cx
	inc	di
	dec	dx
	jnz	0B04h

l1EDA_0B14:
	xor	ax,ax
	jmp	0B20h

l1EDA_0B18:
	sub	di,ax

l1EDA_0B1A:
	mov	ax,di
	sub	ax,ss:[bx+4h]

l1EDA_0B20:
	pop	ds
	retf	8h
