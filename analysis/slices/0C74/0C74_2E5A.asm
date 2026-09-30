;; fn0C74_2E5A: 0C74:2E5A
;;   Called from:
;;     0C74:5249 (in fn0C74_522C)
fn0C74_2E5A proc
	enter	1Eh,0h
	mov	byte ptr [bp-1h],0h
	cmp	word ptr [58B4h],1h
	ja	2E6Ch

l0C74_2E69:
	jmp	3231h

l0C74_2E6C:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	2ED2h

l0C74_2E7E:
	mov	ax,[58B4h]
	sub	ax,9h
	push	ax
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	2ED2h

l0C74_2E95:
	mov	ax,[58B4h]
	sub	ax,17h
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	2ED2h

l0C74_2EA9:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	push	word ptr [58B8h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	2ED2h

l0C74_2EBB:
	mov	ax,[58B4h]
	sub	ax,17h
	push	ax
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	2ED5h

l0C74_2ED2:
	jmp	3231h

l0C74_2ED5:
	mov	byte ptr [bp-1h],1h
	mov	ax,[58B4h]
	sub	ax,16h
	push	ax
	mov	ax,[58B8h]
	add	ax,15h
	push	ax
	push	word ptr [58B4h]
	push	word ptr [58BAh]
	call	far 1AB8h:13A3h
	mov	[bp-10h],ax
	push	word ptr [bp-10h]
	call	far 1EDAh:023Fh
	mov	[bp-0Eh],ax
	mov	[bp-0Ch],dx
	mov	ax,[58B4h]
	sub	ax,16h
	push	ax
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	push	word ptr [58B4h]
	push	word ptr [58BAh]
	les	di,[bp-0Eh]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[58B4h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-12h],ax
	push	word ptr [bp-12h]
	call	far 1EDAh:023Fh
	mov	[bp-1Eh],ax
	mov	[bp-1Ch],dx
	mov	ax,[58B4h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-1Eh]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[58B4h]
	add	ax,0Dh
	mov	[bp-0Ah],ax
	dec	word ptr [bp-0Ah]
	push	word ptr [bp-0Ah]
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Eh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	push	0Bh
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	push	3h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	push	9h
	call	far 1AB8h:1E54h
	push	word ptr [bp-1Ch]
	push	word ptr [bp-1Eh]
	push	word ptr [bp-12h]
	call	far 1EDAh:0254h
	mov	ax,[58B4h]
	add	ax,0Ch
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-12h],ax
	push	word ptr [bp-12h]
	call	far 1EDAh:023Fh
	mov	[bp-1Eh],ax
	mov	[bp-1Ch],dx
	mov	ax,[58B4h]
	add	ax,0Ch
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,11h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-1Eh]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	byte ptr [bp-2h],1h

l0C74_307B:
	cmp	byte ptr [bp-2h],14h
	jnc	30D1h

l0C74_3081:
	mov	al,[bp-2h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,0Ch
	sub	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	30D1h

l0C74_30A1:
	push	0E6h
	push	0Ah
	call	070Dh
	mov	al,[bp-2h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Eh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	inc	byte ptr [bp-2h]
	jmp	307Bh

l0C74_30D1:
	mov	al,[bp-2h]
	xor	ah,ah
	mov	[bp-8h],ax
	mov	ax,[58B4h]
	sub	ax,16h
	mov	[bp-14h],ax
	mov	ax,[58B4h]
	dec	ax
	mov	[bp-16h],ax
	mov	ax,[58B8h]
	add	ax,15h
	mov	[bp-18h],ax
	mov	ax,[58BAh]
	mov	[bp-1Ah],ax
	mov	byte ptr [bp-3h],1h
	jmp	3101h

l0C74_30FE:
	inc	byte ptr [bp-3h]

l0C74_3101:
	dec	word ptr [bp-14h]
	dec	word ptr [bp-16h]
	push	word ptr [bp-14h]
	mov	ax,[bp-18h]
	inc	ax
	push	ax
	les	di,[bp-0Eh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	ax,[bp-16h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Eh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	0E6h
	push	14h
	call	070Dh
	cmp	byte ptr [bp-3h],16h
	jnz	30FEh

l0C74_3142:
	push	word ptr [bp-16h]
	mov	ax,[bp-1Ah]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	3162h

l0C74_3153:
	push	word ptr [bp-14h]
	push	word ptr [bp-18h]
	push	word ptr [bp-16h]
	push	word ptr [bp-1Ah]
	call	2BBDh

l0C74_3162:
	mov	ax,[bp-8h]
	add	ax,16h
	or	al,al
	jc	31A5h

l0C74_316C:
	mov	[bp-3h],al
	jmp	3174h

l0C74_3171:
	dec	byte ptr [bp-3h]

l0C74_3174:
	push	0E6h
	push	5h
	call	070Dh
	mov	al,[bp-3h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,0Dh
	sub	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Eh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	byte ptr [bp-3h],0h
	jnz	3171h

l0C74_31A5:
	push	word ptr [bp-1Ch]
	push	word ptr [bp-1Eh]
	push	word ptr [bp-12h]
	call	far 1EDAh:0254h
	mov	byte ptr [bp-2h],5h
	mov	byte ptr [bp-3h],1h
	jmp	31C0h

l0C74_31BD:
	inc	byte ptr [bp-3h]

l0C74_31C0:
	mov	ax,[58E6h]
	cwd
	mov	cx,2h
	idiv	cx
	push	ax
	call	far 1E78h:029Ch
	push	0Ah
	call	02D8h
	dec	byte ptr [bp-2h]
	cmp	byte ptr [bp-2h],0h
	jnz	31F1h

l0C74_31DD:
	mov	byte ptr [bp-2h],4h
	cmp	byte ptr [58B0h],0h
	jz	31EFh

l0C74_31E8:
	push	32h
	call	far 11C8h:0354h

l0C74_31EF:
	jmp	31F6h

l0C74_31F1:
	call	far 11C8h:033Bh

l0C74_31F6:
	dec	word ptr [58B4h]
	dec	word ptr [58B6h]
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	al,[bp-2h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+58F4h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	byte ptr [bp-3h],16h
	jnz	31BDh

l0C74_3223:
	push	word ptr [bp-0Ch]
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	call	far 1EDAh:0254h

l0C74_3231:
	mov	al,[bp-1h]
	leave
	ret
