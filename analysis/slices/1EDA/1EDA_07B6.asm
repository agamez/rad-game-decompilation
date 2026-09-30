;; fn1EDA_07B6: 1EDA:07B6
;;   Called from:
;;     1EDA:0850 (in fn1EDA_0848)
;;     1EDA:08D7 (in fn1EDA_08CE)
fn1EDA_07B6 proc
	cmp	word ptr [5380h],0h
	jnz	07C5h

l1EDA_07BD:
	cmp	word ptr es:[di+2h],0D7B2h
	jnz	07D2h

l1EDA_07C5:
	mov	bx,es:[di+8h]
	mov	dx,es:[di+4h]
	les	di,es:[di+0Ch]
	ret

l1EDA_07D2:
	mov	word ptr [5380h],69h
	jmp	07C5h
