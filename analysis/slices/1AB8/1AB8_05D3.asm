;; fn1AB8_05D3: 1AB8:05D3
;;   Called from:
;;     13E2:022B (in fn13E2_0220)
;;     1AB8:0AAC (in fn1AB8_097B)
fn1AB8_05D3 proc
	push	bp
	mov	bp,sp
	sub	sp,108h
	cmp	byte ptr [0B84Eh],0h
	jz	05EFh

l1AB8_05E1:
	mov	word ptr [0B818h],0FFF5h
	mov	word ptr [bp-2h],0FFF5h
	jmp	06BEh

l1AB8_05EF:
	mov	word ptr [0B818h],0FFFCh
	mov	word ptr [bp-2h],0FFFCh
	lea	di,[bp+0FEF8h]
	push	ss
	push	di
	les	di,[bp+6h]
	push	es
	push	di
	mov	ax,2h
	push	ax
	call	far 1EDAh:0B61h
	mov	di,5D0h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jz	061Dh

l1AB8_061A:
	jmp	06BEh

l1AB8_061D:
	mov	ax,[bp+6h]
	add	ax,80h
	mov	dx,[bp+8h]
	mov	[bp-6h],ax
	mov	[bp-4h],dx
	les	di,[bp-6h]
	mov	[bp-0Ch],di
	mov	[bp-0Ah],es
	les	di,[bp-0Ch]
	cmp	byte ptr es:[di+6h],2h
	jc	0649h

l1AB8_063F:
	les	di,[bp-0Ch]
	cmp	byte ptr es:[di+8h],1h
	jbe	064Bh

l1AB8_0649:
	jmp	06BEh

l1AB8_064B:
	mov	ax,[0B7B8h]
	mov	[bp-0Eh],ax
	xor	ax,ax
	cmp	ax,[bp-0Eh]
	jg	06BEh

l1AB8_0658:
	mov	[bp-8h],ax
	jmp	0660h

l1AB8_065D:
	inc	word ptr [bp-8h]

l1AB8_0660:
	mov	ax,1Ah
	mul	word ptr [bp-8h]
	mov	di,ax
	add	di,50FCh
	push	ds
	push	di
	les	di,[bp-0Ch]
	add	di,0Ah
	push	es
	push	di
	call	far 1EDAh:0B24h
	jnz	06B6h

l1AB8_067E:
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	les	di,[bp-0Ch]
	push	es
	push	di
	les	di,[bp-0Ch]
	add	di,4h
	push	es
	push	di
	call	0569h
	mov	cx,ax
	mov	bx,dx
	mov	ax,1Ah
	mul	word ptr [bp-8h]
	mov	di,ax
	mov	[di+5112h],cx
	mov	[di+5114h],bx
	mov	ax,[bp-8h]
	mov	[bp-2h],ax
	xor	ax,ax
	mov	[0B818h],ax
	jmp	06BEh

l1AB8_06B6:
	mov	ax,[bp-8h]
	cmp	ax,[bp-0Eh]
	jnz	065Dh

l1AB8_06BE:
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf	4h
1AB8:06C7                      02 50 4B                          .PK
