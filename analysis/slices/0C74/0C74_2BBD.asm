;; fn0C74_2BBD: 0C74:2BBD
;;   Called from:
;;     0C74:315F (in fn0C74_2E5A)
;;     0C74:353E (in fn0C74_3236)
;;     0C74:53FB (in fn0C74_5258)
fn0C74_2BBD proc
	enter	12h,0h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	call	far 1AB8h:13A3h
	mov	[bp-0Ch],ax
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+8h]
	call	far 1AB8h:13A3h
	mov	[bp-0Ah],ax
	push	word ptr [bp-0Ch]
	call	far 1EDAh:023Fh
	mov	[bp-4h],ax
	mov	[bp-2h],dx
	push	word ptr [bp-0Ah]
	call	far 1EDAh:023Fh
	mov	[bp-8h],ax
	mov	[bp-6h],dx
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+8h]
	les	di,[bp-8h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	push	0h
	call	far 1AB8h:1C32h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+8h]
	call	far 1AB8h:1AF6h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	les	di,[bp-4h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	les	di,[bp-8h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	word ptr [bp-6h]
	push	word ptr [bp-8h]
	push	word ptr [bp-0Ah]
	call	far 1EDAh:0254h
	mov	ax,[bp+0Ah]
	add	ax,0Bh
	push	ax
	push	word ptr [bp+4h]
	call	far 1AB8h:1E3Ch
	mov	[bp-0Fh],al
	xor	ax,ax
	mov	[bp-0Eh],ax

l0C74_2C80:
	mov	ax,[bp+0Ah]
	add	ax,0Bh
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	2C98h

l0C74_2C95:
	jmp	2E23h

l0C74_2C98:
	mov	ax,[58E6h]
	cwd
	mov	cx,4h
	idiv	cx
	push	ax
	call	far 1E78h:029Ch
	inc	word ptr [bp+8h]
	inc	word ptr [bp+4h]
	inc	word ptr [bp-0Eh]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	les	di,[bp-4h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	word ptr [bp+4h],176h
	jz	2CCCh

l0C74_2CC9:
	jmp	2E20h

l0C74_2CCC:
	cmp	byte ptr [bp-0Fh],0Fh
	jz	2CD5h

l0C74_2CD2:
	jmp	2E20h

l0C74_2CD5:
	mov	byte ptr [bp-12h],0Fh
	jmp	2CDEh

l0C74_2CDB:
	dec	byte ptr [bp-12h]

l0C74_2CDE:
	mov	byte ptr [bp-11h],0h
	jmp	2CE7h

l0C74_2CE4:
	inc	byte ptr [bp-11h]

l0C74_2CE7:
	mov	byte ptr [bp-10h],1h
	jmp	2CF0h

l0C74_2CED:
	inc	byte ptr [bp-10h]

l0C74_2CF0:
	cmp	byte ptr [58B0h],0h
	jz	2D15h

l0C74_2CF7:
	mov	al,[bp-10h]
	xor	ah,ah
	mov	cx,ax
	mov	al,[bp-11h]
	xor	ah,ah
	inc	ax
	mov	dx,ax
	mov	al,[bp-12h]
	xor	ah,ah
	mul	dx
	mul	cx
	push	ax
	call	far 11C8h:0354h

l0C74_2D15:
	push	1h
	call	far 1E78h:029Ch
	mov	al,[bp-10h]
	xor	ah,ah
	cwd
	mov	cx,3h
	div	cx
	xchg	dx,ax
	or	ax,ax
	jnz	2D4Ch

l0C74_2D2C:
	mov	al,[bp-11h]
	xor	ah,ah
	add	ax,[bp+0Ah]
	push	ax
	mov	al,[bp-10h]
	xor	ah,ah
	add	ax,160h
	inc	ax
	push	ax
	mov	al,[bp-12h]
	xor	ah,ah
	push	ax
	call	far 1AB8h:1E54h
	jmp	2D6Dh

l0C74_2D4C:
	mov	al,[bp-11h]
	xor	ah,ah
	add	ax,[bp+0Ah]
	push	ax
	mov	al,[bp-10h]
	xor	ah,ah
	inc	ax
	add	ax,160h
	push	ax
	mov	al,[bp-12h]
	xor	ah,ah
	sub	ax,8h
	push	ax
	call	far 1AB8h:1E54h

l0C74_2D6D:
	mov	al,[bp-10h]
	xor	ah,ah
	cwd
	mov	cx,3h
	div	cx
	xchg	dx,ax
	or	ax,ax
	jnz	2DA4h

l0C74_2D7D:
	mov	al,[bp-11h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[bp+0Ah]
	add	ax,15h
	sub	ax,dx
	push	ax
	mov	al,[bp-10h]
	xor	ah,ah
	add	ax,160h
	inc	ax
	push	ax
	mov	al,[bp-12h]
	xor	ah,ah
	push	ax
	call	far 1AB8h:1E54h
	jmp	2DCCh

l0C74_2DA4:
	mov	al,[bp-11h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[bp+0Ah]
	add	ax,15h
	sub	ax,dx
	push	ax
	mov	al,[bp-10h]
	xor	ah,ah
	inc	ax
	add	ax,160h
	push	ax
	mov	al,[bp-12h]
	xor	ah,ah
	sub	ax,8h
	push	ax
	call	far 1AB8h:1E54h

l0C74_2DCC:
	cmp	byte ptr [bp-10h],15h
	jz	2DD5h

l0C74_2DD2:
	jmp	2CEDh

l0C74_2DD5:
	cmp	byte ptr [bp-11h],0Ah
	jz	2DDEh

l0C74_2DDB:
	jmp	2CE4h

l0C74_2DDE:
	cmp	byte ptr [bp-12h],8h
	jz	2DE7h

l0C74_2DE4:
	jmp	2CDBh

l0C74_2DE7:
	mov	al,[bp-0Fh]
	xor	ah,ah
	push	ax
	call	far 1AB8h:1C32h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+4h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	push	word ptr [bp+0Ah]
	push	161h
	push	word ptr [bp+6h]
	push	161h
	call	far 1AB8h:1AF6h
	call	far 11C8h:033Bh

l0C74_2E20:
	jmp	2C80h

l0C74_2E23:
	push	word ptr [bp-2h]
	push	word ptr [bp-4h]
	push	word ptr [bp-0Ch]
	call	far 1EDAh:0254h
	mov	al,[4D0Ah]
	xor	ah,ah
	cmp	ax,[bp-0Eh]
	jnc	2E56h

l0C74_2E3B:
	cmp	word ptr [bp+4h],172h
	jnc	2E56h

l0C74_2E42:
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	mov	ax,[bp+4h]
	add	ax,16h
	push	ax
	push	cs
	call	076Bh

l0C74_2E56:
	leave
	ret	8h
