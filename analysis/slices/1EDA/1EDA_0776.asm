;; fn1EDA_0776: 1EDA:0776
;;   Called from:
;;     1EDA:0822 (in fn1EDA_081A)
;;     1EDA:089F (in fn1EDA_0896)
;;     1EDA:0922 (in fn1EDA_0918)
fn1EDA_0776 proc
	cmp	word ptr [5380h],0h
	jnz	0785h

l1EDA_077D:
	cmp	word ptr es:[di+2h],0D7B1h
	jnz	0792h

l1EDA_0785:
	mov	bx,es:[di+8h]
	mov	dx,es:[di+0Ah]
	les	di,es:[di+0Ch]
	ret

l1EDA_0792:
	mov	word ptr [5380h],68h
	jmp	0785h
