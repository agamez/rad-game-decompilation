;; fn0C74_4999: 0C74:4999
;;   Called from:
;;     0C74:52DF (in fn0C74_5258)
fn0C74_4999 proc
	enter	0Ch,0h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0Ch
	call	far 1AB8h:1C32h
	mov	word ptr [bp-4h],0Dh
	inc	word ptr [58B4h]
	mov	byte ptr [bp-1h],1h

l0C74_49BC:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	dec	word ptr [bp-4h]
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-4h],0F1h
	jz	4A49h

l0C74_4A04:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4A49h

l0C74_4A26:
	mov	ax,[bp-4h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	cmp	dx,0h
	jl	4A49h

l0C74_4A3C:
	jle	4A41h

l0C74_4A3E:
	jmp	49BCh

l0C74_4A41:
	cmp	ax,0h
	jbe	4A49h

l0C74_4A46:
	jmp	49BCh

l0C74_4A49:
	cmp	word ptr [bp-4h],0F1h
	jz	4AB7h

l0C74_4A4F:
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-4h]
	inc	ax
	cmp	ax,0Dh
	jg	4AACh

l0C74_4A5F:
	mov	[bp-6h],ax
	jmp	4A67h

l0C74_4A64:
	inc	word ptr [bp-6h]

l0C74_4A67:
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-6h],0Dh
	jnz	4A64h

l0C74_4AAC:
	dec	word ptr [58B4h]
	mov	byte ptr [bp-1h],0h
	jmp	4DA7h

l0C74_4AB7:
	push	1F4h
	call	02D8h
	mov	ax,[58B8h]
	add	ax,12h
	mov	[bp-0Ah],ax
	mov	ax,[58B8h]
	add	ax,14h
	mov	[bp-0Ch],ax

l0C74_4ACF:
	mov	ax,[58B4h]
	sub	ax,0Eh
	push	ax
	push	word ptr [bp-0Ch]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4B36h

l0C74_4AE2:
	cmp	word ptr [bp-0Ch],1DEh
	jnc	4B36h

l0C74_4AE9:
	push	0Ch
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	push	word ptr [bp-0Ch]
	mov	ax,[58B4h]
	sub	ax,0Fh
	push	ax
	push	word ptr [bp-0Ch]
	call	far 1AB8h:1AF6h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	push	word ptr [bp-0Ah]
	mov	ax,[58B4h]
	sub	ax,0Fh
	push	ax
	push	word ptr [bp-0Ah]
	call	far 1AB8h:1AF6h
	push	28h
	call	02D8h
	inc	word ptr [bp-0Ah]
	inc	word ptr [bp-0Ch]
	jmp	4ACFh

l0C74_4B36:
	mov	ax,[58B4h]
	sub	ax,2Dh
	mov	[596Ch],ax
	mov	ax,[58B4h]
	dec	ax
	dec	ax
	mov	[5970h],ax
	cmp	word ptr [596Ch],1h
	jge	4B54h

l0C74_4B4E:
	mov	word ptr [596Ch],1h

l0C74_4B54:
	mov	ax,[bp-0Ch]
	cmp	ax,[58BAh]
	jnc	4B6Bh

l0C74_4B5D:
	mov	ax,[58B8h]
	mov	[596Eh],ax
	mov	ax,[58BAh]
	mov	[5972h],ax
	jmp	4B7Dh

l0C74_4B6B:
	mov	ax,[bp-0Ch]
	sub	ax,16h
	mov	[596Eh],ax
	mov	ax,[bp-0Ch]
	add	ax,15h
	mov	[5972h],ax

l0C74_4B7D:
	cmp	word ptr [5972h],176h
	jle	4B91h

l0C74_4B85:
	mov	word ptr [5972h],176h
	mov	word ptr [596Eh],14Ah

l0C74_4B91:
	push	word ptr [596Ch]
	mov	ax,[5972h]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4BBBh

l0C74_4BA5:
	push	word ptr [596Ch]
	push	word ptr [596Eh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4BBBh

l0C74_4BB6:
	add	word ptr [596Ch],16h

l0C74_4BBB:
	mov	ax,[5970h]
	sub	ax,15h
	push	ax
	push	word ptr [596Eh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4BE8h

l0C74_4BCF:
	mov	ax,[5970h]
	sub	ax,2Bh
	push	ax
	push	word ptr [596Eh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4BE8h

l0C74_4BE3:
	add	word ptr [596Eh],12h

l0C74_4BE8:
	push	0Ch
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[bp-0Ah]
	dec	ax
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Fh
	push	ax
	mov	ax,[bp-0Ah]
	dec	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	sub	ax,0Bh
	push	ax
	mov	ax,[bp-0Ah]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[58B4h]
	sub	ax,0Fh
	push	ax
	mov	ax,[bp-0Ah]
	dec	ax
	dec	ax
	push	ax
	call	far 1AB8h:1AF6h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp-4h]
	inc	ax
	cmp	ax,0Dh
	jg	4C88h

l0C74_4C3B:
	mov	[bp-6h],ax
	jmp	4C43h

l0C74_4C40:
	inc	word ptr [bp-6h]

l0C74_4C43:
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	mov	ax,[bp-6h]
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58B4h]
	xor	dx,dx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	call	far 1AB8h:1AF6h
	push	12Ch
	push	14h
	call	070Dh
	cmp	word ptr [bp-6h],0Dh
	jnz	4C40h

l0C74_4C88:
	dec	word ptr [58B4h]
	xor	ax,ax
	mov	[bp-4h],ax
	mov	word ptr [bp-8h],1h
	mov	word ptr [bp-6h],1h
	jmp	4CA0h

l0C74_4C9D:
	inc	word ptr [bp-6h]

l0C74_4CA0:
	push	12Ch
	push	14h
	call	070Dh
	push	0Ah
	call	02D8h
	inc	word ptr [bp-4h]
	cmp	word ptr [bp-4h],5h
	jnz	4CCBh

l0C74_4CB6:
	mov	word ptr [bp-4h],1h
	cmp	byte ptr [58B0h],0h
	jz	4CC9h

l0C74_4CC2:
	push	32h
	call	far 11C8h:0354h

l0C74_4CC9:
	jmp	4CD0h

l0C74_4CCB:
	call	far 11C8h:033Bh

l0C74_4CD0:
	cmp	word ptr [58B6h],27Fh
	jnc	4CE3h

l0C74_4CD8:
	inc	word ptr [58B4h]
	inc	word ptr [58B6h]
	inc	word ptr [bp-8h]

l0C74_4CE3:
	cmp	word ptr [58B6h],27Fh
	jnc	4D22h

l0C74_4CEB:
	push	word ptr [58B6h]
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4D22h

l0C74_4CFC:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4D22h

l0C74_4D10:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	4D34h

l0C74_4D22:
	dec	word ptr [58B4h]
	dec	word ptr [58B6h]
	dec	word ptr [bp-8h]
	call	far 11C8h:033Bh
	jmp	4D4Fh

l0C74_4D34:
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	di,[bp-4h]
	shl	di,2h
	les	di,[di+58F4h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h

l0C74_4D4F:
	cmp	word ptr [bp-6h],2Ch
	jz	4D58h

l0C74_4D55:
	jmp	4C9Dh

l0C74_4D58:
	cmp	word ptr [bp-8h],16h
	jge	4D93h

l0C74_4D5E:
	mov	ax,[58BAh]
	add	ax,17h
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[5972h]
	cwd
	cmp	dx,bx
	jl	4D78h

l0C74_4D72:
	jg	4D93h

l0C74_4D74:
	cmp	ax,cx
	ja	4D93h

l0C74_4D78:
	push	word ptr [596Ch]
	push	word ptr [596Eh]
	push	word ptr [58B6h]
	push	word ptr [58BAh]
	push	cs
	call	076Bh
	mov	byte ptr [58B3h],1h
	jmp	4DA7h

l0C74_4D93:
	push	word ptr [596Ch]
	push	word ptr [596Eh]
	push	word ptr [5970h]
	push	word ptr [5972h]
	push	cs
	call	076Bh

l0C74_4DA7:
	mov	al,[bp-1h]
	leave
	ret
