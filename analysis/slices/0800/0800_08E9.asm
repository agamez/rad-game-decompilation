;; fn0800_08E9: 0800:08E9
;;   Called from:
;;     0800:0D00 (in fn0800_0C71)
fn0800_08E9 proc
	enter	4h,0h
	mov	byte ptr [bp-2h],0h
	jmp	08F6h

l0800_08F3:
	inc	byte ptr [bp-2h]

l0800_08F6:
	mov	byte ptr [bp-1h],0h
	jmp	08FFh

l0800_08FC:
	inc	byte ptr [bp-1h]

l0800_08FF:
	call	far 1E78h:02FBh
	or	al,al
	jz	091Dh

l0800_0908:
	call	far 1E78h:030Dh
	mov	[bp-3h],al
	cmp	byte ptr [bp-3h],1Bh
	jnz	091Dh

l0800_0916:
	mov	byte ptr [58B3h],1h
	jmp	0980h

l0800_091D:
	mov	al,[bp-1h]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	al,[bp-2h]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	cmp	ax,0Fh
	jnz	096Ch

l0800_093B:
	mov	al,[bp-1h]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	al,[bp-2h]
	xor	ah,ah
	imul	ax,ax,16h
	inc	ax
	push	ax
	mov	al,[bp-1h]
	xor	ah,ah
	imul	ax,ax,16h
	add	ax,16h
	push	ax
	mov	al,[bp-2h]
	xor	ah,ah
	imul	ax,ax,16h
	add	ax,16h
	push	ax
	call	far 0C74h:076Bh

l0800_096C:
	cmp	byte ptr [bp-1h],1Dh
	jnz	08FCh

l0800_0972:
	cmp	byte ptr [bp-2h],11h
	jz	097Bh

l0800_0978:
	jmp	08F3h

l0800_097B:
	call	far 0C74h:0A35h

l0800_0980:
	leave
	ret
0800:0982       EA 00 00 00 00 00 00 00 00 00 00 00 00 00   ..............
0800:0990 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0800:09A0 00 00 00 E2 01 00 00 00 00 00 00 00 00 00 00 00 ................
0800:09B0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0800:09C0 00 00                                           ..
