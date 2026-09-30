;; fn1AB8_06CA: 1AB8:06CA
;;   Called from:
;;     13E2:0245 (in fn13E2_0220)
;;     13E2:025F (in fn13E2_0220)
;;     1AB8:16F3 (in fn1AB8_1536)
fn1AB8_06CA proc
	push	bp
	mov	bp,sp
	sub	sp,112h
	mov	word ptr [0B818h],0FFF3h
	mov	ax,[0B818h]
	mov	[bp-2h],ax
	lea	di,[bp+0FEF6h]
	push	ss
	push	di
	les	di,[bp+6h]
	push	es
	push	di
	mov	ax,2h
	push	ax
	call	far 1EDAh:0B61h
	mov	di,6C7h
	push	cs
	push	di
	call	far 1EDAh:0B24h
	jz	0700h

l1AB8_06FD:
	jmp	080Ah

l1AB8_0700:
	xor	ax,ax
	mov	[bp-0Ah],ax

l1AB8_0705:
	mov	ax,[bp-0Ah]
	les	di,[bp+6h]
	add	di,ax
	cmp	byte ptr es:[di],1Ah
	jz	071Fh

l1AB8_0713:
	cmp	word ptr [bp-0Ah],101h
	jnc	071Fh

l1AB8_071A:
	inc	word ptr [bp-0Ah]
	jmp	0705h

l1AB8_071F:
	cmp	word ptr [bp-0Ah],100h
	jc	0729h

l1AB8_0726:
	jmp	080Ah

l1AB8_0729:
	les	di,[bp+6h]
	mov	ax,di
	add	ax,[bp-0Ah]
	inc	ax
	les	di,[bp+6h]
	mov	dx,es
	mov	[bp-6h],ax
	mov	[bp-4h],dx
	les	di,[bp-6h]
	mov	[bp-0Eh],di
	mov	[bp-0Ch],es
	les	di,[bp-0Eh]
	cmp	byte ptr es:[di+8h],1h
	jc	075Ah

l1AB8_0750:
	les	di,[bp-0Eh]
	cmp	byte ptr es:[di+0Ah],1h
	jbe	075Dh

l1AB8_075A:
	jmp	080Ah

l1AB8_075D:
	mov	word ptr [bp-8h],1h
	jmp	0767h

l1AB8_0764:
	inc	word ptr [bp-8h]

l1AB8_0767:
	mov	ax,0Fh
	mul	word ptr [bp-8h]
	mov	di,ax
	add	di,5215h
	push	ds
	push	di
	lea	di,[bp+0FEF2h]
	push	ss
	push	di
	les	di,[bp-0Eh]
	add	di,2h
	push	es
	push	di
	mov	ax,4h
	push	ax
	call	far 1EDAh:0B61h
	call	far 1EDAh:0B24h
	jnz	0801h

l1AB8_0794:
	mov	ax,0Fh
	mul	word ptr [bp-8h]
	mov	di,ax
	add	di,520Bh
	mov	[bp+0FEEEh],di
	mov	[bp+0FEF0h],ds
	les	di,[bp+0FEEEh]
	push	es
	push	di
	les	di,[bp+0FEEEh]
	push	word ptr es:[di+8h]
	call	dword ptr [0B6C6h]
	les	di,[bp+0FEEEh]
	xor	ax,ax
	mov	es:[di],ax
	mov	es:[di+2h],ax
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	les	di,[bp-0Eh]
	push	es
	push	di
	les	di,[bp-0Eh]
	add	di,6h
	push	es
	push	di
	call	0569h
	les	di,[bp+0FEEEh]
	mov	es:[di+4h],ax
	mov	es:[di+6h],dx
	les	di,[bp+0FEEEh]
	xor	ax,ax
	mov	es:[di+8h],ax
	mov	ax,[bp-8h]
	mov	[bp-2h],ax
	xor	ax,ax
	mov	[0B818h],ax
	jmp	080Ah

l1AB8_0801:
	cmp	word ptr [bp-8h],14h
	jz	080Ah

l1AB8_0807:
	jmp	0764h

l1AB8_080A:
	mov	ax,[bp-2h]
	mov	sp,bp
	pop	bp
	retf	4h
