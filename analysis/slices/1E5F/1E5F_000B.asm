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
