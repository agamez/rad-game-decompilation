;; fn11C8_0092: 11C8:0092
;;   Called from:
;;     11C8:0397 (in fn11C8_0394)
fn11C8_0092 proc
	enter	10Eh,0h
	call	far 1E78h:01C0h
	mov	byte ptr [bp-0Dh],0h
	mov	byte ptr [bp-1h],1h

l11C8_00A3:
	cmp	byte ptr [bp-1h],7h
	jc	00ACh

l11C8_00A9:
	jmp	0229h

l11C8_00AC:
	cmp	byte ptr [bp-0Dh],0h
	jz	00B5h

l11C8_00B2:
	jmp	0229h

l11C8_00B5:
	mov	al,[bp-1h]
	xor	ah,ah
	shl	ax,4h
	add	ax,200h
	mov	[5978h],ax
	xor	ax,ax
	mov	[bp-8h],ax
	mov	byte ptr [bp-0Eh],0h

l11C8_00CC:
	cmp	word ptr [bp-8h],201h
	jnc	00F1h

l11C8_00D3:
	cmp	byte ptr [bp-0Eh],0h
	jnz	00F1h

l11C8_00D9:
	mov	ax,[5978h]
	add	ax,0Ch
	mov	dx,ax
	in	al,dx
	and	al,80h
	or	al,al
	jnz	00ECh

l11C8_00E8:
	mov	byte ptr [bp-0Eh],1h

l11C8_00EC:
	inc	word ptr [bp-8h]
	jmp	00CCh

l11C8_00F1:
	cmp	byte ptr [bp-0Eh],0h
	jnz	00FAh

l11C8_00F7:
	jmp	01EAh

l11C8_00FA:
	mov	ax,[5978h]
	add	ax,0Ch
	mov	dx,ax
	in	al,dx
	mov	[bp-3h],al
	mov	ax,[5978h]
	add	ax,0Ch
	mov	dx,ax
	mov	al,0D3h
	out	dx,al
	mov	word ptr [bp-0Ah],1h
	jmp	011Bh

l11C8_0118:
	inc	word ptr [bp-0Ah]

l11C8_011B:
	cmp	word ptr [bp-0Ah],1000h
	jnz	0118h

l11C8_0122:
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	in	al,dx
	mov	[bp-4h],al
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	mov	al,1h
	out	dx,al
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	in	al,dx
	mov	[bp-2h],al
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	in	al,dx
	mov	[bp-2h],al
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	in	al,dx
	mov	[bp-2h],al
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	in	al,dx
	mov	[bp-2h],al
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	mov	al,0h
	out	dx,al
	mov	byte ptr [bp-2h],0h

l11C8_0178:
	xor	ax,ax
	mov	[bp-8h],ax
	mov	byte ptr [bp-0Eh],0h

l11C8_0181:
	cmp	word ptr [bp-8h],201h
	jnc	01A6h

l11C8_0188:
	cmp	byte ptr [bp-0Eh],0h
	jnz	01A6h

l11C8_018E:
	mov	ax,[5978h]
	add	ax,0Eh
	mov	dx,ax
	in	al,dx
	and	al,80h
	cmp	al,80h
	jnz	01A1h

l11C8_019D:
	mov	byte ptr [bp-0Eh],1h

l11C8_01A1:
	inc	word ptr [bp-8h]
	jmp	0181h

l11C8_01A6:
	cmp	byte ptr [bp-0Eh],0h
	jz	01BDh

l11C8_01AC:
	mov	ax,[5978h]
	add	ax,0Ah
	mov	dx,ax
	in	al,dx
	cmp	al,0AAh
	jnz	01BDh

l11C8_01B9:
	mov	byte ptr [bp-0Dh],1h

l11C8_01BD:
	inc	byte ptr [bp-2h]
	cmp	byte ptr [bp-2h],10h
	jz	01CCh

l11C8_01C6:
	cmp	byte ptr [bp-0Eh],0h
	jz	0178h

l11C8_01CC:
	cmp	byte ptr [bp-0Eh],0h
	jnz	01EAh

l11C8_01D2:
	mov	ax,[5978h]
	add	ax,0Ch
	mov	dx,ax
	mov	al,[bp-3h]
	out	dx,al
	mov	ax,[5978h]
	add	ax,6h
	mov	dx,ax
	mov	al,[bp-4h]
	out	dx,al

l11C8_01EA:
	cmp	byte ptr [bp-0Dh],0h
	jz	0223h

l11C8_01F0:
	mov	di,0B9BCh
	push	ds
	push	di
	mov	di,71h
	push	cs
	push	di
	push	0h
	call	far 1EDAh:08CEh
	lea	di,[bp+0FEF2h]
	push	ss
	push	di
	push	word ptr [5978h]
	push	3h
	call	0000h
	push	0h
	call	far 1EDAh:08CEh
	call	far 1EDAh:086Ch
	mov	byte ptr [5976h],1h
	jmp	0226h

l11C8_0223:
	inc	byte ptr [bp-1h]

l11C8_0226:
	jmp	00A3h

l11C8_0229:
	cmp	byte ptr [bp-0Dh],0h
	jnz	0234h

l11C8_022F:
	mov	byte ptr [5976h],0h

l11C8_0234:
	leave
	ret
