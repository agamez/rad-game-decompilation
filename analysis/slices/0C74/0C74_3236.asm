;; fn0C74_3236: 0C74:3236
;;   Called from:
;;     0C74:523C (in fn0C74_522C)
fn0C74_3236 proc
	enter	1Ch,0h
	mov	byte ptr [bp-1h],0h
	cmp	word ptr [58B4h],27Eh
	jc	3249h

l0C74_3246:
	jmp	3610h

l0C74_3249:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	32ADh

l0C74_325B:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	32ADh

l0C74_3270:
	mov	ax,[58B6h]
	add	ax,17h
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	32ADh

l0C74_3284:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	push	word ptr [58B8h]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	32ADh

l0C74_3296:
	mov	ax,[58B6h]
	add	ax,17h
	push	ax
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	32B0h

l0C74_32AD:
	jmp	3610h

l0C74_32B0:
	mov	byte ptr [bp-1h],1h
	push	word ptr [58B6h]
	mov	ax,[58B8h]
	add	ax,15h
	push	ax
	mov	ax,[58B6h]
	add	ax,16h
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:13A3h
	mov	[bp-0Eh],ax
	push	word ptr [bp-0Eh]
	call	far 1EDAh:023Fh
	mov	[bp-0Ch],ax
	mov	[bp-0Ah],dx
	push	word ptr [58B6h]
	mov	ax,[58B8h]
	add	ax,16h
	push	ax
	mov	ax,[58B6h]
	add	ax,16h
	push	ax
	push	word ptr [58BAh]
	les	di,[bp-0Ch]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Dh
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-10h],ax
	push	word ptr [bp-10h]
	call	far 1EDAh:023Fh
	mov	[bp-1Ch],ax
	mov	[bp-1Ah],dx
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Dh
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-1Ch]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	ax,[58B4h]
	add	ax,19h
	mov	[bp-8h],ax
	inc	word ptr [bp-8h]
	push	word ptr [bp-8h]
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Ch]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,12h
	push	ax
	push	0Bh
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,13h
	push	ax
	push	3h
	call	far 1AB8h:1E54h
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,14h
	push	ax
	push	9h
	call	far 1AB8h:1E54h
	push	word ptr [bp-1Ah]
	push	word ptr [bp-1Ch]
	push	word ptr [bp-10h]
	call	far 1EDAh:0254h
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Eh
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:13A3h
	mov	[bp-10h],ax
	push	word ptr [bp-10h]
	call	far 1EDAh:023Fh
	mov	[bp-1Ch],ax
	mov	[bp-1Ah],dx
	mov	ax,[58B4h]
	add	ax,19h
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	mov	ax,[58B4h]
	add	ax,1Eh
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	les	di,[bp-1Ch]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	mov	byte ptr [bp-2h],1h

l0C74_3456:
	cmp	byte ptr [bp-2h],14h
	jnc	34ACh

l0C74_345C:
	mov	al,[bp-2h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,1Eh
	add	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,1Bh
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	34ACh

l0C74_347C:
	push	0E6h
	push	0Ah
	call	070Dh
	mov	al,[bp-2h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,19h
	add	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Ch]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	inc	byte ptr [bp-2h]
	jmp	3456h

l0C74_34AC:
	mov	al,[bp-2h]
	xor	ah,ah
	mov	[bp-6h],ax
	mov	ax,[58B6h]
	mov	[bp-12h],ax
	mov	ax,[58B6h]
	add	ax,16h
	mov	[bp-14h],ax
	mov	ax,[58B8h]
	add	ax,15h
	mov	[bp-16h],ax
	mov	ax,[58BAh]
	mov	[bp-18h],ax
	mov	byte ptr [bp-3h],1h
	jmp	34DBh

l0C74_34D8:
	inc	byte ptr [bp-3h]

l0C74_34DB:
	inc	word ptr [bp-12h]
	inc	word ptr [bp-14h]
	push	word ptr [bp-12h]
	mov	ax,[bp-16h]
	inc	ax
	push	ax
	les	di,[bp-0Ch]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	mov	ax,[bp-12h]
	sub	ax,5h
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Ch]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	0E6h
	push	14h
	call	070Dh
	cmp	byte ptr [bp-3h],16h
	jnz	34D8h

l0C74_351D:
	mov	ax,[bp-12h]
	inc	ax
	push	ax
	mov	ax,[bp-18h]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	3541h

l0C74_3530:
	mov	ax,[bp-12h]
	inc	ax
	push	ax
	push	word ptr [bp-16h]
	push	word ptr [bp-14h]
	push	word ptr [bp-18h]
	call	2BBDh

l0C74_3541:
	mov	ax,[bp-6h]
	add	ax,15h
	or	al,al
	jc	3584h

l0C74_354B:
	mov	[bp-3h],al
	jmp	3553h

l0C74_3550:
	dec	byte ptr [bp-3h]

l0C74_3553:
	push	0E6h
	push	5h
	call	070Dh
	mov	al,[bp-3h]
	xor	ah,ah
	mov	dx,ax
	mov	ax,[58B4h]
	add	ax,19h
	add	ax,dx
	push	ax
	mov	ax,[58B8h]
	add	ax,0Dh
	push	ax
	les	di,[bp-1Ch]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	byte ptr [bp-3h],0h
	jnz	3550h

l0C74_3584:
	push	word ptr [bp-1Ah]
	push	word ptr [bp-1Ch]
	push	word ptr [bp-10h]
	call	far 1EDAh:0254h
	mov	byte ptr [bp-2h],1h
	mov	byte ptr [bp-3h],1h
	jmp	359Fh

l0C74_359C:
	inc	byte ptr [bp-3h]

l0C74_359F:
	mov	ax,[58E6h]
	cwd
	mov	cx,2h
	idiv	cx
	push	ax
	call	far 1E78h:029Ch
	push	0Ah
	call	02D8h
	inc	byte ptr [bp-2h]
	cmp	byte ptr [bp-2h],5h
	jnz	35D0h

l0C74_35BC:
	mov	byte ptr [bp-2h],1h
	cmp	byte ptr [58B0h],0h
	jz	35CEh

l0C74_35C7:
	push	32h
	call	far 11C8h:0354h

l0C74_35CE:
	jmp	35D5h

l0C74_35D0:
	call	far 11C8h:033Bh

l0C74_35D5:
	inc	word ptr [58B4h]
	inc	word ptr [58B6h]
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
	cmp	byte ptr [bp-3h],16h
	jnz	359Ch

l0C74_3602:
	push	word ptr [bp-0Ah]
	push	word ptr [bp-0Ch]
	push	word ptr [bp-0Eh]
	call	far 1EDAh:0254h

l0C74_3610:
	mov	al,[bp-1h]
	leave
	ret
