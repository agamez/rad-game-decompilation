;; fn1EDA_0B61: 1EDA:0B61
;;   Called from:
;;     1AB8:0609 (in fn1AB8_05D3)
;;     1AB8:06EC (in fn1AB8_06CA)
;;     1AB8:0788 (in fn1AB8_06CA)
fn1EDA_0B61 proc
	cld
	mov	bx,sp
	mov	dx,ds
	les	di,ss:[bx+0Ah]
	lds	si,ss:[bx+6h]
	mov	ax,ss:[bx+4h]
	stosb
	mov	cx,ax
	rep movsb
	mov	ds,dx
	retf	6h
