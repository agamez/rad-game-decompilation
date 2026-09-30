;; fn0C74_3F74: 0C74:3F74
;;   Called from:
;;     0C74:52D3 (in fn0C74_5258)
fn0C74_3F74 proc
	enter	0Ah,0h
	mov	byte ptr [bp-1h],1h
	inc	word ptr [58B4h]
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0Ch
	call	far 1AB8h:1C32h
	mov	word ptr [bp-4h],0Dh

l0C74_3F97:
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
	call	far 1AB8h:1AF6h
	dec	word ptr [bp-4h]
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-4h],0F3h
	jz	4024h

l0C74_3FDF:
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
	jnz	4024h

l0C74_4001:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	cmp	dx,0h
	jl	4024h

l0C74_4017:
	jle	401Ch

l0C74_4019:
	jmp	3F97h

l0C74_401C:
	cmp	ax,1h
	jbe	4024h

l0C74_4021:
	jmp	3F97h

l0C74_4024:
	cmp	word ptr [bp-4h],0F3h
	jz	4092h

l0C74_402A:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-4h]
	inc	ax
	cmp	ax,0Dh
	jg	4087h

l0C74_403A:
	mov	[bp-6h],ax
	jmp	4042h

l0C74_403F:
	inc	word ptr [bp-6h]

l0C74_4042:
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
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-6h],0Dh
	jnz	403Fh

l0C74_4087:
	dec	word ptr [58B4h]
	mov	byte ptr [bp-1h],0h
	jmp	45C9h

l0C74_4092:
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	mov	ax,[58B4h]
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	mov	word ptr [bp-6h],3h
	jmp	40F1h

l0C74_40EE:
	inc	word ptr [bp-6h]

l0C74_40F1:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	shl	di,1h
	mov	ax,[di+4D5Eh]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D87h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D9Bh]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	sub	ax,dx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4DAFh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	di,[bp-6h]
	shl	di,1h
	mov	ax,[di+4D5Eh]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	di,[bp-6h]
	mov	al,[di+4D87h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	di,[bp-6h]
	mov	al,[di+4D9Bh]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	sub	ax,dx
	push	ax
	mov	di,[bp-6h]
	mov	al,[di+4DAFh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	shl	di,1h
	mov	ax,[di+4D5Eh]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	mov	al,[di+4D87h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	mov	al,[di+4D9Bh]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	sub	ax,dx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	mov	al,[di+4DAFh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	190h
	push	32h
	call	070Dh
	cmp	word ptr [bp-6h],14h
	jz	420Ah

l0C74_4207:
	jmp	40EEh

l0C74_420A:
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	push	0h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	mov	ax,[58B8h]
	add	ax,6h
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	mov	ax,[58B8h]
	add	ax,10h
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[58B8h]
	add	ax,6h
	mov	[bp-8h],ax
	mov	ax,[58B8h]
	add	ax,14h
	mov	[bp-0Ah],ax
	mov	word ptr [bp-6h],1h
	jmp	425Ch

l0C74_4259:
	inc	word ptr [bp-6h]

l0C74_425C:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	push	word ptr [bp-8h]
	mov	ax,[58B4h]
	sub	ax,0Dh
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	push	word ptr [bp-0Ah]
	mov	ax,[58B4h]
	sub	ax,0Dh
	push	ax
	push	word ptr [bp-0Ah]
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	push	word ptr [bp-0Ah]
	push	0h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	sub	ax,0Eh
	push	ax
	push	word ptr [bp-0Ah]
	push	0h
	call	far 1AB8h:1E54h
	inc	word ptr [bp-8h]
	inc	word ptr [bp-0Ah]
	push	64h
	push	64h
	call	070Dh
	cmp	word ptr [bp-6h],0Bh
	jnz	4259h

l0C74_42D1:
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	push	word ptr [bp-0Ah]
	mov	ax,[58B4h]
	sub	ax,0Dh
	push	ax
	push	word ptr [bp-0Ah]
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	push	word ptr [bp-0Ah]
	push	0h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	sub	ax,0Eh
	push	ax
	push	word ptr [bp-0Ah]
	push	0h
	call	far 1AB8h:1E54h
	push	1F4h
	call	02D8h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	push	word ptr [bp-0Ah]
	mov	ax,[58B4h]
	sub	ax,0Dh
	push	ax
	push	word ptr [bp-0Ah]
	call	far 1AB8h:1AF6h
	mov	ax,[58B8h]
	add	ax,10h
	mov	[bp-8h],ax
	mov	ax,[58B8h]
	add	ax,1Eh
	mov	[bp-0Ah],ax
	mov	word ptr [bp-6h],1h
	jmp	4355h

l0C74_4352:
	inc	word ptr [bp-6h]

l0C74_4355:
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	push	word ptr [bp-8h]
	mov	ax,[58B4h]
	sub	ax,0Dh
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1AF6h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	push	word ptr [bp-0Ah]
	mov	ax,[58B4h]
	sub	ax,0Dh
	push	ax
	push	word ptr [bp-0Ah]
	call	far 1AB8h:1AF6h
	dec	word ptr [bp-8h]
	dec	word ptr [bp-0Ah]
	push	64h
	push	64h
	call	070Dh
	cmp	word ptr [bp-6h],0Bh
	jnz	4352h

l0C74_43A8:
	mov	word ptr [bp-6h],14h
	jmp	43B2h

l0C74_43AF:
	dec	word ptr [bp-6h]

l0C74_43B2:
	push	0h
	call	far 1AB8h:1C32h
	mov	di,[bp-6h]
	shl	di,1h
	mov	ax,[di+4D5Eh]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	di,[bp-6h]
	mov	al,[di+4D87h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	di,[bp-6h]
	mov	al,[di+4D9Bh]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	sub	ax,dx
	push	ax
	mov	di,[bp-6h]
	mov	al,[di+4DAFh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	shl	di,1h
	mov	ax,[di+4D5Eh]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D87h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D9Bh]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	sub	ax,dx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4DAFh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	shl	di,1h
	mov	ax,[di+4D5Eh]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	mov	al,[di+4D87h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	mov	al,[di+4D9Bh]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	sub	ax,dx
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	mov	di,ax
	mov	al,[di+4DAFh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	190h
	push	32h
	call	070Dh
	cmp	word ptr [bp-6h],3h
	jz	44CBh

l0C74_44C8:
	jmp	43AFh

l0C74_44CB:
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	mov	ax,[58B8h]
	add	ax,10h
	push	ax
	push	0h
	call	far 1AB8h:1E54h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	call	far 1AB8h:1AF6h
	push	1F4h
	call	02D8h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	push	0Ch
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-4h]
	inc	ax
	cmp	ax,0Dh
	jg	45C5h

l0C74_4578:
	mov	[bp-6h],ax
	jmp	4580h

l0C74_457D:
	inc	word ptr [bp-6h]

l0C74_4580:
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
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-6h],0Dh
	jnz	457Dh

l0C74_45C5:
	dec	word ptr [58B4h]

l0C74_45C9:
	mov	al,[bp-1h]
	leave
	ret
