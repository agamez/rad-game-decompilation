;; fn0C43_0056: 0C43:0056
;;   Called from:
;;     0C43:01EB (in fn0C43_00B9)
fn0C43_0056 proc
	mov	es,[5882h]
	mov	di,[589Ah]
	xor	cx,cx
	mov	cl,[5892h]
	mov	bx,[5894h]
	push	ds
	lds	si,[5884h]
	add	bx,si
	cld

l0C43_0070:
	cmp	si,bx
	jz	008Bh

l0C43_0074:
	lodsb
	cmp	cl,0h
	jg	0087h

l0C43_007A:
	cmp	al,0C0h
	jc	0084h

l0C43_007E:
	xor	al,0C0h
	mov	cl,al
	jmp	0070h

l0C43_0084:
	stosb
	jmp	0070h

l0C43_0087:
	rep stosb

l0C43_0089:
	jmp	0070h

l0C43_008B:
	pop	ds
	mov	[589Ah],di
	mov	[5892h],cl
	ret
