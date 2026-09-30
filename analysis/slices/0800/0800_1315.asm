;; fn0800_1315: 0800:1315
;;   Called from:
;;     0800:14D4 (in fn0800_149F)
;;     0800:16B7 (in fn0800_166D)
;;     0800:188A (in fn0800_184C)
;;     0800:1E7E (in fn0800_1E3F)
;;     0800:202D (in fn0800_2004)
;;     0800:220A (in fn0800_21E7)
;;     0800:24A9 (in fn0800_2401)
;;     0800:321D (in fn0800_31B7)
;;     0800:3984 (in fn0800_391E)
fn0800_1315 proc
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
	push	0Bh
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
	push	8h
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
0800:147F                                              00                .
0800:1480 00 00 00 00 00 00 00 FE FF FF 07 00 00 00 00 00 ................
0800:1490 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00    ...............
