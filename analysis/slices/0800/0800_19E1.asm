;; fn0800_19E1: 0800:19E1
;;   Called from:
;;     0800:1F37 (in fn0800_1E3F)
;;     0800:1F84 (in fn0800_1E3F)
;;     0800:20FA (in fn0800_2004)
;;     0800:2140 (in fn0800_2004)
;;     0800:22AF (in fn0800_21E7)
;;     0800:22C3 (in fn0800_21E7)
;;     0800:22D5 (in fn0800_21E7)
;;     0800:22E7 (in fn0800_21E7)
;;     0800:2300 (in fn0800_21E7)
;;     0800:2314 (in fn0800_21E7)
;;     0800:232D (in fn0800_21E7)
;;     0800:2341 (in fn0800_21E7)
;;     0800:2353 (in fn0800_21E7)
;;     0800:2365 (in fn0800_21E7)
;;     0800:39F1 (in fn0800_391E)
;;     0800:3A03 (in fn0800_391E)
;;     0800:3AE2 (in fn0800_391E)
;;     0800:3B81 (in fn0800_391E)
;;     0800:3BB1 (in fn0800_391E)
;;     0800:3F16 (in fn0800_3D9D)
;;     0800:3F47 (in fn0800_3D9D)
;;     0800:3F5E (in fn0800_3D9D)
;;     0800:3FC7 (in fn0800_3D9D)
;;     0800:3FDD (in fn0800_3D9D)
;;     0800:3FF8 (in fn0800_3D9D)
;;     0800:4044 (in fn0800_3D9D)
;;     0800:405F (in fn0800_3D9D)
;;     0800:407D (in fn0800_3D9D)
;;     0800:411A (in fn0800_3D9D)
;;     0800:414E (in fn0800_3D9D)
fn0800_19E1 proc
	enter	108h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	call	far 1206h:0066h
	push	1h
	push	0h
	push	3h
	call	far 1AB8h:1536h
	push	1h
	push	3h
	call	far 1AB8h:1175h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1E0Bh
	shr	ax,1h
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0Ch]
	cwd
	sub	ax,cx
	sbb	dx,bx
	sub	ax,5h
	sbb	dx,0h
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	[di+53E2h],ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1E0Bh
	shr	ax,1h
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0Ch]
	cwd
	add	ax,cx
	adc	dx,bx
	add	ax,5h
	adc	dx,0h
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	[di+53FEh],ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1783h
	shr	ax,1h
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0Ah]
	cwd
	sub	ax,cx
	sbb	dx,bx
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	[di+53F0h],ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1783h
	shr	ax,1h
	xor	dx,dx
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0Ah]
	cwd
	add	ax,cx
	adc	dx,bx
	add	ax,5h
	adc	dx,0h
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	[di+540Ch],ax
	mov	ax,[bp+0Ch]
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	[di+541Ah],ax
	mov	ax,[bp+0Ah]
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	[di+5428h],ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	imul	di,[bp+0Eh],1Ah
	add	di,541Eh
	push	ds
	push	di
	push	19h
	call	far 1EDAh:0A39h
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	ax,[di+53E2h]
	mov	[bp+0FEFEh],ax
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	ax,[di+53FEh]
	mov	[bp+0FEFAh],ax
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	ax,[di+53F0h]
	mov	[bp+0FEFCh],ax
	mov	di,[bp+0Eh]
	shl	di,1h
	mov	ax,[di+540Ch]
	mov	[bp+0FEF8h],ax
	push	word ptr [bp+0FEFEh]
	push	word ptr [bp+0FEFCh]
	push	word ptr [bp+0FEFAh]
	push	word ptr [bp+0FEF8h]
	call	far 1AB8h:1B3Eh
	push	0Bh
	call	far 1AB8h:1C32h
	cmp	byte ptr [bp+4h],0h
	jz	1B53h

l0800_1B4C:
	push	0h
	call	far 1AB8h:1C32h

l0800_1B53:
	mov	ax,[bp+0FEFEh]
	sub	ax,3h
	push	ax
	push	word ptr [bp+0FEFCh]
	mov	ax,[bp+0FEFAh]
	add	ax,3h
	push	ax
	push	word ptr [bp+0FEFCh]
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0FEFEh]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+0FEFCh]
	inc	ax
	push	ax
	mov	ax,[bp+0FEFAh]
	inc	ax
	push	ax
	mov	ax,[bp+0FEFCh]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	push	0Bh
	call	far 1AB8h:1C32h
	mov	ax,[bp+0FEFEh]
	dec	ax
	push	ax
	mov	ax,[bp+0FEFCh]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp+0FEFAh]
	mov	ax,[bp+0FEFCh]
	inc	ax
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	cmp	byte ptr [bp+4h],0h
	jz	1BBFh

l0800_1BB8:
	push	0h
	call	far 1AB8h:1C32h

l0800_1BBF:
	mov	ax,[bp+0FEFEh]
	sub	ax,3h
	push	ax
	push	word ptr [bp+0FEFCh]
	mov	ax,[bp+0FEFEh]
	sub	ax,3h
	push	ax
	mov	ax,[bp+0FEF8h]
	inc	ax
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0FEFEh]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+0FEFCh]
	inc	ax
	push	ax
	mov	ax,[bp+0FEFEh]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+0FEF8h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	push	0Bh
	call	far 1AB8h:1C32h
	mov	ax,[bp+0FEFEh]
	dec	ax
	push	ax
	mov	ax,[bp+0FEFCh]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+0FEFEh]
	dec	ax
	push	ax
	push	word ptr [bp+0FEF8h]
	call	far 1AB8h:1AF6h
	push	8h
	call	far 1AB8h:1C32h
	cmp	byte ptr [bp+4h],0h
	jz	1C35h

l0800_1C2E:
	push	0h
	call	far 1AB8h:1C32h

l0800_1C35:
	mov	ax,[bp+0FEFAh]
	add	ax,3h
	push	ax
	push	word ptr [bp+0FEFCh]
	mov	ax,[bp+0FEFAh]
	add	ax,3h
	push	ax
	mov	ax,[bp+0FEF8h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0FEFAh]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+0FEFCh]
	inc	ax
	push	ax
	mov	ax,[bp+0FEFAh]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp+0FEF8h]
	call	far 1AB8h:1AF6h
	push	8h
	call	far 1AB8h:1C32h
	mov	ax,[bp+0FEFAh]
	inc	ax
	push	ax
	mov	ax,[bp+0FEFCh]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+0FEFAh]
	inc	ax
	push	ax
	mov	ax,[bp+0FEF8h]
	dec	ax
	push	ax
	call	far 1AB8h:1AF6h
	cmp	byte ptr [bp+4h],0h
	jz	1CA3h

l0800_1C9C:
	push	0h
	call	far 1AB8h:1C32h

l0800_1CA3:
	mov	ax,[bp+0FEFEh]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+0FEF8h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+0FEFAh]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+0FEF8h]
	inc	ax
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0FEFEh]
	dec	ax
	push	ax
	mov	ax,[bp+0FEF8h]
	inc	ax
	push	ax
	mov	ax,[bp+0FEFAh]
	inc	ax
	push	ax
	mov	ax,[bp+0FEF8h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	push	8h
	call	far 1AB8h:1C32h
	push	word ptr [bp+0FEFEh]
	push	word ptr [bp+0FEF8h]
	push	word ptr [bp+0FEFAh]
	push	word ptr [bp+0FEF8h]
	call	far 1AB8h:1AF6h
	push	0h
	call	far 1AB8h:1C32h
	mov	ax,[bp+0FEFEh]
	sub	ax,4h
	push	ax
	mov	ax,[bp+0FEFCh]
	dec	ax
	push	ax
	mov	ax,[bp+0FEFAh]
	add	ax,4h
	push	ax
	mov	ax,[bp+0FEF8h]
	add	ax,3h
	push	ax
	call	far 1AB8h:112Eh
	push	1h
	call	far 1AB8h:1C32h
	cmp	byte ptr [bp+4h],0h
	jz	1D3Bh

l0800_1D34:
	push	0Eh
	call	far 1AB8h:1C32h

l0800_1D3B:
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	call	far 1206h:0038h
	leave
	ret	0Ch
