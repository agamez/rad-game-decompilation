;; fn1EDA_1216: 1EDA:1216
;;   Called from:
;;     0800:429D (in fn0800_4255)
;;     0800:42B8 (in fn0800_4255)
;;     0800:42F9 (in fn0800_4255)
fn1EDA_1216 proc
	push	bp
	mov	bp,sp
	mov	dx,[bp+6h]
	or	dx,dx
	jz	1225h

l1EDA_1220:
	call	126Ch
	jmp	1255h

l1EDA_1225:
	mov	ah,30h
	int	21h
	cmp	al,3h
	mov	ax,0h
	jc	1255h

l1EDA_1230:
	mov	es,[537Ch]
	mov	es,es:[002Ch]
	xor	di,di
	cld

l1EDA_123C:
	cmp	al,es:[di]
	jz	1248h

l1EDA_1241:
	mov	cx,0FFFFh
	repne scasb
	jmp	123Ch

l1EDA_1248:
	add	di,3h
	mov	si,di
	mov	cx,100h

l1EDA_1250:
	repne scasb

l1EDA_1252:
	xchg	cx,ax
	not	al

l1EDA_1255:
	push	ds
	push	es
	pop	ds
	les	di,[bp+8h]
	cld
	stosb
	xchg	cx,ax
	rep movsb
	pop	ds
	pop	bp
	retf	2h
