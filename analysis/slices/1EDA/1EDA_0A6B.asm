;; fn1EDA_0A6B: 1EDA:0A6B
;;   Called from:
;;     1229:084F (in fn1229_0735)
;;     133F:031B (in fn133F_02DF)
;;     1EDA:0B97 (in fn1EDA_0B7C)
;;     1EDA:0BB6 (in fn1EDA_0B7C)
;;     1EDA:0BF1 (in fn1EDA_0BD0)
;;     1EDA:0C0B (in fn1EDA_0BD0)
fn1EDA_0A6B proc
	cld
	mov	bx,sp
	mov	dx,ds
	les	di,ss:[bx+0Ch]
	lds	si,ss:[bx+8h]
	mov	al,[si]
	xor	ah,ah
	mov	cx,ss:[bx+6h]
	or	cx,cx
	jg	0A87h

l1EDA_0A84:
	mov	cx,1h

l1EDA_0A87:
	add	si,cx
	sub	ax,cx
	jc	0AA0h

l1EDA_0A8D:
	inc	ax
	mov	cx,ss:[bx+4h]
	or	cx,cx
	jge	0A98h

l1EDA_0A96:
	xor	cx,cx

l1EDA_0A98:
	cmp	ax,cx
	jbe	0AA2h

l1EDA_0A9C:
	mov	ax,cx
	jmp	0AA2h

l1EDA_0AA0:
	xor	ax,ax

l1EDA_0AA2:
	stosb
	mov	cx,ax
	rep movsb
	mov	ds,dx
	retf	8h
