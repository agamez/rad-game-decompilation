;; fn1EDA_0879: 1EDA:0879
;;   Called from:
;;     1EDA:0841 (in fn1EDA_081A)
;;     1EDA:0865 (in fn1EDA_0848)
;;     1EDA:0872 (in fn1EDA_086C)
fn1EDA_0879 proc
	cmp	word ptr es:[di+1Ah],0h
	jnz	0881h

l1EDA_0880:
	ret

l1EDA_0881:
	cmp	word ptr [5380h],0h
	jnz	0895h

l1EDA_0888:
	push	es
	push	di
	call	dword ptr es:[di+18h]
	or	ax,ax
	jz	0895h

l1EDA_0892:
	mov	[5380h],ax

l1EDA_0895:
	ret
