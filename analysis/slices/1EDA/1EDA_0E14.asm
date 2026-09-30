;; fn1EDA_0E14: 1EDA:0E14
;;   Called from:
;;     1EDA:0F37 (in fn1EDA_0F26)
fn1EDA_0E14 proc
	push	di
	cld
	mov	bx,ax
	or	dx,dx
	jge	0E29h

l1EDA_0E1C:
	not	bx
	not	dx
	add	bx,1h
	adc	dx,0h
	mov	al,2Dh
	stosb

l1EDA_0E29:
	mov	si,0E66h
	mov	cl,9h

l1EDA_0E2E:
	cmp	dx,cs:[si+2h]
	jc	0E3Bh

l1EDA_0E34:
	ja	0E42h

l1EDA_0E36:
	cmp	bx,cs:[si]
	jnc	0E42h

l1EDA_0E3B:
	add	si,4h
	dec	cl
	jnz	0E2Eh

l1EDA_0E42:
	inc	cl

l1EDA_0E44:
	mov	al,2Fh

l1EDA_0E46:
	inc	al
	sub	bx,cs:[si]
	sbb	dx,cs:[si+2h]
	jnc	0E46h

l1EDA_0E51:
	add	bx,cs:[si]
	adc	dx,cs:[si+2h]
	add	si,4h
	stosb
	dec	cl
	jnz	0E44h

l1EDA_0E60:
	mov	cx,di
	pop	di
	sub	cx,di
	ret
1EDA:0E66                   00 CA 9A 3B 00 E1 F5 05 80 96       ...;......
1EDA:0E70 98 00 40 42 0F 00 A0 86 01 00 10 27 00 00 E8 03 ..@B.......'....
1EDA:0E80 00 00 64 00 00 00 0A 00 00 00 01 00 00 00       ..d...........
