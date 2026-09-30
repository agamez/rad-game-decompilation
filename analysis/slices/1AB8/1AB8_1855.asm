;; fn1AB8_1855: 1AB8:1855
;;   Called from:
;;     1AB8:0E25 (in fn1AB8_0BAE)
fn1AB8_1855 proc
	mov	byte ptr [0B8A3h],0FFh
	push	bp
	mov	bp,sp
	xor	ax,ax
	mov	ch,[0B89Dh]
	cmp	byte ptr [0B89Ch],5h
	jnz	186Ch

l1AB8_186A:
	mov	ch,3h

l1AB8_186C:
	mov	cl,[0B89Bh]
	les	bx,[bp+6h]
	mov	ah,1h
	cmp	byte ptr es:[bx+16h],0h
	jnz	1882h

l1AB8_187C:
	xor	ah,ah
	les	bx,[0B832h]

l1AB8_1882:
	mov	si,0h
	call	dword ptr [0B820h]
	mov	[0B83Ah],bx
	mov	[0B83Ch],es
	pop	bp
	retf	4h
