;; fn1EDA_00ED: 1EDA:00ED
;;   Called from:
;;     1EDA:00E4 (in fn1EDA_00E2)
;;     1EDA:00EB (in fn1EDA_00E9)
fn1EDA_00ED proc
	mov	dx,2014h
	mov	ds,dx
	sti
	mov	[5376h],ax
	mov	ax,cx
	or	ax,bx
	jz	011Bh
