;; fn0800_03F8: 0800:03F8
;;   Called from:
;;     0800:43FB (in fn0800_4255)
fn0800_03F8 proc
	enter	88h,0h
	call	0147h
	mov	di,3DDh
	push	cs
	push	di
	call	far 0C74h:0000h
	or	al,al
	jnz	0417h

l0800_040D:
	mov	di,3E5h
	push	cs
	push	di
	call	far 13E2h:0193h

l0800_0417:
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	mov	di,3DDh
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	push	word ptr [0004h]
	call	far 1EDAh:0FD0h
	push	0h
	push	0h
	push	2Bh
	push	2Bh
	call	far 1AB8h:13A3h
	mov	[bp+0FF78h],ax
	push	word ptr [0004h]
	call	far 1EDAh:023Fh
	mov	[bp+0FF7Ah],ax
	mov	[bp+0FF7Ch],dx
	mov	byte ptr [bp-1h],0h
	jmp	0461h

l0800_045E:
	inc	byte ptr [bp-1h]

l0800_0461:
	push	5h
	call	far 0C74h:00B2h
	push	word ptr [bp+0FF78h]
	call	far 1EDAh:023Fh
	mov	cx,ax
	mov	bx,dx
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	mov	[di+5388h],cx
	mov	[di+538Ah],bx
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5388h]
	push	es
	push	di
	push	1h
	xor	ax,ax
	push	ax
	push	ax
	call	far 1EDAh:10BBh
	cmp	byte ptr [bp-1h],10h
	jnz	045Eh

l0800_04AE:
	push	word ptr [bp+0FF7Ch]
	push	word ptr [bp+0FF7Ah]
	push	word ptr [0004h]
	call	far 1EDAh:0254h
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	call	far 1EDAh:1051h
	leave
	ret
