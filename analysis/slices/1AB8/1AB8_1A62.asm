;; fn1AB8_1A62: 1AB8:1A62
;;   Called from:
;;     1AB8:1A0D (in fn1AB8_19EE)
fn1AB8_1A62 proc
	push	bp
	call	1EE3h
	pop	bp
	les	di,[bp+0Ah]
	mov	al,[0B89Ch]
	xor	ah,ah
	cmp	al,0FFh
	jnz	1A75h

l1AB8_1A73:
	mov	ah,al

l1AB8_1A75:
	mov	es:[di],ax
	xor	ah,ah
	mov	al,[0B89Bh]
	les	di,[bp+6h]
	mov	es:[di],ax
	ret
