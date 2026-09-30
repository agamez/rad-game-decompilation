;; fn0C74_54F0: 0C74:54F0
;;   Called from:
;;     0800:278E (in fn0800_2401)
;;     0800:2A75 (in fn0800_2827)
;;     0800:3031 (in fn0800_2C0C)
;;     0800:35A4 (in fn0800_31B7)
;;     0800:3E89 (in fn0800_3D9D)
;;     0800:3E9E (in fn0800_3D9D)
fn0C74_54F0 proc
	enter	2h,0h
	mov	byte ptr [58BCh],1h
	mov	ax,[58B4h]
	dec	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	5524h

l0C74_550C:
	mov	ax,[58B4h]
	sub	ax,17h
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	5524h

l0C74_5521:
	call	2AD9h

l0C74_5524:
	call	37C3h
	mov	[bp-1h],al
	mov	al,[bp-1h]
	leave
	retf
