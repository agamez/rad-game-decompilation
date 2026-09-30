;; fn1EDA_1091: 1EDA:1091
;;   Called from:
;;     1EDA:108A (in fn1EDA_1085)
;;     1EDA:108E (in fn1EDA_108C)
fn1EDA_1091 proc
	push	bp
	mov	bp,sp
	les	di,[bp+0Ah]
	call	1076h
	jnz	10B7h

l1EDA_109C:
	push	ds
	push	dx
	lds	dx,[bp+6h]
	mov	cx,es:[di+4h]
	mov	bx,es:[di]
	int	21h
	pop	dx
	pop	ds
	jc	10B4h

l1EDA_10AE:
	cmp	ax,cx
	jz	10B7h

l1EDA_10B2:
	mov	ax,dx

l1EDA_10B4:
	mov	[5380h],ax

l1EDA_10B7:
	pop	bp
	retf	4h
