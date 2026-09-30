;; fn1AB8_2011: 1AB8:2011
;;   Called from:
;;     1AB8:1F57 (in fn1AB8_1F19)
fn1AB8_2011 proc
	mov	dx,3BAh
	xor	bl,bl
	in	al,dx
	and	al,80h
	mov	ah,al
	mov	cx,8000h

l1AB8_201E:
	in	al,dx
	and	al,80h
	cmp	al,ah
	jz	202Ch

l1AB8_2025:
	inc	bl
	cmp	bl,0Ah
	jnc	2031h

l1AB8_202C:
	loop	201Eh

l1AB8_202E:
	xor	al,al
	ret

l1AB8_2031:
	mov	cx,8000h

l1AB8_2034:
	in	al,dx
	and	al,30h
	cmp	al,10h
	jnz	2040h

l1AB8_203B:
	loop	2034h

l1AB8_203D:
	mov	al,2h
	ret

l1AB8_2040:
	mov	al,1h
	ret
