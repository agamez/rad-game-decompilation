;; fn1EDA_079A: 1EDA:079A
;;   Called from:
;;     1EDA:0827 (in fn1EDA_081A)
;;     1EDA:0833 (in fn1EDA_081A)
;;     1EDA:08AA (in fn1EDA_0896)
;;     1EDA:0927 (in fn1EDA_0918)
fn1EDA_079A proc
	cmp	bx,dx
	jz	07A3h

l1EDA_079E:
	mov	al,es:[bx+di]
	clc
	ret

l1EDA_07A3:
	mov	di,sp
	les	di,ss:[di+2h]
	call	07E9h
	mov	dx,ax
	cmp	bx,dx
	jnz	079Eh

l1EDA_07B2:
	mov	al,1Ah
	stc
	ret
