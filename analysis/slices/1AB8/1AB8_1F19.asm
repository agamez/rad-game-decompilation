;; fn1AB8_1F19: 1AB8:1F19
;;   Called from:
;;     1AB8:1EF2 (in fn1AB8_1EE3)
fn1AB8_1F19 proc
	mov	ah,0Fh
	int	10h
	cmp	al,7h
	jz	1F52h

l1AB8_1F21:
	call	200Eh
	jnc	1F2Ch

l1AB8_1F26:
	mov	byte ptr [0B89Ch],6h
	ret

l1AB8_1F2C:
	call	1F80h
	jnc	1F35h

l1AB8_1F31:
	call	1F9Eh
	ret

l1AB8_1F35:
	call	2043h
	and	ax,ax
	jz	1F42h

l1AB8_1F3C:
	mov	byte ptr [0B89Ch],0Ah
	ret

l1AB8_1F42:
	mov	byte ptr [0B89Ch],1h
	call	1FEDh
	jnc	1F51h

l1AB8_1F4C:
	mov	byte ptr [0B89Ch],2h

l1AB8_1F51:
	ret

l1AB8_1F52:
	call	1F80h
	jc	1F31h

l1AB8_1F57:
	call	2011h
	and	al,al
	jz	1F64h

l1AB8_1F5E:
	mov	byte ptr [0B89Ch],7h
	ret

l1AB8_1F64:
	mov	si,0B800h
	mov	es,si
	xor	si,si
	mov	ax,es:[si]
	not	ax
	not	word ptr es:[si]
	nop
	nop
	cmp	ax,es:[si]
	jnz	1F7Fh

l1AB8_1F7A:
	mov	byte ptr [0B89Ch],1h

l1AB8_1F7F:
	ret
