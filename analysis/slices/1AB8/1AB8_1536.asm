;; fn1AB8_1536: 1AB8:1536
;;   Called from:
;;     0800:04FC (in fn0800_04E3)
;;     0800:0632 (in fn0800_0619)
;;     0800:0772 (in fn0800_0768)
;;     0800:0E06 (in fn0800_0D20)
;;     0800:14F8 (in fn0800_149F)
;;     0800:16DB (in fn0800_166D)
;;     0800:18C0 (in fn0800_184C)
;;     0800:1A03 (in fn0800_19E1)
;;     0800:1EA2 (in fn0800_1E3F)
;;     0800:2051 (in fn0800_2004)
;;     0800:21F1 (in fn0800_21E7)
;;     0800:2230 (in fn0800_21E7)
;;     0800:24B2 (in fn0800_2401)
;;     0800:25B8 (in fn0800_2401)
;;     0800:28D9 (in fn0800_2827)
;;     0800:2D31 (in fn0800_2C0C)
;;     0800:2F5F (in fn0800_2C0C)
;;     0800:3293 (in fn0800_31B7)
;;     0800:33BD (in fn0800_31B7)
;;     0800:3A4F (in fn0800_391E)
;;     0800:3DCF (in fn0800_3D9D)
;;     0800:43B0 (in fn0800_4255)
;;     1229:00C2 (in fn1229_0040)
;;     1229:0B7F (in fn1229_0AA8)
;;     133F:0173 (in fn133F_014B)
;;     1AB8:0B88 (in fn1AB8_0AEE)
fn1AB8_1536 proc
	push	bp
	mov	bp,sp
	sub	sp,10Ah
	cmp	word ptr [bp+0Ah],14h
	ja	155Eh

l1AB8_1543:
	cmp	word ptr [bp+0Ah],0h
	jc	155Eh

l1AB8_1549:
	cmp	word ptr [bp+0Ah],0h
	jz	1571h

l1AB8_154F:
	mov	ax,0Fh
	mul	word ptr [bp+0Ah]
	mov	di,ax
	cmp	byte ptr [di+5215h],0h
	jnz	1571h

l1AB8_155E:
	mov	word ptr [0B818h],0FFF2h
	xor	ax,ax
	mov	[bp+0Ah],ax
	mov	word ptr [bp+6h],1h
	jmp	175Eh

l1AB8_1571:
	cmp	word ptr [bp+0Ah],0h
	jnz	157Ah

l1AB8_1577:
	jmp	175Eh

l1AB8_157A:
	mov	ax,[bp+0Ah]
	cmp	ax,[0B88Ch]
	jnz	1586h

l1AB8_1583:
	jmp	175Eh

l1AB8_1586:
	mov	ax,[bp+0Ah]
	cmp	ax,[0B74Ah]
	jnz	1592h

l1AB8_158F:
	jmp	1747h

l1AB8_1592:
	cmp	word ptr [0B74Ah],0h
	jz	15E8h

l1AB8_1599:
	mov	ax,0Fh
	mul	word ptr [0B74Ah]
	mov	di,ax
	add	di,520Bh
	mov	[bp-0Ah],di
	mov	[bp-8h],ds
	les	di,[bp-0Ah]
	cmp	word ptr es:[di+8h],0h
	jz	15E8h

l1AB8_15B6:
	les	di,[bp-0Ah]
	push	es
	push	di
	les	di,[bp-0Ah]
	push	word ptr es:[di+8h]
	call	dword ptr [0B6C6h]
	les	di,[bp-0Ah]
	xor	ax,ax
	mov	es:[di],ax
	mov	es:[di+2h],ax
	les	di,[bp-0Ah]
	xor	ax,ax
	mov	es:[di+4h],ax
	mov	es:[di+6h],ax
	les	di,[bp-0Ah]
	xor	ax,ax
	mov	es:[di+8h],ax

l1AB8_15E8:
	mov	ax,0Fh
	mul	word ptr [bp+0Ah]
	mov	di,ax
	add	di,520Bh
	mov	[bp-0Ah],di
	mov	[bp-8h],ds
	les	di,[bp-0Ah]
	mov	ax,es:[di+4h]
	or	ax,es:[di+6h]
	jz	160Ah

l1AB8_1607:
	jmp	1741h

l1AB8_160A:
	lea	di,[bp+0FEF6h]
	push	ss
	push	di
	les	di,[bp-0Ah]
	add	di,0Ah
	push	es
	push	di
	call	far 1EDAh:0A1Fh
	mov	di,1531h
	push	cs
	push	di
	call	far 1EDAh:0AACh
	mov	di,0B74Ch
	push	ds
	push	di
	mov	ax,8h
	push	ax
	call	far 1EDAh:0A39h
	mov	di,0B764h
	push	ds
	push	di
	mov	di,0B74Ch
	push	ds
	push	di
	lea	di,[bp-2h]
	push	ss
	push	di
	mov	ax,0FFF3h
	push	ax
	call	0887h
	or	al,al
	jnz	166Ah

l1AB8_1650:
	cmp	word ptr [0B818h],0FDh
	jnz	165Dh

l1AB8_1657:
	mov	word ptr [0B818h],0FFF8h

l1AB8_165D:
	xor	ax,ax
	mov	[bp+0Ah],ax
	mov	word ptr [bp+6h],1h
	jmp	175Eh

l1AB8_166A:
	mov	ax,[536Eh]
	mov	dx,[5370h]
	mov	[0B7BCh],ax
	mov	[0B7BEh],dx
	mov	ax,50Bh
	mov	dx,1AB8h
	mov	[536Eh],ax
	mov	[5370h],dx
	lea	di,[bp-6h]
	push	ss
	push	di
	push	word ptr [bp-2h]
	call	dword ptr [0B6C2h]
	mov	ax,[0B7BCh]
	mov	dx,[0B7BEh]
	mov	[536Eh],ax
	mov	[5370h],dx
	mov	ax,[bp-6h]
	or	ax,[bp-4h]
	jnz	16C4h

l1AB8_16A7:
	mov	di,0B6CAh
	push	ds
	push	di
	call	far 1EDAh:1051h
	mov	word ptr [0B818h],0FFF7h
	xor	ax,ax
	mov	[bp+0Ah],ax
	mov	word ptr [bp+6h],1h
	jmp	175Eh

l1AB8_16C4:
	mov	di,0B6CAh
	push	ds
	push	di
	les	di,[bp-6h]
	push	es
	push	di
	push	word ptr [bp-2h]
	xor	ax,ax
	push	ax
	push	ax
	call	far 1EDAh:10BBh
	mov	di,0B6CAh
	push	ds
	push	di
	call	far 1EDAh:1051h
	call	far 1EDAh:04A2h
	or	ax,ax
	jnz	1709h

l1AB8_16ED:
	push	word ptr [bp-4h]
	push	word ptr [bp-6h]
	push	cs
	call	06CAh
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0Ah]
	xor	dx,dx
	cmp	dx,bx
	jnz	1709h

l1AB8_1705:
	cmp	ax,cx
	jz	1727h

l1AB8_1709:
	mov	word ptr [0B818h],0FFF3h
	lea	di,[bp-6h]
	push	ss
	push	di
	push	word ptr [bp-2h]
	call	dword ptr [0B6C6h]
	xor	ax,ax
	mov	[bp+0Ah],ax
	mov	word ptr [bp+6h],1h
	jmp	175Eh

l1AB8_1727:
	mov	ax,[bp-2h]
	les	di,[bp-0Ah]
	mov	es:[di+8h],ax
	mov	ax,[bp-6h]
	mov	dx,[bp-4h]
	les	di,[bp-0Ah]
	mov	es:[di],ax
	mov	es:[di+2h],dx

l1AB8_1741:
	mov	ax,[bp+0Ah]
	mov	[0B74Ah],ax

l1AB8_1747:
	mov	ax,0Fh
	mul	word ptr [bp+0Ah]
	mov	di,ax
	mov	ax,[di+520Fh]
	mov	dx,[di+5211h]
	mov	[0B836h],ax
	mov	[0B838h],dx

l1AB8_175E:
	mov	ax,[bp+0Ah]
	mov	[0B88Ch],ax
	mov	ax,[bp+8h]
	mov	[0B88Eh],ax
	mov	ax,[bp+6h]
	mov	[0B890h],ax
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	cs
	call	1DA6h
	mov	sp,bp
	pop	bp
	retf	6h
