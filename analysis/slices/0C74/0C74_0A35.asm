;; fn0C74_0A35: 0C74:0A35
;;   Called from:
;;     0800:097B (in fn0800_08E9)
;;     0800:4151 (in fn0800_3D9D)
;;     0C74:1B32 (in fn0C74_0FA1)
;;     0C74:2ACC (in fn0C74_1F08)
fn0C74_0A35 proc
	enter	30ECh,0h
	xor	ax,ax
	mov	[bp-6h],ax
	mov	ax,[58BAh]
	sub	ax,[58B8h]
	shr	ax,1h
	mov	[bp+0CF18h],ax
	cmp	word ptr [bp+0CF18h],17h
	jnc	0A5Ah

l0C74_0A52:
	mov	word ptr [bp+0CF16h],61A8h
	jmp	0A60h

l0C74_0A5A:
	mov	word ptr [bp+0CF16h],0C350h

l0C74_0A60:
	mov	ax,[58B4h]
	add	ax,15h
	mov	[bp-0Ah],ax
	mov	ax,[58B8h]
	add	ax,[bp+0CF18h]
	mov	[bp-0Ch],ax
	mov	ax,[bp+0CF16h]
	mov	[bp+0CF14h],ax
	mov	ax,1h
	cmp	ax,[bp+0CF14h]
	jbe	0A87h

l0C74_0A84:
	jmp	0CA3h

l0C74_0A87:
	mov	[bp-4h],ax
	jmp	0A8Fh

l0C74_0A8C:
	inc	word ptr [bp-4h]

l0C74_0A8F:
	push	2Dh
	call	far 1EDAh:0D80h
	add	ax,[bp-0Ah]
	sub	ax,15h
	mov	[bp-0Eh],ax
	mov	ax,[bp-0Ah]
	add	ax,9h
	cmp	ax,[bp-0Eh]
	jnc	0AADh

l0C74_0AAA:
	dec	word ptr [bp-0Eh]

l0C74_0AAD:
	mov	ax,[bp+0CF18h]
	shl	ax,1h
	inc	ax
	inc	ax
	push	ax
	call	far 1EDAh:0D80h
	add	ax,[bp-0Ch]
	sub	ax,[bp+0CF18h]
	mov	[bp-10h],ax
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	call	far 1AB8h:1E3Ch
	mov	[bp+0CF1Bh],al
	cmp	byte ptr [bp+0CF1Bh],0h
	jnz	0ADEh

l0C74_0ADB:
	jmp	0BDAh

l0C74_0ADE:
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	0h
	call	far 1AB8h:1E54h
	push	3h
	call	far 1EDAh:0D80h
	cmp	ax,1h
	jz	0AFAh

l0C74_0AF7:
	jmp	0BD7h

l0C74_0AFA:
	cmp	byte ptr [58B0h],0h
	jz	0B0Eh

l0C74_0B01:
	push	64h
	call	far 1EDAh:0D80h
	push	ax
	call	far 11C8h:0354h

l0C74_0B0E:
	mov	ax,[58E6h]
	cwd
	mov	cx,4h
	idiv	cx
	push	ax
	call	far 1E78h:029Ch
	push	12Ch
	call	far 1EDAh:0D80h
	add	ax,[bp-0Ah]
	sub	ax,96h
	mov	[bp-0Eh],ax
	cmp	word ptr [bp-0Eh],1h
	jnc	0B39h

l0C74_0B34:
	mov	word ptr [bp-0Eh],1h

l0C74_0B39:
	cmp	word ptr [bp-0Eh],27Eh
	jbe	0B45h

l0C74_0B40:
	mov	word ptr [bp-0Eh],27Eh

l0C74_0B45:
	push	0C8h
	call	far 1EDAh:0D80h
	add	ax,16h
	mov	dx,ax
	mov	ax,[bp-0Ch]
	sub	ax,dx
	mov	[bp-10h],ax
	cmp	word ptr [bp-10h],1h
	jnc	0B65h

l0C74_0B60:
	mov	word ptr [bp-10h],1h

l0C74_0B65:
	cmp	word ptr [bp-10h],177h
	jbe	0B71h

l0C74_0B6C:
	mov	word ptr [bp-10h],1h

l0C74_0B71:
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	0BCBh

l0C74_0B80:
	inc	word ptr [bp-6h]
	mov	al,[bp+0CF1Bh]
	mov	di,[bp-6h]
	mov	[bp+di+0CF1Bh],al
	mov	ax,[bp-0Eh]
	mov	di,[bp-6h]
	shl	di,2h
	mov	[bp+di+0D8DCh],ax
	mov	ax,[bp-10h]
	mov	di,[bp-6h]
	shl	di,2h
	mov	[bp+di+0D8DEh],ax
	mov	di,[bp-6h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-6h]
	shl	di,2h
	push	word ptr [bp+di+0D8DEh]
	mov	di,[bp-6h]
	mov	al,[bp+di+0CF1Bh]
	xor	ah,ah
	push	ax
	call	far 1AB8h:1E54h

l0C74_0BCB:
	cmp	byte ptr [58B0h],0h
	jz	0BD7h

l0C74_0BD2:
	call	far 11C8h:033Bh

l0C74_0BD7:
	jmp	0C97h

l0C74_0BDA:
	cmp	word ptr [bp-6h],0h
	jnz	0BE3h

l0C74_0BE0:
	jmp	0C97h

l0C74_0BE3:
	push	word ptr [bp-6h]
	call	far 1EDAh:0D80h
	inc	ax
	mov	[bp-8h],ax
	mov	di,[bp-8h]
	shl	di,2h
	cmp	word ptr [bp+di+0D8DEh],1F4h
	jnz	0C00h

l0C74_0BFD:
	jmp	0C97h

l0C74_0C00:
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DEh]
	push	0h
	call	far 1AB8h:1E54h
	push	14h
	call	far 1EDAh:0D80h
	mov	[bp-0Eh],ax
	cmp	word ptr [bp-0Eh],1h
	jz	0C5Ch

l0C74_0C2B:
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-8h]
	shl	di,2h
	mov	ax,[bp+di+0D8DEh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	0C5Ch

l0C74_0C4A:
	mov	di,[bp-8h]
	shl	di,2h
	mov	ax,[bp+di+0D8DEh]
	inc	ax
	inc	ax
	cmp	ax,[58BAh]
	jc	0C6Ah

l0C74_0C5C:
	mov	di,[bp-8h]
	shl	di,2h
	mov	word ptr [bp+di+0D8DEh],1F4h
	jmp	0C97h

l0C74_0C6A:
	mov	di,[bp-8h]
	shl	di,2h
	inc	word ptr [bp+di+0D8DEh]
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DEh]
	mov	di,[bp-8h]
	mov	al,[bp+di+0CF1Bh]
	xor	ah,ah
	push	ax
	call	far 1AB8h:1E54h

l0C74_0C97:
	mov	ax,[bp-4h]
	cmp	ax,[bp+0CF14h]
	jz	0CA3h

l0C74_0CA0:
	jmp	0A8Ch

l0C74_0CA3:
	cmp	word ptr [bp-6h],0h
	jz	0CF3h

l0C74_0CA9:
	mov	ax,[bp-6h]
	mov	[bp+0CF14h],ax
	mov	ax,1h
	cmp	ax,[bp+0CF14h]
	ja	0CF3h

l0C74_0CB9:
	mov	[bp-8h],ax
	jmp	0CC1h

l0C74_0CBE:
	inc	word ptr [bp-8h]

l0C74_0CC1:
	mov	di,[bp-8h]
	shl	di,2h
	cmp	word ptr [bp+di+0D8DEh],1F4h
	jz	0CEAh

l0C74_0CCF:
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DEh]
	push	0h
	call	far 1AB8h:1E54h

l0C74_0CEA:
	mov	ax,[bp-8h]
	cmp	ax,[bp+0CF14h]
	jnz	0CBEh

l0C74_0CF3:
	mov	byte ptr [58B3h],1h
	leave
	retf
