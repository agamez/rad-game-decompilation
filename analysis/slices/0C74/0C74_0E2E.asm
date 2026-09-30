;; fn0C74_0E2E: 0C74:0E2E
;;   Called from:
;;     0C74:12E9 (in fn0C74_0FA1)
;;     0C74:1461 (in fn0C74_0FA1)
;;     0C74:15B1 (in fn0C74_0FA1)
;;     0C74:1AE3 (in fn0C74_0FA1)
fn0C74_0E2E proc
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
	jc	0F81h

l0C74_0F25:
	mov	[bp-1h],al
	jmp	0F2Dh

l0C74_0F2A:
	dec	byte ptr [bp-1h]

l0C74_0F2D:
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
	jnz	0F2Ah

l0C74_0F81:
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
