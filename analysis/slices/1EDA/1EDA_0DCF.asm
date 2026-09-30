;; fn1EDA_0DCF: 1EDA:0DCF
;;   Called from:
;;     1EDA:0D80 (in fn1EDA_0D80)
fn1EDA_0DCF proc
	mov	ax,[5382h]
	mov	bx,[5384h]
	mov	cx,ax
	mul	word ptr cs:[0E05h]
	shl	cx,1h
	shl	cx,1h
	shl	cx,1h
	add	ch,cl
	add	dx,cx
	add	dx,bx
	shl	bx,1h
	shl	bx,1h
	add	dx,bx
	add	dh,bl
	mov	cl,5h
	shl	bx,cl
	add	dh,bl
	add	ax,1h
	adc	dx,0h
	mov	[5382h],ax
	mov	[5384h],dx
	ret
1EDA:0E05                05 84                                 ..
