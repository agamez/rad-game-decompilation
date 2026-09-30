;; fn1EDA_04F5: 1EDA:04F5
;;   Called from:
;;     0800:0D4C (in fn0800_0D20)
;;     0800:2C6C (in fn0800_2C0C)
;;     0800:392D (in fn0800_391E)
;;     1EDA:008C (in fn1EDA_0000)
;;     1EDA:00A0 (in fn1EDA_0000)
fn1EDA_04F5 proc
	mov	bx,sp
	push	ds
	les	di,ss:[bx+8h]
	lds	si,ss:[bx+4h]
	cld
	xor	ax,ax
	stosw
	mov	ax,0D7B0h
	stosw
	mov	ax,80h
	stosw
	xor	ax,ax
	stosw
	stosw
	stosw
	lea	ax,[di+74h]
	stosw
	mov	ax,es
	stosw
	mov	ax,60Ch
	stosw
	mov	ax,cs
	stosw
	xor	ax,ax
	mov	cx,0Eh

l1EDA_0524:
	rep stosw

l1EDA_0526:
	lodsb
	cmp	al,4Fh
	jbe	052Dh

l1EDA_052B:
	mov	al,4Fh

l1EDA_052D:
	mov	cl,al
	xor	ch,ch
	rep movsb
	xor	al,al
	stosb
	pop	ds
	retf	8h
1EDA:053A                               8B DC 36 C4 7F 0A           ..6...
1EDA:0540 36 8B 47 04 26 89 45 04 36 8B 47 06 26 89 45 0C 6.G.&.E.6.G.&.E.
1EDA:0550 36 8B 47 08 26 89 45 0E 33 C0 26 89 45 08 26 89 6.G.&.E.3.&.E.&.
1EDA:0560 45 0A CA 0A 00                                  E....
