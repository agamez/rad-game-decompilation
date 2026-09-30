;; fn1EDA_0801: 1EDA:0801
;;   Called from:
;;     1EDA:07FF (in fn1EDA_07E9)
;;     1EDA:07FF (in fn1EDA_07DA)
;;     1EDA:07FF (in fn1EDA_07DA)
fn1EDA_0801 proc
	mov	[5380h],ax

l1EDA_0804:
	pop	di
	pop	es
	mov	ax,es:[di+0Ah]
	mov	bx,es:[di+8h]
	mov	dx,es:[di+4h]
	les	di,es:[di+0Ch]
	pop	ds
	pop	si
	pop	cx
	ret
