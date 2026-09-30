;; fn1EDA_0572: 1EDA:0572
;;   Called from:
;;     1EDA:0568 (in fn1EDA_0565)
;;     1EDA:056D (in fn1EDA_056A)
fn1EDA_0572 proc
	push	bp
	mov	bp,sp
	les	di,[bp+6h]
	mov	ax,es:[di+2h]
	cmp	ax,0D7B1h
	jz	0593h

l1EDA_0581:
	cmp	ax,0D7B2h
	jz	0593h

l1EDA_0586:
	cmp	ax,0D7B0h
	jz	059Bh

l1EDA_058B:
	mov	word ptr [5380h],66h
	jmp	05B7h

l1EDA_0593:
	push	dx
	push	es
	push	di
	push	cs
	call	05BFh
	pop	dx

l1EDA_059B:
	xor	ax,ax
	mov	es:[di+2h],dx
	mov	es:[di+8h],ax
	mov	es:[di+0Ah],ax
	mov	bx,10h
	call	05FBh
	jz	05B7h

l1EDA_05B1:
	mov	word ptr es:[di+2h],0D7B0h

l1EDA_05B7:
	pop	bp
	retf	4h
1EDA:05BB                                  B0 00 EB 02               ....
