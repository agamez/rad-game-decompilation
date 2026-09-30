;; fn0C74_011E: 0C74:011E
;;   Called from:
;;     0C74:035B (in fn0C74_02D8)
fn0C74_011E proc
	enter	106h,0h
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	push	word ptr [58DEh]
	push	word ptr [58DCh]
	push	cs
	call	004Bh
	lea	di,[bp-4h]
	push	ss
	push	di
	push	2h
	call	far 1EDAh:0A39h
	cmp	byte ptr [bp-4h],2h
	jnc	016Ch

l0C74_0146:
	lea	di,[bp+0FEFAh]
	push	ss
	push	di
	mov	di,0FCh
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

l0C74_016C:
	call	far 1AB8h:1285h
	mov	[bp-6h],ax
	mov	al,[58E4h]
	push	ax
	mov	di,0FEh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jnz	0189h

l0C74_0184:
	call	far 1206h:0066h

l0C74_0189:
	push	24Bh
	push	192h
	push	25Ch
	push	19Bh
	push	word ptr [bp+4h]
	call	00DBh
	push	8h
	call	far 1AB8h:1C32h
	push	253h
	push	196h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	push	0Ah
	call	far 1AB8h:1C32h
	push	254h
	push	197h
	lea	di,[bp-4h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	mov	al,[58E4h]
	push	ax
	mov	di,0FEh
	push	cs
	push	di
	call	far 1EDAh:0CD4h
	jnz	01DEh

l0C74_01D9:
	call	far 1206h:0038h

l0C74_01DE:
	push	word ptr [bp-6h]
	call	far 1AB8h:1C32h
	leave
	ret	2h
0C74:01EA                               01 30 00 E2 01 00           .0....
0C74:01F0 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 ................
0C74:0200 00 00 00 00 00 00 00 00 00 00 00 00             ............
