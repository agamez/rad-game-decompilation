;; fn0C74_076B: 0C74:076B
;;   Called from:
;;     0800:0967 (in fn0800_08E9)
;;     0C74:2E52 (in fn0C74_2BBD)
;;     0C74:4975 (in fn0C74_45CE)
;;     0C74:4990 (in fn0C74_45CE)
;;     0C74:4D88 (in fn0C74_4999)
;;     0C74:4DA3 (in fn0C74_4999)
fn0C74_076B proc
	enter	30EEh,0h
	xor	ax,ax
	mov	[bp-6h],ax
	mov	ax,[bp+8h]
	sub	ax,[bp+0Ch]
	shr	ax,1h
	add	ax,[bp+0Ch]
	mov	[bp+0CF16h],ax
	mov	ax,[bp+6h]
	sub	ax,[bp+0Ah]
	shr	ax,1h
	add	ax,[bp+0Ah]
	mov	[bp+0CF14h],ax
	mov	ax,[bp+6h]
	sub	ax,[bp+0Ah]
	mov	dx,ax
	mov	ax,[bp+8h]
	sub	ax,[bp+0Ch]
	mul	dx
	imul	ax,ax,0Fh
	mov	[bp+0CF1Ah],ax
	mov	ax,[bp+0Ch]
	mov	[bp-0Ah],ax
	mov	ax,[bp+0Ah]
	mov	[bp-0Ch],ax
	mov	ax,[bp+0CF1Ah]
	mov	[bp+0CF12h],ax
	mov	ax,1h
	cmp	ax,[bp+0CF12h]
	jbe	07C9h

l0C74_07C6:
	jmp	09E1h

l0C74_07C9:
	mov	[bp-4h],ax
	jmp	07D1h

l0C74_07CE:
	inc	word ptr [bp-4h]

l0C74_07D1:
	mov	ax,[bp+8h]
	sub	ax,[bp+0Ch]
	inc	ax
	push	ax
	call	far 1EDAh:0D80h
	add	ax,[bp+0Ch]
	mov	[bp-0Eh],ax
	mov	ax,[bp+6h]
	sub	ax,[bp+0Ah]
	inc	ax
	push	ax
	call	far 1EDAh:0D80h
	add	ax,[bp+0Ah]
	mov	[bp-10h],ax
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	call	far 1AB8h:1E3Ch
	mov	[bp+0CF19h],al
	mov	al,[bp+0CF19h]
	push	ax
	mov	di,74Bh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	081Ah

l0C74_0817:
	jmp	0918h

l0C74_081A:
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	push	0h
	call	far 1AB8h:1E54h
	push	3h
	call	far 1EDAh:0D80h
	cmp	ax,1h
	jz	0836h

l0C74_0833:
	jmp	0915h

l0C74_0836:
	cmp	byte ptr [58B0h],0h
	jz	084Ah

l0C74_083D:
	push	64h
	call	far 1EDAh:0D80h
	push	ax
	call	far 11C8h:0354h

l0C74_084A:
	mov	ax,[58E6h]
	cwd
	mov	cx,4h
	idiv	cx
	push	ax
	call	far 1E78h:029Ch
	push	12Ch
	call	far 1EDAh:0D80h
	add	ax,[bp+0CF16h]
	sub	ax,96h
	mov	[bp-0Eh],ax
	cmp	word ptr [bp-0Eh],1h
	jnc	0876h

l0C74_0871:
	mov	word ptr [bp-0Eh],1h

l0C74_0876:
	cmp	word ptr [bp-0Eh],27Eh
	jbe	0882h

l0C74_087D:
	mov	word ptr [bp-0Eh],27Eh

l0C74_0882:
	push	0C8h
	call	far 1EDAh:0D80h
	add	ax,16h
	mov	dx,ax
	mov	ax,[bp+0CF14h]
	sub	ax,dx
	mov	[bp-10h],ax
	cmp	word ptr [bp-10h],1h
	jnc	08A3h

l0C74_089E:
	mov	word ptr [bp-10h],1h

l0C74_08A3:
	cmp	word ptr [bp-10h],177h
	jbe	08AFh

l0C74_08AA:
	mov	word ptr [bp-10h],1h

l0C74_08AF:
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	0909h

l0C74_08BE:
	inc	word ptr [bp-6h]
	mov	al,[bp+0CF19h]
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

l0C74_0909:
	cmp	byte ptr [58B0h],0h
	jz	0915h

l0C74_0910:
	call	far 11C8h:033Bh

l0C74_0915:
	jmp	09D5h

l0C74_0918:
	cmp	word ptr [bp-6h],0h
	jnz	0921h

l0C74_091E:
	jmp	09D5h

l0C74_0921:
	push	word ptr [bp-6h]
	call	far 1EDAh:0D80h
	inc	ax
	mov	[bp-8h],ax
	mov	di,[bp-8h]
	shl	di,2h
	cmp	word ptr [bp+di+0D8DEh],1F4h
	jnz	093Eh

l0C74_093B:
	jmp	09D5h

l0C74_093E:
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
	jz	099Ah

l0C74_0969:
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
	jnz	099Ah

l0C74_0988:
	mov	di,[bp-8h]
	shl	di,2h
	mov	ax,[bp+di+0D8DEh]
	inc	ax
	inc	ax
	cmp	ax,[58BAh]
	jc	09A8h

l0C74_099A:
	mov	di,[bp-8h]
	shl	di,2h
	mov	word ptr [bp+di+0D8DEh],1F4h
	jmp	09D5h

l0C74_09A8:
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

l0C74_09D5:
	mov	ax,[bp-4h]
	cmp	ax,[bp+0CF12h]
	jz	09E1h

l0C74_09DE:
	jmp	07CEh

l0C74_09E1:
	cmp	word ptr [bp-6h],0h
	jz	0A31h

l0C74_09E7:
	mov	ax,[bp-6h]
	mov	[bp+0CF12h],ax
	mov	ax,1h
	cmp	ax,[bp+0CF12h]
	ja	0A31h

l0C74_09F7:
	mov	[bp-8h],ax
	jmp	09FFh

l0C74_09FC:
	inc	word ptr [bp-8h]

l0C74_09FF:
	mov	di,[bp-8h]
	shl	di,2h
	cmp	word ptr [bp+di+0D8DEh],1F4h
	jz	0A28h

l0C74_0A0D:
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DCh]
	mov	di,[bp-8h]
	shl	di,2h
	push	word ptr [bp+di+0D8DEh]
	push	0h
	call	far 1AB8h:1E54h

l0C74_0A28:
	mov	ax,[bp-8h]
	cmp	ax,[bp+0CF12h]
	jnz	09FCh

l0C74_0A31:
	leave
	retf	8h
