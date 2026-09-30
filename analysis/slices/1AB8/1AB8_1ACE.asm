;; fn1AB8_1ACE: 1AB8:1ACE
;;   Called from:
;;     1AB8:1094 (in fn1AB8_108B)
fn1AB8_1ACE proc
	push	bp
	mov	bp,sp
	mov	ax,[bp+8h]
	mov	bx,[bp+6h]
	mov	si,8h
	call	dword ptr [0B820h]
	pop	bp
	retf	4h
1AB8:1AE2       55 8B EC 8B 46 08 8B 5E 06 BE 0A 00 FF 1E   U...F..^......
1AB8:1AF0 20 B8 5D CA 04 00                                .]...
