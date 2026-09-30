;; fn1EDA_0F26: 1EDA:0F26
;;   Called from:
;;     0C74:0060 (in fn0C74_004B)
;;     1229:0A11 (in fn1229_09F9)
;;     133F:0287 (in fn133F_026B)
;;     133F:02A4 (in fn133F_026B)
;;     13C1:004B (in fn13C1_0036)
;;     1AB8:0018 (in fn1AB8_0000)
fn1EDA_0F26 proc
	push	bp
	mov	bp,sp
	sub	sp,20h
	mov	ax,[bp+0Eh]
	mov	dx,[bp+10h]
	lea	di,[bp-20h]
	push	ss
	pop	es
	call	0E14h
	push	ds
	mov	si,di
	push	ss
	pop	ds
	les	di,[bp+8h]
	mov	dx,[bp+6h]
	mov	ax,[bp+0Ch]
	cmp	ax,dx
	jle	0F4Eh

l1EDA_0F4C:
	mov	ax,dx

l1EDA_0F4E:
	cmp	cx,dx
	jle	0F54h

l1EDA_0F52:
	mov	cx,dx

l1EDA_0F54:
	cmp	ax,cx
	jge	0F5Ah

l1EDA_0F58:
	mov	ax,cx

l1EDA_0F5A:
	cld
	stosb
	sub	ax,cx
	jz	0F68h

l1EDA_0F60:
	push	cx
	mov	cx,ax
	mov	al,20h

l1EDA_0F65:
	rep stosb

l1EDA_0F67:
	pop	cx

l1EDA_0F68:
	rep movsb
	pop	ds
	mov	sp,bp
	pop	bp
	retf	0Ch
