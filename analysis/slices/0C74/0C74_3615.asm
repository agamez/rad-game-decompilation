;; fn0C74_3615: 0C74:3615
;;   Called from:
;;     0C74:5467 (in fn0C74_542B)
;;     0C74:54E5 (in fn0C74_54B1)
fn0C74_3615 proc
	enter	4h,0h
	mov	byte ptr [bp-1h],0h
	cmp	word ptr [58B6h],27Eh
	jc	3628h

l0C74_3625:
	jmp	37BEh

l0C74_3628:
	mov	byte ptr [58B1h],0h
	cmp	word ptr [5968h],0FFh
	jnz	3640h

l0C74_3634:
	push	15h
	call	0CFAh
	mov	byte ptr [bp-1h],1h
	jmp	37BEh

l0C74_3640:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	368Fh

l0C74_3652:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	368Fh

l0C74_3667:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	sub	ax,29h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	368Fh

l0C74_367C:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	3692h

l0C74_368F:
	jmp	37BEh

l0C74_3692:
	mov	byte ptr [bp-1h],1h
	mov	byte ptr [bp-2h],0h

l0C74_369A:
	mov	byte ptr [bp-3h],1h
	jmp	36A3h

l0C74_36A0:
	inc	byte ptr [bp-3h]

l0C74_36A3:
	mov	ax,[58E6h]
	shl	ax,1h
	push	ax
	call	02D8h
	inc	byte ptr [bp-2h]
	cmp	byte ptr [bp-2h],5h
	jnz	36C9h

l0C74_36B5:
	mov	byte ptr [bp-2h],1h
	cmp	byte ptr [58B0h],0h
	jz	36C7h

l0C74_36C0:
	push	32h
	call	far 11C8h:0354h

l0C74_36C7:
	jmp	36CEh

l0C74_36C9:
	call	far 11C8h:033Bh

l0C74_36CE:
	cmp	word ptr [58B6h],27Eh
	jnc	36DEh

l0C74_36D6:
	inc	word ptr [58B4h]
	inc	word ptr [58B6h]

l0C74_36DE:
	cmp	byte ptr [58B2h],0h
	jz	370Ah

l0C74_36E5:
	call	far 1E78h:02FBh
	or	al,al
	jz	36F3h

l0C74_36EE:
	mov	byte ptr [58B1h],1h

l0C74_36F3:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	3708h

l0C74_36FE:
	mov	byte ptr [58E0h],1h
	mov	byte ptr [58B1h],1h

l0C74_3708:
	jmp	3718h

l0C74_370A:
	mov	al,[58BCh]
	cmp	al,[58BDh]
	jnz	3718h

l0C74_3713:
	mov	byte ptr [58B1h],1h

l0C74_3718:
	cmp	word ptr [58B6h],27Eh
	jc	3725h

l0C74_3720:
	mov	byte ptr [58B1h],1h

l0C74_3725:
	push	word ptr [58B6h]
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	3770h

l0C74_3736:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	3770h

l0C74_374A:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	sub	ax,29h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	3770h

l0C74_375E:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	3781h

l0C74_3770:
	dec	word ptr [58B4h]
	dec	word ptr [58B6h]
	call	far 11C8h:033Bh
	jmp	37BEh
0C74:377F                                              EB                .
0C74:3780 1F                                              .               

l0C74_3781:
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
	jz	37A9h

l0C74_37A6:
	jmp	36A0h

l0C74_37A9:
	cmp	byte ptr [58B1h],0h
	jnz	37B4h

l0C74_37B0:
	inc	byte ptr [58BCh]

l0C74_37B4:
	cmp	byte ptr [58B1h],0h
	jnz	37BEh

l0C74_37BB:
	jmp	369Ah

l0C74_37BE:
	mov	al,[bp-1h]
	leave
	ret
