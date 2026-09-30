;; fn0800_11EF: 0800:11EF
;;   Called from:
;;     0800:3F4A (in fn0800_3D9D)
fn0800_11EF proc
	enter	18Ch,0h
	call	far 1206h:0066h
	lea	di,[bp+0FE74h]
	push	ss
	push	di
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	sub	ax,68h
	push	ax
	push	8Eh
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	add	ax,68h
	push	ax
	push	0A0h
	mov	di,11D8h
	push	cs
	push	di
	call	0D20h
	lea	di,[bp-8h]
	push	ss
	push	di
	push	6h
	call	far 1EDAh:0A39h
	call	far 1206h:0038h
	mov	di,11E7h
	push	cs
	push	di
	call	far 0C74h:0000h
	or	al,al
	jnz	124Ch

l0800_1249:
	call	0000h

l0800_124C:
	lea	di,[bp+0FF78h]
	push	ss
	push	di
	mov	di,11E7h
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp+0FF78h]
	push	ss
	push	di
	push	219h
	call	far 1EDAh:0FD0h
	call	far 1EDAh:04A9h
	mov	word ptr [598Eh],0FFFFh
	mov	word ptr [5990h],0FFFFh

l0800_127B:
	add	word ptr [598Eh],1h
	adc	word ptr [5990h],0h
	lea	di,[bp+0FF78h]
	push	ss
	push	di
	mov	di,5CB4h
	push	ds
	push	di
	call	far 1EDAh:1085h
	add	sp,4h
	call	far 1EDAh:04A9h
	mov	di,5CB4h
	push	ds
	push	di
	lea	di,[bp-8h]
	push	ss
	push	di
	call	far 1EDAh:0B24h
	jz	12D5h

l0800_12AE:
	lea	di,[bp+0FF78h]
	push	ss
	push	di
	call	far 1EDAh:1185h
	call	far 1EDAh:04A9h
	or	al,al
	jnz	12D5h

l0800_12C2:
	mov	al,[0002h]
	xor	ah,ah
	dec	ax
	cwd
	cmp	dx,[5990h]
	jnz	127Bh

l0800_12CF:
	cmp	ax,[598Eh]
	jnz	127Bh

l0800_12D5:
	lea	di,[bp+0FF78h]
	push	ss
	push	di
	call	far 1EDAh:1051h
	call	far 1EDAh:04A9h
	lea	di,[bp-8h]
	push	ss
	push	di
	mov	di,5ED6h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h
	mov	di,5CB4h
	push	ds
	push	di
	lea	di,[bp-8h]
	push	ss
	push	di
	call	far 1EDAh:0B24h
	jz	1313h

l0800_1307:
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h

l0800_1313:
	leave
	ret
