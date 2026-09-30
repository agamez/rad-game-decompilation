;; fn0800_36E6: 0800:36E6
;;   Called from:
;;     0800:39A3 (in fn0800_391E)
fn0800_36E6 proc
	push	bp
	mov	bp,sp
	push	1h
	push	3h
	call	far 1AB8h:1175h
	push	0h
	push	0h
	push	1h
	call	far 1AB8h:10F4h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+8h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	call	far 1AB8h:1B3Eh
	push	8h
	call	far 1AB8h:1C32h
	mov	ax,[bp+0Ah]
	sub	ax,3h
	push	ax
	push	word ptr [bp+8h]
	mov	ax,[bp+6h]
	add	ax,3h
	push	ax
	push	word ptr [bp+8h]
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	push	ax
	mov	ax,[bp+6h]
	inc	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp+6h]
	mov	ax,[bp+8h]
	inc	ax
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	sub	ax,3h
	push	ax
	push	word ptr [bp+8h]
	mov	ax,[bp+0Ah]
	sub	ax,3h
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	push	ax
	mov	ax,[bp+0Ah]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+0Ah]
	dec	ax
	push	ax
	push	word ptr [bp+4h]
	call	far 1AB8h:1AF6h
	push	0Bh
	call	far 1AB8h:1C32h
	mov	ax,[bp+6h]
	add	ax,3h
	push	ax
	push	word ptr [bp+8h]
	mov	ax,[bp+6h]
	add	ax,3h
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+6h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	push	ax
	mov	ax,[bp+6h]
	inc	ax
	inc	ax
	push	ax
	push	word ptr [bp+4h]
	call	far 1AB8h:1AF6h
	mov	ax,[bp+6h]
	inc	ax
	push	ax
	mov	ax,[bp+8h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+6h]
	inc	ax
	push	ax
	mov	ax,[bp+4h]
	dec	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	dec	ax
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+6h]
	inc	ax
	inc	ax
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	mov	ax,[bp+0Ah]
	dec	ax
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	push	ax
	mov	ax,[bp+6h]
	inc	ax
	push	ax
	mov	ax,[bp+4h]
	inc	ax
	push	ax
	call	far 1AB8h:1AF6h
	push	word ptr [bp+0Ah]
	push	word ptr [bp+4h]
	push	word ptr [bp+6h]
	push	word ptr [bp+4h]
	call	far 1AB8h:1AF6h
	leave
	ret	8h
