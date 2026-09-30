;; fn1E78_02BF: 1E78:02BF
;;   Called from:
;;     1E78:007A (in fn1E78_002E)
;;     1E78:02B6 (in fn1E78_029C)
fn1E78_02BF proc
	cmp	al,es:[di]
	jnz	02C6h

l1E78_02C4:
	loop	02BFh

l1E78_02C6:
	ret
