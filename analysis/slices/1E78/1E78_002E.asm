;; fn1E78_002E: 1E78:002E
;;   Called from:
;;     1E78:0003 (in fn1E78_0000)
fn1E78_002E proc
	mov	ah,0Fh
	call	0609h
	cmp	al,7h
	jz	0041h

l1E78_0037:
	cmp	al,3h
	jbe	0041h

l1E78_003B:
	mov	ax,3h
	call	0097h

l1E78_0041:
	call	00E5h
	mov	ah,8h
	xor	bh,bh
	call	0609h
	mov	al,ah
	and	al,7Fh
	mov	[0B8B8h],al
	mov	[0B8AEh],al
	xor	ax,ax
	mov	[0B8A9h],al
	mov	[0B8B9h],al
	mov	[0B8BAh],al
	inc	ax
	mov	[0B8A8h],al
	mov	ax,40h
	mov	es,ax
	mov	di,6Ch
	mov	al,es:[di]

l1E78_006F:
	cmp	al,es:[di]
	jz	006Fh

l1E78_0074:
	mov	al,es:[di]
	mov	cx,0FFFFh
	call	02BFh
	mov	ax,37h
	xchg	cx,ax
	not	ax
	xor	dx,dx
	div	cx
	mov	[0B8B4h],ax
	push	ds
	push	cs
	pop	ds
	mov	dx,12Dh
	mov	ax,251Bh
	int	21h
	pop	ds
	ret
