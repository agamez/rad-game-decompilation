;; fn1AB8_1D5B: 1AB8:1D5B
;;   Called from:
;;     1AB8:1198 (in fn1AB8_1175)
fn1AB8_1D5B proc
	push	bp
	mov	bp,sp
	mov	ah,[bp+6h]
	mov	[0B83Fh],ah
	mov	al,[0B83Eh]
	mov	si,1Eh
	call	dword ptr [0B820h]
	mov	al,[bp+8h]
	mov	[0B842h],al
	mov	ah,al
	mov	si,20h
	call	dword ptr [0B820h]
	pop	bp
	retf	4h
