;; fn1AB8_097B: 1AB8:097B
;;   Called from:
;;     1AB8:0D5B (in fn1AB8_0BAE)
fn1AB8_097B proc
	push	bp
	mov	bp,sp
	sub	sp,20Eh
	les	di,[bp+4h]
	push	es
	push	di
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	mov	ax,0FFh
	push	ax
	call	far 1EDAh:0A39h
	mov	byte ptr [bp-1h],0h
	lea	di,[bp+0FDF2h]
	push	ss
	push	di
	mov	ax,1Ah
	mul	word ptr [bp+8h]
	mov	di,ax
	add	di,50FCh
	push	ds
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,976h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	mov	di,0B756h
	push	ds
	push	di
	mov	ax,0Ch
	push	ax
	call	far 1EDAh:0A39h
	mov	ax,1Ah
	mul	word ptr [bp+8h]
	mov	di,ax
	mov	ax,[di+5112h]
	or	ax,[di+5114h]
	jz	0A08h

l1AB8_09DD:
	mov	ax,1Ah
	mul	word ptr [bp+8h]
	mov	di,ax
	mov	ax,[di+5112h]
	mov	dx,[di+5114h]
	mov	[0B832h],ax
	mov	[0B834h],dx
	xor	ax,ax
	mov	[0B828h],ax
	mov	[0B82Ah],ax
	xor	ax,ax
	mov	[0B82Ch],ax
	mov	byte ptr [bp-1h],1h
	jmp	0AE5h

l1AB8_0A08:
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	mov	di,0B756h
	push	ds
	push	di
	mov	di,0B82Ch
	push	ds
	push	di
	mov	ax,0FFFCh
	push	ax
	call	0887h
	or	al,al
	jnz	0A26h

l1AB8_0A23:
	jmp	0AE5h

l1AB8_0A26:
	mov	ax,[536Eh]
	mov	dx,[5370h]
	mov	[0B7BCh],ax
	mov	[0B7BEh],dx
	mov	ax,50Bh
	mov	dx,1AB8h
	mov	[536Eh],ax
	mov	[5370h],dx
	mov	di,0B828h
	push	ds
	push	di
	push	word ptr [0B82Ch]
	call	dword ptr [0B6C2h]
	mov	ax,[0B7BCh]
	mov	dx,[0B7BEh]
	mov	[536Eh],ax
	mov	[5370h],dx
	mov	ax,[0B828h]
	or	ax,[0B82Ah]
	jnz	0A6Dh

l1AB8_0A65:
	mov	word ptr [0B818h],0FFFBh
	jmp	0AE5h

l1AB8_0A6D:
	mov	di,0B6CAh
	push	ds
	push	di
	les	di,[0B828h]
	push	es
	push	di
	push	word ptr [0B82Ch]
	lea	di,[bp+0FEF6h]
	push	ss
	push	di
	call	far 1EDAh:10BBh
	mov	di,0B6CAh
	push	ds
	push	di
	call	far 1EDAh:1051h
	call	far 1EDAh:04A2h
	or	ax,ax
	jnz	0AB5h

l1AB8_0A9A:
	mov	ax,[bp+0FEF6h]
	cmp	ax,[0B82Ch]
	jnz	0AB5h

l1AB8_0AA4:
	push	word ptr [0B82Ah]
	push	word ptr [0B828h]
	push	cs
	call	05D3h
	cmp	ax,[bp+8h]
	jz	0ACAh

l1AB8_0AB5:
	mov	word ptr [0B818h],0FFFCh
	mov	di,0B828h
	push	ds
	push	di
	push	word ptr [0B82Ch]
	call	dword ptr [0B6C6h]
	jmp	0AE5h

l1AB8_0ACA:
	mov	ax,1Ah
	mul	word ptr [bp+8h]
	mov	di,ax
	mov	ax,[di+5112h]
	mov	dx,[di+5114h]
	mov	[0B832h],ax
	mov	[0B834h],dx
	mov	byte ptr [bp-1h],1h

l1AB8_0AE5:
	mov	al,[bp-1h]
	mov	sp,bp
	pop	bp
	ret	6h
