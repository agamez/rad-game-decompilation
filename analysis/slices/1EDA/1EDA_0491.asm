;; fn1EDA_0491: 1EDA:0491
;;   Called from:
;;     1EDA:030F (in fn1EDA_0308)
;;     1EDA:03F9 (in fn1EDA_03D3)
fn1EDA_0491 proc
	add	ax,7h
	mov	dx,ax
	rcr	dx,1h
	shr	dx,1h
	shr	dx,1h
	shr	dx,1h
	and	ax,8h
	ret
