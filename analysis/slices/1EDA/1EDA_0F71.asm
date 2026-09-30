;; fn1EDA_0F71: 1EDA:0F71
;;   Called from:
;;     0800:4303 (in fn0800_4255)
;;     1229:05C8 (in fn1229_050A)
fn1EDA_0F71 proc
	push	bp
	mov	bp,sp
	les	di,[bp+0Ah]
	mov	cl,es:[di]
	xor	ch,ch
	inc	di
	jcxz	0F88h

l1EDA_0F7F:
	cmp	byte ptr es:[di],20h
	jnz	0F88h

l1EDA_0F85:
	inc	di
	loop	0F7Fh

l1EDA_0F88:
	call	0E8Eh
	jc	0F8Fh

l1EDA_0F8D:
	jcxz	0F98h

l1EDA_0F8F:
	mov	cx,di
	sub	cx,[bp+0Ah]
	xor	ax,ax
	xor	dx,dx

l1EDA_0F98:
	les	di,[bp+6h]
	mov	es:[di],cx
	pop	bp
	retf	8h
