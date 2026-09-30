;; fn0C74_45CE: 0C74:45CE
;;   Called from:
;;     0C74:529D (in fn0C74_5258)
fn0C74_45CE proc
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

l0C74_45F0:
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
	cmp	byte ptr [bp-2h],3Ah
	jz	4650h

l0C74_4628:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4650h

l0C74_4642:
	mov	al,[bp-2h]
	xor	ah,ah
	add	ax,[58B4h]
	cmp	ax,27Eh
	jc	45F0h

l0C74_4650:
	cmp	byte ptr [bp-2h],3Ah
	jz	46AFh

l0C74_4656:
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-2h]
	xor	ah,ah
	dec	ax
	cmp	al,1Dh
	jc	46A4h

l0C74_4667:
	mov	[bp-3h],al
	jmp	466Fh

l0C74_466C:
	dec	byte ptr [bp-3h]

l0C74_466F:
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
	jnz	466Ch

l0C74_46A4:
	inc	word ptr [58B4h]
	mov	byte ptr [bp-1h],0h
	jmp	4994h

l0C74_46AF:
	push	1F4h
	call	02D8h
	mov	ax,[58B8h]
	add	ax,12h
	mov	[bp-6h],ax
	mov	ax,[58B8h]
	add	ax,14h
	mov	[bp-8h],ax

l0C74_46C7:
	mov	ax,[58B4h]
	add	ax,39h
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	472Eh

l0C74_46DA:
	cmp	word ptr [bp-8h],1DEh
	jnc	472Eh

l0C74_46E1:
	push	0Ch
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	push	word ptr [bp-8h]
	mov	ax,[58B4h]
	add	ax,3Ah
	push	ax
	push	word ptr [bp-8h]
	call	far 1AB8h:1AF6h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	push	word ptr [bp-6h]
	mov	ax,[58B4h]
	add	ax,3Ah
	push	ax
	push	word ptr [bp-6h]
	call	far 1AB8h:1AF6h
	push	1Eh
	call	02D8h
	inc	word ptr [bp-6h]
	inc	word ptr [bp-8h]
	jmp	46C7h

l0C74_472E:
	mov	ax,[58B6h]
	inc	ax
	mov	[596Ch],ax
	mov	ax,[58B6h]
	add	ax,2Ch
	mov	[5970h],ax
	cmp	word ptr [5970h],27Eh
	jle	474Ch

l0C74_4746:
	mov	word ptr [5970h],27Eh

l0C74_474C:
	mov	ax,[bp-8h]
	cmp	ax,[58BAh]
	jnc	4763h

l0C74_4755:
	mov	ax,[58B8h]
	mov	[596Eh],ax
	mov	ax,[58BAh]
	mov	[5972h],ax
	jmp	4775h

l0C74_4763:
	mov	ax,[bp-8h]
	sub	ax,16h
	mov	[596Eh],ax
	mov	ax,[bp-8h]
	add	ax,15h
	mov	[5972h],ax

l0C74_4775:
	cmp	word ptr [5972h],176h
	jle	4789h

l0C74_477D:
	mov	word ptr [5972h],176h
	mov	word ptr [596Eh],14Ah

l0C74_4789:
	mov	ax,[5970h]
	sub	ax,15h
	push	ax
	mov	ax,[5972h]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	47BCh

l0C74_47A0:
	mov	ax,[5970h]
	sub	ax,15h
	push	ax
	mov	ax,[5972h]
	sub	ax,2Bh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	47BCh

l0C74_47B7:
	sub	word ptr [5970h],16h

l0C74_47BC:
	mov	ax,[596Ch]
	add	ax,16h
	push	ax
	push	word ptr [596Eh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	47E6h

l0C74_47D0:
	push	word ptr [596Ch]
	push	word ptr [596Eh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	47E6h

l0C74_47E1:
	add	word ptr [596Eh],12h

l0C74_47E6:
	push	0Ch
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	push	ax
	mov	ax,[58B4h]
	add	ax,3Ah
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	add	ax,36h
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[58B4h]
	add	ax,3Ah
	push	ax
	mov	ax,[bp-6h]
	dec	ax
	dec	ax
	push	ax
	call	far 1AB8h:1AF6h
	push	0h
	call	far 1AB8h:1C32h
	mov	al,[bp-2h]
	xor	ah,ah
	dec	ax
	cmp	al,1Dh
	jc	4877h

l0C74_483A:
	mov	[bp-3h],al
	jmp	4842h

l0C74_483F:
	dec	byte ptr [bp-3h]

l0C74_4842:
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
	jnz	483Fh

l0C74_4877:
	inc	word ptr [58B4h]
	mov	byte ptr [bp-2h],5h
	mov	byte ptr [bp-4h],1h
	mov	byte ptr [bp-3h],1h
	jmp	488Ch

l0C74_4889:
	inc	byte ptr [bp-3h]

l0C74_488C:
	push	12Ch
	push	14h
	call	070Dh
	push	0Ah
	call	02D8h
	dec	byte ptr [bp-2h]
	cmp	byte ptr [bp-2h],0h
	jnz	48B6h

l0C74_48A2:
	mov	byte ptr [bp-2h],4h
	cmp	byte ptr [58B0h],0h
	jz	48B4h

l0C74_48AD:
	push	32h
	call	far 11C8h:0354h

l0C74_48B4:
	jmp	48BBh

l0C74_48B6:
	call	far 11C8h:033Bh

l0C74_48BB:
	cmp	word ptr [58B4h],0h
	jbe	48CDh

l0C74_48C2:
	inc	byte ptr [bp-4h]
	dec	word ptr [58B4h]
	dec	word ptr [58B6h]

l0C74_48CD:
	cmp	word ptr [58B6h],0h
	jbe	490Bh

l0C74_48D4:
	push	word ptr [58B4h]
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	490Bh

l0C74_48E5:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	490Bh

l0C74_48F9:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	491Dh

l0C74_490B:
	dec	byte ptr [bp-4h]
	inc	word ptr [58B4h]
	inc	word ptr [58B6h]
	call	far 11C8h:033Bh
	jmp	493Ch

l0C74_491D:
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	al,[bp-2h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+58E4h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h

l0C74_493C:
	cmp	byte ptr [bp-3h],2Ch
	jz	4945h

l0C74_4942:
	jmp	4889h

l0C74_4945:
	cmp	byte ptr [bp-4h],16h
	jnc	4980h

l0C74_494B:
	mov	ax,[58BAh]
	add	ax,17h
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[5972h]
	cwd
	cmp	dx,bx
	jl	4965h

l0C74_495F:
	jg	4980h

l0C74_4961:
	cmp	ax,cx
	ja	4980h

l0C74_4965:
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	push	word ptr [5970h]
	push	word ptr [5972h]
	push	cs
	call	076Bh
	mov	byte ptr [58B3h],1h
	jmp	4994h

l0C74_4980:
	push	word ptr [596Ch]
	push	word ptr [596Eh]
	push	word ptr [5970h]
	push	word ptr [5972h]
	push	cs
	call	076Bh

l0C74_4994:
	mov	al,[bp-1h]
	leave
	ret
