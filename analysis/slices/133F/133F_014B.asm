;; fn133F_014B: 133F:014B
;;   Called from:
;;     133F:02D7 (in fn133F_026B)
;;     133F:0491 (in fn133F_0352)
fn133F_014B proc
	enter	100h,0h
	les	di,[bp+6h]
	push	es
	push	di
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	push	0FFh
	call	far 1EDAh:0A39h
	push	1h
	push	1h
	call	far 1AB8h:14F4h
	push	word ptr [bp+0Ch]
	push	0h
	push	word ptr [bp+0Ah]
	call	far 1AB8h:1536h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1E0Bh
	shr	ax,1h
	inc	ax
	mov	dx,ax
	mov	ax,[bp+10h]
	sub	ax,dx
	push	ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1783h
	shr	ax,1h
	inc	ax
	mov	dx,ax
	mov	ax,[bp+0Eh]
	sub	ax,dx
	push	ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1E0Bh
	shr	ax,1h
	inc	ax
	add	ax,[bp+10h]
	push	ax
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1783h
	shr	ax,1h
	inc	ax
	add	ax,[bp+0Eh]
	push	ax
	push	1h
	call	far 1AB8h:0F93h
	call	far 1AB8h:1028h
	push	0h
	push	0h
	call	far 1AB8h:10CEh
	push	ax
	call	far 1AB8h:10E1h
	push	ax
	push	1h
	call	far 1AB8h:0F93h
	push	word ptr [bp+10h]
	push	word ptr [bp+0Eh]
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	call	far 1AB8h:1D82h
	leave
	retf	0Ch
