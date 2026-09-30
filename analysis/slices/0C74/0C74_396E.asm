;; fn0C74_396E: 0C74:396E
;;   Called from:
;;     0C74:5291 (in fn0C74_5258)
fn0C74_396E proc
	enter	8h,0h
	mov	byte ptr [bp-1h],1h
	dec	word ptr [58B4h]
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0Ch
	call	far 1AB8h:1C32h
	mov	byte ptr [bp-2h],1Dh

l0C74_3990:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	inc	byte ptr [bp-2h]
	push	12Ch
	push	14h
	call	070Dh
	cmp	byte ptr [bp-2h],39h
	jz	39F0h

l0C74_39C8:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	39F0h

l0C74_39E2:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	cmp	ax,27Eh
	jc	3990h

l0C74_39F0:
	cmp	byte ptr [bp-2h],39h
	jz	3A4Fh

l0C74_39F6:
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-2h]
	xor	ah,ah
	dec	ax
	cmp	al,1Dh
	jc	3A44h

l0C74_3A07:
	mov	[bp-3h],al
	jmp	3A0Fh

l0C74_3A0C:
	dec	byte ptr [bp-3h]

l0C74_3A0F:
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
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	byte ptr [bp-3h],1Dh
	jnz	3A0Ch

l0C74_3A44:
	inc	word ptr [58B4h]
	mov	byte ptr [bp-1h],0h
	jmp	3F6Fh

l0C74_3A4F:
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,2Ah
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	mov	ax,[58B4h]
	add	ax,2Ah
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	mov	byte ptr [bp-3h],3h
	jmp	3AB1h

l0C74_3AAE:
	inc	byte ptr [bp-3h]

l0C74_3AB1:
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D0Fh]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D23h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D37h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D4Bh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D0Fh]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D23h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D37h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D4Bh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D0Fh]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D23h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D37h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D4Bh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	190h
	push	32h
	call	070Dh
	cmp	byte ptr [bp-3h],14h
	jz	3BC3h

l0C74_3BC0:
	jmp	3AAEh

l0C74_3BC3:
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	push	0h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	mov	ax,[58B8h]
	add	ax,6h
	push	ax
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	mov	ax,[58B8h]
	add	ax,10h
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[58B8h]
	add	ax,6h
	mov	[bp-6h],ax
	mov	ax,[58B8h]
	add	ax,14h
	mov	[bp-8h],ax
	mov	byte ptr [bp-3h],1h
	jmp	3C14h

l0C74_3C11:
	inc	byte ptr [bp-3h]

l0C74_3C14:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	push	word ptr [bp-6h]
	mov	ax,[58B4h]
	add	ax,38h
	push	ax
	push	word ptr [bp-6h]
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	push	word ptr [bp-8h]
	mov	ax,[58B4h]
	add	ax,38h
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	push	word ptr [bp-8h]
	push	0h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,39h
	push	ax
	push	word ptr [bp-8h]
	push	0h
	call	far 1AB8h:1E54h
	inc	word ptr [bp-6h]
	inc	word ptr [bp-8h]
	push	64h
	push	64h
	call	070Dh
	cmp	byte ptr [bp-3h],0Bh
	jnz	3C11h

l0C74_3C89:
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	push	word ptr [bp-8h]
	mov	ax,[58B4h]
	add	ax,38h
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	push	word ptr [bp-8h]
	push	0h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,39h
	push	ax
	push	word ptr [bp-8h]
	push	0h
	call	far 1AB8h:1E54h
	push	1F4h
	call	02D8h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	push	word ptr [bp-8h]
	mov	ax,[58B4h]
	add	ax,38h
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1AF6h
	mov	ax,[58B8h]
	add	ax,10h
	mov	[bp-6h],ax
	mov	ax,[58B8h]
	add	ax,1Eh
	mov	[bp-8h],ax
	mov	byte ptr [bp-3h],1h
	jmp	3D0Ch

l0C74_3D09:
	inc	byte ptr [bp-3h]

l0C74_3D0C:
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	push	word ptr [bp-6h]
	mov	ax,[58B4h]
	add	ax,38h
	push	ax
	push	word ptr [bp-6h]
	call	far 1AB8h:1AF6h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	push	word ptr [bp-8h]
	mov	ax,[58B4h]
	add	ax,38h
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1AF6h
	dec	word ptr [bp-6h]
	dec	word ptr [bp-8h]
	push	64h
	push	64h
	call	070Dh
	cmp	byte ptr [bp-3h],0Bh
	jnz	3D09h

l0C74_3D5F:
	mov	byte ptr [bp-3h],14h
	jmp	3D68h

l0C74_3D65:
	dec	byte ptr [bp-3h]

l0C74_3D68:
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D0Fh]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D23h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D37h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+4D4Bh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D0Fh]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D23h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D37h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	dec	ax
	mov	di,ax
	mov	al,[di+4D4Bh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D0Fh]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D23h]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D37h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	al,[bp-3h]
	xor	ah,ah
	dec	ax
	mov	di,ax
	mov	al,[di+4D4Bh]
	xor	ah,ah
	add	ax,[58B8h]
	push	ax
	call	far 1AB8h:1AF6h
	push	190h
	push	32h
	call	070Dh
	cmp	byte ptr [bp-3h],3h
	jz	3E7Ah

l0C74_3E77:
	jmp	3D65h

l0C74_3E7A:
	mov	ax,[58B4h]
	add	ax,37h
	push	ax
	mov	ax,[58B8h]
	add	ax,10h
	push	ax
	push	0h
	call	far 1AB8h:1E54h
	push	0Ah
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,2Ah
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	call	far 1AB8h:1AF6h
	push	1F4h
	call	02D8h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,2Ah
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[58B8h]
	add	ax,11h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	push	0Ch
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,2Ah
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-2h]
	xor	ah,ah
	dec	ax
	cmp	al,1Dh
	jc	3F6Bh

l0C74_3F2E:
	mov	[bp-3h],al
	jmp	3F36h

l0C74_3F33:
	dec	byte ptr [bp-3h]

l0C74_3F36:
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
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	byte ptr [bp-3h],1Dh
	jnz	3F33h

l0C74_3F6B:
	inc	word ptr [58B4h]

l0C74_3F6F:
	mov	al,[bp-1h]
	leave
	ret
