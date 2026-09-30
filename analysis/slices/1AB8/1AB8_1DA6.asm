;; fn1AB8_1DA6: 1AB8:1DA6
;;   Called from:
;;     1AB8:1779 (in fn1AB8_1536)
fn1AB8_1DA6 proc
	push	bp
	mov	bp,sp
	les	bx,[0B83Ah]
	mov	bx,es:[bx+10h]
	and	bx,7F7Fh
	mov	dl,[bp+6h]
	mov	al,bh
	mul	dl
	mov	cx,ax
	mov	al,bl
	mul	dl
	mov	bx,ax
	mov	al,[bp+0Ah]
	mov	ah,[bp+8h]
	and	al,al
	jz	1DE3h

l1AB8_1DCE:
	les	di,[0B83Ah]
	cmp	byte ptr es:[di+1h],3h
	jz	1DE3h

l1AB8_1DD9:
	mov	cl,dl
	xor	ch,ch
	mov	bx,cx
	mov	dx,[0B838h]

l1AB8_1DE3:
	mov	si,24h
	call	dword ptr [0B820h]
	pop	bp
	retf	6h
1AB8:1DEE                                           55 8B               U.
1AB8:1DF0 EC 8B 46 0C 8B 5E 0A 8B 4E 08 8B 56 06 80 CC 80 ..F..^..N..V....
1AB8:1E00 BE 24 00 FF 1E 20 B8 5D CA 08 00                .$... .]...
