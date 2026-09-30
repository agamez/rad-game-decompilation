;; fn1EDA_0FD0: 1EDA:0FD0
;;   Called from:
;;     0800:018E (in fn0800_0147)
;;     0800:0219 (in fn0800_01FE)
;;     0800:0431 (in fn0800_03F8)
;;     0800:1265 (in fn0800_11EF)
;;     0800:243F (in fn0800_2401)
;;     0800:2892 (in fn0800_2827)
;;     0800:367E (in fn0800_31B7)
;;     0800:4194 (in fn0800_4168)
;;     0C43:00EB (in fn0C43_00B9)
;;     0C74:042F (in fn0C74_03D4)
;;     1229:0415 (in fn1229_039D)
;;     1229:04A1 (in fn1229_0486)
;;     1229:091E (in fn1229_0735)
;;     1AB8:08F7 (in fn1AB8_0887)
;;     1AB8:0929 (in fn1AB8_0887)
fn1EDA_0FD0 proc
	mov	al,[5386h]
	mov	ah,3Dh
	xor	dx,dx
	jmp	0FDFh
1EDA:0FD9                            B8 00 3C BA 01 00             ..<... 

l1EDA_0FDF:
	push	bp
	mov	bp,sp
	les	di,[bp+8h]
	cmp	word ptr es:[di+2h],0D7B0h
	jz	1007h

l1EDA_0FED:
	cmp	word ptr es:[di+2h],0D7B3h
	jz	0FFDh

l1EDA_0FF5:
	mov	word ptr [5380h],66h
	jmp	1031h

l1EDA_0FFD:
	push	ax
	push	dx
	push	es
	push	di
	push	cs
	call	1051h
	pop	dx
	pop	ax

l1EDA_1007:
	cmp	byte ptr es:[di+30h],0h
	jz	1020h

l1EDA_100E:
	push	ds
	lea	dx,[di+30h]
	push	es
	pop	ds
	xor	cx,cx
	int	21h
	pop	ds
	jnc	1021h

l1EDA_101B:
	mov	[5380h],ax
	jmp	1031h

l1EDA_1020:
	xchg	dx,ax

l1EDA_1021:
	mov	word ptr es:[di+2h],0D7B3h
	mov	es:[di],ax
	mov	ax,[bp+6h]
	mov	es:[di+4h],ax

l1EDA_1031:
	pop	bp
	retf	6h
1EDA:1035                8B DC 36 C4 7F 04 E8 38 00 75 0E      ..6....8.u.
1EDA:1040 33 C9 26 8B 1D B4 40 CD 21 73 03 A3 80 53 CA 04 3.&...@.!s...S..
1EDA:1050 00                                              .
