;; fn13C8_0000: 13C8:0000
;;   Called from:
;;     133F:00E0 (in fn133F_0056)
;;     13C8:0141 (in fn13C8_0139)
fn13C8_0000 proc
	enter	6h,0h
	mov	byte ptr [bp-1h],1h
	mov	al,[bp-1h]
	leave
	retf
