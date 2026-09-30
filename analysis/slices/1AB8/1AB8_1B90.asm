;; fn1AB8_1B90: 1AB8:1B90
;;   Called from:
;;     1AB8:1248 (in fn1AB8_122E)
fn1AB8_1B90 proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+10h]
	mov	bx,[bp+0Eh]
	mov	si,8h
	call	dword ptr [0B820h]
	mov	ax,[bp+0Ch]
	mov	bx,[bp+0Ah]
	mov	cx,[bp+8h]
	mov	dx,[bp+6h]
	mov	si,14h
	call	dword ptr [0B820h]
	pop	bp
	retf	0Ch
1AB8:1BB7                      55 8B EC 8B 46 0C 8B 5E 0A        U...F..^.
1AB8:1BC0 BE 08 00 FF 1E 20 B8 8B 46 08 8B 5E 06 BE 18 00 ..... ..F..^....
1AB8:1BD0 FF 1E 20 B8 B8 00 00 BB 68 01 8B 4E 08 8B 56 06 .. .....h..N..V.
1AB8:1BE0 BE 14 00 FF 1E 20 B8 5D CA 08 00 55 8B EC 8B 46 ..... .]...U...F
1AB8:1BF0 10 8B 5E 0E BE 08 00 FF 1E 20 B8 8B 46 0C 8B 5E ..^...... ..F..^
1AB8:1C00 0A 8B 4E 08 8B 56 06 BE 16 00 FF 1E 20 B8 5D CA ..N..V...... .].
1AB8:1C10 0C 00 55 8B EC 1E B8 FF FF BE 14 00 FF 1E 20 B8 ..U........... .
1AB8:1C20 8B F3 06 1F C4 7E 06 FC B9 06 00 F3 A5 1F 5D CA .....~........].
1AB8:1C30 04 00                                           ..
