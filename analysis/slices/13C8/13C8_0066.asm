;; fn13C8_0066: 13C8:0066
;;   Called from:
;;     133F:072E (in fn133F_0528)
;;     13C8:0179 (in fn13C8_0139)
fn13C8_0066 proc
	enter	14h,0h
	mov	word ptr [bp-14h],3h
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	mov	ax,[bp-10h]
	les	di,[bp+0Ah]
	mov	es:[di],ax
	mov	ax,[bp-0Eh]
	les	di,[bp+6h]
	mov	es:[di],ax
	mov	ax,[bp-12h]
	les	di,[bp+0Eh]
	mov	es:[di],ax
	leave
	retf	0Ch
