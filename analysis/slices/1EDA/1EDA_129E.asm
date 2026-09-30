;; fn1EDA_129E: 1EDA:129E
;;   Called from:
;;     0800:437F (in fn0800_4255)
fn1EDA_129E proc
	push	bp
	mov	bp,sp
	sub	sp,80h
	push	ds
	lea	si,[bp-80h]
	push	ss
	pop	ds
	mov	al,[bp+0Ch]
	or	al,al
	jnz	12B8h

l1EDA_12B2:
	mov	ah,19h
	int	21h
	inc	al

l1EDA_12B8:
	mov	dl,al
	add	al,40h
	mov	[si],al
	inc	si
	mov	word ptr [si],5C3Ah
	inc	si
	inc	si
	mov	ah,47h
	int	21h
	jnc	12CEh

l1EDA_12CB:
	mov	byte ptr [si],0h

l1EDA_12CE:
	lea	si,[bp-80h]
	les	di,[bp+8h]
	mov	cx,[bp+6h]
	xor	bx,bx
	cld

l1EDA_12DA:
	lodsb
	or	al,al
	jz	12E5h

l1EDA_12DF:
	inc	bx
	mov	es:[bx+di],al
	loop	12DAh

l1EDA_12E5:
	mov	es:[di],bl
	pop	ds
	mov	sp,bp
	pop	bp
	retf	8h
1EDA:12EF                                              55                U
1EDA:12F0 8B EC 81 EC 80 00 E8 61 00 8B 46 80 0A C0 74 2A .......a..F...t*
1EDA:1300 80 FC 3A 75 20 24 DF 2C 41 8A D0 B4 0E CD 21 B4 ..:u $.,A.....!.
1EDA:1310 19 CD 21 3A C2 74 08 C7 06 80 53 0F 00 EB 0B 80 ..!:.t....S.....
1EDA:1320 7E 82 00 74 05 B4 3B E8 4B 00 8B E5 5D CA 04 00 ~..t..;.K...]...
1EDA:1330 55 8B EC 81 EC 80 00 E8 20 00 B4 39 E8 36 00 8B U....... ..9.6..
1EDA:1340 E5 5D CA 04 00 55 8B EC 81 EC 80 00 E8 0B 00 B4 .]...U..........
1EDA:1350 3A E8 21 00 8B E5 5D CA 04 00 1E C5 76 06 8D 7E :.!...].....v..~
1EDA:1360 80 16 07 FC AC 3C 7F 72 02 B0 7F 98 8B C8 F3 A4 .....<.r........
1EDA:1370 32 C0 AA 1F C3 1E 8D 56 80 16 1F CD 21 1F 73 03 2......V....!.s.
1EDA:1380 A3 80 53 C3                                     ..S.
