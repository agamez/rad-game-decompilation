;; fn1EDA_011B: 1EDA:011B
;;   Called from:
;;     1EDA:00FA (in fn1EDA_00ED)
;;     1EDA:00FA (in fn1EDA_00ED)
;;     1EDA:0118 (in fn1EDA_00FC)
fn1EDA_011B proc
	mov	[5378h],cx
	mov	[537Ah],bx
	les	bx,[5372h]
	mov	ax,es
	or	ax,bx
	jz	0140h

l1EDA_012D:
	xor	ax,ax
	mov	[5372h],ax
	mov	[5374h],ax
	mov	[5380h],ax
	mov	ax,123h
	push	cs
	push	ax
	push	es
	push	bx
	retf

l1EDA_0140:
	mov	ax,0B8BCh
	push	ds
	push	ax
	push	cs
	call	05BFh
	mov	ax,0B9BCh
	push	ds
	push	ax
	push	cs
	call	05BFh
	mov	di,0BABCh
	mov	si,1EEh
	mov	cx,13h
	nop

l1EDA_015C:
	cld
	lodsb	al,cs:[si]
	mov	ah,25h
	push	ds
	lds	dx,[di]
	int	21h
	pop	ds
	add	di,4h
	loop	015Ch

l1EDA_016C:
	mov	ax,[5378h]
	or	ax,[537Ah]
	jz	019Eh

l1EDA_0175:
	mov	bx,201h
	call	01A5h
	mov	ax,[5376h]
	call	01B3h
	mov	bx,210h
	call	01A5h
	mov	ax,[537Ah]
	call	01CDh
	mov	al,3Ah
	call	01E7h
	mov	ax,[5378h]
	call	01CDh
	mov	bx,215h
	call	01A5h

l1EDA_019E:
	mov	ax,[5376h]
	mov	ah,4Ch
	int	21h
