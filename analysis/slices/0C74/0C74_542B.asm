;; fn0C74_542B: 0C74:542B
;;   Called from:
;;     0800:2715 (in fn0800_2401)
;;     0800:29FC (in fn0800_2827)
;;     0800:2F0A (in fn0800_2C0C)
;;     0800:34E5 (in fn0800_31B7)
fn0C74_542B proc
	enter	2h,0h
	mov	byte ptr [bp-1h],1h
	mov	ax,[5968h]
	cmp	ax,1h
	jnz	5472h

l0C74_543B:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	546Ch

l0C74_544E:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	dec	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	546Ch

l0C74_5461:
	call	4FD7h
	mov	[bp-1h],al
	call	3615h
	jmp	5470h

l0C74_546C:
	mov	byte ptr [bp-1h],0h

l0C74_5470:
	jmp	54ACh

l0C74_5472:
	cmp	ax,0FFFFh
	jnz	54ACh

l0C74_5477:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	54A8h

l0C74_548A:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	dec	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	54A8h

l0C74_549D:
	call	4DACh
	mov	[bp-1h],al
	call	37C3h
	jmp	54ACh

l0C74_54A8:
	mov	byte ptr [bp-1h],0h

l0C74_54AC:
	mov	al,[bp-1h]
	leave
	retf
