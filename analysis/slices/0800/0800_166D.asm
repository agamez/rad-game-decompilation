;; fn0800_166D: 0800:166D
;;   Called from:
;;     0800:2B19 (in fn0800_2827)
;;     0800:30E8 (in fn0800_2C0C)
fn0800_166D proc
	enter	10Eh,0h
	call	far 1AB8h:0F80h
	call	far 13E2h:0080h

l0800_167B:
	call	far 1E78h:02FBh
	or	al,al
	jz	168Bh

l0800_1684:
	call	far 1E78h:030Dh
	jmp	167Bh

l0800_168B:
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
	jmp	16E9h

l0800_16E6:
	inc	byte ptr [bp-0Bh]

l0800_16E9:
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	mov	al,[di+1106h]
	mov	[bp-0Dh],al
	mov	al,1h
	cmp	al,[bp-0Dh]
	jbe	1704h

l0800_1701:
	jmp	17DBh

l0800_1704:
	mov	[bp-0Ch],al
	jmp	170Ch

l0800_1709:
	inc	byte ptr [bp-0Ch]

l0800_170C:
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
	mov	al,[di+1106h]
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
	mov	al,[di+1106h]
	push	ax
	mov	di,164Dh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	1782h

l0800_1779:
	push	0Ah
	call	far 1AB8h:1C32h
	jmp	1789h

l0800_1782:
	push	0Bh
	call	far 1AB8h:1C32h

l0800_1789:
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
	mov	al,[di+1106h]
	push	ax
	call	far 1EDAh:0B4Fh
	call	far 1AB8h:1D82h
	push	1Eh
	call	far 1E78h:029Ch
	mov	al,[bp-0Ch]
	cmp	al,[bp-0Dh]
	jz	17DBh

l0800_17D8:
	jmp	1709h

l0800_17DB:
	push	1F4h
	call	far 1E78h:029Ch
	cmp	byte ptr [bp-0Bh],12h
	jz	17ECh

l0800_17E9:
	jmp	16E6h

l0800_17EC:
	call	far 1E78h:030Dh
	mov	word ptr [bp-0Ah],1h
	jmp	17FBh

l0800_17F8:
	inc	word ptr [bp-0Ah]

l0800_17FB:
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
	jnz	17F8h

l0800_1829:
	call	far 1AB8h:0F80h
	leave
	ret
0800:1830 07 46 4C 45 43 48 45 53 06 45 53 50 41 43 45 02 .FLECHES.ESPACE.
0800:1840 46 31 02 46 32 02 46 33 03 45 53 43             F1.F2.F3.ESC
