;; fn1AB8_1895: 1AB8:1895
;;   Called from:
;;     1AB8:1016 (in fn1AB8_0F93)
fn1AB8_1895 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+0Eh]
	mov	bx,[bp+0Ch]
	mov	cx,[bp+0Ah]
	mov	dx,[bp+8h]
	cmp	byte ptr [bp+6h],0h
	jnz	18ADh

l1AB8_18AA:
	or	ah,80h

l1AB8_18AD:
	mov	si,38h
	call	dword ptr [0B820h]
	pop	bp
	retf	0Ah
1AB8:18B8                         55 8B EC E8 4C FF 8A 46         U...L..F
1AB8:18C0 06 3C 0A 73 0F A2 9B B8 FF 36 A1 B8 FF 36 9F B8 .<.s.....6...6..
1AB8:18D0 0E E8 86 FF C4 1E 9F B8 BE 02 00 FF 1E 20 B8 5D ............. .]
1AB8:18E0 CA 02 00                                        ...
