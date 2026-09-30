;; fn13C8_004F: 13C8:004F
;;   Called from:
;;     133F:013A (in fn133F_0137)
fn13C8_004F proc
	enter	14h,0h
	mov	word ptr [bp-14h],2h
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	leave
	retf
