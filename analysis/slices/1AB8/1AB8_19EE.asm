;; fn1AB8_19EE: 1AB8:19EE
;;   Called from:
;;     1AB8:0C9C (in fn1AB8_0BAE)
;;     1AB8:0CC7 (in fn1AB8_0BAE)
fn1AB8_19EE proc
	push	bp
	mov	bp,sp
	mov	byte ptr [0B89Ah],0FFh
	mov	byte ptr [0B89Bh],0h
	mov	byte ptr [0B89Dh],0Ah
	les	di,[bp+0Ah]
	mov	al,es:[di]
	mov	[0B89Ch],al
	and	al,al
	jnz	1A15h

l1AB8_1A0D:
	call	1A62h
	mov	al,[0B89Ah]
	jmp	1A44h

l1AB8_1A15:
	les	di,[bp+6h]
	mov	al,es:[di]
	mov	[0B89Bh],al
	les	di,[bp+0Ah]
	mov	bl,es:[di]
	and	bl,bl
	js	1A4Ch

l1AB8_1A28:
	mov	al,0Ah
	sub	al,bl
	jnc	1A32h

l1AB8_1A2E:
	neg	al
	jmp	1A44h

l1AB8_1A32:
	xor	bh,bh
	mov	al,cs:[bx+1ED5h]
	mov	[0B89Dh],al
	mov	al,cs:[bx+1EB9h]
	mov	[0B89Ah],al

l1AB8_1A44:
	les	di,[bp+0Eh]
	xor	ah,ah
	mov	es:[di],ax

l1AB8_1A4C:
	pop	bp
	retf	0Ch
1AB8:1A50 55 8B EC FF 36 9A B8 E8 08 00 8F 06 9A B8 5D CA U...6.........].
1AB8:1A60 08 00                                           ..
