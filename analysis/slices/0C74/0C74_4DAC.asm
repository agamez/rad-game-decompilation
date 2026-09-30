;; fn0C74_4DAC: 0C74:4DAC
;;   Called from:
;;     0C74:549D (in fn0C74_542B)
fn0C74_4DAC proc
	enter	0Ch,0h
	mov	word ptr [bp-4h],0Dh
	mov	byte ptr [bp-1h],1h

l0C74_4DB9:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	push	0Ah
	call	far 1AB8h:1E54h
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	push	2h
	call	far 1AB8h:1E54h
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	push	8h
	call	far 1AB8h:1E54h
	dec	word ptr [bp-4h]
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-4h],0E9h
	jz	4E6Fh

l0C74_4E2A:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4E6Fh

l0C74_4E4C:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	cmp	dx,0h
	jl	4E6Fh

l0C74_4E62:
	jle	4E67h

l0C74_4E64:
	jmp	4DB9h

l0C74_4E67:
	cmp	ax,1h
	jbe	4E6Fh

l0C74_4E6C:
	jmp	4DB9h

l0C74_4E6F:
	cmp	word ptr [bp-4h],0E9h
	jz	4ED9h

l0C74_4E75:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-4h]
	inc	ax
	cmp	ax,0Dh
	jg	4ED2h

l0C74_4E85:
	mov	[bp-6h],ax
	jmp	4E8Dh

l0C74_4E8A:
	inc	word ptr [bp-6h]

l0C74_4E8D:
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-6h],0Dh
	jnz	4E8Ah

l0C74_4ED2:
	mov	byte ptr [bp-1h],0h
	jmp	4FD2h

l0C74_4ED9:
	push	1F4h
	call	02D8h
	mov	ax,[58B4h]
	sub	ax,16h
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-8h],ax
	push	word ptr [bp-8h]
	call	far 1EDAh:023Fh
	mov	[bp-0Ch],ax
	mov	[bp-0Ah],dx
	mov	ax,[58B4h]
	sub	ax,16h
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	les	di,[bp-0Ch]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	word ptr [bp-4h],12h
	jmp	4F3Dh

l0C74_4F3A:
	inc	word ptr [bp-4h]

l0C74_4F3D:
	mov	ax,[58B4h]
	sub	ax,16h
	push	ax
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B8h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	les	di,[bp-0Ch]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	12Ch
	push	14h
	call	070Dh
	push	28h
	call	02D8h
	cmp	word ptr [bp-4h],2Bh
	jnz	4F3Ah

l0C74_4F75:
	push	word ptr [bp-0Ah]
	push	word ptr [bp-0Ch]
	push	word ptr [bp-8h]
	call	far 1EDAh:0254h
	mov	word ptr [bp-6h],0FFEAh
	jmp	4F8Dh

l0C74_4F8A:
	inc	word ptr [bp-6h]

l0C74_4F8D:
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-6h],0Dh
	jnz	4F8Ah

l0C74_4FD2:
	mov	al,[bp-1h]
	leave
	ret
