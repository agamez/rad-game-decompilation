;; fn1AB8_1C4A: 1AB8:1C4A
;;   Called from:
;;     1AB8:0B3B (in fn1AB8_0AEE)
;;     1AB8:0B5A (in fn1AB8_0AEE)
;;     1AB8:0B67 (in fn1AB8_0AEE)
;;     1AB8:11B9 (in fn1AB8_11A0)
fn1AB8_1C4A proc
	push	bp
	mov	bp,sp
	xor	al,al
	mov	si,3Ah
	call	dword ptr [0B820h]
	mov	ax,cx
	pop	bp
	retf
