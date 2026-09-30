;; fn0800_391E: 0800:391E
;;   Called from:
;;     0800:4129 (in fn0800_3D9D)
fn0800_391E proc
	enter	210h,0h
	lea	di,[bp+0FEF0h]
	push	ss
	push	di
	mov	di,38E0h
	push	cs
	push	di
	call	far 1EDAh:04F5h
	lea	di,[bp+0FEF0h]
	push	ss
	push	di
	call	far 1EDAh:0565h
	call	far 1EDAh:04A2h
	or	ax,ax
	jz	3949h

l0800_3946:
	jmp	3BF0h

l0800_3949:
	call	far 1E78h:02FBh
	or	al,al
	jz	3959h

l0800_3952:
	call	far 1E78h:030Dh
	jmp	3949h

l0800_3959:
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
	push	ax
	mov	ax,[bp-6h]
	add	ax,0Ah
	push	ax
	mov	ax,[bp-4h]
	sub	ax,8h
	push	ax
	mov	ax,[bp-8h]
	sub	ax,32h
	push	ax
	call	36E6h
	push	1h
	push	7h
	call	far 1AB8h:1175h
	mov	ax,[bp-2h]
	add	ax,8h
	push	ax
	mov	ax,[bp-6h]
	add	ax,0Dh
	push	ax
	mov	ax,[bp-4h]
	sub	ax,9h
	push	ax
	mov	ax,[bp-8h]
	sub	ax,34h
	push	ax
	call	far 1AB8h:1B3Eh
	mov	ax,[bp-2h]
	add	ax,30h
	mov	[bp-0Ah],ax
	mov	ax,[bp-6h]
	add	ax,0Ch
	mov	[bp-0Ch],ax
	push	1h
	push	0F0h
	push	14Eh
	mov	di,38E8h
	push	cs
	push	di
	push	0h
	call	19E1h
	push	2h
	push	190h
	push	14Eh
	mov	di,38F4h
	push	cs
	push	di
	push	0h
	call	19E1h

l0800_3A06:
	call	far 1206h:0066h
	push	1h
	push	7h
	call	far 1AB8h:1175h
	mov	ax,[bp-2h]
	add	ax,8h
	push	ax
	mov	ax,[bp-6h]
	add	ax,0Dh
	push	ax
	mov	ax,[bp-4h]
	sub	ax,9h
	push	ax
	mov	ax,[bp-8h]
	sub	ax,34h
	push	ax
	call	far 1AB8h:1B3Eh
	mov	al,[4D06h]
	xor	ah,ah
	push	ax
	call	far 1AB8h:1C32h
	push	0h
	push	1h
	call	far 1AB8h:14F4h
	push	2h
	push	0h
	push	4h
	call	far 1AB8h:1536h
	mov	byte ptr [bp-0Fh],1h
	jmp	3A5Dh

l0800_3A5A:
	inc	byte ptr [bp-0Fh]

l0800_3A5D:
	lea	di,[bp+0FEF0h]
	push	ss
	push	di
	lea	di,[bp+0FDF0h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0896h
	call	far 1EDAh:081Ah
	call	far 1EDAh:04A9h
	push	word ptr [bp-0Ah]
	mov	al,[bp-0Fh]
	xor	ah,ah
	imul	ax,ax,0Dh
	add	ax,[bp-0Ch]
	push	ax
	lea	di,[bp+0FDF0h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	cmp	byte ptr [bp-0Fh],14h
	jnz	3A5Ah

l0800_3A9B:
	lea	di,[bp+0FEF0h]
	push	ss
	push	di
	call	far 1EDAh:0918h
	call	far 1EDAh:04A9h
	or	al,al
	jz	3AD3h

l0800_3AAF:
	mov	ax,[53E4h]
	sub	ax,4h
	push	ax
	mov	ax,[53F2h]
	dec	ax
	push	ax
	mov	ax,[5400h]
	add	ax,4h
	push	ax
	mov	ax,[540Eh]
	add	ax,3h
	push	ax
	call	005Ah
	call	far 1206h:0038h
	jmp	3AE5h

l0800_3AD3:
	push	1h
	push	0F0h
	push	14Eh
	mov	di,38E8h
	push	cs
	push	di
	push	0h
	call	19E1h

l0800_3AE5:
	mov	byte ptr [53D2h],0FFh
	call	far 1E78h:02FBh
	or	al,al
	jz	3B26h

l0800_3AF3:
	call	far 1E78h:030Dh
	mov	[53D2h],al
	cmp	byte ptr [53D2h],0h
	jnz	3B0Ah

l0800_3B02:
	call	far 1E78h:030Dh
	mov	[53D2h],al

l0800_3B0A:
	call	far 1E78h:02FBh
	or	al,al
	jz	3B1Ah

l0800_3B13:
	call	far 1E78h:030Dh
	jmp	3B0Ah

l0800_3B1A:
	mov	al,[53D2h]
	push	ax
	call	far 1EDAh:1384h
	mov	[53D2h],al

l0800_3B26:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	3B38h

l0800_3B31:
	push	bp
	call	3850h
	mov	[53D2h],al

l0800_3B38:
	lea	di,[bp+0FEF0h]
	push	ss
	push	di
	call	far 1EDAh:0918h
	call	far 1EDAh:04A9h
	or	al,al
	jz	3B58h

l0800_3B4C:
	cmp	byte ptr [53D2h],53h
	jnz	3B58h

l0800_3B53:
	mov	byte ptr [53D2h],0h

l0800_3B58:
	mov	al,[53D2h]
	push	ax
	mov	di,38FEh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jnz	3B6Bh

l0800_3B68:
	jmp	3AE5h

l0800_3B6B:
	cmp	byte ptr [53D2h],53h
	jnz	3B84h

l0800_3B72:
	push	1h
	push	0F0h
	push	14Eh
	mov	di,38E8h
	push	cs
	push	di
	push	1h
	call	19E1h

l0800_3B84:
	lea	di,[bp+0FEF0h]
	push	ss
	push	di
	call	far 1EDAh:0918h
	call	far 1EDAh:04A9h
	or	al,al
	jnz	3BA2h

l0800_3B98:
	cmp	byte ptr [53D2h],46h
	jz	3BA2h

l0800_3B9F:
	jmp	3A06h

l0800_3BA2:
	push	2h
	push	190h
	push	14Eh
	mov	di,38F4h
	push	cs
	push	di
	push	1h
	call	19E1h
	lea	di,[bp+0FEF0h]
	push	ss
	push	di
	call	far 1EDAh:05BFh
	call	far 1EDAh:04A9h
	call	far 1206h:0066h
	push	96h
	call	far 1E78h:029Ch
	mov	ax,[bp-2h]
	sub	ax,14h
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

l0800_3BF0:
	leave
	ret
