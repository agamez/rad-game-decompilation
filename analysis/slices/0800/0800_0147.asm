;; fn0800_0147: 0800:0147
;;   Called from:
;;     0800:03FC (in fn0800_03F8)
fn0800_0147 proc
	enter	84h,0h
	push	0h
	push	0h
	push	15h
	push	15h
	call	far 1AB8h:13A3h
	mov	[bp+0FF7Ch],ax
	mov	di,125h
	push	cs
	push	di
	call	far 0C74h:0000h
	or	al,al
	jnz	0174h

l0800_016A:
	mov	di,12Dh
	push	cs
	push	di
	call	far 13E2h:0193h

l0800_0174:
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	mov	di,125h
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	push	word ptr [bp+0FF7Ch]
	call	far 1EDAh:0FD0h
	mov	byte ptr [bp-1h],0h
	jmp	019Ch

l0800_0199:
	inc	byte ptr [bp-1h]

l0800_019C:
	push	2h
	call	far 0C74h:00B2h
	push	word ptr [bp+0FF7Ch]
	call	far 1EDAh:023Fh
	mov	cx,ax
	mov	bx,dx
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	mov	[di+5992h],cx
	mov	[di+5994h],bx
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	mov	al,[bp-1h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+5992h]
	push	es
	push	di
	push	1h
	xor	ax,ax
	push	ax
	push	ax
	call	far 1EDAh:10BBh
	cmp	byte ptr [bp-1h],0C7h
	jnz	0199h

l0800_01E9:
	lea	di,[bp+0FF7Eh]
	push	ss
	push	di
	call	far 1EDAh:1051h
	leave
	ret
0800:01F6                   07 52 41 44 2E 44 41 54             .RAD.DAT
