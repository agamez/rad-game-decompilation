;; fn0C74_020C: 0C74:020C
;;   Called from:
;;     0C74:0389 (in fn0C74_02D8)
fn0C74_020C proc
	enter	106h,0h
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	push	word ptr [58CEh]
	push	word ptr [58CCh]
	push	cs
	call	004Bh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h
	cmp	byte ptr [bp-4h],2h
	jnc	025Ah

l0C74_0234:
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	mov	di,1EAh
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h

l0C74_025A:
	call	far 1AB8h:1285h
	mov	[bp-6h],ax
	mov	al,[58E4h]
	push	ax
	mov	di,1ECh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jnz	0277h

l0C74_0272:
	call	far 1206h:0066h

l0C74_0277:
	push	233h
	push	192h
	push	244h
	push	19Bh
	push	word ptr [bp+4h]
	call	00DBh
	push	8h
	call	far 1AB8h:1C32h
	push	23Bh
	push	196h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	push	0Ah
	call	far 1AB8h:1C32h
	push	23Ch
	push	197h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	push	word ptr [bp-6h]
	call	far 1AB8h:1C32h
	mov	al,[58E4h]
	push	ax
	mov	di,1ECh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jnz	02D4h

l0C74_02CF:
	call	far 1206h:0038h

l0C74_02D4:
	leave
	ret	2h
