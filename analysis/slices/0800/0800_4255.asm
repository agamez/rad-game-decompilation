;; fn0800_4255: 0800:4255
fn0800_4255 proc
	call	far 1EDAh:0000h
	call	far 1E78h:0000h
	call	far 1AB8h:17AEh
	call	far 13E2h:0220h
	call	far 13C8h:0139h
	call	far 13C1h:0067h
	call	far 133Fh:0816h
	call	far 1206h:0217h
	call	far 11C8h:03CFh
	call	far 0C74h:552Fh
	call	far 0C43h:02FBh
	enter	200h,0h
	mov	di,41C7h
	push	cs
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	1h
	call	far 1EDAh:1216h
	call	far 1EDAh:0AD8h
	or	ax,ax
	jnz	42C6h

l0800_42AB:
	mov	di,41C9h
	push	cs
	push	di
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	push	1h
	call	far 1EDAh:1216h
	call	far 1EDAh:0AD8h
	or	ax,ax
	jz	42CBh

l0800_42C6:
	call	far 11C8h:0394h

l0800_42CB:
	mov	word ptr [58E6h],7h
	mov	byte ptr [53DFh],0h
	call	far 1EDAh:1265h
	mov	[bp-2h],ax
	mov	ax,1h
	cmp	ax,[bp-2h]
	ja	4335h

l0800_42E6:
	mov	[53D6h],ax
	jmp	42EFh

l0800_42EB:
	inc	word ptr [53D6h]

l0800_42EF:
	lea	di,[bp+0FEFEh]
	push	ss
	push	di
	push	word ptr [53D6h]
	call	far 1EDAh:1216h
	mov	di,53D4h
	push	ds
	push	di
	call	far 1EDAh:0F71h
	mov	[53DFh],al
	cmp	word ptr [53D4h],0h
	jnz	432Dh

l0800_4312:
	mov	al,[53DFh]
	push	ax
	mov	di,41CBh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	432Dh

l0800_4322:
	mov	al,[53DFh]
	xor	ah,ah
	imul	ax,ax,7h
	mov	[58E6h],ax

l0800_432D:
	mov	ax,[53D6h]
	cmp	ax,[bp-2h]
	jnz	42EBh

l0800_4335:
	mov	di,41EBh
	push	cs
	push	di
	call	far 0C43h:00B9h
	call	far 1E78h:030Dh

l0800_4344:
	call	far 1E78h:02FBh
	or	al,al
	jz	4354h

l0800_434D:
	call	far 1E78h:030Dh
	jmp	4344h

l0800_4354:
	call	far 13E2h:0001h
	or	al,al
	jnz	4367h

l0800_435D:
	mov	di,41F3h
	push	cs
	push	di
	call	far 13E2h:0193h

l0800_4367:
	call	far 1EDAh:0E07h
	mov	byte ptr [58BEh],0h
	call	far 13E2h:003Bh
	push	0h
	mov	di,550Eh
	push	ds
	push	di
	push	4Fh
	call	far 1EDAh:129Eh
	mov	al,[550Fh]
	push	ax
	mov	di,421Eh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jz	43D7h

l0800_4394:
	push	0Fh
	push	3Fh
	push	3Fh
	push	3Fh
	call	far 1AB8h:1CBAh
	push	0Fh
	push	0Fh
	call	far 1AB8h:1342h
	push	1h
	push	0h
	push	4h
	call	far 1AB8h:1536h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	call	far 1AB8h:10CEh
	cwd
	mov	cx,2h
	idiv	cx
	push	ax
	push	1BAh
	mov	di,423Eh
	push	cs
	push	di
	call	far 1AB8h:1D82h

l0800_43D7:
	xor	ax,ax
	mov	[58E2h],ax
	push	1h
	push	0Fh
	call	far 1AB8h:1175h
	mov	byte ptr [58B0h],1h
	mov	word ptr [598Eh],1h
	mov	word ptr [5990h],0h
	call	far 0C74h:03D4h
	call	03F8h
	call	4168h
	push	1h
	push	16h
	call	04CCh
	push	ax
	call	far 1206h:00FFh
	push	1B0h
	push	1D1h
	call	far 1206h:012Dh
	push	64h
	push	1C2h
	call	far 1206h:00D1h

l0800_4423:
	call	3D9Dh
	jmp	4423h
0800:4428                         C9 31 C0 9A E9 00 DA 1E         .1......
