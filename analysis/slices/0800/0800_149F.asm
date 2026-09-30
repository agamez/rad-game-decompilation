;; fn0800_149F: 0800:149F
;;   Called from:
;;     0800:4008 (in fn0800_3D9D)
fn0800_149F proc
	enter	10Eh,0h
	call	far 1AB8h:0F80h
	mov	word ptr [bp-2h],2Ah
	mov	word ptr [bp-6h],6Ah
	call	far 1AB8h:10CEh
	sub	ax,2Ah
	mov	[bp-4h],ax
	call	far 1AB8h:10E1h
	sub	ax,6Ah
	mov	[bp-8h],ax
	push	word ptr [bp-2h]
	push	word ptr [bp-6h]
	push	word ptr [bp-4h]
	push	word ptr [bp-8h]
	call	1315h
	mov	ax,[bp-2h]
	add	ax,8h
	mov	[bp-2h],ax
	mov	ax,[bp-6h]
	add	ax,8h
	mov	[bp-6h],ax
	push	0h
	push	1h
	call	far 1AB8h:14F4h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	mov	byte ptr [bp-0Bh],1h
	jmp	1506h

l0800_1503:
	inc	byte ptr [bp-0Bh]

l0800_1506:
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	mov	al,[di+0FF06h]
	mov	[bp-0Dh],al
	mov	al,1h
	cmp	al,[bp-0Dh]
	jbe	1521h

l0800_151E:
	jmp	15F8h

l0800_1521:
	mov	[bp-0Ch],al
	jmp	1529h

l0800_1526:
	inc	byte ptr [bp-0Ch]

l0800_1529:
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-0Ch]
	xor	ah,ah
	shl	ax,3h
	add	ax,[bp-2h]
	dec	ax
	push	ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-6h]
	dec	ax
	push	ax
	lea	di,[bp+0FEF2h]
	push	ss
	push	di
	mov	al,[bp-0Ch]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,dx
	mov	al,[di+0FF06h]
	push	ax
	call	far 1EDAh:0B4Fh
	call	far 1AB8h:1D82h
	mov	al,[bp-0Ch]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,dx
	mov	al,[di+0FF06h]
	push	ax
	mov	di,147Fh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	159Fh

l0800_1596:
	push	0Ah
	call	far 1AB8h:1C32h
	jmp	15A6h

l0800_159F:
	push	0Bh
	call	far 1AB8h:1C32h

l0800_15A6:
	mov	al,[bp-0Ch]
	xor	ah,ah
	shl	ax,3h
	add	ax,[bp-2h]
	push	ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-6h]
	push	ax
	lea	di,[bp+0FEF2h]
	push	ss
	push	di
	mov	al,[bp-0Ch]
	xor	ah,ah
	mov	dx,ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,dx
	mov	al,[di+0FF06h]
	push	ax
	call	far 1EDAh:0B4Fh
	call	far 1AB8h:1D82h
	push	1Eh
	call	far 1E78h:029Ch
	mov	al,[bp-0Ch]
	cmp	al,[bp-0Dh]
	jz	15F8h

l0800_15F5:
	jmp	1526h

l0800_15F8:
	push	1F4h
	call	far 1E78h:029Ch
	cmp	byte ptr [bp-0Bh],12h
	jz	1609h

l0800_1606:
	jmp	1503h

l0800_1609:
	call	far 1E78h:030Dh
	mov	word ptr [bp-0Ah],1h
	jmp	1618h

l0800_1615:
	inc	word ptr [bp-0Ah]

l0800_1618:
	mov	ax,[bp-4h]
	sub	ax,[bp-2h]
	push	ax
	call	far 1EDAh:0D80h
	add	ax,[bp-2h]
	push	ax
	mov	ax,[bp-8h]
	sub	ax,[bp-6h]
	push	ax
	call	far 1EDAh:0D80h
	add	ax,[bp-6h]
	push	ax
	push	0h
	call	far 1AB8h:1E54h
	cmp	word ptr [bp-0Ah],7D00h
	jnz	1615h

l0800_1646:
	call	far 1AB8h:0F80h
	leave
	ret
0800:164D                                        00 00 00              ...
0800:1650 00 00 00 FF 03 FE FF FF 07 00 00 00 00 00 00 00 ................
0800:1660 00 00 00 00 00 00 00 00 00 00 00 00 00          .............
