;; fn13C8_00E4: 13C8:00E4
;;   Called from:
;;     133F:010E (in fn133F_0056)
;;     133F:04D5 (in fn133F_04B1)
;;     13C8:018B (in fn13C8_0139)
fn13C8_00E4 proc
	enter	14h,0h
	mov	word ptr [bp-14h],8h
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
13C8:0109                            00 00 00 00 FF FF 00          .......
13C8:0110 00                                              .
