;; fn1EDA_01DF: 1EDA:01DF
;;   Called from:
;;     1EDA:01D9 (in fn1EDA_01D4)
;;     1EDA:01DD (in fn1EDA_01D4)
fn1EDA_01DF proc
	add	al,30h
	cmp	al,3Ah
	jc	01E7h

l1EDA_01E5:
	add	al,7h
