;; fn1AB8_122E: 1AB8:122E
;;   Called from:
;;     0800:3D1E (in fn0800_3CFA)
fn1AB8_122E proc
	push	bp
	mov	bp,sp
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	xor	ax,ax
	push	ax
	mov	ax,168h
	push	ax
	push	word ptr [bp+6h]
	push	word ptr [bp+6h]
	call	11FBh
	push	ax
	push	cs
	call	1B90h
	pop	bp
	retf	6h
