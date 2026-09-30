;; fn1EDA_0953: 1EDA:0953
;;   Called from:
;;     1229:09A7 (in fn1229_0735)
;;     1AB8:11B4 (in fn1AB8_11A0)
;;     1AB8:11E4 (in fn1AB8_11A0)
;;     1AB8:139A (in fn1AB8_1384)
fn1EDA_0953 proc
	mov	bx,sp
	mov	dx,ds
	lds	si,ss:[bx+0Ah]
	les	di,ss:[bx+6h]
	mov	cx,ss:[bx+4h]
	cld
	rep movsb
	mov	ds,dx
	retf	0Ah
1EDA:096B                                  8B C8 8B DA               ....
