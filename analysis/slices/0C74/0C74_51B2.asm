;; fn0C74_51B2: 0C74:51B2
;;   Called from:
;;     0800:27ED (in fn0800_2401)
;;     0800:2AD4 (in fn0800_2827)
;;     0800:307D (in fn0800_2C0C)
;;     0800:35F0 (in fn0800_31B7)
fn0C74_51B2 proc
	enter	2h,0h
	mov	byte ptr [bp-1h],0h
	mov	ax,[5968h]
	cmp	ax,1h
	jnz	51F1h

l0C74_51C2:
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	51EAh

l0C74_51D5:
	mov	ax,[58B6h]
	add	ax,17h
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	51ECh

l0C74_51EA:
	jmp	5227h

l0C74_51EC:
	call	2AD9h
	jmp	5223h

l0C74_51F1:
	cmp	ax,0FFFFh
	jnz	5223h

l0C74_51F6:
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	521Eh

l0C74_5209:
	mov	ax,[58B4h]
	sub	ax,17h
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	5220h

l0C74_521E:
	jmp	5227h

l0C74_5220:
	call	2AD9h

l0C74_5223:
	mov	byte ptr [bp-1h],1h

l0C74_5227:
	mov	al,[bp-1h]
	leave
	retf
