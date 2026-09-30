;; fn13C8_00BF: 13C8:00BF
;;   Called from:
;;     133F:0104 (in fn133F_0056)
;;     133F:04CA (in fn133F_04B1)
;;     13C8:0182 (in fn13C8_0139)
fn13C8_00BF proc
	enter	14h,0h
	mov	word ptr [bp-14h],7h
	mov	ax,[bp+8h]
	mov	[bp-10h],ax
	mov	ax,[bp+6h]
	mov	[bp-0Eh],ax
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	leave
	retf	4h
