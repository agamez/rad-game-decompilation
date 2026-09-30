;; fn13C8_0111: 13C8:0111
;;   Called from:
;;     1229:0E19 (in fn1229_0DCC)
fn13C8_0111 proc
	enter	14h,0h
	mov	word ptr [bp-14h],13h
	mov	ax,[bp+6h]
	cwd
	mov	di,109h
	call	far 1EDAh:04B7h
	mov	[bp-0Eh],ax
	push	33h
	lea	di,[bp-14h]
	push	ss
	push	di
	call	far 1E5Fh:000Bh
	leave
	retf	2h
