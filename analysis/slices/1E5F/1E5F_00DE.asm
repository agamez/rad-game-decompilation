;; fn1E5F_00DE: 1E5F:00DE
;;   Called from:
;;     0C74:0025 (in fn0C74_0000)
fn1E5F_00DE proc
	push	bp
	mov	bp,sp
	sub	sp,50h
	push	ds
	lds	si,[bp+0Ch]
	lea	di,[bp-50h]
	push	ss
	pop	es
	cld
	lodsb
	cmp	al,4Fh
	jc	00F5h

l1E5F_00F3:
	mov	al,4Fh

l1E5F_00F5:
	cbw
	xchg	cx,ax
	rep movsb
	xor	al,al
	stosb
	lds	dx,[bp+6h]
	mov	ah,1Ah
	int	21h
	lea	dx,[bp-50h]
	push	ss
	pop	ds
	mov	cx,[bp+0Ah]
	mov	ah,4Eh
	int	21h
	pop	ds
	les	di,[bp+6h]
	call	0136h
	mov	sp,bp
	pop	bp
	retf	0Ah
1E5F:011C                                     55 8B EC 1E             U...
1E5F:0120 C5 56 06 B4 1A CD 21 1F B4 4F CD 21 C4 7E 06 E8 .V....!..O.!.~..
1E5F:0130 04 00 5D CA 04 00                               ..]...
