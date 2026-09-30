;; fn0800_0D20: 0800:0D20
;;   Called from:
;;     0800:1227 (in fn0800_11EF)
fn0800_0D20 proc
	enter	518h,0h
	les	di,[bp+4h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	mov	byte ptr [bp+0FDFAh],0h
	mov	byte ptr [bp+0FCE8h],0h
	lea	di,[bp+0FCF0h]
	push	ss
	push	di
	mov	di,0D07h
	push	cs
	push	di
	call	far 1EDAh:04F5h
	lea	di,[bp+0FCF0h]
	push	ss
	push	di
	call	far 1EDAh:0565h
	lea	di,[bp+0FCF0h]
	push	ss
	push	di
	lea	di,[bp+0FCE8h]
	push	ss
	push	di
	push	6h
	call	far 1EDAh:0896h
	call	far 1EDAh:086Ch
	lea	di,[bp+0FCF0h]
	push	ss
	push	di
	call	far 1EDAh:05BFh
	call	far 1EDAh:04A2h
	or	ax,ax
	jnz	0D9Ch

l0800_0D88:
	lea	di,[bp+0FCE8h]
	push	ss
	push	di
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h

l0800_0D9C:
	push	0Bh
	call	far 1AB8h:1C32h
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	call	far 1AB8h:13A3h
	mov	[bp+0FEFAh],ax
	push	word ptr [bp+0FEFAh]
	call	far 1EDAh:023Fh
	mov	[bp+0FEFCh],ax
	mov	[bp+0FEFEh],dx
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	les	di,[bp+0FEFCh]
	push	es
	push	di
	call	far 1AB8h:1E6Bh
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	call	0024h
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	call	far 1AB8h:112Eh
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:1536h
	push	0h
	push	1h
	call	far 1AB8h:14F4h
	mov	ax,[bp+8h]
	sub	ax,[bp+0Ch]
	shr	ax,1h
	add	ax,[bp+0Ch]
	mov	[bp+0FDF4h],ax
	mov	di,0D0Fh
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	add	ax,[bp+0Eh]
	push	ax
	push	word ptr [bp+0FDF4h]
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	lea	di,[bp+0FBE8h]
	push	ss
	push	di
	mov	di,0D12h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	call	far 1AB8h:1E0Bh
	add	ax,[bp+0Eh]
	push	ax
	push	word ptr [bp+0FDF4h]
	call	far 1AB8h:108Bh
	call	far 1AB8h:10A8h
	mov	[bp+0FDF6h],ax
	push	0Ah
	call	far 1AB8h:1C32h
	push	word ptr [bp+0FDF6h]
	push	word ptr [bp+0FDF4h]
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	lea	di,[bp+0FBE8h]
	push	ss
	push	di
	mov	di,0D12h
	push	cs
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	call	far 1EDAh:0AACh
	call	far 1AB8h:1E0Bh
	add	ax,[bp+0Eh]
	push	ax
	push	word ptr [bp+0FDF4h]
	call	far 1AB8h:108Bh
	mov	byte ptr [bp+0FDF9h],25h
	xor	ax,ax
	mov	[bp+0FDF0h],ax

l0800_0ED3:
	inc	word ptr [bp+0FDF0h]
	cmp	word ptr [bp+0FDF0h],1388h
	jnz	0F07h

l0800_0EDF:
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

l0800_0F07:
	cmp	word ptr [bp+0FDF0h],2710h
	jnz	0F3Dh

l0800_0F0F:
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

l0800_0F3D:
	call	far 1E78h:02FBh
	or	al,al
	jnz	0F49h

l0800_0F46:
	jmp	1171h

l0800_0F49:
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
	cmp	byte ptr [bp+0FDF9h],0h
	jnz	0FB6h

l0800_0F8E:
	call	far 1E78h:030Dh
	mov	[bp+0FDF9h],al
	mov	al,[bp+0FDF9h]
	cmp	al,4Bh
	jnz	0FA6h

l0800_0F9F:
	mov	byte ptr [bp+0FDF9h],8h
	jmp	0FB6h

l0800_0FA6:
	cmp	al,53h
	jnz	0FB1h

l0800_0FAA:
	mov	byte ptr [bp+0FDF9h],14h
	jmp	0FB6h

l0800_0FB1:
	mov	byte ptr [bp+0FDF9h],0h

l0800_0FB6:
	mov	al,[bp+0FDF9h]
	cmp	al,15h
	jc	1035h

l0800_0FBE:
	cmp	al,0FFh
	ja	1035h

l0800_0FC2:
	mov	di,0D0Fh
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	mov	dx,ax
	mov	ax,[bp+0Ah]
	sub	ax,dx
	xor	dx,dx
	push	dx
	push	ax
	call	far 1AB8h:10A8h
	cwd
	pop	cx
	pop	bx
	cmp	dx,bx
	jl	0FE9h

l0800_0FE3:
	jg	1032h

l0800_0FE5:
	cmp	ax,cx
	jnc	1032h

l0800_0FE9:
	lea	di,[bp+0FBE8h]
	push	ss
	push	di
	mov	al,[bp+0FDF9h]
	push	ax
	call	far 1EDAh:0B4Fh
	call	far 1AB8h:1492h
	lea	di,[bp+0FAE8h]
	push	ss
	push	di
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	call	far 1EDAh:0A1Fh
	lea	di,[bp+0FBE8h]
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

l0800_1032:
	jmp	1171h

l0800_1035:
	cmp	al,14h
	jnz	109Eh

l0800_1039:
	mov	byte ptr [bp+0FDFAh],0h
	push	word ptr [bp+0FDF6h]
	mov	di,0D17h
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
	mov	di,0D19h
	push	cs
	push	di
	call	far 1AB8h:1E0Bh
	add	ax,[bp+0FDF6h]
	push	ax
	mov	di,0D17h
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
	call	0024h
	push	word ptr [bp+0FDF6h]
	push	word ptr [bp+0FDF4h]
	call	far 1AB8h:108Bh
	jmp	1171h

l0800_109E:
	cmp	al,8h
	jz	10A5h

l0800_10A2:
	jmp	1171h

l0800_10A5:
	call	far 1AB8h:10A8h
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[bp+0FDF6h]
	xor	dx,dx
	cmp	dx,bx
	jl	10C5h

l0800_10B9:
	jle	10BEh

l0800_10BB:
	jmp	1171h

l0800_10BE:
	cmp	ax,cx
	jc	10C5h

l0800_10C2:
	jmp	1171h

l0800_10C5:
	call	far 1AB8h:10A8h
	mov	[bp+0FDF2h],ax
	mov	di,0D17h
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
	mov	di,0D17h
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
	mov	di,0D17h
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
	mov	di,0D17h
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
	call	0024h
	mov	di,0D17h
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

l0800_1171:
	cmp	byte ptr [bp+0FDF9h],0Dh
	jz	1182h

l0800_1178:
	cmp	byte ptr [bp+0FDF9h],1Bh
	jz	1182h

l0800_117F:
	jmp	0ED3h

l0800_1182:
	cmp	byte ptr [bp+0FDF9h],1Bh
	jnz	119Dh

l0800_1189:
	lea	di,[bp+0FCE8h]
	push	ss
	push	di
	lea	di,[bp+0FDFAh]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h

l0800_119D:
	push	word ptr [bp+0Eh]
	push	word ptr [bp+0Ch]
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
	les	di,[bp+10h]
	push	es
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	leave
	ret	0Ch
0800:11D8                         0E 43 6F 64 65 20 4D 69         .Code Mi
0800:11E0 73 73 69 6F 6E 20 3A 07 52 41 44 2E 44 41 54    ssion :.RAD.DAT
