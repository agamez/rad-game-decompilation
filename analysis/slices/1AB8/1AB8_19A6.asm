;; fn1AB8_19A6: 1AB8:19A6
;;   Called from:
;;     1AB8:13B5 (in fn1AB8_13A3)
fn1AB8_19A6 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+8h]
	sub	ax,[bp+0Ch]
	jns	19B3h

l1AB8_19B1:
	neg	ax

l1AB8_19B3:
	inc	ax
	add	ax,7h
	shr	ax,1h
	shr	ax,1h
	shr	ax,1h
	push	ax
	mov	si,32h
	call	dword ptr [0B820h]
	mov	bx,es:[bx+8h]
	push	cs
	call	1807h
	pop	bx
	mul	bx
	mov	cx,[bp+6h]
	sub	cx,[bp+0Ah]
	jns	19DAh

l1AB8_19D8:
	neg	cx

l1AB8_19DA:
	inc	cx
	mul	cx
	add	ax,6h
	jc	19E6h

l1AB8_19E2:
	and	dx,dx
	jz	19EAh

l1AB8_19E6:
	xor	ax,ax
	mov	dx,ax

l1AB8_19EA:
	pop	bp
	retf	8h
