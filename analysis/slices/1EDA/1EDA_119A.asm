;; fn1EDA_119A: 1EDA:119A
;;   Called from:
;;     1EDA:116A (in fn1EDA_116A)
;;     1EDA:1185 (in fn1EDA_1185)
fn1EDA_119A proc
	mov	bx,sp
	les	di,ss:[bx+6h]
	cmp	word ptr es:[di+2h],0D7B3h
	jnz	11D3h

l1EDA_11A8:
	xor	cx,cx
	xor	dx,dx
	mov	bx,es:[di]
	mov	ax,4201h
	int	21h
	push	dx
	push	ax
	xor	cx,cx
	xor	dx,dx
	mov	bx,es:[di]
	mov	ax,4202h
	int	21h
	pop	bx
	pop	cx
	push	dx
	push	ax
	mov	dx,bx
	mov	bx,es:[di]
	mov	ax,4200h
	int	21h
	pop	cx
	pop	bx
	ret

l1EDA_11D3:
	mov	word ptr [5380h],67h
	xor	ax,ax
	xor	dx,dx
	stc
	ret
