;; fn1EDA_1202: 1EDA:1202
;;   Called from:
;;     1AB8:0B50 (in fn1AB8_0AEE)
;;     1AB8:0D7D (in fn1AB8_0BAE)
fn1EDA_1202 proc
	mov	bx,sp
	les	di,ss:[bx+8h]
	mov	cx,ss:[bx+6h]
	mov	al,ss:[bx+4h]
	cld

l1EDA_1211:
	rep stosb

l1EDA_1213:
	retf	8h
