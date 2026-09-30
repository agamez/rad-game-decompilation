;; fn0C74_4FD7: 0C74:4FD7
;;   Called from:
;;     0C74:5461 (in fn0C74_542B)
fn0C74_4FD7 proc
	enter	0Ah,0h
	mov	byte ptr [bp-1h],1h
	mov	byte ptr [bp-2h],1Dh

l0C74_4FE3:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	push	0Ah
	call	far 1AB8h:1E54h
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	push	2h
	call	far 1AB8h:1E54h
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	push	8h
	call	far 1AB8h:1E54h
	inc	byte ptr [bp-2h]
	push	12Ch
	push	14h
	call	070Dh
	cmp	byte ptr [bp-2h],42h
	jz	5067h

l0C74_503C:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	5067h

l0C74_5056:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	cmp	ax,27Eh
	jnc	5067h

l0C74_5064:
	jmp	4FE3h

l0C74_5067:
	cmp	byte ptr [bp-2h],42h
	jz	50C2h

l0C74_506D:
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-2h]
	xor	ah,ah
	dec	ax
	cmp	al,1Dh
	jc	50BBh

l0C74_507E:
	mov	[bp-3h],al
	jmp	5086h

l0C74_5083:
	dec	byte ptr [bp-3h]

l0C74_5086:
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	byte ptr [bp-3h],1Dh
	jnz	5083h

l0C74_50BB:
	mov	byte ptr [bp-1h],0h
	jmp	51A5h

l0C74_50C2:
	push	1F4h
	call	02D8h
	mov	ax,[58B4h]
	add	ax,2Ch
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	add	ax,41h
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-6h],ax
	push	word ptr [bp-6h]
	call	far 1EDAh:023Fh
	mov	[bp-0Ah],ax
	mov	[bp-8h],dx
	mov	ax,[58B4h]
	add	ax,2Ch
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	add	ax,41h
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	les	di,[bp-0Ah]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	byte ptr [bp-2h],12h
	jmp	5129h

l0C74_5126:
	inc	byte ptr [bp-2h]

l0C74_5129:
	mov	ax,[58B4h]
	add	ax,2Ch
	push	ax
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	les	di,[bp-0Ah]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	12Ch
	push	14h
	call	070Dh
	push	28h
	call	02D8h
	cmp	byte ptr [bp-2h],2Bh
	jnz	5126h

l0C74_5159:
	push	word ptr [bp-8h]
	push	word ptr [bp-0Ah]
	push	word ptr [bp-6h]
	call	far 1EDAh:0254h
	mov	byte ptr [bp-3h],2Ch
	jmp	5170h

l0C74_516D:
	dec	byte ptr [bp-3h]

l0C74_5170:
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	byte ptr [bp-3h],1Dh
	jnz	516Dh

l0C74_51A5:
	mov	al,[bp-1h]
	leave
	ret
