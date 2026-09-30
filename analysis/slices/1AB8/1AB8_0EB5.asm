;; fn1AB8_0EB5: 1AB8:0EB5
;;   Called from:
;;     0800:0003 (in fn0800_0000)
;;     0C74:03E5 (in fn0C74_03D4)
;;     13E2:01AA (in fn13E2_0193)
fn1AB8_0EB5 proc
	push	bp
	mov	bp,sp
	sub	sp,6h
	cmp	byte ptr [0B84Eh],0h
	jnz	0ECBh

l1AB8_0EC2:
	mov	word ptr [0B818h],0FFFFh
	jmp	0F7Ch

l1AB8_0ECB:
	push	cs
	call	0E88h
	mov	di,0B82Eh
	push	ds
	push	di
	push	word ptr [0B7B6h]
	call	dword ptr [0B6C6h]
	mov	ax,[0B828h]
	or	ax,[0B82Ah]
	jz	0EF8h

l1AB8_0EE5:
	mov	ax,1Ah
	mul	word ptr [0B814h]
	mov	di,ax
	xor	ax,ax
	mov	[di+5112h],ax
	mov	[di+5114h],ax

l1AB8_0EF8:
	mov	di,0B828h
	push	ds
	push	di
	push	word ptr [0B82Ch]
	call	dword ptr [0B6C6h]
	call	0813h
	mov	word ptr [bp-2h],1h
	jmp	0F12h

l1AB8_0F0F:
	inc	word ptr [bp-2h]

l1AB8_0F12:
	mov	ax,0Fh
	mul	word ptr [bp-2h]
	mov	di,ax
	add	di,520Bh
	mov	[bp-6h],di
	mov	[bp-4h],ds
	les	di,[bp-6h]
	cmp	byte ptr es:[di+0Ah],0h
	jz	0F76h

l1AB8_0F2E:
	les	di,[bp-6h]
	cmp	word ptr es:[di+8h],0h
	jz	0F76h

l1AB8_0F38:
	les	di,[bp-6h]
	mov	ax,es:[di]
	or	ax,es:[di+2h]
	jz	0F76h

l1AB8_0F44:
	les	di,[bp-6h]
	push	es
	push	di
	les	di,[bp-6h]
	push	word ptr es:[di+8h]
	call	dword ptr [0B6C6h]
	les	di,[bp-6h]
	xor	ax,ax
	mov	es:[di+8h],ax
	les	di,[bp-6h]
	xor	ax,ax
	mov	es:[di],ax
	mov	es:[di+2h],ax
	les	di,[bp-6h]
	xor	ax,ax
	mov	es:[di+4h],ax
	mov	es:[di+6h],ax

l1AB8_0F76:
	cmp	word ptr [bp-2h],14h
	jnz	0F0Fh

l1AB8_0F7C:
	mov	sp,bp
	pop	bp
	retf
