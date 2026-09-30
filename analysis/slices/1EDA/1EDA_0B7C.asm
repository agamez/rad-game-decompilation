;; fn1EDA_0B7C: 1EDA:0B7C
;;   Called from:
;;     11C8:0043 (in fn11C8_0000)
fn1EDA_0B7C proc
	push	bp
	mov	bp,sp
	sub	sp,200h
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	les	di,[bp+0Ah]
	push	es
	push	di
	mov	ax,1h
	push	ax
	mov	ax,[bp+6h]
	dec	ax
	push	ax
	push	cs
	call	0A6Bh
	les	di,[bp+0Eh]
	push	es
	push	di
	push	cs
	call	0AACh
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	les	di,[bp+0Ah]
	push	es
	push	di
	push	word ptr [bp+6h]
	mov	ax,0FFh
	push	ax
	push	cs
	call	0A6Bh
	push	cs
	call	0AACh
	les	di,[bp+0Ah]
	push	es
	push	di
	push	word ptr [bp+8h]
	push	cs
	call	0A39h
	mov	sp,bp
	pop	bp
	retf	0Ch
