;; fn1EDA_0BD0: 1EDA:0BD0
;;   Called from:
;;     0800:116C (in fn0800_0D20)
;;     1229:0344 (in fn1229_0040)
fn1EDA_0BD0 proc
	push	bp
	mov	bp,sp
	sub	sp,200h
	cmp	word ptr [bp+6h],0h
	jle	0C20h

l1EDA_0BDD:
	lea	di,[bp+0FF00h]
	push	ss
	push	di
	les	di,[bp+0Ah]
	push	es
	push	di
	mov	ax,1h
	push	ax
	mov	ax,[bp+8h]
	dec	ax
	push	ax
	push	cs
	call	0A6Bh
	lea	di,[bp+0FE00h]
	push	ss
	push	di
	les	di,[bp+0Ah]
	push	es
	push	di
	mov	ax,[bp+8h]
	add	ax,[bp+6h]
	push	ax
	mov	ax,0FFh
	push	ax
	push	cs
	call	0A6Bh
	push	cs
	call	0AACh
	les	di,[bp+0Ah]
	push	es
	push	di
	mov	ax,0FFh
	push	ax
	push	cs
	call	0A39h

l1EDA_0C20:
	mov	sp,bp
	pop	bp
	retf	8h
1EDA:0C26                   FC 8B DC 8C DA 36 C4 7F 0A 36       .....6...6
1EDA:0C30 C5 77 06 36 8B 5F 04 8A CF 32 ED 32 C0 F3 AA 8A .w.6._...2.2....
1EDA:0C40 CB F3 A4 B1 20 2A CB 2A CF F3 AA 8E DA CA 06 00 .... *.*........
1EDA:0C50 FC 8B DC 36 C4 7F 04 B9 10 00 33 C0 F3 AB CB 8B ...6......3.....
1EDA:0C60 DC 36 C4 7F 06 36 8A 47 04 8A D8 32 FF B1 03 D3 .6...6.G...2....
1EDA:0C70 EB 8A C8 80 E1 07 B0 01 D2 E0 26 08 01 CA 02 00 ..........&.....
1EDA:0C80 8B DC 36 C4 7F 08 36 8A 47 06 36 8A 57 04 2A D0 ..6...6.G.6.W.*.
1EDA:0C90 72 1F FE C2 8A D8 32 FF B1 03 D3 EB 8A C8 80 E1 r.....2.........
1EDA:0CA0 07 B0 01 D2 E0 26 08 01 D0 C0 83 D3 00 FE CA 75 .....&.........u
1EDA:0CB0 F4 CA 04 00 FC 8B DC 8C DA 36 C5 77 0A 36 C4 7F .........6.w.6..
1EDA:0CC0 06 36 8B 5F 04 8A CF 32 ED 03 F1 8A CB F3 A4 8E .6._...2........
1EDA:0CD0 DA CA 0A 00                                     ....
