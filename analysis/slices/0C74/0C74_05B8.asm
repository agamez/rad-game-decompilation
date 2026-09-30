;; fn0C74_05B8: 0C74:05B8
;;   Called from:
;;     0C74:0705 (in fn0C74_06B7)
;;     0C74:1B2E (in fn0C74_0FA1)
;;     0C74:2AC8 (in fn0C74_1F08)
;;     0C74:524F (in fn0C74_522C)
fn0C74_05B8 proc
	enter	6h,0h
	call	far 1AB8h:10E1h
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58BAh]
	xor	dx,dx
	cmp	dx,bx
	jl	05DBh

l0C74_05CF:
	jle	05D4h

l0C74_05D1:
	jmp	06B5h

l0C74_05D4:
	cmp	ax,cx
	jc	05DBh

l0C74_05D8:
	jmp	06B5h

l0C74_05DB:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	05F0h

l0C74_05ED:
	jmp	06B5h

l0C74_05F0:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	0605h

l0C74_0602:
	jmp	06B5h

l0C74_0605:
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	push	word ptr [58B6h]
	push	word ptr [58BAh]
	call	far 1AB8h:13A3h
	mov	[bp-6h],ax
	push	word ptr [bp-6h]
	call	far 1EDAh:023Fh
	mov	[bp-4h],ax
	mov	[bp-2h],dx
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	push	word ptr [58B6h]
	push	word ptr [58BAh]
	les	di,[bp-4h]
	push	es
	push	di
	call	far 1AB8h:1E6Bh

l0C74_0645:
	call	far 1AB8h:10E1h
	cwd
	mov	cx,ax
	mov	bx,dx
	mov	ax,[58BAh]
	xor	dx,dx
	cmp	dx,bx
	jl	065Eh

l0C74_0658:
	jg	06A7h

l0C74_065A:
	cmp	ax,cx
	jnc	06A7h

l0C74_065E:
	push	word ptr [58B4h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	06A7h

l0C74_0670:
	push	word ptr [58B6h]
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	06A7h

l0C74_0682:
	inc	word ptr [58B8h]
	inc	word ptr [58BAh]
	push	word ptr [58B4h]
	push	word ptr [58B8h]
	les	di,[bp-4h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	word ptr [58E6h]
	call	02D8h
	jmp	0645h

l0C74_06A7:
	push	word ptr [bp-2h]
	push	word ptr [bp-4h]
	push	word ptr [bp-6h]
	call	far 1EDAh:0254h

l0C74_06B5:
	leave
	retf
