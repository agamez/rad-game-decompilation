;; fn1EDA_10BB: 1EDA:10BB
;;   Called from:
;;     0800:01DE (in fn0800_0147)
;;     0800:04A3 (in fn0800_03F8)
;;     0C43:0129 (in fn0C43_00B9)
;;     0C43:01AA (in fn0C43_00B9)
;;     0C43:0245 (in fn0C43_00B9)
;;     0C43:027C (in fn0C43_00B9)
;;     0C74:04BC (in fn0C74_03D4)
;;     0C74:04DE (in fn0C74_03D4)
;;     0C74:0581 (in fn0C74_03D4)
;;     1AB8:0A82 (in fn1AB8_097B)
;;     1AB8:16D5 (in fn1AB8_1536)
fn1EDA_10BB proc
	mov	bl,3Fh
	mov	cx,64h
	jmp	10C7h
1EDA:10C2       B3 40 B9 65 00                              .@.e.         

l1EDA_10C7:
	push	bp
	mov	bp,sp
	les	di,[bp+10h]
	call	1076h
	jnz	1111h

l1EDA_10D2:
	mov	ax,[bp+0Ah]
	or	ax,ax
	jz	10F5h

l1EDA_10D9:
	push	ds
	push	cx
	mul	word ptr es:[di+4h]
	mov	cx,ax
	lds	dx,[bp+0Ch]
	mov	ah,bl
	mov	bx,es:[di]
	int	21h
	pop	cx
	pop	ds
	jc	110Eh

l1EDA_10EF:
	xor	dx,dx
	div	word ptr es:[di+4h]

l1EDA_10F5:
	les	di,[bp+6h]
	mov	dx,es
	or	dx,di
	jz	1103h

l1EDA_10FE:
	mov	es:[di],ax
	jmp	111Fh

l1EDA_1103:
	cmp	ax,[bp+0Ah]
	jz	111Fh

l1EDA_1108:
	mov	[5380h],cx
	jmp	111Fh

l1EDA_110E:
	mov	[5380h],ax

l1EDA_1111:
	les	di,[bp+6h]
	mov	dx,es
	or	dx,di
	jz	111Fh

l1EDA_111A:
	xor	ax,ax
	mov	es:[di],ax

l1EDA_111F:
	pop	bp
	retf	0Eh
