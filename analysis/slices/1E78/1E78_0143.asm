;; fn1E78_0143: 1E78:0143
;;   Called from:
;;     1E78:032B (in fn1E78_030D)
fn1E78_0143 proc
	cmp	byte ptr [0B8BAh],0h
	jnz	014Bh

l1E78_014A:
	ret

l1E78_014B:
	mov	byte ptr [0B8BAh],0h

l1E78_0150:
	mov	ah,1h
	int	16h
	jz	015Ch

l1E78_0156:
	mov	ah,0h
	int	16h
	jmp	0150h

l1E78_015C:
	mov	al,5Eh
	call	047Ch
	mov	al,43h
	call	047Ch
	call	0475h
	int	23h
