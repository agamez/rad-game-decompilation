;; fn13C8_0038: 13C8:0038
;;   Called from:
;;     133F:0144 (in fn133F_0141)
fn13C8_0038 proc
	enter	14h,0h
	mov	word ptr [bp-14h],1h
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	leave
	retf
