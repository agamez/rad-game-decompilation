;; fn0C74_37C3: 0C74:37C3
;;   Called from:
;;     0C74:54A3 (in fn0C74_542B)
;;     0C74:5524 (in fn0C74_54F0)
fn0C74_37C3 proc
	enter	4h,0h
	mov	byte ptr [bp-1h],0h
	cmp	word ptr [58B4h],1h
	ja	37D5h

l0C74_37D2:
	jmp	3969h

l0C74_37D5:
	mov	byte ptr [58B1h],0h
	cmp	word ptr [5968h],1h
	jnz	37EDh

l0C74_37E1:
	push	15h
	call	0D43h
	mov	byte ptr [bp-1h],1h
	jmp	3969h

l0C74_37ED:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	383Ch

l0C74_37FF:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	383Ch

l0C74_3814:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	sub	ax,29h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	383Ch

l0C74_3829:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	383Fh

l0C74_383C:
	jmp	3969h

l0C74_383F:
	mov	byte ptr [bp-1h],1h
	mov	byte ptr [bp-2h],5h

l0C74_3847:
	mov	byte ptr [bp-3h],1h
	jmp	3850h

l0C74_384D:
	inc	byte ptr [bp-3h]

l0C74_3850:
	mov	ax,[58E6h]
	shl	ax,1h
	push	ax
	call	02D8h
	dec	byte ptr [bp-2h]
	cmp	byte ptr [bp-2h],0h
	jnz	3876h

l0C74_3862:
	mov	byte ptr [bp-2h],4h
	cmp	byte ptr [58B0h],0h
	jz	3874h

l0C74_386D:
	push	32h
	call	far 11C8h:0354h

l0C74_3874:
	jmp	387Bh

l0C74_3876:
	call	far 11C8h:033Bh

l0C74_387B:
	cmp	word ptr [58B4h],1h
	jbe	388Ah

l0C74_3882:
	dec	word ptr [58B4h]
	dec	word ptr [58B6h]

l0C74_388A:
	cmp	byte ptr [58B2h],0h
	jz	38B6h

l0C74_3891:
	call	far 1E78h:02FBh
	or	al,al
	jz	389Fh

l0C74_389A:
	mov	byte ptr [58B1h],1h

l0C74_389F:
	push	0h
	call	far 1206h:015Bh
	or	al,al
	jz	38B4h

l0C74_38AA:
	mov	byte ptr [58E0h],1h
	mov	byte ptr [58B1h],1h

l0C74_38B4:
	jmp	38C4h

l0C74_38B6:
	mov	al,[58BCh]
	cmp	al,[58BDh]
	jnz	38C4h

l0C74_38BF:
	mov	byte ptr [58B1h],1h

l0C74_38C4:
	cmp	word ptr [58B4h],1h
	ja	38D0h

l0C74_38CB:
	mov	byte ptr [58B1h],1h

l0C74_38D0:
	push	word ptr [58B4h]
	push	word ptr [58BAh]
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	391Bh

l0C74_38E1:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	sub	ax,15h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	391Bh

l0C74_38F5:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	sub	ax,29h
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	391Bh

l0C74_3909:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	392Ch

l0C74_391B:
	inc	word ptr [58B4h]
	inc	word ptr [58B6h]
	call	far 11C8h:033Bh
	jmp	3969h
0C74:392A                               EB 1F                       ..    

l0C74_392C:
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	mov	al,[bp-2h]
	xor	ah,ah
	mov	di,ax
	shl	di,2h
	les	di,[di+58F4h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	cmp	byte ptr [bp-3h],16h
	jz	3954h

l0C74_3951:
	jmp	384Dh

l0C74_3954:
	cmp	byte ptr [58B1h],0h
	jnz	395Fh

l0C74_395B:
	inc	byte ptr [58BCh]

l0C74_395F:
	cmp	byte ptr [58B1h],0h
	jnz	3969h

l0C74_3966:
	jmp	3847h

l0C74_3969:
	mov	al,[bp-1h]
	leave
	ret
