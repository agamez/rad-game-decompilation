;; fn0800_3850: 0800:3850
;;   Called from:
;;     0800:3B32 (in fn0800_391E)
fn0800_3850 proc
	enter	0Ah,0h

l0800_3854:
	lea	di,[bp-4h]
	push	ss
	push	di
	lea	di,[bp-6h]
	push	ss
	push	di
	lea	di,[bp-8h]
	push	ss
	push	di
	call	far 1206h:0094h
	cmp	word ptr [bp-4h],0h
	jnz	3854h

l0800_386E:
	mov	byte ptr [bp-1h],0h
	mov	byte ptr [bp-9h],1h
	jmp	387Bh

l0800_3878:
	inc	byte ptr [bp-9h]

l0800_387B:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+53E2h]
	cmp	ax,[bp-6h]
	jge	38D3h

l0800_388D:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+53FEh]
	cmp	ax,[bp-6h]
	jle	38D3h

l0800_389F:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+53F0h]
	cmp	ax,[bp-8h]
	jge	38D3h

l0800_38B1:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+540Ch]
	cmp	ax,[bp-8h]
	jle	38D3h

l0800_38C3:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D07h]
	mov	[bp-1h],al
	jmp	38D9h

l0800_38D3:
	cmp	byte ptr [bp-9h],2h
	jnz	3878h

l0800_38D9:
	mov	al,[bp-1h]
	leave
	ret	2h
0800:38E0 07 52 41 44 2E 44 4F 43 0B 20 53 20 3A 20 53 55 .RAD.DOC. S : SU
0800:38F0 49 54 45 20 09 20 46 20 3A 20 46 49 4E 20 00 00 ITE . F : FIN ..
0800:3900 00 00 00 00 00 00 40 00 08 00 00 00 00 00 00 00 ......@.........
0800:3910 00 00 00 00 00 00 00 00 00 00 00 00 00 00       ..............
