;; fn0C74_0D94: 0C74:0D94
;;   Called from:
;;     0C74:1CF3 (in fn0C74_1B3B)
;;     0C74:2AF9 (in fn0C74_2AD9)
fn0C74_0D94 proc
	enter	2h,0h
	mov	word ptr [5968h],1h
	mov	al,[bp+4h]
	mov	[bp-2h],al
	mov	al,15h
	cmp	al,[bp-2h]
	jc	0DE1h

l0C74_0DAB:
	mov	[bp-1h],al
	jmp	0DB3h

l0C74_0DB0:
	dec	byte ptr [bp-1h]

l0C74_0DB3:
	push	64h
	push	14h
	call	070Dh
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5904h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	al,[bp-1h]
	cmp	al,[bp-2h]
	jnz	0DB0h

l0C74_0DE1:
	leave
	ret	2h
