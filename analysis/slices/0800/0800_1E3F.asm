;; fn0800_1E3F: 0800:1E3F
;;   Called from:
;;     0800:2150 (in fn0800_2004)
fn0800_1E3F proc
	enter	0Ch,0h

l0800_1E43:
	call	far 1E78h:02FBh
	or	al,al
	jz	1E53h

l0800_1E4C:
	call	far 1E78h:030Dh
	jmp	1E43h

l0800_1E53:
	mov	word ptr [bp-2h],2Ah
	mov	word ptr [bp-6h],14h
	call	far 1AB8h:10CEh
	sub	ax,2Ah
	mov	[bp-4h],ax
	mov	word ptr [bp-8h],16Ah
	call	far 1206h:0066h
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
	jmp	1EB0h

l0800_1EAD:
	inc	byte ptr [bp-0Bh]

l0800_1EB0:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-2h]
	dec	ax
	push	ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-6h]
	dec	ax
	push	ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,2306h
	push	ds
	push	di
	call	far 1AB8h:1D82h
	mov	al,[bp-0Bh]
	push	ax
	mov	di,1DE0h
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	1EF7h

l0800_1EEE:
	push	0Ah
	call	far 1AB8h:1C32h
	jmp	1EFEh

l0800_1EF7:
	push	0Bh
	call	far 1AB8h:1C32h

l0800_1EFE:
	push	word ptr [bp-2h]
	mov	al,[bp-0Bh]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-6h]
	push	ax
	mov	al,[bp-0Bh]
	xor	ah,ah
	mov	di,ax
	shl	di,8h
	add	di,2306h
	push	ds
	push	di
	call	far 1AB8h:1D82h
	cmp	byte ptr [bp-0Bh],14h
	jnz	1EADh

l0800_1F28:
	push	5h
	push	140h
	push	14Ah
	mov	di,1E00h
	push	cs
	push	di
	push	0h
	call	19E1h

l0800_1F3A:
	call	far 1E78h:02FBh
	or	al,al
	jnz	1F4Eh

l0800_1F43:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	1F3Ah

l0800_1F4E:
	call	far 1E78h:02FBh
	or	al,al
	jz	1F75h

l0800_1F57:
	call	far 1E78h:030Dh
	push	ax
	mov	di,1E1Fh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	1F75h

l0800_1F69:
	cmp	byte ptr [53D8h],0h
	jz	1F75h

l0800_1F70:
	mov	byte ptr [0002h],0FFh

l0800_1F75:
	push	5h
	push	140h
	push	14Ah
	mov	di,1E00h
	push	cs
	push	di
	push	1h
	call	19E1h
	call	far 1206h:0066h
	push	96h
	call	far 1E78h:029Ch
	mov	ax,[bp-2h]
	sub	ax,0Ch
	push	ax
	mov	ax,[bp-6h]
	sub	ax,0Ch
	push	ax
	mov	ax,[bp-4h]
	add	ax,4h
	push	ax
	mov	ax,[bp-8h]
	add	ax,4h
	push	ax
	call	0024h
	leave
	ret
0800:1FB5                12 90 03 00 00 00 00 00 00 00 00      ...........
0800:1FC0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0800:1FD0 00 00 00 00 00 0E 20 20 20 53 55 49 54 45 2E 2E ......   SUITE..
0800:1FE0 2E 20 20 20 00 00 00 00 00 00 00 00 00 20 00 00 .   ......... ..
0800:1FF0 00 20 00 00 00 00 00 00 00 00 00 00 00 00 00 00 . ..............
0800:2000 00 00 00 00                                     ....
