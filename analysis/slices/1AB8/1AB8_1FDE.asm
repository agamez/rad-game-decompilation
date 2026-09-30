;; fn1AB8_1FDE: 1AB8:1FDE
;;   Called from:
;;     1AB8:1FA8 (in fn1AB8_1F9E)
fn1AB8_1FDE proc
	cmp	cl,2h
	jc	1FECh

l1AB8_1FE3:
	cmp	cl,6h
	cmc
	jnc	1FECh

l1AB8_1FE9:
	cmp	cl,8h

l1AB8_1FEC:
	ret
