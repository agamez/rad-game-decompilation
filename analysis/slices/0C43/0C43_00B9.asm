;; fn0C43_00B9: 0C43:00B9
;;   Called from:
;;     0800:433A (in fn0800_4255)
fn0C43_00B9 proc
	enter	0E4h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp-50h]
	push	ss
	push	di
	push	4Fh
	call	far 1EDAh:0A39h
	push	13h
	call	0000h
	lea	di,[bp+0FF2Ch]
	push	ss
	push	di
	lea	di,[bp-50h]
	push	ss
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp+0FF2Ch]
	push	ss
	push	di
	push	1h
	call	far 1EDAh:0FD0h
	call	far 1EDAh:04A2h
	or	ax,ax
	mov	al,0h
	jz	00FCh

l0C43_00FB:
	inc	ax

l0C43_00FC:
	mov	[556Eh],al
	cmp	byte ptr [556Eh],0h
	jz	0109h

l0C43_0106:
	jmp	02F7h

l0C43_0109:
	push	0F1h
	call	far 1EDAh:023Fh
	mov	[5884h],ax
	mov	[5886h],dx
	lea	di,[bp+0FF2Ch]
	push	ss
	push	di
	lea	di,[bp+0FF20h]
	push	ss
	push	di
	push	2h
	xor	ax,ax
	push	ax
	push	ax
	call	far 1EDAh:10BBh
	call	far 1EDAh:04A9h
	cmp	byte ptr [bp+0FF21h],5h
	mov	al,0h
	jnc	013Dh

l0C43_013C:
	inc	ax

l0C43_013D:
	mov	[556Eh],al
	cmp	byte ptr [556Eh],0h
	jz	014Eh

l0C43_0147:
	push	bp
	call	0095h
	jmp	02F7h

l0C43_014E:
	lea	di,[bp+0FF2Ch]
	push	ss
	push	di
	call	far 1EDAh:116Ah
	call	far 1EDAh:04A9h
	sub	ax,301h
	sbb	dx,0h
	mov	[bp+0FF28h],ax
	mov	[bp+0FF2Ah],dx
	lea	di,[bp+0FF2Ch]
	push	ss
	push	di
	push	0h
	push	80h
	call	far 1EDAh:1123h
	call	far 1EDAh:04A9h
	mov	word ptr [bp+0FF24h],80h
	mov	word ptr [bp+0FF26h],0h
	mov	byte ptr [5892h],0h
	xor	ax,ax
	mov	[589Ah],ax

l0C43_0197:
	lea	di,[bp+0FF2Ch]
	push	ss
	push	di
	les	di,[5884h]
	push	es
	push	di
	push	0F1h
	mov	di,5894h
	push	ds
	push	di
	call	far 1EDAh:10BBh
	call	far 1EDAh:04A9h
	mov	ax,[5894h]
	xor	dx,dx
	add	[bp+0FF24h],ax
	adc	[bp+0FF26h],dx
	mov	ax,[bp+0FF24h]
	mov	dx,[bp+0FF26h]
	cmp	dx,[bp+0FF2Ah]
	jg	01D7h

l0C43_01CF:
	jl	01EBh

l0C43_01D1:
	cmp	ax,[bp+0FF28h]
	jbe	01EBh

l0C43_01D7:
	mov	ax,[bp+0FF24h]
	mov	dx,[bp+0FF26h]
	sub	ax,[bp+0FF28h]
	sbb	dx,[bp+0FF2Ah]
	sub	[5894h],ax

l0C43_01EB:
	call	0056h
	lea	di,[bp+0FF2Ch]
	push	ss
	push	di
	call	far 1EDAh:1185h
	call	far 1EDAh:04A9h
	or	al,al
	jnz	021Bh

l0C43_0202:
	mov	ax,[bp+0FF24h]
	mov	dx,[bp+0FF26h]
	cmp	dx,[bp+0FF2Ah]
	jg	021Bh

l0C43_0210:
	jl	0197h

l0C43_0212:
	cmp	ax,[bp+0FF28h]
	jnc	021Bh

l0C43_0218:
	jmp	0197h

l0C43_021B:
	lea	di,[bp+0FF2Ch]
	push	ss
	push	di
	push	word ptr [bp+0FF2Ah]
	push	word ptr [bp+0FF28h]
	call	far 1EDAh:1123h
	call	far 1EDAh:04A9h
	lea	di,[bp+0FF2Ch]
	push	ss
	push	di
	lea	di,[bp+0FF23h]
	push	ss
	push	di
	push	1h
	xor	ax,ax
	push	ax
	push	ax
	call	far 1EDAh:10BBh
	call	far 1EDAh:04A9h
	cmp	byte ptr [bp+0FF23h],0Ch
	mov	al,0h
	jz	0259h

l0C43_0258:
	inc	ax

l0C43_0259:
	mov	[556Eh],al
	cmp	byte ptr [556Eh],0h
	jz	026Ah

l0C43_0263:
	push	bp
	call	0095h
	jmp	02F7h

l0C43_026A:
	lea	di,[bp+0FF2Ch]
	push	ss
	push	di
	mov	di,5582h
	push	ds
	push	di
	push	300h
	xor	ax,ax
	push	ax
	push	ax
	call	far 1EDAh:10BBh
	call	far 1EDAh:04A9h
	mov	byte ptr [bp-51h],0h
	jmp	028Fh

l0C43_028C:
	inc	byte ptr [bp-51h]

l0C43_028F:
	mov	al,[bp-51h]
	xor	ah,ah
	mov	di,ax
	mov	si,di
	shl	di,1h
	add	di,si
	add	di,5582h
	mov	[bp+0FF1Ch],di
	mov	[bp+0FF1Eh],ds
	les	di,[bp+0FF1Ch]
	mov	al,es:[di]
	xor	ah,ah
	shr	ax,2h
	les	di,[bp+0FF1Ch]
	mov	es:[di],al
	les	di,[bp+0FF1Ch]
	mov	al,es:[di+1h]
	xor	ah,ah
	shr	ax,2h
	les	di,[bp+0FF1Ch]
	mov	es:[di+1h],al
	les	di,[bp+0FF1Ch]
	mov	al,es:[di+2h]
	xor	ah,ah
	shr	ax,2h
	les	di,[bp+0FF1Ch]
	mov	es:[di+2h],al
	cmp	byte ptr [bp-51h],0FFh
	jnz	028Ch

l0C43_02EB:
	mov	di,5582h
	push	ds
	push	di
	call	001Eh
	push	bp
	call	0095h

l0C43_02F7:
	leave
	retf	4h
