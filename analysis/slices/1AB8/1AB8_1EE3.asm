;; fn1AB8_1EE3: 1AB8:1EE3
;;   Called from:
;;     1AB8:1A63 (in fn1AB8_1A62)
fn1AB8_1EE3 proc
	mov	byte ptr [0B89Ah],0FFh
	mov	byte ptr [0B89Ch],0FFh
	mov	byte ptr [0B89Bh],0h
	call	1F19h
	mov	bl,[0B89Ch]
	cmp	bl,0FFh
	jz	1F18h

l1AB8_1EFE:
	xor	bh,bh
	mov	al,cs:[bx+1EB9h]
	mov	[0B89Ah],al
	mov	al,cs:[bx+1EC7h]
	mov	[0B89Bh],al
	mov	al,cs:[bx+1ED5h]
	mov	[0B89Dh],al

l1AB8_1F18:
	ret
