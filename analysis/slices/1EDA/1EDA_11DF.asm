;; fn1EDA_11DF: 1EDA:11DF
;;   Called from:
;;     1AB8:05A7 (in fn1AB8_0569)
;;     1AB8:0E3F (in fn1AB8_0BAE)
;;     1AB8:132A (in fn1AB8_129A)
fn1EDA_11DF proc
	mov	bx,sp
	mov	dx,ds
	lds	si,ss:[bx+0Ah]
	les	di,ss:[bx+6h]
	mov	cx,ss:[bx+4h]
	cld
	cmp	si,di
	jnc	11FBh

l1EDA_11F4:
	add	si,cx
	add	di,cx
	dec	si
	dec	di
	std

l1EDA_11FB:
	rep movsb
	mov	ds,dx
	retf	0Ah
