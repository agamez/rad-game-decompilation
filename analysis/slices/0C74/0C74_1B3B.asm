;; fn0C74_1B3B: 0C74:1B3B
;;   Called from:
;;     0C74:51AD (in fn0C74_51AA)
fn0C74_1B3B proc
	enter	6h,0h
	mov	ax,[58B4h]
	add	ax,17h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Ch
	push	ax
	push	3h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,18h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Ch
	push	ax
	push	1h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Ch
	push	ax
	push	1h
	call	far 1AB8h:1E54h
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	ax,[58B4h]
	add	ax,2Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,1Ch
	push	ax
	call	far 1AB8h:13A3h
	mov	[595Eh],ax
	push	word ptr [595Eh]
	call	far 1EDAh:023Fh
	mov	[bp-6h],ax
	mov	[bp-4h],dx
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	ax,[58B4h]
	add	ax,2Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,1Ch
	push	ax
	les	di,[bp-6h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	byte ptr [bp-1h],0h

l0C74_1BCF:
	cmp	byte ptr [bp-1h],58h
	jnc	1C1Eh

l0C74_1BD5:
	push	word ptr [58B4h]
	mov	ax,[58B8h]
	dec	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	1C1Eh

l0C74_1BE7:
	push	word ptr [58B6h]
	mov	ax,[58B8h]
	dec	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	1C1Eh

l0C74_1BF9:
	push	0C8h
	push	0Ah
	call	070Dh
	dec	word ptr [58B8h]
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	les	di,[bp-6h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	inc	byte ptr [bp-1h]
	jmp	1BCFh

l0C74_1C1E:
	mov	ax,[58E6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[4D0Ch]
	xor	dx,dx
	call	far 1EDAh:096Fh
	mov	cx,4h
	xor	bx,bx
	call	far 1EDAh:098Ah
	push	ax
	call	02D8h

l0C74_1C3E:
	cmp	byte ptr [bp-1h],0h
	jbe	1C93h

l0C74_1C44:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,2Ch
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	1C93h

l0C74_1C59:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,2Ch
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	1C93h

l0C74_1C6E:
	push	0C8h
	push	0Ah
	call	070Dh
	inc	word ptr [58B8h]
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	les	di,[bp-6h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	dec	byte ptr [bp-1h]
	jmp	1C3Eh

l0C74_1C93:
	cmp	byte ptr [bp-1h],0h
	jnz	1CABh

l0C74_1C99:
	push	word ptr [bp-4h]
	push	word ptr [bp-6h]
	push	word ptr [595Eh]
	call	far 1EDAh:0254h
	jmp	1D93h

l0C74_1CAB:
	cmp	word ptr [5968h],1h
	jnz	1CD5h

l0C74_1CB2:
	push	0C8h
	call	02D8h
	push	15h
	call	0D43h
	push	0C8h
	call	02D8h
	push	15h
	call	0CFAh
	push	0C8h
	call	02D8h
	push	0Bh
	call	0D43h
	jmp	1CF6h

l0C74_1CD5:
	push	0C8h
	call	02D8h
	push	15h
	call	0CFAh
	push	0C8h
	call	02D8h
	push	15h
	call	0D43h
	push	0C8h
	call	02D8h
	push	0Bh
	call	0D94h

l0C74_1CF6:
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	ax,[58B4h]
	add	ax,2Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,1Ch
	push	ax
	les	di,[bp-6h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	call	0FA1h
	or	al,al
	jnz	1D48h

l0C74_1D1D:
	cmp	byte ptr [bp-1h],0h
	jbe	1D48h

l0C74_1D23:
	push	0C8h
	push	0Ah
	call	070Dh
	inc	word ptr [58B8h]
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	les	di,[bp-6h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	dec	byte ptr [bp-1h]
	jmp	1D1Dh

l0C74_1D48:
	push	word ptr [bp-4h]
	push	word ptr [bp-6h]
	push	word ptr [595Eh]
	call	far 1EDAh:0254h
	cmp	byte ptr [58B3h],0h
	jz	1D60h

l0C74_1D5E:
	jmp	1D93h

l0C74_1D60:
	mov	ax,[58E6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[4D0Ch]
	xor	dx,dx
	call	far 1EDAh:096Fh
	mov	cx,4h
	xor	bx,bx
	call	far 1EDAh:098Ah
	push	ax
	call	02D8h
	cmp	word ptr [5968h],1h
	jnz	1D8Eh

l0C74_1D87:
	push	0Bh
	call	0DE5h
	jmp	1D93h

l0C74_1D8E:
	push	0Bh
	call	0CFAh

l0C74_1D93:
	leave
	ret
