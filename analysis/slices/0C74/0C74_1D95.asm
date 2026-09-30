;; fn0C74_1D95: 0C74:1D95
;;   Called from:
;;     0C74:2250 (in fn0C74_1F08)
;;     0C74:23BA (in fn0C74_1F08)
;;     0C74:2518 (in fn0C74_1F08)
;;     0C74:2A7B (in fn0C74_1F08)
fn0C74_1D95 proc
	enter	0Eh,0h
	mov	ax,[58B4h]
	add	ax,19h
	mov	di,[bp+4h]
	add	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Dh
	mov	di,[bp+4h]
	add	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-4h],ax
	mov	ax,[58B4h]
	add	ax,0Dh
	mov	di,[bp+4h]
	sub	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	mov	di,[bp+4h]
	sub	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-6h],ax
	push	word ptr [bp-6h]
	call	far 1EDAh:023Fh
	mov	[bp-0Ah],ax
	mov	[bp-8h],dx
	push	word ptr [bp-4h]
	call	far 1EDAh:023Fh
	mov	[bp-0Eh],ax
	mov	[bp-0Ch],dx
	mov	ax,[58B4h]
	add	ax,19h
	mov	di,[bp+4h]
	add	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Dh
	mov	di,[bp+4h]
	add	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-0Eh]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[58B4h]
	add	ax,0Dh
	mov	di,[bp+4h]
	sub	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	mov	di,[bp+4h]
	sub	ax,ss:[di-4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-0Ah]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	di,[bp+4h]
	mov	al,ss:[di-4h]
	or	al,al
	jc	1EE8h

l0C74_1E8C:
	mov	[bp-1h],al
	jmp	1E94h

l0C74_1E91:
	dec	byte ptr [bp-1h]

l0C74_1E94:
	push	0E6h
	push	0Ah
	call	070Dh
	mov	al,[bp-1h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,19h
	add	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-0Eh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	al,[bp-1h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-0Ah]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	byte ptr [bp-1h],0h
	jnz	1E91h

l0C74_1EE8:
	push	word ptr [bp-8h]
	push	word ptr [bp-0Ah]
	push	word ptr [bp-6h]
	call	far 1EDAh:0254h
	push	word ptr [bp-0Ch]
	push	word ptr [bp-0Eh]
	push	word ptr [bp-4h]
	call	far 1EDAh:0254h
	leave
	ret	2h
