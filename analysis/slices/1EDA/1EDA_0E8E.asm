;; fn1EDA_0E8E: 1EDA:0E8E
;;   Called from:
;;     1EDA:0F88 (in fn1EDA_0F71)
fn1EDA_0E8E proc
	xor	ax,ax
	xor	dx,dx
	xor	si,si
	jcxz	0EEFh

l1EDA_0E96:
	cmp	byte ptr es:[di],2Bh
	jz	0EA3h

l1EDA_0E9C:
	cmp	byte ptr es:[di],2Dh
	jnz	0EA7h

l1EDA_0EA2:
	inc	si

l1EDA_0EA3:
	inc	di
	dec	cx
	jcxz	0EEFh

l1EDA_0EA7:
	cmp	byte ptr es:[di],24h
	jz	0EF1h

l1EDA_0EAD:
	mov	bl,es:[di]
	sub	bl,3Ah
	add	bl,0Ah
	jnc	0EE0h

l1EDA_0EB8:
	test	dx,0F000h
	jnz	0EEFh

l1EDA_0EBE:
	push	bx
	shl	ax,1h
	rcl	dx,1h
	push	dx
	push	ax
	shl	ax,1h
	rcl	dx,1h
	shl	ax,1h
	rcl	dx,1h
	pop	bx
	add	ax,bx
	pop	bx
	adc	dx,bx
	pop	bx
	xor	bh,bh
	add	ax,bx
	adc	dx,0h
	js	0EEFh

l1EDA_0EDD:
	inc	di
	loop	0EADh

l1EDA_0EE0:
	dec	si
	jnz	0EEDh

l1EDA_0EE3:
	not	ax
	not	dx
	add	ax,1h
	adc	dx,0h

l1EDA_0EED:
	clc
	ret

l1EDA_0EEF:
	stc
	ret

l1EDA_0EF1:
	inc	di
	dec	cx
	jcxz	0EEFh

l1EDA_0EF5:
	mov	bl,es:[di]
	cmp	bl,61h
	jc	0F00h

l1EDA_0EFD:
	sub	bl,20h

l1EDA_0F00:
	sub	bl,3Ah
	add	bl,0Ah
	jc	0F13h

l1EDA_0F08:
	sub	bl,17h
	add	bl,6h
	jnc	0EE0h

l1EDA_0F10:
	add	bl,0Ah

l1EDA_0F13:
	mov	bh,4h

l1EDA_0F15:
	shl	ax,1h
	rcl	dx,1h
	jc	0EEFh

l1EDA_0F1B:
	dec	bh
	jnz	0F15h

l1EDA_0F1F:
	or	al,bl
	inc	di
	loop	0EF5h

l1EDA_0F24:
	jmp	0EE0h
