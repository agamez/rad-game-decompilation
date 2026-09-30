;; fn1229_0040: 1229:0040
;;   Called from:
;;     1229:05AB (in fn1229_050A)
;;     1229:0689 (in fn1229_061B)
;;     1229:07A4 (in fn1229_0735)
;;     1229:0863 (in fn1229_0735)
fn1229_0040 proc
	enter	410h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	push	0Bh
	call	far 1AB8h:1C32h
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	call	far 1AB8h:13A3h
	mov	[bp+0FEFAh],ax
	push	word ptr [bp+0FEFAh]
	call	far 1EDAh:023Fh
	mov	[bp+0FEFCh],ax
	mov	[bp+0FEFEh],dx
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	les	di,[bp+0FEFCh]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	cs
	call	0000h
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	call	far 1AB8h:112Eh
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	0h
	push	1h
	call	far 1AB8h:14F4h
	mov	ax,[bp+0Ah]
	sub	ax,[bp+0Eh]
	shr	ax,1h
	add	ax,[bp+0Eh]
	mov	[bp+0FDF4h],ax
	mov	di,36h
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	add	ax,[bp+10h]
	push	ax
	push	word ptr [bp+0FDF4h]
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	lea	di,[bp+0FCF0h]
	push	ss
	push	di
	mov	di,39h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	call	far 1AB8h:1E0Bh
	add	ax,[bp+10h]
	push	ax
	push	word ptr [bp+0FDF4h]
	call	far 1AB8h:108Bh
	call	far 1AB8h:10A8h
	mov	[bp+0FDF6h],ax
	mov	byte ptr [bp+0FDFAh],0h
	mov	byte ptr [bp+0FDF9h],25h
	xor	ax,ax
	mov	[bp+0FDF0h],ax

l1229_0142:
	inc	word ptr [bp+0FDF0h]
	cmp	word ptr [bp+0FDF0h],1388h
	jnz	0176h

l1229_014E:
	push	0Bh
	call	far 1AB8h:1C32h
	call	far 1AB8h:10A8h
	push	ax
	mov	ax,[bp+0FDF4h]
	add	ax,6h
	push	ax
	call	far 1AB8h:10A8h
	push	ax
	mov	ax,[bp+0FDF4h]
	sub	ax,6h
	push	ax
	call	far 1AB8h:1AF6h

l1229_0176:
	cmp	word ptr [bp+0FDF0h],2710h
	jnz	01ACh

l1229_017E:
	xor	ax,ax
	mov	[bp+0FDF0h],ax
	push	0h
	call	far 1AB8h:1C32h
	call	far 1AB8h:10A8h
	push	ax
	mov	ax,[bp+0FDF4h]
	add	ax,6h
	push	ax
	call	far 1AB8h:10A8h
	push	ax
	mov	ax,[bp+0FDF4h]
	sub	ax,6h
	push	ax
	call	far 1AB8h:1AF6h

l1229_01AC:
	call	far 1E78h:02FBh
	or	al,al
	jnz	01B8h

l1229_01B5:
	jmp	0349h

l1229_01B8:
	push	0h
	call	far 1AB8h:1C32h
	call	far 1AB8h:10A8h
	push	ax
	mov	ax,[bp+0FDF4h]
	add	ax,6h
	push	ax
	call	far 1AB8h:10A8h
	push	ax
	mov	ax,[bp+0FDF4h]
	sub	ax,6h
	push	ax
	call	far 1AB8h:1AF6h
	push	0Ah
	call	far 1AB8h:1C32h
	call	far 1E78h:030Dh
	push	ax
	call	far 1EDAh:1384h
	mov	[bp+0FDF9h],al
	mov	al,[bp+0FDF9h]
	cmp	al,15h
	jc	0275h

l1229_01FE:
	cmp	al,0FFh
	ja	0275h

l1229_0202:
	mov	di,36h
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	mov	dx,ax
	mov	ax,[bp+0Ch]
	sub	ax,dx
	xor	dx,dx
	push	dx
	push	ax
	call	far 1AB8h:10A8h
	cwd
	pop	cx
	pop	bx
	cmp	dx,bx
	jl	0229h

l1229_0223:
	jg	0272h

l1229_0225:
	cmp	ax,cx
	jnc	0272h

l1229_0229:
	lea	di,[bp+0FCF0h]
	push	ss
	push	di
	mov	al,[bp+0FDF9h]
	push	ax
	call	far 1EDAh:0B4Fh
	call	far 1AB8h:1492h
	lea	di,[bp+0FBF0h]
	push	ss
	push	di
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FCF0h]
	push	ss
	push	di
	mov	al,[bp+0FDF9h]
	push	ax
	call	far 1EDAh:0B4Fh
	call	far 1EDAh:0AACh
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h

l1229_0272:
	jmp	0349h

l1229_0275:
	cmp	al,8h
	jz	027Ch

l1229_0279:
	jmp	0349h

l1229_027C:
	call	far 1AB8h:10A8h
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0FDF6h]
	xor	dx,dx
	cmp	dx,bx
	jl	029Ch

l1229_0290:
	jle	0295h

l1229_0292:
	jmp	0349h

l1229_0295:
	cmp	ax,cx
	jc	029Ch

l1229_0299:
	jmp	0349h

l1229_029C:
	call	far 1AB8h:10A8h
	mov	[bp+0FDF2h],ax
	mov	di,3Eh
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	xor	dx,dx
	push	dx
	push	ax
	call	far 1AB8h:10A8h
	cwd
	pop	cx
	pop	bx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	di,3Eh
	push	cs
	push	di
	call	far 1AB8h:1783h
	shr	ax,1h
	xor	dx,dx
	push	dx
	push	ax
	call	far 1AB8h:10BBh
	cwd
	pop	cx
	pop	bx
	sub	ax,cx
	sbb	dx,bx
	push	ax
	mov	di,3Eh
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	xor	dx,dx
	push	dx
	push	ax
	call	far 1AB8h:10A8h
	cwd
	pop	cx
	pop	bx
	add	ax,cx
	adc	dx,bx
	push	ax
	mov	di,3Eh
	push	cs
	push	di
	call	far 1AB8h:1783h
	shr	ax,1h
	xor	dx,dx
	push	dx
	push	ax
	call	far 1AB8h:10BBh
	cwd
	pop	cx
	pop	bx
	add	ax,cx
	adc	dx,bx
	push	ax
	push	cs
	call	0000h
	mov	di,3Eh
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	mov	dx,ax
	mov	ax,[bp+0FDF2h]
	sub	ax,dx
	push	ax
	push	word ptr [bp+0FDF4h]
	call	far 1AB8h:108Bh
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	mov	al,[bp+0FDFAh]
	xor	ah,ah
	push	ax
	push	1h
	call	far 1EDAh:0BD0h

l1229_0349:
	cmp	byte ptr [bp+0FDF9h],0Dh
	jz	0353h

l1229_0350:
	jmp	0142h

l1229_0353:
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	les	di,[bp+0FEFCh]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	word ptr [bp+0FEFEh]
	push	word ptr [bp+0FEFCh]
	push	word ptr [bp+0FEFAh]
	call	far 1EDAh:0254h
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	les	di,[bp+12h]
	push	es
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	leave
	retf	0Ch
1229:038E                                           06 4E               .N
1229:0390 4F 4E 41 4D 45 07 52 41 44 2E 44 41 54          ONAME.RAD.DAT
