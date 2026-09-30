;; fn1EDA_07DA: 1EDA:07DA
;;   Called from:
;;     1EDA:0857 (in fn1EDA_0848)
;;     1EDA:085C (in fn1EDA_0848)
;;     1EDA:08EC (in fn1EDA_08CE)
;;     1EDA:08FC (in fn1EDA_08CE)
fn1EDA_07DA proc
	mov	es:[bx+di],al
	inc	bx
	cmp	bx,dx
	jz	07E3h

l1EDA_07E2:
	ret

l1EDA_07E3:
	mov	di,sp
	les	di,ss:[di+2h]
