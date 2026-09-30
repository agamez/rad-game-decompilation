;; fn0C74_06B7: 0C74:06B7
;;   Called from:
;;     0800:2631 (in fn0800_2401)
;;     0800:2960 (in fn0800_2827)
;;     0800:2DFE (in fn0800_2C0C)
;;     0800:3429 (in fn0800_31B7)
;;     0800:3E26 (in fn0800_3D9D)
fn0C74_06B7 proc
	push	bp
	mov	bp,sp
	mov	word ptr [5968h],1h
	mov	byte ptr [58B3h],0h
	mov	byte ptr [58B1h],1h
	mov	ax,[bp+8h]
	mov	[58B4h],ax
	mov	ax,[bp+6h]
	mov	[58B8h],ax
	mov	ax,[bp+8h]
	add	ax,2Bh
	mov	[58B6h],ax
	mov	ax,[bp+6h]
	add	ax,2Bh
	mov	[58BAh],ax
	mov	byte ptr [596Bh],2Ch
	mov	byte ptr [596Ah],2Ch
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	les	di,[58E8h]
	push	es
	push	di
	push	0h
	call	far 1AB8h:13D7h
	push	cs
	call	05B8h
	leave
	retf	4h
