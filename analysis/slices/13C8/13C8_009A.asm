;; fn13C8_009A: 13C8:009A
;;   Called from:
;;     133F:051B (in fn133F_04DE)
;;     133F:05D3 (in fn133F_0528)
;;     133F:05FA (in fn133F_0528)
;;     133F:0621 (in fn133F_0528)
;;     133F:0648 (in fn133F_0528)
fn13C8_009A proc
	enter	14h,0h
	mov	word ptr [bp-14h],4h
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
