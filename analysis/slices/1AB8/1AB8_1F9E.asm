;; fn1AB8_1F9E: 1AB8:1F9E
;;   Called from:
;;     1AB8:1F31 (in fn1AB8_1F19)
fn1AB8_1F9E proc
	mov	byte ptr [0B89Ch],4h
	cmp	bh,1h
	jz	1FD8h

l1AB8_1FA8:
	call	1FDEh
	jc	1FD7h

l1AB8_1FAD:
	and	bl,bl
	jz	1FD7h

l1AB8_1FB1:
	mov	byte ptr [0B89Ch],3h
	call	1FEDh
	jc	1FD2h

l1AB8_1FBB:
	mov	bx,0C000h
	mov	es,bx
	mov	bx,39h
	cmp	word ptr es:[bx],345Ah
	jnz	1FD7h

l1AB8_1FCA:
	cmp	word ptr es:[bx+2h],3934h
	jnz	1FD7h

l1AB8_1FD2:
	mov	byte ptr [0B89Ch],9h

l1AB8_1FD7:
	ret

l1AB8_1FD8:
	mov	byte ptr [0B89Ch],5h
	ret
