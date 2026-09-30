;; fn1EDA_01A5: 1EDA:01A5
;;   Called from:
;;     1EDA:0178 (in fn1EDA_011B)
;;     1EDA:0184 (in fn1EDA_011B)
;;     1EDA:019B (in fn1EDA_011B)
fn1EDA_01A5 proc
	mov	al,cs:[bx]
	or	al,al
	jz	01B2h

l1EDA_01AC:
	call	01E7h
	inc	bx
	jmp	01A5h

l1EDA_01B2:
	ret
