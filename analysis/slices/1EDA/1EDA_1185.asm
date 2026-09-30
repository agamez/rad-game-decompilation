;; fn1EDA_1185: 1EDA:1185
;;   Called from:
;;     0800:12B4 (in fn0800_11EF)
;;     0C43:01F4 (in fn0C43_00B9)
;;     1229:0447 (in fn1229_039D)
;;     1229:095B (in fn1229_0735)
fn1EDA_1185 proc
	call	119Ah
	jc	1195h

l1EDA_118A:
	sub	ax,cx
	sbb	dx,bx
	jc	1195h

l1EDA_1190:
	mov	al,1h
	retf	4h

l1EDA_1195:
	xor	al,al
	retf	4h
