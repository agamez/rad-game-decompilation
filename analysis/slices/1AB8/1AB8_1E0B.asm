;; fn1AB8_1E0B: 1AB8:1E0B
;;   Called from:
;;     0800:0E28 (in fn0800_0D20)
;;     0800:0E5B (in fn0800_0D20)
;;     0800:0EB6 (in fn0800_0D20)
;;     0800:0FC7 (in fn0800_0D20)
;;     0800:1064 (in fn0800_0D20)
;;     0800:10D3 (in fn0800_0D20)
;;     0800:110B (in fn0800_0D20)
;;     0800:1146 (in fn0800_0D20)
;;     0800:1A2B (in fn0800_19E1)
;;     0800:1A55 (in fn0800_19E1)
;;     1229:00E4 (in fn1229_0040)
;;     1229:0117 (in fn1229_0040)
;;     1229:0207 (in fn1229_0040)
;;     1229:02AA (in fn1229_0040)
;;     1229:02E2 (in fn1229_0040)
;;     1229:031E (in fn1229_0040)
;;     133F:017E (in fn133F_014B)
;;     133F:01AA (in fn133F_014B)
;;     1AB8:14D3 (in fn1AB8_1492)
fn1AB8_1E0B proc
	push	bp
	mov	bp,sp
	les	bx,[bp+6h]
	mov	cl,es:[bx]
	xor	ch,ch
	inc	bx
	mov	si,28h
	call	dword ptr [0B820h]
	mov	ax,bx
	pop	bp
	retf	4h
1AB8:1E24             4D 00                                   M.
