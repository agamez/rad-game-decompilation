;; fn1E5F_0136: 1E5F:0136
;;   Called from:
;;     1E5F:0113 (in fn1E5F_00DE)
fn1E5F_0136 proc
	jc	0155h

l1E5F_0138:
	add	di,1Eh
	push	ds
	push	es
	pop	ds
	xor	al,al
	mov	cx,100h
	cld

l1E5F_0144:
	repne scasb

l1E5F_0146:
	not	cl
	mov	al,cl
	dec	di
	mov	si,di
	dec	si
	std

l1E5F_014F:
	rep movsb

l1E5F_0151:
	stosb
	pop	ds
	xor	ax,ax

l1E5F_0155:
	mov	[0B8A6h],ax
	ret
