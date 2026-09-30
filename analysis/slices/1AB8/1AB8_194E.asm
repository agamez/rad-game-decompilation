;; fn1AB8_194E: 1AB8:194E
;;   Called from:
;;     1AB8:0B9A (in fn1AB8_0AEE)
fn1AB8_194E proc
	push	bp
	mov	bp,sp
	mov	al,[bp+6h]
	xor	ah,ah
	push	ax
	mov	si,32h
	call	dword ptr [0B820h]
	mov	bx,es:[bx+0Eh]
	jmp	1945h
1AB8:1964             5D CA 02 00                             ]...
