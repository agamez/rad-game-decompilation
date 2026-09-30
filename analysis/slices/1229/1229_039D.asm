;; fn1229_039D: 1229:039D
;;   Called from:
;;     1229:0E1E (in fn1229_0DCC)
fn1229_039D proc
	enter	82h,0h
	cmp	byte ptr [6BBAh],0h
	jz	03BBh

l1229_03A8:
	mov	di,6BBAh
	push	ds
	push	di
	mov	di,6BB2h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h
	jmp	03CCh

l1229_03BB:
	mov	di,38Eh
	push	cs
	push	di
	mov	di,6BB2h
	push	ds
	push	di
	push	6h
	call	far 1EDAh:0A39h

l1229_03CC:
	mov	byte ptr [bp+0FF7Fh],1h
	jmp	03D7h

l1229_03D3:
	inc	byte ptr [bp+0FF7Fh]

l1229_03D7:
	mov	al,[bp+0FF7Fh]
	xor	ah,ah
	mov	di,ax
	mov	al,[di+6BB2h]
	push	ax
	call	far 1EDAh:1384h
	mov	dl,al
	mov	al,[bp+0FF7Fh]
	xor	ah,ah
	mov	di,ax
	mov	[di+6BB2h],dl
	cmp	byte ptr [bp+0FF7Fh],6h
	jnz	03D3h

l1229_03FE:
	lea	di,[bp-80h]
	push	ss
	push	di
	mov	di,395h
	push	cs
	push	di
	call	far 1EDAh:0FA2h
	lea	di,[bp-80h]
	push	ss
	push	di
	push	219h
	call	far 1EDAh:0FD0h
	mov	word ptr [598Eh],0FFFFh
	mov	word ptr [5990h],0FFFFh

l1229_0426:
	lea	di,[bp-80h]
	push	ss
	push	di
	mov	di,5CB4h
	push	ds
	push	di
	call	far 1EDAh:1085h
	add	sp,4h
	add	word ptr [598Eh],1h
	adc	word ptr [5990h],0h
	lea	di,[bp-80h]
	push	ss
	push	di
	call	far 1EDAh:1185h
	or	al,al
	jnz	0472h

l1229_0450:
	mov	di,5CB4h
	push	ds
	push	di
	mov	di,6BB2h
	push	ds
	push	di
	call	far 1EDAh:0B24h
	jz	0472h

l1229_0461:
	mov	di,5CB4h
	push	ds
	push	di
	mov	di,38Eh
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jnz	0426h

l1229_0472:
	lea	di,[bp-80h]
	push	ss
	push	di
	call	far 1EDAh:1051h
	leave
	ret
1229:047E                                           07 52               .R
1229:0480 41 44 2E 44 41 54                               AD.DAT
