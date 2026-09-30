;; fn1EDA_1076: 1EDA:1076
;;   Called from:
;;     1EDA:1057 (in fn1EDA_1051)
;;     1EDA:1097 (in fn1EDA_1091)
;;     1EDA:10CD (in fn1EDA_10BB)
;;     1EDA:1129 (in fn1EDA_1123)
fn1EDA_1076 proc
	cmp	word ptr es:[di+2h],0D7B3h
	jz	1084h

l1EDA_107E:
	mov	word ptr [5380h],67h

l1EDA_1084:
	ret
