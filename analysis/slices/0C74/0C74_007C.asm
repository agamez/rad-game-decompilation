;; fn0C74_007C: 0C74:007C
;;   Called from:
;;     0C74:058E (in fn0C74_03D4)
fn0C74_007C proc
	push	bp
	mov	bp,sp
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
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
	leave
	ret	8h
