;; fn1EDA_05BF: 1EDA:05BF
;;   Called from:
;;     0800:0D7A (in fn0800_0D20)
;;     0800:2C99 (in fn0800_2C0C)
;;     0800:3BBA (in fn0800_391E)
;;     1EDA:0145 (in fn1EDA_011B)
;;     1EDA:014E (in fn1EDA_011B)
;;     1EDA:0596 (in fn1EDA_0572)
fn1EDA_05BF proc
	mov	al,1h
	push	bp
	mov	bp,sp
	les	di,[bp+6h]
	cmp	word ptr es:[di+2h],0D7B1h
	jz	05E7h

l1EDA_05CF:
	cmp	word ptr es:[di+2h],0D7B2h
	jz	05DFh

l1EDA_05D7:
	mov	word ptr [5380h],67h
	jmp	05F7h

l1EDA_05DF:
	push	ax
	mov	bx,14h
	call	05FBh
	pop	ax

l1EDA_05E7:
	or	al,al
	jz	05F7h

l1EDA_05EB:
	mov	bx,1Ch
	call	05FBh
	mov	word ptr es:[di+2h],0D7B0h

l1EDA_05F7:
	pop	bp
	retf	4h
