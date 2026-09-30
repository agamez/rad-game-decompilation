;; fn1AB8_18E3: 1AB8:18E3
;;   Called from:
;;     1AB8:0E8B (in fn1AB8_0E88)
fn1AB8_18E3 proc
	push	bp
	mov	bp,sp
	cmp	byte ptr [0B8A3h],0FFh
	jz	1910h

l1AB8_18ED:
	mov	si,6h
	call	dword ptr [0B820h]
	cmp	byte ptr [fn0800_3850],0A5h
	jz	1910h

l1AB8_18FB:
	mov	ax,40h
	mov	es,ax
	mov	bx,10h
	mov	al,[0B8A4h]
	mov	es:[bx],al
	xor	ah,ah
	mov	al,[0B8A3h]
	int	10h

l1AB8_1910:
	mov	byte ptr [0B8A3h],0FFh
	pop	bp
	retf
1AB8:1917                      55 8B EC 8A 46 06 32 E4 50        U...F.2.P
1AB8:1920 BE 32 00 FF 1E 20 B8 26 8B 5F 0C EB 18 5D CA 02 .2... .&._...]..
1AB8:1930 00 55 8B EC 8A 46 06 32 E4 50 BE 32 00 FF 1E 20 .U...F.2.P.2... 
1AB8:1940 B8 26 8B 5F 0A                                  .&._.           

l1AB8_1945:
	pop	ax
	push	cs
	call	1807h
	pop	bp
	retf	2h
