;; fn0C74_03D4: 0C74:03D4
;;   Called from:
;;     0800:43F6 (in fn0800_4255)
fn0C74_03D4 proc
	enter	8Ah,0h
	mov	di,3B2h
	push	cs
	push	di
	push	cs
	call	0000h
	or	al,al
	jnz	0415h

l0C74_03E5:
	call	far 1AB8h:0EB5h
	call	far 1AB8h:0E88h
	push	word ptr [0B8ACh]
	call	far 1E78h:016Bh
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,3BAh
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:0848h
	xor	ax,ax
	call	far 1EDAh:00E9h

l0C74_0415:
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	mov	di,3B2h
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	push	word ptr [4D0Eh]
	call	far 1EDAh:0FD0h
	push	0h
	push	0h
	push	2Bh
	push	18h
	call	far 1AB8h:13A3h
	mov	[bp+0FF78h],ax
	push	0h
	push	0h
	push	2Bh
	push	2Bh
	call	far 1AB8h:13A3h
	mov	[bp+0FF76h],ax
	push	word ptr [4D0Eh]
	call	far 1EDAh:023Fh
	mov	[bp+0FF7Ah],ax
	mov	[bp+0FF7Ch],dx
	mov	byte ptr [bp-1h],1h
	jmp	0470h

l0C74_046D:
	inc	byte ptr [bp-1h]

l0C74_0470:
	push	5h
	push	cs
	call	00B2h
	mov	al,[bp-1h]
	cmp	al,1h
	jc	04C4h

l0C74_047D:
	cmp	al,4h
	ja	04C4h

l0C74_0481:
	push	word ptr [4D0Eh]
	call	far 1EDAh:023Fh
	mov	cx,ax
	mov	bx,dx
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	mov	[di+58E4h],cx
	mov	[di+58E6h],bx
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+58E4h]
	push	es
	push	di
	push	1h
	xor	ax,ax
	push	ax
	push	ax
	call	far 1EDAh:10BBh
	jmp	0586h

l0C74_04C4:
	cmp	al,5h
	jc	0538h

l0C74_04C8:
	cmp	al,19h
	ja	0538h

l0C74_04CC:
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	les	di,[bp+0FF7Ah]
	push	es
	push	di
	push	1h
	xor	ax,ax
	push	ax
	push	ax
	call	far 1EDAh:10BBh
	push	0h
	push	0h
	les	di,[bp+0FF7Ah]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	word ptr [bp+0FF78h]
	call	far 1EDAh:023Fh
	mov	cx,ax
	mov	bx,dx
	mov	al,[bp-1h]
	xor	ah,ah
	sub	ax,4h
	mov	di,ax
	shl	di,2h
	mov	[di+5904h],cx
	mov	[di+5906h],bx
	push	0h
	push	0h
	push	2Bh
	push	18h
	mov	al,[bp-1h]
	xor	ah,ah
	sub	ax,4h
	mov	di,ax
	shl	di,2h
	les	di,[di+5904h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	jmp	0586h

l0C74_0538:
	cmp	al,1Ah
	jc	0586h

l0C74_053C:
	cmp	al,1Dh
	ja	0586h

l0C74_0540:
	push	word ptr [4D0Eh]
	call	far 1EDAh:023Fh
	mov	cx,ax
	mov	bx,dx
	mov	al,[bp-1h]
	xor	ah,ah
	sub	ax,19h
	mov	di,ax
	shl	di,2h
	mov	[di+58F4h],cx
	mov	[di+58F6h],bx
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	mov	al,[bp-1h]
	xor	ah,ah
	sub	ax,19h
	mov	di,ax
	shl	di,2h
	les	di,[di+58F4h]
	push	es
	push	di
	push	1h
	xor	ax,ax
	push	ax
	push	ax
	call	far 1EDAh:10BBh

l0C74_0586:
	push	0h
	push	0h
	push	2Ch
	push	2Ch
	call	007Ch
	cmp	byte ptr [bp-1h],1Dh
	jz	059Ah

l0C74_0597:
	jmp	046Dh

l0C74_059A:
	push	word ptr [bp+0FF7Ch]
	push	word ptr [bp+0FF7Ah]
	push	word ptr [4D0Eh]
	call	far 1EDAh:0254h
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	call	far 1EDAh:1051h
	leave
	retf
