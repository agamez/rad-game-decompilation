;; fn1AB8_1968: 1AB8:1968
;;   Called from:
;;     1AB8:11F1 (in fn1AB8_11A0)
fn1AB8_1968 proc
	push	bp
	mov	bp,sp
	mov	ah,[bp+6h]
	mov	[0B83Fh],ah
	mov	al,[0B83Eh]
	mov	si,1Eh
	call	dword ptr [0B820h]
	mov	byte ptr [0B842h],0Ch
	les	bx,[bp+8h]
	mov	ax,0FFFFh
	mov	si,20h
	call	dword ptr [0B820h]
	pop	bp
	retf	6h
