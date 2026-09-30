;; fn0C74_54B1: 0C74:54B1
;;   Called from:
;;     0800:27C7 (in fn0800_2401)
;;     0800:2AAE (in fn0800_2827)
;;     0800:3057 (in fn0800_2C0C)
;;     0800:35CA (in fn0800_31B7)
;;     0800:3E5F (in fn0800_3D9D)
;;     0800:3E74 (in fn0800_3D9D)
fn0C74_54B1 proc
	enter	2h,0h
	mov	byte ptr [58BCh],1h
	mov	ax,[58B6h]
	inc	ax
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jnz	54E5h

l0C74_54CD:
	mov	ax,[58B6h]
	add	ax,17h
	push	ax
	mov	ax,[58BAh]
	inc	ax
	push	ax
	call	far 1AB8h:1E3Ch
	or	ax,ax
	jz	54E5h

l0C74_54E2:
	call	2AD9h

l0C74_54E5:
	call	3615h
	mov	[bp-1h],al
	mov	al,[bp-1h]
	leave
	retf
