;;; Segment 1E5F (1E5F:0000)
1E5F:0000 5E 5A 59 5B B0 21 50 53 51 52 56                ^ZY[.!PSQRV     

;; fn1E5F_000B: 1E5F:000B
;;   Called from:
;;     0C43:0015 (in fn0C43_0000)
;;     0C43:004D (in fn0C43_001E)
;;     1206:001D (in fn1206_000D)
;;     1206:005F (in fn1206_0038)
;;     1206:008D (in fn1206_0066)
;;     1206:00AD (in fn1206_0094)
;;     1206:00F6 (in fn1206_00D1)
;;     1206:0124 (in fn1206_00FF)
;;     1206:0152 (in fn1206_012D)
;;     13C1:000F (in fn13C1_0000)
;;     13C1:001F (in fn13C1_0000)
;;     13C8:001D (in fn13C8_000D)
;;     13C8:0048 (in fn13C8_0038)
;;     13C8:005F (in fn13C8_004F)
;;     13C8:0076 (in fn13C8_0066)
;;     13C8:00B6 (in fn13C8_009A)
;;     13C8:00DB (in fn13C8_00BF)
;;     13C8:0100 (in fn13C8_00E4)
;;     13C8:0130 (in fn13C8_0111)
fn1E5F_000B proc
	push	bp
	push	ds
	mov	bp,sp
	pushf
	mov	bx,45h
	push	cs
	push	bx
	xor	bx,bx
	mov	ds,bx
	mov	bl,[bp+0Ch]
	shl	bx,1h
	shl	bx,1h
	lds	bx,[bx]
	push	ds
	push	bx
	lds	si,[bp+8h]
	cld
	lodsw
	push	ax
	lodsw
	mov	bx,ax
	lodsw
	mov	cx,ax
	lodsw
	mov	dx,ax
	lodsw
	mov	bp,ax
	lodsw
	push	ax
	lodsw
	mov	di,ax
	lodsw
	push	ax
	lodsw
	mov	es,ax
	pop	ds
	pop	si
	pop	ax
	cli
	retf
1E5F:0045                9C 06 57 55 8B EC C4 7E 10 FC AB      ..WU...~...
1E5F:0050 8B C3 AB 8B C1 AB 8B C2 AB 58 AB 8B C6 AB 58 AB .........X....X.
1E5F:0060 8C D8 AB 58 AB 58 AB 1F 5D CA 06 00 55 8B EC B4 ...X.X..]...U...
1E5F:0070 2A CD 21 32 E4 C4 7E 06 AB 8A C2 C4 7E 0A AB 8A *.!2..~.....~...
1E5F:0080 C6 C4 7E 0E AB 91 C4 7E 12 AB 5D CA 10 00 55 8B ..~....~..]...U.
1E5F:0090 EC 8B 4E 0A 8A 76 08 8A 56 06 B4 2B CD 21 5D CA ..N..v..V..+.!].
1E5F:00A0 06 00                                           ..              

;; fn1E5F_00A2: 1E5F:00A2
;;   Called from:
;;     0800:3C15 (in fn0800_3BF2)
;;     0800:3C8A (in fn0800_3C72)
fn1E5F_00A2 proc
	push	bp
	mov	bp,sp
	mov	ah,2Ch
	int	21h
	xor	ah,ah
	mov	al,dl
	les	di,[bp+6h]
	stosw
	mov	al,dh
	les	di,[bp+0Ah]
	stosw
	mov	al,cl
	les	di,[bp+0Eh]
	stosw
	mov	al,ch
	les	di,[bp+12h]
	stosw
	pop	bp
	retf	10h
1E5F:00C7                      55 8B EC 8A 6E 0C 8A 4E 0A        U...n..N.
1E5F:00D0 8A 76 08 8A 56 06 B4 2D CD 21 5D CA 08 00       .v..V..-.!]...  

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

;; fn1E5F_0136: 1E5F:0136
;;   Called from:
;;     1E5F:0113 (in fn1E5F_00DE)
fn1E5F_0136 proc
	jc	0155h

l1E5F_0138:
	add	di,1Eh
	push	ds
	push	es
	pop	ds
	xor	al,al
	mov	cx,100h
	cld

l1E5F_0144:
	repne scasb

l1E5F_0146:
	not	cl
	mov	al,cl
	dec	di
	mov	si,di
	dec	si
	std

l1E5F_014F:
	rep movsb

l1E5F_0151:
	stosb
	pop	ds
	xor	ax,ax

l1E5F_0155:
	mov	[0B8A6h],ax
	ret

;; fn1E5F_0159: 1E5F:0159
;;   Called from:
;;     0800:00E6 (in fn0800_00C1)
fn1E5F_0159 proc
	push	bp
	mov	bp,sp
	mov	al,[bp+0Ah]
	mov	ah,35h
	int	21h
	mov	ax,es
	les	di,[bp+6h]
	cld
	xchg	bx,ax
	stosw
	xchg	bx,ax
	stosw
	pop	bp
	retf	6h

;; fn1E5F_0171: 1E5F:0171
;;   Called from:
;;     0800:00F5 (in fn0800_00C1)
;;     0800:0119 (in fn0800_0103)
fn1E5F_0171 proc
	push	bp
	mov	bp,sp
	push	ds
	lds	dx,[bp+6h]
	mov	al,[bp+0Ah]
	mov	ah,25h
	int	21h
	pop	ds
	pop	bp
	retf	6h
1E5F:0184             00 00 00 00 00 00 00 00 00 00 00 00     ............
