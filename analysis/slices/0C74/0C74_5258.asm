;; fn0C74_5258: 0C74:5258
;;   Called from:
;;     0800:273A (in fn0800_2401)
;;     0800:2A21 (in fn0800_2827)
;;     0800:2F2F (in fn0800_2C0C)
;;     0800:350A (in fn0800_31B7)
fn0C74_5258 proc
	enter	10h,0h
	mov	byte ptr [bp-2h],1h
	mov	ax,[5968h]
	cmp	ax,1h
	jnz	52A5h

l0C74_5268:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	5297h

l0C74_527A:
	mov	ax,[58B6h]
	add	ax,0Ch
	push	ax
	mov	ax,[58BAh]
	sub	ax,0Ch
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	5297h

l0C74_5291:
	call	396Eh
	mov	[bp-2h],al

l0C74_5297:
	cmp	byte ptr [bp-2h],0h
	jz	52A3h

l0C74_529D:
	call	45CEh
	mov	[bp-2h],al

l0C74_52A3:
	jmp	52E5h

l0C74_52A5:
	cmp	ax,0FFFFh
	jnz	52E5h

l0C74_52AA:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	52D9h

l0C74_52BC:
	mov	ax,[58B4h]
	sub	ax,0Ch
	push	ax
	mov	ax,[58BAh]
	sub	ax,0Ch
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	52D9h

l0C74_52D3:
	call	3F74h
	mov	[bp-2h],al

l0C74_52D9:
	cmp	byte ptr [bp-2h],0h
	jz	52E5h

l0C74_52DF:
	call	4999h
	mov	[bp-2h],al

l0C74_52E5:
	cmp	byte ptr [bp-2h],0h
	jnz	52EEh

l0C74_52EB:
	jmp	5420h

l0C74_52EE:
	cmp	word ptr [5968h],1h
	jnz	5300h

l0C74_52F5:
	mov	ax,[5970h]
	sub	ax,15h
	mov	[bp-4h],ax
	jmp	5306h

l0C74_5300:
	mov	ax,[596Ch]
	mov	[bp-4h],ax

l0C74_5306:
	cmp	word ptr [5968h],1h
	jnz	5315h

l0C74_530D:
	mov	ax,[5970h]
	mov	[bp-8h],ax
	jmp	531Eh

l0C74_5315:
	mov	ax,[596Ch]
	add	ax,15h
	mov	[bp-8h],ax

l0C74_531E:
	push	word ptr [bp-8h]
	mov	ax,[596Eh]
	add	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	535Ch

l0C74_5331:
	push	word ptr [bp-8h]
	mov	ax,[596Eh]
	add	ax,14h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	535Ch

l0C74_5344:
	mov	ax,[596Eh]
	add	ax,15h
	mov	[bp-6h],ax
	push	word ptr [bp-8h]
	push	word ptr [bp-6h]
	push	8h
	call	far 1AB8h:1E54h
	jmp	5363h

l0C74_535C:
	mov	ax,[596Eh]
	dec	ax
	mov	[bp-6h],ax

l0C74_5363:
	mov	ax,[bp-6h]
	mov	[bp-0Ah],ax

l0C74_5369:
	cmp	word ptr [bp-6h],2h
	jbe	5385h

l0C74_536F:
	push	word ptr [bp-8h]
	push	word ptr [bp-6h]
	call	far 1AB8h:1E3Ch
	cmp	ax,8h
	jnz	5385h

l0C74_537F:
	sub	word ptr [bp-6h],16h
	jmp	5369h

l0C74_5385:
	mov	ax,[bp-6h]
	cmp	ax,[bp-0Ah]
	jnz	5390h

l0C74_538D:
	jmp	5420h

l0C74_5390:
	push	word ptr [bp-4h]
	mov	ax,[bp-6h]
	dec	ax
	push	ax
	push	word ptr [bp-8h]
	push	word ptr [bp-6h]
	call	far 1AB8h:13A3h
	mov	[bp-10h],ax
	push	word ptr [bp-10h]
	call	far 1EDAh:023Fh
	mov	[bp-0Eh],ax
	mov	[bp-0Ch],dx
	push	word ptr [bp-4h]
	mov	ax,[bp-6h]
	dec	ax
	push	ax
	push	word ptr [bp-8h]
	push	word ptr [bp-6h]
	les	di,[bp-0Eh]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	0h
	call	far 1AB8h:1C32h
	push	word ptr [bp-4h]
	push	word ptr [bp-6h]
	push	word ptr [bp-8h]
	push	word ptr [bp-6h]
	call	far 1AB8h:1AF6h
	push	word ptr [bp-4h]
	push	word ptr [bp-6h]
	push	word ptr [bp-8h]
	push	word ptr [bp-0Ah]
	call	2BBDh
	push	word ptr [bp-4h]
	mov	ax,[bp-6h]
	dec	ax
	push	ax
	les	di,[bp-0Eh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	word ptr [bp-0Ch]
	push	word ptr [bp-0Eh]
	push	word ptr [bp-10h]
	call	far 1EDAh:0254h

l0C74_5420:
	mov	al,[bp-2h]
	mov	[bp-1h],al
	mov	al,[bp-1h]
	leave
	retf
