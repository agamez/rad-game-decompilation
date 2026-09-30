;; fn0800_1D55: 0800:1D55
;;   Called from:
;;     0800:3ED9 (in fn0800_3D9D)
fn0800_1D55 proc
	enter	0Ah,0h

l0800_1D59:
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
	jnz	1D59h

l0800_1D73:
	mov	byte ptr [bp-1h],0h
	mov	byte ptr [bp-9h],1h
	jmp	1D80h

l0800_1D7D:
	inc	byte ptr [bp-9h]

l0800_1D80:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+53E2h]
	cmp	ax,[bp-6h]
	jge	1DD5h

l0800_1D92:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+53FEh]
	cmp	ax,[bp-6h]
	jle	1DD5h

l0800_1DA4:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+53F0h]
	cmp	ax,[bp-8h]
	jge	1DD5h

l0800_1DB6:
	mov	al,[bp-9h]
	xor	ah,ah
	mov	di,ax
	shl	di,1h
	mov	ax,[di+540Ch]
	cmp	ax,[bp-8h]
	jle	1DD5h

l0800_1DC8:
	mov	al,[bp-9h]
	xor	ah,ah
	add	ax,3Ah
	mov	[bp-1h],al
	jmp	1DDBh

l0800_1DD5:
	cmp	byte ptr [bp-9h],7h
	jnz	1D7Dh

l0800_1DDB:
	mov	al,[bp-1h]
	leave
	ret
0800:1DE0 02 C0 18 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0800:1DF0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0800:1E00 1E 20 20 20 20 20 20 50 52 45 53 53 45 5A 20 55 .      PRESSEZ U
0800:1E10 4E 45 20 54 4F 55 43 48 45 20 20 20 20 20 20 00 NE TOUCHE      .
0800:1E20 00 00 00 00 00 00 00 80 00 00 00 80 00 00 00 00 ................
0800:1E30 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00    ...............
