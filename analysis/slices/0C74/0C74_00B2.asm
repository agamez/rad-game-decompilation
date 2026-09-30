;; fn0C74_00B2: 0C74:00B2
;;   Called from:
;;     0800:019E (in fn0800_0147)
;;     0800:0463 (in fn0800_03F8)
;;     0C74:0472 (in fn0C74_03D4)
fn0C74_00B2 proc
	push	bp
	mov	bp,sp
	push	word ptr [58E2h]
	push	1D5h
	mov	al,[bp+6h]
	xor	ah,ah
	add	ax,[58E2h]
	push	ax
	push	1DFh
	call	far 1AB8h:1B3Eh
	mov	al,[bp+6h]
	xor	ah,ah
	add	[58E2h],ax
	leave
	retf	2h
